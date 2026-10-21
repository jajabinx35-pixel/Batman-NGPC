#ifndef BATMAN_LEADERBOARD_H
#define BATMAN_LEADERBOARD_H
#include "ngpc_qr.h"
extern u8 leaderboard_cursor;
/* 0=legacy overall format2; 1..5=stage format3. */
extern u8 leaderboard_target;
void leaderboard_edit(u8 keys,u8 pressed,u8 refresh);
u8 leaderboard_encode(void);
NgpcQr *leaderboard_matrix(void);
const char *leaderboard_text(void);
#endif
