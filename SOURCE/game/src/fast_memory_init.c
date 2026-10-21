/* Stage-exclusive hot memory accessors execute on the 16-bit RAM bus.
 * 7600..77FF is free after fusing effect decode and mixing. Z80 stays halted.
 * No game address mapping or arithmetic is changed by this relocation. */
#include "faithful.h"
#include "game.h"
#include <stddef.h>
extern const u8 _NativeKernelROM_START,_NativeKernelROM_END;
typedef char native_kernel_layout[(offsetof(NativeRender,map)==4544u)?1:-1];
extern const u8 _PlatformScanROM_START,_PlatformScanROM_END;
typedef char platform_scan_tail_is_unused[(sizeof(PlatformRender)<=2560u)?1:-1];
#ifndef VM_HOST
extern const u8 _FastAxisROM_START,_FastAxisROM_END;
extern const u8 _FastCatROM_START,_FastCatROM_END;
extern const u8 _FastVehROM_START,_FastVehROM_END;
extern const u8 _PcmROM_START,_PcmROM_END,_GraphicsROM_START,_GraphicsROM_END,_ClearROM_START,_ClearROM_END;
static void copy_code(u8 *dst,const u8 *src,const u8 *end){while(src<end)*dst++=*src++;}
/* Bootstrapped before interrupts or graphics helpers can run. These fixed
 * windows cannot be allocated to globals or to the stage-exclusive overlay. */
void runtime_code_init(void){
 copy_code((u8 *)0x7000,&_PcmROM_START,&_PcmROM_END);
 copy_code((u8 *)0x6b60,&_GraphicsROM_START,&_GraphicsROM_END);
 copy_code((u8 *)0x77c0,&_ClearROM_START,&_ClearROM_END);
}
void stage_memory_init(u8 stage){const u8 *s,*end;u8 *dst=(u8 *)0x7600;
 if(stage==1){s=&_FastAxisROM_START;end=&_FastAxisROM_END;}
 else if(stage==5){s=&_FastCatROM_START;end=&_FastCatROM_END;}
 else{s=&_FastVehROM_START;end=&_FastVehROM_END;}
 while(s<end)*dst++=*s++;
 if(stage==1u||stage==5u)copy_code(((u8 *)&render_work)+2560u,&_PlatformScanROM_START,&_PlatformScanROM_END);
 else if(stage==2u||stage==4u)copy_code(((u8 *)&render_work)+4544u,&_NativeKernelROM_START,&_NativeKernelROM_END);
}
#endif
