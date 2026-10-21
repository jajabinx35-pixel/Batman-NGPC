#ifndef BATMAN_CATHEDRAL_H
#define BATMAN_CATHEDRAL_H
#include "faithful.h"
extern const u8 cat_original_code[17157],cat_map_header[128],cathedral_map[17864];
u8 VM_ABI cvr8(u32 p);u16 VM_ABI cvr16(u32 p);u32 VM_ABI cvr32(u32 p);
void VM_ABI cvw8(u32 p,u8 v);void VM_ABI cvw16(u32 p,u16 v);void VM_ABI cvw32(u32 p,u32 v);
void cat_exec(u16 entry);int cat_external(u32 pc);void cat_reset(u8 checkpoint);
void cat_new(void);void cat_tick(u8 keys,u8 pressed);
u8 cat_map_read(u16 index);u8 cat_map_take_dirty(void);
#endif
