/* Tile maps are static ROM assets. Gameplay changes only map-edge entries,
 * character descriptors and changed animation patterns. No pixel background
 * reconstruction, no room-sized staging transaction, no in-game VBlank wait.
 */
#include "video.h"
#include "session.h"
#include "leaderboard.h"
#include "ngpc_qr_pixel.h"
#include "ngpc_sys.h"
#include "faithful.h"
#include "cathedral.h"
#include "bitmap.h"
#include "puzzle.h"
#include "vehicle.h"
extern u8 active_stage;
extern const u16 cathedral_pixels[920],cathedral_palettes[64];
extern const u8 cathedral_tile_pal[115];
#include "ngpc_hw.h"
#include "ngpc_gfx.h"
#include "ngpc_sprite.h"
#define FONT_BASE 400
#define HUD_FONT_BASE 400
#define HUD_BAR_BASE ((active_stage>=2&&active_stage<=4)?385u:352u)
#define HUD_ROW (active_stage==5?3:0)
#define PLAYFIELD_Y (active_stage==5?48:24)
#define PLAYFIELD_BOTTOM (active_stage==5?136:144)
#define SCENE_ROWS (active_stage==5?12:16)
extern const u16 compact_health_words[615];
#define ACTOR_BASE 224
#define ACTOR_STRIDE 24
#define SHOT_BASE 352
#define ROPE_BASE 160
#define SOLID_TILE 464
#define HAZARD_BASE 400
#define HAZARD_STRIDE 14
#define HAZARD_BANKS 7
u16 camera_x,camera_y,video_tile_writes,video_sprite_count;
u16 video_max_sprites,video_overflows,video_background_reloads;
u16 video_present_count,video_visible_tick,video_visible_camera_x,video_visible_camera_y;
u16 graphics_platform_hits,graphics_platform_misses;
static u16 pending_game_tick;
volatile u8 video_present_ready;
#define present_ready video_present_ready
static u8 bitmap_first;
static u16 hud_stage_value,hud_speed;
static s16 map_column,map_row;
#define sprite_words (render_work.platform.sprites)
#define sprite_palette_words (render_work.platform.palettes)
#define sprite_cache (render_work.platform.cache)
#define rope_old_x (render_work.platform.oldx)
#define rope_old_y (render_work.platform.oldy)
#define rope_new_x (render_work.platform.newx)
#define rope_new_y (render_work.platform.newy)
#define rope_pixels (render_work.platform.rope)
static u16 hud_map_index[60];
static u8 packed_sprite_count;
extern void ngpc_memcpy_w(u32 dst,u32 src,u32 words);
extern void graphics_diff_words(u32 dst,u32 src,u32 words);
#include "hardware_perf.h"

static u8 pattern_bank;
static u8 old_sprite_count;
static u8 cache_hazard[HAZARD_BANKS],hazard_first,hazard_end;
static u8 hud_chars[60],hud_char_dirty[60],hud_bar_dirty[15],hud_palette_dirty,hud_palette_hp;
static u16 hud_bar_words[15];
static u32 hud_score,hud_best_score;
#define session_best_score best_score
static u16 hud_time;
static u8 hud_health,hud_lives;
static u8 rope_old_count;
static u8 rope_new_count;

static void tile_load(u16 id,const u16 *p){graphics_diff_words(0xa000ul+(u32)id*16ul,(u32)p,8ul);video_tile_writes++;}
#include "platform_residency.inc"
static void setpal(u8 plane,const u16 *p){u8 i;for(i=0;i<16;i++)ngpc_gfx_set_palette(plane,i,p[i*4],p[i*4+1],p[i*4+2],p[i*4+3]);}
static void ui_palettes(void){
 ngpc_gfx_set_palette(0,15,0,RGB(13,13,14),RGB(0,0,0),RGB(15,11,2));
 ngpc_gfx_set_palette(0,14,0,RGB(15,11,2),RGB(0,0,0),RGB(8,8,10));
}
static void font_load(void){
 u16 a[8];u8 i;
 ngpc_gfx_load_tiles_at(font_pixels,512,FONT_BASE);
 for(i=0;i<8;i++)a[i]=0xaaaau;
 tile_load(SOLID_TILE,a);ui_palettes();
}
/* Colour 0 is transparent on K2GE. Every off-pixel, including SPACE,
   must instead be opaque black in menus placed over the playfield. */
static void font_load_opaque(void){u16 pixels[8],word,ink;u8 i,j;
 for(i=0;i<64u;i++){for(j=0;j<8u;j++){word=font_pixels[(u16)i*8u+j];ink=(u16)((word|(word>>1))&0x5555u);pixels[j]=(u16)(0xaaaau^(ink|(ink<<1)));}tile_load((u16)(FONT_BASE+i),pixels);}
 {u8 k;for(k=0;k<8u;k++)pixels[k]=0xaaaau;}tile_load(SOLID_TILE,pixels);ui_palettes();
}
static void stars_load(void){static const u16 tile[8]={0,0,0x0040,0,0,0,0,0};static const u8 cells[16]={1,4,4,5,7,3,10,5,13,4,17,3,18,6,9,6};u8 i;
 if(active_stage!=2u&&active_stage!=4u)return;
 tile_load(465u,tile);ngpc_gfx_set_palette(0,12,0,RGB(7,8,10),0,0);
 for(i=0;i<8u;i++)ngpc_gfx_put_tile(0,cells[i*2u],cells[i*2u+1u],465u,12);
}
static void text(u8 x,u8 y,const char *s,u8 pal){
 u8 ch;
 while(*s&&x<20){ch=(u8)*s++;if(ch<32||ch>95)ch=32;ngpc_gfx_put_tile(0,x++,y,(u16)(FONT_BASE+ch-32),pal);}
}
static void centered(u8 y,const char *s,u8 pal){u8 len=0;const char *q=s;while(*q++)len++;if(len>20)len=20;text((u8)((20-len)/2),y,s,pal);}
static void blank_ui(void){ngpc_gfx_clear(0);ui_palettes();}
/* Hidden windows expose this palette, not the backdrop colour. */
static void ui_window_black(void){u8 i;for(i=0;i<8u;i++)HW_PAL_WIN[i]=0;}
void video_title_load(void){
 u16 i;
 HW_SCR_PRIO &= (u8)~0x80u; /* restore SCR1 HUD/title front priority */
 present_ready=0;
 ui_window_black();ngpc_gfx_set_viewport(0,0,0,0);ngpc_gfx_set_bg_color(0);
 ngpc_sprite_hide_all();old_sprite_count=0;rope_old_count=0;
 ngpc_gfx_scroll(0,0,0);ngpc_gfx_scroll(1,0,0);
 ngpc_gfx_clear(0);ngpc_gfx_clear(1);font_load();
 ngpc_gfx_load_tiles_at(title_pixels,2080,1);
 for(i=0;i<260;i++)ngpc_gfx_put_tile(1,(u8)(i%20),(u8)(i/20),i+1,title_tile_pal[i]);
 video_title_fade(0);ngpc_gfx_set_viewport(0,0,160,152);
 centered(14,"OCEAN SOFTWARE",15);centered(16,"BATMAN THE MOVIE",14);
 centered(18,"PRESS A OR B",15);
}
void video_title_fade(u8 value){
 u8 i,j,r,g,b;u16 colors[4],c;
 for(i=0;i<16;i++){
  for(j=0;j<4;j++){
   c=title_palettes[i*4+j];r=(u8)((c&15)*value/16);g=(u8)(((c>>4)&15)*value/16);b=(u8)(((c>>8)&15)*value/16);colors[j]=RGB(r,g,b);
  }
  ngpc_gfx_set_palette(1,i,colors[0],colors[1],colors[2],colors[3]);
 }
}
void video_title_reveal(u8 rows){if(rows>100)rows=100;ngpc_gfx_set_viewport(0,(u8)(100-rows),160,rows);}
void video_menu(u8 choice){
 blank_ui();video_menu_update(choice);ngpc_gfx_set_viewport(0,0,160,152);
}
void video_menu_update(u8 choice){
 u8 line=0,i;
 for(i=0;i<5u;i++)text(1,(u8)(13u+i)," ",15);
#if HW_PERF
 centered(11,"B: HARDWARE TESTS",14);
#endif
 if(save_available){centered(13,"CONTINUE",choice==line?14:15);line++;}
 centered((u8)(13+line),"NEW GAME",choice==line?14:15);line++;
 centered((u8)(13+line),"OPTIONS",choice==line?14:15);line++;
 centered((u8)(13+line),"RECORDS",choice==line?14:15);line++;
 centered((u8)(13+line),"CREDITS",choice==line?14:15);
 text(1,(u8)(13+choice),">",14);
 if(save_error)centered(11,"SAVE FAILED - RETRY",14);
 if(cheat_unlocked)text(0,18,active_stage==1?"< 1 AXIS CHEMICALS > ":active_stage==2?"  < 2 BATMOBILE >    ":active_stage==3?"   < 3 BATCAVE >     ":active_stage==4?"   < 4 BATWING >     ":" < 5 CATHEDRAL >     ",15);
}
void video_controls(u8 audio_on){
 present_ready=0;
 ngpc_gfx_set_viewport(0,0,0,0);
 ngpc_gfx_fill_rect(1,0,3,20,16,0,0);
 blank_ui();ngpc_gfx_fill_rect(0,0,3,20,16,SOLID_TILE,15);
 centered(4,"HOW TO PLAY",14);
 if(active_stage==2){text(1,6,"L/R    STEER",15);text(1,8,"UP/DN  GAS / BRAKE",15);text(1,10,"A/B+L/R GRAPPLE",15);text(1,12,"WATCH ROAD SIGNS",15);}
 else if(active_stage==4){text(1,6,"D-PAD  FLY / STEER",15);text(1,8,"A / B  FIRE",15);text(1,10,"A/B+UP/DN THROTTLE",15);text(1,12,"DESTROY THE BALLOONS",15);}
 else if(active_stage==3){text(1,6,"D-PAD  SELECT",15);text(1,8,"A / B  CHOOSE",15);text(1,10,"FIND 3 PRODUCTS",15);text(1,12,"7 GUESSES",15);}
 else{text(1,6,"D-PAD  MOVE / CLIMB",15);text(1,8,"A      BATARANG",15);text(1,10,"B      GRAPPLE",15);text(1,12,"DOWN+B DROP THROUGH",15);}
 text(1,14,"OPTION PAUSE",15);
 centered(18,"B: BACK",15);
 ngpc_gfx_set_viewport(0,0,160,152);
}
void video_credits(void){video_credits_page(0);}
static void map_put(s16 wx,s16 wy){
 u8 cell=0,pal=0;
 if(active_stage==5){
  if(wx>=0&&wx<88&&wy>=0&&wy<203){cell=cat_map_read((u16)wy*88u+(u16)wx);pal=cathedral_tile_pal[cell];}
 }else if(wx>=0&&wx<192&&wy>=0&&wy<41){cell=axis_map[(u16)wy*192u+(u16)wx];pal=axis_tile_pal[cell];}
 {u16 value=(u16)(cell+1u)|((u16)pal<<9);volatile u16 *dst=HW_SCR2_MAP+((u16)(wy&31)<<5)+(u16)(wx&31);if(*dst!=value)*dst=value;}
}
static void map_fill(void){
 s16 x,y;
 for(y=map_row;y<map_row+SCENE_ROWS;y++)for(x=map_column;x<map_column+21;x++)map_put(x,y);
 video_background_reloads++;
}
static s16 clamp(s16 v,s16 lo,s16 hi){return v<lo?lo:v>hi?hi:v;}
static void camera_update(u8 full){
 s16 col,row,x,y,dx,dy,tx,ty;
 if(active_stage==5){tx=(s16)cvr16(0x69ecul);ty=(s16)cvr16(0x69eeul);}
 else{tx=(s16)vr16(0x67bcul);ty=(s16)vr16(0x67beul);}
 camera_x=(u16)tx;camera_y=(u16)ty;
 col=camera_x>>3;row=camera_y>>3;
 dx=col-map_column;dy=row-map_row;
 if(full||dx<=-21||dx>=21||dy<=-SCENE_ROWS||dy>=SCENE_ROWS){map_column=col;map_row=row;map_fill();}
 else{
  while(map_column<col){map_column++;for(y=map_row;y<map_row+SCENE_ROWS;y++)map_put(map_column+20,y);}
  while(map_column>col){map_column--;for(y=map_row;y<map_row+SCENE_ROWS;y++)map_put(map_column,y);}
  while(map_row<row){map_row++;for(x=map_column;x<map_column+21;x++)map_put(x,map_row+SCENE_ROWS-1);}
  while(map_row>row){map_row--;for(x=map_column;x<map_column+21;x++)map_put(x,map_row);}
 }

}
static void hud_palettes(void){
 ngpc_gfx_set_palette(0,15,0,RGB(0,0,0),RGB(6,7,8),RGB(15,15,15));
 ngpc_gfx_set_palette(0,14,0,RGB(13,13,14),RGB(0,0,0),RGB(15,11,0));
 ngpc_gfx_set_palette(0,13,0,RGB(0,0,0),RGB(5,6,7),
  hud_palette_hp>20?RGB(1,13,6):hud_palette_hp>10?RGB(15,11,0):RGB(15,2,2));
}
static void hud_font_load(void){
 u16 pixels[8],word,ink;u8 i,j;
 for(i=0;i<64;i++){
  for(j=0;j<8;j++){
   word=font_pixels[(u16)i*8u+j];ink=(u16)((word|(word>>1))&0x5555u);
   pixels[j]=(u16)(0x5555u|(ink<<1));
  }
  tile_load((u16)(HUD_FONT_BASE+i),pixels);
 }
}
static void hud_char(u8 x,u8 row,u8 ch){
 u8 at=(u8)(row*20+x);
 if(ch<32||ch>95)ch=32;
 if(hud_chars[at]!=ch){hud_chars[at]=ch;hud_char_dirty[at]=1;}
}
static void hud_text(u8 x,u8 row,const char *s){while(*s&&x<20)hud_char(x++,row,(u8)*s++);}
static void hud_number(u8 x,u8 row,u32 value){
 static const u32 place[6]={100000ul,10000ul,1000ul,100ul,10ul,1ul};
 u8 i,n;
 if(value>=1000000ul)value%=1000000ul;
 for(i=0;i<6;i++){n=0;while(value>=place[i]){value-=place[i];n++;}hud_char((u8)(x+i),row,(u8)('0'+n));}
}
static void hud_short(u8 x,u8 row,u16 value){if(value>999u)value=999u;hud_char(x,row,(u8)('0'+value/100u));hud_char(x+1u,row,(u8)('0'+(value/10u)%10u));hud_char(x+2u,row,(u8)('0'+value%10u));}
static void hud_layout(void){
 u8 x,y,bar_y;
 ngpc_gfx_clear(0);hud_palette_hp=game.health;hud_palettes();
 if(active_stage==5){
  /* Preserve the previously delivered Cathedral R1 HUD layout. */
  ngpc_gfx_fill_rect(0,0,0,20,HUD_ROW,SOLID_TILE,14);
  ngpc_gfx_fill_rect(0,0,17,20,2,SOLID_TILE,14);
  bar_y=HUD_ROW;
 }else{
  /* Three compact statistic rows, a 120-pixel game viewport and one HP row. */
  ngpc_gfx_fill_rect(0,0,0,20,3,SOLID_TILE,14);
  ngpc_gfx_fill_rect(0,0,18,20,1,SOLID_TILE,14);
  bar_y=18;
 }
 for(y=0;y<3;y++)for(x=0;x<20;x++){
  hud_chars[y*20u+x]=255;hud_char_dirty[y*20u+x]=0;
  hud_map_index[y*20u+x]=(u16)(HUD_ROW+y)*32u+x;
  ngpc_gfx_put_tile(0,x,(u8)(HUD_ROW+y),HUD_FONT_BASE,15);
 }
 for(x=0;x<15;x++){ngpc_gfx_put_tile(0,(u8)(4+x),bar_y,(u16)(HUD_BAR_BASE+x),13);hud_bar_dirty[x]=1;}
 if(active_stage==5){
  hud_text(1,0,"HP");hud_text(1,1,"PTS");hud_text(11,1,"TIME");
  hud_text(1,2,"BEST");hud_text(12,2,"LIFE ");
  centered(1,"BATMAN THE MOVIE",15);centered(17,"GOTHAM CATHEDRAL",15);
 }else{
  text(0,18,"HP",15);
  hud_text(0,0,"PTS");hud_text(11,0,"TIME");
  hud_text(0,1,"BEST");hud_text(12,1,"LIFE ");
  if(active_stage==2||active_stage==4){
   hud_text(0,2,active_stage==2?"DIST":"BAGS");hud_text(9,2,"SPD");
  }else if(active_stage==3)hud_text(0,2,"TRY");
  else hud_text(0,2,"A:THROW  B:GRAPPLE");
 }
 stars_load();
 hud_stage_value=hud_speed=65535u;
 hud_score=hud_best_score=0xfffffffful;hud_time=65535u;hud_health=hud_lives=255;
}
static void hud_update(void){
 u8 i,hp,lives,main_row=(u8)(active_stage==5?1:0);
 u16 at,word,seconds;u32 score;
 session_record_live();score=run_preview_score;
 if(game.health!=hud_health){
  hp=game.health>40?40:game.health;at=(u16)hp*15u;
  for(i=0;i<15;i++){
   word=compact_health_words[at+i];
   if(word!=hud_bar_words[i]){hud_bar_words[i]=word;hud_bar_dirty[i]=1;}
  }
  hud_palette_hp=hp;hud_palette_dirty=1;hud_health=game.health;
 }
 if(score!=hud_score){if(run_score_disabled||run_cheated){hud_char(4,main_row,' ');hud_char(5,main_row,'O');hud_char(6,main_row,'F');hud_char(7,main_row,'F');hud_char(8,main_row,' ');hud_char(9,main_row,' ');}else hud_number(4,main_row,score);hud_score=score;}
 if(session_best_score!=hud_best_score){hud_number(5,(u8)(active_stage==5?2:1),session_best_score);hud_best_score=session_best_score;}
 if(active_stage==2||active_stage==3||active_stage==4){
  at=active_stage==3?(u16)(pvr16(0xdc00ul)+1u):ver16(active_stage==2?0x8d22ul:0x8d24ul);
  if(at!=hud_stage_value){if(active_stage==3)hud_number(5,2,at);else hud_short(5,2,at);hud_stage_value=at;}
  if(active_stage!=3){at=ver16(0x8f6eul)>>1;if(at!=hud_speed){hud_short(12,2,at);hud_speed=at;}}
 }
 if(game.seconds!=hud_time){
  seconds=game.seconds;
  if(active_stage==5){hud_char(15,main_row,(u8)('0'+seconds/600u));hud_char(16,main_row,(u8)('0'+(seconds/60u)%10u));hud_char(17,main_row,':');seconds%=60u;hud_char(18,main_row,(u8)('0'+seconds/10u));hud_char(19,main_row,(u8)('0'+seconds%10u));}
  else{hud_char(15,main_row,(u8)('0'+seconds/60u));hud_char(16,main_row,':');seconds%=60u;hud_char(17,main_row,(u8)('0'+seconds/10u));hud_char(18,main_row,(u8)('0'+seconds%10u));}hud_time=game.seconds;
 }
 if(game.lives!=hud_lives){
  lives=(u8)(game.ended?0u:game.lives+1u);if(lives>9u)lives=9u;hud_char(17,(u8)(active_stage==5?2:1),lives>=10?(u8)('0'+lives/10u):' ');
  hud_char(18,(u8)(active_stage==5?2:1),(u8)('0'+lives%10u));hud_lives=game.lives;
 }
}
/* Decimal formatting and dirty detection run in main context. The IRQ
 * commits only prepared words; it never reads a partially updated Game. */
static void hud_commit(void){
 u8 i,j;u16 pixels[8];
 if(hud_palette_dirty){hud_palettes();hud_palette_dirty=0;}
 for(i=0;i<60;i++)if(hud_char_dirty[i]){
  HW_SCR1_MAP[hud_map_index[i]]=(u16)(HUD_FONT_BASE+hud_chars[i]-32)|(15u<<9);hud_char_dirty[i]=0;
 }
 for(i=0;i<15;i++)if(hud_bar_dirty[i]){
  pixels[0]=pixels[7]=0x5555u;pixels[1]=pixels[6]=0xaaaau;
  for(j=2;j<6;j++)pixels[j]=hud_bar_words[i];
  tile_load((u16)(HUD_BAR_BASE+i),pixels);hud_bar_dirty[i]=0;
 }
}
void video_start_game(void){
 u16 i;
 HW_SCR_PRIO &= (u8)~0x80u; /* native_start re-enables skyline only in stages 2/4 */
 present_ready=0;
 ngpc_gfx_set_viewport(0,0,0,0);ngpc_sprite_hide_all();old_sprite_count=0;
 ngpc_gfx_clear(0);ngpc_gfx_clear(1);ngpc_gfx_scroll(0,0,0);font_load();
 if(active_stage==5){ngpc_gfx_load_tiles_at(cathedral_pixels,920,1);setpal(1,cathedral_palettes);}
 else if(active_stage==1){ngpc_gfx_load_tiles_at(axis_pixels,1272,1);setpal(1,axis_palettes);}
 setpal(2,bob_palettes);
 ngpc_gfx_set_palette(2,14,0,RGB(13,13,14),RGB(15,11,0),0);
 /* Projectile silhouettes keep their original transparent pixels. */
 ngpc_gfx_set_palette(2,15,0,RGB(15,7,0),RGB(15,15,0),RGB(15,15,15));
 hud_font_load();for(i=0;i<15;i++)hud_bar_words[i]=0;video_present_count=video_visible_tick=0;
 for(i=0;i<128;i++)sprite_cache[i]=65535u;pattern_bank=0;packed_sprite_count=64;if(active_stage==1||active_stage==5)resident_platform_reset();
 for(i=0;i<HAZARD_BANKS;i++)cache_hazard[i]=255;
 hazard_first=hazard_end=0;rope_old_count=0;
 hud_layout();
 if(active_stage>=2&&active_stage<=4){camera_x=camera_y=0;native_start();}
 else camera_update(1);
 hud_update();hud_commit();bitmap_first=(u8)(active_stage>=2&&active_stage<=4);if(!bitmap_first)ngpc_gfx_set_viewport(0,0,160,152);
}
static void rope_draw(void){
 Player *p=&game.player;s16 x,y,endx,endy,dx,dy,sx,sy,err,e2,cx,cy,lastx=-100,lasty=-100;
 u8 count=0,i,j;u16 bit;
 rope_new_count=0;
 if(p->state!=P_HOOK&&p->state!=P_HANG)return;
 x=p->x+(p->facing?-4:3)-(s16)camera_x;y=p->y-12-(s16)camera_y+PLAYFIELD_Y;
 endx=p->hook_x-(s16)camera_x;endy=p->hook_y-(s16)camera_y+PLAYFIELD_Y;
 dx=endx>x?endx-x:x-endx;dy=endy>y?y-endy:endy-y;sx=x<endx?1:-1;sy=y<endy?1:-1;err=dx+dy;
 for(;;){
  if(x>=0&&x<160&&y>=PLAYFIELD_Y&&y<PLAYFIELD_BOTTOM){
   cx=x>>3;cy=y>>3;
   if(cx!=lastx||cy!=lasty){
    if(count>=32)break;
    rope_new_x[count]=(u8)cx;rope_new_y[count]=(u8)cy;
    for(j=0;j<8;j++)rope_pixels[count][j]=0;
    count++;lastx=cx;lasty=cy;
   }
   bit=(u16)(1u<<(14-(x&7)*2));rope_pixels[count-1][y&7]|=bit;
  }
  if(x==endx&&y==endy)break;
  e2=err*2;
  if(e2>=dy){err+=dy;x+=sx;}if(e2<=dx){err+=dx;y+=sy;}
 }
 for(i=0;i<count;i++){
  tile_load((u16)((pattern_bank?192:ROPE_BASE)+i),rope_pixels[i]);
  /* SCR1 is fixed. It carries the rope and HUD, leaving all 64 sprites
     available for visible actors and projectiles. Palette 14 is white. */

 }
 rope_new_count=count;
}
u8 video_bitmap_available(void){return !present_ready;}
void video_bitmap_publish(void){hud_update();pending_game_tick=game.ticks;present_ready=1;}
void video_game(void){
 const SpriteFrame *f;const SpriteTile *t;BobDraw *b;
 u8 i,j,flip,bright;u16 tile_id,cache,at; s16 x,y;
 while(present_ready)ngpc_vsync();
 if(active_stage>=2&&active_stage<=4){if(active_stage==3)puzzle_draw();bitmap_prepare();return;}
 resident_platform_begin();
 if(active_stage==5&&cat_map_take_dirty())camera_update(1);else camera_update(0);video_sprite_count=0;
 for(i=0;i<bob_draw_count;i++){
  b=&bob_draws[i];f=&bob_frames[(b->id&0x1ffu)-1u];flip=(u8)((b->id&0x2000u)!=0);
  bright=(u8)((b->id&0x1ffu)>=59u&&(b->id&0x1ffu)<=68u);
  for(j=0;j<f->count;j++){
   tile_id=(u16)(f->first+j);t=&bob_tiles[tile_id];x=b->x+(flip?-t->x-8:t->x);y=b->y+t->y+PLAYFIELD_Y;
   if(x<=-8||x>=160||y<=PLAYFIELD_Y-8||y>=PLAYFIELD_BOTTOM)continue;
   if(video_sprite_count>=64){video_overflows++;break;}
   cache=resident_platform_slot(platform_tile_keys[tile_id],t->pixels);
   /* Descending slots preserve original overlap priority without a second
     descriptor pass or per-fragment six-argument function calls. */
  at=(u16)(63u-video_sprite_count)*2u;
  sprite_words[at]=(u16)(ACTOR_BASE+cache)|((u16)(SPR_MIDDLE|(flip?SPR_HFLIP:0))<<8);
  sprite_words[at+1u]=(u8)x|((u16)(u8)y<<8);
  ((u8 *)sprite_palette_words)[63u-video_sprite_count]=bright?15u:(u8)(t->palette&15u);
  video_sprite_count++;
  }
 }
 if(video_sprite_count>video_max_sprites)video_max_sprites=video_sprite_count;
 /* Hide only slots vacated since the last prepared frame. */
 for(i=(u8)(64u-packed_sprite_count);i<(u8)(64u-video_sprite_count);i++)sprite_words[(u16)i*2u]=0;
 packed_sprite_count=(u8)video_sprite_count;
 rope_draw();
 /* Publish a complete, immutable descriptor set. VBlank presents it while
    main is free to execute the next source update instead of busy-waiting. */
 hud_update();pending_game_tick=game.ticks;present_ready=1;
}
void video_present(void){
 u16 i;
 if(!present_ready)return;
 if(active_stage>=2&&active_stage<=4){
  native_present();
  hud_commit();if(bitmap_first){ngpc_gfx_set_viewport(0,0,160,152);bitmap_first=0;}video_visible_tick=pending_game_tick;video_present_count++;PERF_PRESENT();present_ready=0;return;
 }
 for(i=0;i<rope_old_count;i++)HW_SCR1_MAP[((u16)rope_old_y[i]<<5)+rope_old_x[i]]=0;
 for(i=0;i<rope_new_count;i++){
  HW_SCR1_MAP[((u16)rope_new_y[i]<<5)+rope_new_x[i]]=(u16)((pattern_bank?192:ROPE_BASE)+i)|(14u<<9);
  rope_old_x[i]=rope_new_x[i];rope_old_y[i]=rope_new_y[i];
 }
 rope_old_count=rope_new_count;
 graphics_diff_words(0x8800ul,(u32)sprite_words,128ul);
 graphics_diff_words(0x8c00ul,(u32)sprite_palette_words,32ul);
 resident_platform_commit();old_sprite_count=(u8)video_sprite_count;
 ngpc_gfx_scroll(1,(u8)camera_x,(u8)(camera_y-PLAYFIELD_Y));hud_commit();pattern_bank^=1;video_visible_tick=pending_game_tick;video_visible_camera_x=camera_x;video_visible_camera_y=camera_y;video_present_count++;PERF_PRESENT();present_ready=0;

}
void video_pause(u8 choice){
 u8 i;present_ready=0;
 HW_SCR_PRIO &= (u8)~0x80u; /* pause text always above skyline */
 /* Native sprites have priority 3, above both scroll planes. Preserve their
    prepared descriptors in RAM and hide hardware sprites until native_restore. */
 if(active_stage>=2u&&active_stage<=4u)ngpc_sprite_hide_all();
 for(i=0;i<rope_old_count;i++)HW_SCR1_MAP[((u16)rope_old_y[i]<<5)+rope_old_x[i]]=0;rope_old_count=0;
 font_load_opaque();ngpc_gfx_fill_rect(0,2,5,16,11,SOLID_TILE,15);
 centered(6,"PAUSED",14);video_pause_update(choice);
}
void video_pause_update(u8 choice){
 centered(8,"RESUME",choice==0?14:15);
 centered(10,"SAVE",choice==1?14:15);centered(12,"RESTART STAGE",choice==2?14:15);centered(14,"MAIN MENU",choice==3?14:15);
}
void video_pause_status(u8 ok){centered(16,ok?"GAME SAVED":"SAVE FAILED - RETRY",14);}
void video_resume(void){present_ready=0;ngpc_gfx_set_viewport(0,0,0,0);hud_font_load();hud_layout();hud_update();hud_commit();if(active_stage>=2&&active_stage<=4){native_restore();if(active_stage!=3)HW_SCR_PRIO &= (u8)~0x80u;}ngpc_gfx_set_viewport(0,0,160,152);}
static void record_time(u8 y,u32 ticks);
static void record_number(u8 y,u32 value);
void video_over(void){
 u16 i;
 HW_SCR_PRIO &= (u8)~0x80u;
 present_ready=0;
 ngpc_gfx_set_viewport(0,0,0,0);ngpc_sprite_hide_all();old_sprite_count=rope_old_count=0;
 ngpc_gfx_clear(0);ngpc_gfx_clear(1);ngpc_gfx_scroll(0,0,0);ngpc_gfx_scroll(1,0,0);font_load();
 ngpc_gfx_load_tiles_at(joker_pixels,2560,1);setpal(1,joker_palettes);
 for(i=0;i<320;i++)ngpc_gfx_put_tile(1,(u8)(i%20),(u8)(1+i/20),(u16)(i+1),joker_tile_pal[i]);
 font_load_opaque();ngpc_gfx_fill_rect(0,0,15,20,3,SOLID_TILE,15);centered(15,"POINTS EARNED",15);record_number(16,last_score);
 centered(17,save_error?"SAVE FAILED - RETRY":last_score?"RECORD SAVED":last_score_cheated||last_score_disabled?"POINTS DISABLED":"NO POINTS EARNED",14);
 centered(18,"A OR B: MAIN MENU",15);ngpc_gfx_set_viewport(0,0,160,152);
}
void video_stage_complete(u8 page){
 if(page==255)return;
 present_ready=0;
 ngpc_gfx_set_viewport(0,0,0,0);ngpc_sprite_hide_all();old_sprite_count=0;
 ngpc_gfx_scroll(0,0,0);ngpc_gfx_scroll(1,0,0);
 ngpc_gfx_clear(0);ngpc_gfx_clear(1);font_load();
 if(page==0){
  if(active_stage==1)centered(8,"JACK IS DEAD",14);
  else if(active_stage==5)centered(8,"THE END.",14);
  else if(active_stage==3){centered(4,"SMILEX SUCCESSFULLY",14);centered(6,"ANALYSED",14);centered(9,"NOW THWART THE",15);centered(11,"JOKERS CARNIVAL",15);centered(13,"PLOT.",15);}
  else if(active_stage==2){centered(5,"YOU HAVE ESCAPED",14);centered(7,"THE JOKER",14);centered(10,"BUT WHAT SECRETS",15);centered(12,"LIE AHEAD...",15);}
  else{centered(6,"THE CITY IS SAFE",14);centered(9,"BUT THE JOKER IS",15);centered(11,"STILL AT LARGE",15);}
 }else if(page==1)centered(8,active_stage==1?"THE JOKER LIVES":"FOR THE TIME BEING.",14);
 else{
  centered(4,active_stage==1?"AXIS CHEMICALS":active_stage==2?"BATMOBILE":active_stage==3?"BATCAVE":active_stage==4?"BATWING":"GOTHAM CATHEDRAL",14);
  centered(6,"COMPLETE",15);
  if(active_stage<5){centered(8,"STAGE TIME",15);record_time(9,run_stage_ticks[active_stage-1u]);centered(11,"NEXT STAGE",15);centered(12,active_stage==1?"BATMOBILE":active_stage==2?"BATCAVE":active_stage==3?"BATWING":"GOTHAM CATHEDRAL",14);if(!save_error)centered(15,"NEXT STAGE SAVED",14);centered(17,"A OR B: CONTINUE",15);}
  else{centered(8,"FINAL RUN TIME",15);record_time(9,last_run_ticks);centered(11,"FINISH POINTS",15);record_number(12,last_score);if(!last_score)centered(14,"UNRANKED RUN",14);centered(17,"A OR B: CREDITS",15);}
 }
 if(save_error)centered(18,"AUTO SAVE FAILED",14);
 ngpc_gfx_set_viewport(0,0,160,152);
}

#include "audio.h"
#include "hardware_perf_video.inc"

#include "session_video.inc"

#include "ending_video.inc"
