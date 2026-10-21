#include "ngpc_hw.h"
#include "ngpc_sys.h"
#include "ngpc_gfx.h"
#include "video.h"
#include "audio.h"
#include "cathedral.h"
#include "vehicle.h"
#include "puzzle.h"
#include "hardware_perf.h"
#include "session.h"
#include "leaderboard.h"
u8 video_render_requested=1;
u8 active_stage=1;
extern volatile u8 screen_mode;
static volatile u8 pause_latched;
static u8 option_was_down;
static void runtime_vblank(void){u8 down=(u8)(HW_JOYPAD&PAD_OPTION);
 if(screen_mode==4u&&down&&!option_was_down)pause_latched=1;
 option_was_down=down;if(screen_mode==4u)session_vblank();video_present();audio_vblank();
}
#include "carthdr.h"
void ngpc_full_speed(void);
void stack_guard_init(void);
volatile u8 screen_mode,ui_choice;
volatile u16 display_frames,logic_steps,debug_x,debug_y,debug_camera_x,debug_camera_y;
volatile u8 debug_player_state,debug_health,debug_lives,debug_actors,debug_max_frame_work,debug_missed_frames;
volatile u8 debug_hazards,debug_checkpoint,debug_boss;
volatile u16 debug_hazard_hits,debug_hazard_cycles;
void cart_entry(void){
 __asm("ldw (0xb8),0xaaaa");
 __asm("ld xsp,0x8000");
 __asm("jp _main");
}
static void debug_game_state(void){
 debug_x=(u16)game.player.x;debug_y=(u16)game.player.y;
 debug_player_state=game.player.state;debug_health=game.health;debug_lives=game.lives;
 debug_checkpoint=game.checkpoint;debug_boss=game.boss_state;
}
static void enter_title(void){if(!cheat_unlocked)active_stage=1;screen_mode=1;ui_choice=0;video_title_load();video_title_fade(16);video_menu(0);audio_music(0);}
/* One playback path for menu Credits and the completed-game ending. */
static void enter_credits(void){run_active=0;screen_mode=16;ui_choice=0;video_ending_start();audio_intro_start();video_ending_render(0);}
static void enter_game(u8 carry){u32 score=run_active?run_source_score:game.score;u8 lives=game.lives;screen_mode=8;pause_latched=0;ui_choice=0;audio_stop();if(active_stage==5)cat_new();else if(active_stage==2||active_stage==4)vehicle_new(active_stage);else if(active_stage==3)puzzle_new();else game_new();if(carry){game.score=score;game.lives=lives;}else game.lives=(u8)(option_lives-1u);session_checkpoint_score();video_render_requested=1;video_start_game();video_game();audio_music(1);screen_mode=4;}
void main(void){
 u8 previous=0,keys,pressed,pending=0,stamp,elapsed,work,advanced=0,page,items,which,stage_carry=0;
 volatile u8 now;u16 phase=0,intro=0;
 stack_guard_init();ngpc_init();ngpc_vblank_hook=runtime_vblank;ngpc_full_speed();audio_init();session_init();ngpc_gfx_set_bg_color(0);video_intro_render(0);audio_intro_start();screen_mode=0;stamp=g_vb_counter;
 for(;;){
  if(g_vb_counter==stamp)ngpc_vsync();now=g_vb_counter;elapsed=(u8)(now-stamp);stamp=now;
  display_frames+=elapsed;keys=HW_JOYPAD;pressed=(u8)(keys&~previous);previous=keys;audio_frame();
  if(screen_mode==0){
    /* With sound enabled the actual DMA audio playback is the authority.
       Without sound, keep the original VBlank-based visual-only intro. */
    if(audio_enabled)intro=audio_intro_frame();else intro=(u16)(intro+elapsed);
    if(intro>=4966u||(pressed&(PAD_A|PAD_B|PAD_OPTION))){intro=0;enter_title();}
    else video_intro_render(intro);
   }
  else if(screen_mode==1){
   if(session_cheat_input(keys)){ui_choice=0;video_menu(0);audio_effect(8);}
#if HW_PERF
   if(pressed&PAD_B){hardware_test=0;audio_stop();screen_mode=9;video_perf_menu();}
#endif
   if(cheat_unlocked&&(pressed&PAD_LEFT)){active_stage=(u8)(active_stage==1?5:active_stage-1);video_menu_update(ui_choice);}
   if(cheat_unlocked&&(pressed&PAD_RIGHT)){active_stage=(u8)(active_stage==5?1:active_stage+1);video_menu_update(ui_choice);}
   items=(u8)(save_available?5u:4u);
   if(pressed&PAD_UP){ui_choice=(u8)((ui_choice+items-1u)%items);video_menu_update(ui_choice);}
   if(pressed&PAD_DOWN){ui_choice=(u8)((ui_choice+1u)%items);video_menu_update(ui_choice);}
   if(pressed&(PAD_A|PAD_OPTION)){
    if(save_available&&ui_choice==0){
     active_stage=save_stage;
     if(save_kind==1u){enter_game(0);screen_mode=8;if(session_restore()){video_start_game();video_game();audio_music(1);screen_mode=4;pending=0;phase=0;stamp=g_vb_counter;}else{save_error=3;enter_title();}}
     else if(session_restore()){stage_carry=1;screen_mode=12;intro=0;video_stage_intro();audio_music(1);}
    }else{
     which=(u8)(ui_choice-(save_available?1u:0u));
     if(which==0){session_new_run();stage_carry=0;screen_mode=12;intro=0;video_stage_intro();audio_music(1);}
     else if(which==1){screen_mode=2;ui_choice=0;video_options(0);}
     else if(which==2){screen_mode=13;ui_choice=0;video_records(0);}
     else{intro=0;enter_credits();stamp=g_vb_counter;}
    }
   }
  }else if(screen_mode==2){
   if(session_cheat_input(keys)){ui_choice=0;video_options(0);audio_effect(8);}
   items=(u8)(cheat_unlocked?7u:4u);
   if(pressed&PAD_UP){ui_choice=(u8)((ui_choice+items-1u)%items);video_options_update(ui_choice);}
   if(pressed&PAD_DOWN){ui_choice=(u8)((ui_choice+1u)%items);video_options_update(ui_choice);}
   if(pressed&(PAD_LEFT|PAD_RIGHT|PAD_A)){
    if(ui_choice==0){audio_enabled^=1;audio_stop();if(audio_enabled)audio_music(0);}
    else if(ui_choice==1){if(pressed&PAD_LEFT){if(option_lives>1u)option_lives--;}else if(option_lives<9u)option_lives++;}
    else if(ui_choice==2&&(pressed&PAD_A)){screen_mode=14;video_controls(audio_enabled);}
    else if(cheat_unlocked&&ui_choice==3)cheat_invulnerable^=1;
    else if(cheat_unlocked&&ui_choice==4)cheat_freeze_time^=1;
    else if(cheat_unlocked&&ui_choice==5){if(pressed&PAD_LEFT)active_stage=(u8)(active_stage==1?5:active_stage-1);else active_stage=(u8)(active_stage==5?1:active_stage+1);}
    else if(ui_choice==items-1u&&(pressed&PAD_A)){session_save_profile();enter_title();}
    if(screen_mode==2)video_options_update(ui_choice);
   }
   if(pressed&(PAD_B|PAD_OPTION)){session_save_profile();enter_title();}
  }else if(screen_mode==14){if(pressed&(PAD_B|PAD_OPTION)){screen_mode=2;video_options(ui_choice);}}
  else if(screen_mode==13){
   items=4u;
   if(pressed&PAD_UP){ui_choice=(u8)((ui_choice+items-1u)%items);video_records_update(ui_choice);}
   if(pressed&PAD_DOWN){ui_choice=(u8)((ui_choice+1u)%items);video_records_update(ui_choice);}
   if(pressed&(PAD_A|PAD_OPTION)){
    if(ui_choice==0u){if(session_upload_available()){audio_stop();leaderboard_cursor=0;leaderboard_target=0;screen_mode=17;video_qr_entry();}else video_records_update(0);}
    else if(ui_choice==1u){screen_mode=21;ui_choice=0;video_stage_records(ui_choice);}
    else if(ui_choice==2u){screen_mode=20;video_records_reset();}
    else enter_title();
   }else if(pressed&PAD_B)enter_title();
  }else if(screen_mode==21){
   if(pressed&PAD_UP){ui_choice=(u8)(ui_choice?ui_choice-1u:4u);video_stage_records(ui_choice);}
   if(pressed&PAD_DOWN){ui_choice=(u8)(ui_choice==4u?0u:ui_choice+1u);video_stage_records(ui_choice);}
   if(pressed&PAD_A){if(session_stage_upload_available((u8)(ui_choice+1u))){leaderboard_target=(u8)(ui_choice+1u);leaderboard_cursor=0;audio_stop();screen_mode=17;video_qr_entry();}}
   if(pressed&(PAD_B|PAD_OPTION)){screen_mode=13;ui_choice=1;video_records(ui_choice);}
  }else if(screen_mode==20){
   if(pressed&PAD_A){screen_mode=8;session_reset_records();screen_mode=13;ui_choice=0;video_records(0);audio_music(0);}
   else if(pressed&(PAD_B|PAD_OPTION)){screen_mode=13;ui_choice=0;video_records(0);}
  }else if(screen_mode==17){
   if(pressed&PAD_B){if(leaderboard_target){screen_mode=21;ui_choice=(u8)(leaderboard_target-1u);video_stage_records(ui_choice);}else{screen_mode=13;ui_choice=0;video_records(0);}audio_music(0);}
   else if(pressed&PAD_OPTION){session_save_profile();audio_stop();screen_mode=18;video_qr_generating();stamp=g_vb_counter;}
   else if((pressed&(PAD_UP|PAD_DOWN|PAD_LEFT|PAD_RIGHT))||((keys&PAD_A)&&(keys&(PAD_UP|PAD_DOWN))&&!(g_vb_counter&3u))){leaderboard_edit(keys,pressed,g_vb_counter);video_qr_entry_update();}
  }else if(screen_mode==18){u8 ok=leaderboard_encode();screen_mode=19;video_qr_show(ok);stamp=g_vb_counter;
  }else if(screen_mode==19){if(pressed&(PAD_B|PAD_OPTION)){screen_mode=17;video_qr_entry();}}
  else if(screen_mode==3){if(pressed&(PAD_LEFT|PAD_RIGHT|PAD_A)){ui_choice^=1;video_credits_page(ui_choice);}if(pressed&(PAD_B|PAD_OPTION))enter_title();}
  else if(screen_mode==12){intro+=elapsed;if(intro>=180u||(pressed&(PAD_A|PAD_B|PAD_OPTION))){enter_game(stage_carry);pending=0;phase=0;stamp=g_vb_counter;}}
  else if(screen_mode==4){
#if HW_PERF
   if(hardware_test)perf_input(&keys,&pressed);
#endif
   if(elapsed>1)debug_missed_frames+=(u8)(elapsed-1);
   if((pressed&PAD_OPTION)||pause_latched){pause_latched=0;screen_mode=5;ui_choice=0;video_pause(0);}
   else{
    pending|=pressed;advanced=0;phase=(u16)(phase+(active_stage==3?250u:132u)*elapsed);
    while(phase>=300u&&advanced<1u){
     if(advanced){keys=HW_JOYPAD;pressed=(u8)(keys&~previous);previous=keys;pending|=pressed;}
     phase-=300u;video_render_requested=1;
#if HW_PERF
     if(hardware_test)perf_before_step();
#endif
     if(active_stage==5)cat_tick(keys,pending);else if(active_stage==2||active_stage==4)vehicle_tick(keys,pending);else if(active_stage==3)puzzle_tick(keys,pending);else game_tick(keys,pending);pending=0;logic_steps++;advanced++;debug_game_state();
#if HW_PERF
     if(hardware_test)perf_after_step();
#endif
     if(game.sfx){audio_effect(game.sfx);game.sfx=0;}
     if(game.ended||game.boss_state==B_COMPLETE)break;
    }
    if(advanced)video_game();
#if HW_PERF
    if(hardware_test&&perf_done()){
     while(video_present_ready)ngpc_vsync();perf_finish();audio_stop();screen_mode=10;ui_choice=0;video_perf(0);continue;
    }
#endif
    if(phase>600u)phase=600u;
    if(game.ended){session_record_end();screen_mode=6;intro=0;audio_stop();video_over();}
    else if(game.boss_state==B_COMPLETE){screen_mode=7;while(video_present_ready)ngpc_vsync();session_save_transition((u8)(active_stage+1u));intro=0;ui_choice=254;audio_music(2);}
   }
  }else if(screen_mode==5){
   if(pressed&PAD_UP){ui_choice=(u8)((ui_choice+3u)&3u);video_pause_update(ui_choice);}
   if(pressed&PAD_DOWN){ui_choice=(u8)((ui_choice+1u)&3u);video_pause_update(ui_choice);}
   if(pressed&(PAD_B|PAD_OPTION)){screen_mode=8;video_resume();screen_mode=4;pending=0;stamp=g_vb_counter;}
   else if(pressed&PAD_A){
    if(ui_choice==0){screen_mode=8;video_resume();screen_mode=4;pending=0;stamp=g_vb_counter;}
    else if(ui_choice==1){u8 ok=session_save_game();audio_music(1);video_pause(ui_choice);video_pause_status(ok);stamp=g_vb_counter;}
    else if(ui_choice==2){if(option_lives>3u)run_score_disabled=1;session_restart_stage_score();enter_game(0);pending=0;phase=0;stamp=g_vb_counter;}
    else{session_record_end();enter_title();}
   }
  }else if(screen_mode==6){
   if(intro<24u&&intro+elapsed>=24u)audio_music(14);intro+=elapsed;
   if(intro>=615u||(pressed&(PAD_A|PAD_B|PAD_OPTION)))enter_title();
  }else if(screen_mode==7){
   intro+=elapsed;page=(u8)(intro<420?255:intro<540?0:intro<660?1:2);
   if(active_stage!=1&&active_stage!=5)page=(u8)(intro<90u?255:intro<390u?0:2);
   if(page!=ui_choice){ui_choice=page;video_stage_complete(page);}
   if(page==2&&(pressed&(PAD_A|PAD_B|PAD_OPTION))){
    if(active_stage<5){active_stage++;stage_carry=1;screen_mode=12;intro=0;video_stage_intro();audio_music(1);}
    else{intro=0;enter_credits();stamp=g_vb_counter;}
   }
  }else if(screen_mode==16){
   if(audio_enabled)intro=audio_intro_frame();else intro=(u16)(intro+elapsed);
   video_ending_render(intro);
   if(intro>=4966u||(pressed&(PAD_A|PAD_B|PAD_OPTION)))enter_title();
  }

#if HW_PERF
  else if(screen_mode==9){
   if(pressed&PAD_LEFT){active_stage=(u8)(active_stage==1?5:active_stage-1);video_perf_menu();}
   if(pressed&PAD_RIGHT){active_stage=(u8)(active_stage==5?1:active_stage+1);video_perf_menu();}
   if(pressed&PAD_A){audio_enabled^=1;video_perf_menu();}
   if(pressed&PAD_B){hardware_test=1;run_active=0;cheat_invulnerable=cheat_freeze_time=0;option_lives=3;video_perf_reset();enter_game(0);while(video_present_ready)ngpc_vsync();perf_arm();pending=0;phase=0;stamp=g_vb_counter;}
#if HW_PERF_VERSION>=14
   if(pressed&PAD_UP){pending=audio_enabled;audio_enabled=1;screen_mode=11;ui_choice=1;sampled_test(1);video_sound_test(1);}
#endif
   if(pressed&PAD_OPTION){hardware_test=0;enter_title();}
  }else if(screen_mode==10){
   if(pressed&PAD_LEFT){ui_choice=(u8)((ui_choice+3u)&3u);video_perf(ui_choice);}
   if(pressed&PAD_RIGHT){ui_choice=(u8)((ui_choice+1u)&3u);video_perf(ui_choice);}
   if(pressed&PAD_A){video_perf_reset();enter_game(0);while(video_present_ready)ngpc_vsync();perf_arm();pending=0;phase=0;stamp=g_vb_counter;}
   if(pressed&PAD_B){hardware_test=0;screen_mode=9;video_perf_menu();}
#if HW_PERF_VERSION>=14
  }else if(screen_mode==11){
   if(pressed&PAD_A){ui_choice=(u8)(ui_choice%4u+1u);sampled_test(ui_choice);video_sound_test(ui_choice);}
   if(pressed&PAD_B){audio_stop();audio_enabled=pending;screen_mode=9;video_perf_menu();}
#endif
  }
#endif
  debug_x=(u16)game.player.x;debug_y=(u16)game.player.y;
  debug_camera_x=camera_x;debug_camera_y=camera_y;
  debug_player_state=game.player.state;debug_health=game.health;debug_lives=game.lives;debug_actors=active_stage==5?cat_actor_count():active_stage==1?game_actor_count():0;
  debug_hazards=0;debug_hazard_hits=game.hazard_hits;debug_hazard_cycles=game.hazard_cycles;
  debug_checkpoint=game.checkpoint;debug_boss=game.boss_state;
  work=(u8)(g_vb_counter-now);if(screen_mode==4&&work>debug_max_frame_work)debug_max_frame_work=work;
  ngpc_shutdown_poll();
 }
}
