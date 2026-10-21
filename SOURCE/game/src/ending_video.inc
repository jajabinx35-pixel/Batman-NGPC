/* Ending uses the same played-DMA-block clock and theme as the startup.
   Native screenshot tiles are installed once per card, never during gameplay. */
#include "ending_shots.h"
volatile u8 ending_card_id=255u;
static u8 ending_previous=255u;
void video_ending_start(void){u8 i;ending_previous=ending_card_id=255u;for(i=0;i<8u;i++)HW_PAL_WIN[i]=0;}
static void ending_shot(u8 index){const EndingShot *s=ending_shots+index;u8 x,y,top=(u8)(2u+(15u-s->rows)/2u);u16 i=0;static const u16 zero[8]={0,0,0,0,0,0,0,0};
 tile_load(0u,zero);ngpc_gfx_load_tiles_at(s->pixels,s->words,1u);setpal(1,s->palettes);
 ngpc_gfx_fill_rect(0,0,top,20,s->rows,0,0);
 for(y=0;y<s->rows;y++)for(x=0;x<20u;x++)HW_SCR2_MAP[((u16)(top+y)<<5)+x]=s->map[i++];
 centered(0,index==0u?"AXIS CHEMICALS":index==1u?"THE BATMOBILE":index==2u?"THE BATCAVE":index==3u?"THE BATWING":"GOTHAM CATHEDRAL",14);
}
void video_ending_render(u16 frame){static const u16 ends[15]={180u,540u,840u,1200u,1500u,1860u,2160u,2520u,2820u,3180u,3480u,3780u,4140u,4440u,4966u};u8 card=0;
 while(card<14u&&frame>=ends[card])card++;
 ending_card_id=card;if(card==ending_previous)return;ending_previous=card;
 if(card==13u||card==14u){video_credits_page((u8)(card-13u));ngpc_gfx_fill_rect(0,0,18,20,1,SOLID_TILE,15);centered(18,"A/B/OPTION: MENU",15);return;}
 session_page();
 if(card==0u){centered(5,"BATMAN THE MOVIE",14);centered(8,"THE END",15);centered(12,"THANKS FOR PLAYING",14);}
 else if(card==1u||card==3u||card==5u||card==7u||card==9u)ending_shot((u8)((card-1u)/2u));
 else if(card==2u){centered(4,"CODING BY",15);centered(7,"MIKE LAMB",14);centered(9,"JOBBEEEE",14);centered(11,"SHORTY",14);}
 else if(card==4u){centered(4,"GRAPHICS BY",15);centered(7,"DAWN DRAKE",14);centered(9,"BILL HARBISON",14);centered(11,"JOHN PALMER",14);}
 else if(card==6u){centered(5,"MUSIC AND FX BY",15);centered(8,"JON DUNN",14);centered(10,"MATTHEW CANNON",14);}
 else if(card==8u){centered(5,"BATMAN THE MOVIE",14);centered(8,"DC COMICS INC. 1989",15);centered(11,"OCEAN SOFTWARE 1989",15);}
 else if(card==10u){centered(5,"REVERSE ENGINEERING",15);centered(9,"MARKYTURTLE",14);}
 else if(card==11u){video_logo();centered(13,"PORTED BY",15);centered(15,"JAJABINX35",14);}
 else{centered(3,"LAST RUN POINTS",15);record_number(5,last_score);centered(8,"TOTAL PLAY TIME",15);record_time(10,last_run_ticks);centered(14,"THANK YOU",14);}
 centered(18,"A/B/OPTION: MENU",15);session_page_show();
}
