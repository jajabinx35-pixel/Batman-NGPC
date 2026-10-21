/* Identical deterministic inputs and counters for M13-control and M14.
 * Only the diagnostic build contains this code. Normal builds pay no cost.
 * Every gameplay update still runs the complete original stage logic.
 */
#define HW_PERF_IMPLEMENTATION 1
#include "hardware_perf.h"
#if HW_PERF
#include "game.h"
#include "video.h"
#include "sampled_audio.h"
#include "hardware_replay.h"
extern u8 active_stage;
extern u16 graphics_platform_hits,graphics_platform_misses,graphics_native_hits,graphics_native_misses;
extern u16 graphics_diff_words(u32 dst,u32 src,u32 words);
volatile u16 perf_clock;
HardwarePerf hardware_perf;
u8 hardware_test;
u16 perf_codec_failures,perf_codec_checked;
/* A self-describing ABI keeps the external observer independent of padding. */
#define PO(member) ((u16)&(((HardwarePerf *)0)->member))
const u16 hardware_perf_offsets[]={sizeof(HardwarePerf),PO(refreshes),PO(updates),PO(source_updates),PO(presents),PO(max_step_gap),PO(max_draw_gap),PO(peak_sprites),PO(overflows),PO(irq),PO(blocks),PO(underruns),PO(fill_max),PO(hits),PO(misses),PO(pattern_bytes),PO(pattern_scan_bytes),PO(descriptor_bytes),PO(rtc_seconds),PO(rtc_warning),PO(pcm_min),PO(pcm_max),PO(live),PO(armed)};
#undef PO
#include "pcm_selftest.inc"
/* Read-only RTC cross-check: independent of serviced VBlank interrupts.
   Quantisation is one second; a report permits at most 65 refreshes of error. */
static u16 rtc_seconds(void){u8 s,t,m;
 do{s=*(volatile u8 *)0x96;m=*(volatile u8 *)0x95;t=*(volatile u8 *)0x96;}while(s!=t);
 s=(u8)((s>>4)*10u+(s&15u));m=(u8)((m>>4)*10u+(m&15u));
 if(s>59u||m>59u)return 65535u;return(u16)m*60u+s;
}
void perf_audio_palette(u32 src){const u8 *q=(const u8 *)src;u8 i,v;
 for(i=0;i<16u;i++){v=q[i];if(v<hardware_perf.pcm_min)hardware_perf.pcm_min=v;if(v>hardware_perf.pcm_max)hardware_perf.pcm_max=v;}
}
static void gap(u16 delta,u16 *bins,u16 *maximum){
 if(delta>*maximum)*maximum=delta;
 if(delta>4u)delta=4u;bins[delta]++;
}
void perf_arm(void){u8 *p=(u8 *)&hardware_perf;u16 i;
 for(i=0;i<sizeof(hardware_perf);i++)p[i]=0;
 hardware_test=1;hardware_perf.armed=1;hardware_perf.pcm_min=255u;
}
void perf_before_step(void){HardwarePerf *p=&hardware_perf;u16 now=perf_clock;
 if(p->armed){
  p->armed=0;p->start=p->last_step=p->last_present=now;p->live=1;
  p->rtc_start=rtc_seconds();
  p->overflow_start=video_overflows;p->blocks_start=sampled_blocks;p->underruns_start=sampled_underruns;
  p->platform_hit_start=graphics_platform_hits;p->platform_miss_start=graphics_platform_misses;
  p->native_hit_start=graphics_native_hits;p->native_miss_start=graphics_native_misses;
 }else if(p->live)gap((u16)(now-p->last_step),p->step_gaps,&p->max_step_gap);
 p->last_step=now;
}
void perf_after_step(void){if(hardware_perf.live)hardware_perf.updates++;}
void perf_present(void){HardwarePerf *p=&hardware_perf;u16 now=perf_clock;
 if(!p->live)return;
 if(p->presents)gap((u16)(now-p->last_present),p->draw_gaps,&p->max_draw_gap);
 p->last_present=now;p->presents++;
 if(video_sprite_count>p->peak_sprites)p->peak_sprites=video_sprite_count;
}
u8 perf_done(void){HardwarePerf *p=&hardware_perf;
 if(!p->live)return 0;
 if(p->updates>=300u)return 1;
 if((u16)(perf_clock-p->start)>=3600u){p->timed_out=1;return 1;}
 return 0;
}
void perf_finish(void){HardwarePerf *p=&hardware_perf;p->live=0;
 p->refreshes=(u16)(perf_clock-p->start);
 p->overflows=(u16)(video_overflows-p->overflow_start);
 p->blocks=(u16)(sampled_blocks-p->blocks_start);
 p->underruns=(u16)(sampled_underruns-p->underruns_start);
 p->hits=(u16)(graphics_platform_hits-p->platform_hit_start)+(u16)(graphics_native_hits-p->native_hit_start);
 p->misses=(u16)(graphics_platform_misses-p->platform_miss_start)+(u16)(graphics_native_misses-p->native_miss_start);
 {u16 rtc=rtc_seconds(),ticks;
  if(rtc==65535u||p->rtc_start==65535u){p->rtc_warning=1;p->rtc_seconds=65535u;}
  else{p->rtc_seconds=rtc>=p->rtc_start?rtc-p->rtc_start:rtc+3600u-p->rtc_start;
   ticks=p->rtc_seconds*60u;p->rtc_warning=(u8)(ticks>p->refreshes?ticks-p->refreshes>65u:p->refreshes-ticks>65u);
  }
 }
}
void perf_input(u8 *keys,u8 *pressed){u16 tick=game.ticks;u8 now=0,before=0;
 if(tick<300u)now=hardware_replay[active_stage-1u][tick];
 if(tick&&tick<=300u)before=hardware_replay[active_stage-1u][tick-1u];
 *keys=now;*pressed=(u8)(now&~before);
}
void perf_diff_words(u32 dst,u32 src,u32 words){u16 bytes=graphics_diff_words(dst,src,words);
 if(!hardware_perf.live)return;
 if(dst>=0xa000ul&&dst<0xc000ul){hardware_perf.pattern_bytes+=bytes;hardware_perf.pattern_scan_bytes+=words*2ul;}
 else hardware_perf.descriptor_bytes+=bytes;
}
#endif
