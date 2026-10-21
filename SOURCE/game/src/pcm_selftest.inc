/* All nibble levels, mixed with varied music levels including both clipping limits. */
extern void pcm_unpack(u32,u32),pcm_mix(u32,u32),pcm_unpack_mix(u32,u32);
static const u8 pcm_test_encoded[144]={0,17,34,51,68,85,102,119,136,153,170,187,204,221,238,255,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15,240,225,210,195,180,165,150,135,120,105,90,75,60,45,30,15};
void perf_audio_selftest(void){u16 i,pass,want;u8 packed,index;u16 music; s16 mixed;
 volatile u16 *out=(volatile u16 *)0x7200;
 perf_codec_failures=perf_codec_checked=0;
 pcm_unpack(0x7200ul,(u32)pcm_test_encoded);
 for(i=0;i<256u;i++){
  packed=pcm_test_encoded[16u+(i>>1)];index=(i&1u)?packed>>4:packed&15u;
  want=(u16)(pcm_test_encoded[index]*257u);if(out[i]!=want)perf_codec_failures++;perf_codec_checked++;
 }
 for(pass=0;pass<4u;pass++){
  for(i=0;i<256u;i++){music=(i*37u+pass*101u)&255u;out[i]=(u16)(music*257u);}
#if HW_PERF_VERSION==13
  pcm_unpack(0x7600ul,(u32)pcm_test_encoded);pcm_mix(0x7200ul,0x7600ul);
#else
  pcm_unpack_mix(0x7200ul,(u32)pcm_test_encoded);
#endif
  for(i=0;i<256u;i++){
   packed=pcm_test_encoded[16u+(i>>1)];index=(i&1u)?packed>>4:packed&15u;
   music=(i*37u+pass*101u)&255u;mixed=(s16)(music+pcm_test_encoded[index])-128;
   if(mixed<0)mixed=0;if(mixed>255)mixed=255;want=(u16)((u16)mixed*257u);
   if(out[i]!=want)perf_codec_failures++;perf_codec_checked++;
  }
 }
}
