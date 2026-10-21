#include "vehicle.h"
#ifndef VM_HOST
#include "bitmap.h"
#endif
#ifndef VM_HOST
extern void vehicle_midpoint_rows(void);
#endif
/* Five projected road edges. Exact16-bit wrap/ASR rules of original $6d40. */
void vehicle_midpoints(void){
 u16 __near *left=(u16 __near *)vehicle_projection;
 u16 __near *quarter=(u16 __near *)(vehicle_projection+256);
 u16 __near *middle=(u16 __near *)(vehicle_projection+512);
 u16 __near *three=(u16 __near *)(vehicle_projection+768);
 u16 __near *right=(u16 __near *)(vehicle_projection+1024);
 u16 i,lo,hi,q1=0,q3=0; s16 half=0,q=0;

#ifndef VM_HOST
 vehicle_midpoint_rows();lo=left[111];hi=right[111];half=(s16)((u16)(hi-lo))>>1;hi=(u16)(lo+half);q=half>>1;q3=(u16)(hi+q);q1=(u16)(q3-half);
#else
 for(i=0;i<112;i++){
  lo=*left++;hi=*right++;half=(s16)((u16)(hi-lo))>>1;
  hi=(u16)(lo+half);*middle++=hi;q=half>>1;q3=(u16)(hi+q);*three++=q3;q1=(u16)(q3-half);*quarter++=q1;
 }
#endif

 d[0]=(d[0]&0xffff0000ul)|q1;d[1]=(d[1]&0xffff0000ul)|(u16)half;d[2]=(d[2]&0xffff0000ul)|(u16)q;d[7]=(d[7]&0xffff0000ul)|65535ul;
 a[1]=0x7ca8ul;a[2]=0x7da8ul;a[3]=0x7ea8ul;a[4]=0x7fa8ul;a[5]=0x80a8ul;
 vsub((u16)half,q3,16,0);
}
#ifdef VM_HOST
s32 vehicle_mul16(u32 left,u32 right){return(s32)(s16)left*(s16)right;}
#endif
/* Exact source Bresenham scanline loops $75ba/$75d2/$75f8/$7610.
 * All virtual registers/flags are restored at the original loop boundary. */
void vehicle_edge_run(u8 kind){
 u16 __near *dst=(u16 __near *)(vehicle_projection+(u16)(a[5]-0x7bc8ul));
 u16 count=(u16)d[1],x=(u16)d[5],sum;u8 error=(u8)d[4],dy=(u8)d[2],dx=(u8)d[3];
 do{
  if(kind&1u){
   do{if(kind&2u)x++;else x--;sum=(u16)error+dy;error=(u8)sum;}while(sum<256u&&error<dx);
   fx=(u8)(dx>error);error=(u8)(error-dx);
  }else{
   sum=(u16)error+dx;error=(u8)sum;fx=(u8)(sum>255u);
   if(error>=dy){error=(u8)(error-dy);if(kind&2u){fx=(u8)(x==65535u);x++;}else{fx=(u8)(x==0);x--;}}
  }
  *dst++=x;a[5]+=2;
 }while(count--);
 d[1]=(d[1]&0xffff0000ul)|65535ul;d[4]=(d[4]&0xffffff00ul)|error;d[5]=(d[5]&0xffff0000ul)|x;
 fn=(u8)((x&32768u)!=0);fz=(u8)(x==0);fv=fc=0;
}

/* $6fa8..$70b4: batch pure raster rows, retaining source road/pattern logic. */
#ifndef VM_HOST
extern void vehicle_draw_road_batch(u16 count);
#endif
void vehicle_road_run(void){
 u16 count=(u16)d[7];u32 step=((u32)count+1ul)<<16;
 #ifndef VM_HOST
 if(count<=151u){
  u32 rows=(u32)count+1ul;
  if(bitmap_building)vehicle_draw_road_batch(count);
  a[0]-=rows*40ul;a[3]-=rows*40ul;a[5]+=rows*2ul;
  vehicle_road_y-=(s16)rows;d[0]=d[1]=d[2]=d[3]=0;
 }else
#endif
 do{vehicle_external(0x6fa8ul);}while(count--);
 d[7]=(d[7]&0xffff0000ul)|65535ul;d[6]=vadd(step,d[6],32,0);
}

/* The original projection algorithms, expressed in native16-bit arithmetic.
 * Byte/word writes intentionally retain the other original register bits.
 * These replace complete hot loops, not gameplay state or route data. */
extern const u8 *vehicle_code;
extern const u16 vehicle_smooth_lut[2048];
extern s32 vehicle_mul16(u32,u32);
#define KW(n) (*(u16 *)&d[n])
#define KB(n) (*(u8 *)&d[n])
#define STATEB(p) vehicle_state[(((u16)((p)-0x8d1eul))^1u)]
#define CODEB(p) vehicle_code[(((u16)((p)-0x2ffcul))^1u)]
static void smooth(void){u16 v=vehicle_smooth_lut[(KW(1)&224u)*8u+KB(2)];d[0]=(u8)v;KB(1)=(u8)((KB(1)<<3)|(KB(1)>>5));d[7]=0;fx=(u8)((v>>12)&1u);}
void vehicle_native_height(void){
 u16 phase=*(u16 *)(vehicle_state+858u),position=*(u16 *)(vehicle_state+856u),w1=0,w3=0,i,product;
 u8 value,coeff,next,ceiling=96u,last=0,carry=0,accumulator;
 (*(u8 *)&phase)&=224u;(*(u8 *)&position)+=32u;
 value=STATEB(0x8f74ul+(s16)position);
 accumulator=(u8)(0u-(u8)vehicle_smooth_lut[(phase&224u)*8u+value]);
 for(i=0;i<21u;i++){
  coeff=CODEB(0x7821ul+phase+i);w1=(u16)coeff*2u;
  accumulator=(u8)(accumulator+STATEB(0x8f74ul+(s16)position));w3=0;
  if(accumulator){value=accumulator;if(value&128u){w1=(u16)(0u-w1);value=(u8)(0u-value);}
   product=(u16)vehicle_mul16((u32)w1,(u32)(value&127u));w3=(u16)((s16)product>>7);
  }
  w3=(u16)((w3&0xff00u)|(u8)((u8)w3+coeff));STATEB(0x909ful+i)=(u8)w3;
  carry=(u8)((u8)position==255u);(*(u8 *)&position)++;
 }
 for(i=0;i<21u;i++){
  next=STATEB(0x909ful+i);if((s8)(u8)(next-ceiling)<0)ceiling=next;
  STATEB(0x90e2ul+i)=ceiling;last=next;
 }
 STATEB(0x90b4ul)=160u;
 d[0]=accumulator;d[1]=(u16)((w1&0xff00u)|ceiling);KB(2)=last;KW(3)=w3;KW(6)=position;d[7]=65535ul;
 a[0]=0x90f7ul;a[1]=a[2]=0x90b4ul;fx=carry;
 fn=(u8)((ceiling&128u)!=0);fz=(u8)(ceiling==0);fv=fc=0;
}
static void edge_side(void){u16 i,curve,coefficient;u8 reset=1,kind,value;u32 product;
 a[0]=0x8f74ul;KW(6)=*(u16 *)(vehicle_state+856u);KB(2)=STATEB(a[0]+(s16)KW(6));KW(1)=*(u16 *)(vehicle_state+858u);KB(1)&=224u;
 a[1]=0x7920ul+KW(1);smooth();KB(0)=(u8)(128u-KB(0));KW(0)&=254u;a[2]=0x7720ul;a[3]=0x90b6ul;d[7]=21;KW(1)=KW(5);
 for(i=0;i<22;i++){
 KB(0)+=STATEB(a[0]+(s16)KW(6));KB(6)++;d[2]=0;
  KW(4)=(u16)(*(const u16 *)(vehicle_code+(u16)(a[2]+(s16)KW(0)-0x2ffcul))-KW(1)+30u);d[4]=(s32)(s16)KW(4);
  coefficient=CODEB(a[1]++);product=(u32)vehicle_mul16(d[4],(u32)(coefficient>>1));KB(3)=(u8)(coefficient<<7);d[2]=(s32)product>>9;
  STATEB(a[3]++)=KB(2);KW(1)+=KW(2);KW(2)=(u16)((s16)KW(2)>>8);STATEB(a[3]+21ul)=KB(2);
 }
 a[1]=0x909eul;d[7]=20;
 for(i=0;i<21;i++){
  if(reset)d[1]=0;KW(2)=KW(1);KB(2)-=2u;KB(2)+=STATEB(a[1]++);KB(2)-=STATEB(a[1]);
  if(KB(2)&128u){
   STATEB(a[1]+90ul)=1;KB(2)++;if(KB(2))KB(2)++;KW(1)=KW(2);KB(2)=STATEB(a[1]+45ul);KW(2)<<=8;KB(2)=STATEB(a[1]+23ul);
   curve=KW(5);KW(5)+=KW(2);fx=(u8)(KW(5)<curve);*(u16 *)(vehicle_projection+(u16)(a[5]-0x7bc8ul))=KW(5);a[5]+=2;
   fn=(u8)((KW(5)&32768u)!=0);fz=(u8)(KW(5)==0);fv=fc=0;reset=0;
  }else{
   KB(2)+=2u;STATEB(a[1]+90ul)=KB(2);KB(2)-=KB(1);KB(1)=KB(2);KB(1)--;KB(3)=STATEB(a[1]+45ul);
   if(KB(3)&128u){KB(3)=(u8)(0u-STATEB(a[1]+23ul));kind=KB(2)<KB(3)?1:0;}
   else{KB(3)=STATEB(a[1]+23ul);kind=KB(2)<KB(3)?3:2;}
   if(kind&1u)d[4]=0;else KB(4)=(u8)(KB(2)>>1);vehicle_edge_run(kind);reset=1;
  }
  KW(7)--;
 }
}
void vehicle_native_edges(void){u16 original=*(u16 *)(vehicle_state+854u);KW(5)=original;a[5]=0x7fc8ul;edge_side();KW(5)=(u16)(original-425u);a[5]=0x7bc8ul;edge_side();}

/* Original object clipping, with the repeated top-offset addition collapsed
 * to one native multiply. Entry variants are actual source branch targets. */
void vehicle_native_clip(u16 entry){u16 old,count;
 if(entry==0x4e56u){a[6]=0x4fccul;goto xy;}
 if(entry==0x4e5eu){a[6]=0x4ec0ul;goto xy;}
 if(entry==0x4e64u)goto xy;
 if(entry==0x4e20u)goto vertical;
 if(entry==0x4e08u)d[6]=0;KW(4)=ver16(a[5]);a[5]+=2;KW(5)=ver16(a[5]);a[5]+=2;KW(7)=ver16(a[5]);a[5]+=2;
 d[3]=0;KW(2)=0;KW(1)=0;KB(1)=ver8(a[1]);KB(2)=ver8(a[1]+67ul);KW(1)=(u16)(KW(1)-KW(2));
 if(!KW(1))goto vertical;
 if((s16)KW(6)<0)KW(1)+=KW(6);else KW(1)-=KW(6);KW(6)=KW(1);
 if(!KW(6)||(s16)KW(6)<0)goto vertical;
 KW(7)--;old=KW(7);KW(7)-=KW(6);if(old<KW(6))return;KW(7)++;goto top;
vertical:
 KW(2)=(u16)vadd(KW(6),KW(2),16,0);if((s16)KW(2)<0)return;
top:
 KW(1)=KW(2);KW(1)++;old=KW(1);KW(1)-=KW(7);
 if(old<KW(7)){
  KW(7)+=KW(1);KW(1)=(u16)(0u-KW(1));count=KW(1);KW(1)--;
  KW(3)=(u16)(KW(3)+(u16)vehicle_mul16((u32)count,(u32)KW(5)));KW(1)=65535u;
 }
 a[6]=0x4ec0ul;
xy:
 KW(1)=(u16)((s16)KW(0)>>4);
 if((s16)KW(1)<0){KW(1)+=KW(4);KW(6)=KW(1);KW(6)=(u16)(0u-KW(6));KW(6)+=KW(4);KW(0)&=15u;}
 else{
  d[6]=0;KW(1)+=KW(4);old=KW(1);KW(1)-=20u;
  if(old>=20u){KW(1)-=KW(4);KW(1)=(u16)(0u-KW(1));KW(6)=(u16)~KW(6);}
  else KW(1)=KW(4);
 }
 a[0]=ver32(0x37c4ul);KW(2)++;KW(2)-=KW(7);KW(4)=KW(2);KW(2)<<=2;KW(2)+=KW(4);KW(2)<<=3;KW(4)=KW(0);KW(0)>>=3;KW(0)&=65534u;
 KW(0)=(u16)vadd(KW(2),KW(0),16,0);a[0]+=(s16)KW(0);KW(4)&=15u;vnz(KW(4),16);vehicle_external(a[6]);
}

#ifdef VM_HOST
u32 vehicle_div16_packed(u32 value,u32 divisor){return((value%(u16)divisor)<<16)|(u16)(value/(u16)divisor);}
u32 vehicle_mulu16(u32 value,u32 other){return(u32)(u16)value*(u16)other;}
#endif

/* The second set of source Bresenham loops edits crossroads/road margins. */
void vehicle_road_edge_run(u8 kind){
 u16 __near *dst=(u16 __near *)(vehicle_projection+(u16)(a[1]-0x7bc8ul));
 u16 count=KW(2),x=KW(0),sum;u8 error=KB(3),dy=KB(7),dx=KB(1);
 do{
  if(kind&1u){do{if(kind&2u)x++;else x--;sum=(u16)error+dy;error=(u8)sum;}while(sum<256u&&error<dx);fx=(u8)(dx>error);error=(u8)(error-dx);}
  else{sum=(u16)error+dx;error=(u8)sum;fx=(u8)(sum>255u);if(error>=dy){error=(u8)(error-dy);if(kind&2u){fx=(u8)(x==65535u);x++;}else{fx=(u8)(x==0);x--;}}}
  *dst++=x;a[1]+=2;
 }while(count--);
 KW(2)=65535u;KB(3)=error;KW(0)=x;fn=(u8)((x&32768u)!=0);fz=(u8)(x==0);fv=fc=0;
}
/* Exact quotient/remainder of the original byte-subtraction skyline loop. */
void vehicle_sky_steps(void){u16 count,step=KB(0),remain=KB(1);if(!step){vm_fault=0xff;return;}count=remain/step;remain%=step;KW(2)=count;KW(3)=(u16)(count*KW(0));KB(1)=(u8)vsub(step,remain,8,0);}

/* Exact $51DA prefix-height and scene-edge gather. Source arithmetic uses
 * byte accumulation and word shifts, including high-byte propagation.
 * Normal projection samples use near RAM words; unusual wrapped indices
 * retain the original mapper, in source read/write order. */
void vehicle_native_boundaries(void){
 u16 i,word=0,right=0,offset;u8 sum=0;u16 __near *out=(u16 __near *)(vehicle_projection+1280u);
 for(i=0;i<21u;i++){offset=(u16)((987u+i)^1u);sum=(u8)(sum+vehicle_state[offset]);vehicle_state[offset]=sum;}
 word=sum;
 for(i=0;i<21u;i++){
  word=(u16)((word&0xff00u)|vehicle_state[(987u+i)^1u]);fx=(u8)(word>>15);word=(u16)(word<<1);
  if(word<=398u){*out++=*(u16 __near *)(vehicle_projection+word);right=*(u16 __near *)(vehicle_projection+1024u+word);}
  else{*out++=ver16(0x7bc8ul+(s16)word);right=ver16(0x7fc8ul+(s16)word);}
  *out++=right;
 }
 d[0]=word;KW(6)=KW(7)=65535u;
 a[0]=0x811cul;a[1]=0x910eul;a[2]=0x7bc8ul;a[3]=0x7fc8ul;
 fn=(u8)((right&0x8000u)!=0);fz=(u8)(right==0);fv=fc=0;
}
