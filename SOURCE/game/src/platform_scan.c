/* Exact batch forms of two original table walks. They only bypass runs of
 * rejected spawn groups or empty projectile entries. Every entry is read on
 * every update; accepted groups and active projectiles use the original code.
 * Registers and live source flags are published at the same continuation.
 * These loops run from otherwise unused platform-render RAM, copied at entry.
 */
#ifndef VM_HOST
#pragma section code platform_scan
#endif
#include "platform_scan.h"
#include "direct_memory.h"
#define LOW_WORD(x) (*(u16 *)&(x))

u8 platform_spawn_scan(u16 variables_base,u16 first,u16 end){
 const u8 DM_NEAR *q;
 u32 cursor=a[0];
 u16 x=0,y=0,dx=0,dy=0,step=0,cx=(u16)d[0],cy=(u16)d[1];
 u8 skipped=0;
 if(cursor<(u32)first||cursor>=(u32)end)return 0;
 while(cursor>=(u32)first&&cursor<(u32)end){
  q=(const u8 DM_NEAR *)(vm_vars+(u16)(cursor-variables_base));
  x=dm_be16(q);y=dm_be16(q+2);dx=(u16)(x-cx);
  dy=(u16)(y-cy);
  if(dx<152u&&dy<80u)break;
  step=(u16)(dm_be16(q+4)*6u);
  cursor+=6ul+(s32)(s16)step;
  skipped=1;
 }
 if(skipped){
  d[2]=(s32)(s16)x;LOW_WORD(d[2])=step;
  d[3]=(s32)(s16)y;if(dx<152u)LOW_WORD(d[3])=dy;
  a[0]=cursor;fc=(u8)(cursor<(u32)end);
 }
 return (u8)(skipped&&cursor>=(u32)end);
}

u8 platform_empty_shots(u16 first,u8 destination_register){
 const u8 DM_NEAR *q;
 u16 offset,remaining=(u16)d[7],skipped=0;
 /* Prove that this is the ordinary twenty-entry source walk. An unusual
  * register/stack continuation retains the complete original mapper path. */
 if(a[6]<(u32)first||a[6]>=(u32)first+160ul||remaining>=20u)return 0;
 offset=(u16)(a[6]-first);
 if((offset&7u)||offset+(remaining+1u)*8u>160u)return 0;
 q=(const u8 DM_NEAR *)(vm_shots+offset);
 while(!q[0]&&!q[1]){
  skipped++;remaining--;q+=8;
  if(remaining==65535u)break;
 }
 if(skipped){
  a[6]+=(u32)skipped*8ul;LOW_WORD(d[7])=remaining;
  LOW_WORD(d[destination_register])=0;fn=fv=fc=0;fz=1;
 }
 return (u8)(skipped&&remaining==65535u);
}

u8 platform_hazard_scan(u16 variables_base,u16 first,u16 end){
 const u8 DM_NEAR *q;
 u32 cursor=a[0],delta;
 u16 x=0,y=0,dx=0,dy=0,cx=(u16)d[0],cy=(u16)d[1];
 u8 skipped=0;
 if(cursor<(u32)first||cursor>=(u32)end)return 0;
 while(cursor<(u32)end){
  q=(const u8 DM_NEAR *)(vm_vars+(u16)(cursor-variables_base));
  x=dm_be16(q+2);y=dm_be16(q+4);
  dx=(u16)(x-cx);dy=(u16)(y-cy);
  if(dx<192u&&dy<96u)break;
  cursor+=6;skipped=1;
 }
 if(skipped){
  d[2]=(s32)(s16)x;LOW_WORD(d[2])=dx;
  d[3]=(s32)(s16)y;if(dx<192u)LOW_WORD(d[3])=dy;
  fx=(u8)(dx<192u?cy>y:cx>x);
  a[0]=cursor;delta=cursor-(u32)end;
  fc=(u8)(cursor<(u32)end);fz=(u8)(cursor==(u32)end);
  fn=(u8)((delta&0x80000000ul)!=0);
  fv=(u8)(((cursor^(u32)end)&(cursor^delta)&0x80000000ul)!=0);
 }
 return (u8)(skipped&&cursor>=(u32)end);
}

/* MOVEM.W D0-D1/A5-A6 stack frames at the two original actor draw sites.
 * Stack words remain big endian, including the sign extension on restore.
 * Unusual pointers use the existing per-word mapping unchanged. */
#ifdef VM_HOST
extern u8 stack[512];
u8 platform_draw_push(void){
 u8 DM_NEAR *q;
 if(a[7]<0x1ffe08ul||a[7]>0x200000ul)return 0;
 a[7]-=8ul;q=(u8 DM_NEAR *)(stack+(u16)(a[7]-0x1ffe00ul));
 dm_put16(q,(u16)d[0]);dm_put16(q+2,(u16)d[1]);
 dm_put16(q+4,(u16)a[5]);dm_put16(q+6,(u16)a[6]);
 return 1;
}
u8 platform_draw_pop(void){
 const u8 DM_NEAR *q;
 if(a[7]<0x1ffe00ul||a[7]>0x1ffff8ul)return 0;
 q=(const u8 DM_NEAR *)(stack+(u16)(a[7]-0x1ffe00ul));
 d[0]=(s32)(s16)dm_be16(q);d[1]=(s32)(s16)dm_be16(q+2);
 a[5]=(s32)(s16)dm_be16(q+4);a[6]=(s32)(s16)dm_be16(q+6);
 a[7]+=8ul;return 1;
}
#endif
