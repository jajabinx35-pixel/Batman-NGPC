/* BATMAN leaderboard format 2. Device-side QR only; no network on NGPC. */
#include "leaderboard.h"
#include "session.h"
#include "game.h"
#include "ngpc_hw.h"
u8 leaderboard_cursor,leaderboard_target;
#define QR_MODEL ((NgpcQr *)(render_work.reserved))
#define QR_TEXT ((char *)(render_work.reserved+384u))
static char *append_ticks(char *out,u32 value){
 static const u32 powers[7]={1000000ul,100000ul,10000ul,1000ul,100ul,10ul,1ul};
 u8 i,n;for(i=0;i<7u;i++){n=0;while(value>=powers[i]){value-=powers[i];n++;}*out++=(char)('0'+n);}return out;
}
static u16 crc_step(u16 crc,u8 v){u8 i;crc^=(u16)v<<8;for(i=0;i<8u;i++)crc=(u16)((crc&0x8000u)?(crc<<1)^0x1021u:crc<<1);return crc;}
void leaderboard_edit(u8 keys,u8 pressed,u8 refresh){u8 change=pressed;char c;
 if((keys&PAD_A)&&!(refresh&3u))change|=(u8)(keys&(PAD_UP|PAD_DOWN));
 if(pressed&PAD_LEFT)leaderboard_cursor=(u8)(leaderboard_cursor?leaderboard_cursor-1u:2u);
 if(pressed&PAD_RIGHT)leaderboard_cursor=(u8)(leaderboard_cursor==2u?0u:leaderboard_cursor+1u);
 c=record_initials[leaderboard_cursor];
 if(change&PAD_UP)c=(char)(c=='Z'?'A':c+1);
 else if(change&PAD_DOWN)c=(char)(c=='A'?'Z':c-1);
 record_initials[leaderboard_cursor]=c;
}
NgpcQr *leaderboard_matrix(void){return QR_MODEL;}
const char *leaderboard_text(void){return QR_TEXT;}
u8 leaderboard_encode(void){
 static const char prefix[]="NGPC-DEV.COM/BATMAN/";
 static const char code[]="BATMAN2";
 static const char hex[]="0123456789ABCDEF";
 static const char salt[]="BATMAN63";
 char *out=QR_TEXT,*start,*at;u8 i;u16 crc=65535u;u32 sum=0,bonus=0;
 if(leaderboard_target){
  /* Stage leaderboard: fixed-width compact format3, independent of a full
     campaign. Stage's source points and clear time must recompute its score. */
  static const char code3[]="BATMAN3",salt3[]="BATMAN65";
  u8 idx=(u8)(leaderboard_target-1u);
  u32 score,base,ticks;
  if(leaderboard_target>5u||!session_stage_upload_available(leaderboard_target))return 0;
  score=session_stage_best_score(leaderboard_target);base=session_stage_best_source(leaderboard_target);ticks=session_stage_best_ticks(leaderboard_target);
  if(!ticks||ticks>9999999ul||base>999999ul||score!=((base+session_time_bonus(leaderboard_target,ticks)>=999999ul)?999999ul:base+session_time_bonus(leaderboard_target,ticks)))return 0;
  for(i=0;prefix[i];i++)*out++=prefix[i];start=out;
  for(i=0;code3[i];i++)*out++=code3[i];
  for(i=0;i<3u;i++)*out++=record_initials[i];
  *out++=(char)('0'+leaderboard_target);
  out=append_ticks(out,score);out=append_ticks(out,base);out=append_ticks(out,ticks);
  for(at=start;at<out;at++)crc=crc_step(crc,(u8)*at);
  for(i=0;salt3[i];i++)crc=crc_step(crc,(u8)salt3[i]);
  *out++=hex[(crc>>12)&15u];*out++=hex[(crc>>8)&15u];*out++=hex[(crc>>4)&15u];*out++=hex[crc&15u];*out=0;
  return ngpc_qr_encode(QR_MODEL,QR_TEXT);
 }
 if(!session_upload_available()||!best_run_ticks||best_run_ticks>9999999ul||best_source_score>999999ul)return 0;
 for(i=0;i<5u;i++){sum+=best_stage_ticks[i];if(best_completed_mask&(1u<<i))bonus+=session_time_bonus((u8)(i+1u),best_stage_ticks[i]);}
 if(sum!=best_run_ticks||best_score!=((best_source_score+bonus>=999999ul)?999999ul:best_source_score+bonus))return 0;
 for(i=0;prefix[i];i++)*out++=prefix[i];start=out;
 for(i=0;code[i];i++)*out++=code[i];
 for(i=0;i<3u;i++)*out++=record_initials[i];
 out=append_ticks(out,best_score);out=append_ticks(out,best_source_score);out=append_ticks(out,best_run_ticks);
 *out++=(char)('0'+best_completed_mask/10u);*out++=(char)('0'+best_completed_mask%10u);
 for(i=0;i<5u;i++)out=append_ticks(out,best_stage_ticks[i]);
 for(at=start;at<out;at++)crc=crc_step(crc,(u8)*at);
 for(i=0;salt[i];i++)crc=crc_step(crc,(u8)salt[i]);
 *out++=hex[(crc>>12)&15u];*out++=hex[(crc>>8)&15u];*out++=hex[(crc>>4)&15u];*out++=hex[crc&15u];*out=0;
 return ngpc_qr_encode(QR_MODEL,QR_TEXT);
}
