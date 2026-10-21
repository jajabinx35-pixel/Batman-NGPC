/* Original-player sample captures. Timer1 -> DMA0 -> both hardware DACs.
 * $7000..$71EF: RAM decoder; $71F0..$71FF: block lookup.
 * $7200..$75FF: two 256-word halves; no decoded-effect scratch pass.
 * The Z80 is reset. $7800..$7FFF is the TLCS stack, below the initial SP.
 */
#include "sampled_audio.h"
#include "sampled_assets.h"
#include "ngpc_hw.h"
#include "hardware_perf.h"
extern u8 audio_enabled;
extern const u8 intro_native_pcm_data[];
extern u32 audio_sample_count;
extern volatile u16 audio_track_ends;
extern void pcm_unpack_mix(u32 dst,u32 encoded),pcm_unpack(u32 dst,u32 encoded),pcm_mix(u32 dst,u32 effect),pcm_silence(u32 dst),pcm_dma_arm(u32 source);
static const u8 *music_next,*music_end,*music_loop,*fx_next,*fx_end;
static volatile u8 active,music_active,fx_active,refill_pending,refilling;
static u8 intro_active;
static u16 intro_block;
/* Progress is counted at DMA completion, i.e. samples actually sent to the DAC,
   NOT blocks decoded into the two prefilled buffers. IRQ-owned clock prevents
   hardware video/audio clock drift from desynchronising the cinematic cards. */
volatile u16 intro_played_blocks;
static volatile u8 intro_playback_clock;
static u8 playing,fx_priority;
#if HW_PERF
static u8 test_tone;
#endif
volatile u16 sampled_blocks,sampled_effect_blocks,sampled_underruns;
static void fill(u8 half){u32 dst=0x7200ul+(half?512ul:0ul);PERF_FILL_BEGIN
 /* M60: reuse the original fast hardware-DAC codec for the new 8-bit MIDI.
    16-byte PCM palette + 128 nibbles => 256 samples per 144-byte block.
    No slow alternate C decoder, new RAM or new audio DMA configuration. */
 if(intro_active){
  if(intro_block<1556u){
   pcm_unpack(dst,(u32)(intro_native_pcm_data+(u32)intro_block*144ul));
   intro_block++;
  }else{
   intro_active=0;
   pcm_silence(dst);
   audio_track_ends++;
  }
  sampled_blocks++;audio_sample_count+=256;
  PERF_FILL_END;
  return;
 }
 if(music_active&&music_next>=music_end){if(music_loop){music_next=music_loop;audio_track_ends++;}else music_active=0;}
 if(music_active){PERF_PCM_PALETTE(music_next);pcm_unpack(dst,(u32)music_next);music_next+=144;}else pcm_silence(dst);
 if(fx_active){if(fx_next>=fx_end)fx_active=0;else{pcm_unpack_mix(dst,(u32)fx_next);fx_next+=144;sampled_effect_blocks++;}}
 sampled_blocks++;audio_sample_count+=256;PERF_FILL_END;
}
static void __interrupt sampled_irq(void){u8 finished;PERF_AUDIO_IRQ();
 if(!active||!audio_enabled){HW_DMA0V=0;HW_TRUN&=(u8)~2u;return;}
 if(refill_pending||refilling)sampled_underruns++;
 /* The PCM decoder runs ahead by two buffers. Only DMA completion marks
    256 samples as genuinely played. The final decode may already have
    disabled intro_active while the last samples are still in flight. */
 if(intro_playback_clock && intro_played_blocks<1556u)intro_played_blocks++;
 finished=playing;playing^=1;pcm_dma_arm(0x7200ul+(playing?512ul:0ul));
#if HW_PERF
 if(test_tone)return;
#endif
 refill_pending=(u8)(finished+1u);
}
void sampled_service(void){u8 half;
 if(!active||!refill_pending)return;
 __asm("di");
 /* VBlank can consume the pending half between the fast test and DI. */
 if(!active||!refill_pending||refilling){__asm("ei 0");return;}
 half=(u8)(refill_pending-1u);refill_pending=0;refilling=1;__asm("ei 0");fill(half);refilling=0;
}
/* ISR fallback: ordinary gameplay may stay in one native/translated routine
 * longer than a sample half. VBlank services the completed half too, after
 * graphics commit. Main sets refilling before re-enabling interrupts, so this
 * path cannot re-enter its decoder. Snapshot ownership atomically, restoring
 * the mandatory NGPC VBlank priority 4; never execute EI 0 inside this ISR.
 * A pending half serviced each display period is ready before the next DMA
 * completion. The DMA IRQ remains the only owner of buffer playback switches.
 */
void sampled_vblank(void){u8 half;
 if(!active||!refill_pending||refilling)return;
 __asm("di");
 if(!active||!refill_pending||refilling){__asm("ei 4");return;}
 half=(u8)(refill_pending-1u);refill_pending=0;refilling=1;
 __asm("ei 4");
 fill(half);refilling=0;
}
void sampled_stop(void){active=music_active=fx_active=intro_active=intro_playback_clock=0;refill_pending=refilling=0;
#if HW_PERF
 test_tone=0;
#endif
 HW_DMA0V=0;HW_TRUN&=(u8)~2u;HW_INTETC01&=0xf0u;*(volatile u16 *)0xa2=0x8080u;}
void sampled_init(void){
 sampled_stop();
 HW_INT_DMA0=sampled_irq;HW_TRUN&=(u8)~3u;HW_T01MOD=4u;HW_TREG1=10;
 /* Own timer 0/1 explicitly: independent 8-bit mode, no CPU timer IRQ.
    Timer 1 requests microDMA; only DMA-complete interrupts reach the CPU. */
 *(volatile u8 *)0x73=0;HW_TRDC&=(u8)~1u;
 PERF_CODEC_CHECK();
}
u16 sampled_intro_played(void){u16 n;
 __asm("di");n=intro_played_blocks;__asm("ei 0");return n;
}
void sampled_intro(void){
 sampled_stop();if(!audio_enabled)return;
 intro_block=0;intro_played_blocks=0;intro_active=1;intro_playback_clock=1;playing=0;
 fill(0);fill(1);HW_INT_DMA0=sampled_irq;
 HW_INTETC01=(u8)((HW_INTETC01&0xf0u)|5u);
 active=1;pcm_dma_arm(0x7200ul);HW_TRUN|=0x82u;
}
void sampled_music(u8 index){const SampleTrack *t;
 sampled_stop();if(!audio_enabled||index>=18)return;t=sampled_tracks+index;music_next=sampled_audio+t->start;music_end=sampled_audio+t->end;music_loop=t->loop==0xfffffffful?(const u8 *)0:sampled_audio+t->loop;
 music_active=1;playing=0;fill(0);fill(1);HW_INT_DMA0=sampled_irq;HW_INTETC01=(u8)((HW_INTETC01&0xf0u)|5u);active=1;pcm_dma_arm(0x7200ul);HW_TRUN|=0x82u;
}
void sampled_effect(u8 index){const SampleTrack *t;
 if(!active||!audio_enabled||index<5||index>13)return;if(fx_active&&index<fx_priority)return;t=sampled_tracks+index;
 __asm("di");fx_next=sampled_audio+t->start;fx_end=sampled_audio+t->end;fx_priority=index;fx_active=1;__asm("ei 0");
}
#if HW_PERF
void sampled_test(u8 channel){u16 i,value;u8 sample;volatile u16 *out=(volatile u16 *)0x7200;
 if(channel==4u){sampled_music(0);return;}
 sampled_stop();*(volatile u8 *)0xb8=0xaau;
 for(i=0;i<512u;i++){
  sample=(i&7u)<4u?176u:80u;
  value=channel==1u?(u16)(128u|((u16)sample<<8)):channel==2u?(u16)(sample|0x8000u):(u16)(sample|((u16)sample<<8));
  out[i]=value;
 }
 test_tone=1;active=1;playing=0;HW_INTETC01=(u8)((HW_INTETC01&0xf0u)|5u);pcm_dma_arm(0x7200ul);HW_TRUN|=0x82u;
}
#endif
