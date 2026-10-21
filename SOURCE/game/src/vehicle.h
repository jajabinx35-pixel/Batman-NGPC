#ifndef BATMAN_VEHICLE_H
#define BATMAN_VEHICLE_H
#include "faithful.h"
#define vehicle_state (stage_work.vehicle.state)
#define vehicle_projection (stage_work.vehicle.projection)
#define vehicle_io (stage_work.vehicle.io)
#define vehicle_rng (stage_work.vehicle.rng)
#define vehicle_hud (stage_work.vehicle.hud)
#define vehicle_clip (stage_work.vehicle.clip)
extern u8 vehicle_stage;
extern u16 vehicle_energy;
extern const u8 vehicle2_code[40440],vehicle4_code[40440];
extern const u8 vehicle2_data[42016],vehicle4_data[42016];
extern const u8 vehicle2_data24[154670],vehicle4_data24[181252];
u8 VM_ABI ver8(u32 p);u16 VM_ABI ver16(u32 p);u32 VM_ABI ver32(u32 p);
void VM_ABI vew8(u32 p,u8 v);void VM_ABI vew16(u32 p,u16 v);void VM_ABI vew32(u32 p,u32 v);
void vehicle_exec(u16 entry);int vehicle_external(u32 pc);
void vehicle_midpoints(void);
void vehicle_native_clip(u16 entry);
void vehicle_native_height(void);void vehicle_native_edges(void);
void vehicle_road_run(void);
void vehicle_road_edge_run(u8 kind);void vehicle_sky_steps(void);
void vehicle_edge_run(u8 kind);
void vehicle_clear_display(void);void vehicle_edges_native(void);void vehicle_scene_native(void);void vehicle_road_native(void);
void vehicle_reset(u8 stage);void vehicle_new(u8 stage);void vehicle_tick(u8 keys,u8 pressed);
#endif
