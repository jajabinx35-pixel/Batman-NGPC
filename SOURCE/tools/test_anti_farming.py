"""Compile the actual M66 reward/respawn functions for focused host checks.
Requires a C compiler for testing only; the Windows ROM builder needs none.
The target ROM build separately checks NGPC RAM/ROM/save boundaries.
"""
from pathlib import Path
import argparse, ctypes as c, json, subprocess, tempfile
P=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--output',type=Path,default=P.parent/'EVIDENCE/M66_ANTI_FARMING/HOST_RESULT.json');v=a.parse_args()
s=(P/'game/src/session.c').read_text()
body=s[s.index('void session_award_points('):s.index('void session_record_live(void)')]
prefix=r"""
#include <stdint.h>
typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32;
typedef struct { u32 score; u16 checkpoint_score_lo,checkpoint_score_hi; u8 lives; } Game;
Game game; u8 run_active,run_score_disabled; u32 run_source_score,run_stage_source_start,run_preview_score;
#define SCORE_MAX 999999u
void session_record_live(void){run_preview_score=run_score_disabled?0:run_source_score;}
"""
class Game(c.Structure):
 _fields_=[('score',c.c_uint32),('checkpoint_score_lo',c.c_uint16),('checkpoint_score_hi',c.c_uint16),('lives',c.c_uint8)]
with tempfile.TemporaryDirectory(prefix='batman_score_test_')as temp:
 t=Path(temp);(t/'score.c').write_text(prefix+body)
 subprocess.run(['cc','-std=c99','-Wall','-Werror','-shared','-fPIC',str(t/'score.c'),'-o',str(t/'score.so')],check=True)
 lib=c.CDLL(str(t/'score.so'));g=Game.in_dll(lib,'game')
 def u32(n):return c.c_uint32.in_dll(lib,n)
 def u8(n):return c.c_uint8.in_dll(lib,n)
 high=u32('run_source_score');entry=u32('run_stage_source_start');active=u8('run_active');disabled=u8('run_score_disabled')
 lib.session_award_points.argtypes=[c.c_uint32]
 for name in ['session_award_points','session_checkpoint_score','session_respawn_score','session_restart_stage_score']:getattr(lib,name).restype=None
 def fresh(base=0,lives=2):
  g.score=high.value=entry.value=base;g.lives=lives;active.value=1;disabled.value=0;lib.session_checkpoint_score()
 def award(n):lib.session_award_points(n)
 def death():lib.session_respawn_score()
 cases=[]
 fresh(3000);award(1000)
 for i in range(100):death();award(1000);assert high.value==4000 and g.lives==2
 award(500);assert high.value==4500;cases.append('100 checkpoint retries do not add repeated rewards; only improvement counts')
 lib.session_checkpoint_score();award(2000);death();award(2000);assert high.value==6500
 cases.append('completed checkpoint section stays banked and next section is protected')
 fresh(1000);award(1000);death();award(500);lib.session_checkpoint_score()
 assert g.score==2000;award(100);assert high.value==2100
 cases.append('crossing next checkpoint banks the best prior attempt without losing points')
 fresh(99000);award(1000);assert g.lives==3
 for i in range(100):death();award(1000);assert g.lives==3 and high.value==100000
 cases.append('repeated 100000-point crossing cannot farm extra lives')
 fresh(5000);award(1000);lib.session_checkpoint_score();award(1200)
 lib.session_restart_stage_score();assert high.value==5000
 # Whole-stage initialisation clears Game; enter_game then reinstalls its base.
 g.score=0;g.checkpoint_score_lo=g.checkpoint_score_hi=0;lib.session_checkpoint_score()
 award(1000);lib.session_checkpoint_score();award(1200);assert high.value==7200
 cases.append('whole-stage restart preserves earlier levels and cannot rebank later checkpoints')
 fresh(7000);award(3000);lib.session_checkpoint_score();award(1000)
 saved=bytes(g);saved_high=high.value;death();award(1000)
 c.memmove(c.addressof(g),saved,len(saved));high.value=saved_high
 death();award(1000);assert high.value==11000
 cases.append('restored checkpoint baseline and high water prevent duplicate rewards')
 fresh(999000);award(2000);assert g.score==high.value==999999
 death();award(2000);assert g.score==high.value==999999
 cases.append('score cap and replay remain bounded')
 fresh();disabled.value=1;award(100000);assert g.score==high.value==0 and g.lives==2
 cases.append('lives-disabled scoring cannot grant ranked points or extra lives')
 result={'passed':True,'cases':cases,'source':'actual functions extracted from game/src/session.c','scope':'host arithmetic/control checks; target-ROM persistence is checked separately'}
 v.output.parent.mkdir(parents=True,exist_ok=True);v.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
