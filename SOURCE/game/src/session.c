/* Two alternating 8 KiB flash sectors (32/33) in the first 2 MiB window.
 * Sector 34 belongs to the BIOS and is NEVER erased or programmed here.
 * A streamed logical snapshot needs only a temporary 512-byte stack page.
 * Payload is written and checked before its committing header. An interrupted
 * replacement leaves the previous sector readable, including during rollover.
 */
#include "session.h"
#include "game.h"
#include "faithful.h"
#include "audio.h"
#include "hardware_perf.h"
#define HEADER_SIZE 512u
#define SNAPSHOT_LIMIT 4096u
/* Schema 1: public game/VM state plus the 21-byte private-state footer.
 * Reject a CRC-valid truncated record before touching any live game RAM. */
#define SNAPSHOT_BYTES ((u16)(sizeof(Game)+sizeof(StageWork)+512u+64u+8u+6u+4u+3u+384u+21u))
extern u8 stack[512],active_stage;
extern void session_flash_erase(u8 block);
extern void session_flash_page(const void *data,u32 offset);
u8 option_lives=3,cheat_unlocked,cheat_invulnerable,cheat_freeze_time,run_cheated,run_active;
u8 save_available,save_kind,save_stage,save_error,last_score_cheated;
u8 run_score_disabled,last_score_disabled;
u32 best_score,last_score;
/* M63: earned arcade points plus a banked stage-clear speed bonus.
 * The stopwatch runs forwards; points never drain while the player waits.
 * The source score remains untouched, preserving original extra-life awards. */
volatile u32 run_refreshes,run_preview_score;
u32 run_stage_start,run_stage_ticks[5],best_run_ticks,best_stage_ticks[5],last_run_ticks;
u32 run_source_score,run_bonus_score,best_source_score;
static u32 run_stage_source_start;
/* 0=none,1..5=uncommitted clear,255=reset in progress. */
static u8 pending_stage;
u8 run_completed_mask,last_run_complete,best_completed_mask;
char record_initials[4]="AAA";
#define RECORD_FORMAT 0x65u
#define LEGACY_RECORD_FORMAT 0x63u
#define SCORE_MAX 999999ul
#define CLOCK_MAX 9999999ul
u32 session_time_bonus(u8 stage,u32 ticks){
 static const u16 budgets[5]={480u,300u,60u,180u,720u};u32 seconds;
 if(stage<1u||stage>5u||ticks>CLOCK_MAX)return 0;
 seconds=(ticks*20ul)/1199ul;
 return seconds>=budgets[stage-1u]?0ul:((u32)budgets[stage-1u]-seconds)*100ul;
}
static u32 stage_bonuses(u8 mask,const u32 *ticks){u8 i;u32 total=0;
 for(i=0;i<5u;i++)if(mask&(1u<<i))total+=session_time_bonus((u8)(i+1u),ticks[i]);return total;
}
static u32 earned_points(u32 source,u32 bonus){return source>=SCORE_MAX||bonus>=SCORE_MAX-source?SCORE_MAX:source+bonus;}
void session_vblank(void){if(run_active&&run_refreshes<CLOCK_MAX)run_refreshes++;}
u8 session_upload_available(void){return(u8)(best_score>0ul&&!cheat_unlocked);}
u8 session_stage_upload_available(u8 stage){return(u8)(stage>=1u&&stage<=5u&&session_stage_best_score(stage)>0ul&&!cheat_unlocked);}
static void bank_best(void){u8 i;
 if(!run_active||run_cheated||run_score_disabled||run_preview_score<=best_score)return;
 best_score=run_preview_score;best_source_score=run_source_score;best_completed_mask=run_completed_mask;best_run_ticks=run_refreshes;
 for(i=0;i<5u;i++)best_stage_ticks[i]=run_stage_ticks[i];
 if(active_stage>=1u&&active_stage<=5u&&!(run_completed_mask&(1u<<(active_stage-1u))))best_stage_ticks[active_stage-1u]=run_refreshes-run_stage_start;
}

static u8 rotation_last=255,rotation_progress;
static u8 newest=255,stream_mode,stream_bad;
static u16 stream_at,stream_fill,stream_crc;
static u32 sequence,stream_address;
static u8 *stream_page;
static u32 bank_offset(u8 bank){return bank?0x1fa000ul:0x1f8000ul;}
static const u8 *bank_pointer(u8 bank){return(const u8 *)(0x200000ul+bank_offset(bank));}
static u16 get16(const u8 *p){return(u16)p[0]|((u16)p[1]<<8);}
static u32 get32(const u8 *p){return(u32)get16(p)|((u32)get16(p+2)<<16);}
static void put16(u8 *p,u16 v){p[0]=(u8)v;p[1]=(u8)(v>>8);}
static void put32(u8 *p,u32 v){put16(p,(u16)v);put16(p+2,(u16)(v>>16));}
static u16 crc_byte(u16 crc,u8 v){u8 i;crc^=(u16)v<<8;for(i=0;i<8;i++)crc=(u16)((crc&0x8000u)?(crc<<1)^0x1021u:crc<<1);return crc;}
static u16 crc_bytes(const u8 *p,u16 n){u16 crc=65535u;while(n--){crc=crc_byte(crc,*p++);HW_WATCHDOG=WATCHDOG_CLEAR;}return crc;}
static u8 valid_bank(u8 bank){const u8 *p=bank_pointer(bank);u16 n;
 if(p[0]!='B'||p[1]!='T'||p[2]!='1'||p[3]!='5'||p[4]!=1u||p[5]>2u||p[6]>5u)return 0;
 if(get16(p+510)!=crc_bytes(p,510))return 0;
 n=get16(p+28);if(n>SNAPSHOT_LIMIT||n!=(p[5]==1u?SNAPSHOT_BYTES:0u))return 0;
 if(p[5]&&(!p[6]||p[8]<1u||p[8]>9u))return 0;
 if(get16(p+32)!=(u16)sizeof(Game)||get16(p+34)!=(u16)sizeof(StageWork))return 0;
 return(u8)(get16(p+30)==crc_bytes(p+512,n));
}
static void accept_header(void){const u8 *p;
 save_available=save_kind=save_stage=0;if(newest==255)return;p=bank_pointer(newest);
 save_kind=p[5];save_stage=p[6];save_available=(u8)(save_kind!=0);
}
u32 session_stage_best_ticks(u8 stage){
 const u8 *p;u32 ticks,source,score;
 if(stage<1u||stage>5u||pending_stage==255u)return 0;
 if(pending_stage==stage)return run_stage_ticks[stage-1u];
 if(newest==255u)return 0;
 p=bank_pointer(newest);if(p[39]!=RECORD_FORMAT)return 0;
 ticks=get32(p+128u+(u16)(stage-1u)*12u);
 source=get32(p+124u+(u16)(stage-1u)*12u);
 score=get32(p+120u+(u16)(stage-1u)*12u);
 if(ticks>CLOCK_MAX||source>SCORE_MAX||score!=earned_points(source,session_time_bonus(stage,ticks)))return 0;
 return ticks;
}
u32 session_stage_best_source(u8 stage){
 const u8 *p;if(stage<1u||stage>5u||!session_stage_best_ticks(stage))return 0;
 if(pending_stage==stage)return run_source_score>=run_stage_source_start?run_source_score-run_stage_source_start:0ul;
 if(newest==255u)return 0;
 p=bank_pointer(newest);
 if(p[39]!=RECORD_FORMAT)return 0;
 return get32(p+124u+(u16)(stage-1u)*12u);
}
u32 session_stage_best_score(u8 stage){
 u32 ticks=session_stage_best_ticks(stage);
 if(!ticks)return 0;
 return earned_points(session_stage_best_source(stage),session_time_bonus(stage,ticks));
}
void session_init(void){u8 a=valid_bank(0),b=valid_bank(1),i;const u8 *p;
 newest=255;if(a)newest=0;if(b&&(!a||(s32)(get32(bank_pointer(1)+12)-get32(bank_pointer(0)+12))>0))newest=1;
 option_lives=3;best_score=last_score=sequence=0;save_error=0;run_score_disabled=last_score_disabled=0;
 if(newest!=255){
  p=bank_pointer(newest);sequence=get32(p+12);option_lives=p[8];if(option_lives<1u||option_lives>9u)option_lives=3;audio_enabled=(u8)(p[9]!=0);
  if(p[39]==0x62u||p[39]==LEGACY_RECORD_FORMAT||p[39]==RECORD_FORMAT){for(i=0;i<3u;i++)record_initials[i]=(p[101u+i]>='A'&&p[101u+i]<='Z')?(char)p[101u+i]:'A';record_initials[3]=0;}
  if(p[39]==RECORD_FORMAT||p[39]==LEGACY_RECORD_FORMAT){
   best_score=get32(p+16);last_score=get32(p+20);last_score_cheated=p[36];last_score_disabled=(u8)(p[38]==0xa1u);
   best_run_ticks=get32(p+72);last_run_ticks=get32(p+96);last_run_complete=(u8)(p[100]==1u);best_source_score=get32(p+112);best_completed_mask=p[116];
   for(i=0;i<5u;i++)best_stage_ticks[i]=get32(p+76u+(u16)i*4u);
   if(best_completed_mask>31u||best_run_ticks>CLOCK_MAX||best_source_score>SCORE_MAX||earned_points(best_source_score,stage_bonuses(best_completed_mask,best_stage_ticks))!=best_score)best_score=0;
   if(last_score>SCORE_MAX)last_score=0;
  }
  /* M62's countdown records are not comparable. Keep its checkpoint/time
     history and initials; convert actual earned source points on Continue. */
 }
 accept_header();
}
u8 session_cheat_input(u8 keys){u8 dir=255,delta;
 keys&=15u;
 if(keys==1u)dir=0;else if(keys==9u)dir=1;else if(keys==8u)dir=2;else if(keys==10u)dir=3;else if(keys==2u)dir=4;else if(keys==6u)dir=5;else if(keys==4u)dir=6;else if(keys==5u)dir=7;
 if(dir==255||dir==rotation_last)return 0;
 if(rotation_last==255){rotation_last=dir;rotation_progress=0;return 0;}
 delta=(u8)((dir+8u-rotation_last)&7u);rotation_last=dir;
 if(delta==1u||delta==2u){rotation_progress=(u8)(rotation_progress+delta);if(rotation_progress>=80u){rotation_progress=0;cheat_unlocked=1;return 1;}}
 else rotation_progress=0;
 return 0;
}
/* Eligibility belongs to the run, not to the number of spare lives remaining.
 * Earning an extra life during an ordinary three-life run keeps scoring. */
void session_new_run(void){u8 i;
 run_active=1;run_cheated=(u8)(cheat_unlocked||cheat_invulnerable||cheat_freeze_time||active_stage!=1u);
 run_score_disabled=(u8)(option_lives>3u);game.lives=(u8)(option_lives-1u);game.score=0;
 run_refreshes=run_stage_start=run_source_score=run_bonus_score=run_stage_source_start=0;run_completed_mask=0;
 for(i=0;i<5u;i++)run_stage_ticks[i]=0;
 run_preview_score=0;
}
/* M66: game.score is the current checkpoint attempt; run_source_score is
 * its credited high water. Respawns rewind only the attempt. Repeated
 * rewards cannot increase ranked points or issue another extra life.
 * Checkpoint baselines occupy two previously unused Game words, so both
 * the 70-byte snapshot ABI and the diagnostic RAM ceiling stay intact. */
void session_award_points(u32 points){u32 before,after;
 if(run_score_disabled)return;
 before=(run_active?run_source_score:game.score)/100000ul;
 if(game.score>=SCORE_MAX||points>SCORE_MAX-game.score)game.score=SCORE_MAX;else game.score+=points;
 if(run_active&&game.score>run_source_score)run_source_score=game.score;
 after=(run_active?run_source_score:game.score)/100000ul;
 if(after>before&&game.lives<8u)game.lives++;
}
void session_checkpoint_score(void){
 if(run_active&&game.score<run_source_score)game.score=run_source_score;
 game.checkpoint_score_lo=(u16)game.score;
 game.checkpoint_score_hi=(u16)(game.score>>16);
}
void session_respawn_score(void){
 game.score=(u32)game.checkpoint_score_lo|((u32)game.checkpoint_score_hi<<16);
}
void session_restart_stage_score(void){
 /* An explicit whole-stage restart discards that stage's attempt. Keep
    earlier completed levels; retaining later checkpoint highs here would
    let an earlier replay bank them a second time. */
 run_source_score=run_stage_source_start;
 game.score=run_source_score;
 session_checkpoint_score();session_record_live();
}
void session_record_live(void){
#if HW_PERF
 if(hardware_test)return;
#endif
 /* Unlocking cheat mode is sufficient, even when its individual toggles are OFF.
    It remains unlocked until a cold restart; saved eligibility is sticky. */
 if(run_active&&(cheat_unlocked||cheat_invulnerable||cheat_freeze_time))run_cheated=1;
 if(run_score_disabled)game.score=0; /* Preserve the original extra-life rule. */
 if(!run_active)return;
 if(game.score>run_source_score)run_source_score=game.score>SCORE_MAX?SCORE_MAX:game.score;
 run_preview_score=(run_cheated||run_score_disabled)?0ul:earned_points(run_source_score,run_bonus_score);
}
void session_record_end(void){
 if(!run_active)return;session_record_live();last_score=run_preview_score;last_run_ticks=run_refreshes;
 last_run_complete=0;last_score_cheated=run_cheated;last_score_disabled=run_score_disabled;
 bank_best();run_active=0;session_save_profile();
}
static void flush_page(void){u16 i;const u8 *p;
 session_flash_page(stream_page,stream_address);p=(const u8 *)(0x200000ul+stream_address);
 for(i=0;i<512u;i++)if(p[i]!=stream_page[i])stream_bad=1;
 stream_address+=512ul;stream_fill=0;
}
void session_io(void *data,u16 count){u8 *p=(u8 *)data,v;
 while(count--){
  if(stream_at>=SNAPSHOT_LIMIT){stream_bad=1;return;}
  if(stream_mode){v=*p++;stream_crc=crc_byte(stream_crc,v);stream_page[stream_fill++]=v;stream_at++;if(stream_fill==512u)flush_page();}
  else{*p++=*(const u8 *)(stream_address+stream_at);stream_at++;}
 }
}
#define IO(value) session_io(&(value),(u16)sizeof(value))
static void logical_state(void){
 IO(game);IO(stage_work);IO(stack);IO(d);IO(a);IO(vm_resume);IO(vm_fault);
 IO(fn);IO(fz);IO(fv);IO(fc);IO(fx);IO(vm_busy);IO(vm_player_state);IO(vm_platform_opcode);
 IO(bob_draw_count);IO(vm_wait);IO(vm_phase);session_io(bob_draws,384u);
 faithful_state_io();cathedral_state_io();vehicle_memory_state_io();game_state_io();cat_state_io();vehicle_state_io();
}
#undef IO
/* kind=255 updates the profile while retaining the last manual/auto save. */
static u8 commit(u8 kind,u8 next_stage){u8 page[512];u8 target,i,old_kind=0;u16 j,n=0,crc=65535u;u32 saved_score=game.score,migrated_bonus;const u8 *old=(const u8 *)0,*at;
#if HW_PERF
 if(hardware_test)return 1;
#endif
 save_error=0;target=newest==0?1u:0u;if(newest!=255){old=bank_pointer(newest);old_kind=old[5];}
 audio_stop();session_flash_erase((u8)(target?33u:32u));at=bank_pointer(target);
 for(j=0;j<8192u;j++){if(at[j]!=255u){save_error=1;return 0;}HW_WATCHDOG=WATCHDOG_CLEAR;}
 stream_page=page;stream_mode=1;stream_bad=0;stream_at=stream_fill=0;stream_crc=65535u;stream_address=bank_offset(target)+512ul;
 if(kind==1u)logical_state();
 else if(kind==255u&&old_kind==1u){n=get16(old+28);for(j=0;j<n;j++){u8 v=old[512u+j];session_io(&v,1);}}
 n=stream_at;crc=stream_crc;
 if((kind==1u||(kind==255u&&old_kind==1u))&&n!=SNAPSHOT_BYTES){save_error=2;return 0;}
 if(stream_fill){for(j=stream_fill;j<512u;j++)page[j]=255u;flush_page();}
 if(stream_bad){save_error=2;return 0;}
 for(j=0;j<512u;j++)page[j]=(kind==255u&&old)?old[j]:255u;
 page[0]='B';page[1]='T';page[2]='1';page[3]='5';page[4]=1;
 if(kind!=255u){page[5]=kind;page[6]=next_stage;page[7]=(u8)((cheat_invulnerable?1u:0u)|(cheat_freeze_time?2u:0u));page[10]=run_cheated;page[11]=game.lives;put32(page+24,saved_score);page[37]=(u8)(0xa0u|run_score_disabled);}
 else if(!old){page[5]=page[6]=page[7]=page[10]=page[11]=0;put32(page+24,0);}
 page[8]=option_lives;page[9]=audio_enabled;put32(page+12,sequence+1ul);put32(page+16,best_score);put32(page+20,last_score);put16(page+28,n);put16(page+30,crc);
 put16(page+32,(u16)sizeof(Game));put16(page+34,(u16)sizeof(StageWork));page[36]=last_score_cheated;page[38]=(u8)(0xa0u|last_score_disabled);
 /* A profile-only write retains the saved run, not the live/menu state.
    Convert M62 checkpoints without losing their earned source points/time. */
 if(kind!=255u){
  put32(page+40,run_refreshes);put32(page+44,run_stage_start);
  for(i=0;i<5u;i++)put32(page+48u+(u16)i*4u,run_stage_ticks[i]);page[68]=run_completed_mask;
  put32(page+104,run_source_score);put32(page+108,run_bonus_score);
  page[184]=0x66u;page[185]=0x99u; /* checkpoint-score snapshot semantics */
 }else if(old&&old[39]==0x62u){
  migrated_bonus=0;for(i=0;i<5u;i++)if(old[68]&(1u<<i))migrated_bonus+=session_time_bonus((u8)(i+1u),get32(old+48u+(u16)i*4u));
  saved_score=get32(old+24);put32(page+104,saved_score>SCORE_MAX?SCORE_MAX:saved_score);put32(page+108,migrated_bonus);
 }else if(!old||(old[39]!=RECORD_FORMAT&&old[39]!=LEGACY_RECORD_FORMAT)){
  for(i=40u;i<69u;i++)page[i]=0;put32(page+104,0);put32(page+108,0);if(page[5])page[37]=0xa1u;
 }
 page[39]=RECORD_FORMAT;put32(page+72,best_run_ticks);put32(page+96,last_run_ticks);page[100]=last_run_complete;
 for(i=0;i<5u;i++)put32(page+76u+(u16)i*4u,best_stage_ticks[i]);
 for(i=0;i<3u;i++)page[101u+i]=(u8)record_initials[i];
 put32(page+112,best_source_score);page[116]=best_completed_mask;
 /* M65 extension in unused 512-byte header; preserves all M63 offsets and
    the original payload snapshot and atomic two-sector commit protocol. */
 for(i=0;i<5u;i++){
  put32(page+120u+(u16)i*12u,session_stage_best_score((u8)(i+1u)));
  put32(page+124u+(u16)i*12u,session_stage_best_source((u8)(i+1u)));
  put32(page+128u+(u16)i*12u,session_stage_best_ticks((u8)(i+1u)));
 }
 if(kind==255u&&old)put32(page+180,old[39]==RECORD_FORMAT?get32(old+180):get32(old+104));
 else put32(page+180,pending_stage>=1u&&pending_stage<=5u?run_source_score:run_stage_source_start);
 put16(page+510,crc_bytes(page,510));session_flash_page(page,bank_offset(target));
 if(!valid_bank(target)){save_error=3;return 0;}
 newest=target;sequence++;if(pending_stage>=1u&&pending_stage<=5u)run_stage_source_start=run_source_score;pending_stage=0;accept_header();return 1;
}
u8 session_save_game(void){session_record_live();bank_best();return commit(1u,active_stage);}
u8 session_save_transition(u8 next_stage){u8 expected;u32 ticks=run_refreshes;
 session_record_live();
 expected=(u8)((active_stage>=1u&&active_stage<=5u)?((1u<<(active_stage-1u))-1u):255u);
 if(active_stage<1u||active_stage>5u||run_completed_mask!=expected||ticks<=run_stage_start)run_cheated=1;
 else{
  run_stage_ticks[active_stage-1u]=ticks-run_stage_start;run_completed_mask|=(u8)(1u<<(active_stage-1u));
  run_bonus_score+=session_time_bonus(active_stage,run_stage_ticks[active_stage-1u]);
 }
 /* The level score is its OWN arcade-point gain, plus its OWN speed
    bonus. Never add earlier levels' points or bonuses to a level record. */
 if(run_completed_mask==((1u<<active_stage)-1u)&&run_active&&!run_cheated&&!run_score_disabled&&active_stage>=1u&&active_stage<=5u){
  u8 idx=(u8)(active_stage-1u);
  u32 source=(run_source_score>=run_stage_source_start)?run_source_score-run_stage_source_start:0ul;
  u32 stage_score=earned_points(source,session_time_bonus(active_stage,run_stage_ticks[idx]));
  if(run_stage_ticks[idx]>0ul&&run_stage_ticks[idx]<=CLOCK_MAX&&stage_score>0ul&&
     (stage_score>session_stage_best_score(active_stage)||(stage_score==session_stage_best_score(active_stage)&&run_stage_ticks[idx]<session_stage_best_ticks(active_stage)))){
   pending_stage=active_stage;
  }
 }
 if(!pending_stage)run_stage_source_start=run_source_score;
 run_stage_start=ticks;session_record_live();bank_best();
 if(next_stage>5u){
  last_run_ticks=ticks;last_run_complete=1;last_score_cheated=run_cheated;last_score_disabled=run_score_disabled;
  last_score=run_preview_score;run_active=0;
 }
 return commit((u8)(next_stage<=5u?2u:0u),(u8)(next_stage<=5u?next_stage:0u));
}
u8 session_save_profile(void){return commit(255u,0);}
u8 session_reset_records(void){
 u32 old_best=best_score,old_last=last_score,old_bt=best_run_ticks,old_lt=last_run_ticks,old_source=best_source_score,old_splits[5];
 u8 i,old_mask=best_completed_mask,old_cheated=last_score_cheated,old_disabled=last_score_disabled,old_complete=last_run_complete;
 for(i=0;i<5u;i++)old_splits[i]=best_stage_ticks[i];
 best_score=last_score=best_run_ticks=last_run_ticks=best_source_score=0;best_completed_mask=0;
 last_score_cheated=last_score_disabled=last_run_complete=0;pending_stage=255u;
 for(i=0;i<5u;i++)best_stage_ticks[i]=0;
 if(session_save_profile())return 1;
 pending_stage=0;best_score=old_best;last_score=old_last;best_run_ticks=old_bt;last_run_ticks=old_lt;
 best_source_score=old_source;best_completed_mask=old_mask;last_score_cheated=old_cheated;
 last_score_disabled=old_disabled;last_run_complete=old_complete;
 for(i=0;i<5u;i++)best_stage_ticks[i]=old_splits[i];return 0;
}
u8 session_restore(void){u8 i;const u8 *p;
 if(newest==255||!valid_bank(newest))return 0;p=bank_pointer(newest);
 if(!p[5])return 0;active_stage=p[6];cheat_invulnerable=p[7]&1u;cheat_freeze_time=(p[7]>>1)&1u;run_cheated=p[10];if(run_cheated||cheat_invulnerable||cheat_freeze_time)cheat_unlocked=1;
 if(p[5]==1u){stream_mode=0;stream_bad=0;stream_at=0;stream_address=(u32)(p+512);logical_state();if(stream_bad||stream_at!=get16(p+28))return 0;}
 else{game.score=get32(p+24);game.lives=p[11];}
 /* Old M15 headers have 0xff here; their original lives preference is the
  * compatible fallback. Profile-only commits preserve the saved run flag. */
 run_score_disabled=(u8)((p[37]&0xfeu)==0xa0u?(p[37]&1u):(p[8]>3u));if(run_score_disabled)game.score=0;
 if(p[39]==RECORD_FORMAT||p[39]==LEGACY_RECORD_FORMAT||p[39]==0x62u){run_refreshes=get32(p+40);run_stage_start=get32(p+44);run_completed_mask=p[68];for(i=0;i<5u;i++)run_stage_ticks[i]=get32(p+48u+(u16)i*4u);}
 else{run_refreshes=run_stage_start=0;run_completed_mask=0;run_score_disabled=1;for(i=0;i<5u;i++)run_stage_ticks[i]=0;}
 if(cheat_unlocked||cheat_invulnerable||cheat_freeze_time)run_cheated=1;
 if(run_refreshes>CLOCK_MAX||run_stage_start>run_refreshes){run_refreshes=run_stage_start=0;run_score_disabled=1;}
 if(p[39]==RECORD_FORMAT||p[39]==LEGACY_RECORD_FORMAT){run_source_score=get32(p+104);run_bonus_score=get32(p+108);}
 else{run_source_score=game.score>SCORE_MAX?SCORE_MAX:game.score;run_bonus_score=stage_bonuses(run_completed_mask,run_stage_ticks);}
 /* M63 checkpoints predate the stage-point start offset. Use the current
    source total as a conservative baseline: never attribute past points to a
    new per-level record after migrating an old save. */
 run_stage_source_start=p[39]==RECORD_FORMAT?get32(p+180):run_source_score;
 if(run_stage_source_start>run_source_score)run_stage_source_start=run_source_score;
 /* Older snapshots have no checkpoint score baseline. Keep them playable,
    but only a fresh M66 run can establish a ranked anti-farming history. */
 if(p[184]!=0x66u||p[185]!=0x99u)run_score_disabled=1;
 run_active=1;session_record_live();return 1;
}
