/* M57 experimental generation-tagged sprite residency.
 * Previously pinned tiles (epoch-1) and newly pinned (epoch) may not be
 * evicted; expired slots are reusable. The hardware sprite pattern bytes,
 * sprite descriptors and original keys are never changed by this refactor.
 */
extern void bitmap_clear_words(u32 dst,u32 words);
#define PC (render_work.platform.resident)
static void resident_platform_reset(void){
 bitmap_clear_words((u32)&PC,467ul);PC.victim=0;
 PC.pending[0]=1;graphics_platform_hits=graphics_platform_misses=0;
}
static void resident_platform_begin(void){
 u8 i,epoch=PC.pending[0];
 if(epoch==255u){
  for(i=0;i<128u;i++)PC.current[i]=(u8)(PC.current[i]==255u?1u:0u);
  epoch=1u;
 }
 PC.pending[0]=(u8)(epoch+1u);
}
static u16 resident_platform_slot(u16 key,const u16 *pixels){
 u16 old;u8 slot,tries=0,epoch=PC.pending[0];
 slot=PC.lookup[key];if(slot){slot--;PC.current[slot]=epoch;graphics_platform_hits++;return slot;}
 slot=PC.victim;
 while((u8)(epoch-PC.current[slot])<=1u){
  slot=(u8)((slot+1u)&127u);if(++tries>=128u){video_overflows++;return 0;}
 }
 PC.victim=(u8)((slot+1u)&127u);old=sprite_cache[slot];if(old!=65535u)PC.lookup[old]=0;
 sprite_cache[slot]=key;PC.lookup[key]=(u8)(slot+1u);PC.current[slot]=epoch;
 ngpc_memcpy_w(0xa000ul+(u32)(ACTOR_BASE+slot)*16ul,(u32)pixels,8ul);
 PERF_UPLOAD(16ul);video_tile_writes++;graphics_platform_misses++;return slot;
}
static void resident_platform_commit(void){/* tags are committed as tiles are used */}
#undef PC
