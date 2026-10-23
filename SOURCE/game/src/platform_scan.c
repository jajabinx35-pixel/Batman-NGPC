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

/* Complete ordinary actor-header work in native words. Active actors still
 * execute every original AI routine. Bounds/respawn exceptions use the old
 * instruction path, after any exactly equivalent empty-slot skips. */
u8 platform_actor_enter(u16 first,u16 camera_offset){
 u8 DM_NEAR *q;
 u16 remaining=(u16)d[7],offset,id,x,y,cx,cy,dx,dy;
 u32 cursor=a[6];
 if(remaining>9u||cursor!=(u32)first+(u32)(9u-remaining)*22ul)return 0;
 offset=(u16)(cursor-first);q=(u8 DM_NEAR *)(vm_actors+offset);
 for(;;){
  id=dm_be16(q);if(id)break;
  LOW_WORD(d[6])=0;fn=fv=fc=0;fz=1;
  cursor+=22ul;remaining--;a[6]=cursor;LOW_WORD(d[7])=remaining;
  if(remaining==65535u)return 2;
  q+=22;
 }
 x=dm_be16(q+2);y=dm_be16(q+4);
 cx=dm_be16((const u8 DM_NEAR *)(vm_vars+camera_offset));
 cy=dm_be16((const u8 DM_NEAR *)(vm_vars+camera_offset+2u));
 dx=(u16)(x-cx);dy=(u16)(y-cy);
 if((dx>=320u&&dx<65376u)||(dy>=160u&&dy<65456u))return 0;
 if((id&0x8000u)&&dx<160u&&dy<80u)return 0;
 LOW_WORD(d[6])=id;d[0]=(s32)(s16)x;d[1]=(s32)(s16)y;
 LOW_WORD(d[4])=x;d[2]=(s32)(s16)cx;d[3]=(s32)(s16)cy;
 LOW_WORD(d[0])=dx;LOW_WORD(d[1])=dy;
 fn=(u8)((id&0x8000u)!=0);fz=(u8)((id&0x8000u)==0);
 fv=0;fc=(u8)(!(id&0x8000u)&&dy<160u);fx=(u8)(cy>y);q[0]&=127u;
 return 1;
}

/* Same descending ten-enemy collision scan, with no repeated sparse address
 * mapping and no intermediate global condition-code stores. Publish the exact
 * source registers/flags once at the hit or exhausted continuation. */
u8 platform_projectile_actors(u16 first){
 const u8 DM_NEAR *q=(const u8 DM_NEAR *)(vm_actors+198u);
 u16 id,r=0,value=0,left=0,right=0,dx=0;
 u8 extend=0,hit=0; s16 index=9;
 for(;;){
  id=dm_be16(q);value=(u16)(id-2u);left=id;right=2u;r=value;
  extend=(u8)(id<2u);
  if(!(r&0x8000u)){
   dx=(u16)(dm_be16(q+14)-(u16)d[0]);
   value=(u16)(dx+4u);extend=(u8)(value<dx);
   left=value;right=8u;r=(u16)(left-right);
   if(value<8u){
    left=(u16)d[1];right=dm_be16(q+16);r=(u16)(left-right);
    if(r&0x8000u){
     right=dm_be16(q+18);r=(u16)(left-right);
     if(!(r&0x8000u)){hit=1;break;}
    }
   }
  }
  if(--index<0)break;q-=22;
 }
 LOW_WORD(d[2])=value;d[6]=hit?(u32)(u16)index:65535ul;
 a[4]=hit?(u32)first+(u32)(u16)index*22ul:(u32)first-22ul;
 fn=(u8)((r&0x8000u)!=0);fz=(u8)(r==0);fc=(u8)(left<right);
 fv=(u8)(((left^right)&(left^r)&0x8000u)!=0);fx=extend;
 return hit;
}

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

#ifndef VM_HOST
/* Known immutable/map ranges avoid the general 68000 sparse mapper.
   All unusual addresses retain its original fallback and 24-bit handling. */
#include "cathedral.h"
extern u8 VM_ABI vr8_slow(u32 p);
extern u8 VM_ABI cvr8_slow(u32 p);
u8 VM_ABI platform_axis_rom8(u32 p){
 if(p>=0x807cul && p<0x9f3cul)return axis_map[(u16)(p-0x807cul)];
 return vr8_slow(p);
}
u8 VM_ABI platform_cat_rom8(u32 p){
 if(p>=0x807cul && p<0xc644ul)return cat_map_read((u16)(p-0x807cul));
 return cvr8_slow(p);
}
#endif

#ifndef VM_HOST
#pragma section code f_code
/* Native word reads for immutable source tables. Boundary words, sparse
   Cathedral history, mutable actors/shots and emulated device words fall back.
   The direct path preserves source byte order even at odd addresses. */
extern u16 VM_ABI vr16_slow(u32 p);
extern u16 VM_ABI cvr16_slow(u32 p);
u16 VM_ABI platform_axis_rom16(u32 p){
 if((p>=0x5508ul&&p<0x62ddul)||
    (p>=0x4936ul&&p<0x5505ul)||
    (p>=0x3c94ul&&p<0x4893ul)||
    (p>=0x3aa4ul&&p<0x3c91ul)||
    (p>=0x67caul&&p<0x7000ul))
  return dm_be16((const u8 *)(original_code+(u16)(p-0x2ffcul)));
 if(p>=0x10000ul&&p<0x10987ul)
  return dm_be16((const u8 *)(original_bob_headers+(u16)(p-0x10000ul)));
 return vr16_slow(p);
}
u16 VM_ABI platform_cat_rom16(u32 p){
 if((p>=0x6014ul&&p<0x6325ul)||
    (p>=0x5548ul&&p<0x5fabul)||
    (p>=0x4974ul&&p<0x5545ul)||
    (p>=0x3c7eul&&p<0x48d1ul)||
    (p>=0x3a98ul&&p<0x3c7bul)||
    (p>=0x69faul&&p<0x7300ul))
  return dm_be16((const u8 *)(cat_original_code+(u16)(p-0x2ffcul)));
 if(p>=0x10000ul&&p<0x10987ul)
  return dm_be16((const u8 *)(original_bob_headers+(u16)(p-0x10000ul)));
 return cvr16_slow(p);
}
#endif

/* Fuse the ordinary actor MOVEM/BSR/draw/RTS/MOVEM boundary. Retain even
   the popped stack bytes and signed MOVEM restores for exact save/debug state.
   The draw callback's contract is to append the descriptor without changing
   source registers or flags; exceptional stack addresses use the old path. */
extern u8 stack[512];
extern int cat_external(u32 pc);
u8 platform_actor_draw(u16 continuation,u8 cathedral){
 u8 DM_NEAR *q;u32 sp=a[7];
 if(sp<0x1ffe0cul||sp>0x200000ul)return 0;
 q=(u8 DM_NEAR *)(stack+(u16)(sp-0x1ffe00ul)-12u);
 dm_put16(q+4,(u16)d[0]);dm_put16(q+6,(u16)d[1]);
 dm_put16(q+8,(u16)a[5]);dm_put16(q+10,(u16)a[6]);
 dm_put32(q,(u32)continuation);a[7]=sp-12ul;
 if(cathedral)cat_external(0x5734ul);else vm_external(0x56f4ul);
 d[0]=(s32)(s16)d[0];d[1]=(s32)(s16)d[1];
 a[5]=(s32)(s16)a[5];a[6]=(s32)(s16)a[6];a[7]=sp;
 return 1;
}
