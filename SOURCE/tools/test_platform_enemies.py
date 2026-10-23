from pathlib import Path
import subprocess,json
import argparse
ap=argparse.ArgumentParser();ap.add_argument('--out',type=Path,required=True);args=ap.parse_args()
P=args.out.resolve();P.mkdir(parents=True,exist_ok=True);R=Path(__file__).resolve().parents[2];S=R/'SOURCE/game/src';B=R/'REFERENCE_V1.0.1/SOURCE/game/src'
# Compile the exact original lifted blocks, not a hand-written expected formula.
chunks=[]
for name,tag,entry,stop,begin,end,hit,miss in [
 ('faithful_exec.c','axis','3eec','3f48','477e','47c4','47ae','47ac'),
 ('cat_exec.c','cat','3eda','3f36','47bc','4802','47ec','47ea')]:
 text=(B/name).read_text();start=text.index('L'+entry+':');finish=text.index('L'+stop+':')
 block=text[start:finish]
 # All-ordinary preflight fixtures stop before off-range cleanup.
 abort='3f2e'if tag=='axis'else'3f1c'
 block=block[:block.index('L'+abort+':')]
 done='3fb0'if tag=='axis'else'3f9e';skip='3fa8'if tag=='axis'else'3f96';loopend='3fac'if tag=='axis'else'3f9a'
 block+=f'\nL{skip}: a[6]+=22; VWORD(d[7])=(u16)(d[7]-1);if((u16)d[7]!=65535u)goto L{entry};return 2;\nL{abort}:return 0;\nL{stop}:return 1;\n'
 head='u32 v,w,r,ea,eb;u16 tv,tw,tr;\n'
 chunks.append('int ref_'+tag+'_enter(void){'+head+'goto L'+entry+';\n'+block+'}\n')
 start=text.index('L'+begin+':');finish=text.index('L'+hit+':');block=text[start:finish]
 # End original miss RTS at the continuation, before reading its outer stack.
 rts=block.index('L'+miss+':');block=block[:rts]+'L'+miss+':return 0;\nL'+hit+':return 1;\n'
 chunks.append('int ref_'+tag+'_shots(void){'+head+'goto L'+begin+';\n'+block+'}\n')
for name,tag,entries,external in [('faithful_exec.c','axis',[('45ae','45b6','45ba','45bc'),('45c0','45c8','45cc','45ce')],'56f4'),('cat_exec.c','cat',[('45ec','45f4','45f8','45fa'),('45fe','4606','460a','460c')],'5734')]:
 text=(B/name).read_text()
 for n,(entry,cont,stop,nextlabel)in enumerate(entries):
  block=text[text.index('L'+entry+':'):text.index('L'+nextlabel+':')]
  block=block[:block.index('L'+stop+':')]+f'L{stop}: return 1;\nL{external}: if({"cat_external"if tag=="cat"else"vm_external"}(0x{external}ul))return 0; a[7]+=4;goto L{cont};\n'
  chunks.append('int ref_'+tag+'_draw'+str(n)+'(void){u32 v,w,r,ea,eb;u16 tv,tw,tr;goto L'+entry+';\n'+block+'}\n')
header=r'''
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "faithful.h"
#include "direct_memory.h"
#include "platform_scan.h"
u32 d[8],a[8],vm_resume,vm_fault;
u8 fn,fz,fv,fc,fx,vm_busy;
StageWork stage_work;u8 stack[512];
u16 vm_player_state,vm_platform_opcode;
u8 vr8(u32 p){return 0;}u8 cvr8(u32 p){return 0;}
u16 vr16(u32 p){if(p>=0x39c8&&p<0x3aa4)return dm_be16(vm_actors+p-0x39c8);return 0;}
u16 cvr16(u32 p){if(p>=0x39bc&&p<0x3a98)return dm_be16(vm_actors+p-0x39bc);return 0;}
u32 vr32(u32 p){if(p>=0x1ffe00&&p<=0x1ffffc)return dm_be32(stack+p-0x1ffe00);return 0;}u32 cvr32(u32 p){return vr32(p);}
void vw8(u32 p,u8 v){}void cvw8(u32 p,u8 v){}
void vw16(u32 p,u16 v){}void cvw16(u32 p,u16 v){}
void vw32(u32 p,u32 v){if(p>=0x1ffe00&&p<=0x1ffffc)dm_put32(stack+p-0x1ffe00,v);}void cvw32(u32 p,u32 v){vw32(p,v);}
typedef struct {s16 x,y;u16 id;} BobDraw;
BobDraw bob_draws[64];u8 bob_draw_count;
int vm_external(u32 pc){u16 id=(u16)d[2];if(bob_draw_count<64&&(id&0x1ffu)&&(id&0x1ffu)<=305u){BobDraw *b=&bob_draws[bob_draw_count++];b->x=(s16)d[0];b->y=(s16)d[1];b->id=id;}return 0;}
int cat_external(u32 pc){return vm_external(pc);}
#define VWORD(x) (*(u16 *)&(x))
#define VBYTE(x) (*(u8 *)&(x))
#define VSTEP(p)
'''
main=r'''
typedef struct {u32 d0[8],a0[8];u8 flags[5],actors[220],stack0[512],count;BobDraw bobs[64];} Snapshot;
static void snap(Snapshot *s){memset(s,0,sizeof(*s));memcpy(s->d0,d,32);memcpy(s->a0,a,32);s->flags[0]=fn;s->flags[1]=fz;s->flags[2]=fv;s->flags[3]=fc;s->flags[4]=fx;memcpy(s->actors,vm_actors,220);memcpy(s->stack0,stack,512);memcpy(s->bobs,bob_draws,sizeof(bob_draws));s->count=bob_draw_count;}
static void load(Snapshot *s){memcpy(d,s->d0,32);memcpy(a,s->a0,32);fn=s->flags[0];fz=s->flags[1];fv=s->flags[2];fc=s->flags[3];fx=s->flags[4];memcpy(vm_actors,s->actors,220);memcpy(stack,s->stack0,512);memcpy(bob_draws,s->bobs,sizeof(bob_draws));bob_draw_count=s->count;}
static u32 rng=0x1021989;static u32 rnd(void){rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return rng;}
int main(void){int stage,j,i,k,old,new;u16 first,cam,cx,cy,remaining;Snapshot initial,expected,actual;
 for(stage=0;stage<2;stage++){
  first=stage?0x39bc:0x39c8;cam=stage?1734:1246;
  for(j=0;j<30000;j++){
   for(i=0;i<8;i++){d[i]=rnd();a[i]=rnd();}fn=rnd()&1;fz=rnd()&1;fv=rnd()&1;fc=rnd()&1;fx=rnd()&1;
   a[7]=0x1ffe0c+rnd()%501;bob_draw_count=rnd()%65;for(i=0;i<512;i++)stack[i]=(u8)rnd();
   snap(&initial);old=stage?(j&1?ref_cat_draw1():ref_cat_draw0()):(j&1?ref_axis_draw1():ref_axis_draw0());snap(&expected);load(&initial);new=platform_actor_draw(stage?(j&1?0x4606:0x45f4):(j&1?0x45c8:0x45b6),stage);snap(&actual);
   if(old!=new||memcmp(&expected,&actual,sizeof(actual))){printf("draw failure %d %d\n",stage,j);return 1;}
  }
  for(j=0;j<30000;j++){
   for(i=0;i<8;i++){d[i]=rnd();a[i]=rnd();}fn=rnd()&1;fz=rnd()&1;fv=rnd()&1;fc=rnd()&1;fx=rnd()&1;
   for(i=0;i<220;i++)vm_actors[i]=(u8)rnd();
   snap(&initial);old=stage?ref_cat_shots():ref_axis_shots();snap(&expected);load(&initial);new=platform_projectile_actors(first);snap(&actual);
   if(old!=new||memcmp(&expected,&actual,sizeof(actual))){printf("collision failure %d %d %d/%d\n",stage,j,old,new);return 1;}
  }
  for(j=0;j<30000;j++){
   for(i=0;i<8;i++){d[i]=rnd();a[i]=rnd();}fn=rnd()&1;fz=rnd()&1;fv=rnd()&1;fc=rnd()&1;fx=rnd()&1;
   remaining=rnd()%10;VWORD(d[7])=remaining;a[6]=first+(9-remaining)*22;
   cx=(u16)rnd();cy=(u16)rnd();dm_put16(vm_vars+cam,cx);dm_put16(vm_vars+cam+2,cy);
   memset(vm_actors,0,220);
   for(i=0;i<10;i++){
    for(k=2;k<22;k++)vm_actors[i*22+k]=(u8)rnd();
    if(rnd()%3){dm_put16(vm_actors+i*22,(u16)((2+(rnd()%25))|((rnd()%4==0)?0x8000:0)));dm_put16(vm_actors+i*22+2,j%2?(u16)(cx+(s16)(rnd()%480)-160):(u16)rnd());dm_put16(vm_actors+i*22+4,j%2?(u16)(cy+(s16)(rnd()%240)-80):(u16)rnd());}
   }
   snap(&initial);old=stage?ref_cat_enter():ref_axis_enter();snap(&expected);load(&initial);new=platform_actor_enter(first,cam);if(!new)new=stage?ref_cat_enter():ref_axis_enter();snap(&actual);
   if(old!=new||memcmp(&expected,&actual,sizeof(actual))){printf("actor failure %d %d %d/%d\n",stage,j,old,new);for(i=0;i<8;i++)printf("d%d %08x/%08x a %08x/%08x\n",i,expected.d0[i],actual.d0[i],expected.a0[i],actual.a0[i]);for(i=0;i<5;i++)printf("flag%d %d/%d\n",i,expected.flags[i],actual.flags[i]);return 1;}
  }
 }
 puts("PASS 60000 actor-preflight, 60000 projectile/enemy scans and 60000 draw boundaries against exact original lifted blocks");return 0;
}
'''
p=P/'enemy_host.c';p.write_text(header+'\n'.join(chunks)+main)
cmd=['gcc','-std=c99','-O2','-fno-strict-aliasing','-DVM_HOST','-I'+str(S),str(p),str(S/'platform_scan.c'),'-o',str(P/'enemy_host')]
r=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True);(P/'enemy-host-build.log').write_text(r.stdout);assert r.returncode==0,r.stdout[-3000:]
r=subprocess.run([str(P/'enemy_host')],capture_output=True,text=True);print(r.stdout);assert r.returncode==0
(P/'ENEMY_HOST_RESULT.json').write_text(json.dumps({'passed':True,'seed':'0x1021989','original_lifted_blocks':True,'actor_preflight_cases':60000,'projectile_enemy_scan_cases':60000,'actor_draw_boundary_cases':60000},indent=2)+'\n')
