#include "session.h"
/* Cathedral gameplay executes translated original 68000 routines.
 * Hardware-specific presentation, panel and audio boundaries are native. */
#include "game.h"
#include "cathedral.h"
#include "audio.h"
#include "hardware_perf.h"
#define VM_W(p) ((u16)((u16)vm_vars[(p)-0x6326u]<<8)|vm_vars[(p)-0x6326u+1u])
extern Game game;

extern u8 bob_draw_count,vm_wait,vm_phase;
static u16 pending_damage;
static u8 clear_draws;
static const u16 phase_entry[8]={0,0x4974,0x3dbe,0x3dec,0x56e6,0x3ed4,0x4696,0x463c};
u8 cat_tile(s16 x,s16 y){if(x<0||y<0||x>=704||y>=1624)return 0;return cvr8(0x807cul+(u16)(y>>3)*88u+(u16)(x>>3));}
static void zero_bytes(void *p,u16 count){u8 *b=(u8 *)p;while(count--)*b++=0;}
void cat_hurt(u8 value);
static void sync_player(void){
 Player *p=&game.player;u16 state=vm_player_state;u8 i;
 p->x=(s16)VM_W(0x69ecu)+(s16)VM_W(0x69f2u);p->y=(s16)VM_W(0x69eeu)+(s16)VM_W(0x69f4u);
 p->facing=(u8)((VM_W(0x6336u)&0x2000u)!=0);
 p->state=state==0x54c0?P_FALL:state==0x5346?P_CLIMB:state==0x5170||state==0x51ee?P_HOOK:
          state==0x4ea2||state==0x4e78?P_HANG:state==0x5096?P_PULLUP:state==0x5598?P_LAND:state==0x4de0?P_DYING:P_GROUND;
 p->rope_length=(s16)VM_W(0x6360u);p->hook_x=p->x+(p->facing?-4:3)+(s16)VM_W(0x6362u);
 p->hook_y=p->y-12-(s16)VM_W(0x6364u);p->invulnerable=0;
 if(VM_W(0x6344u)>game.checkpoint)session_checkpoint_score();
 game.checkpoint=(u8)VM_W(0x6344u);
 game.boss_state=game.boss_state==B_COMPLETE?B_COMPLETE:B_NONE;
 for(i=0;i<10;i++){
  u16 at=(u16)(0x39bcu+i*22u);u16 id=(u16)((u16)vm_actors[i*22u]<<8)|vm_actors[i*22u+1u];
  if(id==25&&game.boss_state!=B_COMPLETE){game.boss_state=B_SPLASH;game.boss_x=(s16)cvr16(at+2);game.boss_y=(s16)cvr16(at+4);}
 }
}
void cat_reset_position(void){
 cat_reset(game.checkpoint);vm_wait=vm_phase=clear_draws=0;bob_draw_count=0;
 session_respawn_score();
 pending_damage=0;game.seconds=720;game.subsecond=0;game.health=40;game.alive=1;game.game_over_wait=0;game.boss_state=B_NONE;
 sync_player();
}
void cat_new(void){zero_bytes(&game,(u16)sizeof(game));game.lives=2;game.seconds=720;cat_reset_position();}
static void lose_life(void){
 u8 status=cvr8(0x7c874ul);if(cheat_invulnerable)return;pending_damage=0;
 if(status&4)return;
 status|=4;if(!game.lives)status|=2;else game.lives--;
 cvw8(0x7c874ul,status);
}
void cat_hurt(u8 value){if(cheat_invulnerable)return;if(game.health&&!(cvr8(0x7c874ul)&4)){pending_damage+=value;game.damage_taken+=value;}}
static void panel_update(void){
 if(pending_damage&&game.health){pending_damage--;game.health--;if(!game.health)lose_life();}
 if(!cheat_freeze_time&&!(cvr8(0x7c874ul)&1)){
  if(++game.subsecond>=50){game.subsecond=0;if(game.seconds)game.seconds--;else cvw8(0x7c874ul,(u8)(cvr8(0x7c874ul)|1));}
 }
}
u8 cat_actor_count(void){u8 i,n=0;for(i=0;i<10;i++)if(vm_actors[i*22u]||vm_actors[i*22u+1u])n++;return n;}
int cat_external(u32 pc){
 u8 i;u32 value,score=0,mult=1;
 if(pc==0x820ul){game.ended=1;vm_busy=0;return 1;}
 else if(pc==0x5734ul){
  u16 id=(u16)d[2];
  if(bob_draw_count<64&&(id&0x1ffu)&&(id&0x1ffu)<=305u){
   BobDraw *b=&bob_draws[bob_draw_count++];b->x=(s16)d[0];b->y=(s16)d[1];b->id=id;
  }
 }else if(pc==0x7c870ul)cat_hurt((u8)d[0]);
 else if(pc==0x7c862ul)lose_life();
 else if(pc==0x7c82aul){
  if(run_score_disabled)return 0;
  value=d[0];for(i=0;i<6;i++){score+=(value&15ul)*mult;mult*=10ul;value>>=4;}
  session_award_points(score);
 }else if(pc==0x48014ul)audio_effect((u8)d[0]);
 else if(pc==0x48010ul)audio_music((u8)d[0]);
 else if(pc==0x48004ul)audio_stop();
 else if(pc==0x4df0ul){
  game.alive=0;game.game_over_wait=41;vm_busy=0;return 1;
 }else if(pc==0x5e7aul||pc==0x5e82ul){
  game.boss_state=B_COMPLETE;vm_busy=0;audio_music(2);return 1;
 }else if(pc==0x5ed4ul||pc==0x36eeul){
  vm_wait=pc==0x36eeul?1:(u8)(((u16)d[0]+2u)/2u);
  if(!vm_wait)vm_wait=1;vm_resume=cvr32(a[7]);a[7]+=4;vm_busy=1;
  if(pc==0x36eeul){cvw16(0x6374ul,(u16)(VM_W(0x6374u)+1));clear_draws=(u8)(vm_resume!=0x5e7aul&&vm_resume!=0x5b68ul);}
  return 1;
 }
 return 0;
}
void cat_tick(u8 keys,u8 pressed){
 u8 cmd=0;u16 entry;
 game.ticks++;cvw16(0x36e2ul,(u16)(game.ticks*2));
 if(game.ended||game.boss_state==B_COMPLETE)return;
 if(game.game_over_wait){
  if(!--game.game_over_wait){if(cvr8(0x7c874ul)&2)game.ended=1;else{cat_reset_position();audio_music(1);}}
  sync_player();return;
 }
 if(vm_wait){if(--vm_wait)return;if(clear_draws){bob_draw_count=0;clear_draws=0;}}
 if(!vm_phase&&!vm_busy){
  if(!(cvr8(0x7c874ul)&1)){
   panel_update();panel_update();
   if(cvr8(0x7c874ul)&1){d[6]=1;cat_exec(0x4d22u);}
  }bob_draw_count=0;
  if(keys&PAD_RIGHT)cmd|=1;if(keys&PAD_LEFT)cmd|=2;if(keys&PAD_DOWN)cmd|=4;if(keys&PAD_UP)cmd|=8;
  if(pressed&PAD_A){cmd&=3;cmd|=16;}
  if(pressed&PAD_B){if(keys&PAD_DOWN){cmd&=7;cmd|=16;}else{cmd&=3;cmd|=24;}}
  cvw8(0x6350ul,cmd);
  d[0]=(u16)VM_W(0x69f2u);d[1]=(u16)VM_W(0x69f4u);
 }
 while(vm_phase<8){
  entry=vm_phase?phase_entry[vm_phase]:vm_player_state;cat_exec(entry);audio_frame();
  if(vm_busy||game.game_over_wait||game.boss_state==B_COMPLETE||vm_fault)break;
  vm_phase++;
 }
 if(vm_phase==8){PERF_LOGIC();vm_phase=0;cvw16(0x6374ul,(u16)(VM_W(0x6374u)+1));}
 sync_player();game.last_keys=keys;
}

#ifndef VM_HOST
#include "session.h"
void cat_state_io(void){session_io(&pending_damage,sizeof(pending_damage));session_io(&clear_draws,sizeof(clear_draws));}
#endif
