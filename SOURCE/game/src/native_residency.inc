/* Exact ROM identity and vertical clipping identify resident sprite pixels.
 * Only cache misses are queued for the next VBlank commit. */
#define NC (R.resident)
static void resident_native_reset(void){u8 i;bitmap_clear_words((u32)NC.lookup,(u32)(NATIVE_RESIDENT_KEYS/2u));for(i=0;i<64;i++){NC.keys[i]=65535u;NC.used[i]=0;}NC.victim=NC.count=0;graphics_native_hits=graphics_native_misses=0;}
static void resident_native_begin(void){bitmap_clear_words((u32)NC.used,32ul);NC.count=0;}
static void resident_native_discard(void){u8 i,slot;for(i=0;i<NC.count;i++){slot=NC.pending[i];if(NC.lookup[NC.keys[slot]]==slot+1u)NC.lookup[NC.keys[slot]]=0;NC.keys[slot]=65535u;}resident_native_begin();}
static u16 resident_native_slot(u16 key,u8 clip){u8 found=NC.lookup[key],slot,tries=0;
 if(found){slot=found-1u;if(NC.clip[slot]==clip){NC.used[slot]=1;graphics_native_hits++;return slot;}}
 slot=NC.victim;while(NC.used[slot]){slot=(u8)((slot+1u)&(SPR_LIMIT-1u));if(++tries>=SPR_LIMIT){native_missing_frames++;return 0;}}
 NC.victim=(u8)((slot+1u)&(SPR_LIMIT-1u));
 if(NC.keys[slot]!=65535u&&NC.lookup[NC.keys[slot]]==slot+1u)NC.lookup[NC.keys[slot]]=0;
 NC.keys[slot]=key;NC.clip[slot]=clip;NC.lookup[key]=slot+1u;NC.used[slot]=1;graphics_native_misses++;return(u16)slot|256u;
}
static void resident_native_upload(void){u8 i;PERF_UPLOAD((u32)NC.count*16ul);for(i=0;i<NC.count;i++)ngpc_memcpy_w(0xa000ul+(u32)(SPR_BASE+NC.pending[i])*16ul,(u32)(R.patterns+(u16)i*8u),8ul);NC.count=0;}
#undef NC
