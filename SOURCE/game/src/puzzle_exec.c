/* Original Batcave rules, statically translated from BATCAVE.IFF. */
#include "puzzle.h"
#define VWORD(x) (*(u16 *)&(x))
#define VBYTE(x) (*(u8 *)&(x))
void puzzle_exec(u16 entry){u32 v,w,r,ea,eb,pc; u16 tv,tw,tr;s32 signed_result;
a[7]=0x200000ul;a[7]-=4;pvw32(a[7],0);pc=entry;
dispatch:if(!pc)return;
PD:if(pc<0xd7b8ul)goto PDL;goto PDR;
PDL:if(pc<0xd4a2ul)goto PDLL;goto PDLR;
PDLL:if(pc<0xd462ul)goto PDLLL;goto PDLLR;
PDLLL:if(pc<0xd32eul)goto PDLLLL;goto PDLLLR;
PDLLLL:if(pc<0x4014ul)goto PDLLLLL;goto PDLLLLR;
PDLLLLL:if(pc==0x4010ul)goto L4010;vm_fault=pc;return;
PDLLLLR:if(pc==0x4014ul)goto L4014;vm_fault=pc;return;
PDLLLR:if(pc<0xd338ul)goto PDLLLRL;goto PDLLLRR;
PDLLLRL:if(pc==0xd32eul)goto Ld32e;vm_fault=pc;return;
PDLLLRR:if(pc<0xd364ul)goto PDLLLRRL;goto PDLLLRRR;
PDLLLRRL:if(pc==0xd338ul)goto Ld338;vm_fault=pc;return;
PDLLLRRR:if(pc==0xd364ul)goto Ld364;vm_fault=pc;return;
PDLLR:if(pc<0xd47cul)goto PDLLRL;goto PDLLRR;
PDLLRL:if(pc<0xd472ul)goto PDLLRLL;goto PDLLRLR;
PDLLRLL:if(pc==0xd462ul)goto Ld462;vm_fault=pc;return;
PDLLRLR:if(pc==0xd472ul)goto Ld472;vm_fault=pc;return;
PDLLRR:if(pc<0xd486ul)goto PDLLRRL;goto PDLLRRR;
PDLLRRL:if(pc==0xd47cul)goto Ld47c;vm_fault=pc;return;
PDLLRRR:if(pc<0xd492ul)goto PDLLRRRL;goto PDLLRRRR;
PDLLRRRL:if(pc==0xd486ul)goto Ld486;vm_fault=pc;return;
PDLLRRRR:if(pc==0xd492ul)goto Ld492;vm_fault=pc;return;
PDLR:if(pc<0xd76eul)goto PDLRL;goto PDLRR;
PDLRL:if(pc<0xd5a8ul)goto PDLRLL;goto PDLRLR;
PDLRLL:if(pc<0xd56aul)goto PDLRLLL;goto PDLRLLR;
PDLRLLL:if(pc==0xd4a2ul)goto Ld4a2;vm_fault=pc;return;
PDLRLLR:if(pc==0xd56aul)goto Ld56a;vm_fault=pc;return;
PDLRLR:if(pc<0xd740ul)goto PDLRLRL;goto PDLRLRR;
PDLRLRL:if(pc==0xd5a8ul)goto Ld5a8;vm_fault=pc;return;
PDLRLRR:if(pc<0xd74cul)goto PDLRLRRL;goto PDLRLRRR;
PDLRLRRL:if(pc==0xd740ul)goto Ld740;vm_fault=pc;return;
PDLRLRRR:if(pc==0xd74cul)goto Ld74c;vm_fault=pc;return;
PDLRR:if(pc<0xd77aul)goto PDLRRL;goto PDLRRR;
PDLRRL:if(pc<0xd776ul)goto PDLRRLL;goto PDLRRLR;
PDLRRLL:if(pc==0xd76eul)goto Ld76e;vm_fault=pc;return;
PDLRRLR:if(pc==0xd776ul)goto Ld776;vm_fault=pc;return;
PDLRRR:if(pc<0xd78aul)goto PDLRRRL;goto PDLRRRR;
PDLRRRL:if(pc==0xd77aul)goto Ld77a;vm_fault=pc;return;
PDLRRRR:if(pc<0xd7a0ul)goto PDLRRRRL;goto PDLRRRRR;
PDLRRRRL:if(pc==0xd78aul)goto Ld78a;vm_fault=pc;return;
PDLRRRRR:if(pc==0xd7a0ul)goto Ld7a0;vm_fault=pc;return;
PDR:if(pc<0xd938ul)goto PDRL;goto PDRR;
PDRL:if(pc<0xd8caul)goto PDRLL;goto PDRLR;
PDRLL:if(pc<0xd87cul)goto PDRLLL;goto PDRLLR;
PDRLLL:if(pc<0xd86eul)goto PDRLLLL;goto PDRLLLR;
PDRLLLL:if(pc==0xd7b8ul)goto Ld7b8;vm_fault=pc;return;
PDRLLLR:if(pc==0xd86eul)goto Ld86e;vm_fault=pc;return;
PDRLLR:if(pc<0xd892ul)goto PDRLLRL;goto PDRLLRR;
PDRLLRL:if(pc==0xd87cul)goto Ld87c;vm_fault=pc;return;
PDRLLRR:if(pc<0xd8acul)goto PDRLLRRL;goto PDRLLRRR;
PDRLLRRL:if(pc==0xd892ul)goto Ld892;vm_fault=pc;return;
PDRLLRRR:if(pc==0xd8acul)goto Ld8ac;vm_fault=pc;return;
PDRLR:if(pc<0xd8e4ul)goto PDRLRL;goto PDRLRR;
PDRLRL:if(pc<0xd8daul)goto PDRLRLL;goto PDRLRLR;
PDRLRLL:if(pc==0xd8caul)goto Ld8ca;vm_fault=pc;return;
PDRLRLR:if(pc==0xd8daul)goto Ld8da;vm_fault=pc;return;
PDRLRR:if(pc<0xd8eeul)goto PDRLRRL;goto PDRLRRR;
PDRLRRL:if(pc==0xd8e4ul)goto Ld8e4;vm_fault=pc;return;
PDRLRRR:if(pc<0xd912ul)goto PDRLRRRL;goto PDRLRRRR;
PDRLRRRL:if(pc==0xd8eeul)goto Ld8ee;vm_fault=pc;return;
PDRLRRRR:if(pc==0xd912ul)goto Ld912;vm_fault=pc;return;
PDRR:if(pc<0xdaaaul)goto PDRRL;goto PDRRR;
PDRRL:if(pc<0xd952ul)goto PDRRLL;goto PDRRLR;
PDRRLL:if(pc<0xd940ul)goto PDRRLLL;goto PDRRLLR;
PDRRLLL:if(pc==0xd938ul)goto Ld938;vm_fault=pc;return;
PDRRLLR:if(pc==0xd940ul)goto Ld940;vm_fault=pc;return;
PDRRLR:if(pc<0xd95aul)goto PDRRLRL;goto PDRRLRR;
PDRRLRL:if(pc==0xd952ul)goto Ld952;vm_fault=pc;return;
PDRRLRR:if(pc<0xd9e6ul)goto PDRRLRRL;goto PDRRLRRR;
PDRRLRRL:if(pc==0xd95aul)goto Ld95a;vm_fault=pc;return;
PDRRLRRR:if(pc==0xd9e6ul)goto Ld9e6;vm_fault=pc;return;
PDRRR:if(pc<0xe382ul)goto PDRRRL;goto PDRRRR;
PDRRRL:if(pc<0xde94ul)goto PDRRRLL;goto PDRRRLR;
PDRRRLL:if(pc==0xdaaaul)goto Ldaaa;vm_fault=pc;return;
PDRRRLR:if(pc==0xde94ul)goto Lde94;vm_fault=pc;return;
PDRRRR:if(pc<0x7c82aul)goto PDRRRRL;goto PDRRRRR;
PDRRRRL:if(pc==0xe382ul)goto Le382;vm_fault=pc;return;
PDRRRRR:if(pc<0x7c870ul)goto PDRRRRRL;goto PDRRRRRR;
PDRRRRRL:if(pc==0x7c82aul)goto L7c82a;vm_fault=pc;return;
PDRRRRRR:if(pc==0x7c870ul)goto L7c870;vm_fault=pc;return;

Ld318:/* lea $d36c.l, A0 */
a[0]=0xd36cul;
goto Ld31e;

Ld31e:/* lea $d37c.l, A1 */
a[1]=0xd37cul;
goto Ld324;

Ld324:/* move.w $d84a.l, D0 */
ea=0xd84aul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld32a;

Ld32a:/* bsr $d33e */
a[7]-=4;pvw32(a[7],0xd32eul);
goto Ld33e;

Ld32e:/* move.w $d848.l, D0 */
ea=0xd848ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld334;

Ld334:/* bsr $d33e */
a[7]-=4;pvw32(a[7],0xd338ul);
goto Ld33e;

Ld338:/* move.w $d846.l, D0 */
ea=0xd846ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld33e;

Ld33e:/* move.w D0, D1 */
tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto Ld340;

Ld340:/* subi.w #$1, D1 */
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto Ld344;

Ld344:/* asl.w #1, D1 */
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw<<1;fx=(u8)((tw>>15)&1);
VWORD(d[1])=(u16)(tr);
goto Ld346;

Ld346:/* move.w (A0,D1.w), $e122.l */
ea=(a[0]+((s16)(d[1])));
tv=pvr16(ea);
ea=0xe122ul;
pvw16(ea,tv);

goto Ld34e;

Ld34e:/* move.w (A1,D1.w), $e126.l */
ea=(a[1]+((s16)(d[1])));
tv=pvr16(ea);
ea=0xe126ul;
pvw16(ea,tv);

goto Ld356;

Ld356:/* move.w D0, $e154.l */
tv=((u16)d[0]);
ea=0xe154ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld35c;

Ld35c:/* movem.l D0-D1/A0-A1, -(A7) */
a[7]-=4;
pvw32(a[7],a[1]);
a[7]-=4;
pvw32(a[7],a[0]);
a[7]-=4;
pvw32(a[7],d[1]);
a[7]-=4;
pvw32(a[7],d[0]);
goto Ld360;

Ld360:/* bsr $de94 */
a[7]-=4;pvw32(a[7],0xd364ul);
goto Lde94;

Ld364:/* movem.l (A7)+, D0-D1/A0-A1 */
ea=a[7];
d[0]=pvr32(ea+0);
d[1]=pvr32(ea+4);
a[0]=pvr32(ea+8);
a[1]=pvr32(ea+12);
a[7]+=16;
goto Ld368;

Ld368:/* lsr.w #1, D1 */
tv=((u16)(1L));
tw=((u16)d[1]);
tr=((u16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;
VWORD(d[1])=(u16)(tr);
goto Ld36a;

Ld36a:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld462:/* clr.l $d840.l */
ea=0xd840ul;
pvw32(ea,0);

goto Ld468;

Ld468:/* clr.w $d844.l */
ea=0xd844ul;
pvw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto Ld46e;

Ld46e:/* bsr $d48e */
a[7]-=4;pvw32(a[7],0xd472ul);
goto Ld48e;

Ld472:/* move.w D0, $d840.l */
tv=((u16)d[0]);
ea=0xd840ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld478;

Ld478:/* bsr $d48e */
a[7]-=4;pvw32(a[7],0xd47cul);
goto Ld48e;

Ld47c:/* move.w D0, $d842.l */
tv=((u16)d[0]);
ea=0xd842ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld482;

Ld482:/* bsr $d48e */
a[7]-=4;pvw32(a[7],0xd486ul);
goto Ld48e;

Ld486:/* move.w D0, $d844.l */
tv=((u16)d[0]);
ea=0xd844ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld48c;

Ld48c:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld48e:/* bsr $d516 */
a[7]-=4;pvw32(a[7],0xd492ul);
goto Ld516;

Ld492:/* move.w $d54a.l, D0 */
ea=0xd54aul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld498;

Ld498:/* andi.w #$7, D0 */
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto Ld49c;

Ld49c:/* moveq #$0, D7 */
v=((u32)(0L));
d[7]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto Ld49e;

Ld49e:/* bsr $d8f4 */
a[7]-=4;pvw32(a[7],0xd4a2ul);
goto Ld8f4;

Ld4a2:/* tst.w D7 */
tv=((u16)d[7]);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld4a4;

Ld4a4:/* bne $d48e */
if(!fz)goto Ld48e;
goto Ld4a6;

Ld4a6:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld516:/* movem.l D0-D1/A0, -(A7) */
a[7]-=4;
pvw32(a[7],a[0]);
a[7]-=4;
pvw32(a[7],d[1]);
a[7]-=4;
pvw32(a[7],d[0]);
goto Ld51a;

Ld51a:/* lea $d54c.l, A0 */
a[0]=0xd54cul;
goto Ld520;

Ld520:/* move.b $bfe801.l, D0 */
ea=0xbfe801ul;
tv=pvr8(ea);
VBYTE(d[0])=(u8)(tv);

goto Ld526;

Ld526:/* move.b $bfe901.l, D1 */
ea=0xbfe901ul;
tv=pvr8(ea);
VBYTE(d[1])=(u8)(tv);

goto Ld52c;

Ld52c:/* eor.w D1, D0 */
tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw^tv;

VWORD(d[0])=(u16)(tr);
goto Ld52e;

Ld52e:/* move.w D0, D1 */
tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto Ld530;

Ld530:/* andi.w #$7, D0 */
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto Ld534;

Ld534:/* asl.w #1, D0 */
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw<<1;fx=(u8)((tw>>15)&1);
VWORD(d[0])=(u16)(tr);
goto Ld536;

Ld536:/* eor.w D1, (A0,D0.w) */
tv=((u16)d[1]);
eb=(a[0]+((s16)(d[0])));
tw=pvr16(eb);
tr=tw^tv;

pvw16(eb,tr);
goto Ld53a;

Ld53a:/* move.w (A0,D0.w), D0 */
ea=(a[0]+((s16)(d[0])));
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld53e;

Ld53e:/* move.w D0, $d54a.l */
tv=((u16)d[0]);
ea=0xd54aul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld544;

Ld544:/* movem.l (A7)+, D0-D1/A0 */
ea=a[7];
d[0]=pvr32(ea+0);
d[1]=pvr32(ea+4);
a[0]=pvr32(ea+8);
a[7]+=12;
goto Ld548;

Ld548:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld56a:/* tst.w $dc02.l */
ea=0xdc02ul;
tv=pvr16(ea);
fz=(u8)((tv&0xfffful)==0);
goto Ld570;

Ld570:/* beq $d588 */
if(fz)goto Ld588;
goto Ld574;

Ld574:/* move.w $dc0a.l, D0 */
ea=0xdc0aul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld57a;

Ld57a:/* add.w D0, $e128.l */
tv=((u16)d[0]);
eb=0xe128ul;
tw=pvr16(eb);
tr=tw+tv;
pvw16(eb,tr);
goto Ld580;

Ld580:/* subi.w #$1, $dc02.l */
tv=((u16)(1L));
eb=0xdc02ul;
tw=pvr16(eb);
tr=tw-tv;fx=(u8)(tv>tw);
pvw16(eb,tr);
goto Ld588;

Ld588:/* tst.w $dc04.l */
ea=0xdc04ul;
tv=pvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld58e;

Ld58e:/* beq $d5a6 */
if(fz)goto Ld5a6;
goto Ld592;

Ld592:/* move.w $dc08.l, D0 */
ea=0xdc08ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld598;

Ld598:/* add.w D0, $e124.l */
tv=((u16)d[0]);
eb=0xe124ul;
tw=pvr16(eb);
tr=tw+tv;
pvw16(eb,tr);
goto Ld59e;

Ld59e:/* subi.w #$1, $dc04.l */
tv=((u16)(1L));
eb=0xdc04ul;
tw=pvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
pvw16(eb,tr);
goto Ld5a6;

Ld5a6:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld5a8:/* clr.l $dc10.l */
ea=0xdc10ul;
pvw32(ea,0);

goto Ld5ae;

Ld5ae:/* clr.w $dc0c.l */
ea=0xdc0cul;
pvw16(ea,0);

goto Ld5b4;

Ld5b4:/* move.w $dff00c.l, D0 */
ea=0xdff00cul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld5ba;

Ld5ba:/* btst #$1, D0 */
v=((u16)(1L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto Ld5be;

Ld5be:/* sne $dc10.l */
ea=0xdc10ul;
pvw8(ea,(!fz?255:0));
goto Ld5c4;

Ld5c4:/* btst #$9, D0 */
v=((u16)(9L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto Ld5c8;

Ld5c8:/* sne $dc11.l */
ea=0xdc11ul;
pvw8(ea,(!fz?255:0));
goto Ld5ce;

Ld5ce:/* btst #$0, D0 */
v=((u16)(0L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto Ld5d2;

Ld5d2:/* sne $dc12.l */
ea=0xdc12ul;
pvw8(ea,(!fz?255:0));
goto Ld5d8;

Ld5d8:/* btst #$8, D0 */
v=((u16)(8L));
w=((u32)d[0]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto Ld5dc;

Ld5dc:/* sne $dc13.l */
ea=0xdc13ul;
pvw8(ea,(!fz?255:0));
goto Ld5e2;

Ld5e2:/* move.b $dc10.l, D1 */
ea=0xdc10ul;
tv=pvr8(ea);
VBYTE(d[1])=(u8)(tv);

goto Ld5e8;

Ld5e8:/* eor.b D1, $dc12.l */
tv=((u8)d[1]);
eb=0xdc12ul;
tw=pvr8(eb);
tr=tw^tv;

pvw8(eb,tr);
goto Ld5ee;

Ld5ee:/* move.b $dc11.l, D1 */
ea=0xdc11ul;
tv=pvr8(ea);
VBYTE(d[1])=(u8)(tv);

goto Ld5f4;

Ld5f4:/* eor.b D1, $dc13.l */
tv=((u8)d[1]);
eb=0xdc13ul;
tw=pvr8(eb);
tr=tw^tv;

pvw8(eb,tr);
goto Ld5fa;

Ld5fa:/* btst #$7, $bfe001.l */
v=((u16)(7L));
eb=0xbfe001ul;
w=pvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto Ld602;

Ld602:/* seq $dc0c.l */
ea=0xdc0cul;
pvw8(ea,(fz?255:0));
goto Ld608;

Ld608:/* tst.w $dc04.l */
ea=0xdc04ul;
tv=pvr16(ea);
fz=(u8)((tv&0xfffful)==0);
goto Ld60e;

Ld60e:/* bne $d636 */
if(!fz)goto Ld636;
goto Ld610;

Ld610:/* clr.w $dc08.l */
ea=0xdc08ul;
pvw16(ea,0);

goto Ld616;

Ld616:/* tst.b $dc10.l */
ea=0xdc10ul;
tv=pvr8(ea);
fz=(u8)((tv&0xfful)==0);
goto Ld61c;

Ld61c:/* beq $d626 */
if(fz)goto Ld626;
goto Ld61e;

Ld61e:/* move.w #$a, $dc08.l */
tv=((u16)(10L));
ea=0xdc08ul;
pvw16(ea,tv);

goto Ld626;

Ld626:/* tst.b $dc11.l */
ea=0xdc11ul;
tv=pvr8(ea);
fz=(u8)((tv&0xfful)==0);
goto Ld62c;

Ld62c:/* beq $d636 */
if(fz)goto Ld636;
goto Ld62e;

Ld62e:/* move.w #$fff6, $dc08.l */
tv=((u16)(65526L));
ea=0xdc08ul;
pvw16(ea,tv);

goto Ld636;

Ld636:/* tst.w $dc02.l */
ea=0xdc02ul;
tv=pvr16(ea);
fz=(u8)((tv&0xfffful)==0);
goto Ld63c;

Ld63c:/* bne $d664 */
if(!fz)goto Ld664;
goto Ld63e;

Ld63e:/* clr.w $dc0a.l */
ea=0xdc0aul;
pvw16(ea,0);

goto Ld644;

Ld644:/* tst.b $dc12.l */
ea=0xdc12ul;
tv=pvr8(ea);
fz=(u8)((tv&0xfful)==0);
goto Ld64a;

Ld64a:/* beq $d654 */
if(fz)goto Ld654;
goto Ld64c;

Ld64c:/* move.w #$4, $dc0a.l */
tv=((u16)(4L));
ea=0xdc0aul;
pvw16(ea,tv);

goto Ld654;

Ld654:/* tst.b $dc13.l */
ea=0xdc13ul;
tv=pvr8(ea);
fz=(u8)((tv&0xfful)==0);
goto Ld65a;

Ld65a:/* beq $d664 */
if(fz)goto Ld664;
goto Ld65c;

Ld65c:/* move.w #$fffc, $dc0a.l */
tv=((u16)(65532L));
ea=0xdc0aul;
pvw16(ea,tv);

goto Ld664;

Ld664:/* tst.w $dc04.l */
ea=0xdc04ul;
tv=pvr16(ea);
fz=(u8)((tv&0xfffful)==0);
goto Ld66a;

Ld66a:/* bne $d6a4 */
if(!fz)goto Ld6a4;
goto Ld66c;

Ld66c:/* tst.w $dc08.l */
ea=0xdc08ul;
tv=pvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto Ld672;

Ld672:/* beq $d6a4 */
if(fz)goto Ld6a4;
goto Ld674;

Ld674:/* bpl $d690 */
if(!fn)goto Ld690;
goto Ld678;

Ld678:/* cmpi.w #$80, $e124.l */
tv=((u16)(128L));
eb=0xe124ul;
tw=pvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ld680;

Ld680:/* blt $d6a4 */
if((fn!=fv))goto Ld6a4;
goto Ld684;

Ld684:/* move.w #$1b, $dc04.l */
tv=((u16)(27L));
ea=0xdc04ul;
pvw16(ea,tv);

goto Ld68c;

Ld68c:/* bra $d6a4 */
goto Ld6a4;

Ld690:/* cmpi.w #$80, $e124.l */
tv=((u16)(128L));
eb=0xe124ul;
tw=pvr16(eb);
fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ld698;

Ld698:/* bgt $d6a4 */
if((!fz&&(fn==fv)))goto Ld6a4;
goto Ld69c;

Ld69c:/* move.w #$1b, $dc04.l */
tv=((u16)(27L));
ea=0xdc04ul;
pvw16(ea,tv);

goto Ld6a4;

Ld6a4:/* tst.w $dc02.l */
ea=0xdc02ul;
tv=pvr16(ea);
fz=(u8)((tv&0xfffful)==0);
goto Ld6aa;

Ld6aa:/* bne $d6ee */
if(!fz)goto Ld6ee;
goto Ld6ac;

Ld6ac:/* tst.w $dc0a.l */
ea=0xdc0aul;
tv=pvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto Ld6b2;

Ld6b2:/* beq $d6ee */
if(fz)goto Ld6ee;
goto Ld6b4;

Ld6b4:/* bpl $d6d0 */
if(!fn)goto Ld6d0;
goto Ld6b8;

Ld6b8:/* cmpi.w #$20, $e128.l */
tv=((u16)(32L));
eb=0xe128ul;
tw=pvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ld6c0;

Ld6c0:/* blt $d6ee */
if((fn!=fv))goto Ld6ee;
goto Ld6c4;

Ld6c4:/* subi.w #$1, $dc06.l */
tv=((u16)(1L));
eb=0xdc06ul;
tw=pvr16(eb);
tr=tw-tv;fx=(u8)(tv>tw);
pvw16(eb,tr);
goto Ld6cc;

Ld6cc:/* bra $d6e4 */
goto Ld6e4;

Ld6d0:/* cmpi.w #$71, $e128.l */
tv=((u16)(113L));
eb=0xe128ul;
tw=pvr16(eb);
fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ld6d8;

Ld6d8:/* bgt $d6ee */
if((!fz&&(fn==fv)))goto Ld6ee;
goto Ld6dc;

Ld6dc:/* addi.w #$1, $dc06.l */
tv=((u16)(1L));
eb=0xdc06ul;
tw=pvr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
pvw16(eb,tr);
goto Ld6e4;

Ld6e4:/* move.w #$9, $dc02.l */
tv=((u16)(9L));
ea=0xdc02ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld6ec;

Ld6ec:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld6ee:/* move.w $dc08.l, D0 */
ea=0xdc08ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld6f4;

Ld6f4:/* or.w $dc0a.l, D0 */
ea=0xdc0aul;
tv=pvr16(ea);
tw=((u16)d[0]);
tr=tw|tv;

VWORD(d[0])=(u16)(tr);
goto Ld6fa;

Ld6fa:/* or.w $dc04.l, D0 */
ea=0xdc04ul;
tv=pvr16(ea);
tw=((u16)d[0]);
tr=tw|tv;

VWORD(d[0])=(u16)(tr);
goto Ld700;

Ld700:/* or.w $dc02.l, D0 */
ea=0xdc02ul;
tv=pvr16(ea);
tw=((u16)d[0]);
tr=tw|tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
VWORD(d[0])=(u16)(tr);
goto Ld706;

Ld706:/* bne $dba4 */
if(!fz)goto Ldba4;
goto Ld70a;

Ld70a:/* tst.w $dc0c.l */
ea=0xdc0cul;
tv=pvr16(ea);
fz=(u8)((tv&0xfffful)==0);
goto Ld710;

Ld710:/* beq $dbea */
if(fz)goto Ldbea;
goto Ld714;

Ld714:/* tst.w $dc0e.l */
ea=0xdc0eul;
tv=pvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld71a;

Ld71a:/* bne $dba4 */
if(!fz)goto Ldba4;
goto Ld71e;

Ld71e:/* lea $d846.l, A2 */
a[2]=0xd846ul;
goto Ld724;

Ld724:/* lea $d7ec.l, A0 */
a[0]=0xd7ecul;
goto Ld72a;

Ld72a:/* lea $d816.l, A1 */
a[1]=0xd816ul;
goto Ld730;

Ld730:/* move.w $dbfc.l, D2 */
ea=0xdbfcul;
tv=pvr16(ea);
VWORD(d[2])=(u16)(tv);

goto Ld736;

Ld736:/* move.w $dbfe.l, D1 */
ea=0xdbfeul;
tv=pvr16(ea);
VWORD(d[1])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld73c;

Ld73c:/* bsr $d84c */
a[7]-=4;pvw32(a[7],0xd740ul);
goto Ld84c;

Ld740:/* moveq #$0, D7 */
v=((u32)(0L));
d[7]=v;

goto Ld742;

Ld742:/* move.w $e154.l, D0 */
ea=0xe154ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld748;

Ld748:/* bsr $d912 */
a[7]-=4;pvw32(a[7],0xd74cul);
goto Ld912;

Ld74c:/* tst.w D7 */
tv=((u16)d[7]);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld74e;

Ld74e:/* bne $d7ea */
if(!fz)goto Ld7ea;
goto Ld752;

Ld752:/* move.w $e154.l, (A2,D1.w) */
ea=0xe154ul;
tv=pvr16(ea);
ea=(a[2]+((s16)(d[1])));
pvw16(ea,tv);

goto Ld75a;

Ld75a:/* move.w (A0,D2.w), $e122.l */
ea=(a[0]+((s16)(d[2])));
tv=pvr16(ea);
ea=0xe122ul;
pvw16(ea,tv);

goto Ld762;

Ld762:/* move.w (A1,D2.w), $e126.l */
ea=(a[1]+((s16)(d[2])));
tv=pvr16(ea);
ea=0xe126ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld76a;

Ld76a:/* bsr $de94 */
a[7]-=4;pvw32(a[7],0xd76eul);
goto Lde94;

Ld76e:/* moveq #$5, D0 */
v=((u32)(5L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto Ld770;

Ld770:/* jsr $4014.l */
a[7]-=4;pvw32(a[7],0xd776ul);
goto L4014;

Ld776:/* bsr $dba6 */
a[7]-=4;pvw32(a[7],0xd77aul);
goto Ldba6;

Ld77a:/* subi.w #$1, $dbfa.l */
tv=((u16)(1L));
eb=0xdbfaul;
tw=pvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
pvw16(eb,tr);
goto Ld782;

Ld782:/* bne $d7d4 */
if(!fz)goto Ld7d4;
goto Ld786;

Ld786:/* bsr $d86a */
a[7]-=4;pvw32(a[7],0xd78aul);
goto Ld86a;

Ld78a:/* cmpi.b #$33, $d8d6.l */
tv=((u8)(51L));
eb=0xd8d6ul;
tw=pvr8(eb);
fz=(u8)((u8)tw==(u8)tv);
goto Ld792;

Ld792:/* bne $d798 */
if(!fz)goto Ld798;
goto Ld794;

Ld794:/* bra $d930 */
goto Ld930;

Ld798:/* moveq #$6, D0 */
v=((u32)(6L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto Ld79a;

Ld79a:/* jsr $4014.l */
a[7]-=4;pvw32(a[7],0xd7a0ul);
goto L4014;

Ld7a0:/* subi.w #$1, $dc00.l */
tv=((u16)(1L));
eb=0xdc00ul;
tw=pvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
pvw16(eb,tr);
goto Ld7a8;

Ld7a8:/* bpl $d7b0 */
if(!fn)goto Ld7b0;
goto Ld7ac;

Ld7ac:/* bra $d9e6 */
goto Ld9e6;

Ld7b0:/* moveq #$6, D0 */
v=((u32)(6L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto Ld7b2;

Ld7b2:/* jsr $7c870.l */
a[7]-=4;pvw32(a[7],0xd7b8ul);
goto L7c870;

Ld7b8:/* move.w #$3, $dbfa.l */
tv=((u16)(3L));
ea=0xdbfaul;
pvw16(ea,tv);

goto Ld7c0;

Ld7c0:/* move.w #$fffe, $dbfe.l */
tv=((u16)(65534L));
ea=0xdbfeul;
pvw16(ea,tv);

goto Ld7c8;

Ld7c8:/* clr.l $d846.l */
ea=0xd846ul;
pvw32(ea,0);

goto Ld7ce;

Ld7ce:/* clr.w $d84a.l */
ea=0xd84aul;
pvw16(ea,0);

goto Ld7d4;

Ld7d4:/* not.w $dc0e.l */
ea=0xdc0eul;
tv=pvr16(ea);
tr=~tv;
pvw16(ea,tr);

goto Ld7da;

Ld7da:/* addi.w #$2, $dbfc.l */
tv=((u16)(2L));
eb=0xdbfcul;
tw=pvr16(eb);
tr=tw+tv;
pvw16(eb,tr);
goto Ld7e2;

Ld7e2:/* addi.w #$2, $dbfe.l */
tv=((u16)(2L));
eb=0xdbfeul;
tw=pvr16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
pvw16(eb,tr);
goto Ld7ea;

Ld7ea:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld84c:/* move.w $dc06.l, $e154.l */
ea=0xdc06ul;
tv=pvr16(ea);
ea=0xe154ul;
pvw16(ea,tv);

goto Ld856;

Ld856:/* cmpi.w #$80, $e124.l */
tv=((u16)(128L));
eb=0xe124ul;
tw=pvr16(eb);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ld85e;

Ld85e:/* blt $d868 */
if((fn!=fv))goto Ld868;
goto Ld860;

Ld860:/* addi.w #$4, $e154.l */
tv=((u16)(4L));
eb=0xe154ul;
tw=pvr16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
pvw16(eb,tr);
goto Ld868;

Ld868:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld86a:/* bsr $d318 */
a[7]-=4;pvw32(a[7],0xd86eul);
goto Ld318;

Ld86e:/* clr.w $dc0e.l */
ea=0xdc0eul;
pvw16(ea,0);

goto Ld874;

Ld874:/* move.b #$30, D7 */
tv=((u8)(48L));
VBYTE(d[7])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto Ld878;

Ld878:/* bsr $d8da */
a[7]-=4;pvw32(a[7],0xd87cul);
goto Ld8da;

Ld87c:/* move.b D7, $d8d6.l */
tv=((u8)d[7]);
ea=0xd8d6ul;
pvw8(ea,tv);

goto Ld882;

Ld882:/* moveq #$0, D0 */
v=((u32)(0L));
d[0]=v;

goto Ld884;

Ld884:/* move.b D7, D0 */
tv=((u8)d[7]);
VBYTE(d[0])=(u8)(tv);

goto Ld886;

Ld886:/* subi.b #$30, D0 */
tv=((u8)(48L));
tw=((u8)d[0]);
tr=tw-tv;
VBYTE(d[0])=(u8)(tr);
goto Ld88a;

Ld88a:/* asl.l #8, D0 */
v=((u32)(8L));
w=((u32)d[0]);
r=w<<8;fc=(u8)((w>>24)&1);fx=(u8)((w>>24)&1);fn=(u8)((r&0x80000000ul)!=0);fz=(u8)((r&0xfffffffful)==0);fv=(u8)((((w<<8)^w)&0x80000000ul)!=0);
d[0]=r;
goto Ld88c;

Ld88c:/* jsr $7c82a.l */
a[7]-=4;pvw32(a[7],0xd892ul);
goto L7c82a;

Ld892:/* not.w $ee04.l */
ea=0xee04ul;
tv=pvr16(ea);
tr=~tv;
pvw16(ea,tr);

goto Ld898;

Ld898:/* move.l #$f68e, $edfc.l */
v=((u32)(63118L));
ea=0xedfcul;
pvw32(ea,v);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto Ld8a2;

Ld8a2:/* lea $d8d4.l, A6 */
a[6]=0xd8d4ul;
goto Ld8a8;

Ld8a8:/* bsr $e382 */
a[7]-=4;pvw32(a[7],0xd8acul);
goto Le382;

Ld8ac:/* move.w #$9, $e154.l */
tv=((u16)(9L));
ea=0xe154ul;
pvw16(ea,tv);

goto Ld8b4;

Ld8b4:/* move.w $d8d8.l, $e122.l */
ea=0xd8d8ul;
tv=pvr16(ea);
ea=0xe122ul;
pvw16(ea,tv);

goto Ld8be;

Ld8be:/* move.w #$6e, $e126.l */
tv=((u16)(110L));
ea=0xe126ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld8c6;

Ld8c6:/* bsr $de94 */
a[7]-=4;pvw32(a[7],0xd8caul);
goto Lde94;

Ld8ca:/* addi.w #$13, $d8d8.l */
tv=((u16)(19L));
eb=0xd8d8ul;
tw=pvr16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
pvw16(eb,tr);
goto Ld8d2;

Ld8d2:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld8da:/* move.w $d846.l, D0 */
ea=0xd846ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld8e0;

Ld8e0:/* bsr $d8f4 */
a[7]-=4;pvw32(a[7],0xd8e4ul);
goto Ld8f4;

Ld8e4:/* move.w $d848.l, D0 */
ea=0xd848ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld8ea;

Ld8ea:/* bsr $d8f4 */
a[7]-=4;pvw32(a[7],0xd8eeul);
goto Ld8f4;

Ld8ee:/* move.w $d84a.l, D0 */
ea=0xd84aul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld8f4;

Ld8f4:/* cmp.w $d840.l, D0 */
ea=0xd840ul;
tv=pvr16(ea);
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto Ld8fa;

Ld8fa:/* beq $d90e */
if(fz)goto Ld90e;
goto Ld8fc;

Ld8fc:/* cmp.w $d842.l, D0 */
ea=0xd842ul;
tv=pvr16(ea);
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto Ld902;

Ld902:/* beq $d90e */
if(fz)goto Ld90e;
goto Ld904;

Ld904:/* cmp.w $d844.l, D0 */
ea=0xd844ul;
tv=pvr16(ea);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ld90a;

Ld90a:/* beq $d90e */
if(fz)goto Ld90e;
goto Ld90c;

Ld90c:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld90e:/* addq.w #1, D7 */
tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[7])=(u16)(tr);
goto Ld910;

Ld910:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld912:/* cmp.w $d846.l, D0 */
ea=0xd846ul;
tv=pvr16(ea);
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto Ld918;

Ld918:/* beq $d92c */
if(fz)goto Ld92c;
goto Ld91a;

Ld91a:/* cmp.w $d848.l, D0 */
ea=0xd848ul;
tv=pvr16(ea);
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto Ld920;

Ld920:/* beq $d92c */
if(fz)goto Ld92c;
goto Ld922;

Ld922:/* cmp.w $d84a.l, D0 */
ea=0xd84aul;
tv=pvr16(ea);
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ld928;

Ld928:/* beq $d92c */
if(fz)goto Ld92c;
goto Ld92a;

Ld92a:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld92c:/* addq.w #1, D7 */
tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[7])=(u16)(tr);
goto Ld92e;

Ld92e:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld930:/* move.w #$d, D3 */
tv=((u16)(13L));
VWORD(d[3])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld934;

Ld934:/* bsr $daaa */
a[7]-=4;pvw32(a[7],0xd938ul);
goto Ldaaa;

Ld938:/* moveq #$2, D0 */
v=((u32)(2L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto Ld93a;

Ld93a:/* jsr $4010.l */
a[7]-=4;pvw32(a[7],0xd940ul);
goto L4010;

Ld940:/* moveq #$0, D0 */
v=((u32)(0L));
d[0]=v;

goto Ld942;

Ld942:/* move.w $7c884.l, D0 */
ea=0x7c884ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ld948;

Ld948:/* asl.l #8, D0 */
v=((u32)(8L));
w=((u32)d[0]);
r=w<<8;
d[0]=r;
goto Ld94a;

Ld94a:/* asl.l #4, D0 */
v=((u32)(4L));
w=((u32)d[0]);
r=w<<4;fc=(u8)((w>>28)&1);fx=(u8)((w>>28)&1);fn=(u8)((r&0x80000000ul)!=0);fz=(u8)((r&0xfffffffful)==0);fv=(u8)((((w<<4)^w)&0x80000000ul)!=0);
d[0]=r;
goto Ld94c;

Ld94c:/* jsr $7c82a.l */
a[7]-=4;pvw32(a[7],0xd952ul);
goto L7c82a;

Ld952:/* move.w #$ffff, $d0c8.l */
tv=((u16)(65535L));
ea=0xd0c8ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ld95a;

Ldba4:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ldba6:/* move.w $dc06.l, D0 */
ea=0xdc06ul;
tv=pvr16(ea);
VWORD(d[0])=(u16)(tv);

goto Ldbac;

Ldbac:/* move.w D0, D1 */
tv=((u16)d[0]);
VWORD(d[1])=(u16)(tv);

goto Ldbae;

Ldbae:/* lea $dbf2.l, A0 */
a[0]=0xdbf2ul;
goto Ldbb4;

Ldbb4:/* add.w D0, D0 */
tv=((u16)d[0]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto Ldbb6;

Ldbb6:/* move.w (-$2,A0,D0.w), $e126.l */
ea=(-2+a[0]+((s16)(d[0])));
tv=pvr16(ea);
ea=0xe126ul;
pvw16(ea,tv);

goto Ldbbe;

Ldbbe:/* move.w $e124.l, $e122.l */
ea=0xe124ul;
tv=pvr16(ea);
ea=0xe122ul;
pvw16(ea,tv);

goto Ldbc8;

Ldbc8:/* addi.w #$1, $e122.l */
tv=((u16)(1L));
eb=0xe122ul;
tw=pvr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
pvw16(eb,tr);
goto Ldbd0;

Ldbd0:/* cmpi.w #$80, $e124.l */
tv=((u16)(128L));
eb=0xe124ul;
tw=pvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto Ldbd8;

Ldbd8:/* blt $dbde */
if((fn!=fv))goto Ldbde;
goto Ldbdc;

Ldbdc:/* addq.w #4, D1 */
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto Ldbde;

Ldbde:/* move.w #$a, $e154.l */
tv=((u16)(10L));
ea=0xe154ul;
pvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto Ldbe6;

Ldbe6:/* bra $de94 */
goto Lde94;

Ldbea:/* clr.w $dc0e.l */
ea=0xdc0eul;
pvw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto Ldbf0;

Ldbf0:/* rts  */
pc=pvr32(a[7]);a[7]+=4;goto dispatch;

L4010:if(puzzle_external(0x4010ul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

L4014:if(puzzle_external(0x4014ul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld95a:if(puzzle_external(0xd95aul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ld9e6:if(puzzle_external(0xd9e6ul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Ldaaa:if(puzzle_external(0xdaaaul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Lde94:if(puzzle_external(0xde94ul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

Le382:if(puzzle_external(0xe382ul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

L7c82a:if(puzzle_external(0x7c82aul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;

L7c870:if(puzzle_external(0x7c870ul))return;pc=pvr32(a[7]);a[7]+=4;goto dispatch;
}
