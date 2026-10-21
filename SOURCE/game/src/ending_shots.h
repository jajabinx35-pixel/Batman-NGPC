#ifndef BATMAN_ENDING_SHOTS_H
#define BATMAN_ENDING_SHOTS_H
#include "ngpc_types.h"
typedef struct {const u16 *pixels,*map,*palettes;u16 words;u8 rows;} EndingShot;
extern const EndingShot ending_shots[5];
#endif
