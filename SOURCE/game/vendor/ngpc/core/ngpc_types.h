/*
 * ngpc_types.h - Base integer types for NGPC development
 *
 * Part of NgpCraft_base_template (MIT License)
 * Written from scratch - no third-party code.
 */

#ifndef NGPC_TYPES_H
#define NGPC_TYPES_H

#include "ngpc_config.h"

/* The bundled cc900 build uses its default full cartridge address pointer
 * representation.  The old -DNGP_FAR=__far switch is not supported by
 * this compiler; keep this qualifier optional across ALL vendor modules,
 * including ngpc_flash.c which does not include the game or gfx headers. */
#ifndef NGP_FAR
#define NGP_FAR
#endif

#ifdef VM_HOST
#include <stdint.h>
typedef uint8_t u8;typedef uint16_t u16;typedef uint32_t u32;
typedef int8_t s8;typedef int16_t s16;typedef int32_t s32;
#else
typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned long   u32;
typedef signed char     s8;
typedef signed short    s16;
typedef signed long     s32;

#endif

typedef void (*FuncPtr)(void);
typedef void __interrupt IntHandler(void);

#endif /* NGPC_TYPES_H */
