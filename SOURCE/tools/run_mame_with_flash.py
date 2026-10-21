"""MAME NGPC cartridge flash persistence bridge; CPU/video timing untouched.
Stock MAME 0.289's driver serializes 0x3000 RAM + 0x20 RTC/I/O only.
Keep writable cart sectors 32/33 in an atomic sidecar, never the BIOS sector.
"""
from pathlib import Path
import argparse,os,subprocess,time
P=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--mame',required=True);a.add_argument('--bios',required=True);a.add_argument('--rom',default=str(P/'OUTPUT/Batman_M63_Final_4MB.ngc'));a.add_argument('--save-dir',default=str(P/'SAVES'));a.add_argument('extra',nargs=argparse.REMAINDER);a=a.parse_args()
rom=Path(a.rom).resolve();root=Path(a.save_dir).resolve();root.mkdir(parents=True,exist_ok=True)
sidecar=root/(rom.stem+'.flash');runtime=root/(rom.stem+'.runtime.ngc');script=root/'persist_flash.lua'
def collect():
 for path in sorted(root.glob(sidecar.name+'.pending.*')):
  if path.name.endswith('.building'):continue
  if path.stat().st_size!=16384:raise RuntimeError('Incomplete flash bridge snapshot')
  os.replace(path,sidecar)
collect()
raw=bytearray(rom.read_bytes());assert len(raw)==4194304
if sidecar.exists():
 saved=sidecar.read_bytes();assert len(saved)==16384,'Flash sidecar has wrong size; keep the existing file for recovery'
 raw[0x1f8000:0x1fc000]=saved
runtime.write_bytes(raw)
script.write_text(r'''local m=manager.machine;local mem=m.devices[':maincpu'].spaces.program;local root=os.getenv('BATMAN_FLASH_PATH');local previous=nil;local serial=0
local function persist()
 local t={}for i=0,16383 do t[#t+1]=string.char(mem:read_u8(0x3f8000+i))end;local bytes=table.concat(t)
 if bytes==previous then return end
 serial=serial+1;local ready=root..string.format('.pending.%08d',serial);local tmp=ready..'.building';local h=assert(io.open(tmp,'wb'));assert(h:write(bytes));assert(h:flush());assert(h:close());assert(os.rename(tmp,ready));previous=bytes
end
-- Read-only host polling does not add emulated CPU cycles. Retain on exit too.
local stop_subscription=emu.add_machine_stop_notifier(persist)
local f=0
emu.register_frame_done(function()assert(stop_subscription.is_active);f=f+1;if f%60==0 then persist()end end)
''')
# This polling only reads cartridge bytes; it does not execute emulated CPU work.
env=os.environ.copy();env['BATMAN_FLASH_PATH']=str(sidecar)
cmd=[str(Path(a.mame).resolve()),'ngpc','-rompath',str(Path(a.bios).resolve()),'-cart',str(runtime),'-nvram_directory',str(root/'nvram'),'-cfg_directory',str(root/'cfg'),'-autoboot_delay','0','-autoboot_script',str(script)]
extra=a.extra[1:]if a.extra[:1]==['--']else a.extra
proc=subprocess.Popen(cmd+extra,env=env)
while proc.poll()is None:
 collect();time.sleep(.2)
collect()
raise SystemExit(proc.returncode)
