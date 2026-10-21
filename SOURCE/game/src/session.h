#ifndef BATMAN_SESSION_H
#define BATMAN_SESSION_H
#include "faithful.h"
#ifdef VM_HOST
#define cheat_invulnerable 0
#define cheat_freeze_time 0
#define run_score_disabled 0
#else
extern u8 option_lives,cheat_unlocked,cheat_invulnerable,cheat_freeze_time,run_cheated,run_active;
extern u8 run_score_disabled;
#endif
extern u8 save_available,save_kind,save_stage,save_error,last_score_cheated;
extern u8 last_score_disabled;
extern u32 best_score,last_score;
extern volatile u32 run_refreshes,run_preview_score;
extern u32 run_stage_start,run_stage_ticks[5],best_run_ticks,best_stage_ticks[5],last_run_ticks;
extern u8 run_completed_mask,last_run_complete,best_completed_mask;
extern u32 run_source_score,run_bonus_score,best_source_score;
/* Independent eligible stage-clear records, not cumulative campaign scores. */
u32 session_stage_best_ticks(u8 stage);
u32 session_stage_best_source(u8 stage);
u32 session_stage_best_score(u8 stage);
u32 session_time_bonus(u8 stage,u32 ticks);
extern char record_initials[4];
void session_vblank(void);
u8 session_upload_available(void);
u8 session_stage_upload_available(u8 stage);
void session_init(void);
u8 session_cheat_input(u8 keys);
void session_new_run(void);
void session_record_live(void);
#ifdef VM_HOST
/* Reference-engine host builds do not link the console session manager. */
#define session_award_points(points) (game.score+=(points))
#define session_checkpoint_score() ((void)0)
#define session_respawn_score() ((void)0)
#else
void session_award_points(u32 points);
void session_checkpoint_score(void);
void session_respawn_score(void);
void session_restart_stage_score(void);
#endif
void session_record_end(void);
u8 session_save_game(void);
u8 session_save_transition(u8 next_stage);
u8 session_save_profile(void);
u8 session_reset_records(void);
u8 session_restore(void);
void session_io(void *data,u16 count);
void game_state_io(void);void cat_state_io(void);void vehicle_state_io(void);
void faithful_state_io(void);void cathedral_state_io(void);void vehicle_memory_state_io(void);
#endif
