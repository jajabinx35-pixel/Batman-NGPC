$MAXIMUM
        module native_frame_stamp
        public _native_stamp_frame
        extern _native_vehicle_shifted
FRAME_STAMP section code large
; tiles, count, x|(y<<16), top|(bottom<<16), road RAM base.
_native_stamp_frame:
        push xix
        push xiy
        push xiz
        sub xsp,16
        ld xix,(xsp+32)
        ld wa,(xsp+36)
        ld (xsp),wa
        ld wa,(xsp+40)
        ld (xsp+2),wa
        ld wa,(xsp+42)
        ld (xsp+4),wa
        ld wa,(xsp+44)
        ld (xsp+6),wa
        ld wa,(xsp+46)
        ld (xsp+8),wa
        ld xiy,(xsp+48)
frame_tile:
        ld wa,(xsp)
        cp wa,0
        jp z,frame_done
        dec 1,wa
        ld (xsp),wa
        ld a,(xix)
        exts wa
        add wa,(xsp+2)
        cp wa,-8
        jp le,frame_next
        cp wa,160
        jp ge,frame_next
        ld (xsp+10),wa
        ld a,(xix+1)
        exts wa
        add wa,(xsp+4)
        ld de,wa
        ld hl,wa
        cp hl,(xsp+6)
        jr ge,frame_top_ok
        ld hl,(xsp+6)
frame_top_ok:
        cp hl,0
        jr ge,frame_zero_ok
        ld hl,0
frame_zero_ok:
        ld bc,de
        add bc,8
        cp bc,(xsp+8)
        jr le,frame_bottom_ok
        ld bc,(xsp+8)
frame_bottom_ok:
        cp bc,76
        jr le,frame_limit_ok
        ld bc,76
frame_limit_ok:
        cp hl,bc
        jp ge,frame_next
        sub bc,hl
        ld (xsp+14),c
        ld a,l
        and a,7
        ld (xsp+13),a
        ld wa,hl
        sub wa,de
        sll 3,wa
        ld xiz,0
        ld iz,(xix+36)
        sll 8,xiz
        sll 1,xiz
        add xiz,_native_vehicle_shifted
        ld xbc,0
        ld bc,(xsp+10)
        and bc,7
        sll 6,bc
        add xiz,xbc
        ld xbc,0
        ld bc,wa
        add xiz,xbc
        ld xde,0
        ld de,hl
        srl 3,de
        ld xbc,xde
        sll 8,xde
        sll 6,xbc
        add xde,xbc
        ld xwa,0
        ld wa,hl
        and wa,7
        sll 1,wa
        add xde,xwa
        ld xwa,0
        ld wa,(xsp+10)
        sra 3,wa
        exts xwa
        sll 4,xwa
        add xde,xwa
        add xde,xiy
        ld wa,(xsp+10)
        ld b,0
        cp wa,0
        jr lt,frame_flag_left_done
        set 0,b
frame_flag_left_done:
        ld c,a
        and c,7
        cp c,0
        jr z,frame_flag_right_done
        cp wa,152
        jr ge,frame_flag_right_done
        set 1,b
frame_flag_right_done:
        ld (xsp+12),b
        ld c,(xsp+14)
        ld b,(xsp+13)
frame_row:
        bit 0,(xsp+12)
        jr z,frame_row_right
        ld wa,(xiz)
        and wa,(xde)
        or wa,(xiz+2)
        ld (xde),wa
frame_row_right:
        bit 1,(xsp+12)
        jr z,frame_row_next
        ld wa,(xiz+4)
        and wa,(xde+16)
        or wa,(xiz+6)
        ld (xde+16),wa
frame_row_next:
        inc 8,xiz
        inc 2,xde
        inc 1,b
        and b,7
        jr nz,frame_same_band
        lda xde,xde+304
frame_same_band:
        djnz c,frame_row
frame_next:
        lda xix,xix+38
        jp frame_tile
frame_done:
        add xsp,16
        pop xiz
        pop xiy
        pop xix
        ret
        end
