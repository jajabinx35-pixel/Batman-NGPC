/* The same monochrome frame composed in ROM before runtime horizontal shift.
 * Bounds are native screen rows/columns. All original nonzero pixels remain. */
extern const u32 native_background_offsets[];
extern const u16 native_background_dimensions[],native_background_data[];
extern void native_background_rows(u32 dst,u32 source,u32 rows,u32 columns,u32 row);
static u8 background_frame(const NativeFrame *f,s16 x,s16 y,s16 top,s16 bottom){
 u32 base;u16 dimensions,columns,height,stride,offset,left,count,native_y,destination; s16 start=0,end,col;
 base=native_background_offsets[f->first];if(base==0xfffffffful)return 0;
 dimensions=native_background_dimensions[f->first];columns=dimensions&255u;height=dimensions>>8;end=height;
 /* Exact unclipped case: no per-side clip/stride adjustment required. */
 col=x>>3;
 if(y>=top && y>=0 && y<76 && bottom>=y && height<=(u16)(76-y) && height<=(u16)(bottom-y) && col>=0 && col<20 && columns<=(u16)(20-col)){
  stride=columns*2u;
  offset=(u16)((u16)(x&7)*height*stride);
  destination=(u16)R.road+((u16)y>>3)*320u+(u16)col*16u+((u16)y&7u)*2u;
  native_background_rows((u32)destination,(u32)(native_background_data+base+offset),(u32)height,(u32)columns,(u32)((u16)y&7u));return 1;
 }
 if(y<top)start=top-y;if(y+start<0)start=-y;if(y+end>bottom)end=bottom-y;if(y+end>76)end=76-y;
 if(start>=end)return 1;col=x>>3;if(col>=20||col+(s16)columns<=0)return 1;
 left=col<0?(u16)-col:0u;count=columns-left;if(count>(u16)(20-col-(s16)left))count=(u16)(20-col-(s16)left);
 stride=(u16)(columns*2u);offset=(u16)((u16)(x&7)*height*stride+(u16)start*stride+left*2u);
 native_y=(u16)(y+start);destination=(u16)R.road+(native_y>>3)*320u+(u16)(col+(s16)left)*16u+(native_y&7u)*2u;
 native_background_rows((u32)destination,(u32)(native_background_data+base+offset),(u32)(end-start),(u32)count|((u32)((columns-count)*4u)<<16),(u32)(native_y&7u));return 1;
}
