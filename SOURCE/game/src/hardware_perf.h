#ifndef BATMAN_HARDWARE_PERF_H
#define BATMAN_HARDWARE_PERF_H
#ifndef HW_PERF
#define HW_PERF 0
#endif
#ifndef HW_PERF_VERSION
#define HW_PERF_VERSION 18
#endif
#if HW_PERF
#include "ngpc_types.h"
typedef struct {
 u16 start,refreshes,updates,source_updates,presents,last_step,last_present;
 u16 step_gaps[5],draw_gaps[5],max_step_gap,max_draw_gap;
 u16 peak_sprites,overflow_start,overflows,irq,blocks_start,blocks,underruns_start,underruns,fill_max;
 u16 platform_hit_start,platform_miss_start,native_hit_start,native_miss_start;
 u16 hits,misses;
 u16 rtc_start,rtc_seconds;
 u32 pattern_bytes,pattern_scan_bytes,descriptor_bytes;
 u8 armed,live,timed_out,pcm_min,pcm_max,rtc_warning;
} HardwarePerf;
extern volatile u16 perf_clock;
extern HardwarePerf hardware_perf;
extern u8 hardware_test;
extern volatile u8 video_present_ready;
extern u16 perf_codec_failures,perf_codec_checked;
void perf_audio_selftest(void);void perf_audio_palette(u32 src);
void perf_arm(void);void perf_before_step(void);void perf_after_step(void);
void perf_present(void);void perf_finish(void);u8 perf_done(void);
void perf_input(u8 *keys,u8 *pressed);
void perf_diff_words(u32 dst,u32 src,u32 words);
void video_perf_reset(void);void video_perf(u8 page);void video_perf_menu(void);void video_sound_test(u8 channel);
void sampled_test(u8 channel);
#define PERF_VBLANK() (perf_clock++)
#define PERF_PRESENT() perf_present()
#define PERF_UPLOAD(n) do{if(hardware_perf.live)hardware_perf.pattern_bytes+=(n);}while(0)
#define PERF_AUDIO_IRQ() do{if(hardware_perf.live)hardware_perf.irq++;}while(0)
#define PERF_LOGIC() do{if(hardware_perf.live)hardware_perf.source_updates++;}while(0)
#define PERF_PCM_PALETTE(src) do{if(hardware_perf.live)perf_audio_palette((u32)(src));}while(0)
#define PERF_CODEC_CHECK() perf_audio_selftest()
#define PERF_FILL_BEGIN u16 perf_fill_start=perf_clock;
#define PERF_FILL_END do{u16 gap=(u16)(perf_clock-perf_fill_start);if(hardware_perf.live&&gap>hardware_perf.fill_max)hardware_perf.fill_max=gap;}while(0)
#ifndef HW_PERF_IMPLEMENTATION
#define graphics_diff_words perf_diff_words
#endif
#else
#define PERF_VBLANK() ((void)0)
#define PERF_PRESENT() ((void)0)
#define PERF_UPLOAD(n) ((void)0)
#define PERF_AUDIO_IRQ() ((void)0)
#define PERF_LOGIC() ((void)0)
#define PERF_PCM_PALETTE(src) ((void)0)
#define PERF_CODEC_CHECK() ((void)0)
#define PERF_FILL_BEGIN
#define PERF_FILL_END ((void)0)
#endif
#endif
