#ifndef BATMAN_AUDIO_H
#define BATMAN_AUDIO_H
#include "ngpc_types.h"
extern u8 audio_enabled;
void audio_music(u8 track);
void audio_intro_start(void);u16 audio_intro_frame(void);
void audio_init(void);
void audio_stop(void);
void audio_effect(u8 effect);
void audio_frame(void);
void audio_vblank(void);
#endif
