/* Included by video.c, using its existing font and UI primitives. */
#if HW_PERF
static void perf_number(u8 x,u8 y,u32 value){char out[11];u8 i=10;
 out[i]=0;do{out[--i]=(char)('0'+value%10ul);value/=10ul;}while(value&&i);text(x,y,out+i,15);
}
static void perf_rate(u8 y,const char *label,u16 count){u16 n=0;u16 r=hardware_perf.refreshes;
 if(r)n=(u16)(((u32)count*5995ul+(u32)r*5ul)/((u32)r*10ul));
 text(1,y,label,15);perf_number(14,y,n/10u);text(17,y,".",15);perf_number(18,y,n%10u);
}
static void perf_background(void){present_ready=0;ngpc_gfx_set_viewport(0,0,0,0);
 ngpc_sprite_hide_all();ngpc_gfx_scroll(0,0,0);ngpc_gfx_scroll(1,0,0);
 ngpc_gfx_clear(0);ngpc_gfx_clear(1);font_load();
 ngpc_gfx_fill_rect(0,0,0,20,19,SOLID_TILE,15);ngpc_gfx_set_viewport(0,0,160,152);
}
static void perf_heading(void){
#if HW_PERF_VERSION==13
 centered(0,"M13 CONTROL PERF",14);
#elif HW_PERF_VERSION==31
 centered(0,"M54 CLEAR PERF",14);
#elif HW_PERF_VERSION==57
 centered(0,"M57 PLATFORM PERF",14);
#elif HW_PERF_VERSION==63
 centered(0,"M64 SCORE QR DIAG",14);
#elif HW_PERF_VERSION==61
 centered(0,"M61 AUDIO SYNC DIAG",14);
#elif HW_PERF_VERSION==60
 centered(0,"M60 INTRO DIAG",14);
#else
 centered(0,"M30R2 HARDWARE PERF",14);
#endif
 text(1,2,"LEVEL",15);perf_number(7,2,active_stage);text(10,2,audio_enabled?"SOUND ON":"SOUND OFF",14);
}
void video_perf_menu(void){perf_background();perf_heading();
 text(1,4,"L/R: SELECT LEVEL",15);text(1,6,"A: SOUND ON / OFF",15);
 text(1,8,"B: RUN 300 STEPS",14);
#if HW_PERF_VERSION>=14
 text(1,10,"UP: L/R SOUND TEST",15);
#endif
 text(1,12,"SAME INPUT REPLAY",15);text(1,14,"NORMAL CPU CLOCK",15);
 text(1,16,"OPTION: MAIN MENU",15);
}
void video_perf(u8 page){HardwarePerf *p=&hardware_perf;perf_background();perf_heading();
 if(page==0){
  text(1,4,"GAME UPDATES",15);perf_number(15,4,p->source_updates);
  perf_rate(5,"UPDATES/SEC",p->source_updates);perf_rate(6,"DRAWS/SEC",p->presents);perf_rate(7,"STEPS/SEC",p->updates);
  text(1,8,"REFRESHES",15);perf_number(13,8,p->refreshes);
  text(1,9,"PRESENTS",15);perf_number(13,9,p->presents);
  text(1,11,"STEP GAP MAX",15);perf_number(15,11,p->max_step_gap);
  text(1,12,"DRAW GAP MAX",15);perf_number(15,12,p->max_draw_gap);
  text(1,14,p->rtc_warning?"CHECK RTC TIMING":p->timed_out?"TIME LIMIT REACHED":"300 STEPS COMPLETE",14);
 }else if(page==1){
  text(1,4,"PEAK SPRITES",15);perf_number(15,4,p->peak_sprites);
  text(1,5,"SPRITE OVF",15);perf_number(15,5,p->overflows);
  text(1,7,"PATTERN BYTES",15);perf_number(13,8,p->pattern_bytes);
  text(1,9,"VRAM READ BYTES",15);perf_number(13,10,p->pattern_scan_bytes);
  text(1,12,"CACHE HITS",15);perf_number(13,12,p->hits);
  text(1,13,"CACHE MISSES",15);perf_number(13,13,p->misses);
 }else if(page==2){
  text(1,4,"AUDIO DMA IRQ",15);perf_number(15,4,p->irq);
  text(1,6,"DECODED BLOCKS",15);perf_number(15,6,p->blocks);
  text(1,8,"AUDIO UNDERRUNS",15);perf_number(15,8,p->underruns);
  text(1,10,"FILL MAX VBLANKS",15);perf_number(17,10,p->fill_max);
  text(1,12,"DESC/PAL BYTES",15);perf_number(13,13,p->descriptor_bytes);
  if(perf_codec_checked==1280u){text(1,14,"CODEC ERRORS",15);perf_number(15,14,perf_codec_failures);}else text(1,14,"CODEC NOT RUN",14);
  text(1,15,"RTC SECONDS",15);perf_number(15,15,p->rtc_seconds);
 }else{
  text(1,4,"GAP IN REFRESHES",14);text(1,6,"GAP   STEP   DRAW",15);
  {u8 i;for(i=0;i<5;i++){perf_number(2,(u8)(8+i),i);if(i==4)text(3,12,"+",15);perf_number(7,(u8)(8+i),p->step_gaps[i]);perf_number(14,(u8)(8+i),p->draw_gaps[i]);}}
  text(1,14,"PCM RANGE",15);if(p->blocks){perf_number(11,14,p->pcm_min);text(14,14,"/",15);perf_number(15,14,p->pcm_max);}else text(12,14,"OFF",15);
 }
 text(1,16,"L/R PAGE A REPEAT",14);text(1,18,"B: TEST MENU",15);
}
void video_sound_test(u8 channel){perf_background();centered(1,"M30R2 DAC TEST",14);
 centered(5,channel==1?"LEFT DAC":channel==2?"RIGHT DAC":channel==3?"BOTH DACS":"SAMPLED MUSIC",15);
 text(1,9,"A: NEXT CHANNEL",15);text(1,12,"CHECK SPEAKER AND",15);text(1,13,"STEREO HEADPHONES",15);text(1,17,"B: TEST MENU",15);
 text(1,7,perf_codec_checked!=1280u?"CODEC NOT RUN":perf_codec_failures?"CODEC TEST: FAIL":"CODEC TEST: PASS",14);
}
#endif

/* Match each replay from cold pattern memory and an empty best-score HUD. */
#if HW_PERF
extern void bitmap_clear_words(u32 dst,u32 words);
void video_perf_reset(void){bitmap_clear_words(0xa000ul,4096ul);}
#endif
