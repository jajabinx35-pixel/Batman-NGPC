$MAXIMUM
        module vehicle_rows_all
        public _vehicle_midpoint_rows
        public _vehicle_road_rows
        public .vehicle_road_rows_fast
        extern _vehicle_road_y
        extern _render_work
        extern _d
        extern _a
        extern _stage_work
MIDPOINT_ROWS section code large
; All 112 native 16-bit samples, retaining wrapped subtract and signed ASR.
_vehicle_midpoint_rows:
        push xix
        ld xix,_stage_work+1008
        ld bc,112
midpoint_row:
        ld wa,(xix)
        ld de,(xix+1024)
        sub de,wa
        sra 1,de
        add wa,de
        ld (xix+512),wa
        ld hl,de
        sra 1,hl
        add wa,hl
        ld (xix+768),wa
        sub wa,de
        ld (xix+256),wa
        inc 2,xix
        djnz bc,midpoint_row
        pop xix
        ret
; road base, projection start, y|(count<<16), marker bits.
; Caller selects count<=151; out-of-range source y values are skipped.
VEHICLE_ROWS section code large
_vehicle_road_rows:
        push xix
        push xiy
        push xiz
        ld xix,(xsp+16)
        ld xiy,(xsp+20)
        ld xhl,(xsp+24)
        ld xiz,(xsp+28)
        ld de,hl
        srl 8,xhl
        srl 8,xhl
        jr road_rows_setup
; __adecl count in WA. Same raster body; avoid rebuilding four 32-bit
; C arguments and re-reading marker inputs in the generic wrapper.
.vehicle_road_rows_fast:
        push xix
        push xiy
        push xiz
        ld hl,wa
        ld de,(_vehicle_road_y)
        ld xix,_render_work
        ld xiy,0
        ld iy,(_a+20)
        sub iy,0x7bc8
        add xiy,_stage_work+1008
        ld xiz,0
        ld iz,31
        ld wa,(_stage_work+586)
        or wa,(_stage_work+588)
        jr z,road_fast_all_marks
        and iz,17
road_fast_all_marks:
        ld wa,(_d+22)
        bit 0,a
        jr z,road_fast_left_mark
        res 0,iz
road_fast_left_mark:
        bit 1,a
        jr z,road_rows_setup
        res 4,iz
road_rows_setup:
        ld wa,de
        and wa,1
        cp hl,wa
        jp c,road_rows_return
        sub hl,wa
        srl 1,hl
        inc 1,hl
        add wa,wa
        ld xbc,0
        ld bc,wa
        add xiy,xbc
        sra 1,de
        sub xsp,12
        ld (xsp),hl
        ld (xsp+2),de
        ld (xsp+8),iz
        ld xiz,bulk_road_pixel_masks
road_rows_start:
        ld wa,(xsp+2)
        cp wa,0
        jp lt,road_rows_done
        cp wa,76
        jp ge,road_rows_skip
        ld xhl,0
        ld hl,wa
        srl 3,hl
        ld xbc,xhl
        sll 8,xhl
        sll 6,xbc
        add xhl,xbc
        and wa,7
        sll 1,wa
        ld xbc,0
        ld bc,wa
        add xhl,xbc
        add xix,xhl
road_rows_draw:
        ld wa,(xiy)
        sra 1,wa
        ld bc,(xiy+1024)
        sra 1,bc
        cp wa,bc
        jp ge,bulk_road_marks
        cp wa,160
        jp ge,bulk_road_marks
        cp bc,0
        jp le,bulk_road_marks
        cp wa,0
        jr ge,bulk_road_left_ok
        ld wa,0
bulk_road_left_ok:
        cp bc,160
        jr le,bulk_road_right_ok
        ld bc,160
bulk_road_right_ok:
        ld xhl,0
        ld hl,wa
        and hl,0xfff8
        sll 1,hl
        ld xde,0
        ld de,wa
        and de,7
        sll 1,de
        add xde,bulk_road_left_masks
        ld wa,(xde)
        ld xde,0
        ld de,bc
        dec 1,de
        and de,0xfff8
        sll 1,de
        push de
        push hl
        ld hl,bc
        and hl,7
        sll 1,hl
        ld xiz,0
        ld iz,hl
        add xiz,bulk_road_right_masks
        ld bc,(xiz)
        pop hl
        pop de
        cp hl,de
        jr z,bulk_road_one_tile
        add xhl,xix
        add xde,xix
        and wa,0xaaaa
        ld (xhl),wa
        lda xhl,xhl+16
        ld wa,0xaaaa
; Clipped spans contain at most 18 complete interior cells. Jump to
; the exact fall-through store run, removing a compare/branch/pointer
; advance for every full cell. Both partial edge masks remain unchanged.
        ld xiz,xde
        sub xiz,xhl
        srl 2,iz
        ld xhl,bulk_road_fill_table
        ld xhl,(xhl+iz)
        jp xhl
bulk_road_fill_18:
        ld (xde-288),wa
bulk_road_fill_17:
        ld (xde-272),wa
bulk_road_fill_16:
        ld (xde-256),wa
bulk_road_fill_15:
        ld (xde-240),wa
bulk_road_fill_14:
        ld (xde-224),wa
bulk_road_fill_13:
        ld (xde-208),wa
bulk_road_fill_12:
        ld (xde-192),wa
bulk_road_fill_11:
        ld (xde-176),wa
bulk_road_fill_10:
        ld (xde-160),wa
bulk_road_fill_9:
        ld (xde-144),wa
bulk_road_fill_8:
        ld (xde-128),wa
bulk_road_fill_7:
        ld (xde-112),wa
bulk_road_fill_6:
        ld (xde-96),wa
bulk_road_fill_5:
        ld (xde-80),wa
bulk_road_fill_4:
        ld (xde-64),wa
bulk_road_fill_3:
        ld (xde-48),wa
bulk_road_fill_2:
        ld (xde-32),wa
bulk_road_fill_1:
        ld (xde-16),wa
bulk_road_fill_0:
bulk_road_last:
        and bc,0xaaaa
        ld (xde),bc
        jr bulk_road_marks
bulk_road_one_tile:
        add xhl,xix
        and wa,bc
        and wa,0xaaaa
        ld (xhl),wa
bulk_road_marks:
        ld xiz,bulk_road_pixel_masks
        bit 0,(xsp+8)
        jr z,bulk_road_mark_0
        ld wa,(xiy)
        cp wa,320
        jr nc,bulk_road_mark_0
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
bulk_road_mark_0:
        bit 1,(xsp+8)
        jr z,bulk_road_mark_1
        ld wa,(xiy+256)
        cp wa,320
        jr nc,bulk_road_mark_1
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
bulk_road_mark_1:
        bit 2,(xsp+8)
        jr z,bulk_road_mark_2
        ld wa,(xiy+512)
        cp wa,320
        jr nc,bulk_road_mark_2
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
bulk_road_mark_2:
        bit 3,(xsp+8)
        jr z,bulk_road_mark_3
        ld wa,(xiy+768)
        cp wa,320
        jr nc,bulk_road_mark_3
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
bulk_road_mark_3:
        bit 4,(xsp+8)
        jr z,bulk_road_mark_4
        ld wa,(xiy+1024)
        cp wa,320
        jr nc,bulk_road_mark_4
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
bulk_road_mark_4:
bulk_road_done:
        ld wa,(xsp)
        dec 1,wa
        ld (xsp),wa
        cp wa,0
        jr z,road_rows_done
        ld wa,(xsp+2)
        cp wa,0
        jr z,road_rows_done
        and wa,7
        jr z,road_rows_previous_band
        lda xix,xix-2
        jr road_rows_advance
road_rows_previous_band:
        lda xix,xix-306
road_rows_advance:
        ld wa,(xsp+2)
        dec 1,wa
        ld (xsp+2),wa
        lda xiy,xiy+4
        jp road_rows_draw
road_rows_skip:
        ld wa,(xsp)
        dec 1,wa
        ld (xsp),wa
        cp wa,0
        jr z,road_rows_done
        ld wa,(xsp+2)
        dec 1,wa
        ld (xsp+2),wa
        lda xiy,xiy+4
        ld (xsp+4),xiy
        jp road_rows_start
road_rows_done:
        add xsp,12
road_rows_return:
        pop xiz
        pop xiy
        pop xix
        ret
bulk_road_fill_table:
        dd bulk_road_fill_0,bulk_road_fill_1,bulk_road_fill_2,bulk_road_fill_3,bulk_road_fill_4,bulk_road_fill_5,bulk_road_fill_6,bulk_road_fill_7,bulk_road_fill_8,bulk_road_fill_9,bulk_road_fill_10,bulk_road_fill_11,bulk_road_fill_12,bulk_road_fill_13,bulk_road_fill_14,bulk_road_fill_15,bulk_road_fill_16,bulk_road_fill_17,bulk_road_fill_18
bulk_road_left_masks:
        dw 0xffff,0x3fff,0x0fff,0x03ff,0x00ff,0x003f,0x000f,0x0003
bulk_road_right_masks:
        dw 0xffff,0xc000,0xf000,0xfc00,0xff00,0xffc0,0xfff0,0xfffc
bulk_road_pixel_masks:
        dw 0xc000,0x3000,0x0c00,0x0300,0x00c0,0x0030,0x000c,0x0003
        end
