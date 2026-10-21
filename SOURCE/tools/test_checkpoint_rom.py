"""Focused MAME fixture: actual respawn, checkpoint scoring, flash Save/Continue.
Injected scores/checkpoint/death-wait events make this a functional fixture,
not a naturally played leaderboard run or a hardware performance claim.
"""
from pathlib import Path
import argparse,os,re,json,subprocess,shutil,hashlib
P=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser()
for n in ['mame','bios','seed','rom','map']:a.add_argument('--'+n,required=True)
a.add_argument('--name',default='M66_CHECKPOINT_ROM');v=a.parse_args()
out=P.parent/'EVIDENCE'/v.name;out.mkdir(parents=True,exist_ok=True)
S={n:int(x,16)for n,x in re.findall(r'(_[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})\s+f_(?:area|data|const|code)',Path(v.map).read_text())}
(out/'nvram').mkdir(exist_ok=True);shutil.copy2(v.seed,out/'nvram/ngpc')
lua=r"""local m=manager.machine;local cpu=m.devices[':maincpu'];local mem=cpu.spaces.program;local root=os.getenv('BATMAN_OUT');local keys=m.ioport.ports[':Controls'].fields;local power=m.ioport.ports[':Power'].fields['Power On'];local S=SYMBOLS
local function b(x)return mem:read_u8(x)end;local function w(x)return mem:read_u16(x)end;local function l(x)return mem:read_u32(x)end
local function setscore(x)mem:write_u32(S._game+52,x)end
local function bytes(x,n)local t={}for i=0,n-1 do t[#t+1]=string.char(b(x+i))end;return table.concat(t)end
local function bank()local a=l(0x3f800c);local c=l(0x3fa00c);return(a~=0xffffffff and(c==0xffffffff or a>c))and 0x3f8000 or 0x3fa000 end
local function file(n,s)local h=assert(io.open(root..'/'..n,'wb'));h:write(s);h:close()end
local f,phase,age,oldphase=0,0,0,-1;local queue={};local qi,held,cool=1,0,0;local injected=false;local saved=false;local count=0;local observed=0;local initial_clock=0;local bios=nil
local function go(p,a)phase=p;age=0;queue=a or{};qi=1;held=0;cool=10;print('PHASE',p,f);io.stdout:flush()end
local function empty()return qi>#queue and cool==0 end
local tap=mem:install_read_tap(0x6f80,0x6f83,'score-fixture-safe-loop',function(off,data,mask)
 if b(S._screen_mode)~=4 or cpu.state['PC'].value<S._main or cpu.state['PC'].value>=S._game_tile then return data end
 if phase==2 then
  setscore(3000);mem:write_u16(S._stage_work+30,0x100);go(3)
 elseif phase==4 then setscore(4000);go(5)
 elseif phase==6 then mem:write_u16(S._game+44,1);initial_clock=l(S._run_refreshes);go(7)
 elseif phase==8 then setscore(4000);go(9)
 elseif phase==10 then setscore(4500);go(11)
 elseif phase==18 then mem:write_u16(S._game+44,1);go(19)
 elseif phase==20 then setscore(4500);go(21)
 end
 return data
end)
local done=false
local function observe()
 if done then return end;assert(tap);f=f+1;age=age+1;power:set_value(1);for _,v in pairs(keys)do v:set_value(0)end
 local mode=b(S._screen_mode);local pc=cpu.state['PC'].value;local cart=pc>=0x200000 and pc<0x400000 and w(S._display_frames)>0
 if not cart and f>240 and f%130<10 then keys['Button A']:set_value(1)end
 if cart and mode==0 and w(S._display_frames)>=65 and w(S._display_frames)<72 then keys['Button A']:set_value(1)end
 if phase==0 and cart and mode==1 then bios=bytes(0x3fc000,16384);go(1,{'Button A'})
 elseif phase==1 and mode==4 and w(S._game+38)>8 then go(2)
 elseif phase==3 and mode==4 and b(S._game+35)==1 and l(S._run_source_score)==3000 then assert(w(S._game+46)==3000 and w(S._game+48)==0,'checkpoint score not banked');go(4)
 elseif phase==5 and mode==4 and l(S._run_preview_score)==4000 then go(6)
 elseif phase==7 and mode==4 and l(S._game+52)==3000 and w(S._game+44)==0 then assert(l(S._run_preview_score)==4000,'death lost credited points');assert(l(S._run_refreshes)>=initial_clock);assert(w(S._game+40)>=479,'game countdown failed to reset');go(8)
 elseif phase==9 and mode==4 and age>12 then assert(l(S._run_preview_score)==4000,'replayed section farmed points');go(10)
 elseif phase==11 and mode==4 and l(S._run_preview_score)==4500 then go(12,{'Option'})
 elseif phase==12 and mode==5 and empty()then go(13,{'Down','Button A'})
 elseif phase==13 and mode==5 and empty()and b(S._save_available)==1 then local at=bank();assert(b(S._save_error)==0 and b(at+184)==0x66 and b(at+185)==0x99,'save marker missing');assert(l(at+104)==4500,'high water not saved');assert(w(at+512+46)==3000,'checkpoint baseline not saved');file('manual_flash.bin',bytes(0x3f8000,16384));go(14,{'Down','Down','Button A'})
 elseif phase==14 and mode==1 and empty()then go(15,{'Button A'})
 elseif phase==15 and mode==4 and empty()then assert(b(S._run_score_disabled)==0 and l(S._run_source_score)==4500,'Continue lost ranked score');assert(w(S._game+46)==3000,'Continue lost checkpoint baseline');go(18)
 elseif phase==19 and mode==4 and l(S._game+52)==3000 and w(S._game+44)==0 then assert(l(S._run_preview_score)==4500);go(20)
 elseif phase==21 and mode==4 and age>12 then
  assert(l(S._run_preview_score)==4500,'Continue allowed repeated points');assert(l(S._vm_fault)==0);assert(bytes(0x3fc000,16384)==bios,'BIOS flash changed');
  file('RESULT.json','{"passed":true,"controlled_fixture":true,"real_checkpoint_banking":true,"real_respawn":true,"timer_reset_preserved":true,"duplicate_score_blocked":true,"real_flash_save_and_continue":true,"continue_keeps_protection":true}')
  done=true;print('CHECKPOINT_SCORE_PASS');io.stdout:flush();m:exit()
 end
 if cool>0 then cool=cool-1 elseif queue[qi]then if held==0 then held=4 end;keys[queue[qi]]:set_value(1);held=held-1;if held==0 then qi=qi+1;cool=10 end end
 if f>6500 then error('checkpoint test timeout phase '..phase..' mode '..mode..' score '..l(S._game+52)..' total '..l(S._run_preview_score)..' cp '..b(S._game+35))end
end
emu.register_frame_done(function()local ok,err=pcall(observe);if not ok then file('FAILURE.txt',tostring(err));done=true;print('CHECKPOINT_SCORE_FAIL',tostring(err));io.stdout:flush();m:exit()end end)
"""
lua=lua.replace('SYMBOLS','{'+','.join('["'+n+'"]='+str(x)for n,x in S.items())+'}');(out/'test.lua').write_text(lua)
env=os.environ.copy();env.update(SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',BATMAN_OUT=str(out))
cmd=[str(Path(v.mame).resolve()),'ngpc','-rompath',str(Path(v.bios).resolve()),'-cart',str(Path(v.rom).resolve()),'-cfg_directory',str(out/'cfg'),'-nvram_directory',str(out/'nvram'),'-autoboot_delay','0','-autoboot_script',str(out/'test.lua'),'-video','none','-sound','none','-noplugins','-skip_gameinfo','-nothrottle','-seconds_to_run','130']
with(out/'mame.log').open('w')as f:subprocess.run(cmd,env=env,stdout=f,stderr=subprocess.STDOUT,timeout=180,check=True)
r=json.loads((out/'RESULT.json').read_text());r['rom_sha256']=hashlib.sha256(Path(v.rom).read_bytes()).hexdigest();(out/'RESULT.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
