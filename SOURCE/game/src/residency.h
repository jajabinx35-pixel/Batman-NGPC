#ifndef BATMAN_RESIDENCY_H
#define BATMAN_RESIDENCY_H
#include "ngpc_types.h"
#define PLATFORM_RESIDENT_KEYS 678
typedef struct {u8 lookup[PLATFORM_RESIDENT_KEYS],current[128],pending[128],victim;} PlatformResidency;
#define NATIVE_RESIDENT_KEYS 622
typedef struct {u8 lookup[NATIVE_RESIDENT_KEYS];u16 keys[64];u8 clip[64],used[64],pending[64],victim,count;} NativeResidency;
extern const u16 platform_tile_keys[812],native_tile_keys[2323],puzzle_tile_keys[107];
extern u16 graphics_platform_hits,graphics_platform_misses,graphics_native_hits,graphics_native_misses;
#endif
