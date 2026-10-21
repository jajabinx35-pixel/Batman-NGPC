/* Original 68000 address space, reduced to the mutable game state. */
#include "faithful.h"
u32 d[8],a[8],vm_resume,vm_fault;
u8 fn,fz,fv,fc,fx,vm_busy;
StageWork stage_work;
u8 stack[512];
u16 vm_player_state,vm_platform_opcode,temp_scroll;
static u8 panel_status[2];

#ifndef VM_HOST
#define MEM_NAME vr8_slow
#else
#define MEM_NAME vr8
#endif
u8 VM_ABI MEM_NAME(u32 p){
 p&=0xfffffful;
 if(p>=0x62deul&&p<0x67caul)return vm_vars[(u16)(p-0x62deul)];
 if(p>=0x39c8ul&&p<0x3aa4ul)return vm_actors[(u16)(p-0x39c8ul)];
 if(p>=0x4894ul&&p<0x4934ul)return vm_shots[(u16)(p-0x4894ul)];
 if(p>=0x36e0ul&&p<0x3710ul)return vm_globals[(u8)(p-0x36e0ul)];
 if(p>=0x1ffe00ul&&p<0x200000ul)return stack[(u16)(p-0x1ffe00ul)];
 if(p>=0x807cul&&p<0x9f3cul)return axis_map[(u16)(p-0x807cul)];
 if(p>=0x7ffcul&&p<0x807cul)return original_map_header[(u8)(p-0x7ffcul)];
 if(p>=0x10000ul&&p<0x10988ul)return original_bob_headers[(u16)(p-0x10000ul)];
 if(p==0x4934ul)return (u8)(temp_scroll>>8);if(p==0x4935ul)return (u8)temp_scroll;
 if(p==0x3c92ul)return (u8)(vm_player_state>>8);if(p==0x3c93ul)return (u8)vm_player_state;
 if(p==0x5506ul)return (u8)(vm_platform_opcode>>8);if(p==0x5507ul)return (u8)vm_platform_opcode;
 if(p==0x7c874ul||p==0x7c875ul)return panel_status[(u8)(p&1)];
 if(p>=0x2ffcul&&p<0x7001ul)return original_code[(u16)(p-0x2ffcul)];
 if(p==0x22ul)return 0xa5;if(p==0x23ul)return 0x5a;
 return 0;
}
#undef MEM_NAME

static u8 *mutable_ptr(u32 p){
 if(p>=0x1ffe00ul&&p<0x200000ul)return stack+(u16)(p-0x1ffe00ul);
 if(p>=0x39c8ul&&p<0x3aa4ul)return vm_actors+(u16)(p-0x39c8ul);
 if(p>=0x62deul&&p<0x67caul)return vm_vars+(u16)(p-0x62deul);
 if(p>=0x4894ul&&p<0x4934ul)return vm_shots+(u16)(p-0x4894ul);
 if(p>=0x36e0ul&&p<0x3710ul)return vm_globals+(u8)(p-0x36e0ul);
 return (u8 *)0;
}

#ifndef VM_HOST
#define MEM_NAME vr16_slow
#else
#define MEM_NAME vr16
#endif
u16 VM_ABI MEM_NAME(u32 p){u8 *q=mutable_ptr(p);if(q)return (u16)((u16)q[0]<<8)|q[1];return (u16)((u16)vr8(p)<<8)|vr8(p+1);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME vr32_slow
#else
#define MEM_NAME vr32
#endif
u32 VM_ABI MEM_NAME(u32 p){u8 *q=mutable_ptr(p);if(q)return ((u32)q[0]<<24)|((u32)q[1]<<16)|((u16)q[2]<<8)|q[3];return ((u32)vr16(p)<<16)|vr16(p+2);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME vw8_slow
#else
#define MEM_NAME vw8
#endif
void VM_ABI MEM_NAME(u32 p,u8 v){
 p&=0xfffffful;
 if(p>=0x62deul&&p<0x67caul){vm_vars[(u16)(p-0x62deul)]=v;return;}
 if(p>=0x39c8ul&&p<0x3aa4ul){vm_actors[(u16)(p-0x39c8ul)]=v;return;}
 if(p>=0x4894ul&&p<0x4934ul){vm_shots[(u16)(p-0x4894ul)]=v;return;}
 if(p>=0x36e0ul&&p<0x3710ul){vm_globals[(u8)(p-0x36e0ul)]=v;return;}
 if(p>=0x1ffe00ul&&p<0x200000ul){stack[(u16)(p-0x1ffe00ul)]=v;return;}
 if(p==0x4934ul){temp_scroll=(u16)((temp_scroll&255)|((u16)v<<8));return;}
 if(p==0x4935ul){temp_scroll=(u16)((temp_scroll&0xff00)|v);return;}
 if((p==0x3c90ul||p==0x3c91ul)&&!v)return;
 if(p==0x3c92ul){vm_player_state=(u16)((vm_player_state&255)|((u16)v<<8));return;}
 if(p==0x3c93ul){vm_player_state=(u16)((vm_player_state&0xff00)|v);return;}
 if(p==0x5506ul){vm_platform_opcode=(u16)((vm_platform_opcode&255)|((u16)v<<8));return;}
 if(p==0x5507ul){vm_platform_opcode=(u16)((vm_platform_opcode&0xff00)|v);return;}
 if(p==0x7c874ul||p==0x7c875ul){panel_status[(u8)(p&1)]=v;return;}
 /* A zero projectile allocation writes to address zero in the original. */
 if(p<8ul)return;
 vm_fault=p;
}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME vw16_slow
#else
#define MEM_NAME vw16
#endif
void VM_ABI MEM_NAME(u32 p,u16 v){u8 *q=mutable_ptr(p);if(q){q[0]=(u8)(v>>8);q[1]=(u8)v;return;}vw8(p,(u8)(v>>8));vw8(p+1,(u8)v);}
#undef MEM_NAME


#ifndef VM_HOST
#define MEM_NAME vw32_slow
#else
#define MEM_NAME vw32
#endif
void VM_ABI MEM_NAME(u32 p,u32 v){u8 *q=mutable_ptr(p);if(q){q[0]=(u8)(v>>24);q[1]=(u8)(v>>16);q[2]=(u8)(v>>8);q[3]=(u8)v;return;}vw16(p,(u16)(v>>16));vw16(p+2,(u16)v);}
#undef MEM_NAME

void vm_reset(u8 checkpoint){
 u16 i;u32 p;
#ifndef VM_HOST
 stage_memory_init(1);
#endif
 temp_scroll=0;vm_fault=vm_resume=0;vm_busy=0;fn=fz=fv=fc=fx=0;
 for(i=0;i<8;i++){d[i]=a[i]=0;}
 for(i=0;i<0x4ec;i++)vm_vars[i]=original_code[0x62de - 0x2ffc+i];
 for(i=0;i<sizeof(vm_actors);i++)vm_actors[i]=0;
 for(i=0;i<sizeof(vm_shots);i++)vm_shots[i]=0;
 for(i=0;i<sizeof(vm_globals);i++)vm_globals[i]=0;
 panel_status[0]=panel_status[1]=0;
 vm_player_state=0x4c3e;vm_platform_opcode=0x4e71;
 for(i=0;i<14;i++)vw8(0x67bcul+i,vr8((checkpoint?0x67aeul:0x67a0ul)+i));
 vw16(0x62fcul,checkpoint?1:0);vw16(0x62eaul,10);vw16(0x62ecul,3);vw16(0x62eeul,1);
 /* Trigger flags are reset by original game_start; source definitions kept. */
 for(p=0x642eul;p<0x6722ul;){vw8(p,(u8)(vr8(p)&127));p+=6ul+(u32)vr16(p+4)*6ul;}
 for(p=0x6722ul;p<0x67a0ul;p+=6)vw8(p,(u8)(vr8(p)&127));
}
void vnz(u32 v,u8 bits){u32 mask=bits==8?255ul:bits==16?65535ul:0xfffffffful;u32 sign=bits==8?128ul:bits==16?32768ul:0x80000000ul;v&=mask;fn=(u8)((v&sign)!=0);fz=(u8)(v==0);fv=fc=0;}
u32 vadd(u32 v,u32 w,u8 bits,u8 extend){
 u32 mask=bits==8?255ul:bits==16?65535ul:0xfffffffful;u32 sign=bits==8?128ul:bits==16?32768ul:0x80000000ul;u32 r;
 v&=mask;w&=mask;r=w+v+extend;fc=(u8)(bits<32?r>mask:(r<w||(extend&&r==w)));r&=mask;
 fn=(u8)((r&sign)!=0);fz=(u8)(r==0);fv=(u8)((~(w^v)&(w^r)&sign)!=0);fx=fc;return r;
}
u32 vsub(u32 v,u32 w,u8 bits,u8 extend){
 u32 mask=bits==8?255ul:bits==16?65535ul:0xfffffffful;u32 sign=bits==8?128ul:bits==16?32768ul:0x80000000ul;u32 r;
 v&=mask;w&=mask;r=(w-v-extend)&mask;fc=(u8)(v>w||(extend&&v==w));fn=(u8)((r&sign)!=0);fz=(u8)(r==0);fv=(u8)(((w^v)&(w^r)&sign)!=0);fx=fc;return r;
}
void vcompare(u32 v,u32 w,u8 bits){u8 save=fx;vsub(v,w,bits,0);fx=save;}
u32 vshift(u32 v,u8 count,u8 bits,u8 mode){
 u32 mask=bits==8?255ul:bits==16?65535ul:0xfffffffful;u32 sign=bits==8?128ul:bits==16?32768ul:0x80000000ul;u32 old;
 v&=mask;fv=fc=0;count&=63;
 while(count--){old=v;
  if(mode==6){fc=(u8)((v&sign)!=0);v=((v<<1)|fx)&mask;fx=fc;}
  else if(mode==7){fc=(u8)(v&1);v=(v>>1)|(fx?sign:0);fx=fc;}
  else if(mode==0||mode==2||mode==5){fc=(u8)((v&sign)!=0);v=(v<<1)&mask;if(mode==5)v|=fc;if(mode==0&&((v^old)&sign))fv=1;}
  else {fc=(u8)(v&1);v>>=1;if(mode==1)v|=old&sign;else if(mode==4&&fc)v|=sign;}
  if(mode<4)fx=fc;
 }
 fn=(u8)((v&sign)!=0);fz=(u8)(v==0);return v;
}
#if defined(VM_HOST) && !defined(VM_GAME)
int (*vm_callback)(u32);
int vm_external(u32 pc){return vm_callback?vm_callback(pc):0;}
#endif

#ifdef VM_HOST
void vm_snapshot(u8 *out){u32 p;for(p=0x62deul;p<0x67caul;p++)*out++=vr8(p);for(p=0x39c8ul;p<0x3aa4ul;p++)*out++=vr8(p);for(p=0x4894ul;p<0x4934ul;p++)*out++=vr8(p);for(p=0x36e0ul;p<0x3710ul;p++)*out++=vr8(p);for(p=0x3c92ul;p<0x3c94ul;p++)*out++=vr8(p);for(p=0x5506ul;p<0x5508ul;p++)*out++=vr8(p);for(p=0x7c874ul;p<0x7c876ul;p++)*out++=vr8(p);}
#endif
#ifdef VM_GAME
#include <string.h>
u16 vm_host_state(u8 *buffer,u8 load){
 u16 at=0;
#define COPY(v) do {if(load)memcpy(&(v),buffer+at,sizeof(v));else memcpy(buffer+at,&(v),sizeof(v));at+=(u16)sizeof(v);}while(0)
 COPY(vm_vars);COPY(vm_actors);COPY(vm_shots);COPY(vm_globals);COPY(stack);COPY(d);COPY(a);
 COPY(fn);COPY(fz);COPY(fv);COPY(fc);COPY(fx);COPY(vm_busy);COPY(vm_resume);COPY(vm_fault);
 COPY(vm_player_state);COPY(vm_platform_opcode);COPY(temp_scroll);COPY(panel_status);
#undef COPY
 return at;
}
#endif

#ifndef VM_HOST
#include "session.h"
void faithful_state_io(void){session_io(&temp_scroll,sizeof(temp_scroll));session_io(&panel_status,sizeof(panel_status));}
#endif
