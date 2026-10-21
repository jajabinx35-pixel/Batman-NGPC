$MAXIMUM
        module vehicle_road_native
        public _vehicle_paint_row
ROAD_NATIVE section code large
; dst row, source five-edge sample, enabled marker bits: three u32 args.
; Only the native road plane is written. Projection/collision data is shared.
_vehicle_paint_row:
        push xix
        push xiy
        push xiz
        ld xix,(xsp+16)
        ld xiy,(xsp+20)
        ld iz,(xsp+24)
        ld wa,(xiy)
        sra 1,wa
        ld bc,(xiy+1024)
        sra 1,bc
        cp wa,bc
        jp ge,road_marks
        cp wa,160
        jp ge,road_marks
        cp bc,0
        jp le,road_marks
        cp wa,0
        jr ge,road_left_ok
        ld wa,0
road_left_ok:
        cp bc,160
        jr le,road_right_ok
        ld bc,160
road_right_ok:
        ld xhl,0
        ld hl,wa
        and hl,0xfff8
        sll 1,hl
        ld xde,0
        ld de,wa
        and de,7
        sll 1,de
        add xde,road_left_masks
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
        ld xiy,0
        ld iy,hl
        add xiy,road_right_masks
        ld bc,(xiy)
        pop hl
        pop de
        cp hl,de
        jr z,road_one_tile
        add xhl,xix
        add xde,xix
        and wa,0xaaaa
        ld (xhl),wa
        lda xhl,xhl+16
        ld wa,0xaaaa
road_fill:
        cp xhl,xde
        jr nc,road_last
        ld (xhl),wa
        lda xhl,xhl+16
        jr road_fill
road_last:
        and bc,0xaaaa
        ld (xde),bc
        jr road_marks
road_one_tile:
        add xhl,xix
        and wa,bc
        and wa,0xaaaa
        ld (xhl),wa
road_marks:
        ld xiy,(xsp+20)
        ld xiz,road_pixel_masks
        bit 0,(xsp+24)
        jr z,road_mark_0
        ld wa,(xiy)
        cp wa,320
        jr nc,road_mark_0
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
road_mark_0:
        bit 1,(xsp+24)
        jr z,road_mark_1
        ld wa,(xiy+256)
        cp wa,320
        jr nc,road_mark_1
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
road_mark_1:
        bit 2,(xsp+24)
        jr z,road_mark_2
        ld wa,(xiy+512)
        cp wa,320
        jr nc,road_mark_2
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
road_mark_2:
        bit 3,(xsp+24)
        jr z,road_mark_3
        ld wa,(xiy+768)
        cp wa,320
        jr nc,road_mark_3
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
road_mark_3:
        bit 4,(xsp+24)
        jr z,road_mark_4
        ld wa,(xiy+1024)
        cp wa,320
        jr nc,road_mark_4
        ld de,wa
        and de,0xfff0
        and wa,14
        ld bc,(xiz+wa)
        or bc,(xix+de)
        ld (xix+de),bc
road_mark_4:
road_done:
        pop xiz
        pop xiy
        pop xix
        ret

road_left_masks:
        dw 0xffff,0x3fff,0x0fff,0x03ff,0x00ff,0x003f,0x000f,0x0003
road_right_masks:
        dw 0xffff,0xc000,0xf000,0xfc00,0xff00,0xffc0,0xfff0,0xfffc
road_pixel_masks:
        dw 0xc000,0x3000,0x0c00,0x0300,0x00c0,0x0030,0x000c,0x0003
        end
