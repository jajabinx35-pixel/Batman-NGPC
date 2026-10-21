/* M11 native scene traversal. The world simulation and interaction routines
 * remain original. Scenery no longer runs the 68000 register/stack loop. */
#include "vehicle.h"
#include "bitmap.h"
#include "audio.h"
#include "native_video.h"
extern void native_scene_draw(void);
extern void native_scene_draw_prepared(const NativeFrame *frame);
extern const u8 *vehicle_code;
extern const u8 *vehicle_shared,*vehicle_data24;
/* Immutable scenery header width: map only the two proven cartridge banks.
 * General translated reads are kept for odd and unusual addresses. */
static u16 scenery_header_word(u32 address){
 if(!(address&1ul)){
  if(address>=0x1fffcul && address<=0x2a414ul)
   return *(const u16 *)(vehicle_shared+(u16)(address-0x1fffcul));
  if(address>=0x2a416ul && address<=(vehicle_stage==2?0x50042ul:0x56818ul))
   return *(const u16 *)(vehicle_data24+(address-0x2a416ul));
 }
 return ver16(address);
}

extern u8 vehicle_profile[16];
#define PROBE (*(volatile u8 *)(vehicle_profile+15))
extern u32 vehicle_mulu16(u32,u32),vehicle_div16_packed(u32,u32);
#define SW(p) (*(u16 *)(vehicle_state+(u16)((p)-0x8d1eul)))
#define SB(p) (vehicle_state[((u16)((p)-0x8d1eul))^1u])
#define PW(p) (*(u16 *)(vehicle_projection+(u16)((p)-0x7bc8ul)))
#define CW(p) (*(const u16 *)(vehicle_code+(u16)((p)-0x2ffcul)))
#define CB(p) (vehicle_code[((u16)((p)-0x2ffcul))^1u])
#define DW(n) (*(u16 *)&d[n])
#include "vehicle_scenery_q.inc"
#include "vehicle_scene_recipes.inc"
static void scenery(u16 table,u8 kind,u8 depth,u16 row,u16 edge,u16 curve,u8 right){
 u16 pos=(u16)(kind&15u)*16u,q,width,frame_index,recipe;u32 base;
 const NativeFrame *prepared;const u16 *recipes;
 /* The original 68000 clamps the animation scale to frame 8. M18 did
    not need this beyond depth 7 because it omitted the far scenery. */
 frame_index=(u16)(depth>>1);if(frame_index>8u)frame_index=8u;
 /* The two scenery tables live inside the loaded vehicle CODE image.
    Their immutable 32-bit pointers use two 68000-ordered 16-bit words.
    Avoid two general VM address lookups per drawn decoration. */
 recipes=scenery_recipes[vehicle_stage==2?0:1]+((right?256u:0u)+pos+frame_index)*2u;
 recipe=recipes[0];prepared=(const NativeFrame *)0;
 if(recipe!=65535u){
  prepared=(const NativeFrame *)((const u8 *)(vehicle_stage==2?native_vehicle2_frames:native_vehicle4_frames)+recipe);
  base=prepared->address;width=recipes[1];
 }else{
  base=((u32)CW((u16)(table+pos))<<16)|CW((u16)(table+pos+2u));
  base+=(u16)(frame_index<<4);width=scenery_header_word(base);
 }
 /* Eliminate the repeated unsigned multiply + possible 32/16 divide.
    These source-byte parameters are immutable in both loaded vehicle banks. */
 q=scenery_div_table[((u16)scenery_div_class[right][kind&15u]<<8)|CB(curve+depth)];
 if(right)q=(u16)(edge+10u-q-width);else q+=edge;
 if((s16)q>=0){if(q>=304u)return;}else{
  if((s16)(u16)(q+width)<0)return;
  if(!right&&q<(u16)-16)return;
 }
 DW(0)=q;d[6]=0;a[1]=row;a[5]=base+2ul;
 if(prepared)native_scene_draw_prepared(prepared);else native_scene_draw();
}
/* Original balloon-cord clipping in native values. The separate sparse
 * column renderer receives identical source x/y/height/pattern parameters. */
static void cord(u32 object,u16 scale,u16 row){
 u32 frame=ver32(object+32ul)+(scale>>1);u16 x,y,height,cut,base,old;
 x=(u16)(ver16(object+16ul)+ver16(frame));if((s16)x<0||x>=304u)return;
 height=ver16(frame+2ul);if(!height)return;
 y=(u16)(ver16(object+10ul)+height);height=(u16)(height+ver16(frame+4ul)+ver16(object+30ul));
 base=SB((u32)row+67ul);cut=(u16)(SB(row)-base);
 if(cut){if((s16)y<0)cut+=y;else cut-=y;if(cut&&(s16)cut>=0){height--;old=height;height-=cut;if(old<cut)return;height++;goto clipped;}}
 base+=y;if((s16)base<0)return;
clipped:
 old=(u16)(base+1u);if(old<height)height=old;
 DW(0)=x;DW(2)=base;DW(7)=height;a[4]=0x4c6aul+(scale>>1);vehicle_external(0x4b06ul);
}
static void objects(u16 depth,u16 scale,u16 row){
 u32 head,object,base;u16 x,width;
 for(;;){
  head=((u32)SW(0x8f5eul)<<16)|SW(0x8f60ul);
  /* Sorted objects normally occupy the projection tail. The virtual
     big-endian byte ordering is swapped within each native word.
     Retain the original mapper for all other addresses, including a
     list which straddles this region. No entries or AI are skipped. */
  if(head>=0x7bc8ul&&head<0x8158ul){
   u16 off=(u16)(head-0x7bc8ul);
   if(vehicle_projection[off^1u]!=(u8)depth)return;
   if(off<=1418u){
    object=((u32)*(u16 *)(vehicle_projection+off+2u)<<16)|*(u16 *)(vehicle_projection+off+4u);
   }else object=ver32(head+2ul);
  }else{
   if(ver8(head)!=(u8)depth)return;
   object=ver32(head+2ul);
  }
  head+=6ul;SW(0x8f5eul)=(u16)(head>>16);SW(0x8f60ul)=(u16)head;
  base=ver32(object+18ul)+scale;width=ver16(base);x=ver16(object+16ul);
  if((s16)x>=0){if(x>=320u)continue;}else if((s16)(u16)(width+x)<0)continue;
  if(ver16(object+26ul))cord(object,scale,row);
  DW(0)=x;DW(6)=(u16)(ver16(object+10ul)-ver16(object+30ul));a[1]=row;a[5]=base+2ul;
  native_scene_draw();
 }
}
void vehicle_scene_native(void){
 s16 depth;u8 route;u16 row,edge,curve,position,scale;
 if(vehicle_stage==4){PROBE=5;vehicle_exec(0x5f5au);PROBE=0;}
 for(depth=0;depth<21;depth++){SB(0x909ful+(u16)depth)+=56u;SB(0x90e2ul+(u16)depth)+=56u;}
 curve=(u16)(0x7a20u+(SW(0x9078ul)&224u));position=SW(0x9076ul);
 position=(u16)((position&0xff00u)|(u8)((u8)position+83u));
 for(depth=19;depth>=0;depth--){
  scale=(u16)(depth>>1);if(scale>8u)scale=8u;scale<<=4;
  row=(u16)(0x90b2u-(19-depth));edge=(u16)(0x8116u-(19-depth)*4);
  DW(5)=scale;DW(6)=position;DW(7)=(u16)depth;
  a[0]=edge;a[1]=row;a[2]=0x8f74ul;a[3]=curve;
  if(vehicle_stage==2&&depth==0){PROBE=6;vehicle_exec(0x5c9cu);PROBE=0;}
  /* Sorted interactive objects still execute their exact native clip/cord
     path. Only their presentation is interleaved with scenery here. */
  /* The preceding register setup is still valid unless the special
     Batmobile depth-zero boundary ran. Do not publish it twice on each band. */
  if(vehicle_stage==2&&depth==0){
   DW(5)=scale;DW(6)=position;DW(7)=(u16)depth;
   a[0]=edge;a[1]=row;a[2]=0x8f74ul;a[3]=curve;
  }
  objects((u16)depth,scale,row);
  /* Draw both original roadside-decoration passes at every source depth.
     M18 discarded depths 8..19 and visibly removed Gotham scenery. */
  {
   route=SB(0x8f74ul+(s16)position);
   if(route)scenery(0x8baeu,route,(u8)depth,row,PW(edge),curve,0);
   route=SB(0x8f74ul+(s16)(u16)((position&0xff00u)|(u8)((u8)position+32u)));
   if(route)scenery(0x8c5eu,route,(u8)depth,row,PW(edge-2u),curve,1);
  }
  position=(u16)((position&0xff00u)|(u8)((u8)position-1u));
  /* Native scenery bypasses the old VM callbacks that serviced audio.
     Refill between depth bands, keeping the DAC timer/pitch unchanged. */
  if(((u16)depth&3u)==0u)audio_frame();
 }
 DW(7)=65535u;PROBE=8;vehicle_exec(vehicle_stage==2?0x5c9cu:0x5f92u);PROBE=0;
}
