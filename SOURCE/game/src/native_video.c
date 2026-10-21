/* Native2bpp tile/sprite engine for Batmobile,Batcave and Batwing.
 * Original physics, routes and animation select the original frame IDs.
 * No software4bpp framebuffer, RGB quantisation or full-frame pixel conversion.
 * A complete prepared frame is committed by VBlank, with no visible partials. */
#include "native_video.h"
#include "vehicle.h"
#include "puzzle.h"
#include "video.h"
#include "ngpc_gfx.h"
extern u8 active_stage,video_render_requested;
extern volatile u8 g_vb_counter;
extern u8 vehicle_profile[16];
static void road_map_load(void){u8 row,col;u16 id=1;volatile u16 *dst=HW_SCR1_MAP+8u*32u;for(row=0;row<10;row++){for(col=0;col<20;col++)*dst++=id++;dst+=12;}}
extern void native_map_upload(u32 source,u32 destination);
extern void ngpc_memcpy_w(u32 dst,u32 src,u32 words);
extern void graphics_diff_words(u32 dst,u32 src,u32 words);
#include "hardware_perf.h"
extern void bitmap_clear_words(u32 dst,u32 words);
#define R (render_work.native)
#define PLAY_Y (active_stage==3?48:64)
#define ROAD_MAP_ROW (active_stage==3?6u:8u)
#define SPR_BASE (active_stage==3?465u:321u)
#define SPR_LIMIT (active_stage==3?32u:64u)
u8 bitmap_building;
s16 vehicle_road_y;
u16 native_fallbacks,native_missing_frames;
static u8 packed_count,old_packed_count;
u16 graphics_native_hits,graphics_native_misses;
static u8 background_dirty,puzzle_valid,puzzle_cache[34];
static u16 cached_sky_column;
static u8 cached_sky_valid,background_map_valid;
static const u16 left_masks[9]={65535u,16383u,4095u,1023u,255u,63u,15u,3u,0};
#include "native_residency.inc"
#include "skyline_hw.inc"

#include "vehicle_complete_frames.inc"
static void palette(u8 plane,const u16 *p,u8 count){u8 i;for(i=0;i<count;i++)ngpc_gfx_set_palette(plane,i,p[i*4u],p[i*4u+1u],p[i*4u+2u],p[i*4u+3u]);}
void native_start(void){u16 i;static const u16 zero[8]={0,0,0,0,0,0,0,0};
 resident_native_reset();bitmap_building=packed_count=old_packed_count=0;bitmap_clear_words((u32)R.descriptors,128ul);puzzle_valid=0;native_fallbacks=native_missing_frames=0;cached_sky_valid=0;background_map_valid=0;
 ngpc_gfx_load_tiles_at(zero,8,0);if(active_stage==3)for(i=0;i<200;i++)R.map[i]=(u16)(i+1u);
 if(active_stage==3){
  /* Restore SCR2 vertical scroll after either vehicle stage. */
  ngpc_gfx_scroll(1,0u,0u);
  ngpc_gfx_load_tiles_at(native_puzzle_bg_pixels,(u16)(native_puzzle_bg_count[0]*8u),201);
  palette(1,native_puzzle_bg_palettes,16);palette(0,native_puzzle_palettes,13);palette(2,native_puzzle_palettes,13);
  for(i=0;i<200;i++)HW_SCR2_MAP[((6u+i/20u)<<5)+(i%20u)]=native_puzzle_bg_map[i];
 }else{
  /* Hardware compositing: SCR2 behind SCR1, transparent ink 0.  No
     framebuffer prefills, no moving skyline over the Batmobile or Batwing. */
  HW_SCR_PRIO &= (u8)~0x80u;
  ngpc_gfx_scroll(1,0u,0u);
  ngpc_gfx_load_tiles_at(skyline_hw_patterns,960u,201u);
  ngpc_gfx_set_palette(1,0,RGB(0,0,0),RGB(15,10,2),RGB(5,7,9),RGB(13,14,15));
  palette(2,native_vehicle_palettes,16);
  ngpc_gfx_set_palette(0,0,RGB(0,0,0),RGB(15,10,2),RGB(5,7,9),RGB(13,14,15));
  /* 32-map-column repetition covers the visible 20 columns; the city is
     installed only once per stage.  At pixel level the road plane wins. */
  for(i=0;i<32u*19u;i++)HW_SCR2_MAP[i]=0;
  for(i=0;i<6u*32u;i++)HW_SCR2_MAP[6u*32u+i]=(u16)(201u+(i/32u)*20u+(i%32u)%20u);
 }
}
void bitmap_begin(void){u16 i;u8 before=g_vb_counter;
 bitmap_building=(u8)(video_render_requested&&video_bitmap_available());if(!bitmap_building)return;
 resident_native_begin();old_packed_count=packed_count;packed_count=0;vehicle_profile[13]=0;
 if(active_stage!=3){background_dirty=1;bitmap_clear_words((u32)R.road,1600ul); }
 vehicle_profile[14]=(u8)(g_vb_counter-before);
}
/* Grapple corner exit: source $5712 clears all four Amiga bitplanes.
 * No VRAM is exposed until the replacement native frame is complete. */
void vehicle_clear_display(void){if(!bitmap_building)return;resident_native_discard();background_dirty=1;packed_count=0;bitmap_clear_words((u32)R.road,1600ul);bitmap_clear_words((u32)R.descriptors,128ul);}
/* Store one native pixel. Used only for the sparse balloon cord geometry. */
static void pixel(s16 x,s16 y,u8 colour){u16 __near *p;u16 shift,mask;
 if(x<0||x>=160||y<0||y>=76)return;
 p=(u16 __near *)R.road+((u16)y>>3)*160u+((u16)x>>3)*8u+((u16)y&7u);shift=(u16)(14u-((u16)x&7u)*2u);mask=(u16)(3u<<shift);*p=(u16)((*p&~mask)|((u16)colour<<shift));
}
static void span(s16 left,s16 right,s16 y){u16 __near *p;u16 first,last,mask;
 if(y<0||y>=76||left>=160||right<=0||left>=right)return;if(left<0)left=0;if(right>160)right=160;
 first=(u16)left>>3;last=(u16)(right-1)>>3;p=(u16 __near *)R.road+((u16)y>>3)*160u+first*8u+((u16)y&7u);
 mask=left_masks[(u16)left&7u];
 if(first==last){mask&=(u16)~left_masks[((u16)(right-1)&7u)+1u];*p=(u16)((*p&~mask)|(0xaaaau&mask));return;}
 *p=(u16)((*p&~mask)|(0xaaaau&mask));p+=8;
 while(++first<last){*p=0xaaaau;p+=8;}
 mask=(u16)~left_masks[((u16)(right-1)&7u)+1u];*p=(u16)((*p&~mask)|(0xaaaau&mask));
}
void vehicle_draw_road_row(void){s16 y,left,right,x;u8 i;u16 at;
 if(bitmap_building){y=vehicle_road_y;if(y>=0&&y<152&&!(y&1)){
  at=(u16)(a[5]-0x7bc8ul);left=(s16)*(u16 *)(vehicle_projection+at)>>1;right=(s16)*(u16 *)(vehicle_projection+at+1024u)>>1;span(left,right,y>>1);
  for(i=0;i<5;i++){
   if((i==0&&(d[5]&0x10000ul))||(i==4&&(d[5]&0x20000ul)))continue;
   if(i>0&&i<4&&(*(u16 *)(vehicle_state+586u)||*(u16 *)(vehicle_state+588u)))continue;
   x=(s16)*(u16 *)(vehicle_projection+at+(u16)i*256u)>>1;pixel(x,y>>1,3);
  }
 }}vehicle_road_y--;a[5]+=2ul;a[0]-=40ul;a[3]-=40ul;d[0]=d[1]=d[2]=d[3]=0;
}
/* M09: equivalent batched road rasterisation: all rows read identical
 * projection samples, in the same order and with the same pixel/edge rules.
 * Called once per translated road section rather than 152 virtual callbacks. */
extern void vehicle_road_rows(u32 road,u32 samples,u32 yc,u32 markers);
extern void vehicle_paint_row(u32 dst,u32 samples,u32 markers);
void vehicle_draw_road_batch(u16 count){
 u16 j,at,markers=31u; s16 y;u16 __near *dst;
 if(!bitmap_building)return;
 if(*(u16 *)(vehicle_state+586u)||*(u16 *)(vehicle_state+588u))markers&=17u;
 if(d[5]&0x10000ul)markers&=30u;if(d[5]&0x20000ul)markers&=15u;
#ifndef VM_HOST
 if(count<=151u){vehicle_road_rows((u32)R.road,(u32)(u16)(vehicle_projection+(u16)(a[5]-0x7bc8ul)),(u32)(u16)vehicle_road_y|((u32)count<<16),(u32)markers);return;}
#endif
 for(j=(u16)vehicle_road_y&1u;j<=count;j+=2u){
  y=(s16)(vehicle_road_y-(s16)j);if(y<0||y>=152)continue;y>>=1;
  at=(u16)(a[5]-0x7bc8ul)+j*2u;
  dst=(u16 __near *)R.road+((u16)y>>3)*160u+((u16)y&7u);
  vehicle_paint_row((u32)(u16)dst,(u32)(u16)(vehicle_projection+at),(u32)markers);
 }
}

void vehicle_draw_skyline(void){if(!bitmap_building||active_stage==4u)return;R.skyx=(u16)(ver16(0x8d44ul)>>1)%320u;R.skyy=(s16)((152-(s16)ver16(0x8d3aul))>>1)-24+PLAY_Y;}
/* Eight original one-bit columns become two native word operations per
 * row. Repeated Amiga pattern rows are decoded once per column, preserving
 * all original masks and opaque/dark cord pixels. */
static void column_inner(void){
 u16 row,col,height,repeat,mask,at,index,shift,word,opaque=0,cached[4],slot;u32 src,bits;u8 valid=0;u16 __near *dst;
 s16 x,y,yy,cell;
 if(!bitmap_building)return;src=ver32(a[4]+4ul);repeat=ver16(a[4]);mask=ver16(a[4]+2ul);height=((u16)d[7]+1u)>>1;
 x=(s16)d[0]>>1;y=((s16)d[2]+1-(s16)d[7])>>1;cell=x>>3;shift=(u16)(x&7)*2u;
 if(cell<-1||cell>=20)return;
 for(col=0;col<8u;col++)if(!(mask&(1u<<(15u-col*2u))))opaque|=(u16)(3u<<(14u-col*2u));
 for(row=0;row<height;row++){
  yy=y+(s16)row;if(yy<0||yy>=76)continue;
  at=(s16)repeat<0?(u16)((row*2u)%3u)*16u:(u16)((row*32u)&repeat);slot=at>>4;
  if(!(valid&(1u<<slot))){
   bits=ver32(src+at)|ver32(src+at+4ul)|ver32(src+at+8ul)|ver32(src+at+12ul);word=0;
   for(col=0;col<8u;col++)if(opaque&(3u<<(14u-col*2u)))word|=(u16)(((bits&(0x80000000ul>>(col*2u)))?3u:1u)<<(14u-col*2u));
   cached[slot]=word;valid|=(u8)(1u<<slot);
  }
  word=cached[slot];index=((u16)yy>>3)*160u+((u16)yy&7u);
  if(cell>=0){dst=(u16 __near *)R.road+index+(u16)cell*8u;*dst=(u16)((*dst&~(opaque>>shift))|(word>>shift));}
  if(shift&&cell<19){dst=(u16 __near *)R.road+index+(u16)(cell+1)*8u;*dst=(u16)((*dst&~(opaque<<(16u-shift)))|(word<<(16u-shift)));}
 }
}
void vehicle_draw_column(void){u8 old=vehicle_profile[15];*(volatile u8 *)(vehicle_profile+15)=9;column_inner();*(volatile u8 *)(vehicle_profile+15)=old;}
/* Native masked tile placement for background objects. Transparent pixels
 * preserve the road. Monochrome scenery shares the road palette, so it never
 * requires colour conversion or a mask/palette scan at runtime. */
extern void native_stamp_frame(u32 tiles,u32 count,u32 xy,u32 limits,u32 road);
extern void native_stamp_rows(u32 dst,u32 src,u32 count,u32 row,u32 flags);
static void stamp_inner(const NativeTile *tile,s16 x,s16 y,s16 top,s16 bottom,u8 colour){
 const u16 *src=colour?tile->pixels:tile->mono;u16 row,w,mask,part,keep,shift,index;u16 __near *dst;s16 yy,col,px;
 x+=tile->x;y+=tile->y;col=x>>3;shift=(u16)(x&7)*2u;
 if(!colour&&tile->shifted!=65535u){
  s16 start=0,end=8,yy;s32 off;u8 flags;
  if(y<top)start=top-y;if(y+start<0)start=-y;if(y+end>bottom)end=bottom-y;if(y+end>76)end=76-y;
  if(start>=end||col<-1||col>=20)return;
  flags=(u8)((col>=0?1:0)|((shift&&col<19)?2:0));if(!flags)return;yy=y+start;
  off=(s32)((u16)yy>>3)*160ul+(s32)col*8+(yy&7);
  native_stamp_rows((u32)(u16)R.road+(u32)(off*2),(u32)(native_vehicle_shifted+(u32)tile->shifted*256ul+(u32)(x&7)*32ul+(u16)start*4u),(u32)(end-start),(u32)(yy&7),(u32)flags);return;
 }

 for(row=0;row<8;row++){
  yy=y+row;if(yy<top||yy>=bottom||yy<0||yy>=76)continue;w=src[row];if(!w)continue;
  mask=(u16)((w|(w>>1))&0x5555u);mask|=(u16)(mask<<1);index=((u16)yy>>3)*160u+((u16)yy&7u);
  if(col>=0&&col<20){part=(u16)(w>>shift);keep=(u16)(mask>>shift);dst=(u16 __near *)R.road+index+(u16)col*8u;*dst=(u16)((*dst&~keep)|part);if(colour)R.map[((u16)yy>>3)*20u+(u16)col]=(u16)((((u16)yy>>3)*20u+(u16)col+1u)|((u16)tile->palette<<9));}
  if(shift&&col>=-1&&col<19){part=(u16)(w<<(16u-shift));keep=(u16)(mask<<(16u-shift));dst=(u16 __near *)R.road+index+(u16)(col+1)*8u;*dst=(u16)((*dst&~keep)|part);if(colour)R.map[((u16)yy>>3)*20u+(u16)(col+1)]=(u16)((((u16)yy>>3)*20u+(u16)(col+1)+1u)|((u16)tile->palette<<9));}
 }
}
#define PROBE (*(volatile u8 *)(vehicle_profile+15))
static void stamp(const NativeTile *tile,s16 x,s16 y,s16 top,s16 bottom,u8 colour){u8 old=PROBE;PROBE=2;stamp_inner(tile,x,y,top,bottom,colour);PROBE=old;}
#include "background_atlas.inc"
/* Junction shape is determined solely by the source road geometry.
 * M26 drew phantom eight-row side roads for ordinary roadside signs.
 * Highlight only the post of actual sign art; never invent a road branch. */
static void original_sign_pole(const NativeFrame *f,s16 x,s16 y,s16 top,s16 bottom){
 u32 at=f->address;u16 col,shift,mask;u16 __near *p;s16 yy,shaft,end;
 if(active_stage!=2||f->height<40)return;
 if(at==0x26be6ul||at==0x28800ul){
  shaft=x+(at<0x28800ul?(s16)f->width-5:4);
  if(shaft<0||shaft>=160)return;
  if(y+4>top)top=y+4;
  end=y+(s16)f->height-1;if(end>bottom)end=bottom;
  if(top<0)top=0;if(end>76)end=76;
  if(top>=end)return;
  col=(u16)shaft>>3;shift=(u16)((shaft&7)*2u);
  mask=(u16)(3u<<(14u-shift));
  for(yy=top;yy<end;yy++){
   p=(u16 __near *)R.road+(((u16)yy>>3)*160u+col*8u+((u16)yy&7u));
   *p=(u16)((*p&~mask)|mask);
  }
 }
}
/* Whole source frames have transparent padding outside their artwork.
 * With the source rectangle on screen, no per-tile clipping or clipped
 * geometry is needed. Preserve the source clip identity in the resident
 * cache, including transparent padding. The asset proof checks every tile.
 * Partial frames retain the general path below. */
static void complete_sprites(const NativeFrame *f,const NativeTile *tiles,const u16 *keys,s16 x,s16 y){
 const NativeTile *t=tiles+f->first;u16 i,slot,at;u16 __near *out;
 for(i=0;i<f->count;i++,t++){
  slot=resident_native_slot(keys[f->first+i],vehicle_complete_clips[f->first+i]);
  if(slot&256u){slot&=63u;out=(u16 __near *)R.patterns+(u16)R.resident.count*8u;
   ngpc_memcpy_w((u32)(u16)out,(u32)t->pixels,8ul);
   R.resident.pending[R.resident.count++]=(u8)slot;
  }
  at=(u16)(63u-packed_count)*2u;R.descriptors[at]=(u16)(SPR_BASE+slot)|0x1800u;
  R.descriptors[at+1u]=(u8)(x+t->x)|((u16)(u8)(y+t->y+PLAY_Y)<<8);
  ((u8 *)R.palettes)[63u-packed_count]=t->palette;packed_count++;
 }
}
static void draw(const NativeFrame *f,const NativeTile *tiles,s16 x,s16 y,u8 sy,u8 height,u8 background,u8 colour){
 const NativeTile *t;u8 i,j,count=0,total=f->count;u16 at,slot,identity,begin,end;const u16 *keys=(tiles==native_vehicle_tiles?native_tile_keys:puzzle_tile_keys);u16 __near *out;s16 tx,ty,top=(s16)(y+sy),bottom=(s16)(y+sy+height),yy;
 if(!background&&(u16)packed_count+total>SPR_LIMIT){
  t=tiles+f->first;for(i=0;i<total;i++,t++){tx=x+t->x;ty=y+t->y;if(tx<=-8||tx>=160||ty+8<=top||ty>=bottom||ty<=-8||ty>=76)continue;count++;}
  if((u16)packed_count+count>SPR_LIMIT){background=1;colour=0;native_fallbacks++;}
 }
 if(!background&&(active_stage==2||active_stage==4)&&height==f->height&&x>=0&&y>=0&&x+(s16)f->width<=160&&y+(s16)f->height<=76&&top<=y&&bottom>=y+(s16)f->height&&(vehicle_complete_frames[f->first>>3]&(1u<<(f->first&7u)))){
  complete_sprites(f,tiles,keys,x,y);return;
 }
 if(background&&!colour&&(f->decor&1u)&&f->count&&(active_stage==2||active_stage==4))if(background_frame(f,x,y,top,bottom)){original_sign_pole(f,x,y,top,bottom);return;}
 if(background&&!colour&&(f->decor&1u)){
  native_stamp_frame((u32)(tiles+f->first),(u32)total,(u32)(u16)x|((u32)(u16)y<<16),(u32)(u16)top|((u32)(u16)bottom<<16),(u32)R.road);original_sign_pole(f,x,y,top,bottom);return;
 }
 t=tiles+f->first;
 for(i=0;i<total;i++,t++){
  tx=x+t->x;ty=y+t->y;if(tx<=-8||tx>=160||ty+8<=top||ty>=bottom||ty<=-8||ty>=76)continue;
  if(background){stamp(t,x,y,top,bottom,colour);continue;}
  begin=0;end=8;if(ty<top)begin=(u16)(top-ty);if(ty+(s16)begin<0)begin=(u16)-ty;if(ty+8>bottom)end=(u16)(bottom-ty);if(ty+(s16)end>76)end=(u16)(76-ty);
  identity=keys[f->first+i];slot=resident_native_slot(identity,(u8)(begin|((end-1u)<<3)));
  if(slot&256u){slot&=63u;out=(u16 __near *)R.patterns+(u16)R.resident.count*8u;
   if(begin==0&&end==8)ngpc_memcpy_w((u32)(u16)out,(u32)t->pixels,8ul);
   else for(j=0;j<8;j++)*out++=(j>=begin&&j<end)?t->pixels[j]:0;
   R.resident.pending[R.resident.count++]=(u8)slot;
  }
  at=(u16)(63u-packed_count)*2u;R.descriptors[at]=(u16)(SPR_BASE+slot)|0x1800u;R.descriptors[at+1u]=(u8)tx|((u16)(u8)(ty+PLAY_Y)<<8);
  ((u8 *)R.palettes)[63u-packed_count]=t->palette;packed_count++;
 }
}
#include "scene_clip.inc"
#include "vehicle_frame_index.inc"
static void draw_bob_inner(void){const NativeFrame *frames,*f;u16 sx,sy,h,page;u8 group,index;u32 id=a[5]-8ul;u16 offset;s16 x,y;u8 before;
 if(!bitmap_building)return;frames=vehicle_stage==2?native_vehicle2_frames:native_vehicle4_frames;
 /* Exact frame slot from the source-asset address, with an address guard.
    Reject unmapped entries exactly as the original binary search did. */
 page=(u16)(id>>12);index=255u;
 if(vehicle_stage==2){
  if(page<70u){group=vehicle2_lookup_page[page];
   if(group!=255u)index=vehicle2_lookup_index[((u16)group<<8)|((u16)(id>>4)&255u)];}
 }else if(page<77u){
  group=vehicle4_lookup_page[page];
  if(group!=255u)index=vehicle4_lookup_index[((u16)group<<8)|((u16)(id>>4)&255u)];
 }
 if(index==255u||frames[index].address!=id){native_missing_frames++;return;}
 f=frames+index;
 /* Fixed 0x37c4 source origin is inside the 200-byte vehicle IO block;
    direct two-word read preserves the original 68000 high/low word order. */
 offset=(u16)(a[0]-(((u32)*(u16 *)(vehicle_io+196u)<<16)|*(u16 *)(vehicle_io+198u)));
 /* M51: use a single quotient for the original 40-pixel row and column split. */
 {u16 tile_row=(u16)(offset/40u);
  y=(s16)tile_row;
  x=(s16)((u16)(offset-(u16)(tile_row*40u))*8u+(u16)d[4]);
 }sx=0;
 if((s16)d[6]>0){sx=((u16)d[6]-1u)*8u;x-=16;}sy=(u16)d[3]?(u16)((u16)d[3]/(u16)(((f->width+7u)>>3)*4u)):0u;h=(u16)(((u16)d[7]+1u)>>1);
 before=g_vb_counter;draw(f,native_vehicle_tiles,(s16)((x>>1)-sx),(s16)((y>>1)-sy),(u8)sy,(u8)h,(u8)(f->decor&1u),0);vehicle_profile[13]+=(u8)(g_vb_counter-before);
}
void vehicle_draw_bob(void){u8 old=PROBE;PROBE=1;draw_bob_inner();PROBE=old;}
void native_puzzle_draw(void){u16 i,j,x,y;u8 id,selected,v;const NativeFrame *f;
 bitmap_begin();if(!bitmap_building)return;background_dirty=(u8)!puzzle_valid;
 for(i=0;i<34;i++){v=i<6?puzzle_ram[24u+i]:puzzle_ram[154u+i];if(puzzle_cache[i]!=v){puzzle_cache[i]=v;background_dirty=1;}}
 if(background_dirty){
 bitmap_clear_words((u32)R.road,1600ul);for(i=0;i<200;i++)R.map[i]=(u16)(i+1u);
 for(id=1;id<=8;id++){
  selected=0;for(j=0;j<3;j++)if(pvr16(0xd846ul+j*2u)==id)selected=1;
  if(!selected){x=id<=4?13u:133u;y=(u16)(((id-1u)&3u)==0?2:((id-1u)&3u)==1?21:((id-1u)&3u)==2?39:58);f=native_puzzle_frames+id;draw(f,native_puzzle_tiles,x,y,0,f->height,1,1);}
 }
 for(i=0;i<21;i++)if((id=puzzle_ram[160u+i])!=0){f=native_puzzle_frames+13u+id;draw(f,native_puzzle_tiles,(s16)(47u+(i/3u)*9u),(s16)(10u+(i%3u)*15u),0,8,1,1);}
 for(i=0;i<7;i++)if(puzzle_ram[181u+i])R.map[6u*20u+6u+i]=(u16)(400u+'0'-32u+puzzle_ram[181u+i]-1u)|(15u<<9);
 puzzle_valid=1;}
 f=native_puzzle_frames;draw(f,native_puzzle_tiles,(s16)(pvr16(0xe124ul)*5u/11u),(s16)(pvr16(0xe128ul)>>1),0,f->height,0,1);
}
void bitmap_prepare(void){u8 i;if(!bitmap_building)return;for(i=(u8)(64u-old_packed_count);i<(u8)(64u-packed_count);i++){R.descriptors[(u16)i*2u]=0;R.descriptors[(u16)i*2u+1u]=0;}video_sprite_count=packed_count;if(video_sprite_count>video_max_sprites)video_max_sprites=video_sprite_count;bitmap_building=0;video_bitmap_publish();}
void native_present(void){u8 row,col;u16 i,scroll;volatile u16 *dst;
 if(background_dirty){
  if(active_stage==2u||active_stage==4u){
   ngpc_memcpy_w(0xa010ul,(u32)R.road,1600ul);
   PERF_UPLOAD(3200ul);
  }else graphics_diff_words(0xa010ul,(u32)R.road,1600ul);
 }
 resident_native_upload();
 graphics_diff_words(0x8800ul,(u32)R.descriptors,128ul);graphics_diff_words(0x8c00ul,(u32)R.palettes,32ul);
 if(background_dirty&&(active_stage==3||!background_map_valid)){if(active_stage==3)native_map_upload((u32)R.map,(u32)(HW_SCR1_MAP+ROAD_MAP_ROW*32u));else road_map_load();background_map_valid=1;}

}

void native_restore(void){u8 old=background_dirty;cached_sky_valid=0;background_map_valid=0;background_dirty=1;native_present();background_dirty=old;}
