#include "vehicle.h"
extern u8 stack[512];
#ifdef VM_VEHICLEHOST
#include <stdio.h>
extern u32 vehicle_trace;
u8 vehicle_profile[16];
#endif
u8 vehicle_stage;
u16 vehicle_energy=40;
static u8 panel_status[2];
const u8 *vehicle_code;
#define code vehicle_code
const u8 *vehicle_shared,*vehicle_data24;
static u8 *mutable_at(u32 p){
 if(p>=0x8d1eul&&p<0x910eul)return vehicle_state+(u16)(p-0x8d1eul);
 if(p>=0x7bc8ul&&p<0x8158ul)return vehicle_projection+(u16)(p-0x7bc8ul);
 if(p>=0x3700ul&&p<0x37c8ul)return vehicle_io+(u8)(p-0x3700ul);
 if(p>=0x4238ul&&p<0x423eul)return vehicle_rng+(u8)(p-0x4238ul);
 if(p>=0x4e60ul&&p<0x4ea0ul)return vehicle_clip+(u8)(p-0x4e60ul);
 if(p>=0x3f3aul&&p<0x3f70ul)return vehicle_hud+(u8)(p-0x3f3aul);
 if(p>=0x6688ul&&p<0x66e4ul&&(p-0x6688ul)%18ul<2ul)return stage_work.vehicle.fx+(u8)((p-0x6688ul)/18ul)*2u+(u8)(p&1);
 if(p>=0x6718ul&&p<0x6768ul&&(p-0x6718ul)%26ul<2ul)return stage_work.vehicle.fx+12u+(u8)((p-0x6718ul)/26ul)*2u+(u8)(p&1);
 if(p>=0x1ffe00ul&&p<0x200000ul)return stack+(u16)(p-0x1ffe00ul);
 if(p>=0x7c874ul&&p<0x7c876ul)return panel_status+(u8)(p&1);
 return (u8 *)0;
}
static const u8 *rom_at(u32 p){
 if(p>=0x2a416ul&&p<(vehicle_stage==2?0x50044ul:0x5681aul))return vehicle_data24+(p-0x2a416ul);
 if(p>=0x1fffcul&&p<0x2a416ul)return vehicle_shared+(u16)(p-0x1fffcul);
 if(p>=0x2ffcul&&p<0xcdf4ul)return code+(u16)(p-0x2ffcul);return (const u8 *)0;
}
/* Native16-bit range tests for the dominant state/projection and virtual
 * stack accesses. The general sparse mapper remains the fallback. */
#define FAST_MUTABLE(p,q) do {u16 off; q=(u8 *)0; \
 if((p)<0x10000ul){off=(u16)((p)-0x8d1eul);if(off<1008u)q=vehicle_state+off; \
 else{off=(u16)((p)-0x7bc8ul);if(off<1424u)q=vehicle_projection+off; \
 else{off=(u16)((p)-0x3700ul);if(off<200u)q=vehicle_io+off;}}} \
 else if((p)>=0x1ffe00ul&&(p)<0x200000ul)q=stack+(u16)((p)-0x1ffe00ul); \
 if(!q)q=mutable_at(p); \
}while(0)

#ifndef VM_HOST
#define MEM_NAME ver8_slow
#else
#define MEM_NAME ver8
#endif
u8 VM_ABI MEM_NAME(u32 p){u8 *q;const u8 *r;p&=0xfffffful;FAST_MUTABLE(p,q);if(q)return p&1ul?q[-1]:q[1];
 if(p==0x7c88ful)return(u8)vehicle_energy;r=rom_at(p);if(r)return p&1ul?r[-1]:r[1];return 0;
}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME ver16_slow
#else
#define MEM_NAME ver16
#endif
u16 VM_ABI MEM_NAME(u32 p){u8 *q;const u8 *r;if(p&1ul)return(u16)((u16)ver8(p)<<8)|ver8(p+1);
 FAST_MUTABLE(p,q);if(q)return*(u16 *)q;r=rom_at(p);if(r)return*(const u16 *)r;if(p==0x7c88eul)return vehicle_energy;return 0;
}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME ver32_slow
#else
#define MEM_NAME ver32
#endif
u32 VM_ABI MEM_NAME(u32 p){u8 *q;const u8 *r;FAST_MUTABLE(p,q);if(q)return((u32)*(u16 *)q<<16)|*(u16 *)(q+2);r=rom_at(p);if(r)return((u32)*(const u16 *)r<<16)|*(const u16 *)(r+2);return((u32)ver16(p)<<16)|ver16(p+2);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME vew8_slow
#else
#define MEM_NAME vew8
#endif
void VM_ABI MEM_NAME(u32 p,u8 v){u8 *q;p&=0xfffffful;FAST_MUTABLE(p,q);if(q){if(p&1ul)q[-1]=v;else q[1]=v;return;}if(p<8ul)return;vm_fault=p;}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME vew16_slow
#else
#define MEM_NAME vew16
#endif
void VM_ABI MEM_NAME(u32 p,u16 v){u8 *q;FAST_MUTABLE(p,q);if(q&&!(p&1ul)){*(u16 *)q=v;return;}vew8(p,(u8)(v>>8));vew8(p+1,(u8)v);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME vew32_slow
#else
#define MEM_NAME vew32
#endif
void VM_ABI MEM_NAME(u32 p,u32 v){u8 *q;FAST_MUTABLE(p,q);if(q){*(u16 *)q=(u16)(v>>16);*(u16 *)(q+2)=(u16)v;return;}vew16(p,(u16)(v>>16));vew16(p+2,(u16)v);}
#undef MEM_NAME

void vehicle_reset(u8 stage){u16 i;
#ifndef VM_HOST
 stage_memory_init(stage);
#endif
 vehicle_stage=stage;code=stage==2?vehicle2_code:vehicle4_code;vehicle_shared=stage==2?vehicle2_data:vehicle4_data;vehicle_data24=stage==2?vehicle2_data24:vehicle4_data24;
 for(i=0;i<1008;i++)vehicle_state[i]=code[0x8d1e - 0x2ffc+i];
 for(i=0;i<1424;i++)vehicle_projection[i]=code[0x7bc8-0x2ffc+i];
 for(i=0;i<200;i++)vehicle_io[i]=code[0x3700-0x2ffc+i];
 for(i=0;i<6;i++)vehicle_rng[i]=code[0x4238-0x2ffc+i];
 for(i=0;i<64;i++)vehicle_clip[i]=code[0x4e60-0x2ffc+i];
 for(i=0;i<54;i++)vehicle_hud[i]=code[0x3f3a-0x2ffc+i];
 for(i=0;i<6;i++){stage_work.vehicle.fx[i*2u]=code[0x6688-0x2ffc+i*18u];stage_work.vehicle.fx[i*2u+1u]=code[0x6689-0x2ffc+i*18u];}
 for(i=0;i<4;i++){stage_work.vehicle.fx[12u+i*2u]=code[0x6718-0x2ffc+i*26u];stage_work.vehicle.fx[13u+i*2u]=code[0x6719-0x2ffc+i*26u];}
 for(i=0;i<8;i++)d[i]=a[i]=0;
 panel_status[0]=panel_status[1]=0;vm_busy=0;vm_fault=vm_resume=0;fn=fz=fv=fc=fx=0;
 vew16(0x8d1eul,stage==4?1:0);vew16(0x8d22ul,999);vew16(0x8d24ul,100);
 vew32(0x37c0ul,0x5c200ul);vew32(0x37c4ul,0x62100ul);
}
#ifdef VM_VEHICLEHOST
u32 vehicle_trace;
u8 vehicle_profile[16];
extern int (*vm_callback)(u32);
int vehicle_external(u32 pc){return vm_callback?vm_callback(pc):0;}
#endif

#ifdef VM_VEHICLEHOST
void vehicle_snapshot(u8 *out){u16 i;u8 *q=(u8 *)&stage_work.vehicle;for(i=0;i<sizeof(VehicleWork);i++)*out++=q[i^1u];*out++=panel_status[1];*out++=panel_status[0];}
#endif

#ifndef VM_HOST
#include "session.h"
void vehicle_memory_state_io(void){session_io(&vehicle_stage,sizeof(vehicle_stage));session_io(&vehicle_energy,sizeof(vehicle_energy));session_io(&panel_status,sizeof(panel_status));}
#endif
