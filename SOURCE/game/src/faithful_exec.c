/* Generated from the shipped Amiga 68000 code1.iff. See tools/lift.py.
 * Static native translation; original state transitions and integer rules.
 */
#include "faithful.h"
#include "direct_memory.h"
#include "platform_scan.h"
extern const u16 vm_dispatch_table[];
#define VWORD(x) (*(u16 *)&(x))
#define VBYTE(x) (*(u8 *)&(x))
void vm_exec(u16 entry){
 u32 v,w,r,ea,eb; u16 tv,tw,tr,dispatch_pc; s32 signed_result;u32 pc;
#ifdef VM_HOST
 u32 instruction_count=0;
#define VSTEP(p) if(++instruction_count>200000ul){vm_fault=0x1000000ul|(p);return;}
#else
#define VSTEP(p)
#endif
 if(!vm_busy){a[7]=0x200000ul;a[7]-=4;vw32(a[7],0);pc=entry;}else pc=vm_resume;
 vm_busy=0;
dispatch:
 if(pc>65535ul){vm_fault=pc;return;}dispatch_pc=(u16)pc;
 if(!pc)return;
DISP0:
if(dispatch_pc<0x5036u)goto DISP0L;goto DISP0R;
DISP0L:
if(dispatch_pc<0x45ceu)goto DISP0LL;goto DISP0LR;
DISP0LL:
if(dispatch_pc<0x4258u)goto DISP0LLL;goto DISP0LLR;
DISP0LLL:
if(dispatch_pc<0x4044u)goto DISP0LLLL;goto DISP0LLLR;
DISP0LLLL:
if(dispatch_pc<0x3f56u)goto DISP0LLLLL;goto DISP0LLLLR;
DISP0LLLLL:
if(dispatch_pc<0x3e62u)goto DISP0LLLLLL;goto DISP0LLLLLR;
DISP0LLLLLL:
if(dispatch_pc<0x3dfeu)goto DISP0LLLLLLL;goto DISP0LLLLLLR;
DISP0LLLLLLL:
if(dispatch_pc==0x3dd4u)goto L3dd4;vm_fault=pc;return;
DISP0LLLLLLR:
if(dispatch_pc<0x3e2au)goto DISP0LLLLLLRL;goto DISP0LLLLLLRR;
DISP0LLLLLLRL:
if(dispatch_pc==0x3dfeu)goto L3dfe;vm_fault=pc;return;
DISP0LLLLLLRR:
if(dispatch_pc==0x3e2au)goto L3e2a;vm_fault=pc;return;
DISP0LLLLLR:
if(dispatch_pc<0x3ec6u)goto DISP0LLLLLRL;goto DISP0LLLLLRR;
DISP0LLLLLRL:
if(dispatch_pc==0x3e62u)goto L3e62;vm_fault=pc;return;
DISP0LLLLLRR:
if(dispatch_pc<0x3ee6u)goto DISP0LLLLLRRL;goto DISP0LLLLLRRR;
DISP0LLLLLRRL:
if(dispatch_pc==0x3ec6u)goto L3ec6;vm_fault=pc;return;
DISP0LLLLLRRR:
if(dispatch_pc==0x3ee6u)goto L3ee6;vm_fault=pc;return;
DISP0LLLLR:
if(dispatch_pc<0x3fdcu)goto DISP0LLLLRL;goto DISP0LLLLRR;
DISP0LLLLRL:
if(dispatch_pc<0x3f88u)goto DISP0LLLLRLL;goto DISP0LLLLRLR;
DISP0LLLLRLL:
if(dispatch_pc==0x3f56u)goto L3f56;vm_fault=pc;return;
DISP0LLLLRLR:
if(dispatch_pc<0x3fa6u)goto DISP0LLLLRLRL;goto DISP0LLLLRLRR;
DISP0LLLLRLRL:
if(dispatch_pc==0x3f88u)goto L3f88;vm_fault=pc;return;
DISP0LLLLRLRR:
if(dispatch_pc==0x3fa6u)goto L3fa6;vm_fault=pc;return;
DISP0LLLLRR:
if(dispatch_pc<0x400cu)goto DISP0LLLLRRL;goto DISP0LLLLRRR;
DISP0LLLLRRL:
if(dispatch_pc<0x4006u)goto DISP0LLLLRRLL;goto DISP0LLLLRRLR;
DISP0LLLLRRLL:
if(dispatch_pc==0x3fdcu)goto L3fdc;vm_fault=pc;return;
DISP0LLLLRRLR:
if(dispatch_pc==0x4006u)goto L4006;vm_fault=pc;return;
DISP0LLLLRRR:
if(dispatch_pc<0x401cu)goto DISP0LLLLRRRL;goto DISP0LLLLRRRR;
DISP0LLLLRRRL:
if(dispatch_pc==0x400cu)goto L400c;vm_fault=pc;return;
DISP0LLLLRRRR:
if(dispatch_pc==0x401cu)goto L401c;vm_fault=pc;return;
DISP0LLLR:
if(dispatch_pc<0x40f0u)goto DISP0LLLRL;goto DISP0LLLRR;
DISP0LLLRL:
if(dispatch_pc<0x4092u)goto DISP0LLLRLL;goto DISP0LLLRLR;
DISP0LLLRLL:
if(dispatch_pc<0x404cu)goto DISP0LLLRLLL;goto DISP0LLLRLLR;
DISP0LLLRLLL:
if(dispatch_pc==0x4044u)goto L4044;vm_fault=pc;return;
DISP0LLLRLLR:
if(dispatch_pc<0x405eu)goto DISP0LLLRLLRL;goto DISP0LLLRLLRR;
DISP0LLLRLLRL:
if(dispatch_pc==0x404cu)goto L404c;vm_fault=pc;return;
DISP0LLLRLLRR:
if(dispatch_pc==0x405eu)goto L405e;vm_fault=pc;return;
DISP0LLLRLR:
if(dispatch_pc<0x40b8u)goto DISP0LLLRLRL;goto DISP0LLLRLRR;
DISP0LLLRLRL:
if(dispatch_pc==0x4092u)goto L4092;vm_fault=pc;return;
DISP0LLLRLRR:
if(dispatch_pc<0x40c8u)goto DISP0LLLRLRRL;goto DISP0LLLRLRRR;
DISP0LLLRLRRL:
if(dispatch_pc==0x40b8u)goto L40b8;vm_fault=pc;return;
DISP0LLLRLRRR:
if(dispatch_pc==0x40c8u)goto L40c8;vm_fault=pc;return;
DISP0LLLRR:
if(dispatch_pc<0x413cu)goto DISP0LLLRRL;goto DISP0LLLRRR;
DISP0LLLRRL:
if(dispatch_pc<0x40f8u)goto DISP0LLLRRLL;goto DISP0LLLRRLR;
DISP0LLLRRLL:
if(dispatch_pc==0x40f0u)goto L40f0;vm_fault=pc;return;
DISP0LLLRRLR:
if(dispatch_pc<0x410au)goto DISP0LLLRRLRL;goto DISP0LLLRRLRR;
DISP0LLLRRLRL:
if(dispatch_pc==0x40f8u)goto L40f8;vm_fault=pc;return;
DISP0LLLRRLRR:
if(dispatch_pc==0x410au)goto L410a;vm_fault=pc;return;
DISP0LLLRRR:
if(dispatch_pc<0x41bau)goto DISP0LLLRRRL;goto DISP0LLLRRRR;
DISP0LLLRRRL:
if(dispatch_pc<0x41a2u)goto DISP0LLLRRRLL;goto DISP0LLLRRRLR;
DISP0LLLRRRLL:
if(dispatch_pc==0x413cu)goto L413c;vm_fault=pc;return;
DISP0LLLRRRLR:
if(dispatch_pc==0x41a2u)goto L41a2;vm_fault=pc;return;
DISP0LLLRRRR:
if(dispatch_pc<0x41d2u)goto DISP0LLLRRRRL;goto DISP0LLLRRRRR;
DISP0LLLRRRRL:
if(dispatch_pc==0x41bau)goto L41ba;vm_fault=pc;return;
DISP0LLLRRRRR:
if(dispatch_pc==0x41d2u)goto L41d2;vm_fault=pc;return;
DISP0LLR:
if(dispatch_pc<0x4430u)goto DISP0LLRL;goto DISP0LLRR;
DISP0LLRL:
if(dispatch_pc<0x4340u)goto DISP0LLRLL;goto DISP0LLRLR;
DISP0LLRLL:
if(dispatch_pc<0x4284u)goto DISP0LLRLLL;goto DISP0LLRLLR;
DISP0LLRLLL:
if(dispatch_pc<0x4266u)goto DISP0LLRLLLL;goto DISP0LLRLLLR;
DISP0LLRLLLL:
if(dispatch_pc==0x4258u)goto L4258;vm_fault=pc;return;
DISP0LLRLLLR:
if(dispatch_pc<0x426cu)goto DISP0LLRLLLRL;goto DISP0LLRLLLRR;
DISP0LLRLLLRL:
if(dispatch_pc==0x4266u)goto L4266;vm_fault=pc;return;
DISP0LLRLLLRR:
if(dispatch_pc==0x426cu)goto L426c;vm_fault=pc;return;
DISP0LLRLLR:
if(dispatch_pc<0x42a8u)goto DISP0LLRLLRL;goto DISP0LLRLLRR;
DISP0LLRLLRL:
if(dispatch_pc==0x4284u)goto L4284;vm_fault=pc;return;
DISP0LLRLLRR:
if(dispatch_pc<0x4332u)goto DISP0LLRLLRRL;goto DISP0LLRLLRRR;
DISP0LLRLLRRL:
if(dispatch_pc==0x42a8u)goto L42a8;vm_fault=pc;return;
DISP0LLRLLRRR:
if(dispatch_pc==0x4332u)goto L4332;vm_fault=pc;return;
DISP0LLRLR:
if(dispatch_pc<0x43a0u)goto DISP0LLRLRL;goto DISP0LLRLRR;
DISP0LLRLRL:
if(dispatch_pc<0x4380u)goto DISP0LLRLRLL;goto DISP0LLRLRLR;
DISP0LLRLRLL:
if(dispatch_pc==0x4340u)goto L4340;vm_fault=pc;return;
DISP0LLRLRLR:
if(dispatch_pc<0x439eu)goto DISP0LLRLRLRL;goto DISP0LLRLRLRR;
DISP0LLRLRLRL:
if(dispatch_pc==0x4380u)goto L4380;vm_fault=pc;return;
DISP0LLRLRLRR:
if(dispatch_pc==0x439eu)goto L439e;vm_fault=pc;return;
DISP0LLRLRR:
if(dispatch_pc<0x43ceu)goto DISP0LLRLRRL;goto DISP0LLRLRRR;
DISP0LLRLRRL:
if(dispatch_pc<0x43c2u)goto DISP0LLRLRRLL;goto DISP0LLRLRRLR;
DISP0LLRLRRLL:
if(dispatch_pc==0x43a0u)goto L43a0;vm_fault=pc;return;
DISP0LLRLRRLR:
if(dispatch_pc==0x43c2u)goto L43c2;vm_fault=pc;return;
DISP0LLRLRRR:
if(dispatch_pc<0x43eeu)goto DISP0LLRLRRRL;goto DISP0LLRLRRRR;
DISP0LLRLRRRL:
if(dispatch_pc==0x43ceu)goto L43ce;vm_fault=pc;return;
DISP0LLRLRRRR:
if(dispatch_pc==0x43eeu)goto L43ee;vm_fault=pc;return;
DISP0LLRR:
if(dispatch_pc<0x447eu)goto DISP0LLRRL;goto DISP0LLRRR;
DISP0LLRRL:
if(dispatch_pc<0x4448u)goto DISP0LLRRLL;goto DISP0LLRRLR;
DISP0LLRRLL:
if(dispatch_pc<0x4434u)goto DISP0LLRRLLL;goto DISP0LLRRLLR;
DISP0LLRRLLL:
if(dispatch_pc==0x4430u)goto L4430;vm_fault=pc;return;
DISP0LLRRLLR:
if(dispatch_pc<0x4444u)goto DISP0LLRRLLRL;goto DISP0LLRRLLRR;
DISP0LLRRLLRL:
if(dispatch_pc==0x4434u)goto L4434;vm_fault=pc;return;
DISP0LLRRLLRR:
if(dispatch_pc==0x4444u)goto L4444;vm_fault=pc;return;
DISP0LLRRLR:
if(dispatch_pc<0x4456u)goto DISP0LLRRLRL;goto DISP0LLRRLRR;
DISP0LLRRLRL:
if(dispatch_pc==0x4448u)goto L4448;vm_fault=pc;return;
DISP0LLRRLRR:
if(dispatch_pc<0x446eu)goto DISP0LLRRLRRL;goto DISP0LLRRLRRR;
DISP0LLRRLRRL:
if(dispatch_pc==0x4456u)goto L4456;vm_fault=pc;return;
DISP0LLRRLRRR:
if(dispatch_pc==0x446eu)goto L446e;vm_fault=pc;return;
DISP0LLRRR:
if(dispatch_pc<0x4580u)goto DISP0LLRRRL;goto DISP0LLRRRR;
DISP0LLRRRL:
if(dispatch_pc<0x4482u)goto DISP0LLRRRLL;goto DISP0LLRRRLR;
DISP0LLRRRLL:
if(dispatch_pc==0x447eu)goto L447e;vm_fault=pc;return;
DISP0LLRRRLR:
if(dispatch_pc<0x44ceu)goto DISP0LLRRRLRL;goto DISP0LLRRRLRR;
DISP0LLRRRLRL:
if(dispatch_pc==0x4482u)goto L4482;vm_fault=pc;return;
DISP0LLRRRLRR:
if(dispatch_pc==0x44ceu)goto L44ce;vm_fault=pc;return;
DISP0LLRRRR:
if(dispatch_pc<0x45b6u)goto DISP0LLRRRRL;goto DISP0LLRRRRR;
DISP0LLRRRRL:
if(dispatch_pc<0x4584u)goto DISP0LLRRRRLL;goto DISP0LLRRRRLR;
DISP0LLRRRRLL:
if(dispatch_pc==0x4580u)goto L4580;vm_fault=pc;return;
DISP0LLRRRRLR:
if(dispatch_pc==0x4584u)goto L4584;vm_fault=pc;return;
DISP0LLRRRRR:
if(dispatch_pc<0x45c8u)goto DISP0LLRRRRRL;goto DISP0LLRRRRRR;
DISP0LLRRRRRL:
if(dispatch_pc==0x45b6u)goto L45b6;vm_fault=pc;return;
DISP0LLRRRRRR:
if(dispatch_pc==0x45c8u)goto L45c8;vm_fault=pc;return;
DISP0LR:
if(dispatch_pc<0x4936u)goto DISP0LRL;goto DISP0LRR;
DISP0LRL:
if(dispatch_pc<0x4718u)goto DISP0LRLL;goto DISP0LRLR;
DISP0LRLL:
if(dispatch_pc<0x46b2u)goto DISP0LRLLL;goto DISP0LRLLR;
DISP0LRLLL:
if(dispatch_pc<0x4658u)goto DISP0LRLLLL;goto DISP0LRLLLR;
DISP0LRLLLL:
if(dispatch_pc<0x45feu)goto DISP0LRLLLLL;goto DISP0LRLLLLR;
DISP0LRLLLLL:
if(dispatch_pc==0x45ceu)goto L45ce;vm_fault=pc;return;
DISP0LRLLLLR:
if(dispatch_pc<0x4632u)goto DISP0LRLLLLRL;goto DISP0LRLLLLRR;
DISP0LRLLLLRL:
if(dispatch_pc==0x45feu)goto L45fe;vm_fault=pc;return;
DISP0LRLLLLRR:
if(dispatch_pc==0x4632u)goto L4632;vm_fault=pc;return;
DISP0LRLLLR:
if(dispatch_pc<0x467eu)goto DISP0LRLLLRL;goto DISP0LRLLLRR;
DISP0LRLLLRL:
if(dispatch_pc==0x4658u)goto L4658;vm_fault=pc;return;
DISP0LRLLLRR:
if(dispatch_pc<0x468eu)goto DISP0LRLLLRRL;goto DISP0LRLLLRRR;
DISP0LRLLLRRL:
if(dispatch_pc==0x467eu)goto L467e;vm_fault=pc;return;
DISP0LRLLLRRR:
if(dispatch_pc==0x468eu)goto L468e;vm_fault=pc;return;
DISP0LRLLR:
if(dispatch_pc<0x46d4u)goto DISP0LRLLRL;goto DISP0LRLLRR;
DISP0LRLLRL:
if(dispatch_pc<0x46bau)goto DISP0LRLLRLL;goto DISP0LRLLRLR;
DISP0LRLLRLL:
if(dispatch_pc==0x46b2u)goto L46b2;vm_fault=pc;return;
DISP0LRLLRLR:
if(dispatch_pc<0x46c2u)goto DISP0LRLLRLRL;goto DISP0LRLLRLRR;
DISP0LRLLRLRL:
if(dispatch_pc==0x46bau)goto L46ba;vm_fault=pc;return;
DISP0LRLLRLRR:
if(dispatch_pc==0x46c2u)goto L46c2;vm_fault=pc;return;
DISP0LRLLRR:
if(dispatch_pc<0x46f8u)goto DISP0LRLLRRL;goto DISP0LRLLRRR;
DISP0LRLLRRL:
if(dispatch_pc<0x46e6u)goto DISP0LRLLRRLL;goto DISP0LRLLRRLR;
DISP0LRLLRRLL:
if(dispatch_pc==0x46d4u)goto L46d4;vm_fault=pc;return;
DISP0LRLLRRLR:
if(dispatch_pc==0x46e6u)goto L46e6;vm_fault=pc;return;
DISP0LRLLRRR:
if(dispatch_pc<0x470cu)goto DISP0LRLLRRRL;goto DISP0LRLLRRRR;
DISP0LRLLRRRL:
if(dispatch_pc==0x46f8u)goto L46f8;vm_fault=pc;return;
DISP0LRLLRRRR:
if(dispatch_pc==0x470cu)goto L470c;vm_fault=pc;return;
DISP0LRLR:
if(dispatch_pc<0x4758u)goto DISP0LRLRL;goto DISP0LRLRR;
DISP0LRLRL:
if(dispatch_pc<0x4734u)goto DISP0LRLRLL;goto DISP0LRLRLR;
DISP0LRLRLL:
if(dispatch_pc<0x4722u)goto DISP0LRLRLLL;goto DISP0LRLRLLR;
DISP0LRLRLLL:
if(dispatch_pc==0x4718u)goto L4718;vm_fault=pc;return;
DISP0LRLRLLR:
if(dispatch_pc<0x4728u)goto DISP0LRLRLLRL;goto DISP0LRLRLLRR;
DISP0LRLRLLRL:
if(dispatch_pc==0x4722u)goto L4722;vm_fault=pc;return;
DISP0LRLRLLRR:
if(dispatch_pc==0x4728u)goto L4728;vm_fault=pc;return;
DISP0LRLRLR:
if(dispatch_pc<0x4740u)goto DISP0LRLRLRL;goto DISP0LRLRLRR;
DISP0LRLRLRL:
if(dispatch_pc==0x4734u)goto L4734;vm_fault=pc;return;
DISP0LRLRLRR:
if(dispatch_pc<0x474cu)goto DISP0LRLRLRRL;goto DISP0LRLRLRRR;
DISP0LRLRLRRL:
if(dispatch_pc==0x4740u)goto L4740;vm_fault=pc;return;
DISP0LRLRLRRR:
if(dispatch_pc==0x474cu)goto L474c;vm_fault=pc;return;
DISP0LRLRR:
if(dispatch_pc<0x47ecu)goto DISP0LRLRRL;goto DISP0LRLRRR;
DISP0LRLRRL:
if(dispatch_pc<0x47bcu)goto DISP0LRLRRLL;goto DISP0LRLRRLR;
DISP0LRLRRLL:
if(dispatch_pc==0x4758u)goto L4758;vm_fault=pc;return;
DISP0LRLRRLR:
if(dispatch_pc<0x47c4u)goto DISP0LRLRRLRL;goto DISP0LRLRRLRR;
DISP0LRLRRLRL:
if(dispatch_pc==0x47bcu)goto L47bc;vm_fault=pc;return;
DISP0LRLRRLRR:
if(dispatch_pc==0x47c4u)goto L47c4;vm_fault=pc;return;
DISP0LRLRRR:
if(dispatch_pc<0x4822u)goto DISP0LRLRRRL;goto DISP0LRLRRRR;
DISP0LRLRRRL:
if(dispatch_pc<0x4810u)goto DISP0LRLRRRLL;goto DISP0LRLRRRLR;
DISP0LRLRRRLL:
if(dispatch_pc==0x47ecu)goto L47ec;vm_fault=pc;return;
DISP0LRLRRRLR:
if(dispatch_pc==0x4810u)goto L4810;vm_fault=pc;return;
DISP0LRLRRRR:
if(dispatch_pc<0x4844u)goto DISP0LRLRRRRL;goto DISP0LRLRRRRR;
DISP0LRLRRRRL:
if(dispatch_pc==0x4822u)goto L4822;vm_fault=pc;return;
DISP0LRLRRRRR:
if(dispatch_pc==0x4844u)goto L4844;vm_fault=pc;return;
DISP0LRR:
if(dispatch_pc<0x4d88u)goto DISP0LRRL;goto DISP0LRRR;
DISP0LRRL:
if(dispatch_pc<0x4ce4u)goto DISP0LRRLL;goto DISP0LRRLR;
DISP0LRRLL:
if(dispatch_pc<0x4a5cu)goto DISP0LRRLLL;goto DISP0LRRLLR;
DISP0LRRLLL:
if(dispatch_pc<0x49d0u)goto DISP0LRRLLLL;goto DISP0LRRLLLR;
DISP0LRRLLLL:
if(dispatch_pc==0x4936u)goto L4936;vm_fault=pc;return;
DISP0LRRLLLR:
if(dispatch_pc<0x49ecu)goto DISP0LRRLLLRL;goto DISP0LRRLLLRR;
DISP0LRRLLLRL:
if(dispatch_pc==0x49d0u)goto L49d0;vm_fault=pc;return;
DISP0LRRLLLRR:
if(dispatch_pc==0x49ecu)goto L49ec;vm_fault=pc;return;
DISP0LRRLLR:
if(dispatch_pc<0x4c3eu)goto DISP0LRRLLRL;goto DISP0LRRLLRR;
DISP0LRRLLRL:
if(dispatch_pc==0x4a5cu)goto L4a5c;vm_fault=pc;return;
DISP0LRRLLRR:
if(dispatch_pc<0x4ce0u)goto DISP0LRRLLRRL;goto DISP0LRRLLRRR;
DISP0LRRLLRRL:
if(dispatch_pc==0x4c3eu)goto L4c3e;vm_fault=pc;return;
DISP0LRRLLRRR:
if(dispatch_pc==0x4ce0u)goto L4ce0;vm_fault=pc;return;
DISP0LRRLR:
if(dispatch_pc<0x4d56u)goto DISP0LRRLRL;goto DISP0LRRLRR;
DISP0LRRLRL:
if(dispatch_pc<0x4d18u)goto DISP0LRRLRLL;goto DISP0LRRLRLR;
DISP0LRRLRLL:
if(dispatch_pc==0x4ce4u)goto L4ce4;vm_fault=pc;return;
DISP0LRRLRLR:
if(dispatch_pc<0x4d48u)goto DISP0LRRLRLRL;goto DISP0LRRLRLRR;
DISP0LRRLRLRL:
if(dispatch_pc==0x4d18u)goto L4d18;vm_fault=pc;return;
DISP0LRRLRLRR:
if(dispatch_pc==0x4d48u)goto L4d48;vm_fault=pc;return;
DISP0LRRLRR:
if(dispatch_pc<0x4d76u)goto DISP0LRRLRRL;goto DISP0LRRLRRR;
DISP0LRRLRRL:
if(dispatch_pc<0x4d60u)goto DISP0LRRLRRLL;goto DISP0LRRLRRLR;
DISP0LRRLRRLL:
if(dispatch_pc==0x4d56u)goto L4d56;vm_fault=pc;return;
DISP0LRRLRRLR:
if(dispatch_pc==0x4d60u)goto L4d60;vm_fault=pc;return;
DISP0LRRLRRR:
if(dispatch_pc<0x4d7au)goto DISP0LRRLRRRL;goto DISP0LRRLRRRR;
DISP0LRRLRRRL:
if(dispatch_pc==0x4d76u)goto L4d76;vm_fault=pc;return;
DISP0LRRLRRRR:
if(dispatch_pc==0x4d7au)goto L4d7a;vm_fault=pc;return;
DISP0LRRR:
if(dispatch_pc<0x4f26u)goto DISP0LRRRL;goto DISP0LRRRR;
DISP0LRRRL:
if(dispatch_pc<0x4daau)goto DISP0LRRRLL;goto DISP0LRRRLR;
DISP0LRRRLL:
if(dispatch_pc<0x4d94u)goto DISP0LRRRLLL;goto DISP0LRRRLLR;
DISP0LRRRLLL:
if(dispatch_pc==0x4d88u)goto L4d88;vm_fault=pc;return;
DISP0LRRRLLR:
if(dispatch_pc<0x4da2u)goto DISP0LRRRLLRL;goto DISP0LRRRLLRR;
DISP0LRRRLLRL:
if(dispatch_pc==0x4d94u)goto L4d94;vm_fault=pc;return;
DISP0LRRRLLRR:
if(dispatch_pc==0x4da2u)goto L4da2;vm_fault=pc;return;
DISP0LRRRLR:
if(dispatch_pc<0x4e3au)goto DISP0LRRRLRL;goto DISP0LRRRLRR;
DISP0LRRRLRL:
if(dispatch_pc==0x4daau)goto L4daa;vm_fault=pc;return;
DISP0LRRRLRR:
if(dispatch_pc<0x4e64u)goto DISP0LRRRLRRL;goto DISP0LRRRLRRR;
DISP0LRRRLRRL:
if(dispatch_pc==0x4e3au)goto L4e3a;vm_fault=pc;return;
DISP0LRRRLRRR:
if(dispatch_pc==0x4e64u)goto L4e64;vm_fault=pc;return;
DISP0LRRRR:
if(dispatch_pc<0x4fe0u)goto DISP0LRRRRL;goto DISP0LRRRRR;
DISP0LRRRRL:
if(dispatch_pc<0x4f4eu)goto DISP0LRRRRLL;goto DISP0LRRRRLR;
DISP0LRRRRLL:
if(dispatch_pc==0x4f26u)goto L4f26;vm_fault=pc;return;
DISP0LRRRRLR:
if(dispatch_pc<0x4fa4u)goto DISP0LRRRRLRL;goto DISP0LRRRRLRR;
DISP0LRRRRLRL:
if(dispatch_pc==0x4f4eu)goto L4f4e;vm_fault=pc;return;
DISP0LRRRRLRR:
if(dispatch_pc==0x4fa4u)goto L4fa4;vm_fault=pc;return;
DISP0LRRRRR:
if(dispatch_pc<0x4ffeu)goto DISP0LRRRRRL;goto DISP0LRRRRRR;
DISP0LRRRRRL:
if(dispatch_pc<0x4ff6u)goto DISP0LRRRRRLL;goto DISP0LRRRRRLR;
DISP0LRRRRRLL:
if(dispatch_pc==0x4fe0u)goto L4fe0;vm_fault=pc;return;
DISP0LRRRRRLR:
if(dispatch_pc==0x4ff6u)goto L4ff6;vm_fault=pc;return;
DISP0LRRRRRR:
if(dispatch_pc<0x5016u)goto DISP0LRRRRRRL;goto DISP0LRRRRRRR;
DISP0LRRRRRRL:
if(dispatch_pc==0x4ffeu)goto L4ffe;vm_fault=pc;return;
DISP0LRRRRRRR:
if(dispatch_pc==0x5016u)goto L5016;vm_fault=pc;return;
DISP0R:
if(dispatch_pc<0x56e0u)goto DISP0RL;goto DISP0RR;
DISP0RL:
if(dispatch_pc<0x5292u)goto DISP0RLL;goto DISP0RLR;
DISP0RLL:
if(dispatch_pc<0x5182u)goto DISP0RLLL;goto DISP0RLLR;
DISP0RLLL:
if(dispatch_pc<0x50eeu)goto DISP0RLLLL;goto DISP0RLLLR;
DISP0RLLLL:
if(dispatch_pc<0x5088u)goto DISP0RLLLLL;goto DISP0RLLLLR;
DISP0RLLLLL:
if(dispatch_pc<0x5058u)goto DISP0RLLLLLL;goto DISP0RLLLLLR;
DISP0RLLLLLL:
if(dispatch_pc==0x5036u)goto L5036;vm_fault=pc;return;
DISP0RLLLLLR:
if(dispatch_pc<0x5076u)goto DISP0RLLLLLRL;goto DISP0RLLLLLRR;
DISP0RLLLLLRL:
if(dispatch_pc==0x5058u)goto L5058;vm_fault=pc;return;
DISP0RLLLLLRR:
if(dispatch_pc==0x5076u)goto L5076;vm_fault=pc;return;
DISP0RLLLLR:
if(dispatch_pc<0x509au)goto DISP0RLLLLRL;goto DISP0RLLLLRR;
DISP0RLLLLRL:
if(dispatch_pc==0x5088u)goto L5088;vm_fault=pc;return;
DISP0RLLLLRR:
if(dispatch_pc<0x50e6u)goto DISP0RLLLLRRL;goto DISP0RLLLLRRR;
DISP0RLLLLRRL:
if(dispatch_pc==0x509au)goto L509a;vm_fault=pc;return;
DISP0RLLLLRRR:
if(dispatch_pc==0x50e6u)goto L50e6;vm_fault=pc;return;
DISP0RLLLR:
if(dispatch_pc<0x511eu)goto DISP0RLLLRL;goto DISP0RLLLRR;
DISP0RLLLRL:
if(dispatch_pc<0x50f8u)goto DISP0RLLLRLL;goto DISP0RLLLRLR;
DISP0RLLLRLL:
if(dispatch_pc==0x50eeu)goto L50ee;vm_fault=pc;return;
DISP0RLLLRLR:
if(dispatch_pc<0x510cu)goto DISP0RLLLRLRL;goto DISP0RLLLRLRR;
DISP0RLLLRLRL:
if(dispatch_pc==0x50f8u)goto L50f8;vm_fault=pc;return;
DISP0RLLLRLRR:
if(dispatch_pc==0x510cu)goto L510c;vm_fault=pc;return;
DISP0RLLLRR:
if(dispatch_pc<0x5132u)goto DISP0RLLLRRL;goto DISP0RLLLRRR;
DISP0RLLLRRL:
if(dispatch_pc<0x5126u)goto DISP0RLLLRRLL;goto DISP0RLLLRRLR;
DISP0RLLLRRLL:
if(dispatch_pc==0x511eu)goto L511e;vm_fault=pc;return;
DISP0RLLLRRLR:
if(dispatch_pc==0x5126u)goto L5126;vm_fault=pc;return;
DISP0RLLLRRR:
if(dispatch_pc<0x515eu)goto DISP0RLLLRRRL;goto DISP0RLLLRRRR;
DISP0RLLLRRRL:
if(dispatch_pc==0x5132u)goto L5132;vm_fault=pc;return;
DISP0RLLLRRRR:
if(dispatch_pc==0x515eu)goto L515e;vm_fault=pc;return;
DISP0RLLR:
if(dispatch_pc<0x5240u)goto DISP0RLLRL;goto DISP0RLLRR;
DISP0RLLRL:
if(dispatch_pc<0x5202u)goto DISP0RLLRLL;goto DISP0RLLRLR;
DISP0RLLRLL:
if(dispatch_pc<0x51b0u)goto DISP0RLLRLLL;goto DISP0RLLRLLR;
DISP0RLLRLLL:
if(dispatch_pc==0x5182u)goto L5182;vm_fault=pc;return;
DISP0RLLRLLR:
if(dispatch_pc<0x51fau)goto DISP0RLLRLLRL;goto DISP0RLLRLLRR;
DISP0RLLRLLRL:
if(dispatch_pc==0x51b0u)goto L51b0;vm_fault=pc;return;
DISP0RLLRLLRR:
if(dispatch_pc==0x51fau)goto L51fa;vm_fault=pc;return;
DISP0RLLRLR:
if(dispatch_pc<0x5204u)goto DISP0RLLRLRL;goto DISP0RLLRLRR;
DISP0RLLRLRL:
if(dispatch_pc==0x5202u)goto L5202;vm_fault=pc;return;
DISP0RLLRLRR:
if(dispatch_pc<0x5224u)goto DISP0RLLRLRRL;goto DISP0RLLRLRRR;
DISP0RLLRLRRL:
if(dispatch_pc==0x5204u)goto L5204;vm_fault=pc;return;
DISP0RLLRLRRR:
if(dispatch_pc==0x5224u)goto L5224;vm_fault=pc;return;
DISP0RLLRR:
if(dispatch_pc<0x5246u)goto DISP0RLLRRL;goto DISP0RLLRRR;
DISP0RLLRRL:
if(dispatch_pc<0x5242u)goto DISP0RLLRRLL;goto DISP0RLLRRLR;
DISP0RLLRRLL:
if(dispatch_pc==0x5240u)goto L5240;vm_fault=pc;return;
DISP0RLLRRLR:
if(dispatch_pc<0x5244u)goto DISP0RLLRRLRL;goto DISP0RLLRRLRR;
DISP0RLLRRLRL:
if(dispatch_pc==0x5242u)goto L5242;vm_fault=pc;return;
DISP0RLLRRLRR:
if(dispatch_pc==0x5244u)goto L5244;vm_fault=pc;return;
DISP0RLLRRR:
if(dispatch_pc<0x5260u)goto DISP0RLLRRRL;goto DISP0RLLRRRR;
DISP0RLLRRRL:
if(dispatch_pc<0x524eu)goto DISP0RLLRRRLL;goto DISP0RLLRRRLR;
DISP0RLLRRRLL:
if(dispatch_pc==0x5246u)goto L5246;vm_fault=pc;return;
DISP0RLLRRRLR:
if(dispatch_pc==0x524eu)goto L524e;vm_fault=pc;return;
DISP0RLLRRRR:
if(dispatch_pc<0x5290u)goto DISP0RLLRRRRL;goto DISP0RLLRRRRR;
DISP0RLLRRRRL:
if(dispatch_pc==0x5260u)goto L5260;vm_fault=pc;return;
DISP0RLLRRRRR:
if(dispatch_pc==0x5290u)goto L5290;vm_fault=pc;return;
DISP0RLR:
if(dispatch_pc<0x5406u)goto DISP0RLRL;goto DISP0RLRR;
DISP0RLRL:
if(dispatch_pc<0x5308u)goto DISP0RLRLL;goto DISP0RLRLR;
DISP0RLRLL:
if(dispatch_pc<0x529cu)goto DISP0RLRLLL;goto DISP0RLRLLR;
DISP0RLRLLL:
if(dispatch_pc<0x5296u)goto DISP0RLRLLLL;goto DISP0RLRLLLR;
DISP0RLRLLLL:
if(dispatch_pc==0x5292u)goto L5292;vm_fault=pc;return;
DISP0RLRLLLR:
if(dispatch_pc<0x5298u)goto DISP0RLRLLLRL;goto DISP0RLRLLLRR;
DISP0RLRLLLRL:
if(dispatch_pc==0x5296u)goto L5296;vm_fault=pc;return;
DISP0RLRLLLRR:
if(dispatch_pc==0x5298u)goto L5298;vm_fault=pc;return;
DISP0RLRLLR:
if(dispatch_pc<0x52a4u)goto DISP0RLRLLRL;goto DISP0RLRLLRR;
DISP0RLRLLRL:
if(dispatch_pc==0x529cu)goto L529c;vm_fault=pc;return;
DISP0RLRLLRR:
if(dispatch_pc<0x52b6u)goto DISP0RLRLLRRL;goto DISP0RLRLLRRR;
DISP0RLRLLRRL:
if(dispatch_pc==0x52a4u)goto L52a4;vm_fault=pc;return;
DISP0RLRLLRRR:
if(dispatch_pc==0x52b6u)goto L52b6;vm_fault=pc;return;
DISP0RLRLR:
if(dispatch_pc<0x53deu)goto DISP0RLRLRL;goto DISP0RLRLRR;
DISP0RLRLRL:
if(dispatch_pc<0x5352u)goto DISP0RLRLRLL;goto DISP0RLRLRLR;
DISP0RLRLRLL:
if(dispatch_pc==0x5308u)goto L5308;vm_fault=pc;return;
DISP0RLRLRLR:
if(dispatch_pc<0x53d6u)goto DISP0RLRLRLRL;goto DISP0RLRLRLRR;
DISP0RLRLRLRL:
if(dispatch_pc==0x5352u)goto L5352;vm_fault=pc;return;
DISP0RLRLRLRR:
if(dispatch_pc==0x53d6u)goto L53d6;vm_fault=pc;return;
DISP0RLRLRR:
if(dispatch_pc<0x53f8u)goto DISP0RLRLRRL;goto DISP0RLRLRRR;
DISP0RLRLRRL:
if(dispatch_pc<0x53f4u)goto DISP0RLRLRRLL;goto DISP0RLRLRRLR;
DISP0RLRLRRLL:
if(dispatch_pc==0x53deu)goto L53de;vm_fault=pc;return;
DISP0RLRLRRLR:
if(dispatch_pc==0x53f4u)goto L53f4;vm_fault=pc;return;
DISP0RLRLRRR:
if(dispatch_pc<0x53feu)goto DISP0RLRLRRRL;goto DISP0RLRLRRRR;
DISP0RLRLRRRL:
if(dispatch_pc==0x53f8u)goto L53f8;vm_fault=pc;return;
DISP0RLRLRRRR:
if(dispatch_pc==0x53feu)goto L53fe;vm_fault=pc;return;
DISP0RLRR:
if(dispatch_pc<0x549au)goto DISP0RLRRL;goto DISP0RLRRR;
DISP0RLRRL:
if(dispatch_pc<0x542au)goto DISP0RLRRLL;goto DISP0RLRRLR;
DISP0RLRRLL:
if(dispatch_pc<0x540cu)goto DISP0RLRRLLL;goto DISP0RLRRLLR;
DISP0RLRRLLL:
if(dispatch_pc==0x5406u)goto L5406;vm_fault=pc;return;
DISP0RLRRLLR:
if(dispatch_pc<0x5414u)goto DISP0RLRRLLRL;goto DISP0RLRRLLRR;
DISP0RLRRLLRL:
if(dispatch_pc==0x540cu)goto L540c;vm_fault=pc;return;
DISP0RLRRLLRR:
if(dispatch_pc==0x5414u)goto L5414;vm_fault=pc;return;
DISP0RLRRLR:
if(dispatch_pc<0x5472u)goto DISP0RLRRLRL;goto DISP0RLRRLRR;
DISP0RLRRLRL:
if(dispatch_pc==0x542au)goto L542a;vm_fault=pc;return;
DISP0RLRRLRR:
if(dispatch_pc<0x5482u)goto DISP0RLRRLRRL;goto DISP0RLRRLRRR;
DISP0RLRRLRRL:
if(dispatch_pc==0x5472u)goto L5472;vm_fault=pc;return;
DISP0RLRRLRRR:
if(dispatch_pc==0x5482u)goto L5482;vm_fault=pc;return;
DISP0RLRRR:
if(dispatch_pc<0x555au)goto DISP0RLRRRL;goto DISP0RLRRRR;
DISP0RLRRRL:
if(dispatch_pc<0x54ecu)goto DISP0RLRRRLL;goto DISP0RLRRRLR;
DISP0RLRRRLL:
if(dispatch_pc==0x549au)goto L549a;vm_fault=pc;return;
DISP0RLRRRLR:
if(dispatch_pc<0x5530u)goto DISP0RLRRRLRL;goto DISP0RLRRRLRR;
DISP0RLRRRLRL:
if(dispatch_pc==0x54ecu)goto L54ec;vm_fault=pc;return;
DISP0RLRRRLRR:
if(dispatch_pc==0x5530u)goto L5530;vm_fault=pc;return;
DISP0RLRRRR:
if(dispatch_pc<0x56a6u)goto DISP0RLRRRRL;goto DISP0RLRRRRR;
DISP0RLRRRRL:
if(dispatch_pc<0x5586u)goto DISP0RLRRRRLL;goto DISP0RLRRRRLR;
DISP0RLRRRRLL:
if(dispatch_pc==0x555au)goto L555a;vm_fault=pc;return;
DISP0RLRRRRLR:
if(dispatch_pc==0x5586u)goto L5586;vm_fault=pc;return;
DISP0RLRRRRR:
if(dispatch_pc<0x56ceu)goto DISP0RLRRRRRL;goto DISP0RLRRRRRR;
DISP0RLRRRRRL:
if(dispatch_pc==0x56a6u)goto L56a6;vm_fault=pc;return;
DISP0RLRRRRRR:
if(dispatch_pc==0x56ceu)goto L56ce;vm_fault=pc;return;
DISP0RR:
if(dispatch_pc<0x5d50u)goto DISP0RRL;goto DISP0RRR;
DISP0RRL:
if(dispatch_pc<0x5bfcu)goto DISP0RRLL;goto DISP0RRLR;
DISP0RRLL:
if(dispatch_pc<0x5b06u)goto DISP0RRLLL;goto DISP0RRLLR;
DISP0RRLLL:
if(dispatch_pc<0x5ae4u)goto DISP0RRLLLL;goto DISP0RRLLLR;
DISP0RRLLLL:
if(dispatch_pc<0x56f2u)goto DISP0RRLLLLL;goto DISP0RRLLLLR;
DISP0RRLLLLL:
if(dispatch_pc==0x56e0u)goto L56e0;vm_fault=pc;return;
DISP0RRLLLLR:
if(dispatch_pc<0x58d4u)goto DISP0RRLLLLRL;goto DISP0RRLLLLRR;
DISP0RRLLLLRL:
if(dispatch_pc==0x56f2u)goto L56f2;vm_fault=pc;return;
DISP0RRLLLLRR:
if(dispatch_pc==0x58d4u)goto L58d4;vm_fault=pc;return;
DISP0RRLLLR:
if(dispatch_pc<0x5aeeu)goto DISP0RRLLLRL;goto DISP0RRLLLRR;
DISP0RRLLLRL:
if(dispatch_pc==0x5ae4u)goto L5ae4;vm_fault=pc;return;
DISP0RRLLLRR:
if(dispatch_pc<0x5af8u)goto DISP0RRLLLRRL;goto DISP0RRLLLRRR;
DISP0RRLLLRRL:
if(dispatch_pc==0x5aeeu)goto L5aee;vm_fault=pc;return;
DISP0RRLLLRRR:
if(dispatch_pc==0x5af8u)goto L5af8;vm_fault=pc;return;
DISP0RRLLR:
if(dispatch_pc<0x5b5cu)goto DISP0RRLLRL;goto DISP0RRLLRR;
DISP0RRLLRL:
if(dispatch_pc<0x5b20u)goto DISP0RRLLRLL;goto DISP0RRLLRLR;
DISP0RRLLRLL:
if(dispatch_pc==0x5b06u)goto L5b06;vm_fault=pc;return;
DISP0RRLLRLR:
if(dispatch_pc<0x5b26u)goto DISP0RRLLRLRL;goto DISP0RRLLRLRR;
DISP0RRLLRLRL:
if(dispatch_pc==0x5b20u)goto L5b20;vm_fault=pc;return;
DISP0RRLLRLRR:
if(dispatch_pc==0x5b26u)goto L5b26;vm_fault=pc;return;
DISP0RRLLRR:
if(dispatch_pc<0x5beau)goto DISP0RRLLRRL;goto DISP0RRLLRRR;
DISP0RRLLRRL:
if(dispatch_pc<0x5b96u)goto DISP0RRLLRRLL;goto DISP0RRLLRRLR;
DISP0RRLLRRLL:
if(dispatch_pc==0x5b5cu)goto L5b5c;vm_fault=pc;return;
DISP0RRLLRRLR:
if(dispatch_pc==0x5b96u)goto L5b96;vm_fault=pc;return;
DISP0RRLLRRR:
if(dispatch_pc<0x5becu)goto DISP0RRLLRRRL;goto DISP0RRLLRRRR;
DISP0RRLLRRRL:
if(dispatch_pc==0x5beau)goto L5bea;vm_fault=pc;return;
DISP0RRLLRRRR:
if(dispatch_pc==0x5becu)goto L5bec;vm_fault=pc;return;
DISP0RRLR:
if(dispatch_pc<0x5caau)goto DISP0RRLRL;goto DISP0RRLRR;
DISP0RRLRL:
if(dispatch_pc<0x5c18u)goto DISP0RRLRLL;goto DISP0RRLRLR;
DISP0RRLRLL:
if(dispatch_pc<0x5c02u)goto DISP0RRLRLLL;goto DISP0RRLRLLR;
DISP0RRLRLLL:
if(dispatch_pc==0x5bfcu)goto L5bfc;vm_fault=pc;return;
DISP0RRLRLLR:
if(dispatch_pc<0x5c04u)goto DISP0RRLRLLRL;goto DISP0RRLRLLRR;
DISP0RRLRLLRL:
if(dispatch_pc==0x5c02u)goto L5c02;vm_fault=pc;return;
DISP0RRLRLLRR:
if(dispatch_pc==0x5c04u)goto L5c04;vm_fault=pc;return;
DISP0RRLRLR:
if(dispatch_pc<0x5c30u)goto DISP0RRLRLRL;goto DISP0RRLRLRR;
DISP0RRLRLRL:
if(dispatch_pc==0x5c18u)goto L5c18;vm_fault=pc;return;
DISP0RRLRLRR:
if(dispatch_pc<0x5c6eu)goto DISP0RRLRLRRL;goto DISP0RRLRLRRR;
DISP0RRLRLRRL:
if(dispatch_pc==0x5c30u)goto L5c30;vm_fault=pc;return;
DISP0RRLRLRRR:
if(dispatch_pc==0x5c6eu)goto L5c6e;vm_fault=pc;return;
DISP0RRLRR:
if(dispatch_pc<0x5d04u)goto DISP0RRLRRL;goto DISP0RRLRRR;
DISP0RRLRRL:
if(dispatch_pc<0x5cd2u)goto DISP0RRLRRLL;goto DISP0RRLRRLR;
DISP0RRLRRLL:
if(dispatch_pc==0x5caau)goto L5caa;vm_fault=pc;return;
DISP0RRLRRLR:
if(dispatch_pc<0x5d00u)goto DISP0RRLRRLRL;goto DISP0RRLRRLRR;
DISP0RRLRRLRL:
if(dispatch_pc==0x5cd2u)goto L5cd2;vm_fault=pc;return;
DISP0RRLRRLRR:
if(dispatch_pc==0x5d00u)goto L5d00;vm_fault=pc;return;
DISP0RRLRRR:
if(dispatch_pc<0x5d2cu)goto DISP0RRLRRRL;goto DISP0RRLRRRR;
DISP0RRLRRRL:
if(dispatch_pc<0x5d20u)goto DISP0RRLRRRLL;goto DISP0RRLRRRLR;
DISP0RRLRRRLL:
if(dispatch_pc==0x5d04u)goto L5d04;vm_fault=pc;return;
DISP0RRLRRRLR:
if(dispatch_pc==0x5d20u)goto L5d20;vm_fault=pc;return;
DISP0RRLRRRR:
if(dispatch_pc<0x5d3cu)goto DISP0RRLRRRRL;goto DISP0RRLRRRRR;
DISP0RRLRRRRL:
if(dispatch_pc==0x5d2cu)goto L5d2c;vm_fault=pc;return;
DISP0RRLRRRRR:
if(dispatch_pc==0x5d3cu)goto L5d3c;vm_fault=pc;return;
DISP0RRR:
if(dispatch_pc<0x5efeu)goto DISP0RRRL;goto DISP0RRRR;
DISP0RRRL:
if(dispatch_pc<0x5e32u)goto DISP0RRRLL;goto DISP0RRRLR;
DISP0RRRLL:
if(dispatch_pc<0x5e14u)goto DISP0RRRLLL;goto DISP0RRRLLR;
DISP0RRRLLL:
if(dispatch_pc<0x5d64u)goto DISP0RRRLLLL;goto DISP0RRRLLLR;
DISP0RRRLLLL:
if(dispatch_pc==0x5d50u)goto L5d50;vm_fault=pc;return;
DISP0RRRLLLR:
if(dispatch_pc<0x5db0u)goto DISP0RRRLLLRL;goto DISP0RRRLLLRR;
DISP0RRRLLLRL:
if(dispatch_pc==0x5d64u)goto L5d64;vm_fault=pc;return;
DISP0RRRLLLRR:
if(dispatch_pc==0x5db0u)goto L5db0;vm_fault=pc;return;
DISP0RRRLLR:
if(dispatch_pc<0x5e1au)goto DISP0RRRLLRL;goto DISP0RRRLLRR;
DISP0RRRLLRL:
if(dispatch_pc==0x5e14u)goto L5e14;vm_fault=pc;return;
DISP0RRRLLRR:
if(dispatch_pc<0x5e2eu)goto DISP0RRRLLRRL;goto DISP0RRRLLRRR;
DISP0RRRLLRRL:
if(dispatch_pc==0x5e1au)goto L5e1a;vm_fault=pc;return;
DISP0RRRLLRRR:
if(dispatch_pc==0x5e2eu)goto L5e2e;vm_fault=pc;return;
DISP0RRRLR:
if(dispatch_pc<0x5eccu)goto DISP0RRRLRL;goto DISP0RRRLRR;
DISP0RRRLRL:
if(dispatch_pc<0x5eb8u)goto DISP0RRRLRLL;goto DISP0RRRLRLR;
DISP0RRRLRLL:
if(dispatch_pc==0x5e32u)goto L5e32;vm_fault=pc;return;
DISP0RRRLRLR:
if(dispatch_pc<0x5ebau)goto DISP0RRRLRLRL;goto DISP0RRRLRLRR;
DISP0RRRLRLRL:
if(dispatch_pc==0x5eb8u)goto L5eb8;vm_fault=pc;return;
DISP0RRRLRLRR:
if(dispatch_pc==0x5ebau)goto L5eba;vm_fault=pc;return;
DISP0RRRLRR:
if(dispatch_pc<0x5ee8u)goto DISP0RRRLRRL;goto DISP0RRRLRRR;
DISP0RRRLRRL:
if(dispatch_pc<0x5ee0u)goto DISP0RRRLRRLL;goto DISP0RRRLRRLR;
DISP0RRRLRRLL:
if(dispatch_pc==0x5eccu)goto L5ecc;vm_fault=pc;return;
DISP0RRRLRRLR:
if(dispatch_pc==0x5ee0u)goto L5ee0;vm_fault=pc;return;
DISP0RRRLRRR:
if(dispatch_pc<0x5ef0u)goto DISP0RRRLRRRL;goto DISP0RRRLRRRR;
DISP0RRRLRRRL:
if(dispatch_pc==0x5ee8u)goto L5ee8;vm_fault=pc;return;
DISP0RRRLRRRR:
if(dispatch_pc==0x5ef0u)goto L5ef0;vm_fault=pc;return;
DISP0RRRR:
if(dispatch_pc<0x5f60u)goto DISP0RRRRL;goto DISP0RRRRR;
DISP0RRRRL:
if(dispatch_pc<0x5f48u)goto DISP0RRRRLL;goto DISP0RRRRLR;
DISP0RRRRLL:
if(dispatch_pc<0x5f36u)goto DISP0RRRRLLL;goto DISP0RRRRLLR;
DISP0RRRRLLL:
if(dispatch_pc==0x5efeu)goto L5efe;vm_fault=pc;return;
DISP0RRRRLLR:
if(dispatch_pc<0x5f42u)goto DISP0RRRRLLRL;goto DISP0RRRRLLRR;
DISP0RRRRLLRL:
if(dispatch_pc==0x5f36u)goto L5f36;vm_fault=pc;return;
DISP0RRRRLLRR:
if(dispatch_pc==0x5f42u)goto L5f42;vm_fault=pc;return;
DISP0RRRRLR:
if(dispatch_pc<0x5f50u)goto DISP0RRRRLRL;goto DISP0RRRRLRR;
DISP0RRRRLRL:
if(dispatch_pc==0x5f48u)goto L5f48;vm_fault=pc;return;
DISP0RRRRLRR:
if(dispatch_pc<0x5f58u)goto DISP0RRRRLRRL;goto DISP0RRRRLRRR;
DISP0RRRRLRRL:
if(dispatch_pc==0x5f50u)goto L5f50;vm_fault=pc;return;
DISP0RRRRLRRR:
if(dispatch_pc==0x5f58u)goto L5f58;vm_fault=pc;return;
DISP0RRRRR:
if(dispatch_pc<0x6012u)goto DISP0RRRRRL;goto DISP0RRRRRR;
DISP0RRRRRL:
if(dispatch_pc<0x5fccu)goto DISP0RRRRRLL;goto DISP0RRRRRLR;
DISP0RRRRRLL:
if(dispatch_pc==0x5f60u)goto L5f60;vm_fault=pc;return;
DISP0RRRRRLR:
if(dispatch_pc<0x5fdeu)goto DISP0RRRRRLRL;goto DISP0RRRRRLRR;
DISP0RRRRRLRL:
if(dispatch_pc==0x5fccu)goto L5fcc;vm_fault=pc;return;
DISP0RRRRRLRR:
if(dispatch_pc==0x5fdeu)goto L5fde;vm_fault=pc;return;
DISP0RRRRRR:
if(dispatch_pc<0x6034u)goto DISP0RRRRRRL;goto DISP0RRRRRRR;
DISP0RRRRRRL:
if(dispatch_pc<0x6020u)goto DISP0RRRRRRLL;goto DISP0RRRRRRLR;
DISP0RRRRRRLL:
if(dispatch_pc==0x6012u)goto L6012;vm_fault=pc;return;
DISP0RRRRRRLR:
if(dispatch_pc==0x6020u)goto L6020;vm_fault=pc;return;
DISP0RRRRRRR:
if(dispatch_pc<0x606au)goto DISP0RRRRRRRL;goto DISP0RRRRRRRR;
DISP0RRRRRRRL:
if(dispatch_pc==0x6034u)goto L6034;vm_fault=pc;return;
DISP0RRRRRRRR:
if(dispatch_pc==0x606au)goto L606a;vm_fault=pc;return;

L3dd4: /* clr.l D0 */
VSTEP(0x3dd4ul);
d[0]=0;

goto L3dd6;
L3dd6: /* move.w $67bc.w, D1 */
VSTEP(0x3dd6ul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
VWORD(d[1])=(u16)(tv);

goto L3dda;
L3dda: /* sub.w $67c0.w, D1 */
VSTEP(0x3ddaul);
ea=0x67c0ul;
tv=(((u16)vm_vars[1250]<<8)|((u16)vm_vars[1251]<<0));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L3dde;
L3dde: /* bls $3dfc */
VSTEP(0x3ddeul);
if((fc||fz))goto L3dfc;
goto L3de0;
L3de0: /* move.w $67bc.w, $67c0.w */
VSTEP(0x3de0ul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
vm_vars[1250]=(u8)((u32)(tv)>>8);
vm_vars[1251]=(u8)((u32)(tv)>>0);

goto L3de6;
L3de6: /* lsl.w #4, D1 */
VSTEP(0x3de6ul);
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw<<4;
VWORD(d[1])=(u16)(tr);
goto L3de8;
L3de8: /* move.b D1, D0 */
VSTEP(0x3de8ul);
tv=((u8)d[1]);
VBYTE(d[0])=(u8)(tv);

goto L3dea;
L3dea: /* bra $3df0 */
VSTEP(0x3deaul);
goto L3df0;
L3dec: /* addi.w #$100, D0 */
VSTEP(0x3decul);
tv=((u16)(256L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L3df0;
L3df0: /* subi.w #$64, D1 */
VSTEP(0x3df0ul);
tv=((u16)(100L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L3df4;
L3df4: /* bcc $3dec */
VSTEP(0x3df4ul);
if(!fc)goto L3dec;
goto L3df6;
L3df6: /* jmp $7c82a.l */
VSTEP(0x3df6ul);
goto L7c82a;
L3dfc: /* rts  */
VSTEP(0x3dfcul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3dfe: /* movem.w $67bc.w, D0-D1 */
VSTEP(0x3dfeul);
ea=0x67bcul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1246u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1248u));
goto L3e04;
L3e04: /* lea $642e.w, A0 */
VSTEP(0x3e04ul);
a[0]=0x642eul;
goto L3e08;
L3e08: /* movem.w (A0)+, D2-D3 */
VSTEP(0x3e08ul);
if(platform_spawn_scan(0x62deu,0x642eu,0x6722u))goto L3e42;
ea=a[0];
d[2]=(s16)vr16(ea+0);
d[3]=(s16)vr16(ea+2);
a[0]+=4;
goto L3e0c;
L3e0c: /* sub.w D0, D2 */
VSTEP(0x3e0cul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L3e0e;
L3e0e: /* cmpi.w #$98, D2 */
VSTEP(0x3e0eul);
tv=((u16)(152L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L3e12;
L3e12: /* bcc $3e30 */
VSTEP(0x3e12ul);
if(!fc)goto L3e30;
goto L3e14;
L3e14: /* sub.w D1, D3 */
VSTEP(0x3e14ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L3e16;
L3e16: /* cmpi.w #$50, D3 */
VSTEP(0x3e16ul);
tv=((u16)(80L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L3e1a;
L3e1a: /* bcc $3e30 */
VSTEP(0x3e1aul);
if(!fc)goto L3e30;
goto L3e1c;
L3e1c: /* bset #$7, (-$4,A0) */
VSTEP(0x3e1cul);
v=((u16)(7L));
eb=(-4+a[0]);
w=vr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
vw8(eb,r);
goto L3e22;
L3e22: /* move.w (A0)+, D7 */
VSTEP(0x3e22ul);
ea=a[0];
tv=vr16(ea);
a[0]+=2;
VWORD(d[7])=(u16)(tv);

goto L3e24;
L3e24: /* subq.w #1, D7 */
VSTEP(0x3e24ul);
tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[7])=(u16)(tr);
goto L3e26;
L3e26: /* bsr $3e74 */
VSTEP(0x3e26ul);
a[7]-=4;vw32(a[7],0x3e2aul);
goto L3e74;
L3e2a: /* dbra D7, $3e26 */
VSTEP(0x3e2aul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L3e26;
goto L3e2e;
L3e2e: /* bra $3e3c */
VSTEP(0x3e2eul);
goto L3e3c;
L3e30: /* move.w (A0), D2 */
VSTEP(0x3e30ul);
ea=a[0];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L3e32;
L3e32: /* add.w D2, D2 */
VSTEP(0x3e32ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L3e34;
L3e34: /* add.w (A0), D2 */
VSTEP(0x3e34ul);
ea=a[0];
tv=vr16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L3e36;
L3e36: /* add.w D2, D2 */
VSTEP(0x3e36ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L3e38;
L3e38: /* lea ($2,A0,D2.w), A0 */
VSTEP(0x3e38ul);
a[0]=(2+a[0]+((s16)(d[2])));
goto L3e3c;
L3e3c: /* cmpa.w #$6722, A0 */
VSTEP(0x3e3cul);
v=((u16)(26402L));
w=((u32)a[0]);
v=(s32)(s16)v;
r=w-v;
fc=(u8)((u32)w<(u32)v);
goto L3e40;
L3e40: /* bcs $3e08 */
VSTEP(0x3e40ul);
if(fc)goto L3e08;
goto L3e42;
L3e42: /* subi.w #$10, D0 */
VSTEP(0x3e42ul);
tv=((u16)(16L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3e46;
L3e46: /* subq.w #8, D1 */
VSTEP(0x3e46ul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L3e48;
L3e48: /* movem.w ($2,A0), D2-D3 */
VSTEP(0x3e48ul);
if(platform_hazard_scan(0x62deu,0x6722u,0x67a0u))goto L3e72;
ea=(2+a[0]);
d[2]=(s16)vr16(ea+0);
d[3]=(s16)vr16(ea+2);
goto L3e4e;
L3e4e: /* sub.w D0, D2 */
VSTEP(0x3e4eul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[2])=(u16)(tr);
goto L3e50;
L3e50: /* cmpi.w #$c0, D2 */
VSTEP(0x3e50ul);
tv=((u16)(192L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L3e54;
L3e54: /* bcc $3e6a */
VSTEP(0x3e54ul);
if(!fc)goto L3e6a;
goto L3e56;
L3e56: /* sub.w D1, D3 */
VSTEP(0x3e56ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L3e58;
L3e58: /* cmpi.w #$60, D3 */
VSTEP(0x3e58ul);
tv=((u16)(96L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3e5c;
L3e5c: /* bcc $3e6a */
VSTEP(0x3e5cul);
if(!fc)goto L3e6a;
goto L3e5e;
L3e5e: /* bsr $3e74 */
VSTEP(0x3e5eul);
a[7]-=4;vw32(a[7],0x3e62ul);
goto L3e74;
L3e62: /* bset #$7, (-$2,A0) */
VSTEP(0x3e62ul);
v=((u16)(7L));
eb=(-2+a[0]);
w=vr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
vw8(eb,r);
goto L3e68;
L3e68: /* bra $3e6c */
VSTEP(0x3e68ul);
goto L3e6c;
L3e6a: /* addq.w #6, A0 */
VSTEP(0x3e6aul);
v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L3e6c;
L3e6c: /* cmpa.w #$67a0, A0 */
VSTEP(0x3e6cul);
v=((u16)(26528L));
w=((u32)a[0]);
v=(s32)(s16)v;
r=w-v;
fc=(u8)((u32)w<(u32)v);fz=(u8)((u32)w==(u32)v);r=w-v;fn=(u8)((r&0x80000000ul)!=0);fv=(u8)(((w^v)&(w^r)&0x80000000ul)!=0);
goto L3e70;
L3e70: /* bcs $3e48 */
VSTEP(0x3e70ul);
if(fc)goto L3e48;
goto L3e72;
L3e72: /* rts  */
VSTEP(0x3e72ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3e74: /* movem.w (A0)+, D2-D4 */
VSTEP(0x3e74ul);
ea=a[0];
d[2]=(s16)vr16(ea+0);
d[3]=(s16)vr16(ea+2);
d[4]=(s16)vr16(ea+4);
a[0]+=6;
goto L3e78;
L3e78: /* cmp.w $22.l, D0 */
VSTEP(0x3e78ul);
ea=0x22ul;
tv=42330u;
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto L3e7e;
L3e7e: /* beq $3e7e */
VSTEP(0x3e7eul);
if(fz)goto L3e7e;
goto L3e80;
L3e80: /* nop  */
VSTEP(0x3e80ul);
goto L3e82;
L3e82: /* lea $39c8.w, A6 */
VSTEP(0x3e82ul);
a[6]=0x39c8ul;
goto L3e86;
L3e86: /* moveq #$9, D6 */
VSTEP(0x3e86ul);
v=((u32)(9L));
d[6]=v;

goto L3e88;
L3e88: /* tst.w (A6) */
VSTEP(0x3e88ul);
ea=a[6];
tv=vr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3e8a;
L3e8a: /* beq $3e96 */
VSTEP(0x3e8aul);
if(fz)goto L3e96;
goto L3e8c;
L3e8c: /* lea ($16,A6), A6 */
VSTEP(0x3e8cul);
a[6]=(22+a[6]);
goto L3e90;
L3e90: /* dbra D6, $3e88 */
VSTEP(0x3e90ul);
VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L3e88;
goto L3e94;
L3e94: /* rts  */
VSTEP(0x3e94ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3e96: /* move.w A0, ($14,A6) */
VSTEP(0x3e96ul);
tv=((u16)a[0]);
ea=(20+a[6]);
vw16(ea,tv);

goto L3e9a;
L3e9a: /* bset #$f, D2 */
VSTEP(0x3e9aul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
d[2]=r;
goto L3e9e;
L3e9e: /* movem.w D2-D4, (A6) */
VSTEP(0x3e9eul);
ea=a[6];
vw16(ea+0,d[2]);
vw16(ea+2,d[3]);
vw16(ea+4,d[4]);
goto L3ea2;
L3ea2: /* clr.l ($8,A6) */
VSTEP(0x3ea2ul);
ea=(8+a[6]);
vw32(ea,0);

goto L3ea6;
L3ea6: /* bclr #$f, D2 */
VSTEP(0x3ea6ul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L3eaa;
L3eaa: /* clr.l ($10,A6) */
VSTEP(0x3eaaul);
ea=(16+a[6]);
vw32(ea,0);

goto L3eae;
L3eae: /* lea $5a7a.w, A5 */
VSTEP(0x3eaeul);
a[5]=0x5a7aul;
goto L3eb2;
L3eb2: /* cmp.w (A5)+, D2 */
VSTEP(0x3eb2ul);
ea=a[5];
tv=vr16(ea);
a[5]+=2;
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L3eb4;
L3eb4: /* bcs $3eba */
VSTEP(0x3eb4ul);
if(fc)goto L3eba;
goto L3eb6;
L3eb6: /* addq.w #2, A5 */
VSTEP(0x3eb6ul);
v=((u16)(2L));
w=((u32)a[5]);
r=w+v;
a[5]=r;
goto L3eb8;
L3eb8: /* bra $3eb2 */
VSTEP(0x3eb8ul);
goto L3eb2;
L3eba: /* move.w (A5), D3 */
VSTEP(0x3ebaul);
ea=a[5];
tv=vr16(ea);
VWORD(d[3])=(u16)(tv);

goto L3ebc;
L3ebc: /* cmpi.w #$46, D3 */
VSTEP(0x3ebcul);
tv=((u16)(70L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3ec0;
L3ec0: /* bne $3ed0 */
VSTEP(0x3ec0ul);
if(!fz)goto L3ed0;
goto L3ec2;
L3ec2: /* bsr $3ed6 */
VSTEP(0x3ec2ul);
a[7]-=4;vw32(a[7],0x3ec6ul);
goto L3ed6;
L3ec6: /* btst #$c, D2 */
VSTEP(0x3ec6ul);
v=((u16)(12L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L3eca;
L3eca: /* beq $3ed0 */
VSTEP(0x3ecaul);
if(fz)goto L3ed0;
goto L3ecc;
L3ecc: /* move.w #$9e, D3 */
VSTEP(0x3eccul);
tv=((u16)(158L));
VWORD(d[3])=(u16)(tv);

goto L3ed0;
L3ed0: /* move.w D3, ($6,A6) */
VSTEP(0x3ed0ul);
tv=((u16)d[3]);
ea=(6+a[6]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3ed4;
L3ed4: /* rts  */
VSTEP(0x3ed4ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3ed6: /* movea.l $6322.l, A1 */
VSTEP(0x3ed6ul);
ea=0x6322ul;
v=(((u32)vm_vars[68]<<24)|((u32)vm_vars[69]<<16)|((u32)vm_vars[70]<<8)|((u32)vm_vars[71]<<0));
a[1]=v;
goto L3edc;
L3edc: /* move.w (A1)+, D2 */
VSTEP(0x3edcul);
ea=a[1];
tv=vr16(ea);
a[1]+=2;
VWORD(d[2])=(u16)(tv);

goto L3ede;
L3ede: /* move.l A1, $6322.l */
VSTEP(0x3edeul);
v=((u32)a[1]);
vm_vars[68]=(u8)((u32)(v)>>24);
vm_vars[69]=(u8)((u32)(v)>>16);
vm_vars[70]=(u8)((u32)(v)>>8);
vm_vars[71]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3ee4;
L3ee4: /* rts  */
VSTEP(0x3ee4ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3ee6: /* lea $39c8.w, A6 */
VSTEP(0x3ee6ul);
a[6]=0x39c8ul;
goto L3eea;
L3eea: /* moveq #$9, D7 */
VSTEP(0x3eeaul);
v=((u32)(9L));
d[7]=v;

goto L3eec;
L3eec: /* move.w (A6), D6 */
VSTEP(0x3eecul);
ea=a[6];
tv=(ea>=0x39c8ul&&ea<0x3aa4ul)?dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul))):vr16(ea);
VWORD(d[6])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3eee;
L3eee: /* beq $3fa8 */
VSTEP(0x3eeeul);
if(fz)goto L3fa8;
goto L3ef2;
L3ef2: /* movem.w ($2,A6), D0-D1 */
VSTEP(0x3ef2ul);
ea=(2+a[6]);
if(ea>=0x39c8ul&&ea<=0x3aa0ul){
 d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul)+0u));
 d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul)+2u));
}else{
 d[0]=(s16)vr16(ea+0);
 d[1]=(s16)vr16(ea+2);
}
goto L3ef8;
L3ef8: /* move.w D0, D4 */
VSTEP(0x3ef8ul);
tv=((u16)d[0]);
VWORD(d[4])=(u16)(tv);

goto L3efa;
L3efa: /* movem.w $67bc.w, D2-D3 */
VSTEP(0x3efaul);
ea=0x67bcul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1246u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1248u));
goto L3f00;
L3f00: /* sub.w D2, D0 */
VSTEP(0x3f00ul);
tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3f02;
L3f02: /* sub.w D3, D1 */
VSTEP(0x3f02ul);
tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L3f04;
L3f04: /* cmpi.w #$140, D0 */
VSTEP(0x3f04ul);
tv=((u16)(320L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f08;
L3f08: /* bcs $3f10 */
VSTEP(0x3f08ul);
if(fc)goto L3f10;
goto L3f0a;
L3f0a: /* cmpi.w #-$a0, D0 */
VSTEP(0x3f0aul);
tv=((u16)(-160L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f0e;
L3f0e: /* bcs $3f2e */
VSTEP(0x3f0eul);
if(fc)goto L3f2e;
goto L3f10;
L3f10: /* cmpi.w #$a0, D1 */
VSTEP(0x3f10ul);
tv=((u16)(160L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f14;
L3f14: /* bcs $3f1c */
VSTEP(0x3f14ul);
if(fc)goto L3f1c;
goto L3f16;
L3f16: /* cmpi.w #-$50, D1 */
VSTEP(0x3f16ul);
tv=((u16)(-80L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f1a;
L3f1a: /* bcs $3f2e */
VSTEP(0x3f1aul);
if(fc)goto L3f2e;
goto L3f1c;
L3f1c: /* bclr #$7, (A6) */
VSTEP(0x3f1cul);
v=((u16)(7L));
eb=a[6];
w=(eb>=0x39c8ul&&eb<(0x39c8ul+220ul))?vm_actors[(u16)(eb-0x39c8ul)]:vr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
if(eb>=0x39c8ul&&eb<(0x39c8ul+220ul))vm_actors[(u16)(eb-0x39c8ul)]=(u8)r;else vw8(eb,r);
goto L3f20;
L3f20: /* beq $3f48 */
VSTEP(0x3f20ul);
if(fz)goto L3f48;
goto L3f22;
L3f22: /* cmpi.w #$50, D1 */
VSTEP(0x3f22ul);
tv=((u16)(80L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f26;
L3f26: /* bcc $3f48 */
VSTEP(0x3f26ul);
if(!fc)goto L3f48;
goto L3f28;
L3f28: /* cmpi.w #$a0, D0 */
VSTEP(0x3f28ul);
tv=((u16)(160L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f2c;
L3f2c: /* bcc $3f48 */
VSTEP(0x3f2cul);
if(!fc)goto L3f48;
goto L3f2e;
L3f2e: /* cmpi.w #$14, D6 */
VSTEP(0x3f2eul);
tv=((u16)(20L));
tw=((u16)d[6]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f32;
L3f32: /* bcs $3f44 */
VSTEP(0x3f32ul);
if(fc)goto L3f44;
goto L3f34;
L3f34: /* lea $0.w, A0 */
VSTEP(0x3f34ul);
a[0]=0x0ul;
goto L3f38;
L3f38: /* movea.l D0, A0 */
VSTEP(0x3f38ul);
v=((u32)d[0]);
a[0]=v;
goto L3f3a;
L3f3a: /* movea.w ($14,A6), A0 */
VSTEP(0x3f3aul);
ea=(20+a[6]);
v=vr16(ea);
a[0]=(s16)v;
goto L3f3e;
L3f3e: /* bclr #$7, (-$2,A0) */
VSTEP(0x3f3eul);
v=((u16)(7L));
eb=(-2+a[0]);
w=vr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
vw8(eb,r);
goto L3f44;
L3f44: /* clr.w (A6) */
VSTEP(0x3f44ul);
ea=a[6];
if(ea>=0x39c8ul&&ea<=(0x39c8ul+218ul))dm_put16((u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul)),0);else vw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L3f46;
L3f46: /* bra $3fa8 */
VSTEP(0x3f46ul);
goto L3fa8;
L3f48: /* lea $5a9a.w, A0 */
VSTEP(0x3f48ul);
a[0]=0x5a9aul;
goto L3f4c;
L3f4c: /* add.w D6, D6 */
VSTEP(0x3f4cul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[6])=(u16)(tr);
goto L3f4e;
L3f4e: /* adda.w D6, A0 */
VSTEP(0x3f4eul);
v=((u16)d[6]);
w=((u32)a[0]);
v=(s32)(s16)v;
r=w+v;
a[0]=r;
goto L3f50;
L3f50: /* movea.w (A0), A0 */
VSTEP(0x3f50ul);
ea=a[0];
v=vr16(ea);
a[0]=(s16)v;
goto L3f52;
L3f52: /* move.w D7, -(A7) */
VSTEP(0x3f52ul);
tv=((u16)d[7]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3f54;
L3f54: /* jsr (A0) */
VSTEP(0x3f54ul);
a[7]-=4;vw32(a[7],0x3f56ul);
pc=a[0];goto dispatch;
L3f56: /* movem.w ($e,A6), D0-D2 */
VSTEP(0x3f56ul);
ea=(14+a[6]);
if(ea>=0x39c8ul&&ea<=0x3a9eul){
 d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul)+0u));
 d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul)+2u));
 d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul)+4u));
}else{
 d[0]=(s16)vr16(ea+0);
 d[1]=(s16)vr16(ea+2);
 d[2]=(s16)vr16(ea+4);
}
goto L3f5c;
L3f5c: /* sub.w $67c2.w, D0 */
VSTEP(0x3f5cul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3f60;
L3f60: /* addq.w #6, D0 */
VSTEP(0x3f60ul);
tv=((u16)(6L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L3f62;
L3f62: /* cmpi.w #$d, D0 */
VSTEP(0x3f62ul);
tv=((u16)(13L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f66;
L3f66: /* bcc $3fa6 */
VSTEP(0x3f66ul);
if(!fc)goto L3fa6;
goto L3f68;
L3f68: /* sub.w $62f0.w, D1 */
VSTEP(0x3f68ul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L3f6c;
L3f6c: /* subq.w #6, D1 */
VSTEP(0x3f6cul);
tv=((u16)(6L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L3f6e;
L3f6e: /* bmi $3fa6 */
VSTEP(0x3f6eul);
if(fn)goto L3fa6;
goto L3f70;
L3f70: /* sub.w $67c4.w, D2 */
VSTEP(0x3f70ul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L3f74;
L3f74: /* bpl $3fa6 */
VSTEP(0x3f74ul);
if(!fn)goto L3fa6;
goto L3f76;
L3f76: /* move.w (A6), D0 */
VSTEP(0x3f76ul);
ea=a[6];
tv=(ea>=0x39c8ul&&ea<=(0x39c8ul+218ul))?dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul))):vr16(ea);
VWORD(d[0])=(u16)(tv);

goto L3f78;
L3f78: /* subq.w #2, D0 */
VSTEP(0x3f78ul);
tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L3f7a;
L3f7a: /* bmi $3fa6 */
VSTEP(0x3f7aul);
if(fn)goto L3fa6;
goto L3f7c;
L3f7c: /* move.w #$1, (A6) */
VSTEP(0x3f7cul);
tv=((u16)(1L));
ea=a[6];
if(ea>=0x39c8ul&&ea<=(0x39c8ul+218ul))dm_put16((u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39c8ul)),tv);else vw16(ea,tv);

goto L3f80;
L3f80: /* moveq #$a, D0 */
VSTEP(0x3f80ul);
v=((u32)(10L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3f82;
L3f82: /* jsr $48014.l */
VSTEP(0x3f82ul);
a[7]-=4;vw32(a[7],0x3f88ul);
goto L48014;
L3f88: /* move.w #$fffe, ($a,A6) */
VSTEP(0x3f88ul);
tv=((u16)(65534L));
ea=(10+a[6]);
vw16(ea,tv);

goto L3f8e;
L3f8e: /* tst.w $62fa.w */
VSTEP(0x3f8eul);
ea=0x62faul;
tv=(((u16)vm_vars[28]<<8)|((u16)vm_vars[29]<<0));
fn=(u8)((tv&0x8000ul)!=0);
goto L3f92;
L3f92: /* bmi $3fa6 */
VSTEP(0x3f92ul);
if(fn)goto L3fa6;
goto L3f94;
L3f94: /* tst.w $6318.w */
VSTEP(0x3f94ul);
ea=0x6318ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
fz=(u8)((tv&0xfffful)==0);
goto L3f98;
L3f98: /* beq $3fa0 */
VSTEP(0x3f98ul);
if(fz)goto L3fa0;
goto L3f9a;
L3f9a: /* tst.w $62f4.w */
VSTEP(0x3f9aul);
ea=0x62f4ul;
tv=(((u16)vm_vars[22]<<8)|((u16)vm_vars[23]<<0));
fz=(u8)((tv&0xfffful)==0);
goto L3f9e;
L3f9e: /* bne $3fa6 */
VSTEP(0x3f9eul);
if(!fz)goto L3fa6;
goto L3fa0;
L3fa0: /* moveq #$5, D6 */
VSTEP(0x3fa0ul);
v=((u32)(5L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3fa2;
L3fa2: /* bsr $4ccc */
VSTEP(0x3fa2ul);
a[7]-=4;vw32(a[7],0x3fa6ul);
goto L4ccc;
L3fa6: /* move.w (A7)+, D7 */
VSTEP(0x3fa6ul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3fa8;
L3fa8: /* lea ($16,A6), A6 */
VSTEP(0x3fa8ul);
a[6]=(22+a[6]);
goto L3fac;
L3fac: /* dbra D7, $3eec */
VSTEP(0x3facul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L3eec;
goto L3fb0;
L3fb0: /* rts  */
VSTEP(0x3fb0ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3fb2: /* addi.w #$2, (A6) */
VSTEP(0x3fb2ul);
tv=((u16)(2L));
eb=a[6];
tw=(eb>=0x39c8ul&&eb<=(0x39c8ul+218ul))?dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(eb-0x39c8ul))):vr16(eb);
tr=tw+tv;
if(eb>=0x39c8ul&&eb<=(0x39c8ul+218ul))dm_put16((u8 DM_NEAR *)(vm_actors+(u16)(eb-0x39c8ul)),(u16)tr);else vw16(eb,tr);
goto L3fb6;
L3fb6: /* movem.w $67c2.w, D2 */
VSTEP(0x3fb6ul);
ea=0x67c2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
goto L3fbc;
L3fbc: /* move.w $62f0.w, D3 */
VSTEP(0x3fbcul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
VWORD(d[3])=(u16)(tv);

goto L3fc0;
L3fc0: /* addi.w #$15, D3 */
VSTEP(0x3fc0ul);
tv=((u16)(21L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L3fc4;
L3fc4: /* sub.w D1, D3 */
VSTEP(0x3fc4ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L3fc6;
L3fc6: /* asl.w #3, D3 */
VSTEP(0x3fc6ul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=tw<<3;
VWORD(d[3])=(u16)(tr);
goto L3fc8;
L3fc8: /* ext.l D3 */
VSTEP(0x3fc8ul);
v=((u32)d[3]);
r=(s32)(s16)v;
d[3]=r;

goto L3fca;
L3fca: /* sub.w D0, D2 */
VSTEP(0x3fcaul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L3fcc;
L3fcc: /* bpl $3fd0 */
VSTEP(0x3fccul);
if(!fn)goto L3fd0;
goto L3fce;
L3fce: /* neg.w D2 */
VSTEP(0x3fceul);
tv=((u16)d[2]);
tr=0-tv;fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L3fd0;
L3fd0: /* beq $3fd4 */
VSTEP(0x3fd0ul);
if(fz)goto L3fd4;
goto L3fd2;
L3fd2: /* divs.w D2, D3 */
VSTEP(0x3fd2ul);
v=((u16)d[2]);
w=((u32)d[3]);
if(!(s16)v){vm_fault=0xff;return;}
signed_result=(s32)w/(s16)v;
if(signed_result>32767L||signed_result<-32768L){fv=1;}else{r=((u32)((s32)w%(s16)v)<<16)|(u16)signed_result;}
d[3]=r;
goto L3fd4;
L3fd4: /* asr.w #2, D2 */
VSTEP(0x3fd4ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((s16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L3fd6;
L3fd6: /* sub.w D2, D3 */
VSTEP(0x3fd6ul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[3])=(u16)(tr);
goto L3fd8;
L3fd8: /* bsr $463e */
VSTEP(0x3fd8ul);
a[7]-=4;vw32(a[7],0x3fdcul);
goto L463e;
L3fdc: /* cmpi.w #$8, D3 */
VSTEP(0x3fdcul);
tv=((u16)(8L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L3fe0;
L3fe0: /* bcs $3ff0 */
VSTEP(0x3fe0ul);
if(fc)goto L3ff0;
goto L3fe2;
L3fe2: /* bmi $3fe8 */
VSTEP(0x3fe2ul);
if(fn)goto L3fe8;
goto L3fe4;
L3fe4: /* moveq #$8, D3 */
VSTEP(0x3fe4ul);
v=((u32)(8L));
d[3]=v;

goto L3fe6;
L3fe6: /* bra $3ff0 */
VSTEP(0x3fe6ul);
goto L3ff0;
L3fe8: /* cmpi.w #-$18, D3 */
VSTEP(0x3fe8ul);
tv=((u16)(-24L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L3fec;
L3fec: /* bcc $3ff0 */
VSTEP(0x3fecul);
if(!fc)goto L3ff0;
goto L3fee;
L3fee: /* moveq #-$18, D3 */
VSTEP(0x3feeul);
v=((u32)(-24L));
d[3]=v;

goto L3ff0;
L3ff0: /* move.w D3, ($6,A0) */
VSTEP(0x3ff0ul);
tv=((u16)d[3]);
ea=(6+a[0]);
vw16(ea,tv);

goto L3ff4;
L3ff4: /* cmpi.w #$73, D1 */
VSTEP(0x3ff4ul);
tv=((u16)(115L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3ff8;
L3ff8: /* bpl $400a */
VSTEP(0x3ff8ul);
if(!fn)goto L400a;
goto L3ffa;
L3ffa: /* movem.w D0-D1, -(A7) */
VSTEP(0x3ffaul);
a[7]-=2;
vw16(a[7],d[1]);
a[7]-=2;
vw16(a[7],d[0]);
goto L3ffe;
L3ffe: /* moveq #$9, D0 */
VSTEP(0x3ffeul);
v=((u32)(9L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4000;
L4000: /* jsr $48014.l */
VSTEP(0x4000ul);
a[7]-=4;vw32(a[7],0x4006ul);
goto L48014;
L4006: /* movem.w (A7)+, D0-D1 */
VSTEP(0x4006ul);
ea=a[7];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
a[7]+=4;
goto L400a;
L400a: /* rts  */
VSTEP(0x400aul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L400c: /* move.w ($8,A6), D2 */
VSTEP(0x400cul);
ea=(8+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4010;
L4010: /* cmpi.w #$7, D2 */
VSTEP(0x4010ul);
tv=((u16)(7L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4014;
L4014: /* bne $402e */
VSTEP(0x4014ul);
if(!fz)goto L402e;
goto L4016;
L4016: /* subq.w #5, D0 */
VSTEP(0x4016ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4018;
L4018: /* bsr $3fb2 */
VSTEP(0x4018ul);
a[7]-=4;vw32(a[7],0x401cul);
goto L3fb2;
L401c: /* move.w #$d, (A0)+ */
VSTEP(0x401cul);
tv=((u16)(13L));
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L4020;
L4020: /* move.w D1, D3 */
VSTEP(0x4020ul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L4022;
L4022: /* subi.w #$11, D3 */
VSTEP(0x4022ul);
tv=((u16)(17L));
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L4026;
L4026: /* movem.w D0/D3, (A0) */
VSTEP(0x4026ul);
ea=a[0];
vw16(ea+0,d[0]);
vw16(ea+2,d[3]);
goto L402a;
L402a: /* addq.w #5, D0 */
VSTEP(0x402aul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L402c;
L402c: /* moveq #$8, D2 */
VSTEP(0x402cul);
v=((u32)(8L));
d[2]=v;

goto L402e;
L402e: /* addq.w #1, ($8,A6) */
VSTEP(0x402eul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L4032;
L4032: /* lea $44d4.w, A5 */
VSTEP(0x4032ul);
a[5]=0x44d4ul;
goto L4036;
L4036: /* andi.w #$fe, D2 */
VSTEP(0x4036ul);
tv=((u16)(254L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L403a;
L403a: /* adda.w D2, A5 */
VSTEP(0x403aul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L403c;
L403c: /* add.w D2, D2 */
VSTEP(0x403cul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L403e;
L403e: /* adda.w D2, A5 */
VSTEP(0x403eul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L4040;
L4040: /* bra $457c */
VSTEP(0x4040ul);
goto L457c;
L4044: /* lea $44ec.w, A5 */
VSTEP(0x4044ul);
a[5]=0x44ecul;
goto L4048;
L4048: /* bsr $457c */
VSTEP(0x4048ul);
a[7]-=4;vw32(a[7],0x404cul);
goto L457c;
L404c: /* subq.w #1, ($8,A6) */
VSTEP(0x404cul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vw16(eb,tr);
goto L4050;
L4050: /* bne $405c */
VSTEP(0x4050ul);
if(!fz)goto L405c;
goto L4052;
L4052: /* move.w #$20, ($8,A6) */
VSTEP(0x4052ul);
tv=((u16)(32L));
ea=(8+a[6]);
vw16(ea,tv);

goto L4058;
L4058: /* move.w #$2, (A6) */
VSTEP(0x4058ul);
tv=((u16)(2L));
ea=a[6];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L405c;
L405c: /* rts  */
VSTEP(0x405cul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L405e: /* cmpi.w #-$40, D0 */
VSTEP(0x405eul);
tv=((u16)(-64L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4062;
L4062: /* bmi $40b0 */
VSTEP(0x4062ul);
if(fn)goto L40b0;
goto L4064;
L4064: /* subq.w #1, ($8,A6) */
VSTEP(0x4064ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
vw16(eb,tr);
goto L4068;
L4068: /* bpl $4082 */
VSTEP(0x4068ul);
if(!fn)goto L4082;
goto L406a;
L406a: /* move.w D0, D2 */
VSTEP(0x406aul);
tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L406c;
L406c: /* sub.w $67c2.w, D2 */
VSTEP(0x406cul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4070;
L4070: /* cmpi.w #$30, D2 */
VSTEP(0x4070ul);
tv=((u16)(48L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4074;
L4074: /* bcc $4082 */
VSTEP(0x4074ul);
if(!fc)goto L4082;
goto L4076;
L4076: /* clr.w ($8,A6) */
VSTEP(0x4076ul);
ea=(8+a[6]);
vw16(ea,0);

goto L407a;
L407a: /* move.w #$5, (A6) */
VSTEP(0x407aul);
tv=((u16)(5L));
ea=a[6];
vw16(ea,tv);

goto L407e;
L407e: /* bra $431e */
VSTEP(0x407eul);
goto L431e;
L4082: /* moveq #$7, D2 */
VSTEP(0x4082ul);
v=((u32)(7L));
d[2]=v;

goto L4084;
L4084: /* and.w D4, D2 */
VSTEP(0x4084ul);
tv=((u16)d[4]);
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4086;
L4086: /* bne $4318 */
VSTEP(0x4086ul);
if(!fz)goto L4318;
goto L408a;
L408a: /* subi.w #$c, D0 */
VSTEP(0x408aul);
tv=((u16)(12L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L408e;
L408e: /* bsr $55a0 */
VSTEP(0x408eul);
a[7]-=4;vw32(a[7],0x4092ul);
goto L55a0;
L4092: /* addi.w #$c, D0 */
VSTEP(0x4092ul);
tv=((u16)(12L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4096;
L4096: /* cmpi.b #$79, D2 */
VSTEP(0x4096ul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L409a;
L409a: /* bcc $4318 */
VSTEP(0x409aul);
if(!fc)goto L4318;
goto L409e;
L409e: /* tst.w ($8,A6) */
VSTEP(0x409eul);
ea=(8+a[6]);
tv=vr16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L40a2;
L40a2: /* bpl $40b0 */
VSTEP(0x40a2ul);
if(!fn)goto L40b0;
goto L40a4;
L40a4: /* move.w D0, D2 */
VSTEP(0x40a4ul);
tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L40a6;
L40a6: /* sub.w $67c2.w, D2 */
VSTEP(0x40a6ul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L40aa;
L40aa: /* cmpi.w #$40, D2 */
VSTEP(0x40aaul);
tv=((u16)(64L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L40ae;
L40ae: /* bcs $4076 */
VSTEP(0x40aeul);
if(fc)goto L4076;
goto L40b0;
L40b0: /* move.w #$2, (A6) */
VSTEP(0x40b0ul);
tv=((u16)(2L));
ea=a[6];
vw16(ea,tv);

goto L40b4;
L40b4: /* bra $431e */
VSTEP(0x40b4ul);
goto L431e;
L40b8: /* move.w ($8,A6), D2 */
VSTEP(0x40b8ul);
ea=(8+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L40bc;
L40bc: /* cmpi.w #$7, D2 */
VSTEP(0x40bcul);
tv=((u16)(7L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L40c0;
L40c0: /* bne $40da */
VSTEP(0x40c0ul);
if(!fz)goto L40da;
goto L40c2;
L40c2: /* addq.w #5, D0 */
VSTEP(0x40c2ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L40c4;
L40c4: /* bsr $3fb2 */
VSTEP(0x40c4ul);
a[7]-=4;vw32(a[7],0x40c8ul);
goto L3fb2;
L40c8: /* move.w #$c, (A0)+ */
VSTEP(0x40c8ul);
tv=((u16)(12L));
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L40cc;
L40cc: /* move.w D1, D3 */
VSTEP(0x40ccul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L40ce;
L40ce: /* subi.w #$11, D3 */
VSTEP(0x40ceul);
tv=((u16)(17L));
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L40d2;
L40d2: /* movem.w D0/D3, (A0) */
VSTEP(0x40d2ul);
ea=a[0];
vw16(ea+0,d[0]);
vw16(ea+2,d[3]);
goto L40d6;
L40d6: /* subq.w #5, D0 */
VSTEP(0x40d6ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L40d8;
L40d8: /* moveq #$8, D2 */
VSTEP(0x40d8ul);
v=((u32)(8L));
d[2]=v;

goto L40da;
L40da: /* addq.w #1, ($8,A6) */
VSTEP(0x40daul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L40de;
L40de: /* lea $44f2.w, A5 */
VSTEP(0x40deul);
a[5]=0x44f2ul;
goto L40e2;
L40e2: /* andi.w #$fe, D2 */
VSTEP(0x40e2ul);
tv=((u16)(254L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L40e6;
L40e6: /* adda.w D2, A5 */
VSTEP(0x40e6ul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L40e8;
L40e8: /* add.w D2, D2 */
VSTEP(0x40e8ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L40ea;
L40ea: /* adda.w D2, A5 */
VSTEP(0x40eaul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L40ec;
L40ec: /* bra $457c */
VSTEP(0x40ecul);
goto L457c;
L40f0: /* lea $450a.w, A5 */
VSTEP(0x40f0ul);
a[5]=0x450aul;
goto L40f4;
L40f4: /* bsr $457c */
VSTEP(0x40f4ul);
a[7]-=4;vw32(a[7],0x40f8ul);
goto L457c;
L40f8: /* subq.w #1, ($8,A6) */
VSTEP(0x40f8ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vw16(eb,tr);
goto L40fc;
L40fc: /* bne $4108 */
VSTEP(0x40fcul);
if(!fz)goto L4108;
goto L40fe;
L40fe: /* move.w #$20, ($8,A6) */
VSTEP(0x40feul);
tv=((u16)(32L));
ea=(8+a[6]);
vw16(ea,tv);

goto L4104;
L4104: /* move.w #$3, (A6) */
VSTEP(0x4104ul);
tv=((u16)(3L));
ea=a[6];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4108;
L4108: /* rts  */
VSTEP(0x4108ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L410a: /* cmpi.w #$e0, D0 */
VSTEP(0x410aul);
tv=((u16)(224L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L410e;
L410e: /* bpl $4158 */
VSTEP(0x410eul);
if(!fn)goto L4158;
goto L4110;
L4110: /* subq.w #1, ($8,A6) */
VSTEP(0x4110ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
vw16(eb,tr);
goto L4114;
L4114: /* bpl $412e */
VSTEP(0x4114ul);
if(!fn)goto L412e;
goto L4116;
L4116: /* move.w $67c2.w, D2 */
VSTEP(0x4116ul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
VWORD(d[2])=(u16)(tv);

goto L411a;
L411a: /* sub.w D0, D2 */
VSTEP(0x411aul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L411c;
L411c: /* cmpi.w #$30, D2 */
VSTEP(0x411cul);
tv=((u16)(48L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4120;
L4120: /* bcc $412e */
VSTEP(0x4120ul);
if(!fc)goto L412e;
goto L4122;
L4122: /* clr.w ($8,A6) */
VSTEP(0x4122ul);
ea=(8+a[6]);
vw16(ea,0);

goto L4126;
L4126: /* move.w #$4, (A6) */
VSTEP(0x4126ul);
tv=((u16)(4L));
ea=a[6];
vw16(ea,tv);

goto L412a;
L412a: /* bra $4248 */
VSTEP(0x412aul);
goto L4248;
L412e: /* moveq #$7, D2 */
VSTEP(0x412eul);
v=((u32)(7L));
d[2]=v;

goto L4130;
L4130: /* and.w D4, D2 */
VSTEP(0x4130ul);
tv=((u16)d[4]);
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4132;
L4132: /* bne $4242 */
VSTEP(0x4132ul);
if(!fz)goto L4242;
goto L4136;
L4136: /* addq.w #8, D0 */
VSTEP(0x4136ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4138;
L4138: /* bsr $55a0 */
VSTEP(0x4138ul);
a[7]-=4;vw32(a[7],0x413cul);
goto L55a0;
L413c: /* subq.w #8, D0 */
VSTEP(0x413cul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L413e;
L413e: /* cmpi.b #$79, D2 */
VSTEP(0x413eul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4142;
L4142: /* bcc $4242 */
VSTEP(0x4142ul);
if(!fc)goto L4242;
goto L4146;
L4146: /* tst.w ($8,A6) */
VSTEP(0x4146ul);
ea=(8+a[6]);
tv=vr16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L414a;
L414a: /* bpl $4158 */
VSTEP(0x414aul);
if(!fn)goto L4158;
goto L414c;
L414c: /* move.w $67c2.w, D2 */
VSTEP(0x414cul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
VWORD(d[2])=(u16)(tv);

goto L4150;
L4150: /* sub.w D0, D2 */
VSTEP(0x4150ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4152;
L4152: /* cmpi.w #$40, D2 */
VSTEP(0x4152ul);
tv=((u16)(64L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4156;
L4156: /* bcs $4122 */
VSTEP(0x4156ul);
if(fc)goto L4122;
goto L4158;
L4158: /* move.w #$3, (A6) */
VSTEP(0x4158ul);
tv=((u16)(3L));
ea=a[6];
vw16(ea,tv);

goto L415c;
L415c: /* bra $4248 */
VSTEP(0x415cul);
goto L4248;
L4160: /* move.w $67c4.w, D5 */
VSTEP(0x4160ul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
VWORD(d[5])=(u16)(tv);

goto L4164;
L4164: /* sub.w D1, D5 */
VSTEP(0x4164ul);
tv=((u16)d[1]);
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4166;
L4166: /* addi.w #$10, D5 */
VSTEP(0x4166ul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[5])=(u16)(tr);
goto L416a;
L416a: /* cmpi.w #$20, D5 */
VSTEP(0x416aul);
tv=((u16)(32L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L416e;
L416e: /* bcs $41a0 */
VSTEP(0x416eul);
if(fc)goto L41a0;
goto L4170;
L4170: /* bpl $4184 */
VSTEP(0x4170ul);
if(!fn)goto L4184;
goto L4172;
L4172: /* move.w $8002.l, D2 */
VSTEP(0x4172ul);
ea=0x8002ul;
tv=192u;
VWORD(d[2])=(u16)(tv);

goto L4178;
L4178: /* add.w D2, D2 */
VSTEP(0x4178ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L417a;
L417a: /* add.w D2, D2 */
VSTEP(0x417aul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L417c;
L417c: /* sub.w D2, D3 */
VSTEP(0x417cul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L417e;
L417e: /* clr.w D2 */
VSTEP(0x417eul);
VWORD(d[2])=(u16)(0);

goto L4180;
L4180: /* move.b (A0,D3.w), D2 */
VSTEP(0x4180ul);
ea=(a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4184;
L4184: /* cmpi.b #-$7b, D2 */
VSTEP(0x4184ul);
tv=((u8)(-123L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4188;
L4188: /* bcs $41a0 */
VSTEP(0x4188ul);
if(fc)goto L41a0;
goto L418a;
L418a: /* move.w #$2, ($8,A6) */
VSTEP(0x418aul);
tv=((u16)(2L));
ea=(8+a[6]);
vw16(ea,tv);

goto L4190;
L4190: /* move.w #$d, ($c,A6) */
VSTEP(0x4190ul);
tv=((u16)(13L));
ea=(12+a[6]);
vw16(ea,tv);

goto L4196;
L4196: /* subq.w #8, D5 */
VSTEP(0x4196ul);
tv=((u16)(8L));
tw=((u16)d[5]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[5])=(u16)(tr);
goto L4198;
L4198: /* bpl $41a0 */
VSTEP(0x4198ul);
if(!fn)goto L41a0;
goto L419a;
L419a: /* move.w #$c, ($c,A6) */
VSTEP(0x419aul);
tv=((u16)(12L));
ea=(12+a[6]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L41a0;
L41a0: /* rts  */
VSTEP(0x41a0ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L41a2: /* move.w D4, D2 */
VSTEP(0x41a2ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L41a4;
L41a4: /* addq.w #4, D2 */
VSTEP(0x41a4ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L41a6;
L41a6: /* andi.w #$7, D2 */
VSTEP(0x41a6ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L41aa;
L41aa: /* bne $4242 */
VSTEP(0x41aaul);
if(!fz)goto L4242;
goto L41ae;
L41ae: /* cmpi.w #$140, D0 */
VSTEP(0x41aeul);
tv=((u16)(320L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L41b2;
L41b2: /* bpl $41c2 */
VSTEP(0x41b2ul);
if(!fn)goto L41c2;
goto L41b4;
L41b4: /* addq.w #7, D0 */
VSTEP(0x41b4ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L41b6;
L41b6: /* bsr $55a0 */
VSTEP(0x41b6ul);
a[7]-=4;vw32(a[7],0x41baul);
goto L55a0;
L41ba: /* subq.w #7, D0 */
VSTEP(0x41baul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L41bc;
L41bc: /* cmpi.b #$79, D2 */
VSTEP(0x41bcul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L41c0;
L41c0: /* bcc $41ce */
VSTEP(0x41c0ul);
if(!fc)goto L41ce;
goto L41c2;
L41c2: /* move.w #$f, (A6) */
VSTEP(0x41c2ul);
tv=((u16)(15L));
ea=a[6];
vw16(ea,tv);

goto L41c6;
L41c6: /* clr.w ($8,A6) */
VSTEP(0x41c6ul);
ea=(8+a[6]);
vw16(ea,0);

goto L41ca;
L41ca: /* bra $4242 */
VSTEP(0x41caul);
goto L4242;
L41ce: /* bsr $4160 */
VSTEP(0x41ceul);
a[7]-=4;vw32(a[7],0x41d2ul);
goto L4160;
L41d2: /* subq.w #1, ($8,A6) */
VSTEP(0x41d2ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);
vw16(eb,tr);
goto L41d6;
L41d6: /* beq $4348 */
VSTEP(0x41d6ul);
if(fz)goto L4348;
goto L41da;
L41da: /* bpl $4242 */
VSTEP(0x41daul);
if(!fn)goto L4242;
goto L41dc;
L41dc: /* move.w $67c2.w, D2 */
VSTEP(0x41dcul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
VWORD(d[2])=(u16)(tv);

goto L41e0;
L41e0: /* sub.w D0, D2 */
VSTEP(0x41e0ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L41e2;
L41e2: /* bmi $4242 */
VSTEP(0x41e2ul);
if(fn)goto L4242;
goto L41e4;
L41e4: /* cmpi.w #$20, D5 */
VSTEP(0x41e4ul);
tv=((u16)(32L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L41e8;
L41e8: /* bpl $4224 */
VSTEP(0x41e8ul);
if(!fn)goto L4224;
goto L41ea;
L41ea: /* bcc $4202 */
VSTEP(0x41eaul);
if(!fc)goto L4202;
goto L41ec;
L41ec: /* cmpi.w #$38, D2 */
VSTEP(0x41ecul);
tv=((u16)(56L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L41f0;
L41f0: /* bcc $4242 */
VSTEP(0x41f0ul);
if(!fc)goto L4242;
goto L41f2;
L41f2: /* move.w #$10, ($c,A6) */
VSTEP(0x41f2ul);
tv=((u16)(16L));
ea=(12+a[6]);
vw16(ea,tv);

goto L41f8;
L41f8: /* move.l #$10000, ($8,A6) */
VSTEP(0x41f8ul);
v=((u32)(65536L));
ea=(8+a[6]);
vw32(ea,v);

goto L4200;
L4200: /* bra $4242 */
VSTEP(0x4200ul);
goto L4242;
L4202: /* subi.w #$10, D5 */
VSTEP(0x4202ul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4206;
L4206: /* add.w D5, D2 */
VSTEP(0x4206ul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4208;
L4208: /* ble $4242 */
VSTEP(0x4208ul);
if((fz||(fn!=fv)))goto L4242;
goto L420a;
L420a: /* subq.w #4, D2 */
VSTEP(0x420aul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L420c;
L420c: /* lsr.w #3, D2 */
VSTEP(0x420cul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L420e;
L420e: /* addq.w #1, D2 */
VSTEP(0x420eul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4210;
L4210: /* cmpi.w #$8, D2 */
VSTEP(0x4210ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4214;
L4214: /* bcc $4242 */
VSTEP(0x4214ul);
if(!fc)goto L4242;
goto L4216;
L4216: /* move.w D2, ($8,A6) */
VSTEP(0x4216ul);
tv=((u16)d[2]);
ea=(8+a[6]);
vw16(ea,tv);

goto L421a;
L421a: /* move.l #$50010, ($a,A6) */
VSTEP(0x421aul);
v=((u32)(327696L));
ea=(10+a[6]);
vw32(ea,v);

goto L4222;
L4222: /* bra $4242 */
VSTEP(0x4222ul);
goto L4242;
L4224: /* subq.w #8, D5 */
VSTEP(0x4224ul);
tv=((u16)(8L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4226;
L4226: /* sub.w D5, D2 */
VSTEP(0x4226ul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4228;
L4228: /* bls $4242 */
VSTEP(0x4228ul);
if((fc||fz))goto L4242;
goto L422a;
L422a: /* subq.w #4, D2 */
VSTEP(0x422aul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L422c;
L422c: /* lsr.w #3, D2 */
VSTEP(0x422cul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L422e;
L422e: /* addq.w #1, D2 */
VSTEP(0x422eul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4230;
L4230: /* cmpi.w #$8, D2 */
VSTEP(0x4230ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4234;
L4234: /* bcc $4242 */
VSTEP(0x4234ul);
if(!fc)goto L4242;
goto L4236;
L4236: /* move.w D2, ($8,A6) */
VSTEP(0x4236ul);
tv=((u16)d[2]);
ea=(8+a[6]);
vw16(ea,tv);

goto L423a;
L423a: /* move.l #$70010, ($a,A6) */
VSTEP(0x423aul);
v=((u32)(458768L));
ea=(10+a[6]);
vw32(ea,v);

goto L4242;
L4242: /* addq.w #1, D4 */
VSTEP(0x4242ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L4244;
L4244: /* move.w D4, ($2,A6) */
VSTEP(0x4244ul);
tv=((u16)d[4]);
ea=(2+a[6]);
vw16(ea,tv);

goto L4248;
L4248: /* andi.w #$e, D4 */
VSTEP(0x4248ul);
tv=((u16)(14L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L424c;
L424c: /* lsr.w #1, D4 */
VSTEP(0x424cul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((u16)tw)>>1;
VWORD(d[4])=(u16)(tr);
goto L424e;
L424e: /* move.w D4, -(A7) */
VSTEP(0x424eul);
tv=((u16)d[4]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);

goto L4250;
L4250: /* addq.w #8, D4 */
VSTEP(0x4250ul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L4252;
L4252: /* move.w D4, D2 */
VSTEP(0x4252ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4254;
L4254: /* bsr $45bc */
VSTEP(0x4254ul);
a[7]-=4;vw32(a[7],0x4258ul);
goto L45bc;
L4258: /* move.w (A7)+, D2 */
VSTEP(0x4258ul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L425a;
L425a: /* lsr.w #1, D2 */
VSTEP(0x425aul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L425c;
L425c: /* bne $4260 */
VSTEP(0x425cul);
if(!fz)goto L4260;
goto L425e;
L425e: /* addq.w #2, D2 */
VSTEP(0x425eul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4260;
L4260: /* addq.w #4, D2 */
VSTEP(0x4260ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4262;
L4262: /* bsr $45bc */
VSTEP(0x4262ul);
a[7]-=4;vw32(a[7],0x4266ul);
goto L45bc;
L4266: /* moveq #$4, D2 */
VSTEP(0x4266ul);
v=((u32)(4L));
d[2]=v;

goto L4268;
L4268: /* bra $458a */
VSTEP(0x4268ul);
goto L458a;
L426c: /* move.w D4, D2 */
VSTEP(0x426cul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L426e;
L426e: /* addq.w #4, D2 */
VSTEP(0x426eul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4270;
L4270: /* andi.w #$7, D2 */
VSTEP(0x4270ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4274;
L4274: /* bne $4318 */
VSTEP(0x4274ul);
if(!fz)goto L4318;
goto L4278;
L4278: /* cmpi.w #-$a0, D0 */
VSTEP(0x4278ul);
tv=((u16)(-160L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L427c;
L427c: /* bmi $4298 */
VSTEP(0x427cul);
if(fn)goto L4298;
goto L427e;
L427e: /* subq.w #7, D0 */
VSTEP(0x427eul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4280;
L4280: /* bsr $55a0 */
VSTEP(0x4280ul);
a[7]-=4;vw32(a[7],0x4284ul);
goto L55a0;
L4284: /* addq.w #7, D0 */
VSTEP(0x4284ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4286;
L4286: /* cmpi.b #$79, D2 */
VSTEP(0x4286ul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L428a;
L428a: /* bcc $42a4 */
VSTEP(0x428aul);
if(!fc)goto L42a4;
goto L428c;
L428c: /* move.w ($6,A6), D2 */
VSTEP(0x428cul);
ea=(6+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4290;
L4290: /* cmpi.w #$85, D2 */
VSTEP(0x4290ul);
tv=((u16)(133L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4294;
L4294: /* beq $440a */
VSTEP(0x4294ul);
if(fz)goto L440a;
goto L4298;
L4298: /* move.w #$e, (A6) */
VSTEP(0x4298ul);
tv=((u16)(14L));
ea=a[6];
vw16(ea,tv);

goto L429c;
L429c: /* clr.w ($8,A6) */
VSTEP(0x429cul);
ea=(8+a[6]);
vw16(ea,0);

goto L42a0;
L42a0: /* bra $4318 */
VSTEP(0x42a0ul);
goto L4318;
L42a4: /* bsr $4160 */
VSTEP(0x42a4ul);
a[7]-=4;vw32(a[7],0x42a8ul);
goto L4160;
L42a8: /* subq.w #1, ($8,A6) */
VSTEP(0x42a8ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);
vw16(eb,tr);
goto L42ac;
L42ac: /* beq $4348 */
VSTEP(0x42acul);
if(fz)goto L4348;
goto L42b0;
L42b0: /* bpl $4318 */
VSTEP(0x42b0ul);
if(!fn)goto L4318;
goto L42b2;
L42b2: /* move.w D0, D2 */
VSTEP(0x42b2ul);
tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L42b4;
L42b4: /* sub.w $67c2.w, D2 */
VSTEP(0x42b4ul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L42b8;
L42b8: /* bmi $4318 */
VSTEP(0x42b8ul);
if(fn)goto L4318;
goto L42ba;
L42ba: /* cmpi.w #$20, D5 */
VSTEP(0x42baul);
tv=((u16)(32L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L42be;
L42be: /* bpl $42fa */
VSTEP(0x42beul);
if(!fn)goto L42fa;
goto L42c0;
L42c0: /* bcc $42d8 */
VSTEP(0x42c0ul);
if(!fc)goto L42d8;
goto L42c2;
L42c2: /* cmpi.w #$38, D2 */
VSTEP(0x42c2ul);
tv=((u16)(56L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L42c6;
L42c6: /* bcc $4318 */
VSTEP(0x42c6ul);
if(!fc)goto L4318;
goto L42c8;
L42c8: /* move.w #$10, ($c,A6) */
VSTEP(0x42c8ul);
tv=((u16)(16L));
ea=(12+a[6]);
vw16(ea,tv);

goto L42ce;
L42ce: /* move.l #$10001, ($8,A6) */
VSTEP(0x42ceul);
v=((u32)(65537L));
ea=(8+a[6]);
vw32(ea,v);

goto L42d6;
L42d6: /* bra $4318 */
VSTEP(0x42d6ul);
goto L4318;
L42d8: /* subi.w #$10, D5 */
VSTEP(0x42d8ul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L42dc;
L42dc: /* add.w D5, D2 */
VSTEP(0x42dcul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L42de;
L42de: /* ble $4318 */
VSTEP(0x42deul);
if((fz||(fn!=fv)))goto L4318;
goto L42e0;
L42e0: /* subq.w #4, D2 */
VSTEP(0x42e0ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L42e2;
L42e2: /* lsr.w #3, D2 */
VSTEP(0x42e2ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L42e4;
L42e4: /* addq.w #1, D2 */
VSTEP(0x42e4ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L42e6;
L42e6: /* cmpi.w #$8, D2 */
VSTEP(0x42e6ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L42ea;
L42ea: /* bcc $4318 */
VSTEP(0x42eaul);
if(!fc)goto L4318;
goto L42ec;
L42ec: /* move.w D2, ($8,A6) */
VSTEP(0x42ecul);
tv=((u16)d[2]);
ea=(8+a[6]);
vw16(ea,tv);

goto L42f0;
L42f0: /* move.l #$40010, ($a,A6) */
VSTEP(0x42f0ul);
v=((u32)(262160L));
ea=(10+a[6]);
vw32(ea,v);

goto L42f8;
L42f8: /* bra $4318 */
VSTEP(0x42f8ul);
goto L4318;
L42fa: /* subq.w #8, D5 */
VSTEP(0x42faul);
tv=((u16)(8L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L42fc;
L42fc: /* sub.w D5, D2 */
VSTEP(0x42fcul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L42fe;
L42fe: /* bls $4318 */
VSTEP(0x42feul);
if((fc||fz))goto L4318;
goto L4300;
L4300: /* subq.w #4, D2 */
VSTEP(0x4300ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4302;
L4302: /* lsr.w #3, D2 */
VSTEP(0x4302ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L4304;
L4304: /* addq.w #1, D2 */
VSTEP(0x4304ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4306;
L4306: /* cmpi.w #$8, D2 */
VSTEP(0x4306ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L430a;
L430a: /* bcc $4318 */
VSTEP(0x430aul);
if(!fc)goto L4318;
goto L430c;
L430c: /* move.w D2, ($8,A6) */
VSTEP(0x430cul);
tv=((u16)d[2]);
ea=(8+a[6]);
vw16(ea,tv);

goto L4310;
L4310: /* move.l #$60010, ($a,A6) */
VSTEP(0x4310ul);
v=((u32)(393232L));
ea=(10+a[6]);
vw32(ea,v);

goto L4318;
L4318: /* subq.w #1, D4 */
VSTEP(0x4318ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L431a;
L431a: /* move.w D4, ($2,A6) */
VSTEP(0x431aul);
tv=((u16)d[4]);
ea=(2+a[6]);
vw16(ea,tv);

goto L431e;
L431e: /* andi.w #$e, D4 */
VSTEP(0x431eul);
tv=((u16)(14L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L4322;
L4322: /* lsr.w #1, D4 */
VSTEP(0x4322ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((u16)tw)>>1;
VWORD(d[4])=(u16)(tr);
goto L4324;
L4324: /* eori.w #$e007, D4 */
VSTEP(0x4324ul);
tv=((u16)(57351L));
tw=((u16)d[4]);
tr=tw^tv;

VWORD(d[4])=(u16)(tr);
goto L4328;
L4328: /* move.w D4, -(A7) */
VSTEP(0x4328ul);
tv=((u16)d[4]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);

goto L432a;
L432a: /* addq.w #8, D4 */
VSTEP(0x432aul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L432c;
L432c: /* move.w D4, D2 */
VSTEP(0x432cul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L432e;
L432e: /* bsr $45bc */
VSTEP(0x432eul);
a[7]-=4;vw32(a[7],0x4332ul);
goto L45bc;
L4332: /* move.w (A7)+, D2 */
VSTEP(0x4332ul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L4334;
L4334: /* lsr.b #1, D2 */
VSTEP(0x4334ul);
tv=((u8)(1L));
tw=((u8)d[2]);
tr=((u8)tw)>>1;fz=(u8)((tr&0xfful)==0);
VBYTE(d[2])=(u8)(tr);
goto L4336;
L4336: /* bne $433a */
VSTEP(0x4336ul);
if(!fz)goto L433a;
goto L4338;
L4338: /* addq.w #2, D2 */
VSTEP(0x4338ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L433a;
L433a: /* addq.w #4, D2 */
VSTEP(0x433aul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L433c;
L433c: /* bsr $45bc */
VSTEP(0x433cul);
a[7]-=4;vw32(a[7],0x4340ul);
goto L45bc;
L4340: /* move.w #$e004, D2 */
VSTEP(0x4340ul);
tv=((u16)(57348L));
VWORD(d[2])=(u16)(tv);

goto L4344;
L4344: /* bra $458a */
VSTEP(0x4344ul);
goto L458a;
L4348: /* move.w ($c,A6), D6 */
VSTEP(0x4348ul);
ea=(12+a[6]);
tv=vr16(ea);
VWORD(d[6])=(u16)(tv);

goto L434c;
L434c: /* move.w D6, (A6) */
VSTEP(0x434cul);
tv=((u16)d[6]);
ea=a[6];
vw16(ea,tv);

goto L434e;
L434e: /* cmpi.w #$10, D6 */
VSTEP(0x434eul);
tv=((u16)(16L));
tw=((u16)d[6]);
fz=(u8)((u16)tw==(u16)tv);
goto L4352;
L4352: /* bne $4374 */
VSTEP(0x4352ul);
if(!fz)goto L4374;
goto L4354;
L4354: /* move.w #$2, ($8,A6) */
VSTEP(0x4354ul);
tv=((u16)(2L));
ea=(8+a[6]);
vw16(ea,tv);

goto L435a;
L435a: /* move.w ($a,A6), D2 */
VSTEP(0x435aul);
ea=(10+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L435e;
L435e: /* cmpi.w #$2, D2 */
VSTEP(0x435eul);
tv=((u16)(2L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4362;
L4362: /* bcc $4374 */
VSTEP(0x4362ul);
if(!fc)goto L4374;
goto L4364;
L4364: /* move.w ($12,A6), D2 */
VSTEP(0x4364ul);
ea=(18+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4368;
L4368: /* addq.w #4, D2 */
VSTEP(0x4368ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L436a;
L436a: /* sub.w $62f0.w, D2 */
VSTEP(0x436aul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L436e;
L436e: /* bpl $4374 */
VSTEP(0x436eul);
if(!fn)goto L4374;
goto L4370;
L4370: /* addq.w #2, ($a,A6) */
VSTEP(0x4370ul);
tv=((u16)(2L));
eb=(10+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L4374;
L4374: /* lea $5a9a.w, A0 */
VSTEP(0x4374ul);
a[0]=0x5a9aul;
goto L4378;
L4378: /* add.w D6, D6 */
VSTEP(0x4378ul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[6])=(u16)(tr);
goto L437a;
L437a: /* adda.w D6, A0 */
VSTEP(0x437aul);
v=((u16)d[6]);
w=((u32)a[0]);
v=(s32)(s16)v;
r=w+v;
a[0]=r;
goto L437c;
L437c: /* movea.w (A0), A0 */
VSTEP(0x437cul);
ea=a[0];
v=vr16(ea);
a[0]=(s16)v;
goto L437e;
L437e: /* jmp (A0) */
VSTEP(0x437eul);
pc=a[0];goto dispatch;
L4380: /* move.w ($4,A6), D4 */
VSTEP(0x4380ul);
ea=(4+a[6]);
tv=vr16(ea);
VWORD(d[4])=(u16)(tv);

goto L4384;
L4384: /* btst #$0, $632d.w */
VSTEP(0x4384ul);
v=((u16)(0L));
eb=0x632dul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L438a;
L438a: /* bne $43ce */
VSTEP(0x438aul);
if(!fz)goto L43ce;
goto L438c;
L438c: /* addq.w #1, D4 */
VSTEP(0x438cul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L438e;
L438e: /* move.w D4, ($4,A6) */
VSTEP(0x438eul);
tv=((u16)d[4]);
ea=(4+a[6]);
vw16(ea,tv);

goto L4392;
L4392: /* addq.w #1, D1 */
VSTEP(0x4392ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L4394;
L4394: /* andi.w #$7, D4 */
VSTEP(0x4394ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
VWORD(d[4])=(u16)(tr);
goto L4398;
L4398: /* bne $43ce */
VSTEP(0x4398ul);
if(!fz)goto L43ce;
goto L439a;
L439a: /* bsr $55a0 */
VSTEP(0x439aul);
a[7]-=4;vw32(a[7],0x439eul);
goto L55a0;
L439e: /* bra $43c6 */
VSTEP(0x439eul);
goto L43c6;
L43a0: /* move.w ($4,A6), D4 */
VSTEP(0x43a0ul);
ea=(4+a[6]);
tv=vr16(ea);
VWORD(d[4])=(u16)(tv);

goto L43a4;
L43a4: /* btst #$0, $632d.w */
VSTEP(0x43a4ul);
v=((u16)(0L));
eb=0x632dul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L43aa;
L43aa: /* bne $43ce */
VSTEP(0x43aaul);
if(!fz)goto L43ce;
goto L43ac;
L43ac: /* subq.w #1, D4 */
VSTEP(0x43acul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L43ae;
L43ae: /* move.w D4, ($4,A6) */
VSTEP(0x43aeul);
tv=((u16)d[4]);
ea=(4+a[6]);
vw16(ea,tv);

goto L43b2;
L43b2: /* subq.w #1, D1 */
VSTEP(0x43b2ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L43b4;
L43b4: /* andi.w #$7, D4 */
VSTEP(0x43b4ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L43b8;
L43b8: /* bne $43ce */
VSTEP(0x43b8ul);
if(!fz)goto L43ce;
goto L43ba;
L43ba: /* subi.w #$18, D1 */
VSTEP(0x43baul);
tv=((u16)(24L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L43be;
L43be: /* bsr $55a0 */
VSTEP(0x43beul);
a[7]-=4;vw32(a[7],0x43c2ul);
goto L55a0;
L43c2: /* addi.w #$18, D1 */
VSTEP(0x43c2ul);
tv=((u16)(24L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L43c6;
L43c6: /* cmpi.b #-$7b, D2 */
VSTEP(0x43c6ul);
tv=((u8)(-123L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L43ca;
L43ca: /* bcc $43ce */
VSTEP(0x43caul);
if(!fc)goto L43ce;
goto L43cc;
L43cc: /* bsr $43fc */
VSTEP(0x43ccul);
a[7]-=4;vw32(a[7],0x43ceul);
goto L43fc;
L43ce: /* not.w D4 */
VSTEP(0x43ceul);
tv=((u16)d[4]);
tr=~tv;
VWORD(d[4])=(u16)(tr);

goto L43d0;
L43d0: /* andi.w #$7, D4 */
VSTEP(0x43d0ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L43d4;
L43d4: /* subq.w #1, D0 */
VSTEP(0x43d4ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L43d6;
L43d6: /* move.w D4, D2 */
VSTEP(0x43d6ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L43d8;
L43d8: /* bclr #$2, D2 */
VSTEP(0x43d8ul);
v=((u16)(2L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L43dc;
L43dc: /* beq $43e4 */
VSTEP(0x43dcul);
if(fz)goto L43e4;
goto L43de;
L43de: /* ori.w #$e000, D2 */
VSTEP(0x43deul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw|tv;

VWORD(d[2])=(u16)(tr);
goto L43e2;
L43e2: /* addq.w #1, D0 */
VSTEP(0x43e2ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L43e4;
L43e4: /* addi.w #$1b, D2 */
VSTEP(0x43e4ul);
tv=((u16)(27L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L43e8;
L43e8: /* move.w D2, -(A7) */
VSTEP(0x43e8ul);
tv=((u16)d[2]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L43ea;
L43ea: /* bsr $45bc */
VSTEP(0x43eaul);
a[7]-=4;vw32(a[7],0x43eeul);
goto L45bc;
L43ee: /* move.w (A7)+, D2 */
VSTEP(0x43eeul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L43f0;
L43f0: /* andi.w #$e000, D2 */
VSTEP(0x43f0ul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L43f4;
L43f4: /* addi.w #$1a, D2 */
VSTEP(0x43f4ul);
tv=((u16)(26L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L43f8;
L43f8: /* bra $458a */
VSTEP(0x43f8ul);
goto L458a;
L43fc: /* moveq #$7, D2 */
VSTEP(0x43fcul);
v=((u32)(7L));
d[2]=v;

goto L43fe;
L43fe: /* moveq #$4c, D3 */
VSTEP(0x43feul);
v=((u32)(76L));
d[3]=v;

goto L4400;
L4400: /* sub.w D0, D3 */
VSTEP(0x4400ul);
tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L4402;
L4402: /* add.w D3, D3 */
VSTEP(0x4402ul);
tv=((u16)d[3]);
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[3])=(u16)(tr);
goto L4404;
L4404: /* addx.w D2, D2 */
VSTEP(0x4404ul);
v=((u16)d[2]);
w=((u16)d[2]);
r=w+v+fx;fx=(u8)((r&~0xfffful)!=0);
VWORD(d[2])=(u16)(r);
goto L4406;
L4406: /* move.w D2, (A6) */
VSTEP(0x4406ul);
tv=((u16)d[2]);
ea=a[6];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4408;
L4408: /* rts  */
VSTEP(0x4408ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L440a: /* move.w #$ffff, ($8,A6) */
VSTEP(0x440aul);
tv=((u16)(65535L));
ea=(8+a[6]);
vw16(ea,tv);

goto L4410;
L4410: /* moveq #$6, D2 */
VSTEP(0x4410ul);
v=((u32)(6L));
d[2]=v;

goto L4412;
L4412: /* cmp.w $62f0.w, D1 */
VSTEP(0x4412ul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4416;
L4416: /* bmi $4428 */
VSTEP(0x4416ul);
if(fn)goto L4428;
goto L4418;
L4418: /* moveq #$1, D2 */
VSTEP(0x4418ul);
v=((u32)(1L));
d[2]=v;

goto L441a;
L441a: /* move.w ($12,A6), D3 */
VSTEP(0x441aul);
ea=(18+a[6]);
tv=vr16(ea);
VWORD(d[3])=(u16)(tv);

goto L441e;
L441e: /* addq.w #4, D3 */
VSTEP(0x441eul);
tv=((u16)(4L));
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[3])=(u16)(tr);
goto L4420;
L4420: /* cmp.w $62f0.w, D3 */
VSTEP(0x4420ul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[3]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4424;
L4424: /* bpl $4428 */
VSTEP(0x4424ul);
if(!fn)goto L4428;
goto L4426;
L4426: /* addq.w #2, D2 */
VSTEP(0x4426ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4428;
L4428: /* move.w D2, ($a,A6) */
VSTEP(0x4428ul);
tv=((u16)d[2]);
ea=(10+a[6]);
vw16(ea,tv);

goto L442c;
L442c: /* move.w #$10, (A6) */
VSTEP(0x442cul);
tv=((u16)(16L));
ea=a[6];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4430;
L4430: /* bsr $4570 */
VSTEP(0x4430ul);
a[7]-=4;vw32(a[7],0x4434ul);
goto L4570;
L4434: /* subq.w #1, ($8,A6) */
VSTEP(0x4434ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vw16(eb,tr);
goto L4438;
L4438: /* bpl $4442 */
VSTEP(0x4438ul);
if(!fn)goto L4442;
goto L443a;
L443a: /* addq.w #1, (A6) */
VSTEP(0x443aul);
tv=((u16)(1L));
eb=a[6];
tw=vr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vw16(eb,tr);
goto L443c;
L443c: /* move.w #$3, ($8,A6) */
VSTEP(0x443cul);
tv=((u16)(3L));
ea=(8+a[6]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4442;
L4442: /* rts  */
VSTEP(0x4442ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4444: /* bsr $4570 */
VSTEP(0x4444ul);
a[7]-=4;vw32(a[7],0x4448ul);
goto L4570;
L4448: /* btst #$0, $632d.l */
VSTEP(0x4448ul);
v=((u16)(0L));
eb=0x632dul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L4450;
L4450: /* bne $4442 */
VSTEP(0x4450ul);
if(!fz)goto L4442;
goto L4452;
L4452: /* bsr $463e */
VSTEP(0x4452ul);
a[7]-=4;vw32(a[7],0x4456ul);
goto L463e;
L4456: /* sub.w (A5)+, D1 */
VSTEP(0x4456ul);
ea=a[5];
tv=vr16(ea);
a[5]+=2;
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4458;
L4458: /* add.w $6310.w, D1 */
VSTEP(0x4458ul);
ea=0x6310ul;
tv=(((u16)vm_vars[50]<<8)|((u16)vm_vars[51]<<0));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L445c;
L445c: /* add.w (A5)+, D0 */
VSTEP(0x445cul);
ea=a[5];
tv=vr16(ea);
a[5]+=2;
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L445e;
L445e: /* add.w $630e.w, D0 */
VSTEP(0x445eul);
ea=0x630eul;
tv=(((u16)vm_vars[48]<<8)|((u16)vm_vars[49]<<0));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4462;
L4462: /* move.w (A5), (A0)+ */
VSTEP(0x4462ul);
ea=a[5];
tv=vr16(ea);
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L4464;
L4464: /* movem.w D0-D1, (A0) */
VSTEP(0x4464ul);
ea=a[0];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L4468;
L4468: /* moveq #$c, D2 */
VSTEP(0x4468ul);
v=((u32)(12L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L446a;
L446a: /* bsr $44b6 */
VSTEP(0x446aul);
a[7]-=4;vw32(a[7],0x446eul);
goto L44b6;
L446e: /* subq.w #1, ($8,A6) */
VSTEP(0x446eul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vw16(eb,tr);
goto L4472;
L4472: /* bne $4442 */
VSTEP(0x4472ul);
if(!fz)goto L4442;
goto L4474;
L4474: /* move.w #$6, ($8,A6) */
VSTEP(0x4474ul);
tv=((u16)(6L));
ea=(8+a[6]);
vw16(ea,tv);

goto L447a;
L447a: /* addq.w #1, (A6) */
VSTEP(0x447aul);
tv=((u16)(1L));
eb=a[6];
tw=vr16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
vw16(eb,tr);
goto L447c;
L447c: /* rts  */
VSTEP(0x447cul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L447e: /* bsr $4570 */
VSTEP(0x447eul);
a[7]-=4;vw32(a[7],0x4482ul);
goto L4570;
L4482: /* subq.w #1, ($8,A6) */
VSTEP(0x4482ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vw16(eb,tr);
goto L4486;
L4486: /* bne $4442 */
VSTEP(0x4486ul);
if(!fz)goto L4442;
goto L4488;
L4488: /* move.w #$4, ($8,A6) */
VSTEP(0x4488ul);
tv=((u16)(4L));
ea=(8+a[6]);
vw16(ea,tv);

goto L448e;
L448e: /* move.w ($a,A6), D2 */
VSTEP(0x448eul);
ea=(10+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4492;
L4492: /* move.w ($6,A6), D3 */
VSTEP(0x4492ul);
ea=(6+a[6]);
tv=vr16(ea);
VWORD(d[3])=(u16)(tv);

goto L4496;
L4496: /* cmpi.w #$85, D3 */
VSTEP(0x4496ul);
tv=((u16)(133L));
tw=((u16)d[3]);
fz=(u8)((u16)tw==(u16)tv);
goto L449a;
L449a: /* bne $44a0 */
VSTEP(0x449aul);
if(!fz)goto L44a0;
goto L449c;
L449c: /* move.w #$1, D2 */
VSTEP(0x449cul);
tv=((u16)(1L));
VWORD(d[2])=(u16)(tv);

goto L44a0;
L44a0: /* not.w D2 */
VSTEP(0x44a0ul);
tv=((u16)d[2]);
tr=~tv;
VWORD(d[2])=(u16)(tr);

goto L44a2;
L44a2: /* andi.w #$1, D2 */
VSTEP(0x44a2ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L44a6;
L44a6: /* addi.w #$e, D2 */
VSTEP(0x44a6ul);
tv=((u16)(14L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L44aa;
L44aa: /* move.w D2, (A6) */
VSTEP(0x44aaul);
tv=((u16)d[2]);
ea=a[6];
vw16(ea,tv);

goto L44ac;
L44ac: /* move.w D2, ($c,A6) */
VSTEP(0x44acul);
tv=((u16)d[2]);
ea=(12+a[6]);
vw16(ea,tv);

goto L44b0;
L44b0: /* move.w ($2,A6), D4 */
VSTEP(0x44b0ul);
ea=(2+a[6]);
tv=vr16(ea);
VWORD(d[4])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L44b4;
L44b4: /* rts  */
VSTEP(0x44b4ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L44b6: /* cmpi.w #$a0, D0 */
VSTEP(0x44b6ul);
tv=((u16)(160L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L44ba;
L44ba: /* bcc $44b4 */
VSTEP(0x44baul);
if(!fc)goto L44b4;
goto L44bc;
L44bc: /* cmpi.w #$59, D1 */
VSTEP(0x44bcul);
tv=((u16)(89L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L44c0;
L44c0: /* bcc $44b4 */
VSTEP(0x44c0ul);
if(!fc)goto L44b4;
goto L44c2;
L44c2: /* movem.w D0-D1, -(A7) */
VSTEP(0x44c2ul);
a[7]-=2;
vw16(a[7],d[1]);
a[7]-=2;
vw16(a[7],d[0]);
goto L44c6;
L44c6: /* move.w D2, D0 */
VSTEP(0x44c6ul);
tv=((u16)d[2]);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L44c8;
L44c8: /* jsr $48014.l */
VSTEP(0x44c8ul);
a[7]-=4;vw32(a[7],0x44ceul);
goto L48014;
L44ce: /* movem.w (A7)+, D0-D1 */
VSTEP(0x44ceul);
ea=a[7];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
a[7]+=4;
goto L44d2;
L44d2: /* rts  */
VSTEP(0x44d2ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4570: /* move.w ($a,A6), D2 */
VSTEP(0x4570ul);
ea=(10+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4574;
L4574: /* mulu.w #$c, D2 */
VSTEP(0x4574ul);
v=((u16)(12L));
w=((u32)d[2]);
r=(u32)(u16)v*(u16)w;

d[2]=r;
goto L4578;
L4578: /* lea (-$6a,PC,D2.w), A5 */
VSTEP(0x4578ul);
a[5]=(-106+0x457aul+((s16)(d[2])));
goto L457c;
L457c: /* move.w (A5)+, D2 */
VSTEP(0x457cul);
ea=a[5];
tv=vr16(ea);
a[5]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L457e;
L457e: /* bsr $458a */
VSTEP(0x457eul);
a[7]-=4;vw32(a[7],0x4580ul);
goto L458a;
L4580: /* move.w (A5)+, D2 */
VSTEP(0x4580ul);
ea=a[5];
tv=vr16(ea);
a[5]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4582;
L4582: /* bsr $45bc */
VSTEP(0x4582ul);
a[7]-=4;vw32(a[7],0x4584ul);
goto L45bc;
L4584: /* move.w (A5)+, D2 */
VSTEP(0x4584ul);
ea=a[5];
tv=vr16(ea);
a[5]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4586;
L4586: /* bne $45bc */
VSTEP(0x4586ul);
if(!fz)goto L45bc;
goto L4588;
L4588: /* rts  */
VSTEP(0x4588ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L458a: /* add.w ($6,A6), D2 */
VSTEP(0x458aul);
ea=(6+a[6]);
tv=vr16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L458e;
L458e: /* move.w D2, D3 */
VSTEP(0x458eul);
tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L4590;
L4590: /* andi.w #$1fff, D3 */
VSTEP(0x4590ul);
tv=((u16)(8191L));
tw=((u16)d[3]);
tr=tw&tv;

VWORD(d[3])=(u16)(tr);
goto L4594;
L4594: /* lsl.w #1, D3 */
VSTEP(0x4594ul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L4596;
L4596: /* lea $607c.w, A0 */
VSTEP(0x4596ul);
a[0]=0x607cul;
goto L459a;
L459a: /* move.w D1, D4 */
VSTEP(0x459aul);
tv=((u16)d[1]);
VWORD(d[4])=(u16)(tv);

goto L459c;
L459c: /* add.w D4, D4 */
VSTEP(0x459cul);
tv=((u16)d[4]);
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L459e;
L459e: /* move.b (-$2,A0,D3.w), D5 */
VSTEP(0x459eul);
ea=(-2+a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[5])=(u8)(tv);

goto L45a2;
L45a2: /* ext.w D5 */
VSTEP(0x45a2ul);
v=((u32)d[5]);
r=(s16)(s8)v;
VWORD(d[5])=(u16)(r);

goto L45a4;
L45a4: /* sub.w D5, D4 */
VSTEP(0x45a4ul);
tv=((u16)d[5]);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L45a6;
L45a6: /* asr.w #1, D4 */
VSTEP(0x45a6ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;
VWORD(d[4])=(u16)(tr);
goto L45a8;
L45a8: /* movem.w D0-D1/D4, ($e,A6) */
VSTEP(0x45a8ul);
ea=(14+a[6]);
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
vw16(ea+4,d[4]);
goto L45ae;
L45ae: /* movem.w D0-D1/A5-A6, -(A7) */
VSTEP(0x45aeul);
if(platform_draw_push())goto L45b2;
a[7]-=2;
vw16(a[7],a[6]);
a[7]-=2;
vw16(a[7],a[5]);
a[7]-=2;
vw16(a[7],d[1]);
a[7]-=2;
vw16(a[7],d[0]);
goto L45b2;
L45b2: /* bsr $56f4 */
VSTEP(0x45b2ul);
a[7]-=4;vw32(a[7],0x45b6ul);
goto L56f4;
L45b6: /* movem.w (A7)+, D0-D1/A5-A6 */
VSTEP(0x45b6ul);
ea=a[7];if(platform_draw_pop())goto L45ba;
ea=a[7];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
a[5]=(s16)vr16(ea+4);
a[6]=(s16)vr16(ea+6);
a[7]+=8;
goto L45ba;
L45ba: /* rts  */
VSTEP(0x45baul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L45bc: /* add.w ($6,A6), D2 */
VSTEP(0x45bcul);
ea=(6+a[6]);
tv=vr16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L45c0;
L45c0: /* movem.w D0-D1/A5-A6, -(A7) */
VSTEP(0x45c0ul);
if(platform_draw_push())goto L45c4;
a[7]-=2;
vw16(a[7],a[6]);
a[7]-=2;
vw16(a[7],a[5]);
a[7]-=2;
vw16(a[7],d[1]);
a[7]-=2;
vw16(a[7],d[0]);
goto L45c4;
L45c4: /* bsr $56f4 */
VSTEP(0x45c4ul);
a[7]-=4;vw32(a[7],0x45c8ul);
goto L56f4;
L45c8: /* movem.w (A7)+, D0-D1/A5-A6 */
VSTEP(0x45c8ul);
ea=a[7];if(platform_draw_pop())goto L45cc;
ea=a[7];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
a[5]=(s16)vr16(ea+4);
a[6]=(s16)vr16(ea+6);
a[7]+=8;
goto L45cc;
L45cc: /* rts  */
VSTEP(0x45ccul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L45ce: /* move.w ($a,A6), D2 */
VSTEP(0x45ceul);
ea=(10+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L45d2;
L45d2: /* addq.w #1, D2 */
VSTEP(0x45d2ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L45d4;
L45d4: /* cmpi.w #$e, D2 */
VSTEP(0x45d4ul);
tv=((u16)(14L));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L45d8;
L45d8: /* bpl $45de */
VSTEP(0x45d8ul);
if(!fn)goto L45de;
goto L45da;
L45da: /* move.w D2, ($a,A6) */
VSTEP(0x45daul);
tv=((u16)d[2]);
ea=(10+a[6]);
vw16(ea,tv);

goto L45de;
L45de: /* asr.w #1, D2 */
VSTEP(0x45deul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((s16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L45e0;
L45e0: /* add.w D2, ($4,A6) */
VSTEP(0x45e0ul);
tv=((u16)d[2]);
eb=(4+a[6]);
tw=vr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vw16(eb,tr);
goto L45e4;
L45e4: /* lea $62de.w, A5 */
VSTEP(0x45e4ul);
a[5]=0x62deul;
goto L45e8;
L45e8: /* cmpi.w #$64, D1 */
VSTEP(0x45e8ul);
tv=((u16)(100L));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L45ec;
L45ec: /* bmi $457c */
VSTEP(0x45ecul);
if(fn)goto L457c;
goto L45f0;
L45f0: /* clr.w (A6) */
VSTEP(0x45f0ul);
ea=a[6];
vw16(ea,0);

goto L45f2;
L45f2: /* move.l #$350, D0 */
VSTEP(0x45f2ul);
v=((u32)(848L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L45f8;
L45f8: /* jmp $7c82a.l */
VSTEP(0x45f8ul);
goto L7c82a;
L45fe: /* lea $4866.w, A5 */
VSTEP(0x45feul);
a[5]=0x4866ul;
goto L4602;
L4602: /* lea $4894.w, A6 */
VSTEP(0x4602ul);
a[6]=0x4894ul;
goto L4606;
L4606: /* moveq #$13, D7 */
VSTEP(0x4606ul);
v=((u32)(19L));
d[7]=v;

goto L4608;
L4608: /* move.w (A6)+, D2 */
VSTEP(0x4608ul);
if(platform_empty_shots(0x4894u,2u))goto L463c;
ea=a[6];
tv=vr16(ea);
a[6]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L460a;
L460a: /* beq $4636 */
VSTEP(0x460aul);
if(fz)goto L4636;
goto L460c;
L460c: /* movem.w (A6), D0-D1 */
VSTEP(0x460cul);
ea=a[6];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
goto L4610;
L4610: /* move.l A6, -(A7) */
VSTEP(0x4610ul);
v=((u32)a[6]);
a[7]-=4;
ea=a[7];
vw32(ea,v);

goto L4612;
L4612: /* move.w D7, -(A7) */
VSTEP(0x4612ul);
tv=((u16)d[7]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);

goto L4614;
L4614: /* btst #$f, D2 */
VSTEP(0x4614ul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4618;
L4618: /* beq $4622 */
VSTEP(0x4618ul);
if(fz)goto L4622;
goto L461a;
L461a: /* ext.w D2 */
VSTEP(0x461aul);
v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);

goto L461c;
L461c: /* move.w D2, (-$2,A6) */
VSTEP(0x461cul);
tv=((u16)d[2]);
ea=(-2+a[6]);
vw16(ea,tv);

goto L4620;
L4620: /* moveq #$4, D2 */
VSTEP(0x4620ul);
v=((u32)(4L));
d[2]=v;

goto L4622;
L4622: /* ror.w #1, D2 */
VSTEP(0x4622ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=(((u16)tw>>1)|(tw<<15));fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4624;
L4624: /* bpl $462a */
VSTEP(0x4624ul);
if(!fn)goto L462a;
goto L4626;
L4626: /* ori.w #$e000, D2 */
VSTEP(0x4626ul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw|tv;

VWORD(d[2])=(u16)(tr);
goto L462a;
L462a: /* addi.w #$3b, D2 */
VSTEP(0x462aul);
tv=((u16)(59L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L462e;
L462e: /* bsr $56f4 */
VSTEP(0x462eul);
a[7]-=4;vw32(a[7],0x4632ul);
goto L56f4;
L4632: /* move.w (A7)+, D7 */
VSTEP(0x4632ul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4634;
L4634: /* movea.l (A7)+, A6 */
VSTEP(0x4634ul);
ea=a[7];
v=vr32(ea);
a[7]+=4;
a[6]=v;
goto L4636;
L4636: /* addq.w #6, A6 */
VSTEP(0x4636ul);
v=((u16)(6L));
w=((u32)a[6]);
r=w+v;
a[6]=r;
goto L4638;
L4638: /* dbra D7, $4608 */
VSTEP(0x4638ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4608;
goto L463c;
L463c: /* rts  */
VSTEP(0x463cul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L463e: /* lea $4894.w, A0 */
VSTEP(0x463eul);
a[0]=0x4894ul;
goto L4642;
L4642: /* moveq #$13, D7 */
VSTEP(0x4642ul);
v=((u32)(19L));
d[7]=v;

goto L4644;
L4644: /* tst.w (A0) */
VSTEP(0x4644ul);
ea=a[0];
tv=vr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4646;
L4646: /* beq $4656 */
VSTEP(0x4646ul);
if(fz)goto L4656;
goto L4648;
L4648: /* lea ($8,A0), A0 */
VSTEP(0x4648ul);
a[0]=(8+a[0]);
goto L464c;
L464c: /* dbra D7, $4644 */
VSTEP(0x464cul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4644;
goto L4650;
L4650: /* movea.l #$fffffff8, A0 */
VSTEP(0x4650ul);
v=((u32)(4294967288L));
a[0]=v;
goto L4656;
L4656: /* rts  */
VSTEP(0x4656ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4658: /* lea $4866.w, A5 */
VSTEP(0x4658ul);
a[5]=0x4866ul;
goto L465c;
L465c: /* lea $4894.w, A6 */
VSTEP(0x465cul);
a[6]=0x4894ul;
goto L4660;
L4660: /* moveq #$13, D7 */
VSTEP(0x4660ul);
v=((u32)(19L));
d[7]=v;

goto L4662;
L4662: /* move.w (A6)+, D6 */
VSTEP(0x4662ul);
if(platform_empty_shots(0x4894u,6u))goto L4684;
ea=a[6];
tv=vr16(ea);
a[6]+=2;
VWORD(d[6])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4664;
L4664: /* beq $467e */
VSTEP(0x4664ul);
if(fz)goto L467e;
goto L4666;
L4666: /* movem.w (A6), D0-D1 */
VSTEP(0x4666ul);
ea=a[6];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
goto L466a;
L466a: /* sub.w $630e.w, D0 */
VSTEP(0x466aul);
ea=0x630eul;
tv=(((u16)vm_vars[48]<<8)|((u16)vm_vars[49]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L466e;
L466e: /* sub.w $6310.w, D1 */
VSTEP(0x466eul);
ea=0x6310ul;
tv=(((u16)vm_vars[50]<<8)|((u16)vm_vars[51]<<0));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4672;
L4672: /* asl.w #1, D6 */
VSTEP(0x4672ul);
tv=((u16)(1L));
tw=((u16)d[6]);
tr=tw<<1;fx=(u8)((tw>>15)&1);
VWORD(d[6])=(u16)(tr);
goto L4674;
L4674: /* clr.l D2 */
VSTEP(0x4674ul);
d[2]=0;
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L4676;
L4676: /* movea.l D2, A0 */
VSTEP(0x4676ul);
v=((u32)d[2]);
a[0]=v;
goto L4678;
L4678: /* movea.w (-$2,A5,D6.w), A0 */
VSTEP(0x4678ul);
ea=(-2+a[5]+((s16)(d[6])));
v=vr16(ea);
a[0]=(s16)v;
goto L467c;
L467c: /* jsr (A0) */
VSTEP(0x467cul);
a[7]-=4;vw32(a[7],0x467eul);
pc=a[0];goto dispatch;
L467e: /* addq.w #6, A6 */
VSTEP(0x467eul);
v=((u16)(6L));
w=((u32)a[6]);
r=w+v;
a[6]=r;
goto L4680;
L4680: /* dbra D7, $4662 */
VSTEP(0x4680ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4662;
goto L4684;
L4684: /* rts  */
VSTEP(0x4684ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4686: /* movem.w D0-D1, (A6) */
VSTEP(0x4686ul);
ea=a[6];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L468a;
L468a: /* bsr $55a0 */
VSTEP(0x468aul);
a[7]-=4;vw32(a[7],0x468eul);
goto L55a0;
L468e: /* cmpi.b #$17, D2 */
VSTEP(0x468eul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4692;
L4692: /* bcs $46ba */
VSTEP(0x4692ul);
if(fc)goto L46ba;
goto L4694;
L4694: /* sub.w $67c2.w, D0 */
VSTEP(0x4694ul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4698;
L4698: /* addq.w #4, D0 */
VSTEP(0x4698ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L469a;
L469a: /* cmpi.w #$9, D0 */
VSTEP(0x469aul);
tv=((u16)(9L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L469e;
L469e: /* bcc $46c0 */
VSTEP(0x469eul);
if(!fc)goto L46c0;
goto L46a0;
L46a0: /* cmp.w $67c4.w, D1 */
VSTEP(0x46a0ul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46a4;
L46a4: /* bpl $46c0 */
VSTEP(0x46a4ul);
if(!fn)goto L46c0;
goto L46a6;
L46a6: /* cmp.w $62f0.w, D1 */
VSTEP(0x46a6ul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46aa;
L46aa: /* bmi $46c0 */
VSTEP(0x46aaul);
if(fn)goto L46c0;
goto L46ac;
L46ac: /* moveq #$1, D6 */
VSTEP(0x46acul);
v=((u32)(1L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L46ae;
L46ae: /* bsr $4ccc */
VSTEP(0x46aeul);
a[7]-=4;vw32(a[7],0x46b2ul);
goto L4ccc;
L46b2: /* moveq #$a, D0 */
VSTEP(0x46b2ul);
v=((u32)(10L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L46b4;
L46b4: /* jsr $48014.l */
VSTEP(0x46b4ul);
a[7]-=4;vw32(a[7],0x46baul);
goto L48014;
L46ba: /* move.w #$4, (-$2,A6) */
VSTEP(0x46baul);
tv=((u16)(4L));
ea=(-2+a[6]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L46c0;
L46c0: /* rts  */
VSTEP(0x46c0ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L46c2: /* subq.w #3, D0 */
VSTEP(0x46c2ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L46c4;
L46c4: /* cmpi.w #-$a, D0 */
VSTEP(0x46c4ul);
tv=((u16)(-10L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L46c8;
L46c8: /* bmi $4722 */
VSTEP(0x46c8ul);
if(fn)goto L4722;
goto L46ca;
L46ca: /* subq.w #3, D1 */
VSTEP(0x46caul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L46cc;
L46cc: /* cmpi.w #$58, D1 */
VSTEP(0x46ccul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46d0;
L46d0: /* bcs $4686 */
VSTEP(0x46d0ul);
if(fc)goto L4686;
goto L46d2;
L46d2: /* bra $4722 */
VSTEP(0x46d2ul);
goto L4722;
L46d4: /* addq.w #3, D0 */
VSTEP(0x46d4ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L46d6;
L46d6: /* cmpi.w #$a8, D0 */
VSTEP(0x46d6ul);
tv=((u16)(168L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L46da;
L46da: /* bpl $4722 */
VSTEP(0x46daul);
if(!fn)goto L4722;
goto L46dc;
L46dc: /* subq.w #3, D1 */
VSTEP(0x46dcul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L46de;
L46de: /* cmpi.w #$58, D1 */
VSTEP(0x46deul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46e2;
L46e2: /* bcs $4686 */
VSTEP(0x46e2ul);
if(fc)goto L4686;
goto L46e4;
L46e4: /* bra $4722 */
VSTEP(0x46e4ul);
goto L4722;
L46e6: /* subq.w #3, D0 */
VSTEP(0x46e6ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L46e8;
L46e8: /* cmpi.w #-$a, D0 */
VSTEP(0x46e8ul);
tv=((u16)(-10L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L46ec;
L46ec: /* bmi $4722 */
VSTEP(0x46ecul);
if(fn)goto L4722;
goto L46ee;
L46ee: /* addq.w #3, D1 */
VSTEP(0x46eeul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L46f0;
L46f0: /* cmpi.w #$58, D1 */
VSTEP(0x46f0ul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46f4;
L46f4: /* bcs $4686 */
VSTEP(0x46f4ul);
if(fc)goto L4686;
goto L46f6;
L46f6: /* bra $4722 */
VSTEP(0x46f6ul);
goto L4722;
L46f8: /* addq.w #3, D0 */
VSTEP(0x46f8ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L46fa;
L46fa: /* cmpi.w #$a8, D0 */
VSTEP(0x46faul);
tv=((u16)(168L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L46fe;
L46fe: /* bpl $4722 */
VSTEP(0x46feul);
if(!fn)goto L4722;
goto L4700;
L4700: /* addq.w #3, D1 */
VSTEP(0x4700ul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L4702;
L4702: /* cmpi.w #$58, D1 */
VSTEP(0x4702ul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4706;
L4706: /* bcs $4686 */
VSTEP(0x4706ul);
if(fc)goto L4686;
goto L470a;
L470a: /* bra $4722 */
VSTEP(0x470aul);
goto L4722;
L470c: /* subq.w #5, D0 */
VSTEP(0x470cul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L470e;
L470e: /* cmpi.w #-$a, D0 */
VSTEP(0x470eul);
tv=((u16)(-10L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4712;
L4712: /* bpl $4686 */
VSTEP(0x4712ul);
if(!fn)goto L4686;
goto L4716;
L4716: /* bra $4722 */
VSTEP(0x4716ul);
goto L4722;
L4718: /* addq.w #5, D0 */
VSTEP(0x4718ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L471a;
L471a: /* cmpi.w #$a8, D0 */
VSTEP(0x471aul);
tv=((u16)(168L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L471e;
L471e: /* bmi $4686 */
VSTEP(0x471eul);
if(fn)goto L4686;
goto L4722;
L4722: /* clr.w (-$2,A6) */
VSTEP(0x4722ul);
ea=(-2+a[6]);
vw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L4726;
L4726: /* rts  */
VSTEP(0x4726ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4728: /* addq.w #4, D0 */
VSTEP(0x4728ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L472a;
L472a: /* cmpi.w #$a8, D0 */
VSTEP(0x472aul);
tv=((u16)(168L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L472e;
L472e: /* bpl $4722 */
VSTEP(0x472eul);
if(!fn)goto L4722;
goto L4730;
L4730: /* bsr $55a0 */
VSTEP(0x4730ul);
a[7]-=4;vw32(a[7],0x4734ul);
goto L55a0;
L4734: /* cmpi.b #$17, D2 */
VSTEP(0x4734ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4738;
L4738: /* movem.w D0-D1, (A6) */
VSTEP(0x4738ul);
ea=a[6];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L473c;
L473c: /* bcc $477e */
VSTEP(0x473cul);
if(!fc)goto L477e;
goto L473e;
L473e: /* bcs $4722 */
VSTEP(0x473eul);
if(fc)goto L4722;
goto L4740;
L4740: /* subq.w #4, D0 */
VSTEP(0x4740ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L4742;
L4742: /* cmpi.w #-$a, D0 */
VSTEP(0x4742ul);
tv=((u16)(-10L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4746;
L4746: /* bmi $4722 */
VSTEP(0x4746ul);
if(fn)goto L4722;
goto L4748;
L4748: /* bsr $55a0 */
VSTEP(0x4748ul);
a[7]-=4;vw32(a[7],0x474cul);
goto L55a0;
L474c: /* cmpi.b #$17, D2 */
VSTEP(0x474cul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4750;
L4750: /* movem.w D0-D1, (A6) */
VSTEP(0x4750ul);
ea=a[6];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L4754;
L4754: /* bcc $477e */
VSTEP(0x4754ul);
if(!fc)goto L477e;
goto L4756;
L4756: /* bra $4722 */
VSTEP(0x4756ul);
goto L4722;
L4758: /* move.w $6318.w, D0 */
VSTEP(0x4758ul);
ea=0x6318ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L475c;
L475c: /* beq $4722 */
VSTEP(0x475cul);
if(fz)goto L4722;
goto L475e;
L475e: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x475eul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L4764;
L4764: /* add.w $631a.w, D0 */
VSTEP(0x4764ul);
ea=0x631aul;
tv=(((u16)vm_vars[60]<<8)|((u16)vm_vars[61]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4768;
L4768: /* sub.w $631c.w, D1 */
VSTEP(0x4768ul);
ea=0x631cul;
tv=(((u16)vm_vars[62]<<8)|((u16)vm_vars[63]<<0));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L476c;
L476c: /* subi.w #$c, D1 */
VSTEP(0x476cul);
tv=((u16)(12L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4770;
L4770: /* addq.w #5, D0 */
VSTEP(0x4770ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4772;
L4772: /* tst.w $62ee.w */
VSTEP(0x4772ul);
ea=0x62eeul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
fn=(u8)((tv&0x8000ul)!=0);
goto L4776;
L4776: /* bpl $477a */
VSTEP(0x4776ul);
if(!fn)goto L477a;
goto L4778;
L4778: /* subq.w #7, D0 */
VSTEP(0x4778ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L477a;
L477a: /* movem.w D0-D1, (A6) */
VSTEP(0x477aul);
ea=a[6];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L477e;
L477e: /* lea $3a8e.w, A4 */
VSTEP(0x477eul);
a[4]=0x3a8eul;
goto L4782;
L4782: /* moveq #$9, D6 */
VSTEP(0x4782ul);
v=((u32)(9L));
d[6]=v;

goto L4784;
L4784: /* move.w (A4), D2 */
VSTEP(0x4784ul);
ea=a[4];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4786;
L4786: /* subq.w #2, D2 */
VSTEP(0x4786ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4788;
L4788: /* bmi $47a4 */
VSTEP(0x4788ul);
if(fn)goto L47a4;
goto L478a;
L478a: /* move.w ($e,A4), D2 */
VSTEP(0x478aul);
ea=(14+a[4]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L478e;
L478e: /* sub.w D0, D2 */
VSTEP(0x478eul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4790;
L4790: /* addq.w #4, D2 */
VSTEP(0x4790ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4792;
L4792: /* cmpi.w #$8, D2 */
VSTEP(0x4792ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4796;
L4796: /* bcc $47a4 */
VSTEP(0x4796ul);
if(!fc)goto L47a4;
goto L4798;
L4798: /* cmp.w ($10,A4), D1 */
VSTEP(0x4798ul);
ea=(16+a[4]);
tv=vr16(ea);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L479c;
L479c: /* bpl $47a4 */
VSTEP(0x479cul);
if(!fn)goto L47a4;
goto L479e;
L479e: /* cmp.w ($12,A4), D1 */
VSTEP(0x479eul);
ea=(18+a[4]);
tv=vr16(ea);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L47a2;
L47a2: /* bpl $47ae */
VSTEP(0x47a2ul);
if(!fn)goto L47ae;
goto L47a4;
L47a4: /* lea (-$16,A4), A4 */
VSTEP(0x47a4ul);
a[4]=(-22+a[4]);
goto L47a8;
L47a8: /* dbra D6, $4784 */
VSTEP(0x47a8ul);
VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L4784;
goto L47ac;
L47ac: /* rts  */
VSTEP(0x47acul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L47ae: /* move.w #$1, (A4) */
VSTEP(0x47aeul);
tv=((u16)(1L));
ea=a[4];
vw16(ea,tv);

goto L47b2;
L47b2: /* move.w #$fffc, ($a,A4) */
VSTEP(0x47b2ul);
tv=((u16)(65532L));
ea=(10+a[4]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L47b8;
L47b8: /* bsr $4722 */
VSTEP(0x47b8ul);
a[7]-=4;vw32(a[7],0x47bcul);
goto L4722;
L47bc: /* moveq #$a, D0 */
VSTEP(0x47bcul);
v=((u32)(10L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L47be;
L47be: /* jmp $48014.l */
VSTEP(0x47beul);
goto L48014;
L47c4: /* addq.w #2, D0 */
VSTEP(0x47c4ul);
tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L47c6;
L47c6: /* move.w ($4,A6), D2 */
VSTEP(0x47c6ul);
ea=(4+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L47ca;
L47ca: /* cmpi.w #$28, D2 */
VSTEP(0x47caul);
tv=((u16)(40L));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L47ce;
L47ce: /* bpl $47d4 */
VSTEP(0x47ceul);
if(!fn)goto L47d4;
goto L47d0;
L47d0: /* addq.w #1, ($4,A6) */
VSTEP(0x47d0ul);
tv=((u16)(1L));
eb=(4+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L47d4;
L47d4: /* asr.w #2, D2 */
VSTEP(0x47d4ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((s16)tw)>>2;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L47d6;
L47d6: /* bpl $47da */
VSTEP(0x47d6ul);
if(!fn)goto L47da;
goto L47d8;
L47d8: /* addq.w #1, D2 */
VSTEP(0x47d8ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L47da;
L47da: /* add.w D2, D1 */
VSTEP(0x47daul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L47dc;
L47dc: /* cmpi.w #$60, D1 */
VSTEP(0x47dcul);
tv=((u16)(96L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L47e0;
L47e0: /* bpl $4722 */
VSTEP(0x47e0ul);
if(!fn)goto L4722;
goto L47e4;
L47e4: /* movem.w D0-D1, (A6) */
VSTEP(0x47e4ul);
ea=a[6];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L47e8;
L47e8: /* bsr $55a0 */
VSTEP(0x47e8ul);
a[7]-=4;vw32(a[7],0x47ecul);
goto L55a0;
L47ec: /* cmpi.b #$17, D2 */
VSTEP(0x47ecul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L47f0;
L47f0: /* bcs $4814 */
VSTEP(0x47f0ul);
if(fc)goto L4814;
goto L47f2;
L47f2: /* sub.w $67c2.w, D0 */
VSTEP(0x47f2ul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L47f6;
L47f6: /* addq.w #3, D0 */
VSTEP(0x47f6ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L47f8;
L47f8: /* cmpi.w #$7, D0 */
VSTEP(0x47f8ul);
tv=((u16)(7L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L47fc;
L47fc: /* bcc $4820 */
VSTEP(0x47fcul);
if(!fc)goto L4820;
goto L47fe;
L47fe: /* cmp.w $67c4.w, D1 */
VSTEP(0x47feul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4802;
L4802: /* bpl $4820 */
VSTEP(0x4802ul);
if(!fn)goto L4820;
goto L4804;
L4804: /* cmp.w $62f0.w, D1 */
VSTEP(0x4804ul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4808;
L4808: /* bmi $4820 */
VSTEP(0x4808ul);
if(fn)goto L4820;
goto L480a;
L480a: /* moveq #$6, D6 */
VSTEP(0x480aul);
v=((u32)(6L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L480c;
L480c: /* bsr $4ccc */
VSTEP(0x480cul);
a[7]-=4;vw32(a[7],0x4810ul);
goto L4ccc;
L4810: /* movem.w (A6), D0-D1 */
VSTEP(0x4810ul);
ea=a[6];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
goto L4814;
L4814: /* move.w #$e, (-$2,A6) */
VSTEP(0x4814ul);
tv=((u16)(14L));
ea=(-2+a[6]);
vw16(ea,tv);

goto L481a;
L481a: /* moveq #$d, D2 */
VSTEP(0x481aul);
v=((u32)(13L));
d[2]=v;

goto L481c;
L481c: /* bra $44b6 */
VSTEP(0x481cul);
goto L44b6;
L4820: /* rts  */
VSTEP(0x4820ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4822: /* subq.w #2, D0 */
VSTEP(0x4822ul);
tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4824;
L4824: /* move.w ($4,A6), D2 */
VSTEP(0x4824ul);
ea=(4+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4828;
L4828: /* cmpi.w #$28, D2 */
VSTEP(0x4828ul);
tv=((u16)(40L));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L482c;
L482c: /* bpl $4832 */
VSTEP(0x482cul);
if(!fn)goto L4832;
goto L482e;
L482e: /* addq.w #1, ($4,A6) */
VSTEP(0x482eul);
tv=((u16)(1L));
eb=(4+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L4832;
L4832: /* asr.w #2, D2 */
VSTEP(0x4832ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((s16)tw)>>2;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4834;
L4834: /* bpl $4838 */
VSTEP(0x4834ul);
if(!fn)goto L4838;
goto L4836;
L4836: /* addq.w #1, D2 */
VSTEP(0x4836ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4838;
L4838: /* add.w D2, D1 */
VSTEP(0x4838ul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L483a;
L483a: /* cmpi.w #$60, D1 */
VSTEP(0x483aul);
tv=((u16)(96L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L483e;
L483e: /* bpl $4722 */
VSTEP(0x483eul);
if(!fn)goto L4722;
goto L4842;
L4842: /* bra $47e4 */
VSTEP(0x4842ul);
goto L47e4;
L4844: /* movem.w D0-D1, (A6) */
VSTEP(0x4844ul);
ea=a[6];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L4848;
L4848: /* btst #$0, $632d.w */
VSTEP(0x4848ul);
v=((u16)(0L));
eb=0x632dul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L484e;
L484e: /* bne $4864 */
VSTEP(0x484eul);
if(!fz)goto L4864;
goto L4850;
L4850: /* move.w (-$2,A6), D2 */
VSTEP(0x4850ul);
ea=(-2+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4854;
L4854: /* addq.w #1, D2 */
VSTEP(0x4854ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4856;
L4856: /* cmpi.w #$18, D2 */
VSTEP(0x4856ul);
tv=((u16)(24L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L485a;
L485a: /* bne $4860 */
VSTEP(0x485aul);
if(!fz)goto L4860;
goto L485e;
L485e: /* clr.w D2 */
VSTEP(0x485eul);
VWORD(d[2])=(u16)(0);

goto L4860;
L4860: /* move.w D2, (-$2,A6) */
VSTEP(0x4860ul);
tv=((u16)d[2]);
ea=(-2+a[6]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4864;
L4864: /* rts  */
VSTEP(0x4864ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4936: /* movem.w $67c4.w, D1-D2 */
VSTEP(0x4936ul);
ea=0x67c4ul;
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1256u));
goto L493c;
L493c: /* move.w D1, D0 */
VSTEP(0x493cul);
tv=((u16)d[1]);
VWORD(d[0])=(u16)(tv);

goto L493e;
L493e: /* sub.w D2, D0 */
VSTEP(0x493eul);
tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4940;
L4940: /* move.w $6310.w, $4934.w */
VSTEP(0x4940ul);
ea=0x6310ul;
tv=(((u16)vm_vars[50]<<8)|((u16)vm_vars[51]<<0));
ea=0x4934ul;
vw16(ea,tv);

goto L4946;
L4946: /* move.w D0, $6310.w */
VSTEP(0x4946ul);
tv=((u16)d[0]);
vm_vars[50]=(u8)((u32)(tv)>>8);
vm_vars[51]=(u8)((u32)(tv)>>0);
fz=(u8)((tv&0xfffful)==0);
goto L494a;
L494a: /* beq $49ec */
VSTEP(0x494aul);
if(fz)goto L49ec;
goto L494e;
L494e: /* tst.w $62fa.w */
VSTEP(0x494eul);
ea=0x62faul;
tv=(((u16)vm_vars[28]<<8)|((u16)vm_vars[29]<<0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L4952;
L4952: /* bmi $496c */
VSTEP(0x4952ul);
if(fn)goto L496c;
goto L4954;
L4954: /* beq $4980 */
VSTEP(0x4954ul);
if(fz)goto L4980;
goto L4956;
L4956: /* cmpi.w #$4, D0 */
VSTEP(0x4956ul);
tv=((u16)(4L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L495a;
L495a: /* bcs $4980 */
VSTEP(0x495aul);
if(fc)goto L4980;
goto L495c;
L495c: /* cmpi.w #-$3, D0 */
VSTEP(0x495cul);
tv=((u16)(-3L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4960;
L4960: /* bcc $4980 */
VSTEP(0x4960ul);
if(!fc)goto L4980;
goto L4962;
L4962: /* bpl $4968 */
VSTEP(0x4962ul);
if(!fn)goto L4968;
goto L4964;
L4964: /* moveq #-$2, D0 */
VSTEP(0x4964ul);
v=((u32)(-2L));
d[0]=v;

goto L4966;
L4966: /* bra $4980 */
VSTEP(0x4966ul);
goto L4980;
L4968: /* moveq #$2, D0 */
VSTEP(0x4968ul);
v=((u32)(2L));
d[0]=v;

goto L496a;
L496a: /* bra $4980 */
VSTEP(0x496aul);
goto L4980;
L496c: /* cmpi.w #$8, D0 */
VSTEP(0x496cul);
tv=((u16)(8L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L4970;
L4970: /* bcs $4980 */
VSTEP(0x4970ul);
if(fc)goto L4980;
goto L4972;
L4972: /* cmpi.w #-$3, D0 */
VSTEP(0x4972ul);
tv=((u16)(-3L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4976;
L4976: /* bcc $4980 */
VSTEP(0x4976ul);
if(!fc)goto L4980;
goto L4978;
L4978: /* bmi $497e */
VSTEP(0x4978ul);
if(fn)goto L497e;
goto L497a;
L497a: /* moveq #$7, D0 */
VSTEP(0x497aul);
v=((u32)(7L));
d[0]=v;

goto L497c;
L497c: /* bra $4980 */
VSTEP(0x497cul);
goto L4980;
L497e: /* moveq #-$3, D0 */
VSTEP(0x497eul);
v=((u32)(-3L));
d[0]=v;

goto L4980;
L4980: /* move.w $67be.w, D1 */
VSTEP(0x4980ul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
VWORD(d[1])=(u16)(tv);

goto L4984;
L4984: /* move.w D1, D3 */
VSTEP(0x4984ul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L4986;
L4986: /* add.w D0, D1 */
VSTEP(0x4986ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4988;
L4988: /* cmpi.w #$f1, D1 */
VSTEP(0x4988ul);
tv=((u16)(241L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L498c;
L498c: /* bcs $49a0 */
VSTEP(0x498cul);
if(fc)goto L49a0;
goto L498e;
L498e: /* bmi $499c */
VSTEP(0x498eul);
if(fn)goto L499c;
goto L4990;
L4990: /* move.w #$f0, D2 */
VSTEP(0x4990ul);
tv=((u16)(240L));
VWORD(d[2])=(u16)(tv);

goto L4994;
L4994: /* sub.w D2, D1 */
VSTEP(0x4994ul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4996;
L4996: /* sub.w D1, D0 */
VSTEP(0x4996ul);
tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4998;
L4998: /* move.w D2, D1 */
VSTEP(0x4998ul);
tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L499a;
L499a: /* bra $49a0 */
VSTEP(0x499aul);
goto L49a0;
L499c: /* sub.w D1, D0 */
VSTEP(0x499cul);
tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L499e;
L499e: /* clr.w D1 */
VSTEP(0x499eul);
VWORD(d[1])=(u16)(0);

goto L49a0;
L49a0: /* sub.w D0, $67c4.w */
VSTEP(0x49a0ul);
tv=((u16)d[0]);
eb=0x67c4ul;
tw=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tr=tw-tv;
vm_vars[1254]=(u8)((u32)(tr)>>8);
vm_vars[1255]=(u8)((u32)(tr)>>0);
goto L49a4;
L49a4: /* move.w D1, $67be.w */
VSTEP(0x49a4ul);
tv=((u16)d[1]);
vm_vars[1248]=(u8)((u32)(tv)>>8);
vm_vars[1249]=(u8)((u32)(tv)>>0);

goto L49a8;
L49a8: /* sub.w D3, D1 */
VSTEP(0x49a8ul);
tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L49aa;
L49aa: /* move.w D1, $6310.w */
VSTEP(0x49aaul);
tv=((u16)d[1]);
vm_vars[50]=(u8)((u32)(tv)>>8);
vm_vars[51]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L49ae;
L49ae: /* beq $49ec */
VSTEP(0x49aeul);
if(fz)goto L49ec;
goto L49b0;
L49b0: /* bmi $49d4 */
VSTEP(0x49b0ul);
if(fn)goto L49d4;
goto L49b2;
L49b2: /* addi.w #$57, D3 */
VSTEP(0x49b2ul);
tv=((u16)(87L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L49b6;
L49b6: /* move.w $6312.w, D2 */
VSTEP(0x49b6ul);
ea=0x6312ul;
tv=(((u16)vm_vars[52]<<8)|((u16)vm_vars[53]<<0));
VWORD(d[2])=(u16)(tv);

goto L49ba;
L49ba: /* move.w D1, D4 */
VSTEP(0x49baul);
tv=((u16)d[1]);
VWORD(d[4])=(u16)(tv);

goto L49bc;
L49bc: /* add.w D2, D4 */
VSTEP(0x49bcul);
tv=((u16)d[2]);
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L49be;
L49be: /* cmpi.w #$57, D4 */
VSTEP(0x49beul);
tv=((u16)(87L));
tw=((u16)d[4]);
fc=(u8)((u16)tw<(u16)tv);
goto L49c2;
L49c2: /* bcs $49c8 */
VSTEP(0x49c2ul);
if(fc)goto L49c8;
goto L49c4;
L49c4: /* subi.w #$57, D4 */
VSTEP(0x49c4ul);
tv=((u16)(87L));
tw=((u16)d[4]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[4])=(u16)(tr);
goto L49c8;
L49c8: /* move.w D4, $6312.w */
VSTEP(0x49c8ul);
tv=((u16)d[4]);
vm_vars[52]=(u8)((u32)(tv)>>8);
vm_vars[53]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L49cc;
L49cc: /* bsr $4a5e */
VSTEP(0x49ccul);
a[7]-=4;vw32(a[7],0x49d0ul);
goto L4a5e;
L49d0: /* bra $49ec */
VSTEP(0x49d0ul);
goto L49ec;
L49d4: /* move.w $6312.w, D2 */
VSTEP(0x49d4ul);
ea=0x6312ul;
tv=(((u16)vm_vars[52]<<8)|((u16)vm_vars[53]<<0));
VWORD(d[2])=(u16)(tv);

goto L49d8;
L49d8: /* add.w D1, D2 */
VSTEP(0x49d8ul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L49da;
L49da: /* bpl $49e0 */
VSTEP(0x49daul);
if(!fn)goto L49e0;
goto L49dc;
L49dc: /* addi.w #$57, D2 */
VSTEP(0x49dcul);
tv=((u16)(87L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L49e0;
L49e0: /* move.w D2, $6312.w */
VSTEP(0x49e0ul);
tv=((u16)d[2]);
vm_vars[52]=(u8)((u32)(tv)>>8);
vm_vars[53]=(u8)((u32)(tv)>>0);

goto L49e4;
L49e4: /* add.w D1, D3 */
VSTEP(0x49e4ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L49e6;
L49e6: /* neg.w D1 */
VSTEP(0x49e6ul);
tv=((u16)d[1]);
tr=0-tv;fc=(u8)(tv>0);fx=(u8)(tv>0);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((0^tv)&(0^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L49e8;
L49e8: /* bsr $4a5e */
VSTEP(0x49e8ul);
a[7]-=4;vw32(a[7],0x49ecul);
goto L4a5e;
L49ec: /* move.w $67c2.w, D0 */
VSTEP(0x49ecul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
VWORD(d[0])=(u16)(tv);

goto L49f0;
L49f0: /* sub.w $67c8.w, D0 */
VSTEP(0x49f0ul);
ea=0x67c8ul;
tv=(((u16)vm_vars[1258]<<8)|((u16)vm_vars[1259]<<0));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L49f4;
L49f4: /* move.w D0, $630e.w */
VSTEP(0x49f4ul);
tv=((u16)d[0]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L49f8;
L49f8: /* beq $4a5c */
VSTEP(0x49f8ul);
if(fz)goto L4a5c;
goto L49fc;
L49fc: /* move.w $67bc.w, D1 */
VSTEP(0x49fcul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
VWORD(d[1])=(u16)(tv);

goto L4a00;
L4a00: /* move.w D1, D2 */
VSTEP(0x4a00ul);
tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L4a02;
L4a02: /* add.w D0, D1 */
VSTEP(0x4a02ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4a04;
L4a04: /* bpl $4a0c */
VSTEP(0x4a04ul);
if(!fn)goto L4a0c;
goto L4a06;
L4a06: /* move.w D1, D0 */
VSTEP(0x4a06ul);
tv=((u16)d[1]);
VWORD(d[0])=(u16)(tv);

goto L4a08;
L4a08: /* clr.w D1 */
VSTEP(0x4a08ul);
VWORD(d[1])=(u16)(0);

goto L4a0a;
L4a0a: /* bra $4a1c */
VSTEP(0x4a0aul);
goto L4a1c;
L4a0c: /* clr.w D0 */
VSTEP(0x4a0cul);
VWORD(d[0])=(u16)(0);

goto L4a0e;
L4a0e: /* cmpi.w #$540, D1 */
VSTEP(0x4a0eul);
tv=((u16)(1344L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);
goto L4a12;
L4a12: /* bls $4a1c */
VSTEP(0x4a12ul);
if((fc||fz))goto L4a1c;
goto L4a14;
L4a14: /* move.w #$540, D0 */
VSTEP(0x4a14ul);
tv=((u16)(1344L));
VWORD(d[0])=(u16)(tv);

goto L4a18;
L4a18: /* sub.w D0, D1 */
VSTEP(0x4a18ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4a1a;
L4a1a: /* exg D1, D0 */
VSTEP(0x4a1aul);
r=d[1];d[1]=d[0];d[0]=r;
goto L4a1c;
L4a1c: /* add.w $67c8.w, D0 */
VSTEP(0x4a1cul);
ea=0x67c8ul;
tv=(((u16)vm_vars[1258]<<8)|((u16)vm_vars[1259]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4a20;
L4a20: /* move.w D0, $67c2.w */
VSTEP(0x4a20ul);
tv=((u16)d[0]);
vm_vars[1252]=(u8)((u32)(tv)>>8);
vm_vars[1253]=(u8)((u32)(tv)>>0);

goto L4a24;
L4a24: /* move.w D1, $67bc.w */
VSTEP(0x4a24ul);
tv=((u16)d[1]);
vm_vars[1246]=(u8)((u32)(tv)>>8);
vm_vars[1247]=(u8)((u32)(tv)>>0);

goto L4a28;
L4a28: /* move.w D1, D3 */
VSTEP(0x4a28ul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L4a2a;
L4a2a: /* sub.w D2, D3 */
VSTEP(0x4a2aul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L4a2c;
L4a2c: /* move.w D3, $630e.w */
VSTEP(0x4a2cul);
tv=((u16)d[3]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4a30;
L4a30: /* beq $4a5c */
VSTEP(0x4a30ul);
if(fz)goto L4a5c;
goto L4a32;
L4a32: /* eor.w D1, D2 */
VSTEP(0x4a32ul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw^tv;
fn=(u8)((tr&0x8000ul)!=0);fv=0;fc=0;
VWORD(d[2])=(u16)(tr);
goto L4a34;
L4a34: /* btst #$3, D2 */
VSTEP(0x4a34ul);
v=((u16)(3L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4a38;
L4a38: /* beq $4a5c */
VSTEP(0x4a38ul);
if(fz)goto L4a5c;
goto L4a3a;
L4a3a: /* movea.l $631e.w, A4 */
VSTEP(0x4a3aul);
ea=0x631eul;
v=(((u32)vm_vars[64]<<24)|((u32)vm_vars[65]<<16)|((u32)vm_vars[66]<<8)|((u32)vm_vars[67]<<0));
a[4]=v;
goto L4a3e;
L4a3e: /* tst.w D3 */
VSTEP(0x4a3eul);
tv=((u16)d[3]);
fn=(u8)((tv&0x8000ul)!=0);
goto L4a40;
L4a40: /* bmi $4a52 */
VSTEP(0x4a40ul);
if(fn)goto L4a52;
goto L4a42;
L4a42: /* addi.w #$a0, D1 */
VSTEP(0x4a42ul);
tv=((u16)(160L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L4a46;
L4a46: /* addq.w #2, A4 */
VSTEP(0x4a46ul);
v=((u16)(2L));
w=((u32)a[4]);
r=w+v;
a[4]=r;
goto L4a48;
L4a48: /* move.l A4, $631e.w */
VSTEP(0x4a48ul);
v=((u32)a[4]);
vm_vars[64]=(u8)((u32)(v)>>24);
vm_vars[65]=(u8)((u32)(v)>>16);
vm_vars[66]=(u8)((u32)(v)>>8);
vm_vars[67]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4a4c;
L4a4c: /* lea ($28,A4), A4 */
VSTEP(0x4a4cul);
a[4]=(40+a[4]);
goto L4a50;
L4a50: /* bra $4a58 */
VSTEP(0x4a50ul);
goto L4a58;
L4a52: /* subq.w #2, A4 */
VSTEP(0x4a52ul);
v=((u16)(2L));
w=((u32)a[4]);
r=w-v;
a[4]=r;
goto L4a54;
L4a54: /* move.l A4, $631e.w */
VSTEP(0x4a54ul);
v=((u32)a[4]);
vm_vars[64]=(u8)((u32)(v)>>24);
vm_vars[65]=(u8)((u32)(v)>>16);
vm_vars[66]=(u8)((u32)(v)>>8);
vm_vars[67]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4a58;
L4a58: /* bsr $4ad6 */
VSTEP(0x4a58ul);
a[7]-=4;vw32(a[7],0x4a5cul);
goto L4ad6;
L4a5c: /* rts  */
VSTEP(0x4a5cul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4c3e: /* clr.w D2 */
VSTEP(0x4c3eul);
VWORD(d[2])=(u16)(0);

goto L4c40;
L4c40: /* move.b $6308.w, D2 */
VSTEP(0x4c40ul);
ea=0x6308ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[2])=(u8)(tv);

goto L4c44;
L4c44: /* asl.w #2, D2 */
VSTEP(0x4c44ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw<<2;fc=(u8)((tw>>14)&1);fx=(u8)((tw>>14)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((((tw<<2)^tw)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4c46;
L4c46: /* movea.l ($4,PC,D2.w), A0 */
VSTEP(0x4c46ul);
ea=(4+0x4c48ul+((s16)(d[2])));
v=vr32(ea);
a[0]=v;
goto L4c4a;
L4c4a: /* jmp (A0) */
VSTEP(0x4c4aul);
pc=a[0];goto dispatch;
L4ccc: /* tst.b $7c874.l */
VSTEP(0x4cccul);
ea=0x7c874ul;
tv=vr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4cd2;
L4cd2: /* bne $4d36 */
VSTEP(0x4cd2ul);
if(!fz)goto L4d36;
goto L4cd4;
L4cd4: /* movem.l D0-D7/A5-A6, -(A7) */
VSTEP(0x4cd4ul);
a[7]-=4;
vw32(a[7],a[6]);
a[7]-=4;
vw32(a[7],a[5]);
a[7]-=4;
vw32(a[7],d[7]);
a[7]-=4;
vw32(a[7],d[6]);
a[7]-=4;
vw32(a[7],d[5]);
a[7]-=4;
vw32(a[7],d[4]);
a[7]-=4;
vw32(a[7],d[3]);
a[7]-=4;
vw32(a[7],d[2]);
a[7]-=4;
vw32(a[7],d[1]);
a[7]-=4;
vw32(a[7],d[0]);
goto L4cd8;
L4cd8: /* move.w D6, D0 */
VSTEP(0x4cd8ul);
tv=((u16)d[6]);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4cda;
L4cda: /* jsr $7c870.l */
VSTEP(0x4cdaul);
a[7]-=4;vw32(a[7],0x4ce0ul);
goto L7c870;
L4ce0: /* movem.l (A7)+, D0-D7/A5-A6 */
VSTEP(0x4ce0ul);
ea=a[7];
d[0]=vr32(ea+0);
d[1]=vr32(ea+4);
d[2]=vr32(ea+8);
d[3]=vr32(ea+12);
d[4]=vr32(ea+16);
d[5]=vr32(ea+20);
d[6]=vr32(ea+24);
d[7]=vr32(ea+28);
a[5]=vr32(ea+32);
a[6]=vr32(ea+36);
a[7]+=40;
goto L4ce4;
L4ce4: /* move.w $3c92.w, D2 */
VSTEP(0x4ce4ul);
ea=0x3c92ul;
tv=vm_player_state;
VWORD(d[2])=(u16)(tv);

goto L4ce8;
L4ce8: /* cmpi.w #$5482, D2 */
VSTEP(0x4ce8ul);
tv=((u16)(21634L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4cec;
L4cec: /* beq $4d36 */
VSTEP(0x4cecul);
if(fz)goto L4d36;
goto L4cee;
L4cee: /* move.w #$4e3a, D3 */
VSTEP(0x4ceeul);
tv=((u16)(20026L));
VWORD(d[3])=(u16)(tv);

goto L4cf2;
L4cf2: /* cmp.w D3, D2 */
VSTEP(0x4cf2ul);
tv=((u16)d[3]);
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4cf4;
L4cf4: /* beq $4d1c */
VSTEP(0x4cf4ul);
if(fz)goto L4d1c;
goto L4cf6;
L4cf6: /* cmpi.w #$4e64, D2 */
VSTEP(0x4cf6ul);
tv=((u16)(20068L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4cfa;
L4cfa: /* beq $4d1c */
VSTEP(0x4cfaul);
if(fz)goto L4d1c;
goto L4cfc;
L4cfc: /* cmpi.w #$5058, D2 */
VSTEP(0x4cfcul);
tv=((u16)(20568L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4d00;
L4d00: /* beq $4d38 */
VSTEP(0x4d00ul);
if(fz)goto L4d38;
goto L4d02;
L4d02: /* move.w #$4d48, D3 */
VSTEP(0x4d02ul);
tv=((u16)(19784L));
VWORD(d[3])=(u16)(tv);

goto L4d06;
L4d06: /* cmpi.w #$5308, D2 */
VSTEP(0x4d06ul);
tv=((u16)(21256L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4d0a;
L4d0a: /* beq $4d1c */
VSTEP(0x4d0aul);
if(fz)goto L4d1c;
goto L4d0c;
L4d0c: /* cmp.w D2, D3 */
VSTEP(0x4d0cul);
tv=((u16)d[2]);
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4d0e;
L4d0e: /* beq $4d1c */
VSTEP(0x4d0eul);
if(fz)goto L4d1c;
goto L4d10;
L4d10: /* lea $5457.w, A0 */
VSTEP(0x4d10ul);
a[0]=0x5457ul;
goto L4d14;
L4d14: /* bsr $5438 */
VSTEP(0x4d14ul);
a[7]-=4;vw32(a[7],0x4d18ul);
goto L5438;
L4d18: /* move.w #$4d56, D3 */
VSTEP(0x4d18ul);
tv=((u16)(19798L));
VWORD(d[3])=(u16)(tv);

goto L4d1c;
L4d1c: /* move.w D3, $3c92.w */
VSTEP(0x4d1cul);
tv=((u16)d[3]);
vm_player_state=(u16)(tv);

goto L4d20;
L4d20: /* move.w $6306.w, D2 */
VSTEP(0x4d20ul);
ea=0x6306ul;
tv=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
VWORD(d[2])=(u16)(tv);

goto L4d24;
L4d24: /* add.w D6, D6 */
VSTEP(0x4d24ul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;
VWORD(d[6])=(u16)(tr);
goto L4d26;
L4d26: /* add.w D6, D6 */
VSTEP(0x4d26ul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;
VWORD(d[6])=(u16)(tr);
goto L4d28;
L4d28: /* add.w D6, D2 */
VSTEP(0x4d28ul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4d2a;
L4d2a: /* cmpi.w #$c, D2 */
VSTEP(0x4d2aul);
tv=((u16)(12L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4d2e;
L4d2e: /* bcs $4d32 */
VSTEP(0x4d2eul);
if(fc)goto L4d32;
goto L4d30;
L4d30: /* moveq #$c, D2 */
VSTEP(0x4d30ul);
v=((u32)(12L));
d[2]=v;

goto L4d32;
L4d32: /* move.w D2, $6306.w */
VSTEP(0x4d32ul);
tv=((u16)d[2]);
vm_vars[40]=(u8)((u32)(tv)>>8);
vm_vars[41]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d36;
L4d36: /* rts  */
VSTEP(0x4d36ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4d38: /* move.w $62f2.w, D2 */
VSTEP(0x4d38ul);
ea=0x62f2ul;
tv=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
VWORD(d[2])=(u16)(tv);

goto L4d3c;
L4d3c: /* add.w D6, D2 */
VSTEP(0x4d3cul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4d3e;
L4d3e: /* add.w D6, D2 */
VSTEP(0x4d3eul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4d40;
L4d40: /* add.w D6, D2 */
VSTEP(0x4d40ul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4d42;
L4d42: /* move.w D2, $62f2.w */
VSTEP(0x4d42ul);
tv=((u16)d[2]);
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d46;
L4d46: /* rts  */
VSTEP(0x4d46ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4d48: /* subq.w #1, $6306.w */
VSTEP(0x4d48ul);
tv=((u16)(1L));
eb=0x6306ul;
tw=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[40]=(u8)((u32)(tr)>>8);
vm_vars[41]=(u8)((u32)(tr)>>0);
goto L4d4c;
L4d4c: /* bne $4d36 */
VSTEP(0x4d4cul);
if(!fz)goto L4d36;
goto L4d4e;
L4d4e: /* move.w #$5308, $3c92.w */
VSTEP(0x4d4eul);
tv=((u16)(21256L));
vm_player_state=(u16)(tv);

goto L4d54;
L4d54: /* bra $4d7a */
VSTEP(0x4d54ul);
goto L4d7a;
L4d56: /* tst.w $6318.w */
VSTEP(0x4d56ul);
ea=0x6318ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d5a;
L4d5a: /* beq $4d60 */
VSTEP(0x4d5aul);
if(fz)goto L4d60;
goto L4d5c;
L4d5c: /* bsr $51b0 */
VSTEP(0x4d5cul);
a[7]-=4;vw32(a[7],0x4d60ul);
goto L51b0;
L4d60: /* subq.w #1, $6306.w */
VSTEP(0x4d60ul);
tv=((u16)(1L));
eb=0x6306ul;
tw=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[40]=(u8)((u32)(tr)>>8);
vm_vars[41]=(u8)((u32)(tr)>>0);
goto L4d64;
L4d64: /* bne $4d36 */
VSTEP(0x4d64ul);
if(!fz)goto L4d36;
goto L4d66;
L4d66: /* move.w #$4c3e, $3c92.w */
VSTEP(0x4d66ul);
tv=((u16)(19518L));
vm_player_state=(u16)(tv);

goto L4d6c;
L4d6c: /* tst.w $6318.w */
VSTEP(0x4d6cul);
ea=0x6318ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d70;
L4d70: /* beq $4d76 */
VSTEP(0x4d70ul);
if(fz)goto L4d76;
goto L4d72;
L4d72: /* bsr $51a8 */
VSTEP(0x4d72ul);
a[7]-=4;vw32(a[7],0x4d76ul);
goto L51a8;
L4d76: /* bsr $5430 */
VSTEP(0x4d76ul);
a[7]-=4;vw32(a[7],0x4d7aul);
goto L5430;
L4d7a: /* tst.b $7c874.l */
VSTEP(0x4d7aul);
ea=0x7c874ul;
tv=vr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4d80;
L4d80: /* beq $4d36 */
VSTEP(0x4d80ul);
if(fz)goto L4d36;
goto L4d82;
L4d82: /* jsr $48004.l */
VSTEP(0x4d82ul);
a[7]-=4;vw32(a[7],0x4d88ul);
goto L48004;
L4d88: /* clr.w $6318.w */
VSTEP(0x4d88ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L4d8c;
L4d8c: /* moveq #$3, D0 */
VSTEP(0x4d8cul);
v=((u32)(3L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4d8e;
L4d8e: /* jsr $48010.l */
VSTEP(0x4d8eul);
a[7]-=4;vw32(a[7],0x4d94ul);
goto L48010;
L4d94: /* move.w #$4da2, $3c92.w */
VSTEP(0x4d94ul);
tv=((u16)(19874L));
vm_player_state=(u16)(tv);

goto L4d9a;
L4d9a: /* move.w #$63dc, $6326.w */
VSTEP(0x4d9aul);
tv=((u16)(25564L));
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4da0;
L4da0: /* rts  */
VSTEP(0x4da0ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4da2: /* movea.w $6326.w, A0 */
VSTEP(0x4da2ul);
ea=0x6326ul;
v=(((u16)vm_vars[72]<<8)|((u16)vm_vars[73]<<0));
a[0]=(s16)v;
goto L4da6;
L4da6: /* bsr $5438 */
VSTEP(0x4da6ul);
a[7]-=4;vw32(a[7],0x4daaul);
goto L5438;
L4daa: /* move.w A0, $6326.w */
VSTEP(0x4daaul);
tv=((u16)a[0]);
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L4dae;
L4dae: /* tst.b (A0) */
VSTEP(0x4daeul);
ea=a[0];
tv=vr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4db0;
L4db0: /* bne $4d36 */
VSTEP(0x4db0ul);
if(!fz)goto L4d36;
goto L4db2;
L4e3a: /* moveq #$10, D3 */
VSTEP(0x4e3aul);
v=((u32)(16L));
d[3]=v;

goto L4e3c;
L4e3c: /* tst.b $7c874.l */
VSTEP(0x4e3cul);
ea=0x7c874ul;
tv=vr8(ea);
fz=(u8)((tv&0xfful)==0);
goto L4e42;
L4e42: /* bne $4e60 */
VSTEP(0x4e42ul);
if(!fz)goto L4e60;
goto L4e44;
L4e44: /* lea $6318.w, A0 */
VSTEP(0x4e44ul);
a[0]=0x6318ul;
goto L4e48;
L4e48: /* move.w (A0), D2 */
VSTEP(0x4e48ul);
ea=a[0];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4e4a;
L4e4a: /* cmpi.w #$50, D2 */
VSTEP(0x4e4aul);
tv=((u16)(80L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4e4e;
L4e4e: /* bcc $4e60 */
VSTEP(0x4e4eul);
if(!fc)goto L4e60;
goto L4e50;
L4e50: /* addq.w #1, (A0) */
VSTEP(0x4e50ul);
tv=((u16)(1L));
eb=a[0];
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L4e52;
L4e52: /* clr.w D3 */
VSTEP(0x4e52ul);
VWORD(d[3])=(u16)(0);

goto L4e54;
L4e54: /* subq.w #1, $6306.w */
VSTEP(0x4e54ul);
tv=((u16)(1L));
eb=0x6306ul;
tw=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
tr=tw-tv;fz=(u8)((tr&0xfffful)==0);
vm_vars[40]=(u8)((u32)(tr)>>8);
vm_vars[41]=(u8)((u32)(tr)>>0);
goto L4e58;
L4e58: /* bne $4e60 */
VSTEP(0x4e58ul);
if(!fz)goto L4e60;
goto L4e5a;
L4e5a: /* move.w #$4e64, $3c92.w */
VSTEP(0x4e5aul);
tv=((u16)(20068L));
vm_player_state=(u16)(tv);

goto L4e60;
L4e60: /* move.b D3, $6308.w */
VSTEP(0x4e60ul);
tv=((u8)d[3]);
vm_vars[42]=(u8)((u32)(tv)>>0);

goto L4e64;
L4e64: /* lea $6318.w, A0 */
VSTEP(0x4e64ul);
a[0]=0x6318ul;
goto L4e68;
L4e68: /* move.w (A0), D5 */
VSTEP(0x4e68ul);
ea=a[0];
tv=vr16(ea);
VWORD(d[5])=(u16)(tv);

goto L4e6a;
L4e6a: /* move.b $6308.w, D4 */
VSTEP(0x4e6aul);
ea=0x6308ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[4])=(u8)(tv);

goto L4e6e;
L4e6e: /* btst #$3, D4 */
VSTEP(0x4e6eul);
v=((u16)(3L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4e72;
L4e72: /* beq $4ea8 */
VSTEP(0x4e72ul);
if(fz)goto L4ea8;
goto L4e74;
L4e74: /* move.w #$48, $67c6.w */
VSTEP(0x4e74ul);
tv=((u16)(72L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L4e7a;
L4e7a: /* subq.w #1, D5 */
VSTEP(0x4e7aul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[5])=(u16)(tr);
goto L4e7c;
L4e7c: /* bhi $4ea6 */
VSTEP(0x4e7cul);
if((!fc&&!fz))goto L4ea6;
goto L4e7e;
L4e7e: /* clr.w (A0) */
VSTEP(0x4e7eul);
ea=a[0];
vw16(ea,0);

goto L4e80;
L4e80: /* move.w #$5058, $3c92.w */
VSTEP(0x4e80ul);
tv=((u16)(20568L));
vm_player_state=(u16)(tv);

goto L4e86;
L4e86: /* move.w #$5, $62f2.w */
VSTEP(0x4e86ul);
tv=((u16)(5L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L4e8c;
L4e8c: /* move.w #$6426, $6326.w */
VSTEP(0x4e8cul);
tv=((u16)(25638L));
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L4e92;
L4e92: /* move.w D1, D2 */
VSTEP(0x4e92ul);
tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L4e94;
L4e94: /* add.w $67be.w, D2 */
VSTEP(0x4e94ul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4e98;
L4e98: /* subq.w #2, D2 */
VSTEP(0x4e98ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4e9a;
L4e9a: /* andi.w #$7, D2 */
VSTEP(0x4e9aul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L4e9e;
L4e9e: /* sub.w D2, D1 */
VSTEP(0x4e9eul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L4ea0;
L4ea0: /* move.w D1, $67c4.w */
VSTEP(0x4ea0ul);
tv=((u16)d[1]);
vm_vars[1254]=(u8)((u32)(tv)>>8);
vm_vars[1255]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4ea4;
L4ea4: /* rts  */
VSTEP(0x4ea4ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4ea6: /* move.w D5, (A0) */
VSTEP(0x4ea6ul);
tv=((u16)d[5]);
ea=a[0];
vw16(ea,tv);

goto L4ea8;
L4ea8: /* btst #$2, D4 */
VSTEP(0x4ea8ul);
v=((u16)(2L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4eac;
L4eac: /* beq $4ec0 */
VSTEP(0x4eacul);
if(fz)goto L4ec0;
goto L4eb0;
L4eb0: /* move.w #$28, $67c6.w */
VSTEP(0x4eb0ul);
tv=((u16)(40L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L4eb6;
L4eb6: /* addq.w #1, D5 */
VSTEP(0x4eb6ul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L4eb8;
L4eb8: /* cmpi.w #$50, D5 */
VSTEP(0x4eb8ul);
tv=((u16)(80L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L4ebc;
L4ebc: /* bcc $4ec0 */
VSTEP(0x4ebcul);
if(!fc)goto L4ec0;
goto L4ebe;
L4ebe: /* move.w D5, (A0) */
VSTEP(0x4ebeul);
tv=((u16)d[5]);
ea=a[0];
vw16(ea,tv);

goto L4ec0;
L4ec0: /* lea $6314.w, A0 */
VSTEP(0x4ec0ul);
a[0]=0x6314ul;
goto L4ec4;
L4ec4: /* movem.w (A0), D2-D3 */
VSTEP(0x4ec4ul);
ea=a[0];
d[2]=(s16)vr16(ea+0);
d[3]=(s16)vr16(ea+2);
goto L4ec8;
L4ec8: /* clr.w D7 */
VSTEP(0x4ec8ul);
VWORD(d[7])=(u16)(0);

goto L4eca;
L4eca: /* moveq #$7, D6 */
VSTEP(0x4ecaul);
v=((u32)(7L));
d[6]=v;

goto L4ecc;
L4ecc: /* cmpi.w #$28, D5 */
VSTEP(0x4eccul);
tv=((u16)(40L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L4ed0;
L4ed0: /* bcc $4edc */
VSTEP(0x4ed0ul);
if(!fc)goto L4edc;
goto L4ed2;
L4ed2: /* moveq #$3, D6 */
VSTEP(0x4ed2ul);
v=((u32)(3L));
d[6]=v;

goto L4ed4;
L4ed4: /* cmpi.w #$14, D6 */
VSTEP(0x4ed4ul);
tv=((u16)(20L));
tw=((u16)d[6]);
fc=(u8)((u16)tw<(u16)tv);
goto L4ed8;
L4ed8: /* bcc $4edc */
VSTEP(0x4ed8ul);
if(!fc)goto L4edc;
goto L4eda;
L4eda: /* moveq #$1, D6 */
VSTEP(0x4edaul);
v=((u32)(1L));
d[6]=v;

goto L4edc;
L4edc: /* and.w $632c.w, D6 */
VSTEP(0x4edcul);
ea=0x632cul;
tv=(((u16)vm_vars[78]<<8)|((u16)vm_vars[79]<<0));
tw=((u16)d[6]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[6])=(u16)(tr);
goto L4ee0;
L4ee0: /* bne $4eec */
VSTEP(0x4ee0ul);
if(!fz)goto L4eec;
goto L4ee2;
L4ee2: /* andi.w #$3, D4 */
VSTEP(0x4ee2ul);
tv=((u16)(3L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L4ee6;
L4ee6: /* asr.w #1, D4 */
VSTEP(0x4ee6ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fx=(u8)((tw>>0)&1);fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L4ee8;
L4ee8: /* subx.w D7, D4 */
VSTEP(0x4ee8ul);
v=((u16)d[7]);
w=((u16)d[4]);
r=w-v-fx;
VWORD(d[4])=(u16)(r);
goto L4eea;
L4eea: /* move.w D4, D7 */
VSTEP(0x4eeaul);
tv=((u16)d[4]);
VWORD(d[7])=(u16)(tv);

goto L4eec;
L4eec: /* move.w D2, D4 */
VSTEP(0x4eecul);
tv=((u16)d[2]);
VWORD(d[4])=(u16)(tv);

goto L4eee;
L4eee: /* ext.l D4 */
VSTEP(0x4eeeul);
v=((u32)d[4]);
r=(s32)(s16)v;
d[4]=r;

goto L4ef0;
L4ef0: /* divs.w D5, D4 */
VSTEP(0x4ef0ul);
v=((u16)d[5]);
w=((u32)d[4]);
if(!(s16)v){vm_fault=0xff;return;}
signed_result=(s32)w/(s16)v;
if(signed_result>32767L||signed_result<-32768L){fv=1;}else{r=((u32)((s32)w%(s16)v)<<16)|(u16)signed_result;}
d[4]=r;
goto L4ef2;
L4ef2: /* sub.w D7, D4 */
VSTEP(0x4ef2ul);
tv=((u16)d[7]);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4ef4;
L4ef4: /* add.w D4, D3 */
VSTEP(0x4ef4ul);
tv=((u16)d[4]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L4ef6;
L4ef6: /* sub.w D3, D2 */
VSTEP(0x4ef6ul);
tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4ef8;
L4ef8: /* addi.w #$80, D2 */
VSTEP(0x4ef8ul);
tv=((u16)(128L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4efc;
L4efc: /* cmpi.w #$100, D2 */
VSTEP(0x4efcul);
tv=((u16)(256L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4f00;
L4f00: /* bcc $4f08 */
VSTEP(0x4f00ul);
if(!fc)goto L4f08;
goto L4f02;
L4f02: /* subi.w #$80, D2 */
VSTEP(0x4f02ul);
tv=((u16)(128L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4f06;
L4f06: /* bra $4f16 */
VSTEP(0x4f06ul);
goto L4f16;
L4f08: /* clr.w D3 */
VSTEP(0x4f08ul);
VWORD(d[3])=(u16)(0);

goto L4f0a;
L4f0a: /* subi.w #$80, D2 */
VSTEP(0x4f0aul);
tv=((u16)(128L));
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4f0e;
L4f0e: /* bpl $4f14 */
VSTEP(0x4f0eul);
if(!fn)goto L4f14;
goto L4f10;
L4f10: /* moveq #-$7f, D2 */
VSTEP(0x4f10ul);
v=((u32)(-127L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4f12;
L4f12: /* bra $4f16 */
VSTEP(0x4f12ul);
goto L4f16;
L4f14: /* moveq #$7f, D2 */
VSTEP(0x4f14ul);
v=((u32)(127L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4f16;
L4f16: /* movem.w D2-D3, (A0) */
VSTEP(0x4f16ul);
ea=a[0];
vw16(ea+0,d[2]);
vw16(ea+2,d[3]);
goto L4f1a;
L4f1a: /* lea $6314.w, A0 */
VSTEP(0x4f1aul);
a[0]=0x6314ul;
goto L4f1e;
L4f1e: /* lea $67c2.w, A2 */
VSTEP(0x4f1eul);
a[2]=0x67c2ul;
goto L4f22;
L4f22: /* bsr $50aa */
VSTEP(0x4f22ul);
a[7]-=4;vw32(a[7],0x4f26ul);
goto L50aa;
L4f26: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x4f26ul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L4f2c;
L4f2c: /* movem.w $6328.w, D5-D6 */
VSTEP(0x4f2cul);
ea=0x6328ul;
d[5]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+74u));
d[6]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+76u));
goto L4f32;
L4f32: /* sub.w D3, D5 */
VSTEP(0x4f32ul);
tv=((u16)d[3]);
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4f34;
L4f34: /* move.w D5, $62f4.w */
VSTEP(0x4f34ul);
tv=((u16)d[5]);
vm_vars[22]=(u8)((u32)(tv)>>8);
vm_vars[23]=(u8)((u32)(tv)>>0);

goto L4f38;
L4f38: /* move.w D5, $630e.w */
VSTEP(0x4f38ul);
tv=((u16)d[5]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);

goto L4f3c;
L4f3c: /* sub.w D6, D4 */
VSTEP(0x4f3cul);
tv=((u16)d[6]);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4f3e;
L4f3e: /* move.w D4, $62f6.w */
VSTEP(0x4f3eul);
tv=((u16)d[4]);
vm_vars[24]=(u8)((u32)(tv)>>8);
vm_vars[25]=(u8)((u32)(tv)>>0);

goto L4f42;
L4f42: /* add.w D4, D1 */
VSTEP(0x4f42ul);
tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4f44;
L4f44: /* add.w D5, D0 */
VSTEP(0x4f44ul);
tv=((u16)d[5]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4f46;
L4f46: /* subq.w #4, D1 */
VSTEP(0x4f46ul);
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4f48;
L4f48: /* subq.w #5, D0 */
VSTEP(0x4f48ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4f4a;
L4f4a: /* bsr $55a0 */
VSTEP(0x4f4aul);
a[7]-=4;vw32(a[7],0x4f4eul);
goto L55a0;
L4f4e: /* moveq #$2, D7 */
VSTEP(0x4f4eul);
v=((u32)(2L));
d[7]=v;

goto L4f50;
L4f50: /* move.b (A0,D3.w), D2 */
VSTEP(0x4f50ul);
ea=(a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4f54;
L4f54: /* cmpi.b #$17, D2 */
VSTEP(0x4f54ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4f58;
L4f58: /* bcs $4f8e */
VSTEP(0x4f58ul);
if(fc)goto L4f8e;
goto L4f5a;
L4f5a: /* move.b ($1,A0,D3.w), D2 */
VSTEP(0x4f5aul);
ea=(1+a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4f5e;
L4f5e: /* cmpi.b #$17, D2 */
VSTEP(0x4f5eul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4f62;
L4f62: /* bcs $4f8e */
VSTEP(0x4f62ul);
if(fc)goto L4f8e;
goto L4f64;
L4f64: /* sub.w $8002.l, D3 */
VSTEP(0x4f64ul);
ea=0x8002ul;
tv=192u;
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L4f6a;
L4f6a: /* dbra D7, $4f50 */
VSTEP(0x4f6aul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4f50;
goto L4f6e;
L4f6e: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x4f6eul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L4f74;
L4f74: /* add.w D4, D1 */
VSTEP(0x4f74ul);
tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4f76;
L4f76: /* add.w D5, D0 */
VSTEP(0x4f76ul);
tv=((u16)d[5]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4f78;
L4f78: /* movem.w D0-D1, $67c2.w */
VSTEP(0x4f78ul);
ea=0x67c2ul;
dm_put16((u8 DM_NEAR *)(vm_vars+1252u),(u16)(d[0]));
dm_put16((u8 DM_NEAR *)(vm_vars+1254u),(u16)(d[1]));
goto L4f7e;
L4f7e: /* move.l $631a.w, $6328.w */
VSTEP(0x4f7eul);
ea=0x631aul;
v=(((u32)vm_vars[60]<<24)|((u32)vm_vars[61]<<16)|((u32)vm_vars[62]<<8)|((u32)vm_vars[63]<<0));
vm_vars[74]=(u8)((u32)(v)>>24);
vm_vars[75]=(u8)((u32)(v)>>16);
vm_vars[76]=(u8)((u32)(v)>>8);
vm_vars[77]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fv=0;fc=0;
goto L4f84;
L4f84: /* btst #$4, $6308.w */
VSTEP(0x4f84ul);
v=((u16)(4L));
eb=0x6308ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L4f8a;
L4f8a: /* bne $4fae */
VSTEP(0x4f8aul);
if(!fz)goto L4fae;
goto L4f8c;
L4f8c: /* rts  */
VSTEP(0x4f8cul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4f8e: /* tst.w D4 */
VSTEP(0x4f8eul);
tv=((u16)d[4]);
fn=(u8)((tv&0x8000ul)!=0);
goto L4f90;
L4f90: /* bmi $4f9a */
VSTEP(0x4f90ul);
if(fn)goto L4f9a;
goto L4f92;
L4f92: /* subq.w #2, $6318.w */
VSTEP(0x4f92ul);
tv=((u16)(2L));
eb=0x6318ul;
tw=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[58]=(u8)((u32)(tr)>>8);
vm_vars[59]=(u8)((u32)(tr)>>0);
goto L4f96;
L4f96: /* bra $4f1a */
VSTEP(0x4f96ul);
goto L4f1a;
L4f9a: /* movem.w D0-D7, -(A7) */
VSTEP(0x4f9aul);
a[7]-=2;
vw16(a[7],d[7]);
a[7]-=2;
vw16(a[7],d[6]);
a[7]-=2;
vw16(a[7],d[5]);
a[7]-=2;
vw16(a[7],d[4]);
a[7]-=2;
vw16(a[7],d[3]);
a[7]-=2;
vw16(a[7],d[2]);
a[7]-=2;
vw16(a[7],d[1]);
a[7]-=2;
vw16(a[7],d[0]);
goto L4f9e;
L4f9e: /* moveq #$2, D6 */
VSTEP(0x4f9eul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4fa0;
L4fa0: /* bsr $4ccc */
VSTEP(0x4fa0ul);
a[7]-=4;vw32(a[7],0x4fa4ul);
goto L4ccc;
L4fa4: /* movem.w (A7)+, D0-D7 */
VSTEP(0x4fa4ul);
ea=a[7];
d[0]=(s16)vr16(ea+0);
d[1]=(s16)vr16(ea+2);
d[2]=(s16)vr16(ea+4);
d[3]=(s16)vr16(ea+6);
d[4]=(s16)vr16(ea+8);
d[5]=(s16)vr16(ea+10);
d[6]=(s16)vr16(ea+12);
d[7]=(s16)vr16(ea+14);
a[7]+=16;
goto L4fa8;
L4fa8: /* clr.w D4 */
VSTEP(0x4fa8ul);
VWORD(d[4])=(u16)(0);

goto L4faa;
L4faa: /* clr.w D5 */
VSTEP(0x4faaul);
VWORD(d[5])=(u16)(0);

goto L4fac;
L4fac: /* bra $4fcc */
VSTEP(0x4facul);
goto L4fcc;
L4fae: /* movem.w $62f4.w, D4-D5 */
VSTEP(0x4faeul);
ea=0x62f4ul;
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+22u));
d[5]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+24u));
goto L4fb4;
L4fb4: /* subq.w #3, D5 */
VSTEP(0x4fb4ul);
tv=((u16)(3L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4fb6;
L4fb6: /* cmpi.w #-$6, D5 */
VSTEP(0x4fb6ul);
tv=((u16)(-6L));
tw=((u16)d[5]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4fba;
L4fba: /* bpl $4fbe */
VSTEP(0x4fbaul);
if(!fn)goto L4fbe;
goto L4fbc;
L4fbc: /* moveq #-$6, D5 */
VSTEP(0x4fbcul);
v=((u32)(-6L));
d[5]=v;

goto L4fbe;
L4fbe: /* subq.w #2, D4 */
VSTEP(0x4fbeul);
tv=((u16)(2L));
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4fc0;
L4fc0: /* cmpi.w #-$4, D4 */
VSTEP(0x4fc0ul);
tv=((u16)(-4L));
tw=((u16)d[4]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4fc4;
L4fc4: /* bcc $4fca */
VSTEP(0x4fc4ul);
if(!fc)goto L4fca;
goto L4fc6;
L4fc6: /* smi D4 */
VSTEP(0x4fc6ul);
VBYTE(d[4])=(u8)((fn?255:0));
goto L4fc8;
L4fc8: /* asl.w #2, D4 */
VSTEP(0x4fc8ul);
tv=((u16)(2L));
tw=((u16)d[4]);
tr=tw<<2;
VWORD(d[4])=(u16)(tr);
goto L4fca;
L4fca: /* addq.w #2, D4 */
VSTEP(0x4fcaul);
tv=((u16)(2L));
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L4fcc;
L4fcc: /* movem.w D4-D5, $62f4.w */
VSTEP(0x4fccul);
ea=0x62f4ul;
dm_put16((u8 DM_NEAR *)(vm_vars+22u),(u16)(d[4]));
dm_put16((u8 DM_NEAR *)(vm_vars+24u),(u16)(d[5]));
goto L4fd2;
L4fd2: /* clr.w $6318.w */
VSTEP(0x4fd2ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L4fd6;
L4fd6: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x4fd6ul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L4fdc;
L4fdc: /* bra $5464 */
VSTEP(0x4fdcul);
goto L5464;
L4fe0: /* move.w #$6419, $6326.l */
VSTEP(0x4fe0ul);
tv=((u16)(25625L));
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L4fe8;
L4fe8: /* move.w #$4ff6, $3c92.w */
VSTEP(0x4fe8ul);
tv=((u16)(20470L));
vm_player_state=(u16)(tv);

goto L4fee;
L4fee: /* moveq #$8, D0 */
VSTEP(0x4feeul);
v=((u32)(8L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4ff0;
L4ff0: /* jsr $48014.l */
VSTEP(0x4ff0ul);
a[7]-=4;vw32(a[7],0x4ff6ul);
goto L48014;
L4ff6: /* movea.w $6326.w, A0 */
VSTEP(0x4ff6ul);
ea=0x6326ul;
v=(((u16)vm_vars[72]<<8)|((u16)vm_vars[73]<<0));
a[0]=(s16)v;
goto L4ffa;
L4ffa: /* bsr $5438 */
VSTEP(0x4ffaul);
a[7]-=4;vw32(a[7],0x4ffeul);
goto L5438;
L4ffe: /* move.w A0, $6326.w */
VSTEP(0x4ffeul);
tv=((u16)a[0]);
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L5002;
L5002: /* tst.b (A0) */
VSTEP(0x5002ul);
ea=a[0];
tv=vr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5004;
L5004: /* bne $5034 */
VSTEP(0x5004ul);
if(!fz)goto L5034;
goto L5006;
L5006: /* move.w #$8, $62f2.w */
VSTEP(0x5006ul);
tv=((u16)(8L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L500c;
L500c: /* move.w #$5036, $3c92.w */
VSTEP(0x500cul);
tv=((u16)(20534L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5012;
L5012: /* bsr $463e */
VSTEP(0x5012ul);
a[7]-=4;vw32(a[7],0x5016ul);
goto L463e;
L5016: /* subi.w #$7, D0 */
VSTEP(0x5016ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L501a;
L501a: /* move.w $62ee.w, D2 */
VSTEP(0x501aul);
ea=0x62eeul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L501e;
L501e: /* spl D2 */
VSTEP(0x501eul);
VBYTE(d[2])=(u8)((!fn?255:0));
goto L5020;
L5020: /* ext.w D2 */
VSTEP(0x5020ul);
v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);
fn=(u8)((r&0x8000ul)!=0);
goto L5022;
L5022: /* bpl $5028 */
VSTEP(0x5022ul);
if(!fn)goto L5028;
goto L5024;
L5024: /* addi.w #$e, D0 */
VSTEP(0x5024ul);
tv=((u16)(14L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5028;
L5028: /* addq.w #3, D2 */
VSTEP(0x5028ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L502a;
L502a: /* move.w D2, (A0)+ */
VSTEP(0x502aul);
tv=((u16)d[2]);
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L502c;
L502c: /* subi.w #$10, D1 */
VSTEP(0x502cul);
tv=((u16)(16L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5030;
L5030: /* movem.w D0-D1, (A0) */
VSTEP(0x5030ul);
ea=a[0];
vw16(ea+0,d[0]);
vw16(ea+2,d[1]);
goto L5034;
L5034: /* rts  */
VSTEP(0x5034ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5036: /* move.b $6308.l, D4 */
VSTEP(0x5036ul);
ea=0x6308ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[4])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L503c;
L503c: /* bne $504e */
VSTEP(0x503cul);
if(!fz)goto L504e;
goto L5040;
L5040: /* subq.w #1, $62f2.w */
VSTEP(0x5040ul);
tv=((u16)(1L));
eb=0x62f2ul;
tw=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[20]=(u8)((u32)(tr)>>8);
vm_vars[21]=(u8)((u32)(tr)>>0);
goto L5044;
L5044: /* bne $5034 */
VSTEP(0x5044ul);
if(!fz)goto L5034;
goto L5046;
L5046: /* lea $63d3.w, A0 */
VSTEP(0x5046ul);
a[0]=0x63d3ul;
goto L504a;
L504a: /* bra $5438 */
VSTEP(0x504aul);
goto L5438;
L504e: /* move.w #$4c3e, $3c92.w */
VSTEP(0x504eul);
tv=((u16)(19518L));
vm_player_state=(u16)(tv);

goto L5054;
L5054: /* bra $4c3e */
VSTEP(0x5054ul);
goto L4c3e;
L5058: /* subq.w #1, $62f2.w */
VSTEP(0x5058ul);
tv=((u16)(1L));
eb=0x62f2ul;
tw=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[20]=(u8)((u32)(tr)>>8);
vm_vars[21]=(u8)((u32)(tr)>>0);
goto L505c;
L505c: /* bne $5034 */
VSTEP(0x505cul);
if(!fz)goto L5034;
goto L505e;
L505e: /* move.w #$6, $62f2.w */
VSTEP(0x505eul);
tv=((u16)(6L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L5064;
L5064: /* subq.w #5, $67c4.w */
VSTEP(0x5064ul);
tv=((u16)(5L));
eb=0x67c4ul;
tw=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tr=tw-tv;
vm_vars[1254]=(u8)((u32)(tr)>>8);
vm_vars[1255]=(u8)((u32)(tr)>>0);
goto L5068;
L5068: /* subq.w #4, D1 */
VSTEP(0x5068ul);
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L506a;
L506a: /* move.w $62ee.w, D2 */
VSTEP(0x506aul);
ea=0x62eeul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L506e;
L506e: /* bmi $5082 */
VSTEP(0x506eul);
if(fn)goto L5082;
goto L5070;
L5070: /* addq.w #7, D0 */
VSTEP(0x5070ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5072;
L5072: /* bsr $55a0 */
VSTEP(0x5072ul);
a[7]-=4;vw32(a[7],0x5076ul);
goto L55a0;
L5076: /* cmpi.b #$17, D2 */
VSTEP(0x5076ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L507a;
L507a: /* bcs $5092 */
VSTEP(0x507aul);
if(fc)goto L5092;
goto L507c;
L507c: /* addq.w #1, $67c2.w */
VSTEP(0x507cul);
tv=((u16)(1L));
eb=0x67c2ul;
tw=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[1252]=(u8)((u32)(tr)>>8);
vm_vars[1253]=(u8)((u32)(tr)>>0);
goto L5080;
L5080: /* bra $5092 */
VSTEP(0x5080ul);
goto L5092;
L5082: /* subq.w #6, D0 */
VSTEP(0x5082ul);
tv=((u16)(6L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5084;
L5084: /* bsr $55a0 */
VSTEP(0x5084ul);
a[7]-=4;vw32(a[7],0x5088ul);
goto L55a0;
L5088: /* cmpi.b #$17, D2 */
VSTEP(0x5088ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L508c;
L508c: /* bcs $5092 */
VSTEP(0x508cul);
if(fc)goto L5092;
goto L508e;
L508e: /* subq.w #1, $67c2.w */
VSTEP(0x508eul);
tv=((u16)(1L));
eb=0x67c2ul;
tw=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[1252]=(u8)((u32)(tr)>>8);
vm_vars[1253]=(u8)((u32)(tr)>>0);
goto L5092;
L5092: /* movea.w $6326.w, A0 */
VSTEP(0x5092ul);
ea=0x6326ul;
v=(((u16)vm_vars[72]<<8)|((u16)vm_vars[73]<<0));
a[0]=(s16)v;
goto L5096;
L5096: /* bsr $5438 */
VSTEP(0x5096ul);
a[7]-=4;vw32(a[7],0x509aul);
goto L5438;
L509a: /* move.w A0, $6326.w */
VSTEP(0x509aul);
tv=((u16)a[0]);
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L509e;
L509e: /* move.b (A0), D7 */
VSTEP(0x509eul);
ea=a[0];
tv=vr8(ea);
VBYTE(d[7])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L50a0;
L50a0: /* bne $50a8 */
VSTEP(0x50a0ul);
if(!fz)goto L50a8;
goto L50a2;
L50a2: /* move.w #$5414, $3c92.w */
VSTEP(0x50a2ul);
tv=((u16)(21524L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L50a8;
L50a8: /* rts  */
VSTEP(0x50a8ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L50aa: /* lea ($7c,A0), A1 */
VSTEP(0x50aaul);
a[1]=(124+a[0]);
goto L50ae;
L50ae: /* move.w (A0), D2 */
VSTEP(0x50aeul);
ea=a[0];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L50b0;
L50b0: /* asr.w #1, D2 */
VSTEP(0x50b0ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((s16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L50b2;
L50b2: /* move.w D2, D4 */
VSTEP(0x50b2ul);
tv=((u16)d[2]);
VWORD(d[4])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L50b4;
L50b4: /* bpl $50b8 */
VSTEP(0x50b4ul);
if(!fn)goto L50b8;
goto L50b6;
L50b6: /* neg.w D4 */
VSTEP(0x50b6ul);
tv=((u16)d[4]);
tr=0-tv;
VWORD(d[4])=(u16)(tr);
goto L50b8;
L50b8: /* clr.w D3 */
VSTEP(0x50b8ul);
VWORD(d[3])=(u16)(0);

goto L50ba;
L50ba: /* move.b (-$40,A1,D4.w), D3 */
VSTEP(0x50baul);
ea=(-64+a[1]+((s16)(d[4])));
tv=vr8(ea);
VBYTE(d[3])=(u8)(tv);

goto L50be;
L50be: /* mulu.w ($4,A0), D3 */
VSTEP(0x50beul);
ea=(4+a[0]);
v=vr16(ea);
w=((u32)d[3]);
r=(u32)(u16)v*(u16)w;

d[3]=r;
goto L50c2;
L50c2: /* btst #$f, D2 */
VSTEP(0x50c2ul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L50c6;
L50c6: /* beq $50ca */
VSTEP(0x50c6ul);
if(fz)goto L50ca;
goto L50c8;
L50c8: /* neg.w D3 */
VSTEP(0x50c8ul);
tv=((u16)d[3]);
tr=0-tv;
VWORD(d[3])=(u16)(tr);
goto L50ca;
L50ca: /* asr.w #8, D3 */
VSTEP(0x50caul);
tv=((u16)(8L));
tw=((u16)d[3]);
tr=((s16)tw)>>8;
VWORD(d[3])=(u16)(tr);
goto L50cc;
L50cc: /* move.w D3, ($6,A0) */
VSTEP(0x50ccul);
tv=((u16)d[3]);
ea=(6+a[0]);
vw16(ea,tv);

goto L50d0;
L50d0: /* move.w D4, D2 */
VSTEP(0x50d0ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L50d2;
L50d2: /* neg.w D2 */
VSTEP(0x50d2ul);
tv=((u16)d[2]);
tr=0-tv;
VWORD(d[2])=(u16)(tr);
goto L50d4;
L50d4: /* clr.w D4 */
VSTEP(0x50d4ul);
VWORD(d[4])=(u16)(0);

goto L50d6;
L50d6: /* move.b ($3f,A1,D2.w), D4 */
VSTEP(0x50d6ul);
ea=(63+a[1]+((s16)(d[2])));
tv=vr8(ea);
VBYTE(d[4])=(u8)(tv);

goto L50da;
L50da: /* mulu.w ($4,A0), D4 */
VSTEP(0x50daul);
ea=(4+a[0]);
v=vr16(ea);
w=((u32)d[4]);
r=(u32)(u16)v*(u16)w;

d[4]=r;
goto L50de;
L50de: /* lsr.w #8, D4 */
VSTEP(0x50deul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=((u16)tw)>>8;fx=(u8)((tw>>7)&1);
VWORD(d[4])=(u16)(tr);
goto L50e0;
L50e0: /* move.w D4, ($8,A0) */
VSTEP(0x50e0ul);
tv=((u16)d[4]);
ea=(8+a[0]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L50e4;
L50e4: /* rts  */
VSTEP(0x50e4ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L50e6: /* clr.w $62ee.w */
VSTEP(0x50e6ul);
vm_vars[16]=(u8)((u32)(0)>>8);
vm_vars[17]=(u8)((u32)(0)>>0);

goto L50ea;
L50ea: /* moveq #$7f, D0 */
VSTEP(0x50eaul);
v=((u32)(127L));
d[0]=v;

goto L50ec;
L50ec: /* bra $50fa */
VSTEP(0x50ecul);
goto L50fa;
L50ee: /* move.w #$e000, $62ee.w */
VSTEP(0x50eeul);
tv=((u16)(57344L));
vm_vars[16]=(u8)((u32)(tv)>>8);
vm_vars[17]=(u8)((u32)(tv)>>0);

goto L50f4;
L50f4: /* moveq #-$7f, D0 */
VSTEP(0x50f4ul);
v=((u32)(-127L));
d[0]=v;

goto L50f6;
L50f6: /* bra $50fa */
VSTEP(0x50f6ul);
goto L50fa;
L50f8: /* clr.w D0 */
VSTEP(0x50f8ul);
VWORD(d[0])=(u16)(0);

goto L50fa;
L50fa: /* move.w #$48, $67c6.w */
VSTEP(0x50faul);
tv=((u16)(72L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L5100;
L5100: /* lea $6314.w, A0 */
VSTEP(0x5100ul);
a[0]=0x6314ul;
goto L5104;
L5104: /* move.w D0, (A0)+ */
VSTEP(0x5104ul);
tv=((u16)d[0]);
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L5106;
L5106: /* clr.l (A0)+ */
VSTEP(0x5106ul);
ea=a[0];
vw32(ea,0);
a[0]+=4;
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5108;
L5108: /* bsr $463e */
VSTEP(0x5108ul);
a[7]-=4;vw32(a[7],0x510cul);
goto L463e;
L510c: /* move.w #$1, (A0) */
VSTEP(0x510cul);
tv=((u16)(1L));
ea=a[0];
vw16(ea,tv);

goto L5110;
L5110: /* move.w #$5132, $3c92.w */
VSTEP(0x5110ul);
tv=((u16)(20786L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5116;
L5116: /* lea $63d0.w, A0 */
VSTEP(0x5116ul);
a[0]=0x63d0ul;
goto L511a;
L511a: /* bsr $5438 */
VSTEP(0x511aul);
a[7]-=4;vw32(a[7],0x511eul);
goto L5438;
L511e: /* moveq #$7, D0 */
VSTEP(0x511eul);
v=((u32)(7L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5120;
L5120: /* jsr $48014.l */
VSTEP(0x5120ul);
a[7]-=4;vw32(a[7],0x5126ul);
goto L48014;
L5126: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x5126ul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L512c;
L512c: /* bclr #$4, $6308.w */
VSTEP(0x512cul);
v=((u16)(4L));
eb=0x6308ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
vm_vars[42]=(u8)((u32)(r)>>0);
goto L5132;
L5132: /* lea $6314.w, A0 */
VSTEP(0x5132ul);
a[0]=0x6314ul;
goto L5136;
L5136: /* btst #$4, $6308.l */
VSTEP(0x5136ul);
v=((u16)(4L));
eb=0x6308ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L513e;
L513e: /* bne $51be */
VSTEP(0x513eul);
if(!fz)goto L51be;
goto L5140;
L5140: /* move.w ($4,A0), D2 */
VSTEP(0x5140ul);
ea=(4+a[0]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L5144;
L5144: /* addq.w #2, D2 */
VSTEP(0x5144ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5146;
L5146: /* cmpi.w #$28, D2 */
VSTEP(0x5146ul);
tv=((u16)(40L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L514a;
L514a: /* bcc $5156 */
VSTEP(0x514aul);
if(!fc)goto L5156;
goto L514c;
L514c: /* addq.w #1, D2 */
VSTEP(0x514cul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L514e;
L514e: /* cmpi.w #$14, D2 */
VSTEP(0x514eul);
tv=((u16)(20L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5152;
L5152: /* bcc $5156 */
VSTEP(0x5152ul);
if(!fc)goto L5156;
goto L5154;
L5154: /* addq.w #1, D2 */
VSTEP(0x5154ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5156;
L5156: /* move.w D2, ($4,A0) */
VSTEP(0x5156ul);
tv=((u16)d[2]);
ea=(4+a[0]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L515a;
L515a: /* bsr $50aa */
VSTEP(0x515aul);
a[7]-=4;vw32(a[7],0x515eul);
goto L50aa;
L515e: /* addq.w #3, D3 */
VSTEP(0x515eul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5160;
L5160: /* move.w $62ee.w, D7 */
VSTEP(0x5160ul);
ea=0x62eeul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L5164;
L5164: /* bpl $5168 */
VSTEP(0x5164ul);
if(!fn)goto L5168;
goto L5166;
L5166: /* subq.w #7, D3 */
VSTEP(0x5166ul);
tv=((u16)(7L));
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L5168;
L5168: /* addi.w #$a, D4 */
VSTEP(0x5168ul);
tv=((u16)(10L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L516c;
L516c: /* sub.w D4, D1 */
VSTEP(0x516cul);
tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L516e;
L516e: /* bcs $51a8 */
VSTEP(0x516eul);
if(fc)goto L51a8;
goto L5170;
L5170: /* move.w $67be.w, D5 */
VSTEP(0x5170ul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
VWORD(d[5])=(u16)(tv);

goto L5174;
L5174: /* add.w D1, D5 */
VSTEP(0x5174ul);
tv=((u16)d[1]);
tw=((u16)d[5]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[5])=(u16)(tr);
goto L5176;
L5176: /* btst #$2, D5 */
VSTEP(0x5176ul);
v=((u16)(2L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L517a;
L517a: /* bne $51ae */
VSTEP(0x517aul);
if(!fz)goto L51ae;
goto L517c;
L517c: /* add.w D3, D0 */
VSTEP(0x517cul);
tv=((u16)d[3]);
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L517e;
L517e: /* bsr $55a0 */
VSTEP(0x517eul);
a[7]-=4;vw32(a[7],0x5182ul);
goto L55a0;
L5182: /* cmpi.b #$17, D2 */
VSTEP(0x5182ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5186;
L5186: /* bcs $51a8 */
VSTEP(0x5186ul);
if(fc)goto L51a8;
goto L5188;
L5188: /* cmpi.b #-$7b, D2 */
VSTEP(0x5188ul);
tv=((u8)(-123L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L518c;
L518c: /* bcc $51a8 */
VSTEP(0x518cul);
if(!fc)goto L51a8;
goto L518e;
L518e: /* cmpi.b #$79, D2 */
VSTEP(0x518eul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5192;
L5192: /* bcs $51ae */
VSTEP(0x5192ul);
if(fc)goto L51ae;
goto L5194;
L5194: /* move.w #$4e64, $3c92.w */
VSTEP(0x5194ul);
tv=((u16)(20068L));
vm_player_state=(u16)(tv);

goto L519a;
L519a: /* move.l $631a.w, $6328.w */
VSTEP(0x519aul);
ea=0x631aul;
v=(((u32)vm_vars[60]<<24)|((u32)vm_vars[61]<<16)|((u32)vm_vars[62]<<8)|((u32)vm_vars[63]<<0));
vm_vars[74]=(u8)((u32)(v)>>24);
vm_vars[75]=(u8)((u32)(v)>>16);
vm_vars[76]=(u8)((u32)(v)>>8);
vm_vars[77]=(u8)((u32)(v)>>0);

goto L51a0;
L51a0: /* lea $6416.w, A0 */
VSTEP(0x51a0ul);
a[0]=0x6416ul;
goto L51a4;
L51a4: /* bra $5438 */
VSTEP(0x51a4ul);
goto L5438;
L51a8: /* move.w #$51b0, $3c92.w */
VSTEP(0x51a8ul);
tv=((u16)(20912L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L51ae;
L51ae: /* rts  */
VSTEP(0x51aeul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L51b0: /* lea $6314.w, A0 */
VSTEP(0x51b0ul);
a[0]=0x6314ul;
goto L51b4;
L51b4: /* btst #$4, $6308.l */
VSTEP(0x51b4ul);
v=((u16)(4L));
eb=0x6308ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L51bc;
L51bc: /* beq $51c4 */
VSTEP(0x51bcul);
if(fz)goto L51c4;
goto L51be;
L51be: /* move.w #$2, ($4,A0) */
VSTEP(0x51beul);
tv=((u16)(2L));
ea=(4+a[0]);
vw16(ea,tv);

goto L51c4;
L51c4: /* subq.w #3, ($4,A0) */
VSTEP(0x51c4ul);
tv=((u16)(3L));
eb=(4+a[0]);
tw=vr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
vw16(eb,tr);
goto L51c8;
L51c8: /* bls $51ce */
VSTEP(0x51c8ul);
if((fc||fz))goto L51ce;
goto L51ca;
L51ca: /* bra $50aa */
VSTEP(0x51caul);
goto L50aa;
L51ce: /* clr.w ($4,A0) */
VSTEP(0x51ceul);
ea=(4+a[0]);
vw16(ea,0);

goto L51d2;
L51d2: /* move.w #$4c3e, $3c92.w */
VSTEP(0x51d2ul);
tv=((u16)(19518L));
vm_player_state=(u16)(tv);

goto L51d8;
L51d8: /* lea $63d3.w, A0 */
VSTEP(0x51d8ul);
a[0]=0x63d3ul;
goto L51dc;
L51dc: /* bra $5438 */
VSTEP(0x51dcul);
goto L5438;
L51e0: /* rts  */
VSTEP(0x51e0ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L51e2: /* move.w #$28, $67c6.w */
VSTEP(0x51e2ul);
tv=((u16)(40L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L51e8;
L51e8: /* move.w $67bc.w, D2 */
VSTEP(0x51e8ul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
VWORD(d[2])=(u16)(tv);

goto L51ec;
L51ec: /* add.w D0, D2 */
VSTEP(0x51ecul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L51ee;
L51ee: /* andi.w #$7, D2 */
VSTEP(0x51eeul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L51f2;
L51f2: /* subq.w #4, D2 */
VSTEP(0x51f2ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L51f4;
L51f4: /* bne $51e0 */
VSTEP(0x51f4ul);
if(!fz)goto L51e0;
goto L51f6;
L51f6: /* bsr $55a0 */
VSTEP(0x51f6ul);
a[7]-=4;vw32(a[7],0x51faul);
goto L55a0;
L51fa: /* cmpi.b #-$7b, D2 */
VSTEP(0x51faul);
tv=((u8)(-123L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L51fe;
L51fe: /* bcs $51e0 */
VSTEP(0x51feul);
if(fc)goto L51e0;
goto L5200;
L5200: /* bra $522e */
VSTEP(0x5200ul);
goto L522e;
L5202: /* bsr $5208 */
VSTEP(0x5202ul);
a[7]-=4;vw32(a[7],0x5204ul);
goto L5208;
L5204: /* bra $5430 */
VSTEP(0x5204ul);
goto L5430;
L5208: /* move.w #$48, $67c6.w */
VSTEP(0x5208ul);
tv=((u16)(72L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L520e;
L520e: /* move.w $67bc.w, D2 */
VSTEP(0x520eul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
VWORD(d[2])=(u16)(tv);

goto L5212;
L5212: /* add.w D0, D2 */
VSTEP(0x5212ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5214;
L5214: /* andi.w #$7, D2 */
VSTEP(0x5214ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5218;
L5218: /* subq.w #4, D2 */
VSTEP(0x5218ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L521a;
L521a: /* bne $51e0 */
VSTEP(0x521aul);
if(!fz)goto L51e0;
goto L521c;
L521c: /* subi.w #$c, D1 */
VSTEP(0x521cul);
tv=((u16)(12L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5220;
L5220: /* bsr $55a0 */
VSTEP(0x5220ul);
a[7]-=4;vw32(a[7],0x5224ul);
goto L55a0;
L5224: /* addi.w #$c, D1 */
VSTEP(0x5224ul);
tv=((u16)(12L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L5228;
L5228: /* cmpi.b #-$7b, D2 */
VSTEP(0x5228ul);
tv=((u8)(-123L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L522c;
L522c: /* bcs $51e0 */
VSTEP(0x522cul);
if(fc)goto L51e0;
goto L522e;
L522e: /* addq.w #4, A7 */
VSTEP(0x522eul);
v=((u16)(4L));
w=((u32)a[7]);
r=w+v;
a[7]=r;
goto L5230;
L5230: /* andi.b #$c, $6308.w */
VSTEP(0x5230ul);
tv=((u8)(12L));
eb=0x6308ul;
tw=(((u8)vm_vars[42]<<0));
tr=tw&tv;

vm_vars[42]=(u8)((u32)(tr)>>0);
goto L5236;
L5236: /* move.w #$5308, $3c92.w */
VSTEP(0x5236ul);
tv=((u16)(21256L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fv=0;fc=0;
goto L523c;
L523c: /* bra $5308 */
VSTEP(0x523cul);
goto L5308;
L5240: /* bsr $51e2 */
VSTEP(0x5240ul);
a[7]-=4;vw32(a[7],0x5242ul);
goto L51e2;
L5242: /* bra $5246 */
VSTEP(0x5242ul);
goto L5246;
L5244: /* bsr $5208 */
VSTEP(0x5244ul);
a[7]-=4;vw32(a[7],0x5246ul);
goto L5208;
L5246: /* addq.w #4, D0 */
VSTEP(0x5246ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5248;
L5248: /* subq.w #2, D1 */
VSTEP(0x5248ul);
tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L524a;
L524a: /* bsr $55a0 */
VSTEP(0x524aul);
a[7]-=4;vw32(a[7],0x524eul);
goto L55a0;
L524e: /* cmpi.b #$17, D2 */
VSTEP(0x524eul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5252;
L5252: /* bcs $5290 */
VSTEP(0x5252ul);
if(fc)goto L5290;
goto L5254;
L5254: /* addq.w #1, $67c2.w */
VSTEP(0x5254ul);
tv=((u16)(1L));
eb=0x67c2ul;
tw=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tr=tw+tv;
vm_vars[1252]=(u8)((u32)(tr)>>8);
vm_vars[1253]=(u8)((u32)(tr)>>0);
goto L5258;
L5258: /* addq.w #7, D1 */
VSTEP(0x5258ul);
tv=((u16)(7L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L525a;
L525a: /* subq.w #5, D0 */
VSTEP(0x525aul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L525c;
L525c: /* bsr $55a0 */
VSTEP(0x525cul);
a[7]-=4;vw32(a[7],0x5260ul);
goto L55a0;
L5260: /* subi.b #$79, D2 */
VSTEP(0x5260ul);
tv=((u8)(121L));
tw=((u8)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[2])=(u8)(tr);
goto L5264;
L5264: /* cmpi.b #$d, D2 */
VSTEP(0x5264ul);
tv=((u8)(13L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5268;
L5268: /* bcc $545a */
VSTEP(0x5268ul);
if(!fc)goto L545a;
goto L526c;
L526c: /* lea $62ea.w, A0 */
VSTEP(0x526cul);
a[0]=0x62eaul;
goto L5270;
L5270: /* add.w $67bc.w, D0 */
VSTEP(0x5270ul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5274;
L5274: /* lsr.w #1, D0 */
VSTEP(0x5274ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;
VWORD(d[0])=(u16)(tr);
goto L5276;
L5276: /* andi.w #$7, D0 */
VSTEP(0x5276ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L527a;
L527a: /* addq.w #5, D0 */
VSTEP(0x527aul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L527c;
L527c: /* move.w D0, (A0)+ */
VSTEP(0x527cul);
tv=((u16)d[0]);
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L527e;
L527e: /* andi.w #$6, D0 */
VSTEP(0x527eul);
tv=((u16)(6L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L5282;
L5282: /* lsr.w #1, D0 */
VSTEP(0x5282ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;fz=(u8)((tr&0xfffful)==0);
VWORD(d[0])=(u16)(tr);
goto L5284;
L5284: /* bne $5288 */
VSTEP(0x5284ul);
if(!fz)goto L5288;
goto L5286;
L5286: /* moveq #$2, D0 */
VSTEP(0x5286ul);
v=((u32)(2L));
d[0]=v;

goto L5288;
L5288: /* addq.w #1, D0 */
VSTEP(0x5288ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L528a;
L528a: /* move.w D0, (A0)+ */
VSTEP(0x528aul);
tv=((u16)d[0]);
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L528c;
L528c: /* move.w #$1, (A0) */
VSTEP(0x528cul);
tv=((u16)(1L));
ea=a[0];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5290;
L5290: /* rts  */
VSTEP(0x5290ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5292: /* bsr $51e2 */
VSTEP(0x5292ul);
a[7]-=4;vw32(a[7],0x5296ul);
goto L51e2;
L5296: /* bra $529c */
VSTEP(0x5296ul);
goto L529c;
L5298: /* bsr $5208 */
VSTEP(0x5298ul);
a[7]-=4;vw32(a[7],0x529cul);
goto L5208;
L529c: /* subq.w #5, D0 */
VSTEP(0x529cul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L529e;
L529e: /* subq.w #2, D1 */
VSTEP(0x529eul);
tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L52a0;
L52a0: /* bsr $55a0 */
VSTEP(0x52a0ul);
a[7]-=4;vw32(a[7],0x52a4ul);
goto L55a0;
L52a4: /* cmpi.b #$17, D2 */
VSTEP(0x52a4ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L52a8;
L52a8: /* bcs $5290 */
VSTEP(0x52a8ul);
if(fc)goto L5290;
goto L52aa;
L52aa: /* subq.w #1, $67c2.w */
VSTEP(0x52aaul);
tv=((u16)(1L));
eb=0x67c2ul;
tw=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
tr=tw-tv;
vm_vars[1252]=(u8)((u32)(tr)>>8);
vm_vars[1253]=(u8)((u32)(tr)>>0);
goto L52ae;
L52ae: /* addq.w #7, D1 */
VSTEP(0x52aeul);
tv=((u16)(7L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L52b0;
L52b0: /* addq.w #5, D0 */
VSTEP(0x52b0ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L52b2;
L52b2: /* bsr $55a0 */
VSTEP(0x52b2ul);
a[7]-=4;vw32(a[7],0x52b6ul);
goto L55a0;
L52b6: /* subi.b #$79, D2 */
VSTEP(0x52b6ul);
tv=((u8)(121L));
tw=((u8)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[2])=(u8)(tr);
goto L52ba;
L52ba: /* cmpi.b #$d, D2 */
VSTEP(0x52baul);
tv=((u8)(13L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L52be;
L52be: /* bcc $545a */
VSTEP(0x52beul);
if(!fc)goto L545a;
goto L52c2;
L52c2: /* lea $62ea.w, A0 */
VSTEP(0x52c2ul);
a[0]=0x62eaul;
goto L52c6;
L52c6: /* add.w $67bc.w, D0 */
VSTEP(0x52c6ul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L52ca;
L52ca: /* not.w D0 */
VSTEP(0x52caul);
tv=((u16)d[0]);
tr=~tv;
VWORD(d[0])=(u16)(tr);

goto L52cc;
L52cc: /* lsr.w #1, D0 */
VSTEP(0x52ccul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;
VWORD(d[0])=(u16)(tr);
goto L52ce;
L52ce: /* andi.w #$7, D0 */
VSTEP(0x52ceul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L52d2;
L52d2: /* addi.w #-$1ffb, D0 */
VSTEP(0x52d2ul);
tv=((u16)(-8187L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L52d6;
L52d6: /* move.w D0, (A0)+ */
VSTEP(0x52d6ul);
tv=((u16)d[0]);
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L52d8;
L52d8: /* andi.w #$e006, D0 */
VSTEP(0x52d8ul);
tv=((u16)(57350L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L52dc;
L52dc: /* lsr.b #1, D0 */
VSTEP(0x52dcul);
tv=((u8)(1L));
tw=((u8)d[0]);
tr=((u8)tw)>>1;fz=(u8)((tr&0xfful)==0);
VBYTE(d[0])=(u8)(tr);
goto L52de;
L52de: /* bne $52e4 */
VSTEP(0x52deul);
if(!fz)goto L52e4;
goto L52e0;
L52e0: /* move.w #$e002, D0 */
VSTEP(0x52e0ul);
tv=((u16)(57346L));
VWORD(d[0])=(u16)(tv);

goto L52e4;
L52e4: /* addq.w #1, D0 */
VSTEP(0x52e4ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L52e6;
L52e6: /* move.w D0, (A0)+ */
VSTEP(0x52e6ul);
tv=((u16)d[0]);
ea=a[0];
vw16(ea,tv);
a[0]+=2;

goto L52e8;
L52e8: /* move.w #$e001, (A0) */
VSTEP(0x52e8ul);
tv=((u16)(57345L));
ea=a[0];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L52ec;
L52ec: /* rts  */
VSTEP(0x52ecul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L52ee: /* add.w D5, D3 */
VSTEP(0x52eeul);
tv=((u16)d[5]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L52f0;
L52f0: /* move.b (A0,D3.w), D2 */
VSTEP(0x52f0ul);
ea=(a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L52f4;
L52f4: /* subi.b #$79, D2 */
VSTEP(0x52f4ul);
tv=((u8)(121L));
tw=((u8)d[2]);
tr=tw-tv;
VBYTE(d[2])=(u8)(tr);
goto L52f8;
L52f8: /* cmpi.b #$d, D2 */
VSTEP(0x52f8ul);
tv=((u8)(13L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L52fc;
L52fc: /* bcc $5368 */
VSTEP(0x52fcul);
if(!fc)goto L5368;
goto L52fe;
L52fe: /* move.w #$4c3e, $3c92.w */
VSTEP(0x52feul);
tv=((u16)(19518L));
vm_player_state=(u16)(tv);

goto L5304;
L5304: /* bra $4c3e */
VSTEP(0x5304ul);
goto L4c3e;
L5308: /* btst #$4, $6308.w */
VSTEP(0x5308ul);
v=((u16)(4L));
eb=0x6308ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L530e;
L530e: /* bne $545a */
VSTEP(0x530eul);
if(!fz)goto L545a;
goto L5312;
L5312: /* btst #$0, $632d.w */
VSTEP(0x5312ul);
v=((u16)(0L));
eb=0x632dul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5318;
L5318: /* bne $52ec */
VSTEP(0x5318ul);
if(!fz)goto L52ec;
goto L531a;
L531a: /* clr.w D4 */
VSTEP(0x531aul);
VWORD(d[4])=(u16)(0);

goto L531c;
L531c: /* move.b $6308.w, D4 */
VSTEP(0x531cul);
ea=0x6308ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[4])=(u8)(tv);

goto L5320;
L5320: /* move.w $67be.w, D2 */
VSTEP(0x5320ul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
VWORD(d[2])=(u16)(tv);

goto L5324;
L5324: /* add.w D1, D2 */
VSTEP(0x5324ul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5326;
L5326: /* andi.w #$7, D2 */
VSTEP(0x5326ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
VWORD(d[2])=(u16)(tr);
goto L532a;
L532a: /* beq $534e */
VSTEP(0x532aul);
if(fz)goto L534e;
goto L532c;
L532c: /* btst #$2, D4 */
VSTEP(0x532cul);
v=((u16)(2L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5330;
L5330: /* beq $533a */
VSTEP(0x5330ul);
if(fz)goto L533a;
goto L5332;
L5332: /* addq.w #1, D1 */
VSTEP(0x5332ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5334;
L5334: /* move.w #$28, $67c6.w */
VSTEP(0x5334ul);
tv=((u16)(40L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L533a;
L533a: /* btst #$3, D4 */
VSTEP(0x533aul);
v=((u16)(3L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L533e;
L533e: /* beq $5348 */
VSTEP(0x533eul);
if(fz)goto L5348;
goto L5340;
L5340: /* subq.w #1, D1 */
VSTEP(0x5340ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L5342;
L5342: /* move.w #$48, $67c6.w */
VSTEP(0x5342ul);
tv=((u16)(72L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L5348;
L5348: /* move.w D1, $67c4.w */
VSTEP(0x5348ul);
tv=((u16)d[1]);
vm_vars[1254]=(u8)((u32)(tv)>>8);
vm_vars[1255]=(u8)((u32)(tv)>>0);

goto L534c;
L534c: /* bra $53a6 */
VSTEP(0x534cul);
goto L53a6;
L534e: /* bsr $55a0 */
VSTEP(0x534eul);
a[7]-=4;vw32(a[7],0x5352ul);
goto L55a0;
L5352: /* move.w D4, D5 */
VSTEP(0x5352ul);
tv=((u16)d[4]);
VWORD(d[5])=(u16)(tv);

goto L5354;
L5354: /* andi.b #$3, D5 */
VSTEP(0x5354ul);
tv=((u8)(3L));
tw=((u8)d[5]);
tr=tw&tv;

VBYTE(d[5])=(u8)(tr);
goto L5358;
L5358: /* move.b D5, $6308.w */
VSTEP(0x5358ul);
tv=((u8)d[5]);
vm_vars[42]=(u8)((u32)(tv)>>0);

goto L535c;
L535c: /* moveq #$1, D5 */
VSTEP(0x535cul);
v=((u32)(1L));
d[5]=v;

goto L535e;
L535e: /* asr.w #1, D4 */
VSTEP(0x535eul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);
VWORD(d[4])=(u16)(tr);
goto L5360;
L5360: /* bcs $52ee */
VSTEP(0x5360ul);
if(fc)goto L52ee;
goto L5362;
L5362: /* moveq #-$1, D5 */
VSTEP(0x5362ul);
v=((u32)(-1L));
d[5]=v;

goto L5364;
L5364: /* asr.w #1, D4 */
VSTEP(0x5364ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);
VWORD(d[4])=(u16)(tr);
goto L5366;
L5366: /* bcs $52ee */
VSTEP(0x5366ul);
if(fc)goto L52ee;
goto L5368;
L5368: /* asr.w #1, D4 */
VSTEP(0x5368ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);
VWORD(d[4])=(u16)(tr);
goto L536a;
L536a: /* bcc $5380 */
VSTEP(0x536aul);
if(!fc)goto L5380;
goto L536c;
L536c: /* move.w #$28, $67c6.w */
VSTEP(0x536cul);
tv=((u16)(40L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L5372;
L5372: /* cmpi.b #-$7b, D2 */
VSTEP(0x5372ul);
tv=((u8)(-123L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5376;
L5376: /* bcs $53ce */
VSTEP(0x5376ul);
if(fc)goto L53ce;
goto L537a;
L537a: /* addq.w #1, $67c4.w */
VSTEP(0x537aul);
tv=((u16)(1L));
eb=0x67c4ul;
tw=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tr=tw+tv;
vm_vars[1254]=(u8)((u32)(tr)>>8);
vm_vars[1255]=(u8)((u32)(tr)>>0);
goto L537e;
L537e: /* bra $53a6 */
VSTEP(0x537eul);
goto L53a6;
L5380: /* asr.w #1, D4 */
VSTEP(0x5380ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;
VWORD(d[4])=(u16)(tr);
goto L5382;
L5382: /* bcc $53cc */
VSTEP(0x5382ul);
if(!fc)goto L53cc;
goto L5384;
L5384: /* move.w #$48, $67c6.w */
VSTEP(0x5384ul);
tv=((u16)(72L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L538a;
L538a: /* move.w $8002.l, D5 */
VSTEP(0x538aul);
ea=0x8002ul;
tv=192u;
VWORD(d[5])=(u16)(tv);

goto L5390;
L5390: /* sub.w D5, D3 */
VSTEP(0x5390ul);
tv=((u16)d[5]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L5392;
L5392: /* sub.w D5, D3 */
VSTEP(0x5392ul);
tv=((u16)d[5]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L5394;
L5394: /* sub.w D5, D3 */
VSTEP(0x5394ul);
tv=((u16)d[5]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L5396;
L5396: /* move.b (A0,D3.w), D2 */
VSTEP(0x5396ul);
ea=(a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L539a;
L539a: /* cmpi.b #-$7b, D2 */
VSTEP(0x539aul);
tv=((u8)(-123L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L539e;
L539e: /* bcs $53ce */
VSTEP(0x539eul);
if(fc)goto L53ce;
goto L53a0;
L53a0: /* subq.w #1, D1 */
VSTEP(0x53a0ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L53a2;
L53a2: /* move.w D1, $67c4.w */
VSTEP(0x53a2ul);
tv=((u16)d[1]);
vm_vars[1254]=(u8)((u32)(tv)>>8);
vm_vars[1255]=(u8)((u32)(tv)>>0);

goto L53a6;
L53a6: /* move.w $67be.w, D2 */
VSTEP(0x53a6ul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
VWORD(d[2])=(u16)(tv);

goto L53aa;
L53aa: /* add.w $67c4.w, D2 */
VSTEP(0x53aaul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L53ae;
L53ae: /* addq.w #2, D2 */
VSTEP(0x53aeul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L53b0;
L53b0: /* not.w D2 */
VSTEP(0x53b0ul);
tv=((u16)d[2]);
tr=~tv;
VWORD(d[2])=(u16)(tr);

goto L53b2;
L53b2: /* andi.w #$7, D2 */
VSTEP(0x53b2ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L53b6;
L53b6: /* bclr #$2, D2 */
VSTEP(0x53b6ul);
v=((u16)(2L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L53ba;
L53ba: /* beq $53c0 */
VSTEP(0x53baul);
if(fz)goto L53c0;
goto L53bc;
L53bc: /* addi.w #-$2000, D2 */
VSTEP(0x53bcul);
tv=((u16)(-8192L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L53c0;
L53c0: /* addi.w #$20, D2 */
VSTEP(0x53c0ul);
tv=((u16)(32L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L53c4;
L53c4: /* lea $62ea.w, A0 */
VSTEP(0x53c4ul);
a[0]=0x62eaul;
goto L53c8;
L53c8: /* clr.l (A0)+ */
VSTEP(0x53c8ul);
ea=a[0];
vw32(ea,0);
a[0]+=4;

goto L53ca;
L53ca: /* move.w D2, (A0) */
VSTEP(0x53caul);
tv=((u16)d[2]);
ea=a[0];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L53cc;
L53cc: /* rts  */
VSTEP(0x53ccul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L53ce: /* move.w #$4c3e, $3c92.w */
VSTEP(0x53ceul);
tv=((u16)(19518L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L53d4;
L53d4: /* rts  */
VSTEP(0x53d4ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L53d6: /* addi.w #$8, D1 */
VSTEP(0x53d6ul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L53da;
L53da: /* bsr $55a0 */
VSTEP(0x53daul);
a[7]-=4;vw32(a[7],0x53deul);
goto L55a0;
L53de: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x53deul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L53e4;
L53e4: /* cmpi.b #$17, D2 */
VSTEP(0x53e4ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L53e8;
L53e8: /* bcs $53f4 */
VSTEP(0x53e8ul);
if(fc)goto L53f4;
goto L53ea;
L53ea: /* move.w #$8000, $5506.w */
VSTEP(0x53eaul);
tv=((u16)(32768L));
vm_platform_opcode=(u16)(tv);

goto L53f0;
L53f0: /* bra $545a */
VSTEP(0x53f0ul);
goto L545a;
L53f4: /* bsr $51e2 */
VSTEP(0x53f4ul);
a[7]-=4;vw32(a[7],0x53f8ul);
goto L51e2;
L53f8: /* lea $63d6.w, A0 */
VSTEP(0x53f8ul);
a[0]=0x63d6ul;
goto L53fc;
L53fc: /* bsr $5438 */
VSTEP(0x53fcul);
a[7]-=4;vw32(a[7],0x53feul);
goto L5438;
L53fe: /* move.w #$5406, $3c92.w */
VSTEP(0x53feul);
tv=((u16)(21510L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5404;
L5404: /* rts  */
VSTEP(0x5404ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5406: /* lea $63d9.w, A0 */
VSTEP(0x5406ul);
a[0]=0x63d9ul;
goto L540a;
L540a: /* bsr $5438 */
VSTEP(0x540aul);
a[7]-=4;vw32(a[7],0x540cul);
goto L5438;
L540c: /* btst #$2, $6308.w */
VSTEP(0x540cul);
v=((u16)(2L));
eb=0x6308ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5412;
L5412: /* bne $5420 */
VSTEP(0x5412ul);
if(!fz)goto L5420;
goto L5414;
L5414: /* move.w #$542a, $3c92.w */
VSTEP(0x5414ul);
tv=((u16)(21546L));
vm_player_state=(u16)(tv);

goto L541a;
L541a: /* lea $63d6.w, A0 */
VSTEP(0x541aul);
a[0]=0x63d6ul;
goto L541e;
L541e: /* bra $5438 */
VSTEP(0x541eul);
goto L5438;
L5420: /* btst #$4, $6308.w */
VSTEP(0x5420ul);
v=((u16)(4L));
eb=0x6308ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5426;
L5426: /* bne $53d6 */
VSTEP(0x5426ul);
if(!fz)goto L53d6;
goto L5428;
L5428: /* rts  */
VSTEP(0x5428ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L542a: /* move.w #$4c3e, $3c92.w */
VSTEP(0x542aul);
tv=((u16)(19518L));
vm_player_state=(u16)(tv);

goto L5430;
L5430: /* lea $63d3.w, A0 */
VSTEP(0x5430ul);
a[0]=0x63d3ul;
goto L5434;
L5434: /* bra $5438 */
VSTEP(0x5434ul);
goto L5438;
L5438: /* move.w D7, -(A7) */
VSTEP(0x5438ul);
tv=((u16)d[7]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);

goto L543a;
L543a: /* lea $62ee.w, A1 */
VSTEP(0x543aul);
a[1]=0x62eeul;
goto L543e;
L543e: /* move.w (A1), D7 */
VSTEP(0x543eul);
ea=a[1];
tv=vr16(ea);
VWORD(d[7])=(u16)(tv);

goto L5440;
L5440: /* andi.w #$e000, D7 */
VSTEP(0x5440ul);
tv=((u16)(57344L));
tw=((u16)d[7]);
tr=tw&tv;

VWORD(d[7])=(u16)(tr);
goto L5444;
L5444: /* add.b (A0)+, D7 */
VSTEP(0x5444ul);
ea=a[0];
tv=vr8(ea);
a[0]+=1;
tw=((u8)d[7]);
tr=tw+tv;
VBYTE(d[7])=(u8)(tr);
goto L5446;
L5446: /* move.w D7, (A1) */
VSTEP(0x5446ul);
tv=((u16)d[7]);
ea=a[1];
vw16(ea,tv);

goto L5448;
L5448: /* add.b (A0)+, D7 */
VSTEP(0x5448ul);
ea=a[0];
tv=vr8(ea);
a[0]+=1;
tw=((u8)d[7]);
tr=tw+tv;
VBYTE(d[7])=(u8)(tr);
goto L544a;
L544a: /* move.w D7, -(A1) */
VSTEP(0x544aul);
tv=((u16)d[7]);
a[1]-=2;
ea=a[1];
vw16(ea,tv);

goto L544c;
L544c: /* add.b (A0)+, D7 */
VSTEP(0x544cul);
ea=a[0];
tv=vr8(ea);
a[0]+=1;
tw=((u8)d[7]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[7])=(u8)(tr);
goto L544e;
L544e: /* move.w D7, -(A1) */
VSTEP(0x544eul);
tv=((u16)d[7]);
a[1]-=2;
ea=a[1];
vw16(ea,tv);

goto L5450;
L5450: /* move.w (A7)+, D7 */
VSTEP(0x5450ul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5452;
L5452: /* rts  */
VSTEP(0x5452ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L545a: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x545aul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L5460;
L5460: /* clr.l $62f4.w */
VSTEP(0x5460ul);
vm_vars[22]=(u8)((u32)(0)>>24);
vm_vars[23]=(u8)((u32)(0)>>16);
vm_vars[24]=(u8)((u32)(0)>>8);
vm_vars[25]=(u8)((u32)(0)>>0);

goto L5464;
L5464: /* move.w $67c4.w, $67c6.w */
VSTEP(0x5464ul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L546a;
L546a: /* lea (-$18,PC), A0 */
VSTEP(0x546aul);
a[0]=(-24+0x546cul);
goto L546e;
L546e: /* bsr $5438 */
VSTEP(0x546eul);
a[7]-=4;vw32(a[7],0x5472ul);
goto L5438;
L5472: /* move.w #$5482, $3c92.w */
VSTEP(0x5472ul);
tv=((u16)(21634L));
vm_player_state=(u16)(tv);

goto L5478;
L5478: /* move.w #$ffff, $62fa.w */
VSTEP(0x5478ul);
tv=((u16)(65535L));
vm_vars[28]=(u8)((u32)(tv)>>8);
vm_vars[29]=(u8)((u32)(tv)>>0);

goto L547e;
L547e: /* clr.w $62f8.w */
VSTEP(0x547eul);
vm_vars[26]=(u8)((u32)(0)>>8);
vm_vars[27]=(u8)((u32)(0)>>0);

goto L5482;
L5482: /* movem.w $62f4.w, D4-D5 */
VSTEP(0x5482ul);
ea=0x62f4ul;
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+22u));
d[5]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+24u));
goto L5488;
L5488: /* move.w D4, $630e.w */
VSTEP(0x5488ul);
tv=((u16)d[4]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);
fz=(u8)((tv&0xfffful)==0);
goto L548c;
L548c: /* beq $54cc */
VSTEP(0x548cul);
if(fz)goto L54cc;
goto L548e;
L548e: /* subi.w #$10, D1 */
VSTEP(0x548eul);
tv=((u16)(16L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L5492;
L5492: /* subq.w #4, D0 */
VSTEP(0x5492ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5494;
L5494: /* add.w D4, D0 */
VSTEP(0x5494ul);
tv=((u16)d[4]);
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5496;
L5496: /* bsr $55a0 */
VSTEP(0x5496ul);
a[7]-=4;vw32(a[7],0x549aul);
goto L55a0;
L549a: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x549aul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L54a0;
L54a0: /* moveq #$1, D7 */
VSTEP(0x54a0ul);
v=((u32)(1L));
d[7]=v;

goto L54a2;
L54a2: /* cmpi.b #$17, D2 */
VSTEP(0x54a2ul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L54a6;
L54a6: /* bcs $54c8 */
VSTEP(0x54a6ul);
if(fc)goto L54c8;
goto L54a8;
L54a8: /* move.b ($1,A0,D3.w), D2 */
VSTEP(0x54a8ul);
ea=(1+a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L54ac;
L54ac: /* cmpi.b #$17, D2 */
VSTEP(0x54acul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L54b0;
L54b0: /* bcs $54c8 */
VSTEP(0x54b0ul);
if(fc)goto L54c8;
goto L54b2;
L54b2: /* add.w $8002.l, D3 */
VSTEP(0x54b2ul);
ea=0x8002ul;
tv=192u;
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L54b8;
L54b8: /* move.b (A0,D3.w), D2 */
VSTEP(0x54b8ul);
ea=(a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L54bc;
L54bc: /* dbra D7, $54a2 */
VSTEP(0x54bcul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L54a2;
goto L54c0;
L54c0: /* add.w D0, D4 */
VSTEP(0x54c0ul);
tv=((u16)d[0]);
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L54c2;
L54c2: /* move.w D4, $67c2.w */
VSTEP(0x54c2ul);
tv=((u16)d[4]);
vm_vars[1252]=(u8)((u32)(tv)>>8);
vm_vars[1253]=(u8)((u32)(tv)>>0);

goto L54c6;
L54c6: /* bra $54cc */
VSTEP(0x54c6ul);
goto L54cc;
L54c8: /* clr.w $62f4.w */
VSTEP(0x54c8ul);
vm_vars[22]=(u8)((u32)(0)>>8);
vm_vars[23]=(u8)((u32)(0)>>0);

goto L54cc;
L54cc: /* cmpi.w #$10, D5 */
VSTEP(0x54ccul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L54d0;
L54d0: /* bpl $54d4 */
VSTEP(0x54d0ul);
if(!fn)goto L54d4;
goto L54d2;
L54d2: /* addq.w #1, D5 */
VSTEP(0x54d2ul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L54d4;
L54d4: /* move.w D5, $62f6.w */
VSTEP(0x54d4ul);
tv=((u16)d[5]);
vm_vars[24]=(u8)((u32)(tv)>>8);
vm_vars[25]=(u8)((u32)(tv)>>0);

goto L54d8;
L54d8: /* asr.w #2, D5 */
VSTEP(0x54d8ul);
tv=((u16)(2L));
tw=((u16)d[5]);
tr=((s16)tw)>>2;
VWORD(d[5])=(u16)(tr);
goto L54da;
L54da: /* add.w D5, D1 */
VSTEP(0x54daul);
tv=((u16)d[5]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L54dc;
L54dc: /* move.w D1, $67c4.w */
VSTEP(0x54dcul);
tv=((u16)d[1]);
vm_vars[1254]=(u8)((u32)(tv)>>8);
vm_vars[1255]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fv=0;fc=0;
goto L54e0;
L54e0: /* btst #$f, D1 */
VSTEP(0x54e0ul);
v=((u16)(15L));
w=((u32)d[1]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L54e4;
L54e4: /* beq $54e8 */
VSTEP(0x54e4ul);
if(fz)goto L54e8;
goto L54e6;
L54e6: /* rts  */
VSTEP(0x54e6ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L54e8: /* bsr $55a0 */
VSTEP(0x54e8ul);
a[7]-=4;vw32(a[7],0x54ecul);
goto L55a0;
L54ec: /* cmpi.b #$17, D2 */
VSTEP(0x54ecul);
tv=((u8)(23L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L54f0;
L54f0: /* bcc $54fe */
VSTEP(0x54f0ul);
if(!fc)goto L54fe;
goto L54f2;
L54f2: /* subq.w #7, $67c4.w */
VSTEP(0x54f2ul);
tv=((u16)(7L));
eb=0x67c4ul;
tw=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tr=tw-tv;
vm_vars[1254]=(u8)((u32)(tr)>>8);
vm_vars[1255]=(u8)((u32)(tr)>>0);
goto L54f6;
L54f6: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x54f6ul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L54fc;
L54fc: /* bra $5482 */
VSTEP(0x54fcul);
goto L5482;
L54fe: /* subi.b #$79, D2 */
VSTEP(0x54feul);
tv=((u8)(121L));
tw=((u8)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[2])=(u8)(tr);
goto L5502;
L5502: /* cmpi.b #$d, D2 */
VSTEP(0x5502ul);
tv=((u8)(13L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5506;
L5506: /* nop  */
VSTEP(0x5506ul);
if(vm_platform_opcode==0x8000u)vnz(d[0],8);
goto L5508;
L5508: /* move SR, D6 */
VSTEP(0x5508ul);
v=(0x2000u|(fx<<4)|(fn<<3)|(fz<<2)|(fv<<1)|fc);
VWORD(d[6])=(u16)(v);

goto L550a;
L550a: /* add.w $62f8.w, D5 */
VSTEP(0x550aul);
ea=0x62f8ul;
tv=(((u16)vm_vars[26]<<8)|((u16)vm_vars[27]<<0));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L550e;
L550e: /* move.w D5, $62f8.w */
VSTEP(0x550eul);
tv=((u16)d[5]);
vm_vars[26]=(u8)((u32)(tv)>>8);
vm_vars[27]=(u8)((u32)(tv)>>0);

goto L5512;
L5512: /* cmpi.w #$8, D5 */
VSTEP(0x5512ul);
tv=((u16)(8L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L5516;
L5516: /* bcs $551e */
VSTEP(0x5516ul);
if(fc)goto L551e;
goto L5518;
L5518: /* move.w #$4e71, $5506.w */
VSTEP(0x5518ul);
tv=((u16)(20081L));
vm_platform_opcode=(u16)(tv);

goto L551e;
L551e: /* move D6, SR */
VSTEP(0x551eul);
v=((u16)d[6]);
fx=(v>>4)&1;fn=(v>>3)&1;fz=(v>>2)&1;fv=(v>>1)&1;fc=v&1;
goto L5520;
L5520: /* bcc $54e6 */
VSTEP(0x5520ul);
if(!fc)goto L54e6;
goto L5522;
L5522: /* move.w #$28, $67c6.w */
VSTEP(0x5522ul);
tv=((u16)(40L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5528;
L5528: /* lea $5457.w, A0 */
VSTEP(0x5528ul);
a[0]=0x5457ul;
goto L552c;
L552c: /* bsr $5438 */
VSTEP(0x552cul);
a[7]-=4;vw32(a[7],0x5530ul);
goto L5438;
L5530: /* move.l #$555a, $3c90.w */
VSTEP(0x5530ul);
v=((u32)(21850L));
ea=0x3c90ul;
vw32(ea,v);

goto L5538;
L5538: /* clr.w $62f6.w */
VSTEP(0x5538ul);
vm_vars[24]=(u8)((u32)(0)>>8);
vm_vars[25]=(u8)((u32)(0)>>0);

goto L553c;
L553c: /* move.w #$1, $62fa.w */
VSTEP(0x553cul);
tv=((u16)(1L));
vm_vars[28]=(u8)((u32)(tv)>>8);
vm_vars[29]=(u8)((u32)(tv)>>0);

goto L5542;
L5542: /* move.w #$2, $62f2.w */
VSTEP(0x5542ul);
tv=((u16)(2L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L5548;
L5548: /* move.w $67be.w, D0 */
VSTEP(0x5548ul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
VWORD(d[0])=(u16)(tv);

goto L554c;
L554c: /* add.w D1, D0 */
VSTEP(0x554cul);
tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L554e;
L554e: /* andi.w #$7, D0 */
VSTEP(0x554eul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L5552;
L5552: /* sub.w D0, D1 */
VSTEP(0x5552ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L5554;
L5554: /* move.w D1, $67c4.w */
VSTEP(0x5554ul);
tv=((u16)d[1]);
vm_vars[1254]=(u8)((u32)(tv)>>8);
vm_vars[1255]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5558;
L5558: /* rts  */
VSTEP(0x5558ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L555a: /* subq.w #1, $62f2.w */
VSTEP(0x555aul);
tv=((u16)(1L));
eb=0x62f2ul;
tw=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[20]=(u8)((u32)(tr)>>8);
vm_vars[21]=(u8)((u32)(tr)>>0);
goto L555e;
L555e: /* bne $5558 */
VSTEP(0x555eul);
if(!fz)goto L5558;
goto L5560;
L5560: /* tst.b $7c874.l */
VSTEP(0x5560ul);
ea=0x7c874ul;
tv=vr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5566;
L5566: /* bne $4d82 */
VSTEP(0x5566ul);
if(!fz)goto L4d82;
goto L556a;
L556a: /* move.l #$4c3e, $3c90.w */
VSTEP(0x556aul);
v=((u32)(19518L));
ea=0x3c90ul;
vw32(ea,v);

goto L5572;
L5572: /* lea $63d3.w, A0 */
VSTEP(0x5572ul);
a[0]=0x63d3ul;
goto L5576;
L5576: /* cmpi.w #$50, $62f8.w */
VSTEP(0x5576ul);
tv=((u16)(80L));
eb=0x62f8ul;
tw=(((u16)vm_vars[26]<<8)|((u16)vm_vars[27]<<0));
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L557c;
L557c: /* bmi $5438 */
VSTEP(0x557cul);
if(fn)goto L5438;
goto L5580;
L5580: /* moveq #$5a, D6 */
VSTEP(0x5580ul);
v=((u32)(90L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5582;
L5582: /* bsr $4ccc */
VSTEP(0x5582ul);
a[7]-=4;vw32(a[7],0x5586ul);
goto L4ccc;
L5586: /* move.b #$4, $7c874.l */
VSTEP(0x5586ul);
tv=((u8)(4L));
ea=0x7c874ul;
vw8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fv=0;fc=0;
goto L558e;
L558e: /* btst #$7, $7c875.l */
VSTEP(0x558eul);
v=((u16)(7L));
eb=0x7c875ul;
w=vr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5596;
L5596: /* bne $559e */
VSTEP(0x5596ul);
if(!fz)goto L559e;
goto L5598;
L5598: /* jmp $7c862.l */
VSTEP(0x5598ul);
goto L7c862;
L559e: /* rts  */
VSTEP(0x559eul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L55a0:
v=(u16)((u16)(((u16)vm_vars[0x4de]<<8)|vm_vars[0x4df])+(u16)d[0]);
w=(u16)((u16)(((u16)vm_vars[0x4e0]<<8)|vm_vars[0x4e1])+(u16)d[1]);
v>>=3;w>>=3;w=(w<<7)+(w<<6);r=(u16)w+v;fx=(u8)(r>65535ul);
d[3]=(w&0xffff0000ul)|(u16)r;a[0]=0x807cul;
d[2]=(u16)d[3]<7872u?axis_map[(u16)d[3]]:vr8(a[0]+(s16)d[3]);fn=(u8)((d[2]&128ul)!=0);fz=(u8)(d[2]==0);fc=fv=0;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L55a6: /* add.w D0, D2 */
VSTEP(0x55a6ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L55a8;
L55a8: /* add.w D1, D3 */
VSTEP(0x55a8ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L55aa;
L55aa: /* lsr.w #3, D2 */
VSTEP(0x55aaul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L55ac;
L55ac: /* lsr.w #3, D3 */
VSTEP(0x55acul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=((u16)tw)>>3;
VWORD(d[3])=(u16)(tr);
goto L55ae;
L55ae: /* mulu.w $8002.l, D3 */
VSTEP(0x55aeul);
ea=0x8002ul;
v=192u;
w=((u32)d[3]);
r=(u32)(u16)v*(u16)w;

d[3]=r;
goto L55b4;
L55b4: /* add.w D2, D3 */
VSTEP(0x55b4ul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[3])=(u16)(tr);
goto L55b6;
L55b6: /* lea $807c.l, A0 */
VSTEP(0x55b6ul);
a[0]=0x807cul;
goto L55bc;
L55bc: /* clr.w D2 */
VSTEP(0x55bcul);
VWORD(d[2])=(u16)(0);

goto L55be;
L55be: /* move.b (A0,D3.w), D2 */
VSTEP(0x55beul);
ea=(a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L55c2;
L55c2: /* rts  */
VSTEP(0x55c2ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L56a6: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x56a6ul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L56ac;
L56ac: /* move.w $62ee.w, D2 */
VSTEP(0x56acul);
ea=0x62eeul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[2])=(u16)(tv);

goto L56b0;
L56b0: /* clr.w D4 */
VSTEP(0x56b0ul);
VWORD(d[4])=(u16)(0);

goto L56b2;
L56b2: /* move.b D2, D4 */
VSTEP(0x56b2ul);
tv=((u8)d[2]);
VBYTE(d[4])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L56b4;
L56b4: /* beq $56f2 */
VSTEP(0x56b4ul);
if(fz)goto L56f2;
goto L56b8;
L56b8: /* move.w D1, D3 */
VSTEP(0x56b8ul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L56ba;
L56ba: /* lea $607c.w, A0 */
VSTEP(0x56baul);
a[0]=0x607cul;
goto L56be;
L56be: /* add.w D4, D4 */
VSTEP(0x56beul);
tv=((u16)d[4]);
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L56c0;
L56c0: /* add.w D3, D3 */
VSTEP(0x56c0ul);
tv=((u16)d[3]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L56c2;
L56c2: /* sub.b (-$2,A0,D4.w), D3 */
VSTEP(0x56c2ul);
ea=(-2+a[0]+((s16)(d[4])));
tv=vr8(ea);
tw=((u8)d[3]);
tr=tw-tv;
VBYTE(d[3])=(u8)(tr);
goto L56c6;
L56c6: /* asr.w #1, D3 */
VSTEP(0x56c6ul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=((s16)tw)>>1;fx=(u8)((tw>>0)&1);
VWORD(d[3])=(u16)(tr);
goto L56c8;
L56c8: /* move.w D3, $62f0.w */
VSTEP(0x56c8ul);
tv=((u16)d[3]);
vm_vars[18]=(u8)((u32)(tv)>>8);
vm_vars[19]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L56cc;
L56cc: /* bsr $56f4 */
VSTEP(0x56ccul);
a[7]-=4;vw32(a[7],0x56ceul);
goto L56f4;
L56ce: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x56ceul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L56d4;
L56d4: /* move.w $62ec.w, D2 */
VSTEP(0x56d4ul);
ea=0x62ecul;
tv=(((u16)vm_vars[14]<<8)|((u16)vm_vars[15]<<0));
VWORD(d[2])=(u16)(tv);

goto L56d8;
L56d8: /* move.b D2, D2 */
VSTEP(0x56d8ul);
tv=((u8)d[2]);
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L56da;
L56da: /* beq $56f2 */
VSTEP(0x56daul);
if(fz)goto L56f2;
goto L56de;
L56de: /* bsr $56f4 */
VSTEP(0x56deul);
a[7]-=4;vw32(a[7],0x56e0ul);
goto L56f4;
L56e0: /* movem.w $67c2.w, D0-D1 */
VSTEP(0x56e0ul);
ea=0x67c2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L56e6;
L56e6: /* move.w $62ea.w, D2 */
VSTEP(0x56e6ul);
ea=0x62eaul;
tv=(((u16)vm_vars[12]<<8)|((u16)vm_vars[13]<<0));
VWORD(d[2])=(u16)(tv);

goto L56ea;
L56ea: /* move.b D2, D2 */
VSTEP(0x56eaul);
tv=((u8)d[2]);
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L56ec;
L56ec: /* beq $56f2 */
VSTEP(0x56ecul);
if(fz)goto L56f2;
goto L56f0;
L56f0: /* bsr $56f4 */
VSTEP(0x56f0ul);
a[7]-=4;vw32(a[7],0x56f2ul);
goto L56f4;
L56f2: /* rts  */
VSTEP(0x56f2ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L58aa: /* clr.l D0 */
VSTEP(0x58aaul);
d[0]=0;

goto L58ac;
L58ac: /* move.w $67bc.w, D0 */
VSTEP(0x58acul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
VWORD(d[0])=(u16)(tv);

goto L58b0;
L58b0: /* lsr.w #3, D0 */
VSTEP(0x58b0ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=((u16)tw)>>3;
VWORD(d[0])=(u16)(tr);
goto L58b2;
L58b2: /* add.w D0, D0 */
VSTEP(0x58b2ul);
tv=((u16)d[0]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L58b4;
L58b4: /* movea.l #$5a36c, A4 */
VSTEP(0x58b4ul);
v=((u32)(369516L));
a[4]=v;
goto L58ba;
L58ba: /* adda.l D0, A4 */
VSTEP(0x58baul);
v=((u32)d[0]);
w=((u32)a[4]);
r=w+v;
a[4]=r;
goto L58bc;
L58bc: /* move.l A4, $631e.w */
VSTEP(0x58bcul);
v=((u32)a[4]);
vm_vars[64]=(u8)((u32)(v)>>24);
vm_vars[65]=(u8)((u32)(v)>>16);
vm_vars[66]=(u8)((u32)(v)>>8);
vm_vars[67]=(u8)((u32)(v)>>0);

goto L58c0;
L58c0: /* clr.w $6312.w */
VSTEP(0x58c0ul);
vm_vars[52]=(u8)((u32)(0)>>8);
vm_vars[53]=(u8)((u32)(0)>>0);

goto L58c4;
L58c4: /* clr.l D1 */
VSTEP(0x58c4ul);
d[1]=0;

goto L58c6;
L58c6: /* move.w $67bc.w, D1 */
VSTEP(0x58c6ul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
VWORD(d[1])=(u16)(tv);

goto L58ca;
L58ca: /* moveq #$14, D7 */
VSTEP(0x58caul);
v=((u32)(20L));
d[7]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L58cc;
L58cc: /* movem.l D1/D7/A4, -(A7) */
VSTEP(0x58ccul);
a[7]-=4;
vw32(a[7],a[4]);
a[7]-=4;
vw32(a[7],d[7]);
a[7]-=4;
vw32(a[7],d[1]);
goto L58d0;
L58d0: /* bsr $4ad6 */
VSTEP(0x58d0ul);
a[7]-=4;vw32(a[7],0x58d4ul);
goto L4ad6;
L58d4: /* movem.l (A7)+, D1/D7/A4 */
VSTEP(0x58d4ul);
ea=a[7];
d[1]=vr32(ea+0);
d[7]=vr32(ea+4);
a[4]=vr32(ea+8);
a[7]+=12;
goto L58d8;
L58d8: /* addq.w #8, D1 */
VSTEP(0x58d8ul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L58da;
L58da: /* addq.l #2, A4 */
VSTEP(0x58daul);
v=((u32)(2L));
w=((u32)a[4]);
r=w+v;
a[4]=r;
goto L58dc;
L58dc: /* dbra D7, $58cc */
VSTEP(0x58dcul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L58cc;
goto L58e0;
L58e0: /* rts  */
VSTEP(0x58e0ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5ae4: /* moveq #$1, D0 */
VSTEP(0x5ae4ul);
v=((u32)(1L));
d[0]=v;

goto L5ae6;
L5ae6: /* cmp.w $62fc.w, D0 */
VSTEP(0x5ae6ul);
ea=0x62fcul;
tv=(((u16)vm_vars[30]<<8)|((u16)vm_vars[31]<<0));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5aea;
L5aea: /* bcs $5b02 */
VSTEP(0x5aeaul);
if(fc)goto L5b02;
goto L5aec;
L5aec: /* bra $5afe */
VSTEP(0x5aecul);
goto L5afe;
L5aee: /* moveq #$2, D0 */
VSTEP(0x5aeeul);
v=((u32)(2L));
d[0]=v;

goto L5af0;
L5af0: /* cmp.w $62fc.w, D0 */
VSTEP(0x5af0ul);
ea=0x62fcul;
tv=(((u16)vm_vars[30]<<8)|((u16)vm_vars[31]<<0));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5af4;
L5af4: /* bcs $5b02 */
VSTEP(0x5af4ul);
if(fc)goto L5b02;
goto L5af6;
L5af6: /* bra $5afe */
VSTEP(0x5af6ul);
goto L5afe;
L5af8: /* moveq #$3, D0 */
VSTEP(0x5af8ul);
v=((u32)(3L));
d[0]=v;

goto L5afa;
L5afa: /* cmp.w $62fc.w, D0 */
VSTEP(0x5afaul);
ea=0x62fcul;
tv=(((u16)vm_vars[30]<<8)|((u16)vm_vars[31]<<0));
tw=((u16)d[0]);

goto L5afe;
L5afe: /* move.w D0, $62fc.w */
VSTEP(0x5afeul);
tv=((u16)d[0]);
vm_vars[30]=(u8)((u32)(tv)>>8);
vm_vars[31]=(u8)((u32)(tv)>>0);

goto L5b02;
L5b02: /* clr.w (A6) */
VSTEP(0x5b02ul);
ea=a[6];
vw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5b04;
L5b04: /* rts  */
VSTEP(0x5b04ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5b06: /* move.w #$590, D0 */
VSTEP(0x5b06ul);
tv=((u16)(1424L));
VWORD(d[0])=(u16)(tv);

goto L5b0a;
L5b0a: /* sub.w $67bc.w, D0 */
VSTEP(0x5b0aul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5b0e;
L5b0e: /* addq.w #2, ($a,A6) */
VSTEP(0x5b0eul);
tv=((u16)(2L));
eb=(10+a[6]);
tw=vr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vw16(eb,tr);
goto L5b12;
L5b12: /* movea.l ($8,A6), A5 */
VSTEP(0x5b12ul);
ea=(8+a[6]);
v=vr32(ea);
a[5]=v;
goto L5b16;
L5b16: /* move.w (A5), D2 */
VSTEP(0x5b16ul);
ea=a[5];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5b18;
L5b18: /* bpl $45bc */
VSTEP(0x5b18ul);
if(!fn)goto L45bc;
goto L5b1c;
L5b1c: /* bsr $36fa */
VSTEP(0x5b1cul);
a[7]-=4;vw32(a[7],0x5b20ul);
goto L36fa;
L5b20: /* moveq #$32, D0 */
VSTEP(0x5b20ul);
v=((u32)(50L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5b22;
L5b22: /* bsr $5e8c */
VSTEP(0x5b22ul);
a[7]-=4;vw32(a[7],0x5b26ul);
goto L5e8c;
L5b26: /* bra $5e3a */
VSTEP(0x5b26ul);
goto L5e3a;
L5b5c: /* move.w #$98, ($4,A6) */
VSTEP(0x5b5cul);
tv=((u16)(152L));
ea=(4+a[6]);
vw16(ea,tv);

goto L5b62;
L5b62: /* lea $39c8.w, A5 */
VSTEP(0x5b62ul);
a[5]=0x39c8ul;
goto L5b66;
L5b66: /* move.w #$85, D2 */
VSTEP(0x5b66ul);
tv=((u16)(133L));
VWORD(d[2])=(u16)(tv);

goto L5b6a;
L5b6a: /* moveq #$9, D7 */
VSTEP(0x5b6aul);
v=((u32)(9L));
d[7]=v;

goto L5b6c;
L5b6c: /* cmp.w ($6,A5), D2 */
VSTEP(0x5b6cul);
ea=(6+a[5]);
tv=vr16(ea);
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L5b70;
L5b70: /* beq $5b7c */
VSTEP(0x5b70ul);
if(fz)goto L5b7c;
goto L5b72;
L5b72: /* lea ($16,A5), A5 */
VSTEP(0x5b72ul);
a[5]=(22+a[5]);
goto L5b76;
L5b76: /* dbra D7, $5b6c */
VSTEP(0x5b76ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L5b6c;
goto L5b7a;
L5b7a: /* bra $5b80 */
VSTEP(0x5b7aul);
goto L5b80;
L5b7c: /* move.w (A5), D2 */
VSTEP(0x5b7cul);
ea=a[5];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5b7e;
L5b7e: /* bne $5b8c */
VSTEP(0x5b7eul);
if(!fz)goto L5b8c;
goto L5b80;
L5b80: /* bclr #$7, $670a.l */
VSTEP(0x5b80ul);
v=((u16)(7L));
eb=0x670aul;
w=(((u8)vm_vars[1068]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
vm_vars[1068]=(u8)((u32)(r)>>0);
goto L5b88;
L5b88: /* clr.w (A6) */
VSTEP(0x5b88ul);
ea=a[6];
vw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5b8a;
L5b8a: /* rts  */
VSTEP(0x5b8aul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5b8c: /* subq.w #1, D2 */
VSTEP(0x5b8cul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5b8e;
L5b8e: /* bne $5b8a */
VSTEP(0x5b8eul);
if(!fz)goto L5b8a;
goto L5b90;
L5b90: /* jsr $48008.l */
VSTEP(0x5b90ul);
a[7]-=4;vw32(a[7],0x5b96ul);
goto L48008;
L5b96: /* bset #$0, $7c874.l */
VSTEP(0x5b96ul);
v=((u16)(0L));
eb=0x7c874ul;
w=vr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
vw8(eb,r);
goto L5b9e;
L5b9e: /* move.w #$5290, $3c92.w */
VSTEP(0x5b9eul);
tv=((u16)(21136L));
vm_player_state=(u16)(tv);

goto L5ba4;
L5ba4: /* clr.w $62fa.w */
VSTEP(0x5ba4ul);
vm_vars[28]=(u8)((u32)(0)>>8);
vm_vars[29]=(u8)((u32)(0)>>0);

goto L5ba8;
L5ba8: /* clr.w $6318.w */
VSTEP(0x5ba8ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L5bac;
L5bac: /* move.w ($4,A5), D0 */
VSTEP(0x5bacul);
ea=(4+a[5]);
tv=vr16(ea);
VWORD(d[0])=(u16)(tv);

goto L5bb0;
L5bb0: /* cmpi.w #$d4, D0 */
VSTEP(0x5bb0ul);
tv=((u16)(212L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5bb4;
L5bb4: /* bcs $5bd2 */
VSTEP(0x5bb4ul);
if(fc)goto L5bd2;
goto L5bb6;
L5bb6: /* move.w #$81, ($6,A5) */
VSTEP(0x5bb6ul);
tv=((u16)(129L));
ea=(6+a[5]);
vw16(ea,tv);

goto L5bbc;
L5bbc: /* move.l #$5b28, ($8,A5) */
VSTEP(0x5bbcul);
v=((u32)(23336L));
ea=(8+a[5]);
vw32(ea,v);

goto L5bc4;
L5bc4: /* move.w #$19, (A5) */
VSTEP(0x5bc4ul);
tv=((u16)(25L));
ea=a[5];
vw16(ea,tv);

goto L5bc8;
L5bc8: /* clr.w (A6) */
VSTEP(0x5bc8ul);
ea=a[6];
vw16(ea,0);

goto L5bca;
L5bca: /* moveq #$b, D0 */
VSTEP(0x5bcaul);
v=((u32)(11L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5bcc;
L5bcc: /* jmp $48014.l */
VSTEP(0x5bccul);
goto L48014;
L5bd2: /* subq.w #1, $67c8.w */
VSTEP(0x5bd2ul);
tv=((u16)(1L));
eb=0x67c8ul;
tw=(((u16)vm_vars[1258]<<8)|((u16)vm_vars[1259]<<0));
tr=tw-tv;
vm_vars[1258]=(u8)((u32)(tr)>>8);
vm_vars[1259]=(u8)((u32)(tr)>>0);
goto L5bd6;
L5bd6: /* subi.w #$18, D0 */
VSTEP(0x5bd6ul);
tv=((u16)(24L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5bda;
L5bda: /* sub.w $67be.w, D0 */
VSTEP(0x5bdaul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5bde;
L5bde: /* neg.w D0 */
VSTEP(0x5bdeul);
tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L5be0;
L5be0: /* add.w $67c4.w, D0 */
VSTEP(0x5be0ul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5be4;
L5be4: /* move.w D0, $67c6.w */
VSTEP(0x5be4ul);
tv=((u16)d[0]);
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5be8;
L5be8: /* rts  */
VSTEP(0x5be8ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5bea: /* bsr $5c20 */
VSTEP(0x5beaul);
a[7]-=4;vw32(a[7],0x5becul);
goto L5c20;
L5bec: /* cmpi.w #$8, D2 */
VSTEP(0x5becul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5bf0;
L5bf0: /* bcc $5be8 */
VSTEP(0x5bf0ul);
if(!fc)goto L5be8;
goto L5bf2;
L5bf2: /* cmpi.w #$4, D2 */
VSTEP(0x5bf2ul);
tv=((u16)(4L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5bf6;
L5bf6: /* bne $45bc */
VSTEP(0x5bf6ul);
if(!fz)goto L45bc;
goto L5bfa;
L5bfa: /* bsr $5c4e */
VSTEP(0x5bfaul);
a[7]-=4;vw32(a[7],0x5bfcul);
goto L5c4e;
L5bfc: /* moveq #$4, D2 */
VSTEP(0x5bfcul);
v=((u32)(4L));
d[2]=v;

goto L5bfe;
L5bfe: /* bra $45bc */
VSTEP(0x5bfeul);
goto L45bc;
L5c02: /* bsr $5c20 */
VSTEP(0x5c02ul);
a[7]-=4;vw32(a[7],0x5c04ul);
goto L5c20;
L5c04: /* ori.w #$e000, D2 */
VSTEP(0x5c04ul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw|tv;

VWORD(d[2])=(u16)(tr);
goto L5c08;
L5c08: /* cmpi.w #-$1ff8, D2 */
VSTEP(0x5c08ul);
tv=((u16)(-8184L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c0c;
L5c0c: /* bcc $5be8 */
VSTEP(0x5c0cul);
if(!fc)goto L5be8;
goto L5c0e;
L5c0e: /* cmpi.w #-$1ffc, D2 */
VSTEP(0x5c0eul);
tv=((u16)(-8188L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c12;
L5c12: /* bne $45bc */
VSTEP(0x5c12ul);
if(!fz)goto L45bc;
goto L5c16;
L5c16: /* bsr $5c42 */
VSTEP(0x5c16ul);
a[7]-=4;vw32(a[7],0x5c18ul);
goto L5c42;
L5c18: /* move.w #$e004, D2 */
VSTEP(0x5c18ul);
tv=((u16)(57348L));
VWORD(d[2])=(u16)(tv);

goto L5c1c;
L5c1c: /* bra $45bc */
VSTEP(0x5c1cul);
goto L45bc;
L5c20: /* clr.w D2 */
VSTEP(0x5c20ul);
VWORD(d[2])=(u16)(0);

goto L5c22;
L5c22: /* move.w ($8,A6), D2 */
VSTEP(0x5c22ul);
ea=(8+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L5c26;
L5c26: /* addq.b #4, D2 */
VSTEP(0x5c26ul);
tv=((u8)(4L));
tw=((u8)d[2]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[2])=(u8)(tr);
goto L5c28;
L5c28: /* bcc $5c32 */
VSTEP(0x5c28ul);
if(!fc)goto L5c32;
goto L5c2a;
L5c2a: /* moveq #$6, D2 */
VSTEP(0x5c2aul);
v=((u32)(6L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5c2c;
L5c2c: /* bsr $44b6 */
VSTEP(0x5c2cul);
a[7]-=4;vw32(a[7],0x5c30ul);
goto L44b6;
L5c30: /* clr.w D2 */
VSTEP(0x5c30ul);
VWORD(d[2])=(u16)(0);

goto L5c32;
L5c32: /* move.w D2, ($8,A6) */
VSTEP(0x5c32ul);
tv=((u16)d[2]);
ea=(8+a[6]);
vw16(ea,tv);

goto L5c36;
L5c36: /* cmpi.w #$37, D2 */
VSTEP(0x5c36ul);
tv=((u16)(55L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c3a;
L5c3a: /* bcc $5c40 */
VSTEP(0x5c3aul);
if(!fc)goto L5c40;
goto L5c3c;
L5c3c: /* lsr.w #3, D2 */
VSTEP(0x5c3cul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L5c3e;
L5c3e: /* addq.w #1, D2 */
VSTEP(0x5c3eul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5c40;
L5c40: /* rts  */
VSTEP(0x5c40ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5c42: /* movem.w $67c2.w, D3-D4 */
VSTEP(0x5c42ul);
ea=0x67c2ul;
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L5c48;
L5c48: /* addi.w #$10, D3 */
VSTEP(0x5c48ul);
tv=((u16)(16L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5c4c;
L5c4c: /* bra $5c56 */
VSTEP(0x5c4cul);
goto L5c56;
L5c4e: /* movem.w $67c2.w, D3-D4 */
VSTEP(0x5c4eul);
ea=0x67c2ul;
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L5c54;
L5c54: /* addq.w #4, D3 */
VSTEP(0x5c54ul);
tv=((u16)(4L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5c56;
L5c56: /* sub.w D0, D3 */
VSTEP(0x5c56ul);
tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L5c58;
L5c58: /* cmpi.w #$16, D3 */
VSTEP(0x5c58ul);
tv=((u16)(22L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c5c;
L5c5c: /* bcc $5c40 */
VSTEP(0x5c5cul);
if(!fc)goto L5c40;
goto L5c5e;
L5c5e: /* cmp.w D1, D4 */
VSTEP(0x5c5eul);
tv=((u16)d[1]);
tw=((u16)d[4]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c60;
L5c60: /* bmi $5c40 */
VSTEP(0x5c60ul);
if(fn)goto L5c40;
goto L5c62;
L5c62: /* cmp.w $62f0.w, D1 */
VSTEP(0x5c62ul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c66;
L5c66: /* bmi $5c40 */
VSTEP(0x5c66ul);
if(fn)goto L5c40;
goto L5c68;
L5c68: /* moveq #$3, D6 */
VSTEP(0x5c68ul);
v=((u32)(3L));
d[6]=v;

goto L5c6a;
L5c6a: /* bra $4ccc */
VSTEP(0x5c6aul);
goto L4ccc;
L5c6e: /* move.w ($c,A6), D3 */
VSTEP(0x5c6eul);
ea=(12+a[6]);
tv=vr16(ea);
VWORD(d[3])=(u16)(tv);

goto L5c72;
L5c72: /* addq.b #6, D3 */
VSTEP(0x5c72ul);
tv=((u8)(6L));
tw=((u8)d[3]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[3])=(u8)(tr);
goto L5c74;
L5c74: /* move.w D3, ($c,A6) */
VSTEP(0x5c74ul);
tv=((u16)d[3]);
ea=(12+a[6]);
vw16(ea,tv);

goto L5c78;
L5c78: /* cmpi.b #$20, D3 */
VSTEP(0x5c78ul);
tv=((u8)(32L));
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5c7c;
L5c7c: /* bcs $5c40 */
VSTEP(0x5c7cul);
if(fc)goto L5c40;
goto L5c7e;
L5c7e: /* moveq #$1, D2 */
VSTEP(0x5c7eul);
v=((u32)(1L));
d[2]=v;

goto L5c80;
L5c80: /* cmpi.b #$40, D3 */
VSTEP(0x5c80ul);
tv=((u8)(64L));
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);
goto L5c84;
L5c84: /* bcs $45bc */
VSTEP(0x5c84ul);
if(fc)goto L45bc;
goto L5c88;
L5c88: /* move.w ($a,A6), D5 */
VSTEP(0x5c88ul);
ea=(10+a[6]);
tv=vr16(ea);
VWORD(d[5])=(u16)(tv);

goto L5c8c;
L5c8c: /* cmpi.w #$10, D5 */
VSTEP(0x5c8cul);
tv=((u16)(16L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L5c90;
L5c90: /* bcc $5c96 */
VSTEP(0x5c90ul);
if(!fc)goto L5c96;
goto L5c94;
L5c94: /* addq.w #1, D5 */
VSTEP(0x5c94ul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L5c96;
L5c96: /* move.w D5, ($a,A6) */
VSTEP(0x5c96ul);
tv=((u16)d[5]);
ea=(10+a[6]);
vw16(ea,tv);

goto L5c9a;
L5c9a: /* lsr.w #1, D5 */
VSTEP(0x5c9aul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=((u16)tw)>>1;
VWORD(d[5])=(u16)(tr);
goto L5c9c;
L5c9c: /* add.w ($8,A6), D5 */
VSTEP(0x5c9cul);
ea=(8+a[6]);
tv=vr16(ea);
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L5ca0;
L5ca0: /* move.w D5, ($8,A6) */
VSTEP(0x5ca0ul);
tv=((u16)d[5]);
ea=(8+a[6]);
vw16(ea,tv);

goto L5ca4;
L5ca4: /* add.w D5, D1 */
VSTEP(0x5ca4ul);
tv=((u16)d[5]);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5ca6;
L5ca6: /* bsr $55a0 */
VSTEP(0x5ca6ul);
a[7]-=4;vw32(a[7],0x5caaul);
goto L55a0;
L5caa: /* cmpi.b #$79, D2 */
VSTEP(0x5caaul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5cae;
L5cae: /* bcs $5cd8 */
VSTEP(0x5caeul);
if(fc)goto L5cd8;
goto L5cb0;
L5cb0: /* move.w $67be.w, D3 */
VSTEP(0x5cb0ul);
ea=0x67beul;
tv=(((u16)vm_vars[1248]<<8)|((u16)vm_vars[1249]<<0));
VWORD(d[3])=(u16)(tv);

goto L5cb4;
L5cb4: /* add.w D1, D3 */
VSTEP(0x5cb4ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5cb6;
L5cb6: /* andi.w #$7, D3 */
VSTEP(0x5cb6ul);
tv=((u16)(7L));
tw=((u16)d[3]);
tr=tw&tv;

VWORD(d[3])=(u16)(tr);
goto L5cba;
L5cba: /* not.w D3 */
VSTEP(0x5cbaul);
tv=((u16)d[3]);
tr=~tv;
VWORD(d[3])=(u16)(tr);

goto L5cbc;
L5cbc: /* add.w D3, D1 */
VSTEP(0x5cbcul);
tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L5cbe;
L5cbe: /* moveq #$4, D2 */
VSTEP(0x5cbeul);
v=((u32)(4L));
d[2]=v;

goto L5cc0;
L5cc0: /* eor.w D2, ($2,A6) */
VSTEP(0x5cc0ul);
tv=((u16)d[2]);
eb=(2+a[6]);
tw=vr16(eb);
tr=tw^tv;

vw16(eb,tr);
goto L5cc4;
L5cc4: /* clr.l ($8,A6) */
VSTEP(0x5cc4ul);
ea=(8+a[6]);
vw32(ea,0);

goto L5cc8;
L5cc8: /* clr.w ($c,A6) */
VSTEP(0x5cc8ul);
ea=(12+a[6]);
vw16(ea,0);

goto L5ccc;
L5ccc: /* moveq #$5, D2 */
VSTEP(0x5cccul);
v=((u32)(5L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5cce;
L5cce: /* bsr $44b6 */
VSTEP(0x5cceul);
a[7]-=4;vw32(a[7],0x5cd2ul);
goto L44b6;
L5cd2: /* moveq #$2, D2 */
VSTEP(0x5cd2ul);
v=((u32)(2L));
d[2]=v;

goto L5cd4;
L5cd4: /* bra $45bc */
VSTEP(0x5cd4ul);
goto L45bc;
L5cd8: /* moveq #$1, D2 */
VSTEP(0x5cd8ul);
v=((u32)(1L));
d[2]=v;

goto L5cda;
L5cda: /* move.w $67c2.w, D3 */
VSTEP(0x5cdaul);
ea=0x67c2ul;
tv=(((u16)vm_vars[1252]<<8)|((u16)vm_vars[1253]<<0));
VWORD(d[3])=(u16)(tv);

goto L5cde;
L5cde: /* sub.w D0, D3 */
VSTEP(0x5cdeul);
tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L5ce0;
L5ce0: /* addq.w #3, D3 */
VSTEP(0x5ce0ul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[3])=(u16)(tr);
goto L5ce2;
L5ce2: /* cmpi.w #$7, D3 */
VSTEP(0x5ce2ul);
tv=((u16)(7L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L5ce6;
L5ce6: /* bcc $45bc */
VSTEP(0x5ce6ul);
if(!fc)goto L45bc;
goto L5cea;
L5cea: /* cmp.w $62f0.w, D1 */
VSTEP(0x5ceaul);
ea=0x62f0ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5cee;
L5cee: /* bmi $45bc */
VSTEP(0x5ceeul);
if(fn)goto L45bc;
goto L5cf2;
L5cf2: /* cmp.w $67c4.w, D1 */
VSTEP(0x5cf2ul);
ea=0x67c4ul;
tv=(((u16)vm_vars[1254]<<8)|((u16)vm_vars[1255]<<0));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5cf6;
L5cf6: /* bpl $45bc */
VSTEP(0x5cf6ul);
if(!fn)goto L45bc;
goto L5cfa;
L5cfa: /* moveq #$2, D6 */
VSTEP(0x5cfaul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5cfc;
L5cfc: /* bsr $4ccc */
VSTEP(0x5cfcul);
a[7]-=4;vw32(a[7],0x5d00ul);
goto L4ccc;
L5d00: /* bra $5cbe */
VSTEP(0x5d00ul);
goto L5cbe;
L5d02: /* rts  */
VSTEP(0x5d02ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5d04: /* move.w ($4,A6), D2 */
VSTEP(0x5d04ul);
ea=(4+a[6]);
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);

goto L5d08;
L5d08: /* not.w D2 */
VSTEP(0x5d08ul);
tv=((u16)d[2]);
tr=~tv;
VWORD(d[2])=(u16)(tr);

goto L5d0a;
L5d0a: /* andi.w #$7, D2 */
VSTEP(0x5d0aul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5d0e;
L5d0e: /* bclr #$2, D2 */
VSTEP(0x5d0eul);
v=((u16)(2L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L5d12;
L5d12: /* bne $5d18 */
VSTEP(0x5d12ul);
if(!fz)goto L5d18;
goto L5d14;
L5d14: /* addi.w #-$2000, D2 */
VSTEP(0x5d14ul);
tv=((u16)(-8192L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5d18;
L5d18: /* move.w D2, -(A7) */
VSTEP(0x5d18ul);
tv=((u16)d[2]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);

goto L5d1a;
L5d1a: /* addq.w #2, D2 */
VSTEP(0x5d1aul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d1c;
L5d1c: /* bsr $45bc */
VSTEP(0x5d1cul);
a[7]-=4;vw32(a[7],0x5d20ul);
goto L45bc;
L5d20: /* move.w (A7)+, D2 */
VSTEP(0x5d20ul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L5d22;
L5d22: /* andi.w #$e000, D2 */
VSTEP(0x5d22ul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5d26;
L5d26: /* addq.w #1, D2 */
VSTEP(0x5d26ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d28;
L5d28: /* bsr $458a */
VSTEP(0x5d28ul);
a[7]-=4;vw32(a[7],0x5d2cul);
goto L458a;
L5d2c: /* btst #$0, $632d.w */
VSTEP(0x5d2cul);
v=((u16)(0L));
eb=0x632dul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5d32;
L5d32: /* beq $5d02 */
VSTEP(0x5d32ul);
if(fz)goto L5d02;
goto L5d34;
L5d34: /* subq.w #1, ($4,A6) */
VSTEP(0x5d34ul);
tv=((u16)(1L));
eb=(4+a[6]);
tw=vr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vw16(eb,tr);
goto L5d38;
L5d38: /* bmi $5d82 */
VSTEP(0x5d38ul);
if(fn)goto L5d82;
goto L5d3a;
L5d3a: /* rts  */
VSTEP(0x5d3aul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5d3c: /* btst #$0, $632d.w */
VSTEP(0x5d3cul);
v=((u16)(0L));
eb=0x632dul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5d42;
L5d42: /* beq $5d54 */
VSTEP(0x5d42ul);
if(fz)goto L5d54;
goto L5d44;
L5d44: /* movem.l D0-D1/A6, -(A7) */
VSTEP(0x5d44ul);
a[7]-=4;
vw32(a[7],a[6]);
a[7]-=4;
vw32(a[7],d[1]);
a[7]-=4;
vw32(a[7],d[0]);
goto L5d48;
L5d48: /* moveq #$b, D0 */
VSTEP(0x5d48ul);
v=((u32)(11L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5d4a;
L5d4a: /* jsr $48014.l */
VSTEP(0x5d4aul);
a[7]-=4;vw32(a[7],0x5d50ul);
goto L48014;
L5d50: /* movem.l (A7)+, D0-D1/A6 */
VSTEP(0x5d50ul);
ea=a[7];
d[0]=vr32(ea+0);
d[1]=vr32(ea+4);
a[6]=vr32(ea+8);
a[7]+=12;
goto L5d54;
L5d54: /* move.w $632c.w, D2 */
VSTEP(0x5d54ul);
ea=0x632cul;
tv=(((u16)vm_vars[78]<<8)|((u16)vm_vars[79]<<0));
VWORD(d[2])=(u16)(tv);

goto L5d58;
L5d58: /* lsr.w #2, D2 */
VSTEP(0x5d58ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L5d5a;
L5d5a: /* andi.w #$3, D2 */
VSTEP(0x5d5aul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5d5e;
L5d5e: /* addq.w #1, D2 */
VSTEP(0x5d5eul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d60;
L5d60: /* bsr $45bc */
VSTEP(0x5d60ul);
a[7]-=4;vw32(a[7],0x5d64ul);
goto L45bc;
L5d64: /* subi.w #$10, D1 */
VSTEP(0x5d64ul);
tv=((u16)(16L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5d68;
L5d68: /* bpl $5d54 */
VSTEP(0x5d68ul);
if(!fn)goto L5d54;
goto L5d6a;
L5d6a: /* lea $39c8.w, A5 */
VSTEP(0x5d6aul);
a[5]=0x39c8ul;
goto L5d6e;
L5d6e: /* move.w #$103, D2 */
VSTEP(0x5d6eul);
tv=((u16)(259L));
VWORD(d[2])=(u16)(tv);

goto L5d72;
L5d72: /* moveq #$9, D7 */
VSTEP(0x5d72ul);
v=((u32)(9L));
d[7]=v;

goto L5d74;
L5d74: /* cmp.w ($6,A5), D2 */
VSTEP(0x5d74ul);
ea=(6+a[5]);
tv=vr16(ea);
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L5d78;
L5d78: /* beq $5d88 */
VSTEP(0x5d78ul);
if(fz)goto L5d88;
goto L5d7a;
L5d7a: /* lea ($16,A5), A5 */
VSTEP(0x5d7aul);
a[5]=(22+a[5]);
goto L5d7e;
L5d7e: /* dbra D7, $5d74 */
VSTEP(0x5d7eul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L5d74;
goto L5d82;
L5d82: /* moveq #$5a, D6 */
VSTEP(0x5d82ul);
v=((u32)(90L));
d[6]=v;

goto L5d84;
L5d84: /* bra $4ccc */
VSTEP(0x5d84ul);
goto L4ccc;
L5d88: /* move.w (A5), D2 */
VSTEP(0x5d88ul);
ea=a[5];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5d8a;
L5d8a: /* beq $5d82 */
VSTEP(0x5d8aul);
if(fz)goto L5d82;
goto L5d8c;
L5d8c: /* subq.w #1, D2 */
VSTEP(0x5d8cul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d8e;
L5d8e: /* bne $5d02 */
VSTEP(0x5d8eul);
if(!fz)goto L5d02;
goto L5d92;
L5d92: /* move.w #$5290, $3c92.w */
VSTEP(0x5d92ul);
tv=((u16)(21136L));
vm_player_state=(u16)(tv);

goto L5d98;
L5d98: /* move.w #$21, (A5) */
VSTEP(0x5d98ul);
tv=((u16)(33L));
ea=a[5];
vw16(ea,tv);

goto L5d9c;
L5d9c: /* clr.w $6318.w */
VSTEP(0x5d9cul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L5da0;
L5da0: /* move.w #$ffff, $62fa.w */
VSTEP(0x5da0ul);
tv=((u16)(65535L));
vm_vars[28]=(u8)((u32)(tv)>>8);
vm_vars[29]=(u8)((u32)(tv)>>0);

goto L5da6;
L5da6: /* move.b #$1, $7c874.l */
VSTEP(0x5da6ul);
tv=((u8)(1L));
ea=0x7c874ul;
vw8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5dae;
L5dae: /* rts  */
VSTEP(0x5daeul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5db0: /* move.w $67bc.w, D2 */
VSTEP(0x5db0ul);
ea=0x67bcul;
tv=(((u16)vm_vars[1246]<<8)|((u16)vm_vars[1247]<<0));
VWORD(d[2])=(u16)(tv);

goto L5db4;
L5db4: /* cmpi.w #$540, D2 */
VSTEP(0x5db4ul);
tv=((u16)(1344L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L5db8;
L5db8: /* beq $5dce */
VSTEP(0x5db8ul);
if(fz)goto L5dce;
goto L5dba;
L5dba: /* addq.w #2, ($2,A6) */
VSTEP(0x5dbaul);
tv=((u16)(2L));
eb=(2+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L5dbe;
L5dbe: /* moveq #$70, D2 */
VSTEP(0x5dbeul);
v=((u32)(112L));
d[2]=v;

goto L5dc0;
L5dc0: /* sub.w D0, D2 */
VSTEP(0x5dc0ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5dc2;
L5dc2: /* cmpi.w #-$3, D2 */
VSTEP(0x5dc2ul);
tv=((u16)(-3L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5dc6;
L5dc6: /* bcc $5dca */
VSTEP(0x5dc6ul);
if(!fc)goto L5dca;
goto L5dc8;
L5dc8: /* moveq #-$2, D2 */
VSTEP(0x5dc8ul);
v=((u32)(-2L));
d[2]=v;

goto L5dca;
L5dca: /* add.w D2, $67c8.w */
VSTEP(0x5dcaul);
tv=((u16)d[2]);
eb=0x67c8ul;
tw=(((u16)vm_vars[1258]<<8)|((u16)vm_vars[1259]<<0));
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vm_vars[1258]=(u8)((u32)(tr)>>8);
vm_vars[1259]=(u8)((u32)(tr)>>0);
goto L5dce;
L5dce: /* cmpi.w #$48, D1 */
VSTEP(0x5dceul);
tv=((u16)(72L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L5dd2;
L5dd2: /* bcc $5e26 */
VSTEP(0x5dd2ul);
if(!fc)goto L5e26;
goto L5dd4;
L5dd4: /* move.w ($a,A6), D3 */
VSTEP(0x5dd4ul);
ea=(10+a[6]);
tv=vr16(ea);
VWORD(d[3])=(u16)(tv);

goto L5dd8;
L5dd8: /* cmpi.w #$e, D3 */
VSTEP(0x5dd8ul);
tv=((u16)(14L));
tw=((u16)d[3]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5ddc;
L5ddc: /* bpl $5de4 */
VSTEP(0x5ddcul);
if(!fn)goto L5de4;
goto L5dde;
L5dde: /* addq.w #1, D3 */
VSTEP(0x5ddeul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5de0;
L5de0: /* move.w D3, ($a,A6) */
VSTEP(0x5de0ul);
tv=((u16)d[3]);
ea=(10+a[6]);
vw16(ea,tv);

goto L5de4;
L5de4: /* asr.w #1, D3 */
VSTEP(0x5de4ul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=((s16)tw)>>1;
VWORD(d[3])=(u16)(tr);
goto L5de6;
L5de6: /* add.w D3, ($4,A6) */
VSTEP(0x5de6ul);
tv=((u16)d[3]);
eb=(4+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L5dea;
L5dea: /* moveq #$18, D2 */
VSTEP(0x5deaul);
v=((u32)(24L));
d[2]=v;

goto L5dec;
L5dec: /* sub.w D1, D2 */
VSTEP(0x5decul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5dee;
L5dee: /* add.w D2, $67c6.w */
VSTEP(0x5deeul);
tv=((u16)d[2]);
eb=0x67c6ul;
tw=(((u16)vm_vars[1256]<<8)|((u16)vm_vars[1257]<<0));
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vm_vars[1256]=(u8)((u32)(tr)>>8);
vm_vars[1257]=(u8)((u32)(tr)>>0);
goto L5df2;
L5df2: /* moveq #$6, D2 */
VSTEP(0x5df2ul);
v=((u32)(6L));
d[2]=v;

goto L5df4;
L5df4: /* cmpi.w #$4, D3 */
VSTEP(0x5df4ul);
tv=((u16)(4L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5df8;
L5df8: /* bmi $5e10 */
VSTEP(0x5df8ul);
if(fn)goto L5e10;
goto L5dfa;
L5dfa: /* moveq #$7, D2 */
VSTEP(0x5dfaul);
v=((u32)(7L));
d[2]=v;

goto L5dfc;
L5dfc: /* cmpi.w #$7, D2 */
VSTEP(0x5dfcul);
tv=((u16)(7L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5e00;
L5e00: /* bmi $5e10 */
VSTEP(0x5e00ul);
if(fn)goto L5e10;
goto L5e02;
L5e02: /* moveq #$c, D2 */
VSTEP(0x5e02ul);
v=((u32)(12L));
d[2]=v;

goto L5e04;
L5e04: /* and.w $632c.w, D2 */
VSTEP(0x5e04ul);
ea=0x632cul;
tv=(((u16)vm_vars[78]<<8)|((u16)vm_vars[79]<<0));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5e08;
L5e08: /* lsr.w #2, D2 */
VSTEP(0x5e08ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L5e0a;
L5e0a: /* bne $5e0e */
VSTEP(0x5e0aul);
if(!fz)goto L5e0e;
goto L5e0c;
L5e0c: /* moveq #$2, D2 */
VSTEP(0x5e0cul);
v=((u32)(2L));
d[2]=v;

goto L5e0e;
L5e0e: /* addq.w #7, D2 */
VSTEP(0x5e0eul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5e10;
L5e10: /* bsr $45bc */
VSTEP(0x5e10ul);
a[7]-=4;vw32(a[7],0x5e14ul);
goto L45bc;
L5e14: /* jsr $48004.l */
VSTEP(0x5e14ul);
a[7]-=4;vw32(a[7],0x5e1aul);
goto L48004;
L5e1a: /* move.l #$210, D0 */
VSTEP(0x5e1aul);
v=((u32)(528L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5e20;
L5e20: /* jmp $7c82a.l */
VSTEP(0x5e20ul);
goto L7c82a;
L5e26: /* moveq #$50, D1 */
VSTEP(0x5e26ul);
v=((u32)(80L));
d[1]=v;

goto L5e28;
L5e28: /* moveq #$b, D2 */
VSTEP(0x5e28ul);
v=((u32)(11L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5e2a;
L5e2a: /* bsr $45bc */
VSTEP(0x5e2aul);
a[7]-=4;vw32(a[7],0x5e2eul);
goto L45bc;
L5e2e: /* bsr $36fa */
VSTEP(0x5e2eul);
a[7]-=4;vw32(a[7],0x5e32ul);
goto L36fa;
L5e32: /* bset #$6, $7c875.l */
VSTEP(0x5e32ul);
v=((u16)(6L));
eb=0x7c875ul;
w=vr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
vw8(eb,r);
goto L5e3a;
L5e98: /* movem.w $67c2.w, D2-D3 */
VSTEP(0x5e98ul);
ea=0x67c2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L5e9e;
L5e9e: /* sub.w D1, D3 */
VSTEP(0x5e9eul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L5ea0;
L5ea0: /* cmpi.w #$1, D3 */
VSTEP(0x5ea0ul);
tv=((u16)(1L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5ea4;
L5ea4: /* bcc $5eca */
VSTEP(0x5ea4ul);
if(!fc)goto L5eca;
goto L5ea6;
L5ea6: /* sub.w D0, D2 */
VSTEP(0x5ea6ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[2])=(u16)(tr);
goto L5ea8;
L5ea8: /* cmpi.w #$20, D2 */
VSTEP(0x5ea8ul);
tv=((u16)(32L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5eac;
L5eac: /* bcc $5eca */
VSTEP(0x5eacul);
if(!fc)goto L5eca;
goto L5eae;
L5eae: /* move.b $62ef.w, D2 */
VSTEP(0x5eaeul);
ea=0x62eful;
tv=(((u8)vm_vars[17]<<0));
VBYTE(d[2])=(u8)(tv);

goto L5eb2;
L5eb2: /* cmpi.b #$24, D2 */
VSTEP(0x5eb2ul);
tv=((u8)(36L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5eb6;
L5eb6: /* rts  */
VSTEP(0x5eb6ul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5eb8: /* bsr $5e98 */
VSTEP(0x5eb8ul);
a[7]-=4;vw32(a[7],0x5ebaul);
goto L5e98;
L5eba: /* bcc $5eca */
VSTEP(0x5ebaul);
if(!fc)goto L5eca;
goto L5ebc;
L5ebc: /* move.w #$18, $67c6.w */
VSTEP(0x5ebcul);
tv=((u16)(24L));
vm_vars[1256]=(u8)((u32)(tv)>>8);
vm_vars[1257]=(u8)((u32)(tv)>>0);

goto L5ec2;
L5ec2: /* addq.w #1, (A6) */
VSTEP(0x5ec2ul);
tv=((u16)(1L));
eb=a[6];
tw=vr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vw16(eb,tr);
goto L5ec4;
L5ec4: /* move.w #$20, ($8,A6) */
VSTEP(0x5ec4ul);
tv=((u16)(32L));
ea=(8+a[6]);
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5eca;
L5eca: /* rts  */
VSTEP(0x5ecaul);
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5ecc: /* subq.w #1, ($8,A6) */
VSTEP(0x5eccul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fx=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
vw16(eb,tr);
goto L5ed0;
L5ed0: /* beq $5ef8 */
VSTEP(0x5ed0ul);
if(fz)goto L5ef8;
goto L5ed2;
L5ed2: /* moveq #$27, D2 */
VSTEP(0x5ed2ul);
v=((u32)(39L));
d[2]=v;

goto L5ed4;
L5ed4: /* sub.w ($8,A6), D2 */
VSTEP(0x5ed4ul);
ea=(8+a[6]);
tv=vr16(ea);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5ed8;
L5ed8: /* lsr.w #3, D2 */
VSTEP(0x5ed8ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;fx=(u8)((tw>>2)&1);
VWORD(d[2])=(u16)(tr);
goto L5eda;
L5eda: /* move.w D2, -(A7) */
VSTEP(0x5edaul);
tv=((u16)d[2]);
a[7]-=2;
ea=a[7];
vw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5edc;
L5edc: /* bsr $45bc */
VSTEP(0x5edcul);
a[7]-=4;vw32(a[7],0x5ee0ul);
goto L45bc;
L5ee0: /* addq.w #8, D0 */
VSTEP(0x5ee0ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5ee2;
L5ee2: /* move.w (A7), D2 */
VSTEP(0x5ee2ul);
ea=a[7];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5ee4;
L5ee4: /* bsr $45bc */
VSTEP(0x5ee4ul);
a[7]-=4;vw32(a[7],0x5ee8ul);
goto L45bc;
L5ee8: /* addq.w #8, D0 */
VSTEP(0x5ee8ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5eea;
L5eea: /* move.w (A7), D2 */
VSTEP(0x5eeaul);
ea=a[7];
tv=vr16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5eec;
L5eec: /* bsr $45bc */
VSTEP(0x5eecul);
a[7]-=4;vw32(a[7],0x5ef0ul);
goto L45bc;
L5ef0: /* addq.w #8, D0 */
VSTEP(0x5ef0ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5ef2;
L5ef2: /* move.w (A7)+, D2 */
VSTEP(0x5ef2ul);
ea=a[7];
tv=vr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L5ef4;
L5ef4: /* bra $45bc */
VSTEP(0x5ef4ul);
goto L45bc;
L5ef8: /* clr.w (A6) */
VSTEP(0x5ef8ul);
ea=a[6];
vw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5efa;
L5efa: /* bsr $55a0 */
VSTEP(0x5efaul);
a[7]-=4;vw32(a[7],0x5efeul);
goto L55a0;
L5efe: /* lsl.w #8, D2 */
VSTEP(0x5efeul);
tv=((u16)(8L));
tw=((u16)d[2]);
tr=tw<<8;
VWORD(d[2])=(u16)(tr);
goto L5f00;
L5f00: /* move.b ($1,A0,D3.w), D2 */
VSTEP(0x5f00ul);
ea=(1+a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L5f04;
L5f04: /* move.b ($2,A0,D3.w), D4 */
VSTEP(0x5f04ul);
ea=(2+a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[4])=(u8)(tv);

goto L5f08;
L5f08: /* lsl.w #8, D4 */
VSTEP(0x5f08ul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=tw<<8;fx=(u8)((tw>>8)&1);
VWORD(d[4])=(u16)(tr);
goto L5f0a;
L5f0a: /* move.b ($3,A0,D3.w), D4 */
VSTEP(0x5f0aul);
ea=(3+a[0]+((s16)(d[3])));
tv=vr8(ea);
VBYTE(d[4])=(u8)(tv);

goto L5f0e;
L5f0e: /* movea.l $5f64.w, A5 */
VSTEP(0x5f0eul);
ea=0x5f64ul;
v=vr32(ea);
a[5]=v;
goto L5f12;
L5f12: /* movem.w D2-D4, -(A5) */
VSTEP(0x5f12ul);
a[5]-=2;
vw16(a[5],d[4]);
a[5]-=2;
vw16(a[5],d[3]);
a[5]-=2;
vw16(a[5],d[2]);
goto L5f16;
L5f16: /* move.l A5, $5f64.w */
VSTEP(0x5f16ul);
v=((u32)a[5]);
ea=0x5f64ul;
vw32(ea,v);

goto L5f1a;
L5f1a: /* move.b #$4f, (A0,D3.w) */
VSTEP(0x5f1aul);
tv=((u8)(79L));
ea=(a[0]+((s16)(d[3])));
vw8(ea,tv);

goto L5f20;
L5f20: /* move.b #$4f, ($1,A0,D3.w) */
VSTEP(0x5f20ul);
tv=((u8)(79L));
ea=(1+a[0]+((s16)(d[3])));
vw8(ea,tv);

goto L5f26;
L5f26: /* move.b #$4f, ($2,A0,D3.w) */
VSTEP(0x5f26ul);
tv=((u8)(79L));
ea=(2+a[0]+((s16)(d[3])));
vw8(ea,tv);

goto L5f2c;
L5f2c: /* move.b #$4f, ($3,A0,D3.w) */
VSTEP(0x5f2cul);
tv=((u8)(79L));
ea=(3+a[0]+((s16)(d[3])));
vw8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5f32;
L5f32: /* bsr $5e98 */
VSTEP(0x5f32ul);
a[7]-=4;vw32(a[7],0x5f36ul);
goto L5e98;
L5f36: /* bcc $5f42 */
VSTEP(0x5f36ul);
if(!fc)goto L5f42;
goto L5f38;
L5f38: /* move.w #$53d6, $3c92.w */
VSTEP(0x5f38ul);
tv=((u16)(21462L));
vm_player_state=(u16)(tv);

goto L5f3e;
L5f3e: /* clr.w $6318.w */
VSTEP(0x5f3eul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L5f42;
L5f42: /* moveq #$5, D2 */
VSTEP(0x5f42ul);
v=((u32)(5L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5f44;
L5f44: /* bsr $45bc */
VSTEP(0x5f44ul);
a[7]-=4;vw32(a[7],0x5f48ul);
goto L45bc;
L5f48: /* moveq #$5, D2 */
VSTEP(0x5f48ul);
v=((u32)(5L));
d[2]=v;

goto L5f4a;
L5f4a: /* addq.w #8, D0 */
VSTEP(0x5f4aul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5f4c;
L5f4c: /* bsr $45bc */
VSTEP(0x5f4cul);
a[7]-=4;vw32(a[7],0x5f50ul);
goto L45bc;
L5f50: /* moveq #$5, D2 */
VSTEP(0x5f50ul);
v=((u32)(5L));
d[2]=v;

goto L5f52;
L5f52: /* addq.w #8, D0 */
VSTEP(0x5f52ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5f54;
L5f54: /* bsr $45bc */
VSTEP(0x5f54ul);
a[7]-=4;vw32(a[7],0x5f58ul);
goto L45bc;
L5f58: /* moveq #$5, D2 */
VSTEP(0x5f58ul);
v=((u32)(5L));
d[2]=v;

goto L5f5a;
L5f5a: /* addq.w #8, D0 */
VSTEP(0x5f5aul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5f5c;
L5f5c: /* bsr $45bc */
VSTEP(0x5f5cul);
a[7]-=4;vw32(a[7],0x5f60ul);
goto L45bc;
L5f60: /* bra $58aa */
VSTEP(0x5f60ul);
goto L58aa;
L5fcc: /* cmpi.w #$c0, D0 */
VSTEP(0x5fccul);
tv=((u16)(192L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5fd0;
L5fd0: /* bpl $6012 */
VSTEP(0x5fd0ul);
if(!fn)goto L6012;
goto L5fd2;
L5fd2: /* andi.w #$7, D4 */
VSTEP(0x5fd2ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L5fd6;
L5fd6: /* bne $5fe6 */
VSTEP(0x5fd6ul);
if(!fz)goto L5fe6;
goto L5fd8;
L5fd8: /* addq.w #8, D0 */
VSTEP(0x5fd8ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5fda;
L5fda: /* bsr $55a0 */
VSTEP(0x5fdaul);
a[7]-=4;vw32(a[7],0x5fdeul);
goto L55a0;
L5fde: /* subq.w #8, D0 */
VSTEP(0x5fdeul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5fe0;
L5fe0: /* cmpi.b #$79, D2 */
VSTEP(0x5fe0ul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5fe4;
L5fe4: /* bcs $6012 */
VSTEP(0x5fe4ul);
if(fc)goto L6012;
goto L5fe6;
L5fe6: /* addq.w #1, ($2,A6) */
VSTEP(0x5fe6ul);
tv=((u16)(1L));
eb=(2+a[6]);
tw=vr16(eb);
tr=tw+tv;
vw16(eb,tr);
goto L5fea;
L5fea: /* subq.w #1, ($8,A6) */
VSTEP(0x5feaul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
vw16(eb,tr);
goto L5fee;
L5fee: /* bpl $6016 */
VSTEP(0x5feeul);
if(!fn)goto L6016;
goto L5ff0;
L5ff0: /* movem.w $67c2.w, D2-D3 */
VSTEP(0x5ff0ul);
ea=0x67c2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L5ff6;
L5ff6: /* sub.w D0, D2 */
VSTEP(0x5ff6ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5ff8;
L5ff8: /* cmpi.w #$8, D2 */
VSTEP(0x5ff8ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5ffc;
L5ffc: /* bcc $6016 */
VSTEP(0x5ffcul);
if(!fc)goto L6016;
goto L5ffe;
L5ffe: /* sub.w D1, D3 */
VSTEP(0x5ffeul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L6000;
L6000: /* cmpi.w #$13, D3 */
VSTEP(0x6000ul);
tv=((u16)(19L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L6004;
L6004: /* bcc $6016 */
VSTEP(0x6004ul);
if(!fc)goto L6016;
goto L6006;
L6006: /* move.w #$19, ($8,A6) */
VSTEP(0x6006ul);
tv=((u16)(25L));
ea=(8+a[6]);
vw16(ea,tv);

goto L600c;
L600c: /* moveq #$2, D6 */
VSTEP(0x600cul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L600e;
L600e: /* bsr $4ccc */
VSTEP(0x600eul);
a[7]-=4;vw32(a[7],0x6012ul);
goto L4ccc;
L6012: /* move.w #$1e, (A6) */
VSTEP(0x6012ul);
tv=((u16)(30L));
ea=a[6];
vw16(ea,tv);

goto L6016;
L6016: /* move.w D4, D2 */
VSTEP(0x6016ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L6018;
L6018: /* lsr.w #1, D2 */
VSTEP(0x6018ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L601a;
L601a: /* addq.w #1, D2 */
VSTEP(0x601aul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L601c;
L601c: /* bra $45bc */
VSTEP(0x601cul);
goto L45bc;
L6020: /* cmpi.w #-$40, D0 */
VSTEP(0x6020ul);
tv=((u16)(-64L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L6024;
L6024: /* bmi $606a */
VSTEP(0x6024ul);
if(fn)goto L606a;
goto L6026;
L6026: /* andi.w #$7, D4 */
VSTEP(0x6026ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L602a;
L602a: /* bne $603e */
VSTEP(0x602aul);
if(!fz)goto L603e;
goto L602c;
L602c: /* subi.w #$10, D0 */
VSTEP(0x602cul);
tv=((u16)(16L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L6030;
L6030: /* bsr $55a0 */
VSTEP(0x6030ul);
a[7]-=4;vw32(a[7],0x6034ul);
goto L55a0;
L6034: /* addi.w #$10, D0 */
VSTEP(0x6034ul);
tv=((u16)(16L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6038;
L6038: /* cmpi.b #$79, D2 */
VSTEP(0x6038ul);
tv=((u8)(121L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L603c;
L603c: /* bcs $606a */
VSTEP(0x603cul);
if(fc)goto L606a;
goto L603e;
L603e: /* subq.w #1, ($2,A6) */
VSTEP(0x603eul);
tv=((u16)(1L));
eb=(2+a[6]);
tw=vr16(eb);
tr=tw-tv;
vw16(eb,tr);
goto L6042;
L6042: /* subq.w #1, ($8,A6) */
VSTEP(0x6042ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=vr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
vw16(eb,tr);
goto L6046;
L6046: /* bpl $606e */
VSTEP(0x6046ul);
if(!fn)goto L606e;
goto L6048;
L6048: /* movem.w $67c2.w, D2-D3 */
VSTEP(0x6048ul);
ea=0x67c2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1252u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1254u));
goto L604e;
L604e: /* sub.w D0, D2 */
VSTEP(0x604eul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L6050;
L6050: /* addi.w #$a, D2 */
VSTEP(0x6050ul);
tv=((u16)(10L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L6054;
L6054: /* bcc $606e */
VSTEP(0x6054ul);
if(!fc)goto L606e;
goto L6056;
L6056: /* sub.w D1, D3 */
VSTEP(0x6056ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L6058;
L6058: /* cmpi.w #$13, D3 */
VSTEP(0x6058ul);
tv=((u16)(19L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L605c;
L605c: /* bcc $606e */
VSTEP(0x605cul);
if(!fc)goto L606e;
goto L605e;
L605e: /* move.w #$19, ($8,A6) */
VSTEP(0x605eul);
tv=((u16)(25L));
ea=(8+a[6]);
vw16(ea,tv);

goto L6064;
L6064: /* moveq #$2, D6 */
VSTEP(0x6064ul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L6066;
L6066: /* bsr $4ccc */
VSTEP(0x6066ul);
a[7]-=4;vw32(a[7],0x606aul);
goto L4ccc;
L606a: /* move.w #$1d, (A6) */
VSTEP(0x606aul);
tv=((u16)(29L));
ea=a[6];
vw16(ea,tv);

goto L606e;
L606e: /* move.w #$e003, D2 */
VSTEP(0x606eul);
tv=((u16)(57347L));
VWORD(d[2])=(u16)(tv);

goto L6072;
L6072: /* lsr.w #1, D4 */
VSTEP(0x6072ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((u16)tw)>>1;
VWORD(d[4])=(u16)(tr);
goto L6074;
L6074: /* eor.w D4, D2 */
VSTEP(0x6074ul);
tv=((u16)d[4]);
tw=((u16)d[2]);
tr=tw^tv;

VWORD(d[2])=(u16)(tr);
goto L6076;
L6076: /* addq.w #1, D2 */
VSTEP(0x6076ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L6078;
L6078: /* bra $45bc */
VSTEP(0x6078ul);
goto L45bc;
L36fa:
if(vm_external(0x36faul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3cbc:
if(vm_external(0x3cbcul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3cc0:
if(vm_external(0x3cc0ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3d14:
if(vm_external(0x3d14ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3d32:
if(vm_external(0x3d32ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L3d8c:
if(vm_external(0x3d8cul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4a5e:
if(vm_external(0x4a5eul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4ad6:
if(vm_external(0x4ad6ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4b62:
if(vm_external(0x4b62ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4db2:
if(vm_external(0x4db2ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4e28:
if(vm_external(0x4e28ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L55c4:
goto L56a6;
L56f4:
if(vm_external(0x56f4ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5e3a:
if(vm_external(0x5e3aul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5e60:
if(vm_external(0x5e60ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L5e8c:
if(vm_external(0x5e8cul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L67ca:
if(vm_external(0x67caul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L48000:
if(vm_external(0x48000ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L48004:
if(vm_external(0x48004ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L48008:
if(vm_external(0x48008ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L4800c:
if(vm_external(0x4800cul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L48010:
if(vm_external(0x48010ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L48014:
if(vm_external(0x48014ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L48018:
if(vm_external(0x48018ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L7c82a:
if(vm_external(0x7c82aul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L7c862:
if(vm_external(0x7c862ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
L7c870:
if(vm_external(0x7c870ul))return;
pc=vr32(a[7]);a[7]+=4;goto dispatch;
}
