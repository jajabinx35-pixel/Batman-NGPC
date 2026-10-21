#ifndef BATMAN_NATIVE_VIDEO_H
#define BATMAN_NATIVE_VIDEO_H
#include "game.h"
typedef struct {s8 x,y;u8 palette,pad;u16 pixels[8],mono[8],shifted;} NativeTile;
typedef struct {u32 address;u16 first;u8 count,width,height,decor;} NativeFrame;
extern const u16 native_vehicle_shifted[];
extern const NativeTile native_vehicle_tiles[],native_puzzle_tiles[];
extern const NativeFrame native_vehicle2_frames[],native_vehicle4_frames[],native_puzzle_frames[22];
extern const u16 native_vehicle2_count[1],native_vehicle4_count[1];
extern const u16 native_vehicle_palettes[64],native_puzzle_palettes[52];
extern const u16 native_sky_pixels[960],native_sky_palettes[64];
extern const u8 native_sky_pal[120];
extern const u16 native_puzzle_bg_pixels[],native_puzzle_bg_map[200],native_puzzle_bg_count[1],native_puzzle_bg_palettes[64];
extern u8 bitmap_building;
extern s16 vehicle_road_y;
extern u16 native_fallbacks,native_missing_frames;
void native_start(void);
void native_present(void);void native_restore(void);
void native_puzzle_draw(void);
void bitmap_begin(void);
void bitmap_prepare(void);
void vehicle_draw_bob(void);
void vehicle_draw_column(void);
void vehicle_draw_road_row(void);
void vehicle_draw_skyline(void);
#endif
