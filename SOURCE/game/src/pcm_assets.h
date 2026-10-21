#ifndef PCM_ASSETS_H
#define PCM_ASSETS_H
#include "ngpc_types.h"
typedef struct {u32 start,end,loop;u8 mono;} PcmTrack;
#define PCM_BANK_CUT 366302ul
extern const u8 pcm_bank0[366302],pcm_bank1[2097152];
extern const PcmTrack pcm_tracks[16];
#endif
