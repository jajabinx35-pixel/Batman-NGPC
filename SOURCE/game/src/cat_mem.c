#include "cathedral.h"
extern u8 stack[512];
static u16 temp_scroll;static u8 panel_status[2];

/* Cathedral-only writable history and sparse map cells fit the unused
 * tail of the2776-byte stage workspace. Stages1-4 keep their own layout. */
#define CAT_EXTRA (stage_work.puzzle+2176u)
#define CAT_HISTORY 104u
#define CAT_KEYS 104u
#define CAT_VALUES 360u
#define CAT_DIRTY 488u
#ifndef VM_HOST
#pragma section code platform_scan
#endif
u8 cat_map_read(u16 index){u8 slot,tries;u16 key;
 if(index>=17864u)return 0;
 slot=(u8)((index^(index>>7))&127u);
 for(tries=0;tries<128;tries++){
  key=(u16)((u16)CAT_EXTRA[CAT_KEYS+(u16)slot*2u]<<8)|CAT_EXTRA[CAT_KEYS+(u16)slot*2u+1u];
  if(key==index)return CAT_EXTRA[CAT_VALUES+slot];if(key==65535u)break;slot=(u8)((slot+1u)&127u);
 }return cathedral_map[index];
}
#ifndef VM_HOST
#pragma section code f_code
#endif
static void cat_map_write(u16 index,u8 value){u8 slot,tries;u16 key;
 slot=(u8)((index^(index>>7))&127u);
 for(tries=0;tries<128;tries++){
  key=(u16)((u16)CAT_EXTRA[CAT_KEYS+(u16)slot*2u]<<8)|CAT_EXTRA[CAT_KEYS+(u16)slot*2u+1u];
  if(key==index||key==65535u){
   CAT_EXTRA[CAT_KEYS+(u16)slot*2u]=(u8)(index>>8);CAT_EXTRA[CAT_KEYS+(u16)slot*2u+1u]=(u8)index;
   CAT_EXTRA[CAT_VALUES+slot]=value;CAT_EXTRA[CAT_DIRTY]=1;return;
  }slot=(u8)((slot+1u)&127u);
 }vm_fault=0x807cul+index;
}
u8 cat_map_take_dirty(void){u8 dirty=CAT_EXTRA[CAT_DIRTY];CAT_EXTRA[CAT_DIRTY]=0;return dirty;}


#ifndef VM_HOST
#define MEM_NAME cvr8_slow
#else
#define MEM_NAME cvr8
#endif
u8 VM_ABI MEM_NAME(u32 p){
 p&=0xfffffful;
 if(p>=0x6326ul&&p<0x69faul)return vm_vars[(u16)(p-0x6326ul)];
 if(p>=0x39bcul&&p<0x3a98ul)return vm_actors[(u16)(p-0x39bcul)];
 if(p>=0x48d2ul&&p<0x4972ul)return vm_shots[(u16)(p-0x48d2ul)];
 if(p>=0x36e0ul&&p<0x3710ul)return vm_globals[(u8)(p-0x36e0ul)];
 if(p>=0x1ffe00ul&&p<0x200000ul)return stack[(u16)(p-0x1ffe00ul)];
 if(p>=0x807cul&&p<0xc644ul)return cat_map_read((u16)(p-0x807cul));
 if(p>=0x5facul&&p<0x6014ul)return CAT_EXTRA[(u16)(p-0x5facul)];
 if(p>=0x7ffcul&&p<0x807cul)return cat_map_header[(u8)(p-0x7ffcul)];
 if(p>=0x10000ul&&p<0x10988ul)return original_bob_headers[(u16)(p-0x10000ul)];
 if(p==0x4972ul)return (u8)(temp_scroll>>8);if(p==0x4973ul)return (u8)temp_scroll;
 if(p==0x3c7cul)return (u8)(vm_player_state>>8);if(p==0x3c7dul)return (u8)vm_player_state;
 if(p==0x5546ul)return (u8)(vm_platform_opcode>>8);if(p==0x5547ul)return (u8)vm_platform_opcode;
 if(p==0x7c874ul||p==0x7c875ul)return panel_status[(u8)(p&1)];
 if(p>=0x2ffcul&&p<0x7301ul)return cat_original_code[(u16)(p-0x2ffcul)];
 if(p==0x22ul)return 0xa5;if(p==0x23ul)return 0x5a;
 return 0;
}
#undef MEM_NAME

static u8 *mutable_ptr(u32 p){
 if(p>=0x5facul&&p<0x6014ul)return CAT_EXTRA+(u16)(p-0x5facul);
 if(p>=0x1ffe00ul&&p<0x200000ul)return stack+(u16)(p-0x1ffe00ul);
 if(p>=0x39bcul&&p<0x3a98ul)return vm_actors+(u16)(p-0x39bcul);
 if(p>=0x6326ul&&p<0x69faul)return vm_vars+(u16)(p-0x6326ul);
 if(p>=0x48d2ul&&p<0x4972ul)return vm_shots+(u16)(p-0x48d2ul);
 if(p>=0x36e0ul&&p<0x3710ul)return vm_globals+(u8)(p-0x36e0ul);
 return (u8 *)0;
}

#ifndef VM_HOST
#define MEM_NAME cvr16_slow
#else
#define MEM_NAME cvr16
#endif
u16 VM_ABI MEM_NAME(u32 p){u8 *q=mutable_ptr(p);if(q)return (u16)((u16)q[0]<<8)|q[1];return (u16)((u16)cvr8(p)<<8)|cvr8(p+1);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME cvr32_slow
#else
#define MEM_NAME cvr32
#endif
u32 VM_ABI MEM_NAME(u32 p){u8 *q=mutable_ptr(p);if(q)return ((u32)q[0]<<24)|((u32)q[1]<<16)|((u16)q[2]<<8)|q[3];return ((u32)cvr16(p)<<16)|cvr16(p+2);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME cvw8_slow
#else
#define MEM_NAME cvw8
#endif
void VM_ABI MEM_NAME(u32 p,u8 v){
 p&=0xfffffful;
 if(p>=0x807cul&&p<0xc644ul){cat_map_write((u16)(p-0x807cul),v);return;}
 if(p>=0x5facul&&p<0x6014ul){CAT_EXTRA[(u16)(p-0x5facul)]=v;return;}
 if(p>=0x6326ul&&p<0x69faul){vm_vars[(u16)(p-0x6326ul)]=v;return;}
 if(p>=0x39bcul&&p<0x3a98ul){vm_actors[(u16)(p-0x39bcul)]=v;return;}
 if(p>=0x48d2ul&&p<0x4972ul){vm_shots[(u16)(p-0x48d2ul)]=v;return;}
 if(p>=0x36e0ul&&p<0x3710ul){vm_globals[(u8)(p-0x36e0ul)]=v;return;}
 if(p>=0x1ffe00ul&&p<0x200000ul){stack[(u16)(p-0x1ffe00ul)]=v;return;}
 if(p==0x4972ul){temp_scroll=(u16)((temp_scroll&255)|((u16)v<<8));return;}
 if(p==0x4973ul){temp_scroll=(u16)((temp_scroll&0xff00)|v);return;}
 if((p==0x3c7aul||p==0x3c7bul)&&!v)return;
 if(p==0x3c7cul){vm_player_state=(u16)((vm_player_state&255)|((u16)v<<8));return;}
 if(p==0x3c7dul){vm_player_state=(u16)((vm_player_state&0xff00)|v);return;}
 if(p==0x5546ul){vm_platform_opcode=(u16)((vm_platform_opcode&255)|((u16)v<<8));return;}
 if(p==0x5547ul){vm_platform_opcode=(u16)((vm_platform_opcode&0xff00)|v);return;}
 if(p==0x7c874ul||p==0x7c875ul){panel_status[(u8)(p&1)]=v;return;}
 /* A zero projectile allocation writes to address zero in the original. */
 if(p<8ul)return;
 vm_fault=p;
}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME cvw16_slow
#else
#define MEM_NAME cvw16
#endif
void VM_ABI MEM_NAME(u32 p,u16 v){u8 *q=mutable_ptr(p);if(q){q[0]=(u8)(v>>8);q[1]=(u8)v;return;}cvw8(p,(u8)(v>>8));cvw8(p+1,(u8)v);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME cvw32_slow
#else
#define MEM_NAME cvw32
#endif
void VM_ABI MEM_NAME(u32 p,u32 v){u8 *q=mutable_ptr(p);if(q){q[0]=(u8)(v>>24);q[1]=(u8)(v>>16);q[2]=(u8)(v>>8);q[3]=(u8)v;return;}cvw16(p,(u16)(v>>16));cvw16(p+2,(u16)v);}
#undef MEM_NAME

void cat_reset(u8 checkpoint){
 u16 i;u32 p;
#ifndef VM_HOST
 stage_memory_init(5);
#endif
 for(i=0;i<CAT_HISTORY;i++)CAT_EXTRA[i]=cat_original_code[12208u+i];
 for(i=CAT_KEYS;i<CAT_VALUES;i++)CAT_EXTRA[i]=255;
 CAT_EXTRA[CAT_DIRTY]=1;
 temp_scroll=0;vm_fault=vm_resume=0;vm_busy=0;fn=fz=fv=fc=fx=0;
 for(i=0;i<8;i++){d[i]=a[i]=0;}
 for(i=0;i<sizeof(vm_vars);i++)vm_vars[i]=cat_original_code[0x6326 - 0x2ffc+i];
 for(i=0;i<sizeof(vm_actors);i++)vm_actors[i]=0;
 for(i=0;i<sizeof(vm_shots);i++)vm_shots[i]=0;
 for(i=0;i<sizeof(vm_globals);i++)vm_globals[i]=0;
 panel_status[0]=panel_status[1]=0;
 vm_player_state=0x4c7c;vm_platform_opcode=0x4e71;
 for(i=0;i<14;i++)cvw8(0x69ecul+i,cvr8((0x69c2ul+(u32)checkpoint*14ul)+i));
 cvw16(0x6344ul,checkpoint);cvw16(0x6332ul,10);cvw16(0x6334ul,3);cvw16(0x6336ul,1);
 /* Trigger flags are reset by original game_start; source definitions kept. */
 for(p=0x6476ul;p<0x6944ul;){cvw8(p,(u8)(cvr8(p)&127));p+=6ul+(u32)cvr16(p+4)*6ul;}
 for(p=0x6944ul;p<0x69c2ul;p+=6)cvw8(p+4ul,(u8)(cvr8(p+4ul)&127));
}

#ifdef VM_CATHOST
extern int (*vm_callback)(u32);
int cat_external(u32 pc){return vm_callback?vm_callback(pc):0;}
#endif

#ifdef VM_CATHOST
void cat_snapshot(u8 *out){u32 p;
for(p=0x6326ul;p<0x69faul;p++)*out++=cvr8(p);
for(p=0x39bcul;p<0x3a98ul;p++)*out++=cvr8(p);
for(p=0x48d2ul;p<0x4972ul;p++)*out++=cvr8(p);
for(p=0x36e0ul;p<0x3710ul;p++)*out++=cvr8(p);
for(p=0x3c7cul;p<0x3c7eul;p++)*out++=cvr8(p);
for(p=0x5546ul;p<0x5548ul;p++)*out++=cvr8(p);
for(p=0x7c874ul;p<0x7c876ul;p++)*out++=cvr8(p);
for(p=0x5facul;p<0x6014ul;p++)*out++=cvr8(p);
for(p=0x807cul;p<0xc644ul;p++)*out++=cvr8(p);}
#endif

#ifndef VM_HOST
#include "session.h"
void cathedral_state_io(void){session_io(&temp_scroll,sizeof(temp_scroll));session_io(&panel_status,sizeof(panel_status));}
#endif
