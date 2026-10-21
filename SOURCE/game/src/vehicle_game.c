#include "session.h"
/* Original vehicle update order, physics, AI, route/checkpoint and balloon rules. */
#include "vehicle.h"
#include "game.h"
#include "bitmap.h"
#include "audio.h"
#include "hardware_perf.h"
#include "video.h"
#include "ngpc_sys.h"
static u16 pending_damage;
extern volatile u8 g_vb_counter;
u8 vehicle_profile[16];
extern s16 vehicle_road_y;
static const u16 roots[13]={0x67ba,0x6b02,0x764a,0x74c8,0x6d40,0x51da,0x5086,0x4792,0x5764,0x6f1c,0x4cb2,0x3f70,0x3be0};
static void lose_life(void){u8 status=ver8(0x7c874ul);if(cheat_invulnerable)return;pending_damage=0;if(status&4)return;status|=4;if(!game.lives)status|=2;else game.lives--;vew8(0x7c874ul,status);}
static void hurt(u8 value){if(cheat_invulnerable)return;if(game.health&&!(ver8(0x7c874ul)&4)){pending_damage+=value;game.damage_taken+=value;}}
static void panel_update(void){
 if(pending_damage&&game.health){pending_damage--;game.health--;if(!game.health)lose_life();}
 if(!cheat_freeze_time&&++game.subsecond>=50){game.subsecond=0;if(game.seconds)game.seconds--;else{vew8(0x7c874ul,(u8)(ver8(0x7c874ul)|1));lose_life();}}
 vehicle_energy=game.health;
}
static void restart(void){session_respawn_score();game.health=40;game.alive=1;game.boss_state=B_NONE;pending_damage=0;game.subsecond=0;game.game_over_wait=0;vew8(0x7c874ul,0);vehicle_energy=40;vehicle_exec(vehicle_stage==2?0x3884:0x392e);}
void vehicle_new(u8 stage){u16 i;u8 *p=(u8 *)&game;for(i=0;i<sizeof(game);i++)p[i]=0;game.lives=2;game.seconds=stage==2?300:180;vm_wait=vm_phase=bob_draw_count=0;vehicle_reset(stage);restart();}
int vehicle_external(u32 pc){u8 i;u32 value,score=0,mult=1;audio_frame();
 if(pc==0x4ec0ul||pc==0x4fccul)vehicle_draw_bob();
 else if(pc==0x4b06ul)vehicle_draw_column();
 else if(pc==0x6fa8ul)vehicle_draw_road_row();
 else if(pc==0x712aul)vehicle_draw_skyline();
 else if(pc==0x3728ul){d[0]=0;fz=1;fn=fv=fc=0;}
 else if(pc==0x7c870ul)hurt((u8)d[0]);
 else if(pc==0x7c862ul)lose_life();
 else if(pc==0x7c854ul){game.health=40;vehicle_energy=40;pending_damage=0;}
 else if(pc==0x7c80eul){value=d[0];game.seconds=(u16)(((value>>12)&15ul)*600ul+((value>>8)&15ul)*60ul+((value>>4)&15ul)*10ul+(value&15ul));game.subsecond=0;}
 else if(pc==0x7c82aul){if(run_score_disabled)return 0;value=d[0];for(i=0;i<6;i++){score+=(value&15ul)*mult;mult*=10ul;value>>=4;}session_award_points(score);}
 else if(pc==0x68f94ul||pc==0x68f8cul){if((u8)d[0]>=7)audio_effect((u8)((u8)d[0]>13?13:d[0]));}
 else if(pc==0x68f84ul)audio_stop();
 else if(pc==0x3b6eul||pc==0x82cul||pc==0x834ul){game.boss_state=B_COMPLETE;return 1;}
 else if(pc==0x820ul||pc==0x3b18ul){game.ended=1;return 1;}
 else if(pc==0x39ceul)return 1;
 return 0;
}
void vehicle_tick(u8 keys,u8 pressed){u8 i,cmd=0,before;u16 reason;
 (void)pressed;game.ticks++;vew16(0x37bcul,(u16)(game.ticks*2u));
 if(game.ended||game.boss_state==B_COMPLETE)return;
 if(game.game_over_wait){if(!--game.game_over_wait){if(ver8(0x7c874ul)&2)game.ended=1;else{restart();audio_music(1);}}return;}
 panel_update();panel_update();
 if(keys&PAD_UP)cmd|=1;if(keys&PAD_DOWN)cmd|=2;if(keys&PAD_LEFT)cmd|=4;if(keys&PAD_RIGHT)cmd|=8;
 vew16(0x3708ul,(u16)cmd|((keys&(PAD_A|PAD_B))?0xff00u:0));
 for(i=0;i<13;i++){
  if(i==7){if(vehicle_stage==2){vehicle_exec(0x459c);vehicle_exec(0x44a8);}else vehicle_exec(0x42be);}
  if(i==9){while(!video_bitmap_available())ngpc_vsync();before=g_vb_counter;bitmap_begin();vehicle_profile[14]=(u8)(g_vb_counter-before);vehicle_road_y=151;}before=g_vb_counter;
#if !defined(VM_HOST)||defined(M11_NATIVE_HOST)
 if(i==9)vehicle_road_native();else if(i==10)vehicle_scene_native();else
#endif
 vehicle_exec(roots[i]);vehicle_profile[i]=(u8)(g_vb_counter-before);audio_frame();if(vm_fault||game.ended||game.boss_state==B_COMPLETE)break;
 }
 if(i==13u)PERF_LOGIC();
 reason=ver16(0x8f66ul);
 if(reason||((ver8(0x7c874ul)&7u)&&vehicle_stage==2)){
  if(reason==1)lose_life();game.game_over_wait=30;game.alive=0;audio_music(3);
 }else if(vehicle_stage==4&&(ver8(0x7c874ul)&7u)&&!ver16(0x8d38ul))vew16(0x8d38ul,25);
 game.player.x=(s16)ver16(0x8d72ul);game.player.y=(s16)ver16(0x8d6cul);game.player.state=reason?P_DYING:P_GROUND;if(!game.checkpoint&&(vehicle_stage==2?ver16(0x8d22ul)<=500:ver16(0x8d24ul)<=50))session_checkpoint_score();game.checkpoint=(u8)((vehicle_stage==2?ver16(0x8d22ul)<=500:ver16(0x8d24ul)<=50)?1:0);
 game.last_keys=keys;
}

#ifndef VM_HOST
#include "session.h"
void vehicle_state_io(void){session_io(&pending_damage,sizeof(pending_damage));}
#endif
