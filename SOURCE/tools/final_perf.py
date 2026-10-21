from m16_test_support import runtime_choice
"""Stock-clock physical-input replay; exact state and resolved VRAM capture."""
from pathlib import Path
import argparse,csv,hashlib,json,os,re,shutil,subprocess,zlib
P=Path(__file__).resolve().parents[1];ap=argparse.ArgumentParser();ap.add_argument('--runtime',choices=['hardware','emulation'],default='emulation')
for n in ['mame','bios','seed','name']:ap.add_argument('--'+n,required=True)
ap.add_argument('--capture-av',action='store_true',help='Record native video and mixer audio for trailer, without changing target execution.');ap.add_argument('--stage',type=int,choices=range(1,6),required=True);ap.add_argument('--updates',type=int,default=500);ap.add_argument('--rom');ap.add_argument('--map');ap.add_argument('--sound-off',action='store_true');a=ap.parse_args()
out=P/'EVIDENCE'/a.name;out.mkdir(parents=True,exist_ok=True);(out/'RESULT.json').unlink(missing_ok=True)
for n in ['cfg','nvram']:(out/n).mkdir(exist_ok=True)
shutil.copy(a.seed,out/'nvram/ngpc');rom=Path(a.rom).resolve()if a.rom else P/'OUTPUT/Batman_The_Movie_NGPC_M18_4MB.ngc';mp=Path(a.map).resolve()if a.map else P/'EVIDENCE/batman.map'
syms={n:int(v,16)for n,v in re.findall(r'(_[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})\s+f_(?:area|data|const|code)',mp.read_text())};shutil.copy(mp,out/'batman.map');(out/'ROM_SHA256.txt').write_text(hashlib.sha256(rom.read_bytes()).hexdigest()+'\n')
if a.stage in [1,2,4]:buttons=json.loads((P/'EVIDENCE'/('FULL_LEVEL_BUTTONS.json'if a.stage==1 else f'VEHICLE{a.stage}_BUTTONS.json')).read_text())
else:
 buttons=[]
 for t in range(a.updates+10):
  if a.stage==3:k=(1,2,4,8,16,0)[(t//12)%6]if t%12<3 else 0
  else:k=(8 if t%160<100 else 4)|(16 if t%47<3 else 0)|(32 if t%89<3 else 0)|(1 if 35<=t%160<65 else 0)
  buttons.append(k)
(out/'buttons.json').write_text(json.dumps(buttons))
s=r'''local m=manager.machine;local cpu=m.devices[':maincpu'];local mem=cpu.spaces.program;local scr=m.screens[':screen'];local root=os.getenv('BATMAN_OUT')
local controls=m.ioport.ports[':Controls'].fields;local power=m.ioport.ports[':Power'].fields['Power On']
local function b(a)return mem:read_u8(a)end;local function w(a)return mem:read_u16(a)end
local function bytes(a,n)local t={}for j=0,n-1 do t[#t+1]=string.char(b(a+j))end;return table.concat(t)end
local buttons=BUTTONS;local f,menu,checked,presented=0,0,0,0;local done=false;local failure=nil;local pending=false
local states,surfaces,images,imframes,imcounts,strows,prrows,trrows,prticks={},{},{},{},{},{},{},{},{}
local first_game_time=nil;local first_game_frame=nil;local writes={0,0,0,0};local width,height=0,0
local timing_rows={};local tick_start,tick_end,timed_tick=nil,nil,0
local function written_word(addr,off,data,mask)
 local value=w(addr);for j=0,3 do local at=off+j;if at>=addr and at<addr+2 and(mask&(255<<(j*8)))~=0 then local shift=(at-addr)*8;value=(value&~(255<<shift))|(((data>>(j*8))&255)<<shift)end end;return value
end
local ts=mem:install_write_tap(GAME+38,GAME+39,'gameplay-start-time',function(off,data,mask)
 if b(MODE)==4 and b(STAGE)==TEST_STAGE then local n=written_word(GAME+38,off,data,mask);if n~=w(GAME+38)and n>=1 and n<=LIMIT then timed_tick=n;tick_start=m.time:as_double();tick_end=nil end end
end)
local te=mem:install_write_tap(LOGIC,LOGIC+1,'gameplay-end-time',function(off,data,mask)
 if tick_start and written_word(LOGIC,off,data,mask)~=w(LOGIC)then tick_end=m.time:as_double()end
end)
local vt=mem:install_write_tap(0x8200,0xbfff,'graphics-write-bytes',function(off,data,mask)
 if b(MODE)~=4 or b(STAGE)~=TEST_STAGE then return end
 local n=0;for j=0,3 do if(mask&(255<<(j*8)))~=0 then n=n+1 end end
 local k=off>=0xa000 and 1 or(off>=0x9000 and 3 or(off>=0x8800 and off<0x8c00 and 2 or((off<0x8400 or(off>=0x8c00 and off<0x8c40))and 4 or 0)))
 if k>0 then writes[k]=writes[k]+n end
end)
local function surface()
 local t={bytes(0x9000,4096),bytes(0x8200,512),bytes(0x8c00,64),bytes(0x8000,6),bytes(0x8012,7),bytes(0x8030,6),bytes(0x8020,2)}
 local first,last;if TEST_STAGE==1 or TEST_STAGE==5 then first=224;last=351 elseif TEST_STAGE==3 then first=465;last=496 else first=321;last=384 end
 t[#t+1]=bytes(0xa000,first*16);t[#t+1]=bytes(0xa000+(last+1)*16,(511-last)*16)
 for j=0,63 do local attr=w(0x8800+j*4);local xy=w(0x8802+j*4);t[#t+1]=string.pack('<I2I2',attr&0xfe00,xy);t[#t+1]=(attr&0x1800)~=0 and bytes(0xa000+(attr&511)*16,16)or string.rep('\0',16)end
 return table.concat(t)
end
local ct=mem:install_write_tap(READY,READY,'completed-graphics',function(off,data,mask)
 if b(MODE)~=4 or b(STAGE)~=TEST_STAGE then return end
 if data==1 then pending=true;if tick_start and tick_end and timed_tick>=1 and timed_tick<=LIMIT then timing_rows[#timing_rows+1]=string.format('%d,%.9f,%.9f',timed_tick,(tick_end-tick_start)*1000,(m.time:as_double()-tick_end)*1000);tick_start=nil;tick_end=nil end;return end;if data~=0 or not pending then return end;pending=false
 local ok,err=pcall(function()local i=w(VISIBLE);if i<1 or i>LIMIT then return end;assert(i>presented,'out-of-order presentation');surfaces[#surfaces+1]=surface();prticks[#prticks+1]=i;presented=i;prrows[#prrows+1]=table.concat({f,i,w(PRESENTS),w(PLATFORM_HITS),w(PLATFORM_MISSES),w(NATIVE_HITS),w(NATIVE_MISSES)},',')end)
 if not ok then failure=tostring(err)end
end)
local it=mem:install_read_tap(0x6f80,0x6f83,'physical-input',function(off,data,mask)
 local pc=cpu.state['PC'].value
 if b(MODE)==4 and b(STAGE)==TEST_STAGE and pc>=MAIN and pc<MAIN_END then
  local i=w(GAME+38);if i>checked and i<=LIMIT then if i~=checked+1 then failure='skipped state'end;states[i]=bytes(WORK,2776)..bytes(GAME,70);checked=i;strows[#strows+1]=table.concat({f,i,w(GAME+44),w(GAME+40)},',')end
  local shift=(0x6f82-off)*8;if shift>=0 and shift<=24 then return(data&~(255<<shift))|((buttons[i+1]or 0)<<shift)end
 end;return data
end)
local function save(n,h,t)local o=assert(io.open(root..'/'..n,'wb'));assert(o:write(h,'\n',table.concat(t,'\n'),'\n'));assert(o:close())end
local function binary(n,t)local o=assert(io.open(root..'/'..n,'wb'));assert(o:write(table.concat(t)));assert(o:close())end
local function observe_frame()
 if done then return end;assert(vt and ct and it and ts and te);if failure then print('REUSE_FAILURE',failure);io.stdout:flush();done=true;m:exit();return end
 f=f+1;power:set_value(1);for _,field in pairs(controls)do field:set_value(0)end
 local pc=cpu.state['PC'].value;local mode=b(MODE);local cart=pc>=0x200000 and pc<0x400000 and w(DISPLAY)>0
 if not cart and f>240 and f<3700 and f%130<10 then controls['Button A']:set_value(1)end
 if cart and mode==0 and w(DISPLAY)>=65 and w(DISPLAY)<70 then controls['Button A']:set_value(1)end
 if cart and mode==1 and menu==0 then menu=f end
 if mode==1 and menu>0 then local dt=f-menu;for n=1,TEST_STAGE-1 do if dt>=20+(n-1)*15 and dt<24+(n-1)*15 then controls['Right']:set_value(1)end end;if TEST_STAGE~=3 and dt>=110 and dt<115 then controls['Button A']:set_value(1)end;if TEST_STAGE==3 and w(DISPLAY)>=256 and w(DISPLAY)<261 then controls['Button A']:set_value(1)end end
 if mode==4 and b(STAGE)==TEST_STAGE then
  if not first_game_time then first_game_time=m.time:as_double();first_game_frame=f end
  assert(b(AUDIOFLAG)==SOUND_EXPECTED,'sound setting differs');assert(mem:read_u32(FAULT)==0,'engine fault');assert(w(MISSING)==0,'missing frame');assert(w(OVERFLOW)==0,'sprite overflow');assert(w(UNDERRUNS)==0,'audio underrun')
  local i=w(VISIBLE);if i>=1 and i<=LIMIT then local pixels,x,y=scr:pixels();images[i]=pixels;width=x;height=y;imframes[i]=f;imcounts[i]=(imcounts[i]or 0)+1 end
 end
 trrows[#trrows+1]=table.concat({f,b(MODE),w(GAME+38),w(VISIBLE),table.unpack(writes)},',');writes={0,0,0,0}
 if checked>=LIMIT and w(VISIBLE)>LIMIT then
  assert(#states==LIMIT and #surfaces==#prticks and #surfaces>0,'incomplete capture')
  save('states.csv','frame,tick,retry_wait,seconds',strows);save('presents.csv','frame,tick,presents,platform_hits,platform_misses,native_hits,native_misses',prrows);save('vram.csv','frame,mode,tick,visible_tick,patterns,sprites,maps,palettes',trrows);save('cpu_times.csv','tick,gameplay_elapsed_ms,prepare_elapsed_ms',timing_rows)
  local ir,ordered={},{};for _,i in ipairs(prticks)do assert(images[i]);ordered[#ordered+1]=images[i];ir[#ir+1]=table.concat({i,imframes[i],imcounts[i]},',')end;save('pixels.csv','tick,last_frame,display_frames',ir)
  binary('state_bytes.bin',states);binary('surface_bytes.bin',surfaces);binary('screen_pixels.bin',ordered);scr:snapshot(root..'/final.png')
  local av=assert(io.open(root..'/CAPTURE.json','w'));av:write(string.format('{"gameplay_start_time":%.9f,"gameplay_start_frame":%d,"end_time":%.9f,"end_frame":%d,"stock_clock":true,"ram_rom_writes":false}',first_game_time,first_game_frame,m.time:as_double(),f));av:close();local o=assert(io.open(root..'/RESULT.json','w'));o:write(string.format('{"passed":true,"stage":%d,"updates":%d,"width":%d,"height":%d,"state_size":%d,"surface_size":%d}',TEST_STAGE,LIMIT,width,height,#states[1],#surfaces[1]));o:close();done=true;print('BATMAN_REUSE_COMPLETE');io.stdout:flush();m:exit()
 elseif f>=20000 then failure='replay timeout';done=true;print('REUSE_FAILURE',failure);io.stdout:flush();m:exit()end
end
emu.register_frame_done(function()local ok,err=pcall(observe_frame);if not ok then done=true;print("REUSE_FAILURE",tostring(err));io.stdout:flush();m:exit()end end)
'''
if '_hardware_mode' in syms:
 s=s.replace("assert(b(AUDIOFLAG)==SOUND_EXPECTED,'sound setting differs');","assert(b("+str(syms['_hardware_mode'])+")=="+str(1 if a.runtime=='hardware' else 0)+",'startup profile differs');assert(b(AUDIOFLAG)==SOUND_EXPECTED,'sound setting differs');")
names={'MODE':'_screen_mode','STAGE':'_active_stage','GAME':'_game','WORK':'_stage_work','MAIN':'_main','MAIN_END':'_game_tile','VISIBLE':'_video_visible_tick','PRESENTS':'_video_present_count','READY':'_video_present_ready','DISPLAY':'_display_frames','FAULT':'_vm_fault','MISSING':'_native_missing_frames','OVERFLOW':'_video_overflows','UNDERRUNS':'_sampled_underruns','PLATFORM_HITS':'_graphics_platform_hits','PLATFORM_MISSES':'_graphics_platform_misses','NATIVE_HITS':'_graphics_native_hits','NATIVE_MISSES':'_graphics_native_misses'}
if '_cheat_unlocked' in syms:
 old="if mode==1 and menu>0 then local dt=f-menu;for n=1,TEST_STAGE-1 do if dt>=20+(n-1)*15 and dt<24+(n-1)*15 then controls['Right']:set_value(1)end end;if TEST_STAGE~=3 and dt>=110 and dt<115 then controls['Button A']:set_value(1)end;if TEST_STAGE==3 and w(DISPLAY)>=256 and w(DISPLAY)<261 then controls['Button A']:set_value(1)end end"
 new="""if mode==1 and menu>0 then
 local dt=f-menu
 if dt>=10 and dt<334 then local n=(dt-10)//4;if (dt-10)%4<2 then local dirs={{'Up'},{'Up','Right'},{'Right'},{'Right','Down'},{'Down'},{'Down','Left'},{'Left'},{'Left','Up'}};for _,k in ipairs(dirs[(n%8)+1])do controls[k]:set_value(1)end end end
 if dt>=345 and dt<349 then controls['Down']:set_value(1)end
 for n=1,TEST_STAGE-1 do if dt>=370+(n-1)*15 and dt<374+(n-1)*15 then controls['Right']:set_value(1)end end
 if ((TEST_STAGE~=3 and dt>=460 and dt<464)or(TEST_STAGE==3 and w(DISPLAY)>=900 and w(DISPLAY)<905))then assert(b(CHEAT_UNLOCK)==1,'ten clockwise turns failed');controls['Button A']:set_value(1)end
 end
 if mode==12 and w(DISPLAY)>=1024 and w(DISPLAY)<1029 then controls['Button A']:set_value(1)end"""
 assert old in s;s=s.replace(old,new).replace('CHEAT_UNLOCK',str(syms['_cheat_unlocked']))
 # Keep the briefing until the matched start refresh; no game RAM/ROM writes.
 # Other stages do not seed random logic from the startup display counter.
 s=s.replace('if mode==12 and w(DISPLAY)>=1024 and w(DISPLAY)<1029', 'if mode==12 and ((TEST_STAGE==3 and w(DISPLAY)>=1024 and w(DISPLAY)<1029)or(TEST_STAGE~=3))')
elif a.stage==3:
 s=s.replace('w(DISPLAY)>=256 and w(DISPLAY)<261','w(DISPLAY)>=1024 and w(DISPLAY)<1029')
for k,n in names.items():
 value=syms.get(n,0x20003c)
 if k=='MAIN_END' and value<syms['_main']:value=syms['_game_actor_count']
 s=re.sub(r'\b'+k+r'\b',str(value),s)
s=s.replace('LOGIC',str(syms['_logic_steps'])).replace('AUDIOFLAG',str(syms['_audio_enabled'])).replace('SOUND_EXPECTED','0' if a.sound_off else '1')
if a.sound_off:
 s=s.replace('local writes={0,0,0,0};','local sound_config=0;local sound_frame=0;local writes={0,0,0,0};',1)
 old="if cart and mode==1 and menu==0 then menu=f end"
 new="""if sound_config<3 then
  if cart and mode==1 and sound_config==0 then sound_frame=f;sound_config=1 end
  if mode==1 and sound_config==1 then local dt=f-sound_frame;if dt>=8 and dt<12 then controls['Down']:set_value(1)end;if dt>=22 and dt<26 then controls['Button A']:set_value(1)end end
  if mode==2 then if sound_config==1 then sound_config=2;sound_frame=f end;local dt=f-sound_frame;if dt>=8 and dt<12 then controls['Button A']:set_value(1)end;if dt>=26 and dt<30 then controls['Button B']:set_value(1);sound_config=3 end end
 end
 if cart and mode==1 and menu==0 and sound_config==3 then menu=f end"""
 assert old in s;s=s.replace(old,new)
s=s.replace('TEST_STAGE',str(a.stage)).replace('LIMIT',str(a.updates)).replace('BUTTONS','{'+','.join(map(str,buttons))+'}');s=runtime_choice(s,syms,a.runtime);(out/'input.lua').write_text(s)
env=os.environ.copy();env.update(SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',BATMAN_OUT=str(out));cmd=[str(Path(a.mame).resolve()),'ngpc','-rompath',str(Path(a.bios).resolve()),'-cart',str(rom),'-cfg_directory',str(out/'cfg'),'-nvram_directory',str(out/'nvram'),'-autoboot_script',str(out/'input.lua'),'-video','none','-sound','none','-noplugins','-skip_gameinfo','-nothrottle','-seconds_to_run','350']
if a.capture_av:cmd+=['-aviwrite',str(out/'footage.avi'),'-wavwrite',str(out/'footage.wav'),'-snapsize','160x152','-snapview','native']
with(out/'mame.log').open('w')as log:subprocess.run(cmd,env=env,stdout=log,stderr=subprocess.STDOUT,timeout=420)
log=(out/'mame.log').read_text();assert 'LUA ERROR'not in log and 'REUSE_FAILURE'not in log,log[-3000:];r=json.loads((out/'RESULT.json').read_text());assert r['passed'];r['runtime_profile']=a.runtime;r['rom_sha256']=hashlib.sha256(rom.read_bytes()).hexdigest();(out/'RESULT.json').write_text(json.dumps(r,indent=2));n=len(list(csv.DictReader((out/'presents.csv').open())))
for name,size in [('state_bytes',r['state_size']),('surface_bytes',r['surface_size']),('screen_pixels',r['width']*r['height']*4)]:
 raw=(out/(name+'.bin')).read_bytes();assert len(raw)==(a.updates if name=='state_bytes'else n)*size;(out/(name+'.sha256.json')).write_text(json.dumps([hashlib.sha256(raw[i:i+size]).hexdigest()for i in range(0,len(raw),size)]));(out/(name+'.zlib')).write_bytes(zlib.compress(raw,9));(out/(name+'.bin')).unlink()
print('PASS',out)
