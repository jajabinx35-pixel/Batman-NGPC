/* Generated from the shipped Amiga 68000 code5.iff. See tools/lift.py.
 * Static native translation; original state transitions and integer rules.
 */
#include "cathedral.h"
#include "direct_memory.h"
#include "platform_scan.h"
extern const u16 vm_dispatch_table[];
#define VWORD(x) (*(u16 *)&(x))
#define VBYTE(x) (*(u8 *)&(x))
void cat_exec(u16 entry){
 u32 v,w,r,ea,eb; u16 tv,tw,tr,dispatch_pc; s32 signed_result;u32 pc;
#ifdef VM_HOST
 u32 instruction_count=0;
#define VSTEP(p) if(++instruction_count>200000ul){vm_fault=0x1000000ul|(p);return;}
#else
#define VSTEP(p)
#endif
 if(!vm_busy){a[7]=0x200000ul;a[7]-=4;cvw32(a[7],0);pc=entry;}else pc=vm_resume;
 vm_busy=0;
dispatch:
 if(pc>65535ul){vm_fault=pc;return;}dispatch_pc=(u16)pc;
 if(!pc)return;if(dispatch_pc==0x5e76u)goto L5e76;if(dispatch_pc==0x5e7au)goto L5e7a;
#ifdef VM_HOST
 /* Test the same collision kernel directly without adding a cartridge entry. */
 if(dispatch_pc==0x55e0u)goto L55e0;
#endif
DISP0:
if(dispatch_pc<0x5124u)goto DISP0L;goto DISP0R;
DISP0L:
if(dispatch_pc<0x463cu)goto DISP0LL;goto DISP0LR;
DISP0LL:
if(dispatch_pc<0x4272u)goto DISP0LLL;goto DISP0LLR;
DISP0LLL:
if(dispatch_pc<0x4032u)goto DISP0LLLL;goto DISP0LLLR;
DISP0LLLL:
if(dispatch_pc<0x3f44u)goto DISP0LLLLL;goto DISP0LLLLR;
DISP0LLLLL:
if(dispatch_pc<0x3e50u)goto DISP0LLLLLL;goto DISP0LLLLLR;
DISP0LLLLLL:
if(dispatch_pc<0x3e18u)goto DISP0LLLLLLL;goto DISP0LLLLLLR;
DISP0LLLLLLL:
if(dispatch_pc==0x3dbeu)goto L3dbe;if(dispatch_pc==0x3decu)goto L3dec;vm_fault=pc;return;
DISP0LLLLLLR:
if(dispatch_pc<0x3e30u)goto DISP0LLLLLLRL;goto DISP0LLLLLLRR;
DISP0LLLLLLRL:
if(dispatch_pc==0x3e18u)goto L3e18;vm_fault=pc;return;
DISP0LLLLLLRR:
if(dispatch_pc==0x3e30u)goto L3e30;vm_fault=pc;return;
DISP0LLLLLR:
if(dispatch_pc<0x3eb4u)goto DISP0LLLLLRL;goto DISP0LLLLLRR;
DISP0LLLLLRL:
if(dispatch_pc==0x3e50u)goto L3e50;vm_fault=pc;return;
DISP0LLLLLRR:
if(dispatch_pc<0x3ed4u)goto DISP0LLLLLRRL;goto DISP0LLLLLRRR;
DISP0LLLLLRRL:
if(dispatch_pc==0x3eb4u)goto L3eb4;vm_fault=pc;return;
DISP0LLLLLRRR:
if(dispatch_pc==0x3ed4u)goto L3ed4;vm_fault=pc;return;
DISP0LLLLR:
if(dispatch_pc<0x3fcau)goto DISP0LLLLRL;goto DISP0LLLLRR;
DISP0LLLLRL:
if(dispatch_pc<0x3f76u)goto DISP0LLLLRLL;goto DISP0LLLLRLR;
DISP0LLLLRLL:
if(dispatch_pc==0x3f44u)goto L3f44;vm_fault=pc;return;
DISP0LLLLRLR:
if(dispatch_pc<0x3f94u)goto DISP0LLLLRLRL;goto DISP0LLLLRLRR;
DISP0LLLLRLRL:
if(dispatch_pc==0x3f76u)goto L3f76;vm_fault=pc;return;
DISP0LLLLRLRR:
if(dispatch_pc==0x3f94u)goto L3f94;vm_fault=pc;return;
DISP0LLLLRR:
if(dispatch_pc<0x3ffau)goto DISP0LLLLRRL;goto DISP0LLLLRRR;
DISP0LLLLRRL:
if(dispatch_pc<0x3ff4u)goto DISP0LLLLRRLL;goto DISP0LLLLRRLR;
DISP0LLLLRRLL:
if(dispatch_pc==0x3fcau)goto L3fca;vm_fault=pc;return;
DISP0LLLLRRLR:
if(dispatch_pc==0x3ff4u)goto L3ff4;vm_fault=pc;return;
DISP0LLLLRRR:
if(dispatch_pc<0x400au)goto DISP0LLLLRRRL;goto DISP0LLLLRRRR;
DISP0LLLLRRRL:
if(dispatch_pc==0x3ffau)goto L3ffa;vm_fault=pc;return;
DISP0LLLLRRRR:
if(dispatch_pc==0x400au)goto L400a;vm_fault=pc;return;
DISP0LLLR:
if(dispatch_pc<0x40e6u)goto DISP0LLLRL;goto DISP0LLLRR;
DISP0LLLRL:
if(dispatch_pc<0x4080u)goto DISP0LLLRLL;goto DISP0LLLRLR;
DISP0LLLRLL:
if(dispatch_pc<0x403au)goto DISP0LLLRLLL;goto DISP0LLLRLLR;
DISP0LLLRLLL:
if(dispatch_pc==0x4032u)goto L4032;vm_fault=pc;return;
DISP0LLLRLLR:
if(dispatch_pc<0x404cu)goto DISP0LLLRLLRL;goto DISP0LLLRLLRR;
DISP0LLLRLLRL:
if(dispatch_pc==0x403au)goto L403a;vm_fault=pc;return;
DISP0LLLRLLRR:
if(dispatch_pc==0x404cu)goto L404c;vm_fault=pc;return;
DISP0LLLRLR:
if(dispatch_pc<0x40b6u)goto DISP0LLLRLRL;goto DISP0LLLRLRR;
DISP0LLLRLRL:
if(dispatch_pc<0x40a6u)goto DISP0LLLRLRLL;goto DISP0LLLRLRLR;
DISP0LLLRLRLL:
if(dispatch_pc==0x4080u)goto L4080;vm_fault=pc;return;
DISP0LLLRLRLR:
if(dispatch_pc==0x40a6u)goto L40a6;vm_fault=pc;return;
DISP0LLLRLRR:
if(dispatch_pc<0x40deu)goto DISP0LLLRLRRL;goto DISP0LLLRLRRR;
DISP0LLLRLRRL:
if(dispatch_pc==0x40b6u)goto L40b6;vm_fault=pc;return;
DISP0LLLRLRRR:
if(dispatch_pc==0x40deu)goto L40de;vm_fault=pc;return;
DISP0LLLRR:
if(dispatch_pc<0x41aeu)goto DISP0LLLRRL;goto DISP0LLLRRR;
DISP0LLLRRL:
if(dispatch_pc<0x40f8u)goto DISP0LLLRRLL;goto DISP0LLLRRLR;
DISP0LLLRRLL:
if(dispatch_pc==0x40e6u)goto L40e6;vm_fault=pc;return;
DISP0LLLRRLR:
if(dispatch_pc<0x412au)goto DISP0LLLRRLRL;goto DISP0LLLRRLRR;
DISP0LLLRRLRL:
if(dispatch_pc==0x40f8u)goto L40f8;vm_fault=pc;return;
DISP0LLLRRLRR:
if(dispatch_pc==0x412au)goto L412a;vm_fault=pc;return;
DISP0LLLRRR:
if(dispatch_pc<0x41deu)goto DISP0LLLRRRL;goto DISP0LLLRRRR;
DISP0LLLRRRL:
if(dispatch_pc<0x41c6u)goto DISP0LLLRRRLL;goto DISP0LLLRRRLR;
DISP0LLLRRRLL:
if(dispatch_pc==0x41aeu)goto L41ae;vm_fault=pc;return;
DISP0LLLRRRLR:
if(dispatch_pc==0x41c6u)goto L41c6;vm_fault=pc;return;
DISP0LLLRRRR:
if(dispatch_pc<0x4264u)goto DISP0LLLRRRRL;goto DISP0LLLRRRRR;
DISP0LLLRRRRL:
if(dispatch_pc==0x41deu)goto L41de;vm_fault=pc;return;
DISP0LLLRRRRR:
if(dispatch_pc==0x4264u)goto L4264;vm_fault=pc;return;
DISP0LLR:
if(dispatch_pc<0x446eu)goto DISP0LLRL;goto DISP0LLRR;
DISP0LLRL:
if(dispatch_pc<0x43aau)goto DISP0LLRLL;goto DISP0LLRLR;
DISP0LLRLL:
if(dispatch_pc<0x42b4u)goto DISP0LLRLLL;goto DISP0LLRLLR;
DISP0LLRLLL:
if(dispatch_pc<0x4278u)goto DISP0LLRLLLL;goto DISP0LLRLLLR;
DISP0LLRLLLL:
if(dispatch_pc==0x4272u)goto L4272;vm_fault=pc;return;
DISP0LLRLLLR:
if(dispatch_pc<0x4290u)goto DISP0LLRLLLRL;goto DISP0LLRLLLRR;
DISP0LLRLLLRL:
if(dispatch_pc==0x4278u)goto L4278;vm_fault=pc;return;
DISP0LLRLLLRR:
if(dispatch_pc==0x4290u)goto L4290;vm_fault=pc;return;
DISP0LLRLLR:
if(dispatch_pc<0x434cu)goto DISP0LLRLLRL;goto DISP0LLRLLRR;
DISP0LLRLLRL:
if(dispatch_pc<0x433eu)goto DISP0LLRLLRLL;goto DISP0LLRLLRLR;
DISP0LLRLLRLL:
if(dispatch_pc==0x42b4u)goto L42b4;vm_fault=pc;return;
DISP0LLRLLRLR:
if(dispatch_pc==0x433eu)goto L433e;vm_fault=pc;return;
DISP0LLRLLRR:
if(dispatch_pc<0x438cu)goto DISP0LLRLLRRL;goto DISP0LLRLLRRR;
DISP0LLRLLRRL:
if(dispatch_pc==0x434cu)goto L434c;vm_fault=pc;return;
DISP0LLRLLRRR:
if(dispatch_pc==0x438cu)goto L438c;vm_fault=pc;return;
DISP0LLRLR:
if(dispatch_pc<0x43e2u)goto DISP0LLRLRL;goto DISP0LLRLRR;
DISP0LLRLRL:
if(dispatch_pc<0x43b4u)goto DISP0LLRLRLL;goto DISP0LLRLRLR;
DISP0LLRLRLL:
if(dispatch_pc==0x43aau)goto L43aa;vm_fault=pc;return;
DISP0LLRLRLR:
if(dispatch_pc<0x43d4u)goto DISP0LLRLRLRL;goto DISP0LLRLRLRR;
DISP0LLRLRLRL:
if(dispatch_pc==0x43b4u)goto L43b4;vm_fault=pc;return;
DISP0LLRLRLRR:
if(dispatch_pc==0x43d4u)goto L43d4;vm_fault=pc;return;
DISP0LLRLRR:
if(dispatch_pc<0x440cu)goto DISP0LLRLRRL;goto DISP0LLRLRRR;
DISP0LLRLRRL:
if(dispatch_pc<0x4402u)goto DISP0LLRLRRLL;goto DISP0LLRLRRLR;
DISP0LLRLRRLL:
if(dispatch_pc==0x43e2u)goto L43e2;vm_fault=pc;return;
DISP0LLRLRRLR:
if(dispatch_pc==0x4402u)goto L4402;vm_fault=pc;return;
DISP0LLRLRRR:
if(dispatch_pc<0x442cu)goto DISP0LLRLRRRL;goto DISP0LLRLRRRR;
DISP0LLRLRRRL:
if(dispatch_pc==0x440cu)goto L440c;vm_fault=pc;return;
DISP0LLRLRRRR:
if(dispatch_pc==0x442cu)goto L442c;vm_fault=pc;return;
DISP0LLRR:
if(dispatch_pc<0x44c0u)goto DISP0LLRRL;goto DISP0LLRRR;
DISP0LLRRL:
if(dispatch_pc<0x4486u)goto DISP0LLRRLL;goto DISP0LLRRLR;
DISP0LLRRLL:
if(dispatch_pc<0x4472u)goto DISP0LLRRLLL;goto DISP0LLRRLLR;
DISP0LLRRLLL:
if(dispatch_pc==0x446eu)goto L446e;vm_fault=pc;return;
DISP0LLRRLLR:
if(dispatch_pc<0x4482u)goto DISP0LLRRLLRL;goto DISP0LLRRLLRR;
DISP0LLRRLLRL:
if(dispatch_pc==0x4472u)goto L4472;vm_fault=pc;return;
DISP0LLRRLLRR:
if(dispatch_pc==0x4482u)goto L4482;vm_fault=pc;return;
DISP0LLRRLR:
if(dispatch_pc<0x44acu)goto DISP0LLRRLRL;goto DISP0LLRRLRR;
DISP0LLRRLRL:
if(dispatch_pc<0x4494u)goto DISP0LLRRLRLL;goto DISP0LLRRLRLR;
DISP0LLRRLRLL:
if(dispatch_pc==0x4486u)goto L4486;vm_fault=pc;return;
DISP0LLRRLRLR:
if(dispatch_pc==0x4494u)goto L4494;vm_fault=pc;return;
DISP0LLRRLRR:
if(dispatch_pc<0x44bcu)goto DISP0LLRRLRRL;goto DISP0LLRRLRRR;
DISP0LLRRLRRL:
if(dispatch_pc==0x44acu)goto L44ac;vm_fault=pc;return;
DISP0LLRRLRRR:
if(dispatch_pc==0x44bcu)goto L44bc;vm_fault=pc;return;
DISP0LLRRR:
if(dispatch_pc<0x45c2u)goto DISP0LLRRRL;goto DISP0LLRRRR;
DISP0LLRRRL:
if(dispatch_pc<0x450cu)goto DISP0LLRRRLL;goto DISP0LLRRRLR;
DISP0LLRRRLL:
if(dispatch_pc==0x44c0u)goto L44c0;vm_fault=pc;return;
DISP0LLRRRLR:
if(dispatch_pc<0x45beu)goto DISP0LLRRRLRL;goto DISP0LLRRRLRR;
DISP0LLRRRLRL:
if(dispatch_pc==0x450cu)goto L450c;vm_fault=pc;return;
DISP0LLRRRLRR:
if(dispatch_pc==0x45beu)goto L45be;vm_fault=pc;return;
DISP0LLRRRR:
if(dispatch_pc<0x4606u)goto DISP0LLRRRRL;goto DISP0LLRRRRR;
DISP0LLRRRRL:
if(dispatch_pc<0x45f4u)goto DISP0LLRRRRLL;goto DISP0LLRRRRLR;
DISP0LLRRRRLL:
if(dispatch_pc==0x45c2u)goto L45c2;vm_fault=pc;return;
DISP0LLRRRRLR:
if(dispatch_pc==0x45f4u)goto L45f4;vm_fault=pc;return;
DISP0LLRRRRR:
if(dispatch_pc<0x460cu)goto DISP0LLRRRRRL;goto DISP0LLRRRRRR;
DISP0LLRRRRRL:
if(dispatch_pc==0x4606u)goto L4606;vm_fault=pc;return;
DISP0LLRRRRRR:
if(dispatch_pc==0x460cu)goto L460c;vm_fault=pc;return;
DISP0LR:
if(dispatch_pc<0x4a9au)goto DISP0LRL;goto DISP0LRR;
DISP0LRL:
if(dispatch_pc<0x4766u)goto DISP0LRLL;goto DISP0LRLR;
DISP0LRLL:
if(dispatch_pc<0x4700u)goto DISP0LRLLL;goto DISP0LRLLR;
DISP0LRLLL:
if(dispatch_pc<0x46bcu)goto DISP0LRLLLL;goto DISP0LRLLLR;
DISP0LRLLLL:
if(dispatch_pc<0x4670u)goto DISP0LRLLLLL;goto DISP0LRLLLLR;
DISP0LRLLLLL:
if(dispatch_pc==0x463cu)goto L463c;vm_fault=pc;return;
DISP0LRLLLLR:
if(dispatch_pc<0x4696u)goto DISP0LRLLLLRL;goto DISP0LRLLLLRR;
DISP0LRLLLLRL:
if(dispatch_pc==0x4670u)goto L4670;vm_fault=pc;return;
DISP0LRLLLLRR:
if(dispatch_pc==0x4696u)goto L4696;vm_fault=pc;return;
DISP0LRLLLR:
if(dispatch_pc<0x46f0u)goto DISP0LRLLLRL;goto DISP0LRLLLRR;
DISP0LRLLLRL:
if(dispatch_pc<0x46ccu)goto DISP0LRLLLRLL;goto DISP0LRLLLRLR;
DISP0LRLLLRLL:
if(dispatch_pc==0x46bcu)goto L46bc;vm_fault=pc;return;
DISP0LRLLLRLR:
if(dispatch_pc==0x46ccu)goto L46cc;vm_fault=pc;return;
DISP0LRLLLRR:
if(dispatch_pc<0x46f8u)goto DISP0LRLLLRRL;goto DISP0LRLLLRRR;
DISP0LRLLLRRL:
if(dispatch_pc==0x46f0u)goto L46f0;vm_fault=pc;return;
DISP0LRLLLRRR:
if(dispatch_pc==0x46f8u)goto L46f8;vm_fault=pc;return;
DISP0LRLLR:
if(dispatch_pc<0x4736u)goto DISP0LRLLRL;goto DISP0LRLLRR;
DISP0LRLLRL:
if(dispatch_pc<0x4712u)goto DISP0LRLLRLL;goto DISP0LRLLRLR;
DISP0LRLLRLL:
if(dispatch_pc==0x4700u)goto L4700;vm_fault=pc;return;
DISP0LRLLRLR:
if(dispatch_pc<0x4724u)goto DISP0LRLLRLRL;goto DISP0LRLLRLRR;
DISP0LRLLRLRL:
if(dispatch_pc==0x4712u)goto L4712;vm_fault=pc;return;
DISP0LRLLRLRR:
if(dispatch_pc==0x4724u)goto L4724;vm_fault=pc;return;
DISP0LRLLRR:
if(dispatch_pc<0x4756u)goto DISP0LRLLRRL;goto DISP0LRLLRRR;
DISP0LRLLRRL:
if(dispatch_pc<0x474au)goto DISP0LRLLRRLL;goto DISP0LRLLRRLR;
DISP0LRLLRRLL:
if(dispatch_pc==0x4736u)goto L4736;vm_fault=pc;return;
DISP0LRLLRRLR:
if(dispatch_pc==0x474au)goto L474a;vm_fault=pc;return;
DISP0LRLLRRR:
if(dispatch_pc<0x4760u)goto DISP0LRLLRRRL;goto DISP0LRLLRRRR;
DISP0LRLLRRRL:
if(dispatch_pc==0x4756u)goto L4756;vm_fault=pc;return;
DISP0LRLLRRRR:
if(dispatch_pc==0x4760u)goto L4760;vm_fault=pc;return;
DISP0LRLR:
if(dispatch_pc<0x482au)goto DISP0LRLRL;goto DISP0LRLRR;
DISP0LRLRL:
if(dispatch_pc<0x478au)goto DISP0LRLRLL;goto DISP0LRLRLR;
DISP0LRLRLL:
if(dispatch_pc<0x4772u)goto DISP0LRLRLLL;goto DISP0LRLRLLR;
DISP0LRLRLLL:
if(dispatch_pc==0x4766u)goto L4766;vm_fault=pc;return;
DISP0LRLRLLR:
if(dispatch_pc<0x477eu)goto DISP0LRLRLLRL;goto DISP0LRLRLLRR;
DISP0LRLRLLRL:
if(dispatch_pc==0x4772u)goto L4772;vm_fault=pc;return;
DISP0LRLRLLRR:
if(dispatch_pc==0x477eu)goto L477e;vm_fault=pc;return;
DISP0LRLRLR:
if(dispatch_pc<0x47fau)goto DISP0LRLRLRL;goto DISP0LRLRLRR;
DISP0LRLRLRL:
if(dispatch_pc<0x4796u)goto DISP0LRLRLRLL;goto DISP0LRLRLRLR;
DISP0LRLRLRLL:
if(dispatch_pc==0x478au)goto L478a;vm_fault=pc;return;
DISP0LRLRLRLR:
if(dispatch_pc==0x4796u)goto L4796;vm_fault=pc;return;
DISP0LRLRLRR:
if(dispatch_pc<0x4802u)goto DISP0LRLRLRRL;goto DISP0LRLRLRRR;
DISP0LRLRLRRL:
if(dispatch_pc==0x47fau)goto L47fa;vm_fault=pc;return;
DISP0LRLRLRRR:
if(dispatch_pc==0x4802u)goto L4802;vm_fault=pc;return;
DISP0LRLRR:
if(dispatch_pc<0x4882u)goto DISP0LRLRRL;goto DISP0LRLRRR;
DISP0LRLRRL:
if(dispatch_pc<0x484eu)goto DISP0LRLRRLL;goto DISP0LRLRRLR;
DISP0LRLRRLL:
if(dispatch_pc==0x482au)goto L482a;vm_fault=pc;return;
DISP0LRLRRLR:
if(dispatch_pc<0x4860u)goto DISP0LRLRRLRL;goto DISP0LRLRRLRR;
DISP0LRLRRLRL:
if(dispatch_pc==0x484eu)goto L484e;vm_fault=pc;return;
DISP0LRLRRLRR:
if(dispatch_pc==0x4860u)goto L4860;vm_fault=pc;return;
DISP0LRLRRR:
if(dispatch_pc<0x4a0eu)goto DISP0LRLRRRL;goto DISP0LRLRRRR;
DISP0LRLRRRL:
if(dispatch_pc<0x4974u)goto DISP0LRLRRRLL;goto DISP0LRLRRRLR;
DISP0LRLRRRLL:
if(dispatch_pc==0x4882u)goto L4882;vm_fault=pc;return;
DISP0LRLRRRLR:
if(dispatch_pc==0x4974u)goto L4974;vm_fault=pc;return;
DISP0LRLRRRR:
if(dispatch_pc<0x4a2au)goto DISP0LRLRRRRL;goto DISP0LRLRRRRR;
DISP0LRLRRRRL:
if(dispatch_pc==0x4a0eu)goto L4a0e;vm_fault=pc;return;
DISP0LRLRRRRR:
if(dispatch_pc==0x4a2au)goto L4a2a;vm_fault=pc;return;
DISP0LRR:
if(dispatch_pc<0x4e78u)goto DISP0LRRL;goto DISP0LRRR;
DISP0LRRL:
if(dispatch_pc<0x4d9eu)goto DISP0LRRLL;goto DISP0LRRLR;
DISP0LRRLL:
if(dispatch_pc<0x4d22u)goto DISP0LRRLLL;goto DISP0LRRLLR;
DISP0LRRLLL:
if(dispatch_pc<0x4c7cu)goto DISP0LRRLLLL;goto DISP0LRRLLLR;
DISP0LRRLLLL:
if(dispatch_pc==0x4a9au)goto L4a9a;vm_fault=pc;return;
DISP0LRRLLLR:
if(dispatch_pc<0x4d1eu)goto DISP0LRRLLLRL;goto DISP0LRRLLLRR;
DISP0LRRLLLRL:
if(dispatch_pc==0x4c7cu)goto L4c7c;vm_fault=pc;return;
DISP0LRRLLLRR:
if(dispatch_pc==0x4d1eu)goto L4d1e;vm_fault=pc;return;
DISP0LRRLLR:
if(dispatch_pc<0x4d86u)goto DISP0LRRLLRL;goto DISP0LRRLLRR;
DISP0LRRLLRL:
if(dispatch_pc<0x4d56u)goto DISP0LRRLLRLL;goto DISP0LRRLLRLR;
DISP0LRRLLRLL:
if(dispatch_pc==0x4d22u)goto L4d22;vm_fault=pc;return;
DISP0LRRLLRLR:
if(dispatch_pc==0x4d56u)goto L4d56;vm_fault=pc;return;
DISP0LRRLLRR:
if(dispatch_pc<0x4d94u)goto DISP0LRRLLRRL;goto DISP0LRRLLRRR;
DISP0LRRLLRRL:
if(dispatch_pc==0x4d86u)goto L4d86;vm_fault=pc;return;
DISP0LRRLLRRR:
if(dispatch_pc==0x4d94u)goto L4d94;vm_fault=pc;return;
DISP0LRRLR:
if(dispatch_pc<0x4dc6u)goto DISP0LRRLRL;goto DISP0LRRLRR;
DISP0LRRLRL:
if(dispatch_pc<0x4db4u)goto DISP0LRRLRLL;goto DISP0LRRLRLR;
DISP0LRRLRLL:
if(dispatch_pc==0x4d9eu)goto L4d9e;vm_fault=pc;return;
DISP0LRRLRLR:
if(dispatch_pc<0x4db8u)goto DISP0LRRLRLRL;goto DISP0LRRLRLRR;
DISP0LRRLRLRL:
if(dispatch_pc==0x4db4u)goto L4db4;vm_fault=pc;return;
DISP0LRRLRLRR:
if(dispatch_pc==0x4db8u)goto L4db8;vm_fault=pc;return;
DISP0LRRLRR:
if(dispatch_pc<0x4de0u)goto DISP0LRRLRRL;goto DISP0LRRLRRR;
DISP0LRRLRRL:
if(dispatch_pc<0x4dd2u)goto DISP0LRRLRRLL;goto DISP0LRRLRRLR;
DISP0LRRLRRLL:
if(dispatch_pc==0x4dc6u)goto L4dc6;vm_fault=pc;return;
DISP0LRRLRRLR:
if(dispatch_pc==0x4dd2u)goto L4dd2;vm_fault=pc;return;
DISP0LRRLRRR:
if(dispatch_pc<0x4de8u)goto DISP0LRRLRRRL;goto DISP0LRRLRRRR;
DISP0LRRLRRRL:
if(dispatch_pc==0x4de0u)goto L4de0;vm_fault=pc;return;
DISP0LRRLRRRR:
if(dispatch_pc==0x4de8u)goto L4de8;vm_fault=pc;return;
DISP0LRRR:
if(dispatch_pc<0x503cu)goto DISP0LRRRL;goto DISP0LRRRR;
DISP0LRRRL:
if(dispatch_pc<0x4f8cu)goto DISP0LRRRLL;goto DISP0LRRRLR;
DISP0LRRRLL:
if(dispatch_pc<0x4ea2u)goto DISP0LRRRLLL;goto DISP0LRRRLLR;
DISP0LRRRLLL:
if(dispatch_pc==0x4e78u)goto L4e78;vm_fault=pc;return;
DISP0LRRRLLR:
if(dispatch_pc<0x4f64u)goto DISP0LRRRLLRL;goto DISP0LRRRLLRR;
DISP0LRRRLLRL:
if(dispatch_pc==0x4ea2u)goto L4ea2;vm_fault=pc;return;
DISP0LRRRLLRR:
if(dispatch_pc==0x4f64u)goto L4f64;vm_fault=pc;return;
DISP0LRRRLR:
if(dispatch_pc<0x501eu)goto DISP0LRRRLRL;goto DISP0LRRRLRR;
DISP0LRRRLRL:
if(dispatch_pc<0x4fe2u)goto DISP0LRRRLRLL;goto DISP0LRRRLRLR;
DISP0LRRRLRLL:
if(dispatch_pc==0x4f8cu)goto L4f8c;vm_fault=pc;return;
DISP0LRRRLRLR:
if(dispatch_pc==0x4fe2u)goto L4fe2;vm_fault=pc;return;
DISP0LRRRLRR:
if(dispatch_pc<0x5034u)goto DISP0LRRRLRRL;goto DISP0LRRRLRRR;
DISP0LRRRLRRL:
if(dispatch_pc==0x501eu)goto L501e;vm_fault=pc;return;
DISP0LRRRLRRR:
if(dispatch_pc==0x5034u)goto L5034;vm_fault=pc;return;
DISP0LRRRR:
if(dispatch_pc<0x5096u)goto DISP0LRRRRL;goto DISP0LRRRRR;
DISP0LRRRRL:
if(dispatch_pc<0x5054u)goto DISP0LRRRRLL;goto DISP0LRRRRLR;
DISP0LRRRRLL:
if(dispatch_pc==0x503cu)goto L503c;vm_fault=pc;return;
DISP0LRRRRLR:
if(dispatch_pc<0x5074u)goto DISP0LRRRRLRL;goto DISP0LRRRRLRR;
DISP0LRRRRLRL:
if(dispatch_pc==0x5054u)goto L5054;vm_fault=pc;return;
DISP0LRRRRLRR:
if(dispatch_pc==0x5074u)goto L5074;vm_fault=pc;return;
DISP0LRRRRR:
if(dispatch_pc<0x50c6u)goto DISP0LRRRRRL;goto DISP0LRRRRRR;
DISP0LRRRRRL:
if(dispatch_pc<0x50b4u)goto DISP0LRRRRRLL;goto DISP0LRRRRRLR;
DISP0LRRRRRLL:
if(dispatch_pc==0x5096u)goto L5096;vm_fault=pc;return;
DISP0LRRRRRLR:
if(dispatch_pc==0x50b4u)goto L50b4;vm_fault=pc;return;
DISP0LRRRRRR:
if(dispatch_pc<0x50d8u)goto DISP0LRRRRRRL;goto DISP0LRRRRRRR;
DISP0LRRRRRRL:
if(dispatch_pc==0x50c6u)goto L50c6;vm_fault=pc;return;
DISP0LRRRRRRR:
if(dispatch_pc==0x50d8u)goto L50d8;vm_fault=pc;return;
DISP0R:
if(dispatch_pc<0x5b6eu)goto DISP0RL;goto DISP0RR;
DISP0RL:
if(dispatch_pc<0x532eu)goto DISP0RLL;goto DISP0RLR;
DISP0RLL:
if(dispatch_pc<0x524au)goto DISP0RLLL;goto DISP0RLLR;
DISP0RLLL:
if(dispatch_pc<0x5170u)goto DISP0RLLLL;goto DISP0RLLLR;
DISP0RLLLL:
if(dispatch_pc<0x514au)goto DISP0RLLLLL;goto DISP0RLLLLR;
DISP0RLLLLL:
if(dispatch_pc<0x512cu)goto DISP0RLLLLLL;goto DISP0RLLLLLR;
DISP0RLLLLLL:
if(dispatch_pc==0x5124u)goto L5124;vm_fault=pc;return;
DISP0RLLLLLR:
if(dispatch_pc<0x5136u)goto DISP0RLLLLLRL;goto DISP0RLLLLLRR;
DISP0RLLLLLRL:
if(dispatch_pc==0x512cu)goto L512c;vm_fault=pc;return;
DISP0RLLLLLRR:
if(dispatch_pc==0x5136u)goto L5136;vm_fault=pc;return;
DISP0RLLLLR:
if(dispatch_pc<0x515cu)goto DISP0RLLLLRL;goto DISP0RLLLLRR;
DISP0RLLLLRL:
if(dispatch_pc==0x514au)goto L514a;vm_fault=pc;return;
DISP0RLLLLRR:
if(dispatch_pc<0x5164u)goto DISP0RLLLLRRL;goto DISP0RLLLLRRR;
DISP0RLLLLRRL:
if(dispatch_pc==0x515cu)goto L515c;vm_fault=pc;return;
DISP0RLLLLRRR:
if(dispatch_pc==0x5164u)goto L5164;vm_fault=pc;return;
DISP0RLLLR:
if(dispatch_pc<0x51eeu)goto DISP0RLLLRL;goto DISP0RLLLRR;
DISP0RLLLRL:
if(dispatch_pc<0x519cu)goto DISP0RLLLRLL;goto DISP0RLLLRLR;
DISP0RLLLRLL:
if(dispatch_pc==0x5170u)goto L5170;vm_fault=pc;return;
DISP0RLLLRLR:
if(dispatch_pc<0x51c0u)goto DISP0RLLLRLRL;goto DISP0RLLLRLRR;
DISP0RLLLRLRL:
if(dispatch_pc==0x519cu)goto L519c;vm_fault=pc;return;
DISP0RLLLRLRR:
if(dispatch_pc==0x51c0u)goto L51c0;vm_fault=pc;return;
DISP0RLLLRR:
if(dispatch_pc<0x5236u)goto DISP0RLLLRRL;goto DISP0RLLLRRR;
DISP0RLLLRRL:
if(dispatch_pc<0x522cu)goto DISP0RLLLRRLL;goto DISP0RLLLRRLR;
DISP0RLLLRRLL:
if(dispatch_pc==0x51eeu)goto L51ee;vm_fault=pc;return;
DISP0RLLLRRLR:
if(dispatch_pc==0x522cu)goto L522c;vm_fault=pc;return;
DISP0RLLLRRR:
if(dispatch_pc<0x5238u)goto DISP0RLLLRRRL;goto DISP0RLLLRRRR;
DISP0RLLLRRRL:
if(dispatch_pc==0x5236u)goto L5236;vm_fault=pc;return;
DISP0RLLLRRRR:
if(dispatch_pc==0x5238u)goto L5238;vm_fault=pc;return;
DISP0RLLR:
if(dispatch_pc<0x52b6u)goto DISP0RLLRL;goto DISP0RLLRR;
DISP0RLLRL:
if(dispatch_pc<0x526au)goto DISP0RLLRLL;goto DISP0RLLRLR;
DISP0RLLRLL:
if(dispatch_pc<0x5266u)goto DISP0RLLRLLL;goto DISP0RLLRLLR;
DISP0RLLRLLL:
if(dispatch_pc==0x524au)goto L524a;vm_fault=pc;return;
DISP0RLLRLLR:
if(dispatch_pc<0x5268u)goto DISP0RLLRLLRL;goto DISP0RLLRLLRR;
DISP0RLLRLLRL:
if(dispatch_pc==0x5266u)goto L5266;vm_fault=pc;return;
DISP0RLLRLLRR:
if(dispatch_pc==0x5268u)goto L5268;vm_fault=pc;return;
DISP0RLLRLR:
if(dispatch_pc<0x5274u)goto DISP0RLLRLRL;goto DISP0RLLRLRR;
DISP0RLLRLRL:
if(dispatch_pc<0x526cu)goto DISP0RLLRLRLL;goto DISP0RLLRLRLR;
DISP0RLLRLRLL:
if(dispatch_pc==0x526au)goto L526a;vm_fault=pc;return;
DISP0RLLRLRLR:
if(dispatch_pc==0x526cu)goto L526c;vm_fault=pc;return;
DISP0RLLRLRR:
if(dispatch_pc<0x5286u)goto DISP0RLLRLRRL;goto DISP0RLLRLRRR;
DISP0RLLRLRRL:
if(dispatch_pc==0x5274u)goto L5274;vm_fault=pc;return;
DISP0RLLRLRRR:
if(dispatch_pc==0x5286u)goto L5286;vm_fault=pc;return;
DISP0RLLRR:
if(dispatch_pc<0x52beu)goto DISP0RLLRRL;goto DISP0RLLRRR;
DISP0RLLRRL:
if(dispatch_pc<0x52b8u)goto DISP0RLLRRLL;goto DISP0RLLRRLR;
DISP0RLLRRLL:
if(dispatch_pc==0x52b6u)goto L52b6;vm_fault=pc;return;
DISP0RLLRRLR:
if(dispatch_pc<0x52bcu)goto DISP0RLLRRLRL;goto DISP0RLLRRLRR;
DISP0RLLRRLRL:
if(dispatch_pc==0x52b8u)goto L52b8;vm_fault=pc;return;
DISP0RLLRRLRR:
if(dispatch_pc==0x52bcu)goto L52bc;vm_fault=pc;return;
DISP0RLLRRR:
if(dispatch_pc<0x52cau)goto DISP0RLLRRRL;goto DISP0RLLRRRR;
DISP0RLLRRRL:
if(dispatch_pc<0x52c2u)goto DISP0RLLRRRLL;goto DISP0RLLRRRLR;
DISP0RLLRRRLL:
if(dispatch_pc==0x52beu)goto L52be;vm_fault=pc;return;
DISP0RLLRRRLR:
if(dispatch_pc==0x52c2u)goto L52c2;vm_fault=pc;return;
DISP0RLLRRRR:
if(dispatch_pc<0x52dcu)goto DISP0RLLRRRRL;goto DISP0RLLRRRRR;
DISP0RLLRRRRL:
if(dispatch_pc==0x52cau)goto L52ca;vm_fault=pc;return;
DISP0RLLRRRRR:
if(dispatch_pc==0x52dcu)goto L52dc;vm_fault=pc;return;
DISP0RLR:
if(dispatch_pc<0x5524u)goto DISP0RLRL;goto DISP0RLRR;
DISP0RLRL:
if(dispatch_pc<0x543eu)goto DISP0RLRLL;goto DISP0RLRLR;
DISP0RLRLL:
if(dispatch_pc<0x5416u)goto DISP0RLRLLL;goto DISP0RLRLLR;
DISP0RLRLLL:
if(dispatch_pc<0x5378u)goto DISP0RLRLLLL;goto DISP0RLRLLLR;
DISP0RLRLLLL:
if(dispatch_pc==0x532eu)goto L532e;vm_fault=pc;return;
DISP0RLRLLLR:
if(dispatch_pc<0x540eu)goto DISP0RLRLLLRL;goto DISP0RLRLLLRR;
DISP0RLRLLLRL:
if(dispatch_pc==0x5378u)goto L5378;vm_fault=pc;return;
DISP0RLRLLLRR:
if(dispatch_pc==0x540eu)goto L540e;vm_fault=pc;return;
DISP0RLRLLR:
if(dispatch_pc<0x5430u)goto DISP0RLRLLRL;goto DISP0RLRLLRR;
DISP0RLRLLRL:
if(dispatch_pc<0x542cu)goto DISP0RLRLLRLL;goto DISP0RLRLLRLR;
DISP0RLRLLRLL:
if(dispatch_pc==0x5416u)goto L5416;vm_fault=pc;return;
DISP0RLRLLRLR:
if(dispatch_pc==0x542cu)goto L542c;vm_fault=pc;return;
DISP0RLRLLRR:
if(dispatch_pc<0x5436u)goto DISP0RLRLLRRL;goto DISP0RLRLLRRR;
DISP0RLRLLRRL:
if(dispatch_pc==0x5430u)goto L5430;vm_fault=pc;return;
DISP0RLRLLRRR:
if(dispatch_pc==0x5436u)goto L5436;vm_fault=pc;return;
DISP0RLRLR:
if(dispatch_pc<0x5462u)goto DISP0RLRLRL;goto DISP0RLRLRR;
DISP0RLRLRL:
if(dispatch_pc<0x5444u)goto DISP0RLRLRLL;goto DISP0RLRLRLR;
DISP0RLRLRLL:
if(dispatch_pc==0x543eu)goto L543e;vm_fault=pc;return;
DISP0RLRLRLR:
if(dispatch_pc<0x544cu)goto DISP0RLRLRLRL;goto DISP0RLRLRLRR;
DISP0RLRLRLRL:
if(dispatch_pc==0x5444u)goto L5444;vm_fault=pc;return;
DISP0RLRLRLRR:
if(dispatch_pc==0x544cu)goto L544c;vm_fault=pc;return;
DISP0RLRLRR:
if(dispatch_pc<0x54bau)goto DISP0RLRLRRL;goto DISP0RLRLRRR;
DISP0RLRLRRL:
if(dispatch_pc<0x54aau)goto DISP0RLRLRRLL;goto DISP0RLRLRRLR;
DISP0RLRLRRLL:
if(dispatch_pc==0x5462u)goto L5462;vm_fault=pc;return;
DISP0RLRLRRLR:
if(dispatch_pc==0x54aau)goto L54aa;vm_fault=pc;return;
DISP0RLRLRRR:
if(dispatch_pc<0x54d2u)goto DISP0RLRLRRRL;goto DISP0RLRLRRRR;
DISP0RLRLRRRL:
if(dispatch_pc==0x54bau)goto L54ba;vm_fault=pc;return;
DISP0RLRLRRRR:
if(dispatch_pc==0x54d2u)goto L54d2;vm_fault=pc;return;
DISP0RLRR:
if(dispatch_pc<0x5732u)goto DISP0RLRRL;goto DISP0RLRRR;
DISP0RLRRL:
if(dispatch_pc<0x55c6u)goto DISP0RLRRLL;goto DISP0RLRRLR;
DISP0RLRRLL:
if(dispatch_pc<0x5570u)goto DISP0RLRRLLL;goto DISP0RLRRLLR;
DISP0RLRRLLL:
if(dispatch_pc==0x5524u)goto L5524;vm_fault=pc;return;
DISP0RLRRLLR:
if(dispatch_pc<0x559au)goto DISP0RLRRLLRL;goto DISP0RLRRLLRR;
DISP0RLRRLLRL:
if(dispatch_pc==0x5570u)goto L5570;vm_fault=pc;return;
DISP0RLRRLLRR:
if(dispatch_pc==0x559au)goto L559a;vm_fault=pc;return;
DISP0RLRRLR:
if(dispatch_pc<0x570eu)goto DISP0RLRRLRL;goto DISP0RLRRLRR;
DISP0RLRRLRL:
if(dispatch_pc<0x56e6u)goto DISP0RLRRLRLL;goto DISP0RLRRLRLR;
DISP0RLRRLRLL:
if(dispatch_pc==0x55c6u)goto L55c6;vm_fault=pc;return;
DISP0RLRRLRLR:
if(dispatch_pc==0x56e6u)goto L56e6;vm_fault=pc;return;
DISP0RLRRLRR:
if(dispatch_pc<0x5720u)goto DISP0RLRRLRRL;goto DISP0RLRRLRRR;
DISP0RLRRLRRL:
if(dispatch_pc==0x570eu)goto L570e;vm_fault=pc;return;
DISP0RLRRLRRR:
if(dispatch_pc==0x5720u)goto L5720;vm_fault=pc;return;
DISP0RLRRR:
if(dispatch_pc<0x5b36u)goto DISP0RLRRRL;goto DISP0RLRRRR;
DISP0RLRRRL:
if(dispatch_pc<0x5914u)goto DISP0RLRRRLL;goto DISP0RLRRRLR;
DISP0RLRRRLL:
if(dispatch_pc==0x5732u)goto L5732;vm_fault=pc;return;
DISP0RLRRRLR:
if(dispatch_pc<0x5b2cu)goto DISP0RLRRRLRL;goto DISP0RLRRRLRR;
DISP0RLRRRLRL:
if(dispatch_pc==0x5914u)goto L5914;vm_fault=pc;return;
DISP0RLRRRLRR:
if(dispatch_pc==0x5b2cu)goto L5b2c;vm_fault=pc;return;
DISP0RLRRRR:
if(dispatch_pc<0x5b4eu)goto DISP0RLRRRRL;goto DISP0RLRRRRR;
DISP0RLRRRRL:
if(dispatch_pc<0x5b40u)goto DISP0RLRRRRLL;goto DISP0RLRRRRLR;
DISP0RLRRRRLL:
if(dispatch_pc==0x5b36u)goto L5b36;vm_fault=pc;return;
DISP0RLRRRRLR:
if(dispatch_pc==0x5b40u)goto L5b40;vm_fault=pc;return;
DISP0RLRRRRR:
if(dispatch_pc<0x5b68u)goto DISP0RLRRRRRL;goto DISP0RLRRRRRR;
DISP0RLRRRRRL:
if(dispatch_pc==0x5b4eu)goto L5b4e;vm_fault=pc;return;
DISP0RLRRRRRR:
if(dispatch_pc==0x5b68u)goto L5b68;vm_fault=pc;return;
DISP0RR:
if(dispatch_pc<0x5ea8u)goto DISP0RRL;goto DISP0RRR;
DISP0RRL:
if(dispatch_pc<0x5d4cu)goto DISP0RRLL;goto DISP0RRLR;
DISP0RRLL:
if(dispatch_pc<0x5c4cu)goto DISP0RRLLL;goto DISP0RRLLR;
DISP0RRLLL:
if(dispatch_pc<0x5c32u)goto DISP0RRLLLL;goto DISP0RRLLLR;
DISP0RRLLLL:
if(dispatch_pc<0x5ba4u)goto DISP0RRLLLLL;goto DISP0RRLLLLR;
DISP0RRLLLLL:
if(dispatch_pc==0x5b6eu)goto L5b6e;vm_fault=pc;return;
DISP0RRLLLLR:
if(dispatch_pc<0x5bdeu)goto DISP0RRLLLLRL;goto DISP0RRLLLLRR;
DISP0RRLLLLRL:
if(dispatch_pc==0x5ba4u)goto L5ba4;vm_fault=pc;return;
DISP0RRLLLLRR:
if(dispatch_pc==0x5bdeu)goto L5bde;vm_fault=pc;return;
DISP0RRLLLR:
if(dispatch_pc<0x5c44u)goto DISP0RRLLLRL;goto DISP0RRLLLRR;
DISP0RRLLLRL:
if(dispatch_pc<0x5c34u)goto DISP0RRLLLRLL;goto DISP0RRLLLRLR;
DISP0RRLLLRLL:
if(dispatch_pc==0x5c32u)goto L5c32;vm_fault=pc;return;
DISP0RRLLLRLR:
if(dispatch_pc==0x5c34u)goto L5c34;vm_fault=pc;return;
DISP0RRLLLRR:
if(dispatch_pc<0x5c4au)goto DISP0RRLLLRRL;goto DISP0RRLLLRRR;
DISP0RRLLLRRL:
if(dispatch_pc==0x5c44u)goto L5c44;vm_fault=pc;return;
DISP0RRLLLRRR:
if(dispatch_pc==0x5c4au)goto L5c4a;vm_fault=pc;return;
DISP0RRLLR:
if(dispatch_pc<0x5cb6u)goto DISP0RRLLRL;goto DISP0RRLLRR;
DISP0RRLLRL:
if(dispatch_pc<0x5c60u)goto DISP0RRLLRLL;goto DISP0RRLLRLR;
DISP0RRLLRLL:
if(dispatch_pc==0x5c4cu)goto L5c4c;vm_fault=pc;return;
DISP0RRLLRLR:
if(dispatch_pc<0x5c78u)goto DISP0RRLLRLRL;goto DISP0RRLLRLRR;
DISP0RRLLRLRL:
if(dispatch_pc==0x5c60u)goto L5c60;vm_fault=pc;return;
DISP0RRLLRLRR:
if(dispatch_pc==0x5c78u)goto L5c78;vm_fault=pc;return;
DISP0RRLLRR:
if(dispatch_pc<0x5d1au)goto DISP0RRLLRRL;goto DISP0RRLLRRR;
DISP0RRLLRRL:
if(dispatch_pc<0x5cf2u)goto DISP0RRLLRRLL;goto DISP0RRLLRRLR;
DISP0RRLLRRLL:
if(dispatch_pc==0x5cb6u)goto L5cb6;vm_fault=pc;return;
DISP0RRLLRRLR:
if(dispatch_pc==0x5cf2u)goto L5cf2;vm_fault=pc;return;
DISP0RRLLRRR:
if(dispatch_pc<0x5d48u)goto DISP0RRLLRRRL;goto DISP0RRLLRRRR;
DISP0RRLLRRRL:
if(dispatch_pc==0x5d1au)goto L5d1a;vm_fault=pc;return;
DISP0RRLLRRRR:
if(dispatch_pc==0x5d48u)goto L5d48;vm_fault=pc;return;
DISP0RRLR:
if(dispatch_pc<0x5e5cu)goto DISP0RRLRL;goto DISP0RRLRR;
DISP0RRLRL:
if(dispatch_pc<0x5d84u)goto DISP0RRLRLL;goto DISP0RRLRLR;
DISP0RRLRLL:
if(dispatch_pc<0x5d68u)goto DISP0RRLRLLL;goto DISP0RRLRLLR;
DISP0RRLRLLL:
if(dispatch_pc==0x5d4cu)goto L5d4c;vm_fault=pc;return;
DISP0RRLRLLR:
if(dispatch_pc<0x5d74u)goto DISP0RRLRLLRL;goto DISP0RRLRLLRR;
DISP0RRLRLLRL:
if(dispatch_pc==0x5d68u)goto L5d68;vm_fault=pc;return;
DISP0RRLRLLRR:
if(dispatch_pc==0x5d74u)goto L5d74;vm_fault=pc;return;
DISP0RRLRLR:
if(dispatch_pc<0x5dacu)goto DISP0RRLRLRL;goto DISP0RRLRLRR;
DISP0RRLRLRL:
if(dispatch_pc<0x5d98u)goto DISP0RRLRLRLL;goto DISP0RRLRLRLR;
DISP0RRLRLRLL:
if(dispatch_pc==0x5d84u)goto L5d84;vm_fault=pc;return;
DISP0RRLRLRLR:
if(dispatch_pc==0x5d98u)goto L5d98;vm_fault=pc;return;
DISP0RRLRLRR:
if(dispatch_pc<0x5df8u)goto DISP0RRLRLRRL;goto DISP0RRLRLRRR;
DISP0RRLRLRRL:
if(dispatch_pc==0x5dacu)goto L5dac;vm_fault=pc;return;
DISP0RRLRLRRR:
if(dispatch_pc==0x5df8u)goto L5df8;vm_fault=pc;return;
DISP0RRLRR:
if(dispatch_pc<0x5e90u)goto DISP0RRLRRL;goto DISP0RRLRRR;
DISP0RRLRRL:
if(dispatch_pc<0x5e62u)goto DISP0RRLRRLL;goto DISP0RRLRRLR;
DISP0RRLRRLL:
if(dispatch_pc==0x5e5cu)goto L5e5c;vm_fault=pc;return;
DISP0RRLRRLR:
if(dispatch_pc<0x5e88u)goto DISP0RRLRRLRL;goto DISP0RRLRRLRR;
DISP0RRLRRLRL:
if(dispatch_pc==0x5e62u)goto L5e62;vm_fault=pc;return;
DISP0RRLRRLRR:
if(dispatch_pc==0x5e88u)goto L5e88;vm_fault=pc;return;
DISP0RRLRRR:
if(dispatch_pc<0x5e9cu)goto DISP0RRLRRRL;goto DISP0RRLRRRR;
DISP0RRLRRRL:
if(dispatch_pc<0x5e96u)goto DISP0RRLRRRLL;goto DISP0RRLRRRLR;
DISP0RRLRRRLL:
if(dispatch_pc==0x5e90u)goto L5e90;vm_fault=pc;return;
DISP0RRLRRRLR:
if(dispatch_pc==0x5e96u)goto L5e96;vm_fault=pc;return;
DISP0RRLRRRR:
if(dispatch_pc<0x5ea0u)goto DISP0RRLRRRRL;goto DISP0RRLRRRRR;
DISP0RRLRRRRL:
if(dispatch_pc==0x5e9cu)goto L5e9c;vm_fault=pc;return;
DISP0RRLRRRRR:
if(dispatch_pc==0x5ea0u)goto L5ea0;vm_fault=pc;return;
DISP0RRR:
if(dispatch_pc<0x5f38u)goto DISP0RRRL;goto DISP0RRRR;
DISP0RRRL:
if(dispatch_pc<0x5eccu)goto DISP0RRRLL;goto DISP0RRRLR;
DISP0RRRLL:
if(dispatch_pc<0x5eb6u)goto DISP0RRRLLL;goto DISP0RRRLLR;
DISP0RRRLLL:
if(dispatch_pc<0x5eacu)goto DISP0RRRLLLL;goto DISP0RRRLLLR;
DISP0RRRLLLL:
if(dispatch_pc==0x5ea8u)goto L5ea8;vm_fault=pc;return;
DISP0RRRLLLR:
if(dispatch_pc<0x5eb2u)goto DISP0RRRLLLRL;goto DISP0RRRLLLRR;
DISP0RRRLLLRL:
if(dispatch_pc==0x5eacu)goto L5eac;vm_fault=pc;return;
DISP0RRRLLLRR:
if(dispatch_pc==0x5eb2u)goto L5eb2;vm_fault=pc;return;
DISP0RRRLLR:
if(dispatch_pc<0x5ec2u)goto DISP0RRRLLRL;goto DISP0RRRLLRR;
DISP0RRRLLRL:
if(dispatch_pc<0x5ebeu)goto DISP0RRRLLRLL;goto DISP0RRRLLRLR;
DISP0RRRLLRLL:
if(dispatch_pc==0x5eb6u)goto L5eb6;vm_fault=pc;return;
DISP0RRRLLRLR:
if(dispatch_pc==0x5ebeu)goto L5ebe;vm_fault=pc;return;
DISP0RRRLLRR:
if(dispatch_pc<0x5ec8u)goto DISP0RRRLLRRL;goto DISP0RRRLLRRR;
DISP0RRRLLRRL:
if(dispatch_pc==0x5ec2u)goto L5ec2;vm_fault=pc;return;
DISP0RRRLLRRR:
if(dispatch_pc==0x5ec8u)goto L5ec8;vm_fault=pc;return;
DISP0RRRLR:
if(dispatch_pc<0x5f02u)goto DISP0RRRLRL;goto DISP0RRRLRR;
DISP0RRRLRL:
if(dispatch_pc<0x5ed0u)goto DISP0RRRLRLL;goto DISP0RRRLRLR;
DISP0RRRLRLL:
if(dispatch_pc==0x5eccu)goto L5ecc;vm_fault=pc;return;
DISP0RRRLRLR:
if(dispatch_pc<0x5f00u)goto DISP0RRRLRLRL;goto DISP0RRRLRLRR;
DISP0RRRLRLRL:
if(dispatch_pc==0x5ed0u)goto L5ed0;vm_fault=pc;return;
DISP0RRRLRLRR:
if(dispatch_pc==0x5f00u)goto L5f00;vm_fault=pc;return;
DISP0RRRLRR:
if(dispatch_pc<0x5f28u)goto DISP0RRRLRRL;goto DISP0RRRLRRR;
DISP0RRRLRRL:
if(dispatch_pc<0x5f14u)goto DISP0RRRLRRLL;goto DISP0RRRLRRLR;
DISP0RRRLRRLL:
if(dispatch_pc==0x5f02u)goto L5f02;vm_fault=pc;return;
DISP0RRRLRRLR:
if(dispatch_pc==0x5f14u)goto L5f14;vm_fault=pc;return;
DISP0RRRLRRR:
if(dispatch_pc<0x5f30u)goto DISP0RRRLRRRL;goto DISP0RRRLRRRR;
DISP0RRRLRRRL:
if(dispatch_pc==0x5f28u)goto L5f28;vm_fault=pc;return;
DISP0RRRLRRRR:
if(dispatch_pc==0x5f30u)goto L5f30;vm_fault=pc;return;
DISP0RRRR:
if(dispatch_pc<0x5fa8u)goto DISP0RRRRL;goto DISP0RRRRR;
DISP0RRRRL:
if(dispatch_pc<0x5f8au)goto DISP0RRRRLL;goto DISP0RRRRLR;
DISP0RRRRLL:
if(dispatch_pc<0x5f46u)goto DISP0RRRRLLL;goto DISP0RRRRLLR;
DISP0RRRRLLL:
if(dispatch_pc==0x5f38u)goto L5f38;vm_fault=pc;return;
DISP0RRRRLLR:
if(dispatch_pc<0x5f7eu)goto DISP0RRRRLLRL;goto DISP0RRRRLLRR;
DISP0RRRRLLRL:
if(dispatch_pc==0x5f46u)goto L5f46;vm_fault=pc;return;
DISP0RRRRLLRR:
if(dispatch_pc==0x5f7eu)goto L5f7e;vm_fault=pc;return;
DISP0RRRRLR:
if(dispatch_pc<0x5f98u)goto DISP0RRRRLRL;goto DISP0RRRRLRR;
DISP0RRRRLRL:
if(dispatch_pc<0x5f90u)goto DISP0RRRRLRLL;goto DISP0RRRRLRLR;
DISP0RRRRLRLL:
if(dispatch_pc==0x5f8au)goto L5f8a;vm_fault=pc;return;
DISP0RRRRLRLR:
if(dispatch_pc==0x5f90u)goto L5f90;vm_fault=pc;return;
DISP0RRRRLRR:
if(dispatch_pc<0x5fa0u)goto DISP0RRRRLRRL;goto DISP0RRRRLRRR;
DISP0RRRRLRRL:
if(dispatch_pc==0x5f98u)goto L5f98;vm_fault=pc;return;
DISP0RRRRLRRR:
if(dispatch_pc==0x5fa0u)goto L5fa0;vm_fault=pc;return;
DISP0RRRRR:
if(dispatch_pc<0x605au)goto DISP0RRRRRL;goto DISP0RRRRRR;
DISP0RRRRRL:
if(dispatch_pc<0x6014u)goto DISP0RRRRRLL;goto DISP0RRRRRLR;
DISP0RRRRRLL:
if(dispatch_pc==0x5fa8u)goto L5fa8;vm_fault=pc;return;
DISP0RRRRRLR:
if(dispatch_pc<0x6026u)goto DISP0RRRRRLRL;goto DISP0RRRRRLRR;
DISP0RRRRRLRL:
if(dispatch_pc==0x6014u)goto L6014;vm_fault=pc;return;
DISP0RRRRRLRR:
if(dispatch_pc==0x6026u)goto L6026;vm_fault=pc;return;
DISP0RRRRRR:
if(dispatch_pc<0x607cu)goto DISP0RRRRRRL;goto DISP0RRRRRRR;
DISP0RRRRRRL:
if(dispatch_pc<0x6068u)goto DISP0RRRRRRLL;goto DISP0RRRRRRLR;
DISP0RRRRRRLL:
if(dispatch_pc==0x605au)goto L605a;vm_fault=pc;return;
DISP0RRRRRRLR:
if(dispatch_pc==0x6068u)goto L6068;vm_fault=pc;return;
DISP0RRRRRRR:
if(dispatch_pc<0x60b2u)goto DISP0RRRRRRRL;goto DISP0RRRRRRRR;
DISP0RRRRRRRL:
if(dispatch_pc==0x607cu)goto L607c;vm_fault=pc;return;
DISP0RRRRRRRR:
if(dispatch_pc==0x60b2u)goto L60b2;vm_fault=pc;return;

L3d76: /* moveq #$f, D7 */
VSTEP(0x3d76ul);
v=((u32)(15L));
d[7]=v;

goto L3d78;
L3d78: /* lea $3252.w, A0 */
VSTEP(0x3d78ul);
a[0]=0x3252ul;
goto L3d7c;
L3d7c: /* moveq #$f, D6 */
VSTEP(0x3d7cul);
v=((u32)(15L));
d[6]=v;

goto L3d7e;
L3d7e: /* move.w (A0), D0 */
VSTEP(0x3d7eul);
ea=a[0];
tv=cvr16(ea);
VWORD(d[0])=(u16)(tv);

goto L3d80;
L3d80: /* moveq #$f, D1 */
VSTEP(0x3d80ul);
v=((u32)(15L));
d[1]=v;

goto L3d82;
L3d82: /* and.w D0, D1 */
VSTEP(0x3d82ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[1])=(u16)(tr);
goto L3d84;
L3d84: /* beq $3d88 */
VSTEP(0x3d84ul);
if(fz)goto L3d88;
goto L3d86;
L3d86: /* subq.w #1, D0 */
VSTEP(0x3d86ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3d88;
L3d88: /* move.w #$f0, D1 */
VSTEP(0x3d88ul);
tv=((u16)(240L));
VWORD(d[1])=(u16)(tv);

goto L3d8c;
L3d8c: /* and.w D0, D1 */
VSTEP(0x3d8cul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[1])=(u16)(tr);
goto L3d8e;
L3d8e: /* beq $3d94 */
VSTEP(0x3d8eul);
if(fz)goto L3d94;
goto L3d90;
L3d90: /* subi.w #$10, D0 */
VSTEP(0x3d90ul);
tv=((u16)(16L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3d94;
L3d94: /* move.w #$f00, D1 */
VSTEP(0x3d94ul);
tv=((u16)(3840L));
VWORD(d[1])=(u16)(tv);

goto L3d98;
L3d98: /* and.w D0, D1 */
VSTEP(0x3d98ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[1])=(u16)(tr);
goto L3d9a;
L3d9a: /* beq $3da0 */
VSTEP(0x3d9aul);
if(fz)goto L3da0;
goto L3d9c;
L3d9c: /* subi.w #$100, D0 */
VSTEP(0x3d9cul);
tv=((u16)(256L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3da0;
L3da0: /* move.w D0, (A0) */
VSTEP(0x3da0ul);
tv=((u16)d[0]);
ea=a[0];
cvw16(ea,tv);

goto L3da2;
L3da2: /* addq.w #4, A0 */
VSTEP(0x3da2ul);
v=((u16)(4L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L3da4;
L3da4: /* dbra D6, $3d7e */
VSTEP(0x3da4ul);
VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L3d7e;
goto L3da8;
L3da8: /* move.w $36e2.l, D0 */
VSTEP(0x3da8ul);
ea=0x36e2ul;
tv=(((u16)vm_globals[2]<<8)|((u16)vm_globals[3]<<0));
VWORD(d[0])=(u16)(tv);

goto L3dae;
L3dae: /* addq.w #4, D0 */
VSTEP(0x3daeul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L3db0;
L3db0: /* cmp.w $36e2.l, D0 */
VSTEP(0x3db0ul);
ea=0x36e2ul;
tv=(((u16)vm_globals[2]<<8)|((u16)vm_globals[3]<<0));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3db6;
L3db6: /* bne $3db0 */
VSTEP(0x3db6ul);
if(!fz)goto L3db0;
goto L3db8;
L3db8: /* dbra D7, $3d78 */
VSTEP(0x3db8ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L3d78;
goto L3dbc;
L3dbc: /* rts  */
VSTEP(0x3dbcul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
/* Original3dbe..3dea: ascending distance awards source BCD points. */
L3dbe:
 d[0]=0;vnz(0,32);
 VWORD(d[1])=dm_be16((const u8 DM_NEAR *)(vm_vars+1736u));vnz(d[1],16);
 VWORD(d[1])=(u16)vadd(dm_be16((const u8 DM_NEAR *)(vm_vars+1742u)),d[1],16,0);
 VWORD(d[1])=(u16)vsub(dm_be16((const u8 DM_NEAR *)(vm_vars+1738u)),d[1],16,0);
 if(!fn){pc=cvr32(a[7]);a[7]+=4;goto dispatch;}
 dm_put16((u8 DM_NEAR *)(vm_vars+1738u),(u16)((u16)vadd(d[1],dm_be16((const u8 DM_NEAR *)(vm_vars+1738u)),16,0)));
 VWORD(d[1])=(u16)vsub(d[1],0,16,0);
 VWORD(d[1])=(u16)vshift(d[1],4,16,2);
 VBYTE(d[0])=(u8)d[1];vnz(d[0],8);
L3dde_native:
 VWORD(d[1])=(u16)vsub(100ul,d[1],16,0);
 if(!fc){VWORD(d[0])=(u16)vadd(256ul,d[0],16,0);goto L3dde_native;}
 goto L7c82a;

L3dec: /* movem.w $69ec.w, D0-D1 */
VSTEP(0x3decul);
ea=0x69ecul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1734u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1736u));
goto L3df2;
L3df2: /* lea $6476.w, A0 */
VSTEP(0x3df2ul);
a[0]=0x6476ul;
goto L3df6;
L3df6: /* movem.w (A0)+, D2-D3 */
VSTEP(0x3df6ul);
if(platform_spawn_scan(0x6326u,0x6476u,0x6944u))goto L3e30;
ea=a[0];
d[2]=(s16)cvr16(ea+0);
d[3]=(s16)cvr16(ea+2);
a[0]+=4;
goto L3dfa;
L3dfa: /* sub.w D0, D2 */
VSTEP(0x3dfaul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L3dfc;
L3dfc: /* cmpi.w #$98, D2 */
VSTEP(0x3dfcul);
tv=((u16)(152L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L3e00;
L3e00: /* bcc $3e1e */
VSTEP(0x3e00ul);
if(!fc)goto L3e1e;
goto L3e02;
L3e02: /* sub.w D1, D3 */
VSTEP(0x3e02ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L3e04;
L3e04: /* cmpi.w #$50, D3 */
VSTEP(0x3e04ul);
tv=((u16)(80L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L3e08;
L3e08: /* bcc $3e1e */
VSTEP(0x3e08ul);
if(!fc)goto L3e1e;
goto L3e0a;
L3e0a: /* bset #$7, (-$4,A0) */
VSTEP(0x3e0aul);
v=((u16)(7L));
eb=(-4+a[0]);
w=cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
cvw8(eb,r);
goto L3e10;
L3e10: /* move.w (A0)+, D7 */
VSTEP(0x3e10ul);
ea=a[0];
tv=cvr16(ea);
a[0]+=2;
VWORD(d[7])=(u16)(tv);

goto L3e12;
L3e12: /* subq.w #1, D7 */
VSTEP(0x3e12ul);
tv=((u16)(1L));
tw=((u16)d[7]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[7])=(u16)(tr);
goto L3e14;
L3e14: /* bsr $3e62 */
VSTEP(0x3e14ul);
a[7]-=4;cvw32(a[7],0x3e18ul);
goto L3e62;
L3e18: /* dbra D7, $3e14 */
VSTEP(0x3e18ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L3e14;
goto L3e1c;
L3e1c: /* bra $3e2a */
VSTEP(0x3e1cul);
goto L3e2a;
L3e1e: /* move.w (A0), D2 */
VSTEP(0x3e1eul);
ea=a[0];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L3e20;
L3e20: /* add.w D2, D2 */
VSTEP(0x3e20ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L3e22;
L3e22: /* add.w (A0), D2 */
VSTEP(0x3e22ul);
ea=a[0];
tv=cvr16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L3e24;
L3e24: /* add.w D2, D2 */
VSTEP(0x3e24ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L3e26;
L3e26: /* lea ($2,A0,D2.w), A0 */
VSTEP(0x3e26ul);
a[0]=(2+a[0]+((s16)(d[2])));
goto L3e2a;
L3e2a: /* cmpa.w #$6944, A0 */
VSTEP(0x3e2aul);
v=((u16)(26948L));
w=((u32)a[0]);
v=(s32)(s16)v;
r=w-v;
fc=(u8)((u32)w<(u32)v);
goto L3e2e;
L3e2e: /* bcs $3df6 */
VSTEP(0x3e2eul);
if(fc)goto L3df6;
goto L3e30;
L3e30: /* subi.w #$10, D0 */
VSTEP(0x3e30ul);
tv=((u16)(16L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3e34;
L3e34: /* subq.w #8, D1 */
VSTEP(0x3e34ul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L3e36;
L3e36: /* movem.w ($2,A0), D2-D3 */
VSTEP(0x3e36ul);
if(platform_hazard_scan(0x6326u,0x6944u,0x69c2u))goto L3e60;
ea=(2+a[0]);
d[2]=(s16)cvr16(ea+0);
d[3]=(s16)cvr16(ea+2);
goto L3e3c;
L3e3c: /* sub.w D0, D2 */
VSTEP(0x3e3cul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[2])=(u16)(tr);
goto L3e3e;
L3e3e: /* cmpi.w #$c0, D2 */
VSTEP(0x3e3eul);
tv=((u16)(192L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L3e42;
L3e42: /* bcc $3e58 */
VSTEP(0x3e42ul);
if(!fc)goto L3e58;
goto L3e44;
L3e44: /* sub.w D1, D3 */
VSTEP(0x3e44ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L3e46;
L3e46: /* cmpi.w #$60, D3 */
VSTEP(0x3e46ul);
tv=((u16)(96L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3e4a;
L3e4a: /* bcc $3e58 */
VSTEP(0x3e4aul);
if(!fc)goto L3e58;
goto L3e4c;
L3e4c: /* bsr $3e62 */
VSTEP(0x3e4cul);
a[7]-=4;cvw32(a[7],0x3e50ul);
goto L3e62;
L3e50: /* bset #$7, (-$2,A0) */
VSTEP(0x3e50ul);
v=((u16)(7L));
eb=(-2+a[0]);
w=cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
cvw8(eb,r);
goto L3e56;
L3e56: /* bra $3e5a */
VSTEP(0x3e56ul);
goto L3e5a;
L3e58: /* addq.w #6, A0 */
VSTEP(0x3e58ul);
v=((u16)(6L));
w=((u32)a[0]);
r=w+v;
a[0]=r;
goto L3e5a;
L3e5a: /* cmpa.w #$69c2, A0 */
VSTEP(0x3e5aul);
v=((u16)(27074L));
w=((u32)a[0]);
v=(s32)(s16)v;
r=w-v;
fc=(u8)((u32)w<(u32)v);fz=(u8)((u32)w==(u32)v);r=w-v;fn=(u8)((r&0x80000000ul)!=0);fv=(u8)(((w^v)&(w^r)&0x80000000ul)!=0);
goto L3e5e;
L3e5e: /* bcs $3e36 */
VSTEP(0x3e5eul);
if(fc)goto L3e36;
goto L3e60;
L3e60: /* rts  */
VSTEP(0x3e60ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3e62: /* movem.w (A0)+, D2-D4 */
VSTEP(0x3e62ul);
ea=a[0];
d[2]=(s16)cvr16(ea+0);
d[3]=(s16)cvr16(ea+2);
d[4]=(s16)cvr16(ea+4);
a[0]+=6;
goto L3e66;
L3e66: /* cmp.w $22.l, D0 */
VSTEP(0x3e66ul);
ea=0x22ul;
tv=42330u;
tw=((u16)d[0]);
fz=(u8)((u16)tw==(u16)tv);
goto L3e6c;
L3e6c: /* beq $3e6c */
VSTEP(0x3e6cul);
if(fz)goto L3e6c;
goto L3e6e;
L3e6e: /* nop  */
VSTEP(0x3e6eul);
goto L3e70;
L3e70: /* lea $39bc.w, A6 */
VSTEP(0x3e70ul);
a[6]=0x39bcul;
goto L3e74;
L3e74: /* moveq #$9, D6 */
VSTEP(0x3e74ul);
v=((u32)(9L));
d[6]=v;

goto L3e76;
L3e76: /* tst.w (A6) */
VSTEP(0x3e76ul);
ea=a[6];
tv=cvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3e78;
L3e78: /* beq $3e84 */
VSTEP(0x3e78ul);
if(fz)goto L3e84;
goto L3e7a;
L3e7a: /* lea ($16,A6), A6 */
VSTEP(0x3e7aul);
a[6]=(22+a[6]);
goto L3e7e;
L3e7e: /* dbra D6, $3e76 */
VSTEP(0x3e7eul);
VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L3e76;
goto L3e82;
L3e82: /* rts  */
VSTEP(0x3e82ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3e84: /* move.w A0, ($14,A6) */
VSTEP(0x3e84ul);
tv=((u16)a[0]);
ea=(20+a[6]);
cvw16(ea,tv);

goto L3e88;
L3e88: /* bset #$f, D2 */
VSTEP(0x3e88ul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
d[2]=r;
goto L3e8c;
L3e8c: /* movem.w D2-D4, (A6) */
VSTEP(0x3e8cul);
ea=a[6];
cvw16(ea+0,d[2]);
cvw16(ea+2,d[3]);
cvw16(ea+4,d[4]);
goto L3e90;
L3e90: /* clr.l ($8,A6) */
VSTEP(0x3e90ul);
ea=(8+a[6]);
cvw32(ea,0);

goto L3e94;
L3e94: /* bclr #$f, D2 */
VSTEP(0x3e94ul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L3e98;
L3e98: /* clr.l ($10,A6) */
VSTEP(0x3e98ul);
ea=(16+a[6]);
cvw32(ea,0);

goto L3e9c;
L3e9c: /* lea $5aba.w, A5 */
VSTEP(0x3e9cul);
a[5]=0x5abaul;
goto L3ea0;
L3ea0: /* cmp.w (A5)+, D2 */
VSTEP(0x3ea0ul);
ea=a[5];
tv=cvr16(ea);
a[5]+=2;
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L3ea2;
L3ea2: /* bcs $3ea8 */
VSTEP(0x3ea2ul);
if(fc)goto L3ea8;
goto L3ea4;
L3ea4: /* addq.w #2, A5 */
VSTEP(0x3ea4ul);
v=((u16)(2L));
w=((u32)a[5]);
r=w+v;
a[5]=r;
goto L3ea6;
L3ea6: /* bra $3ea0 */
VSTEP(0x3ea6ul);
goto L3ea0;
L3ea8: /* move.w (A5), D3 */
VSTEP(0x3ea8ul);
ea=a[5];
tv=cvr16(ea);
VWORD(d[3])=(u16)(tv);

goto L3eaa;
L3eaa: /* cmpi.w #$c5, D3 */
VSTEP(0x3eaaul);
tv=((u16)(197L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3eae;
L3eae: /* bne $3ebe */
VSTEP(0x3eaeul);
if(!fz)goto L3ebe;
goto L3eb0;
L3eb0: /* bsr $3ec4 */
VSTEP(0x3eb0ul);
a[7]-=4;cvw32(a[7],0x3eb4ul);
goto L3ec4;
L3eb4: /* btst #$c, D2 */
VSTEP(0x3eb4ul);
v=((u16)(12L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L3eb8;
L3eb8: /* beq $3ebe */
VSTEP(0x3eb8ul);
if(fz)goto L3ebe;
goto L3eba;
L3eba: /* move.w #$10e, D3 */
VSTEP(0x3ebaul);
tv=((u16)(270L));
VWORD(d[3])=(u16)(tv);

goto L3ebe;
L3ebe: /* move.w D3, ($6,A6) */
VSTEP(0x3ebeul);
tv=((u16)d[3]);
ea=(6+a[6]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3ec2;
L3ec2: /* rts  */
VSTEP(0x3ec2ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3ec4: /* movea.l $636a.l, A1 */
VSTEP(0x3ec4ul);
ea=0x636aul;
v=(((u32)vm_vars[68]<<24)|((u32)vm_vars[69]<<16)|((u32)vm_vars[70]<<8)|((u32)vm_vars[71]<<0));
a[1]=v;
goto L3eca;
L3eca: /* move.w (A1)+, D2 */
VSTEP(0x3ecaul);
ea=a[1];
tv=cvr16(ea);
a[1]+=2;
VWORD(d[2])=(u16)(tv);

goto L3ecc;
L3ecc: /* move.l A1, $636a.l */
VSTEP(0x3eccul);
v=((u32)a[1]);
vm_vars[68]=(u8)((u32)(v)>>24);
vm_vars[69]=(u8)((u32)(v)>>16);
vm_vars[70]=(u8)((u32)(v)>>8);
vm_vars[71]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3ed2;
L3ed2: /* rts  */
VSTEP(0x3ed2ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3ed4: /* lea $39bc.w, A6 */
VSTEP(0x3ed4ul);
a[6]=0x39bcul;
goto L3ed8;
L3ed8: /* moveq #$9, D7 */
VSTEP(0x3ed8ul);
v=((u32)(9L));
d[7]=v;

goto L3eda;
L3eda: /* move.w (A6), D6 */
VSTEP(0x3edaul);
tv=platform_actor_enter(0x39bcu,1734u);
if(tv==1u)goto L3f36;if(tv==2u)goto L3f9e;
ea=a[6];
tv=(ea>=0x39bcul&&ea<0x3a98ul)?dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul))):cvr16(ea);
VWORD(d[6])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3edc;
L3edc: /* beq $3f96 */
VSTEP(0x3edcul);
if(fz)goto L3f96;
goto L3ee0;
L3ee0: /* movem.w ($2,A6), D0-D1 */
VSTEP(0x3ee0ul);
ea=(2+a[6]);
if(ea>=0x39bcul&&ea<=0x3a94ul){
 d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul)+0u));
 d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul)+2u));
}else{
 d[0]=(s16)cvr16(ea+0);
 d[1]=(s16)cvr16(ea+2);
}
goto L3ee6;
L3ee6: /* move.w D0, D4 */
VSTEP(0x3ee6ul);
tv=((u16)d[0]);
VWORD(d[4])=(u16)(tv);

goto L3ee8;
L3ee8: /* movem.w $69ec.w, D2-D3 */
VSTEP(0x3ee8ul);
ea=0x69ecul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1734u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1736u));
goto L3eee;
L3eee: /* sub.w D2, D0 */
VSTEP(0x3eeeul);
tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3ef0;
L3ef0: /* sub.w D3, D1 */
VSTEP(0x3ef0ul);
tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L3ef2;
L3ef2: /* cmpi.w #$140, D0 */
VSTEP(0x3ef2ul);
tv=((u16)(320L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3ef6;
L3ef6: /* bcs $3efe */
VSTEP(0x3ef6ul);
if(fc)goto L3efe;
goto L3ef8;
L3ef8: /* cmpi.w #-$a0, D0 */
VSTEP(0x3ef8ul);
tv=((u16)(-160L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3efc;
L3efc: /* bcs $3f1c */
VSTEP(0x3efcul);
if(fc)goto L3f1c;
goto L3efe;
L3efe: /* cmpi.w #$a0, D1 */
VSTEP(0x3efeul);
tv=((u16)(160L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f02;
L3f02: /* bcs $3f0a */
VSTEP(0x3f02ul);
if(fc)goto L3f0a;
goto L3f04;
L3f04: /* cmpi.w #-$50, D1 */
VSTEP(0x3f04ul);
tv=((u16)(-80L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f08;
L3f08: /* bcs $3f1c */
VSTEP(0x3f08ul);
if(fc)goto L3f1c;
goto L3f0a;
L3f0a: /* bclr #$7, (A6) */
VSTEP(0x3f0aul);
v=((u16)(7L));
eb=a[6];
w=(eb>=0x39bcul&&eb<(0x39bcul+220ul))?vm_actors[(u16)(eb-0x39bcul)]:cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
if(eb>=0x39bcul&&eb<(0x39bcul+220ul))vm_actors[(u16)(eb-0x39bcul)]=(u8)r;else cvw8(eb,r);
goto L3f0e;
L3f0e: /* beq $3f36 */
VSTEP(0x3f0eul);
if(fz)goto L3f36;
goto L3f10;
L3f10: /* cmpi.w #$50, D1 */
VSTEP(0x3f10ul);
tv=((u16)(80L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f14;
L3f14: /* bcc $3f36 */
VSTEP(0x3f14ul);
if(!fc)goto L3f36;
goto L3f16;
L3f16: /* cmpi.w #$a0, D0 */
VSTEP(0x3f16ul);
tv=((u16)(160L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f1a;
L3f1a: /* bcc $3f36 */
VSTEP(0x3f1aul);
if(!fc)goto L3f36;
goto L3f1c;
L3f1c: /* cmpi.w #$14, D6 */
VSTEP(0x3f1cul);
tv=((u16)(20L));
tw=((u16)d[6]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f20;
L3f20: /* bcs $3f32 */
VSTEP(0x3f20ul);
if(fc)goto L3f32;
goto L3f22;
L3f22: /* lea $0.w, A0 */
VSTEP(0x3f22ul);
a[0]=0x0ul;
goto L3f26;
L3f26: /* movea.l D0, A0 */
VSTEP(0x3f26ul);
v=((u32)d[0]);
a[0]=v;
goto L3f28;
L3f28: /* movea.w ($14,A6), A0 */
VSTEP(0x3f28ul);
ea=(20+a[6]);
v=cvr16(ea);
a[0]=(s16)v;
goto L3f2c;
L3f2c: /* bclr #$7, (-$2,A0) */
VSTEP(0x3f2cul);
v=((u16)(7L));
eb=(-2+a[0]);
w=cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
cvw8(eb,r);
goto L3f32;
L3f32: /* clr.w (A6) */
VSTEP(0x3f32ul);
ea=a[6];
if(ea>=0x39bcul&&ea<=(0x39bcul+218ul))dm_put16((u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul)),0);else cvw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L3f34;
L3f34: /* bra $3f96 */
VSTEP(0x3f34ul);
goto L3f96;
L3f36: /* lea $5ae2.w, A0 */
VSTEP(0x3f36ul);
a[0]=0x5ae2ul;
goto L3f3a;
L3f3a: /* add.w D6, D6 */
VSTEP(0x3f3aul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[6])=(u16)(tr);
goto L3f3c;
L3f3c: /* adda.w D6, A0 */
VSTEP(0x3f3cul);
v=((u16)d[6]);
w=((u32)a[0]);
v=(s32)(s16)v;
r=w+v;
a[0]=r;
goto L3f3e;
L3f3e: /* movea.w (A0), A0 */
VSTEP(0x3f3eul);
ea=a[0];
v=cvr16(ea);
a[0]=(s16)v;
goto L3f40;
L3f40: /* move.w D7, -(A7) */
VSTEP(0x3f40ul);
tv=((u16)d[7]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3f42;
L3f42: /* jsr (A0) */
VSTEP(0x3f42ul);
a[7]-=4;cvw32(a[7],0x3f44ul);
pc=a[0];goto dispatch;
L3f44: /* movem.w ($e,A6), D0-D2 */
VSTEP(0x3f44ul);
ea=(14+a[6]);
if(ea>=0x39bcul&&ea<=0x3a92ul){
 d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul)+0u));
 d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul)+2u));
 d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul)+4u));
}else{
 d[0]=(s16)cvr16(ea+0);
 d[1]=(s16)cvr16(ea+2);
 d[2]=(s16)cvr16(ea+4);
}
goto L3f4a;
L3f4a: /* sub.w $69f2.w, D0 */
VSTEP(0x3f4aul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L3f4e;
L3f4e: /* addq.w #6, D0 */
VSTEP(0x3f4eul);
tv=((u16)(6L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L3f50;
L3f50: /* cmpi.w #$d, D0 */
VSTEP(0x3f50ul);
tv=((u16)(13L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L3f54;
L3f54: /* bcc $3f94 */
VSTEP(0x3f54ul);
if(!fc)goto L3f94;
goto L3f56;
L3f56: /* sub.w $6338.w, D1 */
VSTEP(0x3f56ul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L3f5a;
L3f5a: /* subq.w #6, D1 */
VSTEP(0x3f5aul);
tv=((u16)(6L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L3f5c;
L3f5c: /* bmi $3f94 */
VSTEP(0x3f5cul);
if(fn)goto L3f94;
goto L3f5e;
L3f5e: /* sub.w $69f4.w, D2 */
VSTEP(0x3f5eul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L3f62;
L3f62: /* bpl $3f94 */
VSTEP(0x3f62ul);
if(!fn)goto L3f94;
goto L3f64;
L3f64: /* move.w (A6), D0 */
VSTEP(0x3f64ul);
ea=a[6];
tv=(ea>=0x39bcul&&ea<=(0x39bcul+218ul))?dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul))):cvr16(ea);
VWORD(d[0])=(u16)(tv);

goto L3f66;
L3f66: /* subq.w #2, D0 */
VSTEP(0x3f66ul);
tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L3f68;
L3f68: /* bmi $3f94 */
VSTEP(0x3f68ul);
if(fn)goto L3f94;
goto L3f6a;
L3f6a: /* move.w #$1, (A6) */
VSTEP(0x3f6aul);
tv=((u16)(1L));
ea=a[6];
if(ea>=0x39bcul&&ea<=(0x39bcul+218ul))dm_put16((u8 DM_NEAR *)(vm_actors+(u16)(ea-0x39bcul)),tv);else cvw16(ea,tv);

goto L3f6e;
L3f6e: /* moveq #$a, D0 */
VSTEP(0x3f6eul);
v=((u32)(10L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3f70;
L3f70: /* jsr $48014.l */
VSTEP(0x3f70ul);
a[7]-=4;cvw32(a[7],0x3f76ul);
goto L48014;
L3f76: /* move.w #$fffe, ($a,A6) */
VSTEP(0x3f76ul);
tv=((u16)(65534L));
ea=(10+a[6]);
cvw16(ea,tv);

goto L3f7c;
L3f7c: /* tst.w $6342.w */
VSTEP(0x3f7cul);
ea=0x6342ul;
tv=(((u16)vm_vars[28]<<8)|((u16)vm_vars[29]<<0));
fn=(u8)((tv&0x8000ul)!=0);
goto L3f80;
L3f80: /* bmi $3f94 */
VSTEP(0x3f80ul);
if(fn)goto L3f94;
goto L3f82;
L3f82: /* tst.w $6360.w */
VSTEP(0x3f82ul);
ea=0x6360ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
fz=(u8)((tv&0xfffful)==0);
goto L3f86;
L3f86: /* beq $3f8e */
VSTEP(0x3f86ul);
if(fz)goto L3f8e;
goto L3f88;
L3f88: /* tst.w $633c.w */
VSTEP(0x3f88ul);
ea=0x633cul;
tv=(((u16)vm_vars[22]<<8)|((u16)vm_vars[23]<<0));
fz=(u8)((tv&0xfffful)==0);
goto L3f8c;
L3f8c: /* bne $3f94 */
VSTEP(0x3f8cul);
if(!fz)goto L3f94;
goto L3f8e;
L3f8e: /* moveq #$5, D6 */
VSTEP(0x3f8eul);
v=((u32)(5L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3f90;
L3f90: /* bsr $4d0a */
VSTEP(0x3f90ul);
a[7]-=4;cvw32(a[7],0x3f94ul);
goto L4d0a;
L3f94: /* move.w (A7)+, D7 */
VSTEP(0x3f94ul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L3f96;
L3f96: /* lea ($16,A6), A6 */
VSTEP(0x3f96ul);
a[6]=(22+a[6]);
goto L3f9a;
L3f9a: /* dbra D7, $3eda */
VSTEP(0x3f9aul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L3eda;
goto L3f9e;
L3f9e: /* rts  */
VSTEP(0x3f9eul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3fa0: /* addi.w #$2, (A6) */
VSTEP(0x3fa0ul);
tv=((u16)(2L));
eb=a[6];
tw=(eb>=0x39bcul&&eb<=(0x39bcul+218ul))?dm_be16((const u8 DM_NEAR *)(vm_actors+(u16)(eb-0x39bcul))):cvr16(eb);
tr=tw+tv;
if(eb>=0x39bcul&&eb<=(0x39bcul+218ul))dm_put16((u8 DM_NEAR *)(vm_actors+(u16)(eb-0x39bcul)),(u16)tr);else cvw16(eb,tr);
goto L3fa4;
L3fa4: /* movem.w $69f2.w, D2 */
VSTEP(0x3fa4ul);
ea=0x69f2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
goto L3faa;
L3faa: /* move.w $6338.w, D3 */
VSTEP(0x3faaul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
VWORD(d[3])=(u16)(tv);

goto L3fae;
L3fae: /* addi.w #$15, D3 */
VSTEP(0x3faeul);
tv=((u16)(21L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L3fb2;
L3fb2: /* sub.w D1, D3 */
VSTEP(0x3fb2ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L3fb4;
L3fb4: /* asl.w #3, D3 */
VSTEP(0x3fb4ul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=tw<<3;
VWORD(d[3])=(u16)(tr);
goto L3fb6;
L3fb6: /* ext.l D3 */
VSTEP(0x3fb6ul);
v=((u32)d[3]);
r=(s32)(s16)v;
d[3]=r;

goto L3fb8;
L3fb8: /* sub.w D0, D2 */
VSTEP(0x3fb8ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L3fba;
L3fba: /* bpl $3fbe */
VSTEP(0x3fbaul);
if(!fn)goto L3fbe;
goto L3fbc;
L3fbc: /* neg.w D2 */
VSTEP(0x3fbcul);
tv=((u16)d[2]);
tr=0-tv;fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L3fbe;
L3fbe: /* beq $3fc2 */
VSTEP(0x3fbeul);
if(fz)goto L3fc2;
goto L3fc0;
L3fc0: /* divs.w D2, D3 */
VSTEP(0x3fc0ul);
v=((u16)d[2]);
w=((u32)d[3]);
if(!(s16)v){vm_fault=0xff;return;}
signed_result=(s32)w/(s16)v;
if(signed_result>32767L||signed_result<-32768L){fv=1;}else{r=((u32)((s32)w%(s16)v)<<16)|(u16)signed_result;}
d[3]=r;
goto L3fc2;
L3fc2: /* asr.w #2, D2 */
VSTEP(0x3fc2ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((s16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L3fc4;
L3fc4: /* sub.w D2, D3 */
VSTEP(0x3fc4ul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[3])=(u16)(tr);
goto L3fc6;
L3fc6: /* bsr $467c */
VSTEP(0x3fc6ul);
a[7]-=4;cvw32(a[7],0x3fcaul);
goto L467c;
L3fca: /* cmpi.w #$8, D3 */
VSTEP(0x3fcaul);
tv=((u16)(8L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L3fce;
L3fce: /* bcs $3fde */
VSTEP(0x3fceul);
if(fc)goto L3fde;
goto L3fd0;
L3fd0: /* bmi $3fd6 */
VSTEP(0x3fd0ul);
if(fn)goto L3fd6;
goto L3fd2;
L3fd2: /* moveq #$8, D3 */
VSTEP(0x3fd2ul);
v=((u32)(8L));
d[3]=v;

goto L3fd4;
L3fd4: /* bra $3fde */
VSTEP(0x3fd4ul);
goto L3fde;
L3fd6: /* cmpi.w #-$18, D3 */
VSTEP(0x3fd6ul);
tv=((u16)(-24L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L3fda;
L3fda: /* bcc $3fde */
VSTEP(0x3fdaul);
if(!fc)goto L3fde;
goto L3fdc;
L3fdc: /* moveq #-$18, D3 */
VSTEP(0x3fdcul);
v=((u32)(-24L));
d[3]=v;

goto L3fde;
L3fde: /* move.w D3, ($6,A0) */
VSTEP(0x3fdeul);
tv=((u16)d[3]);
ea=(6+a[0]);
cvw16(ea,tv);

goto L3fe2;
L3fe2: /* cmpi.w #$73, D1 */
VSTEP(0x3fe2ul);
tv=((u16)(115L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L3fe6;
L3fe6: /* bpl $3ff8 */
VSTEP(0x3fe6ul);
if(!fn)goto L3ff8;
goto L3fe8;
L3fe8: /* movem.w D0-D1, -(A7) */
VSTEP(0x3fe8ul);
a[7]-=2;
cvw16(a[7],d[1]);
a[7]-=2;
cvw16(a[7],d[0]);
goto L3fec;
L3fec: /* moveq #$9, D0 */
VSTEP(0x3fecul);
v=((u32)(9L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L3fee;
L3fee: /* jsr $48014.l */
VSTEP(0x3feeul);
a[7]-=4;cvw32(a[7],0x3ff4ul);
goto L48014;
L3ff4: /* movem.w (A7)+, D0-D1 */
VSTEP(0x3ff4ul);
ea=a[7];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
a[7]+=4;
goto L3ff8;
L3ff8: /* rts  */
VSTEP(0x3ff8ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3ffa: /* move.w ($8,A6), D2 */
VSTEP(0x3ffaul);
ea=(8+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L3ffe;
L3ffe: /* cmpi.w #$7, D2 */
VSTEP(0x3ffeul);
tv=((u16)(7L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4002;
L4002: /* bne $401c */
VSTEP(0x4002ul);
if(!fz)goto L401c;
goto L4004;
L4004: /* subq.w #5, D0 */
VSTEP(0x4004ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4006;
L4006: /* bsr $3fa0 */
VSTEP(0x4006ul);
a[7]-=4;cvw32(a[7],0x400aul);
goto L3fa0;
L400a: /* move.w #$d, (A0)+ */
VSTEP(0x400aul);
tv=((u16)(13L));
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L400e;
L400e: /* move.w D1, D3 */
VSTEP(0x400eul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L4010;
L4010: /* subi.w #$11, D3 */
VSTEP(0x4010ul);
tv=((u16)(17L));
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L4014;
L4014: /* movem.w D0/D3, (A0) */
VSTEP(0x4014ul);
ea=a[0];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[3]);
goto L4018;
L4018: /* addq.w #5, D0 */
VSTEP(0x4018ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L401a;
L401a: /* moveq #$8, D2 */
VSTEP(0x401aul);
v=((u32)(8L));
d[2]=v;

goto L401c;
L401c: /* addq.w #1, ($8,A6) */
VSTEP(0x401cul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L4020;
L4020: /* lea $4512.w, A5 */
VSTEP(0x4020ul);
a[5]=0x4512ul;
goto L4024;
L4024: /* andi.w #$fe, D2 */
VSTEP(0x4024ul);
tv=((u16)(254L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L4028;
L4028: /* adda.w D2, A5 */
VSTEP(0x4028ul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L402a;
L402a: /* add.w D2, D2 */
VSTEP(0x402aul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L402c;
L402c: /* adda.w D2, A5 */
VSTEP(0x402cul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L402e;
L402e: /* bra $45ba */
VSTEP(0x402eul);
goto L45ba;
L4032: /* lea $452a.w, A5 */
VSTEP(0x4032ul);
a[5]=0x452aul;
goto L4036;
L4036: /* bsr $45ba */
VSTEP(0x4036ul);
a[7]-=4;cvw32(a[7],0x403aul);
goto L45ba;
L403a: /* subq.w #1, ($8,A6) */
VSTEP(0x403aul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
cvw16(eb,tr);
goto L403e;
L403e: /* bne $404a */
VSTEP(0x403eul);
if(!fz)goto L404a;
goto L4040;
L4040: /* move.w #$20, ($8,A6) */
VSTEP(0x4040ul);
tv=((u16)(32L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L4046;
L4046: /* move.w #$2, (A6) */
VSTEP(0x4046ul);
tv=((u16)(2L));
ea=a[6];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L404a;
L404a: /* rts  */
VSTEP(0x404aul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L404c: /* cmpi.w #-$40, D0 */
VSTEP(0x404cul);
tv=((u16)(-64L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4050;
L4050: /* bmi $409e */
VSTEP(0x4050ul);
if(fn)goto L409e;
goto L4052;
L4052: /* subq.w #1, ($8,A6) */
VSTEP(0x4052ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
cvw16(eb,tr);
goto L4056;
L4056: /* bpl $4070 */
VSTEP(0x4056ul);
if(!fn)goto L4070;
goto L4058;
L4058: /* move.w D0, D2 */
VSTEP(0x4058ul);
tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L405a;
L405a: /* sub.w $69f2.w, D2 */
VSTEP(0x405aul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L405e;
L405e: /* cmpi.w #$30, D2 */
VSTEP(0x405eul);
tv=((u16)(48L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4062;
L4062: /* bcc $4070 */
VSTEP(0x4062ul);
if(!fc)goto L4070;
goto L4064;
L4064: /* clr.w ($8,A6) */
VSTEP(0x4064ul);
ea=(8+a[6]);
cvw16(ea,0);

goto L4068;
L4068: /* move.w #$5, (A6) */
VSTEP(0x4068ul);
tv=((u16)(5L));
ea=a[6];
cvw16(ea,tv);

goto L406c;
L406c: /* bra $432a */
VSTEP(0x406cul);
goto L432a;
L4070: /* moveq #$7, D2 */
VSTEP(0x4070ul);
v=((u32)(7L));
d[2]=v;

goto L4072;
L4072: /* and.w D4, D2 */
VSTEP(0x4072ul);
tv=((u16)d[4]);
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4074;
L4074: /* bne $4324 */
VSTEP(0x4074ul);
if(!fz)goto L4324;
goto L4078;
L4078: /* subi.w #$c, D0 */
VSTEP(0x4078ul);
tv=((u16)(12L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L407c;
L407c: /* bsr $55e0 */
VSTEP(0x407cul);
a[7]-=4;cvw32(a[7],0x4080ul);
goto L55e0;
L4080: /* addi.w #$c, D0 */
VSTEP(0x4080ul);
tv=((u16)(12L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4084;
L4084: /* cmpi.b #$51, D2 */
VSTEP(0x4084ul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4088;
L4088: /* bcc $4324 */
VSTEP(0x4088ul);
if(!fc)goto L4324;
goto L408c;
L408c: /* tst.w ($8,A6) */
VSTEP(0x408cul);
ea=(8+a[6]);
tv=cvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L4090;
L4090: /* bpl $409e */
VSTEP(0x4090ul);
if(!fn)goto L409e;
goto L4092;
L4092: /* move.w D0, D2 */
VSTEP(0x4092ul);
tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L4094;
L4094: /* sub.w $69f2.w, D2 */
VSTEP(0x4094ul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4098;
L4098: /* cmpi.w #$40, D2 */
VSTEP(0x4098ul);
tv=((u16)(64L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L409c;
L409c: /* bcs $4064 */
VSTEP(0x409cul);
if(fc)goto L4064;
goto L409e;
L409e: /* move.w #$2, (A6) */
VSTEP(0x409eul);
tv=((u16)(2L));
ea=a[6];
cvw16(ea,tv);

goto L40a2;
L40a2: /* bra $432a */
VSTEP(0x40a2ul);
goto L432a;
L40a6: /* move.w ($8,A6), D2 */
VSTEP(0x40a6ul);
ea=(8+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L40aa;
L40aa: /* cmpi.w #$7, D2 */
VSTEP(0x40aaul);
tv=((u16)(7L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L40ae;
L40ae: /* bne $40c8 */
VSTEP(0x40aeul);
if(!fz)goto L40c8;
goto L40b0;
L40b0: /* addq.w #5, D0 */
VSTEP(0x40b0ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L40b2;
L40b2: /* bsr $3fa0 */
VSTEP(0x40b2ul);
a[7]-=4;cvw32(a[7],0x40b6ul);
goto L3fa0;
L40b6: /* move.w #$c, (A0)+ */
VSTEP(0x40b6ul);
tv=((u16)(12L));
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L40ba;
L40ba: /* move.w D1, D3 */
VSTEP(0x40baul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L40bc;
L40bc: /* subi.w #$11, D3 */
VSTEP(0x40bcul);
tv=((u16)(17L));
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L40c0;
L40c0: /* movem.w D0/D3, (A0) */
VSTEP(0x40c0ul);
ea=a[0];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[3]);
goto L40c4;
L40c4: /* subq.w #5, D0 */
VSTEP(0x40c4ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L40c6;
L40c6: /* moveq #$8, D2 */
VSTEP(0x40c6ul);
v=((u32)(8L));
d[2]=v;

goto L40c8;
L40c8: /* addq.w #1, ($8,A6) */
VSTEP(0x40c8ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L40cc;
L40cc: /* lea $4530.w, A5 */
VSTEP(0x40ccul);
a[5]=0x4530ul;
goto L40d0;
L40d0: /* andi.w #$fe, D2 */
VSTEP(0x40d0ul);
tv=((u16)(254L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L40d4;
L40d4: /* adda.w D2, A5 */
VSTEP(0x40d4ul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L40d6;
L40d6: /* add.w D2, D2 */
VSTEP(0x40d6ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L40d8;
L40d8: /* adda.w D2, A5 */
VSTEP(0x40d8ul);
v=((u16)d[2]);
w=((u32)a[5]);
v=(s32)(s16)v;
r=w+v;
a[5]=r;
goto L40da;
L40da: /* bra $45ba */
VSTEP(0x40daul);
goto L45ba;
L40de: /* lea $4548.w, A5 */
VSTEP(0x40deul);
a[5]=0x4548ul;
goto L40e2;
L40e2: /* bsr $45ba */
VSTEP(0x40e2ul);
a[7]-=4;cvw32(a[7],0x40e6ul);
goto L45ba;
L40e6: /* subq.w #1, ($8,A6) */
VSTEP(0x40e6ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
cvw16(eb,tr);
goto L40ea;
L40ea: /* bne $40f6 */
VSTEP(0x40eaul);
if(!fz)goto L40f6;
goto L40ec;
L40ec: /* move.w #$20, ($8,A6) */
VSTEP(0x40ecul);
tv=((u16)(32L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L40f2;
L40f2: /* move.w #$3, (A6) */
VSTEP(0x40f2ul);
tv=((u16)(3L));
ea=a[6];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L40f6;
L40f6: /* rts  */
VSTEP(0x40f6ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L40f8: /* cmpi.w #$e0, D0 */
VSTEP(0x40f8ul);
tv=((u16)(224L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L40fc;
L40fc: /* bpl $4146 */
VSTEP(0x40fcul);
if(!fn)goto L4146;
goto L40fe;
L40fe: /* subq.w #1, ($8,A6) */
VSTEP(0x40feul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
cvw16(eb,tr);
goto L4102;
L4102: /* bpl $411c */
VSTEP(0x4102ul);
if(!fn)goto L411c;
goto L4104;
L4104: /* move.w $69f2.w, D2 */
VSTEP(0x4104ul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
VWORD(d[2])=(u16)(tv);

goto L4108;
L4108: /* sub.w D0, D2 */
VSTEP(0x4108ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L410a;
L410a: /* cmpi.w #$30, D2 */
VSTEP(0x410aul);
tv=((u16)(48L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L410e;
L410e: /* bcc $411c */
VSTEP(0x410eul);
if(!fc)goto L411c;
goto L4110;
L4110: /* clr.w ($8,A6) */
VSTEP(0x4110ul);
ea=(8+a[6]);
cvw16(ea,0);

goto L4114;
L4114: /* move.w #$4, (A6) */
VSTEP(0x4114ul);
tv=((u16)(4L));
ea=a[6];
cvw16(ea,tv);

goto L4118;
L4118: /* bra $4254 */
VSTEP(0x4118ul);
goto L4254;
L411c: /* moveq #$7, D2 */
VSTEP(0x411cul);
v=((u32)(7L));
d[2]=v;

goto L411e;
L411e: /* and.w D4, D2 */
VSTEP(0x411eul);
tv=((u16)d[4]);
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4120;
L4120: /* bne $424e */
VSTEP(0x4120ul);
if(!fz)goto L424e;
goto L4124;
L4124: /* addq.w #8, D0 */
VSTEP(0x4124ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4126;
L4126: /* bsr $55e0 */
VSTEP(0x4126ul);
a[7]-=4;cvw32(a[7],0x412aul);
goto L55e0;
L412a: /* subq.w #8, D0 */
VSTEP(0x412aul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L412c;
L412c: /* cmpi.b #$51, D2 */
VSTEP(0x412cul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4130;
L4130: /* bcc $424e */
VSTEP(0x4130ul);
if(!fc)goto L424e;
goto L4134;
L4134: /* tst.w ($8,A6) */
VSTEP(0x4134ul);
ea=(8+a[6]);
tv=cvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);
goto L4138;
L4138: /* bpl $4146 */
VSTEP(0x4138ul);
if(!fn)goto L4146;
goto L413a;
L413a: /* move.w $69f2.w, D2 */
VSTEP(0x413aul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
VWORD(d[2])=(u16)(tv);

goto L413e;
L413e: /* sub.w D0, D2 */
VSTEP(0x413eul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4140;
L4140: /* cmpi.w #$40, D2 */
VSTEP(0x4140ul);
tv=((u16)(64L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4144;
L4144: /* bcs $4110 */
VSTEP(0x4144ul);
if(fc)goto L4110;
goto L4146;
L4146: /* move.w #$3, (A6) */
VSTEP(0x4146ul);
tv=((u16)(3L));
ea=a[6];
cvw16(ea,tv);

goto L414a;
L414a: /* bra $4254 */
VSTEP(0x414aul);
goto L4254;
L414e: /* move.w $69f4.w, D5 */
VSTEP(0x414eul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
VWORD(d[5])=(u16)(tv);

goto L4152;
L4152: /* sub.w D1, D5 */
VSTEP(0x4152ul);
tv=((u16)d[1]);
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4154;
L4154: /* addi.w #$10, D5 */
VSTEP(0x4154ul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[5])=(u16)(tr);
goto L4158;
L4158: /* btst #$2, ($3,A6) */
VSTEP(0x4158ul);
v=((u16)(2L));
eb=(3+a[6]);
w=cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L415e;
L415e: /* beq $41ac */
VSTEP(0x415eul);
if(fz)goto L41ac;
goto L4160;
L4160: /* cmpi.w #$20, D5 */
VSTEP(0x4160ul);
tv=((u16)(32L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4164;
L4164: /* bcs $41ac */
VSTEP(0x4164ul);
if(fc)goto L41ac;
goto L4166;
L4166: /* bpl $417a */
VSTEP(0x4166ul);
if(!fn)goto L417a;
goto L4168;
L4168: /* move.w $8002.l, D2 */
VSTEP(0x4168ul);
ea=0x8002ul;
tv=88u;
VWORD(d[2])=(u16)(tv);

goto L416e;
L416e: /* add.w D2, D2 */
VSTEP(0x416eul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4170;
L4170: /* add.w D2, D2 */
VSTEP(0x4170ul);
tv=((u16)d[2]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4172;
L4172: /* sub.w D2, D3 */
VSTEP(0x4172ul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L4174;
L4174: /* clr.w D2 */
VSTEP(0x4174ul);
VWORD(d[2])=(u16)(0);

goto L4176;
L4176: /* move.b (A0,D3.w), D2 */
VSTEP(0x4176ul);
ea=(a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L417a;
L417a: /* cmpi.b #$5f, D2 */
VSTEP(0x417aul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L417e;
L417e: /* bcs $41ac */
VSTEP(0x417eul);
if(fc)goto L41ac;
goto L4180;
L4180: /* move.b ($1,A0,D3.w), D2 */
VSTEP(0x4180ul);
ea=(1+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4184;
L4184: /* btst #$0, ($1,A6) */
VSTEP(0x4184ul);
v=((u16)(0L));
eb=(1+a[6]);
w=cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L418a;
L418a: /* bne $4190 */
VSTEP(0x418aul);
if(!fz)goto L4190;
goto L418c;
L418c: /* move.b (-$1,A0,D3.w), D2 */
VSTEP(0x418cul);
ea=(-1+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4190;
L4190: /* cmpi.b #$5f, D2 */
VSTEP(0x4190ul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4194;
L4194: /* bcs $41ac */
VSTEP(0x4194ul);
if(fc)goto L41ac;
goto L4196;
L4196: /* move.w #$2, ($8,A6) */
VSTEP(0x4196ul);
tv=((u16)(2L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L419c;
L419c: /* move.w #$d, ($c,A6) */
VSTEP(0x419cul);
tv=((u16)(13L));
ea=(12+a[6]);
cvw16(ea,tv);

goto L41a2;
L41a2: /* subq.w #8, D5 */
VSTEP(0x41a2ul);
tv=((u16)(8L));
tw=((u16)d[5]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[5])=(u16)(tr);
goto L41a4;
L41a4: /* bpl $41ac */
VSTEP(0x41a4ul);
if(!fn)goto L41ac;
goto L41a6;
L41a6: /* move.w #$c, ($c,A6) */
VSTEP(0x41a6ul);
tv=((u16)(12L));
ea=(12+a[6]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L41ac;
L41ac: /* rts  */
VSTEP(0x41acul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L41ae: /* move.w D4, D2 */
VSTEP(0x41aeul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L41b0;
L41b0: /* addq.w #4, D2 */
VSTEP(0x41b0ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L41b2;
L41b2: /* andi.w #$7, D2 */
VSTEP(0x41b2ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L41b6;
L41b6: /* bne $424e */
VSTEP(0x41b6ul);
if(!fz)goto L424e;
goto L41ba;
L41ba: /* cmpi.w #$140, D0 */
VSTEP(0x41baul);
tv=((u16)(320L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L41be;
L41be: /* bpl $41ce */
VSTEP(0x41beul);
if(!fn)goto L41ce;
goto L41c0;
L41c0: /* addq.w #7, D0 */
VSTEP(0x41c0ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L41c2;
L41c2: /* bsr $55e0 */
VSTEP(0x41c2ul);
a[7]-=4;cvw32(a[7],0x41c6ul);
goto L55e0;
L41c6: /* subq.w #7, D0 */
VSTEP(0x41c6ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L41c8;
L41c8: /* cmpi.b #$51, D2 */
VSTEP(0x41c8ul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L41cc;
L41cc: /* bcc $41da */
VSTEP(0x41ccul);
if(!fc)goto L41da;
goto L41ce;
L41ce: /* move.w #$f, (A6) */
VSTEP(0x41ceul);
tv=((u16)(15L));
ea=a[6];
cvw16(ea,tv);

goto L41d2;
L41d2: /* clr.w ($8,A6) */
VSTEP(0x41d2ul);
ea=(8+a[6]);
cvw16(ea,0);

goto L41d6;
L41d6: /* bra $424e */
VSTEP(0x41d6ul);
goto L424e;
L41da: /* bsr $414e */
VSTEP(0x41daul);
a[7]-=4;cvw32(a[7],0x41deul);
goto L414e;
L41de: /* subq.w #1, ($8,A6) */
VSTEP(0x41deul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);
cvw16(eb,tr);
goto L41e2;
L41e2: /* beq $4354 */
VSTEP(0x41e2ul);
if(fz)goto L4354;
goto L41e6;
L41e6: /* bpl $424e */
VSTEP(0x41e6ul);
if(!fn)goto L424e;
goto L41e8;
L41e8: /* move.w $69f2.w, D2 */
VSTEP(0x41e8ul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
VWORD(d[2])=(u16)(tv);

goto L41ec;
L41ec: /* sub.w D0, D2 */
VSTEP(0x41ecul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L41ee;
L41ee: /* bmi $424e */
VSTEP(0x41eeul);
if(fn)goto L424e;
goto L41f0;
L41f0: /* cmpi.w #$20, D5 */
VSTEP(0x41f0ul);
tv=((u16)(32L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L41f4;
L41f4: /* bpl $4230 */
VSTEP(0x41f4ul);
if(!fn)goto L4230;
goto L41f6;
L41f6: /* bcc $420e */
VSTEP(0x41f6ul);
if(!fc)goto L420e;
goto L41f8;
L41f8: /* cmpi.w #$38, D2 */
VSTEP(0x41f8ul);
tv=((u16)(56L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L41fc;
L41fc: /* bcc $424e */
VSTEP(0x41fcul);
if(!fc)goto L424e;
goto L41fe;
L41fe: /* move.w #$10, ($c,A6) */
VSTEP(0x41feul);
tv=((u16)(16L));
ea=(12+a[6]);
cvw16(ea,tv);

goto L4204;
L4204: /* move.l #$10000, ($8,A6) */
VSTEP(0x4204ul);
v=((u32)(65536L));
ea=(8+a[6]);
cvw32(ea,v);

goto L420c;
L420c: /* bra $424e */
VSTEP(0x420cul);
goto L424e;
L420e: /* subi.w #$10, D5 */
VSTEP(0x420eul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4212;
L4212: /* add.w D5, D2 */
VSTEP(0x4212ul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4214;
L4214: /* ble $424e */
VSTEP(0x4214ul);
if((fz||(fn!=fv)))goto L424e;
goto L4216;
L4216: /* subq.w #4, D2 */
VSTEP(0x4216ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4218;
L4218: /* lsr.w #3, D2 */
VSTEP(0x4218ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L421a;
L421a: /* addq.w #1, D2 */
VSTEP(0x421aul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L421c;
L421c: /* cmpi.w #$8, D2 */
VSTEP(0x421cul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4220;
L4220: /* bcc $424e */
VSTEP(0x4220ul);
if(!fc)goto L424e;
goto L4222;
L4222: /* move.w D2, ($8,A6) */
VSTEP(0x4222ul);
tv=((u16)d[2]);
ea=(8+a[6]);
cvw16(ea,tv);

goto L4226;
L4226: /* move.l #$50010, ($a,A6) */
VSTEP(0x4226ul);
v=((u32)(327696L));
ea=(10+a[6]);
cvw32(ea,v);

goto L422e;
L422e: /* bra $424e */
VSTEP(0x422eul);
goto L424e;
L4230: /* subq.w #8, D5 */
VSTEP(0x4230ul);
tv=((u16)(8L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4232;
L4232: /* sub.w D5, D2 */
VSTEP(0x4232ul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4234;
L4234: /* bls $424e */
VSTEP(0x4234ul);
if((fc||fz))goto L424e;
goto L4236;
L4236: /* subq.w #4, D2 */
VSTEP(0x4236ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4238;
L4238: /* lsr.w #3, D2 */
VSTEP(0x4238ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L423a;
L423a: /* addq.w #1, D2 */
VSTEP(0x423aul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L423c;
L423c: /* cmpi.w #$8, D2 */
VSTEP(0x423cul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4240;
L4240: /* bcc $424e */
VSTEP(0x4240ul);
if(!fc)goto L424e;
goto L4242;
L4242: /* move.w D2, ($8,A6) */
VSTEP(0x4242ul);
tv=((u16)d[2]);
ea=(8+a[6]);
cvw16(ea,tv);

goto L4246;
L4246: /* move.l #$70010, ($a,A6) */
VSTEP(0x4246ul);
v=((u32)(458768L));
ea=(10+a[6]);
cvw32(ea,v);

goto L424e;
L424e: /* addq.w #1, D4 */
VSTEP(0x424eul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L4250;
L4250: /* move.w D4, ($2,A6) */
VSTEP(0x4250ul);
tv=((u16)d[4]);
ea=(2+a[6]);
cvw16(ea,tv);

goto L4254;
L4254: /* andi.w #$e, D4 */
VSTEP(0x4254ul);
tv=((u16)(14L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L4258;
L4258: /* lsr.w #1, D4 */
VSTEP(0x4258ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((u16)tw)>>1;
VWORD(d[4])=(u16)(tr);
goto L425a;
L425a: /* move.w D4, -(A7) */
VSTEP(0x425aul);
tv=((u16)d[4]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);

goto L425c;
L425c: /* addq.w #8, D4 */
VSTEP(0x425cul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L425e;
L425e: /* move.w D4, D2 */
VSTEP(0x425eul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4260;
L4260: /* bsr $45fa */
VSTEP(0x4260ul);
a[7]-=4;cvw32(a[7],0x4264ul);
goto L45fa;
L4264: /* move.w (A7)+, D2 */
VSTEP(0x4264ul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L4266;
L4266: /* lsr.w #1, D2 */
VSTEP(0x4266ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4268;
L4268: /* bne $426c */
VSTEP(0x4268ul);
if(!fz)goto L426c;
goto L426a;
L426a: /* addq.w #2, D2 */
VSTEP(0x426aul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L426c;
L426c: /* addq.w #4, D2 */
VSTEP(0x426cul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L426e;
L426e: /* bsr $45fa */
VSTEP(0x426eul);
a[7]-=4;cvw32(a[7],0x4272ul);
goto L45fa;
L4272: /* moveq #$4, D2 */
VSTEP(0x4272ul);
v=((u32)(4L));
d[2]=v;

goto L4274;
L4274: /* bra $45c8 */
VSTEP(0x4274ul);
goto L45c8;
L4278: /* move.w D4, D2 */
VSTEP(0x4278ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L427a;
L427a: /* addq.w #4, D2 */
VSTEP(0x427aul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L427c;
L427c: /* andi.w #$3, D2 */
VSTEP(0x427cul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L4280;
L4280: /* bne $4324 */
VSTEP(0x4280ul);
if(!fz)goto L4324;
goto L4284;
L4284: /* cmpi.w #-$a0, D0 */
VSTEP(0x4284ul);
tv=((u16)(-160L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4288;
L4288: /* bmi $42a4 */
VSTEP(0x4288ul);
if(fn)goto L42a4;
goto L428a;
L428a: /* subq.w #7, D0 */
VSTEP(0x428aul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L428c;
L428c: /* bsr $55e0 */
VSTEP(0x428cul);
a[7]-=4;cvw32(a[7],0x4290ul);
goto L55e0;
L4290: /* addq.w #7, D0 */
VSTEP(0x4290ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4292;
L4292: /* cmpi.b #$51, D2 */
VSTEP(0x4292ul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4296;
L4296: /* bcc $42b0 */
VSTEP(0x4296ul);
if(!fc)goto L42b0;
goto L4298;
L4298: /* move.w ($6,A6), D2 */
VSTEP(0x4298ul);
ea=(6+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L429c;
L429c: /* cmpi.w #$85, D2 */
VSTEP(0x429cul);
tv=((u16)(133L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L42a0;
L42a0: /* beq $4448 */
VSTEP(0x42a0ul);
if(fz)goto L4448;
goto L42a4;
L42a4: /* move.w #$e, (A6) */
VSTEP(0x42a4ul);
tv=((u16)(14L));
ea=a[6];
cvw16(ea,tv);

goto L42a8;
L42a8: /* clr.w ($8,A6) */
VSTEP(0x42a8ul);
ea=(8+a[6]);
cvw16(ea,0);

goto L42ac;
L42ac: /* bra $4324 */
VSTEP(0x42acul);
goto L4324;
L42b0: /* bsr $414e */
VSTEP(0x42b0ul);
a[7]-=4;cvw32(a[7],0x42b4ul);
goto L414e;
L42b4: /* subq.w #1, ($8,A6) */
VSTEP(0x42b4ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);
cvw16(eb,tr);
goto L42b8;
L42b8: /* beq $4354 */
VSTEP(0x42b8ul);
if(fz)goto L4354;
goto L42bc;
L42bc: /* bpl $4324 */
VSTEP(0x42bcul);
if(!fn)goto L4324;
goto L42be;
L42be: /* move.w D0, D2 */
VSTEP(0x42beul);
tv=((u16)d[0]);
VWORD(d[2])=(u16)(tv);

goto L42c0;
L42c0: /* sub.w $69f2.w, D2 */
VSTEP(0x42c0ul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L42c4;
L42c4: /* bmi $4324 */
VSTEP(0x42c4ul);
if(fn)goto L4324;
goto L42c6;
L42c6: /* cmpi.w #$20, D5 */
VSTEP(0x42c6ul);
tv=((u16)(32L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L42ca;
L42ca: /* bpl $4306 */
VSTEP(0x42caul);
if(!fn)goto L4306;
goto L42cc;
L42cc: /* bcc $42e4 */
VSTEP(0x42ccul);
if(!fc)goto L42e4;
goto L42ce;
L42ce: /* cmpi.w #$38, D2 */
VSTEP(0x42ceul);
tv=((u16)(56L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L42d2;
L42d2: /* bcc $4324 */
VSTEP(0x42d2ul);
if(!fc)goto L4324;
goto L42d4;
L42d4: /* move.w #$10, ($c,A6) */
VSTEP(0x42d4ul);
tv=((u16)(16L));
ea=(12+a[6]);
cvw16(ea,tv);

goto L42da;
L42da: /* move.l #$10001, ($8,A6) */
VSTEP(0x42daul);
v=((u32)(65537L));
ea=(8+a[6]);
cvw32(ea,v);

goto L42e2;
L42e2: /* bra $4324 */
VSTEP(0x42e2ul);
goto L4324;
L42e4: /* subi.w #$10, D5 */
VSTEP(0x42e4ul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L42e8;
L42e8: /* add.w D5, D2 */
VSTEP(0x42e8ul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L42ea;
L42ea: /* ble $4324 */
VSTEP(0x42eaul);
if((fz||(fn!=fv)))goto L4324;
goto L42ec;
L42ec: /* subq.w #4, D2 */
VSTEP(0x42ecul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L42ee;
L42ee: /* lsr.w #2, D2 */
VSTEP(0x42eeul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L42f0;
L42f0: /* addq.w #1, D2 */
VSTEP(0x42f0ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L42f2;
L42f2: /* cmpi.w #$8, D2 */
VSTEP(0x42f2ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L42f6;
L42f6: /* bcc $4324 */
VSTEP(0x42f6ul);
if(!fc)goto L4324;
goto L42f8;
L42f8: /* move.w D2, ($8,A6) */
VSTEP(0x42f8ul);
tv=((u16)d[2]);
ea=(8+a[6]);
cvw16(ea,tv);

goto L42fc;
L42fc: /* move.l #$40010, ($a,A6) */
VSTEP(0x42fcul);
v=((u32)(262160L));
ea=(10+a[6]);
cvw32(ea,v);

goto L4304;
L4304: /* bra $4324 */
VSTEP(0x4304ul);
goto L4324;
L4306: /* subq.w #8, D5 */
VSTEP(0x4306ul);
tv=((u16)(8L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4308;
L4308: /* sub.w D5, D2 */
VSTEP(0x4308ul);
tv=((u16)d[5]);
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L430a;
L430a: /* bls $4324 */
VSTEP(0x430aul);
if((fc||fz))goto L4324;
goto L430c;
L430c: /* subq.w #4, D2 */
VSTEP(0x430cul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L430e;
L430e: /* lsr.w #2, D2 */
VSTEP(0x430eul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L4310;
L4310: /* addq.w #1, D2 */
VSTEP(0x4310ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4312;
L4312: /* cmpi.w #$8, D2 */
VSTEP(0x4312ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4316;
L4316: /* bcc $4324 */
VSTEP(0x4316ul);
if(!fc)goto L4324;
goto L4318;
L4318: /* move.w D2, ($8,A6) */
VSTEP(0x4318ul);
tv=((u16)d[2]);
ea=(8+a[6]);
cvw16(ea,tv);

goto L431c;
L431c: /* move.l #$60010, ($a,A6) */
VSTEP(0x431cul);
v=((u32)(393232L));
ea=(10+a[6]);
cvw32(ea,v);

goto L4324;
L4324: /* subq.w #1, D4 */
VSTEP(0x4324ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4326;
L4326: /* move.w D4, ($2,A6) */
VSTEP(0x4326ul);
tv=((u16)d[4]);
ea=(2+a[6]);
cvw16(ea,tv);

goto L432a;
L432a: /* andi.w #$e, D4 */
VSTEP(0x432aul);
tv=((u16)(14L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L432e;
L432e: /* lsr.w #1, D4 */
VSTEP(0x432eul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((u16)tw)>>1;
VWORD(d[4])=(u16)(tr);
goto L4330;
L4330: /* eori.w #$e007, D4 */
VSTEP(0x4330ul);
tv=((u16)(57351L));
tw=((u16)d[4]);
tr=tw^tv;

VWORD(d[4])=(u16)(tr);
goto L4334;
L4334: /* move.w D4, -(A7) */
VSTEP(0x4334ul);
tv=((u16)d[4]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);

goto L4336;
L4336: /* addq.w #8, D4 */
VSTEP(0x4336ul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L4338;
L4338: /* move.w D4, D2 */
VSTEP(0x4338ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L433a;
L433a: /* bsr $45fa */
VSTEP(0x433aul);
a[7]-=4;cvw32(a[7],0x433eul);
goto L45fa;
L433e: /* move.w (A7)+, D2 */
VSTEP(0x433eul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L4340;
L4340: /* lsr.b #1, D2 */
VSTEP(0x4340ul);
tv=((u8)(1L));
tw=((u8)d[2]);
tr=((u8)tw)>>1;fz=(u8)((tr&0xfful)==0);
VBYTE(d[2])=(u8)(tr);
goto L4342;
L4342: /* bne $4346 */
VSTEP(0x4342ul);
if(!fz)goto L4346;
goto L4344;
L4344: /* addq.w #2, D2 */
VSTEP(0x4344ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4346;
L4346: /* addq.w #4, D2 */
VSTEP(0x4346ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4348;
L4348: /* bsr $45fa */
VSTEP(0x4348ul);
a[7]-=4;cvw32(a[7],0x434cul);
goto L45fa;
L434c: /* move.w #$e004, D2 */
VSTEP(0x434cul);
tv=((u16)(57348L));
VWORD(d[2])=(u16)(tv);

goto L4350;
L4350: /* bra $45c8 */
VSTEP(0x4350ul);
goto L45c8;
L4354: /* move.w ($c,A6), D6 */
VSTEP(0x4354ul);
ea=(12+a[6]);
tv=cvr16(ea);
VWORD(d[6])=(u16)(tv);

goto L4358;
L4358: /* move.w D6, (A6) */
VSTEP(0x4358ul);
tv=((u16)d[6]);
ea=a[6];
cvw16(ea,tv);

goto L435a;
L435a: /* cmpi.w #$10, D6 */
VSTEP(0x435aul);
tv=((u16)(16L));
tw=((u16)d[6]);
fz=(u8)((u16)tw==(u16)tv);
goto L435e;
L435e: /* bne $4380 */
VSTEP(0x435eul);
if(!fz)goto L4380;
goto L4360;
L4360: /* move.w #$2, ($8,A6) */
VSTEP(0x4360ul);
tv=((u16)(2L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L4366;
L4366: /* move.w ($a,A6), D2 */
VSTEP(0x4366ul);
ea=(10+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L436a;
L436a: /* cmpi.w #$2, D2 */
VSTEP(0x436aul);
tv=((u16)(2L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L436e;
L436e: /* bcc $4380 */
VSTEP(0x436eul);
if(!fc)goto L4380;
goto L4370;
L4370: /* move.w ($12,A6), D2 */
VSTEP(0x4370ul);
ea=(18+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4374;
L4374: /* addq.w #4, D2 */
VSTEP(0x4374ul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4376;
L4376: /* sub.w $6338.w, D2 */
VSTEP(0x4376ul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L437a;
L437a: /* bpl $4380 */
VSTEP(0x437aul);
if(!fn)goto L4380;
goto L437c;
L437c: /* addq.w #2, ($a,A6) */
VSTEP(0x437cul);
tv=((u16)(2L));
eb=(10+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L4380;
L4380: /* lea $5ae2.w, A0 */
VSTEP(0x4380ul);
a[0]=0x5ae2ul;
goto L4384;
L4384: /* add.w D6, D6 */
VSTEP(0x4384ul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[6])=(u16)(tr);
goto L4386;
L4386: /* adda.w D6, A0 */
VSTEP(0x4386ul);
v=((u16)d[6]);
w=((u32)a[0]);
v=(s32)(s16)v;
r=w+v;
a[0]=r;
goto L4388;
L4388: /* movea.w (A0), A0 */
VSTEP(0x4388ul);
ea=a[0];
v=cvr16(ea);
a[0]=(s16)v;
goto L438a;
L438a: /* jmp (A0) */
VSTEP(0x438aul);
pc=a[0];goto dispatch;
L438c: /* move.w ($4,A6), D4 */
VSTEP(0x438cul);
ea=(4+a[6]);
tv=cvr16(ea);
VWORD(d[4])=(u16)(tv);

goto L4390;
L4390: /* btst #$0, $6375.w */
VSTEP(0x4390ul);
v=((u16)(0L));
eb=0x6375ul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L4396;
L4396: /* bne $43b4 */
VSTEP(0x4396ul);
if(!fz)goto L43b4;
goto L4398;
L4398: /* addq.w #1, D4 */
VSTEP(0x4398ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L439a;
L439a: /* move.w D4, ($4,A6) */
VSTEP(0x439aul);
tv=((u16)d[4]);
ea=(4+a[6]);
cvw16(ea,tv);

goto L439e;
L439e: /* addq.w #1, D1 */
VSTEP(0x439eul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L43a0;
L43a0: /* andi.w #$7, D4 */
VSTEP(0x43a0ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
VWORD(d[4])=(u16)(tr);
goto L43a4;
L43a4: /* bne $43b4 */
VSTEP(0x43a4ul);
if(!fz)goto L43b4;
goto L43a6;
L43a6: /* bsr $55e0 */
VSTEP(0x43a6ul);
a[7]-=4;cvw32(a[7],0x43aaul);
goto L55e0;
L43aa: /* cmpi.b #$5f, D2 */
VSTEP(0x43aaul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L43ae;
L43ae: /* bcc $43b4 */
VSTEP(0x43aeul);
if(!fc)goto L43b4;
goto L43b0;
L43b0: /* bsr $443a */
VSTEP(0x43b0ul);
a[7]-=4;cvw32(a[7],0x43b4ul);
goto L443a;
L43b4: /* not.w D4 */
VSTEP(0x43b4ul);
tv=((u16)d[4]);
tr=~tv;
VWORD(d[4])=(u16)(tr);

goto L43b6;
L43b6: /* andi.w #$7, D4 */
VSTEP(0x43b6ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L43ba;
L43ba: /* subq.w #1, D0 */
VSTEP(0x43baul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L43bc;
L43bc: /* move.w D4, D2 */
VSTEP(0x43bcul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L43be;
L43be: /* bclr #$2, D2 */
VSTEP(0x43beul);
v=((u16)(2L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L43c2;
L43c2: /* beq $43ca */
VSTEP(0x43c2ul);
if(fz)goto L43ca;
goto L43c4;
L43c4: /* ori.w #$e000, D2 */
VSTEP(0x43c4ul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw|tv;

VWORD(d[2])=(u16)(tr);
goto L43c8;
L43c8: /* addq.w #1, D0 */
VSTEP(0x43c8ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L43ca;
L43ca: /* addi.w #$20, D2 */
VSTEP(0x43caul);
tv=((u16)(32L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L43ce;
L43ce: /* move.w D2, -(A7) */
VSTEP(0x43ceul);
tv=((u16)d[2]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L43d0;
L43d0: /* bsr $45fa */
VSTEP(0x43d0ul);
a[7]-=4;cvw32(a[7],0x43d4ul);
goto L45fa;
L43d4: /* move.w (A7)+, D2 */
VSTEP(0x43d4ul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L43d6;
L43d6: /* andi.w #$e000, D2 */
VSTEP(0x43d6ul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L43da;
L43da: /* addi.w #$1f, D2 */
VSTEP(0x43daul);
tv=((u16)(31L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L43de;
L43de: /* bra $45c8 */
VSTEP(0x43deul);
goto L45c8;
L43e2: /* move.w ($4,A6), D4 */
VSTEP(0x43e2ul);
ea=(4+a[6]);
tv=cvr16(ea);
VWORD(d[4])=(u16)(tv);

goto L43e6;
L43e6: /* btst #$0, $6375.w */
VSTEP(0x43e6ul);
v=((u16)(0L));
eb=0x6375ul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L43ec;
L43ec: /* bne $440c */
VSTEP(0x43ecul);
if(!fz)goto L440c;
goto L43ee;
L43ee: /* subq.w #1, D4 */
VSTEP(0x43eeul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L43f0;
L43f0: /* move.w D4, ($4,A6) */
VSTEP(0x43f0ul);
tv=((u16)d[4]);
ea=(4+a[6]);
cvw16(ea,tv);

goto L43f4;
L43f4: /* subq.w #1, D1 */
VSTEP(0x43f4ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L43f6;
L43f6: /* andi.w #$7, D4 */
VSTEP(0x43f6ul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L43fa;
L43fa: /* bne $440c */
VSTEP(0x43faul);
if(!fz)goto L440c;
goto L43fc;
L43fc: /* subq.w #8, D1 */
VSTEP(0x43fcul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L43fe;
L43fe: /* bsr $55e0 */
VSTEP(0x43feul);
a[7]-=4;cvw32(a[7],0x4402ul);
goto L55e0;
L4402: /* addq.w #8, D1 */
VSTEP(0x4402ul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L4404;
L4404: /* cmpi.b #$5f, D2 */
VSTEP(0x4404ul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L4408;
L4408: /* bcc $440c */
VSTEP(0x4408ul);
if(!fc)goto L440c;
goto L440a;
L440a: /* bsr $443a */
VSTEP(0x440aul);
a[7]-=4;cvw32(a[7],0x440cul);
goto L443a;
L440c: /* not.w D4 */
VSTEP(0x440cul);
tv=((u16)d[4]);
tr=~tv;
VWORD(d[4])=(u16)(tr);

goto L440e;
L440e: /* andi.w #$7, D4 */
VSTEP(0x440eul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L4412;
L4412: /* subq.w #1, D0 */
VSTEP(0x4412ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4414;
L4414: /* move.w D4, D2 */
VSTEP(0x4414ul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L4416;
L4416: /* bclr #$2, D2 */
VSTEP(0x4416ul);
v=((u16)(2L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L441a;
L441a: /* beq $4422 */
VSTEP(0x441aul);
if(fz)goto L4422;
goto L441c;
L441c: /* ori.w #$e000, D2 */
VSTEP(0x441cul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw|tv;

VWORD(d[2])=(u16)(tr);
goto L4420;
L4420: /* addq.w #1, D0 */
VSTEP(0x4420ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4422;
L4422: /* addi.w #$1b, D2 */
VSTEP(0x4422ul);
tv=((u16)(27L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4426;
L4426: /* move.w D2, -(A7) */
VSTEP(0x4426ul);
tv=((u16)d[2]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4428;
L4428: /* bsr $45fa */
VSTEP(0x4428ul);
a[7]-=4;cvw32(a[7],0x442cul);
goto L45fa;
L442c: /* move.w (A7)+, D2 */
VSTEP(0x442cul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L442e;
L442e: /* andi.w #$e000, D2 */
VSTEP(0x442eul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L4432;
L4432: /* addi.w #$1a, D2 */
VSTEP(0x4432ul);
tv=((u16)(26L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4436;
L4436: /* bra $45c8 */
VSTEP(0x4436ul);
goto L45c8;
L443a: /* moveq #$7, D2 */
VSTEP(0x443aul);
v=((u32)(7L));
d[2]=v;

goto L443c;
L443c: /* moveq #$4c, D3 */
VSTEP(0x443cul);
v=((u32)(76L));
d[3]=v;

goto L443e;
L443e: /* sub.w D0, D3 */
VSTEP(0x443eul);
tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L4440;
L4440: /* add.w D3, D3 */
VSTEP(0x4440ul);
tv=((u16)d[3]);
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[3])=(u16)(tr);
goto L4442;
L4442: /* addx.w D2, D2 */
VSTEP(0x4442ul);
v=((u16)d[2]);
w=((u16)d[2]);
r=w+v+fx;fx=(u8)((r&~0xfffful)!=0);
VWORD(d[2])=(u16)(r);
goto L4444;
L4444: /* move.w D2, (A6) */
VSTEP(0x4444ul);
tv=((u16)d[2]);
ea=a[6];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4446;
L4446: /* rts  */
VSTEP(0x4446ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4448: /* move.w #$ffff, ($8,A6) */
VSTEP(0x4448ul);
tv=((u16)(65535L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L444e;
L444e: /* moveq #$6, D2 */
VSTEP(0x444eul);
v=((u32)(6L));
d[2]=v;

goto L4450;
L4450: /* cmp.w $6338.w, D1 */
VSTEP(0x4450ul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4454;
L4454: /* bmi $4466 */
VSTEP(0x4454ul);
if(fn)goto L4466;
goto L4456;
L4456: /* moveq #$1, D2 */
VSTEP(0x4456ul);
v=((u32)(1L));
d[2]=v;

goto L4458;
L4458: /* move.w ($12,A6), D3 */
VSTEP(0x4458ul);
ea=(18+a[6]);
tv=cvr16(ea);
VWORD(d[3])=(u16)(tv);

goto L445c;
L445c: /* addq.w #4, D3 */
VSTEP(0x445cul);
tv=((u16)(4L));
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[3])=(u16)(tr);
goto L445e;
L445e: /* cmp.w $6338.w, D3 */
VSTEP(0x445eul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[3]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4462;
L4462: /* bpl $4466 */
VSTEP(0x4462ul);
if(!fn)goto L4466;
goto L4464;
L4464: /* addq.w #2, D2 */
VSTEP(0x4464ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4466;
L4466: /* move.w D2, ($a,A6) */
VSTEP(0x4466ul);
tv=((u16)d[2]);
ea=(10+a[6]);
cvw16(ea,tv);

goto L446a;
L446a: /* move.w #$10, (A6) */
VSTEP(0x446aul);
tv=((u16)(16L));
ea=a[6];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L446e;
L446e: /* bsr $45ae */
VSTEP(0x446eul);
a[7]-=4;cvw32(a[7],0x4472ul);
goto L45ae;
L4472: /* subq.w #1, ($8,A6) */
VSTEP(0x4472ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
cvw16(eb,tr);
goto L4476;
L4476: /* bpl $4480 */
VSTEP(0x4476ul);
if(!fn)goto L4480;
goto L4478;
L4478: /* addq.w #1, (A6) */
VSTEP(0x4478ul);
tv=((u16)(1L));
eb=a[6];
tw=cvr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
cvw16(eb,tr);
goto L447a;
L447a: /* move.w #$3, ($8,A6) */
VSTEP(0x447aul);
tv=((u16)(3L));
ea=(8+a[6]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4480;
L4480: /* rts  */
VSTEP(0x4480ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4482: /* bsr $45ae */
VSTEP(0x4482ul);
a[7]-=4;cvw32(a[7],0x4486ul);
goto L45ae;
L4486: /* btst #$0, $6375.l */
VSTEP(0x4486ul);
v=((u16)(0L));
eb=0x6375ul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L448e;
L448e: /* bne $4480 */
VSTEP(0x448eul);
if(!fz)goto L4480;
goto L4490;
L4490: /* bsr $467c */
VSTEP(0x4490ul);
a[7]-=4;cvw32(a[7],0x4494ul);
goto L467c;
L4494: /* sub.w (A5)+, D1 */
VSTEP(0x4494ul);
ea=a[5];
tv=cvr16(ea);
a[5]+=2;
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4496;
L4496: /* add.w $6358.w, D1 */
VSTEP(0x4496ul);
ea=0x6358ul;
tv=(((u16)vm_vars[50]<<8)|((u16)vm_vars[51]<<0));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L449a;
L449a: /* add.w (A5)+, D0 */
VSTEP(0x449aul);
ea=a[5];
tv=cvr16(ea);
a[5]+=2;
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L449c;
L449c: /* add.w $6356.w, D0 */
VSTEP(0x449cul);
ea=0x6356ul;
tv=(((u16)vm_vars[48]<<8)|((u16)vm_vars[49]<<0));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L44a0;
L44a0: /* move.w (A5), (A0)+ */
VSTEP(0x44a0ul);
ea=a[5];
tv=cvr16(ea);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L44a2;
L44a2: /* movem.w D0-D1, (A0) */
VSTEP(0x44a2ul);
ea=a[0];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L44a6;
L44a6: /* moveq #$c, D2 */
VSTEP(0x44a6ul);
v=((u32)(12L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L44a8;
L44a8: /* bsr $44f4 */
VSTEP(0x44a8ul);
a[7]-=4;cvw32(a[7],0x44acul);
goto L44f4;
L44ac: /* subq.w #1, ($8,A6) */
VSTEP(0x44acul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
cvw16(eb,tr);
goto L44b0;
L44b0: /* bne $4480 */
VSTEP(0x44b0ul);
if(!fz)goto L4480;
goto L44b2;
L44b2: /* move.w #$6, ($8,A6) */
VSTEP(0x44b2ul);
tv=((u16)(6L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L44b8;
L44b8: /* addq.w #1, (A6) */
VSTEP(0x44b8ul);
tv=((u16)(1L));
eb=a[6];
tw=cvr16(eb);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
cvw16(eb,tr);
goto L44ba;
L44ba: /* rts  */
VSTEP(0x44baul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L44bc: /* bsr $45ae */
VSTEP(0x44bcul);
a[7]-=4;cvw32(a[7],0x44c0ul);
goto L45ae;
L44c0: /* subq.w #1, ($8,A6) */
VSTEP(0x44c0ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
cvw16(eb,tr);
goto L44c4;
L44c4: /* bne $4480 */
VSTEP(0x44c4ul);
if(!fz)goto L4480;
goto L44c6;
L44c6: /* move.w #$4, ($8,A6) */
VSTEP(0x44c6ul);
tv=((u16)(4L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L44cc;
L44cc: /* move.w ($a,A6), D2 */
VSTEP(0x44ccul);
ea=(10+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L44d0;
L44d0: /* move.w ($6,A6), D3 */
VSTEP(0x44d0ul);
ea=(6+a[6]);
tv=cvr16(ea);
VWORD(d[3])=(u16)(tv);

goto L44d4;
L44d4: /* cmpi.w #$85, D3 */
VSTEP(0x44d4ul);
tv=((u16)(133L));
tw=((u16)d[3]);
fz=(u8)((u16)tw==(u16)tv);
goto L44d8;
L44d8: /* bne $44de */
VSTEP(0x44d8ul);
if(!fz)goto L44de;
goto L44da;
L44da: /* move.w #$1, D2 */
VSTEP(0x44daul);
tv=((u16)(1L));
VWORD(d[2])=(u16)(tv);

goto L44de;
L44de: /* not.w D2 */
VSTEP(0x44deul);
tv=((u16)d[2]);
tr=~tv;
VWORD(d[2])=(u16)(tr);

goto L44e0;
L44e0: /* andi.w #$1, D2 */
VSTEP(0x44e0ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L44e4;
L44e4: /* addi.w #$e, D2 */
VSTEP(0x44e4ul);
tv=((u16)(14L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L44e8;
L44e8: /* move.w D2, (A6) */
VSTEP(0x44e8ul);
tv=((u16)d[2]);
ea=a[6];
cvw16(ea,tv);

goto L44ea;
L44ea: /* move.w D2, ($c,A6) */
VSTEP(0x44eaul);
tv=((u16)d[2]);
ea=(12+a[6]);
cvw16(ea,tv);

goto L44ee;
L44ee: /* move.w ($2,A6), D4 */
VSTEP(0x44eeul);
ea=(2+a[6]);
tv=cvr16(ea);
VWORD(d[4])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L44f2;
L44f2: /* rts  */
VSTEP(0x44f2ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L44f4: /* cmpi.w #$a0, D0 */
VSTEP(0x44f4ul);
tv=((u16)(160L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L44f8;
L44f8: /* bcc $44f2 */
VSTEP(0x44f8ul);
if(!fc)goto L44f2;
goto L44fa;
L44fa: /* cmpi.w #$59, D1 */
VSTEP(0x44faul);
tv=((u16)(89L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L44fe;
L44fe: /* bcc $44f2 */
VSTEP(0x44feul);
if(!fc)goto L44f2;
goto L4500;
L4500: /* movem.w D0-D1, -(A7) */
VSTEP(0x4500ul);
a[7]-=2;
cvw16(a[7],d[1]);
a[7]-=2;
cvw16(a[7],d[0]);
goto L4504;
L4504: /* move.w D2, D0 */
VSTEP(0x4504ul);
tv=((u16)d[2]);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4506;
L4506: /* jsr $48014.l */
VSTEP(0x4506ul);
a[7]-=4;cvw32(a[7],0x450cul);
goto L48014;
L450c: /* movem.w (A7)+, D0-D1 */
VSTEP(0x450cul);
ea=a[7];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
a[7]+=4;
goto L4510;
L4510: /* rts  */
VSTEP(0x4510ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L45ae: /* move.w ($a,A6), D2 */
VSTEP(0x45aeul);
ea=(10+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L45b2;
L45b2: /* mulu.w #$c, D2 */
VSTEP(0x45b2ul);
v=((u16)(12L));
w=((u32)d[2]);
r=(u32)(u16)v*(u16)w;

d[2]=r;
goto L45b6;
L45b6: /* lea (-$6a,PC,D2.w), A5 */
VSTEP(0x45b6ul);
a[5]=(-106+0x45b8ul+((s16)(d[2])));
goto L45ba;
L45ba: /* move.w (A5)+, D2 */
VSTEP(0x45baul);
ea=a[5];
tv=cvr16(ea);
a[5]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L45bc;
L45bc: /* bsr $45c8 */
VSTEP(0x45bcul);
a[7]-=4;cvw32(a[7],0x45beul);
goto L45c8;
L45be: /* move.w (A5)+, D2 */
VSTEP(0x45beul);
ea=a[5];
tv=cvr16(ea);
a[5]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L45c0;
L45c0: /* bsr $45fa */
VSTEP(0x45c0ul);
a[7]-=4;cvw32(a[7],0x45c2ul);
goto L45fa;
L45c2: /* move.w (A5)+, D2 */
VSTEP(0x45c2ul);
ea=a[5];
tv=cvr16(ea);
a[5]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L45c4;
L45c4: /* bne $45fa */
VSTEP(0x45c4ul);
if(!fz)goto L45fa;
goto L45c6;
L45c6: /* rts  */
VSTEP(0x45c6ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L45c8: /* add.w ($6,A6), D2 */
VSTEP(0x45c8ul);
ea=(6+a[6]);
tv=cvr16(ea);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L45cc;
L45cc: /* move.w D2, D3 */
VSTEP(0x45ccul);
tv=((u16)d[2]);
VWORD(d[3])=(u16)(tv);

goto L45ce;
L45ce: /* andi.w #$1fff, D3 */
VSTEP(0x45ceul);
tv=((u16)(8191L));
tw=((u16)d[3]);
tr=tw&tv;

VWORD(d[3])=(u16)(tr);
goto L45d2;
L45d2: /* lsl.w #1, D3 */
VSTEP(0x45d2ul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw<<1;
VWORD(d[3])=(u16)(tr);
goto L45d4;
L45d4: /* lea $60c4.w, A0 */
VSTEP(0x45d4ul);
a[0]=0x60c4ul;
goto L45d8;
L45d8: /* move.w D1, D4 */
VSTEP(0x45d8ul);
tv=((u16)d[1]);
VWORD(d[4])=(u16)(tv);

goto L45da;
L45da: /* add.w D4, D4 */
VSTEP(0x45daul);
tv=((u16)d[4]);
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L45dc;
L45dc: /* move.b (-$2,A0,D3.w), D5 */
VSTEP(0x45dcul);
ea=(-2+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[5])=(u8)(tv);

goto L45e0;
L45e0: /* ext.w D5 */
VSTEP(0x45e0ul);
v=((u32)d[5]);
r=(s16)(s8)v;
VWORD(d[5])=(u16)(r);

goto L45e2;
L45e2: /* sub.w D5, D4 */
VSTEP(0x45e2ul);
tv=((u16)d[5]);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L45e4;
L45e4: /* asr.w #1, D4 */
VSTEP(0x45e4ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;
VWORD(d[4])=(u16)(tr);
goto L45e6;
L45e6: /* movem.w D0-D1/D4, ($e,A6) */
VSTEP(0x45e6ul);
ea=(14+a[6]);
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
cvw16(ea+4,d[4]);
goto L45ec;
L45ec: /* movem.w D0-D1/A5-A6, -(A7) */
VSTEP(0x45ecul);
if(platform_actor_draw(0x45f4u,1u))goto L45f8;
if(platform_draw_push())goto L45f0;
a[7]-=2;
cvw16(a[7],a[6]);
a[7]-=2;
cvw16(a[7],a[5]);
a[7]-=2;
cvw16(a[7],d[1]);
a[7]-=2;
cvw16(a[7],d[0]);
goto L45f0;
L45f0: /* bsr $5734 */
VSTEP(0x45f0ul);
a[7]-=4;cvw32(a[7],0x45f4ul);
goto L5734;
L45f4: /* movem.w (A7)+, D0-D1/A5-A6 */
VSTEP(0x45f4ul);
ea=a[7];if(platform_draw_pop())goto L45f8;
ea=a[7];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
a[5]=(s16)cvr16(ea+4);
a[6]=(s16)cvr16(ea+6);
a[7]+=8;
goto L45f8;
L45f8: /* rts  */
VSTEP(0x45f8ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L45fa: /* add.w ($6,A6), D2 */
VSTEP(0x45faul);
ea=(6+a[6]);
tv=cvr16(ea);
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L45fe;
L45fe: /* movem.w D0-D1/A5-A6, -(A7) */
VSTEP(0x45feul);
if(platform_actor_draw(0x4606u,1u))goto L460a;
if(platform_draw_push())goto L4602;
a[7]-=2;
cvw16(a[7],a[6]);
a[7]-=2;
cvw16(a[7],a[5]);
a[7]-=2;
cvw16(a[7],d[1]);
a[7]-=2;
cvw16(a[7],d[0]);
goto L4602;
L4602: /* bsr $5734 */
VSTEP(0x4602ul);
a[7]-=4;cvw32(a[7],0x4606ul);
goto L5734;
L4606: /* movem.w (A7)+, D0-D1/A5-A6 */
VSTEP(0x4606ul);
ea=a[7];if(platform_draw_pop())goto L460a;
ea=a[7];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
a[5]=(s16)cvr16(ea+4);
a[6]=(s16)cvr16(ea+6);
a[7]+=8;
goto L460a;
L460a: /* rts  */
VSTEP(0x460aul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L460c: /* move.w ($a,A6), D2 */
VSTEP(0x460cul);
ea=(10+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4610;
L4610: /* addq.w #1, D2 */
VSTEP(0x4610ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4612;
L4612: /* cmpi.w #$e, D2 */
VSTEP(0x4612ul);
tv=((u16)(14L));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4616;
L4616: /* bpl $461c */
VSTEP(0x4616ul);
if(!fn)goto L461c;
goto L4618;
L4618: /* move.w D2, ($a,A6) */
VSTEP(0x4618ul);
tv=((u16)d[2]);
ea=(10+a[6]);
cvw16(ea,tv);

goto L461c;
L461c: /* asr.w #1, D2 */
VSTEP(0x461cul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((s16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L461e;
L461e: /* add.w D2, ($4,A6) */
VSTEP(0x461eul);
tv=((u16)d[2]);
eb=(4+a[6]);
tw=cvr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
cvw16(eb,tr);
goto L4622;
L4622: /* lea $6326.w, A5 */
VSTEP(0x4622ul);
a[5]=0x6326ul;
goto L4626;
L4626: /* cmpi.w #$64, D1 */
VSTEP(0x4626ul);
tv=((u16)(100L));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L462a;
L462a: /* bmi $45ba */
VSTEP(0x462aul);
if(fn)goto L45ba;
goto L462e;
L462e: /* clr.w (A6) */
VSTEP(0x462eul);
ea=a[6];
cvw16(ea,0);

goto L4630;
L4630: /* move.l #$350, D0 */
VSTEP(0x4630ul);
v=((u32)(848L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4636;
L4636: /* jmp $7c82a.l */
VSTEP(0x4636ul);
goto L7c82a;
L463c: /* lea $48a4.w, A5 */
VSTEP(0x463cul);
a[5]=0x48a4ul;
goto L4640;
L4640: /* lea $48d2.w, A6 */
VSTEP(0x4640ul);
a[6]=0x48d2ul;
goto L4644;
L4644: /* moveq #$13, D7 */
VSTEP(0x4644ul);
v=((u32)(19L));
d[7]=v;

goto L4646;
L4646: /* move.w (A6)+, D2 */
VSTEP(0x4646ul);
if(platform_empty_shots(0x48d2u,2u))goto L467a;
ea=a[6];
tv=cvr16(ea);
a[6]+=2;
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4648;
L4648: /* beq $4674 */
VSTEP(0x4648ul);
if(fz)goto L4674;
goto L464a;
L464a: /* movem.w (A6), D0-D1 */
VSTEP(0x464aul);
ea=a[6];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
goto L464e;
L464e: /* move.l A6, -(A7) */
VSTEP(0x464eul);
v=((u32)a[6]);
a[7]-=4;
ea=a[7];
cvw32(ea,v);

goto L4650;
L4650: /* move.w D7, -(A7) */
VSTEP(0x4650ul);
tv=((u16)d[7]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);

goto L4652;
L4652: /* btst #$f, D2 */
VSTEP(0x4652ul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4656;
L4656: /* beq $4660 */
VSTEP(0x4656ul);
if(fz)goto L4660;
goto L4658;
L4658: /* ext.w D2 */
VSTEP(0x4658ul);
v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);

goto L465a;
L465a: /* move.w D2, (-$2,A6) */
VSTEP(0x465aul);
tv=((u16)d[2]);
ea=(-2+a[6]);
cvw16(ea,tv);

goto L465e;
L465e: /* moveq #$4, D2 */
VSTEP(0x465eul);
v=((u32)(4L));
d[2]=v;

goto L4660;
L4660: /* ror.w #1, D2 */
VSTEP(0x4660ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=(((u16)tw>>1)|(tw<<15));fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4662;
L4662: /* bpl $4668 */
VSTEP(0x4662ul);
if(!fn)goto L4668;
goto L4664;
L4664: /* ori.w #$e000, D2 */
VSTEP(0x4664ul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw|tv;

VWORD(d[2])=(u16)(tr);
goto L4668;
L4668: /* addi.w #$3b, D2 */
VSTEP(0x4668ul);
tv=((u16)(59L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L466c;
L466c: /* bsr $5734 */
VSTEP(0x466cul);
a[7]-=4;cvw32(a[7],0x4670ul);
goto L5734;
L4670: /* move.w (A7)+, D7 */
VSTEP(0x4670ul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4672;
L4672: /* movea.l (A7)+, A6 */
VSTEP(0x4672ul);
ea=a[7];
v=cvr32(ea);
a[7]+=4;
a[6]=v;
goto L4674;
L4674: /* addq.w #6, A6 */
VSTEP(0x4674ul);
v=((u16)(6L));
w=((u32)a[6]);
r=w+v;
a[6]=r;
goto L4676;
L4676: /* dbra D7, $4646 */
VSTEP(0x4676ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4646;
goto L467a;
L467a: /* rts  */
VSTEP(0x467aul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L467c: /* lea $48d2.w, A0 */
VSTEP(0x467cul);
a[0]=0x48d2ul;
goto L4680;
L4680: /* moveq #$13, D7 */
VSTEP(0x4680ul);
v=((u32)(19L));
d[7]=v;

goto L4682;
L4682: /* tst.w (A0) */
VSTEP(0x4682ul);
ea=a[0];
tv=cvr16(ea);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4684;
L4684: /* beq $4694 */
VSTEP(0x4684ul);
if(fz)goto L4694;
goto L4686;
L4686: /* lea ($8,A0), A0 */
VSTEP(0x4686ul);
a[0]=(8+a[0]);
goto L468a;
L468a: /* dbra D7, $4682 */
VSTEP(0x468aul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4682;
goto L468e;
L468e: /* movea.l #$fffffff8, A0 */
VSTEP(0x468eul);
v=((u32)(4294967288L));
a[0]=v;
goto L4694;
L4694: /* rts  */
VSTEP(0x4694ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4696: /* lea $48a4.w, A5 */
VSTEP(0x4696ul);
a[5]=0x48a4ul;
goto L469a;
L469a: /* lea $48d2.w, A6 */
VSTEP(0x469aul);
a[6]=0x48d2ul;
goto L469e;
L469e: /* moveq #$13, D7 */
VSTEP(0x469eul);
v=((u32)(19L));
d[7]=v;

goto L46a0;
L46a0: /* move.w (A6)+, D6 */
VSTEP(0x46a0ul);
if(platform_empty_shots(0x48d2u,6u))goto L46c2;
ea=a[6];
tv=cvr16(ea);
a[6]+=2;
VWORD(d[6])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L46a2;
L46a2: /* beq $46bc */
VSTEP(0x46a2ul);
if(fz)goto L46bc;
goto L46a4;
L46a4: /* movem.w (A6), D0-D1 */
VSTEP(0x46a4ul);
ea=a[6];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
goto L46a8;
L46a8: /* sub.w $6356.w, D0 */
VSTEP(0x46a8ul);
ea=0x6356ul;
tv=(((u16)vm_vars[48]<<8)|((u16)vm_vars[49]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L46ac;
L46ac: /* sub.w $6358.w, D1 */
VSTEP(0x46acul);
ea=0x6358ul;
tv=(((u16)vm_vars[50]<<8)|((u16)vm_vars[51]<<0));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L46b0;
L46b0: /* asl.w #1, D6 */
VSTEP(0x46b0ul);
tv=((u16)(1L));
tw=((u16)d[6]);
tr=tw<<1;fx=(u8)((tw>>15)&1);
VWORD(d[6])=(u16)(tr);
goto L46b2;
L46b2: /* clr.l D2 */
VSTEP(0x46b2ul);
d[2]=0;
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L46b4;
L46b4: /* movea.l D2, A0 */
VSTEP(0x46b4ul);
v=((u32)d[2]);
a[0]=v;
goto L46b6;
L46b6: /* movea.w (-$2,A5,D6.w), A0 */
VSTEP(0x46b6ul);
ea=(-2+a[5]+((s16)(d[6])));
v=cvr16(ea);
a[0]=(s16)v;
goto L46ba;
L46ba: /* jsr (A0) */
VSTEP(0x46baul);
a[7]-=4;cvw32(a[7],0x46bcul);
pc=a[0];goto dispatch;
L46bc: /* addq.w #6, A6 */
VSTEP(0x46bcul);
v=((u16)(6L));
w=((u32)a[6]);
r=w+v;
a[6]=r;
goto L46be;
L46be: /* dbra D7, $46a0 */
VSTEP(0x46beul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L46a0;
goto L46c2;
L46c2: /* rts  */
VSTEP(0x46c2ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L46c4: /* movem.w D0-D1, (A6) */
VSTEP(0x46c4ul);
ea=a[6];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L46c8;
L46c8: /* bsr $55e0 */
VSTEP(0x46c8ul);
a[7]-=4;cvw32(a[7],0x46ccul);
goto L55e0;
L46cc: /* cmpi.b #$3, D2 */
VSTEP(0x46ccul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L46d0;
L46d0: /* bcs $46f8 */
VSTEP(0x46d0ul);
if(fc)goto L46f8;
goto L46d2;
L46d2: /* sub.w $69f2.w, D0 */
VSTEP(0x46d2ul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L46d6;
L46d6: /* addq.w #4, D0 */
VSTEP(0x46d6ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L46d8;
L46d8: /* cmpi.w #$9, D0 */
VSTEP(0x46d8ul);
tv=((u16)(9L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46dc;
L46dc: /* bcc $46fe */
VSTEP(0x46dcul);
if(!fc)goto L46fe;
goto L46de;
L46de: /* cmp.w $69f4.w, D1 */
VSTEP(0x46deul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46e2;
L46e2: /* bpl $46fe */
VSTEP(0x46e2ul);
if(!fn)goto L46fe;
goto L46e4;
L46e4: /* cmp.w $6338.w, D1 */
VSTEP(0x46e4ul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L46e8;
L46e8: /* bmi $46fe */
VSTEP(0x46e8ul);
if(fn)goto L46fe;
goto L46ea;
L46ea: /* moveq #$1, D6 */
VSTEP(0x46eaul);
v=((u32)(1L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L46ec;
L46ec: /* bsr $4d0a */
VSTEP(0x46ecul);
a[7]-=4;cvw32(a[7],0x46f0ul);
goto L4d0a;
L46f0: /* moveq #$a, D0 */
VSTEP(0x46f0ul);
v=((u32)(10L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L46f2;
L46f2: /* jsr $48014.l */
VSTEP(0x46f2ul);
a[7]-=4;cvw32(a[7],0x46f8ul);
goto L48014;
L46f8: /* move.w #$4, (-$2,A6) */
VSTEP(0x46f8ul);
tv=((u16)(4L));
ea=(-2+a[6]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L46fe;
L46fe: /* rts  */
VSTEP(0x46feul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4700: /* subq.w #3, D0 */
VSTEP(0x4700ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L4702;
L4702: /* cmpi.w #-$a, D0 */
VSTEP(0x4702ul);
tv=((u16)(-10L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4706;
L4706: /* bmi $4760 */
VSTEP(0x4706ul);
if(fn)goto L4760;
goto L4708;
L4708: /* subq.w #3, D1 */
VSTEP(0x4708ul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L470a;
L470a: /* cmpi.w #$58, D1 */
VSTEP(0x470aul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L470e;
L470e: /* bcs $46c4 */
VSTEP(0x470eul);
if(fc)goto L46c4;
goto L4710;
L4710: /* bra $4760 */
VSTEP(0x4710ul);
goto L4760;
L4712: /* addq.w #3, D0 */
VSTEP(0x4712ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4714;
L4714: /* cmpi.w #$a8, D0 */
VSTEP(0x4714ul);
tv=((u16)(168L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4718;
L4718: /* bpl $4760 */
VSTEP(0x4718ul);
if(!fn)goto L4760;
goto L471a;
L471a: /* subq.w #3, D1 */
VSTEP(0x471aul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L471c;
L471c: /* cmpi.w #$58, D1 */
VSTEP(0x471cul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4720;
L4720: /* bcs $46c4 */
VSTEP(0x4720ul);
if(fc)goto L46c4;
goto L4722;
L4722: /* bra $4760 */
VSTEP(0x4722ul);
goto L4760;
L4724: /* subq.w #3, D0 */
VSTEP(0x4724ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L4726;
L4726: /* cmpi.w #-$a, D0 */
VSTEP(0x4726ul);
tv=((u16)(-10L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L472a;
L472a: /* bmi $4760 */
VSTEP(0x472aul);
if(fn)goto L4760;
goto L472c;
L472c: /* addq.w #3, D1 */
VSTEP(0x472cul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L472e;
L472e: /* cmpi.w #$58, D1 */
VSTEP(0x472eul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4732;
L4732: /* bcs $46c4 */
VSTEP(0x4732ul);
if(fc)goto L46c4;
goto L4734;
L4734: /* bra $4760 */
VSTEP(0x4734ul);
goto L4760;
L4736: /* addq.w #3, D0 */
VSTEP(0x4736ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4738;
L4738: /* cmpi.w #$a8, D0 */
VSTEP(0x4738ul);
tv=((u16)(168L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L473c;
L473c: /* bpl $4760 */
VSTEP(0x473cul);
if(!fn)goto L4760;
goto L473e;
L473e: /* addq.w #3, D1 */
VSTEP(0x473eul);
tv=((u16)(3L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L4740;
L4740: /* cmpi.w #$58, D1 */
VSTEP(0x4740ul);
tv=((u16)(88L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4744;
L4744: /* bcs $46c4 */
VSTEP(0x4744ul);
if(fc)goto L46c4;
goto L4748;
L4748: /* bra $4760 */
VSTEP(0x4748ul);
goto L4760;
L474a: /* subq.w #5, D0 */
VSTEP(0x474aul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L474c;
L474c: /* cmpi.w #-$a, D0 */
VSTEP(0x474cul);
tv=((u16)(-10L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4750;
L4750: /* bpl $46c4 */
VSTEP(0x4750ul);
if(!fn)goto L46c4;
goto L4754;
L4754: /* bra $4760 */
VSTEP(0x4754ul);
goto L4760;
L4756: /* addq.w #5, D0 */
VSTEP(0x4756ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4758;
L4758: /* cmpi.w #$a8, D0 */
VSTEP(0x4758ul);
tv=((u16)(168L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L475c;
L475c: /* bmi $46c4 */
VSTEP(0x475cul);
if(fn)goto L46c4;
goto L4760;
L4760: /* clr.w (-$2,A6) */
VSTEP(0x4760ul);
ea=(-2+a[6]);
cvw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L4764;
L4764: /* rts  */
VSTEP(0x4764ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4766: /* addq.w #4, D0 */
VSTEP(0x4766ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4768;
L4768: /* cmpi.w #$a8, D0 */
VSTEP(0x4768ul);
tv=((u16)(168L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L476c;
L476c: /* bpl $4760 */
VSTEP(0x476cul);
if(!fn)goto L4760;
goto L476e;
L476e: /* bsr $55e0 */
VSTEP(0x476eul);
a[7]-=4;cvw32(a[7],0x4772ul);
goto L55e0;
L4772: /* cmpi.b #$3, D2 */
VSTEP(0x4772ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4776;
L4776: /* movem.w D0-D1, (A6) */
VSTEP(0x4776ul);
ea=a[6];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L477a;
L477a: /* bcc $47bc */
VSTEP(0x477aul);
if(!fc)goto L47bc;
goto L477c;
L477c: /* bcs $4760 */
VSTEP(0x477cul);
if(fc)goto L4760;
goto L477e;
L477e: /* subq.w #4, D0 */
VSTEP(0x477eul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L4780;
L4780: /* cmpi.w #-$a, D0 */
VSTEP(0x4780ul);
tv=((u16)(-10L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4784;
L4784: /* bmi $4760 */
VSTEP(0x4784ul);
if(fn)goto L4760;
goto L4786;
L4786: /* bsr $55e0 */
VSTEP(0x4786ul);
a[7]-=4;cvw32(a[7],0x478aul);
goto L55e0;
L478a: /* cmpi.b #$3, D2 */
VSTEP(0x478aul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L478e;
L478e: /* movem.w D0-D1, (A6) */
VSTEP(0x478eul);
ea=a[6];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L4792;
L4792: /* bcc $47bc */
VSTEP(0x4792ul);
if(!fc)goto L47bc;
goto L4794;
L4794: /* bra $4760 */
VSTEP(0x4794ul);
goto L4760;
L4796: /* move.w $6360.w, D0 */
VSTEP(0x4796ul);
ea=0x6360ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
VWORD(d[0])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L479a;
L479a: /* beq $4760 */
VSTEP(0x479aul);
if(fz)goto L4760;
goto L479c;
L479c: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x479cul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L47a2;
L47a2: /* add.w $6362.w, D0 */
VSTEP(0x47a2ul);
ea=0x6362ul;
tv=(((u16)vm_vars[60]<<8)|((u16)vm_vars[61]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L47a6;
L47a6: /* sub.w $6364.w, D1 */
VSTEP(0x47a6ul);
ea=0x6364ul;
tv=(((u16)vm_vars[62]<<8)|((u16)vm_vars[63]<<0));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L47aa;
L47aa: /* subi.w #$c, D1 */
VSTEP(0x47aaul);
tv=((u16)(12L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L47ae;
L47ae: /* addq.w #5, D0 */
VSTEP(0x47aeul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L47b0;
L47b0: /* tst.w $6336.w */
VSTEP(0x47b0ul);
ea=0x6336ul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
fn=(u8)((tv&0x8000ul)!=0);
goto L47b4;
L47b4: /* bpl $47b8 */
VSTEP(0x47b4ul);
if(!fn)goto L47b8;
goto L47b6;
L47b6: /* subq.w #7, D0 */
VSTEP(0x47b6ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L47b8;
L47b8: /* movem.w D0-D1, (A6) */
VSTEP(0x47b8ul);
ea=a[6];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L47bc;
L47bc: /* lea $3a82.w, A4 */
VSTEP(0x47bcul);
if(platform_projectile_actors(0x39bcu))goto L47ec;goto L47ea;
a[4]=0x3a82ul;
goto L47c0;
L47c0: /* moveq #$9, D6 */
VSTEP(0x47c0ul);
v=((u32)(9L));
d[6]=v;

goto L47c2;
L47c2: /* move.w (A4), D2 */
VSTEP(0x47c2ul);
ea=a[4];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L47c4;
L47c4: /* subq.w #2, D2 */
VSTEP(0x47c4ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L47c6;
L47c6: /* bmi $47e2 */
VSTEP(0x47c6ul);
if(fn)goto L47e2;
goto L47c8;
L47c8: /* move.w ($e,A4), D2 */
VSTEP(0x47c8ul);
ea=(14+a[4]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L47cc;
L47cc: /* sub.w D0, D2 */
VSTEP(0x47ccul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L47ce;
L47ce: /* addq.w #4, D2 */
VSTEP(0x47ceul);
tv=((u16)(4L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L47d0;
L47d0: /* cmpi.w #$8, D2 */
VSTEP(0x47d0ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L47d4;
L47d4: /* bcc $47e2 */
VSTEP(0x47d4ul);
if(!fc)goto L47e2;
goto L47d6;
L47d6: /* cmp.w ($10,A4), D1 */
VSTEP(0x47d6ul);
ea=(16+a[4]);
tv=cvr16(ea);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L47da;
L47da: /* bpl $47e2 */
VSTEP(0x47daul);
if(!fn)goto L47e2;
goto L47dc;
L47dc: /* cmp.w ($12,A4), D1 */
VSTEP(0x47dcul);
ea=(18+a[4]);
tv=cvr16(ea);
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L47e0;
L47e0: /* bpl $47ec */
VSTEP(0x47e0ul);
if(!fn)goto L47ec;
goto L47e2;
L47e2: /* lea (-$16,A4), A4 */
VSTEP(0x47e2ul);
a[4]=(-22+a[4]);
goto L47e6;
L47e6: /* dbra D6, $47c2 */
VSTEP(0x47e6ul);
VWORD(d[6])=(u16)(d[6]-1);
if((u16)d[6]!=65535u)goto L47c2;
goto L47ea;
L47ea: /* rts  */
VSTEP(0x47eaul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L47ec: /* move.w #$1, (A4) */
VSTEP(0x47ecul);
tv=((u16)(1L));
ea=a[4];
cvw16(ea,tv);

goto L47f0;
L47f0: /* move.w #$fffc, ($a,A4) */
VSTEP(0x47f0ul);
tv=((u16)(65532L));
ea=(10+a[4]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L47f6;
L47f6: /* bsr $4760 */
VSTEP(0x47f6ul);
a[7]-=4;cvw32(a[7],0x47faul);
goto L4760;
L47fa: /* moveq #$a, D0 */
VSTEP(0x47faul);
v=((u32)(10L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L47fc;
L47fc: /* jmp $48014.l */
VSTEP(0x47fcul);
goto L48014;
L4802: /* addq.w #2, D0 */
VSTEP(0x4802ul);
tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4804;
L4804: /* move.w ($4,A6), D2 */
VSTEP(0x4804ul);
ea=(4+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4808;
L4808: /* cmpi.w #$28, D2 */
VSTEP(0x4808ul);
tv=((u16)(40L));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L480c;
L480c: /* bpl $4812 */
VSTEP(0x480cul);
if(!fn)goto L4812;
goto L480e;
L480e: /* addq.w #1, ($4,A6) */
VSTEP(0x480eul);
tv=((u16)(1L));
eb=(4+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L4812;
L4812: /* asr.w #2, D2 */
VSTEP(0x4812ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((s16)tw)>>2;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4814;
L4814: /* bpl $4818 */
VSTEP(0x4814ul);
if(!fn)goto L4818;
goto L4816;
L4816: /* addq.w #1, D2 */
VSTEP(0x4816ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4818;
L4818: /* add.w D2, D1 */
VSTEP(0x4818ul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L481a;
L481a: /* cmpi.w #$60, D1 */
VSTEP(0x481aul);
tv=((u16)(96L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L481e;
L481e: /* bpl $4760 */
VSTEP(0x481eul);
if(!fn)goto L4760;
goto L4822;
L4822: /* movem.w D0-D1, (A6) */
VSTEP(0x4822ul);
ea=a[6];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L4826;
L4826: /* bsr $55e0 */
VSTEP(0x4826ul);
a[7]-=4;cvw32(a[7],0x482aul);
goto L55e0;
L482a: /* cmpi.b #$3, D2 */
VSTEP(0x482aul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L482e;
L482e: /* bcs $4852 */
VSTEP(0x482eul);
if(fc)goto L4852;
goto L4830;
L4830: /* sub.w $69f2.w, D0 */
VSTEP(0x4830ul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4834;
L4834: /* addq.w #3, D0 */
VSTEP(0x4834ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4836;
L4836: /* cmpi.w #$7, D0 */
VSTEP(0x4836ul);
tv=((u16)(7L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L483a;
L483a: /* bcc $485e */
VSTEP(0x483aul);
if(!fc)goto L485e;
goto L483c;
L483c: /* cmp.w $69f4.w, D1 */
VSTEP(0x483cul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4840;
L4840: /* bpl $485e */
VSTEP(0x4840ul);
if(!fn)goto L485e;
goto L4842;
L4842: /* cmp.w $6338.w, D1 */
VSTEP(0x4842ul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4846;
L4846: /* bmi $485e */
VSTEP(0x4846ul);
if(fn)goto L485e;
goto L4848;
L4848: /* moveq #$6, D6 */
VSTEP(0x4848ul);
v=((u32)(6L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L484a;
L484a: /* bsr $4d0a */
VSTEP(0x484aul);
a[7]-=4;cvw32(a[7],0x484eul);
goto L4d0a;
L484e: /* movem.w (A6), D0-D1 */
VSTEP(0x484eul);
ea=a[6];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
goto L4852;
L4852: /* move.w #$e, (-$2,A6) */
VSTEP(0x4852ul);
tv=((u16)(14L));
ea=(-2+a[6]);
cvw16(ea,tv);

goto L4858;
L4858: /* moveq #$d, D2 */
VSTEP(0x4858ul);
v=((u32)(13L));
d[2]=v;

goto L485a;
L485a: /* bra $44f4 */
VSTEP(0x485aul);
goto L44f4;
L485e: /* rts  */
VSTEP(0x485eul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4860: /* subq.w #2, D0 */
VSTEP(0x4860ul);
tv=((u16)(2L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L4862;
L4862: /* move.w ($4,A6), D2 */
VSTEP(0x4862ul);
ea=(4+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4866;
L4866: /* cmpi.w #$28, D2 */
VSTEP(0x4866ul);
tv=((u16)(40L));
tw=((u16)d[2]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L486a;
L486a: /* bpl $4870 */
VSTEP(0x486aul);
if(!fn)goto L4870;
goto L486c;
L486c: /* addq.w #1, ($4,A6) */
VSTEP(0x486cul);
tv=((u16)(1L));
eb=(4+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L4870;
L4870: /* asr.w #2, D2 */
VSTEP(0x4870ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((s16)tw)>>2;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4872;
L4872: /* bpl $4876 */
VSTEP(0x4872ul);
if(!fn)goto L4876;
goto L4874;
L4874: /* addq.w #1, D2 */
VSTEP(0x4874ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4876;
L4876: /* add.w D2, D1 */
VSTEP(0x4876ul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L4878;
L4878: /* cmpi.w #$60, D1 */
VSTEP(0x4878ul);
tv=((u16)(96L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L487c;
L487c: /* bpl $4760 */
VSTEP(0x487cul);
if(!fn)goto L4760;
goto L4880;
L4880: /* bra $4822 */
VSTEP(0x4880ul);
goto L4822;
L4882: /* movem.w D0-D1, (A6) */
VSTEP(0x4882ul);
ea=a[6];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L4886;
L4886: /* btst #$0, $6375.w */
VSTEP(0x4886ul);
v=((u16)(0L));
eb=0x6375ul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L488c;
L488c: /* bne $48a2 */
VSTEP(0x488cul);
if(!fz)goto L48a2;
goto L488e;
L488e: /* move.w (-$2,A6), D2 */
VSTEP(0x488eul);
ea=(-2+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4892;
L4892: /* addq.w #1, D2 */
VSTEP(0x4892ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4894;
L4894: /* cmpi.w #$18, D2 */
VSTEP(0x4894ul);
tv=((u16)(24L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4898;
L4898: /* bne $489e */
VSTEP(0x4898ul);
if(!fz)goto L489e;
goto L489c;
L489c: /* clr.w D2 */
VSTEP(0x489cul);
VWORD(d[2])=(u16)(0);

goto L489e;
L489e: /* move.w D2, (-$2,A6) */
VSTEP(0x489eul);
tv=((u16)d[2]);
ea=(-2+a[6]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L48a2;
L48a2: /* rts  */
VSTEP(0x48a2ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4974: /* movem.w $69f4.w, D1-D2 */
VSTEP(0x4974ul);
ea=0x69f4ul;
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1744u));
goto L497a;
L497a: /* move.w D1, D0 */
VSTEP(0x497aul);
tv=((u16)d[1]);
VWORD(d[0])=(u16)(tv);

goto L497c;
L497c: /* sub.w D2, D0 */
VSTEP(0x497cul);
tv=((u16)d[2]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L497e;
L497e: /* move.w $6358.w, $4972.w */
VSTEP(0x497eul);
ea=0x6358ul;
tv=(((u16)vm_vars[50]<<8)|((u16)vm_vars[51]<<0));
ea=0x4972ul;
cvw16(ea,tv);

goto L4984;
L4984: /* move.w D0, $6358.w */
VSTEP(0x4984ul);
tv=((u16)d[0]);
vm_vars[50]=(u8)((u32)(tv)>>8);
vm_vars[51]=(u8)((u32)(tv)>>0);
fz=(u8)((tv&0xfffful)==0);
goto L4988;
L4988: /* beq $4a2a */
VSTEP(0x4988ul);
if(fz)goto L4a2a;
goto L498c;
L498c: /* tst.w $6342.w */
VSTEP(0x498cul);
ea=0x6342ul;
tv=(((u16)vm_vars[28]<<8)|((u16)vm_vars[29]<<0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L4990;
L4990: /* bmi $49aa */
VSTEP(0x4990ul);
if(fn)goto L49aa;
goto L4992;
L4992: /* beq $49be */
VSTEP(0x4992ul);
if(fz)goto L49be;
goto L4994;
L4994: /* cmpi.w #$4, D0 */
VSTEP(0x4994ul);
tv=((u16)(4L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L4998;
L4998: /* bcs $49be */
VSTEP(0x4998ul);
if(fc)goto L49be;
goto L499a;
L499a: /* cmpi.w #-$3, D0 */
VSTEP(0x499aul);
tv=((u16)(-3L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L499e;
L499e: /* bcc $49be */
VSTEP(0x499eul);
if(!fc)goto L49be;
goto L49a0;
L49a0: /* bpl $49a6 */
VSTEP(0x49a0ul);
if(!fn)goto L49a6;
goto L49a2;
L49a2: /* moveq #-$2, D0 */
VSTEP(0x49a2ul);
v=((u32)(-2L));
d[0]=v;

goto L49a4;
L49a4: /* bra $49be */
VSTEP(0x49a4ul);
goto L49be;
L49a6: /* moveq #$2, D0 */
VSTEP(0x49a6ul);
v=((u32)(2L));
d[0]=v;

goto L49a8;
L49a8: /* bra $49be */
VSTEP(0x49a8ul);
goto L49be;
L49aa: /* cmpi.w #$8, D0 */
VSTEP(0x49aaul);
tv=((u16)(8L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L49ae;
L49ae: /* bcs $49be */
VSTEP(0x49aeul);
if(fc)goto L49be;
goto L49b0;
L49b0: /* cmpi.w #-$3, D0 */
VSTEP(0x49b0ul);
tv=((u16)(-3L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L49b4;
L49b4: /* bcc $49be */
VSTEP(0x49b4ul);
if(!fc)goto L49be;
goto L49b6;
L49b6: /* bmi $49bc */
VSTEP(0x49b6ul);
if(fn)goto L49bc;
goto L49b8;
L49b8: /* moveq #$7, D0 */
VSTEP(0x49b8ul);
v=((u32)(7L));
d[0]=v;

goto L49ba;
L49ba: /* bra $49be */
VSTEP(0x49baul);
goto L49be;
L49bc: /* moveq #-$3, D0 */
VSTEP(0x49bcul);
v=((u32)(-3L));
d[0]=v;

goto L49be;
L49be: /* move.w $69ee.w, D1 */
VSTEP(0x49beul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
VWORD(d[1])=(u16)(tv);

goto L49c2;
L49c2: /* move.w D1, D3 */
VSTEP(0x49c2ul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L49c4;
L49c4: /* add.w D0, D1 */
VSTEP(0x49c4ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L49c6;
L49c6: /* cmpi.w #$601, D1 */
VSTEP(0x49c6ul);
tv=((u16)(1537L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L49ca;
L49ca: /* bcs $49de */
VSTEP(0x49caul);
if(fc)goto L49de;
goto L49cc;
L49cc: /* bmi $49da */
VSTEP(0x49ccul);
if(fn)goto L49da;
goto L49ce;
L49ce: /* move.w #$600, D2 */
VSTEP(0x49ceul);
tv=((u16)(1536L));
VWORD(d[2])=(u16)(tv);

goto L49d2;
L49d2: /* sub.w D2, D1 */
VSTEP(0x49d2ul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L49d4;
L49d4: /* sub.w D1, D0 */
VSTEP(0x49d4ul);
tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L49d6;
L49d6: /* move.w D2, D1 */
VSTEP(0x49d6ul);
tv=((u16)d[2]);
VWORD(d[1])=(u16)(tv);

goto L49d8;
L49d8: /* bra $49de */
VSTEP(0x49d8ul);
goto L49de;
L49da: /* sub.w D1, D0 */
VSTEP(0x49daul);
tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L49dc;
L49dc: /* clr.w D1 */
VSTEP(0x49dcul);
VWORD(d[1])=(u16)(0);

goto L49de;
L49de: /* sub.w D0, $69f4.w */
VSTEP(0x49deul);
tv=((u16)d[0]);
eb=0x69f4ul;
tw=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tr=tw-tv;
vm_vars[1742]=(u8)((u32)(tr)>>8);
vm_vars[1743]=(u8)((u32)(tr)>>0);
goto L49e2;
L49e2: /* move.w D1, $69ee.w */
VSTEP(0x49e2ul);
tv=((u16)d[1]);
vm_vars[1736]=(u8)((u32)(tv)>>8);
vm_vars[1737]=(u8)((u32)(tv)>>0);

goto L49e6;
L49e6: /* sub.w D3, D1 */
VSTEP(0x49e6ul);
tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L49e8;
L49e8: /* move.w D1, $6358.w */
VSTEP(0x49e8ul);
tv=((u16)d[1]);
vm_vars[50]=(u8)((u32)(tv)>>8);
vm_vars[51]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);
goto L49ec;
L49ec: /* beq $4a2a */
VSTEP(0x49ecul);
if(fz)goto L4a2a;
goto L49ee;
L49ee: /* bmi $4a12 */
VSTEP(0x49eeul);
if(fn)goto L4a12;
goto L49f0;
L49f0: /* addi.w #$57, D3 */
VSTEP(0x49f0ul);
tv=((u16)(87L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L49f4;
L49f4: /* move.w $635a.w, D2 */
VSTEP(0x49f4ul);
ea=0x635aul;
tv=(((u16)vm_vars[52]<<8)|((u16)vm_vars[53]<<0));
VWORD(d[2])=(u16)(tv);

goto L49f8;
L49f8: /* move.w D1, D4 */
VSTEP(0x49f8ul);
tv=((u16)d[1]);
VWORD(d[4])=(u16)(tv);

goto L49fa;
L49fa: /* add.w D2, D4 */
VSTEP(0x49faul);
tv=((u16)d[2]);
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L49fc;
L49fc: /* cmpi.w #$57, D4 */
VSTEP(0x49fcul);
tv=((u16)(87L));
tw=((u16)d[4]);
fc=(u8)((u16)tw<(u16)tv);
goto L4a00;
L4a00: /* bcs $4a06 */
VSTEP(0x4a00ul);
if(fc)goto L4a06;
goto L4a02;
L4a02: /* subi.w #$57, D4 */
VSTEP(0x4a02ul);
tv=((u16)(87L));
tw=((u16)d[4]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[4])=(u16)(tr);
goto L4a06;
L4a06: /* move.w D4, $635a.w */
VSTEP(0x4a06ul);
tv=((u16)d[4]);
vm_vars[52]=(u8)((u32)(tv)>>8);
vm_vars[53]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4a0a;
L4a0a: /* bsr $4a9c */
VSTEP(0x4a0aul);
a[7]-=4;cvw32(a[7],0x4a0eul);
goto L4a9c;
L4a0e: /* bra $4a2a */
VSTEP(0x4a0eul);
goto L4a2a;
L4a12: /* move.w $635a.w, D2 */
VSTEP(0x4a12ul);
ea=0x635aul;
tv=(((u16)vm_vars[52]<<8)|((u16)vm_vars[53]<<0));
VWORD(d[2])=(u16)(tv);

goto L4a16;
L4a16: /* add.w D1, D2 */
VSTEP(0x4a16ul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4a18;
L4a18: /* bpl $4a1e */
VSTEP(0x4a18ul);
if(!fn)goto L4a1e;
goto L4a1a;
L4a1a: /* addi.w #$57, D2 */
VSTEP(0x4a1aul);
tv=((u16)(87L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4a1e;
L4a1e: /* move.w D2, $635a.w */
VSTEP(0x4a1eul);
tv=((u16)d[2]);
vm_vars[52]=(u8)((u32)(tv)>>8);
vm_vars[53]=(u8)((u32)(tv)>>0);

goto L4a22;
L4a22: /* add.w D1, D3 */
VSTEP(0x4a22ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L4a24;
L4a24: /* neg.w D1 */
VSTEP(0x4a24ul);
tv=((u16)d[1]);
tr=0-tv;fc=(u8)(tv>0);fx=(u8)(tv>0);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((0^tv)&(0^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4a26;
L4a26: /* bsr $4a9c */
VSTEP(0x4a26ul);
a[7]-=4;cvw32(a[7],0x4a2aul);
goto L4a9c;
L4a2a: /* move.w $69f2.w, D0 */
VSTEP(0x4a2aul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
VWORD(d[0])=(u16)(tv);

goto L4a2e;
L4a2e: /* sub.w $69f8.w, D0 */
VSTEP(0x4a2eul);
ea=0x69f8ul;
tv=(((u16)vm_vars[1746]<<8)|((u16)vm_vars[1747]<<0));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L4a32;
L4a32: /* move.w D0, $6356.w */
VSTEP(0x4a32ul);
tv=((u16)d[0]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4a36;
L4a36: /* beq $4a9a */
VSTEP(0x4a36ul);
if(fz)goto L4a9a;
goto L4a3a;
L4a3a: /* move.w $69ec.w, D1 */
VSTEP(0x4a3aul);
ea=0x69ecul;
tv=(((u16)vm_vars[1734]<<8)|((u16)vm_vars[1735]<<0));
VWORD(d[1])=(u16)(tv);

goto L4a3e;
L4a3e: /* move.w D1, D2 */
VSTEP(0x4a3eul);
tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L4a40;
L4a40: /* add.w D0, D1 */
VSTEP(0x4a40ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw+tv;fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L4a42;
L4a42: /* bpl $4a4a */
VSTEP(0x4a42ul);
if(!fn)goto L4a4a;
goto L4a44;
L4a44: /* move.w D1, D0 */
VSTEP(0x4a44ul);
tv=((u16)d[1]);
VWORD(d[0])=(u16)(tv);

goto L4a46;
L4a46: /* clr.w D1 */
VSTEP(0x4a46ul);
VWORD(d[1])=(u16)(0);

goto L4a48;
L4a48: /* bra $4a5a */
VSTEP(0x4a48ul);
goto L4a5a;
L4a4a: /* clr.w D0 */
VSTEP(0x4a4aul);
VWORD(d[0])=(u16)(0);

goto L4a4c;
L4a4c: /* cmpi.w #$230, D1 */
VSTEP(0x4a4cul);
tv=((u16)(560L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);
goto L4a50;
L4a50: /* bls $4a5a */
VSTEP(0x4a50ul);
if((fc||fz))goto L4a5a;
goto L4a52;
L4a52: /* move.w #$230, D0 */
VSTEP(0x4a52ul);
tv=((u16)(560L));
VWORD(d[0])=(u16)(tv);

goto L4a56;
L4a56: /* sub.w D0, D1 */
VSTEP(0x4a56ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4a58;
L4a58: /* exg D1, D0 */
VSTEP(0x4a58ul);
r=d[1];d[1]=d[0];d[0]=r;
goto L4a5a;
L4a5a: /* add.w $69f8.w, D0 */
VSTEP(0x4a5aul);
ea=0x69f8ul;
tv=(((u16)vm_vars[1746]<<8)|((u16)vm_vars[1747]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4a5e;
L4a5e: /* move.w D0, $69f2.w */
VSTEP(0x4a5eul);
tv=((u16)d[0]);
vm_vars[1740]=(u8)((u32)(tv)>>8);
vm_vars[1741]=(u8)((u32)(tv)>>0);

goto L4a62;
L4a62: /* move.w D1, $69ec.w */
VSTEP(0x4a62ul);
tv=((u16)d[1]);
vm_vars[1734]=(u8)((u32)(tv)>>8);
vm_vars[1735]=(u8)((u32)(tv)>>0);

goto L4a66;
L4a66: /* move.w D1, D3 */
VSTEP(0x4a66ul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L4a68;
L4a68: /* sub.w D2, D3 */
VSTEP(0x4a68ul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L4a6a;
L4a6a: /* move.w D3, $6356.w */
VSTEP(0x4a6aul);
tv=((u16)d[3]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4a6e;
L4a6e: /* beq $4a9a */
VSTEP(0x4a6eul);
if(fz)goto L4a9a;
goto L4a70;
L4a70: /* eor.w D1, D2 */
VSTEP(0x4a70ul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw^tv;
fn=(u8)((tr&0x8000ul)!=0);fv=0;fc=0;
VWORD(d[2])=(u16)(tr);
goto L4a72;
L4a72: /* btst #$3, D2 */
VSTEP(0x4a72ul);
v=((u16)(3L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4a76;
L4a76: /* beq $4a9a */
VSTEP(0x4a76ul);
if(fz)goto L4a9a;
goto L4a78;
L4a78: /* movea.l $6366.w, A4 */
VSTEP(0x4a78ul);
ea=0x6366ul;
v=(((u32)vm_vars[64]<<24)|((u32)vm_vars[65]<<16)|((u32)vm_vars[66]<<8)|((u32)vm_vars[67]<<0));
a[4]=v;
goto L4a7c;
L4a7c: /* tst.w D3 */
VSTEP(0x4a7cul);
tv=((u16)d[3]);
fn=(u8)((tv&0x8000ul)!=0);
goto L4a7e;
L4a7e: /* bmi $4a90 */
VSTEP(0x4a7eul);
if(fn)goto L4a90;
goto L4a80;
L4a80: /* addi.w #$a0, D1 */
VSTEP(0x4a80ul);
tv=((u16)(160L));
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L4a84;
L4a84: /* addq.w #2, A4 */
VSTEP(0x4a84ul);
v=((u16)(2L));
w=((u32)a[4]);
r=w+v;
a[4]=r;
goto L4a86;
L4a86: /* move.l A4, $6366.w */
VSTEP(0x4a86ul);
v=((u32)a[4]);
vm_vars[64]=(u8)((u32)(v)>>24);
vm_vars[65]=(u8)((u32)(v)>>16);
vm_vars[66]=(u8)((u32)(v)>>8);
vm_vars[67]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4a8a;
L4a8a: /* lea ($28,A4), A4 */
VSTEP(0x4a8aul);
a[4]=(40+a[4]);
goto L4a8e;
L4a8e: /* bra $4a96 */
VSTEP(0x4a8eul);
goto L4a96;
L4a90: /* subq.w #2, A4 */
VSTEP(0x4a90ul);
v=((u16)(2L));
w=((u32)a[4]);
r=w-v;
a[4]=r;
goto L4a92;
L4a92: /* move.l A4, $6366.w */
VSTEP(0x4a92ul);
v=((u32)a[4]);
vm_vars[64]=(u8)((u32)(v)>>24);
vm_vars[65]=(u8)((u32)(v)>>16);
vm_vars[66]=(u8)((u32)(v)>>8);
vm_vars[67]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4a96;
L4a96: /* bsr $4b14 */
VSTEP(0x4a96ul);
a[7]-=4;cvw32(a[7],0x4a9aul);
goto L4b14;
L4a9a: /* rts  */
VSTEP(0x4a9aul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4c7c: /* clr.w D2 */
VSTEP(0x4c7cul);
VWORD(d[2])=(u16)(0);

goto L4c7e;
L4c7e: /* move.b $6350.w, D2 */
VSTEP(0x4c7eul);
ea=0x6350ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[2])=(u8)(tv);

goto L4c82;
L4c82: /* asl.w #2, D2 */
VSTEP(0x4c82ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw<<2;fc=(u8)((tw>>14)&1);fx=(u8)((tw>>14)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((((tw<<2)^tw)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4c84;
L4c84: /* movea.l ($4,PC,D2.w), A0 */
VSTEP(0x4c84ul);
ea=(4+0x4c86ul+((s16)(d[2])));
v=cvr32(ea);
a[0]=v;
goto L4c88;
L4c88: /* jmp (A0) */
VSTEP(0x4c88ul);
pc=a[0];goto dispatch;
L4d0a: /* tst.b $7c874.l */
VSTEP(0x4d0aul);
ea=0x7c874ul;
tv=cvr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4d10;
L4d10: /* bne $4d74 */
VSTEP(0x4d10ul);
if(!fz)goto L4d74;
goto L4d12;
L4d12: /* movem.l D0-D7/A5-A6, -(A7) */
VSTEP(0x4d12ul);
a[7]-=4;
cvw32(a[7],a[6]);
a[7]-=4;
cvw32(a[7],a[5]);
a[7]-=4;
cvw32(a[7],d[7]);
a[7]-=4;
cvw32(a[7],d[6]);
a[7]-=4;
cvw32(a[7],d[5]);
a[7]-=4;
cvw32(a[7],d[4]);
a[7]-=4;
cvw32(a[7],d[3]);
a[7]-=4;
cvw32(a[7],d[2]);
a[7]-=4;
cvw32(a[7],d[1]);
a[7]-=4;
cvw32(a[7],d[0]);
goto L4d16;
L4d16: /* move.w D6, D0 */
VSTEP(0x4d16ul);
tv=((u16)d[6]);
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d18;
L4d18: /* jsr $7c870.l */
VSTEP(0x4d18ul);
a[7]-=4;cvw32(a[7],0x4d1eul);
goto L7c870;
L4d1e: /* movem.l (A7)+, D0-D7/A5-A6 */
VSTEP(0x4d1eul);
ea=a[7];
d[0]=cvr32(ea+0);
d[1]=cvr32(ea+4);
d[2]=cvr32(ea+8);
d[3]=cvr32(ea+12);
d[4]=cvr32(ea+16);
d[5]=cvr32(ea+20);
d[6]=cvr32(ea+24);
d[7]=cvr32(ea+28);
a[5]=cvr32(ea+32);
a[6]=cvr32(ea+36);
a[7]+=40;
goto L4d22;
L4d22: /* move.w $3c7c.w, D2 */
VSTEP(0x4d22ul);
ea=0x3c7cul;
tv=vm_player_state;
VWORD(d[2])=(u16)(tv);

goto L4d26;
L4d26: /* cmpi.w #$54ba, D2 */
VSTEP(0x4d26ul);
tv=((u16)(21690L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4d2a;
L4d2a: /* beq $4d74 */
VSTEP(0x4d2aul);
if(fz)goto L4d74;
goto L4d2c;
L4d2c: /* move.w #$4e78, D3 */
VSTEP(0x4d2cul);
tv=((u16)(20088L));
VWORD(d[3])=(u16)(tv);

goto L4d30;
L4d30: /* cmp.w D3, D2 */
VSTEP(0x4d30ul);
tv=((u16)d[3]);
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4d32;
L4d32: /* beq $4d5a */
VSTEP(0x4d32ul);
if(fz)goto L4d5a;
goto L4d34;
L4d34: /* cmpi.w #$4ea2, D2 */
VSTEP(0x4d34ul);
tv=((u16)(20130L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4d38;
L4d38: /* beq $4d5a */
VSTEP(0x4d38ul);
if(fz)goto L4d5a;
goto L4d3a;
L4d3a: /* cmpi.w #$5096, D2 */
VSTEP(0x4d3aul);
tv=((u16)(20630L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4d3e;
L4d3e: /* beq $4d76 */
VSTEP(0x4d3eul);
if(fz)goto L4d76;
goto L4d40;
L4d40: /* move.w #$4d86, D3 */
VSTEP(0x4d40ul);
tv=((u16)(19846L));
VWORD(d[3])=(u16)(tv);

goto L4d44;
L4d44: /* cmpi.w #$532e, D2 */
VSTEP(0x4d44ul);
tv=((u16)(21294L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L4d48;
L4d48: /* beq $4d5a */
VSTEP(0x4d48ul);
if(fz)goto L4d5a;
goto L4d4a;
L4d4a: /* cmp.w D2, D3 */
VSTEP(0x4d4aul);
tv=((u16)d[2]);
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L4d4c;
L4d4c: /* beq $4d5a */
VSTEP(0x4d4cul);
if(fz)goto L4d5a;
goto L4d4e;
L4d4e: /* lea $548f.w, A0 */
VSTEP(0x4d4eul);
a[0]=0x548ful;
goto L4d52;
L4d52: /* bsr $5470 */
VSTEP(0x4d52ul);
a[7]-=4;cvw32(a[7],0x4d56ul);
goto L5470;
L4d56: /* move.w #$4d94, D3 */
VSTEP(0x4d56ul);
tv=((u16)(19860L));
VWORD(d[3])=(u16)(tv);

goto L4d5a;
L4d5a: /* move.w D3, $3c7c.w */
VSTEP(0x4d5aul);
tv=((u16)d[3]);
vm_player_state=(u16)(tv);

goto L4d5e;
L4d5e: /* move.w $634e.w, D2 */
VSTEP(0x4d5eul);
ea=0x634eul;
tv=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
VWORD(d[2])=(u16)(tv);

goto L4d62;
L4d62: /* add.w D6, D6 */
VSTEP(0x4d62ul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;
VWORD(d[6])=(u16)(tr);
goto L4d64;
L4d64: /* add.w D6, D6 */
VSTEP(0x4d64ul);
tv=((u16)d[6]);
tw=((u16)d[6]);
tr=tw+tv;
VWORD(d[6])=(u16)(tr);
goto L4d66;
L4d66: /* add.w D6, D2 */
VSTEP(0x4d66ul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4d68;
L4d68: /* cmpi.w #$c, D2 */
VSTEP(0x4d68ul);
tv=((u16)(12L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4d6c;
L4d6c: /* bcs $4d70 */
VSTEP(0x4d6cul);
if(fc)goto L4d70;
goto L4d6e;
L4d6e: /* moveq #$c, D2 */
VSTEP(0x4d6eul);
v=((u32)(12L));
d[2]=v;

goto L4d70;
L4d70: /* move.w D2, $634e.w */
VSTEP(0x4d70ul);
tv=((u16)d[2]);
vm_vars[40]=(u8)((u32)(tv)>>8);
vm_vars[41]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d74;
L4d74: /* rts  */
VSTEP(0x4d74ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4d76: /* move.w $633a.w, D2 */
VSTEP(0x4d76ul);
ea=0x633aul;
tv=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
VWORD(d[2])=(u16)(tv);

goto L4d7a;
L4d7a: /* add.w D6, D2 */
VSTEP(0x4d7aul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4d7c;
L4d7c: /* add.w D6, D2 */
VSTEP(0x4d7cul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4d7e;
L4d7e: /* add.w D6, D2 */
VSTEP(0x4d7eul);
tv=((u16)d[6]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L4d80;
L4d80: /* move.w D2, $633a.w */
VSTEP(0x4d80ul);
tv=((u16)d[2]);
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d84;
L4d84: /* rts  */
VSTEP(0x4d84ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4d86: /* subq.w #1, $634e.w */
VSTEP(0x4d86ul);
tv=((u16)(1L));
eb=0x634eul;
tw=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[40]=(u8)((u32)(tr)>>8);
vm_vars[41]=(u8)((u32)(tr)>>0);
goto L4d8a;
L4d8a: /* bne $4d74 */
VSTEP(0x4d8aul);
if(!fz)goto L4d74;
goto L4d8c;
L4d8c: /* move.w #$532e, $3c7c.w */
VSTEP(0x4d8cul);
tv=((u16)(21294L));
vm_player_state=(u16)(tv);

goto L4d92;
L4d92: /* bra $4db8 */
VSTEP(0x4d92ul);
goto L4db8;
L4d94: /* tst.w $6360.w */
VSTEP(0x4d94ul);
ea=0x6360ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4d98;
L4d98: /* beq $4d9e */
VSTEP(0x4d98ul);
if(fz)goto L4d9e;
goto L4d9a;
L4d9a: /* bsr $51ee */
VSTEP(0x4d9aul);
a[7]-=4;cvw32(a[7],0x4d9eul);
goto L51ee;
L4d9e: /* subq.w #1, $634e.w */
VSTEP(0x4d9eul);
tv=((u16)(1L));
eb=0x634eul;
tw=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[40]=(u8)((u32)(tr)>>8);
vm_vars[41]=(u8)((u32)(tr)>>0);
goto L4da2;
L4da2: /* bne $4d74 */
VSTEP(0x4da2ul);
if(!fz)goto L4d74;
goto L4da4;
L4da4: /* move.w #$4c7c, $3c7c.w */
VSTEP(0x4da4ul);
tv=((u16)(19580L));
vm_player_state=(u16)(tv);

goto L4daa;
L4daa: /* tst.w $6360.w */
VSTEP(0x4daaul);
ea=0x6360ul;
tv=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4dae;
L4dae: /* beq $4db4 */
VSTEP(0x4daeul);
if(fz)goto L4db4;
goto L4db0;
L4db0: /* bsr $51e6 */
VSTEP(0x4db0ul);
a[7]-=4;cvw32(a[7],0x4db4ul);
goto L51e6;
L4db4: /* bsr $5468 */
VSTEP(0x4db4ul);
a[7]-=4;cvw32(a[7],0x4db8ul);
goto L5468;
L4db8: /* tst.b $7c874.l */
VSTEP(0x4db8ul);
ea=0x7c874ul;
tv=cvr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4dbe;
L4dbe: /* beq $4d74 */
VSTEP(0x4dbeul);
if(fz)goto L4d74;
goto L4dc0;
L4dc0: /* jsr $48004.l */
VSTEP(0x4dc0ul);
a[7]-=4;cvw32(a[7],0x4dc6ul);
goto L48004;
L4dc6: /* clr.w $6360.w */
VSTEP(0x4dc6ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L4dca;
L4dca: /* moveq #$3, D0 */
VSTEP(0x4dcaul);
v=((u32)(3L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4dcc;
L4dcc: /* jsr $48010.l */
VSTEP(0x4dccul);
a[7]-=4;cvw32(a[7],0x4dd2ul);
goto L48010;
L4dd2: /* move.w #$4de0, $3c7c.w */
VSTEP(0x4dd2ul);
tv=((u16)(19936L));
vm_player_state=(u16)(tv);

goto L4dd8;
L4dd8: /* move.w #$6424, $636e.w */
VSTEP(0x4dd8ul);
tv=((u16)(25636L));
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4dde;
L4dde: /* rts  */
VSTEP(0x4ddeul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4de0: /* movea.w $636e.w, A0 */
VSTEP(0x4de0ul);
ea=0x636eul;
v=(((u16)vm_vars[72]<<8)|((u16)vm_vars[73]<<0));
a[0]=(s16)v;
goto L4de4;
L4de4: /* bsr $5470 */
VSTEP(0x4de4ul);
a[7]-=4;cvw32(a[7],0x4de8ul);
goto L5470;
L4de8: /* move.w A0, $636e.w */
VSTEP(0x4de8ul);
tv=((u16)a[0]);
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L4dec;
L4dec: /* tst.b (A0) */
VSTEP(0x4decul);
ea=a[0];
tv=cvr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L4dee;
L4dee: /* bne $4d74 */
VSTEP(0x4deeul);
if(!fz)goto L4d74;
goto L4df0;
L4e78: /* moveq #$10, D3 */
VSTEP(0x4e78ul);
v=((u32)(16L));
d[3]=v;

goto L4e7a;
L4e7a: /* tst.b $7c874.l */
VSTEP(0x4e7aul);
ea=0x7c874ul;
tv=cvr8(ea);
fz=(u8)((tv&0xfful)==0);
goto L4e80;
L4e80: /* bne $4e9e */
VSTEP(0x4e80ul);
if(!fz)goto L4e9e;
goto L4e82;
L4e82: /* lea $6360.w, A0 */
VSTEP(0x4e82ul);
a[0]=0x6360ul;
goto L4e86;
L4e86: /* move.w (A0), D2 */
VSTEP(0x4e86ul);
ea=a[0];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L4e88;
L4e88: /* cmpi.w #$50, D2 */
VSTEP(0x4e88ul);
tv=((u16)(80L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4e8c;
L4e8c: /* bcc $4e9e */
VSTEP(0x4e8cul);
if(!fc)goto L4e9e;
goto L4e8e;
L4e8e: /* addq.w #1, (A0) */
VSTEP(0x4e8eul);
tv=((u16)(1L));
eb=a[0];
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L4e90;
L4e90: /* clr.w D3 */
VSTEP(0x4e90ul);
VWORD(d[3])=(u16)(0);

goto L4e92;
L4e92: /* subq.w #1, $634e.w */
VSTEP(0x4e92ul);
tv=((u16)(1L));
eb=0x634eul;
tw=(((u16)vm_vars[40]<<8)|((u16)vm_vars[41]<<0));
tr=tw-tv;fz=(u8)((tr&0xfffful)==0);
vm_vars[40]=(u8)((u32)(tr)>>8);
vm_vars[41]=(u8)((u32)(tr)>>0);
goto L4e96;
L4e96: /* bne $4e9e */
VSTEP(0x4e96ul);
if(!fz)goto L4e9e;
goto L4e98;
L4e98: /* move.w #$4ea2, $3c7c.w */
VSTEP(0x4e98ul);
tv=((u16)(20130L));
vm_player_state=(u16)(tv);

goto L4e9e;
L4e9e: /* move.b D3, $6350.w */
VSTEP(0x4e9eul);
tv=((u8)d[3]);
vm_vars[42]=(u8)((u32)(tv)>>0);

goto L4ea2;
L4ea2: /* lea $6360.w, A0 */
VSTEP(0x4ea2ul);
a[0]=0x6360ul;
goto L4ea6;
L4ea6: /* move.w (A0), D5 */
VSTEP(0x4ea6ul);
ea=a[0];
tv=cvr16(ea);
VWORD(d[5])=(u16)(tv);

goto L4ea8;
L4ea8: /* move.b $6350.w, D4 */
VSTEP(0x4ea8ul);
ea=0x6350ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[4])=(u8)(tv);

goto L4eac;
L4eac: /* btst #$3, D4 */
VSTEP(0x4eacul);
v=((u16)(3L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4eb0;
L4eb0: /* beq $4ee6 */
VSTEP(0x4eb0ul);
if(fz)goto L4ee6;
goto L4eb2;
L4eb2: /* move.w #$48, $69f6.w */
VSTEP(0x4eb2ul);
tv=((u16)(72L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L4eb8;
L4eb8: /* subq.w #1, D5 */
VSTEP(0x4eb8ul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
VWORD(d[5])=(u16)(tr);
goto L4eba;
L4eba: /* bhi $4ee4 */
VSTEP(0x4ebaul);
if((!fc&&!fz))goto L4ee4;
goto L4ebc;
L4ebc: /* clr.w (A0) */
VSTEP(0x4ebcul);
ea=a[0];
cvw16(ea,0);

goto L4ebe;
L4ebe: /* move.w #$5096, $3c7c.w */
VSTEP(0x4ebeul);
tv=((u16)(20630L));
vm_player_state=(u16)(tv);

goto L4ec4;
L4ec4: /* move.w #$5, $633a.w */
VSTEP(0x4ec4ul);
tv=((u16)(5L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L4eca;
L4eca: /* move.w #$646e, $636e.w */
VSTEP(0x4ecaul);
tv=((u16)(25710L));
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L4ed0;
L4ed0: /* move.w D1, D2 */
VSTEP(0x4ed0ul);
tv=((u16)d[1]);
VWORD(d[2])=(u16)(tv);

goto L4ed2;
L4ed2: /* add.w $69ee.w, D2 */
VSTEP(0x4ed2ul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4ed6;
L4ed6: /* subq.w #2, D2 */
VSTEP(0x4ed6ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4ed8;
L4ed8: /* andi.w #$7, D2 */
VSTEP(0x4ed8ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L4edc;
L4edc: /* sub.w D2, D1 */
VSTEP(0x4edcul);
tv=((u16)d[2]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L4ede;
L4ede: /* move.w D1, $69f4.w */
VSTEP(0x4edeul);
tv=((u16)d[1]);
vm_vars[1742]=(u8)((u32)(tv)>>8);
vm_vars[1743]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L4ee2;
L4ee2: /* rts  */
VSTEP(0x4ee2ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4ee4: /* move.w D5, (A0) */
VSTEP(0x4ee4ul);
tv=((u16)d[5]);
ea=a[0];
cvw16(ea,tv);

goto L4ee6;
L4ee6: /* btst #$2, D4 */
VSTEP(0x4ee6ul);
v=((u16)(2L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L4eea;
L4eea: /* beq $4efe */
VSTEP(0x4eeaul);
if(fz)goto L4efe;
goto L4eee;
L4eee: /* move.w #$28, $69f6.w */
VSTEP(0x4eeeul);
tv=((u16)(40L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L4ef4;
L4ef4: /* addq.w #1, D5 */
VSTEP(0x4ef4ul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L4ef6;
L4ef6: /* cmpi.w #$50, D5 */
VSTEP(0x4ef6ul);
tv=((u16)(80L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L4efa;
L4efa: /* bcc $4efe */
VSTEP(0x4efaul);
if(!fc)goto L4efe;
goto L4efc;
L4efc: /* move.w D5, (A0) */
VSTEP(0x4efcul);
tv=((u16)d[5]);
ea=a[0];
cvw16(ea,tv);

goto L4efe;
L4efe: /* lea $635c.w, A0 */
VSTEP(0x4efeul);
a[0]=0x635cul;
goto L4f02;
L4f02: /* movem.w (A0), D2-D3 */
VSTEP(0x4f02ul);
ea=a[0];
d[2]=(s16)cvr16(ea+0);
d[3]=(s16)cvr16(ea+2);
goto L4f06;
L4f06: /* clr.w D7 */
VSTEP(0x4f06ul);
VWORD(d[7])=(u16)(0);

goto L4f08;
L4f08: /* moveq #$7, D6 */
VSTEP(0x4f08ul);
v=((u32)(7L));
d[6]=v;

goto L4f0a;
L4f0a: /* cmpi.w #$28, D5 */
VSTEP(0x4f0aul);
tv=((u16)(40L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L4f0e;
L4f0e: /* bcc $4f1a */
VSTEP(0x4f0eul);
if(!fc)goto L4f1a;
goto L4f10;
L4f10: /* moveq #$3, D6 */
VSTEP(0x4f10ul);
v=((u32)(3L));
d[6]=v;

goto L4f12;
L4f12: /* cmpi.w #$14, D6 */
VSTEP(0x4f12ul);
tv=((u16)(20L));
tw=((u16)d[6]);
fc=(u8)((u16)tw<(u16)tv);
goto L4f16;
L4f16: /* bcc $4f1a */
VSTEP(0x4f16ul);
if(!fc)goto L4f1a;
goto L4f18;
L4f18: /* moveq #$1, D6 */
VSTEP(0x4f18ul);
v=((u32)(1L));
d[6]=v;

goto L4f1a;
L4f1a: /* and.w $6374.w, D6 */
VSTEP(0x4f1aul);
ea=0x6374ul;
tv=(((u16)vm_vars[78]<<8)|((u16)vm_vars[79]<<0));
tw=((u16)d[6]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[6])=(u16)(tr);
goto L4f1e;
L4f1e: /* bne $4f2a */
VSTEP(0x4f1eul);
if(!fz)goto L4f2a;
goto L4f20;
L4f20: /* andi.w #$3, D4 */
VSTEP(0x4f20ul);
tv=((u16)(3L));
tw=((u16)d[4]);
tr=tw&tv;

VWORD(d[4])=(u16)(tr);
goto L4f24;
L4f24: /* asr.w #1, D4 */
VSTEP(0x4f24ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fx=(u8)((tw>>0)&1);fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L4f26;
L4f26: /* subx.w D7, D4 */
VSTEP(0x4f26ul);
v=((u16)d[7]);
w=((u16)d[4]);
r=w-v-fx;
VWORD(d[4])=(u16)(r);
goto L4f28;
L4f28: /* move.w D4, D7 */
VSTEP(0x4f28ul);
tv=((u16)d[4]);
VWORD(d[7])=(u16)(tv);

goto L4f2a;
L4f2a: /* move.w D2, D4 */
VSTEP(0x4f2aul);
tv=((u16)d[2]);
VWORD(d[4])=(u16)(tv);

goto L4f2c;
L4f2c: /* ext.l D4 */
VSTEP(0x4f2cul);
v=((u32)d[4]);
r=(s32)(s16)v;
d[4]=r;

goto L4f2e;
L4f2e: /* divs.w D5, D4 */
VSTEP(0x4f2eul);
v=((u16)d[5]);
w=((u32)d[4]);
if(!(s16)v){vm_fault=0xff;return;}
signed_result=(s32)w/(s16)v;
if(signed_result>32767L||signed_result<-32768L){fv=1;}else{r=((u32)((s32)w%(s16)v)<<16)|(u16)signed_result;}
d[4]=r;
goto L4f30;
L4f30: /* sub.w D7, D4 */
VSTEP(0x4f30ul);
tv=((u16)d[7]);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4f32;
L4f32: /* add.w D4, D3 */
VSTEP(0x4f32ul);
tv=((u16)d[4]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L4f34;
L4f34: /* sub.w D3, D2 */
VSTEP(0x4f34ul);
tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L4f36;
L4f36: /* addi.w #$80, D2 */
VSTEP(0x4f36ul);
tv=((u16)(128L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L4f3a;
L4f3a: /* cmpi.w #$100, D2 */
VSTEP(0x4f3aul);
tv=((u16)(256L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L4f3e;
L4f3e: /* bcc $4f46 */
VSTEP(0x4f3eul);
if(!fc)goto L4f46;
goto L4f40;
L4f40: /* subi.w #$80, D2 */
VSTEP(0x4f40ul);
tv=((u16)(128L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4f44;
L4f44: /* bra $4f54 */
VSTEP(0x4f44ul);
goto L4f54;
L4f46: /* clr.w D3 */
VSTEP(0x4f46ul);
VWORD(d[3])=(u16)(0);

goto L4f48;
L4f48: /* subi.w #$80, D2 */
VSTEP(0x4f48ul);
tv=((u16)(128L));
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L4f4c;
L4f4c: /* bpl $4f52 */
VSTEP(0x4f4cul);
if(!fn)goto L4f52;
goto L4f4e;
L4f4e: /* moveq #-$7f, D2 */
VSTEP(0x4f4eul);
v=((u32)(-127L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4f50;
L4f50: /* bra $4f54 */
VSTEP(0x4f50ul);
goto L4f54;
L4f52: /* moveq #$7f, D2 */
VSTEP(0x4f52ul);
v=((u32)(127L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4f54;
L4f54: /* movem.w D2-D3, (A0) */
VSTEP(0x4f54ul);
ea=a[0];
cvw16(ea+0,d[2]);
cvw16(ea+2,d[3]);
goto L4f58;
L4f58: /* lea $635c.w, A0 */
VSTEP(0x4f58ul);
a[0]=0x635cul;
goto L4f5c;
L4f5c: /* lea $69f2.w, A2 */
VSTEP(0x4f5cul);
a[2]=0x69f2ul;
goto L4f60;
L4f60: /* bsr $50e8 */
VSTEP(0x4f60ul);
a[7]-=4;cvw32(a[7],0x4f64ul);
goto L50e8;
L4f64: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x4f64ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L4f6a;
L4f6a: /* movem.w $6370.w, D5-D6 */
VSTEP(0x4f6aul);
ea=0x6370ul;
d[5]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+74u));
d[6]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+76u));
goto L4f70;
L4f70: /* sub.w D3, D5 */
VSTEP(0x4f70ul);
tv=((u16)d[3]);
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4f72;
L4f72: /* move.w D5, $633c.w */
VSTEP(0x4f72ul);
tv=((u16)d[5]);
vm_vars[22]=(u8)((u32)(tv)>>8);
vm_vars[23]=(u8)((u32)(tv)>>0);

goto L4f76;
L4f76: /* move.w D5, $6356.w */
VSTEP(0x4f76ul);
tv=((u16)d[5]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);

goto L4f7a;
L4f7a: /* sub.w D6, D4 */
VSTEP(0x4f7aul);
tv=((u16)d[6]);
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4f7c;
L4f7c: /* move.w D4, $633e.w */
VSTEP(0x4f7cul);
tv=((u16)d[4]);
vm_vars[24]=(u8)((u32)(tv)>>8);
vm_vars[25]=(u8)((u32)(tv)>>0);

goto L4f80;
L4f80: /* add.w D4, D1 */
VSTEP(0x4f80ul);
tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4f82;
L4f82: /* add.w D5, D0 */
VSTEP(0x4f82ul);
tv=((u16)d[5]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L4f84;
L4f84: /* subq.w #4, D1 */
VSTEP(0x4f84ul);
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L4f86;
L4f86: /* subq.w #5, D0 */
VSTEP(0x4f86ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L4f88;
L4f88: /* bsr $55e0 */
VSTEP(0x4f88ul);
a[7]-=4;cvw32(a[7],0x4f8cul);
goto L55e0;
L4f8c: /* moveq #$2, D7 */
VSTEP(0x4f8cul);
v=((u32)(2L));
d[7]=v;

goto L4f8e;
L4f8e: /* move.b (A0,D3.w), D2 */
VSTEP(0x4f8eul);
ea=(a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4f92;
L4f92: /* cmpi.b #$3, D2 */
VSTEP(0x4f92ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4f96;
L4f96: /* bcs $4fcc */
VSTEP(0x4f96ul);
if(fc)goto L4fcc;
goto L4f98;
L4f98: /* move.b ($1,A0,D3.w), D2 */
VSTEP(0x4f98ul);
ea=(1+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L4f9c;
L4f9c: /* cmpi.b #$3, D2 */
VSTEP(0x4f9cul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L4fa0;
L4fa0: /* bcs $4fcc */
VSTEP(0x4fa0ul);
if(fc)goto L4fcc;
goto L4fa2;
L4fa2: /* sub.w $8002.l, D3 */
VSTEP(0x4fa2ul);
ea=0x8002ul;
tv=88u;
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L4fa8;
L4fa8: /* dbra D7, $4f8e */
VSTEP(0x4fa8ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L4f8e;
goto L4fac;
L4fac: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x4facul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L4fb2;
L4fb2: /* add.w D4, D1 */
VSTEP(0x4fb2ul);
tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L4fb4;
L4fb4: /* add.w D5, D0 */
VSTEP(0x4fb4ul);
tv=((u16)d[5]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L4fb6;
L4fb6: /* movem.w D0-D1, $69f2.w */
VSTEP(0x4fb6ul);
ea=0x69f2ul;
dm_put16((u8 DM_NEAR *)(vm_vars+1740u),(u16)(d[0]));
dm_put16((u8 DM_NEAR *)(vm_vars+1742u),(u16)(d[1]));
goto L4fbc;
L4fbc: /* move.l $6362.w, $6370.w */
VSTEP(0x4fbcul);
ea=0x6362ul;
v=(((u32)vm_vars[60]<<24)|((u32)vm_vars[61]<<16)|((u32)vm_vars[62]<<8)|((u32)vm_vars[63]<<0));
vm_vars[74]=(u8)((u32)(v)>>24);
vm_vars[75]=(u8)((u32)(v)>>16);
vm_vars[76]=(u8)((u32)(v)>>8);
vm_vars[77]=(u8)((u32)(v)>>0);
fn=(u8)((v&0x80000000ul)!=0);fv=0;fc=0;
goto L4fc2;
L4fc2: /* btst #$4, $6350.w */
VSTEP(0x4fc2ul);
v=((u16)(4L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L4fc8;
L4fc8: /* bne $4fec */
VSTEP(0x4fc8ul);
if(!fz)goto L4fec;
goto L4fca;
L4fca: /* rts  */
VSTEP(0x4fcaul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4fcc: /* tst.w D4 */
VSTEP(0x4fccul);
tv=((u16)d[4]);
fn=(u8)((tv&0x8000ul)!=0);
goto L4fce;
L4fce: /* bmi $4fd8 */
VSTEP(0x4fceul);
if(fn)goto L4fd8;
goto L4fd0;
L4fd0: /* subq.w #2, $6360.w */
VSTEP(0x4fd0ul);
tv=((u16)(2L));
eb=0x6360ul;
tw=(((u16)vm_vars[58]<<8)|((u16)vm_vars[59]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[58]=(u8)((u32)(tr)>>8);
vm_vars[59]=(u8)((u32)(tr)>>0);
goto L4fd4;
L4fd4: /* bra $4f58 */
VSTEP(0x4fd4ul);
goto L4f58;
L4fd8: /* movem.w D0-D7, -(A7) */
VSTEP(0x4fd8ul);
a[7]-=2;
cvw16(a[7],d[7]);
a[7]-=2;
cvw16(a[7],d[6]);
a[7]-=2;
cvw16(a[7],d[5]);
a[7]-=2;
cvw16(a[7],d[4]);
a[7]-=2;
cvw16(a[7],d[3]);
a[7]-=2;
cvw16(a[7],d[2]);
a[7]-=2;
cvw16(a[7],d[1]);
a[7]-=2;
cvw16(a[7],d[0]);
goto L4fdc;
L4fdc: /* moveq #$2, D6 */
VSTEP(0x4fdcul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L4fde;
L4fde: /* bsr $4d0a */
VSTEP(0x4fdeul);
a[7]-=4;cvw32(a[7],0x4fe2ul);
goto L4d0a;
L4fe2: /* movem.w (A7)+, D0-D7 */
VSTEP(0x4fe2ul);
ea=a[7];
d[0]=(s16)cvr16(ea+0);
d[1]=(s16)cvr16(ea+2);
d[2]=(s16)cvr16(ea+4);
d[3]=(s16)cvr16(ea+6);
d[4]=(s16)cvr16(ea+8);
d[5]=(s16)cvr16(ea+10);
d[6]=(s16)cvr16(ea+12);
d[7]=(s16)cvr16(ea+14);
a[7]+=16;
goto L4fe6;
L4fe6: /* clr.w D4 */
VSTEP(0x4fe6ul);
VWORD(d[4])=(u16)(0);

goto L4fe8;
L4fe8: /* clr.w D5 */
VSTEP(0x4fe8ul);
VWORD(d[5])=(u16)(0);

goto L4fea;
L4fea: /* bra $500a */
VSTEP(0x4feaul);
goto L500a;
L4fec: /* movem.w $633c.w, D4-D5 */
VSTEP(0x4fecul);
ea=0x633cul;
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+22u));
d[5]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+24u));
goto L4ff2;
L4ff2: /* subq.w #3, D5 */
VSTEP(0x4ff2ul);
tv=((u16)(3L));
tw=((u16)d[5]);
tr=tw-tv;
VWORD(d[5])=(u16)(tr);
goto L4ff4;
L4ff4: /* cmpi.w #-$6, D5 */
VSTEP(0x4ff4ul);
tv=((u16)(-6L));
tw=((u16)d[5]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L4ff8;
L4ff8: /* bpl $4ffc */
VSTEP(0x4ff8ul);
if(!fn)goto L4ffc;
goto L4ffa;
L4ffa: /* moveq #-$6, D5 */
VSTEP(0x4ffaul);
v=((u32)(-6L));
d[5]=v;

goto L4ffc;
L4ffc: /* subq.w #2, D4 */
VSTEP(0x4ffcul);
tv=((u16)(2L));
tw=((u16)d[4]);
tr=tw-tv;
VWORD(d[4])=(u16)(tr);
goto L4ffe;
L4ffe: /* cmpi.w #-$4, D4 */
VSTEP(0x4ffeul);
tv=((u16)(-4L));
tw=((u16)d[4]);
fc=(u8)((u16)tw<(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5002;
L5002: /* bcc $5008 */
VSTEP(0x5002ul);
if(!fc)goto L5008;
goto L5004;
L5004: /* smi D4 */
VSTEP(0x5004ul);
VBYTE(d[4])=(u8)((fn?255:0));
goto L5006;
L5006: /* asl.w #2, D4 */
VSTEP(0x5006ul);
tv=((u16)(2L));
tw=((u16)d[4]);
tr=tw<<2;
VWORD(d[4])=(u16)(tr);
goto L5008;
L5008: /* addq.w #2, D4 */
VSTEP(0x5008ul);
tv=((u16)(2L));
tw=((u16)d[4]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[4])=(u16)(tr);
goto L500a;
L500a: /* movem.w D4-D5, $633c.w */
VSTEP(0x500aul);
ea=0x633cul;
dm_put16((u8 DM_NEAR *)(vm_vars+22u),(u16)(d[4]));
dm_put16((u8 DM_NEAR *)(vm_vars+24u),(u16)(d[5]));
goto L5010;
L5010: /* clr.w $6360.w */
VSTEP(0x5010ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L5014;
L5014: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x5014ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L501a;
L501a: /* bra $549c */
VSTEP(0x501aul);
goto L549c;
L501e: /* move.w #$6461, $636e.l */
VSTEP(0x501eul);
tv=((u16)(25697L));
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L5026;
L5026: /* move.w #$5034, $3c7c.w */
VSTEP(0x5026ul);
tv=((u16)(20532L));
vm_player_state=(u16)(tv);

goto L502c;
L502c: /* moveq #$8, D0 */
VSTEP(0x502cul);
v=((u32)(8L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L502e;
L502e: /* jsr $48014.l */
VSTEP(0x502eul);
a[7]-=4;cvw32(a[7],0x5034ul);
goto L48014;
L5034: /* movea.w $636e.w, A0 */
VSTEP(0x5034ul);
ea=0x636eul;
v=(((u16)vm_vars[72]<<8)|((u16)vm_vars[73]<<0));
a[0]=(s16)v;
goto L5038;
L5038: /* bsr $5470 */
VSTEP(0x5038ul);
a[7]-=4;cvw32(a[7],0x503cul);
goto L5470;
L503c: /* move.w A0, $636e.w */
VSTEP(0x503cul);
tv=((u16)a[0]);
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L5040;
L5040: /* tst.b (A0) */
VSTEP(0x5040ul);
ea=a[0];
tv=cvr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5042;
L5042: /* bne $5072 */
VSTEP(0x5042ul);
if(!fz)goto L5072;
goto L5044;
L5044: /* move.w #$8, $633a.w */
VSTEP(0x5044ul);
tv=((u16)(8L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L504a;
L504a: /* move.w #$5074, $3c7c.w */
VSTEP(0x504aul);
tv=((u16)(20596L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5050;
L5050: /* bsr $467c */
VSTEP(0x5050ul);
a[7]-=4;cvw32(a[7],0x5054ul);
goto L467c;
L5054: /* subi.w #$7, D0 */
VSTEP(0x5054ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5058;
L5058: /* move.w $6336.w, D2 */
VSTEP(0x5058ul);
ea=0x6336ul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L505c;
L505c: /* spl D2 */
VSTEP(0x505cul);
VBYTE(d[2])=(u8)((!fn?255:0));
goto L505e;
L505e: /* ext.w D2 */
VSTEP(0x505eul);
v=((u32)d[2]);
r=(s16)(s8)v;
VWORD(d[2])=(u16)(r);
fn=(u8)((r&0x8000ul)!=0);
goto L5060;
L5060: /* bpl $5066 */
VSTEP(0x5060ul);
if(!fn)goto L5066;
goto L5062;
L5062: /* addi.w #$e, D0 */
VSTEP(0x5062ul);
tv=((u16)(14L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5066;
L5066: /* addq.w #3, D2 */
VSTEP(0x5066ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5068;
L5068: /* move.w D2, (A0)+ */
VSTEP(0x5068ul);
tv=((u16)d[2]);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L506a;
L506a: /* subi.w #$10, D1 */
VSTEP(0x506aul);
tv=((u16)(16L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L506e;
L506e: /* movem.w D0-D1, (A0) */
VSTEP(0x506eul);
ea=a[0];
cvw16(ea+0,d[0]);
cvw16(ea+2,d[1]);
goto L5072;
L5072: /* rts  */
VSTEP(0x5072ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5074: /* move.b $6350.l, D4 */
VSTEP(0x5074ul);
ea=0x6350ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[4])=(u8)(tv);
fz=(u8)((tv&0xfful)==0);
goto L507a;
L507a: /* bne $508c */
VSTEP(0x507aul);
if(!fz)goto L508c;
goto L507e;
L507e: /* subq.w #1, $633a.w */
VSTEP(0x507eul);
tv=((u16)(1L));
eb=0x633aul;
tw=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[20]=(u8)((u32)(tr)>>8);
vm_vars[21]=(u8)((u32)(tr)>>0);
goto L5082;
L5082: /* bne $5072 */
VSTEP(0x5082ul);
if(!fz)goto L5072;
goto L5084;
L5084: /* lea $641b.w, A0 */
VSTEP(0x5084ul);
a[0]=0x641bul;
goto L5088;
L5088: /* bra $5470 */
VSTEP(0x5088ul);
goto L5470;
L508c: /* move.w #$4c7c, $3c7c.w */
VSTEP(0x508cul);
tv=((u16)(19580L));
vm_player_state=(u16)(tv);

goto L5092;
L5092: /* bra $4c7c */
VSTEP(0x5092ul);
goto L4c7c;
L5096: /* subq.w #1, $633a.w */
VSTEP(0x5096ul);
tv=((u16)(1L));
eb=0x633aul;
tw=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[20]=(u8)((u32)(tr)>>8);
vm_vars[21]=(u8)((u32)(tr)>>0);
goto L509a;
L509a: /* bne $5072 */
VSTEP(0x509aul);
if(!fz)goto L5072;
goto L509c;
L509c: /* move.w #$6, $633a.w */
VSTEP(0x509cul);
tv=((u16)(6L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L50a2;
L50a2: /* subq.w #5, $69f4.w */
VSTEP(0x50a2ul);
tv=((u16)(5L));
eb=0x69f4ul;
tw=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tr=tw-tv;
vm_vars[1742]=(u8)((u32)(tr)>>8);
vm_vars[1743]=(u8)((u32)(tr)>>0);
goto L50a6;
L50a6: /* subq.w #4, D1 */
VSTEP(0x50a6ul);
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L50a8;
L50a8: /* move.w $6336.w, D2 */
VSTEP(0x50a8ul);
ea=0x6336ul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L50ac;
L50ac: /* bmi $50c0 */
VSTEP(0x50acul);
if(fn)goto L50c0;
goto L50ae;
L50ae: /* addq.w #7, D0 */
VSTEP(0x50aeul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L50b0;
L50b0: /* bsr $55e0 */
VSTEP(0x50b0ul);
a[7]-=4;cvw32(a[7],0x50b4ul);
goto L55e0;
L50b4: /* cmpi.b #$3, D2 */
VSTEP(0x50b4ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L50b8;
L50b8: /* bcs $50d0 */
VSTEP(0x50b8ul);
if(fc)goto L50d0;
goto L50ba;
L50ba: /* addq.w #1, $69f2.w */
VSTEP(0x50baul);
tv=((u16)(1L));
eb=0x69f2ul;
tw=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[1740]=(u8)((u32)(tr)>>8);
vm_vars[1741]=(u8)((u32)(tr)>>0);
goto L50be;
L50be: /* bra $50d0 */
VSTEP(0x50beul);
goto L50d0;
L50c0: /* subq.w #6, D0 */
VSTEP(0x50c0ul);
tv=((u16)(6L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L50c2;
L50c2: /* bsr $55e0 */
VSTEP(0x50c2ul);
a[7]-=4;cvw32(a[7],0x50c6ul);
goto L55e0;
L50c6: /* cmpi.b #$3, D2 */
VSTEP(0x50c6ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L50ca;
L50ca: /* bcs $50d0 */
VSTEP(0x50caul);
if(fc)goto L50d0;
goto L50cc;
L50cc: /* subq.w #1, $69f2.w */
VSTEP(0x50ccul);
tv=((u16)(1L));
eb=0x69f2ul;
tw=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[1740]=(u8)((u32)(tr)>>8);
vm_vars[1741]=(u8)((u32)(tr)>>0);
goto L50d0;
L50d0: /* movea.w $636e.w, A0 */
VSTEP(0x50d0ul);
ea=0x636eul;
v=(((u16)vm_vars[72]<<8)|((u16)vm_vars[73]<<0));
a[0]=(s16)v;
goto L50d4;
L50d4: /* bsr $5470 */
VSTEP(0x50d4ul);
a[7]-=4;cvw32(a[7],0x50d8ul);
goto L5470;
L50d8: /* move.w A0, $636e.w */
VSTEP(0x50d8ul);
tv=((u16)a[0]);
vm_vars[72]=(u8)((u32)(tv)>>8);
vm_vars[73]=(u8)((u32)(tv)>>0);

goto L50dc;
L50dc: /* move.b (A0), D7 */
VSTEP(0x50dcul);
ea=a[0];
tv=cvr8(ea);
VBYTE(d[7])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L50de;
L50de: /* bne $50e6 */
VSTEP(0x50deul);
if(!fz)goto L50e6;
goto L50e0;
L50e0: /* move.w #$544c, $3c7c.w */
VSTEP(0x50e0ul);
tv=((u16)(21580L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L50e6;
L50e6: /* rts  */
VSTEP(0x50e6ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L50e8: /* lea ($7c,A0), A1 */
VSTEP(0x50e8ul);
a[1]=(124+a[0]);
goto L50ec;
L50ec: /* move.w (A0), D2 */
VSTEP(0x50ecul);
ea=a[0];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L50ee;
L50ee: /* asr.w #1, D2 */
VSTEP(0x50eeul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((s16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L50f0;
L50f0: /* move.w D2, D4 */
VSTEP(0x50f0ul);
tv=((u16)d[2]);
VWORD(d[4])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L50f2;
L50f2: /* bpl $50f6 */
VSTEP(0x50f2ul);
if(!fn)goto L50f6;
goto L50f4;
L50f4: /* neg.w D4 */
VSTEP(0x50f4ul);
tv=((u16)d[4]);
tr=0-tv;
VWORD(d[4])=(u16)(tr);
goto L50f6;
L50f6: /* clr.w D3 */
VSTEP(0x50f6ul);
VWORD(d[3])=(u16)(0);

goto L50f8;
L50f8: /* move.b (-$40,A1,D4.w), D3 */
VSTEP(0x50f8ul);
ea=(-64+a[1]+((s16)(d[4])));
tv=cvr8(ea);
VBYTE(d[3])=(u8)(tv);

goto L50fc;
L50fc: /* mulu.w ($4,A0), D3 */
VSTEP(0x50fcul);
ea=(4+a[0]);
v=cvr16(ea);
w=((u32)d[3]);
r=(u32)(u16)v*(u16)w;

d[3]=r;
goto L5100;
L5100: /* btst #$f, D2 */
VSTEP(0x5100ul);
v=((u16)(15L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5104;
L5104: /* beq $5108 */
VSTEP(0x5104ul);
if(fz)goto L5108;
goto L5106;
L5106: /* neg.w D3 */
VSTEP(0x5106ul);
tv=((u16)d[3]);
tr=0-tv;
VWORD(d[3])=(u16)(tr);
goto L5108;
L5108: /* asr.w #8, D3 */
VSTEP(0x5108ul);
tv=((u16)(8L));
tw=((u16)d[3]);
tr=((s16)tw)>>8;
VWORD(d[3])=(u16)(tr);
goto L510a;
L510a: /* move.w D3, ($6,A0) */
VSTEP(0x510aul);
tv=((u16)d[3]);
ea=(6+a[0]);
cvw16(ea,tv);

goto L510e;
L510e: /* move.w D4, D2 */
VSTEP(0x510eul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L5110;
L5110: /* neg.w D2 */
VSTEP(0x5110ul);
tv=((u16)d[2]);
tr=0-tv;
VWORD(d[2])=(u16)(tr);
goto L5112;
L5112: /* clr.w D4 */
VSTEP(0x5112ul);
VWORD(d[4])=(u16)(0);

goto L5114;
L5114: /* move.b ($3f,A1,D2.w), D4 */
VSTEP(0x5114ul);
ea=(63+a[1]+((s16)(d[2])));
tv=cvr8(ea);
VBYTE(d[4])=(u8)(tv);

goto L5118;
L5118: /* mulu.w ($4,A0), D4 */
VSTEP(0x5118ul);
ea=(4+a[0]);
v=cvr16(ea);
w=((u32)d[4]);
r=(u32)(u16)v*(u16)w;

d[4]=r;
goto L511c;
L511c: /* lsr.w #8, D4 */
VSTEP(0x511cul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=((u16)tw)>>8;fx=(u8)((tw>>7)&1);
VWORD(d[4])=(u16)(tr);
goto L511e;
L511e: /* move.w D4, ($8,A0) */
VSTEP(0x511eul);
tv=((u16)d[4]);
ea=(8+a[0]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5122;
L5122: /* rts  */
VSTEP(0x5122ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5124: /* clr.w $6336.w */
VSTEP(0x5124ul);
vm_vars[16]=(u8)((u32)(0)>>8);
vm_vars[17]=(u8)((u32)(0)>>0);

goto L5128;
L5128: /* moveq #$7f, D0 */
VSTEP(0x5128ul);
v=((u32)(127L));
d[0]=v;

goto L512a;
L512a: /* bra $5138 */
VSTEP(0x512aul);
goto L5138;
L512c: /* move.w #$e000, $6336.w */
VSTEP(0x512cul);
tv=((u16)(57344L));
vm_vars[16]=(u8)((u32)(tv)>>8);
vm_vars[17]=(u8)((u32)(tv)>>0);

goto L5132;
L5132: /* moveq #-$7f, D0 */
VSTEP(0x5132ul);
v=((u32)(-127L));
d[0]=v;

goto L5134;
L5134: /* bra $5138 */
VSTEP(0x5134ul);
goto L5138;
L5136: /* clr.w D0 */
VSTEP(0x5136ul);
VWORD(d[0])=(u16)(0);

goto L5138;
L5138: /* move.w #$48, $69f6.w */
VSTEP(0x5138ul);
tv=((u16)(72L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L513e;
L513e: /* lea $635c.w, A0 */
VSTEP(0x513eul);
a[0]=0x635cul;
goto L5142;
L5142: /* move.w D0, (A0)+ */
VSTEP(0x5142ul);
tv=((u16)d[0]);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L5144;
L5144: /* clr.l (A0)+ */
VSTEP(0x5144ul);
ea=a[0];
cvw32(ea,0);
a[0]+=4;
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5146;
L5146: /* bsr $467c */
VSTEP(0x5146ul);
a[7]-=4;cvw32(a[7],0x514aul);
goto L467c;
L514a: /* move.w #$1, (A0) */
VSTEP(0x514aul);
tv=((u16)(1L));
ea=a[0];
cvw16(ea,tv);

goto L514e;
L514e: /* move.w #$5170, $3c7c.w */
VSTEP(0x514eul);
tv=((u16)(20848L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5154;
L5154: /* lea $6418.w, A0 */
VSTEP(0x5154ul);
a[0]=0x6418ul;
goto L5158;
L5158: /* bsr $5470 */
VSTEP(0x5158ul);
a[7]-=4;cvw32(a[7],0x515cul);
goto L5470;
L515c: /* moveq #$7, D0 */
VSTEP(0x515cul);
v=((u32)(7L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L515e;
L515e: /* jsr $48014.l */
VSTEP(0x515eul);
a[7]-=4;cvw32(a[7],0x5164ul);
goto L48014;
L5164: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x5164ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L516a;
L516a: /* bclr #$4, $6350.w */
VSTEP(0x516aul);
v=((u16)(4L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
vm_vars[42]=(u8)((u32)(r)>>0);
goto L5170;
L5170: /* lea $635c.w, A0 */
VSTEP(0x5170ul);
a[0]=0x635cul;
goto L5174;
L5174: /* btst #$4, $6350.l */
VSTEP(0x5174ul);
v=((u16)(4L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L517c;
L517c: /* bne $51fc */
VSTEP(0x517cul);
if(!fz)goto L51fc;
goto L517e;
L517e: /* move.w ($4,A0), D2 */
VSTEP(0x517eul);
ea=(4+a[0]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L5182;
L5182: /* addq.w #2, D2 */
VSTEP(0x5182ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5184;
L5184: /* cmpi.w #$28, D2 */
VSTEP(0x5184ul);
tv=((u16)(40L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5188;
L5188: /* bcc $5194 */
VSTEP(0x5188ul);
if(!fc)goto L5194;
goto L518a;
L518a: /* addq.w #1, D2 */
VSTEP(0x518aul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L518c;
L518c: /* cmpi.w #$14, D2 */
VSTEP(0x518cul);
tv=((u16)(20L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5190;
L5190: /* bcc $5194 */
VSTEP(0x5190ul);
if(!fc)goto L5194;
goto L5192;
L5192: /* addq.w #1, D2 */
VSTEP(0x5192ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L5194;
L5194: /* move.w D2, ($4,A0) */
VSTEP(0x5194ul);
tv=((u16)d[2]);
ea=(4+a[0]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5198;
L5198: /* bsr $50e8 */
VSTEP(0x5198ul);
a[7]-=4;cvw32(a[7],0x519cul);
goto L50e8;
L519c: /* addq.w #3, D3 */
VSTEP(0x519cul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L519e;
L519e: /* move.w $6336.w, D7 */
VSTEP(0x519eul);
ea=0x6336ul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);
goto L51a2;
L51a2: /* bpl $51a6 */
VSTEP(0x51a2ul);
if(!fn)goto L51a6;
goto L51a4;
L51a4: /* subq.w #7, D3 */
VSTEP(0x51a4ul);
tv=((u16)(7L));
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L51a6;
L51a6: /* addi.w #$a, D4 */
VSTEP(0x51a6ul);
tv=((u16)(10L));
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L51aa;
L51aa: /* sub.w D4, D1 */
VSTEP(0x51aaul);
tv=((u16)d[4]);
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L51ac;
L51ac: /* bcs $51e6 */
VSTEP(0x51acul);
if(fc)goto L51e6;
goto L51ae;
L51ae: /* move.w $69ee.w, D5 */
VSTEP(0x51aeul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
VWORD(d[5])=(u16)(tv);

goto L51b2;
L51b2: /* add.w D1, D5 */
VSTEP(0x51b2ul);
tv=((u16)d[1]);
tw=((u16)d[5]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[5])=(u16)(tr);
goto L51b4;
L51b4: /* btst #$2, D5 */
VSTEP(0x51b4ul);
v=((u16)(2L));
w=((u32)d[5]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L51b8;
L51b8: /* bne $51ec */
VSTEP(0x51b8ul);
if(!fz)goto L51ec;
goto L51ba;
L51ba: /* add.w D3, D0 */
VSTEP(0x51baul);
tv=((u16)d[3]);
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L51bc;
L51bc: /* bsr $55e0 */
VSTEP(0x51bcul);
a[7]-=4;cvw32(a[7],0x51c0ul);
goto L55e0;
L51c0: /* cmpi.b #$3, D2 */
VSTEP(0x51c0ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L51c4;
L51c4: /* bcs $51e6 */
VSTEP(0x51c4ul);
if(fc)goto L51e6;
goto L51c6;
L51c6: /* cmpi.b #$5f, D2 */
VSTEP(0x51c6ul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L51ca;
L51ca: /* bcc $51e6 */
VSTEP(0x51caul);
if(!fc)goto L51e6;
goto L51cc;
L51cc: /* cmpi.b #$51, D2 */
VSTEP(0x51ccul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L51d0;
L51d0: /* bcs $51ec */
VSTEP(0x51d0ul);
if(fc)goto L51ec;
goto L51d2;
L51d2: /* move.w #$4ea2, $3c7c.w */
VSTEP(0x51d2ul);
tv=((u16)(20130L));
vm_player_state=(u16)(tv);

goto L51d8;
L51d8: /* move.l $6362.w, $6370.w */
VSTEP(0x51d8ul);
ea=0x6362ul;
v=(((u32)vm_vars[60]<<24)|((u32)vm_vars[61]<<16)|((u32)vm_vars[62]<<8)|((u32)vm_vars[63]<<0));
vm_vars[74]=(u8)((u32)(v)>>24);
vm_vars[75]=(u8)((u32)(v)>>16);
vm_vars[76]=(u8)((u32)(v)>>8);
vm_vars[77]=(u8)((u32)(v)>>0);

goto L51de;
L51de: /* lea $645e.w, A0 */
VSTEP(0x51deul);
a[0]=0x645eul;
goto L51e2;
L51e2: /* bra $5470 */
VSTEP(0x51e2ul);
goto L5470;
L51e6: /* move.w #$51ee, $3c7c.w */
VSTEP(0x51e6ul);
tv=((u16)(20974L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L51ec;
L51ec: /* rts  */
VSTEP(0x51ecul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L51ee: /* lea $635c.w, A0 */
VSTEP(0x51eeul);
a[0]=0x635cul;
goto L51f2;
L51f2: /* btst #$4, $6350.l */
VSTEP(0x51f2ul);
v=((u16)(4L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L51fa;
L51fa: /* beq $5202 */
VSTEP(0x51faul);
if(fz)goto L5202;
goto L51fc;
L51fc: /* move.w #$2, ($4,A0) */
VSTEP(0x51fcul);
tv=((u16)(2L));
ea=(4+a[0]);
cvw16(ea,tv);

goto L5202;
L5202: /* subq.w #3, ($4,A0) */
VSTEP(0x5202ul);
tv=((u16)(3L));
eb=(4+a[0]);
tw=cvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
cvw16(eb,tr);
goto L5206;
L5206: /* bls $520c */
VSTEP(0x5206ul);
if((fc||fz))goto L520c;
goto L5208;
L5208: /* bra $50e8 */
VSTEP(0x5208ul);
goto L50e8;
L520c: /* clr.w ($4,A0) */
VSTEP(0x520cul);
ea=(4+a[0]);
cvw16(ea,0);

goto L5210;
L5210: /* move.w #$4c7c, $3c7c.w */
VSTEP(0x5210ul);
tv=((u16)(19580L));
vm_player_state=(u16)(tv);

goto L5216;
L5216: /* lea $641b.w, A0 */
VSTEP(0x5216ul);
a[0]=0x641bul;
goto L521a;
L521a: /* bra $5470 */
VSTEP(0x521aul);
goto L5470;
L521e: /* rts  */
VSTEP(0x521eul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5220: /* move.w #$28, $69f6.w */
VSTEP(0x5220ul);
tv=((u16)(40L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L5226;
L5226: /* addq.w #4, D0 */
VSTEP(0x5226ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5228;
L5228: /* bsr $55e0 */
VSTEP(0x5228ul);
a[7]-=4;cvw32(a[7],0x522cul);
goto L55e0;
L522c: /* subq.w #4, D0 */
VSTEP(0x522cul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L522e;
L522e: /* cmpi.b #$5f, D2 */
VSTEP(0x522eul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5232;
L5232: /* bne $521e */
VSTEP(0x5232ul);
if(!fz)goto L521e;
goto L5234;
L5234: /* bra $5254 */
VSTEP(0x5234ul);
goto L5254;
L5236: /* bsr $523c */
VSTEP(0x5236ul);
a[7]-=4;cvw32(a[7],0x5238ul);
goto L523c;
L5238: /* bra $5468 */
VSTEP(0x5238ul);
goto L5468;
L523c: /* move.w #$48, $69f6.w */
VSTEP(0x523cul);
tv=((u16)(72L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L5242;
L5242: /* addq.w #4, D0 */
VSTEP(0x5242ul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5244;
L5244: /* subq.w #4, D1 */
VSTEP(0x5244ul);
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5246;
L5246: /* bsr $55e0 */
VSTEP(0x5246ul);
a[7]-=4;cvw32(a[7],0x524aul);
goto L55e0;
L524a: /* addq.w #4, D1 */
VSTEP(0x524aul);
tv=((u16)(4L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L524c;
L524c: /* subq.w #4, D0 */
VSTEP(0x524cul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[0])=(u16)(tr);
goto L524e;
L524e: /* cmpi.b #$62, D2 */
VSTEP(0x524eul);
tv=((u8)(98L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5252;
L5252: /* bne $521e */
VSTEP(0x5252ul);
if(!fz)goto L521e;
goto L5254;
L5254: /* addq.w #4, A7 */
VSTEP(0x5254ul);
v=((u16)(4L));
w=((u32)a[7]);
r=w+v;
a[7]=r;
goto L5256;
L5256: /* andi.b #$c, $6350.w */
VSTEP(0x5256ul);
tv=((u8)(12L));
eb=0x6350ul;
tw=(((u8)vm_vars[42]<<0));
tr=tw&tv;

vm_vars[42]=(u8)((u32)(tr)>>0);
goto L525c;
L525c: /* move.w #$532e, $3c7c.w */
VSTEP(0x525cul);
tv=((u16)(21294L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fv=0;fc=0;
goto L5262;
L5262: /* bra $532e */
VSTEP(0x5262ul);
goto L532e;
L5266: /* bsr $5220 */
VSTEP(0x5266ul);
a[7]-=4;cvw32(a[7],0x5268ul);
goto L5220;
L5268: /* bra $526c */
VSTEP(0x5268ul);
goto L526c;
L526a: /* bsr $523c */
VSTEP(0x526aul);
a[7]-=4;cvw32(a[7],0x526cul);
goto L523c;
L526c: /* addq.w #4, D0 */
VSTEP(0x526cul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L526e;
L526e: /* subq.w #2, D1 */
VSTEP(0x526eul);
tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5270;
L5270: /* bsr $55e0 */
VSTEP(0x5270ul);
a[7]-=4;cvw32(a[7],0x5274ul);
goto L55e0;
L5274: /* cmpi.b #$3, D2 */
VSTEP(0x5274ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5278;
L5278: /* bcs $52b6 */
VSTEP(0x5278ul);
if(fc)goto L52b6;
goto L527a;
L527a: /* addq.w #1, $69f2.w */
VSTEP(0x527aul);
tv=((u16)(1L));
eb=0x69f2ul;
tw=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tr=tw+tv;
vm_vars[1740]=(u8)((u32)(tr)>>8);
vm_vars[1741]=(u8)((u32)(tr)>>0);
goto L527e;
L527e: /* addq.w #7, D1 */
VSTEP(0x527eul);
tv=((u16)(7L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L5280;
L5280: /* subq.w #5, D0 */
VSTEP(0x5280ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5282;
L5282: /* bsr $55e0 */
VSTEP(0x5282ul);
a[7]-=4;cvw32(a[7],0x5286ul);
goto L55e0;
L5286: /* subi.b #$51, D2 */
VSTEP(0x5286ul);
tv=((u8)(81L));
tw=((u8)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[2])=(u8)(tr);
goto L528a;
L528a: /* cmpi.b #$10, D2 */
VSTEP(0x528aul);
tv=((u8)(16L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L528e;
L528e: /* bcc $5492 */
VSTEP(0x528eul);
if(!fc)goto L5492;
goto L5292;
L5292: /* lea $6332.w, A0 */
VSTEP(0x5292ul);
a[0]=0x6332ul;
goto L5296;
L5296: /* add.w $69ec.w, D0 */
VSTEP(0x5296ul);
ea=0x69ecul;
tv=(((u16)vm_vars[1734]<<8)|((u16)vm_vars[1735]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L529a;
L529a: /* lsr.w #1, D0 */
VSTEP(0x529aul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;
VWORD(d[0])=(u16)(tr);
goto L529c;
L529c: /* andi.w #$7, D0 */
VSTEP(0x529cul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L52a0;
L52a0: /* addq.w #5, D0 */
VSTEP(0x52a0ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L52a2;
L52a2: /* move.w D0, (A0)+ */
VSTEP(0x52a2ul);
tv=((u16)d[0]);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L52a4;
L52a4: /* andi.w #$6, D0 */
VSTEP(0x52a4ul);
tv=((u16)(6L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L52a8;
L52a8: /* lsr.w #1, D0 */
VSTEP(0x52a8ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;fz=(u8)((tr&0xfffful)==0);
VWORD(d[0])=(u16)(tr);
goto L52aa;
L52aa: /* bne $52ae */
VSTEP(0x52aaul);
if(!fz)goto L52ae;
goto L52ac;
L52ac: /* moveq #$2, D0 */
VSTEP(0x52acul);
v=((u32)(2L));
d[0]=v;

goto L52ae;
L52ae: /* addq.w #1, D0 */
VSTEP(0x52aeul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L52b0;
L52b0: /* move.w D0, (A0)+ */
VSTEP(0x52b0ul);
tv=((u16)d[0]);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L52b2;
L52b2: /* move.w #$1, (A0) */
VSTEP(0x52b2ul);
tv=((u16)(1L));
ea=a[0];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L52b6;
L52b6: /* rts  */
VSTEP(0x52b6ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L52b8: /* bsr $5220 */
VSTEP(0x52b8ul);
a[7]-=4;cvw32(a[7],0x52bcul);
goto L5220;
L52bc: /* bra $52c2 */
VSTEP(0x52bcul);
goto L52c2;
L52be: /* bsr $523c */
VSTEP(0x52beul);
a[7]-=4;cvw32(a[7],0x52c2ul);
goto L523c;
L52c2: /* subq.w #5, D0 */
VSTEP(0x52c2ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L52c4;
L52c4: /* subq.w #2, D1 */
VSTEP(0x52c4ul);
tv=((u16)(2L));
tw=((u16)d[1]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L52c6;
L52c6: /* bsr $55e0 */
VSTEP(0x52c6ul);
a[7]-=4;cvw32(a[7],0x52caul);
goto L55e0;
L52ca: /* cmpi.b #$3, D2 */
VSTEP(0x52caul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L52ce;
L52ce: /* bcs $52b6 */
VSTEP(0x52ceul);
if(fc)goto L52b6;
goto L52d0;
L52d0: /* subq.w #1, $69f2.w */
VSTEP(0x52d0ul);
tv=((u16)(1L));
eb=0x69f2ul;
tw=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
tr=tw-tv;
vm_vars[1740]=(u8)((u32)(tr)>>8);
vm_vars[1741]=(u8)((u32)(tr)>>0);
goto L52d4;
L52d4: /* addq.w #7, D1 */
VSTEP(0x52d4ul);
tv=((u16)(7L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L52d6;
L52d6: /* addq.w #5, D0 */
VSTEP(0x52d6ul);
tv=((u16)(5L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L52d8;
L52d8: /* bsr $55e0 */
VSTEP(0x52d8ul);
a[7]-=4;cvw32(a[7],0x52dcul);
goto L55e0;
L52dc: /* subi.b #$51, D2 */
VSTEP(0x52dcul);
tv=((u8)(81L));
tw=((u8)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VBYTE(d[2])=(u8)(tr);
goto L52e0;
L52e0: /* cmpi.b #$10, D2 */
VSTEP(0x52e0ul);
tv=((u8)(16L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L52e4;
L52e4: /* bcc $5492 */
VSTEP(0x52e4ul);
if(!fc)goto L5492;
goto L52e8;
L52e8: /* lea $6332.w, A0 */
VSTEP(0x52e8ul);
a[0]=0x6332ul;
goto L52ec;
L52ec: /* add.w $69ec.w, D0 */
VSTEP(0x52ecul);
ea=0x69ecul;
tv=(((u16)vm_vars[1734]<<8)|((u16)vm_vars[1735]<<0));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L52f0;
L52f0: /* not.w D0 */
VSTEP(0x52f0ul);
tv=((u16)d[0]);
tr=~tv;
VWORD(d[0])=(u16)(tr);

goto L52f2;
L52f2: /* lsr.w #1, D0 */
VSTEP(0x52f2ul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=((u16)tw)>>1;
VWORD(d[0])=(u16)(tr);
goto L52f4;
L52f4: /* andi.w #$7, D0 */
VSTEP(0x52f4ul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L52f8;
L52f8: /* addi.w #-$1ffb, D0 */
VSTEP(0x52f8ul);
tv=((u16)(-8187L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L52fc;
L52fc: /* move.w D0, (A0)+ */
VSTEP(0x52fcul);
tv=((u16)d[0]);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L52fe;
L52fe: /* andi.w #$e006, D0 */
VSTEP(0x52feul);
tv=((u16)(57350L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L5302;
L5302: /* lsr.b #1, D0 */
VSTEP(0x5302ul);
tv=((u8)(1L));
tw=((u8)d[0]);
tr=((u8)tw)>>1;fz=(u8)((tr&0xfful)==0);
VBYTE(d[0])=(u8)(tr);
goto L5304;
L5304: /* bne $530a */
VSTEP(0x5304ul);
if(!fz)goto L530a;
goto L5306;
L5306: /* move.w #$e002, D0 */
VSTEP(0x5306ul);
tv=((u16)(57346L));
VWORD(d[0])=(u16)(tv);

goto L530a;
L530a: /* addq.w #1, D0 */
VSTEP(0x530aul);
tv=((u16)(1L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L530c;
L530c: /* move.w D0, (A0)+ */
VSTEP(0x530cul);
tv=((u16)d[0]);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L530e;
L530e: /* move.w #$e001, (A0) */
VSTEP(0x530eul);
tv=((u16)(57345L));
ea=a[0];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5312;
L5312: /* rts  */
VSTEP(0x5312ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5314: /* add.w D5, D3 */
VSTEP(0x5314ul);
tv=((u16)d[5]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5316;
L5316: /* move.b (A0,D3.w), D2 */
VSTEP(0x5316ul);
ea=(a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L531a;
L531a: /* subi.b #$51, D2 */
VSTEP(0x531aul);
tv=((u8)(81L));
tw=((u8)d[2]);
tr=tw-tv;
VBYTE(d[2])=(u8)(tr);
goto L531e;
L531e: /* cmpi.b #$10, D2 */
VSTEP(0x531eul);
tv=((u8)(16L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5322;
L5322: /* bcc $538e */
VSTEP(0x5322ul);
if(!fc)goto L538e;
goto L5324;
L5324: /* move.w #$4c7c, $3c7c.w */
VSTEP(0x5324ul);
tv=((u16)(19580L));
vm_player_state=(u16)(tv);

goto L532a;
L532a: /* bra $4c7c */
VSTEP(0x532aul);
goto L4c7c;
L532e: /* btst #$4, $6350.w */
VSTEP(0x532eul);
v=((u16)(4L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5334;
L5334: /* bne $5492 */
VSTEP(0x5334ul);
if(!fz)goto L5492;
goto L5338;
L5338: /* btst #$0, $6375.w */
VSTEP(0x5338ul);
v=((u16)(0L));
eb=0x6375ul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L533e;
L533e: /* bne $5312 */
VSTEP(0x533eul);
if(!fz)goto L5312;
goto L5340;
L5340: /* clr.w D4 */
VSTEP(0x5340ul);
VWORD(d[4])=(u16)(0);

goto L5342;
L5342: /* move.b $6350.w, D4 */
VSTEP(0x5342ul);
ea=0x6350ul;
tv=(((u8)vm_vars[42]<<0));
VBYTE(d[4])=(u8)(tv);

goto L5346;
L5346: /* move.w $69ee.w, D2 */
VSTEP(0x5346ul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
VWORD(d[2])=(u16)(tv);

goto L534a;
L534a: /* add.w D1, D2 */
VSTEP(0x534aul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L534c;
L534c: /* andi.w #$7, D2 */
VSTEP(0x534cul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;
fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;fc=0;
VWORD(d[2])=(u16)(tr);
goto L5350;
L5350: /* beq $5374 */
VSTEP(0x5350ul);
if(fz)goto L5374;
goto L5352;
L5352: /* btst #$2, D4 */
VSTEP(0x5352ul);
v=((u16)(2L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5356;
L5356: /* beq $5360 */
VSTEP(0x5356ul);
if(fz)goto L5360;
goto L5358;
L5358: /* addq.w #1, D1 */
VSTEP(0x5358ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw+tv;
VWORD(d[1])=(u16)(tr);
goto L535a;
L535a: /* move.w #$28, $69f6.w */
VSTEP(0x535aul);
tv=((u16)(40L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L5360;
L5360: /* btst #$3, D4 */
VSTEP(0x5360ul);
v=((u16)(3L));
w=((u32)d[4]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L5364;
L5364: /* beq $536e */
VSTEP(0x5364ul);
if(fz)goto L536e;
goto L5366;
L5366: /* subq.w #1, D1 */
VSTEP(0x5366ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L5368;
L5368: /* move.w #$48, $69f6.w */
VSTEP(0x5368ul);
tv=((u16)(72L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L536e;
L536e: /* move.w D1, $69f4.w */
VSTEP(0x536eul);
tv=((u16)d[1]);
vm_vars[1742]=(u8)((u32)(tv)>>8);
vm_vars[1743]=(u8)((u32)(tv)>>0);

goto L5372;
L5372: /* bra $53c8 */
VSTEP(0x5372ul);
goto L53c8;
L5374: /* bsr $55e0 */
VSTEP(0x5374ul);
a[7]-=4;cvw32(a[7],0x5378ul);
goto L55e0;
L5378: /* move.w D4, D5 */
VSTEP(0x5378ul);
tv=((u16)d[4]);
VWORD(d[5])=(u16)(tv);

goto L537a;
L537a: /* andi.b #$3, D5 */
VSTEP(0x537aul);
tv=((u8)(3L));
tw=((u8)d[5]);
tr=tw&tv;

VBYTE(d[5])=(u8)(tr);
goto L537e;
L537e: /* move.b D5, $6350.w */
VSTEP(0x537eul);
tv=((u8)d[5]);
vm_vars[42]=(u8)((u32)(tv)>>0);

goto L5382;
L5382: /* moveq #$1, D5 */
VSTEP(0x5382ul);
v=((u32)(1L));
d[5]=v;

goto L5384;
L5384: /* asr.w #1, D4 */
VSTEP(0x5384ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);
VWORD(d[4])=(u16)(tr);
goto L5386;
L5386: /* bcs $5314 */
VSTEP(0x5386ul);
if(fc)goto L5314;
goto L5388;
L5388: /* moveq #-$1, D5 */
VSTEP(0x5388ul);
v=((u32)(-1L));
d[5]=v;

goto L538a;
L538a: /* asr.w #1, D4 */
VSTEP(0x538aul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);
VWORD(d[4])=(u16)(tr);
goto L538c;
L538c: /* bcs $5314 */
VSTEP(0x538cul);
if(fc)goto L5314;
goto L538e;
L538e: /* asr.w #1, D4 */
VSTEP(0x538eul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);
VWORD(d[4])=(u16)(tr);
goto L5390;
L5390: /* bcc $53a6 */
VSTEP(0x5390ul);
if(!fc)goto L53a6;
goto L5392;
L5392: /* move.w #$28, $69f6.w */
VSTEP(0x5392ul);
tv=((u16)(40L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L5398;
L5398: /* cmpi.b #$5f, D2 */
VSTEP(0x5398ul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L539c;
L539c: /* bcs $5406 */
VSTEP(0x539cul);
if(fc)goto L5406;
goto L53a0;
L53a0: /* addq.w #1, $69f4.w */
VSTEP(0x53a0ul);
tv=((u16)(1L));
eb=0x69f4ul;
tw=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tr=tw+tv;
vm_vars[1742]=(u8)((u32)(tr)>>8);
vm_vars[1743]=(u8)((u32)(tr)>>0);
goto L53a4;
L53a4: /* bra $53c8 */
VSTEP(0x53a4ul);
goto L53c8;
L53a6: /* asr.w #1, D4 */
VSTEP(0x53a6ul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((s16)tw)>>1;fc=(u8)((tw>>0)&1);fx=(u8)((tw>>0)&1);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=0;
VWORD(d[4])=(u16)(tr);
goto L53a8;
L53a8: /* bcc $5404 */
VSTEP(0x53a8ul);
if(!fc)goto L5404;
goto L53aa;
L53aa: /* move.w #$48, $69f6.w */
VSTEP(0x53aaul);
tv=((u16)(72L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L53b0;
L53b0: /* move.w $8002.l, D5 */
VSTEP(0x53b0ul);
ea=0x8002ul;
tv=88u;
VWORD(d[5])=(u16)(tv);

goto L53b6;
L53b6: /* sub.w D5, D3 */
VSTEP(0x53b6ul);
tv=((u16)d[5]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L53b8;
L53b8: /* move.b (A0,D3.w), D2 */
VSTEP(0x53b8ul);
ea=(a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L53bc;
L53bc: /* cmpi.b #$5f, D2 */
VSTEP(0x53bcul);
tv=((u8)(95L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L53c0;
L53c0: /* bcs $5406 */
VSTEP(0x53c0ul);
if(fc)goto L5406;
goto L53c2;
L53c2: /* subq.w #1, D1 */
VSTEP(0x53c2ul);
tv=((u16)(1L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L53c4;
L53c4: /* move.w D1, $69f4.w */
VSTEP(0x53c4ul);
tv=((u16)d[1]);
vm_vars[1742]=(u8)((u32)(tv)>>8);
vm_vars[1743]=(u8)((u32)(tv)>>0);

goto L53c8;
L53c8: /* moveq #$31, D3 */
VSTEP(0x53c8ul);
v=((u32)(49L));
d[3]=v;

goto L53ca;
L53ca: /* btst #$3, $6350.w */
VSTEP(0x53caul);
v=((u16)(3L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L53d0;
L53d0: /* bne $53dc */
VSTEP(0x53d0ul);
if(!fz)goto L53dc;
goto L53d2;
L53d2: /* addq.w #5, D3 */
VSTEP(0x53d2ul);
tv=((u16)(5L));
tw=((u16)d[3]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[3])=(u16)(tr);
goto L53d4;
L53d4: /* btst #$2, $6350.w */
VSTEP(0x53d4ul);
v=((u16)(2L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L53da;
L53da: /* beq $5404 */
VSTEP(0x53daul);
if(fz)goto L5404;
goto L53dc;
L53dc: /* move.w $69ee.w, D2 */
VSTEP(0x53dcul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
VWORD(d[2])=(u16)(tv);

goto L53e0;
L53e0: /* add.w $69f4.w, D2 */
VSTEP(0x53e0ul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L53e4;
L53e4: /* addq.w #2, D2 */
VSTEP(0x53e4ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L53e6;
L53e6: /* not.w D2 */
VSTEP(0x53e6ul);
tv=((u16)d[2]);
tr=~tv;
VWORD(d[2])=(u16)(tr);

goto L53e8;
L53e8: /* andi.w #$7, D2 */
VSTEP(0x53e8ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L53ec;
L53ec: /* bclr #$2, D2 */
VSTEP(0x53ecul);
v=((u16)(2L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L53f0;
L53f0: /* beq $53f6 */
VSTEP(0x53f0ul);
if(fz)goto L53f6;
goto L53f2;
L53f2: /* addi.w #-$2000, D3 */
VSTEP(0x53f2ul);
tv=((u16)(-8192L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L53f6;
L53f6: /* addq.w #1, D2 */
VSTEP(0x53f6ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L53f8;
L53f8: /* add.w D3, D2 */
VSTEP(0x53f8ul);
tv=((u16)d[3]);
tw=((u16)d[2]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L53fa;
L53fa: /* lea $6332.w, A0 */
VSTEP(0x53faul);
a[0]=0x6332ul;
goto L53fe;
L53fe: /* clr.w (A0)+ */
VSTEP(0x53feul);
ea=a[0];
cvw16(ea,0);
a[0]+=2;

goto L5400;
L5400: /* move.w D2, (A0)+ */
VSTEP(0x5400ul);
tv=((u16)d[2]);
ea=a[0];
cvw16(ea,tv);
a[0]+=2;

goto L5402;
L5402: /* move.w D3, (A0) */
VSTEP(0x5402ul);
tv=((u16)d[3]);
ea=a[0];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5404;
L5404: /* rts  */
VSTEP(0x5404ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5406: /* move.w #$4c7c, $3c7c.w */
VSTEP(0x5406ul);
tv=((u16)(19580L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L540c;
L540c: /* rts  */
VSTEP(0x540cul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L540e: /* addi.w #$8, D1 */
VSTEP(0x540eul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5412;
L5412: /* bsr $55e0 */
VSTEP(0x5412ul);
a[7]-=4;cvw32(a[7],0x5416ul);
goto L55e0;
L5416: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x5416ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L541c;
L541c: /* cmpi.b #$3, D2 */
VSTEP(0x541cul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5420;
L5420: /* bcs $542c */
VSTEP(0x5420ul);
if(fc)goto L542c;
goto L5422;
L5422: /* move.w #$8000, $5546.w */
VSTEP(0x5422ul);
tv=((u16)(32768L));
ea=0x5546ul;
cvw16(ea,tv);

goto L5428;
L5428: /* bra $5492 */
VSTEP(0x5428ul);
goto L5492;
L542c: /* bsr $5220 */
VSTEP(0x542cul);
a[7]-=4;cvw32(a[7],0x5430ul);
goto L5220;
L5430: /* lea $641e.w, A0 */
VSTEP(0x5430ul);
a[0]=0x641eul;
goto L5434;
L5434: /* bsr $5470 */
VSTEP(0x5434ul);
a[7]-=4;cvw32(a[7],0x5436ul);
goto L5470;
L5436: /* move.w #$543e, $3c7c.w */
VSTEP(0x5436ul);
tv=((u16)(21566L));
vm_player_state=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L543c;
L543c: /* rts  */
VSTEP(0x543cul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L543e: /* lea $6421.w, A0 */
VSTEP(0x543eul);
a[0]=0x6421ul;
goto L5442;
L5442: /* bsr $5470 */
VSTEP(0x5442ul);
a[7]-=4;cvw32(a[7],0x5444ul);
goto L5470;
L5444: /* btst #$2, $6350.w */
VSTEP(0x5444ul);
v=((u16)(2L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L544a;
L544a: /* bne $5458 */
VSTEP(0x544aul);
if(!fz)goto L5458;
goto L544c;
L544c: /* move.w #$5462, $3c7c.w */
VSTEP(0x544cul);
tv=((u16)(21602L));
vm_player_state=(u16)(tv);

goto L5452;
L5452: /* lea $641e.w, A0 */
VSTEP(0x5452ul);
a[0]=0x641eul;
goto L5456;
L5456: /* bra $5470 */
VSTEP(0x5456ul);
goto L5470;
L5458: /* btst #$4, $6350.w */
VSTEP(0x5458ul);
v=((u16)(4L));
eb=0x6350ul;
w=(((u8)vm_vars[42]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L545e;
L545e: /* bne $540e */
VSTEP(0x545eul);
if(!fz)goto L540e;
goto L5460;
L5460: /* rts  */
VSTEP(0x5460ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5462: /* move.w #$4c7c, $3c7c.w */
VSTEP(0x5462ul);
tv=((u16)(19580L));
vm_player_state=(u16)(tv);

goto L5468;
L5468: /* lea $641b.w, A0 */
VSTEP(0x5468ul);
a[0]=0x641bul;
goto L546c;
L546c: /* bra $5470 */
VSTEP(0x546cul);
goto L5470;
L5470: /* move.w D7, -(A7) */
VSTEP(0x5470ul);
tv=((u16)d[7]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);

goto L5472;
L5472: /* lea $6336.w, A1 */
VSTEP(0x5472ul);
a[1]=0x6336ul;
goto L5476;
L5476: /* move.w (A1), D7 */
VSTEP(0x5476ul);
ea=a[1];
tv=cvr16(ea);
VWORD(d[7])=(u16)(tv);

goto L5478;
L5478: /* andi.w #$e000, D7 */
VSTEP(0x5478ul);
tv=((u16)(57344L));
tw=((u16)d[7]);
tr=tw&tv;

VWORD(d[7])=(u16)(tr);
goto L547c;
L547c: /* add.b (A0)+, D7 */
VSTEP(0x547cul);
ea=a[0];
tv=cvr8(ea);
a[0]+=1;
tw=((u8)d[7]);
tr=tw+tv;
VBYTE(d[7])=(u8)(tr);
goto L547e;
L547e: /* move.w D7, (A1) */
VSTEP(0x547eul);
tv=((u16)d[7]);
ea=a[1];
cvw16(ea,tv);

goto L5480;
L5480: /* add.b (A0)+, D7 */
VSTEP(0x5480ul);
ea=a[0];
tv=cvr8(ea);
a[0]+=1;
tw=((u8)d[7]);
tr=tw+tv;
VBYTE(d[7])=(u8)(tr);
goto L5482;
L5482: /* move.w D7, -(A1) */
VSTEP(0x5482ul);
tv=((u16)d[7]);
a[1]-=2;
ea=a[1];
cvw16(ea,tv);

goto L5484;
L5484: /* add.b (A0)+, D7 */
VSTEP(0x5484ul);
ea=a[0];
tv=cvr8(ea);
a[0]+=1;
tw=((u8)d[7]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[7])=(u8)(tr);
goto L5486;
L5486: /* move.w D7, -(A1) */
VSTEP(0x5486ul);
tv=((u16)d[7]);
a[1]-=2;
ea=a[1];
cvw16(ea,tv);

goto L5488;
L5488: /* move.w (A7)+, D7 */
VSTEP(0x5488ul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[7])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L548a;
L548a: /* rts  */
VSTEP(0x548aul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5492: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x5492ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L5498;
L5498: /* clr.l $633c.w */
VSTEP(0x5498ul);
vm_vars[22]=(u8)((u32)(0)>>24);
vm_vars[23]=(u8)((u32)(0)>>16);
vm_vars[24]=(u8)((u32)(0)>>8);
vm_vars[25]=(u8)((u32)(0)>>0);

goto L549c;
L549c: /* move.w $69f4.w, $69f6.w */
VSTEP(0x549cul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L54a2;
L54a2: /* lea (-$18,PC), A0 */
VSTEP(0x54a2ul);
a[0]=(-24+0x54a4ul);
goto L54a6;
L54a6: /* bsr $5470 */
VSTEP(0x54a6ul);
a[7]-=4;cvw32(a[7],0x54aaul);
goto L5470;
L54aa: /* move.w #$54ba, $3c7c.w */
VSTEP(0x54aaul);
tv=((u16)(21690L));
vm_player_state=(u16)(tv);

goto L54b0;
L54b0: /* move.w #$ffff, $6342.w */
VSTEP(0x54b0ul);
tv=((u16)(65535L));
vm_vars[28]=(u8)((u32)(tv)>>8);
vm_vars[29]=(u8)((u32)(tv)>>0);

goto L54b6;
L54b6: /* clr.w $6340.w */
VSTEP(0x54b6ul);
vm_vars[26]=(u8)((u32)(0)>>8);
vm_vars[27]=(u8)((u32)(0)>>0);

goto L54ba;
L54ba: /* movem.w $633c.w, D4-D5 */
VSTEP(0x54baul);
ea=0x633cul;
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+22u));
d[5]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+24u));
goto L54c0;
L54c0: /* move.w D4, $6356.w */
VSTEP(0x54c0ul);
tv=((u16)d[4]);
vm_vars[48]=(u8)((u32)(tv)>>8);
vm_vars[49]=(u8)((u32)(tv)>>0);
fz=(u8)((tv&0xfffful)==0);
goto L54c4;
L54c4: /* beq $5504 */
VSTEP(0x54c4ul);
if(fz)goto L5504;
goto L54c6;
L54c6: /* subi.w #$10, D1 */
VSTEP(0x54c6ul);
tv=((u16)(16L));
tw=((u16)d[1]);
tr=tw-tv;
VWORD(d[1])=(u16)(tr);
goto L54ca;
L54ca: /* subq.w #4, D0 */
VSTEP(0x54caul);
tv=((u16)(4L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L54cc;
L54cc: /* add.w D4, D0 */
VSTEP(0x54ccul);
tv=((u16)d[4]);
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L54ce;
L54ce: /* bsr $55e0 */
VSTEP(0x54ceul);
a[7]-=4;cvw32(a[7],0x54d2ul);
goto L55e0;
L54d2: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x54d2ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L54d8;
L54d8: /* moveq #$1, D7 */
VSTEP(0x54d8ul);
v=((u32)(1L));
d[7]=v;

goto L54da;
L54da: /* cmpi.b #$3, D2 */
VSTEP(0x54daul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L54de;
L54de: /* bcs $5500 */
VSTEP(0x54deul);
if(fc)goto L5500;
goto L54e0;
L54e0: /* move.b ($1,A0,D3.w), D2 */
VSTEP(0x54e0ul);
ea=(1+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L54e4;
L54e4: /* cmpi.b #$3, D2 */
VSTEP(0x54e4ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L54e8;
L54e8: /* bcs $5500 */
VSTEP(0x54e8ul);
if(fc)goto L5500;
goto L54ea;
L54ea: /* add.w $8002.l, D3 */
VSTEP(0x54eaul);
ea=0x8002ul;
tv=88u;
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L54f0;
L54f0: /* move.b (A0,D3.w), D2 */
VSTEP(0x54f0ul);
ea=(a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L54f4;
L54f4: /* dbra D7, $54da */
VSTEP(0x54f4ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L54da;
goto L54f8;
L54f8: /* add.w D0, D4 */
VSTEP(0x54f8ul);
tv=((u16)d[0]);
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L54fa;
L54fa: /* move.w D4, $69f2.w */
VSTEP(0x54faul);
tv=((u16)d[4]);
vm_vars[1740]=(u8)((u32)(tv)>>8);
vm_vars[1741]=(u8)((u32)(tv)>>0);

goto L54fe;
L54fe: /* bra $5504 */
VSTEP(0x54feul);
goto L5504;
L5500: /* clr.w $633c.w */
VSTEP(0x5500ul);
vm_vars[22]=(u8)((u32)(0)>>8);
vm_vars[23]=(u8)((u32)(0)>>0);

goto L5504;
L5504: /* cmpi.w #$10, D5 */
VSTEP(0x5504ul);
tv=((u16)(16L));
tw=((u16)d[5]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5508;
L5508: /* bpl $550c */
VSTEP(0x5508ul);
if(!fn)goto L550c;
goto L550a;
L550a: /* addq.w #1, D5 */
VSTEP(0x550aul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L550c;
L550c: /* move.w D5, $633e.w */
VSTEP(0x550cul);
tv=((u16)d[5]);
vm_vars[24]=(u8)((u32)(tv)>>8);
vm_vars[25]=(u8)((u32)(tv)>>0);

goto L5510;
L5510: /* asr.w #2, D5 */
VSTEP(0x5510ul);
tv=((u16)(2L));
tw=((u16)d[5]);
tr=((s16)tw)>>2;
VWORD(d[5])=(u16)(tr);
goto L5512;
L5512: /* add.w D5, D1 */
VSTEP(0x5512ul);
tv=((u16)d[5]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L5514;
L5514: /* move.w D1, $69f4.w */
VSTEP(0x5514ul);
tv=((u16)d[1]);
vm_vars[1742]=(u8)((u32)(tv)>>8);
vm_vars[1743]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fv=0;fc=0;
goto L5518;
L5518: /* btst #$f, D1 */
VSTEP(0x5518ul);
v=((u16)(15L));
w=((u32)d[1]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
goto L551c;
L551c: /* beq $5520 */
VSTEP(0x551cul);
if(fz)goto L5520;
goto L551e;
L551e: /* rts  */
VSTEP(0x551eul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5520: /* bsr $55e0 */
VSTEP(0x5520ul);
a[7]-=4;cvw32(a[7],0x5524ul);
goto L55e0;
L5524: /* cmpi.b #$3, D2 */
VSTEP(0x5524ul);
tv=((u8)(3L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5528;
L5528: /* bcc $5536 */
VSTEP(0x5528ul);
if(!fc)goto L5536;
goto L552a;
L552a: /* subq.w #7, $69f4.w */
VSTEP(0x552aul);
tv=((u16)(7L));
eb=0x69f4ul;
tw=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tr=tw-tv;
vm_vars[1742]=(u8)((u32)(tr)>>8);
vm_vars[1743]=(u8)((u32)(tr)>>0);
goto L552e;
L552e: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x552eul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L5534;
L5534: /* bra $54ba */
VSTEP(0x5534ul);
goto L54ba;
L5536: /* subi.b #$50, D2 */
VSTEP(0x5536ul);
tv=((u8)(80L));
tw=((u8)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);fz=(u8)((tr&0xfful)==0);
VBYTE(d[2])=(u8)(tr);
goto L553a;
L553a: /* bne $5542 */
VSTEP(0x553aul);
if(!fz)goto L5542;
goto L553c;
L553c: /* move.w #$70, $6340.w */
VSTEP(0x553cul);
tv=((u16)(112L));
vm_vars[26]=(u8)((u32)(tv)>>8);
vm_vars[27]=(u8)((u32)(tv)>>0);

goto L5542;
L5542: /* cmpi.b #$11, D2 */
VSTEP(0x5542ul);
tv=((u8)(17L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5546;
L5546: /* nop  */
VSTEP(0x5546ul);
if(vm_platform_opcode==0x8000u)vnz(d[0],8);
goto L5548;
L5548: /* move SR, D6 */
VSTEP(0x5548ul);
v=(0x2000u|(fx<<4)|(fn<<3)|(fz<<2)|(fv<<1)|fc);
VWORD(d[6])=(u16)(v);

goto L554a;
L554a: /* add.w $6340.w, D5 */
VSTEP(0x554aul);
ea=0x6340ul;
tv=(((u16)vm_vars[26]<<8)|((u16)vm_vars[27]<<0));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L554e;
L554e: /* move.w D5, $6340.w */
VSTEP(0x554eul);
tv=((u16)d[5]);
vm_vars[26]=(u8)((u32)(tv)>>8);
vm_vars[27]=(u8)((u32)(tv)>>0);

goto L5552;
L5552: /* cmpi.w #$8, D5 */
VSTEP(0x5552ul);
tv=((u16)(8L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L5556;
L5556: /* bcs $555e */
VSTEP(0x5556ul);
if(fc)goto L555e;
goto L5558;
L5558: /* move.w #$4e71, $5546.w */
VSTEP(0x5558ul);
tv=((u16)(20081L));
ea=0x5546ul;
cvw16(ea,tv);

goto L555e;
L555e: /* move D6, SR */
VSTEP(0x555eul);
v=((u16)d[6]);
fx=(v>>4)&1;fn=(v>>3)&1;fz=(v>>2)&1;fv=(v>>1)&1;fc=v&1;
goto L5560;
L5560: /* bcc $551e */
VSTEP(0x5560ul);
if(!fc)goto L551e;
goto L5562;
L5562: /* move.w #$28, $69f6.w */
VSTEP(0x5562ul);
tv=((u16)(40L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5568;
L5568: /* lea $548f.w, A0 */
VSTEP(0x5568ul);
a[0]=0x548ful;
goto L556c;
L556c: /* bsr $5470 */
VSTEP(0x556cul);
a[7]-=4;cvw32(a[7],0x5570ul);
goto L5470;
L5570: /* move.l #$559a, $3c7a.w */
VSTEP(0x5570ul);
v=((u32)(21914L));
ea=0x3c7aul;
cvw32(ea,v);

goto L5578;
L5578: /* clr.w $633e.w */
VSTEP(0x5578ul);
vm_vars[24]=(u8)((u32)(0)>>8);
vm_vars[25]=(u8)((u32)(0)>>0);

goto L557c;
L557c: /* move.w #$1, $6342.w */
VSTEP(0x557cul);
tv=((u16)(1L));
vm_vars[28]=(u8)((u32)(tv)>>8);
vm_vars[29]=(u8)((u32)(tv)>>0);

goto L5582;
L5582: /* move.w #$2, $633a.w */
VSTEP(0x5582ul);
tv=((u16)(2L));
vm_vars[20]=(u8)((u32)(tv)>>8);
vm_vars[21]=(u8)((u32)(tv)>>0);

goto L5588;
L5588: /* move.w $69ee.w, D0 */
VSTEP(0x5588ul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
VWORD(d[0])=(u16)(tv);

goto L558c;
L558c: /* add.w D1, D0 */
VSTEP(0x558cul);
tv=((u16)d[1]);
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L558e;
L558e: /* andi.w #$7, D0 */
VSTEP(0x558eul);
tv=((u16)(7L));
tw=((u16)d[0]);
tr=tw&tv;

VWORD(d[0])=(u16)(tr);
goto L5592;
L5592: /* sub.w D0, D1 */
VSTEP(0x5592ul);
tv=((u16)d[0]);
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[1])=(u16)(tr);
goto L5594;
L5594: /* move.w D1, $69f4.w */
VSTEP(0x5594ul);
tv=((u16)d[1]);
vm_vars[1742]=(u8)((u32)(tv)>>8);
vm_vars[1743]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5598;
L5598: /* rts  */
VSTEP(0x5598ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L559a: /* subq.w #1, $633a.w */
VSTEP(0x559aul);
tv=((u16)(1L));
eb=0x633aul;
tw=(((u16)vm_vars[20]<<8)|((u16)vm_vars[21]<<0));
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
vm_vars[20]=(u8)((u32)(tr)>>8);
vm_vars[21]=(u8)((u32)(tr)>>0);
goto L559e;
L559e: /* bne $5598 */
VSTEP(0x559eul);
if(!fz)goto L5598;
goto L55a0;
L55a0: /* tst.b $7c874.l */
VSTEP(0x55a0ul);
ea=0x7c874ul;
tv=cvr8(ea);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L55a6;
L55a6: /* bne $4dc0 */
VSTEP(0x55a6ul);
if(!fz)goto L4dc0;
goto L55aa;
L55aa: /* move.l #$4c7c, $3c7a.w */
VSTEP(0x55aaul);
v=((u32)(19580L));
ea=0x3c7aul;
cvw32(ea,v);

goto L55b2;
L55b2: /* lea $641b.w, A0 */
VSTEP(0x55b2ul);
a[0]=0x641bul;
goto L55b6;
L55b6: /* cmpi.w #$50, $6340.w */
VSTEP(0x55b6ul);
tv=((u16)(80L));
eb=0x6340ul;
tw=(((u16)vm_vars[26]<<8)|((u16)vm_vars[27]<<0));
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L55bc;
L55bc: /* bmi $5470 */
VSTEP(0x55bcul);
if(fn)goto L5470;
goto L55c0;
L55c0: /* moveq #$5a, D6 */
VSTEP(0x55c0ul);
v=((u32)(90L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L55c2;
L55c2: /* bsr $4d0a */
VSTEP(0x55c2ul);
a[7]-=4;cvw32(a[7],0x55c6ul);
goto L4d0a;
L55c6: /* move.b #$4, $7c874.l */
VSTEP(0x55c6ul);
tv=((u8)(4L));
ea=0x7c874ul;
cvw8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fv=0;fc=0;
goto L55ce;
L55ce: /* btst #$7, $7c875.l */
VSTEP(0x55ceul);
v=((u16)(7L));
eb=0x7c875ul;
w=cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L55d6;
L55d6: /* bne $55de */
VSTEP(0x55d6ul);
if(!fz)goto L55de;
goto L55d8;
L55d8: /* jmp $7c862.l */
VSTEP(0x55d8ul);
goto L7c862;
L55de: /* rts  */
VSTEP(0x55deul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L55e0:
v=(u16)((u16)(((u16)vm_vars[0x6c6]<<8)|vm_vars[0x6c7])+(u16)d[0]);
w=(u16)((u16)(((u16)vm_vars[0x6c8]<<8)|vm_vars[0x6c9])+(u16)d[1]);
v>>=3;w>>=3;w=(w<<6)+(w<<4)+(w<<3);r=(u16)w+v;fx=(u8)(r>65535ul);
d[3]=(w&0xffff0000ul)|(u16)r;a[0]=0x807cul;
d[2]=(u16)d[3]<17864u?cat_map_read((u16)d[3]):cvr8(a[0]+(s16)d[3]);fn=(u8)((d[2]&128ul)!=0);fz=(u8)(d[2]==0);fc=fv=0;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L55e6: /* add.w D0, D2 */
VSTEP(0x55e6ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L55e8;
L55e8: /* add.w D1, D3 */
VSTEP(0x55e8ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L55ea;
L55ea: /* lsr.w #3, D2 */
VSTEP(0x55eaul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L55ec;
L55ec: /* lsr.w #3, D3 */
VSTEP(0x55ecul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=((u16)tw)>>3;
VWORD(d[3])=(u16)(tr);
goto L55ee;
L55ee: /* mulu.w $8002.l, D3 */
VSTEP(0x55eeul);
ea=0x8002ul;
v=88u;
w=((u32)d[3]);
r=(u32)(u16)v*(u16)w;

d[3]=r;
goto L55f4;
L55f4: /* add.w D2, D3 */
VSTEP(0x55f4ul);
tv=((u16)d[2]);
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[3])=(u16)(tr);
goto L55f6;
L55f6: /* lea $807c.l, A0 */
VSTEP(0x55f6ul);
a[0]=0x807cul;
goto L55fc;
L55fc: /* clr.w D2 */
VSTEP(0x55fcul);
VWORD(d[2])=(u16)(0);

goto L55fe;
L55fe: /* move.b (A0,D3.w), D2 */
VSTEP(0x55feul);
ea=(a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5602;
L5602: /* rts  */
VSTEP(0x5602ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L56e6: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x56e6ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L56ec;
L56ec: /* move.w $6336.w, D2 */
VSTEP(0x56ecul);
ea=0x6336ul;
tv=(((u16)vm_vars[16]<<8)|((u16)vm_vars[17]<<0));
VWORD(d[2])=(u16)(tv);

goto L56f0;
L56f0: /* clr.w D4 */
VSTEP(0x56f0ul);
VWORD(d[4])=(u16)(0);

goto L56f2;
L56f2: /* move.b D2, D4 */
VSTEP(0x56f2ul);
tv=((u8)d[2]);
VBYTE(d[4])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L56f4;
L56f4: /* beq $5732 */
VSTEP(0x56f4ul);
if(fz)goto L5732;
goto L56f8;
L56f8: /* move.w D1, D3 */
VSTEP(0x56f8ul);
tv=((u16)d[1]);
VWORD(d[3])=(u16)(tv);

goto L56fa;
L56fa: /* lea $60c4.w, A0 */
VSTEP(0x56faul);
a[0]=0x60c4ul;
goto L56fe;
L56fe: /* add.w D4, D4 */
VSTEP(0x56feul);
tv=((u16)d[4]);
tw=((u16)d[4]);
tr=tw+tv;
VWORD(d[4])=(u16)(tr);
goto L5700;
L5700: /* add.w D3, D3 */
VSTEP(0x5700ul);
tv=((u16)d[3]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5702;
L5702: /* sub.b (-$2,A0,D4.w), D3 */
VSTEP(0x5702ul);
ea=(-2+a[0]+((s16)(d[4])));
tv=cvr8(ea);
tw=((u8)d[3]);
tr=tw-tv;
VBYTE(d[3])=(u8)(tr);
goto L5706;
L5706: /* asr.w #1, D3 */
VSTEP(0x5706ul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=((s16)tw)>>1;fx=(u8)((tw>>0)&1);
VWORD(d[3])=(u16)(tr);
goto L5708;
L5708: /* move.w D3, $6338.w */
VSTEP(0x5708ul);
tv=((u16)d[3]);
vm_vars[18]=(u8)((u32)(tv)>>8);
vm_vars[19]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L570c;
L570c: /* bsr $5734 */
VSTEP(0x570cul);
a[7]-=4;cvw32(a[7],0x570eul);
goto L5734;
L570e: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x570eul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L5714;
L5714: /* move.w $6334.w, D2 */
VSTEP(0x5714ul);
ea=0x6334ul;
tv=(((u16)vm_vars[14]<<8)|((u16)vm_vars[15]<<0));
VWORD(d[2])=(u16)(tv);

goto L5718;
L5718: /* move.b D2, D2 */
VSTEP(0x5718ul);
tv=((u8)d[2]);
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L571a;
L571a: /* beq $5732 */
VSTEP(0x571aul);
if(fz)goto L5732;
goto L571e;
L571e: /* bsr $5734 */
VSTEP(0x571eul);
a[7]-=4;cvw32(a[7],0x5720ul);
goto L5734;
L5720: /* movem.w $69f2.w, D0-D1 */
VSTEP(0x5720ul);
ea=0x69f2ul;
d[0]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[1]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L5726;
L5726: /* move.w $6332.w, D2 */
VSTEP(0x5726ul);
ea=0x6332ul;
tv=(((u16)vm_vars[12]<<8)|((u16)vm_vars[13]<<0));
VWORD(d[2])=(u16)(tv);

goto L572a;
L572a: /* move.b D2, D2 */
VSTEP(0x572aul);
tv=((u8)d[2]);
VBYTE(d[2])=(u8)(tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L572c;
L572c: /* beq $5732 */
VSTEP(0x572cul);
if(fz)goto L5732;
goto L5730;
L5730: /* bsr $5734 */
VSTEP(0x5730ul);
a[7]-=4;cvw32(a[7],0x5732ul);
goto L5734;
L5732: /* rts  */
VSTEP(0x5732ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L58ea: /* clr.l D0 */
VSTEP(0x58eaul);
d[0]=0;

goto L58ec;
L58ec: /* move.w $69ec.w, D0 */
VSTEP(0x58ecul);
ea=0x69ecul;
tv=(((u16)vm_vars[1734]<<8)|((u16)vm_vars[1735]<<0));
VWORD(d[0])=(u16)(tv);

goto L58f0;
L58f0: /* lsr.w #3, D0 */
VSTEP(0x58f0ul);
tv=((u16)(3L));
tw=((u16)d[0]);
tr=((u16)tw)>>3;
VWORD(d[0])=(u16)(tr);
goto L58f2;
L58f2: /* add.w D0, D0 */
VSTEP(0x58f2ul);
tv=((u16)d[0]);
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L58f4;
L58f4: /* movea.l #$5a36c, A4 */
VSTEP(0x58f4ul);
v=((u32)(369516L));
a[4]=v;
goto L58fa;
L58fa: /* adda.l D0, A4 */
VSTEP(0x58faul);
v=((u32)d[0]);
w=((u32)a[4]);
r=w+v;
a[4]=r;
goto L58fc;
L58fc: /* move.l A4, $6366.w */
VSTEP(0x58fcul);
v=((u32)a[4]);
vm_vars[64]=(u8)((u32)(v)>>24);
vm_vars[65]=(u8)((u32)(v)>>16);
vm_vars[66]=(u8)((u32)(v)>>8);
vm_vars[67]=(u8)((u32)(v)>>0);

goto L5900;
L5900: /* clr.w $635a.w */
VSTEP(0x5900ul);
vm_vars[52]=(u8)((u32)(0)>>8);
vm_vars[53]=(u8)((u32)(0)>>0);

goto L5904;
L5904: /* clr.l D1 */
VSTEP(0x5904ul);
d[1]=0;

goto L5906;
L5906: /* move.w $69ec.w, D1 */
VSTEP(0x5906ul);
ea=0x69ecul;
tv=(((u16)vm_vars[1734]<<8)|((u16)vm_vars[1735]<<0));
VWORD(d[1])=(u16)(tv);

goto L590a;
L590a: /* moveq #$14, D7 */
VSTEP(0x590aul);
v=((u32)(20L));
d[7]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L590c;
L590c: /* movem.l D1/D7/A4, -(A7) */
VSTEP(0x590cul);
a[7]-=4;
cvw32(a[7],a[4]);
a[7]-=4;
cvw32(a[7],d[7]);
a[7]-=4;
cvw32(a[7],d[1]);
goto L5910;
L5910: /* bsr $4b14 */
VSTEP(0x5910ul);
a[7]-=4;cvw32(a[7],0x5914ul);
goto L4b14;
L5914: /* movem.l (A7)+, D1/D7/A4 */
VSTEP(0x5914ul);
ea=a[7];
d[1]=cvr32(ea+0);
d[7]=cvr32(ea+4);
a[4]=cvr32(ea+8);
a[7]+=12;
goto L5918;
L5918: /* addq.w #8, D1 */
VSTEP(0x5918ul);
tv=((u16)(8L));
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L591a;
L591a: /* addq.l #2, A4 */
VSTEP(0x591aul);
v=((u32)(2L));
w=((u32)a[4]);
r=w+v;
a[4]=r;
goto L591c;
L591c: /* dbra D7, $590c */
VSTEP(0x591cul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L590c;
goto L5920;
L5920: /* rts  */
VSTEP(0x5920ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5b2c: /* moveq #$1, D0 */
VSTEP(0x5b2cul);
v=((u32)(1L));
d[0]=v;

goto L5b2e;
L5b2e: /* cmp.w $6344.w, D0 */
VSTEP(0x5b2eul);
ea=0x6344ul;
tv=(((u16)vm_vars[30]<<8)|((u16)vm_vars[31]<<0));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5b32;
L5b32: /* bcs $5b4a */
VSTEP(0x5b32ul);
if(fc)goto L5b4a;
goto L5b34;
L5b34: /* bra $5b46 */
VSTEP(0x5b34ul);
goto L5b46;
L5b36: /* moveq #$2, D0 */
VSTEP(0x5b36ul);
v=((u32)(2L));
d[0]=v;

goto L5b38;
L5b38: /* cmp.w $6344.w, D0 */
VSTEP(0x5b38ul);
ea=0x6344ul;
tv=(((u16)vm_vars[30]<<8)|((u16)vm_vars[31]<<0));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5b3c;
L5b3c: /* bcs $5b4a */
VSTEP(0x5b3cul);
if(fc)goto L5b4a;
goto L5b3e;
L5b3e: /* bra $5b46 */
VSTEP(0x5b3eul);
goto L5b46;
L5b40: /* moveq #$3, D0 */
VSTEP(0x5b40ul);
v=((u32)(3L));
d[0]=v;

goto L5b42;
L5b42: /* cmp.w $6344.w, D0 */
VSTEP(0x5b42ul);
ea=0x6344ul;
tv=(((u16)vm_vars[30]<<8)|((u16)vm_vars[31]<<0));
tw=((u16)d[0]);

goto L5b46;
L5b46: /* move.w D0, $6344.w */
VSTEP(0x5b46ul);
tv=((u16)d[0]);
vm_vars[30]=(u8)((u32)(tv)>>8);
vm_vars[31]=(u8)((u32)(tv)>>0);

goto L5b4a;
L5b4a: /* clr.w (A6) */
VSTEP(0x5b4aul);
ea=a[6];
cvw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5b4c;
L5b4c: /* rts  */
VSTEP(0x5b4cul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5b4e: /* move.w #$590, D0 */
VSTEP(0x5b4eul);
tv=((u16)(1424L));
VWORD(d[0])=(u16)(tv);

goto L5b52;
L5b52: /* sub.w $69ec.w, D0 */
VSTEP(0x5b52ul);
ea=0x69ecul;
tv=(((u16)vm_vars[1734]<<8)|((u16)vm_vars[1735]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5b56;
L5b56: /* addq.w #2, ($a,A6) */
VSTEP(0x5b56ul);
tv=((u16)(2L));
eb=(10+a[6]);
tw=cvr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
cvw16(eb,tr);
goto L5b5a;
L5b5a: /* movea.l ($8,A6), A5 */
VSTEP(0x5b5aul);
ea=(8+a[6]);
v=cvr32(ea);
a[5]=v;
goto L5b5e;
L5b5e: /* move.w (A5), D2 */
VSTEP(0x5b5eul);
ea=a[5];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5b60;
L5b60: /* bpl $45fa */
VSTEP(0x5b60ul);
if(!fn)goto L45fa;
goto L5b64;
L5b64: /* bsr $36ee */
VSTEP(0x5b64ul);
a[7]-=4;cvw32(a[7],0x5b68ul);
goto L36ee;
L5b68: /* moveq #$32, D0 */
VSTEP(0x5b68ul);
v=((u32)(50L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5b6a;
L5b6a: /* bsr $5ed4 */
VSTEP(0x5b6aul);
a[7]-=4;cvw32(a[7],0x5b6eul);
goto L5ed4;
L5b6e: /* bra $5e82 */
VSTEP(0x5b6eul);
goto L5e82;
L5ba4: /* move.w #$98, ($4,A6) */
VSTEP(0x5ba4ul);
tv=((u16)(152L));
ea=(4+a[6]);
cvw16(ea,tv);

goto L5baa;
L5baa: /* lea $39bc.w, A5 */
VSTEP(0x5baaul);
a[5]=0x39bcul;
goto L5bae;
L5bae: /* move.w #$85, D2 */
VSTEP(0x5baeul);
tv=((u16)(133L));
VWORD(d[2])=(u16)(tv);

goto L5bb2;
L5bb2: /* moveq #$9, D7 */
VSTEP(0x5bb2ul);
v=((u32)(9L));
d[7]=v;

goto L5bb4;
L5bb4: /* cmp.w ($6,A5), D2 */
VSTEP(0x5bb4ul);
ea=(6+a[5]);
tv=cvr16(ea);
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L5bb8;
L5bb8: /* beq $5bc4 */
VSTEP(0x5bb8ul);
if(fz)goto L5bc4;
goto L5bba;
L5bba: /* lea ($16,A5), A5 */
VSTEP(0x5bbaul);
a[5]=(22+a[5]);
goto L5bbe;
L5bbe: /* dbra D7, $5bb4 */
VSTEP(0x5bbeul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L5bb4;
goto L5bc2;
L5bc2: /* bra $5bc8 */
VSTEP(0x5bc2ul);
goto L5bc8;
L5bc4: /* move.w (A5), D2 */
VSTEP(0x5bc4ul);
ea=a[5];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5bc6;
L5bc6: /* bne $5bd4 */
VSTEP(0x5bc6ul);
if(!fz)goto L5bd4;
goto L5bc8;
L5bc8: /* bclr #$7, $6476.l */
VSTEP(0x5bc8ul);
v=((u16)(7L));
eb=0x6476ul;
w=(((u8)vm_vars[336]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
vm_vars[336]=(u8)((u32)(r)>>0);
goto L5bd0;
L5bd0: /* clr.w (A6) */
VSTEP(0x5bd0ul);
ea=a[6];
cvw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5bd2;
L5bd2: /* rts  */
VSTEP(0x5bd2ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5bd4: /* subq.w #1, D2 */
VSTEP(0x5bd4ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5bd6;
L5bd6: /* bne $5bd2 */
VSTEP(0x5bd6ul);
if(!fz)goto L5bd2;
goto L5bd8;
L5bd8: /* jsr $48008.l */
VSTEP(0x5bd8ul);
a[7]-=4;cvw32(a[7],0x5bdeul);
goto L48008;
L5bde: /* bset #$0, $7c874.l */
VSTEP(0x5bdeul);
v=((u16)(0L));
eb=0x7c874ul;
w=cvr8(eb);
v&=7;
r=1ul<<v;fz=(w&r)==0;
r=w|r;
cvw8(eb,r);
goto L5be6;
L5be6: /* move.w #$52b6, $3c7c.w */
VSTEP(0x5be6ul);
tv=((u16)(21174L));
vm_player_state=(u16)(tv);

goto L5bec;
L5bec: /* clr.w $6342.w */
VSTEP(0x5becul);
vm_vars[28]=(u8)((u32)(0)>>8);
vm_vars[29]=(u8)((u32)(0)>>0);

goto L5bf0;
L5bf0: /* clr.w $6360.w */
VSTEP(0x5bf0ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L5bf4;
L5bf4: /* move.w ($4,A5), D0 */
VSTEP(0x5bf4ul);
ea=(4+a[5]);
tv=cvr16(ea);
VWORD(d[0])=(u16)(tv);

goto L5bf8;
L5bf8: /* cmpi.w #$d4, D0 */
VSTEP(0x5bf8ul);
tv=((u16)(212L));
tw=((u16)d[0]);
fc=(u8)((u16)tw<(u16)tv);
goto L5bfc;
L5bfc: /* bcs $5c1a */
VSTEP(0x5bfcul);
if(fc)goto L5c1a;
goto L5bfe;
L5bfe: /* move.w #$81, ($6,A5) */
VSTEP(0x5bfeul);
tv=((u16)(129L));
ea=(6+a[5]);
cvw16(ea,tv);

goto L5c04;
L5c04: /* move.l #$5b70, ($8,A5) */
VSTEP(0x5c04ul);
v=((u32)(23408L));
ea=(8+a[5]);
cvw32(ea,v);

goto L5c0c;
L5c0c: /* move.w #$19, (A5) */
VSTEP(0x5c0cul);
tv=((u16)(25L));
ea=a[5];
cvw16(ea,tv);

goto L5c10;
L5c10: /* clr.w (A6) */
VSTEP(0x5c10ul);
ea=a[6];
cvw16(ea,0);

goto L5c12;
L5c12: /* moveq #$b, D0 */
VSTEP(0x5c12ul);
v=((u32)(11L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5c14;
L5c14: /* jmp $48014.l */
VSTEP(0x5c14ul);
goto L48014;
L5c1a: /* subq.w #1, $69f8.w */
VSTEP(0x5c1aul);
tv=((u16)(1L));
eb=0x69f8ul;
tw=(((u16)vm_vars[1746]<<8)|((u16)vm_vars[1747]<<0));
tr=tw-tv;
vm_vars[1746]=(u8)((u32)(tr)>>8);
vm_vars[1747]=(u8)((u32)(tr)>>0);
goto L5c1e;
L5c1e: /* subi.w #$18, D0 */
VSTEP(0x5c1eul);
tv=((u16)(24L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5c22;
L5c22: /* sub.w $69ee.w, D0 */
VSTEP(0x5c22ul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L5c26;
L5c26: /* neg.w D0 */
VSTEP(0x5c26ul);
tv=((u16)d[0]);
tr=0-tv;
VWORD(d[0])=(u16)(tr);
goto L5c28;
L5c28: /* add.w $69f4.w, D0 */
VSTEP(0x5c28ul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5c2c;
L5c2c: /* move.w D0, $69f6.w */
VSTEP(0x5c2cul);
tv=((u16)d[0]);
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5c30;
L5c30: /* rts  */
VSTEP(0x5c30ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5c32: /* bsr $5c68 */
VSTEP(0x5c32ul);
a[7]-=4;cvw32(a[7],0x5c34ul);
goto L5c68;
L5c34: /* cmpi.w #$8, D2 */
VSTEP(0x5c34ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c38;
L5c38: /* bcc $5c30 */
VSTEP(0x5c38ul);
if(!fc)goto L5c30;
goto L5c3a;
L5c3a: /* cmpi.w #$4, D2 */
VSTEP(0x5c3aul);
tv=((u16)(4L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c3e;
L5c3e: /* bne $45fa */
VSTEP(0x5c3eul);
if(!fz)goto L45fa;
goto L5c42;
L5c42: /* bsr $5c96 */
VSTEP(0x5c42ul);
a[7]-=4;cvw32(a[7],0x5c44ul);
goto L5c96;
L5c44: /* moveq #$4, D2 */
VSTEP(0x5c44ul);
v=((u32)(4L));
d[2]=v;

goto L5c46;
L5c46: /* bra $45fa */
VSTEP(0x5c46ul);
goto L45fa;
L5c4a: /* bsr $5c68 */
VSTEP(0x5c4aul);
a[7]-=4;cvw32(a[7],0x5c4cul);
goto L5c68;
L5c4c: /* ori.w #$e000, D2 */
VSTEP(0x5c4cul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw|tv;

VWORD(d[2])=(u16)(tr);
goto L5c50;
L5c50: /* cmpi.w #-$1ff8, D2 */
VSTEP(0x5c50ul);
tv=((u16)(-8184L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c54;
L5c54: /* bcc $5c30 */
VSTEP(0x5c54ul);
if(!fc)goto L5c30;
goto L5c56;
L5c56: /* cmpi.w #-$1ffc, D2 */
VSTEP(0x5c56ul);
tv=((u16)(-8188L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c5a;
L5c5a: /* bne $45fa */
VSTEP(0x5c5aul);
if(!fz)goto L45fa;
goto L5c5e;
L5c5e: /* bsr $5c8a */
VSTEP(0x5c5eul);
a[7]-=4;cvw32(a[7],0x5c60ul);
goto L5c8a;
L5c60: /* move.w #$e004, D2 */
VSTEP(0x5c60ul);
tv=((u16)(57348L));
VWORD(d[2])=(u16)(tv);

goto L5c64;
L5c64: /* bra $45fa */
VSTEP(0x5c64ul);
goto L45fa;
L5c68: /* clr.w D2 */
VSTEP(0x5c68ul);
VWORD(d[2])=(u16)(0);

goto L5c6a;
L5c6a: /* move.w ($8,A6), D2 */
VSTEP(0x5c6aul);
ea=(8+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L5c6e;
L5c6e: /* addq.b #4, D2 */
VSTEP(0x5c6eul);
tv=((u8)(4L));
tw=((u8)d[2]);
tr=tw+tv;fc=(u8)((tr&~0xfful)!=0);fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[2])=(u8)(tr);
goto L5c70;
L5c70: /* bcc $5c7a */
VSTEP(0x5c70ul);
if(!fc)goto L5c7a;
goto L5c72;
L5c72: /* moveq #$6, D2 */
VSTEP(0x5c72ul);
v=((u32)(6L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5c74;
L5c74: /* bsr $44f4 */
VSTEP(0x5c74ul);
a[7]-=4;cvw32(a[7],0x5c78ul);
goto L44f4;
L5c78: /* clr.w D2 */
VSTEP(0x5c78ul);
VWORD(d[2])=(u16)(0);

goto L5c7a;
L5c7a: /* move.w D2, ($8,A6) */
VSTEP(0x5c7aul);
tv=((u16)d[2]);
ea=(8+a[6]);
cvw16(ea,tv);

goto L5c7e;
L5c7e: /* cmpi.w #$37, D2 */
VSTEP(0x5c7eul);
tv=((u16)(55L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5c82;
L5c82: /* bcc $5c88 */
VSTEP(0x5c82ul);
if(!fc)goto L5c88;
goto L5c84;
L5c84: /* lsr.w #3, D2 */
VSTEP(0x5c84ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;
VWORD(d[2])=(u16)(tr);
goto L5c86;
L5c86: /* addq.w #1, D2 */
VSTEP(0x5c86ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5c88;
L5c88: /* rts  */
VSTEP(0x5c88ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5c8a: /* movem.w $69f2.w, D3-D4 */
VSTEP(0x5c8aul);
ea=0x69f2ul;
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L5c90;
L5c90: /* addi.w #$10, D3 */
VSTEP(0x5c90ul);
tv=((u16)(16L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5c94;
L5c94: /* bra $5c9e */
VSTEP(0x5c94ul);
goto L5c9e;
L5c96: /* movem.w $69f2.w, D3-D4 */
VSTEP(0x5c96ul);
ea=0x69f2ul;
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[4]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L5c9c;
L5c9c: /* addq.w #4, D3 */
VSTEP(0x5c9cul);
tv=((u16)(4L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5c9e;
L5c9e: /* sub.w D0, D3 */
VSTEP(0x5c9eul);
tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L5ca0;
L5ca0: /* cmpi.w #$16, D3 */
VSTEP(0x5ca0ul);
tv=((u16)(22L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5ca4;
L5ca4: /* bcc $5c88 */
VSTEP(0x5ca4ul);
if(!fc)goto L5c88;
goto L5ca6;
L5ca6: /* cmp.w D1, D4 */
VSTEP(0x5ca6ul);
tv=((u16)d[1]);
tw=((u16)d[4]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5ca8;
L5ca8: /* bmi $5c88 */
VSTEP(0x5ca8ul);
if(fn)goto L5c88;
goto L5caa;
L5caa: /* cmp.w $6338.w, D1 */
VSTEP(0x5caaul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5cae;
L5cae: /* bmi $5c88 */
VSTEP(0x5caeul);
if(fn)goto L5c88;
goto L5cb0;
L5cb0: /* moveq #$3, D6 */
VSTEP(0x5cb0ul);
v=((u32)(3L));
d[6]=v;

goto L5cb2;
L5cb2: /* bra $4d0a */
VSTEP(0x5cb2ul);
goto L4d0a;
L5cb6: /* move.w ($c,A6), D3 */
VSTEP(0x5cb6ul);
ea=(12+a[6]);
tv=cvr16(ea);
VWORD(d[3])=(u16)(tv);

goto L5cba;
L5cba: /* addq.b #6, D3 */
VSTEP(0x5cbaul);
tv=((u8)(6L));
tw=((u8)d[3]);
tr=tw+tv;fx=(u8)((tr&~0xfful)!=0);
VBYTE(d[3])=(u8)(tr);
goto L5cbc;
L5cbc: /* move.w D3, ($c,A6) */
VSTEP(0x5cbcul);
tv=((u16)d[3]);
ea=(12+a[6]);
cvw16(ea,tv);

goto L5cc0;
L5cc0: /* cmpi.b #$20, D3 */
VSTEP(0x5cc0ul);
tv=((u8)(32L));
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5cc4;
L5cc4: /* bcs $5c88 */
VSTEP(0x5cc4ul);
if(fc)goto L5c88;
goto L5cc6;
L5cc6: /* moveq #$1, D2 */
VSTEP(0x5cc6ul);
v=((u32)(1L));
d[2]=v;

goto L5cc8;
L5cc8: /* cmpi.b #$40, D3 */
VSTEP(0x5cc8ul);
tv=((u8)(64L));
tw=((u8)d[3]);
fc=(u8)((u8)tw<(u8)tv);
goto L5ccc;
L5ccc: /* bcs $45fa */
VSTEP(0x5cccul);
if(fc)goto L45fa;
goto L5cd0;
L5cd0: /* move.w ($a,A6), D5 */
VSTEP(0x5cd0ul);
ea=(10+a[6]);
tv=cvr16(ea);
VWORD(d[5])=(u16)(tv);

goto L5cd4;
L5cd4: /* cmpi.w #$10, D5 */
VSTEP(0x5cd4ul);
tv=((u16)(16L));
tw=((u16)d[5]);
fc=(u8)((u16)tw<(u16)tv);
goto L5cd8;
L5cd8: /* bcc $5cde */
VSTEP(0x5cd8ul);
if(!fc)goto L5cde;
goto L5cdc;
L5cdc: /* addq.w #1, D5 */
VSTEP(0x5cdcul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L5cde;
L5cde: /* move.w D5, ($a,A6) */
VSTEP(0x5cdeul);
tv=((u16)d[5]);
ea=(10+a[6]);
cvw16(ea,tv);

goto L5ce2;
L5ce2: /* lsr.w #1, D5 */
VSTEP(0x5ce2ul);
tv=((u16)(1L));
tw=((u16)d[5]);
tr=((u16)tw)>>1;
VWORD(d[5])=(u16)(tr);
goto L5ce4;
L5ce4: /* add.w ($8,A6), D5 */
VSTEP(0x5ce4ul);
ea=(8+a[6]);
tv=cvr16(ea);
tw=((u16)d[5]);
tr=tw+tv;
VWORD(d[5])=(u16)(tr);
goto L5ce8;
L5ce8: /* move.w D5, ($8,A6) */
VSTEP(0x5ce8ul);
tv=((u16)d[5]);
ea=(8+a[6]);
cvw16(ea,tv);

goto L5cec;
L5cec: /* add.w D5, D1 */
VSTEP(0x5cecul);
tv=((u16)d[5]);
tw=((u16)d[1]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5cee;
L5cee: /* bsr $55e0 */
VSTEP(0x5ceeul);
a[7]-=4;cvw32(a[7],0x5cf2ul);
goto L55e0;
L5cf2: /* cmpi.b #$51, D2 */
VSTEP(0x5cf2ul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L5cf6;
L5cf6: /* bcs $5d20 */
VSTEP(0x5cf6ul);
if(fc)goto L5d20;
goto L5cf8;
L5cf8: /* move.w $69ee.w, D3 */
VSTEP(0x5cf8ul);
ea=0x69eeul;
tv=(((u16)vm_vars[1736]<<8)|((u16)vm_vars[1737]<<0));
VWORD(d[3])=(u16)(tv);

goto L5cfc;
L5cfc: /* add.w D1, D3 */
VSTEP(0x5cfcul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5cfe;
L5cfe: /* andi.w #$7, D3 */
VSTEP(0x5cfeul);
tv=((u16)(7L));
tw=((u16)d[3]);
tr=tw&tv;

VWORD(d[3])=(u16)(tr);
goto L5d02;
L5d02: /* not.w D3 */
VSTEP(0x5d02ul);
tv=((u16)d[3]);
tr=~tv;
VWORD(d[3])=(u16)(tr);

goto L5d04;
L5d04: /* add.w D3, D1 */
VSTEP(0x5d04ul);
tv=((u16)d[3]);
tw=((u16)d[1]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[1])=(u16)(tr);
goto L5d06;
L5d06: /* moveq #$4, D2 */
VSTEP(0x5d06ul);
v=((u32)(4L));
d[2]=v;

goto L5d08;
L5d08: /* eor.w D2, ($2,A6) */
VSTEP(0x5d08ul);
tv=((u16)d[2]);
eb=(2+a[6]);
tw=cvr16(eb);
tr=tw^tv;

cvw16(eb,tr);
goto L5d0c;
L5d0c: /* clr.l ($8,A6) */
VSTEP(0x5d0cul);
ea=(8+a[6]);
cvw32(ea,0);

goto L5d10;
L5d10: /* clr.w ($c,A6) */
VSTEP(0x5d10ul);
ea=(12+a[6]);
cvw16(ea,0);

goto L5d14;
L5d14: /* moveq #$5, D2 */
VSTEP(0x5d14ul);
v=((u32)(5L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5d16;
L5d16: /* bsr $44f4 */
VSTEP(0x5d16ul);
a[7]-=4;cvw32(a[7],0x5d1aul);
goto L44f4;
L5d1a: /* moveq #$2, D2 */
VSTEP(0x5d1aul);
v=((u32)(2L));
d[2]=v;

goto L5d1c;
L5d1c: /* bra $45fa */
VSTEP(0x5d1cul);
goto L45fa;
L5d20: /* moveq #$1, D2 */
VSTEP(0x5d20ul);
v=((u32)(1L));
d[2]=v;

goto L5d22;
L5d22: /* move.w $69f2.w, D3 */
VSTEP(0x5d22ul);
ea=0x69f2ul;
tv=(((u16)vm_vars[1740]<<8)|((u16)vm_vars[1741]<<0));
VWORD(d[3])=(u16)(tv);

goto L5d26;
L5d26: /* sub.w D0, D3 */
VSTEP(0x5d26ul);
tv=((u16)d[0]);
tw=((u16)d[3]);
tr=tw-tv;
VWORD(d[3])=(u16)(tr);
goto L5d28;
L5d28: /* addq.w #3, D3 */
VSTEP(0x5d28ul);
tv=((u16)(3L));
tw=((u16)d[3]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[3])=(u16)(tr);
goto L5d2a;
L5d2a: /* cmpi.w #$7, D3 */
VSTEP(0x5d2aul);
tv=((u16)(7L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L5d2e;
L5d2e: /* bcc $45fa */
VSTEP(0x5d2eul);
if(!fc)goto L45fa;
goto L5d32;
L5d32: /* cmp.w $6338.w, D1 */
VSTEP(0x5d32ul);
ea=0x6338ul;
tv=(((u16)vm_vars[18]<<8)|((u16)vm_vars[19]<<0));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5d36;
L5d36: /* bmi $45fa */
VSTEP(0x5d36ul);
if(fn)goto L45fa;
goto L5d3a;
L5d3a: /* cmp.w $69f4.w, D1 */
VSTEP(0x5d3aul);
ea=0x69f4ul;
tv=(((u16)vm_vars[1742]<<8)|((u16)vm_vars[1743]<<0));
tw=((u16)d[1]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5d3e;
L5d3e: /* bpl $45fa */
VSTEP(0x5d3eul);
if(!fn)goto L45fa;
goto L5d42;
L5d42: /* moveq #$2, D6 */
VSTEP(0x5d42ul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5d44;
L5d44: /* bsr $4d0a */
VSTEP(0x5d44ul);
a[7]-=4;cvw32(a[7],0x5d48ul);
goto L4d0a;
L5d48: /* bra $5d06 */
VSTEP(0x5d48ul);
goto L5d06;
L5d4a: /* rts  */
VSTEP(0x5d4aul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5d4c: /* move.w ($4,A6), D2 */
VSTEP(0x5d4cul);
ea=(4+a[6]);
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);

goto L5d50;
L5d50: /* not.w D2 */
VSTEP(0x5d50ul);
tv=((u16)d[2]);
tr=~tv;
VWORD(d[2])=(u16)(tr);

goto L5d52;
L5d52: /* andi.w #$7, D2 */
VSTEP(0x5d52ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5d56;
L5d56: /* bclr #$2, D2 */
VSTEP(0x5d56ul);
v=((u16)(2L));
w=((u32)d[2]);
v&=31;
r=1ul<<v;fz=(w&r)==0;
r=w&~r;
d[2]=r;
goto L5d5a;
L5d5a: /* bne $5d60 */
VSTEP(0x5d5aul);
if(!fz)goto L5d60;
goto L5d5c;
L5d5c: /* addi.w #-$2000, D2 */
VSTEP(0x5d5cul);
tv=((u16)(-8192L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L5d60;
L5d60: /* move.w D2, -(A7) */
VSTEP(0x5d60ul);
tv=((u16)d[2]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);

goto L5d62;
L5d62: /* addq.w #2, D2 */
VSTEP(0x5d62ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d64;
L5d64: /* bsr $45fa */
VSTEP(0x5d64ul);
a[7]-=4;cvw32(a[7],0x5d68ul);
goto L45fa;
L5d68: /* move.w (A7)+, D2 */
VSTEP(0x5d68ul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L5d6a;
L5d6a: /* andi.w #$e000, D2 */
VSTEP(0x5d6aul);
tv=((u16)(57344L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5d6e;
L5d6e: /* addq.w #1, D2 */
VSTEP(0x5d6eul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5d70;
L5d70: /* bsr $45c8 */
VSTEP(0x5d70ul);
a[7]-=4;cvw32(a[7],0x5d74ul);
goto L45c8;
L5d74: /* btst #$0, $6375.w */
VSTEP(0x5d74ul);
v=((u16)(0L));
eb=0x6375ul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5d7a;
L5d7a: /* beq $5d4a */
VSTEP(0x5d7aul);
if(fz)goto L5d4a;
goto L5d7c;
L5d7c: /* subq.w #1, ($4,A6) */
VSTEP(0x5d7cul);
tv=((u16)(1L));
eb=(4+a[6]);
tw=cvr16(eb);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
cvw16(eb,tr);
goto L5d80;
L5d80: /* bmi $5dca */
VSTEP(0x5d80ul);
if(fn)goto L5dca;
goto L5d82;
L5d82: /* rts  */
VSTEP(0x5d82ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5d84: /* btst #$0, $6375.w */
VSTEP(0x5d84ul);
v=((u16)(0L));
eb=0x6375ul;
w=(((u8)vm_vars[79]<<0));
v&=7;
r=1ul<<v;fz=(w&r)==0;
goto L5d8a;
L5d8a: /* beq $5d9c */
VSTEP(0x5d8aul);
if(fz)goto L5d9c;
goto L5d8c;
L5d8c: /* movem.l D0-D1/A6, -(A7) */
VSTEP(0x5d8cul);
a[7]-=4;
cvw32(a[7],a[6]);
a[7]-=4;
cvw32(a[7],d[1]);
a[7]-=4;
cvw32(a[7],d[0]);
goto L5d90;
L5d90: /* moveq #$b, D0 */
VSTEP(0x5d90ul);
v=((u32)(11L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5d92;
L5d92: /* jsr $48014.l */
VSTEP(0x5d92ul);
a[7]-=4;cvw32(a[7],0x5d98ul);
goto L48014;
L5d98: /* movem.l (A7)+, D0-D1/A6 */
VSTEP(0x5d98ul);
ea=a[7];
d[0]=cvr32(ea+0);
d[1]=cvr32(ea+4);
a[6]=cvr32(ea+8);
a[7]+=12;
goto L5d9c;
L5d9c: /* move.w $6374.w, D2 */
VSTEP(0x5d9cul);
ea=0x6374ul;
tv=(((u16)vm_vars[78]<<8)|((u16)vm_vars[79]<<0));
VWORD(d[2])=(u16)(tv);

goto L5da0;
L5da0: /* lsr.w #2, D2 */
VSTEP(0x5da0ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;
VWORD(d[2])=(u16)(tr);
goto L5da2;
L5da2: /* andi.w #$3, D2 */
VSTEP(0x5da2ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5da6;
L5da6: /* addq.w #1, D2 */
VSTEP(0x5da6ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5da8;
L5da8: /* bsr $45fa */
VSTEP(0x5da8ul);
a[7]-=4;cvw32(a[7],0x5dacul);
goto L45fa;
L5dac: /* subi.w #$10, D1 */
VSTEP(0x5dacul);
tv=((u16)(16L));
tw=((u16)d[1]);
tr=tw-tv;fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);
VWORD(d[1])=(u16)(tr);
goto L5db0;
L5db0: /* bpl $5d9c */
VSTEP(0x5db0ul);
if(!fn)goto L5d9c;
goto L5db2;
L5db2: /* lea $39bc.w, A5 */
VSTEP(0x5db2ul);
a[5]=0x39bcul;
goto L5db6;
L5db6: /* move.w #$103, D2 */
VSTEP(0x5db6ul);
tv=((u16)(259L));
VWORD(d[2])=(u16)(tv);

goto L5dba;
L5dba: /* moveq #$9, D7 */
VSTEP(0x5dbaul);
v=((u32)(9L));
d[7]=v;

goto L5dbc;
L5dbc: /* cmp.w ($6,A5), D2 */
VSTEP(0x5dbcul);
ea=(6+a[5]);
tv=cvr16(ea);
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L5dc0;
L5dc0: /* beq $5dd0 */
VSTEP(0x5dc0ul);
if(fz)goto L5dd0;
goto L5dc2;
L5dc2: /* lea ($16,A5), A5 */
VSTEP(0x5dc2ul);
a[5]=(22+a[5]);
goto L5dc6;
L5dc6: /* dbra D7, $5dbc */
VSTEP(0x5dc6ul);
VWORD(d[7])=(u16)(d[7]-1);
if((u16)d[7]!=65535u)goto L5dbc;
goto L5dca;
L5dca: /* moveq #$5a, D6 */
VSTEP(0x5dcaul);
v=((u32)(90L));
d[6]=v;

goto L5dcc;
L5dcc: /* bra $4d0a */
VSTEP(0x5dccul);
goto L4d0a;
L5dd0: /* move.w (A5), D2 */
VSTEP(0x5dd0ul);
ea=a[5];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);
fz=(u8)((tv&0xfffful)==0);
goto L5dd2;
L5dd2: /* beq $5dca */
VSTEP(0x5dd2ul);
if(fz)goto L5dca;
goto L5dd4;
L5dd4: /* subq.w #1, D2 */
VSTEP(0x5dd4ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5dd6;
L5dd6: /* bne $5d4a */
VSTEP(0x5dd6ul);
if(!fz)goto L5d4a;
goto L5dda;
L5dda: /* move.w #$52b6, $3c7c.w */
VSTEP(0x5ddaul);
tv=((u16)(21174L));
vm_player_state=(u16)(tv);

goto L5de0;
L5de0: /* move.w #$21, (A5) */
VSTEP(0x5de0ul);
tv=((u16)(33L));
ea=a[5];
cvw16(ea,tv);

goto L5de4;
L5de4: /* clr.w $6360.w */
VSTEP(0x5de4ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L5de8;
L5de8: /* move.w #$ffff, $6342.w */
VSTEP(0x5de8ul);
tv=((u16)(65535L));
vm_vars[28]=(u8)((u32)(tv)>>8);
vm_vars[29]=(u8)((u32)(tv)>>0);

goto L5dee;
L5dee: /* move.b #$1, $7c874.l */
VSTEP(0x5deeul);
tv=((u8)(1L));
ea=0x7c874ul;
cvw8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5df6;
L5df6: /* rts  */
VSTEP(0x5df6ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5df8: /* move.w $69ec.w, D2 */
VSTEP(0x5df8ul);
ea=0x69ecul;
tv=(((u16)vm_vars[1734]<<8)|((u16)vm_vars[1735]<<0));
VWORD(d[2])=(u16)(tv);

goto L5dfc;
L5dfc: /* cmpi.w #$230, D2 */
VSTEP(0x5dfcul);
tv=((u16)(560L));
tw=((u16)d[2]);
fz=(u8)((u16)tw==(u16)tv);
goto L5e00;
L5e00: /* beq $5e16 */
VSTEP(0x5e00ul);
if(fz)goto L5e16;
goto L5e02;
L5e02: /* addq.w #2, ($2,A6) */
VSTEP(0x5e02ul);
tv=((u16)(2L));
eb=(2+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L5e06;
L5e06: /* moveq #$70, D2 */
VSTEP(0x5e06ul);
v=((u32)(112L));
d[2]=v;

goto L5e08;
L5e08: /* sub.w D0, D2 */
VSTEP(0x5e08ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5e0a;
L5e0a: /* cmpi.w #-$3, D2 */
VSTEP(0x5e0aul);
tv=((u16)(-3L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L5e0e;
L5e0e: /* bcc $5e12 */
VSTEP(0x5e0eul);
if(!fc)goto L5e12;
goto L5e10;
L5e10: /* moveq #-$2, D2 */
VSTEP(0x5e10ul);
v=((u32)(-2L));
d[2]=v;

goto L5e12;
L5e12: /* add.w D2, $69f8.w */
VSTEP(0x5e12ul);
tv=((u16)d[2]);
eb=0x69f8ul;
tw=(((u16)vm_vars[1746]<<8)|((u16)vm_vars[1747]<<0));
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vm_vars[1746]=(u8)((u32)(tr)>>8);
vm_vars[1747]=(u8)((u32)(tr)>>0);
goto L5e16;
L5e16: /* cmpi.w #$48, D1 */
VSTEP(0x5e16ul);
tv=((u16)(72L));
tw=((u16)d[1]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5e1a;
L5e1a: /* bcc $5e6e */
VSTEP(0x5e1aul);
if(!fc)goto L5e6e;
goto L5e1c;
L5e1c: /* move.w ($a,A6), D3 */
VSTEP(0x5e1cul);
ea=(10+a[6]);
tv=cvr16(ea);
VWORD(d[3])=(u16)(tv);

goto L5e20;
L5e20: /* cmpi.w #$e, D3 */
VSTEP(0x5e20ul);
tv=((u16)(14L));
tw=((u16)d[3]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L5e24;
L5e24: /* bpl $5e2c */
VSTEP(0x5e24ul);
if(!fn)goto L5e2c;
goto L5e26;
L5e26: /* addq.w #1, D3 */
VSTEP(0x5e26ul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=tw+tv;
VWORD(d[3])=(u16)(tr);
goto L5e28;
L5e28: /* move.w D3, ($a,A6) */
VSTEP(0x5e28ul);
tv=((u16)d[3]);
ea=(10+a[6]);
cvw16(ea,tv);

goto L5e2c;
L5e2c: /* asr.w #1, D3 */
VSTEP(0x5e2cul);
tv=((u16)(1L));
tw=((u16)d[3]);
tr=((s16)tw)>>1;
VWORD(d[3])=(u16)(tr);
goto L5e2e;
L5e2e: /* add.w D3, ($4,A6) */
VSTEP(0x5e2eul);
tv=((u16)d[3]);
eb=(4+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L5e32;
L5e32: /* moveq #$18, D2 */
VSTEP(0x5e32ul);
v=((u32)(24L));
d[2]=v;

goto L5e34;
L5e34: /* sub.w D1, D2 */
VSTEP(0x5e34ul);
tv=((u16)d[1]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5e36;
L5e36: /* add.w D2, $69f6.w */
VSTEP(0x5e36ul);
tv=((u16)d[2]);
eb=0x69f6ul;
tw=(((u16)vm_vars[1744]<<8)|((u16)vm_vars[1745]<<0));
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
vm_vars[1744]=(u8)((u32)(tr)>>8);
vm_vars[1745]=(u8)((u32)(tr)>>0);
goto L5e3a;
L5e3a: /* moveq #$6, D2 */
VSTEP(0x5e3aul);
v=((u32)(6L));
d[2]=v;

goto L5e3c;
L5e3c: /* cmpi.w #$4, D3 */
VSTEP(0x5e3cul);
tv=((u16)(4L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5e40;
L5e40: /* bmi $5e58 */
VSTEP(0x5e40ul);
if(fn)goto L5e58;
goto L5e42;
L5e42: /* moveq #$7, D2 */
VSTEP(0x5e42ul);
v=((u32)(7L));
d[2]=v;

goto L5e44;
L5e44: /* cmpi.w #$7, D2 */
VSTEP(0x5e44ul);
tv=((u16)(7L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5e48;
L5e48: /* bmi $5e58 */
VSTEP(0x5e48ul);
if(fn)goto L5e58;
goto L5e4a;
L5e4a: /* moveq #$c, D2 */
VSTEP(0x5e4aul);
v=((u32)(12L));
d[2]=v;

goto L5e4c;
L5e4c: /* and.w $6374.w, D2 */
VSTEP(0x5e4cul);
ea=0x6374ul;
tv=(((u16)vm_vars[78]<<8)|((u16)vm_vars[79]<<0));
tw=((u16)d[2]);
tr=tw&tv;

VWORD(d[2])=(u16)(tr);
goto L5e50;
L5e50: /* lsr.w #2, D2 */
VSTEP(0x5e50ul);
tv=((u16)(2L));
tw=((u16)d[2]);
tr=((u16)tw)>>2;fz=(u8)((tr&0xfffful)==0);
VWORD(d[2])=(u16)(tr);
goto L5e52;
L5e52: /* bne $5e56 */
VSTEP(0x5e52ul);
if(!fz)goto L5e56;
goto L5e54;
L5e54: /* moveq #$2, D2 */
VSTEP(0x5e54ul);
v=((u32)(2L));
d[2]=v;

goto L5e56;
L5e56: /* addq.w #7, D2 */
VSTEP(0x5e56ul);
tv=((u16)(7L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[2])=(u16)(tr);
goto L5e58;
L5e58: /* bsr $45fa */
VSTEP(0x5e58ul);
a[7]-=4;cvw32(a[7],0x5e5cul);
goto L45fa;
L5e5c: /* jsr $48004.l */
VSTEP(0x5e5cul);
a[7]-=4;cvw32(a[7],0x5e62ul);
goto L48004;
L5e62: /* move.l #$210, D0 */
VSTEP(0x5e62ul);
v=((u32)(528L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5e68;
L5e68: /* jmp $7c82a.l */
VSTEP(0x5e68ul);
goto L7c82a;
L5e82:
if(cat_external(0x5e82ul))return;
/* jsr $48004.l */
VSTEP(0x5e82ul);
a[7]-=4;cvw32(a[7],0x5e88ul);
goto L48004;
L5e88: /* moveq #$2, D0 */
VSTEP(0x5e88ul);
v=((u32)(2L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5e8a;
L5e8a: /* jsr $48010.l */
VSTEP(0x5e8aul);
a[7]-=4;cvw32(a[7],0x5e90ul);
goto L48010;
L5e90: /* move.w #$fa, D0 */
VSTEP(0x5e90ul);
tv=((u16)(250L));
VWORD(d[0])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5e94;
L5e94: /* bsr $5ed4 */
VSTEP(0x5e94ul);
a[7]-=4;cvw32(a[7],0x5e96ul);
goto L5ed4;
L5e96: /* moveq #$64, D0 */
VSTEP(0x5e96ul);
v=((u32)(100L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5e98;
L5e98: /* bsr $5ed4 */
VSTEP(0x5e98ul);
a[7]-=4;cvw32(a[7],0x5e9cul);
goto L5ed4;
L5e9c: /* bsr $4e66 */
VSTEP(0x5e9cul);
a[7]-=4;cvw32(a[7],0x5ea0ul);
goto L4e66;
L5ea0: /* lea $3ab1.w, A0 */
VSTEP(0x5ea0ul);
a[0]=0x3ab1ul;
goto L5ea4;
L5ea4: /* bsr $69fa */
VSTEP(0x5ea4ul);
a[7]-=4;cvw32(a[7],0x5ea8ul);
goto L69fa;
L5ea8: /* bsr $3caa */
VSTEP(0x5ea8ul);
a[7]-=4;cvw32(a[7],0x5eacul);
goto L3caa;
L5eac: /* moveq #$64, D0 */
VSTEP(0x5eacul);
v=((u32)(100L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5eae;
L5eae: /* bsr $5ed4 */
VSTEP(0x5eaeul);
a[7]-=4;cvw32(a[7],0x5eb2ul);
goto L5ed4;
L5eb2: /* bsr $4e66 */
VSTEP(0x5eb2ul);
a[7]-=4;cvw32(a[7],0x5eb6ul);
goto L4e66;
L5eb6: /* lea $3abd.w, A0 */
VSTEP(0x5eb6ul);
a[0]=0x3abdul;
goto L5eba;
L5eba: /* bsr $69fa */
VSTEP(0x5ebaul);
a[7]-=4;cvw32(a[7],0x5ebeul);
goto L69fa;
L5ebe: /* bsr $3caa */
VSTEP(0x5ebeul);
a[7]-=4;cvw32(a[7],0x5ec2ul);
goto L3caa;
L5ec2: /* moveq #$64, D0 */
VSTEP(0x5ec2ul);
v=((u32)(100L));
d[0]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5ec4;
L5ec4: /* bsr $5ed4 */
VSTEP(0x5ec4ul);
a[7]-=4;cvw32(a[7],0x5ec8ul);
goto L5ed4;
L5ec8: /* bsr $3ca6 */
VSTEP(0x5ec8ul);
a[7]-=4;cvw32(a[7],0x5eccul);
goto L3ca6;
L5ecc: /* bsr $3d76 */
VSTEP(0x5eccul);
a[7]-=4;cvw32(a[7],0x5ed0ul);
goto L3d76;
L5ed0: /* bra $820 */
VSTEP(0x5ed0ul);
if(cat_external(0x820ul))return;pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5ee0: /* movem.w $69f2.w, D2-D3 */
VSTEP(0x5ee0ul);
ea=0x69f2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L5ee6;
L5ee6: /* sub.w D1, D3 */
VSTEP(0x5ee6ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L5ee8;
L5ee8: /* cmpi.w #$1, D3 */
VSTEP(0x5ee8ul);
tv=((u16)(1L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5eec;
L5eec: /* bcc $5f12 */
VSTEP(0x5eecul);
if(!fc)goto L5f12;
goto L5eee;
L5eee: /* sub.w D0, D2 */
VSTEP(0x5eeeul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[2])=(u16)(tr);
goto L5ef0;
L5ef0: /* cmpi.w #$20, D2 */
VSTEP(0x5ef0ul);
tv=((u16)(32L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);fz=(u8)((u16)tw==(u16)tv);tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
goto L5ef4;
L5ef4: /* bcc $5f12 */
VSTEP(0x5ef4ul);
if(!fc)goto L5f12;
goto L5ef6;
L5ef6: /* move.b $6337.w, D2 */
VSTEP(0x5ef6ul);
ea=0x6337ul;
tv=(((u8)vm_vars[17]<<0));
VBYTE(d[2])=(u8)(tv);

goto L5efa;
L5efa: /* cmpi.b #$24, D2 */
VSTEP(0x5efaul);
tv=((u8)(36L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);fz=(u8)((u8)tw==(u8)tv);tr=tw-tv;fn=(u8)((tr&0x80ul)!=0);fv=(u8)(((tw^tv)&(tw^tr)&0x80ul)!=0);
goto L5efe;
L5efe: /* rts  */
VSTEP(0x5efeul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5f00: /* bsr $5ee0 */
VSTEP(0x5f00ul);
a[7]-=4;cvw32(a[7],0x5f02ul);
goto L5ee0;
L5f02: /* bcc $5f12 */
VSTEP(0x5f02ul);
if(!fc)goto L5f12;
goto L5f04;
L5f04: /* move.w #$18, $69f6.w */
VSTEP(0x5f04ul);
tv=((u16)(24L));
vm_vars[1744]=(u8)((u32)(tv)>>8);
vm_vars[1745]=(u8)((u32)(tv)>>0);

goto L5f0a;
L5f0a: /* addq.w #1, (A6) */
VSTEP(0x5f0aul);
tv=((u16)(1L));
eb=a[6];
tw=cvr16(eb);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
cvw16(eb,tr);
goto L5f0c;
L5f0c: /* move.w #$20, ($8,A6) */
VSTEP(0x5f0cul);
tv=((u16)(32L));
ea=(8+a[6]);
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5f12;
L5f12: /* rts  */
VSTEP(0x5f12ul);
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5f14: /* subq.w #1, ($8,A6) */
VSTEP(0x5f14ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fx=(u8)(tv>tw);fz=(u8)((tr&0xfffful)==0);
cvw16(eb,tr);
goto L5f18;
L5f18: /* beq $5f40 */
VSTEP(0x5f18ul);
if(fz)goto L5f40;
goto L5f1a;
L5f1a: /* moveq #$27, D2 */
VSTEP(0x5f1aul);
v=((u32)(39L));
d[2]=v;

goto L5f1c;
L5f1c: /* sub.w ($8,A6), D2 */
VSTEP(0x5f1cul);
ea=(8+a[6]);
tv=cvr16(ea);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L5f20;
L5f20: /* lsr.w #3, D2 */
VSTEP(0x5f20ul);
tv=((u16)(3L));
tw=((u16)d[2]);
tr=((u16)tw)>>3;fx=(u8)((tw>>2)&1);
VWORD(d[2])=(u16)(tr);
goto L5f22;
L5f22: /* move.w D2, -(A7) */
VSTEP(0x5f22ul);
tv=((u16)d[2]);
a[7]-=2;
ea=a[7];
cvw16(ea,tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5f24;
L5f24: /* bsr $45fa */
VSTEP(0x5f24ul);
a[7]-=4;cvw32(a[7],0x5f28ul);
goto L45fa;
L5f28: /* addq.w #8, D0 */
VSTEP(0x5f28ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5f2a;
L5f2a: /* move.w (A7), D2 */
VSTEP(0x5f2aul);
ea=a[7];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5f2c;
L5f2c: /* bsr $45fa */
VSTEP(0x5f2cul);
a[7]-=4;cvw32(a[7],0x5f30ul);
goto L45fa;
L5f30: /* addq.w #8, D0 */
VSTEP(0x5f30ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fx=(u8)((u16)tr<(u16)tw);
VWORD(d[0])=(u16)(tr);
goto L5f32;
L5f32: /* move.w (A7), D2 */
VSTEP(0x5f32ul);
ea=a[7];
tv=cvr16(ea);
VWORD(d[2])=(u16)(tv);
fn=(u8)((tv&0x8000ul)!=0);fz=(u8)((tv&0xfffful)==0);fv=0;fc=0;
goto L5f34;
L5f34: /* bsr $45fa */
VSTEP(0x5f34ul);
a[7]-=4;cvw32(a[7],0x5f38ul);
goto L45fa;
L5f38: /* addq.w #8, D0 */
VSTEP(0x5f38ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L5f3a;
L5f3a: /* move.w (A7)+, D2 */
VSTEP(0x5f3aul);
ea=a[7];
tv=cvr16(ea);
a[7]+=2;
VWORD(d[2])=(u16)(tv);

goto L5f3c;
L5f3c: /* bra $45fa */
VSTEP(0x5f3cul);
goto L45fa;
L5f40: /* clr.w (A6) */
VSTEP(0x5f40ul);
ea=a[6];
cvw16(ea,0);
fn=(u8)((0&0x8000ul)!=0);fz=(u8)((0&0xfffful)==0);fv=0;fc=0;
goto L5f42;
L5f42: /* bsr $55e0 */
VSTEP(0x5f42ul);
a[7]-=4;cvw32(a[7],0x5f46ul);
goto L55e0;
L5f46: /* lsl.w #8, D2 */
VSTEP(0x5f46ul);
tv=((u16)(8L));
tw=((u16)d[2]);
tr=tw<<8;
VWORD(d[2])=(u16)(tr);
goto L5f48;
L5f48: /* move.b ($1,A0,D3.w), D2 */
VSTEP(0x5f48ul);
ea=(1+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[2])=(u8)(tv);

goto L5f4c;
L5f4c: /* move.b ($2,A0,D3.w), D4 */
VSTEP(0x5f4cul);
ea=(2+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[4])=(u8)(tv);

goto L5f50;
L5f50: /* lsl.w #8, D4 */
VSTEP(0x5f50ul);
tv=((u16)(8L));
tw=((u16)d[4]);
tr=tw<<8;fx=(u8)((tw>>8)&1);
VWORD(d[4])=(u16)(tr);
goto L5f52;
L5f52: /* move.b ($3,A0,D3.w), D4 */
VSTEP(0x5f52ul);
ea=(3+a[0]+((s16)(d[3])));
tv=cvr8(ea);
VBYTE(d[4])=(u8)(tv);

goto L5f56;
L5f56: /* movea.l $5fac.w, A5 */
VSTEP(0x5f56ul);
ea=0x5facul;
v=dm_be32((const u8 DM_NEAR *)((stage_work.puzzle+2176u)+0u));
a[5]=v;
goto L5f5a;
L5f5a: /* movem.w D2-D4, -(A5) */
VSTEP(0x5f5aul);
a[5]-=2;
cvw16(a[5],d[4]);
a[5]-=2;
cvw16(a[5],d[3]);
a[5]-=2;
cvw16(a[5],d[2]);
goto L5f5e;
L5f5e: /* move.l A5, $5fac.w */
VSTEP(0x5f5eul);
v=((u32)a[5]);
ea=0x5facul;
dm_put32((u8 DM_NEAR *)((stage_work.puzzle+2176u)+0u),(u32)(v));

goto L5f62;
L5f62: /* move.b #$4f, (A0,D3.w) */
VSTEP(0x5f62ul);
tv=((u8)(79L));
ea=(a[0]+((s16)(d[3])));
cvw8(ea,tv);

goto L5f68;
L5f68: /* move.b #$4f, ($1,A0,D3.w) */
VSTEP(0x5f68ul);
tv=((u8)(79L));
ea=(1+a[0]+((s16)(d[3])));
cvw8(ea,tv);

goto L5f6e;
L5f6e: /* move.b #$4f, ($2,A0,D3.w) */
VSTEP(0x5f6eul);
tv=((u8)(79L));
ea=(2+a[0]+((s16)(d[3])));
cvw8(ea,tv);

goto L5f74;
L5f74: /* move.b #$4f, ($3,A0,D3.w) */
VSTEP(0x5f74ul);
tv=((u8)(79L));
ea=(3+a[0]+((s16)(d[3])));
cvw8(ea,tv);
fn=(u8)((tv&0x80ul)!=0);fz=(u8)((tv&0xfful)==0);fv=0;fc=0;
goto L5f7a;
L5f7a: /* bsr $5ee0 */
VSTEP(0x5f7aul);
a[7]-=4;cvw32(a[7],0x5f7eul);
goto L5ee0;
L5f7e: /* bcc $5f8a */
VSTEP(0x5f7eul);
if(!fc)goto L5f8a;
goto L5f80;
L5f80: /* move.w #$540e, $3c7c.w */
VSTEP(0x5f80ul);
tv=((u16)(21518L));
vm_player_state=(u16)(tv);

goto L5f86;
L5f86: /* clr.w $6360.w */
VSTEP(0x5f86ul);
vm_vars[58]=(u8)((u32)(0)>>8);
vm_vars[59]=(u8)((u32)(0)>>0);

goto L5f8a;
L5f8a: /* moveq #$5, D2 */
VSTEP(0x5f8aul);
v=((u32)(5L));
d[2]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L5f8c;
L5f8c: /* bsr $45fa */
VSTEP(0x5f8cul);
a[7]-=4;cvw32(a[7],0x5f90ul);
goto L45fa;
L5f90: /* moveq #$5, D2 */
VSTEP(0x5f90ul);
v=((u32)(5L));
d[2]=v;

goto L5f92;
L5f92: /* addq.w #8, D0 */
VSTEP(0x5f92ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5f94;
L5f94: /* bsr $45fa */
VSTEP(0x5f94ul);
a[7]-=4;cvw32(a[7],0x5f98ul);
goto L45fa;
L5f98: /* moveq #$5, D2 */
VSTEP(0x5f98ul);
v=((u32)(5L));
d[2]=v;

goto L5f9a;
L5f9a: /* addq.w #8, D0 */
VSTEP(0x5f9aul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5f9c;
L5f9c: /* bsr $45fa */
VSTEP(0x5f9cul);
a[7]-=4;cvw32(a[7],0x5fa0ul);
goto L45fa;
L5fa0: /* moveq #$5, D2 */
VSTEP(0x5fa0ul);
v=((u32)(5L));
d[2]=v;

goto L5fa2;
L5fa2: /* addq.w #8, D0 */
VSTEP(0x5fa2ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L5fa4;
L5fa4: /* bsr $45fa */
VSTEP(0x5fa4ul);
a[7]-=4;cvw32(a[7],0x5fa8ul);
goto L45fa;
L5fa8: /* bra $58ea */
VSTEP(0x5fa8ul);
goto L58ea;
L6014: /* cmpi.w #$c0, D0 */
VSTEP(0x6014ul);
tv=((u16)(192L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L6018;
L6018: /* bpl $605a */
VSTEP(0x6018ul);
if(!fn)goto L605a;
goto L601a;
L601a: /* andi.w #$7, D4 */
VSTEP(0x601aul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L601e;
L601e: /* bne $602e */
VSTEP(0x601eul);
if(!fz)goto L602e;
goto L6020;
L6020: /* addq.w #8, D0 */
VSTEP(0x6020ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);fx=(u8)((u16)tr<(u16)tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)((~(tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L6022;
L6022: /* bsr $55e0 */
VSTEP(0x6022ul);
a[7]-=4;cvw32(a[7],0x6026ul);
goto L55e0;
L6026: /* subq.w #8, D0 */
VSTEP(0x6026ul);
tv=((u16)(8L));
tw=((u16)d[0]);
tr=tw-tv;
VWORD(d[0])=(u16)(tr);
goto L6028;
L6028: /* cmpi.b #$51, D2 */
VSTEP(0x6028ul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L602c;
L602c: /* bcs $605a */
VSTEP(0x602cul);
if(fc)goto L605a;
goto L602e;
L602e: /* addq.w #1, ($2,A6) */
VSTEP(0x602eul);
tv=((u16)(1L));
eb=(2+a[6]);
tw=cvr16(eb);
tr=tw+tv;
cvw16(eb,tr);
goto L6032;
L6032: /* subq.w #1, ($8,A6) */
VSTEP(0x6032ul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
cvw16(eb,tr);
goto L6036;
L6036: /* bpl $605e */
VSTEP(0x6036ul);
if(!fn)goto L605e;
goto L6038;
L6038: /* movem.w $69f2.w, D2-D3 */
VSTEP(0x6038ul);
ea=0x69f2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L603e;
L603e: /* sub.w D0, D2 */
VSTEP(0x603eul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L6040;
L6040: /* cmpi.w #$8, D2 */
VSTEP(0x6040ul);
tv=((u16)(8L));
tw=((u16)d[2]);
fc=(u8)((u16)tw<(u16)tv);
goto L6044;
L6044: /* bcc $605e */
VSTEP(0x6044ul);
if(!fc)goto L605e;
goto L6046;
L6046: /* sub.w D1, D3 */
VSTEP(0x6046ul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L6048;
L6048: /* cmpi.w #$13, D3 */
VSTEP(0x6048ul);
tv=((u16)(19L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L604c;
L604c: /* bcc $605e */
VSTEP(0x604cul);
if(!fc)goto L605e;
goto L604e;
L604e: /* move.w #$19, ($8,A6) */
VSTEP(0x604eul);
tv=((u16)(25L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L6054;
L6054: /* moveq #$2, D6 */
VSTEP(0x6054ul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L6056;
L6056: /* bsr $4d0a */
VSTEP(0x6056ul);
a[7]-=4;cvw32(a[7],0x605aul);
goto L4d0a;
L605a: /* move.w #$1e, (A6) */
VSTEP(0x605aul);
tv=((u16)(30L));
ea=a[6];
cvw16(ea,tv);

goto L605e;
L605e: /* move.w D4, D2 */
VSTEP(0x605eul);
tv=((u16)d[4]);
VWORD(d[2])=(u16)(tv);

goto L6060;
L6060: /* lsr.w #1, D2 */
VSTEP(0x6060ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=((u16)tw)>>1;
VWORD(d[2])=(u16)(tr);
goto L6062;
L6062: /* addq.w #1, D2 */
VSTEP(0x6062ul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L6064;
L6064: /* bra $45fa */
VSTEP(0x6064ul);
goto L45fa;
L6068: /* cmpi.w #-$40, D0 */
VSTEP(0x6068ul);
tv=((u16)(-64L));
tw=((u16)d[0]);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
goto L606c;
L606c: /* bmi $60b2 */
VSTEP(0x606cul);
if(fn)goto L60b2;
goto L606e;
L606e: /* andi.w #$7, D4 */
VSTEP(0x606eul);
tv=((u16)(7L));
tw=((u16)d[4]);
tr=tw&tv;
fz=(u8)((tr&0xfffful)==0);
VWORD(d[4])=(u16)(tr);
goto L6072;
L6072: /* bne $6086 */
VSTEP(0x6072ul);
if(!fz)goto L6086;
goto L6074;
L6074: /* subi.w #$10, D0 */
VSTEP(0x6074ul);
tv=((u16)(16L));
tw=((u16)d[0]);
tr=tw-tv;fc=(u8)(tv>tw);fx=(u8)(tv>tw);fn=(u8)((tr&0x8000ul)!=0);fz=(u8)((tr&0xfffful)==0);fv=(u8)(((tw^tv)&(tw^tr)&0x8000ul)!=0);
VWORD(d[0])=(u16)(tr);
goto L6078;
L6078: /* bsr $55e0 */
VSTEP(0x6078ul);
a[7]-=4;cvw32(a[7],0x607cul);
goto L55e0;
L607c: /* addi.w #$10, D0 */
VSTEP(0x607cul);
tv=((u16)(16L));
tw=((u16)d[0]);
tr=tw+tv;
VWORD(d[0])=(u16)(tr);
goto L6080;
L6080: /* cmpi.b #$51, D2 */
VSTEP(0x6080ul);
tv=((u8)(81L));
tw=((u8)d[2]);
fc=(u8)((u8)tw<(u8)tv);
goto L6084;
L6084: /* bcs $60b2 */
VSTEP(0x6084ul);
if(fc)goto L60b2;
goto L6086;
L6086: /* subq.w #1, ($2,A6) */
VSTEP(0x6086ul);
tv=((u16)(1L));
eb=(2+a[6]);
tw=cvr16(eb);
tr=tw-tv;
cvw16(eb,tr);
goto L608a;
L608a: /* subq.w #1, ($8,A6) */
VSTEP(0x608aul);
tv=((u16)(1L));
eb=(8+a[6]);
tw=cvr16(eb);
tr=tw-tv;fn=(u8)((tr&0x8000ul)!=0);
cvw16(eb,tr);
goto L608e;
L608e: /* bpl $60b6 */
VSTEP(0x608eul);
if(!fn)goto L60b6;
goto L6090;
L6090: /* movem.w $69f2.w, D2-D3 */
VSTEP(0x6090ul);
ea=0x69f2ul;
d[2]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1740u));
d[3]=(s16)dm_be16((const u8 DM_NEAR *)(vm_vars+1742u));
goto L6096;
L6096: /* sub.w D0, D2 */
VSTEP(0x6096ul);
tv=((u16)d[0]);
tw=((u16)d[2]);
tr=tw-tv;
VWORD(d[2])=(u16)(tr);
goto L6098;
L6098: /* addi.w #$a, D2 */
VSTEP(0x6098ul);
tv=((u16)(10L));
tw=((u16)d[2]);
tr=tw+tv;fc=(u8)((u16)tr<(u16)tw);
VWORD(d[2])=(u16)(tr);
goto L609c;
L609c: /* bcc $60b6 */
VSTEP(0x609cul);
if(!fc)goto L60b6;
goto L609e;
L609e: /* sub.w D1, D3 */
VSTEP(0x609eul);
tv=((u16)d[1]);
tw=((u16)d[3]);
tr=tw-tv;fx=(u8)(tv>tw);
VWORD(d[3])=(u16)(tr);
goto L60a0;
L60a0: /* cmpi.w #$13, D3 */
VSTEP(0x60a0ul);
tv=((u16)(19L));
tw=((u16)d[3]);
fc=(u8)((u16)tw<(u16)tv);
goto L60a4;
L60a4: /* bcc $60b6 */
VSTEP(0x60a4ul);
if(!fc)goto L60b6;
goto L60a6;
L60a6: /* move.w #$19, ($8,A6) */
VSTEP(0x60a6ul);
tv=((u16)(25L));
ea=(8+a[6]);
cvw16(ea,tv);

goto L60ac;
L60ac: /* moveq #$2, D6 */
VSTEP(0x60acul);
v=((u32)(2L));
d[6]=v;
fn=(u8)((v&0x80000000ul)!=0);fz=(u8)((v&0xfffffffful)==0);fv=0;fc=0;
goto L60ae;
L60ae: /* bsr $4d0a */
VSTEP(0x60aeul);
a[7]-=4;cvw32(a[7],0x60b2ul);
goto L4d0a;
L60b2: /* move.w #$1d, (A6) */
VSTEP(0x60b2ul);
tv=((u16)(29L));
ea=a[6];
cvw16(ea,tv);

goto L60b6;
L60b6: /* move.w #$e003, D2 */
VSTEP(0x60b6ul);
tv=((u16)(57347L));
VWORD(d[2])=(u16)(tv);

goto L60ba;
L60ba: /* lsr.w #1, D4 */
VSTEP(0x60baul);
tv=((u16)(1L));
tw=((u16)d[4]);
tr=((u16)tw)>>1;
VWORD(d[4])=(u16)(tr);
goto L60bc;
L60bc: /* eor.w D4, D2 */
VSTEP(0x60bcul);
tv=((u16)d[4]);
tw=((u16)d[2]);
tr=tw^tv;

VWORD(d[2])=(u16)(tr);
goto L60be;
L60be: /* addq.w #1, D2 */
VSTEP(0x60beul);
tv=((u16)(1L));
tw=((u16)d[2]);
tr=tw+tv;
VWORD(d[2])=(u16)(tr);
goto L60c0;
L60c0: /* bra $45fa */
VSTEP(0x60c0ul);
goto L45fa;
L36ee:
if(cat_external(0x36eeul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3ca6:
if(cat_external(0x3ca6ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3caa:
if(cat_external(0x3caaul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3d2a:
if(cat_external(0x3d2aul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3d48:
if(cat_external(0x3d48ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L3d7a:
if(cat_external(0x3d7aul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4a9c:
if(cat_external(0x4a9cul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4b14:
if(cat_external(0x4b14ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4ba0:
if(cat_external(0x4ba0ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4df0:
if(cat_external(0x4df0ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4e66:
if(cat_external(0x4e66ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5604:
goto L56e6;
L5734:
if(cat_external(0x5734ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5e6e:
 d[1]=80;vnz(d[1],32);d[2]=11;vnz(d[2],32);
 a[7]-=4;cvw32(a[7],0x5e76ul);goto L45fa;
L5e76:
 a[7]-=4;cvw32(a[7],0x5e7aul);goto L36ee;
L5e7a:
if(cat_external(0x5e7aul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L5ed4:
if(cat_external(0x5ed4ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L69fa:
if(cat_external(0x69faul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L48000:
if(cat_external(0x48000ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L48004:
if(cat_external(0x48004ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L48008:
if(cat_external(0x48008ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L4800c:
if(cat_external(0x4800cul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L48010:
if(cat_external(0x48010ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L48014:
if(cat_external(0x48014ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L48018:
if(cat_external(0x48018ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L7c82a:
if(cat_external(0x7c82aul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L7c862:
if(cat_external(0x7c862ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
L7c870:
if(cat_external(0x7c870ul))return;
pc=cvr32(a[7]);a[7]+=4;goto dispatch;
}
