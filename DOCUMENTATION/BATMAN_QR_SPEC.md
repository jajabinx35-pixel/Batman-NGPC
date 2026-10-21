# BATMAN QR format 2 — unchanged for overall scores in M65

Prefix `NGPC-DEV.COM/BATMAN/` (20 chars); payload72 chars; full QR text92 chars. This replaces M62's full-game-only countdown format1. BATMAN remains the six-letter game code.

| Offset | Width | Field | Format/bounds |
|---:|---:|---|---|
| 0 | 6 | gameCode | fixed BATMAN |
| 6 | 1 | version | fixed 2 |
| 7 | 3 | initials | A-Z |
| 10 | 7 | score | zero-padded decimal,1..999999 |
| 17 | 7 | sourcePoints | zero-padded decimal,0..999999 |
| 24 | 7 | totalTicks | zero-padded decimal,1..9999999 |
| 31 | 2 | completedMask | decimal, one of 00 01 03 07 15 31 |
| 33 | 7 | stage1Ticks | decimal, 0..9999999; positive for cleared stages, zero for future stages |
| 40 | 7 | stage2Ticks | decimal, 0..9999999; positive for cleared stages, zero for future stages |
| 47 | 7 | stage3Ticks | decimal, 0..9999999; positive for cleared stages, zero for future stages |
| 54 | 7 | stage4Ticks | decimal, 0..9999999; positive for cleared stages, zero for future stages |
| 61 | 7 | stage5Ticks | decimal, 0..9999999; positive for cleared stages, zero for future stages |
| 68 | 4 | checksum | uppercase hexadecimal |

## Validation and scoring

Score=min(999999, sourcePoints + sum(stage-clear bonuses)). For completed stage i, bonus=max(0,budget[i]-floor(stageTicks[i]*20/1199))*100; budgets in seconds=[480,300,60,180,720]. Uncleared stage has zero bonus. totalTicks=sum(stage1Ticks..stage5Ticks). Mask must be consecutive cleared stages (0,1,3,7,15,31). Validate score by recomputing it. Rank score descending; exact scores tie.

The mask counts completed stages in order. All completed-stage splits must be positive. At most the next uncleared stage may have a nonzero partial time; later splits must be zero. Positive game-over records in stage1 have mask00, a positive stage1 partial time, four zero future times and score equal to sourcePoints. Dying earlier does not grant any time bonus.

Raw times are active display refreshes. Convert ticks*20/1199 to seconds using rational/integer arithmetic; keep raw integers for validation. Pauses, menus, loading and cinematics do not accrue time. The stopwatch cap is9,999,999 refreshes; score cap999,999.

## Checksum

CRC-16/CCITT-FALSE: polynomial0x1021, initial0xFFFF, no reflection, xorout0. Feed payload ASCII offsets0..67 followed by ASCII salt `BATMAN63`; append four uppercase hex digits at offsets68..71. Prefix excluded. This detects corruption; it does not authenticate offline scores cryptographically. The independent Python validator is `SOURCE/tools/batman_score_payload.py`.

## Device UI and integration

Records always displays Upload Best Score. At zero it explains `EARN SCORE TO UPLOAD` and cannot generate a QR. During a cheat-unlocked boot it explains `CHEATS BLOCK UPLOAD`. A positive eligible game-over score can be uploaded immediately; clearing the game is not required. Enter three initials, then OPTION to build the QR. B returns.

The on-device QR is profile5,37 modules,3 pixels per module,4-module quiet border,135×135 pixels. The codec and renderer are based on the supplied SDKv2. The site owner must support this new format/formula for online acceptance; this package does not publish or submit a leaderboard entry.

## Synthetic parser examples

```
NGPC-DEV.COM/BATMAN/BATMAN2AAA0002020000202000008000000008000000000000000000000000000000EE6D
```
```
NGPC-DEV.COM/BATMAN/BATMAN2BOB0036400000340000102000100090000001200000000000000000000000E70B
```
```
NGPC-DEV.COM/BATMAN/BATMAN2END01657000045000003200031000900000060000002000000300000120002D0A
```
```
NGPC-DEV.COM/BATMAN/BATMAN2MAX09999990999999999999900999999900000000000000000000000000006151
```


## M65 new: format 3 — per-stage QR

The existing overall score QR (format 2, payload 72 characters) remains exactly as documented above. The five **independent stage-cleared high scores** use the compact format 3. Each stage has its own score and ranking; this is not a way to upload five entries into the existing overall scoreboard.

Prefix: `NGPC-DEV.COM/BATMAN/` (20 ASCII characters). The format 3 body is **36 characters** (total QR text 56). Fields:

| Offset | Width | Name | Rules |
|---:|---:|---|---|
| 0 | 6 | gameCode | `BATMAN` |
| 6 | 1 | version | `3` |
| 7 | 3 | initials | `A-Z` |
| 10 | 1 | stage | `1`, `2`, `3`, `4` or `5` |
| 11 | 7 | score | 0000001..0999999 |
| 18 | 7 | sourcePoints | 0000000..0999999; arcade points gained **within this stage** |
| 25 | 7 | stageTicks | 0000001..9999999; active display refreshes while playing this cleared stage |
| 32 | 4 | checksum | uppercase CRC16/CCITT-FALSE hex |

For stage `i`, `stageBonus=max(0,budgetSeconds[i]-floor(stageTicks*20/1199))*100`; budgets for stages 1..5 are `[480,300,60,180,720]`. `score=min(999999,sourcePoints+stageBonus)`. Rank scores descending **separately for each level**. For an equal score the device retains the quicker local best; the server may treat identical scores as ties. Checksums use CRC16/CCITT-FALSE `poly=0x1021`, `init=0xFFFF`, no reflection, `xorout=0`, over the 32 ASCII payload bytes followed by ASCII `BATMAN65`. The URL prefix is excluded.

Only **cleared stages** in eligible runs are eligible. Cheat activation disqualifies the whole boot; starting with more than three lives disqualifies the run. Reset Records clears both overall and stage records but preserves manual/Continue snapshots. M64 save files automatically migrate when next written, retaining existing overall scores and saves; pre-M65 runs do not retroactively acquire independent stage highs.

On console: `Main Menu > Records > Stage High Scores`; select with UP/DOWN, press A to enter initials and OPTION to show the stage QR. On an untouched level without a positive eligible clear, A does nothing. `Records > Upload Best Score` continues to emit the original format-2 overall QR.

The online scoreboard **must separately implement format 3 and its five categories**. Creating the QR and decoding it in MAME does not mean NGPC-DEV.COM currently accepts or ranks format 3. No submission/site configuration has been performed.

Standalone administrator schema: `BATMAN_Stage_Leaderboard_Submission.json`; combined schema: `BATMAN_Leaderboard_Submission.json` with `additionalPayloadFormats`.
