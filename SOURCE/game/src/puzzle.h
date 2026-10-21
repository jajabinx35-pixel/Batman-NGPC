#ifndef BATMAN_PUZZLE_H
#define BATMAN_PUZZLE_H
#include "faithful.h"
#define puzzle_ram (stage_work.puzzle)
extern const u8 puzzle_code[6144];
u8 pvr8(u32 p);u16 pvr16(u32 p);u32 pvr32(u32 p);
void pvw8(u32 p,u8 v);void pvw16(u32 p,u16 v);void pvw32(u32 p,u32 v);
void puzzle_reset(u16 seed);void puzzle_exec(u16 entry);int puzzle_external(u32 pc);
void puzzle_new(void);void puzzle_tick(u8 keys,u8 pressed);void puzzle_draw(void);
#endif
