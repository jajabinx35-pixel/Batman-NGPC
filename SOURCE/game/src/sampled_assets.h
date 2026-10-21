#ifndef SAMPLED_ASSETS_H
#define SAMPLED_ASSETS_H
#include "ngpc_types.h"
typedef struct {u32 start,end,loop;} SampleTrack;
extern const u8 sampled_audio[];
extern const SampleTrack sampled_tracks[18];
#endif
