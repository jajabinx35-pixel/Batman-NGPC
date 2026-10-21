#include "puzzle.h"
extern u8 stack[512];
static u8 *mutable_at(u32 p){
 if(p>=0xd54aul&&p<0xd55cul)return puzzle_ram+(u16)(p-0xd54aul);
 if(p>=0xd840ul&&p<0xd84cul)return puzzle_ram+18u+(u16)(p-0xd840ul);
 if(p>=0xd8d4ul&&p<0xd8daul)return puzzle_ram+30u+(u16)(p-0xd8d4ul);
 if(p>=0xdbfaul&&p<0xdc1cul)return puzzle_ram+36u+(u16)(p-0xdbfaul);
 if(p>=0xe122ul&&p<0xe158ul)return puzzle_ram+70u+(u16)(p-0xe122ul);
 if(p>=0xedfcul&&p<0xee06ul)return puzzle_ram+124u+(u16)(p-0xedfcul);
 if(p>=0xd0c8ul&&p<0xd0caul)return puzzle_ram+134u+(u16)(p-0xd0c8ul);
 if(p>=0x1ffe00ul&&p<0x200000ul)return stack+(u16)(p-0x1ffe00ul);
 return (u8 *)0;
}
u8 pvr8(u32 p){u8 *q=mutable_at(p);u16 v;if(q)return *q;
 if(p==0xbfe801ul||p==0xbfe901ul){v=(u16)(((u16)puzzle_ram[203]<<8)|puzzle_ram[204]);v=(u16)(v*109u+89u);puzzle_ram[203]=(u8)(v>>8);puzzle_ram[204]=(u8)v;return p==0xbfe801ul?(u8)v:(u8)(v>>8);}
 if(p==0xdff00cul)return puzzle_ram[200];if(p==0xdff00dul)return puzzle_ram[201];if(p==0xbfe001ul)return puzzle_ram[202];
 if(p==0x7c884ul)return puzzle_ram[205];if(p==0x7c885ul)return puzzle_ram[206];
 if(p>=0xd000ul&&p<0xe800ul)return puzzle_code[(u16)(p-0xd000ul)];return 0;
}
u16 pvr16(u32 p){return(u16)((u16)pvr8(p)<<8)|pvr8(p+1);}
u32 pvr32(u32 p){return((u32)pvr16(p)<<16)|pvr16(p+2);}
void pvw8(u32 p,u8 v){u8 *q=mutable_at(p);if(q){*q=v;return;}if(p<8ul)return;vm_fault=p;}
void pvw16(u32 p,u16 v){pvw8(p,(u8)(v>>8));pvw8(p+1,(u8)v);}
void pvw32(u32 p,u32 v){pvw16(p,(u16)(v>>16));pvw16(p+2,(u16)v);}
void puzzle_reset(u16 seed){u16 i;for(i=0;i<256;i++)puzzle_ram[i]=0;
 for(i=0;i<18;i++)puzzle_ram[i]=puzzle_code[0xd54a-0xd000+i];
 for(i=0;i<54;i++)puzzle_ram[70+i]=puzzle_code[0xe122-0xd000+i];
 pvw16(0xdbfaul,3);pvw16(0xdc06ul,1);pvw16(0xd8d8ul,0x73);pvw16(0xdc00ul,6);pvw16(0xe124ul,24);pvw16(0xe128ul,18);
 puzzle_ram[202]=128;puzzle_ram[203]=(u8)(seed>>8);puzzle_ram[204]=(u8)seed;
 for(i=0;i<8;i++)a[i]=d[i]=0;vm_busy=0;vm_fault=vm_resume=0;fn=fz=fv=fc=fx=0;puzzle_exec(0xd462);
}
#ifdef VM_PUZZLEHOST
extern int(*vm_callback)(u32);
int puzzle_external(u32 pc){return vm_callback?vm_callback(pc):0;}
#endif
