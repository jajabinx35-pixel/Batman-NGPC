/* MIT. Pixel-mode QR renderer: builds each module row once as one 16-bit word per tile column and
 * writes it straight into tile RAM (2 bits per pixel, leftmost pixel in the high bits). This is the
 * renderer behind the codes shipped in Neo Bowling and Carcassonne2; it replaces the older
 * 4 px/module tile renderer (ngpc_qr_draw.c), which cannot fit a profile-5 code on screen.
 *
 * cc900 notes baked into the shape of this file (all learned the hard way on this toolchain):
 *  - non-leaf function with many locals -> every local is static (keeps the frame tiny; a large
 *    frame in a non-leaf function can compile to a broken prologue)
 *  - pixel shift comes from a lookup table, not (7 - col) * 2: a byte self-add compiles to the
 *    broken CB81 opcode
 *  - every u8 that feeds a shift/multiply/add that could exceed 255 is widened to u16 first
 */
#include "ngpc_qr_pixel.h"
#include "ngpc_hw.h"
#include "ngpc_gfx.h"
#include "game.h"

/* bit position of pixel column 0..7 inside a tile-row word (leftmost pixel highest) */
static const u8 s_px_shift[8] = { 14u, 12u, 10u, 8u, 6u, 4u, 2u, 0u };

#define QR_MODULES ((u16)(NGPC_QR_SIZE + 2u * NGPC_QR_QUIET))   /* 45 for profile 5 */

u16 ngpc_qr_pixel_px(u8 scale)
{
    return (u16)(QR_MODULES * (u16)scale);
}

u16 ngpc_qr_pixel_tiles(u8 x, u8 y, u8 scale)
{
    u16 px = ngpc_qr_pixel_px(scale);
    u16 cols = (u16)(((u16)x + px - 1u) >> 3) - (u16)(x >> 3) + 1u;
    u16 rows = (u16)(((u16)y + px - 1u) >> 3) - (u16)(y >> 3) + 1u;
    return (u16)(cols * rows);
}

u8 ngpc_qr_pixel_draw(const NgpcQr *qr, u8 plane, u16 tile_base, u8 palette,
                      u8 scale, u8 x, u8 y)
{
    /* Records are reached from the title; render_work has no live frame here. */
    u16 *row = (u16 *)(render_work.reserved + 768u);
    static u16 px, py, bit, tile, n;
    static volatile u16 *dst;
    static volatile u16 *map;
    static u8 tx0, ty0, cols, rows, mx, my, ox, s, k, c, tx, ty, in_row;

    if (!qr || !qr->valid || plane > (u8)GFX_SCR2 || palette > 15u ||
        scale < 1u || scale > 4u) return 0u;
    px = ngpc_qr_pixel_px(scale);
    if ((u16)x + px > 160u || (u16)y + px > 152u) return 0u;
    tx0 = (u8)(x >> 3);
    ty0 = (u8)(y >> 3);
    cols = (u8)((u8)(((u16)x + px - 1u) >> 3) - tx0 + 1u);
    rows = (u8)((u8)(((u16)y + px - 1u) >> 3) - ty0 + 1u);
    if ((u16)tile_base + (u16)cols * (u16)rows > 512u) return 0u;

    /* palette: 0 transparent, 1 white, 2 black */
    ngpc_gfx_set_palette(plane, palette, 0x0000u, 0x0FFFu, 0x0000u, 0x0000u);

    /* clear the claimed tiles, then point the covered map cells at them */
    dst = HW_TILE_DATA + (u16)(tile_base * TILE_WORDS);
    n = (u16)((u16)cols * (u16)rows * TILE_WORDS);
    for (bit = 0u; bit < n; bit++) dst[bit] = 0u;
    map = (plane == (u8)GFX_SCR1) ? HW_SCR1_MAP : HW_SCR2_MAP;
    for (ty = 0u; ty < rows; ty++) {
        for (tx = 0u; tx < cols; tx++) {
            tile = (u16)(tile_base + (u16)ty * cols + tx);
            map[(u16)(ty0 + ty) * SCR_MAP_W + (u16)(tx0 + tx)] = SCR_TILE(tile, palette);
        }
    }

    py = y;
    for (my = 0u; my < (u8)QR_MODULES; my++) {
        for (tx = 0u; tx < cols; tx++) row[tx] = 0u;
        ox = x;
        /* the matrix row's bits in order (ngpc_qr_get_module()'s layout: bit = y * SIZE + x,
         * LSB first) without a function call per module */
        in_row = (u8)(my >= NGPC_QR_QUIET && my < (u8)(NGPC_QR_QUIET + NGPC_QR_SIZE));
        if (in_row) bit = (u16)((u16)(my - NGPC_QR_QUIET) * NGPC_QR_SIZE);
        for (mx = 0u; mx < (u8)QR_MODULES; mx++) {
            c = 1u;   /* white (quiet zone and light modules) */
            if (in_row && mx >= NGPC_QR_QUIET && mx < (u8)(NGPC_QR_QUIET + NGPC_QR_SIZE)) {
                if ((qr->matrix[bit >> 3] >> (bit & 7u)) & 1u) c = 2u;   /* dark */
                bit++;
            }
            for (s = 0u; s < scale; s++) {
                row[(u16)(ox >> 3) - (u16)tx0] |= (u16)((u16)c << s_px_shift[ox & 7u]);
                ox++;
            }
        }
        for (k = 0u; k < scale; k++) {
            dst = HW_TILE_DATA
                + (u16)((u16)(tile_base + (u16)((py >> 3) - (u16)ty0) * (u16)cols) * TILE_WORDS)
                + (u16)(py & 7u);
            for (tx = 0u; tx < cols; tx++) dst[(u16)tx * TILE_WORDS] = row[tx];
            py++;
        }
    }
    return 1u;
}
