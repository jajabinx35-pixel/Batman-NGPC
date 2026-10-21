/* Pocket Sprint: 64 x 512-byte journal records in reserved 32 KiB block 31. */
#ifndef NGPC_FLASH_H
#define NGPC_FLASH_H
#include "ngpc_types.h"
#define SAVE_SIZE 512
void ngpc_flash_init(void);
void ngpc_flash_save(const void *data);
void ngpc_flash_load(void *data);
u8 ngpc_flash_exists(void);
u16 ngpc_flash_verify(const void *data);
#endif
