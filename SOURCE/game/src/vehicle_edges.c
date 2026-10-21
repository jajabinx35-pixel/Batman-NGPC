/* Native projection model: original integer curve and Bresenham rules, with
 * local 16-bit values and one register writeback per edge, rather than
 * translated register writes at every pixel. */
#include "vehicle.h"
extern const u8 *vehicle_code;
extern u8 vehicle_profile[16];
#define PROBE (*(volatile u8 *)(vehicle_profile+15))
extern const u16 vehicle_smooth_lut[2048];
extern s32 vehicle_mul16(u32,u32);
#ifndef VM_HOST
extern u32 vehicle_edge_pixels(u32,u32,u32);
#endif
#define SW(p) (*(u16 *)(vehicle_state+(u16)((p)-0x8d1eul)))
#define SB(p) (vehicle_state[((u16)((p)-0x8d1eul))^1u])
#define CB(p) (vehicle_code[((u16)((p)-0x2ffcul))^1u])
#define CW(p) (*(const u16 *)(vehicle_code+(u16)((p)-0x2ffcul)))
#define LB(x) (*(u8 *)&(x))
#ifndef VM_HOST
typedef struct {u16 position,v,w1,w2;u32 r2,r4;u8 b3,pad;u16 w5,out;u8 fx;} EdgeProfile;
extern void vehicle_edge_profile(u32 context,u32 phase);
extern void vehicle_edge_pixels_all(u32 context);
#endif
static void side(u16 start,u16 address,u8 publish){
 u16 position=SW(0x9076ul),phase=SW(0x9078ul),v,w1=start,w2=0,w5=start,i,coeff,n,x,sum,curve;
 u32 r2=0,r4=d[4];s32 product;u8 b3=(u8)d[3],reset=1,kind,error,dy,dx;u16 __near *out;
#ifndef VM_HOST
 EdgeProfile ep;
#endif
 LB(phase)&=224u;v=vehicle_smooth_lut[(phase&224u)*8u+SB(0x8f74ul+(s16)position)];v=(u16)((128u-(u8)v)&254u);
 PROBE=3;
#ifndef VM_HOST
 ep.position=position;ep.v=v;ep.w1=w1;vehicle_edge_profile((u32)&ep,(u32)phase);

#else
for(i=0;i<22u;i++){
  LB(v)+=SB(0x8f74ul+(s16)position);LB(position)++;
  curve=(u16)(CW(0x7720u+(s16)v)-w1+30u);r4=(s32)(s16)curve;
  coeff=CB(0x7920u+phase+i);product=vehicle_mul16(r4,(u32)(coeff>>1));b3=(u8)(coeff<<7);
  r2=(s32)product>>9;SB(0x90b6ul+i)=(u8)r2;w1+=(u16)r2;
  w2=(u16)((s16)(u16)r2>>8);r2=(r2&0xffff0000ul)|w2;SB(0x90b7ul+i+21ul)=(u8)w2;
 }
#endif

 out=(u16 __near *)(vehicle_projection+(u16)(address-0x7bc8u));
 PROBE=4;
#ifndef VM_HOST
 ep.w5=w5;ep.out=(u16)out;vehicle_edge_pixels_all((u32)&ep);
 /* No source instruction observes the first side's virtual scratch state.
    The profile writes every r4/b3 value before the second side uses it. */
 if(!publish){PROBE=0;return;}
 position=ep.position;v=ep.v;r2=ep.r2;
 w1=ep.w1;w2=ep.w2;r4=ep.r4;b3=ep.b3;w5=ep.w5;out=(u16 __near *)ep.out;
 fx=ep.fx;fn=(u8)((w5&32768u)!=0);fz=(u8)(w5==0);fv=fc=0;
#else
for(i=0;i<21u;i++){
  if(reset)w1=0;w2=w1;LB(w2)-=2u;LB(w2)+=SB(0x909eul+i);LB(w2)-=SB(0x909ful+i);
  if(LB(w2)&128u){
   SB(0x90f9ul+i)=1;LB(w2)++;if(LB(w2))LB(w2)++;w1=w2;
   LB(w2)=SB(0x90ccul+i);w2<<=8;LB(w2)=SB(0x90b6ul+i);
   curve=w5;w5+=w2;fx=(u8)(w5<curve);*out++=w5;
   fn=(u8)((w5&32768u)!=0);fz=(u8)(w5==0);fv=fc=0;reset=0;
  }else{
   LB(w2)+=2u;SB(0x90f9ul+i)=LB(w2);LB(w2)-=LB(w1);LB(w1)=LB(w2);LB(w1)--;
   b3=SB(0x90ccul+i);
   if(b3&128u){b3=(u8)(0u-SB(0x90b6ul+i));kind=LB(w2)<b3?1u:0u;}
   else{b3=SB(0x90b6ul+i);kind=LB(w2)<b3?3u:2u;}
   if(kind&1u)r4=0;else LB(r4)=(u8)(LB(w2)>>1);
   n=w1;x=w5;error=(u8)r4;dy=(u8)w2;dx=b3;
#ifndef VM_HOST
   r2=(r2&0xffff0000ul)|w2;
   product=(s32)vehicle_edge_pixels((u32)(u16)out,(u32)x|((u32)n<<16),(u32)error|((u32)dy<<8)|((u32)dx<<16)|((u32)kind<<24));
   out+=n+1u;x=(u16)product;error=(u8)((u32)product>>16);fx=(u8)((u32)product>>24);
#else
   do{
    if(kind&1u){do{if(kind&2u)x++;else x--;sum=(u16)error+dy;error=(u8)sum;}while(sum<256u&&error<dx);fx=(u8)(dx>error);error=(u8)(error-dx);}
    else{sum=(u16)error+dx;error=(u8)sum;fx=(u8)(sum>255u);if(error>=dy){error=(u8)(error-dy);if(kind&2u){fx=(u8)(x==65535u);x++;}else{fx=(u8)(x==0);x--;}}}
    *out++=x;
   }while(n--);
#endif
   w1=65535u;LB(r4)=error;w5=x;fn=(u8)((x&32768u)!=0);fz=(u8)(x==0);fv=fc=0;reset=1;
  }
 }
#endif

 PROBE=0;if(!publish)return;d[0]=v;d[1]=w1;d[2]=(r2&0xffff0000ul)|w2;d[3]=(d[3]&0xffffff00ul)|b3;d[4]=r4;
 d[5]=(d[5]&0xffff0000ul)|w5;d[6]=(d[6]&0xffff0000ul)|position;d[7]=65535ul;
 a[0]=0x8f74ul;a[1]=0x90b3ul;a[2]=0x7720ul;a[3]=0x90ccul;a[5]=0x7bc8ul+(u16)((u8 __near *)out-(u8 __near *)vehicle_projection);
}
void vehicle_edges_native(void){u16 start=SW(0x9074ul);side(start,0x7fc8u,0);side((u16)(start-425u),0x7bc8u,1);}
