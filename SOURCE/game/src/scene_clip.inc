/* Original clip geometry in native local words. Exposed registers retain
 * their original values, including high halves and clipped-away frames. */
extern const u32 vehicle2_frame_keys[],vehicle4_frame_keys[];
extern const u16 vehicle2_frame_indices[],vehicle4_frame_indices[],vehicle2_frame_mask[1],vehicle4_frame_mask[1];
static const NativeFrame *scene_frame(u32 id){const u32 *keys;const u16 *indices;const NativeFrame *frames;u16 slot,mask,tries=0;
 if(vehicle_stage==2){keys=vehicle2_frame_keys;indices=vehicle2_frame_indices;frames=native_vehicle2_frames;mask=vehicle2_frame_mask[0];}
 else{keys=vehicle4_frame_keys;indices=vehicle4_frame_indices;frames=native_vehicle4_frames;mask=vehicle4_frame_mask[0];}
 slot=(u16)((id>>1)^(id>>9))&mask;while(keys[slot]){if(keys[slot]==id)return frames+indices[slot];slot=(slot+1u)&mask;if(++tries>mask)break;}return(const NativeFrame *)0;
}
#define SCB(p) (vehicle_state[((u16)((p)-0x8d1eul))^1u])
#define SDW(n) (*(u16 *)&d[n])
void native_scene_draw_prepared(const NativeFrame *f){u16 w0=SDW(0),w1,w2,w3=0,w4,w5,w6=SDW(6),w7,old,count,source_words,top,sy;s16 source_x=(s16)w0,native_y;u8 draw_it=0,clear6=0;
 source_words=(u16)((f->width+7u)>>3);w4=source_words;w5=(u16)(source_words*2u);w7=(u16)((u16)f->height*2u-((f->decor>>1)&1u));a[5]+=6;
 w1=SCB(a[1]);w2=SCB(a[1]+67ul);w1=(u16)(w1-w2);
 if(w1){if((s16)w6<0)w1+=w6;else w1-=w6;w6=w1;if(w6&&(s16)w6>=0){w7--;old=w7;w7-=w6;if(old<w6)goto writeback;w7++;goto clip_top;}}
 old=w2;w2=(u16)(w2+w6);if((s16)w2<0){fx=fc=(u8)(w2<old);fn=1;fz=0;fv=(u8)((~(old^w6)&(old^w2)&32768u)!=0);goto writeback;}
clip_top:
 w1=(u16)(w2+1u);old=w1;w1-=w7;if(old<w7){w7+=w1;w1=(u16)(0u-w1);count=w1;w1--;w3=(u16)(count*w5);w1=65535u;}a[6]=0x4ec0ul;w1=(u16)((s16)w0>>4);
 if((s16)w1<0){w1+=w4;w6=w1;w6=(u16)(0u-w6);w6+=w4;w0&=15u;}
 else{clear6=1;w6=0;w1+=w4;old=w1;w1-=20u;if(old>=20u){w1-=w4;w1=(u16)(0u-w1);w6=65535u;}else w1=w4;}
 top=(u16)(w2+1u-w7);sy=w3?(count<=1023u?(u16)(count>>1):(u16)(w3/(source_words*4u))):0u;native_y=(s16)((top>>1)-sy);w2=top;w4=w2;w2<<=2;w2+=w4;w2<<=3;w4=w0;w0>>=3;w0&=65534u;old=w0;w0=(u16)(w0+w2);fx=(u8)(w0<old);
 a[0]=((u32)*(u16 *)(vehicle_io+196u)<<16)|*(u16 *)(vehicle_io+198u);a[0]+=(s16)w0;w4&=15u;fn=0;fz=(u8)(w4==0);fv=fc=0;draw_it=1;
writeback:
 SDW(0)=w0;SDW(1)=w1;SDW(2)=w2;d[3]=w3;SDW(4)=w4;SDW(5)=w5;if(clear6)d[6]=w6;else SDW(6)=w6;SDW(7)=w7;
 if(draw_it&&bitmap_building)draw(f,native_vehicle_tiles,(s16)(source_x>>1),native_y,(u8)sy,(u8)((w7+1u)>>1),(u8)(f->decor&1u),0);
}
void native_scene_draw(void){const NativeFrame *f=scene_frame(a[5]-2ul);if(!f){native_missing_frames++;return;}native_scene_draw_prepared(f);}
#undef SCB
#undef SDW
