/* Native road-section scheduler. Route boundaries, line suppression and
 * original intersection projection are retained; no emulated instruction
 * dispatch for the row/stripe-control loop. */
#include "vehicle.h"
#ifndef VM_HOST
#include "bitmap.h"
extern void __adecl vehicle_road_rows_fast(u32 count);
#endif
#define SW(p) (*(u16 *)(vehicle_state+(u16)((p)-0x8d1eul)))
#define SB(p) (vehicle_state[((u16)((p)-0x8d1eul))^1u])
extern const u8 *vehicle_code;
#define CB(p) (vehicle_code[((u16)((p)-0x2ffcul))^1u])
#define DW(n) (*(u16 *)&d[n])
#define DB(n) (*(u8 *)&d[n])
static void stripe(void){
 SW(0x8f68ul)^=1u;if(!SW(0x8f68ul))SW(0x8f6aul)^=1u;
 if(!--SW(0x8f6cul)){SW(0x8f6cul)=3;if(DW(5)<256u)DW(5)+=64u;}
}
static void margin(u8 kind){
 u16 segment=(u16)(a[4]-0x909eul),phase=SW(0x9078ul)&224u,index,correction,n=DW(7),x,last,distance,sum,count;
 s16 change;u8 error,step,dy;u16 __near *out;
 if(segment>=21u)return;index=(u8)(phase+segment);
 out=(u16 __near *)(vehicle_projection+(u16)(a[5]-0x7bc8ul)+((kind&1u)?0u:1024u));x=out[0];last=out[n];
 if(!(kind&1u)){if(!(kind&2u))x+=CB(0x7a1fu+index);else last+=CB(0x7a20u+index);}
 else{if(!(kind&2u))x-=CB(0x7a1fu+index);else last-=CB(0x7a20u+index);}
 if(segment==1u){correction=phase>>2;correction+=correction>>2;if(((kind&1u)!=0)^((kind&2u)!=0))x+=correction;else x-=correction;}
 change=(s16)(u16)(last-x);
 if(n<2u){*out++=(u16)(x+change);}
 else{
  step=(u8)(change<0);distance=step?(u16)(0u-change):(u16)change;dy=(u8)n;count=n;error=distance>n?0:(u8)(n>>1);
  do{
   if(distance>n){do{if(step)x--;else x++;sum=(u16)error+dy;error=(u8)sum;}while(sum<256u&&error<(u8)distance);error-=(u8)distance;}
   else{sum=(u16)error+(u8)distance;error=(u8)sum;if(error>=dy){error-=dy;if(step)x--;else x++;}}
   *out++=x;
  }while(--count);
 }
 a[1]=0x7bc8ul+(u16)((u8 __near *)out-(u8 __near *)vehicle_projection);
}
void vehicle_road_native(void){u8 kind,delta,lazy_flags=0;u16 limit=0,count,rows,bytes;u32 last_before=0,last_step=0;
 a[0]=ver32(0x37c4ul)+0x2f80ul;a[4]=0x909ful;a[5]=0x7bc8ul;a[2]=0x8f74ul;
 d[5]=0;d[6]=0x130ul;d[7]=(u8)(96u-SB(a[4]));DW(4)=SW(0x9076ul);
 DW(0)=DW(4);DW(1)=DW(4);DB(4)+=128u;SW(0x8f68ul)=DW(0)&1u;SW(0x8f6aul)=(DW(1)&2u)>>1;SW(0x8f6cul)=2;
again:
 if(++limit>128u){if(lazy_flags)(void)vadd(last_step,last_before,32,0);vm_fault=0x116f1cul;return;}
 a[3]=a[0]+(SW(0x8f6aul)?0ul:0x2f80ul);
 kind=SB(0x8f74ul+(s16)DW(4))&15u;DW(0)=kind;
 if(kind&8u){d[0]=(u32)(kind&3u)<<16;d[5]|=d[0];}
 else{
  if(kind){margin(kind);a[3]=a[0];}
  d[5]&=65535ul;
 }
 DB(7)--;
#ifndef VM_HOST
 count=DW(7);
 if(count<=151u){
  if(bitmap_building)vehicle_road_rows_fast((u32)count);
  rows=(u16)(count+1u);bytes=(u16)(rows*40u);
  a[0]-=bytes;a[3]-=bytes;a[5]+=(u16)(rows*2u);vehicle_road_y-=(s16)rows;
  d[0]=d[1]=d[2]=d[3]=0;DW(7)=65535u;
  last_before=d[6];last_step=(u32)rows<<16;d[6]+=last_step;lazy_flags=1;
 }else{vehicle_road_run();lazy_flags=0;}
#else
 vehicle_road_run();
#endif
 DW(7)=(u16)~DW(7);
flat:
 stripe();DB(4)++;DB(7)=(u8)(SB(a[4])-SB(a[4]+1ul));a[4]++;
 if(!DB(7)){a[5]+=2ul;goto flat;}
 if(!(DB(7)&128u)){if(DB(7)<80u)goto again;goto end;}
hidden:
 stripe();delta=(u8)(SB(a[4])-SB(a[4]+1ul));a[4]++;DB(0)=delta;
 if(delta<224u&&delta>=80u)goto end;
 a[5]+=2ul;DB(4)++;DB(7)+=delta;if(!DB(7)||(DB(7)&128u))goto hidden;
 goto again;
end:
 /* No native scheduler operation consumes intermediate source flags. */
 if(lazy_flags)(void)vadd(last_step,last_before,32,0);
 d[6]=(d[6]<<16)|(d[6]>>16);SW(0x8d3aul)=DW(6);
}
