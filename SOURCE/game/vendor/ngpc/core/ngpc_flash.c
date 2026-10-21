/* Standard BIOS save path, compatible with hardware and HLE persistence.
 * ROM builds reserve first-window offset 0x1F0000..0x1FFFFF for saves. 4 MiB builds keep this reservation and use the second cartridge window for expansion. */
#include "ngpc_hw.h"
#include "ngpc_flash.h"
#define SAVE_OFFSET 0x1F0000UL
#define NUM_SLOTS 64
#ifdef PS_FLASH_TEST
extern unsigned char test_flash[32768];
#define SAVE_ADDR test_flash
#else
#define SAVE_ADDR ((volatile u8 NGP_FAR *)(CART_ROM_BASE+SAVE_OFFSET))
#endif
#if !NGP_ENABLE_FLASH_SAVE
void ngpc_flash_init(void){}
void ngpc_flash_save(const void *data){(void)data;}
void ngpc_flash_load(void *data){(void)data;}
u8 ngpc_flash_exists(void){return 0;}
u16 ngpc_flash_verify(const void *data){(void)data;return 0xffff;}
#else
extern void ngpc_flash_erase_asm(void);
extern void ngpc_flash_write_asm(const void *data,u32 offset);
static u8 last_slot=255;
static u8 next_slot(void)
{
 u8 i;u16 j;
 for(i=0;i<NUM_SLOTS;i++){
  for(j=0;j<SAVE_SIZE;j++)if(SAVE_ADDR[(u32)i*SAVE_SIZE+j]!=255)break;
  if(j==SAVE_SIZE)return i;
 }
 return NUM_SLOTS;
}
static u8 newest_slot(void)
{
 u8 i;u16 j,sum;u32 base;
 i=NUM_SLOTS;
 while(i--){
  base=(u32)i*SAVE_SIZE;
  if(SAVE_ADDR[base]!=0x50 || SAVE_ADDR[base+1]!=0x4f || SAVE_ADDR[base+2]!=0x50 || SAVE_ADDR[base+3]!=0x31 || SAVE_ADDR[base+4]!=1)continue;
  sum=0;for(j=0;j<510;j++)sum=(u16)(sum+SAVE_ADDR[base+j]);
  if(sum==((u16)SAVE_ADDR[base+510]|((u16)SAVE_ADDR[base+511]<<8)))return i;
 }
 return 255;
}
void ngpc_flash_init(void){last_slot=255;}
void ngpc_flash_save(const void *data)
{
 u8 slot;u16 i;
 slot=next_slot();
 if(slot==NUM_SLOTS){
  ngpc_flash_erase_asm();
  for(i=0;i<32768;i++)if(SAVE_ADDR[i]!=255){last_slot=255;return;}
  slot=0;
 }
 last_slot=slot;
 ngpc_flash_write_asm(data,SAVE_OFFSET+(u32)slot*SAVE_SIZE);
}
void ngpc_flash_load(void *data)
{
 u8 slot;u8 *dst;u16 i;u32 base;
 slot=newest_slot();if(slot==255)return;
 base=(u32)slot*SAVE_SIZE;dst=(u8 *)data;
 for(i=0;i<SAVE_SIZE;i++)dst[i]=SAVE_ADDR[base+i];
}
u8 ngpc_flash_exists(void){return newest_slot()!=255;}
u16 ngpc_flash_verify(const void *data)
{
 const u8 *src;u32 base;u16 i,errors;
 if(last_slot==255)return 0xffff;
 src=(const u8 *)data;base=(u32)last_slot*SAVE_SIZE;errors=0;
 for(i=0;i<SAVE_SIZE;i++)if(SAVE_ADDR[base+i]!=src[i])errors++;
 return errors;
}
#endif
