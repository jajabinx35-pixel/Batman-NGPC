#ifndef BATMAN_PLATFORM_SCAN_H
#define BATMAN_PLATFORM_SCAN_H
#include "faithful.h"
u8 platform_spawn_scan(u16 variables_base,u16 first,u16 end);
u8 platform_hazard_scan(u16 variables_base,u16 first,u16 end);
u8 platform_empty_shots(u16 first,u8 destination_register);
u8 platform_draw_push(void);
u8 platform_draw_pop(void);
u8 platform_actor_enter(u16 first,u16 camera_offset);
u8 platform_projectile_actors(u16 first);
u8 platform_actor_draw(u16 continuation,u8 cathedral);
#endif
