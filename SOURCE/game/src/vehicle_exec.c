/* Original vehicle instructions, native TLCS C, split for Toshiba optimizer. */
#include "vehicle.h"
extern u32 vehicle_div16_packed(u32,u32),vehicle_mulu16(u32,u32);
extern const u16 vehicle_smooth_lut[2048];
extern const u8 *vehicle_code;
extern s32 vehicle_mul16(u32 left,u32 right);
extern u8 stack[512];
extern void vehicle_native_boundaries(void);
#ifndef VM_HOST
#define STACK_WORD(off) (*(u16 __near *)((u16)stack+(u16)(off)))
#else
#define STACK_WORD(off) (*(u16 *)(stack+(u16)(off)))
#endif
#define STACK_READ(p) (stkp=(p),stkp-0x1ffe00ul<509ul?(((u32)STACK_WORD(stkp-0x1ffe00ul)<<16)|STACK_WORD(stkp-0x1ffe00ul+2ul)):ver32(stkp))
#define STACK_WRITE(p,val) do{stkv=(val);stkp=(p);if(stkp-0x1ffe00ul<509ul){STACK_WORD(stkp-0x1ffe00ul)=(u16)(stkv>>16);STACK_WORD(stkp-0x1ffe00ul+2ul)=(u16)stkv;}else vew32(stkp,stkv);}while(0)
#define VWORD(x) (*(u16 *)&(x))
#define VBYTE(x) (*(u8 *)&(x))
static u32 part0(u32 pc){u32 v,w,r,ea,eb,stkp,stkv; u16 tv,tw,tr;s32 signed_result;
if(pc==0x4a38ul)goto L4a38;
dispatch: if(!pc)return 0;if(pc<0x0ul||pc>=0x5000ul)return pc;
VD: if(pc<0x4314ul)goto VDL;goto VDR;
VDL: if(pc<0x3de0ul)goto VDLL;goto VDLR;
VDLL: if(pc<0x39ceul)goto VDLLL;goto VDLLR;
VDLLL: if(pc<0x3884ul)goto VDLLLL;goto VDLLLR;
VDLLLL: if(pc<0x834ul)goto VDLLLLL;goto VDLLLLR;
VDLLLLL: if(pc<0x82cul)goto VDLLLLLL;goto VDLLLLLR;
VDLLLLLL: if(pc==0x820ul)goto L820;vm_fault=pc;return 0;
VDLLLLLR: if(pc==0x82cul)goto L82c;vm_fault=pc;return 0;
VDLLLLR: if(pc<0x3728ul)goto VDLLLLRL;goto VDLLLLRR;
VDLLLLRL: if(pc==0x834ul)goto L834;vm_fault=pc;return 0;
VDLLLLRR: if(pc<0x37c8ul)goto VDLLLLRRL;goto VDLLLLRRR;
VDLLLLRRL: if(pc==0x3728ul)goto L3728;vm_fault=pc;return 0;
VDLLLLRRR: if(pc==0x37c8ul)goto L37c8;vm_fault=pc;return 0;
VDLLLR: if(pc<0x392eul)goto VDLLLRL;goto VDLLLRR;
VDLLLRL: if(pc<0x388cul)goto VDLLLRLL;goto VDLLLRLR;
VDLLLRLL: if(pc==0x3884ul)goto L3884;vm_fault=pc;return 0;
VDLLLRLR: if(pc==0x388cul)goto L388c;vm_fault=pc;return 0;
VDLLLRR: if(pc<0x3936ul)goto VDLLLRRL;goto VDLLLRRR;
VDLLLRRL: if(pc==0x392eul)goto L392e;vm_fault=pc;return 0;
VDLLLRRR: if(pc<0x39aeul)goto VDLLLRRRL;goto VDLLLRRRR;
VDLLLRRRL: if(pc==0x3936ul)goto L3936;vm_fault=pc;return 0;
VDLLLRRRR: if(pc==0x39aeul)goto L39ae;vm_fault=pc;return 0;
VDLLR: if(pc<0x3c92ul)goto VDLLRL;goto VDLLRR;
VDLLRL: if(pc<0x3b18ul)goto VDLLRLL;goto VDLLRLR;
VDLLRLL: if(pc<0x3a34ul)goto VDLLRLLL;goto VDLLRLLR;
VDLLRLLL: if(pc==0x39ceul)goto L39ce;vm_fault=pc;return 0;
VDLLRLLR: if(pc==0x3a34ul)goto L3a34;vm_fault=pc;return 0;
VDLLRLR: if(pc<0x3b6eul)goto VDLLRLRL;goto VDLLRLRR;
VDLLRLRL: if(pc==0x3b18ul)goto L3b18;vm_fault=pc;return 0;
VDLLRLRR: if(pc<0x3be0ul)goto VDLLRLRRL;goto VDLLRLRRR;
VDLLRLRRL: if(pc==0x3b6eul)goto L3b6e;vm_fault=pc;return 0;
VDLLRLRRR: if(pc==0x3be0ul)goto L3be0;vm_fault=pc;return 0;
VDLLRR: if(pc<0x3ce2ul)goto VDLLRRL;goto VDLLRRR;
VDLLRRL: if(pc<0x3cb2ul)goto VDLLRRLL;goto VDLLRRLR;
VDLLRRLL: if(pc==0x3c92ul)goto L3c92;vm_fault=pc;return 0;
VDLLRRLR: if(pc<0x3cb8ul)goto VDLLRRLRL;goto VDLLRRLRR;
VDLLRRLRL: if(pc==0x3cb2ul)goto L3cb2;vm_fault=pc;return 0;
VDLLRRLRR: if(pc==0x3cb8ul)goto L3cb8;vm_fault=pc;return 0;
VDLLRRR: if(pc<0x3d5aul)goto VDLLRRRL;goto VDLLRRRR;
VDLLRRRL: if(pc==0x3ce2ul)goto L3ce2;vm_fault=pc;return 0;
VDLLRRRR: if(pc<0x3d6cul)goto VDLLRRRRL;goto VDLLRRRRR;
VDLLRRRRL: if(pc==0x3d5aul)goto L3d5a;vm_fault=pc;return 0;
VDLLRRRRR: if(pc==0x3d6cul)goto L3d6c;vm_fault=pc;return 0;
VDLR: if(pc<0x40a8ul)goto VDLRL;goto VDLRR;
VDLRL: if(pc<0x3fbaul)goto VDLRLL;goto VDLRLR;
VDLRLL: if(pc<0x3f70ul)goto VDLRLLL;goto VDLRLLR;
VDLRLLL: if(pc<0x3e2cul)goto VDLRLLLL;goto VDLRLLLR;
VDLRLLLL: if(pc==0x3de0ul)goto L3de0;vm_fault=pc;return 0;
VDLRLLLR: if(pc==0x3e2cul)goto L3e2c;vm_fault=pc;return 0;
VDLRLLR: if(pc<0x3f9aul)goto VDLRLLRL;goto VDLRLLRR;
VDLRLLRL: if(pc==0x3f70ul)goto L3f70;vm_fault=pc;return 0;
VDLRLLRR: if(pc<0x3fa4ul)goto VDLRLLRRL;goto VDLRLLRRR;
VDLRLLRRL: if(pc==0x3f9aul)goto L3f9a;vm_fault=pc;return 0;
VDLRLLRRR: if(pc==0x3fa4ul)goto L3fa4;vm_fault=pc;return 0;
VDLRLR: if(pc<0x405aul)goto VDLRLRL;goto VDLRLRR;
VDLRLRL: if(pc<0x3fd6ul)goto VDLRLRLL;goto VDLRLRLR;
VDLRLRLL: if(pc==0x3fbaul)goto L3fba;vm_fault=pc;return 0;
VDLRLRLR: if(pc<0x3ff4ul)goto VDLRLRLRL;goto VDLRLRLRR;
VDLRLRLRL: if(pc==0x3fd6ul)goto L3fd6;vm_fault=pc;return 0;
VDLRLRLRR: if(pc==0x3ff4ul)goto L3ff4;vm_fault=pc;return 0;
VDLRLRR: if(pc<0x405eul)goto VDLRLRRL;goto VDLRLRRR;
VDLRLRRL: if(pc==0x405aul)goto L405a;vm_fault=pc;return 0;
VDLRLRRR: if(pc<0x4068ul)goto VDLRLRRRL;goto VDLRLRRRR;
VDLRLRRRL: if(pc==0x405eul)goto L405e;vm_fault=pc;return 0;
VDLRLRRRR: if(pc==0x4068ul)goto L4068;vm_fault=pc;return 0;
VDLRR: if(pc<0x421aul)goto VDLRRL;goto VDLRRR;
VDLRRL: if(pc<0x40f2ul)goto VDLRRLL;goto VDLRRLR;
VDLRRLL: if(pc<0x40baul)goto VDLRRLLL;goto VDLRRLLR;
VDLRRLLL: if(pc==0x40a8ul)goto L40a8;vm_fault=pc;return 0;
VDLRRLLR: if(pc==0x40baul)goto L40ba;vm_fault=pc;return 0;
VDLRRLR: if(pc<0x410aul)goto VDLRRLRL;goto VDLRRLRR;
VDLRRLRL: if(pc==0x40f2ul)goto L40f2;vm_fault=pc;return 0;
VDLRRLRR: if(pc<0x410eul)goto VDLRRLRRL;goto VDLRRLRRR;
VDLRRLRRL: if(pc==0x410aul)goto L410a;vm_fault=pc;return 0;
VDLRRLRRR: if(pc==0x410eul)goto L410e;vm_fault=pc;return 0;
VDLRRR: if(pc<0x42e8ul)goto VDLRRRL;goto VDLRRRR;
VDLRRRL: if(pc<0x42beul)goto VDLRRRLL;goto VDLRRRLR;
VDLRRRLL: if(pc==0x421aul)goto L421a;vm_fault=pc;return 0;
VDLRRRLR: if(pc<0x42d6ul)goto VDLRRRLRL;goto VDLRRRLRR;
VDLRRRLRL: if(pc==0x42beul)goto L42be;vm_fault=pc;return 0;
VDLRRRLRR: if(pc==0x42d6ul)goto L42d6;vm_fault=pc;return 0;
VDLRRRR: if(pc<0x42f4ul)goto VDLRRRRL;goto VDLRRRRR;
VDLRRRRL: if(pc==0x42e8ul)goto L42e8;vm_fault=pc;return 0;
VDLRRRRR: if(pc<0x42faul)goto VDLRRRRRL;goto VDLRRRRRR;
VDLRRRRRL: if(pc==0x42f4ul)goto L42f4;vm_fault=pc;return 0;
VDLRRRRRR: if(pc==0x42faul)goto L42fa;vm_fault=pc;return 0;
VDR: if(pc<0x46b8ul)goto VDRL;goto VDRR;
VDRL: if(pc<0x451eul)goto VDRLL;goto VDRLR;
VDRLL: if(pc<0x442cul)goto VDRLLL;goto VDRLLR;
VDRLLL: if(pc<0x4362ul)goto VDRLLLL;goto VDRLLLR;
VDRLLLL: if(pc<0x435aul)goto VDRLLLLL;goto VDRLLLLR;
VDRLLLLL: if(pc==0x4314ul)goto L4314;vm_fault=pc;return 0;
VDRLLLLR: if(pc==0x435aul)goto L435a;vm_fault=pc;return 0;
VDRLLLR: if(pc<0x4414ul)goto VDRLLLRL;goto VDRLLLRR;
VDRLLLRL: if(pc==0x4362ul)goto L4362;vm_fault=pc;return 0;
VDRLLLRR: if(pc<0x4422ul)goto VDRLLLRRL;goto VDRLLLRRR;
VDRLLLRRL: if(pc==0x4414ul)goto L4414;vm_fault=pc;return 0;
VDRLLLRRR: if(pc==0x4422ul)goto L4422;vm_fault=pc;return 0;
VDRLLR: if(pc<0x44a8ul)goto VDRLLRL;goto VDRLLRR;
VDRLLRL: if(pc<0x4436ul)goto VDRLLRLL;goto VDRLLRLR;
VDRLLRLL: if(pc==0x442cul)goto L442c;vm_fault=pc;return 0;
VDRLLRLR: if(pc<0x44a0ul)goto VDRLLRLRL;goto VDRLLRLRR;
VDRLLRLRL: if(pc==0x4436ul)goto L4436;vm_fault=pc;return 0;
VDRLLRLRR: if(pc==0x44a0ul)goto L44a0;vm_fault=pc;return 0;
VDRLLRR: if(pc<0x44c8ul)goto VDRLLRRL;goto VDRLLRRR;
VDRLLRRL: if(pc==0x44a8ul)goto L44a8;vm_fault=pc;return 0;
VDRLLRRR: if(pc<0x44f0ul)goto VDRLLRRRL;goto VDRLLRRRR;
VDRLLRRRL: if(pc==0x44c8ul)goto L44c8;vm_fault=pc;return 0;
VDRLLRRRR: if(pc==0x44f0ul)goto L44f0;vm_fault=pc;return 0;
VDRLR: if(pc<0x45caul)goto VDRLRL;goto VDRLRR;
VDRLRL: if(pc<0x4572ul)goto VDRLRLL;goto VDRLRLR;
VDRLRLL: if(pc<0x4546ul)goto VDRLRLLL;goto VDRLRLLR;
VDRLRLLL: if(pc==0x451eul)goto L451e;vm_fault=pc;return 0;
VDRLRLLR: if(pc==0x4546ul)goto L4546;vm_fault=pc;return 0;
VDRLRLR: if(pc<0x459cul)goto VDRLRLRL;goto VDRLRLRR;
VDRLRLRL: if(pc==0x4572ul)goto L4572;vm_fault=pc;return 0;
VDRLRLRR: if(pc<0x45b4ul)goto VDRLRLRRL;goto VDRLRLRRR;
VDRLRLRRL: if(pc==0x459cul)goto L459c;vm_fault=pc;return 0;
VDRLRLRRR: if(pc==0x45b4ul)goto L45b4;vm_fault=pc;return 0;
VDRLRR: if(pc<0x4602ul)goto VDRLRRL;goto VDRLRRR;
VDRLRRL: if(pc<0x45ceul)goto VDRLRRLL;goto VDRLRRLR;
VDRLRRLL: if(pc==0x45caul)goto L45ca;vm_fault=pc;return 0;
VDRLRRLR: if(pc<0x45e6ul)goto VDRLRRLRL;goto VDRLRRLRR;
VDRLRRLRL: if(pc==0x45ceul)goto L45ce;vm_fault=pc;return 0;
VDRLRRLRR: if(pc==0x45e6ul)goto L45e6;vm_fault=pc;return 0;
VDRLRRR: if(pc<0x463eul)goto VDRLRRRL;goto VDRLRRRR;
VDRLRRRL: if(pc==0x4602ul)goto L4602;vm_fault=pc;return 0;
VDRLRRRR: if(pc<0x4642ul)goto VDRLRRRRL;goto VDRLRRRRR;
VDRLRRRRL: if(pc==0x463eul)goto L463e;vm_fault=pc;return 0;
VDRLRRRRR: if(pc==0x4642ul)goto L4642;vm_fault=pc;return 0;
VDRR: if(pc<0x4cb2ul)goto VDRRL;goto VDRRR;
VDRRL: if(pc<0x47d6ul)goto VDRRLL;goto VDRRLR;
VDRRLL: if(pc<0x471eul)goto VDRRLLL;goto VDRRLLR;
VDRRLLL: if(pc<0x46f2ul)goto VDRRLLLL;goto VDRRLLLR;
VDRRLLLL: if(pc==0x46b8ul)goto L46b8;vm_fault=pc;return 0;
VDRRLLLR: if(pc==0x46f2ul)goto L46f2;vm_fault=pc;return 0;
VDRRLLR: if(pc<0x478cul)goto VDRRLLRL;goto VDRRLLRR;
VDRRLLRL: if(pc==0x471eul)goto L471e;vm_fault=pc;return 0;
VDRRLLRR: if(pc<0x4792ul)goto VDRRLLRRL;goto VDRRLLRRR;
VDRRLLRRL: if(pc==0x478cul)goto L478c;vm_fault=pc;return 0;
VDRRLLRRR: if(pc==0x4792ul)goto L4792;vm_fault=pc;return 0;
VDRRLR: if(pc<0x4a88ul)goto VDRRLRL;goto VDRRLRR;
VDRRLRL: if(pc<0x4998ul)goto VDRRLRLL;goto VDRRLRLR;
VDRRLRLL: if(pc==0x47d6ul)goto L47d6;vm_fault=pc;return 0;
VDRRLRLR: if(pc<0x49aaul)goto VDRRLRLRL;goto VDRRLRLRR;
VDRRLRLRL: if(pc==0x4998ul)goto L4998;vm_fault=pc;return 0;
VDRRLRLRR: if(pc==0x49aaul)goto L49aa;vm_fault=pc;return 0;
VDRRLRR: if(pc<0x4b06ul)goto VDRRLRRL;goto VDRRLRRR;
VDRRLRRL: if(pc==0x4a88ul)goto L4a88;vm_fault=pc;return 0;
VDRRLRRR: if(pc<0x4b90ul)goto VDRRLRRRL;goto VDRRLRRRR;
VDRRLRRRL: if(pc==0x4b06ul)goto L4b06;vm_fault=pc;return 0;
VDRRLRRRR: if(pc==0x4b90ul)goto L4b90;vm_fault=pc;return 0;
VDRRR: if(pc<0x4e00ul)goto VDRRRL;goto VDRRRR;
VDRRRL: if(pc<0x4d18ul)goto VDRRRLL;goto VDRRRLR;
VDRRRLL: if(pc<0x4cbeul)goto VDRRRLLL;goto VDRRRLLR;
VDRRRLLL: if(pc==0x4cb2ul)goto L4cb2;vm_fault=pc;return 0;
VDRRRLLR: if(pc==0x4cbeul)goto L4cbe;vm_fault=pc;return 0;
VDRRRLR: if(pc<0x4d2aul)goto VDRRRLRL;goto VDRRRLRR;
VDRRRLRL: if(pc==0x4d18ul)goto L4d18;vm_fault=pc;return 0;
VDRRRLRR: if(pc<0x4da2ul)goto VDRRRLRRL;goto VDRRRLRRR;
VDRRRLRRL: if(pc==0x4d2aul)goto L4d2a;vm_fault=pc;return 0;
VDRRRLRRR: if(pc==0x4da2ul)goto L4da2;vm_fault=pc;return 0;
VDRRRR: if(pc<0x4e5eul)goto VDRRRRL;goto VDRRRRR;
VDRRRRL: if(pc<0x4e20ul)goto VDRRRRLL;goto VDRRRRLR;
VDRRRRLL: if(pc==0x4e00ul)goto L4e00;vm_fault=pc;return 0;
VDRRRRLR: if(pc<0x4e56ul)goto VDRRRRLRL;goto VDRRRRLRR;
VDRRRRLRL: if(pc==0x4e20ul)goto L4e20;vm_fault=pc;return 0;
VDRRRRLRR: if(pc==0x4e56ul)goto L4e56;vm_fault=pc;return 0;
VDRRRRR: if(pc<0x4ec0ul)goto VDRRRRRL;goto VDRRRRRR;
VDRRRRRL: if(pc==0x4e5eul)goto L4e5e;vm_fault=pc;return 0;
VDRRRRRR: if(pc<0x4fccul)goto VDRRRRRRL;goto VDRRRRRRR;
VDRRRRRRL: if(pc==0x4ec0ul)goto L4ec0;vm_fault=pc;return 0;
VDRRRRRRR: if(pc==0x4fccul)goto L4fcc;vm_fault=pc;return 0;
L820: if(vehicle_external(0x820ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L82c: if(vehicle_external(0x82cul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L834: if(vehicle_external(0x834ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3728: if(vehicle_external(0x3728ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L37c8: if(vehicle_external(0x37c8ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3884: /* move.w #$500, D0 */

tv=((u16)(1280L));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3888;
L3888: /* bsr $3986 */

a[7]-=4;STACK_WRITE(a[7],0x388cul);
goto L3986;
L388c: /* lea $8d5c.l, A0 */

a[0]=0x8d5cul;
goto L3892;
L3892: /* move.w #$91, ($10,A0) */

tv=((u16)(145L));
ea=(16+a[0]);
vew16(ea,tv);

goto L3898;
L3898: /* move.w #$bc, ($30,A0) */

tv=((u16)(188L));
ea=(48+a[0]);
vew16(ea,tv);

goto L389e;
L389e: /* move.w #$84, ($2e,A0) */

tv=((u16)(132L));
ea=(46+a[0]);
vew16(ea,tv);

goto L38a4;
L38a4: /* move.w #$14, ($2a,A0) */

tv=((u16)(20L));
ea=(42+a[0]);
vew16(ea,tv);

goto L38aa;
L38aa: /* move.w #$fffc, ($2c,A0) */

tv=((u16)(65532L));
ea=(44+a[0]);
vew16(ea,tv);

goto L38b0;
L38b0: /* move.w #$4, $8d2c.l */

tv=((u16)(4L));
*(u16 *)(vehicle_state+14)=(u16)(tv);

goto L38b8;
L38b8: /* move.w #$8, $8d2e.l */

tv=((u16)(8L));
*(u16 *)(vehicle_state+16)=(u16)(tv);

goto L38c0;
L38c0: /* move.w #$2, $8d30.l */

tv=((u16)(2L));
*(u16 *)(vehicle_state+18)=(u16)(tv);

goto L38c8;
L38c8: /* move.w #$1f4, D0 */

tv=((u16)(500L));
VWORD(d[0])=(u16)(tv);

goto L38cc;
L38cc: /* cmp.w $8d22.l, D0 */

tv=(*(u16 *)(vehicle_state+4));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L38d2;
L38d2: /* bcc $38d8 */

if(!fc)goto L38d8;
goto L38d4;
L38d4: /* move.w #$3e7, D0 */

tv=((u16)(999L));
VWORD(d[0])=(u16)(tv);

goto L38d8;
L38d8: /* move.w D0, $8d22.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+4)=(u16)(tv);

goto L38de;
L38de: /* move.l #$8236, $907c.l */

v=((u32)(33334L));
*(u16 *)(vehicle_state+862)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+864)=(u16)(v);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L38e8;
L38e8: /* bra $39aa */

goto L39aa;
L392e: /* move.w #$300, D0 */

tv=((u16)(768L));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3932;
L3932: /* bsr $3986 */

a[7]-=4;STACK_WRITE(a[7],0x3936ul);
goto L3986;
L3936: /* lea $8d5c.l, A0 */

a[0]=0x8d5cul;
goto L393c;
L393c: /* move.w #$64, ($10,A0) */

tv=((u16)(100L));
ea=(16+a[0]);
vew16(ea,tv);

goto L3942;
L3942: /* move.w #$78, $8f6e.l */

tv=((u16)(120L));
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L394a;
L394a: /* move.w #$c6, ($30,A0) */

tv=((u16)(198L));
ea=(48+a[0]);
vew16(ea,tv);

goto L3950;
L3950: /* move.w #$70, ($2e,A0) */

tv=((u16)(112L));
ea=(46+a[0]);
vew16(ea,tv);

goto L3956;
L3956: /* move.w #$1, ($2a,A0) */

tv=((u16)(1L));
ea=(42+a[0]);
vew16(ea,tv);

goto L395c;
L395c: /* move.w #$ffec, ($2c,A0) */

tv=((u16)(65516L));
ea=(44+a[0]);
vew16(ea,tv);

goto L3962;
L3962: /* move.w #$32, D0 */

tv=((u16)(50L));
VWORD(d[0])=(u16)(tv);

goto L3966;
L3966: /* cmp.w $8d24.l, D0 */

tv=(*(u16 *)(vehicle_state+6));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L396c;
L396c: /* bcc $3972 */

if(!fc)goto L3972;
goto L396e;
L396e: /* move.w #$64, D0 */

tv=((u16)(100L));
VWORD(d[0])=(u16)(tv);

goto L3972;
L3972: /* move.w D0, $8d24.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+6)=(u16)(tv);

goto L3978;
L3978: /* move.l #$8266, $907c.l */

v=((u32)(33382L));
*(u16 *)(vehicle_state+862)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+864)=(u16)(v);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3982;
L3982: /* bra $39aa */

goto L39aa;
L3986: /* lea $8d26.l, A0 */

a[0]=0x8d26ul;
goto L398c;
L398c: /* move.w #$1bb, D7 */

tv=((u16)(443L));
VWORD(d[7])=(u16)(tv);

goto L3990;
L3990: /* clr.w (A0)+ */

ea=a[0];
vew16(ea,0);
a[0]+=2;

goto L3992;
L3992: /* dbra D7, $3990 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L3990;
goto L3996;
L3996: /* move.w #$2, $8d2a.l */

tv=((u16)(2L));
*(u16 *)(vehicle_state+12)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L399e;
L399e: /* pea $7c854.l */

a[7]-=4;
STACK_WRITE(a[7],0x7c854ul);
goto L39a4;
L39a4: /* jmp $7c80e.l */

return 0x7c80eul;
L39aa: /* bsr $6a2c */

a[7]-=4;STACK_WRITE(a[7],0x39aeul);
return 0x6a2cul;
L39ae: /* move.w #$0, $8d26.l */

tv=((u16)(0L));
*(u16 *)(vehicle_state+8)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fv=0;fc=0;
goto L39b6;
L39b6: /* btst #$0, $7c875.l */

v=((u16)(0L));
eb=0x7c875ul;
w=ver8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L39be;
L39be: /* bne $39ce */

if(!fz)goto L39ce;
goto L39c0;
L39c0: /* moveq #$1, D0 */

v=((u32)(1L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L39c2;
L39c2: /* pea $39ce.l */

a[7]-=4;
STACK_WRITE(a[7],0x39ceul);
goto L39c8;
L39c8: /* jmp $68f90.l */

return 0x68f90ul;
L39ce: if(vehicle_external(0x39ceul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3a34: if(vehicle_external(0x3a34ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3b18: if(vehicle_external(0x3b18ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3b6e: if(vehicle_external(0x3b6eul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3be0: if(vehicle_external(0x3be0ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3c92: /* movem.l D1-D7/A0-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],a[4]);
a[7]-=4;
STACK_WRITE(a[7],a[3]);
a[7]-=4;
STACK_WRITE(a[7],a[2]);
a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],a[0]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
a[7]-=4;
STACK_WRITE(a[7],d[6]);
a[7]-=4;
STACK_WRITE(a[7],d[5]);
a[7]-=4;
STACK_WRITE(a[7],d[4]);
a[7]-=4;
STACK_WRITE(a[7],d[3]);
a[7]-=4;
STACK_WRITE(a[7],d[2]);
a[7]-=4;
STACK_WRITE(a[7],d[1]);
goto L3c96;
L3c96: /* move.w #$1, $8d32.l */

tv=((u16)(1L));
*(u16 *)(vehicle_state+20)=(u16)(tv);

goto L3c9e;
L3c9e: /* move.w #$0, $8d34.l */

tv=((u16)(0L));
*(u16 *)(vehicle_state+22)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3ca6;
L3ca6: /* pea $3cb2.l */

a[7]-=4;
STACK_WRITE(a[7],0x3cb2ul);
goto L3cac;
L3cac: /* jmp $68f94.l */

return 0x68f94ul;
L3cb2: /* movem.l (A7)+, D1-D7/A0-A6 */

ea=a[7];
d[1]=STACK_READ(ea+0);
d[2]=STACK_READ(ea+4);
d[3]=STACK_READ(ea+8);
d[4]=STACK_READ(ea+12);
d[5]=STACK_READ(ea+16);
d[6]=STACK_READ(ea+20);
d[7]=STACK_READ(ea+24);
a[0]=STACK_READ(ea+28);
a[1]=STACK_READ(ea+32);
a[2]=STACK_READ(ea+36);
a[3]=STACK_READ(ea+40);
a[4]=STACK_READ(ea+44);
a[5]=STACK_READ(ea+48);
a[6]=STACK_READ(ea+52);
a[7]+=56;
goto L3cb6;
L3cb6: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3cb8: if(vehicle_external(0x3cb8ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3ce2:
#ifndef VM_HOST
 /* The Amiga corner-exit wipe copies between two virtual bitplanes and
    polls an Amiga frame counter inside the game update. Neither buffer
    exists on NGPC. The next complete native frame replaces it atomically
    through the existing VBlank presentation fence. */
 d[0]=40ul;d[1]=0xfffeul;VWORD(d[7])=65535u;
 a[0]=ver32(0x37c0ul)+6118ul;a[1]=ver32(0x37c4ul)+6118ul;
 a[2]=ver32(0x37c0ul)+6120ul;a[3]=ver32(0x37c4ul)+6120ul;
 vew16(0x37bcul,0);fn=1;fz=fv=0;fc=fx=1;
 pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
#endif
L3ce2_original: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L3ce4;
L3ce4: /* moveq #$26, D1 */

v=((u32)(38L));
d[1]=v;

goto L3ce6;
L3ce6: /* movea.l $37c0.l, A0 */

v=(((u32)*(u16 *)(vehicle_io+192)<<16)|*(u16 *)(vehicle_io+194));
a[0]=v;
goto L3cec;
L3cec: /* movea.l $37c4.l, A1 */

v=(((u32)*(u16 *)(vehicle_io+196)<<16)|*(u16 *)(vehicle_io+198));
a[1]=v;
goto L3cf2;
L3cf2: /* lea ($28,A0,D1.w), A2 */

a[2]=(40+a[0]+((s16)(d[1])));
goto L3cf6;
L3cf6: /* lea ($28,A1,D1.w), A3 */

a[3]=(40+a[1]+((s16)(d[1])));
goto L3cfa;
L3cfa: /* lea (A0,D0.w), A0 */

a[0]=(a[0]+((s16)(d[0])));
goto L3cfe;
L3cfe: /* lea (A1,D0.w), A1 */

a[1]=(a[1]+((s16)(d[0])));
goto L3d02;
L3d02: /* moveq #$4b, D7 */

v=((u32)(75L));
d[7]=v;

goto L3d04;
L3d04: /* move.w (A1), (A0) */

ea=a[1];
tv=ver16(ea);
ea=a[0];
vew16(ea,tv);

goto L3d06;
L3d06: /* move.w ($17c0,A1), ($17c0,A0) */

ea=(6080+a[1]);
tv=ver16(ea);
ea=(6080+a[0]);
vew16(ea,tv);

goto L3d0c;
L3d0c: /* move.w ($2f80,A1), ($2f80,A0) */

ea=(12160+a[1]);
tv=ver16(ea);
ea=(12160+a[0]);
vew16(ea,tv);

goto L3d12;
L3d12: /* move.w ($4740,A1), ($4740,A0) */

ea=(18240+a[1]);
tv=ver16(ea);
ea=(18240+a[0]);
vew16(ea,tv);

goto L3d18;
L3d18: /* move.w (A3), (A2) */

ea=a[3];
tv=ver16(ea);
ea=a[2];
vew16(ea,tv);

goto L3d1a;
L3d1a: /* move.w ($17c0,A3), ($17c0,A2) */

ea=(6080+a[3]);
tv=ver16(ea);
ea=(6080+a[2]);
vew16(ea,tv);

goto L3d20;
L3d20: /* move.w ($2f80,A3), ($2f80,A2) */

ea=(12160+a[3]);
tv=ver16(ea);
ea=(12160+a[2]);
vew16(ea,tv);

goto L3d26;
L3d26: /* move.w ($4740,A3), ($4740,A2) */

ea=(18240+a[3]);
tv=ver16(ea);
ea=(18240+a[2]);
vew16(ea,tv);

goto L3d2c;
L3d2c: /* lea ($50,A0), A0 */

a[0]=(80+a[0]);
goto L3d30;
L3d30: /* lea ($50,A1), A1 */

a[1]=(80+a[1]);
goto L3d34;
L3d34: /* lea ($50,A2), A2 */

a[2]=(80+a[2]);
goto L3d38;
L3d38: /* lea ($50,A3), A3 */

a[3]=(80+a[3]);
goto L3d3c;
L3d3c: /* dbra D7, $3d04 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L3d04;
goto L3d40;
L3d40: /* addq.w #2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L3d42;
L3d42: /* subq.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L3d44;
L3d44: /* bmi $3d58 */

if(fn)goto L3d58;
goto L3d46;
L3d46: /* tst.w $37bc.l */

tv=(*(u16 *)(vehicle_io+188));
fz=(u8)((tv&0xfffful)==0);
goto L3d4c;
L3d4c: /* beq $3d46 */

if(fz)goto L3d46;
goto L3d4e;
L3d4e: /* move.w #$0, $37bc.l */

tv=((u16)(0L));
*(u16 *)(vehicle_io+188)=(u16)(tv);

goto L3d56;
L3d56: /* bra $3ce6 */

goto L3ce6;
L3d58: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3d5a: if(vehicle_external(0x3d5aul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3d6c: if(vehicle_external(0x3d6cul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3de0: if(vehicle_external(0x3de0ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3e2c: if(vehicle_external(0x3e2cul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L3f70: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L3f76;
L3f76: /* tst.w $8d98.l */

tv=(*(u16 *)(vehicle_state+122));
fz=(u8)((tv&0xfffful)==0);
goto L3f7c;
L3f7c: /* beq $3f8e */

if(fz)goto L3f8e;
goto L3f7e;
L3f7e: /* cmpi.w #$2, $8d98.l */

tv=((u16)(2L));
tw=(*(u16 *)(vehicle_state+122));
fc=(u8)((u16)tw<(u16)tv);
goto L3f86;
L3f86: /* bcs $3f8e */

if(fc)goto L3f8e;
goto L3f88;
L3f88: /* move.w $8f70.l, D0 */

tv=(*(u16 *)(vehicle_state+594));
VWORD(d[0])=(u16)(tv);

goto L3f8e;
L3f8e: /* lsr.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;
VWORD(d[0])=(u16)(tr);
goto L3f90;
L3f90: /* lea $3f44.l, A0 */

a[0]=0x3f44ul;
goto L3f96;
L3f96: /* bsr $6780 */

a[7]-=4;STACK_WRITE(a[7],0x3f9aul);
return 0x6780ul;
L3f9a: /* lea $3f3a.l, A0 */

a[0]=0x3f3aul;
goto L3fa0;
L3fa0: /* bsr $410e */

a[7]-=4;STACK_WRITE(a[7],0x3fa4ul);
goto L410e;
L3fa4: /* move.w $7c88e.l, D0 */

ea=0x7c88eul;
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L3faa;
L3faa: /* cmpi.w #$12, D0 */

tv=((u16)(18L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3fae;
L3fae: /* bcc $3fb6 */

if(!fc)goto L3fb6;
goto L3fb0;
L3fb0: /* move.w D0, $8d28.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+10)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3fb6;
L3fb6: /* bsr $3728 */

a[7]-=4;STACK_WRITE(a[7],0x3fbaul);
goto L3728;
L3fba: /* beq $3fd6 */

if(fz)goto L3fd6;
goto L3fbc;
L3fbc: /* cmpi.w #$81, D0 */

tv=((u16)(129L));
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto L3fc0;
L3fc0: /* beq $403e */

if(fz)goto L403e;
goto L3fc4;
L3fc4: /* cmpi.w #$82, D0 */

tv=((u16)(130L));
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto L3fc8;
L3fc8: /* beq $400c */

if(fz)goto L400c;
goto L3fca;
L3fca: /* cmpi.w #$1b, D0 */

tv=((u16)(27L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3fce;
L3fce: /* beq $4032 */

if(fz)goto L4032;
goto L3fd0;
L3fd0: /* cmpi.w #$8a, D0 */

tv=((u16)(138L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3fd4;
L3fd4: /* beq $3ffe */

if(fz)goto L3ffe;
goto L3fd6;
L3fd6: /* tst.w $8d1e.l */

tv=(*(u16 *)(vehicle_state+0));
fz=(u8)((tv&0xfffful)==0);
goto L3fdc;
L3fdc: /* beq $407a */

if(fz)goto L407a;
goto L3fe0;
L3fe0: /* move.w $8d24.l, D0 */

tv=(*(u16 *)(vehicle_state+6));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3fe6;
L3fe6: /* beq $3b6e */

if(fz)goto L3b6e;
goto L3fea;
L3fea: /* lea $3f6b.l, A0 */

a[0]=0x3f6bul;
goto L3ff0;
L3ff0: /* bsr $6780 */

a[7]-=4;STACK_WRITE(a[7],0x3ff4ul);
return 0x6780ul;
L3ff4: /* lea $3f5e.l, A0 */

a[0]=0x3f5eul;
goto L3ffa;
L3ffa: /* bra $410e */

goto L410e;
L3ffe: /* btst #$7, $7c875.l */

v=((u16)(7L));
eb=0x7c875ul;
w=ver8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L4006;
L4006: /* beq $3fd6 */

if(fz)goto L3fd6;
goto L4008;
L4008: /* bra $3b6e */

goto L3b6e;
L400c: /* bchg #$0, $7c875.l */

v=((u16)(0L));
eb=0x7c875ul;
w=ver8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w^r;
vew8(eb,r);
goto L4014;
L4014: /* bne $4024 */

if(!fz)goto L4024;
goto L4016;
L4016: /* moveq #$1, D0 */

v=((u32)(1L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4018;
L4018: /* pea $3fd6.l */

a[7]-=4;
STACK_WRITE(a[7],0x3fd6ul);
goto L401e;
L401e: /* jmp $68f88.l */

return 0x68f88ul;
L4024: /* moveq #$1, D0 */

v=((u32)(1L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4026;
L4026: /* pea $3fd6.l */

a[7]-=4;
STACK_WRITE(a[7],0x3fd6ul);
goto L402c;
L402c: /* jmp $68f90.l */

return 0x68f90ul;
L4032: /* bset #$5, $7c875.l */

v=((u16)(5L));
eb=0x7c875ul;
w=ver8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
vew8(eb,r);
goto L403a;
L403a: /* bra $3b18 */

goto L3b18;
L403e: /* move.w #$1, $8d20.l */

tv=((u16)(1L));
*(u16 *)(vehicle_state+2)=(u16)(tv);

goto L4046;
L4046: /* pea $405a.l */

a[7]-=4;
STACK_WRITE(a[7],0x405aul);
goto L404c;
L404c: /* move.w $8d1e.l, D0 */

tv=(*(u16 *)(vehicle_state+0));
VWORD(d[0])=(u16)(tv);

goto L4052;
L4052: /* addq.w #5, D0 */

tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4054;
L4054: /* jmp $68f8c.l */

return 0x68f8cul;
L405a: /* bsr $3728 */

a[7]-=4;STACK_WRITE(a[7],0x405eul);
goto L3728;
L405e: /* cmpi.w #$81, D0 */

tv=((u16)(129L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4062;
L4062: /* beq $405a */

if(fz)goto L405a;
goto L4064;
L4064: /* bsr $3728 */

a[7]-=4;STACK_WRITE(a[7],0x4068ul);
goto L3728;
L4068: /* cmpi.w #$81, D0 */

tv=((u16)(129L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L406c;
L406c: /* bne $4064 */

if(!fz)goto L4064;
goto L406e;
L406e: /* move.w #$0, $8d20.l */

tv=((u16)(0L));
*(u16 *)(vehicle_state+2)=(u16)(tv);

goto L4076;
L4076: /* bra $3fd6 */

goto L3fd6;
L407a: /* lea $3f57.l, A0 */

a[0]=0x3f57ul;
goto L4080;
L4080: /* move.w $8d26.l, D1 */

tv=(*(u16 *)(vehicle_state+8));
VWORD(d[1])=(u16)(tv);

goto L4086;
L4086: /* move.w $8d22.l, D0 */

tv=(*(u16 *)(vehicle_state+4));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L408c;
L408c: /* beq $3b6e */

if(fz)goto L3b6e;
goto L4090;
L4090: /* subi.w #$6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4094;
L4094: /* bmi $40a4 */

if(fn)goto L40a4;
goto L4096;
L4096: /* move.w D1, $8d26.l */

tv=((u16)d[1]);
*(u16 *)(vehicle_state+8)=(u16)(tv);

goto L409c;
L409c: /* subq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L409e;
L409e: /* move.w D0, $8d22.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+4)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L40a4;
L40a4: /* bsr $6780 */

a[7]-=4;STACK_WRITE(a[7],0x40a8ul);
return 0x6780ul;
L40a8: /* move.b $2e.l, (A0)+ */

ea=0x2eul;
tv=ver8(ea);
ea=a[0];
vew8(ea,tv);
a[0]+=1;

goto L40ae;
L40ae: /* move.b D0, (A0) */

tv=((u8)d[0]);
ea=a[0];
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L40b0;
L40b0: /* lea $3f4a.l, A0 */

a[0]=0x3f4aul;
goto L40b6;
L40b6: /* bsr $410e */

a[7]-=4;STACK_WRITE(a[7],0x40baul);
goto L410e;
L40ba: /* move.w $8d30.l, D0 */

tv=(*(u16 *)(vehicle_state+18));
VWORD(d[0])=(u16)(tv);

goto L40c0;
L40c0: /* mulu.w #$5, D0 */

v=((u16)(5L));
w=((u32)d[0]);
r=vehicle_mulu16(v,w);

d[0]=r;
goto L40c4;
L40c4: /* move.w $8d36.l, D1 */

tv=(*(u16 *)(vehicle_state+24));
VWORD(d[1])=(u16)(tv);

goto L40ca;
L40ca: /* cmpi.w #$5, D1 */

tv=((u16)(5L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L40ce;
L40ce: /* bcc $40d2 */

if(!fc)goto L40d2;
goto L40d0;
L40d0: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L40d2;
L40d2: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;
VWORD(d[0])=(u16)(tr);
goto L40d4;
L40d4: /* lea $36fc8.l, A5 */

a[5]=0x36fc8ul;
goto L40da;
L40da: /* lea ($2,A5,D0.w), A5 */

a[5]=(2+a[5]+((s16)(d[0])));
goto L40de;
L40de: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L40e0;
L40e0: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L40e2;
L40e2: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L40e4;
L40e4: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L40e6;
L40e6: /* move.w #$90, D0 */

tv=((u16)(144L));
VWORD(d[0])=(u16)(tv);

goto L40ea;
L40ea: /* moveq #$2, D2 */

v=((u32)(2L));
d[2]=v;

goto L40ec;
L40ec: /* add.w D7, D2 */

tv=((u16)d[7]);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L40ee;
L40ee: /* bsr $4e5e */

a[7]-=4;STACK_WRITE(a[7],0x40f2ul);
goto L4e5e;
L40f2: /* move.w $8d36.l, D0 */

tv=(*(u16 *)(vehicle_state+24));
VWORD(d[0])=(u16)(tv);

goto L40f8;
L40f8: /* addq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L40fa;
L40fa: /* cmpi.w #$12, D0 */

tv=((u16)(18L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L40fe;
L40fe: /* bcs $4102 */

if(fc)goto L4102;
goto L4100;
L4100: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L4102;
L4102: /* move.w D0, $8d36.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+24)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4108;
L4108: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L410a: if(vehicle_external(0x410aul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L410e: if(vehicle_external(0x410eul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L421a: /* move.l A0, -(A7) */

v=((u32)a[0]);
a[7]-=4;
ea=a[7];
STACK_WRITE(ea,v);

goto L421c;
L421c: /* lea $4238.l, A0 */

a[0]=0x4238ul;
goto L4222;
L4222: /* addq.w #3, (A0) */

tv=((u16)(3L));
eb=a[0];
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L4224;
L4224: /* move.w (A0)+, D0 */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
VWORD(d[0])=(u16)(tv);

goto L4226;
L4226: /* subi.w #$8d, (A0) */

tv=((u16)(141L));
eb=a[0];
tw=ver16(eb);
tr=tw-tv;
vew16(eb,tr);
goto L422a;
L422a: /* add.w (A0)+, D0 */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L422c;
L422c: /* rol.w #1, D0 */

v=((u16)(1L));
w=((u16)d[0]);
r=vshift(w,(u8)v,16,5);
VWORD(d[0])=(u16)(r);
goto L422e;
L422e: /* rol.w (A0) */

v=((u16)(1L));
eb=a[0];
w=ver16(eb);
r=vshift(w,(u8)v,16,5);
vew16(eb,r);
goto L4230;
L4230: /* add.w (A0), D0 */

ea=a[0];
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4232;
L4232: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4234;
L4234: /* movea.l (A7)+, A0 */

ea=a[7];
v=STACK_READ(ea);
a[7]+=4;
a[0]=v;
goto L4236;
L4236: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L42be: /* move.w $8f72.l, D0 */

tv=(*(u16 *)(vehicle_state+596));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L42c4;
L42c4: /* beq $4358 */

if(fz)goto L4358;
goto L42c8;
L42c8: /* sub.w D0, $8d2c.l */

tv=((u16)d[0]);
tw=(*(u16 *)(vehicle_state+14));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
*(u16 *)(vehicle_state+14)=(u16)(tr);
goto L42ce;
L42ce: /* bcc $4358 */

if(!fc)goto L4358;
goto L42d2;
L42d2: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x42d6ul);
goto L421a;
L42d6: /* andi.w #$f, D0 */

tv=((u16)(15L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L42da;
L42da: /* addi.w #$a, D0 */

tv=((u16)(10L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L42de;
L42de: /* move.w D0, $8d2c.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+14)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L42e4;
L42e4: /* bsr $475a */

a[7]-=4;STACK_WRITE(a[7],0x42e8ul);
goto L475a;
L42e8: /* movea.l A6, A5 */

v=((u32)a[6]);
a[5]=v;
goto L42ea;
L42ea: /* pea $435a.l */

a[7]-=4;
STACK_WRITE(a[7],0x435aul);
goto L42f0;
L42f0: /* bsr $475a */

a[7]-=4;STACK_WRITE(a[7],0x42f4ul);
goto L475a;
L42f4: /* addq.l #4, A7 */

v=((u32)(4L));
w=((u32)a[7]);
r=w+v;
a[7]=r;
goto L42f6;
L42f6: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x42faul);
goto L421a;
L42fa: /* andi.w #$3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L42fe;
L42fe: /* move.b D0, ($5,A5) */

tv=((u8)d[0]);
ea=(5+a[5]);
vew8(ea,tv);

goto L4302;
L4302: /* move.b D0, ($5,A6) */

tv=((u8)d[0]);
ea=(5+a[6]);
vew8(ea,tv);

goto L4306;
L4306: /* lea $478e.l, A0 */

a[0]=0x478eul;
goto L430c;
L430c: /* move.b (A0,D0.w), D1 */

ea=(a[0]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4310;
L4310: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x4314ul);
goto L421a;
L4314: /* andi.w #$7, D0 */

tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L4318;
L4318: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;
VWORD(d[0])=(u16)(tr);
goto L431a;
L431a: /* lea $423e.l, A0 */

a[0]=0x423eul;
goto L4320;
L4320: /* lea (A0,D0.w), A0 */

a[0]=(a[0]+((s16)(d[0])));
goto L4324;
L4324: /* move.l (A0)+, ($12,A6) */

ea=a[0];
v=ver32(ea);
a[0]+=4;
ea=(18+a[6]);
vew32(ea,v);

goto L4328;
L4328: /* move.b D1, ($3,A6) */

tv=((u8)d[1]);
ea=(3+a[6]);
vew8(ea,tv);

goto L432c;
L432c: /* move.l #$4362, ($16,A6) */

v=((u32)(17250L));
ea=(22+a[6]);
vew32(ea,v);

goto L4334;
L4334: /* move.l A5, ($20,A6) */

v=((u32)a[5]);
ea=(32+a[6]);
vew32(ea,v);

goto L4338;
L4338: /* move.l (A0)+, ($12,A5) */

ea=a[0];
v=ver32(ea);
a[0]+=4;
ea=(18+a[5]);
vew32(ea,v);

goto L433c;
L433c: /* add.w (A0)+, D1 */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L433e;
L433e: /* move.b D1, ($3,A5) */

tv=((u8)d[1]);
ea=(3+a[5]);
vew8(ea,tv);

goto L4342;
L4342: /* move.l #$4436, ($16,A5) */

v=((u32)(17462L));
ea=(22+a[5]);
vew32(ea,v);

goto L434a;
L434a: /* move.w (A0)+, ($1c,A5) */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
ea=(28+a[5]);
vew16(ea,tv);

goto L434e;
L434e: /* move.l (A0), ($20,A5) */

ea=a[0];
v=ver32(ea);
ea=(32+a[5]);
vew32(ea,v);

goto L4352;
L4352: /* move.w #$1, ($1a,A5) */

tv=((u16)(1L));
ea=(26+a[5]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4358;
L4358: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L435a: /* move.b #$0, ($0,A5) */

tv=((u8)(0L));
ea=(0+a[5]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4360;
L4360: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4362: /* move.b ($8,A1), D0 */

ea=(8+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4366;
L4366: /* beq $4434 */

if(fz)goto L4434;
goto L436a;
L436a: /* move.b #$0, ($0,A1) */

tv=((u8)(0L));
ea=(0+a[1]);
vew8(ea,tv);

goto L4370;
L4370: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L4376;
L4376: /* tst.w ($3a,A6) */

ea=(58+a[6]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L437a;
L437a: /* bne $4434 */

if(!fz)goto L4434;
goto L437e;
L437e: /* move.w #$5, ($32,A6) */

tv=((u16)(5L));
ea=(50+a[6]);
vew16(ea,tv);

goto L4384;
L4384: /* move.w #$4, ($3a,A6) */

tv=((u16)(4L));
ea=(58+a[6]);
vew16(ea,tv);

goto L438a;
L438a: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L438c;
L438c: /* cmpi.b #$2, D0 */

tv=((u8)(2L));
tw=((u8)d[0]);
fz=(u8)((u8)tw==(u8)tv);
goto L4390;
L4390: /* beq $43b4 */

if(fz)goto L43b4;
goto L4392;
L4392: /* cmpi.b #$3, D0 */

tv=((u8)(3L));
tw=((u8)d[0]);
fz=(u8)((u8)tw==(u8)tv);
goto L4396;
L4396: /* bne $439a */

if(!fz)goto L439a;
goto L4398;
L4398: /* moveq #-$1, D1 */

v=((u32)(-1L));
d[1]=v;

goto L439a;
L439a: /* move.w D1, ($38,A6) */

tv=((u16)d[1]);
ea=(56+a[6]);
vew16(ea,tv);

goto L439e;
L439e: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L43a4;
L43a4: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L43a6;
L43a6: /* divu.w #$c, D0 */

v=((u16)(12L));
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L43aa;
L43aa: /* move.w D0, ($36,A6) */

tv=((u16)d[0]);
ea=(54+a[6]);
vew16(ea,tv);

goto L43ae;
L43ae: /* move.w ($6,A1), D1 */

ea=(6+a[1]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L43b2;
L43b2: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L43b4;
L43b4: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L43ba;
L43ba: /* move.w D0, D2 */

tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L43bc;
L43bc: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L43be;
L43be: /* divu.w #$3, D0 */

v=((u16)(3L));
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L43c2;
L43c2: /* move.w ($6,A1), D1 */

ea=(6+a[1]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L43c6;
L43c6: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L43c8;
L43c8: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L43ca;
L43ca: /* move.w D0, $8f6e.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L43d0;
L43d0: /* lea $8dfc.l, A6 */

a[6]=0x8dfcul;
goto L43d6;
L43d6: /* moveq #$1, D6 */

v=((u32)(1L));
d[6]=v;

goto L43d8;
L43d8: /* tst.w ($0,A6) */

ea=(0+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L43dc;
L43dc: /* beq $43e6 */

if(fz)goto L43e6;
goto L43de;
L43de: /* lea ($6,A6), A6 */

a[6]=(6+a[6]);
goto L43e2;
L43e2: /* dbra D6, $43d8 */

VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L43d8;
goto L43e6;
L43e6: /* move.w #$1, ($0,A6) */

tv=((u16)(1L));
ea=(0+a[6]);
vew16(ea,tv);

goto L43ec;
L43ec: /* move.w ($10,A1), ($2,A6) */

ea=(16+a[1]);
tv=ver16(ea);
ea=(2+a[6]);
vew16(ea,tv);

goto L43f2;
L43f2: /* move.w ($26,A1), ($4,A6) */

ea=(38+a[1]);
tv=ver16(ea);
ea=(4+a[6]);
vew16(ea,tv);

goto L43f8;
L43f8: /* movem.l D7/A1, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L43fc;
L43fc: /* move.b ($2,A1), D0 */

ea=(2+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L4400;
L4400: /* movea.l ($20,A1), A1 */

ea=(32+a[1]);
v=ver32(ea);
a[1]=v;
goto L4404;
L4404: /* beq $4422 */

if(fz)goto L4422;
goto L4406;
L4406: /* tst.b ($0,A1) */

ea=(0+a[1]);
tv=ver8(ea);
fz=(u8)((tv&0xfful)==0);
goto L440a;
L440a: /* beq $4422 */

if(fz)goto L4422;
goto L440c;
L440c: /* cmp.b ($2,A1), D0 */

ea=(2+a[1]);
tv=ver8(ea);
tw=((u8)d[0]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4410;
L4410: /* bne $4422 */

if(!fz)goto L4422;
goto L4412;
L4412: /* bsr $443e */

a[7]-=4;STACK_WRITE(a[7],0x4414ul);
goto L443e;
L4414: /* moveq #$e, D0 */

v=((u32)(14L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4416;
L4416: /* pea $4422.l */

a[7]-=4;
STACK_WRITE(a[7],0x4422ul);
goto L441c;
L441c: /* jmp $68f8c.l */

return 0x68f8cul;
L4422: /* movem.l (A7)+, D7/A1 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[1]=STACK_READ(ea+4);
a[7]+=8;
goto L4426;
L4426: /* moveq #$d, D0 */

v=((u32)(13L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4428;
L4428: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x442cul);
goto L3c92;
L442c: /* moveq #$1, D0 */

v=((u32)(1L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L442e;
L442e: /* jmp $7c870.l */

return 0x7c870ul;
L4434: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4436: /* move.b ($8,A1), D0 */

ea=(8+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L443a;
L443a: /* bne $443e */

if(!fz)goto L443e;
goto L443c;
L443c: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L443e: /* move.b #$0, ($0,A1) */

tv=((u8)(0L));
ea=(0+a[1]);
vew8(ea,tv);

goto L4444;
L4444: /* lea $8dc0.l, A6 */

a[6]=0x8dc0ul;
goto L444a;
L444a: /* moveq #$1, D6 */

v=((u32)(1L));
d[6]=v;

goto L444c;
L444c: /* tst.w ($0,A6) */

ea=(0+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L4450;
L4450: /* beq $445a */

if(fz)goto L445a;
goto L4452;
L4452: /* lea ($14,A6), A6 */

a[6]=(20+a[6]);
goto L4456;
L4456: /* dbra D6, $444c */

VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L444c;
goto L445a;
L445a: /* move.w ($10,A1), D0 */

ea=(16+a[1]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L445e;
L445e: /* move.w ($26,A1), D1 */

ea=(38+a[1]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L4462;
L4462: /* move.w #$c, ($0,A6) */

tv=((u16)(12L));
ea=(0+a[6]);
vew16(ea,tv);

goto L4468;
L4468: /* move.w #$0, ($2,A6) */

tv=((u16)(0L));
ea=(2+a[6]);
vew16(ea,tv);

goto L446e;
L446e: /* move.w D0, ($4,A6) */

tv=((u16)d[0]);
ea=(4+a[6]);
vew16(ea,tv);

goto L4472;
L4472: /* move.w D1, ($6,A6) */

tv=((u16)d[1]);
ea=(6+a[6]);
vew16(ea,tv);

goto L4476;
L4476: /* addi.w #$28, D0 */

tv=((u16)(40L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L447a;
L447a: /* move.w D0, ($8,A6) */

tv=((u16)d[0]);
ea=(8+a[6]);
vew16(ea,tv);

goto L447e;
L447e: /* move.w D1, ($a,A6) */

tv=((u16)d[1]);
ea=(10+a[6]);
vew16(ea,tv);

goto L4482;
L4482: /* subi.w #$28, D1 */

tv=((u16)(40L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4486;
L4486: /* move.w D0, ($c,A6) */

tv=((u16)d[0]);
ea=(12+a[6]);
vew16(ea,tv);

goto L448a;
L448a: /* move.w D1, ($e,A6) */

tv=((u16)d[1]);
ea=(14+a[6]);
vew16(ea,tv);

goto L448e;
L448e: /* subi.w #$28, D0 */

tv=((u16)(40L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L4492;
L4492: /* move.w D0, ($10,A6) */

tv=((u16)d[0]);
ea=(16+a[6]);
vew16(ea,tv);

goto L4496;
L4496: /* move.w D1, ($12,A6) */

tv=((u16)d[1]);
ea=(18+a[6]);
vew16(ea,tv);

goto L449a;
L449a: /* moveq #$e, D0 */

v=((u32)(14L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L449c;
L449c: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x44a0ul);
goto L3c92;
L44a0: /* moveq #$1, D0 */

v=((u32)(1L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L44a2;
L44a2: /* jmp $7c870.l */

return 0x7c870ul;
L44a8: /* tst.w $8f64.l */

tv=(*(u16 *)(vehicle_state+582));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L44ae;
L44ae: /* beq $4570 */

if(fz)goto L4570;
goto L44b2;
L44b2: /* tst.w $8f72.l */

tv=(*(u16 *)(vehicle_state+596));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L44b8;
L44b8: /* beq $4570 */

if(fz)goto L4570;
goto L44bc;
L44bc: /* move.w #$0, $8f64.l */

tv=((u16)(0L));
*(u16 *)(vehicle_state+582)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L44c4;
L44c4: /* bsr $475a */

a[7]-=4;STACK_WRITE(a[7],0x44c8ul);
goto L475a;
L44c8: /* move.b #$0, ($5,A6) */

tv=((u8)(0L));
ea=(5+a[6]);
vew8(ea,tv);

goto L44ce;
L44ce: /* move.b $478e.l, ($3,A6) */

ea=0x478eul;
tv=ver8(ea);
ea=(3+a[6]);
vew8(ea,tv);

goto L44d6;
L44d6: /* move.l #$3d214, ($12,A6) */

v=((u32)(250388L));
ea=(18+a[6]);
vew32(ea,v);

goto L44de;
L44de: /* move.l #$4572, ($16,A6) */

v=((u32)(17778L));
ea=(22+a[6]);
vew32(ea,v);

goto L44e6;
L44e6: /* move.w #$1, ($24,A6) */

tv=((u16)(1L));
ea=(36+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L44ec;
L44ec: /* bsr $475a */

a[7]-=4;STACK_WRITE(a[7],0x44f0ul);
goto L475a;
L44f0: /* move.b #$1, ($5,A6) */

tv=((u8)(1L));
ea=(5+a[6]);
vew8(ea,tv);

goto L44f6;
L44f6: /* move.b $478f.l, ($3,A6) */

ea=0x478ful;
tv=ver8(ea);
ea=(3+a[6]);
vew8(ea,tv);

goto L44fe;
L44fe: /* move.l #$3d214, ($12,A6) */

v=((u32)(250388L));
ea=(18+a[6]);
vew32(ea,v);

goto L4506;
L4506: /* move.l #$478c, ($16,A6) */

v=((u32)(18316L));
ea=(22+a[6]);
vew32(ea,v);

goto L450e;
L450e: /* move.w #$1, ($24,A6) */

tv=((u16)(1L));
ea=(36+a[6]);
vew16(ea,tv);

goto L4514;
L4514: /* move.b #$15, ($2,A6) */

tv=((u8)(21L));
ea=(2+a[6]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L451a;
L451a: /* bsr $475a */

a[7]-=4;STACK_WRITE(a[7],0x451eul);
goto L475a;
L451e: /* move.b #$2, ($5,A6) */

tv=((u8)(2L));
ea=(5+a[6]);
vew8(ea,tv);

goto L4524;
L4524: /* move.b $4790.l, ($3,A6) */

ea=0x4790ul;
tv=ver8(ea);
ea=(3+a[6]);
vew8(ea,tv);

goto L452c;
L452c: /* move.l #$3d214, ($12,A6) */

v=((u32)(250388L));
ea=(18+a[6]);
vew32(ea,v);

goto L4534;
L4534: /* move.l #$478c, ($16,A6) */

v=((u32)(18316L));
ea=(22+a[6]);
vew32(ea,v);

goto L453c;
L453c: /* move.w #$1, ($24,A6) */

tv=((u16)(1L));
ea=(36+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4542;
L4542: /* bsr $475a */

a[7]-=4;STACK_WRITE(a[7],0x4546ul);
goto L475a;
L4546: /* move.b #$3, ($5,A6) */

tv=((u8)(3L));
ea=(5+a[6]);
vew8(ea,tv);

goto L454c;
L454c: /* move.b $4791.l, ($3,A6) */

ea=0x4791ul;
tv=ver8(ea);
ea=(3+a[6]);
vew8(ea,tv);

goto L4554;
L4554: /* move.l #$3d214, ($12,A6) */

v=((u32)(250388L));
ea=(18+a[6]);
vew32(ea,v);

goto L455c;
L455c: /* move.l #$478c, ($16,A6) */

v=((u32)(18316L));
ea=(22+a[6]);
vew32(ea,v);

goto L4564;
L4564: /* move.w #$1, ($24,A6) */

tv=((u16)(1L));
ea=(36+a[6]);
vew16(ea,tv);

goto L456a;
L456a: /* move.b #$15, ($2,A6) */

tv=((u8)(21L));
ea=(2+a[6]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4570;
L4570: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4572: /* move.b ($2,A1), D0 */

ea=(2+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L4576;
L4576: /* ext.w D0 */

v=((u32)d[0]);
r=(s16)(s8)v;
VWORD(d[0])=(u16)(r);

goto L4578;
L4578: /* cmpi.w #$4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L457c;
L457c: /* bcc $458a */

if(!fc)goto L458a;
goto L457e;
L457e: /* move.w #$1, $8f66.l */

tv=((u16)(1L));
*(u16 *)(vehicle_state+584)=(u16)(tv);

goto L4586;
L4586: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L4588;
L4588: /* bra $4594 */

goto L4594;
L458a: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;fx=(u8)((tw>>12)&1);
VWORD(d[0])=(u16)(tr);
goto L458c;
L458c: /* cmp.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4592;
L4592: /* bcc $459a */

if(!fc)goto L459a;
goto L4594;
L4594: /* move.w D0, $8f6e.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+592)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L459a;
L459a: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L459c: /* move.w $8f72.l, D0 */

tv=(*(u16 *)(vehicle_state+596));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L45a2;
L45a2: /* beq $461c */

if(fz)goto L461c;
goto L45a6;
L45a6: /* sub.w D0, $8d2c.l */

tv=((u16)d[0]);
tw=(*(u16 *)(vehicle_state+14));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
*(u16 *)(vehicle_state+14)=(u16)(tr);
goto L45ac;
L45ac: /* bcc $461c */

if(!fc)goto L461c;
goto L45b0;
L45b0: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x45b4ul);
goto L421a;
L45b4: /* andi.w #$f, D0 */

tv=((u16)(15L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L45b8;
L45b8: /* add.w $8d2e.l, D0 */

tv=(*(u16 *)(vehicle_state+16));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L45be;
L45be: /* move.w D0, $8d2c.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+14)=(u16)(tv);

goto L45c4;
L45c4: /* moveq #$3, D7 */

v=((u32)(3L));
d[7]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L45c6;
L45c6: /* bsr $475c */

a[7]-=4;STACK_WRITE(a[7],0x45caul);
goto L475c;
L45ca: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x45ceul);
goto L421a;
L45ce: /* andi.w #$3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L45d2;
L45d2: /* move.b D0, ($5,A6) */

tv=((u8)d[0]);
ea=(5+a[6]);
vew8(ea,tv);

goto L45d6;
L45d6: /* lea $478e.l, A0 */

a[0]=0x478eul;
goto L45dc;
L45dc: /* move.b (A0,D0.w), ($3,A6) */

ea=(a[0]+((s16)(d[0])));
tv=ver8(ea);
ea=(3+a[6]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L45e2;
L45e2: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x45e6ul);
goto L421a;
L45e6: /* andi.w #$ff, D0 */

tv=((u16)(255L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L45ea;
L45ea: /* addi.w #$32, D0 */

tv=((u16)(50L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L45ee;
L45ee: /* cmpi.w #$96, D0 */

tv=((u16)(150L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L45f2;
L45f2: /* bcc $45fa */

if(!fc)goto L45fa;
goto L45f6;
L45f6: /* addi.w #$96, D0 */

tv=((u16)(150L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L45fa;
L45fa: /* move.w D0, ($6,A6) */

tv=((u16)d[0]);
ea=(6+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L45fe;
L45fe: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x4602ul);
goto L421a;
L4602: /* andi.w #$7, D0 */

tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L4606;
L4606: /* lsl.w #2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw<<2;fx=(u8)((tw>>14)&1);
VWORD(d[0])=(u16)(tr);
goto L4608;
L4608: /* lea $461e.l, A0 */

a[0]=0x461eul;
goto L460e;
L460e: /* move.l (A0,D0.w), ($12,A6) */

ea=(a[0]+((s16)(d[0])));
v=ver32(ea);
ea=(18+a[6]);
vew32(ea,v);

goto L4614;
L4614: /* move.l #$463e, ($16,A6) */

v=((u32)(17982L));
ea=(22+a[6]);
vew32(ea,v);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L461c;
L461c: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L463e: /* bsr $46c2 */

a[7]-=4;STACK_WRITE(a[7],0x4642ul);
goto L46c2;
L4642: /* move.b ($8,A1), D0 */

ea=(8+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4646;
L4646: /* beq $46c0 */

if(fz)goto L46c0;
goto L4648;
L4648: /* move.b #$0, ($8,A1) */

tv=((u8)(0L));
ea=(8+a[1]);
vew8(ea,tv);

goto L464e;
L464e: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L4654;
L4654: /* tst.w ($3a,A6) */

ea=(58+a[6]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4658;
L4658: /* bne $46c0 */

if(!fz)goto L46c0;
goto L465a;
L465a: /* move.w #$5, ($32,A6) */

tv=((u16)(5L));
ea=(50+a[6]);
vew16(ea,tv);

goto L4660;
L4660: /* move.w #$4, ($3a,A6) */

tv=((u16)(4L));
ea=(58+a[6]);
vew16(ea,tv);

goto L4666;
L4666: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L4668;
L4668: /* cmpi.b #$2, D0 */

tv=((u8)(2L));
tw=((u8)d[0]);
fz=(u8)((u8)tw==(u8)tv);
goto L466c;
L466c: /* beq $4690 */

if(fz)goto L4690;
goto L466e;
L466e: /* cmpi.b #$3, D0 */

tv=((u8)(3L));
tw=((u8)d[0]);
fz=(u8)((u8)tw==(u8)tv);
goto L4672;
L4672: /* bne $4676 */

if(!fz)goto L4676;
goto L4674;
L4674: /* moveq #-$1, D1 */

v=((u32)(-1L));
d[1]=v;

goto L4676;
L4676: /* move.w D1, ($38,A6) */

tv=((u16)d[1]);
ea=(56+a[6]);
vew16(ea,tv);

goto L467a;
L467a: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L4680;
L4680: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L4682;
L4682: /* divu.w #$c, D0 */

v=((u16)(12L));
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L4686;
L4686: /* move.w D0, ($36,A6) */

tv=((u16)d[0]);
ea=(54+a[6]);
vew16(ea,tv);

goto L468a;
L468a: /* move.w ($6,A1), D1 */

ea=(6+a[1]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L468e;
L468e: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L4690;
L4690: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L4696;
L4696: /* move.w D0, D2 */

tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L4698;
L4698: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L469a;
L469a: /* divu.w #$3, D0 */

v=((u16)(3L));
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L469e;
L469e: /* move.w ($6,A1), D1 */

ea=(6+a[1]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L46a2;
L46a2: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L46a4;
L46a4: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L46a6;
L46a6: /* move.w D0, $8f6e.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L46ac;
L46ac: /* addi.b #$2, ($2,A1) */

tv=((u8)(2L));
eb=(2+a[1]);
tw=ver8(eb);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
vew8(eb,tr);
goto L46b2;
L46b2: /* moveq #$c, D0 */

v=((u32)(12L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L46b4;
L46b4: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x46b8ul);
goto L3c92;
L46b8: /* moveq #$3, D0 */

v=((u32)(3L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L46ba;
L46ba: /* jmp $7c870.l */

return 0x7c870ul;
L46c0: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L46c2: /* move.b ($5,A1), D2 */

ea=(5+a[1]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L46c6;
L46c6: /* move.b ($2,A1), D0 */

ea=(2+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L46ca;
L46ca: /* moveq #$7, D6 */

v=((u32)(7L));
d[6]=v;

goto L46cc;
L46cc: /* lea $8e0e.l, A2 */

a[2]=0x8e0eul;
goto L46d2;
L46d2: /* cmpa.l A1, A2 */

v=((u32)a[1]);
w=((u32)a[2]);
r=w-v;
fz=(u8)((u32)w==(u32)v);
goto L46d4;
L46d4: /* beq $46fe */

if(fz)goto L46fe;
goto L46d6;
L46d6: /* tst.b ($0,A2) */

ea=(0+a[2]);
tv=ver8(ea);
fz=(u8)((tv&0xfful)==0);
goto L46da;
L46da: /* beq $46fe */

if(fz)goto L46fe;
goto L46dc;
L46dc: /* move.b ($2,A2), D1 */

ea=(2+a[2]);
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L46e0;
L46e0: /* sub.b D0, D1 */

tv=((u8)d[0]);
tw=((u8)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L46e2;
L46e2: /* bcs $46fe */

if(fc)goto L46fe;
goto L46e4;
L46e4: /* cmpi.b #$3, D1 */

tv=((u8)(3L));
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);
goto L46e8;
L46e8: /* bcc $46fe */

if(!fc)goto L46fe;
goto L46ea;
L46ea: /* tst.w ($24,A2) */

ea=(36+a[2]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L46ee;
L46ee: /* beq $46f8 */

if(fz)goto L46f8;
goto L46f0;
L46f0: /* move.w #$0, ($6,A1) */

tv=((u16)(0L));
ea=(6+a[1]);
vew16(ea,tv);

goto L46f6;
L46f2: /* ori.b #$6, D0 */

tv=((u8)(6L));
tw=((u8)d[0]);
tr=tw|tv;

VBYTE(d[0])=(u8)(tr);
goto L46f6;
L46f6: /* bra $46fe */

goto L46fe;
L46f8: /* cmp.b ($5,A2), D2 */

ea=(5+a[2]);
tv=ver8(ea);
tw=((u8)d[2]);
fz=(u8)((u8)tw==(u8)tv);
goto L46fc;
L46fc: /* beq $4708 */

if(fz)goto L4708;
goto L46fe;
L46fe: /* lea ($2a,A2), A2 */

a[2]=(42+a[2]);
goto L4702;
L4702: /* dbra D6, $46d2 */

VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L46d2;
goto L4706;
L4706: /* bra $472c */

goto L472c;
L4708: /* tst.b D2 */

tv=((u8)d[2]);
fz=(u8)((tv&0xfful)==0);
goto L470a;
L470a: /* bne $4710 */

if(!fz)goto L4710;
goto L470c;
L470c: /* moveq #$1, D2 */

v=((u32)(1L));
d[2]=v;

goto L470e;
L470e: /* bra $4728 */

goto L4728;
L4710: /* cmpi.b #$3, D2 */

tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4714;
L4714: /* bne $471a */

if(!fz)goto L471a;
goto L4716;
L4716: /* moveq #$2, D2 */

v=((u32)(2L));
d[2]=v;

goto L4718;
L4718: /* bra $4728 */

goto L4728;
L471a: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x471eul);
goto L421a;
L471e: /* addq.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[2])=(u8)(tr);
goto L4720;
L4720: /* btst #$0, D0 */

v=((u16)(0L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4724;
L4724: /* beq $4728 */

if(fz)goto L4728;
goto L4726;
L4726: /* subq.b #2, D2 */

tv=((u8)(2L));
tw=((u8)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[2])=(u8)(tr);
goto L4728;
L4728: /* move.b D2, ($5,A1) */

tv=((u8)d[2]);
ea=(5+a[1]);
vew8(ea,tv);

goto L472c;
L472c: /* lea $478e.l, A2 */

a[2]=0x478eul;
goto L4732;
L4732: /* ext.w D2 */

v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);

goto L4734;
L4734: /* move.b (A2,D2.w), D1 */

ea=(a[2]+((s16)(d[2])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4738;
L4738: /* move.b ($3,A1), D0 */

ea=(3+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L473c;
L473c: /* cmp.b D0, D1 */

tv=((u8)d[0]);
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L473e;
L473e: /* beq $4758 */

if(fz)goto L4758;
goto L4740;
L4740: /* bcc $474c */

if(!fc)goto L474c;
goto L4742;
L4742: /* subq.b #6, D0 */

tv=((u8)(6L));
tw=((u8)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[0])=(u8)(tr);
goto L4744;
L4744: /* cmp.b D0, D1 */

tv=((u8)d[0]);
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);
goto L4746;
L4746: /* bcs $4754 */

if(fc)goto L4754;
goto L4748;
L4748: /* move.b D1, D0 */

tv=((u8)d[1]);
VBYTE(d[0])=(u8)(tv);

goto L474a;
L474a: /* bra $4754 */

goto L4754;
L474c: /* addq.b #6, D0 */

tv=((u8)(6L));
tw=((u8)d[0]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[0])=(u8)(tr);
goto L474e;
L474e: /* cmp.b D0, D1 */

tv=((u8)d[0]);
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);
goto L4750;
L4750: /* bcc $4754 */

if(!fc)goto L4754;
goto L4752;
L4752: /* move.b D1, D0 */

tv=((u8)d[1]);
VBYTE(d[0])=(u8)(tv);

goto L4754;
L4754: /* move.b D0, ($3,A1) */

tv=((u8)d[0]);
ea=(3+a[1]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4758;
L4758: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L475a: /* moveq #$7, D7 */

v=((u32)(7L));
d[7]=v;

goto L475c;
L475c: /* lea $8e0e.l, A6 */

a[6]=0x8e0eul;
goto L4762;
L4762: /* tst.b ($0,A6) */

ea=(0+a[6]);
tv=ver8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4766;
L4766: /* beq $4774 */

if(fz)goto L4774;
goto L4768;
L4768: /* lea ($2a,A6), A6 */

a[6]=(42+a[6]);
goto L476c;
L476c: /* dbra D7, $4762 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4762;
goto L4770;
L4770: /* addq.l #4, A7 */

v=((u32)(4L));
w=((u32)a[7]);
r=w+v;
a[7]=r;
goto L4772;
L4772: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4774: /* moveq #$14, D7 */

v=((u32)(20L));
d[7]=v;

goto L4776;
L4776: /* movea.l A6, A4 */

v=((u32)a[6]);
a[4]=v;
goto L4778;
L4778: /* move.w #$0, (A4)+ */

tv=((u16)(0L));
ea=a[4];
vew16(ea,tv);
a[4]+=2;

goto L477c;
L477c: /* dbra D7, $4778 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4778;
goto L4780;
L4780: /* move.b #$16, ($2,A6) */

tv=((u8)(22L));
ea=(2+a[6]);
vew8(ea,tv);

goto L4786;
L4786: /* move.b #$1, ($0,A6) */

tv=((u8)(1L));
ea=(0+a[6]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L478c;
L478c: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4792: /* lea $8122.l, A0 */

a[0]=0x8122ul;
goto L4798;
L4798: /* move.l A0, $8f5e.l */

v=((u32)a[0]);
*(u16 *)(vehicle_state+576)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+578)=(u16)(v);

goto L479e;
L479e: /* moveq #-$1, D0 */

v=((u32)(-1L));
d[0]=v;

goto L47a0;
L47a0: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47a2;
L47a2: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47a4;
L47a4: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47a6;
L47a6: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47a8;
L47a8: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47aa;
L47aa: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47ac;
L47ac: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47ae;
L47ae: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47b0;
L47b0: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47b2;
L47b2: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47b4;
L47b4: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47b6;
L47b6: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47b8;
L47b8: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47ba;
L47ba: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47bc;
L47bc: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47be;
L47be: /* addq.w #6, A0 */

v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L47c0;
L47c0: /* move.w D0, (A0) */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);

goto L47c2;
L47c2: /* lea $909e.l, A0 */

a[0]=0x909eul;
goto L47c8;
L47c8: /* lea $8e0e.l, A1 */

a[1]=0x8e0eul;
goto L47ce;
L47ce: /* moveq #$7, D7 */

v=((u32)(7L));
d[7]=v;

goto L47d0;
L47d0: /* tst.b ($0,A1) */

ea=(0+a[1]);
tv=ver8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L47d4;
L47d4: /* bne $47e0 */

if(!fz)goto L47e0;
goto L47d6;
L47d6: /* lea ($2a,A1), A1 */

a[1]=(42+a[1]);
goto L47da;
L47da: /* dbra D7, $47d0 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L47d0;
goto L47de;
L47de: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L47e0: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L47e2;
L47e2: /* move.w D1, D0 */

tv=((u16)d[1]);
VWORD(d[0])=(u16)(tv);

goto L47e4;
L47e4: /* move.b ($4,A1), D0 */

ea=(4+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L47e8;
L47e8: /* move.b ($6,A1), D1 */

ea=(6+a[1]);
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L47ec;
L47ec: /* sub.b ($7,A1), D0 */

ea=(7+a[1]);
tv=ver8(ea);
tw=((u8)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);
VBYTE(d[0])=(u8)(tr);
goto L47f0;
L47f0: /* bcc $47f6 */

if(!fc)goto L47f6;
goto L47f2;
L47f2: /* addi.b #$1, D1 */

tv=((u8)(1L));
tw=((u8)d[1]);
tr=tw+tv;
VBYTE(d[1])=(u8)(tr);
goto L47f6;
L47f6: /* add.b ($2,A1), D1 */

ea=(2+a[1]);
tv=ver8(ea);
tw=((u8)d[1]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[1])=(u8)(tr);
goto L47fa;
L47fa: /* tst.b ($1,A1) */

ea=(1+a[1]);
tv=ver8(ea);
fz=(u8)((tv&0xfful)==0);
goto L47fe;
L47fe: /* bne $480e */

if(!fz)goto L480e;
goto L4800;
L4800: /* cmpi.b #$18, D1 */

tv=((u8)(24L));
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);
goto L4804;
L4804: /* bcs $4824 */

if(fc)goto L4824;
goto L4806;
L4806: /* move.b #$0, ($0,A1) */

tv=((u8)(0L));
ea=(0+a[1]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L480c;
L480c: /* bra $47d6 */

goto L47d6;
L480e: /* tst.b D1 */

tv=((u8)d[1]);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;
goto L4810;
L4810: /* ble $4824 */

if((fz||(fn!=fv)))goto L4824;
goto L4812;
L4812: /* cmpi.b #$2, D1 */

tv=((u8)(2L));
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);
goto L4816;
L4816: /* bcs $481e */

if(fc)goto L481e;
goto L4818;
L4818: /* cmpi.b #-$42, D0 */

tv=((u8)(-66L));
tw=((u8)d[0]);
fc=(u8)((u8)tw<(u8)tv);
goto L481c;
L481c: /* bcc $4824 */

if(!fc)goto L4824;
goto L481e;
L481e: /* move.b #$be, D0 */

tv=((u8)(190L));
VBYTE(d[0])=(u8)(tv);

goto L4822;
L4822: /* moveq #$1, D1 */

v=((u32)(1L));
d[1]=v;

goto L4824;
L4824: /* move.b D1, ($2,A1) */

tv=((u8)d[1]);
ea=(2+a[1]);
vew8(ea,tv);

goto L4828;
L4828: /* move.b D0, ($4,A1) */

tv=((u8)d[0]);
ea=(4+a[1]);
vew8(ea,tv);

goto L482c;
L482c: /* cmpi.b #$14, D1 */

tv=((u8)(20L));
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4830;
L4830: /* bcc $4a2c */

if(!fc)goto L4a2c;
goto L4834;
L4834: /* tst.b D1 */

tv=((u8)d[1]);
fz=(u8)((tv&0xfful)==0);
goto L4836;
L4836: /* bne $4858 */

if(!fz)goto L4858;
goto L4838;
L4838: /* move.w $9078.l, D2 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[2])=(u16)(tv);

goto L483e;
L483e: /* andi.b #$e0, D2 */

tv=((u8)(224L));
tw=((u8)d[2]);
tr=tw&tv;

VBYTE(d[2])=(u8)(tr);
goto L4842;
L4842: /* not.b D2 */

tv=((u8)d[2]);
tr=~tv;
VBYTE(d[2])=(u8)(tr);

goto L4844;
L4844: /* cmp.b D0, D2 */

tv=((u8)d[0]);
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4846;
L4846: /* bcc $4858 */

if(!fc)goto L4858;
goto L4848;
L4848: /* tst.b ($1,A1) */

ea=(1+a[1]);
tv=ver8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L484c;
L484c: /* bne $47d6 */

if(!fz)goto L47d6;
goto L484e;
L484e: /* move.b #$0, ($0,A1) */

tv=((u8)(0L));
ea=(0+a[1]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4854;
L4854: /* bra $47d6 */

goto L47d6;
L4858: /* move.b ($5b,A0,D1.w), D0 */

ea=(91+a[0]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L485c;
L485c: /* move.b D0, D2 */

tv=((u8)d[0]);
VBYTE(d[2])=(u8)(tv);

goto L485e;
L485e: /* sub.b ($5a,A0,D1.w), D0 */

ea=(90+a[0]+((s16)(d[1])));
tv=ver8(ea);
tw=((u8)d[0]);
tr=tw-tv;
VBYTE(d[0])=(u8)(tr);
goto L4862;
L4862: /* move.b ($4,A1), D1 */

ea=(4+a[1]);
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4866;
L4866: /* mulu.w D1, D0 */

v=((u16)d[1]);
w=((u32)d[0]);
r=vehicle_mulu16(v,w);

d[0]=r;
goto L4868;
L4868: /* lsr.w #8, D0 */

tv=((u16)(8L));
tw=((u16)d[0]);
tr=((u16)tw)>>8;
VWORD(d[0])=(u16)(tr);
goto L486a;
L486a: /* move.w D0, ($a,A1) */

tv=((u16)d[0]);
ea=(10+a[1]);
vew16(ea,tv);

goto L486e;
L486e: /* sub.b D0, D2 */

tv=((u8)d[0]);
tw=((u8)d[2]);
tr=tw-tv;
VBYTE(d[2])=(u8)(tr);
goto L4870;
L4870: /* add.b D2, D2 */

tv=((u8)d[2]);
tw=((u8)d[2]);
tr=tw+tv;
VBYTE(d[2])=(u8)(tr);
goto L4872;
L4872: /* andi.w #$ff, D2 */

tv=((u16)(255L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L4876;
L4876: /* lea $7bc8.l, A2 */

a[2]=0x7bc8ul;
goto L487c;
L487c: /* lea (A2,D2.w), A2 */

a[2]=(a[2]+((s16)(d[2])));
goto L4880;
L4880: /* move.w ($400,A2), D0 */

ea=(1024+a[2]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L4884;
L4884: /* move.w (A2), D1 */

ea=a[2];
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L4886;
L4886: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4888;
L4888: /* moveq #$0, D2 */

v=((u32)(0L));
d[2]=v;

goto L488a;
L488a: /* move.b ($3,A1), D2 */

ea=(3+a[1]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L488e;
L488e: /* mulu.w D2, D0 */

v=((u16)d[2]);
w=((u32)d[0]);
r=vehicle_mulu16(v,w);

d[0]=r;
goto L4890;
L4890: /* lsr.l #8, D0 */

v=((u32)(8L));
w=((u32)d[0]);
r=((u32)w)>>8;
d[0]=r;
goto L4892;
L4892: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4894;
L4894: /* move.b ($2,A1), D2 */

ea=(2+a[1]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4898;
L4898: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L489a;
L489a: /* lsr.b #2, D2 */

tv=((u8)(2L));
tw=((u8)d[2]);
tr=((u8)tw)>>2;
VBYTE(d[2])=(u8)(tr);
goto L489c;
L489c: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L489e;
L489e: /* lsr.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=((u16)tw)>>1;
VWORD(d[3])=(u16)(tr);
goto L48a0;
L48a0: /* cmpi.w #$7, D3 */

tv=((u16)(7L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L48a4;
L48a4: /* bcs $48a8 */

if(fc)goto L48a8;
goto L48a6;
L48a6: /* moveq #$7, D3 */

v=((u32)(7L));
d[3]=v;

goto L48a8;
L48a8: /* asl.w #4, D3 */

tv=((u16)(4L));
tw=((u16)d[3]);
tr=tw<<4;
VWORD(d[3])=(u16)(tr);
goto L48aa;
L48aa: /* movea.l ($12,A1), A2 */

ea=(18+a[1]);
v=ver32(ea);
a[2]=v;
goto L48ae;
L48ae: /* lea (A2,D3.w), A2 */

a[2]=(a[2]+((s16)(d[3])));
goto L48b2;
L48b2: /* move.w (A2), D3 */

ea=a[2];
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L48b4;
L48b4: /* move.w D3, ($c,A1) */

tv=((u16)d[3]);
ea=(12+a[1]);
vew16(ea,tv);

goto L48b8;
L48b8: /* move.w ($6,A2), ($e,A1) */

ea=(6+a[2]);
tv=ver16(ea);
ea=(14+a[1]);
vew16(ea,tv);

goto L48be;
L48be: /* move.w D0, D6 */

tv=((u16)d[0]);
VWORD(d[6])=(u16)(tv);

goto L48c0;
L48c0: /* lsr.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=((u16)tw)>>1;
VWORD(d[3])=(u16)(tr);
goto L48c2;
L48c2: /* sub.w D3, D0 */

tv=((u16)d[3]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L48c4;
L48c4: /* move.w D0, ($10,A1) */

tv=((u16)d[0]);
ea=(16+a[1]);
vew16(ea,tv);

goto L48c8;
L48c8: /* tst.w ($28,A1) */

ea=(40+a[1]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L48cc;
L48cc: /* beq $48e4 */

if(fz)goto L48e4;
goto L48ce;
L48ce: /* addq.w #6, ($1c,A1) */

tv=((u16)(6L));
eb=(28+a[1]);
tw=ver16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vew16(eb,tr);
goto L48d2;
L48d2: /* cmpi.w #$50, ($1c,A1) */

tv=((u16)(80L));
eb=(28+a[1]);
tw=ver16(eb);
fc=(u8)((u16)tw<(u16)tv);
goto L48d8;
L48d8: /* bcs $48ea */

if(fc)goto L48ea;
goto L48da;
L48da: /* move.b #$0, ($0,A1) */

tv=((u8)(0L));
ea=(0+a[1]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L48e0;
L48e0: /* bra $47d6 */

goto L47d6;
L48e4: /* tst.w ($1a,A1) */

ea=(26+a[1]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L48e8;
L48e8: /* beq $4910 */

if(fz)goto L4910;
goto L48ea;
L48ea: /* move.w $9078.l, D1 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[1])=(u16)(tv);

goto L48f0;
L48f0: /* andi.w #$e0, D1 */

tv=((u16)(224L));
tw=((u16)d[1]);
tr=tw&tv;

VWORD(d[1])=(u16)(tr);
goto L48f4;
L48f4: /* add.b ($2,A1), D1 */

ea=(2+a[1]);
tv=ver8(ea);
tw=((u8)d[1]);
tr=tw+tv;
VBYTE(d[1])=(u8)(tr);
goto L48f8;
L48f8: /* lea $7821.l, A2 */

a[2]=0x7821ul;
goto L48fe;
L48fe: /* move.b (A2,D1.w), D1 */

ea=(a[2]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4902;
L4902: /* mulu.w ($1c,A1), D1 */

ea=(28+a[1]);
v=ver16(ea);
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L4906;
L4906: /* lsr.w #5, D1 */

tv=((u16)(5L));
tw=((u16)d[1]);
tr=((u16)tw)>>5;
VWORD(d[1])=(u16)(tr);
goto L4908;
L4908: /* add.w ($a,A1), D1 */

ea=(10+a[1]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L490c;
L490c: /* move.w D1, ($1e,A1) */

tv=((u16)d[1]);
ea=(30+a[1]);
vew16(ea,tv);

goto L4910;
L4910: /* move.b ($2,A1), D1 */

ea=(2+a[1]);
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4914;
L4914: /* cmpi.b #$2, D1 */

tv=((u8)(2L));
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);
goto L4918;
L4918: /* bcc $49f0 */

if(!fc)goto L49f0;
goto L491c;
L491c: /* ext.w D1 */

v=((u32)d[1]);
r=(s16)(s8)v;
VWORD(d[1])=(u16)(r);

goto L491e;
L491e: /* move.b ($1,A0,D1.w), D2 */

ea=(1+a[0]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4922;
L4922: /* andi.w #$ff, D2 */

tv=((u16)(255L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L4926;
L4926: /* addi.w #$38, D2 */

tv=((u16)(56L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L492a;
L492a: /* add.w ($a,A1), D2 */

ea=(10+a[1]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L492e;
L492e: /* move.w D2, ($26,A1) */

tv=((u16)d[2]);
ea=(38+a[1]);
vew16(ea,tv);

goto L4932;
L4932: /* lea $8d5c.l, A2 */

a[2]=0x8d5cul;
goto L4938;
L4938: /* move.w ($10,A2), D3 */

ea=(16+a[2]);
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L493c;
L493c: /* add.w ($2c,A2), D3 */

ea=(44+a[2]);
tv=ver16(ea);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L4940;
L4940: /* move.w D3, D4 */

tv=((u16)d[3]);
VWORD(d[4])=(u16)(tv);

goto L4942;
L4942: /* sub.w ($2a,A2), D4 */

ea=(42+a[2]);
tv=ver16(ea);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4946;
L4946: /* tst.w ($1a,A1) */

ea=(26+a[1]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L494a;
L494a: /* beq $49aa */

if(fz)goto L49aa;
goto L494c;
L494c: /* cmp.w D4, D2 */

tv=((u16)d[4]);
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L494e;
L494e: /* bcs $49aa */

if(fc)goto L49aa;
goto L4950;
L4950: /* move.w D2, D5 */

tv=((u16)d[2]);
VWORD(d[5])=(u16)(tv);

goto L4952;
L4952: /* sub.w ($1e,A1), D5 */

ea=(30+a[1]);
tv=ver16(ea);
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4956;
L4956: /* move.w D5, ($26,A1) */

tv=((u16)d[5]);
ea=(38+a[1]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L495a;
L495a: /* bmi $4960 */

if(fn)goto L4960;
goto L495c;
L495c: /* cmp.w D3, D5 */

tv=((u16)d[3]);
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L495e;
L495e: /* bcc $49aa */

if(!fc)goto L49aa;
goto L4960;
L4960: /* tst.b D1 */

tv=((u8)d[1]);
fz=(u8)((tv&0xfful)==0);
goto L4962;
L4962: /* beq $496c */

if(fz)goto L496c;
goto L4964;
L4964: /* tst.b $9079.l */

tv=vehicle_state[858];
fn=(u8)((tv&0x80ul)!=0);
goto L496a;
L496a: /* bpl $49aa */

if(!fn)goto L49aa;
goto L496c;
L496c: /* subi.w #$8, D6 */

tv=((u16)(8L));
tw=((u16)d[6]);
tr=tw-tv;
VWORD(d[6])=(u16)(tr);
goto L4970;
L4970: /* cmp.w ($30,A2), D6 */

ea=(48+a[2]);
tv=ver16(ea);
tw=((u16)d[6]);
fc=(u8)((u16)tw<(u16)tv);
goto L4974;
L4974: /* bcc $49aa */

if(!fc)goto L49aa;
goto L4976;
L4976: /* addi.w #$10, D6 */

tv=((u16)(16L));
tw=((u16)d[6]);
tr=tw+tv;
VWORD(d[6])=(u16)(tr);
goto L497a;
L497a: /* cmp.w ($2e,A2), D6 */

ea=(46+a[2]);
tv=ver16(ea);
tw=((u16)d[6]);
fc=(u8)((u16)tw<(u16)tv);
goto L497e;
L497e: /* bcs $49aa */

if(fc)goto L49aa;
goto L4980;
L4980: /* move.w #$0, ($1a,A1) */

tv=((u16)(0L));
ea=(26+a[1]);
vew16(ea,tv);

goto L4986;
L4986: /* move.w #$1, ($28,A1) */

tv=((u16)(1L));
ea=(40+a[1]);
vew16(ea,tv);

goto L498c;
L498c: /* subq.w #1, $8d24.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+6));
tr=tw-tv;fx=(u8)(tv>tw);
*(u16 *)(vehicle_state+6)=(u16)(tr);
goto L4992;
L4992: /* moveq #$f, D0 */

v=((u32)(15L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4994;
L4994: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x4998ul);
goto L3c92;
L4998: /* move.l #$200, D0 */

v=((u32)(512L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L499e;
L499e: /* pea $49aa.l */

a[7]-=4;
STACK_WRITE(a[7],0x49aaul);
goto L49a4;
L49a4: /* jmp $7c82a.l */

return 0x7c82aul;
L49aa: /* sub.w ($1e,A1), D2 */

ea=(30+a[1]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L49ae;
L49ae: /* bmi $49f0 */

if(fn)goto L49f0;
goto L49b0;
L49b0: /* tst.w ($28,A1) */

ea=(40+a[1]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L49b4;
L49b4: /* bne $49f0 */

if(!fz)goto L49f0;
goto L49b6;
L49b6: /* cmp.w D4, D2 */

tv=((u16)d[4]);
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L49b8;
L49b8: /* bcs $49f0 */

if(fc)goto L49f0;
goto L49ba;
L49ba: /* sub.w ($e,A1), D2 */

ea=(14+a[1]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L49be;
L49be: /* bmi $49c4 */

if(fn)goto L49c4;
goto L49c0;
L49c0: /* cmp.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L49c2;
L49c2: /* bcc $49f0 */

if(!fc)goto L49f0;
goto L49c4;
L49c4: /* cmp.w ($30,A2), D0 */

ea=(48+a[2]);
tv=ver16(ea);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L49c8;
L49c8: /* bcc $49f0 */

if(!fc)goto L49f0;
goto L49ca;
L49ca: /* move.w ($c,A1), D2 */

ea=(12+a[1]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L49ce;
L49ce: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L49d0;
L49d0: /* cmp.w ($2e,A2), D0 */

ea=(46+a[2]);
tv=ver16(ea);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L49d4;
L49d4: /* bcs $49f0 */

if(fc)goto L49f0;
goto L49d6;
L49d6: /* lsr.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L49d8;
L49d8: /* sub.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L49da;
L49da: /* moveq #$3, D1 */

v=((u32)(3L));
d[1]=v;

goto L49dc;
L49dc: /* cmpi.w #$b9, D0 */

tv=((u16)(185L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L49e0;
L49e0: /* bcc $49ec */

if(!fc)goto L49ec;
goto L49e2;
L49e2: /* moveq #$2, D1 */

v=((u32)(2L));
d[1]=v;

goto L49e4;
L49e4: /* cmpi.w #$87, D0 */

tv=((u16)(135L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L49e8;
L49e8: /* bcc $49ec */

if(!fc)goto L49ec;
goto L49ea;
L49ea: /* moveq #$1, D1 */

v=((u32)(1L));
d[1]=v;

goto L49ec;
L49ec: /* move.b D1, ($8,A1) */

tv=((u8)d[1]);
ea=(8+a[1]);
vew8(ea,tv);

goto L49f0;
L49f0: /* move.b ($2,A1), D0 */

ea=(2+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L49f4;
L49f4: /* lsl.w #8, D0 */

tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw<<8;fx=(u8)((tw>>8)&1);
VWORD(d[0])=(u16)(tr);
goto L49f6;
L49f6: /* move.b ($4,A1), D0 */

ea=(4+a[1]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L49fa;
L49fa: /* not.b D0 */

tv=((u8)d[0]);
tr=~tv;
VBYTE(d[0])=(u8)(tr);

goto L49fc;
L49fc: /* lea $8122.l, A2 */

a[2]=0x8122ul;
goto L4a02;
L4a02: /* moveq #$7, D6 */

v=((u32)(7L));
d[6]=v;

goto L4a04;
L4a04: /* move.w (A2), D1 */

ea=a[2];
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L4a06;
L4a06: /* bmi $4a28 */

if(fn)goto L4a28;
goto L4a08;
L4a08: /* cmp.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L4a0a;
L4a0a: /* bcs $4a12 */

if(fc)goto L4a12;
goto L4a0c;
L4a0c: /* addq.l #6, A2 */

v=((u32)(6L));
w=((u32)a[2]);
r=w+v;
a[2]=r;
goto L4a0e;
L4a0e: /* subq.w #1, D6 */

tv=((u16)(1L));
tw=((u16)d[6]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[6])=(u16)(tr);
goto L4a10;
L4a10: /* bra $4a04 */

goto L4a04;
L4a12: /* subq.w #1, D6 */

tv=((u16)(1L));
tw=((u16)d[6]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[6])=(u16)(tr);
goto L4a14;
L4a14: /* bmi $4a28 */

if(fn)goto L4a28;
goto L4a16;
L4a16: /* lea $8152.l, A3 */

a[3]=0x8152ul;
goto L4a1c;
L4a1c: /* lea (-$6,A3), A2 */

a[2]=(-6+a[3]);
goto L4a20;
L4a20: /* move.l -(A2), -(A3) */

a[2]-=4;
ea=a[2];
v=ver32(ea);
a[3]-=4;
ea=a[3];
vew32(ea,v);

goto L4a22;
L4a22: /* move.w -(A2), -(A3) */

a[2]-=2;
ea=a[2];
tv=ver16(ea);
a[3]-=2;
ea=a[3];
vew16(ea,tv);

goto L4a24;
L4a24: /* dbra D6, $4a20 */

VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L4a20;
goto L4a28;
L4a28: /* move.w D0, (A2)+ */

tv=((u16)d[0]);
ea=a[2];
vew16(ea,tv);
a[2]+=2;

goto L4a2a;
L4a2a: /* move.l A1, (A2) */

v=((u32)a[1]);
ea=a[2];
vew32(ea,v);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4a2c;
L4a2c: /* movea.l ($16,A1), A2 */

ea=(22+a[1]);
v=ver32(ea);
a[2]=v;
goto L4a30;
L4a30: /* pea $47d6.l */

a[7]-=4;
STACK_WRITE(a[7],0x47d6ul);
goto L4a36;
L4a36: /* jmp (A2) */

pc=a[2];goto dispatch;
L4a38: /* movea.l $8f5e.l, A4 */

v=(((u32)*(u16 *)(vehicle_state+576)<<16)|*(u16 *)(vehicle_state+578));
a[4]=v;
goto L4a3e;
L4a3e: /* cmp.b (A4), D7 */

ea=a[4];
tv=ver8(ea);
tw=((u8)d[7]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4a40;
L4a40: /* beq $4a44 */

if(fz)goto L4a44;
goto L4a42;
L4a42: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4a44: /* movea.l ($2,A4), A6 */

ea=(2+a[4]);
v=ver32(ea);
a[6]=v;
goto L4a48;
L4a48: /* addq.l #6, $8f5e.l */

v=((u32)(6L));
w=(((u32)*(u16 *)(vehicle_state+576)<<16)|*(u16 *)(vehicle_state+578));
r=w+v;fx=(u8)(r<w);
*(u16 *)(vehicle_state+576)=(u16)((u32)(r)>>16);
*(u16 *)(vehicle_state+578)=(u16)(r);
goto L4a4e;
L4a4e: /* movea.l ($12,A6), A5 */

ea=(18+a[6]);
v=ver32(ea);
a[5]=v;
goto L4a52;
L4a52: /* lea (A5,D5.w), A5 */

a[5]=(a[5]+((s16)(d[5])));
goto L4a56;
L4a56: /* move.w (A5)+, D1 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[1])=(u16)(tv);

goto L4a58;
L4a58: /* move.w ($10,A6), D0 */

ea=(16+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L4a5c;
L4a5c: /* bmi $4a68 */

if(fn)goto L4a68;
goto L4a5e;
L4a5e: /* cmpi.w #$140, D0 */

tv=((u16)(320L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L4a62;
L4a62: /* bcs $4a72 */

if(fc)goto L4a72;
goto L4a64;
L4a64: /* bra $4a38 */

goto L4a38;
L4a68: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4a6a;
L4a6a: /* bmi $4a38 */

if(fn)goto L4a38;
goto L4a6c;
L4a6c: /* cmpi.w #$0, D1 */

tv=((u16)(0L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L4a70;
L4a70: /* bcs $4a38 */

if(fc)goto L4a38;
goto L4a72;
L4a72: /* tst.w ($1a,A6) */

ea=(26+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L4a76;
L4a76: /* bne $4a8e */

if(!fz)goto L4a8e;
goto L4a78;
L4a78: /* movem.l D5-D7/A0-A3, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[3]);
a[7]-=4;
STACK_WRITE(a[7],a[2]);
a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],a[0]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
a[7]-=4;
STACK_WRITE(a[7],d[6]);
a[7]-=4;
STACK_WRITE(a[7],d[5]);
goto L4a7c;
L4a7c: /* move.w ($a,A6), D6 */

ea=(10+a[6]);
tv=ver16(ea);
VWORD(d[6])=(u16)(tv);

goto L4a80;
L4a80: /* sub.w ($1e,A6), D6 */

ea=(30+a[6]);
tv=ver16(ea);
tw=((u16)d[6]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[6])=(u16)(tr);
goto L4a84;
L4a84: /* bsr $4e0a */

a[7]-=4;STACK_WRITE(a[7],0x4a88ul);
goto L4e0a;
L4a88: /* movem.l (A7)+, D5-D7/A0-A3 */

ea=a[7];
d[5]=STACK_READ(ea+0);
d[6]=STACK_READ(ea+4);
d[7]=STACK_READ(ea+8);
a[0]=STACK_READ(ea+12);
a[1]=STACK_READ(ea+16);
a[2]=STACK_READ(ea+20);
a[3]=STACK_READ(ea+24);
a[7]+=28;
goto L4a8c;
L4a8c: /* bra $4a38 */

goto L4a38;
L4a8e: /* movem.l D0-D7/A0-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],a[4]);
a[7]-=4;
STACK_WRITE(a[7],a[3]);
a[7]-=4;
STACK_WRITE(a[7],a[2]);
a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],a[0]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
a[7]-=4;
STACK_WRITE(a[7],d[6]);
a[7]-=4;
STACK_WRITE(a[7],d[5]);
a[7]-=4;
STACK_WRITE(a[7],d[4]);
a[7]-=4;
STACK_WRITE(a[7],d[3]);
a[7]-=4;
STACK_WRITE(a[7],d[2]);
a[7]-=4;
STACK_WRITE(a[7],d[1]);
a[7]-=4;
STACK_WRITE(a[7],d[0]);
goto L4a92;
L4a92: /* movea.l ($20,A6), A5 */

ea=(32+a[6]);
v=ver32(ea);
a[5]=v;
goto L4a96;
L4a96: /* lsr.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=((u16)tw)>>1;
VWORD(d[5])=(u16)(tr);
goto L4a98;
L4a98: /* lea (A5,D5.w), A5 */

a[5]=(a[5]+((s16)(d[5])));
goto L4a9c;
L4a9c: /* lea $4c6a.l, A4 */

a[4]=0x4c6aul;
goto L4aa2;
L4aa2: /* lea (A4,D5.w), A4 */

a[4]=(a[4]+((s16)(d[5])));
goto L4aa6;
L4aa6: /* add.w (A5), D0 */

ea=a[5];
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4aa8;
L4aa8: /* bmi $4b90 */

if(fn)goto L4b90;
goto L4aac;
L4aac: /* cmpi.w #$130, D0 */

tv=((u16)(304L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L4ab0;
L4ab0: /* bcc $4b90 */

if(!fc)goto L4b90;
goto L4ab4;
L4ab4: /* move.w ($a,A6), D6 */

ea=(10+a[6]);
tv=ver16(ea);
VWORD(d[6])=(u16)(tv);

goto L4ab8;
L4ab8: /* move.w ($2,A5), D7 */

ea=(2+a[5]);
tv=ver16(ea);
VWORD(d[7])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L4abc;
L4abc: /* beq $4b90 */

if(fz)goto L4b90;
goto L4ac0;
L4ac0: /* add.w D7, D6 */

tv=((u16)d[7]);
tw=((u16)d[6]);
tr=tw+tv;
VWORD(d[6])=(u16)(tr);
goto L4ac2;
L4ac2: /* add.w ($4,A5), D7 */

ea=(4+a[5]);
tv=ver16(ea);
tw=((u16)d[7]);
tr=tw+tv;
VWORD(d[7])=(u16)(tr);
goto L4ac6;
L4ac6: /* add.w ($1e,A6), D7 */

ea=(30+a[6]);
tv=ver16(ea);
tw=((u16)d[7]);
tr=tw+tv;
VWORD(d[7])=(u16)(tr);
goto L4aca;
L4aca: /* moveq #$0, D2 */

v=((u32)(0L));
d[2]=v;

goto L4acc;
L4acc: /* move.w D2, D1 */

tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L4ace;
L4ace: /* move.b (A1), D1 */

ea=a[1];
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4ad0;
L4ad0: /* move.b ($43,A1), D2 */

ea=(67+a[1]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4ad4;
L4ad4: /* sub.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw-tv;fz=(u8)((tr&0xfffful)==0);
VWORD(d[1])=(u16)(tr);
goto L4ad6;
L4ad6: /* bne $4aea */

if(!fz)goto L4aea;
goto L4ad8;
L4ad8: /* add.w D6, D2 */

tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4ada;
L4ada: /* bmi $4b90 */

if(fn)goto L4b90;
goto L4ade;
L4ade: /* move.w D2, D1 */

tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L4ae0;
L4ae0: /* addq.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4ae2;
L4ae2: /* sub.w D7, D1 */

tv=((u16)d[7]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4ae4;
L4ae4: /* bcc $4b06 */

if(!fc)goto L4b06;
goto L4ae6;
L4ae6: /* add.w D1, D7 */

tv=((u16)d[1]);
tw=((u16)d[7]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[7])=(u16)(tr);
goto L4ae8;
L4ae8: /* bra $4b06 */

goto L4b06;
L4aea: /* tst.w D6 */

tv=((u16)d[6]);
fn=(u8)((tv&0x8000ul)!=0);
goto L4aec;
L4aec: /* bmi $4af2 */

if(fn)goto L4af2;
goto L4aee;
L4aee: /* sub.w D6, D1 */

tv=((u16)d[6]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4af0;
L4af0: /* bra $4af4 */

goto L4af4;
L4af2: /* add.w D6, D1 */

tv=((u16)d[6]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4af4;
L4af4: /* move.w D1, D6 */

tv=((u16)d[1]);
VWORD(d[6])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L4af6;
L4af6: /* beq $4ad8 */

if(fz)goto L4ad8;
goto L4af8;
L4af8: /* bmi $4ad8 */

if(fn)goto L4ad8;
goto L4afa;
L4afa: /* subq.w #1, D7 */

tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw-tv;
VWORD(d[7])=(u16)(tr);
goto L4afc;
L4afc: /* sub.w D6, D7 */

tv=((u16)d[6]);
tw=((u16)d[7]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[7])=(u16)(tr);
goto L4afe;
L4afe: /* bcs $4b90 */

if(fc)goto L4b90;
goto L4b02;
L4b02: /* addq.w #1, D7 */

tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw+tv;
VWORD(d[7])=(u16)(tr);
goto L4b04;
L4b04: /* bra $4ade */

goto L4ade;
L4b06: if(vehicle_external(0x4b06ul))return 0;goto L4b90;
L4b90: /* movem.l (A7)+, D0-D7/A0-A6 */

ea=a[7];
d[0]=STACK_READ(ea+0);
d[1]=STACK_READ(ea+4);
d[2]=STACK_READ(ea+8);
d[3]=STACK_READ(ea+12);
d[4]=STACK_READ(ea+16);
d[5]=STACK_READ(ea+20);
d[6]=STACK_READ(ea+24);
d[7]=STACK_READ(ea+28);
a[0]=STACK_READ(ea+32);
a[1]=STACK_READ(ea+36);
a[2]=STACK_READ(ea+40);
a[3]=STACK_READ(ea+44);
a[4]=STACK_READ(ea+48);
a[5]=STACK_READ(ea+52);
a[6]=STACK_READ(ea+56);
a[7]+=60;
goto L4b94;
L4b94: /* bra $4a78 */

goto L4a78;
L4cb2: /* tst.w $8d1e.l */

tv=(*(u16 *)(vehicle_state+0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4cb8;
L4cb8: /* beq $4cbe */

if(fz)goto L4cbe;
goto L4cba;
L4cba: /* bsr $5f5a */

a[7]-=4;STACK_WRITE(a[7],0x4cbeul);
return 0x5f5aul;
L4cbe: /* lea $909f.l, A0 */

a[0]=0x909ful;
goto L4cc4;
L4cc4: /* lea $90e2.l, A1 */

a[1]=0x90e2ul;
goto L4cca;
L4cca: /* move.w #$14, D7 */

tv=((u16)(20L));
VWORD(d[7])=(u16)(tv);

goto L4cce;
L4cce: /* move.w #$38, D0 */

tv=((u16)(56L));
VWORD(d[0])=(u16)(tv);

goto L4cd2;
L4cd2: /* add.b D0, (A0)+ */

tv=((u8)d[0]);
eb=a[0];
tw=ver8(eb);
a[0]+=1;
tr=tw+tv;
vew8(eb,tr);
goto L4cd4;
L4cd4: /* add.b D0, (A1)+ */

tv=((u8)d[0]);
eb=a[1];
tw=ver8(eb);
a[1]+=1;
tr=tw+tv;
vew8(eb,tr);
goto L4cd6;
L4cd6: /* dbra D7, $4cd2 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4cd2;
goto L4cda;
L4cda: /* lea $8116.l, A0 */

a[0]=0x8116ul;
goto L4ce0;
L4ce0: /* lea $90b2.l, A1 */

a[1]=0x90b2ul;
goto L4ce6;
L4ce6: /* lea $8f74.l, A2 */

a[2]=0x8f74ul;
goto L4cec;
L4cec: /* lea $7a20.l, A3 */

a[3]=0x7a20ul;
goto L4cf2;
L4cf2: /* move.w $9078.l, D0 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[0])=(u16)(tv);

goto L4cf8;
L4cf8: /* andi.w #$e0, D0 */

tv=((u16)(224L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L4cfc;
L4cfc: /* lea (A3,D0.w), A3 */

a[3]=(a[3]+((s16)(d[0])));
goto L4d00;
L4d00: /* move.w $9076.l, D6 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[6])=(u16)(tv);

goto L4d06;
L4d06: /* addi.b #$53, D6 */

tv=((u8)(83L));
tw=((u8)d[6]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[6])=(u8)(tr);
goto L4d0a;
L4d0a: /* move.w #$13, D7 */

tv=((u16)(19L));
VWORD(d[7])=(u16)(tv);

goto L4d0e;
L4d0e: /* tst.w $8d1e.l */

tv=(*(u16 *)(vehicle_state+0));
fz=(u8)((tv&0xfffful)==0);
goto L4d14;
L4d14: /* beq $5c88 */

if(fz)return 0x5c88ul;
goto L4d18;
L4d18: /* move.w D7, D5 */

tv=((u16)d[7]);
VWORD(d[5])=(u16)(tv);

goto L4d1a;
L4d1a: /* lsr.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=((u16)tw)>>1;
VWORD(d[5])=(u16)(tr);
goto L4d1c;
L4d1c: /* cmpi.w #$8, D5 */

tv=((u16)(8L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L4d20;
L4d20: /* bcs $4d24 */

if(fc)goto L4d24;
goto L4d22;
L4d22: /* moveq #$8, D5 */

v=((u32)(8L));
d[5]=v;

goto L4d24;
L4d24: /* asl.w #4, D5 */

tv=((u16)(4L));
tw=((u16)d[5]);
tr=tw<<4;fc=(u8)((tw>>12)&1);fx=(u8)((tw>>12)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((((tw<<4)^tw)&0x8000ul)!=0);
VWORD(d[5])=(u16)(tr);
goto L4d26;
L4d26: /* bsr $4a38 */

a[7]-=4;STACK_WRITE(a[7],0x4d2aul);
goto L4a38;
L4d2a:
/* Restore the original depth pass for the translated fallback as well.
   The native scene compositor is the shipped hot path. */
L4d2a_unculled: /* move.b (A2,D6.w), D0 */

ea=(a[2]+((s16)(d[6])));
v=ver8(ea);
VBYTE(d[0])=(u8)(v);
fz=(u8)((v&0xfful)==0);
goto L4d2e;
L4d2e: /* bne $4d56 */

if(!fz)goto L4d56;
goto L4d30;
L4d30: /* addi.b #$20, D6 */

tv=((u8)(32L));
tw=((u8)d[6]);
tr=tw+tv;
VBYTE(d[6])=(u8)(tr);
goto L4d34;
L4d34: /* subq.w #2, A0 */

v=((u16)(2L));
w=((u32)a[0]);
r=w-v;
a[0]=r;
goto L4d36;
L4d36: /* move.b (A2,D6.w), D0 */

ea=(a[2]+((s16)(d[6])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L4d3a;
L4d3a: /* bne $4da8 */

if(!fz)goto L4da8;
goto L4d3c;
L4d3c: /* subi.b #$21, D6 */

tv=((u8)(33L));
tw=((u8)d[6]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[6])=(u8)(tr);
goto L4d40;
L4d40: /* subq.w #2, A0 */

v=((u16)(2L));
w=((u32)a[0]);
r=w-v;
a[0]=r;
goto L4d42;
L4d42: /* subq.w #1, A1 */

v=((u16)(1L));
w=((u32)a[1]);
r=w-v;
a[1]=r;
goto L4d44;
L4d44: /* dbra D7, $4d0e */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4d0e;
goto L4d48;
L4d48: /* tst.w $8d1e.l */

tv=(*(u16 *)(vehicle_state+0));
fz=(u8)((tv&0xfffful)==0);
goto L4d4e;
L4d4e: /* beq $5c9c */

if(fz)return 0x5c9cul;
goto L4d52;
L4d52: /* bra $5f92 */

return 0x5f92ul;
L4d56: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;
VWORD(d[0])=(u16)(tr);
goto L4d58;
L4d58: /* andi.w #$f0, D0 */

tv=((u16)(240L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L4d5c;
L4d5c: /* lea $8bae.l, A4 */

a[4]=0x8baeul;
goto L4d62;
L4d62: /* movea.l (A4,D0.w), A5 */

ea=(a[4]+((s16)(d[0])));
v=ver32(ea);
a[5]=v;
goto L4d66;
L4d66: /* move.b ($4,A4,D0.w), D1 */

ea=(4+a[4]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4d6a;
L4d6a: /* move.b ($5,A4,D0.w), D2 */

ea=(5+a[4]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4d6e;
L4d6e: /* move.b (A3,D7.w), D0 */

ea=(a[3]+((s16)(d[7])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L4d72;
L4d72: /* ext.w D0 */

v=((u32)d[0]);
r=(s16)(s8)v;
VWORD(d[0])=(u16)(r);

goto L4d74;
L4d74: /* ext.w D1 */

v=((u32)d[1]);
r=(s16)(s8)v;
VWORD(d[1])=(u16)(r);

goto L4d76;
L4d76: /* mulu.w D1, D0 */

v=((u16)d[1]);
w=((u32)d[0]);
r=vehicle_mulu16(v,w);

d[0]=r;
goto L4d78;
L4d78: /* ext.w D2 */

v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);
fz=(u8)((r&0xfffful)==0);
goto L4d7a;
L4d7a: /* beq $4d7e */

if(fz)goto L4d7e;
goto L4d7c;
L4d7c: /* divu.w D2, D0 */

v=((u16)d[2]);
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L4d7e;
L4d7e: /* add.w (A0), D0 */

ea=a[0];
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4d80;
L4d80: /* lea (A5,D5.w), A5 */

a[5]=(a[5]+((s16)(d[5])));
goto L4d84;
L4d84: /* move.w (A5)+, D1 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[1])=(u16)(tv);

goto L4d86;
L4d86: /* tst.w D0 */

tv=((u16)d[0]);
fn=(u8)((tv&0x8000ul)!=0);
goto L4d88;
L4d88: /* bmi $4d92 */

if(fn)goto L4d92;
goto L4d8a;
L4d8a: /* cmpi.w #$130, D0 */

tv=((u16)(304L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4d8e;
L4d8e: /* bcs $4d9c */

if(fc)goto L4d9c;
goto L4d90;
L4d90: /* bra $4d30 */

goto L4d30;
L4d92: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4d94;
L4d94: /* bmi $4d30 */

if(fn)goto L4d30;
goto L4d96;
L4d96: /* cmpi.w #-$10, D0 */

tv=((u16)(-16L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4d9a;
L4d9a: /* bcs $4d30 */

if(fc)goto L4d30;
goto L4d9c;
L4d9c: /* movem.l D5-D7/A0-A3, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[3]);
a[7]-=4;
STACK_WRITE(a[7],a[2]);
a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],a[0]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
a[7]-=4;
STACK_WRITE(a[7],d[6]);
a[7]-=4;
STACK_WRITE(a[7],d[5]);
goto L4da0;
L4da0: /* bsr $4e08 */

a[7]-=4;STACK_WRITE(a[7],0x4da2ul);
goto L4e08;
L4da2: /* movem.l (A7)+, D5-D7/A0-A3 */

ea=a[7];
d[5]=STACK_READ(ea+0);
d[6]=STACK_READ(ea+4);
d[7]=STACK_READ(ea+8);
a[0]=STACK_READ(ea+12);
a[1]=STACK_READ(ea+16);
a[2]=STACK_READ(ea+20);
a[3]=STACK_READ(ea+24);
a[7]+=28;
goto L4da6;
L4da6: /* bra $4d30 */

goto L4d30;
L4da8: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;
VWORD(d[0])=(u16)(tr);
goto L4daa;
L4daa: /* andi.w #$f0, D0 */

tv=((u16)(240L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L4dae;
L4dae: /* lea $8c5e.l, A4 */

a[4]=0x8c5eul;
goto L4db4;
L4db4: /* movea.l (A4,D0.w), A5 */

ea=(a[4]+((s16)(d[0])));
v=ver32(ea);
a[5]=v;
goto L4db8;
L4db8: /* move.b ($4,A4,D0.w), D1 */

ea=(4+a[4]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4dbc;
L4dbc: /* move.b ($5,A4,D0.w), D2 */

ea=(5+a[4]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4dc0;
L4dc0: /* move.b (A3,D7.w), D0 */

ea=(a[3]+((s16)(d[7])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L4dc4;
L4dc4: /* ext.w D0 */

v=((u32)d[0]);
r=(s16)(s8)v;
VWORD(d[0])=(u16)(r);

goto L4dc6;
L4dc6: /* ext.w D1 */

v=((u32)d[1]);
r=(s16)(s8)v;
VWORD(d[1])=(u16)(r);

goto L4dc8;
L4dc8: /* mulu.w D1, D0 */

v=((u16)d[1]);
w=((u32)d[0]);
r=vehicle_mulu16(v,w);

d[0]=r;
goto L4dca;
L4dca: /* ext.w D2 */

v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);
fz=(u8)((r&0xfffful)==0);
goto L4dcc;
L4dcc: /* beq $4dd0 */

if(fz)goto L4dd0;
goto L4dce;
L4dce: /* divu.w D2, D0 */

v=((u16)d[2]);
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L4dd0;
L4dd0: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L4dd2;
L4dd2: /* addi.w #$a, D0 */

tv=((u16)(10L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4dd6;
L4dd6: /* add.w (A0), D0 */

ea=a[0];
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4dd8;
L4dd8: /* lea (A5,D5.w), A5 */

a[5]=(a[5]+((s16)(d[5])));
goto L4ddc;
L4ddc: /* move.w (A5)+, D1 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[1])=(u16)(tv);

goto L4dde;
L4dde: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4de0;
L4de0: /* bmi $4dec */

if(fn)goto L4dec;
goto L4de2;
L4de2: /* cmpi.w #$130, D0 */

tv=((u16)(304L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4de6;
L4de6: /* bcs $4dfa */

if(fc)goto L4dfa;
goto L4de8;
L4de8: /* bra $4d3c */

goto L4d3c;
L4dec: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4dee;
L4dee: /* bmi $4d3c */

if(fn)goto L4d3c;
goto L4df2;
L4df2: /* cmpi.w #$0, D1 */

tv=((u16)(0L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4df6;
L4df6: /* bcs $4d3c */

if(fc)goto L4d3c;
goto L4dfa;
L4dfa: /* movem.l D5-D7/A0-A3, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[3]);
a[7]-=4;
STACK_WRITE(a[7],a[2]);
a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],a[0]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
a[7]-=4;
STACK_WRITE(a[7],d[6]);
a[7]-=4;
STACK_WRITE(a[7],d[5]);
goto L4dfe;
L4dfe: /* bsr $4e08 */

a[7]-=4;STACK_WRITE(a[7],0x4e00ul);
goto L4e08;
L4e00: /* movem.l (A7)+, D5-D7/A0-A3 */

ea=a[7];
d[5]=STACK_READ(ea+0);
d[6]=STACK_READ(ea+4);
d[7]=STACK_READ(ea+8);
a[0]=STACK_READ(ea+12);
a[1]=STACK_READ(ea+16);
a[2]=STACK_READ(ea+20);
a[3]=STACK_READ(ea+24);
a[7]+=28;
goto L4e04;
L4e04: /* bra $4d3c */

goto L4d3c;
L4e08:vehicle_native_clip(0x4e08u);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4e08_original: /* moveq #$0, D6 */

v=((u32)(0L));
d[6]=v;

goto L4e0a;
L4e0a: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L4e0c;
L4e0c: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L4e0e;
L4e0e: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L4e10;
L4e10: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L4e12;
L4e12: /* move.w D3, D2 */

tv=((u16)d[3]);
VWORD(d[2])=(u16)(tv);

goto L4e14;
L4e14: /* move.w D3, D1 */

tv=((u16)d[3]);
VWORD(d[1])=(u16)(tv);

goto L4e16;
L4e16: /* move.b (A1), D1 */

ea=a[1];
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L4e18;
L4e18: /* move.b ($43,A1), D2 */

ea=(67+a[1]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4e1c;
L4e1c: /* sub.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw-tv;fz=(u8)((tr&0xfffful)==0);
VWORD(d[1])=(u16)(tr);
goto L4e1e;
L4e1e: /* bne $4e3c */

if(!fz)goto L4e3c;
goto L4e20;
L4e20:vehicle_native_clip(0x4e20u);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4e20_original: /* add.w D6, D2 */

tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4e22;
L4e22: /* bmi $4e3a */

if(fn)goto L4e3a;
goto L4e24;
L4e24: /* move.w D2, D1 */

tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L4e26;
L4e26: /* addq.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4e28;
L4e28: /* sub.w D7, D1 */

tv=((u16)d[7]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L4e2a;
L4e2a: /* bcc $4e5e */

if(!fc)goto L4e5e;
goto L4e2c;
L4e2c: /* add.w D1, D7 */

tv=((u16)d[1]);
tw=((u16)d[7]);
tr=tw+tv;
VWORD(d[7])=(u16)(tr);
goto L4e2e;
L4e2e: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L4e30;
L4e30: /* subq.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4e32;
L4e32: /* add.w D5, D3 */

tv=((u16)d[5]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L4e34;
L4e34: /* dbra D1, $4e32 */

VWORD(d[1])=(u16)(d[1]-1);
if((u16)d[1]!=65535u)goto L4e32;
goto L4e38;
L4e38: /* bra $4e5e */

goto L4e5e;
L4e3a: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4e3c: /* tst.w D6 */

tv=((u16)d[6]);
fn=(u8)((tv&0x8000ul)!=0);
goto L4e3e;
L4e3e: /* bmi $4e44 */

if(fn)goto L4e44;
goto L4e40;
L4e40: /* sub.w D6, D1 */

tv=((u16)d[6]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4e42;
L4e42: /* bra $4e46 */

goto L4e46;
L4e44: /* add.w D6, D1 */

tv=((u16)d[6]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4e46;
L4e46: /* move.w D1, D6 */

tv=((u16)d[1]);
VWORD(d[6])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L4e48;
L4e48: /* beq $4e20 */

if(fz)goto L4e20;
goto L4e4a;
L4e4a: /* bmi $4e20 */

if(fn)goto L4e20;
goto L4e4c;
L4e4c: /* subq.w #1, D7 */

tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw-tv;
VWORD(d[7])=(u16)(tr);
goto L4e4e;
L4e4e: /* sub.w D6, D7 */

tv=((u16)d[6]);
tw=((u16)d[7]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[7])=(u16)(tr);
goto L4e50;
L4e50: /* bcs $4e3a */

if(fc)goto L4e3a;
goto L4e52;
L4e52: /* addq.w #1, D7 */

tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw+tv;
VWORD(d[7])=(u16)(tr);
goto L4e54;
L4e54: /* bra $4e24 */

goto L4e24;
L4e56:vehicle_native_clip(0x4e56u);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4e56_original: /* lea $4fcc.l, A6 */

a[6]=0x4fccul;
goto L4e5c;
L4e5c: /* bra $4e64 */

goto L4e64;
L4e5e:vehicle_native_clip(0x4e5eu);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4e5e_original: /* lea $4ec0.l, A6 */

a[6]=0x4ec0ul;
goto L4e64;
L4e64:vehicle_native_clip(0x4e64u);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4e64_original: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L4e66;
L4e66: /* asr.w #4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=((s16)tw)>>4;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4e68;
L4e68: /* bmi $4e86 */

if(fn)goto L4e86;
goto L4e6a;
L4e6a: /* cmpi.w #$0, D1 */

tv=((u16)(0L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L4e6e;
L4e6e: /* bcs $4e86 */

if(fc)goto L4e86;
goto L4e70;
L4e70: /* moveq #$0, D6 */

v=((u32)(0L));
d[6]=v;

goto L4e72;
L4e72: /* add.w D4, D1 */

tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4e74;
L4e74: /* subi.w #$14, D1 */

tv=((u16)(20L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L4e78;
L4e78: /* bcs $4e82 */

if(fc)goto L4e82;
goto L4e7a;
L4e7a: /* sub.w D4, D1 */

tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4e7c;
L4e7c: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L4e7e;
L4e7e: /* not.w D6 */

tv=((u16)d[6]);
tr=~tv;
VWORD(d[6])=(u16)(tr);

goto L4e80;
L4e80: /* bra $4e9a */

goto L4e9a;
L4e82: /* move.w D4, D1 */

tv=((u16)d[4]);
VWORD(d[1])=(u16)(tv);

goto L4e84;
L4e84: /* bra $4e9a */

goto L4e9a;
L4e86: /* add.w D4, D1 */

tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4e88;
L4e88: /* subi.w #$0, D1 */

tv=((u16)(0L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4e8c;
L4e8c: /* move.w D1, D6 */

tv=((u16)d[1]);
VWORD(d[6])=(u16)(tv);

goto L4e8e;
L4e8e: /* neg.w D6 */

tv=((u16)d[6]);
tr=0-tv;
VWORD(d[6])=(u16)(tr);
goto L4e90;
L4e90: /* add.w D4, D6 */

tv=((u16)d[4]);
tw=((u16)d[6]);
tr=tw+tv;
VWORD(d[6])=(u16)(tr);
goto L4e92;
L4e92: /* andi.w #$f, D0 */

tv=((u16)(15L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L4e96;
L4e96: /* ori.w #$0, D0 */

tv=((u16)(0L));
tw=((u16)d[0]);
tr=tw|tv;

VWORD(d[0])=(u16)(tr);
goto L4e9a;
L4e9a: /* movea.l $37c4.l, A0 */

v=(((u32)*(u16 *)(vehicle_io+196)<<16)|*(u16 *)(vehicle_io+198));
a[0]=v;
goto L4ea0;
L4ea0: /* addq.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4ea2;
L4ea2: /* sub.w D7, D2 */

tv=((u16)d[7]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4ea4;
L4ea4: /* move.w D2, D4 */

tv=((u16)d[2]);
VWORD(d[4])=(u16)(tv);

goto L4ea6;
L4ea6: /* lsl.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw<<2;
VWORD(d[2])=(u16)(tr);
goto L4ea8;
L4ea8: /* add.w D4, D2 */

tv=((u16)d[4]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4eaa;
L4eaa: /* lsl.w #3, D2 */

tv=((u16)(3L));
tw=((u16)d[2]);
tr=tw<<3;
VWORD(d[2])=(u16)(tr);
goto L4eac;
L4eac: /* move.w D0, D4 */

tv=((u16)d[0]);
VWORD(d[4])=(u16)(tv);

goto L4eae;
L4eae: /* lsr.w #3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=((u16)tw)>>3;
VWORD(d[0])=(u16)(tr);
goto L4eb0;
L4eb0: /* bclr #$0, D0 */

v=((u16)(0L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[0]=r;
goto L4eb4;
L4eb4: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4eb6;
L4eb6: /* lea (A0,D0.w), A0 */

a[0]=(a[0]+((s16)(d[0])));
goto L4eba;
L4eba: /* andi.w #$f, D4 */

tv=((u16)(15L));
tw=((u16)d[4]);
tr=tw&tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
VWORD(d[4])=(u16)(tr);
goto L4ebe;
L4ebe: /* jmp (A6) */

pc=a[6];goto dispatch;
L4ec0: if(vehicle_external(0x4ec0ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L4fcc: if(vehicle_external(0x4fccul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
}
static u32 part1(u32 pc){u32 v,w,r,ea,eb,stkp,stkv; u16 tv,tw,tr;s32 signed_result;
dispatch: if(!pc)return 0;if(pc<0x5000ul||pc>=0x6300ul)return pc;
VD: if(pc<0x5e0cul)goto VDL;goto VDR;
VDL: if(pc<0x5c1eul)goto VDLL;goto VDLR;
VDLL: if(pc<0x56f8ul)goto VDLLL;goto VDLLR;
VDLLL: if(pc<0x51daul)goto VDLLLL;goto VDLLLR;
VDLLLL: if(pc<0x51d0ul)goto VDLLLLL;goto VDLLLLR;
VDLLLLL: if(pc==0x5086ul)goto L5086;vm_fault=pc;return 0;
VDLLLLR: if(pc==0x51d0ul)goto L51d0;vm_fault=pc;return 0;
VDLLLR: if(pc<0x524eul)goto VDLLLRL;goto VDLLLRR;
VDLLLRL: if(pc==0x51daul)goto L51da;vm_fault=pc;return 0;
VDLLLRR: if(pc<0x546cul)goto VDLLLRRL;goto VDLLLRRR;
VDLLLRRL: if(pc==0x524eul)goto L524e;vm_fault=pc;return 0;
VDLLLRRR: if(pc==0x546cul)goto L546c;vm_fault=pc;return 0;
VDLLR: if(pc<0x57bcul)goto VDLLRL;goto VDLLRR;
VDLLRL: if(pc<0x571cul)goto VDLLRLL;goto VDLLRLR;
VDLLRLL: if(pc==0x56f8ul)goto L56f8;vm_fault=pc;return 0;
VDLLRLR: if(pc<0x5764ul)goto VDLLRLRL;goto VDLLRLRR;
VDLLRLRL: if(pc==0x571cul)goto L571c;vm_fault=pc;return 0;
VDLLRLRR: if(pc==0x5764ul)goto L5764;vm_fault=pc;return 0;
VDLLRR: if(pc<0x57d0ul)goto VDLLRRL;goto VDLLRRR;
VDLLRRL: if(pc==0x57bcul)goto L57bc;vm_fault=pc;return 0;
VDLLRRR: if(pc<0x5910ul)goto VDLLRRRL;goto VDLLRRRR;
VDLLRRRL: if(pc==0x57d0ul)goto L57d0;vm_fault=pc;return 0;
VDLLRRRR: if(pc==0x5910ul)goto L5910;vm_fault=pc;return 0;
VDLR: if(pc<0x5cd8ul)goto VDLRL;goto VDLRR;
VDLRL: if(pc<0x5c94ul)goto VDLRLL;goto VDLRLR;
VDLRLL: if(pc<0x5c88ul)goto VDLRLLL;goto VDLRLLR;
VDLRLLL: if(pc==0x5c1eul)goto L5c1e;vm_fault=pc;return 0;
VDLRLLR: if(pc==0x5c88ul)goto L5c88;vm_fault=pc;return 0;
VDLRLR: if(pc<0x5c9cul)goto VDLRLRL;goto VDLRLRR;
VDLRLRL: if(pc==0x5c94ul)goto L5c94;vm_fault=pc;return 0;
VDLRLRR: if(pc<0x5cd4ul)goto VDLRLRRL;goto VDLRLRRR;
VDLRLRRL: if(pc==0x5c9cul)goto L5c9c;vm_fault=pc;return 0;
VDLRLRRR: if(pc==0x5cd4ul)goto L5cd4;vm_fault=pc;return 0;
VDLRR: if(pc<0x5d68ul)goto VDLRRL;goto VDLRRR;
VDLRRL: if(pc<0x5d0eul)goto VDLRRLL;goto VDLRRLR;
VDLRRLL: if(pc==0x5cd8ul)goto L5cd8;vm_fault=pc;return 0;
VDLRRLR: if(pc<0x5d32ul)goto VDLRRLRL;goto VDLRRLRR;
VDLRRLRL: if(pc==0x5d0eul)goto L5d0e;vm_fault=pc;return 0;
VDLRRLRR: if(pc==0x5d32ul)goto L5d32;vm_fault=pc;return 0;
VDLRRR: if(pc<0x5dc4ul)goto VDLRRRL;goto VDLRRRR;
VDLRRRL: if(pc==0x5d68ul)goto L5d68;vm_fault=pc;return 0;
VDLRRRR: if(pc<0x5dd8ul)goto VDLRRRRL;goto VDLRRRRR;
VDLRRRRL: if(pc==0x5dc4ul)goto L5dc4;vm_fault=pc;return 0;
VDLRRRRR: if(pc==0x5dd8ul)goto L5dd8;vm_fault=pc;return 0;
VDR: if(pc<0x607aul)goto VDRL;goto VDRR;
VDRL: if(pc<0x5f46ul)goto VDRLL;goto VDRLR;
VDRLL: if(pc<0x5e82ul)goto VDRLLL;goto VDRLLR;
VDRLLL: if(pc<0x5e48ul)goto VDRLLLL;goto VDRLLLR;
VDRLLLL: if(pc==0x5e0cul)goto L5e0c;vm_fault=pc;return 0;
VDRLLLR: if(pc==0x5e48ul)goto L5e48;vm_fault=pc;return 0;
VDRLLR: if(pc<0x5ef8ul)goto VDRLLRL;goto VDRLLRR;
VDRLLRL: if(pc==0x5e82ul)goto L5e82;vm_fault=pc;return 0;
VDRLLRR: if(pc<0x5f20ul)goto VDRLLRRL;goto VDRLLRRR;
VDRLLRRL: if(pc==0x5ef8ul)goto L5ef8;vm_fault=pc;return 0;
VDRLLRRR: if(pc==0x5f20ul)goto L5f20;vm_fault=pc;return 0;
VDRLR: if(pc<0x5fecul)goto VDRLRL;goto VDRLRR;
VDRLRL: if(pc<0x5f5aul)goto VDRLRLL;goto VDRLRLR;
VDRLRLL: if(pc==0x5f46ul)goto L5f46;vm_fault=pc;return 0;
VDRLRLR: if(pc<0x5f92ul)goto VDRLRLRL;goto VDRLRLRR;
VDRLRLRL: if(pc==0x5f5aul)goto L5f5a;vm_fault=pc;return 0;
VDRLRLRR: if(pc==0x5f92ul)goto L5f92;vm_fault=pc;return 0;
VDRLRR: if(pc<0x6034ul)goto VDRLRRL;goto VDRLRRR;
VDRLRRL: if(pc==0x5fecul)goto L5fec;vm_fault=pc;return 0;
VDRLRRR: if(pc<0x6058ul)goto VDRLRRRL;goto VDRLRRRR;
VDRLRRRL: if(pc==0x6034ul)goto L6034;vm_fault=pc;return 0;
VDRLRRRR: if(pc==0x6058ul)goto L6058;vm_fault=pc;return 0;
VDRR: if(pc<0x6148ul)goto VDRRL;goto VDRRR;
VDRRL: if(pc<0x60d8ul)goto VDRRLL;goto VDRRLR;
VDRRLL: if(pc<0x609cul)goto VDRRLLL;goto VDRRLLR;
VDRRLLL: if(pc==0x607aul)goto L607a;vm_fault=pc;return 0;
VDRRLLR: if(pc<0x60beul)goto VDRRLLRL;goto VDRRLLRR;
VDRRLLRL: if(pc==0x609cul)goto L609c;vm_fault=pc;return 0;
VDRRLLRR: if(pc==0x60beul)goto L60be;vm_fault=pc;return 0;
VDRRLR: if(pc<0x6106ul)goto VDRRLRL;goto VDRRLRR;
VDRRLRL: if(pc==0x60d8ul)goto L60d8;vm_fault=pc;return 0;
VDRRLRR: if(pc<0x6132ul)goto VDRRLRRL;goto VDRRLRRR;
VDRRLRRL: if(pc==0x6106ul)goto L6106;vm_fault=pc;return 0;
VDRRLRRR: if(pc==0x6132ul)goto L6132;vm_fault=pc;return 0;
VDRRR: if(pc<0x61b2ul)goto VDRRRL;goto VDRRRR;
VDRRRL: if(pc<0x616eul)goto VDRRRLL;goto VDRRRLR;
VDRRRLL: if(pc==0x6148ul)goto L6148;vm_fault=pc;return 0;
VDRRRLR: if(pc<0x617eul)goto VDRRRLRL;goto VDRRRLRR;
VDRRRLRL: if(pc==0x616eul)goto L616e;vm_fault=pc;return 0;
VDRRRLRR: if(pc==0x617eul)goto L617e;vm_fault=pc;return 0;
VDRRRR: if(pc<0x61d0ul)goto VDRRRRL;goto VDRRRRR;
VDRRRRL: if(pc==0x61b2ul)goto L61b2;vm_fault=pc;return 0;
VDRRRRR: if(pc<0x61f4ul)goto VDRRRRRL;goto VDRRRRRR;
VDRRRRRL: if(pc==0x61d0ul)goto L61d0;vm_fault=pc;return 0;
VDRRRRRR: if(pc==0x61f4ul)goto L61f4;vm_fault=pc;return 0;
L5086: /* lea $80c8.l, A0 */

a[0]=0x80c8ul;
goto L508c;
L508c: /* lea $8d5c.l, A1 */

a[1]=0x8d5cul;
goto L5092;
L5092: /* tst.w ($3a,A1) */

ea=(58+a[1]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5096;
L5096: /* bne $51d8 */

if(!fz)goto L51d8;
goto L509a;
L509a: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L509c;
L509c: /* move.w (A0)+, D0 */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L509e;
L509e: /* bmi $50c2 */

if(fn)goto L50c2;
goto L50a0;
L50a0: /* move.w ($2e,A1), D3 */

ea=(46+a[1]);
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L50a4;
L50a4: /* addq.w #5, D3 */

tv=((u16)(5L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L50a6;
L50a6: /* cmp.w D3, D0 */

tv=((u16)d[3]);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L50a8;
L50a8: /* bcs $50c2 */

if(fc)goto L50c2;
goto L50aa;
L50aa: /* moveq #$0, D6 */

v=((u32)(0L));
d[6]=v;

goto L50ac;
L50ac: /* moveq #$60, D2 */

v=((u32)(96L));
d[2]=v;

goto L50ae;
L50ae: /* lea $8c5e.l, A3 */

a[3]=0x8c5eul;
goto L50b4;
L50b4: /* moveq #$1, D1 */

v=((u32)(1L));
d[1]=v;

goto L50b6;
L50b6: /* addi.w #$37, D3 */

tv=((u16)(55L));
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[3])=(u16)(tr);
goto L50ba;
L50ba: /* cmp.w D3, D0 */

tv=((u16)d[3]);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L50bc;
L50bc: /* bcs $50e4 */

if(fc)goto L50e4;
goto L50be;
L50be: /* moveq #$2, D1 */

v=((u32)(2L));
d[1]=v;

goto L50c0;
L50c0: /* bra $50e4 */

goto L50e4;
L50c2: /* move.w (A0)+, D0 */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
VWORD(d[0])=(u16)(tv);

goto L50c4;
L50c4: /* move.w ($30,A1), D3 */

ea=(48+a[1]);
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L50c8;
L50c8: /* subq.w #5, D3 */

tv=((u16)(5L));
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L50ca;
L50ca: /* cmp.w D3, D0 */

tv=((u16)d[3]);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L50cc;
L50cc: /* bcc $50e4 */

if(!fc)goto L50e4;
goto L50ce;
L50ce: /* moveq #-$1, D6 */

v=((u32)(-1L));
d[6]=v;

goto L50d0;
L50d0: /* moveq #$40, D2 */

v=((u32)(64L));
d[2]=v;

goto L50d2;
L50d2: /* lea $8bae.l, A3 */

a[3]=0x8baeul;
goto L50d8;
L50d8: /* moveq #$1, D1 */

v=((u32)(1L));
d[1]=v;

goto L50da;
L50da: /* subi.w #$37, D3 */

tv=((u16)(55L));
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L50de;
L50de: /* cmp.w D3, D0 */

tv=((u16)d[3]);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L50e0;
L50e0: /* bcc $50e4 */

if(!fc)goto L50e4;
goto L50e2;
L50e2: /* moveq #$2, D1 */

v=((u32)(2L));
d[1]=v;

goto L50e4;
L50e4: /* move.w D1, $8f62.l */

tv=((u16)d[1]);
*(u16 *)(vehicle_state+580)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L50ea;
L50ea: /* beq $51d8 */

if(fz)goto L51d8;
goto L50ee;
L50ee: /* lea $7a20.l, A2 */

a[2]=0x7a20ul;
goto L50f4;
L50f4: /* move.w $9078.l, D3 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[3])=(u16)(tv);

goto L50fa;
L50fa: /* andi.w #$e0, D3 */

tv=((u16)(224L));
tw=((u16)d[3]);
tr=tw&tv;

VWORD(d[3])=(u16)(tr);
goto L50fe;
L50fe: /* lea (A2,D3.w), A2 */

a[2]=(a[2]+((s16)(d[3])));
goto L5102;
L5102: /* lea $909f.l, A4 */

a[4]=0x909ful;
goto L5108;
L5108: /* lea $8f74.l, A5 */

a[5]=0x8f74ul;
goto L510e;
L510e: /* add.b $9077.l, D2 */

tv=vehicle_state[856];
tw=((u8)d[2]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[2])=(u8)(tr);
goto L5114;
L5114: /* move.b (A5,D2.w), D1 */

ea=(a[5]+((s16)(d[2])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L5118;
L5118: /* bne $512a */

if(!fz)goto L512a;
goto L511a;
L511a: /* move.b ($1,A5,D2.w), D1 */

ea=(1+a[5]+((s16)(d[2])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L511e;
L511e: /* beq $51d8 */

if(fz)goto L51d8;
goto L5122;
L5122: /* move.w ($2,A0), D0 */

ea=(2+a[0]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5126;
L5126: /* addq.l #1, A2 */

v=((u32)(1L));
w=((u32)a[2]);
r=w+v;
a[2]=r;
goto L5128;
L5128: /* addq.l #1, A4 */

v=((u32)(1L));
w=((u32)a[4]);
r=w+v;
a[4]=r;
goto L512a;
L512a: /* lsl.w #4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw<<4;
VWORD(d[1])=(u16)(tr);
goto L512c;
L512c: /* lea (A3,D1.w), A3 */

a[3]=(a[3]+((s16)(d[1])));
goto L5130;
L5130: /* move.b ($4,A3), D2 */

ea=(4+a[3]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L5134;
L5134: /* move.b ($5,A3), D3 */

ea=(5+a[3]);
tv=ver8(ea);
VBYTE(d[3])=(u8)(tv);

goto L5138;
L5138: /* move.b (A2), D1 */

ea=a[2];
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L513a;
L513a: /* ext.w D2 */

v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);

goto L513c;
L513c: /* ext.w D1 */

v=((u32)d[1]);
r=(s16)(s8)v;
VWORD(d[1])=(u16)(r);

goto L513e;
L513e: /* mulu.w D2, D1 */

v=((u16)d[2]);
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L5140;
L5140: /* ext.w D3 */

v=((u32)d[3]);
r=(s16)(s8)v;
VWORD(d[3])=(u16)(r);
fz=(u8)((r&0xfffful)==0);
goto L5142;
L5142: /* beq $5146 */

if(fz)goto L5146;
goto L5144;
L5144: /* divu.w D3, D1 */

v=((u16)d[3]);
w=((u32)d[1]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[1]=r;
goto L5146;
L5146: /* tst.w D6 */

tv=((u16)d[6]);
fn=(u8)((tv&0x8000ul)!=0);
goto L5148;
L5148: /* bmi $5154 */

if(fn)goto L5154;
goto L514a;
L514a: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L514c;
L514c: /* addi.w #$a, D1 */

tv=((u16)(10L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5150;
L5150: /* sub.w ($c,A3), D0 */

ea=(12+a[3]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5154;
L5154: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5156;
L5156: /* add.w ($6,A3), D0 */

ea=(6+a[3]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L515a;
L515a: /* move.b (A4), D2 */

ea=a[4];
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L515c;
L515c: /* andi.w #$ff, D2 */

tv=((u16)(255L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5160;
L5160: /* addi.w #$38, D2 */

tv=((u16)(56L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5164;
L5164: /* move.w ($10,A1), D3 */

ea=(16+a[1]);
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L5168;
L5168: /* add.w ($2c,A1), D3 */

ea=(44+a[1]);
tv=ver16(ea);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L516c;
L516c: /* move.w D3, D4 */

tv=((u16)d[3]);
VWORD(d[4])=(u16)(tv);

goto L516e;
L516e: /* sub.w ($2a,A1), D4 */

ea=(42+a[1]);
tv=ver16(ea);
tw=((u16)d[4]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[4])=(u16)(tr);
goto L5172;
L5172: /* cmp.w D4, D2 */

tv=((u16)d[4]);
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5174;
L5174: /* bcs $51d8 */

if(fc)goto L51d8;
goto L5176;
L5176: /* sub.w ($a,A3), D2 */

ea=(10+a[3]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L517a;
L517a: /* bmi $5180 */

if(fn)goto L5180;
goto L517c;
L517c: /* cmp.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L517e;
L517e: /* bcc $51d8 */

if(!fc)goto L51d8;
goto L5180;
L5180: /* moveq #$1, D1 */

v=((u32)(1L));
d[1]=v;

goto L5182;
L5182: /* cmp.w ($30,A1), D0 */

ea=(48+a[1]);
tv=ver16(ea);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5186;
L5186: /* bcc $51d8 */

if(!fc)goto L51d8;
goto L5188;
L5188: /* add.w ($8,A3), D0 */

ea=(8+a[3]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L518c;
L518c: /* cmp.w ($2e,A1), D0 */

ea=(46+a[1]);
tv=ver16(ea);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5190;
L5190: /* bcs $51d8 */

if(fc)goto L51d8;
goto L5192;
L5192: /* cmpi.w #$a0, D0 */

tv=((u16)(160L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5196;
L5196: /* bcs $519a */

if(fc)goto L519a;
goto L5198;
L5198: /* addq.b #1, D1 */

tv=((u8)(1L));
tw=((u8)d[1]);
tr=tw+tv;
VBYTE(d[1])=(u8)(tr);
goto L519a;
L519a: /* move.w #$4, ($3a,A1) */

tv=((u16)(4L));
ea=(58+a[1]);
vew16(ea,tv);

goto L51a0;
L51a0: /* move.w D6, ($38,A1) */

tv=((u16)d[6]);
ea=(56+a[1]);
vew16(ea,tv);

goto L51a4;
L51a4: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L51aa;
L51aa: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L51ac;
L51ac: /* divu.w #$7, D0 */

v=((u16)(7L));
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L51b0;
L51b0: /* addi.w #$8, D0 */

tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L51b4;
L51b4: /* move.w D0, ($36,A1) */

tv=((u16)d[0]);
ea=(54+a[1]);
vew16(ea,tv);

goto L51b8;
L51b8: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L51be;
L51be: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L51c0;
L51c0: /* divu.w #$3, D0 */

v=((u16)(3L));
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L51c4;
L51c4: /* move.w D0, $8f6e.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L51ca;
L51ca: /* moveq #$c, D0 */

v=((u32)(12L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L51cc;
L51cc: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x51d0ul);
return 0x3c92ul;
L51d0: /* moveq #$3, D0 */

v=((u32)(3L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L51d2;
L51d2: /* jmp $7c870.l */

return 0x7c870ul;
L51d8: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L51da: /* lea $90f9.l, A0 */
vehicle_native_boundaries();goto L5214;

a[0]=0x90f9ul;
goto L51e0;
L51e0: /* movea.l A0, A1 */

v=((u32)a[0]);
a[1]=v;
goto L51e2;
L51e2: /* move.w #$14, D7 */

tv=((u16)(20L));
VWORD(d[7])=(u16)(tv);

goto L51e6;
L51e6: /* move.w D7, D6 */

tv=((u16)d[7]);
VWORD(d[6])=(u16)(tv);

goto L51e8;
L51e8: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L51ea;
L51ea: /* add.b (A0), D0 */

ea=a[0];
tv=ver8(ea);
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L51ec;
L51ec: /* move.b D0, (A0)+ */

tv=((u8)d[0]);
ea=a[0];
vew8(ea,tv);
a[0]+=1;

goto L51ee;
L51ee: /* dbra D7, $51ea */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L51ea;
goto L51f2;
L51f2: /* lea $80c8.l, A0 */

a[0]=0x80c8ul;
goto L51f8;
L51f8: /* lea $7bc8.l, A2 */

a[2]=0x7bc8ul;
goto L51fe;
L51fe: /* lea $7fc8.l, A3 */

a[3]=0x7fc8ul;
goto L5204;
L5204: /* move.b (A1)+, D0 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[0])=(u8)(tv);

goto L5206;
L5206: /* lsl.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw<<1;fx=(u8)((tw>>15)&1);
VWORD(d[0])=(u16)(tr);
goto L5208;
L5208: /* move.w (A2,D0.w), (A0)+ */

ea=(a[2]+((s16)(d[0])));
tv=ver16(ea);
ea=a[0];
vew16(ea,tv);
a[0]+=2;

goto L520c;
L520c: /* move.w (A3,D0.w), (A0)+ */

ea=(a[3]+((s16)(d[0])));
tv=ver16(ea);
ea=a[0];
vew16(ea,tv);
a[0]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5210;
L5210: /* dbra D6, $5204 */

VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L5204;
goto L5214;
L5214: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L524e: if(vehicle_external(0x524eul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5406: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L540c;
L540c: /* move.w ($3c,A6), D0 */

ea=(60+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5410;
L5410: /* bne $5414 */

if(!fz)goto L5414;
goto L5412;
L5412: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5414: /* cmpi.w #$3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5418;
L5418: /* beq $5412 */

if(fz)goto L5412;
goto L541a;
L541a: /* lea $974e.l, A5 */

a[5]=0x974eul;
goto L5420;
L5420: /* move.w ($54,A6), D0 */

ea=(84+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5424;
L5424: /* add.w ($4e,A6), D0 */

ea=(78+a[6]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5428;
L5428: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;fx=(u8)((tw>>12)&1);
VWORD(d[0])=(u16)(tr);
goto L542a;
L542a: /* lea ($2,A5,D0.w), A5 */

a[5]=(2+a[5]+((s16)(d[0])));
goto L542e;
L542e: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L5430;
L5430: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L5432;
L5432: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L5434;
L5434: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L5436;
L5436: /* move.w ($4a,A6), D0 */

ea=(74+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L543a;
L543a: /* move.w ($4c,A6), D2 */

ea=(76+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L543e;
L543e: /* cmpi.w #$140, D0 */

tv=((u16)(320L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5442;
L5442: /* bcc $5412 */

if(!fc)goto L5412;
goto L5444;
L5444: /* addq.w #6, D2 */

tv=((u16)(6L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5446;
L5446: /* subq.w #6, D0 */

tv=((u16)(6L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5448;
L5448: /* bra $4e5e */

return 0x4e5eul;
L544c: /* move.w ($3c,A6), D0 */

ea=(60+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5450;
L5450: /* bne $54ba */

if(!fz)goto L54ba;
goto L5452;
L5452: /* tst.b $3708.l */

tv=vehicle_io[9];
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5458;
L5458: /* bne $545c */

if(!fz)goto L545c;
goto L545a;
L545a: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L545c: /* cmpi.w #$50, $8f6e.l */

tv=((u16)(80L));
tw=(*(u16 *)(vehicle_state+592));
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5464;
L5464: /* bcs $545a */

if(fc)goto L545a;
goto L5466;
L5466: /* moveq #$a, D0 */

v=((u32)(10L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5468;
L5468: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x546cul);
return 0x3c92ul;
L546c: /* move.w #$1, ($3c,A6) */

tv=((u16)(1L));
ea=(60+a[6]);
vew16(ea,tv);

goto L5472;
L5472: /* move.w #$e, ($44,A6) */

tv=((u16)(14L));
ea=(68+a[6]);
vew16(ea,tv);

goto L5478;
L5478: /* move.w #$7f, ($4c,A6) */

tv=((u16)(127L));
ea=(76+a[6]);
vew16(ea,tv);

goto L547e;
L547e: /* move.w #$7f, ($42,A6) */

tv=((u16)(127L));
ea=(66+a[6]);
vew16(ea,tv);

goto L5484;
L5484: /* move.l #$5216, ($46,A6) */

v=((u32)(21014L));
ea=(70+a[6]);
vew32(ea,v);

goto L548c;
L548c: /* move.w #$7e, D0 */

tv=((u16)(126L));
VWORD(d[0])=(u16)(tv);

goto L5490;
L5490: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5492;
L5492: /* btst #$2, D5 */

v=((u16)(2L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5496;
L5496: /* bne $54ae */

if(!fz)goto L54ae;
goto L5498;
L5498: /* btst #$3, D5 */

v=((u16)(3L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L549c;
L549c: /* bne $54a8 */

if(!fz)goto L54a8;
goto L549e;
L549e: /* cmpi.w #$16d, $9074.l */

tv=((u16)(365L));
tw=(*(u16 *)(vehicle_state+854));
fc=(u8)((u16)tw<(u16)tv);
goto L54a6;
L54a6: /* bcc $54ae */

if(!fc)goto L54ae;
goto L54a8;
L54a8: /* move.w #$c0, D0 */

tv=((u16)(192L));
VWORD(d[0])=(u16)(tv);

goto L54ac;
L54ac: /* moveq #$2, D1 */

v=((u32)(2L));
d[1]=v;

goto L54ae;
L54ae: /* move.w D0, ($4a,A6) */

tv=((u16)d[0]);
ea=(74+a[6]);
vew16(ea,tv);

goto L54b2;
L54b2: /* move.w D0, ($40,A6) */

tv=((u16)d[0]);
ea=(64+a[6]);
vew16(ea,tv);

goto L54b6;
L54b6: /* move.w D1, ($4e,A6) */

tv=((u16)d[1]);
ea=(78+a[6]);
vew16(ea,tv);

goto L54ba;
L54ba: /* cmpi.w #$2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto L54be;
L54be: /* beq $5608 */

if(fz)goto L5608;
goto L54c2;
L54c2: /* cmpi.w #$3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto L54c6;
L54c6: /* beq $56c0 */

if(fz)goto L56c0;
goto L54ca;
L54ca: /* subq.w #1, ($44,A6) */

tv=((u16)(1L));
eb=(68+a[6]);
tw=ver16(eb);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
vew16(eb,tr);
goto L54ce;
L54ce: /* bpl $54da */

if(!fn)goto L54da;
goto L54d0;
L54d0: /* move.w #$0, ($3c,A6) */

tv=((u16)(0L));
ea=(60+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L54d6;
L54d6: /* bra $5572 */

goto L5572;
L54da: /* movea.l ($46,A6), A0 */

ea=(70+a[6]);
v=ver32(ea);
a[0]=v;
goto L54de;
L54de: /* move.w (A0)+, D0 */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
VWORD(d[0])=(u16)(tv);

goto L54e0;
L54e0: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L54e4;
L54e4: /* beq $54e8 */

if(fz)goto L54e8;
goto L54e6;
L54e6: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L54e8;
L54e8: /* add.w D0, ($4a,A6) */

tv=((u16)d[0]);
eb=(74+a[6]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L54ec;
L54ec: /* move.w (A0)+, ($54,A6) */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
ea=(84+a[6]);
vew16(ea,tv);

goto L54f0;
L54f0: /* move.l A0, ($46,A6) */

v=((u32)a[0]);
ea=(70+a[6]);
vew32(ea,v);

goto L54f4;
L54f4: /* lea $8f74.l, A0 */

a[0]=0x8f74ul;
goto L54fa;
L54fa: /* move.w $9076.l, D0 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[0])=(u16)(tv);

goto L5500;
L5500: /* moveq #$0, D6 */

v=((u32)(0L));
d[6]=v;

goto L5502;
L5502: /* addi.b #$40, D0 */

tv=((u8)(64L));
tw=((u8)d[0]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);fx=(u8)((tr&~0xfful)!=0);fn=(u8)((tr&0x80ul)!=0);fz=(u8)((tr&0xfful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x80ul)!=0);
VBYTE(d[0])=(u8)(tr);
goto L5506;
L5506: /* move.w $7ff2.l, D1 */

tv=(*(u16 *)(vehicle_projection+1066));
VWORD(d[1])=(u16)(tv);

goto L550c;
L550c: /* addi.w #$24, D1 */

tv=((u16)(36L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L5510;
L5510: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5514;
L5514: /* bne $5524 */

if(!fz)goto L5524;
goto L5516;
L5516: /* addi.b #$20, D0 */

tv=((u8)(32L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L551a;
L551a: /* move.w $7bf2.l, D1 */

tv=(*(u16 *)(vehicle_projection+42));
VWORD(d[1])=(u16)(tv);

goto L5520;
L5520: /* subi.w #$24, D1 */

tv=((u16)(36L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L5524;
L5524: /* cmpi.b #$1, (A0,D0.w) */

tv=((u8)(1L));
eb=(a[0]+((s16)(d[0])));
tw=ver8(eb);
fz=(u8)((u8)tw==(u8)tv);
goto L552a;
L552a: /* beq $5552 */

if(fz)goto L5552;
goto L552c;
L552c: /* tst.b $8f6e.l */

tv=vehicle_state[593];
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5532;
L5532: /* beq $5572 */

if(fz)goto L5572;
goto L5534;
L5534: /* move.b $8f6f.l, D2 */

tv=vehicle_state[592];
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);
goto L553a;
L553a: /* bmi $5544 */

if(fn)goto L5544;
goto L553c;
L553c: /* cmp.b $9079.l, D2 */

tv=vehicle_state[858];
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5542;
L5542: /* bcc $5572 */

if(!fc)goto L5572;
goto L5544;
L5544: /* addi.b #$1, D0 */

tv=((u8)(1L));
tw=((u8)d[0]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[0])=(u8)(tr);
goto L5548;
L5548: /* cmpi.b #$1, (A0,D0.w) */

tv=((u8)(1L));
eb=(a[0]+((s16)(d[0])));
tw=ver8(eb);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L554e;
L554e: /* bne $5572 */

if(!fz)goto L5572;
goto L5550;
L5550: /* moveq #$1, D6 */

v=((u32)(1L));
d[6]=v;

goto L5552;
L5552: /* tst.w D1 */

tv=((u16)d[1]);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5554;
L5554: /* bmi $5572 */

if(fn)goto L5572;
goto L5558;
L5558: /* move.w D1, D2 */

tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L555a;
L555a: /* sub.w ($40,A6), D2 */

ea=(64+a[6]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[2])=(u16)(tr);
goto L555e;
L555e: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5562;
L5562: /* bne $5574 */

if(!fz)goto L5574;
goto L5564;
L5564: /* cmpi.w #$65, D1 */

tv=((u16)(101L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5568;
L5568: /* bcc $5572 */

if(!fc)goto L5572;
goto L556a;
L556a: /* neg.w D2 */

tv=((u16)d[2]);
tr=0-tv;fx=(u8)(tv>0);
VWORD(d[2])=(u16)(tr);
goto L556c;
L556c: /* cmp.w ($4a,A6), D1 */

ea=(74+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5570;
L5570: /* bcc $5580 */

if(!fc)goto L5580;
goto L5572;
L5572: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5574: /* cmpi.w #$d9, D1 */

tv=((u16)(217L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5578;
L5578: /* bcs $5572 */

if(fc)goto L5572;
goto L557a;
L557a: /* cmp.w ($4a,A6), D1 */

ea=(74+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L557e;
L557e: /* bcc $5572 */

if(!fc)goto L5572;
goto L5580;
L5580: /* move.w D1, ($4a,A6) */

tv=((u16)d[1]);
ea=(74+a[6]);
vew16(ea,tv);

goto L5584;
L5584: /* move.w #$2, ($3c,A6) */

tv=((u16)(2L));
ea=(60+a[6]);
vew16(ea,tv);

goto L558a;
L558a: /* move.w D2, ($50,A6) */

tv=((u16)d[2]);
ea=(80+a[6]);
vew16(ea,tv);

goto L558e;
L558e: /* moveq #$0, D5 */

v=((u32)(0L));
d[5]=v;

goto L5590;
L5590: /* move.w D5, D0 */

tv=((u16)d[5]);
VWORD(d[0])=(u16)(tv);

goto L5592;
L5592: /* tst.w D6 */

tv=((u16)d[6]);
fz=(u8)((tv&0xfffful)==0);
goto L5594;
L5594: /* beq $559a */

if(fz)goto L559a;
goto L5596;
L5596: /* move.w #$fb, D0 */

tv=((u16)(251L));
VWORD(d[0])=(u16)(tv);

goto L559a;
L559a: /* move.w $8f6e.l, D1 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[1])=(u16)(tv);

goto L55a0;
L55a0: /* move.w D1, $8f70.l */

tv=((u16)d[1]);
*(u16 *)(vehicle_state+594)=(u16)(tv);

goto L55a6;
L55a6: /* move.w D0, $8f6e.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L55ac;
L55ac: /* move.w D5, ($4,A6) */

tv=((u16)d[5]);
ea=(4+a[6]);
vew16(ea,tv);

goto L55b0;
L55b0: /* move.w D5, ($2,A6) */

tv=((u16)d[5]);
ea=(2+a[6]);
vew16(ea,tv);

goto L55b4;
L55b4: /* move.w D5, $3708.l */

tv=((u16)d[5]);
*(u16 *)(vehicle_io+8)=(u16)(tv);

goto L55ba;
L55ba: /* divu.w #$a4, D1 */

v=((u16)(164L));
w=((u32)d[1]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[1]=r;
goto L55be;
L55be: /* mulu.w #$19, D1 */

v=((u16)(25L));
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L55c2;
L55c2: /* addi.w #$19, D1 */

tv=((u16)(25L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L55c6;
L55c6: /* move.w #$4e, ($44,A6) */

tv=((u16)(78L));
ea=(68+a[6]);
vew16(ea,tv);

goto L55cc;
L55cc: /* move.w D1, ($56,A6) */

tv=((u16)d[1]);
ea=(86+a[6]);
vew16(ea,tv);

goto L55d0;
L55d0: /* move.w D1, ($52,A6) */

tv=((u16)d[1]);
ea=(82+a[6]);
vew16(ea,tv);

goto L55d4;
L55d4: /* move.w #$c0, $9078.l */

tv=((u16)(192L));
*(u16 *)(vehicle_state+858)=(u16)(tv);

goto L55dc;
L55dc: /* move.w #$1, ($54,A6) */

tv=((u16)(1L));
ea=(84+a[6]);
vew16(ea,tv);

goto L55e2;
L55e2: /* moveq #$0, D6 */

v=((u32)(0L));
d[6]=v;

goto L55e4;
L55e4: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L55e8;
L55e8: /* beq $55ec */

if(fz)goto L55ec;
goto L55ea;
L55ea: /* moveq #-$1, D6 */

v=((u32)(-1L));
d[6]=v;

goto L55ec;
L55ec: /* move.w D6, ($38,A6) */

tv=((u16)d[6]);
ea=(56+a[6]);
vew16(ea,tv);

goto L55f0;
L55f0: /* move.w $8f70.l, D0 */

tv=(*(u16 *)(vehicle_state+594));
VWORD(d[0])=(u16)(tv);

goto L55f6;
L55f6: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L55f8;
L55f8: /* divu.w #$9, D0 */

v=((u16)(9L));
w=((u32)d[0]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[0]=r;
goto L55fc;
L55fc: /* addq.w #3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L55fe;
L55fe: /* move.w D0, ($36,A6) */

tv=((u16)d[0]);
ea=(54+a[6]);
vew16(ea,tv);

goto L5602;
L5602: /* moveq #$b, D0 */

v=((u32)(11L));
d[0]=v;

goto L5604;
L5604: /* bra $3c92 */

return 0x3c92ul;
L5608: /* move.w ($52,A6), D0 */

ea=(82+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L560c;
L560c: /* move.w ($44,A6), D7 */

ea=(68+a[6]);
tv=ver16(ea);
VWORD(d[7])=(u16)(tv);

goto L5610;
L5610: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L5612;
L5612: /* mulu.w #$13a, D1 */

v=((u16)(314L));
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L5616;
L5616: /* divu.w #$3e8, D1 */

v=((u16)(1000L));
w=((u32)d[1]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[1]=r;
goto L561a;
L561a: /* mulu.w D1, D1 */

v=((u16)d[1]);
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L561c;
L561c: /* divu.w #$5, D1 */

v=((u16)(5L));
w=((u32)d[1]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[1]=r;
goto L5620;
L5620: /* andi.l #$ffff, D1 */

v=((u32)(65535L));
w=((u32)d[1]);
r=w&v;

d[1]=r;
goto L5626;
L5626: /* divu.w #$64, D1 */

v=((u16)(100L));
w=((u32)d[1]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[1]=r;
goto L562a;
L562a: /* move.w D1, ($46,A6) */

tv=((u16)d[1]);
ea=(70+a[6]);
vew16(ea,tv);

goto L562e;
L562e: /* cmp.w ($50,A6), D1 */

ea=(80+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5632;
L5632: /* bcc $569c */

if(!fc)goto L569c;
goto L5634;
L5634: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5638;
L5638: /* beq $564a */

if(fz)goto L564a;
goto L563a;
L563a: /* addi.w #$c0, D1 */

tv=((u16)(192L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L563e;
L563e: /* move.w $7ff2.l, D4 */

tv=(*(u16 *)(vehicle_projection+1066));
VWORD(d[4])=(u16)(tv);

goto L5644;
L5644: /* addi.w #$24, D4 */

tv=((u16)(36L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L5648;
L5648: /* bra $565a */

goto L565a;
L564a: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L564c;
L564c: /* addi.w #$7e, D1 */

tv=((u16)(126L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5650;
L5650: /* move.w $7bf2.l, D4 */

tv=(*(u16 *)(vehicle_projection+42));
VWORD(d[4])=(u16)(tv);

goto L5656;
L5656: /* subi.w #$24, D4 */

tv=((u16)(36L));
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L565a;
L565a: /* move.w D1, ($40,A6) */

tv=((u16)d[1]);
ea=(64+a[6]);
vew16(ea,tv);

goto L565e;
L565e: /* move.w D4, ($4a,A6) */

tv=((u16)d[4]);
ea=(74+a[6]);
vew16(ea,tv);

goto L5662;
L5662: /* move.w D0, D2 */

tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L5664;
L5664: /* mulu.w D7, D2 */

v=((u16)d[7]);
w=((u32)d[2]);
r=vehicle_mulu16(v,w);

d[2]=r;
goto L5666;
L5666: /* divu.w #$e, D2 */

v=((u16)(14L));
w=((u32)d[2]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[2]=r;
goto L566a;
L566a: /* andi.l #$ffff, D2 */

v=((u32)(65535L));
w=((u32)d[2]);
r=w&v;

d[2]=r;
goto L5670;
L5670: /* divu.w #$64, D2 */

v=((u16)(100L));
w=((u32)d[2]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[2]=r;
goto L5674;
L5674: /* neg.w D2 */

tv=((u16)d[2]);
tr=0-tv;
VWORD(d[2])=(u16)(tr);
goto L5676;
L5676: /* addi.w #$7f, D2 */

tv=((u16)(127L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L567a;
L567a: /* move.w D2, ($42,A6) */

tv=((u16)d[2]);
ea=(66+a[6]);
vew16(ea,tv);

goto L567e;
L567e: /* add.w ($56,A6), D0 */

ea=(86+a[6]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5682;
L5682: /* move.w D0, ($52,A6) */

tv=((u16)d[0]);
ea=(82+a[6]);
vew16(ea,tv);

goto L5686;
L5686: /* subq.w #1, D7 */

tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[7])=(u16)(tr);
goto L5688;
L5688: /* move.w D7, ($44,A6) */

tv=((u16)d[7]);
ea=(68+a[6]);
vew16(ea,tv);

goto L568c;
L568c: /* moveq #$0, D5 */

v=((u32)(0L));
d[5]=v;

goto L568e;
L568e: /* move.w D5, $8f6e.l */

tv=((u16)d[5]);
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L5694;
L5694: /* move.w D5, $3708.l */

tv=((u16)d[5]);
*(u16 *)(vehicle_io+8)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L569a;
L569a: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L569c: /* move.w #$3, ($3c,A6) */

tv=((u16)(3L));
ea=(60+a[6]);
vew16(ea,tv);

goto L56a2;
L56a2: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L56a6;
L56a6: /* beq $56ae */

if(fz)goto L56ae;
goto L56a8;
L56a8: /* addi.w #$c0, D1 */

tv=((u16)(192L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L56ac;
L56ac: /* bra $56b4 */

goto L56b4;
L56ae: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L56b0;
L56b0: /* addi.w #$7e, D1 */

tv=((u16)(126L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L56b4;
L56b4: /* sub.w ($40,A6), D1 */

ea=(64+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L56b8;
L56b8: /* bpl $56bc */

if(!fn)goto L56bc;
goto L56ba;
L56ba: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L56bc;
L56bc: /* move.w D1, ($44,A6) */

tv=((u16)d[1]);
ea=(68+a[6]);
vew16(ea,tv);

goto L56c0;
L56c0: /* move.w ($44,A6), D0 */

ea=(68+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L56c4;
L56c4: /* addq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L56c6;
L56c6: /* move.w D0, ($44,A6) */

tv=((u16)d[0]);
ea=(68+a[6]);
vew16(ea,tv);

goto L56ca;
L56ca: /* move.w ($40,A6), D1 */

ea=(64+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L56ce;
L56ce: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L56d2;
L56d2: /* beq $56de */

if(fz)goto L56de;
goto L56d4;
L56d4: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L56d6;
L56d6: /* cmpi.w #$1a4, D1 */

tv=((u16)(420L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L56da;
L56da: /* bcc $56ee */

if(!fc)goto L56ee;
goto L56dc;
L56dc: /* bra $56e8 */

goto L56e8;
L56de: /* sub.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L56e0;
L56e0: /* bpl $56e8 */

if(!fn)goto L56e8;
goto L56e2;
L56e2: /* cmpi.w #-$64, D1 */

tv=((u16)(-100L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L56e6;
L56e6: /* bcs $56ee */

if(fc)goto L56ee;
goto L56e8;
L56e8: /* move.w D1, ($40,A6) */

tv=((u16)d[1]);
ea=(64+a[6]);
vew16(ea,tv);

goto L56ec;
L56ec: /* bra $568c */

goto L568c;
L56ee: /* move.w #$0, ($3c,A6) */

tv=((u16)(0L));
ea=(60+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L56f4;
L56f4: /* bsr $6a2c */

a[7]-=4;STACK_WRITE(a[7],0x56f8ul);
return 0x6a2cul;
L56f8: /* move.w $8f70.l, $8f6e.l */

tv=(*(u16 *)(vehicle_state+594));
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L5702;
L5702: /* lea ($8,A7), A7 */

a[7]=(8+a[7]);
goto L5706;
L5706: /* movea.l $37c4.l, A0 */

v=(((u32)*(u16 *)(vehicle_io+196)<<16)|*(u16 *)(vehicle_io+198));
a[0]=v;
goto L570c;
L570c: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L570e;
L570e: /* move.w #$17bf, D7 */

tv=((u16)(6079L));
VWORD(d[7])=(u16)(tv);

goto L5712;
L5712:
#ifndef VM_HOST
 /* Source grapple exit clears a 24KB Amiga screen. A native frame is
    already being built offscreen; clear that buffer once, then preserve the
    source loop boundary. Never execute thousands of virtual pixel writes. */
 vehicle_clear_display();a[0]+=((u32)(u16)d[7]+1ul)*4ul;VWORD(d[7])=65535u;goto L5718;
#endif
L5712_original: /* move.l D0, (A0)+ */

v=((u32)d[0]);
ea=a[0];
vew32(ea,v);
a[0]+=4;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5714;
L5714: /* dbra D7, $5712 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L5712;
goto L5718;
L5718: /* bsr $3ce2 */

a[7]-=4;STACK_WRITE(a[7],0x571cul);
return 0x3ce2ul;
L571c: /* move.w #$1, $8d2a.l */

tv=((u16)(1L));
*(u16 *)(vehicle_state+12)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5724;
L5724: /* bra $39ce */

return 0x39ceul;
L5764: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L576a;
L576a: /* tst.w ($3a,A6) */

ea=(58+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L576e;
L576e: /* beq $5774 */

if(fz)goto L5774;
goto L5770;
L5770: /* subq.w #1, ($3a,A6) */

tv=((u16)(1L));
eb=(58+a[6]);
tw=ver16(eb);
tr=tw-tv;
vew16(eb,tr);
goto L5774;
L5774: /* tst.w ($32,A6) */

ea=(50+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5778;
L5778: /* beq $577e */

if(fz)goto L577e;
goto L577a;
L577a: /* subq.w #1, ($32,A6) */

tv=((u16)(1L));
eb=(50+a[6]);
tw=ver16(eb);
tr=tw-tv;
vew16(eb,tr);
goto L577e;
L577e: /* move.w ($22,A6), D0 */

ea=(34+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5782;
L5782: /* addq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5784;
L5784: /* andi.w #$3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L5788;
L5788: /* move.w D0, ($22,A6) */

tv=((u16)d[0]);
ea=(34+a[6]);
vew16(ea,tv);

goto L578c;
L578c: /* btst #$0, D0 */

v=((u16)(0L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5790;
L5790: /* beq $579c */

if(fz)goto L579c;
goto L5792;
L5792: /* addq.w #1, ($24,A6) */

tv=((u16)(1L));
eb=(36+a[6]);
tw=ver16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vew16(eb,tr);
goto L5796;
L5796: /* andi.w #$3, ($24,A6) */

tv=((u16)(3L));
eb=(36+a[6]);
tw=ver16(eb);
tr=tw&tv;

vew16(eb,tr);
goto L579c;
L579c: /* move.w $3708.l, D5 */

tv=(*(u16 *)(vehicle_io+8));
VWORD(d[5])=(u16)(tv);

goto L57a2;
L57a2: /* tst.w $8f66.l */

tv=(*(u16 *)(vehicle_state+584));
fz=(u8)((tv&0xfffful)==0);
goto L57a8;
L57a8: /* beq $57ae */

if(fz)goto L57ae;
goto L57ac;
L57ac: /* moveq #$0, D5 */

v=((u32)(0L));
d[5]=v;

goto L57ae;
L57ae: /* tst.w $8d1e.l */

tv=(*(u16 *)(vehicle_state+0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L57b4;
L57b4: /* bne $5a28 */

if(!fz)goto L5a28;
goto L57b8;
L57b8: /* bsr $544c */

a[7]-=4;STACK_WRITE(a[7],0x57bcul);
goto L544c;
L57bc: /* move.w ($18,A6), D0 */

ea=(24+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L57c0;
L57c0: /* beq $5802 */

if(fz)goto L5802;
goto L57c2;
L57c2: /* subq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L57c4;
L57c4: /* move.w D0, ($18,A6) */

tv=((u16)d[0]);
ea=(24+a[6]);
vew16(ea,tv);
fz=(u8)((tv&0xfffful)==0);
goto L57c8;
L57c8: /* bne $57d0 */

if(!fz)goto L57d0;
goto L57ca;
L57ca: /* moveq #$8, D0 */

v=((u32)(8L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L57cc;
L57cc: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x57d0ul);
return 0x3c92ul;
L57d0: /* movea.l ($1c,A6), A0 */

ea=(28+a[6]);
v=ver32(ea);
a[0]=v;
goto L57d4;
L57d4: /* move.w #$0, $3708.l */

tv=((u16)(0L));
*(u16 *)(vehicle_io+8)=(u16)(tv);

goto L57dc;
L57dc: /* move.w (A0)+, ($16,A6) */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
ea=(22+a[6]);
vew16(ea,tv);

goto L57e0;
L57e0: /* move.w ($10,A6), D0 */

ea=(16+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L57e4;
L57e4: /* add.w (A0)+, D0 */

ea=a[0];
tv=ver16(ea);
a[0]+=2;
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L57e6;
L57e6: /* move.w D0, ($10,A6) */

tv=((u16)d[0]);
ea=(16+a[6]);
vew16(ea,tv);

goto L57ea;
L57ea: /* addi.w #$7f, D0 */

tv=((u16)(127L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L57ee;
L57ee: /* subi.w #$91, D0 */

tv=((u16)(145L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L57f2;
L57f2: /* move.w D0, ($4c,A6) */

tv=((u16)d[0]);
ea=(76+a[6]);
vew16(ea,tv);

goto L57f6;
L57f6: /* move.w D0, ($42,A6) */

tv=((u16)d[0]);
ea=(66+a[6]);
vew16(ea,tv);

goto L57fa;
L57fa: /* move.l A0, ($1c,A6) */

v=((u32)a[0]);
ea=(28+a[6]);
vew32(ea,v);

goto L57fe;
L57fe: /* bra $5894 */

goto L5894;
L5802: /* tst.w ($36,A6) */

ea=(54+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5806;
L5806: /* beq $581a */

if(fz)goto L581a;
goto L5808;
L5808: /* move.w ($38,A6), D0 */

ea=(56+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L580c;
L580c: /* addi.w #$2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5810;
L5810: /* move.w D5, D1 */

tv=((u16)d[5]);
VWORD(d[1])=(u16)(tv);

goto L5812;
L5812: /* andi.w #$3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw&tv;

VWORD(d[1])=(u16)(tr);
goto L5816;
L5816: /* cmp.w D5, D1 */

tv=((u16)d[5]);
tw=((u16)d[1]);
fz=(u8)((u16)tw==(u16)tv);
goto L5818;
L5818: /* beq $5894 */

if(fz)goto L5894;
goto L581a;
L581a: /* move.w D5, D0 */

tv=((u16)d[5]);
VWORD(d[0])=(u16)(tv);

goto L581c;
L581c: /* move.w $8f6e.l, D2 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[2])=(u16)(tv);

goto L5822;
L5822: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L5824;
L5824: /* move.w #$fffb, D1 */

tv=((u16)(65531L));
VWORD(d[1])=(u16)(tv);

goto L5828;
L5828: /* andi.w #$3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[0])=(u16)(tr);
goto L582c;
L582c: /* beq $587e */

if(fz)goto L587e;
goto L582e;
L582e: /* move.w #$ffe7, D1 */

tv=((u16)(65511L));
VWORD(d[1])=(u16)(tv);

goto L5832;
L5832: /* btst #$0, D0 */

v=((u16)(0L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5836;
L5836: /* beq $587e */

if(fz)goto L587e;
goto L5838;
L5838: /* move.w #$1c3, D1 */

tv=((u16)(451L));
VWORD(d[1])=(u16)(tv);

goto L583c;
L583c: /* move.w $8f62.l, D0 */

tv=(*(u16 *)(vehicle_state+580));
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5842;
L5842: /* beq $5852 */

if(fz)goto L5852;
goto L5844;
L5844: /* move.w #$78, D1 */

tv=((u16)(120L));
VWORD(d[1])=(u16)(tv);

goto L5848;
L5848: /* cmpi.w #$1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L584c;
L584c: /* bcs $5852 */

if(fc)goto L5852;
goto L584e;
L584e: /* move.w #$78, D1 */

tv=((u16)(120L));
VWORD(d[1])=(u16)(tv);

goto L5852;
L5852: /* sub.w D1, D2 */

tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[2])=(u16)(tr);
goto L5854;
L5854: /* bcc $5876 */

if(!fc)goto L5876;
goto L5856;
L5856: /* addi.w #$118, D1 */

tv=((u16)(280L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L585a;
L585a: /* bcs $5868 */

if(fc)goto L5868;
goto L585c;
L585c: /* addi.w #$118, D1 */

tv=((u16)(280L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5860;
L5860: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L5862;
L5862: /* ori.w #$1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw|tv;

VWORD(d[1])=(u16)(tr);
goto L5866;
L5866: /* bra $587e */

goto L587e;
L5868: /* subi.w #$118, D1 */

tv=((u16)(280L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L586c;
L586c: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L586e;
L586e: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L5870;
L5870: /* ori.w #$1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw|tv;

VWORD(d[1])=(u16)(tr);
goto L5874;
L5874: /* bra $587e */

goto L587e;
L5876: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L5878;
L5878: /* ori.w #$1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw|tv;

VWORD(d[1])=(u16)(tr);
goto L587c;
L587c: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L587e;
L587e: /* add.w D3, D1 */

tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5880;
L5880: /* bpl $5884 */

if(!fn)goto L5884;
goto L5882;
L5882: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5884;
L5884: /* cmpi.w #$1c2, D1 */

tv=((u16)(450L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5888;
L5888: /* bcs $588e */

if(fc)goto L588e;
goto L588a;
L588a: /* move.w #$1c2, D1 */

tv=((u16)(450L));
VWORD(d[1])=(u16)(tv);

goto L588e;
L588e: /* move.w D1, $8f6e.l */

tv=((u16)d[1]);
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L5894;
L5894: /* move.w ($2,A6), D0 */

ea=(2+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5898;
L5898: /* move.w ($4,A6), D1 */

ea=(4+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L589c;
L589c: /* tst.w ($18,A6) */

ea=(24+a[6]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L58a0;
L58a0: /* bne $590c */

if(!fz)goto L590c;
goto L58a2;
L58a2: /* btst #$2, D5 */

v=((u16)(2L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L58a6;
L58a6: /* bne $58d0 */

if(!fz)goto L58d0;
goto L58a8;
L58a8: /* btst #$3, D5 */

v=((u16)(3L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L58ac;
L58ac: /* bne $58be */

if(!fz)goto L58be;
goto L58ae;
L58ae: /* subq.w #2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L58b0;
L58b0: /* bcc $58b6 */

if(!fc)goto L58b6;
goto L58b4;
L58b4: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L58b6;
L58b6: /* subq.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L58b8;
L58b8: /* bcc $58e2 */

if(!fc)goto L58e2;
goto L58ba;
L58ba: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L58bc;
L58bc: /* bra $58e2 */

goto L58e2;
L58be: /* addq.w #3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L58c0;
L58c0: /* cmpi.w #$10, D0 */

tv=((u16)(16L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L58c4;
L58c4: /* bcs $58c8 */

if(fc)goto L58c8;
goto L58c6;
L58c6: /* moveq #$10, D0 */

v=((u32)(16L));
d[0]=v;

goto L58c8;
L58c8: /* sub.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L58ca;
L58ca: /* bcc $58e2 */

if(!fc)goto L58e2;
goto L58cc;
L58cc: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L58ce;
L58ce: /* bra $58e2 */

goto L58e2;
L58d0: /* addq.w #3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L58d2;
L58d2: /* cmpi.w #$10, D1 */

tv=((u16)(16L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L58d6;
L58d6: /* bcs $58da */

if(fc)goto L58da;
goto L58d8;
L58d8: /* moveq #$10, D1 */

v=((u32)(16L));
d[1]=v;

goto L58da;
L58da: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L58dc;
L58dc: /* bcc $58e2 */

if(!fc)goto L58e2;
goto L58de;
L58de: /* move.w #$0, D0 */

tv=((u16)(0L));
VWORD(d[0])=(u16)(tv);

goto L58e2;
L58e2: /* move.w $8f6e.l, D2 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[2])=(u16)(tv);

goto L58e8;
L58e8: /* lsr.w #4, D2 */

tv=((u16)(4L));
tw=((u16)d[2]);
tr=((u16)tw)>>4;
VWORD(d[2])=(u16)(tr);
goto L58ea;
L58ea: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L58ec;
L58ec: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L58ee;
L58ee: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L58f0;
L58f0: /* cmp.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L58f2;
L58f2: /* bcs $58f6 */

if(fc)goto L58f6;
goto L58f4;
L58f4: /* move.w D2, D0 */

tv=((u16)d[2]);
VWORD(d[0])=(u16)(tv);

goto L58f6;
L58f6: /* cmp.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L58f8;
L58f8: /* bcs $58fc */

if(fc)goto L58fc;
goto L58fa;
L58fa: /* move.w D2, D1 */

tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L58fc;
L58fc: /* move.w D0, ($2,A6) */

tv=((u16)d[0]);
ea=(2+a[6]);
vew16(ea,tv);

goto L5900;
L5900: /* move.w D1, ($4,A6) */

tv=((u16)d[1]);
ea=(4+a[6]);
vew16(ea,tv);

goto L5904;
L5904: /* move.w ($36,A6), D2 */

ea=(54+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5908;
L5908: /* beq $590c */

if(fz)goto L590c;
goto L590a;
L590a: /* exg D0, D1 */

r=d[0];d[0]=d[1];d[1]=r;
goto L590c;
L590c: /* bsr $5980 */

a[7]-=4;STACK_WRITE(a[7],0x5910ul);
goto L5980;
L5910: /* moveq #$2, D0 */

v=((u32)(2L));
d[0]=v;

goto L5912;
L5912: /* moveq #-$1, D2 */

v=((u32)(-1L));
d[2]=v;

goto L5914;
L5914: /* tst.w D1 */

tv=((u16)d[1]);
fn=(u8)((tv&0x8000ul)!=0);
goto L5916;
L5916: /* bpl $591c */

if(!fn)goto L591c;
goto L5918;
L5918: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L591a;
L591a: /* neg.w D2 */

tv=((u16)d[2]);
tr=0-tv;fx=(u8)(tv>0);
VWORD(d[2])=(u16)(tr);
goto L591c;
L591c: /* cmpi.w #$8, D1 */

tv=((u16)(8L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5920;
L5920: /* bcs $592c */

if(fc)goto L592c;
goto L5922;
L5922: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5924;
L5924: /* cmpi.w #$10, D1 */

tv=((u16)(16L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5928;
L5928: /* bcs $592c */

if(fc)goto L592c;
goto L592a;
L592a: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L592c;
L592c: /* move.w D0, ($12,A6) */

tv=((u16)d[0]);
ea=(18+a[6]);
vew16(ea,tv);

goto L5930;
L5930: /* move.w ($36,A6), D0 */

ea=(54+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5934;
L5934: /* beq $597e */

if(fz)goto L597e;
goto L5938;
L5938: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L593a;
L593a: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L593c;
L593c: /* tst.w ($18,A6) */

ea=(24+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5940;
L5940: /* bne $594e */

if(!fz)goto L594e;
goto L5942;
L5942: /* mulu.w #$4, D1 */

v=((u16)(4L));
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L5946;
L5946: /* divu.w #$5, D1 */

v=((u16)(5L));
w=((u32)d[1]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[1]=r;
goto L594a;
L594a: /* move.w D1, ($36,A6) */

tv=((u16)d[1]);
ea=(54+a[6]);
vew16(ea,tv);

goto L594e;
L594e: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L5950;
L5950: /* lsr.w #3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
tr=((u16)tw)>>3;
VWORD(d[1])=(u16)(tr);
goto L5952;
L5952: /* cmpi.w #$3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5956;
L5956: /* bcs $595c */

if(fc)goto L595c;
goto L5958;
L5958: /* move.w #$2, D1 */

tv=((u16)(2L));
VWORD(d[1])=(u16)(tv);

goto L595c;
L595c: /* addi.w #$2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5960;
L5960: /* tst.w ($38,A6) */

ea=(56+a[6]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L5964;
L5964: /* bmi $596e */

if(fn)goto L596e;
goto L5966;
L5966: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L5968;
L5968: /* addi.w #$4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L596c;
L596c: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L596e;
L596e: /* add.w D0, $9074.l */

tv=((u16)d[0]);
tw=(*(u16 *)(vehicle_state+854));
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
*(u16 *)(vehicle_state+854)=(u16)(tr);
goto L5974;
L5974: /* move.w D1, ($12,A6) */

tv=((u16)d[1]);
ea=(18+a[6]);
vew16(ea,tv);

goto L5978;
L5978: /* move.w #$2, ($32,A6) */

tv=((u16)(2L));
ea=(50+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L597e;
L597e: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5980: /* moveq #$0, D5 */

v=((u32)(0L));
d[5]=v;

goto L5982;
L5982: /* move.w ($e,A6), D2 */

ea=(14+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L5986;
L5986: /* beq $59c6 */

if(fz)goto L59c6;
goto L5988;
L5988: /* bpl $598c */

if(!fn)goto L598c;
goto L598a;
L598a: /* neg.w D2 */

tv=((u16)d[2]);
tr=0-tv;
VWORD(d[2])=(u16)(tr);
goto L598c;
L598c: /* move.w #$5e, D3 */

tv=((u16)(94L));
VWORD(d[3])=(u16)(tv);

goto L5990;
L5990: /* divu.w D2, D3 */

v=((u16)d[2]);
w=((u32)d[3]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[3]=r;
goto L5992;
L5992: /* move.w D3, D2 */

tv=((u16)d[3]);
VWORD(d[2])=(u16)(tv);

goto L5994;
L5994: /* move.w ($a,A6), D3 */

ea=(10+a[6]);
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L5998;
L5998: /* move.w $9078.l, D4 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[4])=(u16)(tv);

goto L599e;
L599e: /* sub.w D3, D4 */

tv=((u16)d[3]);
tw=((u16)d[4]);
tr=tw-tv;fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L59a0;
L59a0: /* beq $59c6 */

if(fz)goto L59c6;
goto L59a2;
L59a2: /* sub.w D2, D4 */

tv=((u16)d[2]);
tw=((u16)d[4]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[4])=(u16)(tr);
goto L59a4;
L59a4: /* bcs $59ac */

if(fc)goto L59ac;
goto L59a6;
L59a6: /* addq.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L59a8;
L59a8: /* add.b D2, D3 */

tv=((u8)d[2]);
tw=((u8)d[3]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);
VBYTE(d[3])=(u8)(tr);
goto L59aa;
L59aa: /* bcs $59a2 */

if(fc)goto L59a2;
goto L59ac;
L59ac: /* tst.w D5 */

tv=((u16)d[5]);
fz=(u8)((tv&0xfffful)==0);
goto L59ae;
L59ae: /* beq $59c2 */

if(fz)goto L59c2;
goto L59b0;
L59b0: /* add.w D5, ($c,A6) */

tv=((u16)d[5]);
eb=(12+a[6]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L59b4;
L59b4: /* move.w D5, D4 */

tv=((u16)d[5]);
VWORD(d[4])=(u16)(tv);

goto L59b6;
L59b6: /* lsl.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw<<1;
VWORD(d[5])=(u16)(tr);
goto L59b8;
L59b8: /* add.w D4, D5 */

tv=((u16)d[4]);
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L59ba;
L59ba: /* tst.w ($e,A6) */

ea=(14+a[6]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L59be;
L59be: /* bpl $59c2 */

if(!fn)goto L59c2;
goto L59c0;
L59c0: /* neg.w D5 */

tv=((u16)d[5]);
tr=0-tv;
VWORD(d[5])=(u16)(tr);
goto L59c2;
L59c2: /* move.w D3, ($a,A6) */

tv=((u16)d[3]);
ea=(10+a[6]);
vew16(ea,tv);

goto L59c6;
L59c6: /* add.w ($34,A6), D5 */

ea=(52+a[6]);
tv=ver16(ea);
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L59ca;
L59ca: /* move.w #$0, ($34,A6) */

tv=((u16)(0L));
ea=(52+a[6]);
vew16(ea,tv);

goto L59d0;
L59d0: /* sub.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L59d2;
L59d2: /* add.w D1, D5 */

tv=((u16)d[1]);
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L59d4;
L59d4: /* tst.w D1 */

tv=((u16)d[1]);
fz=(u8)((tv&0xfffful)==0);
goto L59d6;
L59d6: /* beq $59fc */

if(fz)goto L59fc;
goto L59d8;
L59d8: /* move.w D1, D0 */

tv=((u16)d[1]);
VWORD(d[0])=(u16)(tv);

goto L59da;
L59da: /* andi.b #$f, D0 */

tv=((u8)(15L));
tw=((u8)d[0]);
tr=tw&tv;
fz=(u8)((tr&0xfful)==0);
VBYTE(d[0])=(u8)(tr);
goto L59de;
L59de: /* bne $59fc */

if(!fz)goto L59fc;
goto L59e0;
L59e0: /* tst.w D5 */

tv=((u16)d[5]);
fn=(u8)((tv&0x8000ul)!=0);
goto L59e2;
L59e2: /* bpl $59ee */

if(!fn)goto L59ee;
goto L59e4;
L59e4: /* tst.w D1 */

tv=((u16)d[1]);
fn=(u8)((tv&0x8000ul)!=0);
goto L59e6;
L59e6: /* bmi $59fc */

if(fn)goto L59fc;
goto L59e8;
L59e8: /* tst.w D5 */

tv=((u16)d[5]);
fn=(u8)((tv&0x8000ul)!=0);
goto L59ea;
L59ea: /* bpl $59fc */

if(!fn)goto L59fc;
goto L59ec;
L59ec: /* bra $59f6 */

goto L59f6;
L59ee: /* tst.w D1 */

tv=((u16)d[1]);
fn=(u8)((tv&0x8000ul)!=0);
goto L59f0;
L59f0: /* bpl $59fc */

if(!fn)goto L59fc;
goto L59f2;
L59f2: /* tst.w D5 */

tv=((u16)d[5]);
fn=(u8)((tv&0x8000ul)!=0);
goto L59f4;
L59f4: /* bmi $59fc */

if(fn)goto L59fc;
goto L59f6;
L59f6: /* move.w #$2, ($32,A6) */

tv=((u16)(2L));
ea=(50+a[6]);
vew16(ea,tv);

goto L59fc;
L59fc: /* add.w $9074.l, D5 */

tv=(*(u16 *)(vehicle_state+854));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L5a02;
L5a02: /* move.w #$34, D2 */

tv=((u16)(52L));
VWORD(d[2])=(u16)(tv);

goto L5a06;
L5a06: /* cmp.w D2, D5 */

tv=((u16)d[2]);
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L5a08;
L5a08: /* bcc $5a0c */

if(!fc)goto L5a0c;
goto L5a0a;
L5a0a: /* move.w D2, D5 */

tv=((u16)d[2]);
VWORD(d[5])=(u16)(tv);

goto L5a0c;
L5a0c: /* move.w #$29f, D2 */

tv=((u16)(671L));
VWORD(d[2])=(u16)(tv);

goto L5a10;
L5a10: /* cmp.w D2, D5 */

tv=((u16)d[2]);
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L5a12;
L5a12: /* bcs $5a16 */

if(fc)goto L5a16;
goto L5a14;
L5a14: /* move.w D2, D5 */

tv=((u16)d[2]);
VWORD(d[5])=(u16)(tv);

goto L5a16;
L5a16: /* move.w D5, $9074.l */

tv=((u16)d[5]);
*(u16 *)(vehicle_state+854)=(u16)(tv);

goto L5a1c;
L5a1c: /* addq.w #1, ($26,A6) */

tv=((u16)(1L));
eb=(38+a[6]);
tw=ver16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vew16(eb,tr);
goto L5a20;
L5a20: /* andi.w #$3, ($26,A6) */

tv=((u16)(3L));
eb=(38+a[6]);
tw=ver16(eb);
tr=tw&tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
vew16(eb,tr);
goto L5a26;
L5a26: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5a28: /* tst.w $8d38.l */

tv=(*(u16 *)(vehicle_state+26));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5a2e;
L5a2e: /* beq $5a32 */

if(fz)goto L5a32;
goto L5a30;
L5a30: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5a32: /* move.w $8f6e.l, D2 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[2])=(u16)(tv);

goto L5a38;
L5a38: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L5a3a;
L5a3a: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5a3c;
L5a3c: /* tst.b $3708.l */

tv=vehicle_io[9];
fz=(u8)((tv&0xfful)==0);
goto L5a42;
L5a42: /* beq $5a86 */

if(fz)goto L5a86;
goto L5a44;
L5a44: /* move.w D5, D0 */

tv=((u16)d[5]);
VWORD(d[0])=(u16)(tv);

goto L5a46;
L5a46: /* andi.w #$3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[0])=(u16)(tr);
goto L5a4a;
L5a4a: /* beq $5a86 */

if(fz)goto L5a86;
goto L5a4c;
L5a4c: /* move.w #$ffec, D1 */

tv=((u16)(65516L));
VWORD(d[1])=(u16)(tv);

goto L5a50;
L5a50: /* btst #$0, D0 */

v=((u16)(0L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5a54;
L5a54: /* beq $5a86 */

if(fz)goto L5a86;
goto L5a56;
L5a56: /* move.w #$200, D1 */

tv=((u16)(512L));
VWORD(d[1])=(u16)(tv);

goto L5a5a;
L5a5a: /* sub.w D1, D2 */

tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[2])=(u16)(tr);
goto L5a5c;
L5a5c: /* bcc $5a7e */

if(!fc)goto L5a7e;
goto L5a5e;
L5a5e: /* addi.w #$12c, D1 */

tv=((u16)(300L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L5a62;
L5a62: /* bcs $5a70 */

if(fc)goto L5a70;
goto L5a64;
L5a64: /* addi.w #$12c, D1 */

tv=((u16)(300L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5a68;
L5a68: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L5a6a;
L5a6a: /* ori.w #$1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw|tv;

VWORD(d[1])=(u16)(tr);
goto L5a6e;
L5a6e: /* bra $5a86 */

goto L5a86;
L5a70: /* subi.w #$12c, D1 */

tv=((u16)(300L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L5a74;
L5a74: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L5a76;
L5a76: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L5a78;
L5a78: /* ori.w #$1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw|tv;

VWORD(d[1])=(u16)(tr);
goto L5a7c;
L5a7c: /* bra $5a86 */

goto L5a86;
L5a7e: /* lsr.w #6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
tr=((u16)tw)>>6;
VWORD(d[1])=(u16)(tr);
goto L5a80;
L5a80: /* ori.w #$1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw|tv;

VWORD(d[1])=(u16)(tr);
goto L5a84;
L5a84: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L5a86;
L5a86: /* add.w D3, D1 */

tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5a88;
L5a88: /* bpl $5a8c */

if(!fn)goto L5a8c;
goto L5a8a;
L5a8a: /* moveq #$78, D1 */

v=((u32)(120L));
d[1]=v;

goto L5a8c;
L5a8c: /* cmpi.w #$1ff, D1 */

tv=((u16)(511L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5a90;
L5a90: /* bcs $5a96 */

if(fc)goto L5a96;
goto L5a92;
L5a92: /* move.w #$1ff, D1 */

tv=((u16)(511L));
VWORD(d[1])=(u16)(tv);

goto L5a96;
L5a96: /* cmpi.w #$78, D1 */

tv=((u16)(120L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5a9a;
L5a9a: /* bcc $5a9e */

if(!fc)goto L5a9e;
goto L5a9c;
L5a9c: /* moveq #$78, D1 */

v=((u32)(120L));
d[1]=v;

goto L5a9e;
L5a9e: /* move.w D1, $8f6e.l */

tv=((u16)d[1]);
*(u16 *)(vehicle_state+592)=(u16)(tv);

goto L5aa4;
L5aa4: /* lea $8f74.l, A0 */

a[0]=0x8f74ul;
goto L5aaa;
L5aaa: /* move.w $9076.l, D0 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[0])=(u16)(tv);

goto L5ab0;
L5ab0: /* addi.b #$20, D0 */

tv=((u8)(32L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L5ab4;
L5ab4: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5ab6;
L5ab6: /* moveq #$4, D2 */

v=((u32)(4L));
d[2]=v;

goto L5ab8;
L5ab8: /* move.b (A0,D0.w), D3 */

ea=(a[0]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[3])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);
goto L5abc;
L5abc: /* bmi $5ac0 */

if(fn)goto L5ac0;
goto L5abe;
L5abe: /* asr.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=((s8)tw)>>1;
VBYTE(d[3])=(u8)(tr);
goto L5ac0;
L5ac0: /* add.b D3, D1 */

tv=((u8)d[3]);
tw=((u8)d[1]);
tr=tw+tv;
VBYTE(d[1])=(u8)(tr);
goto L5ac2;
L5ac2: /* addq.b #1, D0 */

tv=((u8)(1L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L5ac4;
L5ac4: /* dbra D2, $5ab8 */

VWORD(d[2])=(u16)(d[2]-1);
if((u16)d[2]!=65535u)goto L5ab8;
goto L5ac8;
L5ac8: /* addi.b #-$79, D1 */

tv=((u8)(-121L));
tw=((u8)d[1]);
tr=tw+tv;
VBYTE(d[1])=(u8)(tr);
goto L5acc;
L5acc: /* move.w D1, ($20,A6) */

tv=((u16)d[1]);
ea=(32+a[6]);
vew16(ea,tv);

goto L5ad0;
L5ad0: /* move.w ($6,A6), D0 */

ea=(6+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5ad4;
L5ad4: /* move.w ($8,A6), D1 */

ea=(8+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5ad8;
L5ad8: /* tst.b $3708.l */

tv=vehicle_io[9];
fz=(u8)((tv&0xfful)==0);
goto L5ade;
L5ade: /* bne $5aec */

if(!fz)goto L5aec;
goto L5ae0;
L5ae0: /* btst #$0, D5 */

v=((u16)(0L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5ae4;
L5ae4: /* bne $5afa */

if(!fz)goto L5afa;
goto L5ae6;
L5ae6: /* btst #$1, D5 */

v=((u16)(1L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5aea;
L5aea: /* bne $5b0e */

if(!fz)goto L5b0e;
goto L5aec;
L5aec: /* subq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L5aee;
L5aee: /* bcc $5af2 */

if(!fc)goto L5af2;
goto L5af0;
L5af0: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L5af2;
L5af2: /* subq.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L5af4;
L5af4: /* bcc $5b22 */

if(!fc)goto L5b22;
goto L5af6;
L5af6: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5af8;
L5af8: /* bra $5b22 */

goto L5b22;
L5afa: /* move.w D0, D2 */

tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L5afc;
L5afc: /* addq.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5afe;
L5afe: /* cmpi.w #$5, D2 */

tv=((u16)(5L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5b02;
L5b02: /* bcc $5b06 */

if(!fc)goto L5b06;
goto L5b04;
L5b04: /* move.w D2, D0 */

tv=((u16)d[2]);
VWORD(d[0])=(u16)(tv);

goto L5b06;
L5b06: /* sub.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L5b08;
L5b08: /* bcc $5b22 */

if(!fc)goto L5b22;
goto L5b0a;
L5b0a: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5b0c;
L5b0c: /* bra $5b22 */

goto L5b22;
L5b0e: /* move.w D1, D2 */

tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L5b10;
L5b10: /* addq.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5b12;
L5b12: /* cmpi.w #$5, D2 */

tv=((u16)(5L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5b16;
L5b16: /* bcc $5b1a */

if(!fc)goto L5b1a;
goto L5b18;
L5b18: /* move.w D2, D1 */

tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L5b1a;
L5b1a: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L5b1c;
L5b1c: /* bcc $5b22 */

if(!fc)goto L5b22;
goto L5b1e;
L5b1e: /* move.w #$0, D0 */

tv=((u16)(0L));
VWORD(d[0])=(u16)(tv);

goto L5b22;
L5b22: /* move.w $8f6e.l, D2 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[2])=(u16)(tv);

goto L5b28;
L5b28: /* lsr.w #4, D2 */

tv=((u16)(4L));
tw=((u16)d[2]);
tr=((u16)tw)>>4;
VWORD(d[2])=(u16)(tr);
goto L5b2a;
L5b2a: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L5b2c;
L5b2c: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L5b2e;
L5b2e: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5b30;
L5b30: /* bra $5b3e */

goto L5b3e;
L5b3e: /* move.w D0, ($6,A6) */

tv=((u16)d[0]);
ea=(6+a[6]);
vew16(ea,tv);

goto L5b42;
L5b42: /* move.w D1, ($8,A6) */

tv=((u16)d[1]);
ea=(8+a[6]);
vew16(ea,tv);

goto L5b46;
L5b46: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5b48;
L5b48: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L5b4a;
L5b4a: /* add.w ($10,A6), D0 */

ea=(16+a[6]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5b4e;
L5b4e: /* cmpi.w #$26, D0 */

tv=((u16)(38L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5b52;
L5b52: /* bcc $5b58 */

if(!fc)goto L5b58;
goto L5b54;
L5b54: /* move.w #$26, D0 */

tv=((u16)(38L));
VWORD(d[0])=(u16)(tv);

goto L5b58;
L5b58: /* move.w ($20,A6), D2 */

ea=(32+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L5b5c;
L5b5c: /* cmp.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5b5e;
L5b5e: /* bcs $5b90 */

if(fc)goto L5b90;
goto L5b60;
L5b60: /* tst.w ($28,A6) */

ea=(40+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5b64;
L5b64: /* bne $5b6c */

if(!fz)goto L5b6c;
goto L5b66;
L5b66: /* move.w #$1, ($28,A6) */

tv=((u16)(1L));
ea=(40+a[6]);
vew16(ea,tv);

goto L5b6c;
L5b6c: /* move.w D2, D0 */

tv=((u16)d[2]);
VWORD(d[0])=(u16)(tv);

goto L5b6e;
L5b6e: /* subi.w #$87, D2 */

tv=((u16)(135L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5b72;
L5b72: /* neg.w D2 */

tv=((u16)d[2]);
tr=0-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5b74;
L5b74: /* bpl $5b78 */

if(!fn)goto L5b78;
goto L5b76;
L5b76: /* moveq #$0, D2 */

v=((u32)(0L));
d[2]=v;

goto L5b78;
L5b78: /* lsr.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L5b7a;
L5b7a: /* add.w ($6,A6), D2 */

ea=(6+a[6]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5b7e;
L5b7e: /* cmpi.w #$9, D2 */

tv=((u16)(9L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5b82;
L5b82: /* bcs $5b86 */

if(fc)goto L5b86;
goto L5b84;
L5b84: /* moveq #$9, D2 */

v=((u32)(9L));
d[2]=v;

goto L5b86;
L5b86: /* move.w #$0, ($6,A6) */

tv=((u16)(0L));
ea=(6+a[6]);
vew16(ea,tv);

goto L5b8c;
L5b8c: /* move.w D2, ($8,A6) */

tv=((u16)d[2]);
ea=(8+a[6]);
vew16(ea,tv);

goto L5b90;
L5b90: /* move.w D0, ($10,A6) */

tv=((u16)d[0]);
ea=(16+a[6]);
vew16(ea,tv);

goto L5b94;
L5b94: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L5b96;
L5b96: /* tst.w D1 */

tv=((u16)d[1]);
fz=(u8)((tv&0xfffful)==0);
goto L5b98;
L5b98: /* beq $5bac */

if(fz)goto L5bac;
goto L5b9a;
L5b9a: /* moveq #$a, D2 */

v=((u32)(10L));
d[2]=v;

goto L5b9c;
L5b9c: /* tst.w D1 */

tv=((u16)d[1]);
fn=(u8)((tv&0x8000ul)!=0);
goto L5b9e;
L5b9e: /* bpl $5ba4 */

if(!fn)goto L5ba4;
goto L5ba0;
L5ba0: /* moveq #$5, D2 */

v=((u32)(5L));
d[2]=v;

goto L5ba2;
L5ba2: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L5ba4;
L5ba4: /* cmpi.w #$2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5ba8;
L5ba8: /* bcs $5bac */

if(fc)goto L5bac;
goto L5baa;
L5baa: /* move.w D2, D0 */

tv=((u16)d[2]);
VWORD(d[0])=(u16)(tv);

goto L5bac;
L5bac: /* move.w D0, ($1e,A6) */

tv=((u16)d[0]);
ea=(30+a[6]);
vew16(ea,tv);

goto L5bb0;
L5bb0: /* move.w ($2,A6), D0 */

ea=(2+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5bb4;
L5bb4: /* move.w ($4,A6), D1 */

ea=(4+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5bb8;
L5bb8: /* btst #$2, D5 */

v=((u16)(2L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5bbc;
L5bbc: /* bne $5be4 */

if(!fz)goto L5be4;
goto L5bbe;
L5bbe: /* btst #$3, D5 */

v=((u16)(3L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5bc2;
L5bc2: /* bne $5bd2 */

if(!fz)goto L5bd2;
goto L5bc4;
L5bc4: /* subq.w #3, D0 */

tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L5bc6;
L5bc6: /* bcc $5bca */

if(!fc)goto L5bca;
goto L5bc8;
L5bc8: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L5bca;
L5bca: /* subq.w #3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L5bcc;
L5bcc: /* bcc $5bf6 */

if(!fc)goto L5bf6;
goto L5bce;
L5bce: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5bd0;
L5bd0: /* bra $5bf6 */

goto L5bf6;
L5bd2: /* addq.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5bd4;
L5bd4: /* cmpi.w #$12, D0 */

tv=((u16)(18L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5bd8;
L5bd8: /* bcs $5bdc */

if(fc)goto L5bdc;
goto L5bda;
L5bda: /* moveq #$12, D0 */

v=((u32)(18L));
d[0]=v;

goto L5bdc;
L5bdc: /* sub.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L5bde;
L5bde: /* bcc $5bf6 */

if(!fc)goto L5bf6;
goto L5be0;
L5be0: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L5be2;
L5be2: /* bra $5bf6 */

goto L5bf6;
L5be4: /* addq.w #4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5be6;
L5be6: /* cmpi.w #$12, D1 */

tv=((u16)(18L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5bea;
L5bea: /* bcs $5bee */

if(fc)goto L5bee;
goto L5bec;
L5bec: /* moveq #$12, D1 */

v=((u32)(18L));
d[1]=v;

goto L5bee;
L5bee: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L5bf0;
L5bf0: /* bcc $5bf6 */

if(!fc)goto L5bf6;
goto L5bf2;
L5bf2: /* move.w #$0, D0 */

tv=((u16)(0L));
VWORD(d[0])=(u16)(tv);

goto L5bf6;
L5bf6: /* move.w $8f6e.l, D2 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[2])=(u16)(tv);

goto L5bfc;
L5bfc: /* lsr.w #4, D2 */

tv=((u16)(4L));
tw=((u16)d[2]);
tr=((u16)tw)>>4;
VWORD(d[2])=(u16)(tr);
goto L5bfe;
L5bfe: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L5c00;
L5c00: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L5c02;
L5c02: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5c04;
L5c04: /* bra $5c12 */

goto L5c12;
L5c12: /* move.w D0, ($2,A6) */

tv=((u16)d[0]);
ea=(2+a[6]);
vew16(ea,tv);

goto L5c16;
L5c16: /* move.w D1, ($4,A6) */

tv=((u16)d[1]);
ea=(4+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5c1a;
L5c1a: /* bsr $5980 */

a[7]-=4;STACK_WRITE(a[7],0x5c1eul);
goto L5980;
L5c1e: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L5c20;
L5c20: /* tst.w D1 */

tv=((u16)d[1]);
fz=(u8)((tv&0xfffful)==0);
goto L5c22;
L5c22: /* beq $5c40 */

if(fz)goto L5c40;
goto L5c24;
L5c24: /* moveq #$3, D2 */

v=((u32)(3L));
d[2]=v;

goto L5c26;
L5c26: /* tst.w D1 */

tv=((u16)d[1]);
fn=(u8)((tv&0x8000ul)!=0);
goto L5c28;
L5c28: /* bpl $5c2e */

if(!fn)goto L5c2e;
goto L5c2a;
L5c2a: /* moveq #$1, D2 */

v=((u32)(1L));
d[2]=v;

goto L5c2c;
L5c2c: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;fx=(u8)(tv>0);
VWORD(d[1])=(u16)(tr);
goto L5c2e;
L5c2e: /* cmpi.w #$6, D1 */

tv=((u16)(6L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5c32;
L5c32: /* bcs $5c40 */

if(fc)goto L5c40;
goto L5c34;
L5c34: /* move.w D2, D0 */

tv=((u16)d[2]);
VWORD(d[0])=(u16)(tv);

goto L5c36;
L5c36: /* cmpi.w #$c, D1 */

tv=((u16)(12L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5c3a;
L5c3a: /* bcs $5c40 */

if(fc)goto L5c40;
goto L5c3c;
L5c3c: /* addi.w #$1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5c40;
L5c40: /* move.w D0, ($12,A6) */

tv=((u16)d[0]);
ea=(18+a[6]);
vew16(ea,tv);

goto L5c44;
L5c44: /* move.w ($36,A6), D0 */

ea=(54+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5c48;
L5c48: /* beq $5c86 */

if(fz)goto L5c86;
goto L5c4c;
L5c4c: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L5c4e;
L5c4e: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L5c50;
L5c50: /* mulu.w #$4, D1 */

v=((u16)(4L));
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L5c54;
L5c54: /* divu.w #$5, D1 */

v=((u16)(5L));
w=((u32)d[1]);
if(!(u16)v){vm_fault=0xff;return 0;}
r=w;if((w>>16)>=(u16)v){fv=1;fn=1;fc=0;}else r=vehicle_div16_packed(w,v);
d[1]=r;
goto L5c58;
L5c58: /* move.w D1, ($36,A6) */

tv=((u16)d[1]);
ea=(54+a[6]);
vew16(ea,tv);

goto L5c5c;
L5c5c: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L5c5e;
L5c5e: /* lsr.w #3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
tr=((u16)tw)>>3;
VWORD(d[1])=(u16)(tr);
goto L5c60;
L5c60: /* cmpi.w #$3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5c64;
L5c64: /* bcs $5c6a */

if(fc)goto L5c6a;
goto L5c66;
L5c66: /* move.w #$2, D1 */

tv=((u16)(2L));
VWORD(d[1])=(u16)(tv);

goto L5c6a;
L5c6a: /* addi.w #$2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5c6e;
L5c6e: /* tst.w ($38,A6) */

ea=(56+a[6]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L5c72;
L5c72: /* bmi $5c7c */

if(fn)goto L5c7c;
goto L5c74;
L5c74: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L5c76;
L5c76: /* addi.w #$4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5c7a;
L5c7a: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L5c7c;
L5c7c: /* add.w D0, $9074.l */

tv=((u16)d[0]);
tw=(*(u16 *)(vehicle_state+854));
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
*(u16 *)(vehicle_state+854)=(u16)(tr);
goto L5c82;
L5c82: /* move.w D1, ($12,A6) */

tv=((u16)d[1]);
ea=(18+a[6]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5c86;
L5c86: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5c88: /* tst.w D7 */

tv=((u16)d[7]);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5c8a;
L5c8a: /* bne $4d18 */

if(!fz)return 0x4d18ul;
goto L5c8e;
L5c8e: /* movem.l D6-D7/A0-A3, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[3]);
a[7]-=4;
STACK_WRITE(a[7],a[2]);
a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],a[0]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
a[7]-=4;
STACK_WRITE(a[7],d[6]);
goto L5c92;
L5c92: /* bsr $5c9c */

a[7]-=4;STACK_WRITE(a[7],0x5c94ul);
goto L5c9c;
L5c94: /* movem.l (A7)+, D6-D7/A0-A3 */

ea=a[7];
d[6]=STACK_READ(ea+0);
d[7]=STACK_READ(ea+4);
a[0]=STACK_READ(ea+8);
a[1]=STACK_READ(ea+12);
a[2]=STACK_READ(ea+16);
a[3]=STACK_READ(ea+20);
a[7]+=24;
goto L5c98;
L5c98: /* bra $4d18 */

return 0x4d18ul;
L5c9c: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L5ca2;
L5ca2: /* move.w ($3c,A6), D0 */

ea=(60+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5ca6;
L5ca6: /* cmpi.w #$2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5caa;
L5caa: /* bcc $5e86 */

if(!fc)goto L5e86;
goto L5cae;
L5cae: /* tst.w D7 */

tv=((u16)d[7]);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5cb0;
L5cb0: /* bpl $5f58 */

if(!fn)goto L5f58;
goto L5cb4;
L5cb4: /* tst.w D0 */

tv=((u16)d[0]);
fz=(u8)((tv&0xfffful)==0);
goto L5cb6;
L5cb6: /* beq $5cde */

if(fz)goto L5cde;
goto L5cb8;
L5cb8: /* move.w ($12,A6), D0 */

ea=(18+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5cbc;
L5cbc: /* subi.w #$2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5cc0;
L5cc0: /* beq $5cd0 */

if(fz)goto L5cd0;
goto L5cc2;
L5cc2: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L5cc4;
L5cc4: /* swap D0 */

v=((u32)d[0]);
r=((v<<16)|(v>>16));
d[0]=r;

goto L5cc6;
L5cc6: /* move.w ($4e,A6), D1 */

ea=(78+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5cca;
L5cca: /* lsr.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=((u16)tw)>>1;
VWORD(d[1])=(u16)(tr);
goto L5ccc;
L5ccc: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5cce;
L5cce: /* bne $5cde */

if(!fz)goto L5cde;
goto L5cd0;
L5cd0: /* bsr $524e */

a[7]-=4;STACK_WRITE(a[7],0x5cd4ul);
goto L524e;
L5cd4: /* bsr $5406 */

a[7]-=4;STACK_WRITE(a[7],0x5cd8ul);
goto L5406;
L5cd8: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L5cde;
L5cde: /* move.w ($12,A6), D1 */

ea=(18+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5ce2;
L5ce2: /* add.w ($16,A6), D1 */

ea=(22+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5ce6;
L5ce6: /* move.w D1, D3 */

tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L5ce8;
L5ce8: /* lsl.w #2, D3 */

tv=((u16)(2L));
tw=((u16)d[3]);
tr=tw<<2;
VWORD(d[3])=(u16)(tr);
goto L5cea;
L5cea: /* lea $63d6.l, A4 */

a[4]=0x63d6ul;
goto L5cf0;
L5cf0: /* move.w #$74, D0 */

tv=((u16)(116L));
VWORD(d[0])=(u16)(tv);

goto L5cf4;
L5cf4: /* add.w (A4,D3.w), D0 */

ea=(a[4]+((s16)(d[3])));
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5cf8;
L5cf8: /* move.w #$91, D2 */

tv=((u16)(145L));
VWORD(d[2])=(u16)(tv);

goto L5cfc;
L5cfc: /* add.w ($2,A4,D3.w), D2 */

ea=(2+a[4]+((s16)(d[3])));
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d00;
L5d00: /* lea $3622e.l, A5 */

a[5]=0x3622eul;
goto L5d06;
L5d06: /* movem.l D1-D3/A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],d[3]);
a[7]-=4;
STACK_WRITE(a[7],d[2]);
a[7]-=4;
STACK_WRITE(a[7],d[1]);
goto L5d0a;
L5d0a: /* bsr $62a4 */

a[7]-=4;STACK_WRITE(a[7],0x5d0eul);
goto L62a4;
L5d0e: /* movem.l (A7)+, D1-D3/A6 */

ea=a[7];
d[1]=STACK_READ(ea+0);
d[2]=STACK_READ(ea+4);
d[3]=STACK_READ(ea+8);
a[6]=STACK_READ(ea+12);
a[7]+=16;
goto L5d12;
L5d12: /* lea $639a.l, A4 */

a[4]=0x639aul;
goto L5d18;
L5d18: /* move.w #$77, D0 */

tv=((u16)(119L));
VWORD(d[0])=(u16)(tv);

goto L5d1c;
L5d1c: /* add.w (A4,D3.w), D0 */

ea=(a[4]+((s16)(d[3])));
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5d20;
L5d20: /* move.w ($10,A6), D2 */

ea=(16+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L5d24;
L5d24: /* add.w ($2,A4,D3.w), D2 */

ea=(2+a[4]+((s16)(d[3])));
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d28;
L5d28: /* lea $2a41a.l, A5 */

a[5]=0x2a41aul;
goto L5d2e;
L5d2e: /* bsr $62ce */

a[7]-=4;STACK_WRITE(a[7],0x5d32ul);
goto L62ce;
L5d32: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L5d38;
L5d38: /* move.w ($26,A6), D0 */

ea=(38+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5d3c;
L5d3c: /* beq $5d68 */

if(fz)goto L5d68;
goto L5d3e;
L5d3e: /* subq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5d40;
L5d40: /* andi.w #$1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L5d44;
L5d44: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L5d46;
L5d46: /* move.w ($12,A6), D2 */

ea=(18+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L5d4a;
L5d4a: /* lsl.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw<<1;
VWORD(d[2])=(u16)(tr);
goto L5d4c;
L5d4c: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5d4e;
L5d4e: /* addi.w #$1d, D0 */

tv=((u16)(29L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5d52;
L5d52: /* mulu.w #$f, D1 */

v=((u16)(15L));
w=((u32)d[1]);
r=vehicle_mulu16(v,w);

d[1]=r;
goto L5d56;
L5d56: /* addi.w #$69, D1 */

tv=((u16)(105L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5d5a;
L5d5a: /* add.w ($16,A6), D1 */

ea=(22+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5d5e;
L5d5e: /* lea $2a41a.l, A5 */

a[5]=0x2a41aul;
goto L5d64;
L5d64: /* bsr $6206 */

a[7]-=4;STACK_WRITE(a[7],0x5d68ul);
goto L6206;
L5d68: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L5d6e;
L5d6e: /* tst.w ($18,A6) */

ea=(24+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5d72;
L5d72: /* bne $5dd8 */

if(!fz)goto L5dd8;
goto L5d74;
L5d74: /* tst.w $8f6e.l */

tv=(*(u16 *)(vehicle_state+592));
fz=(u8)((tv&0xfffful)==0);
goto L5d7a;
L5d7a: /* beq $5dd8 */

if(fz)goto L5dd8;
goto L5d7c;
L5d7c: /* move.w $8f62.l, D0 */

tv=(*(u16 *)(vehicle_state+580));
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5d82;
L5d82: /* beq $5d9a */

if(fz)goto L5d9a;
goto L5d84;
L5d84: /* cmpi.w #$2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto L5d88;
L5d88: /* beq $5da0 */

if(fz)goto L5da0;
goto L5d8a;
L5d8a: /* moveq #$1, D2 */

v=((u32)(1L));
d[2]=v;

goto L5d8c;
L5d8c: /* cmpi.w #$16d, $9074.l */

tv=((u16)(365L));
tw=(*(u16 *)(vehicle_state+854));
fc=(u8)((u16)tw<(u16)tv);
goto L5d94;
L5d94: /* bcc $5da2 */

if(!fc)goto L5da2;
goto L5d96;
L5d96: /* moveq #$2, D2 */

v=((u32)(2L));
d[2]=v;

goto L5d98;
L5d98: /* bra $5da2 */

goto L5da2;
L5d9a: /* tst.w ($32,A6) */

ea=(50+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5d9e;
L5d9e: /* beq $5dd8 */

if(fz)goto L5dd8;
goto L5da0;
L5da0: /* moveq #$3, D2 */

v=((u32)(3L));
d[2]=v;

goto L5da2;
L5da2: /* move.w ($24,A6), D0 */

ea=(36+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5da6;
L5da6: /* move.w ($16,A6), D1 */

ea=(22+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5daa;
L5daa: /* lea $2a41a.l, A5 */

a[5]=0x2a41aul;
goto L5db0;
L5db0: /* lsr.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;fc=(u8)((tw>>0)&1);
VWORD(d[2])=(u16)(tr);
goto L5db2;
L5db2: /* bcc $5dc8 */

if(!fc)goto L5dc8;
goto L5db4;
L5db4: /* movem.l D0-D2/A5-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],d[2]);
a[7]-=4;
STACK_WRITE(a[7],d[1]);
a[7]-=4;
STACK_WRITE(a[7],d[0]);
goto L5db8;
L5db8: /* addi.w #$19, D0 */

tv=((u16)(25L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5dbc;
L5dbc: /* addi.w #$4b, D1 */

tv=((u16)(75L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5dc0;
L5dc0: /* bsr $6206 */

a[7]-=4;STACK_WRITE(a[7],0x5dc4ul);
goto L6206;
L5dc4: /* movem.l (A7)+, D0-D2/A5-A6 */

ea=a[7];
d[0]=STACK_READ(ea+0);
d[1]=STACK_READ(ea+4);
d[2]=STACK_READ(ea+8);
a[5]=STACK_READ(ea+12);
a[6]=STACK_READ(ea+16);
a[7]+=20;
goto L5dc8;
L5dc8: /* lsr.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);
VWORD(d[2])=(u16)(tr);
goto L5dca;
L5dca: /* bcc $5dd8 */

if(!fc)goto L5dd8;
goto L5dcc;
L5dcc: /* addi.w #$15, D0 */

tv=((u16)(21L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5dd0;
L5dd0: /* addi.w #$5a, D1 */

tv=((u16)(90L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5dd4;
L5dd4: /* bsr $6206 */

a[7]-=4;STACK_WRITE(a[7],0x5dd8ul);
goto L6206;
L5dd8: /* move.w $8d28.l, D7 */

tv=(*(u16 *)(vehicle_state+10));
VWORD(d[7])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5dde;
L5dde: /* beq $5e54 */

if(fz)goto L5e54;
goto L5de0;
L5de0: /* lsr.w #2, D7 */

tv=((u16)(2L));
tw=((u16)d[7]);
tr=((u16)tw)>>2;
VWORD(d[7])=(u16)(tr);
goto L5de2;
L5de2: /* neg.w D7 */

tv=((u16)d[7]);
tr=0-tv;
VWORD(d[7])=(u16)(tr);
goto L5de4;
L5de4: /* addq.w #4, D7 */

tv=((u16)(4L));
tw=((u16)d[7]);
tr=tw+tv;
VWORD(d[7])=(u16)(tr);
goto L5de6;
L5de6: /* cmpi.w #$4, D7 */

tv=((u16)(4L));
tw=((u16)d[7]);
fc=(u8)((u16)tw<(u16)tv);
goto L5dea;
L5dea: /* bcs $5dee */

if(fc)goto L5dee;
goto L5dec;
L5dec: /* moveq #$3, D7 */

v=((u32)(3L));
d[7]=v;

goto L5dee;
L5dee: /* lea $6718.l, A0 */

a[0]=0x6718ul;
goto L5df4;
L5df4: /* movem.l D7/A0, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[0]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L5df8;
L5df8: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L5dfe;
L5dfe: /* move.w (A0), D0 */

ea=a[0];
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5e00;
L5e00: /* addq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5e02;
L5e02: /* cmpi.w #$c, D0 */

tv=((u16)(12L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5e06;
L5e06: /* bne $5e14 */

if(!fz)goto L5e14;
goto L5e08;
L5e08: /* bsr $421a */

a[7]-=4;STACK_WRITE(a[7],0x5e0cul);
return 0x421aul;
L5e0c: /* andi.w #$f, D0 */

tv=((u16)(15L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L5e10;
L5e10: /* addi.w #$c, D0 */

tv=((u16)(12L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5e14;
L5e14: /* cmpi.w #$14, D0 */

tv=((u16)(20L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5e18;
L5e18: /* bcs $5e1c */

if(fc)goto L5e1c;
goto L5e1a;
L5e1a: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L5e1c;
L5e1c: /* move.w D0, (A0)+ */

tv=((u16)d[0]);
ea=a[0];
vew16(ea,tv);
a[0]+=2;

goto L5e1e;
L5e1e: /* lsr.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;fx=(u8)((tw>>0)&1);
VWORD(d[0])=(u16)(tr);
goto L5e20;
L5e20: /* cmpi.w #$6, D0 */

tv=((u16)(6L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5e24;
L5e24: /* bcc $5e48 */

if(!fc)goto L5e48;
goto L5e26;
L5e26: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L5e28;
L5e28: /* lsl.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw<<2;
VWORD(d[1])=(u16)(tr);
goto L5e2a;
L5e2a: /* move.w (A0,D1.w), D2 */

ea=(a[0]+((s16)(d[1])));
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L5e2e;
L5e2e: /* move.w ($2,A0,D1.w), D3 */

ea=(2+a[0]+((s16)(d[1])));
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L5e32;
L5e32: /* addi.w #$27, D0 */

tv=((u16)(39L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5e36;
L5e36: /* move.w #$87, D1 */

tv=((u16)(135L));
VWORD(d[1])=(u16)(tv);

goto L5e3a;
L5e3a: /* add.w ($16,A6), D1 */

ea=(22+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5e3e;
L5e3e: /* lea $2a41a.l, A5 */

a[5]=0x2a41aul;
goto L5e44;
L5e44: /* bsr $6266 */

a[7]-=4;STACK_WRITE(a[7],0x5e48ul);
goto L6266;
L5e48: /* movem.l (A7)+, D7/A0 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[0]=STACK_READ(ea+4);
a[7]+=8;
goto L5e4c;
L5e4c: /* lea ($1a,A0), A0 */

a[0]=(26+a[0]);
goto L5e50;
L5e50: /* dbra D7, $5df4 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L5df4;
goto L5e54;
L5e54: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L5e5a;
L5e5a: /* tst.w ($3c,A6) */

ea=(60+a[6]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5e5e;
L5e5e: /* beq $5f58 */

if(fz)goto L5f58;
goto L5e62;
L5e62: /* move.w ($12,A6), D0 */

ea=(18+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5e66;
L5e66: /* subi.w #$2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5e6a;
L5e6a: /* beq $5f58 */

if(fz)goto L5f58;
goto L5e6e;
L5e6e: /* ext.l D0 */

v=((u32)d[0]);
r=(s32)(s16)v;
d[0]=r;

goto L5e70;
L5e70: /* swap D0 */

v=((u32)d[0]);
r=((v<<16)|(v>>16));
d[0]=r;

goto L5e72;
L5e72: /* move.w ($4e,A6), D1 */

ea=(78+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5e76;
L5e76: /* lsr.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=((u16)tw)>>1;
VWORD(d[1])=(u16)(tr);
goto L5e78;
L5e78: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5e7a;
L5e7a: /* beq $5f58 */

if(fz)goto L5f58;
goto L5e7e;
L5e7e: /* bsr $524e */

a[7]-=4;STACK_WRITE(a[7],0x5e82ul);
goto L524e;
L5e82: /* bra $5406 */

goto L5406;
L5e86: /* tst.w D7 */

tv=((u16)d[7]);
fn=(u8)((tv&0x8000ul)!=0);
goto L5e88;
L5e88: /* bmi $5406 */

if(fn)goto L5406;
goto L5e8c;
L5e8c: /* moveq #$5, D0 */

v=((u32)(5L));
d[0]=v;

goto L5e8e;
L5e8e: /* cmpi.w #$3, ($3c,A6) */

tv=((u16)(3L));
eb=(60+a[6]);
tw=ver16(eb);
fz=(u8)((u16)tw==(u16)tv);
goto L5e94;
L5e94: /* beq $5eca */

if(fz)goto L5eca;
goto L5e96;
L5e96: /* move.w ($50,A6), D1 */

ea=(80+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5e9a;
L5e9a: /* move.w D1, D2 */

tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L5e9c;
L5e9c: /* sub.w ($46,A6), D1 */

ea=(70+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L5ea0;
L5ea0: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;fx=(u8)((tw>>1)&1);
VWORD(d[2])=(u16)(tr);
goto L5ea2;
L5ea2: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L5ea4;
L5ea4: /* cmp.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5ea6;
L5ea6: /* bcs $5eca */

if(fc)goto L5eca;
goto L5ea8;
L5ea8: /* moveq #$4, D0 */

v=((u32)(4L));
d[0]=v;

goto L5eaa;
L5eaa: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5eac;
L5eac: /* cmp.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5eae;
L5eae: /* bcs $5eca */

if(fc)goto L5eca;
goto L5eb0;
L5eb0: /* moveq #$3, D0 */

v=((u32)(3L));
d[0]=v;

goto L5eb2;
L5eb2: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5eb4;
L5eb4: /* cmp.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5eb6;
L5eb6: /* bcs $5eca */

if(fc)goto L5eca;
goto L5eb8;
L5eb8: /* moveq #$2, D0 */

v=((u32)(2L));
d[0]=v;

goto L5eba;
L5eba: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5ebc;
L5ebc: /* cmp.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5ebe;
L5ebe: /* bcs $5eca */

if(fc)goto L5eca;
goto L5ec0;
L5ec0: /* moveq #$1, D0 */

v=((u32)(1L));
d[0]=v;

goto L5ec2;
L5ec2: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5ec4;
L5ec4: /* cmp.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5ec6;
L5ec6: /* bcs $5eca */

if(fc)goto L5eca;
goto L5ec8;
L5ec8: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L5eca;
L5eca: /* lea $6346.l, A4 */

a[4]=0x6346ul;
goto L5ed0;
L5ed0: /* tst.w ($4e,A6) */

ea=(78+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L5ed4;
L5ed4: /* bne $5edc */

if(!fz)goto L5edc;
goto L5ed6;
L5ed6: /* lea $62f2.l, A4 */

a[4]=0x62f2ul;
goto L5edc;
L5edc: /* mulu.w #$e, D0 */

v=((u16)(14L));
w=((u32)d[0]);
r=vehicle_mulu16(v,w);

d[0]=r;
goto L5ee0;
L5ee0: /* lea (A4,D0.w), A4 */

a[4]=(a[4]+((s16)(d[0])));
goto L5ee4;
L5ee4: /* cmpi.w #$3, ($3c,A6) */

tv=((u16)(3L));
eb=(60+a[6]);
tw=ver16(eb);
fz=(u8)((u16)tw==(u16)tv);
goto L5eea;
L5eea: /* beq $5efc */

if(fz)goto L5efc;
goto L5eec;
L5eec: /* tst.w (A4) */

ea=a[4];
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5eee;
L5eee: /* bne $5efc */

if(!fz)goto L5efc;
goto L5ef0;
L5ef0: /* movem.l A4/A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[4]);
goto L5ef4;
L5ef4: /* bsr $524e */

a[7]-=4;STACK_WRITE(a[7],0x5ef8ul);
goto L524e;
L5ef8: /* movem.l (A7)+, A4/A6 */

ea=a[7];
a[4]=STACK_READ(ea+0);
a[6]=STACK_READ(ea+4);
a[7]+=8;
goto L5efc;
L5efc: /* move.w ($2,A4), D1 */

ea=(2+a[4]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L5f00;
L5f00: /* bmi $5f24 */

if(fn)goto L5f24;
goto L5f02;
L5f02: /* move.w ($40,A6), D0 */

ea=(64+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5f06;
L5f06: /* move.w ($42,A6), D2 */

ea=(66+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L5f0a;
L5f0a: /* add.w ($4,A4), D0 */

ea=(4+a[4]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5f0e;
L5f0e: /* add.w ($6,A4), D2 */

ea=(6+a[4]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5f12;
L5f12: /* movem.l A4/A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[4]);
goto L5f16;
L5f16: /* lea $3622e.l, A5 */

a[5]=0x3622eul;
goto L5f1c;
L5f1c: /* bsr $62a4 */

a[7]-=4;STACK_WRITE(a[7],0x5f20ul);
goto L62a4;
L5f20: /* movem.l (A7)+, A4/A6 */

ea=a[7];
a[4]=STACK_READ(ea+0);
a[6]=STACK_READ(ea+4);
a[7]+=8;
goto L5f24;
L5f24: /* move.w ($8,A4), D1 */

ea=(8+a[4]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5f28;
L5f28: /* move.w ($40,A6), D0 */

ea=(64+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5f2c;
L5f2c: /* move.w ($42,A6), D2 */

ea=(66+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L5f30;
L5f30: /* add.w ($a,A4), D0 */

ea=(10+a[4]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5f34;
L5f34: /* add.w ($c,A4), D2 */

ea=(12+a[4]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5f38;
L5f38: /* movem.l A4/A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[4]);
goto L5f3c;
L5f3c: /* lea $2a41a.l, A5 */

a[5]=0x2a41aul;
goto L5f42;
L5f42: /* bsr $62ce */

a[7]-=4;STACK_WRITE(a[7],0x5f46ul);
goto L62ce;
L5f46: /* movem.l (A7)+, A4/A6 */

ea=a[7];
a[4]=STACK_READ(ea+0);
a[6]=STACK_READ(ea+4);
a[7]+=8;
goto L5f4a;
L5f4a: /* cmpi.w #$3, ($3c,A6) */

tv=((u16)(3L));
eb=(60+a[6]);
tw=ver16(eb);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5f50;
L5f50: /* beq $5f58 */

if(fz)goto L5f58;
goto L5f52;
L5f52: /* tst.w (A4) */

ea=a[4];
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5f54;
L5f54: /* bne $524e */

if(!fz)goto L524e;
goto L5f58;
L5f58: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L5f5a: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L5f60;
L5f60: /* move.w ($20,A6), D1 */

ea=(32+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L5f64;
L5f64: /* move.w D1, D2 */

tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L5f66;
L5f66: /* sub.w ($10,A6), D1 */

ea=(16+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L5f6a;
L5f6a: /* lsr.w #4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=((u16)tw)>>4;
VWORD(d[1])=(u16)(tr);
goto L5f6c;
L5f6c: /* cmpi.w #$4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5f70;
L5f70: /* bcs $5f76 */

if(fc)goto L5f76;
goto L5f72;
L5f72: /* move.w #$4, D1 */

tv=((u16)(4L));
VWORD(d[1])=(u16)(tv);

goto L5f76;
L5f76: /* move.w D1, D3 */

tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L5f78;
L5f78: /* lsl.w #2, D3 */

tv=((u16)(2L));
tw=((u16)d[3]);
tr=tw<<2;
VWORD(d[3])=(u16)(tr);
goto L5f7a;
L5f7a: /* lea $6704.l, A1 */

a[1]=0x6704ul;
goto L5f80;
L5f80: /* move.w #$5a, D0 */

tv=((u16)(90L));
VWORD(d[0])=(u16)(tv);

goto L5f84;
L5f84: /* add.w (A1,D3.w), D0 */

ea=(a[1]+((s16)(d[3])));
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5f88;
L5f88: /* lea $358b0.l, A5 */

a[5]=0x358b0ul;
goto L5f8e;
L5f8e: /* bra $62a4 */

goto L62a4;
L5f92: /* lea $8dfc.l, A6 */

a[6]=0x8dfcul;
goto L5f98;
L5f98: /* lea $35d4c.l, A5 */

a[5]=0x35d4cul;
goto L5f9e;
L5f9e: /* moveq #$2, D7 */

v=((u32)(2L));
d[7]=v;

goto L5fa0;
L5fa0: /* move.w ($0,A6), D1 */

ea=(0+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5fa4;
L5fa4: /* bne $5fb0 */

if(!fz)goto L5fb0;
goto L5fa6;
L5fa6: /* lea ($6,A6), A6 */

a[6]=(6+a[6]);
goto L5faa;
L5faa: /* dbra D7, $5fa0 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L5fa0;
goto L5fae;
L5fae: /* bra $5ff2 */

goto L5ff2;
L5fb0: /* cmpi.w #$9, D1 */

tv=((u16)(9L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5fb4;
L5fb4: /* bcs $5fbe */

if(fc)goto L5fbe;
goto L5fb6;
L5fb6: /* move.w #$0, ($0,A6) */

tv=((u16)(0L));
ea=(0+a[6]);
vew16(ea,tv);

goto L5fbc;
L5fbc: /* bra $5fa6 */

goto L5fa6;
L5fbe: /* addq.w #1, ($0,A6) */

tv=((u16)(1L));
eb=(0+a[6]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L5fc2;
L5fc2: /* subq.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L5fc4;
L5fc4: /* lsr.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=((u16)tw)>>1;
VWORD(d[1])=(u16)(tr);
goto L5fc6;
L5fc6: /* lea $66f4.l, A0 */

a[0]=0x66f4ul;
goto L5fcc;
L5fcc: /* move.w D1, D3 */

tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L5fce;
L5fce: /* lsl.w #2, D3 */

tv=((u16)(2L));
tw=((u16)d[3]);
tr=tw<<2;
VWORD(d[3])=(u16)(tr);
goto L5fd0;
L5fd0: /* addi.w #$11, D1 */

tv=((u16)(17L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5fd4;
L5fd4: /* move.w ($2,A6), D0 */

ea=(2+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L5fd8;
L5fd8: /* add.w (A0,D3.w), D0 */

ea=(a[0]+((s16)(d[3])));
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5fdc;
L5fdc: /* move.w ($4,A6), D2 */

ea=(4+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L5fe0;
L5fe0: /* add.w ($2,A0,D3.w), D2 */

ea=(2+a[0]+((s16)(d[3])));
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5fe4;
L5fe4: /* movem.l D7/A5-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L5fe8;
L5fe8: /* bsr $62ce */

a[7]-=4;STACK_WRITE(a[7],0x5fecul);
goto L62ce;
L5fec: /* movem.l (A7)+, D7/A5-A6 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[5]=STACK_READ(ea+4);
a[6]=STACK_READ(ea+8);
a[7]+=12;
goto L5ff0;
L5ff0: /* bra $5fa6 */

goto L5fa6;
L5ff2: /* lea $8dc0.l, A6 */

a[6]=0x8dc0ul;
goto L5ff8;
L5ff8: /* lea $42592.l, A5 */

a[5]=0x42592ul;
goto L5ffe;
L5ffe: /* moveq #$2, D7 */

v=((u32)(2L));
d[7]=v;

goto L6000;
L6000: /* tst.w ($0,A6) */

ea=(0+a[6]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L6004;
L6004: /* bne $6012 */

if(!fz)goto L6012;
goto L6006;
L6006: /* lea ($14,A6), A6 */

a[6]=(20+a[6]);
goto L600a;
L600a: /* dbra D7, $6000 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L6000;
goto L600e;
L600e: /* bra $60c6 */

goto L60c6;
L6012: /* subq.w #1, ($0,A6) */

tv=((u16)(1L));
eb=(0+a[6]);
tw=ver16(eb);
tr=tw-tv;
vew16(eb,tr);
goto L6016;
L6016: /* move.w ($2,A6), D1 */

ea=(2+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L601a;
L601a: /* cmpi.w #$3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L601e;
L601e: /* bcc $603a */

if(!fc)goto L603a;
goto L6020;
L6020: /* addq.w #1, ($2,A6) */

tv=((u16)(1L));
eb=(2+a[6]);
tw=ver16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vew16(eb,tr);
goto L6024;
L6024: /* move.w ($4,A6), D0 */

ea=(4+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6028;
L6028: /* move.w ($6,A6), D2 */

ea=(6+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L602c;
L602c: /* movem.l D7/A5-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L6030;
L6030: /* bsr $62ce */

a[7]-=4;STACK_WRITE(a[7],0x6034ul);
goto L62ce;
L6034: /* movem.l (A7)+, D7/A5-A6 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[5]=STACK_READ(ea+4);
a[6]=STACK_READ(ea+8);
a[7]+=12;
goto L6038;
L6038: /* bra $6006 */

goto L6006;
L603a: /* move.w ($4,A6), D0 */

ea=(4+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L603e;
L603e: /* move.w ($6,A6), D2 */

ea=(6+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L6042;
L6042: /* moveq #$5, D1 */

v=((u32)(5L));
d[1]=v;

goto L6044;
L6044: /* subi.w #$10, ($4,A6) */

tv=((u16)(16L));
eb=(4+a[6]);
tw=ver16(eb);
tr=tw-tv;
vew16(eb,tr);
goto L604a;
L604a: /* addi.w #$10, ($6,A6) */

tv=((u16)(16L));
eb=(6+a[6]);
tw=ver16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
vew16(eb,tr);
goto L6050;
L6050: /* movem.l D7/A5-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L6054;
L6054: /* bsr $62c6 */

a[7]-=4;STACK_WRITE(a[7],0x6058ul);
goto L62c6;
L6058: /* movem.l (A7)+, D7/A5-A6 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[5]=STACK_READ(ea+4);
a[6]=STACK_READ(ea+8);
a[7]+=12;
goto L605c;
L605c: /* move.w ($8,A6), D0 */

ea=(8+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6060;
L6060: /* move.w ($a,A6), D2 */

ea=(10+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L6064;
L6064: /* moveq #$6, D1 */

v=((u32)(6L));
d[1]=v;

goto L6066;
L6066: /* addi.w #$10, ($8,A6) */

tv=((u16)(16L));
eb=(8+a[6]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L606c;
L606c: /* addi.w #$10, ($a,A6) */

tv=((u16)(16L));
eb=(10+a[6]);
tw=ver16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
vew16(eb,tr);
goto L6072;
L6072: /* movem.l D7/A5-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L6076;
L6076: /* bsr $62c6 */

a[7]-=4;STACK_WRITE(a[7],0x607aul);
goto L62c6;
L607a: /* movem.l (A7)+, D7/A5-A6 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[5]=STACK_READ(ea+4);
a[6]=STACK_READ(ea+8);
a[7]+=12;
goto L607e;
L607e: /* move.w ($c,A6), D0 */

ea=(12+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6082;
L6082: /* move.w ($e,A6), D2 */

ea=(14+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L6086;
L6086: /* moveq #$3, D1 */

v=((u32)(3L));
d[1]=v;

goto L6088;
L6088: /* addi.w #$10, ($c,A6) */

tv=((u16)(16L));
eb=(12+a[6]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L608e;
L608e: /* subi.w #$10, ($e,A6) */

tv=((u16)(16L));
eb=(14+a[6]);
tw=ver16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vew16(eb,tr);
goto L6094;
L6094: /* movem.l D7/A5-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L6098;
L6098: /* bsr $62c6 */

a[7]-=4;STACK_WRITE(a[7],0x609cul);
goto L62c6;
L609c: /* movem.l (A7)+, D7/A5-A6 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[5]=STACK_READ(ea+4);
a[6]=STACK_READ(ea+8);
a[7]+=12;
goto L60a0;
L60a0: /* move.w ($10,A6), D0 */

ea=(16+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L60a4;
L60a4: /* move.w ($12,A6), D2 */

ea=(18+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L60a8;
L60a8: /* moveq #$4, D1 */

v=((u32)(4L));
d[1]=v;

goto L60aa;
L60aa: /* subi.w #$10, ($10,A6) */

tv=((u16)(16L));
eb=(16+a[6]);
tw=ver16(eb);
tr=tw-tv;
vew16(eb,tr);
goto L60b0;
L60b0: /* subi.w #$10, ($12,A6) */

tv=((u16)(16L));
eb=(18+a[6]);
tw=ver16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vew16(eb,tr);
goto L60b6;
L60b6: /* movem.l D7/A5-A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],a[5]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L60ba;
L60ba: /* bsr $62c6 */

a[7]-=4;STACK_WRITE(a[7],0x60beul);
goto L62c6;
L60be: /* movem.l (A7)+, D7/A5-A6 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[5]=STACK_READ(ea+4);
a[6]=STACK_READ(ea+8);
a[7]+=12;
goto L60c2;
L60c2: /* bra $6006 */

goto L6006;
L60c6: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L60cc;
L60cc: /* cmpi.w #$a, ($1e,A6) */

tv=((u16)(10L));
eb=(30+a[6]);
tw=ver16(eb);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L60d2;
L60d2: /* bne $60d8 */

if(!fz)goto L60d8;
goto L60d4;
L60d4: /* bsr $61de */

a[7]-=4;STACK_WRITE(a[7],0x60d8ul);
goto L61de;
L60d8: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L60de;
L60de: /* lea $6412.l, A5 */

a[5]=0x6412ul;
goto L60e4;
L60e4: /* move.w ($12,A6), D1 */

ea=(18+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L60e8;
L60e8: /* add.w ($1e,A6), D1 */

ea=(30+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L60ec;
L60ec: /* move.w D1, D3 */

tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L60ee;
L60ee: /* lsl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L60f0;
L60f0: /* move.w (A5,D3.w), D2 */

ea=(a[5]+((s16)(d[3])));
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L60f4;
L60f4: /* move.w #$62, D0 */

tv=((u16)(98L));
VWORD(d[0])=(u16)(tv);

goto L60f8;
L60f8: /* add.w ($10,A6), D2 */

ea=(16+a[6]);
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L60fc;
L60fc: /* lea $2a41a.l, A5 */

a[5]=0x2a41aul;
goto L6102;
L6102: /* bsr $62ce */

a[7]-=4;STACK_WRITE(a[7],0x6106ul);
goto L62ce;
L6106: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L610c;
L610c: /* move.w ($26,A6), D0 */

ea=(38+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L6110;
L6110: /* beq $6132 */

if(fz)goto L6132;
goto L6112;
L6112: /* move.w #$7, D2 */

tv=((u16)(7L));
VWORD(d[2])=(u16)(tv);

goto L6116;
L6116: /* move.w ($1e,A6), D1 */

ea=(30+a[6]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L611a;
L611a: /* beq $612a */

if(fz)goto L612a;
goto L611c;
L611c: /* move.w #$d, D2 */

tv=((u16)(13L));
VWORD(d[2])=(u16)(tv);

goto L6120;
L6120: /* cmpi.w #$9, D1 */

tv=((u16)(9L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L6124;
L6124: /* bcc $612a */

if(!fc)goto L612a;
goto L6126;
L6126: /* move.w #$a, D2 */

tv=((u16)(10L));
VWORD(d[2])=(u16)(tv);

goto L612a;
L612a: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L612c;
L612c: /* moveq #$1e, D1 */

v=((u32)(30L));
d[1]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L612e;
L612e: /* bsr $61fc */

a[7]-=4;STACK_WRITE(a[7],0x6132ul);
goto L61fc;
L6132: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L6138;
L6138: /* move.w ($28,A6), D0 */

ea=(40+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L613c;
L613c: /* beq $616e */

if(fz)goto L616e;
goto L613e;
L613e: /* addi.w #-$1, D0 */

tv=((u16)(-1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L6142;
L6142: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L6144;
L6144: /* bsr $61fc */

a[7]-=4;STACK_WRITE(a[7],0x6148ul);
goto L61fc;
L6148: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L614e;
L614e: /* move.w ($28,A6), D0 */

ea=(40+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6152;
L6152: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L6154;
L6154: /* addq.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L6156;
L6156: /* cmpi.w #$5, D1 */

tv=((u16)(5L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L615a;
L615a: /* bcs $6160 */

if(fc)goto L6160;
goto L615e;
L615e: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L6160;
L6160: /* move.w D1, ($28,A6) */

tv=((u16)d[1]);
ea=(40+a[6]);
vew16(ea,tv);

goto L6164;
L6164: /* addi.w #-$1, D0 */

tv=((u16)(-1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L6168;
L6168: /* moveq #$f, D1 */

v=((u32)(15L));
d[1]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L616a;
L616a: /* bsr $61fc */

a[7]-=4;STACK_WRITE(a[7],0x616eul);
goto L61fc;
L616e: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L6174;
L6174: /* cmpi.w #$a, ($1e,A6) */

tv=((u16)(10L));
eb=(30+a[6]);
tw=ver16(eb);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L617a;
L617a: /* beq $617e */

if(fz)goto L617e;
goto L617c;
L617c: /* bsr $61de */

a[7]-=4;STACK_WRITE(a[7],0x617eul);
goto L61de;
L617e: /* tst.w $8d38.l */

tv=(*(u16 *)(vehicle_state+26));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6184;
L6184: /* beq $61dc */

if(fz)goto L61dc;
goto L6186;
L6186: /* subq.w #1, $8d38.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+26));
tr=tw-tv;fz=(u8)((tr&0xfffful)==0);
*(u16 *)(vehicle_state+26)=(u16)(tr);
goto L618c;
L618c: /* bne $6196 */

if(!fz)goto L6196;
goto L618e;
L618e: /* move.w #$2, $8f66.l */

tv=((u16)(2L));
*(u16 *)(vehicle_state+584)=(u16)(tv);

goto L6196;
L6196: /* lea $6688.l, A1 */

a[1]=0x6688ul;
goto L619c;
L619c: /* moveq #$5, D7 */

v=((u32)(5L));
d[7]=v;

goto L619e;
L619e: /* movem.l D7/A1, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[1]);
a[7]-=4;
STACK_WRITE(a[7],d[7]);
goto L61a2;
L61a2: /* move.w (A1), D0 */

ea=a[1];
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L61a4;
L61a4: /* addq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L61a6;
L61a6: /* cmpi.w #$c, D0 */

tv=((u16)(12L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L61aa;
L61aa: /* bcs $61b4 */

if(fc)goto L61b4;
goto L61ac;
L61ac: /* moveq #$d, D0 */

v=((u32)(13L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L61ae;
L61ae: /* bsr $3c92 */

a[7]-=4;STACK_WRITE(a[7],0x61b2ul);
return 0x3c92ul;
L61b2: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L61b4;
L61b4: /* move.w D0, (A1)+ */

tv=((u16)d[0]);
ea=a[1];
vew16(ea,tv);
a[1]+=2;

goto L61b6;
L61b6: /* cmpi.w #$4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L61ba;
L61ba: /* bcc $61d0 */

if(!fc)goto L61d0;
goto L61bc;
L61bc: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L61be;
L61be: /* addi.w #$11, D0 */

tv=((u16)(17L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L61c2;
L61c2: /* lea $35d4c.l, A5 */

a[5]=0x35d4cul;
goto L61c8;
L61c8: /* lea $8d5c.l, A6 */

a[6]=0x8d5cul;
goto L61ce;
L61ce: /* bsr $6210 */

a[7]-=4;STACK_WRITE(a[7],0x61d0ul);
goto L6210;
L61d0: /* movem.l (A7)+, D7/A1 */

ea=a[7];
d[7]=STACK_READ(ea+0);
a[1]=STACK_READ(ea+4);
a[7]+=8;
goto L61d4;
L61d4: /* lea ($12,A1), A1 */

a[1]=(18+a[1]);
goto L61d8;
L61d8: /* dbra D7, $619e */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L619e;
goto L61dc;
L61dc: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L61de: /* move.w $8d28.l, D3 */

tv=(*(u16 *)(vehicle_state+10));
VWORD(d[3])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L61e4;
L61e4: /* beq $61dc */

if(fz)goto L61dc;
goto L61e6;
L61e6: /* move.w ($22,A6), D0 */

ea=(34+a[6]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L61ea;
L61ea: /* addq.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L61ec;
L61ec: /* moveq #$2d, D1 */

v=((u32)(45L));
d[1]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L61ee;
L61ee: /* movem.l D0-D3/A6, -(A7) */

a[7]-=4;
STACK_WRITE(a[7],a[6]);
a[7]-=4;
STACK_WRITE(a[7],d[3]);
a[7]-=4;
STACK_WRITE(a[7],d[2]);
a[7]-=4;
STACK_WRITE(a[7],d[1]);
a[7]-=4;
STACK_WRITE(a[7],d[0]);
goto L61f2;
L61f2: /* bsr $6240 */

a[7]-=4;STACK_WRITE(a[7],0x61f4ul);
goto L6240;
L61f4: /* movem.l (A7)+, D0-D3/A6 */

ea=a[7];
d[0]=STACK_READ(ea+0);
d[1]=STACK_READ(ea+4);
d[2]=STACK_READ(ea+8);
d[3]=STACK_READ(ea+12);
a[6]=STACK_READ(ea+16);
a[7]+=20;
goto L61f8;
L61f8: /* moveq #$3c, D1 */

v=((u32)(60L));
d[1]=v;

goto L61fa;
L61fa: /* bra $6240 */

goto L6240;
L61fc: /* lea $35d4c.l, A5 */

a[5]=0x35d4cul;
goto L6202;
L6202: /* add.w ($1e,A6), D1 */

ea=(30+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L6206;
L6206: /* add.w ($12,A6), D1 */

ea=(18+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L620a;
L620a: /* lea $6430.l, A1 */

a[1]=0x6430ul;
goto L6210;
L6210: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;
VWORD(d[0])=(u16)(tr);
goto L6212;
L6212: /* lsl.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw<<2;fx=(u8)((tw>>14)&1);
VWORD(d[1])=(u16)(tr);
goto L6214;
L6214: /* lea ($2,A5,D0.w), A5 */

a[5]=(2+a[5]+((s16)(d[0])));
goto L6218;
L6218: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L621a;
L621a: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L621c;
L621c: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L621e;
L621e: /* move.w #$62, D0 */

tv=((u16)(98L));
VWORD(d[0])=(u16)(tv);

goto L6222;
L6222: /* move.w (A1,D1.w), D2 */

ea=(a[1]+((s16)(d[1])));
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L6226;
L6226: /* cmpi.w #$64, D2 */

tv=((u16)(100L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L622a;
L622a: /* beq $623e */

if(fz)goto L623e;
goto L622c;
L622c: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L622e;
L622e: /* move.w ($10,A6), D2 */

ea=(16+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L6232;
L6232: /* add.w ($2,A1,D1.w), D2 */

ea=(2+a[1]+((s16)(d[1])));
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L6236;
L6236: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L6238;
L6238: /* move.w D3, D6 */

tv=((u16)d[3]);
VWORD(d[6])=(u16)(tv);

goto L623a;
L623a: /* bra $4e20 */

return 0x4e20ul;
L623e: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6240: /* lea $35d4c.l, A5 */

a[5]=0x35d4cul;
goto L6246;
L6246: /* add.w ($1e,A6), D1 */

ea=(30+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L624a;
L624a: /* add.w ($12,A6), D1 */

ea=(18+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L624e;
L624e: /* lea $6430.l, A1 */

a[1]=0x6430ul;
goto L6254;
L6254: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;
VWORD(d[0])=(u16)(tr);
goto L6256;
L6256: /* lsl.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw<<2;
VWORD(d[1])=(u16)(tr);
goto L6258;
L6258: /* lea ($2,A5,D0.w), A5 */

a[5]=(2+a[5]+((s16)(d[0])));
goto L625c;
L625c: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L625e;
L625e: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L6260;
L6260: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L6262;
L6262: /* sub.w D3, D7 */

tv=((u16)d[3]);
tw=((u16)d[7]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[7])=(u16)(tr);
goto L6264;
L6264: /* bra $621e */

goto L621e;
L6266: /* add.w ($12,A6), D1 */

ea=(18+a[6]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L626a;
L626a: /* lea $6430.l, A1 */

a[1]=0x6430ul;
goto L6270;
L6270: /* lsl.w #4, D0 */

tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw<<4;
VWORD(d[0])=(u16)(tr);
goto L6272;
L6272: /* lsl.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw<<2;
VWORD(d[1])=(u16)(tr);
goto L6274;
L6274: /* lea ($2,A5,D0.w), A5 */

a[5]=(2+a[5]+((s16)(d[0])));
goto L6278;
L6278: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L627a;
L627a: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L627c;
L627c: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L627e;
L627e: /* move.w #$62, D0 */

tv=((u16)(98L));
VWORD(d[0])=(u16)(tv);

goto L6282;
L6282: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L6284;
L6284: /* move.w (A1,D1.w), D2 */

ea=(a[1]+((s16)(d[1])));
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L6288;
L6288: /* cmpi.w #$64, D2 */

tv=((u16)(100L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L628c;
L628c: /* beq $62a2 */

if(fz)goto L62a2;
goto L628e;
L628e: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6290;
L6290: /* move.w ($10,A6), D2 */

ea=(16+a[6]);
tv=ver16(ea);
VWORD(d[2])=(u16)(tv);

goto L6294;
L6294: /* add.w D3, D2 */

tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L6296;
L6296: /* add.w ($2,A1,D1.w), D2 */

ea=(2+a[1]+((s16)(d[1])));
tv=ver16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L629a;
L629a: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L629c;
L629c: /* move.w D3, D6 */

tv=((u16)d[3]);
VWORD(d[6])=(u16)(tv);

goto L629e;
L629e: /* bra $4e20 */

return 0x4e20ul;
L62a2: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L62a4: /* lsl.w #4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw<<4;fx=(u8)((tw>>12)&1);
VWORD(d[1])=(u16)(tr);
goto L62a6;
L62a6: /* lea (A5,D1.w), A5 */

a[5]=(a[5]+((s16)(d[1])));
goto L62aa;
L62aa: /* move.w (A5)+, D1 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[1])=(u16)(tv);

goto L62ac;
L62ac: /* cmpi.w #$140, D0 */

tv=((u16)(320L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L62b0;
L62b0: /* bcs $62ba */

if(fc)goto L62ba;
goto L62b2;
L62b2: /* bpl $62b8 */

if(!fn)goto L62b8;
goto L62b4;
L62b4: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L62b6;
L62b6: /* bpl $62ba */

if(!fn)goto L62ba;
goto L62b8;
L62b8: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L62ba: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L62bc;
L62bc: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L62be;
L62be: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L62c0;
L62c0: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L62c2;
L62c2: /* bra $4e56 */

return 0x4e56ul;
L62c6: /* cmpi.w #$98, D2 */

tv=((u16)(152L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L62ca;
L62ca: /* bcs $62ce */

if(fc)goto L62ce;
goto L62cc;
L62cc: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L62ce: /* lsl.w #4, D1 */

tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw<<4;fx=(u8)((tw>>12)&1);
VWORD(d[1])=(u16)(tr);
goto L62d0;
L62d0: /* lea (A5,D1.w), A5 */

a[5]=(a[5]+((s16)(d[1])));
goto L62d4;
L62d4: /* move.w (A5)+, D1 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[1])=(u16)(tv);

goto L62d6;
L62d6: /* cmpi.w #$140, D0 */

tv=((u16)(320L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L62da;
L62da: /* bcs $62e4 */

if(fc)goto L62e4;
goto L62dc;
L62dc: /* bpl $62e2 */

if(!fn)goto L62e2;
goto L62de;
L62de: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L62e0;
L62e0: /* bpl $62e4 */

if(!fn)goto L62e4;
goto L62e2;
L62e2: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L62e4: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L62e6;
L62e6: /* move.w D3, D6 */

tv=((u16)d[3]);
VWORD(d[6])=(u16)(tv);

goto L62e8;
L62e8: /* move.w (A5)+, D4 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[4])=(u16)(tv);

goto L62ea;
L62ea: /* move.w (A5)+, D5 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[5])=(u16)(tv);

goto L62ec;
L62ec: /* move.w (A5)+, D7 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[7])=(u16)(tv);

goto L62ee;
L62ee: /* bra $4e20 */

return 0x4e20ul;
}
static u32 part2(u32 pc){u32 v,w,r,ea,eb,stkp,stkv; u16 tv,tw,tr;s32 signed_result;
if(pc==0x6d82ul)goto L6d82;
dispatch: if(!pc)return 0;if(pc<0x6300ul||pc>=0x7000ul)return pc;
VD: if(pc<0x6b1aul)goto VDL;goto VDR;
VDL: if(pc<0x69c0ul)goto VDLL;goto VDLR;
VDLL: if(pc<0x67ccul)goto VDLLL;goto VDLLR;
VDLLL: if(pc<0x67baul)goto VDLLLL;goto VDLLLR;
VDLLLL: if(pc==0x6780ul)goto L6780;vm_fault=pc;return 0;
VDLLLR: if(pc==0x67baul)goto L67ba;vm_fault=pc;return 0;
VDLLR: if(pc<0x67eeul)goto VDLLRL;goto VDLLRR;
VDLLRL: if(pc==0x67ccul)goto L67cc;vm_fault=pc;return 0;
VDLLRR: if(pc<0x6986ul)goto VDLLRRL;goto VDLLRRR;
VDLLRRL: if(pc==0x67eeul)goto L67ee;vm_fault=pc;return 0;
VDLLRRR: if(pc==0x6986ul)goto L6986;vm_fault=pc;return 0;
VDLR: if(pc<0x6a68ul)goto VDLRL;goto VDLRR;
VDLRL: if(pc<0x6a2cul)goto VDLRLL;goto VDLRLR;
VDLRLL: if(pc==0x69c0ul)goto L69c0;vm_fault=pc;return 0;
VDLRLR: if(pc==0x6a2cul)goto L6a2c;vm_fault=pc;return 0;
VDLRR: if(pc<0x6a70ul)goto VDLRRL;goto VDLRRR;
VDLRRL: if(pc==0x6a68ul)goto L6a68;vm_fault=pc;return 0;
VDLRRR: if(pc<0x6b02ul)goto VDLRRRL;goto VDLRRRR;
VDLRRRL: if(pc==0x6a70ul)goto L6a70;vm_fault=pc;return 0;
VDLRRRR: if(pc==0x6b02ul)goto L6b02;vm_fault=pc;return 0;
VDR: if(pc<0x6ee6ul)goto VDRL;goto VDRR;
VDRL: if(pc<0x6bf6ul)goto VDRLL;goto VDRLR;
VDRLL: if(pc<0x6b38ul)goto VDRLLL;goto VDRLLR;
VDRLLL: if(pc==0x6b1aul)goto L6b1a;vm_fault=pc;return 0;
VDRLLR: if(pc==0x6b38ul)goto L6b38;vm_fault=pc;return 0;
VDRLR: if(pc<0x6c0cul)goto VDRLRL;goto VDRLRR;
VDRLRL: if(pc==0x6bf6ul)goto L6bf6;vm_fault=pc;return 0;
VDRLRR: if(pc<0x6d40ul)goto VDRLRRL;goto VDRLRRR;
VDRLRRL: if(pc==0x6c0cul)goto L6c0c;vm_fault=pc;return 0;
VDRLRRR: if(pc==0x6d40ul)goto L6d40;vm_fault=pc;return 0;
VDRR: if(pc<0x6f70ul)goto VDRRL;goto VDRRR;
VDRRL: if(pc<0x6f1cul)goto VDRRLL;goto VDRRLR;
VDRRLL: if(pc==0x6ee6ul)goto L6ee6;vm_fault=pc;return 0;
VDRRLR: if(pc==0x6f1cul)goto L6f1c;vm_fault=pc;return 0;
VDRRR: if(pc<0x6f9eul)goto VDRRRL;goto VDRRRR;
VDRRRL: if(pc==0x6f70ul)goto L6f70;vm_fault=pc;return 0;
VDRRRR: if(pc<0x6fa8ul)goto VDRRRRL;goto VDRRRRR;
VDRRRRL: if(pc==0x6f9eul)goto L6f9e;vm_fault=pc;return 0;
VDRRRRR: if(pc==0x6fa8ul)goto L6fa8;vm_fault=pc;return 0;
L6780: if(vehicle_external(0x6780ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L67ba: /* move.w #$0, $8f72.l */

tv=((u16)(0L));
*(u16 *)(vehicle_state+596)=(u16)(tv);

goto L67c2;
L67c2: /* tst.b $8f6e.l */

tv=vehicle_state[593];
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L67c8;
L67c8: /* beq $67cc */

if(fz)goto L67cc;
goto L67ca;
L67ca: /* bsr $67dc */

a[7]-=4;STACK_WRITE(a[7],0x67ccul);
goto L67dc;
L67cc: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);

goto L67d2;
L67d2: /* add.b D0, $9079.l */

tv=((u8)d[0]);
tw=vehicle_state[858];
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);fx=(u8)((tr&~0xfful)!=0);fn=(u8)((tr&0x80ul)!=0);fz=(u8)((tr&0xfful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x80ul)!=0);
vehicle_state[858]=(u8)(tr);
goto L67d8;
L67d8: /* bcs $67dc */

if(fc)goto L67dc;
goto L67da;
L67da: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L67dc: /* move.l #$10, D0 */

v=((u32)(16L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L67e2;
L67e2: /* pea $67ee.l */

a[7]-=4;
STACK_WRITE(a[7],0x67eeul);
goto L67e8;
L67e8: /* jmp $7c82a.l */

return 0x7c82aul;
L67ee: /* move.w $9076.l, D0 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[0])=(u16)(tv);

goto L67f4;
L67f4: /* addq.b #1, D0 */

tv=((u8)(1L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L67f6;
L67f6: /* move.w D0, $9076.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+856)=(u16)(tv);

goto L67fc;
L67fc: /* addq.w #1, $8f72.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+596));
tr=tw+tv;
*(u16 *)(vehicle_state+596)=(u16)(tr);
goto L6802;
L6802: /* addq.w #1, $8d26.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+8));
tr=tw+tv;
*(u16 *)(vehicle_state+8)=(u16)(tr);
goto L6808;
L6808: /* lea $8f74.l, A0 */

a[0]=0x8f74ul;
goto L680e;
L680e: /* move.w $9076.l, D0 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[0])=(u16)(tv);

goto L6814;
L6814: /* addi.b #$1f, D0 */

tv=((u8)(31L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L6818;
L6818: /* move.b $9098.l, D1 */

tv=vehicle_state[891];
VBYTE(d[1])=(u8)(tv);

goto L681e;
L681e: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L6822;
L6822: /* bcc $683a */

if(!fc)goto L683a;
goto L6824;
L6824: /* movea.l $9084.l, A1 */

v=(((u32)*(u16 *)(vehicle_state+870)<<16)|*(u16 *)(vehicle_state+872));
a[1]=v;
goto L682a;
L682a: /* move.b (A1)+, D1 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[1])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L682c;
L682c: /* beq $69ca */

if(fz)goto L69ca;
goto L6830;
L6830: /* move.l A1, $9084.l */

v=((u32)a[1]);
*(u16 *)(vehicle_state+870)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+872)=(u16)(v);

goto L6836;
L6836: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;
VBYTE(d[1])=(u8)(tr);
goto L683a;
L683a: /* move.b D1, $9098.l */

tv=((u8)d[1]);
vehicle_state[891]=(u8)(tv);

goto L6840;
L6840: /* andi.b #$f, D1 */

tv=((u8)(15L));
tw=((u8)d[1]);
tr=tw&tv;

VBYTE(d[1])=(u8)(tr);
goto L6844;
L6844: /* btst #$3, D1 */

v=((u16)(3L));
w=((u32)d[1]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L6848;
L6848: /* beq $6850 */

if(fz)goto L6850;
goto L684a;
L684a: /* andi.w #$7, D1 */

tv=((u16)(7L));
tw=((u16)d[1]);
tr=tw&tv;

VWORD(d[1])=(u16)(tr);
goto L684e;
L684e: /* neg.b D1 */

tv=((u8)d[1]);
tr=0-tv;
VBYTE(d[1])=(u8)(tr);
goto L6850;
L6850: /* asl.b #1, D1 */

tv=((u8)(1L));
tw=((u8)d[1]);
tr=tw<<1;
VBYTE(d[1])=(u8)(tr);
goto L6852;
L6852: /* move.b D1, (A0,D0.w) */

tv=((u8)d[1]);
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);

goto L6856;
L6856: /* addi.b #$20, D0 */

tv=((u8)(32L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L685a;
L685a: /* move.b $9099.l, D1 */

tv=vehicle_state[890];
VBYTE(d[1])=(u8)(tv);

goto L6860;
L6860: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L6864;
L6864: /* bcc $687c */

if(!fc)goto L687c;
goto L6866;
L6866: /* movea.l $9088.l, A1 */

v=(((u32)*(u16 *)(vehicle_state+874)<<16)|*(u16 *)(vehicle_state+876));
a[1]=v;
goto L686c;
L686c: /* move.b (A1)+, D1 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[1])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L686e;
L686e: /* beq $69ca */

if(fz)goto L69ca;
goto L6872;
L6872: /* move.l A1, $9088.l */

v=((u32)a[1]);
*(u16 *)(vehicle_state+874)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+876)=(u16)(v);

goto L6878;
L6878: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;
VBYTE(d[1])=(u8)(tr);
goto L687c;
L687c: /* move.b D1, $9099.l */

tv=((u8)d[1]);
vehicle_state[890]=(u8)(tv);

goto L6882;
L6882: /* andi.b #$f, D1 */

tv=((u8)(15L));
tw=((u8)d[1]);
tr=tw&tv;

VBYTE(d[1])=(u8)(tr);
goto L6886;
L6886: /* subq.b #8, D1 */

tv=((u8)(8L));
tw=((u8)d[1]);
tr=tw-tv;
VBYTE(d[1])=(u8)(tr);
goto L6888;
L6888: /* move.b D1, (A0,D0.w) */

tv=((u8)d[1]);
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);

goto L688c;
L688c: /* addi.b #$20, D0 */

tv=((u8)(32L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L6890;
L6890: /* addi.w #$1, $907a.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+860));
tr=tw+tv;
*(u16 *)(vehicle_state+860)=(u16)(tr);
goto L6898;
L6898: /* andi.w #$1, $907a.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+860));
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
*(u16 *)(vehicle_state+860)=(u16)(tr);
goto L68a0;
L68a0: /* bne $68b4 */

if(!fz)goto L68b4;
goto L68a2;
L68a2: /* move.b #$0, (A0,D0.w) */

tv=((u8)(0L));
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);

goto L68a8;
L68a8: /* addi.b #$20, D0 */

tv=((u8)(32L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L68ac;
L68ac: /* move.b #$0, (A0,D0.w) */

tv=((u8)(0L));
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);

goto L68b2;
L68b2: /* bra $6918 */

goto L6918;
L68b4: /* move.b $909b.l, D1 */

tv=vehicle_state[892];
VBYTE(d[1])=(u8)(tv);

goto L68ba;
L68ba: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L68be;
L68be: /* bcc $68d6 */

if(!fc)goto L68d6;
goto L68c0;
L68c0: /* movea.l $9094.l, A1 */

v=(((u32)*(u16 *)(vehicle_state+886)<<16)|*(u16 *)(vehicle_state+888));
a[1]=v;
goto L68c6;
L68c6: /* move.b (A1)+, D1 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[1])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L68c8;
L68c8: /* beq $69ca */

if(fz)goto L69ca;
goto L68cc;
L68cc: /* move.l A1, $9094.l */

v=((u32)a[1]);
*(u16 *)(vehicle_state+886)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+888)=(u16)(v);

goto L68d2;
L68d2: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;
VBYTE(d[1])=(u8)(tr);
goto L68d6;
L68d6: /* move.b D1, $909b.l */

tv=((u8)d[1]);
vehicle_state[892]=(u8)(tv);

goto L68dc;
L68dc: /* andi.b #$f, D1 */

tv=((u8)(15L));
tw=((u8)d[1]);
tr=tw&tv;

VBYTE(d[1])=(u8)(tr);
goto L68e0;
L68e0: /* move.b D1, (A0,D0.w) */

tv=((u8)d[1]);
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);

goto L68e4;
L68e4: /* addi.b #$20, D0 */

tv=((u8)(32L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L68e8;
L68e8: /* move.b $909a.l, D1 */

tv=vehicle_state[893];
VBYTE(d[1])=(u8)(tv);

goto L68ee;
L68ee: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L68f2;
L68f2: /* bcc $690a */

if(!fc)goto L690a;
goto L68f4;
L68f4: /* movea.l $9090.l, A1 */

v=(((u32)*(u16 *)(vehicle_state+882)<<16)|*(u16 *)(vehicle_state+884));
a[1]=v;
goto L68fa;
L68fa: /* move.b (A1)+, D1 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[1])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L68fc;
L68fc: /* beq $69ca */

if(fz)goto L69ca;
goto L6900;
L6900: /* move.l A1, $9090.l */

v=((u32)a[1]);
*(u16 *)(vehicle_state+882)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+884)=(u16)(v);

goto L6906;
L6906: /* subi.b #$10, D1 */

tv=((u8)(16L));
tw=((u8)d[1]);
tr=tw-tv;
VBYTE(d[1])=(u8)(tr);
goto L690a;
L690a: /* move.b D1, $909a.l */

tv=((u8)d[1]);
vehicle_state[893]=(u8)(tv);

goto L6910;
L6910: /* andi.b #$f, D1 */

tv=((u8)(15L));
tw=((u8)d[1]);
tr=tw&tv;

VBYTE(d[1])=(u8)(tr);
goto L6914;
L6914: /* move.b D1, (A0,D0.w) */

tv=((u8)d[1]);
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);

goto L6918;
L6918: /* addi.b #$20, D0 */

tv=((u8)(32L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L691c;
L691c: /* move.b $909c.l, D1 */

tv=vehicle_state[895];
VBYTE(d[1])=(u8)(tv);

goto L6922;
L6922: /* subq.b #1, D1 */

tv=((u8)(1L));
tw=((u8)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L6924;
L6924: /* bcc $6974 */

if(!fc)goto L6974;
goto L6926;
L6926: /* movea.l $908c.l, A1 */

v=(((u32)*(u16 *)(vehicle_state+878)<<16)|*(u16 *)(vehicle_state+880));
a[1]=v;
goto L692c;
L692c: /* move.b (A1)+, D1 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[1])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L692e;
L692e: /* beq $69ca */

if(fz)goto L69ca;
goto L6932;
L6932: /* subq.b #1, D1 */

tv=((u8)(1L));
tw=((u8)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L6934;
L6934: /* move.b D1, $909c.l */

tv=((u8)d[1]);
vehicle_state[895]=(u8)(tv);

goto L693a;
L693a: /* move.b (A1)+, D1 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[1])=(u8)(tv);

goto L693c;
L693c: /* move.l A1, $908c.l */

v=((u32)a[1]);
*(u16 *)(vehicle_state+878)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+880)=(u16)(v);

goto L6942;
L6942: /* cmpi.b #$40, D1 */

tv=((u8)(64L));
tw=((u8)d[1]);
fc=(u8)((u8)tw<(u8)tv);
goto L6946;
L6946: /* bcs $6958 */

if(fc)goto L6958;
goto L6948;
L6948: /* rol.b #2, D1 */

v=((u8)(2L));
w=((u8)d[1]);
r=vshift(w,(u8)v,8,5);
VBYTE(d[1])=(u8)(r);
goto L694a;
L694a: /* andi.w #$3, D1 */

tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw&tv;

VWORD(d[1])=(u16)(tr);
goto L694e;
L694e: /* subq.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L6950;
L6950: /* move.w D1, $8d30.l */

tv=((u16)d[1]);
*(u16 *)(vehicle_state+18)=(u16)(tv);

goto L6956;
L6956: /* bra $6966 */

goto L6966;
L6958: /* cmpi.b #$20, D1 */

tv=((u8)(32L));
tw=((u8)d[1]);
fz=(u8)((u8)tw==(u8)tv);
goto L695c;
L695c: /* bne $6968 */

if(!fz)goto L6968;
goto L695e;
L695e: /* move.w #$1, $8f64.l */

tv=((u16)(1L));
*(u16 *)(vehicle_state+582)=(u16)(tv);

goto L6966;
L6966: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L6968;
L6968: /* move.b D1, $909d.l */

tv=((u8)d[1]);
vehicle_state[894]=(u8)(tv);

goto L696e;
L696e: /* move.b D1, (A0,D0.w) */

tv=((u8)d[1]);
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L6972;
L6972: /* bra $6982 */

goto L6982;
L6974: /* move.b D1, $909c.l */

tv=((u8)d[1]);
vehicle_state[895]=(u8)(tv);

goto L697a;
L697a: /* move.b $909d.l, (A0,D0.w) */

tv=vehicle_state[894];
ea=(a[0]+((s16)(d[0])));
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L6982;
L6982: /* bsr $6bda */

a[7]-=4;STACK_WRITE(a[7],0x6986ul);
goto L6bda;
L6986: /* lea $8e0e.l, A0 */

a[0]=0x8e0eul;
goto L698c;
L698c: /* moveq #$7, D7 */

v=((u32)(7L));
d[7]=v;

goto L698e;
L698e: /* tst.b ($0,A0) */

ea=(0+a[0]);
tv=ver8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L6992;
L6992: /* beq $69c0 */

if(fz)goto L69c0;
goto L6994;
L6994: /* move.b ($2,A0), D0 */

ea=(2+a[0]);
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L6998;
L6998: /* subq.b #1, D0 */

tv=((u8)(1L));
tw=((u8)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x80ul)!=0);
VBYTE(d[0])=(u8)(tr);
goto L699a;
L699a: /* bpl $69bc */

if(!fn)goto L69bc;
goto L699c;
L699c: /* move.b #$0, ($0,A0) */

tv=((u8)(0L));
ea=(0+a[0]);
vew8(ea,tv);

goto L69a2;
L69a2: /* tst.w ($1a,A0) */

ea=(26+a[0]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L69a6;
L69a6: /* beq $69c0 */

if(fz)goto L69c0;
goto L69a8;
L69a8: /* tst.w ($28,A0) */

ea=(40+a[0]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L69ac;
L69ac: /* bne $69c0 */

if(!fz)goto L69c0;
goto L69ae;
L69ae: /* pea $69c0.l */

a[7]-=4;
STACK_WRITE(a[7],0x69c0ul);
goto L69b4;
L69b4: /* moveq #$1, D0 */

v=((u32)(1L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L69b6;
L69b6: /* jmp $7c870.l */

return 0x7c870ul;
L69bc: /* move.b D0, ($2,A0) */

tv=((u8)d[0]);
ea=(2+a[0]);
vew8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L69c0;
L69c0: /* lea ($2a,A0), A0 */

a[0]=(42+a[0]);
goto L69c4;
L69c4: /* dbra D7, $698e */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L698e;
goto L69c8;
L69c8: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L69ca: /* movea.l $9080.l, A0 */

v=(((u32)*(u16 *)(vehicle_state+866)<<16)|*(u16 *)(vehicle_state+868));
a[0]=v;
goto L69d0;
L69d0: /* move.l (A0)+, D0 */

ea=a[0];
v=ver32(ea);
a[0]+=4;
d[0]=v;
fz=(u8)((v&0xfffffffful)==0);
goto L69d2;
L69d2: /* bne $69d8 */

if(!fz)goto L69d8;
goto L69d4;
L69d4: /* movea.l (A0), A0 */

ea=a[0];
v=ver32(ea);
a[0]=v;
goto L69d6;
L69d6: /* bra $69d0 */

goto L69d0;
L69d8: /* move.l D0, $9084.l */

v=((u32)d[0]);
*(u16 *)(vehicle_state+870)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+872)=(u16)(v);

goto L69de;
L69de: /* move.l (A0)+, $9088.l */

ea=a[0];
v=ver32(ea);
a[0]+=4;
*(u16 *)(vehicle_state+874)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+876)=(u16)(v);

goto L69e4;
L69e4: /* move.l (A0)+, $9094.l */

ea=a[0];
v=ver32(ea);
a[0]+=4;
*(u16 *)(vehicle_state+886)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+888)=(u16)(v);

goto L69ea;
L69ea: /* move.l (A0)+, $9090.l */

ea=a[0];
v=ver32(ea);
a[0]+=4;
*(u16 *)(vehicle_state+882)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+884)=(u16)(v);

goto L69f0;
L69f0: /* move.l (A0)+, $908c.l */

ea=a[0];
v=ver32(ea);
a[0]+=4;
*(u16 *)(vehicle_state+878)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+880)=(u16)(v);

goto L69f6;
L69f6: /* move.l A0, $9080.l */

v=((u32)a[0]);
*(u16 *)(vehicle_state+866)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+868)=(u16)(v);

goto L69fc;
L69fc: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L69fe;
L69fe: /* move.w D0, $907a.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+860)=(u16)(tv);

goto L6a04;
L6a04: /* move.b D0, $9098.l */

tv=((u8)d[0]);
vehicle_state[891]=(u8)(tv);

goto L6a0a;
L6a0a: /* move.b D0, $9099.l */

tv=((u8)d[0]);
vehicle_state[890]=(u8)(tv);

goto L6a10;
L6a10: /* move.b D0, $909b.l */

tv=((u8)d[0]);
vehicle_state[892]=(u8)(tv);

goto L6a16;
L6a16: /* move.b D0, $909a.l */

tv=((u8)d[0]);
vehicle_state[893]=(u8)(tv);

goto L6a1c;
L6a1c: /* move.b D0, $909c.l */

tv=((u8)d[0]);
vehicle_state[895]=(u8)(tv);

goto L6a22;
L6a22: /* move.b D0, $909d.l */

tv=((u8)d[0]);
vehicle_state[894]=(u8)(tv);

goto L6a28;
L6a28: /* bra $6808 */

goto L6808;
L6a2c: /* movea.l $907c.l, A0 */

v=(((u32)*(u16 *)(vehicle_state+862)<<16)|*(u16 *)(vehicle_state+864));
a[0]=v;
goto L6a32;
L6a32: /* move.l (A0)+, D0 */

ea=a[0];
v=ver32(ea);
a[0]+=4;
d[0]=v;
fz=(u8)((v&0xfffffffful)==0);
goto L6a34;
L6a34: /* bne $6a3a */

if(!fz)goto L6a3a;
goto L6a36;
L6a36: /* movea.l (A0), A0 */

ea=a[0];
v=ver32(ea);
a[0]=v;
goto L6a38;
L6a38: /* bra $6a32 */

goto L6a32;
L6a3a: /* move.l D0, $9080.l */

v=((u32)d[0]);
*(u16 *)(vehicle_state+866)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+868)=(u16)(v);

goto L6a40;
L6a40: /* move.l A0, $907c.l */

v=((u32)a[0]);
*(u16 *)(vehicle_state+862)=(u16)((u32)(v)>>16);
*(u16 *)(vehicle_state+864)=(u16)(v);

goto L6a46;
L6a46: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L6a48;
L6a48: /* move.w D0, $9076.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+856)=(u16)(tv);

goto L6a4e;
L6a4e: /* move.w D0, $9078.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+858)=(u16)(tv);

goto L6a54;
L6a54: /* lea $8f74.l, A0 */

a[0]=0x8f74ul;
goto L6a5a;
L6a5a: /* move.w #$3f, D7 */

tv=((u16)(63L));
VWORD(d[7])=(u16)(tv);

goto L6a5e;
L6a5e: /* move.l D0, (A0)+ */

v=((u32)d[0]);
ea=a[0];
vew32(ea,v);
a[0]+=4;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L6a60;
L6a60: /* dbra D7, $6a5e */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L6a5e;
goto L6a64;
L6a64: /* bsr $69ca */

a[7]-=4;STACK_WRITE(a[7],0x6a68ul);
goto L69ca;
L6a68: /* moveq #$1f, D7 */

v=((u32)(31L));
d[7]=v;

goto L6a6a;
L6a6a: /* move.w D7, -(A7) */

tv=((u16)d[7]);
a[7]-=2;
ea=a[7];
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6a6c;
L6a6c: /* bsr $67ee */

a[7]-=4;STACK_WRITE(a[7],0x6a70ul);
goto L67ee;
L6a70: /* move.w (A7)+, D7 */

ea=a[7];
tv=ver16(ea);
a[7]+=2;
VWORD(d[7])=(u16)(tv);

goto L6a72;
L6a72: /* dbra D7, $6a6a */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L6a6a;
goto L6a76;
L6a76: /* lea $8d3c.l, A0 */

a[0]=0x8d3cul;
goto L6a7c;
L6a7c: /* move.w ($8,A0), D1 */

ea=(8+a[0]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);

goto L6a80;
L6a80: /* movea.l A0, A1 */

v=((u32)a[0]);
a[1]=v;
goto L6a82;
L6a82: /* moveq #$f, D7 */

v=((u32)(15L));
d[7]=v;

goto L6a84;
L6a84: /* move.w #$0, (A0)+ */

tv=((u16)(0L));
ea=a[0];
vew16(ea,tv);
a[0]+=2;

goto L6a88;
L6a88: /* dbra D7, $6a84 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L6a84;
goto L6a8c;
L6a8c: /* move.w #$58, ($6,A1) */

tv=((u16)(88L));
ea=(6+a[1]);
vew16(ea,tv);

goto L6a92;
L6a92: /* addi.w #$28, D1 */

tv=((u16)(40L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L6a96;
L6a96: /* cmpi.w #$140, D1 */

tv=((u16)(320L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L6a9a;
L6a9a: /* bcs $6aa0 */

if(fc)goto L6aa0;
goto L6a9c;
L6a9c: /* subi.w #$140, D1 */

tv=((u16)(320L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L6aa0;
L6aa0: /* move.w D1, ($8,A1) */

tv=((u16)d[1]);
ea=(8+a[1]);
vew16(ea,tv);

goto L6aa4;
L6aa4: /* move.w D1, ($18,A1) */

tv=((u16)d[1]);
ea=(24+a[1]);
vew16(ea,tv);

goto L6aa8;
L6aa8: /* move.w #$16d, $9074.l */

tv=((u16)(365L));
*(u16 *)(vehicle_state+854)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6ab0;
L6ab0: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6b02: /* lea $8d3c.l, A0 */

a[0]=0x8d3cul;
goto L6b08;
L6b08: /* lea $6ae2.l, A1 */

a[1]=0x6ae2ul;
goto L6b0e;
L6b0e: /* lea $6ab1.l, A2 */

a[2]=0x6ab1ul;
goto L6b14;
L6b14: /* move.w #$140, D7 */

tv=((u16)(320L));
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6b18;
L6b18: /* bsr $6b4a */

a[7]-=4;STACK_WRITE(a[7],0x6b1aul);
goto L6b4a;
L6b1a: /* move.w ($6,A0), D0 */

ea=(6+a[0]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6b1e;
L6b1e: /* move.w D0, -(A7) */

tv=((u16)d[0]);
a[7]-=2;
ea=a[7];
vew16(ea,tv);

goto L6b20;
L6b20: /* lea $8d4c.l, A0 */

a[0]=0x8d4cul;
goto L6b26;
L6b26: /* lea $6aca.l, A1 */

a[1]=0x6acaul;
goto L6b2c;
L6b2c: /* lea $6ac1.l, A2 */

a[2]=0x6ac1ul;
goto L6b32;
L6b32: /* move.w #$140, D7 */

tv=((u16)(320L));
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6b36;
L6b36: /* bsr $6b4a */

a[7]-=4;STACK_WRITE(a[7],0x6b38ul);
goto L6b4a;
L6b38: /* move.w (A7)+, D0 */

ea=a[7];
tv=ver16(ea);
a[7]+=2;
VWORD(d[0])=(u16)(tv);

goto L6b3a;
L6b3a: /* subi.w #$58, D0 */

tv=((u16)(88L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6b3e;
L6b3e: /* asr.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=((s16)tw)>>1;
VWORD(d[0])=(u16)(tr);
goto L6b40;
L6b40: /* addi.w #$6e, D0 */

tv=((u16)(110L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L6b44;
L6b44: /* move.w D0, ($6,A0) */

tv=((u16)d[0]);
ea=(6+a[0]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6b48;
L6b48: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6b4a: /* move.w $8f6e.l, D0 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6b50;
L6b50: /* bne $6b54 */

if(!fz)goto L6b54;
goto L6b52;
L6b52: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6b54: /* tst.w ($e,A0) */

ea=(14+a[0]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L6b58;
L6b58: /* beq $6b98 */

if(fz)goto L6b98;
goto L6b5c;
L6b5c: /* subq.w #1, ($c,A0) */

tv=((u16)(1L));
eb=(12+a[0]);
tw=ver16(eb);
tr=tw-tv;fx=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
vew16(eb,tr);
goto L6b60;
L6b60: /* bne $6b98 */

if(!fz)goto L6b98;
goto L6b62;
L6b62: /* lsr.w #5, D0 */

tv=((u16)(5L));
tw=((u16)d[0]);
tr=((u16)tw)>>5;
VWORD(d[0])=(u16)(tr);
goto L6b64;
L6b64: /* andi.w #$fe, D0 */

tv=((u16)(254L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L6b68;
L6b68: /* add.w ($a,A0), D0 */

ea=(10+a[0]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6b6c;
L6b6c: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L6b6e;
L6b6e: /* move.b (A1,D0.w), D1 */

ea=(a[1]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L6b72;
L6b72: /* move.w D1, ($c,A0) */

tv=((u16)d[1]);
ea=(12+a[0]);
vew16(ea,tv);

goto L6b76;
L6b76: /* move.b ($1,A1,D0.w), D1 */

ea=(1+a[1]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L6b7a;
L6b7a: /* tst.w ($e,A0) */

ea=(14+a[0]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L6b7e;
L6b7e: /* bmi $6b84 */

if(fn)goto L6b84;
goto L6b82;
L6b82: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L6b84;
L6b84: /* add.w ($8,A0), D1 */

ea=(8+a[0]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L6b88;
L6b88: /* bpl $6b8e */

if(!fn)goto L6b8e;
goto L6b8a;
L6b8a: /* add.w D7, D1 */

tv=((u16)d[7]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L6b8c;
L6b8c: /* bra $6b94 */

goto L6b94;
L6b8e: /* cmp.w D7, D1 */

tv=((u16)d[7]);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L6b90;
L6b90: /* bcs $6b94 */

if(fc)goto L6b94;
goto L6b92;
L6b92: /* sub.w D7, D1 */

tv=((u16)d[7]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L6b94;
L6b94: /* move.w D1, ($8,A0) */

tv=((u16)d[1]);
ea=(8+a[0]);
vew16(ea,tv);

goto L6b98;
L6b98: /* move.w ($2,A0), D0 */

ea=(2+a[0]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6b9c;
L6b9c: /* beq $6bd8 */

if(fz)goto L6bd8;
goto L6b9e;
L6b9e: /* bpl $6ba2 */

if(!fn)goto L6ba2;
goto L6ba0;
L6ba0: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L6ba2;
L6ba2: /* move.b (A2,D0.w), D0 */

ea=(a[2]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L6ba6;
L6ba6: /* move.w $9078.l, D1 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[1])=(u16)(tv);

goto L6bac;
L6bac: /* sub.w ($4,A0), D1 */

ea=(4+a[0]);
tv=ver16(ea);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L6bb0;
L6bb0: /* beq $6bd8 */

if(fz)goto L6bd8;
goto L6bb2;
L6bb2: /* moveq #$0, D2 */

v=((u32)(0L));
d[2]=v;

goto L6bb4;
L6bb4: /* move.w D2, D3 */

tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L6bb6;
L6bb6:vehicle_sky_steps();goto L6bc0;
L6bb6_original: /* sub.b D0, D1 */

tv=((u8)d[0]);
tw=((u8)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);
VBYTE(d[1])=(u8)(tr);
goto L6bb8;
L6bb8: /* bcs $6bc0 */

if(fc)goto L6bc0;
goto L6bba;
L6bba: /* addq.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L6bbc;
L6bbc: /* add.w D0, D3 */

tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L6bbe;
L6bbe: /* bra $6bb6 */

goto L6bb6;
L6bc0: /* tst.w D2 */

tv=((u16)d[2]);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6bc2;
L6bc2: /* beq $6bd8 */

if(fz)goto L6bd8;
goto L6bc4;
L6bc4: /* add.w D2, ($0,A0) */

tv=((u16)d[2]);
eb=(0+a[0]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L6bc8;
L6bc8: /* tst.w ($2,A0) */

ea=(2+a[0]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L6bcc;
L6bcc: /* bpl $6bd0 */

if(!fn)goto L6bd0;
goto L6bce;
L6bce: /* neg.w D2 */

tv=((u16)d[2]);
tr=0-tv;
VWORD(d[2])=(u16)(tr);
goto L6bd0;
L6bd0: /* add.w D2, ($6,A0) */

tv=((u16)d[2]);
eb=(6+a[0]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L6bd4;
L6bd4: /* add.w D3, ($4,A0) */

tv=((u16)d[3]);
eb=(4+a[0]);
tw=ver16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
vew16(eb,tr);
goto L6bd8;
L6bd8: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6bda: /* lea $8f74.l, A6 */

a[6]=0x8f74ul;
goto L6be0;
L6be0: /* lea $8d3c.l, A0 */

a[0]=0x8d3cul;
goto L6be6;
L6be6: /* lea $6ae2.l, A2 */

a[2]=0x6ae2ul;
goto L6bec;
L6bec: /* lea $6ab9.l, A3 */

a[3]=0x6ab9ul;
goto L6bf2;
L6bf2: /* bsr $6cbc */

a[7]-=4;STACK_WRITE(a[7],0x6bf6ul);
goto L6cbc;
L6bf6: /* lea $8d4c.l, A0 */

a[0]=0x8d4cul;
goto L6bfc;
L6bfc: /* lea $6aca.l, A2 */

a[2]=0x6acaul;
goto L6c02;
L6c02: /* lea $6ac9.l, A3 */

a[3]=0x6ac9ul;
goto L6c08;
L6c08: /* bsr $6cbc */

a[7]-=4;STACK_WRITE(a[7],0x6c0cul);
goto L6cbc;
L6c0c: /* lea $8d5c.l, A1 */

a[1]=0x8d5cul;
goto L6c12;
L6c12: /* move.w ($e,A1), D0 */

ea=(14+a[1]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L6c16;
L6c16: /* bpl $6c1a */

if(!fn)goto L6c1a;
goto L6c18;
L6c18: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L6c1a;
L6c1a: /* sub.w ($c,A1), D0 */

ea=(12+a[1]);
tv=ver16(ea);
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[0])=(u16)(tr);
goto L6c1e;
L6c1e: /* bcs $6c36 */

if(fc)goto L6c36;
goto L6c20;
L6c20: /* beq $6c36 */

if(fz)goto L6c36;
goto L6c22;
L6c22: /* move.w D0, D1 */

tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto L6c24;
L6c24: /* mulu.w #$3, D0 */

v=((u16)(3L));
w=((u32)d[0]);
r=vehicle_mulu16(v,w);

d[0]=r;
goto L6c28;
L6c28: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6c2a;
L6c2a: /* tst.w ($e,A1) */

ea=(14+a[1]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L6c2e;
L6c2e: /* bpl $6c32 */

if(!fn)goto L6c32;
goto L6c30;
L6c30: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L6c32;
L6c32: /* add.w D0, ($34,A1) */

tv=((u16)d[0]);
eb=(52+a[1]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L6c36;
L6c36: /* move.w #$0, ($a,A1) */

tv=((u16)(0L));
ea=(10+a[1]);
vew16(ea,tv);

goto L6c3c;
L6c3c: /* move.w #$0, ($c,A1) */

tv=((u16)(0L));
ea=(12+a[1]);
vew16(ea,tv);

goto L6c42;
L6c42: /* move.w ($e,A0), ($e,A1) */

ea=(14+a[0]);
tv=ver16(ea);
ea=(14+a[1]);
vew16(ea,tv);

goto L6c48;
L6c48: /* move.w $9076.l, D0 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[0])=(u16)(tv);

goto L6c4e;
L6c4e: /* addi.b #$21, D0 */

tv=((u8)(33L));
tw=((u8)d[0]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[0])=(u8)(tr);
goto L6c52;
L6c52: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L6c54;
L6c54: /* move.b (A6,D0.w), D0 */

ea=(a[6]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L6c58;
L6c58: /* beq $6c62 */

if(fz)goto L6c62;
goto L6c5a;
L6c5a: /* moveq #$5, D1 */

v=((u32)(5L));
d[1]=v;

goto L6c5c;
L6c5c: /* tst.b D0 */

tv=((u8)d[0]);
fn=(u8)((tv&0x80ul)!=0);
goto L6c5e;
L6c5e: /* bmi $6c62 */

if(fn)goto L6c62;
goto L6c60;
L6c60: /* moveq #$a, D1 */

v=((u32)(10L));
d[1]=v;

goto L6c62;
L6c62: /* move.w D1, ($16,A1) */

tv=((u16)d[1]);
ea=(22+a[1]);
vew16(ea,tv);

goto L6c66;
L6c66: /* move.w ($1a,A1), D1 */

ea=(26+a[1]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L6c6a;
L6c6a: /* bpl $6cae */

if(!fn)goto L6cae;
goto L6c6c;
L6c6c: /* tst.b D0 */

tv=((u8)d[0]);
fn=(u8)((tv&0x80ul)!=0);
goto L6c6e;
L6c6e: /* bmi $6cae */

if(fn)goto L6cae;
goto L6c70;
L6c70: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L6c72;
L6c72: /* subq.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L6c74;
L6c74: /* bcs $6cae */

if(fc)goto L6cae;
goto L6c76;
L6c76: /* tst.w ($18,A1) */

ea=(24+a[1]);
tv=ver16(ea);
fz=(u8)((tv&0xfffful)==0);
goto L6c7a;
L6c7a: /* bne $6cae */

if(!fz)goto L6cae;
goto L6c7c;
L6c7c: /* move.w $8f6e.l, D2 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[2])=(u16)(tv);

goto L6c82;
L6c82: /* lsr.w #7, D2 */

tv=((u16)(7L));
tw=((u16)d[2]);
tr=((u16)tw)>>7;
VWORD(d[2])=(u16)(tr);
goto L6c84;
L6c84: /* not.w D2 */

tv=((u16)d[2]);
tr=~tv;
VWORD(d[2])=(u16)(tr);

goto L6c86;
L6c86: /* addq.w #4, D2 */

tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L6c88;
L6c88: /* sub.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[1])=(u16)(tr);
goto L6c8a;
L6c8a: /* bcs $6cae */

if(fc)goto L6cae;
goto L6c8c;
L6c8c: /* beq $6cae */

if(fz)goto L6cae;
goto L6c8e;
L6c8e: /* lsl.w #2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw<<2;fx=(u8)((tw>>14)&1);
VWORD(d[1])=(u16)(tr);
goto L6c90;
L6c90: /* lea $574c.l, A2 */

a[2]=0x574cul;
goto L6c96;
L6c96: /* lea (A2,D1.w), A2 */

a[2]=(a[2]+((s16)(d[1])));
goto L6c9a;
L6c9a: /* move.w (A2)+, D1 */

ea=a[2];
tv=ver16(ea);
a[2]+=2;
VWORD(d[1])=(u16)(tv);

goto L6c9c;
L6c9c: /* move.w (A2), ($18,A1) */

ea=a[2];
tv=ver16(ea);
ea=(24+a[1]);
vew16(ea,tv);

goto L6ca0;
L6ca0: /* lea $5728.l, A2 */

a[2]=0x5728ul;
goto L6ca6;
L6ca6: /* lea (A2,D1.w), A2 */

a[2]=(a[2]+((s16)(d[1])));
goto L6caa;
L6caa: /* move.l A2, ($1c,A1) */

v=((u32)a[2]);
ea=(28+a[1]);
vew32(ea,v);

goto L6cae;
L6cae: /* tst.b D0 */

tv=((u8)d[0]);
fn=(u8)((tv&0x80ul)!=0);
goto L6cb0;
L6cb0: /* bpl $6cb6 */

if(!fn)goto L6cb6;
goto L6cb2;
L6cb2: /* ori.w #$ff00, D0 */

tv=((u16)(65280L));
tw=((u16)d[0]);
tr=tw|tv;

VWORD(d[0])=(u16)(tr);
goto L6cb6;
L6cb6: /* move.w D0, ($1a,A1) */

tv=((u16)d[0]);
ea=(26+a[1]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6cba;
L6cba: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6cbc: /* move.w ($0,A0), D0 */

ea=(0+a[0]);
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6cc0;
L6cc0: /* move.w ($2,A0), D1 */

ea=(2+a[0]);
tv=ver16(ea);
VWORD(d[1])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L6cc4;
L6cc4: /* beq $6cde */

if(fz)goto L6cde;
goto L6cc6;
L6cc6: /* bpl $6cca */

if(!fn)goto L6cca;
goto L6cc8;
L6cc8: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L6cca;
L6cca: /* move.b (A3,D1.w), D1 */

ea=(a[3]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L6cce;
L6cce: /* sub.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;fz=(u8)((tr&0xfffful)==0);
VWORD(d[1])=(u16)(tr);
goto L6cd0;
L6cd0: /* beq $6cde */

if(fz)goto L6cde;
goto L6cd2;
L6cd2: /* tst.w ($2,A0) */

ea=(2+a[0]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L6cd6;
L6cd6: /* bpl $6cda */

if(!fn)goto L6cda;
goto L6cd8;
L6cd8: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L6cda;
L6cda: /* add.w D1, ($6,A0) */

tv=((u16)d[1]);
eb=(6+a[0]);
tw=ver16(eb);
tr=tw+tv;
vew16(eb,tr);
goto L6cde;
L6cde: /* move.w $9076.l, D0 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[0])=(u16)(tv);

goto L6ce4;
L6ce4: /* addi.b #$22, D0 */

tv=((u8)(34L));
tw=((u8)d[0]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[0])=(u8)(tr);
goto L6ce8;
L6ce8: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L6cea;
L6cea: /* move.w D1, ($4,A0) */

tv=((u16)d[1]);
ea=(4+a[0]);
vew16(ea,tv);

goto L6cee;
L6cee: /* move.w D1, ($0,A0) */

tv=((u16)d[1]);
ea=(0+a[0]);
vew16(ea,tv);

goto L6cf2;
L6cf2: /* move.b (A6,D0.w), D1 */

ea=(a[6]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);
goto L6cf6;
L6cf6: /* bpl $6cfc */

if(!fn)goto L6cfc;
goto L6cf8;
L6cf8: /* ori.w #$ff00, D1 */

tv=((u16)(65280L));
tw=((u16)d[1]);
tr=tw|tv;

VWORD(d[1])=(u16)(tr);
goto L6cfc;
L6cfc: /* move.w D1, ($2,A0) */

tv=((u16)d[1]);
ea=(2+a[0]);
vew16(ea,tv);

goto L6d00;
L6d00: /* move.w $9076.l, D0 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[0])=(u16)(tv);

goto L6d06;
L6d06: /* move.b (A6,D0.w), D0 */

ea=(a[6]+((s16)(d[0])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);
goto L6d0a;
L6d0a: /* bpl $6d10 */

if(!fn)goto L6d10;
goto L6d0c;
L6d0c: /* ori.w #$ff00, D0 */

tv=((u16)(65280L));
tw=((u16)d[0]);
tr=tw|tv;

VWORD(d[0])=(u16)(tr);
goto L6d10;
L6d10: /* move.w D0, ($e,A0) */

tv=((u16)d[0]);
ea=(14+a[0]);
vew16(ea,tv);

goto L6d14;
L6d14: /* tst.w D0 */

tv=((u16)d[0]);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L6d16;
L6d16: /* beq $6d3a */

if(fz)goto L6d3a;
goto L6d18;
L6d18: /* bpl $6d1c */

if(!fn)goto L6d1c;
goto L6d1a;
L6d1a: /* neg.w D0 */

tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L6d1c;
L6d1c: /* asl.w #2, D0 */

tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw<<2;fx=(u8)((tw>>14)&1);
VWORD(d[0])=(u16)(tr);
goto L6d1e;
L6d1e: /* move.w D0, ($a,A0) */

tv=((u16)d[0]);
ea=(10+a[0]);
vew16(ea,tv);

goto L6d22;
L6d22: /* tst.w ($c,A0) */

ea=(12+a[0]);
tv=ver16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6d26;
L6d26: /* bne $6d3e */

if(!fz)goto L6d3e;
goto L6d28;
L6d28: /* move.w $8f6e.l, D1 */

tv=(*(u16 *)(vehicle_state+592));
VWORD(d[1])=(u16)(tv);

goto L6d2e;
L6d2e: /* lsr.w #5, D1 */

tv=((u16)(5L));
tw=((u16)d[1]);
tr=((u16)tw)>>5;
VWORD(d[1])=(u16)(tr);
goto L6d30;
L6d30: /* andi.w #$fe, D1 */

tv=((u16)(254L));
tw=((u16)d[1]);
tr=tw&tv;

VWORD(d[1])=(u16)(tr);
goto L6d34;
L6d34: /* add.w D0, D1 */

tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L6d36;
L6d36: /* move.b (A2,D1.w), D0 */

ea=(a[2]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L6d3a;
L6d3a: /* move.w D0, ($c,A0) */

tv=((u16)d[0]);
ea=(12+a[0]);
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6d3e;
L6d3e: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6d40: /* lea $7bc8.l, A1 */

a[1]=0x7bc8ul;
goto L6d46;
L6d46: /* lea $7cc8.l, A2 */

a[2]=0x7cc8ul;
goto L6d4c;
L6d4c: /* lea $7dc8.l, A3 */

a[3]=0x7dc8ul;
goto L6d52;
L6d52: /* lea $7ec8.l, A4 */

a[4]=0x7ec8ul;
goto L6d58;
L6d58: /* lea $7fc8.l, A5 */

a[5]=0x7fc8ul;
goto L6d5e;
L6d5e: /* move.w #$6f, D7 */

tv=((u16)(111L));
VWORD(d[7])=(u16)(tv);

goto L6d62;
L6d62: /* move.w (A1)+, D1 */

ea=a[1];
tv=ver16(ea);
a[1]+=2;
VWORD(d[1])=(u16)(tv);

goto L6d64;
L6d64: /* move.w (A5)+, D0 */

ea=a[5];
tv=ver16(ea);
a[5]+=2;
VWORD(d[0])=(u16)(tv);

goto L6d66;
L6d66: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6d68;
L6d68: /* asr.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=((s16)tw)>>1;
VWORD(d[0])=(u16)(tr);
goto L6d6a;
L6d6a: /* move.w D0, D2 */

tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L6d6c;
L6d6c: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6d6e;
L6d6e: /* move.w D0, (A3)+ */

tv=((u16)d[0]);
ea=a[3];
vew16(ea,tv);
a[3]+=2;

goto L6d70;
L6d70: /* move.w D2, D1 */

tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L6d72;
L6d72: /* asr.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=((s16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L6d74;
L6d74: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6d76;
L6d76: /* move.w D0, (A4)+ */

tv=((u16)d[0]);
ea=a[4];
vew16(ea,tv);
a[4]+=2;

goto L6d78;
L6d78: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L6d7a;
L6d7a: /* move.w D0, (A2)+ */

tv=((u16)d[0]);
ea=a[2];
vew16(ea,tv);
a[2]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6d7c;
L6d7c: /* dbra D7, $6d62 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L6d62;
goto L6d80;
L6d80: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6d82: /* move.l A4, D2 */

v=((u32)a[4]);
d[2]=v;

goto L6d84;
L6d84: /* subi.l #$909e, D2 */

v=((u32)(37022L));
w=((u32)d[2]);
r=w-v;fx=(u8)(v>w);
d[2]=r;
goto L6d8a;
L6d8a: /* cmpi.w #$15, D2 */

tv=((u16)(21L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L6d8e;
L6d8e: /* bcc $6e96 */

if(!fc)goto L6e96;
goto L6d92;
L6d92: /* lea $7a20.l, A1 */

a[1]=0x7a20ul;
goto L6d98;
L6d98: /* move.w $9078.l, D1 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[1])=(u16)(tv);

goto L6d9e;
L6d9e: /* andi.w #$e0, D1 */

tv=((u16)(224L));
tw=((u16)d[1]);
tr=tw&tv;

VWORD(d[1])=(u16)(tr);
goto L6da2;
L6da2: /* add.b D2, D1 */

tv=((u8)d[2]);
tw=((u8)d[1]);
tr=tw+tv;
VBYTE(d[1])=(u8)(tr);
goto L6da4;
L6da4: /* move.w D7, D3 */

tv=((u16)d[7]);
VWORD(d[3])=(u16)(tv);

goto L6da6;
L6da6: /* lsl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L6da8;
L6da8: /* btst #$0, D0 */

v=((u16)(0L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L6dac;
L6dac: /* bne $6e12 */

if(!fz)goto L6e12;
goto L6dae;
L6dae: /* btst #$1, D0 */

v=((u16)(1L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L6db2;
L6db2: /* bne $6de4 */

if(!fz)goto L6de4;
goto L6db4;
L6db4: /* move.b (-$1,A1,D1.w), D1 */

ea=(-1+a[1]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L6db8;
L6db8: /* lea ($400,A5), A1 */

a[1]=(1024+a[5]);
goto L6dbc;
L6dbc: /* move.w (A1), D0 */

ea=a[1];
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6dbe;
L6dbe: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6dc0;
L6dc0: /* move.w (A1,D3.w), D3 */

ea=(a[1]+((s16)(d[3])));
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L6dc4;
L6dc4: /* cmpi.w #$1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L6dc8;
L6dc8: /* bne $6ddc */

if(!fz)goto L6ddc;
goto L6dca;
L6dca: /* move.w $9078.l, D2 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[2])=(u16)(tv);

goto L6dd0;
L6dd0: /* andi.w #$e0, D2 */

tv=((u16)(224L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L6dd4;
L6dd4: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6dd6;
L6dd6: /* sub.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6dd8;
L6dd8: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6dda;
L6dda: /* sub.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6ddc;
L6ddc: /* sub.w D0, D3 */

tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L6dde;
L6dde: /* move.w D3, D1 */

tv=((u16)d[3]);
VWORD(d[1])=(u16)(tv);

goto L6de0;
L6de0: /* bra $6e6e */

goto L6e6e;
L6de4: /* move.b (A1,D1.w), D1 */

ea=(a[1]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L6de8;
L6de8: /* lea ($400,A5), A1 */

a[1]=(1024+a[5]);
goto L6dec;
L6dec: /* move.w (A1), D0 */

ea=a[1];
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6dee;
L6dee: /* move.w (A1,D3.w), D3 */

ea=(a[1]+((s16)(d[3])));
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L6df2;
L6df2: /* add.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L6df4;
L6df4: /* cmpi.w #$1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L6df8;
L6df8: /* bne $6e0c */

if(!fz)goto L6e0c;
goto L6dfa;
L6dfa: /* move.w $9078.l, D2 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[2])=(u16)(tv);

goto L6e00;
L6e00: /* andi.w #$e0, D2 */

tv=((u16)(224L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L6e04;
L6e04: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6e06;
L6e06: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6e08;
L6e08: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6e0a;
L6e0a: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6e0c;
L6e0c: /* sub.w D0, D3 */

tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L6e0e;
L6e0e: /* move.w D3, D1 */

tv=((u16)d[3]);
VWORD(d[1])=(u16)(tv);

goto L6e10;
L6e10: /* bra $6e6e */

goto L6e6e;
L6e12: /* btst #$1, D0 */

v=((u16)(1L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L6e16;
L6e16: /* bne $6e44 */

if(!fz)goto L6e44;
goto L6e18;
L6e18: /* move.w (A5), D0 */

ea=a[5];
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6e1a;
L6e1a: /* move.b (-$1,A1,D1.w), D1 */

ea=(-1+a[1]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L6e1e;
L6e1e: /* sub.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6e20;
L6e20: /* move.w (A5,D3.w), D3 */

ea=(a[5]+((s16)(d[3])));
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L6e24;
L6e24: /* cmpi.w #$1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L6e28;
L6e28: /* bne $6e3c */

if(!fz)goto L6e3c;
goto L6e2a;
L6e2a: /* move.w $9078.l, D2 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[2])=(u16)(tv);

goto L6e30;
L6e30: /* andi.w #$e0, D2 */

tv=((u16)(224L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L6e34;
L6e34: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6e36;
L6e36: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6e38;
L6e38: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6e3a;
L6e3a: /* add.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6e3c;
L6e3c: /* sub.w D0, D3 */

tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L6e3e;
L6e3e: /* move.w D3, D1 */

tv=((u16)d[3]);
VWORD(d[1])=(u16)(tv);

goto L6e40;
L6e40: /* movea.l A5, A1 */

v=((u32)a[5]);
a[1]=v;
goto L6e42;
L6e42: /* bra $6e6e */

goto L6e6e;
L6e44: /* move.w (A5), D0 */

ea=a[5];
tv=ver16(ea);
VWORD(d[0])=(u16)(tv);

goto L6e46;
L6e46: /* move.w (A5,D3.w), D3 */

ea=(a[5]+((s16)(d[3])));
tv=ver16(ea);
VWORD(d[3])=(u16)(tv);

goto L6e4a;
L6e4a: /* move.b (A1,D1.w), D1 */

ea=(a[1]+((s16)(d[1])));
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L6e4e;
L6e4e: /* sub.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L6e50;
L6e50: /* cmpi.w #$1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L6e54;
L6e54: /* bne $6e68 */

if(!fz)goto L6e68;
goto L6e56;
L6e56: /* move.w $9078.l, D2 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[2])=(u16)(tv);

goto L6e5c;
L6e5c: /* andi.w #$e0, D2 */

tv=((u16)(224L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L6e60;
L6e60: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6e62;
L6e62: /* sub.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6e64;
L6e64: /* lsr.w #2, D2 */

tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L6e66;
L6e66: /* sub.w D2, D0 */

tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6e68;
L6e68: /* sub.w D0, D3 */

tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L6e6a;
L6e6a: /* move.w D3, D1 */

tv=((u16)d[3]);
VWORD(d[1])=(u16)(tv);

goto L6e6c;
L6e6c: /* movea.l A5, A1 */

v=((u32)a[5]);
a[1]=v;
goto L6e6e;
L6e6e: /* cmpi.w #$2, D7 */

tv=((u16)(2L));
tw=((u16)d[7]);
fc=(u8)((u16)tw<(u16)tv);
goto L6e72;
L6e72: /* bcs $6ee0 */

if(fc)goto L6ee0;
goto L6e74;
L6e74: /* move.w D7, D2 */

tv=((u16)d[7]);
VWORD(d[2])=(u16)(tv);

goto L6e76;
L6e76: /* subq.w #1, D2 */

tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L6e78;
L6e78: /* tst.w D1 */

tv=((u16)d[1]);
fn=(u8)((tv&0x8000ul)!=0);
goto L6e7a;
L6e7a: /* bpl $6eae */

if(!fn)goto L6eae;
goto L6e7c;
L6e7c: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L6e7e;
L6e7e: /* cmp.w D1, D7 */

tv=((u16)d[1]);
tw=((u16)d[7]);
fc=(u8)((u16)tw<(u16)tv);
goto L6e80;
L6e80: /* bcs $6e98 */

if(fc)goto L6e98;
goto L6e82;
L6e82: /* move.b D7, D3 */

tv=((u8)d[7]);
VBYTE(d[3])=(u8)(tv);

goto L6e84;
L6e84: /* lsr.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=((u8)tw)>>1;
VBYTE(d[3])=(u8)(tr);
goto L6e86;
L6e86:vehicle_road_edge_run(0);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6e86_original: /* add.b D1, D3 */

tv=((u8)d[1]);
tw=((u8)d[3]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[3])=(u8)(tr);
goto L6e88;
L6e88: /* cmp.b D7, D3 */

tv=((u8)d[7]);
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);
goto L6e8a;
L6e8a: /* bcs $6e90 */

if(fc)goto L6e90;
goto L6e8c;
L6e8c: /* sub.b D7, D3 */

tv=((u8)d[7]);
tw=((u8)d[3]);
tr=tw-tv;
VBYTE(d[3])=(u8)(tr);
goto L6e8e;
L6e8e: /* subq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L6e90;
L6e90: /* move.w D0, (A1)+ */

tv=((u16)d[0]);
ea=a[1];
vew16(ea,tv);
a[1]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6e92;
L6e92: /* dbra D2, $6e86 */

VWORD(d[2])=(u16)(d[2]-1);
if((u16)d[2]!=65535u)goto L6e86;
goto L6e96;
L6e96: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6e98: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L6e9a;
L6e9a:vehicle_road_edge_run(1);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6e9a_original: /* subq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6e9c;
L6e9c: /* add.b D7, D3 */

tv=((u8)d[7]);
tw=((u8)d[3]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);
VBYTE(d[3])=(u8)(tr);
goto L6e9e;
L6e9e: /* bcs $6ea4 */

if(fc)goto L6ea4;
goto L6ea0;
L6ea0: /* cmp.b D1, D3 */

tv=((u8)d[1]);
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);
goto L6ea2;
L6ea2: /* bcs $6e9a */

if(fc)goto L6e9a;
goto L6ea4;
L6ea4: /* sub.b D1, D3 */

tv=((u8)d[1]);
tw=((u8)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[3])=(u8)(tr);
goto L6ea6;
L6ea6: /* move.w D0, (A1)+ */

tv=((u16)d[0]);
ea=a[1];
vew16(ea,tv);
a[1]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6ea8;
L6ea8: /* dbra D2, $6e9a */

VWORD(d[2])=(u16)(d[2]-1);
if((u16)d[2]!=65535u)goto L6e9a;
goto L6eac;
L6eac: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6eae: /* cmp.w D1, D7 */

tv=((u16)d[1]);
tw=((u16)d[7]);
fc=(u8)((u16)tw<(u16)tv);
goto L6eb0;
L6eb0: /* bcs $6eca */

if(fc)goto L6eca;
goto L6eb4;
L6eb4: /* move.b D7, D3 */

tv=((u8)d[7]);
VBYTE(d[3])=(u8)(tv);

goto L6eb6;
L6eb6: /* lsr.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=((u8)tw)>>1;
VBYTE(d[3])=(u8)(tr);
goto L6eb8;
L6eb8:vehicle_road_edge_run(2);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6eb8_original: /* add.b D1, D3 */

tv=((u8)d[1]);
tw=((u8)d[3]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[3])=(u8)(tr);
goto L6eba;
L6eba: /* cmp.b D7, D3 */

tv=((u8)d[7]);
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);
goto L6ebc;
L6ebc: /* bcs $6ec2 */

if(fc)goto L6ec2;
goto L6ebe;
L6ebe: /* sub.b D7, D3 */

tv=((u8)d[7]);
tw=((u8)d[3]);
tr=tw-tv;
VBYTE(d[3])=(u8)(tr);
goto L6ec0;
L6ec0: /* addq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L6ec2;
L6ec2: /* move.w D0, (A1)+ */

tv=((u16)d[0]);
ea=a[1];
vew16(ea,tv);
a[1]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6ec4;
L6ec4: /* dbra D2, $6eb8 */

VWORD(d[2])=(u16)(d[2]-1);
if((u16)d[2]!=65535u)goto L6eb8;
goto L6ec8;
L6ec8: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6eca: /* moveq #$0, D3 */

v=((u32)(0L));
d[3]=v;

goto L6ecc;
L6ecc:vehicle_road_edge_run(3);pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6ecc_original: /* addq.w #1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6ece;
L6ece: /* add.b D7, D3 */

tv=((u8)d[7]);
tw=((u8)d[3]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);
VBYTE(d[3])=(u8)(tr);
goto L6ed0;
L6ed0: /* bcs $6ed6 */

if(fc)goto L6ed6;
goto L6ed2;
L6ed2: /* cmp.b D1, D3 */

tv=((u8)d[1]);
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);
goto L6ed4;
L6ed4: /* bcs $6ecc */

if(fc)goto L6ecc;
goto L6ed6;
L6ed6: /* sub.b D1, D3 */

tv=((u8)d[1]);
tw=((u8)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[3])=(u8)(tr);
goto L6ed8;
L6ed8: /* move.w D0, (A1)+ */

tv=((u16)d[0]);
ea=a[1];
vew16(ea,tv);
a[1]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6eda;
L6eda: /* dbra D2, $6ecc */

VWORD(d[2])=(u16)(d[2]-1);
if((u16)d[2]!=65535u)goto L6ecc;
goto L6ede;
L6ede: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6ee0: /* add.w D1, D0 */

tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L6ee2;
L6ee2: /* move.w D0, (A1)+ */

tv=((u16)d[0]);
ea=a[1];
vew16(ea,tv);
a[1]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L6ee4;
L6ee4: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6ee6: if(vehicle_external(0x6ee6ul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L6f1c: /* movea.l $37c4.l, A0 */

v=(((u32)*(u16 *)(vehicle_io+196)<<16)|*(u16 *)(vehicle_io+198));
a[0]=v;
goto L6f22;
L6f22: /* lea ($2f80,A0), A0 */

a[0]=(12160+a[0]);
goto L6f26;
L6f26: /* lea $909f.l, A4 */

a[4]=0x909ful;
goto L6f2c;
L6f2c: /* lea $7bc8.l, A5 */

a[5]=0x7bc8ul;
goto L6f32;
L6f32: /* moveq #$0, D5 */

v=((u32)(0L));
d[5]=v;

goto L6f34;
L6f34: /* move.l #$130, D6 */

v=((u32)(304L));
d[6]=v;

goto L6f3a;
L6f3a: /* moveq #$60, D7 */

v=((u32)(96L));
d[7]=v;

goto L6f3c;
L6f3c: /* sub.b (A4), D7 */

ea=a[4];
tv=ver8(ea);
tw=((u8)d[7]);
tr=tw-tv;
VBYTE(d[7])=(u8)(tr);
goto L6f3e;
L6f3e: /* lea $8f74.l, A2 */

a[2]=0x8f74ul;
goto L6f44;
L6f44: /* move.w $9076.l, D4 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[4])=(u16)(tv);

goto L6f4a;
L6f4a: /* move.w D4, D0 */

tv=((u16)d[4]);
VWORD(d[0])=(u16)(tv);

goto L6f4c;
L6f4c: /* move.w D4, D1 */

tv=((u16)d[4]);
VWORD(d[1])=(u16)(tv);

goto L6f4e;
L6f4e: /* addi.b #-$80, D4 */

tv=((u8)(-128L));
tw=((u8)d[4]);
tr=tw+tv;
VBYTE(d[4])=(u8)(tr);
goto L6f52;
L6f52: /* andi.w #$1, D0 */

tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L6f56;
L6f56: /* move.w D0, $8f68.l */

tv=((u16)d[0]);
*(u16 *)(vehicle_state+586)=(u16)(tv);

goto L6f5c;
L6f5c: /* andi.w #$2, D1 */

tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw&tv;

VWORD(d[1])=(u16)(tr);
goto L6f60;
L6f60: /* lsr.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=((u16)tw)>>1;fx=(u8)((tw>>0)&1);
VWORD(d[1])=(u16)(tr);
goto L6f62;
L6f62: /* move.w D1, $8f6a.l */

tv=((u16)d[1]);
*(u16 *)(vehicle_state+588)=(u16)(tv);

goto L6f68;
L6f68: /* move.w #$2, $8f6c.l */

tv=((u16)(2L));
*(u16 *)(vehicle_state+590)=(u16)(tv);

goto L6f70;
L6f70: /* tst.w $8f6a.l */

tv=(*(u16 *)(vehicle_state+588));
fz=(u8)((tv&0xfffful)==0);
goto L6f76;
L6f76: /* movea.l A0, A3 */

v=((u32)a[0]);
a[3]=v;
goto L6f78;
L6f78: /* bne $6f7e */

if(!fz)goto L6f7e;
goto L6f7a;
L6f7a: /* lea ($2f80,A0), A3 */

a[3]=(12160+a[0]);
goto L6f7e;
L6f7e: /* move.b (A2,D4.w), D0 */

ea=(a[2]+((s16)(d[4])));
tv=ver8(ea);
VBYTE(d[0])=(u8)(tv);

goto L6f82;
L6f82: /* andi.w #$f, D0 */

tv=((u16)(15L));
tw=((u16)d[0]);
tr=tw&tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
VWORD(d[0])=(u16)(tr);
goto L6f86;
L6f86: /* beq $6fa0 */

if(fz)goto L6fa0;
goto L6f88;
L6f88: /* btst #$3, D0 */

v=((u16)(3L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L6f8c;
L6f8c: /* beq $6f9a */

if(fz)goto L6f9a;
goto L6f8e;
L6f8e: /* andi.l #$3, D0 */

v=((u32)(3L));
w=((u32)d[0]);
r=w&v;

d[0]=r;
goto L6f94;
L6f94: /* swap D0 */

v=((u32)d[0]);
r=((v<<16)|(v>>16));
d[0]=r;

goto L6f96;
L6f96: /* or.l D0, D5 */

v=((u32)d[0]);
w=((u32)d[5]);
r=w|v;

d[5]=r;
goto L6f98;
L6f98: /* bra $6fa6 */

goto L6fa6;
L6f9a: /* bsr $6d82 */

a[7]-=4;STACK_WRITE(a[7],0x6f9eul);
goto L6d82;
L6f9e: /* movea.l A0, A3 */

v=((u32)a[0]);
a[3]=v;
goto L6fa0;
L6fa0: /* andi.l #$ffff, D5 */

v=((u32)(65535L));
w=((u32)d[5]);
r=w&v;

d[5]=r;
goto L6fa6;
L6fa6: /* subq.b #1, D7 */

tv=((u8)(1L));
tw=((u8)d[7]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x80ul)!=0);fz=(u8)((tr&0xfful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
VBYTE(d[7])=(u8)(tr);
goto L6fa8;
L6fa8:vehicle_road_run();return 0x70b8ul;
L6fa8_original: if(vehicle_external(0x6fa8ul))return 0;return 0x70aeul;
}
static u32 part3(u32 pc){u32 v,w,r,ea,eb,stkp,stkv; u16 tv,tw,tr;s32 signed_result;if(pc==0x70b8ul)goto L70b8;
dispatch: if(!pc)return 0;if(pc<0x7000ul||pc>=0x10000ul)return pc;
VD: if(pc<0x74c8ul)goto VDL;goto VDR;
VDL: if(pc<0x70ccul)goto VDLL;goto VDLR;
VDLL: if(pc<0x70c0ul)goto VDLLL;goto VDLLR;
VDLLL: if(pc==0x70aeul)goto L70ae;vm_fault=pc;return 0;
VDLLR: if(pc==0x70c0ul)goto L70c0;vm_fault=pc;return 0;
VDLR: if(pc<0x712aul)goto VDLRL;goto VDLRR;
VDLRL: if(pc==0x70ccul)goto L70cc;vm_fault=pc;return 0;
VDLRR: if(pc==0x712aul)goto L712a;vm_fault=pc;return 0;
VDR: if(pc<0x750cul)goto VDRL;goto VDRR;
VDRL: if(pc<0x74daul)goto VDRLL;goto VDRLR;
VDRLL: if(pc==0x74c8ul)goto L74c8;vm_fault=pc;return 0;
VDRLR: if(pc==0x74daul)goto L74da;vm_fault=pc;return 0;
VDRR: if(pc<0x764aul)goto VDRRL;goto VDRRR;
VDRRL: if(pc==0x750cul)goto L750c;vm_fault=pc;return 0;
VDRRR: if(pc<0x7674ul)goto VDRRRL;goto VDRRRR;
VDRRRL: if(pc==0x764aul)goto L764a;vm_fault=pc;return 0;
VDRRRR: if(pc==0x7674ul)goto L7674;vm_fault=pc;return 0;
L70ae: /* addi.l #$10000, D6 */

v=((u32)(65536L));
w=((u32)d[6]);
r=w+v;fc=(u8)(r<w);fx=(u8)(r<w);fn=(u8)((r&0x80000000ul)!=0);fz=(u8)((r&0xfffffffful)==0);fv=(u8)((~(w^v)&(w^r)&0x80000000ul)!=0);
d[6]=r;
goto L70b4;
L70b4: /* dbra D7, $6fa8 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)return 0x6fa8ul;
goto L70b8;
L70b8: /* not.w D7 */

tv=((u16)d[7]);
tr=~tv;
VWORD(d[7])=(u16)(tr);
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
goto L70ba;
L70ba: /* bra $70be */

goto L70be;
L70bc: /* addq.w #2, A5 */

v=((u16)(2L));
w=((u32)a[5]);
r=w+v;
a[5]=r;
goto L70be;
L70be: /* bsr $70f4 */

a[7]-=4;STACK_WRITE(a[7],0x70c0ul);
goto L70f4;
L70c0: /* addq.b #1, D4 */

tv=((u8)(1L));
tw=((u8)d[4]);
tr=tw+tv;
VBYTE(d[4])=(u8)(tr);
goto L70c2;
L70c2: /* move.b (A4)+, D7 */

ea=a[4];
tv=ver8(ea);
a[4]+=1;
VBYTE(d[7])=(u8)(tv);

goto L70c4;
L70c4: /* sub.b (A4), D7 */

ea=a[4];
tv=ver8(ea);
tw=((u8)d[7]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x80ul)!=0);fz=(u8)((tr&0xfful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
VBYTE(d[7])=(u8)(tr);
goto L70c6;
L70c6: /* beq $70bc */

if(fz)goto L70bc;
goto L70c8;
L70c8: /* bpl $70ea */

if(!fn)goto L70ea;
goto L70ca;
L70ca: /* bsr $70f4 */

a[7]-=4;STACK_WRITE(a[7],0x70ccul);
goto L70f4;
L70cc: /* move.b (A4)+, D0 */

ea=a[4];
tv=ver8(ea);
a[4]+=1;
VBYTE(d[0])=(u8)(tv);

goto L70ce;
L70ce: /* sub.b (A4), D0 */

ea=a[4];
tv=ver8(ea);
tw=((u8)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[0])=(u8)(tr);
goto L70d0;
L70d0: /* cmpi.b #-$20, D0 */

tv=((u8)(-32L));
tw=((u8)d[0]);
fc=(u8)((u8)tw<(u8)tv);
goto L70d4;
L70d4: /* bcc $70dc */

if(!fc)goto L70dc;
goto L70d6;
L70d6: /* cmpi.b #$50, D0 */

tv=((u8)(80L));
tw=((u8)d[0]);
fc=(u8)((u8)tw<(u8)tv);
goto L70da;
L70da: /* bcc $7122 */

if(!fc)goto L7122;
goto L70dc;
L70dc: /* addq.w #2, A5 */

v=((u16)(2L));
w=((u32)a[5]);
r=w+v;
a[5]=r;
goto L70de;
L70de: /* addq.b #1, D4 */

tv=((u8)(1L));
tw=((u8)d[4]);
tr=tw+tv;
VBYTE(d[4])=(u8)(tr);
goto L70e0;
L70e0: /* add.b D0, D7 */

tv=((u8)d[0]);
tw=((u8)d[7]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);fx=(u8)((tr&~0xfful)!=0);fn=(u8)((tr&0x80ul)!=0);fz=(u8)((tr&0xfful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x80ul)!=0);
VBYTE(d[7])=(u8)(tr);
goto L70e2;
L70e2: /* beq $70ca */

if(fz)goto L70ca;
goto L70e4;
L70e4: /* bmi $70ca */

if(fn)goto L70ca;
goto L70e6;
L70e6: /* bra $6f70 */

return 0x6f70ul;
L70ea: /* cmpi.b #$50, D7 */

tv=((u8)(80L));
tw=((u8)d[7]);
fc=(u8)((u8)tw<(u8)tv);
goto L70ee;
L70ee: /* bcs $6f70 */

if(fc)return 0x6f70ul;
goto L70f2;
L70f2: /* bra $7122 */

goto L7122;
L70f4: /* eori.w #$1, $8f68.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+586));
tr=tw^tv;
fz=(u8)((tr&0xfffful)==0);
*(u16 *)(vehicle_state+586)=(u16)(tr);
goto L70fc;
L70fc: /* bne $7106 */

if(!fz)goto L7106;
goto L70fe;
L70fe: /* eori.w #$1, $8f6a.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+588));
tr=tw^tv;

*(u16 *)(vehicle_state+588)=(u16)(tr);
goto L7106;
L7106: /* subq.w #1, $8f6c.l */

tv=((u16)(1L));
tw=(*(u16 *)(vehicle_state+590));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
*(u16 *)(vehicle_state+590)=(u16)(tr);
goto L710c;
L710c: /* bne $7120 */

if(!fz)goto L7120;
goto L710e;
L710e: /* move.w #$3, $8f6c.l */

tv=((u16)(3L));
*(u16 *)(vehicle_state+590)=(u16)(tv);

goto L7116;
L7116: /* cmpi.w #$100, D5 */

tv=((u16)(256L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L711a;
L711a: /* bcc $7120 */

if(!fc)goto L7120;
goto L711c;
L711c: /* addi.w #$40, D5 */

tv=((u16)(64L));
tw=((u16)d[5]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[5])=(u16)(tr);
goto L7120;
L7120: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L7122: /* swap D6 */

v=((u32)d[6]);
r=((v<<16)|(v>>16));
d[6]=r;

goto L7124;
L7124: /* move.w D6, $8d3a.l */

tv=((u16)d[6]);
*(u16 *)(vehicle_state+28)=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L712a;
L712a: if(vehicle_external(0x712aul))return 0;pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L74c8: /* move.w $9074.l, D5 */

tv=(*(u16 *)(vehicle_state+854));
VWORD(d[5])=(u16)(tv);

goto L74ce;
L74ce: /* move.w D5, -(A7) */

tv=((u16)d[5]);
a[7]-=2;
ea=a[7];
vew16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L74d0;
L74d0: /* lea $7fc8.l, A5 */

a[5]=0x7fc8ul;
goto L74d6;
L74d6: /* bsr $74e6 */

a[7]-=4;STACK_WRITE(a[7],0x74daul);
goto L74e6;
L74da: /* move.w (A7)+, D5 */

ea=a[7];
tv=ver16(ea);
a[7]+=2;
VWORD(d[5])=(u16)(tv);

goto L74dc;
L74dc: /* subi.w #$1a9, D5 */

tv=((u16)(425L));
tw=((u16)d[5]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[5])=(u16)(tr);
goto L74e0;
L74e0: /* lea $7bc8.l, A5 */

a[5]=0x7bc8ul;
goto L74e6;
L74e6: /* lea $8f74.l, A0 */

a[0]=0x8f74ul;
goto L74ec;
L74ec: /* move.w $9076.l, D6 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[6])=(u16)(tv);

goto L74f2;
L74f2: /* move.b (A0,D6.w), D2 */

ea=(a[0]+((s16)(d[6])));
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L74f6;
L74f6: /* move.w $9078.l, D1 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[1])=(u16)(tv);

goto L74fc;
L74fc: /* andi.b #$e0, D1 */

tv=((u8)(224L));
tw=((u8)d[1]);
tr=tw&tv;
fn=(u8)((tr&0x80ul)!=0);fz=(u8)((tr&0xfful)==0);fv=0;fc=0;
VBYTE(d[1])=(u8)(tr);
goto L7500;
L7500: /* lea $7920.l, A1 */

a[1]=0x7920ul;
goto L7506;
L7506: /* adda.w D1, A1 */

v=((u16)d[1]);
w=((u32)a[1]);
v=(s32)(s16)v;
r=w+v;
a[1]=r;
goto L7508;
L7508: /* bsr $7704 */

a[7]-=4;STACK_WRITE(a[7],0x750cul);
goto L7704;
L750c: /* neg.b D0 */

tv=((u8)d[0]);
tr=0-tv;
VBYTE(d[0])=(u8)(tr);
goto L750e;
L750e: /* addi.b #-$80, D0 */

tv=((u8)(-128L));
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L7512;
L7512: /* andi.w #$fe, D0 */

tv=((u16)(254L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L7516;
L7516: /* lea $7720.l, A2 */

a[2]=0x7720ul;
goto L751c;
L751c: /* lea $90b6.l, A3 */

a[3]=0x90b6ul;
goto L7522;
L7522: /* moveq #$15, D7 */

v=((u32)(21L));
d[7]=v;

goto L7524;
L7524: /* move.w D5, D1 */

tv=((u16)d[5]);
VWORD(d[1])=(u16)(tv);

goto L7526;
L7526: /* add.b (A0,D6.w), D0 */

ea=(a[0]+((s16)(d[6])));
tv=ver8(ea);
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L752a;
L752a: /* addq.b #1, D6 */

tv=((u8)(1L));
tw=((u8)d[6]);
tr=tw+tv;
VBYTE(d[6])=(u8)(tr);
goto L752c;
L752c: /* moveq #$0, D2 */

v=((u32)(0L));
d[2]=v;

goto L752e;
L752e: /* move.w (A2,D0.w), D4 */

ea=(a[2]+((s16)(d[0])));
tv=ver16(ea);
VWORD(d[4])=(u16)(tv);

goto L7532;
L7532: /* sub.w D1, D4 */

tv=((u16)d[1]);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L7534;
L7534: /* addi.w #$1e, D4 */

tv=((u16)(30L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L7538;
L7538: /* ext.l D4 */

v=((u32)d[4]);
r=(s32)(s16)v;
d[4]=r;

goto L753a;
L753a:
 v=vehicle_code[((u16)a[1]-0x2ffcu)^1u];a[1]++;
 r=(u32)vehicle_mul16(d[4],v>>1);VBYTE(d[3])=(u8)(v<<7);
 d[2]=(s32)r>>9;fc=fx=(u8)((r>>8)&1ul);fn=(u8)((d[2]&0x80000000ul)!=0);fz=(u8)(d[2]==0);fv=0;
 goto L7576;
L753a_original: /* move.b (A1)+, D3 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[3])=(u8)(tv);

goto L753c;
L753c: /* lsl.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[3])=(u8)(tr);
goto L753e;
L753e: /* bcc $7544 */

if(!fc)goto L7544;
goto L7540;
L7540: /* move.l D4, D2 */

v=((u32)d[4]);
d[2]=v;

goto L7542;
L7542: /* asl.l #1, D2 */

v=((u32)(1L));
w=((u32)d[2]);
r=w<<1;
d[2]=r;
goto L7544;
L7544: /* asl.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[3])=(u8)(tr);
goto L7546;
L7546: /* bcc $754a */

if(!fc)goto L754a;
goto L7548;
L7548: /* add.l D4, D2 */

v=((u32)d[4]);
w=((u32)d[2]);
r=w+v;
d[2]=r;
goto L754a;
L754a: /* asl.l #1, D2 */

v=((u32)(1L));
w=((u32)d[2]);
r=w<<1;
d[2]=r;
goto L754c;
L754c: /* asl.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[3])=(u8)(tr);
goto L754e;
L754e: /* bcc $7552 */

if(!fc)goto L7552;
goto L7550;
L7550: /* add.l D4, D2 */

v=((u32)d[4]);
w=((u32)d[2]);
r=w+v;
d[2]=r;
goto L7552;
L7552: /* asl.l #1, D2 */

v=((u32)(1L));
w=((u32)d[2]);
r=w<<1;
d[2]=r;
goto L7554;
L7554: /* asl.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[3])=(u8)(tr);
goto L7556;
L7556: /* bcc $755a */

if(!fc)goto L755a;
goto L7558;
L7558: /* add.l D4, D2 */

v=((u32)d[4]);
w=((u32)d[2]);
r=w+v;
d[2]=r;
goto L755a;
L755a: /* asl.l #1, D2 */

v=((u32)(1L));
w=((u32)d[2]);
r=w<<1;
d[2]=r;
goto L755c;
L755c: /* asl.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[3])=(u8)(tr);
goto L755e;
L755e: /* bcc $7562 */

if(!fc)goto L7562;
goto L7560;
L7560: /* add.l D4, D2 */

v=((u32)d[4]);
w=((u32)d[2]);
r=w+v;
d[2]=r;
goto L7562;
L7562: /* asl.l #1, D2 */

v=((u32)(1L));
w=((u32)d[2]);
r=w<<1;
d[2]=r;
goto L7564;
L7564: /* asl.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[3])=(u8)(tr);
goto L7566;
L7566: /* bcc $756a */

if(!fc)goto L756a;
goto L7568;
L7568: /* add.l D4, D2 */

v=((u32)d[4]);
w=((u32)d[2]);
r=w+v;
d[2]=r;
goto L756a;
L756a: /* asl.l #1, D2 */

v=((u32)(1L));
w=((u32)d[2]);
r=w<<1;
d[2]=r;
goto L756c;
L756c: /* asl.b #1, D3 */

tv=((u8)(1L));
tw=((u8)d[3]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[3])=(u8)(tr);
goto L756e;
L756e: /* bcc $7572 */

if(!fc)goto L7572;
goto L7570;
L7570: /* add.l D4, D2 */

v=((u32)d[4]);
w=((u32)d[2]);
r=w+v;
d[2]=r;
goto L7572;
L7572: /* asr.l #1, D2 */

v=((u32)(1L));
w=((u32)d[2]);
r=((s32)w)>>1;
d[2]=r;
goto L7574;
L7574: /* asr.l #8, D2 */

v=((u32)(8L));
w=((u32)d[2]);
r=((s32)w)>>8;
d[2]=r;
goto L7576;
L7576: /* move.b D2, (A3)+ */

tv=((u8)d[2]);
ea=a[3];
vew8(ea,tv);
a[3]+=1;

goto L7578;
L7578: /* add.w D2, D1 */

tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L757a;
L757a: /* asr.w #8, D2 */

tv=((u16)(8L));
tw=((u16)d[2]);
tr=((s16)tw)>>8;
VWORD(d[2])=(u16)(tr);
goto L757c;
L757c: /* move.b D2, ($15,A3) */

tv=((u8)d[2]);
ea=(21+a[3]);
vew8(ea,tv);

goto L7580;
L7580: /* dbra D7, $7526 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L7526;
goto L7584;
L7584: /* lea $909e.l, A1 */

a[1]=0x909eul;
goto L758a;
L758a: /* moveq #$14, D7 */

v=((u32)(20L));
d[7]=v;

goto L758c;
L758c: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L758e;
L758e: /* move.w D1, D2 */

tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L7590;
L7590: /* subq.b #2, D2 */

tv=((u8)(2L));
tw=((u8)d[2]);
tr=tw-tv;
VBYTE(d[2])=(u8)(tr);
goto L7592;
L7592: /* add.b (A1)+, D2 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
tw=((u8)d[2]);
tr=tw+tv;
VBYTE(d[2])=(u8)(tr);
goto L7594;
L7594: /* sub.b (A1), D2 */

ea=a[1];
tv=ver8(ea);
tw=((u8)d[2]);
tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);
VBYTE(d[2])=(u8)(tr);
goto L7596;
L7596: /* bmi $7628 */

if(fn)goto L7628;
goto L759a;
L759a: /* addq.b #2, D2 */

tv=((u8)(2L));
tw=((u8)d[2]);
tr=tw+tv;
VBYTE(d[2])=(u8)(tr);
goto L759c;
L759c: /* move.b D2, ($5a,A1) */

tv=((u8)d[2]);
ea=(90+a[1]);
vew8(ea,tv);

goto L75a0;
L75a0: /* sub.b D1, D2 */

tv=((u8)d[1]);
tw=((u8)d[2]);
tr=tw-tv;
VBYTE(d[2])=(u8)(tr);
goto L75a2;
L75a2: /* move.b D2, D1 */

tv=((u8)d[2]);
VBYTE(d[1])=(u8)(tv);

goto L75a4;
L75a4: /* subq.b #1, D1 */

tv=((u8)(1L));
tw=((u8)d[1]);
tr=tw-tv;
VBYTE(d[1])=(u8)(tr);
goto L75a6;
L75a6: /* move.b ($2d,A1), D3 */

ea=(45+a[1]);
tv=ver8(ea);
VBYTE(d[3])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);
goto L75aa;
L75aa: /* bpl $75ea */

if(!fn)goto L75ea;
goto L75ac;
L75ac: /* move.b ($17,A1), D3 */

ea=(23+a[1]);
tv=ver8(ea);
VBYTE(d[3])=(u8)(tv);

goto L75b0;
L75b0: /* neg.b D3 */

tv=((u8)d[3]);
tr=0-tv;
VBYTE(d[3])=(u8)(tr);
goto L75b2;
L75b2: /* cmp.b D3, D2 */

tv=((u8)d[3]);
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L75b4;
L75b4: /* bcs $75d0 */

if(fc)goto L75d0;
goto L75b6;
L75b6: /* move.b D2, D4 */

tv=((u8)d[2]);
VBYTE(d[4])=(u8)(tv);

goto L75b8;
L75b8: /* lsr.b #1, D4 */

tv=((u8)(1L));
tw=((u8)d[4]);
tr=((u8)tw)>>1;
VBYTE(d[4])=(u8)(tr);
goto L75ba;
L75ba:vehicle_edge_run(0);goto L75ca;
L75ba_original: /* add.b D3, D4 */

tv=((u8)d[3]);
tw=((u8)d[4]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[4])=(u8)(tr);
goto L75bc;
L75bc: /* cmp.b D2, D4 */

tv=((u8)d[2]);
tw=((u8)d[4]);
fc=(u8)((u8)tw<(u8)tv);
goto L75be;
L75be: /* bcs $75c4 */

if(fc)goto L75c4;
goto L75c0;
L75c0: /* sub.b D2, D4 */

tv=((u8)d[2]);
tw=((u8)d[4]);
tr=tw-tv;
VBYTE(d[4])=(u8)(tr);
goto L75c2;
L75c2: /* subq.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[5])=(u16)(tr);
goto L75c4;
L75c4: /* move.w D5, (A5)+ */

tv=((u16)d[5]);
ea=a[5];
vew16(ea,tv);
a[5]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L75c6;
L75c6: /* dbra D1, $75ba */

VWORD(d[1])=(u16)(d[1]-1);
if((u16)d[1]!=65535u)goto L75ba;
goto L75ca;
L75ca: /* dbra D7, $758c */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L758c;
goto L75ce;
L75ce: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L75d0: /* moveq #$0, D4 */

v=((u32)(0L));
d[4]=v;

goto L75d2;
L75d2:vehicle_edge_run(1);goto L75e4;
L75d2_original: /* subq.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L75d4;
L75d4: /* add.b D2, D4 */

tv=((u8)d[2]);
tw=((u8)d[4]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);
VBYTE(d[4])=(u8)(tr);
goto L75d6;
L75d6: /* bcs $75dc */

if(fc)goto L75dc;
goto L75d8;
L75d8: /* cmp.b D3, D4 */

tv=((u8)d[3]);
tw=((u8)d[4]);
fc=(u8)((u8)tw<(u8)tv);
goto L75da;
L75da: /* bcs $75d2 */

if(fc)goto L75d2;
goto L75dc;
L75dc: /* sub.b D3, D4 */

tv=((u8)d[3]);
tw=((u8)d[4]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[4])=(u8)(tr);
goto L75de;
L75de: /* move.w D5, (A5)+ */

tv=((u16)d[5]);
ea=a[5];
vew16(ea,tv);
a[5]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L75e0;
L75e0: /* dbra D1, $75d2 */

VWORD(d[1])=(u16)(d[1]-1);
if((u16)d[1]!=65535u)goto L75d2;
goto L75e4;
L75e4: /* dbra D7, $758c */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L758c;
goto L75e8;
L75e8: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L75ea: /* move.b ($17,A1), D3 */

ea=(23+a[1]);
tv=ver8(ea);
VBYTE(d[3])=(u8)(tv);

goto L75ee;
L75ee: /* cmp.b D3, D2 */

tv=((u8)d[3]);
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L75f0;
L75f0: /* bcs $760e */

if(fc)goto L760e;
goto L75f4;
L75f4: /* move.b D2, D4 */

tv=((u8)d[2]);
VBYTE(d[4])=(u8)(tv);

goto L75f6;
L75f6: /* lsr.b #1, D4 */

tv=((u8)(1L));
tw=((u8)d[4]);
tr=((u8)tw)>>1;
VBYTE(d[4])=(u8)(tr);
goto L75f8;
L75f8:vehicle_edge_run(2);goto L7608;
L75f8_original: /* add.b D3, D4 */

tv=((u8)d[3]);
tw=((u8)d[4]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[4])=(u8)(tr);
goto L75fa;
L75fa: /* cmp.b D2, D4 */

tv=((u8)d[2]);
tw=((u8)d[4]);
fc=(u8)((u8)tw<(u8)tv);
goto L75fc;
L75fc: /* bcs $7602 */

if(fc)goto L7602;
goto L75fe;
L75fe: /* sub.b D2, D4 */

tv=((u8)d[2]);
tw=((u8)d[4]);
tr=tw-tv;
VBYTE(d[4])=(u8)(tr);
goto L7600;
L7600: /* addq.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[5])=(u16)(tr);
goto L7602;
L7602: /* move.w D5, (A5)+ */

tv=((u16)d[5]);
ea=a[5];
vew16(ea,tv);
a[5]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L7604;
L7604: /* dbra D1, $75f8 */

VWORD(d[1])=(u16)(d[1]-1);
if((u16)d[1]!=65535u)goto L75f8;
goto L7608;
L7608: /* dbra D7, $758c */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L758c;
goto L760c;
L760c: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L760e: /* moveq #$0, D4 */

v=((u32)(0L));
d[4]=v;

goto L7610;
L7610:vehicle_edge_run(3);goto L7622;
L7610_original: /* addq.w #1, D5 */

tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L7612;
L7612: /* add.b D2, D4 */

tv=((u8)d[2]);
tw=((u8)d[4]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);
VBYTE(d[4])=(u8)(tr);
goto L7614;
L7614: /* bcs $761a */

if(fc)goto L761a;
goto L7616;
L7616: /* cmp.b D3, D4 */

tv=((u8)d[3]);
tw=((u8)d[4]);
fc=(u8)((u8)tw<(u8)tv);
goto L7618;
L7618: /* bcs $7610 */

if(fc)goto L7610;
goto L761a;
L761a: /* sub.b D3, D4 */

tv=((u8)d[3]);
tw=((u8)d[4]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[4])=(u8)(tr);
goto L761c;
L761c: /* move.w D5, (A5)+ */

tv=((u16)d[5]);
ea=a[5];
vew16(ea,tv);
a[5]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L761e;
L761e: /* dbra D1, $7610 */

VWORD(d[1])=(u16)(d[1]-1);
if((u16)d[1]!=65535u)goto L7610;
goto L7622;
L7622: /* dbra D7, $758c */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L758c;
goto L7626;
L7626: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L7628: /* move.b #$1, ($5a,A1) */

tv=((u8)(1L));
ea=(90+a[1]);
vew8(ea,tv);

goto L762e;
L762e: /* addq.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw+tv;fz=(u8)((tr&0xfful)==0);
VBYTE(d[2])=(u8)(tr);
goto L7630;
L7630: /* beq $7634 */

if(fz)goto L7634;
goto L7632;
L7632: /* addq.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw+tv;
VBYTE(d[2])=(u8)(tr);
goto L7634;
L7634: /* move.w D2, D1 */

tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L7636;
L7636: /* move.b ($2d,A1), D2 */

ea=(45+a[1]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L763a;
L763a: /* lsl.w #8, D2 */

tv=((u16)(8L));
tw=((u16)d[2]);
tr=tw<<8;
VWORD(d[2])=(u16)(tr);
goto L763c;
L763c: /* move.b ($17,A1), D2 */

ea=(23+a[1]);
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L7640;
L7640: /* add.w D2, D5 */

tv=((u16)d[2]);
tw=((u16)d[5]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[5])=(u16)(tr);
goto L7642;
L7642: /* move.w D5, (A5)+ */

tv=((u16)d[5]);
ea=a[5];
vew16(ea,tv);
a[5]+=2;
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L7644;
L7644: /* dbra D7, $758e */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L758e;
goto L7648;
L7648: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L764a: /* lea $8f74.l, A0 */

a[0]=0x8f74ul;
goto L7650;
L7650: /* move.w $9076.l, D6 */

tv=(*(u16 *)(vehicle_state+856));
VWORD(d[6])=(u16)(tv);

goto L7656;
L7656: /* addi.b #$20, D6 */

tv=((u8)(32L));
tw=((u8)d[6]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[6])=(u8)(tr);
goto L765a;
L765a: /* move.b (A0,D6.w), D2 */

ea=(a[0]+((s16)(d[6])));
tv=ver8(ea);
VBYTE(d[2])=(u8)(tv);

goto L765e;
L765e: /* move.w $9078.l, D1 */

tv=(*(u16 *)(vehicle_state+858));
VWORD(d[1])=(u16)(tv);

goto L7664;
L7664: /* andi.b #$e0, D1 */

tv=((u8)(224L));
tw=((u8)d[1]);
tr=tw&tv;
fn=(u8)((tr&0x80ul)!=0);fz=(u8)((tr&0xfful)==0);fv=0;fc=0;
VBYTE(d[1])=(u8)(tr);
goto L7668;
L7668: /* lea $7821.l, A1 */

a[1]=0x7821ul;
goto L766e;
L766e: /* adda.w D1, A1 */

v=((u16)d[1]);
w=((u32)a[1]);
v=(s32)(s16)v;
r=w+v;
a[1]=r;
goto L7670;
L7670: /* bsr $7704 */

a[7]-=4;STACK_WRITE(a[7],0x7674ul);
goto L7704;
L7674: /* neg.b D0 */

tv=((u8)d[0]);
tr=0-tv;
VBYTE(d[0])=(u8)(tr);
goto L7676;
L7676: /* moveq #$14, D7 */

v=((u32)(20L));
d[7]=v;

goto L7678;
L7678: /* lea $909f.l, A2 */

a[2]=0x909ful;
goto L767e;
L767e: /* moveq #$0, D1 */

v=((u32)(0L));
d[1]=v;

goto L7680;
L7680: /* move.w D1, D3 */

tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L7682;
L7682:
 v=vehicle_code[((u16)a[1]-0x2ffcu)^1u];d[1]=(u16)(v*2u);VWORD(d[3])=0;
 w=ver8(a[0]+(s16)d[6]);VBYTE(d[0])=(u8)((u8)d[0]+(u8)w);
 if(!(u8)d[0])goto L7700;
 v=(u8)d[0];if(v&128ul){VWORD(d[1])=(u16)(0u-(u16)d[1]);v=(u8)(0u-v);}
 r=(u16)vehicle_mul16(d[1],v&127ul);VBYTE(d[2])=0;
 VWORD(d[3])=(u16)((s16)r>>7);fc=fx=(u8)((r>>6)&1ul);fn=(u8)(((u16)d[3]&0x8000u)!=0);fz=(u8)((u16)d[3]==0);fv=0;
 goto L76ce;
L7682_original: /* move.b (A1), D1 */

ea=a[1];
tv=ver8(ea);
VBYTE(d[1])=(u8)(tv);

goto L7684;
L7684: /* asl.w #1, D1 */

tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw<<1;
VWORD(d[1])=(u16)(tr);
goto L7686;
L7686: /* add.b (A0,D6.w), D0 */

ea=(a[0]+((s16)(d[6])));
tv=ver8(ea);
tw=((u8)d[0]);
tr=tw+tv;fz=(u8)((tr&0xfful)==0);
VBYTE(d[0])=(u8)(tr);
goto L768a;
L768a: /* beq $7700 */

if(fz)goto L7700;
goto L768c;
L768c: /* move.b D0, D2 */

tv=((u8)d[0]);
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);
goto L768e;
L768e: /* bpl $7694 */

if(!fn)goto L7694;
goto L7690;
L7690: /* neg.w D1 */

tv=((u16)d[1]);
tr=0-tv;
VWORD(d[1])=(u16)(tr);
goto L7692;
L7692: /* neg.b D2 */

tv=((u8)d[2]);
tr=0-tv;
VBYTE(d[2])=(u8)(tr);
goto L7694;
L7694: /* add.b D2, D2 */

tv=((u8)d[2]);
tw=((u8)d[2]);
tr=tw+tv;
VBYTE(d[2])=(u8)(tr);
goto L7696;
L7696: /* add.b D2, D2 */

tv=((u8)d[2]);
tw=((u8)d[2]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);
VBYTE(d[2])=(u8)(tr);
goto L7698;
L7698: /* bcc $769e */

if(!fc)goto L769e;
goto L769a;
L769a: /* move.w D1, D3 */

tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L769c;
L769c: /* asl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L769e;
L769e: /* asl.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[2])=(u8)(tr);
goto L76a0;
L76a0: /* bcc $76a4 */

if(!fc)goto L76a4;
goto L76a2;
L76a2: /* add.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L76a4;
L76a4: /* asl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L76a6;
L76a6: /* asl.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[2])=(u8)(tr);
goto L76a8;
L76a8: /* bcc $76ac */

if(!fc)goto L76ac;
goto L76aa;
L76aa: /* add.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L76ac;
L76ac: /* asl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L76ae;
L76ae: /* asl.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[2])=(u8)(tr);
goto L76b0;
L76b0: /* bcc $76b4 */

if(!fc)goto L76b4;
goto L76b2;
L76b2: /* add.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L76b4;
L76b4: /* asl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L76b6;
L76b6: /* asl.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[2])=(u8)(tr);
goto L76b8;
L76b8: /* bcc $76bc */

if(!fc)goto L76bc;
goto L76ba;
L76ba: /* add.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L76bc;
L76bc: /* asl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L76be;
L76be: /* asl.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[2])=(u8)(tr);
goto L76c0;
L76c0: /* bcc $76c4 */

if(!fc)goto L76c4;
goto L76c2;
L76c2: /* add.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L76c4;
L76c4: /* asl.w #1, D3 */

tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L76c6;
L76c6: /* asl.b #1, D2 */

tv=((u8)(1L));
tw=((u8)d[2]);
tr=tw<<1;fc=(u8)((tw>>7)&1);
VBYTE(d[2])=(u8)(tr);
goto L76c8;
L76c8: /* bcc $76cc */

if(!fc)goto L76cc;
goto L76ca;
L76ca: /* add.w D1, D3 */

tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L76cc;
L76cc: /* asr.w #7, D3 */

tv=((u16)(7L));
tw=((u16)d[3]);
tr=((s16)tw)>>7;
VWORD(d[3])=(u16)(tr);
goto L76ce;
L76ce: /* add.b (A1)+, D3 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
tw=((u8)d[3]);
tr=tw+tv;
VBYTE(d[3])=(u8)(tr);
goto L76d0;
L76d0: /* move.b D3, (A2)+ */

tv=((u8)d[3]);
ea=a[2];
vew8(ea,tv);
a[2]+=1;

goto L76d2;
L76d2: /* addq.b #1, D6 */

tv=((u8)(1L));
tw=((u8)d[6]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[6])=(u8)(tr);
goto L76d4;
L76d4: /* dbra D7, $767e */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L767e;
goto L76d8;
L76d8: /* move.b #$a0, (A2) */

tv=((u8)(160L));
ea=a[2];
vew8(ea,tv);

goto L76dc;
L76dc: /* lea $90e2.l, A0 */

a[0]=0x90e2ul;
goto L76e2;
L76e2: /* lea $909f.l, A1 */

a[1]=0x909ful;
goto L76e8;
L76e8: /* move.w #$14, D7 */

tv=((u16)(20L));
VWORD(d[7])=(u16)(tv);

goto L76ec;
L76ec: /* move.b #$60, D1 */

tv=((u8)(96L));
VBYTE(d[1])=(u8)(tv);

goto L76f0;
L76f0: /* move.b (A1)+, D2 */

ea=a[1];
tv=ver8(ea);
a[1]+=1;
VBYTE(d[2])=(u8)(tv);

goto L76f2;
L76f2: /* cmp.b D1, D2 */

tv=((u8)d[1]);
tw=((u8)d[2]);
tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);
goto L76f4;
L76f4: /* bpl $76f8 */

if(!fn)goto L76f8;
goto L76f6;
L76f6: /* move.b D2, D1 */

tv=((u8)d[2]);
VBYTE(d[1])=(u8)(tv);

goto L76f8;
L76f8: /* move.b D1, (A0)+ */

tv=((u8)d[1]);
ea=a[0];
vew8(ea,tv);
a[0]+=1;
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L76fa;
L76fa: /* dbra D7, $76f0 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L76f0;
goto L76fe;
L76fe: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L7700: /* move.b D0, D3 */

tv=((u8)d[0]);
VBYTE(d[3])=(u8)(tv);

goto L7702;
L7702: /* bra $76ce */

goto L76ce;
L7704:
 v=vehicle_smooth_lut[((u16)d[1]&224u)*8u+(u8)d[2]];
 d[0]=(u8)v;VBYTE(d[1])=(u8)(((u8)d[1]<<3)|((u8)d[1]>>5));d[7]=0;
 fn=(u8)((v&0x800ul)!=0);fz=(u8)((v&0x400ul)!=0);fv=(u8)((v&0x200ul)!=0);fc=(u8)((v&0x100ul)!=0);fx=(u8)((v&0x1000ul)!=0);
 pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
L7704_original: /* moveq #$2, D7 */

v=((u32)(2L));
d[7]=v;

goto L7706;
L7706: /* moveq #$0, D0 */

v=((u32)(0L));
d[0]=v;

goto L7708;
L7708: /* rol.b #1, D1 */

v=((u8)(1L));
w=((u8)d[1]);
r=vshift(w,(u8)v,8,5);
VBYTE(d[1])=(u8)(r);
goto L770a;
L770a: /* bcc $7710 */

if(!fc)goto L7710;
goto L770e;
L770e: /* add.b D2, D0 */

tv=((u8)d[2]);
tw=((u8)d[0]);
tr=tw+tv;
VBYTE(d[0])=(u8)(tr);
goto L7710;
L7710: /* asl.b #1, D0 */

tv=((u8)(1L));
tw=((u8)d[0]);
tr=tw<<1;fx=(u8)((tw>>7)&1);
VBYTE(d[0])=(u8)(tr);
goto L7712;
L7712: /* dbra D7, $7708 */

VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L7708;
goto L7716;
L7716: /* roxr.b #1, D0 */

v=((u8)(1L));
w=((u8)d[0]);
r=vshift(w,(u8)v,8,7);
VBYTE(d[0])=(u8)(r);
goto L7718;
L7718: /* asr.b #3, D0 */

tv=((u8)(3L));
tw=((u8)d[0]);
tr=((s8)tw)>>3;fx=(u8)((tw>>2)&1);
VBYTE(d[0])=(u8)(tr);
goto L771a;
L771a: /* moveq #$0, D7 */

v=((u32)(0L));
d[7]=v;
fz=(u8)((v&0xfffffffful)==0);
goto L771c;
L771c: /* addx.b D7, D0 */

v=((u8)d[7]);
w=((u8)d[0]);
r=w+v+fx;fc=(u8)((r&~0xfful)!=0);fx=(u8)((r&~0xfful)!=0);fn=(u8)((r&0x80ul)!=0);fz=(u8)fz&&((r&0xfful)==0);fv=(u8)((~(w^v)&(w^r)&0x80ul)!=0);
VBYTE(d[0])=(u8)(r);
goto L771e;
L771e: /* rts  */

pc=STACK_READ(a[7]);a[7]+=4;goto dispatch;
}
void vehicle_exec(u16 entry){u32 pc,stkp,stkv;if(entry==0x764au){vehicle_native_height();return;}if(entry==0x74c8u){vehicle_edges_native();return;}if(entry==0x6d40u){vehicle_midpoints();return;}if(!vm_busy){a[7]=0x200000ul;a[7]-=4;STACK_WRITE(a[7],0);pc=entry;}else pc=vm_resume;vm_busy=0;
while(pc&&!vm_fault){if(pc>=0x10000ul){if(vehicle_external(pc))return;pc=STACK_READ(a[7]);a[7]+=4;}else if(pc<0x5000ul)pc=part0(pc);else if(pc<0x6300ul)pc=part1(pc);else if(pc<0x7000ul)pc=part2(pc);else pc=part3(pc);}
}
