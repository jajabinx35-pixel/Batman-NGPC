import sys,re,json,hashlib,struct,argparse,zlib
from pathlib import Path
P=Path(__file__).resolve().parent

ap=argparse.ArgumentParser();ap.add_argument('--rom',required=True);ap.add_argument('--map',required=True);ap.add_argument('--out',required=True);ap.add_argument('--sound-off',action='store_true');ap.add_argument('--stages',default='1,2,3,4,5');ap.add_argument('--emulator',required=True,help='Path to pinned Ngpcraft_emulator checkout');o=ap.parse_args()
EMU=Path(o.emulator).resolve();sys.path.insert(0,str(EMU))
from core.native import NativeMachine,STATUS_BREAKPOINT,HW_WATCHDOG,HW_SYSTEM_STACK
sym={n:int(v,16)for n,v in re.findall(r'([_.A-Za-z][A-Za-z0-9_.$]*)\s+([0-9A-F]{4,6})\s+(?:f_[a-z]+|[A-Z_]+|platform_scan)',Path(o.map).read_text())}
out=Path(o.out);out.mkdir(parents=True,exist_ok=True);results=[]
for stage in map(int,o.stages.split(',')):
 m=NativeMachine(Path(o.rom).read_bytes(),bios=(EMU/'hle_bios/bios_hle.bin').read_bytes());m.set_timing_silicon();m.set_hw_guard(HW_WATCHDOG|HW_SYSTEM_STACK);m.reset()
 def val(n,k=1):return int.from_bytes(m.read(sym[n],k),'little')
 def frames(n,key=0):
  m.write(0xb0,bytes([key]));s=m.run_frames(n);assert s.stop_status in (0,1,41),(s.stop_status,hex(s.stop_pc));return s
 def pulse(k):frames(6,k);frames(8)
 frames(130,16);frames(15);assert val('_screen_mode')==1
 pulse(32);assert val('_screen_mode')==9
 for i in range(stage-1):pulse(8)
 if o.sound_off:pulse(16)
 assert val('_audio_enabled')==int(not o.sound_off)
 m.set_breakpoints([sym['_perf_after_step'],sym['_perf_present']])
 m.write(0xb0,b'\x20')
 states={};surfaces={};cycles=0
 def surface():
  b=m.read(0x8000,0x4000)
  def take(a,n):return b[a-0x8000:a-0x8000+n]
  t=[take(0x9000,4096),take(0x8200,512),take(0x8c00,64),take(0x8000,6),take(0x8012,7),take(0x8030,6),take(0x8020,2)]
  first,last=(224,351)if stage in [1,5]else (465,496)if stage==3 else (321,384)
  t.extend([take(0xa000,first*16),take(0xa000+(last+1)*16,(511-last)*16)])
  for i in range(64):
   a,xy=struct.unpack('<HH',take(0x8800+i*4,4));t.append(struct.pack('<HH',a&0xfe00,xy));t.append(take(0xa000+(a&511)*16,16)if a&0x1800 else b'\0'*16)
  return b''.join(t)
 for it in range(2000):
  s,_=m.run(1000000,record=False);cycles+=s.total_cycles
  assert s.stop_status in (0,1,40,41),(s.stop_status,hex(s.stop_pc))
  if s.stop_status==40:
   m.write(0xb0,b'\0');pc=m.cpu().pc
   tick=int.from_bytes(m.read(sym['_game']+38,2),'little')
   if pc==sym['_perf_after_step'] and 1<=tick<=300:
    states[tick]=(m.read(sym['_stage_work'],2776)+m.read(sym['_game'],70)+m.read(sym['_d'],32)+m.read(sym['_a'],32)+m.read(sym['_fn'],10)).hex()
   if pc==sym['_perf_present']:
    tick=val('_video_visible_tick',2)
    if 1<=tick<=300:surfaces[tick]=surface().hex()
   assert val('_vm_fault',4)==0
  if len(surfaces)==300 and len(states)==300:break
 else:raise Exception(('replay timeout',stage,len(states),len(surfaces),val('_screen_mode')))
 assert set(states)==set(range(1,301)) and set(surfaces)==set(states)
 for k in ['_video_overflows','_native_missing_frames','_sampled_underruns']:assert val(k,2)==0,(stage,k,val(k,2))
 stack=m.read(0x7800,0x780);used=next((i for i,b in enumerate(stack)if b!=0xa5),0x780);floor=0x7800+used
 data={'stage':stage,'states':states,'surfaces':surfaces}
 (out/f'LEVEL{stage}.json.zlib').write_bytes(zlib.compress(json.dumps(data,separators=(',',':')).encode(),9))
 r={'stage':stage,'states':len(states),'surfaces':len(surfaces),'cycles_to_last_present':cycles,'engine_fault':val('_vm_fault',4),'overflows':val('_video_overflows',2),'missing_frames':val('_native_missing_frames',2),'underruns':val('_sampled_underruns',2),'hw_violations':m.hw_violations(),'stack_guard_untouched_to':hex(floor)}
 results.append(r);print(r,flush=True);m.close()
(out/'RESULT.json').write_text(json.dumps({'passed':True,'rom':o.rom,'sha256':hashlib.sha256(Path(o.rom).read_bytes()).hexdigest(),'sound_on':not o.sound_off,'timing':'NgpCraft silicon','bios':'clean-room HLE','results':results},indent=2)+'\n')
