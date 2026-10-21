#ifndef BATMAN_STAGE_WORK_H
#define BATMAN_STAGE_WORK_H
/* Stages are mutually exclusive. Share their scratch RAM explicitly. */
typedef struct {u8 variables[1748],actors[220],shots[160],globals[48];} PlatformWork;
typedef struct {u8 state[1008],projection[1424],io[200],rng[6],clip[64],hud[54],fx[20];} VehicleWork;
typedef union {PlatformWork platform;VehicleWork vehicle;u8 puzzle[2776];} StageWork;
extern StageWork stage_work;
#define vm_vars (stage_work.platform.variables)
#define vm_actors (stage_work.platform.actors)
#define vm_shots (stage_work.platform.shots)
#define vm_globals (stage_work.platform.globals)
#endif
