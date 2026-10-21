#include "session.h"
/* Original Batcave:8 products,3 different selections,7 attempts,source scoring. */
#include "puzzle.h"
#include "game.h"
#include "bitmap.h"
#include "audio.h"
#include "hardware_perf.h"
extern volatile u16 display_frames;
static void score_bcd(u32 value){u8 i;u32 score=0,mult=1;if(run_score_disabled)return;for(i=0;i<6;i++){score+=(value&15ul)*mult;mult*=10ul;value>>=4;}session_award_points(score);}
static void restart(void){
 session_respawn_score();
#if HW_PERF
 puzzle_reset(hardware_test?1989u:display_frames);
#else
 puzzle_reset(display_frames);
#endif
game.health=40;game.seconds=59;game.subsecond=0;game.alive=1;game.boss_state=B_NONE;game.game_over_wait=0;}
void puzzle_new(void){u8 *p=(u8 *)&game;u16 i;for(i=0;i<sizeof(game);i++)p[i]=0;game.lives=2;vm_wait=vm_phase=bob_draw_count=0;restart();}
int puzzle_external(u32 pc){u16 id,x,y,attempt,slot;
 if(pc==0xde94ul){
  id=pvr16(0xe154ul);x=pvr16(0xe122ul);y=pvr16(0xe126ul);
  if(id>=1&&id<=8&&x>=104&&x<=218&&(y==19||y==49||y==79)){
   attempt=(x-104u)/19u;slot=(y-19u)/30u;if(attempt<7&&slot<3)puzzle_ram[160u+attempt*3u+slot]=(u8)id;
  }
 }else if(pc==0xe382ul){attempt=(pvr16(0xd8d8ul)-115u)/19u;if(attempt<7)puzzle_ram[181u+attempt]=(u8)(pvr8(0xd8d6ul)-'0'+1u);}
 else if(pc==0x7c82aul)score_bcd(d[0]);
 else if(pc==0x7c870ul){if(cheat_invulnerable)return 0;if(game.health>(u8)d[0])game.health-=(u8)d[0];else game.health=0;}
 else if(pc==0x4014ul)audio_effect((u8)(d[0]==5?5:9));
 else if(pc==0xd95aul){game.boss_state=B_COMPLETE;game.alive=1;audio_effect(8);return 1;}
 else if(pc==0xd9e6ul){
  game.alive=0;game.game_over_wait=40;if(!game.lives&&!cheat_invulnerable)puzzle_ram[210]=1;else if(!cheat_invulnerable)game.lives--;audio_effect(11);return 1;
 }
 return 0;
}
void puzzle_tick(u8 keys,u8 pressed){u16 joy=0;u8 *p;
 (void)pressed;game.ticks++;
 if(game.ended||game.boss_state==B_COMPLETE)return;
 if(game.game_over_wait){if(!--game.game_over_wait){if(puzzle_ram[210])game.ended=1;else restart();}return;}
 if(!cheat_freeze_time&&++game.subsecond>=50){game.subsecond=0;if(game.seconds)game.seconds--;else{puzzle_external(0xd9e6);return;}}
 if(keys&PAD_UP)joy^=0x0100;if(keys&PAD_DOWN)joy^=0x0001;if(keys&PAD_LEFT)joy^=0x0300;if(keys&PAD_RIGHT)joy^=0x0003;
 puzzle_ram[200]=(u8)(joy>>8);puzzle_ram[201]=(u8)joy;puzzle_ram[202]=(keys&(PAD_A|PAD_B))?0:128;
 puzzle_ram[205]=0;puzzle_ram[206]=(u8)(((game.seconds/10u)<<4)|(game.seconds%10u));
 puzzle_exec(0xd5a8);if(!game.game_over_wait&&game.boss_state!=B_COMPLETE)puzzle_exec(0xd56a);
 PERF_LOGIC();game.player.x=(s16)pvr16(0xe124ul);game.player.y=(s16)pvr16(0xe128ul);game.player.state=P_GROUND;game.last_keys=keys;
}
void puzzle_draw(void){native_puzzle_draw();}
