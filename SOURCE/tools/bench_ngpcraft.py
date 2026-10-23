import sys,json,re,bisect,ctypes,hashlib,time,argparse
from pathlib import Path
P=Path(__file__).resolve().parent

a=argparse.ArgumentParser();a.add_argument('--rom',required=True);a.add_argument('--map',required=True);a.add_argument('--out',required=True);a.add_argument('--stages',default='1,2,4,5');a.add_argument('--profile',action='store_true');a.add_argument('--sound-off',action='store_true');a.add_argument('--emulator',required=True,help='Path to pinned Ngpcraft_emulator checkout');o=a.parse_args()
EMU=Path(o.emulator).resolve();sys.path.insert(0,str(EMU))
from core.native import NativeMachine,status_name,active_timing_model
mp=Path(o.map).read_text();syms={n:int(v,16)for n,v in re.findall(r'([_.A-Za-z][A-Za-z0-9_.$]*)\s+([0-9A-F]{4,6})\s+(?:f_[a-z]+|FAST_[A-Z]+|PLATFORM_SCAN|platform_scan|[A-Z_]+)',mp)}
byaddr=sorted((v,n)for n,v in syms.items()if (v>=0x200000 or 0x7000<=v<0x7800)); addrs=[x[0]for x in byaddr]
def sym(pc):
 i=bisect.bisect_right(addrs,pc)-1
 return byaddr[i][1]if i>=0 else 'RAM_'+hex(pc&~255)
results=[]
for stage in map(int,o.stages.split(',')):
 m=NativeMachine(Path(o.rom).read_bytes(),bios=(EMU/'hle_bios/bios_hle.bin').read_bytes());m.set_timing_silicon();m.reset();
 def rd(n,k=1):return int.from_bytes(m.read(syms[n],k),'little')
 def frames(n,key=0):
  m.write(0xb0,bytes([key]));s=m.run_frames(n);assert s.stop_status in (0,1,41),(status_name(s.stop_status),hex(s.stop_pc));return s
 def pulse(key):frames(6,key);frames(8,0)
 frames(130,16);frames(15);assert rd('_screen_mode')==1,('title',rd('_screen_mode'))
 pulse(32);assert rd('_screen_mode')==9,('testmenu',rd('_screen_mode'))
 for i in range(stage-1):pulse(8)
 assert rd('_active_stage')==stage
 if o.sound_off:pulse(16)
 pulse(32)
 for _ in range(2000):
  if rd('_screen_mode')==4:break
  frames(1)
 assert rd('_screen_mode')==4,('start',rd('_screen_mode'))
 stats={};blocks={};instructions={};win_cycles=0;win_n=0;watch=[];last=-1;start=time.monotonic()
 for f in range(7000):
  nt=int.from_bytes(m.read(syms['_game']+38,2),'little')
  if nt!=last:
   last=nt
   watch.append({'tick':nt,'game':m.read(syms['_game'],70).hex(),'work':hashlib.sha256(m.read(syms['_stage_work'],2776)).hexdigest()})
  if rd('_screen_mode')==10:break
  if o.profile and 20<=nt<40:
   summary,recs=m.run(4096,record=True)
   for r in recs:
    bl=r.pc&~63;blocks[bl]=blocks.get(bl,0)+r.cycles;ins=instructions.setdefault(r.pc,[0,0,bytes(r.raw[:r.raw_len]).hex()]);ins[0]+=r.cycles;ins[1]+=1;name=sym(r.pc);d=stats.setdefault(name,[0,0]);d[0]+=r.cycles;d[1]+=1
    win_cycles+=r.cycles;win_n+=1
  else:summary=frames(1)
 else:raise Exception('timeout stage '+str(stage))
 base=syms['_hardware_perf'];offs=[int.from_bytes(m.read(syms['_hardware_perf_offsets']+i*2,2),'little')for i in range(25)]
 names=['size','refreshes','updates','source_updates','presents','max_step_gap','max_draw_gap','peak_sprites','overflows','irq','blocks','underruns','fill_max','hits','misses','pattern_bytes','pattern_scan_bytes','descriptor_bytes','rtc_seconds','rtc_warning','pcm_min','pcm_max','live','armed']
 data={}
 for i,n in enumerate(names):
  if i==0:data[n]=offs[i];continue
  size=4 if n in ['pattern_bytes','pattern_scan_bytes','descriptor_bytes']else 1 if n in ['rtc_warning','pcm_min','pcm_max','live','armed']else 2
  data[n]=int.from_bytes(m.read(base+offs[i],size),'little')
 data.update(stage=stage,final_game=m.read(syms['_game'],70).hex(),state_samples=watch,engine_fault=rd('_vm_fault',4),elapsed_host=time.monotonic()-start,profile_cycles=win_cycles,profile_instructions=win_n,profile_blocks=sorted([{'pc':hex(k),'cycles':v}for k,v in blocks.items()],key=lambda d:-d['cycles'])[:30],instructions=sorted([{'pc':hex(k),'cycles':v[0],'count':v[1],'raw':v[2]}for k,v in instructions.items()],key=lambda d:-d['cycles'])[:80],top=sorted([{'name':n,'cycles':v[0],'instructions':v[1],'share':round(100*v[0]/win_cycles,3)}for n,v in stats.items()],key=lambda d:-d['cycles'])[:30])
 results.append(data);print(stage,{k:v for k,v in data.items()if k not in ['state_samples','top','profile_blocks','instructions']},flush=True);print(data['top'][:15],flush=True)
 m.close()
Path(o.out).write_text(json.dumps({'rom':o.rom,'sha256':hashlib.sha256(Path(o.rom).read_bytes()).hexdigest(),'core_commit':__import__('subprocess').check_output(['git','rev-parse','HEAD'],cwd=EMU,text=True).strip(),'timing':active_timing_model(),'bios':'NgpCraft clean-room HLE','results':results},indent=2)+'\n')
