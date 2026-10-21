"""Target-ROM feature fixtures, deliberately separate from performance replays.
Completion fixtures force a terminal event; they are not evidence of a played clear.
Every menu operation and all flash writes execute the actual cartridge code.
"""
from pathlib import Path
import argparse,subprocess,sys,os,re,json,hashlib,shutil
P=Path(__file__).resolve().parents[1]
ap=argparse.ArgumentParser()
for n in ['mame','bios','seed','rom','map']:ap.add_argument('--'+n,required=True)
ap.add_argument('--case',required=True,choices=['campaign','continue_auto','resume_manual','cheat_save','cheat_resume','fresh_after_cheat','qr','reset','lives_save','lives_resume','fresh_three','zero_upload','legacy_resume','cheat_campaign','gameover_points','quick_death','ending','restart_points','grapple','cat_grapple','m62_resume','m62_profile_migration','menu_credits','reset_cold','ui_stress','stage_qr'])
ap.add_argument('--flash',type=Path);ap.add_argument('--name');a=ap.parse_args()
out=P/'EVIDENCE/FINAL_FEATURES'/(a.name or a.case);out.mkdir(parents=True,exist_ok=True);(out/'RESULT.json').unlink(missing_ok=True)
syms={n:int(v,16)for n,v in re.findall(r'(_[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})\s+f_(?:area|data|const|code)',Path(a.map).read_text())}
raw=bytearray(Path(a.rom).read_bytes())
if a.flash:
 data=a.flash.read_bytes();assert len(data)==16384;raw[0x1f8000:0x1fc000]=data
rom=out/'runtime.ngc';rom.write_bytes(raw)
(out/'nvram').mkdir(exist_ok=True);shutil.copy2(a.seed,out/'nvram/ngpc')
lua=r'''local m=manager.machine;local cpu=m.devices[':maincpu'];local mem=cpu.spaces.program;local scr=m.screens[':screen'];local keys=m.ioport.ports[':Controls'].fields;local power=m.ioport.ports[':Power'].fields['Power On'];local root=os.getenv('BATMAN_OUT')
local S=SYMBOLS;local CASE='CASE_NAME'
local function b(x)return mem:read_u8(x)end;local function w(x)return mem:read_u16(x)end;local function l(x)return mem:read_u32(x)end
local function bytes(x,n)local t={}for i=0,n-1 do t[#t+1]=string.char(b(x+i))end;return table.concat(t)end
local function file(n,data)local h=assert(io.open(root..'/'..n,'wb'));assert(h:write(data));h:close()end
local function snap(n)scr:snapshot(root..'/'..n..'.png')end
local function bank()local a=l(0x3f800c);local c=l(0x3fa00c);return(a~=0xffffffff and(c==0xffffffff or a>c))and 0x3f8000 or 0x3fa000 end
local function flash(n)file(n..'.bin',bytes(0x3f8000,16384))end
local f,age,step,stable,oldmode=0,0,0,0,255;local queue={};local qi=1;local held=0;local cool=0;local done=false
local stage_qr_index=1;local page_ready=0;local qr_ready_refresh=0;local bindings=0;local points_at=0;local last_preview=0;local ending_seen={};local ending_previous=-1;local ending_start=0;local ending_photo=-1;local ending_photo_due=0;local frozen=0;local previous_ticks=0;local finished_stage=0;local bios=nil;local matched=false;local expected=nil;local best_before=0
local function go(n,actions)step=n;age=0;queue=actions or{};qi=1;held=0;cool=12;print('STEP',n,f,CASE);io.stdout:flush()end
local function empty()return qi>#queue and cool==0 end
local function finish()
 assert(l(S._vm_fault)==0,'VM fault');assert(w(S._sampled_underruns)==0,'audio underrun');assert(bytes(0x3fc000,16384)==bios,'BIOS flash modified')
 local low=0x7f80;for at=0x7800,0x7f7f do if b(at)~=0xa5 then low=at;break end end;assert(low>0x7810,'stack guard exhausted')
 file('RESULT.json',string.format('{"passed":true,"case":"%s","controlled_completion_fixture":%s,"best_score":%d,"best_ticks":%d,"stack_lowest_written":%d,"binding_checks":%d,"credits_cards":%d,"credits_played_blocks":%d,"credits_refreshes":%d}',CASE,(CASE=='campaign'or CASE=='cheat_campaign'or CASE=='ending')and'true'or'false',l(S._best_score),l(S._best_run_ticks),low,bindings,#ending_seen,ending_start>0 and w(S._intro_played_blocks)or 0,ending_start>0 and f-ending_start or 0));done=true;print('FINAL_FEATURE_PASS',CASE);io.stdout:flush();m:exit()
end
local function new_game_actions()return b(S._save_available)==1 and{'Down','Button A'}or{'Button A'}end
local ui_armed=false;local ui_windows=0;local ui_patterns=0;local ui_checks=0;local ui_cursor_seen=0
local ui_window_tap=mem:install_write_tap(0x8002,0x8005,'UI-window-writes',function(off,data,mask)if ui_armed then ui_windows=ui_windows+1 end;return data end)
local ui_pattern_tap=mem:install_write_tap(0xa000,0xbfff,'UI-pattern-writes',function(off,data,mask)if ui_armed then ui_patterns=ui_patterns+1 end;return data end)
local function ui_check()assert(ui_windows==0,'menu edit hid the display');assert(ui_patterns==0,'menu edit reloaded graphics');ui_checks=ui_checks+1 end
local function ui_pairs(n)local a={}for i=1,n do a[#a+1]='Down';a[#a+1]='Up'end;return a end
local gameplay_buttons=REPLAY_BUTTONS
local input_tap=mem:install_read_tap(0x6f80,0x6f83,'cold-manual-restore',function(off,data,mask)
 if (CASE=='resume_manual'or CASE=='legacy_resume'or CASE=='m62_resume'or CASE=='m62_profile_migration')and (step==1 or(CASE=='m62_profile_migration'and step==3)) and b(S._screen_mode)==4 and cpu.state['PC'].value>=S._main and cpu.state['PC'].value<S._game_tile then
  local at=bank();local n=w(at+28);assert(n>0);if CASE=='legacy_resume'then assert(bytes(S._game,52)==bytes(at+512,52)and bytes(S._game+56,14)==bytes(at+568,14),'legacy non-score Game differs')else assert(bytes(S._game,70)==bytes(at+512,70),'cold restore Game differs')end;assert(bytes(S._stage_work,2776)==bytes(at+582,2776),'cold restore stage RAM differs');matched=true
 end
 if CASE=='grapple'and step==1 and b(S._screen_mode)==4 and cpu.state['PC'].value>=S._main and cpu.state['PC'].value<S._game_tile then local i=w(S._game+38);local shift=(0x6f82-off)*8;if shift>=0 and shift<=24 then return(data&~(255<<shift))|(((i<8 and gameplay_buttons[i+1]or 0))<<shift)end end
 if CASE=='gameover_points'and b(S._screen_mode)==4 and cpu.state['PC'].value>=S._main and cpu.state['PC'].value<S._game_tile then local i=w(S._game+38);local shift=(0x6f82-off)*8;if shift>=0 and shift<=24 then return(data&~(255<<shift))|(((i<200 and gameplay_buttons[i+1]or 0))<<shift)end end
 if CASE=='qr'and step==3 and qr_ready_refresh==0 and b(S._screen_mode)==19 and cpu.state['PC'].value>=S._main and cpu.state['PC'].value<S._game_tile then qr_ready_refresh=f end
 return data
end)
local command_tap=mem:install_write_tap(S._stage_work+42,S._stage_work+42,'platform-action-command',function(off,data,mask)
 if (CASE=='grapple'or CASE=='cat_grapple')and b(S._screen_mode)==4 then
  local value=data&255
  if step==4 and value==20 then bindings=bindings|1 end
  if step==5 and value==16 then bindings=bindings|2 end
  if step==6 and value==24 then bindings=bindings|4 end
 end
 return data
end)
local function observe()
 if done then return end;assert(input_tap and command_tap);f=f+1;age=age+1;power:set_value(1);for _,v in pairs(keys)do v:set_value(0)end
 local mode=b(S._screen_mode);if mode==oldmode then stable=stable+1 else stable=0;oldmode=mode end
 if mode==4 and b(S._run_active)==1 and b(S._run_cheated)==0 and b(S._run_score_disabled)==0 then local v=l(S._run_preview_score);assert(v>=last_preview,'points count backwards');last_preview=v end
 local pc=cpu.state['PC'].value;local cart=pc>=0x200000 and pc<0x400000 and w(S._display_frames)>0
 if cart and mode==0 and w(S._display_frames)>=65 and w(S._display_frames)<72 then keys['Button A']:set_value(1)end
 if not cart and f>240 and f<3700 and f%130<10 then keys['Button A']:set_value(1)end
 if step==0 and cart and mode==1 and stable>16 then
  bios=bytes(0x3fc000,16384);best_before=l(S._best_score);snap('title')
  if CASE=='ui_stress'then assert(best_before>0);ui_armed=true;go(1,ui_pairs(8))
  elseif CASE=='menu_credits'then go(8,{'Down','Down','Down','Button A'})
  elseif CASE=='cat_grapple'then local actions={};for i=1,10 do for _,k in ipairs({'Up','Right','Down','Left'})do actions[#actions+1]=k end end;for _,k in ipairs({'Up','Down','Down','Button A','Down','Down','Down','Down','Down','Left','Button B','Button A'})do actions[#actions+1]=k end;go(1,actions)
  elseif CASE=='gameover_points'or CASE=='quick_death'or CASE=='restart_points'or CASE=='grapple'then go(1,new_game_actions())
  elseif CASE=='lives_save'then go(1,{'Down','Button A','Down','Right','Right','Right','Right','Right','Right','Button B'})
  elseif CASE=='fresh_three'then go(1,{'Down','Down','Button A','Down','Left','Left','Left','Left','Left','Left','Button B'})
  elseif CASE=='m62_profile_migration'then assert(best_before==0 and b(bank()+39)==0x62);expected=l(bank()+40);go(1,{'Down','Down','Button A'})
  elseif CASE=='m62_resume'then assert(best_before==0 and b(bank()+39)==0x62);expected=l(bank()+40);go(1,{'Button A'})
  elseif CASE=='lives_resume'or CASE=='legacy_resume'then assert(b(S._save_available)==1);expected=l(bank()+40);go(1,{'Button A'})
  elseif CASE=='reset_cold'then assert(best_before==0 and l(S._last_score)==0 and l(bank()+16)==0 and l(bank()+20)==0,'reset was not saved as zero');go(1,b(S._save_available)==1 and{'Down','Down','Down','Button A'}or{'Down','Down','Button A'})
  elseif CASE=='zero_upload'then assert(best_before==0);go(1,{'Down','Down','Button A'})
 elseif CASE=='campaign'or CASE=='ending'then assert(b(S._cheat_unlocked)==0);go(1,new_game_actions())
  elseif CASE=='continue_auto'or CASE=='resume_manual'or CASE=='cheat_resume'then
   assert(b(S._save_available)==1);expected=l(bank()+40);go(1,{'Button A'})
  elseif CASE=='fresh_after_cheat'then assert(b(S._cheat_unlocked)==0);go(1,new_game_actions())
  elseif CASE=='cheat_save'or CASE=='cheat_campaign'then local a={};for i=1,10 do for _,k in ipairs({'Up','Right','Down','Left'})do a[#a+1]=k end end;a[#a+1]='Up';a[#a+1]='Down';a[#a+1]='Button A';go(1,a)
  elseif CASE=='stage_qr'then go(1,b(S._save_available)==1 and{'Down','Down','Down','Button A'}or{'Down','Down','Button A'})
  elseif CASE=='qr'or CASE=='reset'then local a={};local n=b(S._save_available)==1 and 3 or 2;for i=1,n do a[#a+1]='Down'end;a[#a+1]='Button A';go(1,a)
  end
 end
 if CASE=='ui_stress'then
  if ui_armed then ui_check()end
  if step==1 and mode==1 and empty()then ui_armed=false;snap('title_navigation');go(2,{'Down','Button A'})
  elseif step==2 and mode==2 and empty()and stable>20 then ui_armed=true;go(3,ui_pairs(8))
  elseif step==3 and mode==2 and empty()then ui_armed=false;snap('options_navigation');go(4,{'Button B'})
  elseif step==4 and mode==1 and empty()and stable>20 then go(5,{'Down','Down','Button A'})
  elseif step==5 and mode==13 and empty()and stable>20 then ui_armed=true;go(6,ui_pairs(8))
  elseif step==6 and mode==13 and empty()then ui_armed=false;snap('records_navigation');go(7,{'Button A'})
  elseif step==7 and mode==17 and empty()and stable>20 then
   snap('initials_first_selected');ui_armed=true;local a={};for slot=1,3 do for i=1,28 do a[#a+1]='Up'end;a[#a+1]='Right'end;go(8,a)
  elseif step==8 and mode==17 then
   if cool>=3 and cool<=7 then
    local cursor=b(S._leaderboard_cursor);assert(cursor<3);ui_cursor_seen=ui_cursor_seen|(1<<cursor)
    for i=0,2 do local pal=(w(0x9000+2*(5*32+4+i*4))>>9)&15;assert(pal==(i==cursor and 13 or 15),'selected initial has no highlight')end
    if cool==6 then snap('initials_slot'..cursor)end
   end
   if empty()then ui_check();assert(ui_cursor_seen==7,'not all three initial positions tested');ui_armed=false;file('UI_RESULT.json',string.format('{"passed":true,"window_writes_during_edits":%d,"pattern_writes_during_edits":%d,"frames_checked":%d,"initial_positions_checked":3,"alphabet_steps":84}',ui_windows,ui_patterns,ui_checks));finish()end
  end
 elseif CASE=='gameover_points'or CASE=='quick_death'then
  if step==1 and mode==4 then
   if CASE=='quick_death'and w(S._game+38)>=3 then assert(l(S._run_preview_score)==0);mem:write_u8(S._game+33,1);go(2)
   elseif CASE=='gameover_points'and w(S._game+38)>=200 then assert(l(S._run_preview_score)>0 and b(S._run_completed_mask)==0,'no points earned in original gameplay');points_at=l(S._run_preview_score);snap('earned_points');mem:write_u8(S._game+33,1);go(2)end
  elseif step==2 and mode==6 and stable>30 then assert((CASE=='quick_death'and l(S._last_score)==0)or(CASE=='gameover_points'and l(S._last_score)>=points_at and l(S._last_score)==l(S._run_preview_score)),'game-over score was not recorded');assert(l(S._best_score)>=l(S._last_score));assert(b(bank()+39)==0x63 and b(S._save_error)==0);flash('gameover_flash');snap('game_over_recorded');go(3,{'Button A'})
  elseif step==3 and mode==1 and empty()and stable>15 then go(4,{'Down','Down','Button A'})
  elseif step==4 and mode==13 and empty()and stable>15 then snap('gameover_records');finish()end
 elseif CASE=='menu_credits'then
  if step==8 and mode==16 then
   if ending_start==0 then ending_start=f end;local card=b(S._ending_card_id);if card<15 and card~=ending_previous then assert(card==ending_previous+1,'menu credits skipped a card');ending_previous=card;ending_seen[#ending_seen+1]=card;ending_photo=card;ending_photo_due=f+6 end
   if ending_photo>=0 and f>=ending_photo_due and card==ending_photo and b(0x8004)==160 and b(0x8005)==152 then snap('credits_card'..card);ending_photo=-1 end
  elseif step==8 and mode==1 and ending_start>0 then assert(#ending_seen==15 and w(S._intro_played_blocks)==1556,'menu credits theme stopped early');snap('credits_finished');finish()end
 elseif CASE=='grapple'or CASE=='cat_grapple'then
  if step==1 and mode==4 and empty()and((CASE=='grapple'and b(S._game+22)==4)or(CASE=='cat_grapple'and w(S._game+38)>=8))then assert(b(S._active_stage)==(CASE=='cat_grapple'and 5 or 1));snap('before_option_pause');go(2,{'Option'})
  elseif step==2 and mode==5 and empty()and stable>10 then snap('option_pause');go(3,{'Button B'})
  elseif step==3 and mode==4 and empty()then go(4)
  elseif step==4 and mode==4 then
   keys['Down']:set_value(1);if age%12<6 then keys['Button B']:set_value(1)end
   if(bindings&1)~=0 then snap('down_B_drop_command');go(5)end
  elseif step==5 and mode==4 then
   keys['Down']:set_value(1);if age%12<6 then keys['Button A']:set_value(1)end
   if(bindings&2)~=0 then go(6)end
  elseif step==6 and mode==4 then
   if age%12<6 then keys['Button B']:set_value(1)end
   if(bindings&4)~=0 then go(7,{'Option'})end
  elseif step==7 and mode==5 and empty()and stable>10 then assert(bindings==7);snap('final_option_pause');finish()end
 elseif CASE=='m62_resume'or CASE=='m62_profile_migration'then
  if CASE=='m62_profile_migration'and step==1 and mode==2 and empty()and stable>15 then go(2,{'Button B'})
  elseif CASE=='m62_profile_migration'and step==2 and mode==1 and empty()and stable>15 then assert(b(bank()+39)==0x63);go(3,{'Button A'})
  elseif matched then assert(b(S._run_score_disabled)==0 and b(S._run_cheated)==0,'M62 Continue lost eligibility');assert(l(S._run_refreshes)>=expected and l(S._run_refreshes)-expected<10);assert(l(S._run_bonus_score)>0 and l(S._run_preview_score)>=l(S._run_bonus_score),'M62 earned checkpoint points not migrated');snap('m62_save_continued');finish()end
 elseif CASE=='restart_points'then
  if step==1 and mode==4 and w(S._game+38)>8 then mem:write_u32(S._game+52,1500);go(2)
  elseif step==2 and mode==4 and l(S._run_preview_score)==1500 then frozen=l(S._run_refreshes);go(3,{'Option'})
  elseif step==3 and mode==5 and empty()and stable>15 then go(4,{'Down','Down','Button A'})
  elseif step==4 and mode==4 and w(S._game+38)>12 then assert(l(S._run_preview_score)==1500 and l(S._run_refreshes)>frozen,'restart lost earned points or elapsed time');mem:write_u32(S._game+52,1800);go(5)
  elseif step==5 and mode==4 and l(S._run_preview_score)==1800 then mem:write_u8(S._game+33,1);go(6)
  elseif step==6 and mode==6 and stable>30 then assert(l(S._last_score)==1800 and l(S._best_score)==1800);snap('restart_points_kept');finish()end
 elseif CASE=='campaign'or CASE=='cheat_campaign'or CASE=='ending'then
  if step==1 and mode==4 and w(S._game+38)>=30 then assert(b(S._run_cheated)==(CASE=='cheat_campaign'and 1 or 0) and b(S._run_score_disabled)==0);go(2,{'Option'})
  elseif step==2 and mode==5 and empty()and stable>15 then frozen=l(S._run_refreshes);go(3)
  elseif step==3 and mode==5 and age>120 then assert(l(S._run_refreshes)==frozen,'pause clock advanced');go(4,{'Button B'})
  elseif step==4 and mode==4 and age>100 then assert(l(S._run_refreshes)>frozen,'active clock stopped');mem:write_u8(S._game+66,4);go(5)
  elseif step==5 and mode==7 and stable>30 then
   local at=bank();local stage=b(S._active_stage);assert(b(S._save_error)==0,'autosave failed');assert(b(at+39)==0x65);assert(b(at+10)==(CASE=='cheat_campaign'and 1 or 0) and b(at+37)==0xa0,'run eligibility changed');assert(b(at+68)==(1<<stage)-1,'completed stage mask incorrect');assert(l(at+40)==l(S._run_refreshes),'checkpoint clock differs');
   finished_stage=stage;previous_ticks=l(S._run_refreshes)
   if stage<5 then assert(b(at+5)==2 and b(at+6)==stage+1,'wrong next-stage checkpoint');assert(b(S._save_available)==1);if stage==1 then flash('autosave_l1_flash')end
   else assert(b(at+5)==0 and b(S._save_available)==0);if CASE=='cheat_campaign'then assert(l(S._best_score)==best_before and l(S._last_score)==0 and b(S._last_score_cheated)==1,'cheat finish registered points')else local budgets={480,300,60,180,720};local bonus=0;for i=0,4 do bonus=bonus+math.max(0,budgets[i+1]-math.floor(l(S._best_stage_ticks+i*4)*20/1199))*100 end;assert(l(S._best_score)==math.min(999999,l(S._best_source_score)+bonus)and l(S._best_score)>0,'earned points/clear bonus wrong');assert(l(S._last_score)==l(S._best_score));local sum=0;for i=0,4 do sum=sum+l(S._best_stage_ticks+i*4)end;assert(sum==l(S._best_run_ticks),'split sum differs')end;flash('completed_flash')end
   snap('stage'..stage..'_saved');go(6)
  elseif step==6 and mode==7 then
   assert(l(S._run_refreshes)==previous_ticks,'cutscene clock advanced')
   if b(S._ui_choice)==2 and b(0x8004)==160 and b(0x8005)==152 then page_ready=page_ready+1 else page_ready=0 end
   if page_ready>=4 and empty()then page_ready=0; snap('stage'..finished_stage..'_summary');if finished_stage==5 then if CASE=='ending'then go(8,{'Button A'})else finish()end else go(7,{'Button A'})end end
  elseif step==8 and mode==16 then
   if ending_start==0 then ending_start=f;assert(w(S._intro_played_blocks)<10)end
   local card=b(S._ending_card_id);if card<15 and card~=ending_previous then assert(card==ending_previous+1,'ending card skipped');ending_previous=card;ending_seen[#ending_seen+1]=card;ending_photo=card;ending_photo_due=f+6 end
   if ending_photo>=0 and f>=ending_photo_due and card==ending_photo and b(0x8004)==160 and b(0x8005)==152 then snap('ending_card'..card);ending_photo=-1 end
  elseif step==8 and mode==1 then assert(#ending_seen==15 and w(S._intro_played_blocks)==1556,'ending theme stopped early');snap('ending_finished');finish()
  elseif step==7 and mode==4 and w(S._game+38)>=30 then assert(b(S._active_stage)==finished_stage+1);mem:write_u8(S._game+66,4);go(5)
  end
 elseif CASE=='lives_save'or CASE=='fresh_three'then
  if step==1 and mode==1 and empty()and stable>15 then assert(b(S._option_lives)==(CASE=='lives_save'and 9 or 3));if CASE=='fresh_three'then assert(b(bank()+37)==0xa1,'preference change requalified saved run');flash('three_pref_flash')end;go(2,new_game_actions())
  elseif step==2 and mode==4 and w(S._game+38)>8 then
   assert(b(S._run_score_disabled)==(CASE=='lives_save'and 1 or 0));assert(l(S._run_preview_score)==0,'starting without earning points grants a score')
   if CASE=='fresh_three'then finish()else go(3,{'Option'})end
  elseif step==3 and mode==5 and empty()and stable>15 then go(4,{'Down','Button A'})
  elseif step==4 and mode==5 and empty()and b(S._save_kind)==1 then assert(b(bank()+37)==0xa1 and b(S._save_error)==0);flash('nine_lives_flash');finish()end
 elseif CASE=='lives_resume'then
  if step==1 and mode==4 and w(S._game+38)>8 then assert(b(S._option_lives)==b(bank()+8) and b(S._run_score_disabled)==1 and l(S._run_preview_score)==0);assert(l(S._best_score)==best_before);finish()end
 elseif CASE=='legacy_resume'then
  if matched then assert(b(S._run_score_disabled)==1 and l(S._best_score)==0 and l(S._run_preview_score)==0,'legacy run requalified');finish()end
 elseif CASE=='zero_upload'or CASE=='reset_cold'then
  if step==1 and mode==13 and empty()and stable>15 then snap('zero_records');go(2,{'Button A'})
  elseif step==2 and mode==13 and empty()and stable>15 then assert(l(S._best_score)==0);snap('zero_upload_locked');finish()end
 elseif CASE=='continue_auto'then
  if step==1 and mode==12 then assert(b(S._active_stage)==2 and l(S._run_refreshes)==expected);assert(b(S._run_completed_mask)==1);go(2)
  elseif step==2 and mode==4 and w(S._game+38)>=30 then assert(l(S._run_refreshes)>expected and b(S._run_cheated)==0);go(3,{'Option'})
  elseif step==3 and mode==5 and empty()and stable>15 then frozen=l(S._run_refreshes);go(4,{'Down','Button A'})
  elseif step==4 and mode==5 and empty()and b(S._save_kind)==1 then assert(b(S._save_error)==0);assert(l(bank()+40)==frozen);assert(b(bank()+6)==2);flash('manual_flash');snap('manual_saved');finish()end
 elseif CASE=='resume_manual'then
  if matched then assert(b(S._active_stage)==2 and b(S._run_cheated)==0);assert(l(S._run_refreshes)>=expected and l(S._run_refreshes)-expected<10);snap('manual_resumed');finish()end
 elseif CASE=='cheat_save'then
  if step==1 and mode==4 and w(S._game+38)>=30 then assert(b(S._cheat_unlocked)==1 and b(S._cheat_invulnerable)==0 and b(S._cheat_freeze_time)==0,'cheat fixture toggled a cheat');assert(b(S._run_cheated)==1 and l(S._run_preview_score)==0,'unlock alone must disqualify');go(2,{'Option'})
  elseif step==2 and mode==5 and empty()and stable>15 then go(3,{'Down','Button A'})
  elseif step==3 and mode==5 and empty()and b(S._save_kind)==1 then assert(b(bank()+10)==1 and b(S._save_error)==0);assert(l(S._best_score)==best_before);flash('cheated_flash');snap('cheat_saved');finish()end
 elseif CASE=='cheat_resume'then
  if step==1 and mode==4 and w(S._game+38)>8 then assert(b(S._cheat_unlocked)==1 and b(S._run_cheated)==1 and l(S._run_preview_score)==0);go(2,{'Option'})
  elseif step==2 and mode==5 and empty()and stable>15 then go(3,{'Down','Down','Down','Button A'})
  elseif step==3 and mode==1 and empty()and stable>15 then go(4,{'Down','Button A'})
  elseif step==4 and mode==4 and w(S._game+38)>8 then assert(b(S._cheat_unlocked)==1 and b(S._run_cheated)==1 and l(S._run_preview_score)==0,'new game requalified within cheated boot');finish()end
 elseif CASE=='fresh_after_cheat'then
  if step==1 and mode==4 and w(S._game+38)>8 then assert(b(S._cheat_unlocked)==0 and b(S._run_cheated)==0 and b(S._run_score_disabled)==0 and l(S._run_preview_score)==0,'cold fresh normal run did not requalify');finish()end
 elseif CASE=='stage_qr'then
  if step==1 and mode==13 and empty() and stable>15 then assert(l(S._best_score)>0,'requires scored campaign');go(2,{'Down','Button A'})
  elseif step==2 and mode==21 and empty() and stable>15 then snap('stage_record_page');go(3,{'Button A'})
  elseif (step==3 or step==7) and mode==17 and empty() and stable>15 then assert(b(S._leaderboard_target)==stage_qr_index,'wrong selected stage');go(4,{'Option'})
  elseif step==4 and mode==19 and stable>15 then
   local t={};for i=0,90 do local c=b(S._render_work+384+i);if c==0 then break end;t[#t+1]=string.char(c)end
   local text=table.concat(t);assert(text:sub(1,30):match('^NGPC%-DEV%.COM/BATMAN/BATMAN3'),'not a stage QR');assert(tonumber(text:sub(31,31))==stage_qr_index,'wrong QR stage ID');
   file('stage'..stage_qr_index..'_payload.txt',text);snap('stage'..stage_qr_index..'_qr');go(5,{'Button B'})
  elseif step==5 and mode==17 and empty() and stable>15 then go(6,{'Button B'})
  elseif step==6 and mode==21 and empty() and stable>15 then
   if stage_qr_index==5 then flash('stage_best_flash');finish()
   else stage_qr_index=stage_qr_index+1;go(7,{'Down','Button A'})end
  end
 elseif CASE=='qr'then
  if step==1 and mode==13 and empty()and stable>15 then assert(l(S._best_score)>0 and b(S._cheat_unlocked)==0);snap('records');go(2,{'Button A'})
  elseif step==2 and mode==17 and empty()and stable>15 then go(3,{'Right','Up','Right','Down','Option'})
  elseif step==3 and mode==18 then snap('generating')
  elseif step==3 and mode==19 and stable>15 and qr_ready_refresh>0 and f>qr_ready_refresh+2 then
   snap('score_qr');local t={};for i=0,153 do local c=b(S._render_work+384+i);if c==0 then break end;t[#t+1]=string.char(c)end;local text=table.concat(t);assert(text:sub(1,20)=='NGPC-DEV.COM/BATMAN/','QR URL prefix wrong');file('payload.txt',text);flash('initials_flash');go(4,{'Button B'})
  elseif step==4 and mode==17 and empty()and stable>15 then go(5,{'Button B'})
  elseif step==5 and mode==13 and empty()and stable>15 then for at=0x9800,0x9fff,2 do assert(w(at)==0,'QR map leaked into records')end;snap('records_after_qr');assert(l(S._best_score)==best_before);finish()end
 elseif CASE=='reset'then
  if step==1 and mode==13 and empty()and stable>15 then assert(l(S._best_score)>0);expected=bytes(bank()+512,w(bank()+28));go(2,{'Down','Down','Button A'})
  elseif step==2 and mode==20 and empty()and stable>15 then snap('reset_confirmation');go(3,{'Button B'})
  elseif step==3 and mode==13 and empty()and stable>15 then assert(l(S._best_score)==best_before,'cancel reset changed record');go(4,{'Down','Down','Button A'})
  elseif step==4 and mode==20 and empty()and stable>15 then go(5,{'Button A'})
  elseif step==5 and mode==13 and empty()and stable>15 then assert(l(S._best_score)==0 and l(S._last_score)==0);assert(b(S._save_available)==1 and b(S._save_kind)==1);assert(bytes(bank()+512,w(bank()+28))==expected,'record reset altered checkpoint');assert(l(bank()+16)==0 and b(S._save_error)==0);flash('reset_flash');snap('records_reset');finish()end
 end
 if cool>0 then cool=cool-1 elseif queue[qi]then if held==0 then held=4 end;keys[queue[qi]]:set_value(1);held=held-1;if held==0 then qi=qi+1;cool=10 end end
 if f%900==0 then print('TRACE',CASE,f,step,mode,b(S._save_error),l(S._run_refreshes));io.stdout:flush()end
 if f>17000 then error('feature timeout '..CASE..' step '..step..' mode '..mode)end
end
emu.register_frame_done(function()local ok,err=pcall(observe);if not ok then done=true;print('FINAL_FEATURE_FAILURE',tostring(err));io.stdout:flush();m:exit()end end)
'''
sym='{' + ','.join(n+'='+str(v)for n,v in syms.items()) + '}'
lua=lua.replace('REPLAY_BUTTONS','{'+','.join(map(str,json.loads((P/'EVIDENCE/FULL_LEVEL_BUTTONS.json').read_text())))+'}').replace('SYMBOLS',sym).replace('CASE_NAME',a.case);(out/'test.lua').write_text(lua)
env=os.environ.copy();env.update(SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',BATMAN_OUT=str(out))
cmd=[str(Path(a.mame).resolve()),'ngpc','-rompath',str(Path(a.bios).resolve()),'-cart',str(rom),'-cfg_directory',str(out/'cfg'),'-nvram_directory',str(out/'nvram'),'-autoboot_delay','0','-autoboot_script',str(out/'test.lua'),'-video','none','-sound','none','-noplugins','-skip_gameinfo','-nothrottle','-seconds_to_run','310']
with(out/'mame.log').open('w')as log:subprocess.run(cmd,env=env,stdout=log,stderr=subprocess.STDOUT,timeout=400,check=True)
# RESULT is removed before every run and written only after every target assertion.
# Some AppImage runs omit the tail of redirected stdout; use the fresh result as completion evidence.
t=(out/'mame.log').read_text();assert 'FINAL_FEATURE_FAILURE'not in t and 'LUA ERROR'not in t,t[-3000:]
assert (out/'RESULT.json').is_file(),'target did not complete';fresh=json.loads((out/'RESULT.json').read_text());assert fresh.get('passed')and fresh.get('case')==a.case
result=json.loads((out/'RESULT.json').read_text());result['forced_gameover_event']=a.case in ['gameover_points','quick_death','restart_points'];result['rom_sha256']=hashlib.sha256(Path(a.rom).read_bytes()).hexdigest();(out/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n');print('PASS',a.case,out)
