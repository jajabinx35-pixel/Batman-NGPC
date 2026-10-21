#ifndef BATMAN_GAME_H
#define BATMAN_GAME_H
#include "assets.h"
#include "residency.h"
#include "ngpc_hw.h"
#define ACTORS 4
#define SHOTS 8
#define HAZARDS 21
enum {P_GROUND,P_FALL,P_CLIMB,P_HOOK,P_HANG,P_LAND,P_PULLUP,P_DYING};
enum {B_NONE,B_ACTIVE,B_FALLING,B_SPLASH,B_COMPLETE};
typedef struct {
 s16 x,y,vx,vy,fall,drop_y;
 s16 hook_x,hook_y,rope_length,angle,swing_speed;
 u8 state,facing,pose,shoot,cooldown,invulnerable,state_time,hook_dir;
} Player;
typedef struct {
 s16 x,y,start_x,start_y;
 u16 source;
 u8 active,type,facing,skin,pose,hp,cooldown,anim,dying;
 u8 aim; s8 climb; s16 vy;
} Actor;
typedef struct {s16 x,y,vx,vy;u8 active,kind,life,owner;} Shot;
typedef struct {
 s16 x,y,draw_x,draw_y,offset;
 u8 type,phase,velocity,visible,harmful,pose,in_range;
} Hazard;
typedef struct {
 Player player;
 u8 health,lives,alive,ended,last_keys;
 u8 checkpoint,sfx;
 u16 ticks,seconds,subsecond,game_over_wait;
 /* Reuse the unused max_x/kills words: no extra NGPC RAM or save bytes. */
 u16 checkpoint_score_lo,checkpoint_score_hi,damage_taken;
 u32 score;
 u16 hazard_hits,hazard_cycles,stage_ticks;
 s16 boss_x,boss_y;
 u8 boss_state,boss_slot,boss_anim;
} Game;
typedef struct {s16 x,y;u16 id;} BobDraw;
typedef struct {
 BobDraw bobs[64];u16 sprites[128],palettes[32],cache[128];
 u8 oldx[32],oldy[32],newx[32],newy[32];u16 rope[32][8];PlatformResidency resident;
} PlatformRender;
typedef struct {u16 road[1600],patterns[512],descriptors[128],palettes[32],map[200];u16 skyx; s16 skyy;NativeResidency resident;} NativeRender;
typedef union {PlatformRender platform;NativeRender native;u8 reserved[6280];} RenderWork;
extern RenderWork render_work;
#define bob_draws (render_work.platform.bobs)
extern u8 bob_draw_count,vm_wait,vm_phase;
extern Game game;
u8 game_tile(s16 x,s16 y);
void game_new(void);
void game_tick(u8 keys,u8 pressed);
void game_reset_position(void);
u8 game_actor_count(void);
void game_hurt(u8 value);
void game_hazards_reset(void);
void game_hazards_tick(void);
#endif
