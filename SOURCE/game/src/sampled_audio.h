#ifndef SAMPLED_AUDIO_H
#define SAMPLED_AUDIO_H
#include "ngpc_types.h"
void sampled_init(void);void sampled_stop(void);void sampled_music(u8 index);
void sampled_intro(void);u16 sampled_intro_played(void);void sampled_effect(u8 index);void sampled_service(void);void sampled_vblank(void);
extern volatile u16 sampled_blocks,sampled_effect_blocks,sampled_underruns;
#endif
