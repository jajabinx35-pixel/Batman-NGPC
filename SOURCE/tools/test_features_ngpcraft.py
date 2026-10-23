import sys,re,json,struct,argparse,hashlib
from pathlib import Path
P=Path(__file__).resolve().parent;
ap=argparse.ArgumentParser();ap.add_argument('--rom',required=True);ap.add_argument('--map',required=True);ap.add_argument('--out',required=True);ap.add_argument('--emulator',required=True,help='Path to pinned Ngpcraft_emulator checkout');o=ap.parse_args()
EMU=Path(o.emulator).resolve();sys.path.insert(0,str(EMU))
from core.native import NativeMachine,HW_WATCHDOG,HW_SYSTEM_STACK
from ngpc_native import write_png
S={n:int(v,16)for n,v in re.findall(r'([_.A-Za-z][A-Za-z0-9_.$]*)\s+([0-9A-F]{4,6})\s+(?:f_[a-z]+|[A-Z_]+|platform_scan)',Path(o.map).read_text())};out=Path(o.out);out.mkdir(parents=True,exist_ok=True)
rom=Path(o.rom).read_bytes();m=None;checks=[]
def boot(flash=None):
 global m
 if m:m.close()
 r=bytearray(rom)
 if flash:r[0x1f8000:0x1fc000]=flash
 m=NativeMachine(bytes(r),bios=(EMU/'hle_bios/bios_hle.bin').read_bytes());m.set_timing_silicon();m.set_hw_guard(HW_WATCHDOG|HW_SYSTEM_STACK);m.reset();frames(130,16);frames(15);assert v('_screen_mode')==1
 return m
def v(n,k=1):return int.from_bytes(m.read(S[n],k),'little')
def raw(off,k=2):return int.from_bytes(m.read(S['_game']+off,k),'little')
def put(n,value,k=1):m.write(S[n],value.to_bytes(k,'little'))
def frames(n,key=0):
 m.write(0xb0,bytes([key]));s=m.run_frames(n);assert s.stop_status in (0,1,41),(s.stop_status,hex(s.stop_pc));return s
def pulse(k):frames(10,k);frames(20)
def wait_mode(mode,limit=2000):
 for i in range(limit):
  if v('_screen_mode')==mode:
   if mode in [1,13,17,19,20]:frames(60)
   return
  frames(1)
 raise Exception(('mode timeout',mode,v('_screen_mode')))
def next_tick():
 m.write(0xb0,b'\0');m.set_breakpoints([S['_game_tick']])
 for i in range(10):
  s,_=m.run(1000000,record=False)
  assert s.stop_status in (0,1,40,41),(s.stop_status,hex(s.stop_pc))
  if s.stop_status==40:return
 raise Exception('no next tick')
def choice(target):
 for _ in range(10):
  if v('_ui_choice')==target:return
  pulse(2)
 raise Exception(('choice timeout',target,v('_ui_choice')))
def check(name,yes=True):
 assert yes,name
 checks.append(name);print('PASS',name,flush=True)
def photo(name):frames(60);write_png(m,out/name)
def flash():return m.flash_peek(0x3f8000,16384)
boot();pulse(16);wait_mode(4);next_tick()
m.write(S['_game']+52,struct.pack('<I',3000));m.write(S['_stage_work']+30,b'\0\1');next_tick();next_tick()
check('real checkpoint baseline',raw(46)==3000 and raw(48)==0 and v('_run_source_score',4)==3000)
m.write(S['_game']+52,struct.pack('<I',4000));next_tick();next_tick();check('credited high water',v('_run_preview_score',4)==4000)
m.write(S['_game']+44,struct.pack('<H',1));oldclock=v('_run_refreshes',4);next_tick();next_tick()
check('respawn restores attempt, retains credited points and elapsed ranking clock',raw(52,4)==3000 and v('_run_preview_score',4)==4000 and v('_run_refreshes',4)>=oldclock)
m.write(S['_game']+52,struct.pack('<I',4000));next_tick();next_tick();check('replayed rewards do not increase points',v('_run_preview_score',4)==4000)
m.write(S['_game']+52,struct.pack('<I',4500));next_tick();next_tick();check('better attempt earns only improvement',v('_run_preview_score',4)==4500)
m.set_breakpoints([]);pulse(64);wait_mode(5);pulse(2);pulse(16)
for i in range(2000):
 if v('_save_available') and not v('_save_error') and v('_screen_mode')==5:break
 frames(1)
else:raise Exception('save failed')
saved=flash();check('actual flash save',m.flash_dirty() and any(x!=255 for x in saved));photo('pause_saved.png')
boot(saved);check('cold boot offers Continue',v('_save_available')==1);pulse(16);wait_mode(4);next_tick();check('cold Continue retains score protection',raw(46)==3000 and v('_run_source_score',4)==4500 and v('_run_score_disabled')==0)
m.write(S['_game']+44,struct.pack('<H',1));next_tick();next_tick();m.write(S['_game']+52,struct.pack('<I',4500));next_tick();next_tick();check('continued retry cannot farm',v('_run_preview_score',4)==4500)
m.set_breakpoints([]);pulse(64);wait_mode(5)
for i in range(3):pulse(2)
pulse(16);wait_mode(1)
choice(3 if v('_save_available') else 2)
pulse(16);wait_mode(13);check('positive record retained',v('_best_score',4)==4500);pulse(16);wait_mode(17);photo('qr_initials.png');pulse(64);wait_mode(19,4000)
text=m.read(S['_render_work']+384,256).split(b'\0')[0].decode('ascii');assert text.startswith('NGPC-DEV.COM/BATMAN/BATMAN2');(out/'actual_qr_payload.txt').write_text(text+'\n');check('positive-score upload produces QR');photo('qr_code.png');pulse(32);wait_mode(17);pulse(32);wait_mode(13)
pulse(2);pulse(2);pulse(16);wait_mode(20);pulse(16);wait_mode(13)
check('Reset Records clears score and upload entry',v('_best_score',4)==0 and v('_last_score',4)==0);pulse(16);check('zero score cannot open upload',v('_screen_mode')==13);cleared=flash()
boot(cleared);check('record reset survives power cycle',v('_best_score',4)==0 and v('_last_score',4)==0)
# Continue is still present; credits is the fifth item.
choice(4 if v('_save_available') else 3)
pulse(16);wait_mode(16)
for i in range(7000):
 if v('_ending_card_id')==14:break
 frames(1)
else:raise Exception('credits did not reach final page')
photo('hardhat_credits.png');check('shared menu/ending sequence reaches Hardhat Warrior credit page')
check('no engine, sprite, audio or hardware guard faults',v('_vm_fault',4)==0 and v('_video_overflows',2)==0 and v('_sampled_underruns',2)==0 and m.hw_violations()==0)
(out/'RESULT.json').write_text(json.dumps({'passed':True,'rom_sha256':hashlib.sha256(rom).hexdigest(),'engine':'NgpCraft native core, silicon timing, clean-room HLE BIOS','controlled_fixture':True,'note':'Scores/checkpoint/death wait injected at game_tick breakpoints. Real handlers, physical menu inputs and actual flash writes used. No website submission or physical-console claim.','checks':checks},indent=2)+'\n')
m.close()
