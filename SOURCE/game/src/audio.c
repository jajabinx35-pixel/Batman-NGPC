#include "audio.h"
#include "sampled_audio.h"
#include "ngpc_hw.h"
extern u8 active_stage;
u8 audio_enabled=1;
u32 audio_sample_count;
volatile u16 audio_track_ends;
void audio_vblank(void){sampled_vblank();}
void audio_frame(void){sampled_service();}
void audio_stop(void){sampled_stop();}
void audio_music(u8 track){u8 index;audio_stop();if(!audio_enabled)return;
 if(track==0)index=0;else if(track==1)index=active_stage==1?1:active_stage==2||active_stage==4?2:active_stage==3?3:4;else index=track==2?14:track==3?15:track==14?16:17;sampled_music(index);
}
void audio_intro_start(void){audio_stop();if(audio_enabled)sampled_intro();}
void audio_effect(u8 effect){if(!audio_enabled)return;if(effect<5)effect=5;if(effect>13)effect=13;sampled_effect(effect);}
/* B8 is the PSG/DAC selector: 55=PSG, AA=DAC. B9=AA halts Z80.
 * MAME 0.289 mixes DAC output even in PSG mode; real hardware does not.
 * Keep both bytes at AA for sampled playback, as in Mic's console demo. */
void audio_init(void){
 HW_Z80_CTRL=0xaau;
 HW_AUDIO_MODE=0xaau;
 audio_enabled=1;sampled_init();
}

/* 4966 cinematic VBlank units correspond to 1556 encoded 256-sample
   PCM blocks. Derive cards from DAC completions rather than display refreshes.
   The display may be late, but never drifts from the actual soundtrack. */
u16 audio_intro_frame(void){u16 b=sampled_intro_played();
 if(b>=1556u)return 4966u;
 return (u16)(((u32)b*4966ul+778ul)/1556ul);
}
