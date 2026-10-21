#include "session.h"
/* First-level gameplay executes translated original 68000 routines.
 * Hardware-specific presentation, panel and audio boundaries are native. */
#include "game.h"
#include "faithful.h"
#include "audio.h"
#include "hardware_perf.h"
#define VM_W(p) ((u16)((u16)vm_vars[(p)-0x62deu]<<8)|vm_vars[(p)-0x62deu+1u])
Game game;
RenderWork render_work;
u8 bob_draw_count,vm_wait,vm_phase;
static u16 pending_damage;
static u8 clear_draws;
static const u16 phase_entry[8]={0,0x4936,0x3dd4,0x3dfe,0x56a6,0x3ee6,0x4658,0x45fe};
u8 game_tile(s16 x,s16 y){if(x<0||y<0||x>=1536||y>=328)return 0;return vr8(0x807cul+(u16)(y>>3)*192u+(u16)(x>>3));}
static void zero_bytes(void *p,u16 count){u8 *b=(u8 *)p;while(count--)*b++=0;}
static void sync_player(void){
 Player *p=&game.player;u16 state=vm_player_state;u8 i;
 p->x=(s16)VM_W(0x67bcu)+(s16)VM_W(0x67c2u);p->y=(s16)VM_W(0x67beu)+(s16)VM_W(0x67c4u);
 p->facing=(u8)((VM_W(0x62eeu)&0x2000u)!=0);
 p->state=state==0x5482?P_FALL:state==0x5308?P_CLIMB:state==0x5132||state==0x51b0?P_HOOK:
          state==0x4e64||state==0x4e3a?P_HANG:state==0x5058?P_PULLUP:state==0x555a?P_LAND:state==0x4da2?P_DYING:P_GROUND;
 p->rope_length=(s16)VM_W(0x6318u);p->hook_x=p->x+(p->facing?-4:3)+(s16)VM_W(0x631au);
 p->hook_y=p->y-12-(s16)VM_W(0x631cu);p->invulnerable=0;
 /* Axis respawn currently has two physical spawn positions (0/nonzero). */
 if(!game.checkpoint&&VM_W(0x62fcu))session_checkpoint_score();
 game.checkpoint=(u8)VM_W(0x62fcu);
 game.boss_state=game.boss_state==B_COMPLETE?B_COMPLETE:B_NONE;
 for(i=0;i<10;i++){
  u16 at=(u16)(0x39c8u+i*22u);u16 id=(u16)((u16)vm_actors[i*22u]<<8)|vm_actors[i*22u+1u];
  if(id==25&&game.boss_state!=B_COMPLETE){game.boss_state=B_SPLASH;game.boss_x=(s16)vr16(at+2);game.boss_y=(s16)vr16(at+4);}
 }
}
void game_reset_position(void){
 vm_reset(game.checkpoint);vm_wait=vm_phase=clear_draws=0;bob_draw_count=0;
 session_respawn_score();
 pending_damage=0;game.seconds=480;game.subsecond=0;game.health=40;game.alive=1;game.game_over_wait=0;game.boss_state=B_NONE;
 sync_player();
}
void game_new(void){zero_bytes(&game,(u16)sizeof(game));game.lives=2;game.seconds=480;game_reset_position();}
static void lose_life(void){
 u8 status=vr8(0x7c874ul);if(cheat_invulnerable)return;pending_damage=0;
 if(status&4)return;
 status|=4;if(!game.lives)status|=2;else game.lives--;
 vw8(0x7c874ul,status);
}
void game_hurt(u8 value){if(cheat_invulnerable)return;if(game.health&&!(vr8(0x7c874ul)&4)){pending_damage+=value;game.damage_taken+=value;}}
static void panel_update(void){
 if(pending_damage&&game.health){pending_damage--;game.health--;if(!game.health)lose_life();}
 if(!cheat_freeze_time&&!(vr8(0x7c874ul)&1)){
  if(++game.subsecond>=50){game.subsecond=0;if(game.seconds)game.seconds--;else vw8(0x7c874ul,(u8)(vr8(0x7c874ul)|1));}
 }
}
u8 game_actor_count(void){u8 i,n=0;for(i=0;i<10;i++)if(vm_actors[i*22u]||vm_actors[i*22u+1u])n++;return n;}
int vm_external(u32 pc){
 u8 i;u32 value,score=0,mult=1;
 if(pc==0x56f4ul){
  u16 id=(u16)d[2];
  if(bob_draw_count<64&&(id&0x1ffu)&&(id&0x1ffu)<=305u){
   BobDraw *b=&bob_draws[bob_draw_count++];b->x=(s16)d[0];b->y=(s16)d[1];b->id=id;
  }
 }else if(pc==0x7c870ul)game_hurt((u8)d[0]);
 else if(pc==0x7c862ul)lose_life();
 else if(pc==0x7c82aul){
  if(run_score_disabled)return 0;
  value=d[0];for(i=0;i<6;i++){score+=(value&15ul)*mult;mult*=10ul;value>>=4;}
  session_award_points(score);
 }else if(pc==0x48014ul)audio_effect((u8)d[0]);
 else if(pc==0x48010ul)audio_music((u8)d[0]);
 else if(pc==0x48004ul)audio_stop();
 else if(pc==0x4db2ul){
  game.alive=0;game.game_over_wait=41;vm_busy=0;return 1;
 }else if(pc==0x5e3aul||pc==0x5e60ul){
  game.boss_state=B_COMPLETE;vm_busy=0;audio_music(2);return 1;
 }else if(pc==0x5e8cul||pc==0x36faul){
  vm_wait=pc==0x36faul?1:(u8)(((u16)d[0]+2u)/2u);
  if(!vm_wait)vm_wait=1;vm_resume=vr32(a[7]);a[7]+=4;vm_busy=1;
  if(pc==0x36faul){vw16(0x632cul,(u16)(VM_W(0x632cu)+1));clear_draws=1;}
  return 1;
 }
 return 0;
}
void game_tick(u8 keys,u8 pressed){
 u8 cmd=0;u16 entry;
 game.ticks++;vw16(0x36eeul,(u16)(game.ticks*2));
 if(game.ended||game.boss_state==B_COMPLETE)return;
 if(game.game_over_wait){
  if(!--game.game_over_wait){if(vr8(0x7c874ul)&2)game.ended=1;else{game_reset_position();audio_music(1);}}
  sync_player();return;
 }
 if(vm_wait){if(--vm_wait)return;if(clear_draws){bob_draw_count=0;clear_draws=0;}}
 if(!vm_phase&&!vm_busy){
  panel_update();panel_update();bob_draw_count=0;
  if(keys&PAD_RIGHT)cmd|=1;if(keys&PAD_LEFT)cmd|=2;if(keys&PAD_DOWN)cmd|=4;if(keys&PAD_UP)cmd|=8;
  if(pressed&PAD_A){cmd&=3;cmd|=16;}
  if(pressed&PAD_B){if(keys&PAD_DOWN){cmd&=7;cmd|=16;}else{cmd&=3;cmd|=24;}}
  vw8(0x6308ul,cmd);
  d[0]=(u16)VM_W(0x67c2u);d[1]=(u16)VM_W(0x67c4u);
 }
 while(vm_phase<8){
  entry=vm_phase?phase_entry[vm_phase]:vm_player_state;vm_exec(entry);audio_frame();
  if(vm_busy||game.game_over_wait||game.boss_state==B_COMPLETE||vm_fault)break;
  vm_phase++;
 }
 if(vm_phase==8){PERF_LOGIC();vm_phase=0;vw16(0x632cul,(u16)(VM_W(0x632cu)+1));}
 sync_player();game.last_keys=keys;
}
#ifdef VM_GAME
#include <string.h>
extern u16 vm_host_state(u8 *,u8);
u16 game_host_state(u8 *buffer,u8 load){
 u16 at=0;
#define COPY(v) do {if(load)memcpy(&(v),buffer+at,sizeof(v));else memcpy(buffer+at,&(v),sizeof(v));at+=(u16)sizeof(v);}while(0)
 COPY(game);COPY(bob_draws);COPY(bob_draw_count);COPY(vm_wait);COPY(vm_phase);COPY(clear_draws);COPY(pending_damage);
#undef COPY
 return (u16)(at+vm_host_state(buffer+at,load));
}
#endif

#ifndef VM_HOST
#include "session.h"
void game_state_io(void){session_io(&pending_damage,sizeof(pending_damage));session_io(&clear_draws,sizeof(clear_draws));}
#endif
