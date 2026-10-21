#ifndef BATMAN_FAITHFUL_H
#define BATMAN_FAITHFUL_H
#ifdef VM_HOST
#include <stdint.h>
typedef uint8_t u8;typedef int8_t s8;typedef uint16_t u16;typedef int16_t s16;typedef uint32_t u32;typedef int32_t s32;
#else
#include "ngpc_types.h"
#endif
#ifdef VM_HOST
#define VM_ABI
#else
#define VM_ABI __adecl
#endif
#include "stage_work.h"
extern u16 vm_player_state,vm_platform_opcode;
extern u32 d[8],a[8],vm_resume,vm_fault;
extern u8 fn,fz,fv,fc,fx,vm_busy;
extern const u8 original_code[16389],original_map_header[128],original_bob_headers[2440];
extern const u8 axis_map[7872];
u8 VM_ABI vr8(u32 p);u16 VM_ABI vr16(u32 p);u32 VM_ABI vr32(u32 p);
void VM_ABI vw8(u32 p,u8 v);void VM_ABI vw16(u32 p,u16 v);void VM_ABI vw32(u32 p,u32 v);
void vm_exec(u16 entry);int vm_external(u32 pc);void vm_reset(u8 checkpoint);
void stage_memory_init(u8 stage);
void vnz(u32 v,u8 bits);void vcompare(u32 v,u32 w,u8 bits);
u32 vadd(u32 v,u32 w,u8 bits,u8 extend);u32 vsub(u32 v,u32 w,u8 bits,u8 extend);
u32 vshift(u32 v,u8 count,u8 bits,u8 mode);
#ifdef VM_HOST
extern int (*vm_callback)(u32);
#endif
#endif
