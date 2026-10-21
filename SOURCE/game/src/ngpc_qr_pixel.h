/* MIT. Pixel-mode QR renderer for ngpc_qr.h -- standalone (needs only ngpc_hw.h + ngpc_gfx.h). */
#ifndef NGPC_QR_PIXEL_H
#define NGPC_QR_PIXEL_H
#include "ngpc_qr.h"

/* Recommended scale for the default profile (V5-L, 37 modules): 3 px per module with the full
 * 4-module quiet zone = (37 + 8) * 3 = 135 px, the largest whole scale that fits the 160x152 screen.
 * Scale 2 (90 px) also scans but is harder for a phone to lock onto; never go below 2. */
#define NGPC_QR_PIXEL_SCALE 3u

/* Side length in pixels of the drawn square, quiet zone included. */
u16 ngpc_qr_pixel_px(u8 scale);

/* Number of consecutive tile slots the drawing claims starting at tile_base, for a code whose
 * top-left pixel is (x, y). Budget these against your game's own tile art (tiles 0..511 total;
 * tile 0 is reserved, and 32..127 are the BIOS font if you still print text afterwards). */
u16 ngpc_qr_pixel_tiles(u8 x, u8 y, u8 scale);

/* Draw an already-encoded code (ngpc_qr_encode() returned 1) on GFX_SCR1 or GFX_SCR2.
 *
 *   plane      GFX_SCR1 / GFX_SCR2
 *   tile_base  first of ngpc_qr_pixel_tiles() consecutive free tile slots (it OVERWRITES them)
 *   palette    0..15, set by this call: index 1 = white, index 2 = black, index 0 = transparent
 *   scale      pixels per module, 1..4 (4 only fits smaller profiles); see NGPC_QR_PIXEL_SCALE
 *   x, y       top-left pixel of the code including its quiet zone (screen is 160x152)
 *
 * The map cells of the covered tile rectangle on that plane are rewritten to point at the claimed
 * tiles. Pixels of those tiles that fall outside the code square stay index 0 (transparent), so
 * pick a backdrop colour/plane that makes that look right -- on a white or black backdrop the code
 * square is simply surrounded by that colour.
 *
 * Returns 0 BEFORE any VRAM writes if qr is NULL/invalid, an argument is out of range, the code
 * would not fit on screen, or the tile range would run past tile 511. Returns 1 on success.
 * No vsync, no clears, no sprite or scroll handling -- the caller owns all of that.
 *
 * Takes a moment (a full screen of tile writes): call it after the screen is otherwise set up,
 * and ENCODE FIRST -- see the guide: never call ngpc_qr_encode() after drawing in the same tick. */
u8 ngpc_qr_pixel_draw(const NgpcQr *qr, u8 plane, u16 tile_base, u8 palette,
                      u8 scale, u8 x, u8 y);

#endif
