from m16_test_support import runtime_choice
"""Exercise the console's 300-step replay and independently audit its counters.

Only ordinary UI buttons are supplied. The ROM performs its own deterministic
replay. CPU bus taps independently count pattern reads/writes, DAC transfers
and committed sprites. This validates the diagnostic in MAME, not hardware.
"""
from pathlib import Path
import argparse,json,re,shutil,os,subprocess,hashlib,zlib
P=Path(__file__).resolve().parents[1];ap=argparse.ArgumentParser();ap.add_argument('--runtime',choices=['hardware','emulation'],default='emulation')
for name in ['mame','bios','rom','map','name']:ap.add_argument('--'+name,required=True)
ap.add_argument('--seed',default=str(P/'EVIDENCE/NVRAM_SEED_ngpc'));a=ap.parse_args()
out=P/'EVIDENCE'/a.name;out.mkdir(parents=True,exist_ok=True);(out/'RESULT.json').unlink(missing_ok=True)
for n in ['cfg','nvram']:(out/n).mkdir(exist_ok=True)
shutil.copy(a.seed,out/'nvram/ngpc');mp=Path(a.map).read_text()
symbols={n:int(v,16) for n,v in re.findall(r'(_[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})\s+f_(?:area|data|const|code)',mp)}
rom=Path(a.rom).resolve();(out/'ROM_SHA256.txt').write_text(hashlib.sha256(rom.read_bytes()).hexdigest()+'\n')
lua=r'''local m=manager.machine;local cpu=m.devices[':maincpu'];local mem=cpu.spaces.program;local scr=m.screens[':screen'];local root=os.getenv('BATMAN_OUT')
local buttons=m.ioport.ports[':Controls'].fields;local power=m.ioport.ports[':Power'].fields['Power On']
local function b(x)return mem:read_u8(x)end;local function w(x)return mem:read_u16(x)end;local function l(x)return mem:read_u32(x)end
local fields={'refreshes','updates','source_updates','presents','max_step_gap','max_draw_gap','peak_sprites','overflows','irq','blocks','underruns','fill_max','hits','misses','pattern_bytes','pattern_scan_bytes','descriptor_bytes','rtc_seconds','rtc_warning','pcm_min','pcm_max','live','armed'}
local offsets={};for i,n in ipairs(fields)do offsets[n]=w(LAYOUT+i*2)end
local function field(n)local x=PERF+offsets[n];if n=='rtc_warning'or n=='pcm_min'or n=='pcm_max'or n=='live'or n=='armed'then return b(x)end;if n=='pattern_bytes'or n=='pattern_scan_bytes'or n=='descriptor_bytes'then return l(x)end;return w(x)end
local f,case,phase,due,pulse,until_frame=0,1,'boot',0,nil,0;local report_page=0;local results={};local states={};local done=false
local observed=false;local observed_writes,observed_reads,dac_samples,sprite_peak=0,0,0,0;local first_time,last_time=0,0
local function maskbytes(mask)local n=0;for j=0,3 do if(mask&(255<<(8*j)))~=0 then n=n+1 end end;return n end
local live_addr=PERF+offsets.live
local lt=mem:install_write_tap(live_addr,live_addr,'measurement-window',function(off,data,mask)
 local shift=(live_addr-off)*8;if shift<0 or shift>24 or(mask&(255<<shift))==0 then return end;local value=(data>>shift)&255
 if value==1 and not observed then observed=true;observed_writes=0;observed_reads=0;dac_samples=0;sprite_peak=0;first_time=m.time:as_double()
 elseif value==0 and observed then observed=false;last_time=m.time:as_double()end
end)
local wt=mem:install_write_tap(0xa000,0xbfff,'independent-pattern-writes',function(off,data,mask)if observed then observed_writes=observed_writes+maskbytes(mask)end end)
local rt=mem:install_read_tap(0xa000,0xbfff,'independent-pattern-reads',function(off,data,mask)if observed then observed_reads=observed_reads+maskbytes(mask)end end)
local dt=mem:install_write_tap(0xa2,0xa3,'independent-dac-writes',function(off,data,mask)if observed then dac_samples=dac_samples+maskbytes(mask)/2 end end)
local pt=mem:install_write_tap(READY,READY,'sprite-audit',function(off,data,mask)
 if observed and data==0 then local n=0;for i=0,63 do if(w(0x8800+i*4)&0x1800)~=0 then n=n+1 end end;if n>sprite_peak then sprite_peak=n end end
end)
local function press(n,next_phase,wait)pulse=n;until_frame=f+4;due=f+(wait or 15);phase=next_phase end
local function snapshot(page)local stage=(case+1)//2;local audio=(case&1)==1 and'on'or'off';scr:snapshot(root..'/level'..stage..'_'..audio..'_page'..page..'.png')end
local function capture()
 assert(w(CODEC_CHECKED)==1280,'codec selftest did not complete');assert(w(CODEC_FAILURES)==0,'codec selftest failed');assert(l(FAULT)==0,'translated gameplay fault')
 local r={stage=(case+1)//2,sound=(case&1)==1,observed_seconds=last_time-first_time,observed_pattern_writes=observed_writes,observed_pattern_reads=observed_reads,observed_dac_samples=dac_samples,observed_sprite_peak=sprite_peak}
 for _,n in ipairs(fields)do if n~='live'and n~='armed'then r[n]=field(n)end end
 assert(r.updates==300,'replay did not execute 300 steps');assert(r.rtc_warning==0 and r.rtc_seconds~=65535,'RTC cross-check failed');assert(r.overflows==0,'sprite overflow');assert(r.underruns==0,'sampled audio underrun');if r.sound then assert(math.abs(r.blocks-r.irq)<=1,'audio buffer filled more than once per DMA completion')end
 assert(r.pattern_bytes==observed_writes,'pattern-write counter differs from CPU bus');assert(r.pattern_scan_bytes==observed_reads,'pattern-read counter differs from CPU bus');assert(r.peak_sprites==sprite_peak,'sprite peak differs from hardware descriptors')
 local expected=r.observed_seconds*6144000/(515*199);assert(math.abs(expected-r.refreshes)<2,'refresh counter differs from display timing')
 if r.sound then local rate=dac_samples/r.observed_seconds;assert(rate>4700 and rate<4900,'incorrect DAC sample rate');assert(math.abs(dac_samples-r.irq*256)<520,'DMA completion count differs from DAC writes');assert(r.pcm_max>r.pcm_min,'sampled music is constant')
 else assert(dac_samples==0 and r.irq==0 and r.blocks==0,'audio work continues while disabled')end
 local t={};for i=0,2775 do t[#t+1]=string.char(b(WORK+i))end;for i=0,69 do t[#t+1]=string.char(b(GAME+i))end
 local state=table.concat(t);states[#states+1]=state
 local o=assert(io.open(root..'/case'..case..'.json','w'));o:write('{');local sep='';for k,v in pairs(r)do o:write(sep,string.format('%q',k),':',tostring(v));sep=','end;o:write('}');o:close();results[#results+1]=r
 if case%2==0 then assert(states[#states]==states[#states-1],'sound ON/OFF produced different gameplay state')end
end
emu.register_frame_done(function()
 if done then return end;assert(lt and wt and rt and dt and pt);f=f+1;power:set_value(1);for _,v in pairs(buttons)do v:set_value(0)end
 if pulse and f<until_frame then buttons[pulse]:set_value(1);return end;pulse=nil;if f<due then return end
 local mode=b(MODE);local pc=cpu.state['PC'].value
 if phase=='boot'and mode==0 and pc>=0x200000 and pc<0x400000 and w(DISPLAY)>=65 and w(DISPLAY)<72 then buttons['Button A']:set_value(1)end
 if mode==1 and pc>=0x200000 and pc<0x400000 and w(DISPLAY)>0 and phase=='boot'then press('Button B','menu',20)
 elseif phase=='boot'and f>240 and f%130<10 then buttons['Button A']:set_value(1)
 elseif mode==9 and phase=='menu'then
  if case>10 then
   local o=assert(io.open(root..'/state_bytes.bin','wb'));for _,s in ipairs(states)do o:write(s)end;o:close();o=assert(io.open(root..'/RESULT.json','w'));o:write('{"passed":true,"cases":10,"codec_words_checked":1280,"hardware_verified":false}');o:close();done=true;print('HARDWARE_DIAG_AUDIT_COMPLETE');io.stdout:flush();m:exit();return
  end
  local target=(case+1)//2;local audio=(case&1)==1 and 1 or 0
  if b(STAGE)~=target then press('Right','menu',18)elseif b(AUDIO)~=audio then press('Button A','menu',18)else press('Button B','running',20)end
 elseif mode==10 and phase=='running'then capture();phase='report';report_page=0;due=f+16
 elseif mode==10 and phase=='report'then snapshot(report_page);if report_page<3 then report_page=report_page+1;press('Right','report',18)else case=case+1;press('Button B','menu',18)end
 end
 if f>26000 then done=true;print('HARDWARE_DIAG_FAILURE',phase,case,mode);io.stdout:flush();m:exit()end
end)
'''
lua=lua.replace("assert(r.updates==300,'replay did not execute 300 steps');","assert(r.updates==300,'replay did not execute 300 steps');assert(r.presents==300,'one presentation is required for every original update');")
lua=lua.replace('emu.register_frame_done(function()', 'local function observe_frame()', 1)
end=lua.rfind('end)');lua=lua[:end]+'end\nemu.register_frame_done(function()local ok,err=pcall(observe_frame);if not ok then done=true;print(\"HARDWARE_DIAG_FAILURE\",tostring(err));io.stdout:flush();m:exit()end end)'+lua[end+4:]
for key,name in {'PERF':'_hardware_perf','LAYOUT':'_hardware_perf_offsets','MODE':'_screen_mode','STAGE':'_active_stage','AUDIO':'_audio_enabled','READY':'_video_present_ready','DISPLAY':'_display_frames','GAME':'_game','WORK':'_stage_work','FAULT':'_vm_fault','CODEC_CHECKED':'_perf_codec_checked','CODEC_FAILURES':'_perf_codec_failures'}.items():
    lua=re.sub(r'\b'+key+r'\b',str(symbols[name]),lua)
lua=runtime_choice(lua,symbols,a.runtime);(out/'audit.lua').write_text(lua);env=os.environ.copy();env.update(SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',BATMAN_OUT=str(out))
cmd=[str(Path(a.mame).resolve()),'ngpc','-rompath',str(Path(a.bios).resolve()),'-cart',str(rom),'-cfg_directory',str(out/'cfg'),'-nvram_directory',str(out/'nvram'),'-autoboot_script',str(out/'audit.lua'),'-video','none','-sound','none','-noplugins','-skip_gameinfo','-nothrottle','-seconds_to_run','440']
with(out/'mame.log').open('w')as log:subprocess.run(cmd,env=env,stdout=log,stderr=subprocess.STDOUT,timeout=600,check=True)
log=(out/'mame.log').read_text();assert 'LUA ERROR'not in log and 'HARDWARE_DIAG_FAILURE'not in log,log[-2500:]
result=json.loads((out/'RESULT.json').read_text());assert result['passed']
cases=[json.loads((out/f'case{i}.json').read_text())for i in range(1,11)];result['runtime_profile']=a.runtime;result['rom_sha256']=hashlib.sha256(rom.read_bytes()).hexdigest();result['measurements']=cases
raw=(out/'state_bytes.bin').read_bytes();assert len(raw)==10*2846;result['state_sha256']=[hashlib.sha256(raw[i:i+2846]).hexdigest()for i in range(0,len(raw),2846)];(out/'state_bytes.zlib').write_bytes(zlib.compress(raw,9));(out/'state_bytes.bin').unlink();(out/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n')
print('PASS',out)
