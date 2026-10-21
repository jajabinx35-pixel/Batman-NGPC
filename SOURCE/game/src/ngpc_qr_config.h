#ifndef NGPC_QR_CONFIG_H
#define NGPC_QR_CONFIG_H
/* Compile ALL consumers with the same profile. Rebuild after changing it.
 * 2 = V2-M (38 alphanumeric characters), 3 = V3-L (77 characters),
 * 4 = V4-L (114 characters) -- EXPERIMENTAL, added to test whether V4 scans
 * reliably now that the 2-modules/hw-tile renderer (ngpc_qr_draw.c) is the
 * "refined" display method, unlike the old byte-mode V4 attempt (round 104)
 * that was dropped for not scanning. At this renderer's fixed 4px/module
 * density, V4's spec-correct 4-module quiet zone needs 21 hw-tiles
 * (168px) -- taller than this screen's 152px. NGPC_QR_QUIET below is
 * SHRUNK to 2 modules for profile 4 only, purely to physically fit the
 * screen; that's below the QR spec's recommended 4-module minimum, so a
 * scan failure on profile 4 doesn't necessarily mean "V4 doesn't work
 * here" -- it may mean "this quiet zone is too thin for this camera/
 * lighting." Profiles 2/3 keep the full spec-correct 4-module zone.
 * 5 = V5-L (154 characters) -- still ONE Reed-Solomon block (same as 2/3/4;
 * V6-L is the first version that needs multiple RS blocks, which this
 * hand-rolled single-block encoder does not implement), so the jump from 4
 * to 5 is just bigger tables, not new encoder logic. Carcassonne2 switched
 * to this profile once it moved off the old 4px/module tile renderer onto
 * real ngpc_bitmap.h pixel mode (1px/module): that renderer has no need to
 * shrink the quiet zone the way profile 4 did, and the extra capacity means
 * most real games now fit in a SINGLE code instead of 2-3 (see main.c's
 * QR_MAX_CODES comment for the remaining worst-case math).
 * Override globally with -DNGPC_QR_PROFILE=2 or edit the default here. */
#ifndef NGPC_QR_PROFILE
#define NGPC_QR_PROFILE 5
#endif
#if NGPC_QR_PROFILE == 2
#define NGPC_QR_SIZE 25u
#define NGPC_QR_BYTES 79u
#define NGPC_QR_TEXT_MAX 38u
#define NGPC_QR_DATA_WORDS 28u
#define NGPC_QR_ECC_WORDS 16u
#define NGPC_QR_QUIET 4u
#elif NGPC_QR_PROFILE == 3
#define NGPC_QR_SIZE 29u
#define NGPC_QR_BYTES 106u
#define NGPC_QR_TEXT_MAX 77u
#define NGPC_QR_DATA_WORDS 55u
#define NGPC_QR_ECC_WORDS 15u
#define NGPC_QR_QUIET 4u
#elif NGPC_QR_PROFILE == 4
#define NGPC_QR_SIZE 33u
#define NGPC_QR_BYTES 137u
#define NGPC_QR_TEXT_MAX 114u
#define NGPC_QR_DATA_WORDS 80u
#define NGPC_QR_ECC_WORDS 20u
#define NGPC_QR_QUIET 2u
#elif NGPC_QR_PROFILE == 5
#define NGPC_QR_SIZE 37u
#define NGPC_QR_BYTES 172u
#define NGPC_QR_TEXT_MAX 154u
#define NGPC_QR_DATA_WORDS 108u
#define NGPC_QR_ECC_WORDS 26u
#define NGPC_QR_QUIET 4u
#else
#error NGPC_QR_PROFILE_must_be_2_3_4_or_5
#endif
#define NGPC_QR_CODEWORDS (NGPC_QR_DATA_WORDS + NGPC_QR_ECC_WORDS)
#define NGPC_QR_DATA_BITS (NGPC_QR_DATA_WORDS * 8u)
#define NGPC_QR_MAP_SIZE ((NGPC_QR_SIZE + 2u * NGPC_QR_QUIET + 1u) / 2u)
#define NGPC_QR_PIXELS (NGPC_QR_MAP_SIZE * 8u)
#endif
