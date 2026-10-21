#ifndef BATMAN_DIRECT_MEMORY_H
#define BATMAN_DIRECT_MEMORY_H
/* Compile-time-resolved mutable addresses. The ordinary mapper handles every
 * dynamic or unproved address. Keep big-endian platform bytes exactly intact. */
#ifdef VM_HOST
#define DM_INLINE inline
#define DM_NEAR
#else
#define DM_INLINE __inline
#define DM_NEAR __near
#endif
static u16 DM_INLINE dm_be16(const u8 DM_NEAR *q){return(u16)((u16)q[0]<<8)|q[1];}
static u32 DM_INLINE dm_be32(const u8 DM_NEAR *q){return((u32)q[0]<<24)|((u32)q[1]<<16)|((u16)q[2]<<8)|q[3];}
static void DM_INLINE dm_put16(u8 DM_NEAR *q,u16 v){q[0]=(u8)(v>>8);q[1]=(u8)v;}
static void DM_INLINE dm_put32(u8 DM_NEAR *q,u32 v){q[0]=(u8)(v>>24);q[1]=(u8)(v>>16);q[2]=(u8)(v>>8);q[3]=(u8)v;}
#endif
