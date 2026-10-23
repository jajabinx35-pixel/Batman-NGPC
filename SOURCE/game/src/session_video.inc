/* Main-context menu/ident pages: no recurring gameplay cost. */
#include "jajabinx_logo.inc"
static void session_page(void){present_ready=0;ui_window_black();ngpc_gfx_set_viewport(0,0,0,0);ngpc_sprite_hide_all();ngpc_gfx_clear(0);ngpc_gfx_clear(1);ngpc_gfx_scroll(0,0,0);ngpc_gfx_scroll(1,0,0);font_load_opaque();ngpc_gfx_fill_rect(0,0,0,20,19,SOLID_TILE,15);}
static void session_page_show(void){ngpc_gfx_set_viewport(0,0,160,152);}
static void record_number(u8 y,u32 value){char out[11];u8 i=10;out[i]=0;do{out[--i]=(char)('0'+value%10ul);value/=10ul;}while(value&&i);centered(y,out+i,14);}
void video_options(u8 choice){session_page();centered(1,"OPTIONS",14);video_options_update(choice);centered(18,"L/R CHANGE  A SELECT",15);session_page_show();}
void video_options_update(u8 choice){u8 row,i;
 for(i=0;i<7u;i++)text(0,(u8)(4u+i*2u)," ",15);
 ngpc_gfx_fill_rect(0,0,2,20,1,SOLID_TILE,15);
 text(1,4,"SOUND",15);text(16,4,audio_enabled?"ON ":"OFF",14);
 text(1,6,"START LIVES",15);{char v[2];v[0]=(char)('0'+option_lives);v[1]=0;text(17,6,v,14);}
 text(1,8,"HOW TO PLAY",15);
 if(option_lives>3u)centered(2,"POINTS DISABLED",14);
 if(cheat_unlocked){text(1,10,"INVULNERABLE",15);text(16,10,cheat_invulnerable?"ON ":"OFF",14);text(1,12,"FREEZE TIME",15);text(16,12,cheat_freeze_time?"ON ":"OFF",14);text(1,14,"LEVEL",15);{char v[2];v[0]=(char)('0'+active_stage);v[1]=0;text(17,14,v,14);}text(1,16,"BACK",15);}
 else text(1,10,"BACK",15);
 row=(u8)(4u+choice*2u);text(0,row,">",14);
}
static void record_time(u8 y,u32 ticks){
 char out[12];u32 seconds=(ticks*20ul)/1199ul;u16 minutes=(u16)((seconds/60ul)%60ul),sub=(u16)((((ticks%1199ul)*2000ul)/1199ul)%100ul);u8 hours=(u8)(seconds/3600ul);
 seconds%=60ul;
 out[0]=(char)('0'+hours/10u);out[1]=(char)('0'+hours%10u);out[2]=':';out[3]=(char)('0'+minutes/10u);out[4]=(char)('0'+minutes%10u);out[5]=':';
 out[6]=(char)('0'+seconds/10ul);out[7]=(char)('0'+seconds%10ul);out[8]='.';out[9]=(char)('0'+sub/10u);out[10]=(char)('0'+sub%10u);out[11]=0;centered(y,out,14);
}
void video_records(u8 choice){
 session_page();centered(0,"HIGH SCORE RECORDS",14);centered(2,"BEST SCORE",15);record_number(3,best_score);
 if(best_score)record_time(4,best_run_ticks);else centered(4,"NO SCORE RECORDED",15);
 centered(6,"LAST RUN POINTS",15);record_number(7,last_score);
 if(last_run_ticks)record_time(8,last_run_ticks);else centered(8,"NO RUN RECORDED",15);
 video_records_update(choice);if(save_error)centered(17,"SAVE FAILED - RETRY",14);else centered(17,cheat_unlocked?"CHEATS BLOCK UPLOAD":"STAGE CLEAR = BONUS",15);
 centered(18,"UP/DN A:OK B:BACK",15);session_page_show();
}
void video_records_update(u8 choice){u8 i,row;
 for(i=0;i<4u;i++)text(0,(u8)(10u+i*2u)," ",15);
 text(2,10,"UPLOAD BEST SCORE",session_upload_available()&&choice==0u?14:15);
 text(2,12,"STAGE HIGH SCORES",choice==1u?14:15);
 text(2,14,"RESET RECORDS",choice==2u?14:15);
 text(2,16,"BACK",choice==3u?14:15);row=(u8)(10u+choice*2u);
 text(0,row,">",14);
}
void video_stage_records(u8 choice){
 static const char *const names[5]={"AXIS","BATMOBILE","BATCAVE","BATWING","CATHEDRAL"};
 u8 i,y;char out[8];u32 value;u8 j;
 session_page();centered(0,"STAGE HIGH SCORES",14);
 for(i=0;i<5u;i++){
  y=(u8)(2u+i*3u);text(0,y,i==choice?">":" ",14);text(2,y,names[i],i==choice?14:15);
  value=session_stage_best_score((u8)(i+1u));for(j=0;j<7u;j++){out[6u-j]=(char)('0'+value%10ul);value/=10ul;}out[7]=0;
  text(12,y,out,i==choice?14:15);
  if(session_stage_best_score((u8)(i+1u)))record_time((u8)(y+1u),session_stage_best_ticks((u8)(i+1u)));
 }
 if(session_stage_upload_available((u8)(choice+1u)))centered(17,"A: UPLOAD  B: BACK",14);
 else centered(17,"NO SCORE  B: BACK",15);
 centered(18,"UP/DN: SELECT",15);session_page_show();
}
void video_records_reset(void){session_page();centered(4,"RESET ALL RECORDS?",14);centered(7,"YOUR SAVED GAME",15);centered(9,"WILL BE KEPT",15);centered(13,"A: RESET RECORDS",14);centered(16,"B: CANCEL",15);session_page_show();}
void video_qr_entry(void){session_page();centered(1,leaderboard_target?"STAGE LEADERBOARD":"LEADERBOARD ENTRY",14);text(2,3,leaderboard_target?"STAGE POINTS":"POINTS",15);record_number(4,leaderboard_target?session_stage_best_score(leaderboard_target):best_score);
 /* Opaque font: ink 1 is the letter, ink 2 the background. */
 ngpc_gfx_set_palette(0,13,0,RGB(0,0,0),RGB(15,11,2),RGB(15,15,15));
 video_qr_entry_update();record_time(9,leaderboard_target?session_stage_best_ticks(leaderboard_target):best_run_ticks);
 centered(11,"UP/DOWN: LETTER",15);centered(12,"L/R: MOVE",15);centered(13,"HOLD A: FAST SCROLL",15);
 centered(15,"OPTION: SHOW QR",14);centered(17,"B: RECORDS",15);session_page_show();
}
void video_qr_entry_update(void){u8 i,x,pal;char letter[2];letter[1]=0;
 for(i=0;i<3u;i++){x=(u8)(4u+i*4u);pal=(u8)(i==leaderboard_cursor?13u:15u);ngpc_gfx_fill_rect(0,x,5,3,3,SOLID_TILE,pal);letter[0]=record_initials[i];text((u8)(x+1u),6,letter,pal);}
 text(2,8,"EDITING INITIAL",15);letter[0]=(char)('1'+leaderboard_cursor);text(18,8,letter,14);
}
void video_qr_generating(void){session_page();centered(7,"BUILDING BATMAN QR",14);centered(10,"PLEASE WAIT...",15);session_page_show();}
void video_qr_show(u8 ok){static const u16 empty[8]={0,0,0,0,0,0,0,0};
 present_ready=0;ngpc_sprite_hide_all();ngpc_gfx_clear(0);ngpc_gfx_clear(1);ngpc_gfx_scroll(0,0,0);ngpc_gfx_scroll(1,0,0);ngpc_gfx_set_bg_color(0);
 font_load_opaque();tile_load(0,empty);
 if(ok)ok=ngpc_qr_pixel_draw(leaderboard_matrix(),1u,1u,12u,3u,12u,8u);
 if(ok){text(1,0,"NGPC-DEV.COM/BATMAN",15);text(0,18,leaderboard_target?"SCAN STAGE  B: BACK":"SCAN SCORE  B: BACK",15);}
 else{centered(7,"QR UNAVAILABLE",14);centered(10,"NO RANKED SCORE",15);centered(16,"B: BACK",15);}
 session_page_show();
}
void video_logo(void){static const u16 transparent[8]={0,0,0,0,0,0,0,0};u8 x,y;session_page();tile_load(0u,transparent);ngpc_gfx_set_palette(1,0,0,RGB(15,15,15),RGB(8,8,8),RGB(15,15,15));ngpc_gfx_load_tiles_at(jajabinx_logo,320u,1u);
 for(y=0;y<5u;y++)for(x=0;x<8u;x++)ngpc_gfx_put_tile(1,(u8)(6u+x),(u8)(5u+y),(u16)(1u+y*8u+x),0);
 /* SCR1 must be transparent over the original logo artwork. */
 ngpc_gfx_fill_rect(0,6,5,8,5,0,0);session_page_show();
}
void video_stage_intro(void){session_page();
 if(active_stage==1u)centered(8,"AXIS CHEMICALS",14);
 else if(active_stage==2u){centered(6,"THE STREETS OF",14);centered(9,"GOTHAM CITY",14);}
 else if(active_stage==3u)centered(8,"THE BATCAVE",14);
 else if(active_stage==4u){centered(6,"GOTHAM CITY",14);centered(9,"CARNIVAL",14);}
 else{centered(6,"GOTHAM CITY",14);centered(9,"CATHEDRAL",14);}
 centered(17,"A OR B: CONTINUE",15);session_page_show();
}
void video_credits_page(u8 page){session_page();
 if(!page){centered(0,"ORIGINAL CREDITS",14);centered(2,"CODING BY",15);centered(3,"MIKE LAMB",14);centered(4,"JOBBEEEE",14);centered(5,"SHORTY",14);centered(7,"GRAPHICS BY",15);centered(8,"DAWN DRAKE",14);centered(9,"BILL HARBISON",14);centered(10,"JOHN PALMER",14);centered(12,"MUSIC AND FX BY",15);centered(13,"JON DUNN",14);centered(14,"MATTHEW CANNON",14);centered(16,"PORTED BY",15);centered(17,"JAJABINX35",14);}
 else{centered(0,"BATMAN THE MOVIE",14);centered(2,"DC COMICS INC. 1989",15);centered(4,"OCEAN SOFTWARE 1989",15);centered(6,"REVERSE ENGINEERING",15);centered(7,"MARKYTURTLE",14);centered(9,"PORTED BY",15);centered(10,"JAJABINX35",14);centered(12,"NGPC HIGH SCORE",15);centered(13,"MANAGEMENT",15);centered(15,"HARDHAT WARRIOR",14);centered(16,"WWW.NGPC-DEV.COM",15);}
 centered(18,"L/R PAGE   B: BACK",15);session_page_show();
}

/* M58: 1989 gold credits and actual photograph-based Batman emblem.
   All frame time is in stock 59.95Hz display refreshes; no gameplay timings touched. */
#include "batman_intro_logo.inc"
#include "batman_gold_font.inc"
static const char *const intro_credit[5][3]={
 {"A TIM BURTON FILM","",""},
 {"MUSIC BY","DANNY ELFMAN",""},
 {"SCREENPLAY BY","SAM HAMM","AND WARREN SKAAREN"},
 {"PRODUCED BY","JON PETERS","AND PETER GUBER"},
 {"DIRECTED BY","TIM BURTON",""}
};
static const char *const intro_cast[11][3]={
 {"MICHAEL KEATON","AS","BATMAN"},
 {"JACK NICHOLSON","AS","THE JOKER"},
 {"KIM BASINGER","AS","VICKI VALE"},
 {"ROBERT WUHL","AS","ALEXANDER KNOX"},
 {"PAT HINGLE","AS","COMMISSIONER GORDON"},
 {"BILLY DEE WILLIAMS","AS","HARVEY DENT"},
 {"MICHAEL GOUGH","AS","ALFRED"},
 {"JACK PALANCE","AS","CARL GRISSOM"},
 {"JERRY HALL","AS","ALICIA HUNT"},
 {"TRACEY WALTER","AS","BOB"},
 {"WILLIAM HOOTKINS","AS","LT ECKHARDT"}
};
volatile u8 intro_card_id=255u;
static u8 intro_previous_card=255u,intro_previous_light=255u;
static void intro_black(void){
 /* Never set the viewport to 0x0 during cinematic transitions.  Doing so
    exposes the NGPC's outside-window colour (white) while the new card
    is being loaded, and causes visible full-screen white flashes.
    The preceding card fades to black so map clears are safe in place. */
 static const u16 empty[8]={0,0,0,0,0,0,0,0};
 present_ready=0;
 ngpc_sprite_hide_all();
 ngpc_gfx_set_bg_color(0);
 ngpc_gfx_set_palette(0,14,0,0,0,0);
 ngpc_gfx_set_palette(0,15,0,0,0,0);
 ngpc_gfx_set_palette(1,13,0,0,0,0);
 ngpc_gfx_scroll(0,0,0);ngpc_gfx_scroll(1,0,0);
 ngpc_gfx_clear(0);ngpc_gfx_clear(1);
 tile_load(0u,empty);
 ngpc_gfx_load_tiles_at(batman_gold_font,512u,FONT_BASE);
 ngpc_gfx_set_viewport(0,0,160,152);
}
static void intro_emblem(void){u8 x,y;
 intro_black();ngpc_gfx_load_tiles_at(batman_intro_logo,2240u,1u);
 for(y=0;y<14u;y++)for(x=0;x<20u;x++)
  ngpc_gfx_put_tile(1,x,(u8)(2u+y),(u16)(1u+(u16)y*20u+x),13u);
}
static void intro_lines(const char *a,const char *b,const char *c){
 intro_black();
 if(*a)centered(7,a,14u);
 if(*b)centered(9,b,14u);
 if(*c)centered(11,c,14u);
}
/* Adjust four palette entries only; no per-frame pattern conversions. */
static void intro_palette(u8 light,u8 logo){
 u8 a=(u8)((u16)light*5u/15u),b=(u8)((u16)light*11u/15u),c=light;
 if(logo)ngpc_gfx_set_palette(1,13,0,RGB(a,(u8)(a>>1),0),RGB(c,b,(u8)(a>>1)),RGB(c,c,b));
 else ngpc_gfx_set_palette(0,14,0,RGB(a,(u8)(a>>1),0),RGB(b,a,0),RGB(c,b,(u8)(a>>1)));
}
void video_intro_render(u16 frame){
 u8 card,light=15u,logo=0u;u16 at=0,span=0,t=0;
 if(frame<120u){card=0u;at=0;span=120;}
 else if(frame<2308u){card=(u8)(1u+(frame-120u)/438u);if(card>5u)card=5u;at=(u16)(120u+(u16)(card-1u)*438u);span=438u;}
 /* First fanfare: 38.5s appearance, full gold logo on 44.9s hit. */
 else if(frame<2860u){card=6u;at=2308u;span=552u;logo=1u;}
 /* Retime all eleven original cast cards over the shorter 82.8s MIDI. */
 else if(frame<4720u){card=(u8)(7u+(frame-2860u)/169u);if(card>17u)card=17u;at=(u16)(2860u+(u16)(card-7u)*169u);span=(card==17u?170u:169u);}
 else{card=18u;at=4720u;span=246u;logo=1u;}
 t=(u16)(frame-at);
 intro_card_id=card;
 if(card!=intro_previous_card){
  intro_previous_card=card;intro_previous_light=255u;
  if(card==0u)video_logo();
  else if(logo)intro_emblem();
  else if(card<=5u)intro_lines(intro_credit[card-1u][0],intro_credit[card-1u][1],intro_credit[card-1u][2]);
  else intro_lines(intro_cast[card-7u][0],intro_cast[card-7u][1],intro_cast[card-7u][2]);
 }
 if(!card)return;
 if(card==6u){light=(t>=384u)?15u:(u8)((u32)t*15u/384ul);}
 else if(card==18u){light=(u8)((t<45u)?(t*15u/45u):(t>201u?((span-t)*15u/45u):15u));}
 else{if(t<38u)light=(u8)((t*15u)/38u);else if(t>span-38u)light=(u8)(((span-t)*15u)/38u);}
 if(light>15u)light=15u;
 if(light!=intro_previous_light){intro_palette(light,logo);intro_previous_light=light;}
}
