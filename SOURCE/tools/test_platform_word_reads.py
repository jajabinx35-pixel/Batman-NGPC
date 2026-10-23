from pathlib import Path
import re,subprocess,json
import argparse
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path,required=True);args=ap.parse_args()
P=args.out.resolve();P.mkdir(parents=True,exist_ok=True);S=Path(__file__).resolve().parents[1]/'game/src'
s=(S/'platform_scan.c').read_text();functions=s[s.index('u16 VM_ABI platform_axis_rom16'):s.index('\n#endif',s.index('u16 VM_ABI platform_axis_rom16'))]
arrays=[]
for file,name in [('assets_axis.c','axis_map'),('assets_cathedral.c','cathedral_map')]:
 source=(S/file).read_text();arrays.append(re.search(r'const u8 '+name+r'\[\d+\]\s*=\s*\{.*?\};',source,re.S)[0])
code='''#include <stdio.h>
#include "cathedral.h"
#include "direct_memory.h"
#define vr16_slow vr16
#define cvr16_slow cvr16
'''+functions+'\n'+'\n'.join(arrays)+'''
int main(void){u32 p;u16 x,y;unsigned long checks=0;int stage;
 for(stage=0;stage<2;stage++){
  if(stage)cat_reset(0);else vm_reset(0);
  for(p=0;p<1748;p++)vm_vars[p]=(u8)(p*31u+9u);
  for(p=0;p<220;p++)vm_actors[p]=(u8)(p*17u+13u);
  for(p=0;p<160;p++)vm_shots[p]=(u8)(p*11u+123u);
  vm_player_state=0x8f23;vm_platform_opcode=0xfedc;
  if(stage){cvw16(0x4972,0xd17f);cvw16(0x7c874,0xa273);cvw8(0x807c+77,43);cvw8(0x807c+9000,101);}else{vw16(0x4934,0xd17f);vw16(0x7c874,0xa273);}
  for(p=0;p<0x12000;p++){
   x=stage?cvr16(p):vr16(p);y=stage?platform_cat_rom16(p):platform_axis_rom16(p);checks++;
   if(x!=y){printf("FAIL %d %lx %x/%x\\n",stage,(unsigned long)p,x,y);return 1;}
   if((p&31)==0){x=stage?cvr16(p|0x1000000):vr16(p|0x1000000);y=stage?platform_cat_rom16(p|0x1000000):platform_axis_rom16(p|0x1000000);checks++;if(x!=y)return 2;}
  }
 }
 printf("PASS %lu word reads, including odd addresses, boundaries, mutable state, aliases and sparse Cathedral map\\n",checks);return 0;
}
'''
f=P/'word_reads_host.c';f.write_text(code)
cmd=['gcc','-std=c99','-O2','-fno-strict-aliasing','-DVM_HOST','-I'+str(S),str(f)]+[str(S/name)for name in ['faithful_mem.c','cat_mem.c','faithful_data.c','cat_data.c']]+['-o',str(P/'word_reads_host')]
r=subprocess.run(cmd,capture_output=True,text=True);assert r.returncode==0,r.stderr[-2000:]
r=subprocess.run([str(P/'word_reads_host')],capture_output=True,text=True);print(r.stdout);assert r.returncode==0
(P/'WORD_READ_RESULT.json').write_text(json.dumps({'passed':True,'cases':152064,'exact_original_mappers':True,'full_low_address_range':'0..0x11fff, every word start, both stages','aliases_tested':True,'mutable_and_sparse_states':True},indent=2)+'\n')
