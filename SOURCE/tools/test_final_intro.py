"""Full unskipped target intro: playback-driven credits, stock emulated clock."""
from pathlib import Path
import argparse,os,subprocess,re,shutil,json,hashlib
P=Path(__file__).resolve().parents[1];a=argparse.ArgumentParser()
for n in ['mame','bios','seed','rom','map']:a.add_argument('--'+n,required=True)
a.add_argument('--capture-av',action='store_true');a=a.parse_args();out=P/'EVIDENCE/FINAL_INTRO';out.mkdir(parents=True,exist_ok=True);(out/'nvram').mkdir(exist_ok=True);shutil.copy(a.seed,out/'nvram/ngpc')
syms={n:int(v,16)for n,v in re.findall(r'(_[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})\s+f_(?:area|data|const|code)',Path(a.map).read_text())}
lua=r"""local m=manager.machine;local mem=m.devices[':maincpu'].spaces.program;local scr=m.screens[':screen'];local keys=m.ioport.ports[':Controls'].fields;local power=m.ioport.ports[':Power'].fields['Power On'];local root=os.getenv('BATMAN_OUT');local S=SYMBOLS
local function b(x)return mem:read_u8(x)end;local function w(x)return mem:read_u16(x)end
local function model(n)local v=math.floor((n*4966+778)/1556);if v<120 then return 0 elseif v<2308 then return math.min(1+math.floor((v-120)/438),5)elseif v<2860 then return 6 elseif v<4720 then return math.min(7+math.floor((v-2860)/169),17)else return 18 end end
local start_time=nil;local f,start,previous,init,done=0,nil,-1,0,false;local seen={};local frames={};local oldblocks=0;local mismatches=0;local logo=nil;local cast=nil
local function observe()
 if done then return end;f=f+1;power:set_value(1);for _,v in pairs(keys)do v:set_value(0)end
 local pc=m.devices[':maincpu'].state['PC'].value;local mode=b(S._screen_mode)
 if not start then
  if mode==0 and pc>=0x200000 and pc<0x400000 and w(S._display_frames)>0 then start=f;start_time=m.time:as_double();init=w(S._sampled_underruns)
  elseif f>240 and f%130<10 then keys['Button A']:set_value(1)end
 else
  local blocks=w(S._intro_played_blocks);local card=b(S._intro_card_id)
  if mode==0 then
   assert(blocks>=oldblocks,'audio clock reversed');oldblocks=blocks
   if card~=model(blocks)and card~=model(math.max(0,blocks-1))then mismatches=mismatches+1 end
   if card~=previous then assert(card==previous+1,'intro card skipped');previous=card;seen[#seen+1]=card;frames[#frames+1]={f-start,blocks,card};print('CARD',card,blocks);io.stdout:flush();scr:snapshot(root..'/card'..card..'.png');if card==6 then logo=blocks elseif card==7 then cast=blocks end end
  elseif mode==1 then
   assert(#seen==19 and seen[1]==0 and seen[19]==18,'not all original intro cards shown');assert(blocks==1556,'intro ended on wrong audio block');assert(w(S._sampled_underruns)==init,'intro audio underrun');assert(mismatches==0,'playback/card mismatch');assert(logo==724 and cast==896,'logo/cast timing changed');scr:snapshot(root..'/title.png')
   local av=assert(io.open(root..'/CAPTURE.json','w'));av:write(string.format('{"intro_start_time":%.9f,"intro_start_frame":%d,"end_time":%.9f,"end_frame":%d,"stock_clock":true}',start_time,start,m.time:as_double(),f));av:close();local h=assert(io.open(root..'/RESULT.json','w'));h:write(string.format('{"passed":true,"cards":19,"played_blocks":%d,"logo_blocks":%d,"cast_blocks":%d,"underruns":0,"card_clock_mismatches":0,"display_refreshes":%d}',blocks,logo,cast,f-start));h:close();done=true;print('FINAL_INTRO_PASS');io.stdout:flush();m:exit()
  end
 end
 if f>13500 then error('full intro timeout')end
end
emu.register_frame_done(function()local ok,e=pcall(observe);if not ok then done=true;print('FINAL_INTRO_FAIL',tostring(e));io.stdout:flush();m:exit()end end)
"""
lua=lua.replace('SYMBOLS','{'+','.join(n+'='+str(v)for n,v in syms.items())+'}');(out/'intro.lua').write_text(lua)
env=os.environ.copy();env.update(SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',BATMAN_OUT=str(out))
cmd=[str(Path(a.mame).resolve()),'ngpc','-rompath',str(Path(a.bios).resolve()),'-cart',str(Path(a.rom).resolve()),'-cfg_directory',str(out/'cfg'),'-nvram_directory',str(out/'nvram'),'-autoboot_delay','0','-autoboot_script',str(out/'intro.lua'),'-video','none','-sound','none','-noplugins','-skip_gameinfo','-nothrottle','-seconds_to_run','230']
if a.capture_av:cmd+=['-aviwrite',str(out/'footage.avi'),'-wavwrite',str(out/'footage.wav'),'-snapsize','160x152','-snapview','native']
with(out/'mame.log').open('w')as h:subprocess.run(cmd,env=env,stdout=h,stderr=subprocess.STDOUT,check=True,timeout=300)
s=(out/'mame.log').read_text();assert 'FINAL_INTRO_PASS'in s and 'FINAL_INTRO_FAIL'not in s,s[-2500:];r=json.loads((out/'RESULT.json').read_text());r['rom_sha256']=hashlib.sha256(Path(a.rom).read_bytes()).hexdigest();(out/'RESULT.json').write_text(json.dumps(r,indent=2)+'\n');print('PASS',r)
