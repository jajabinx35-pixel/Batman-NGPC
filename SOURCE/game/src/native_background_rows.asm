$MAXIMUM
        module native_background_rows
        public _native_background_rows
BACKGROUND_ROWS section code large
_native_background_rows:
        ld a,(xsp+16)
        cp a,1
        jp c,background_general
        cp a,9
        jp nc,background_general
        push xix
        push xiy
        push xiz
        ld xix,(xsp+16)
        ld xiz,(xsp+20)
        ld hl,(xsp+24)
        cp hl,0
        jp z,background_fast_done
        ld xwa,(xsp+28)
        ld c,a
        ld de,wa
        sll 2,de
        srl 8,xwa
        srl 8,xwa
        add wa,de
        ld xiy,0
        ld iy,wa
        ld b,(xsp+32)
        cp c,1
        jp z,background_fast_1
        cp c,2
        jp z,background_fast_2
        cp c,3
        jp z,background_fast_3
        cp c,4
        jp z,background_fast_4
        cp c,5
        jp z,background_fast_5
        cp c,6
        jp z,background_fast_6
        cp c,7
        jp z,background_fast_7
        jp background_fast_8
background_fast_1:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_1
        inc 2,xix
        jr background_next_1
background_band_1:
        lda xix,xix+306
background_next_1:
        djnz hl,background_fast_1
        jp background_fast_done
background_fast_2:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        ld wa,(xiz+4)
        and wa,(xix+16)
        or wa,(xiz+6)
        ld (xix+16),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_2
        inc 2,xix
        jr background_next_2
background_band_2:
        lda xix,xix+306
background_next_2:
        djnz hl,background_fast_2
        jp background_fast_done
background_fast_3:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        ld wa,(xiz+4)
        and wa,(xix+16)
        or wa,(xiz+6)
        ld (xix+16),wa
        ld wa,(xiz+8)
        and wa,(xix+32)
        or wa,(xiz+10)
        ld (xix+32),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_3
        inc 2,xix
        jr background_next_3
background_band_3:
        lda xix,xix+306
background_next_3:
        djnz hl,background_fast_3
        jp background_fast_done
background_fast_4:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        ld wa,(xiz+4)
        and wa,(xix+16)
        or wa,(xiz+6)
        ld (xix+16),wa
        ld wa,(xiz+8)
        and wa,(xix+32)
        or wa,(xiz+10)
        ld (xix+32),wa
        ld wa,(xiz+12)
        and wa,(xix+48)
        or wa,(xiz+14)
        ld (xix+48),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_4
        inc 2,xix
        jr background_next_4
background_band_4:
        lda xix,xix+306
background_next_4:
        djnz hl,background_fast_4
        jp background_fast_done
background_fast_5:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        ld wa,(xiz+4)
        and wa,(xix+16)
        or wa,(xiz+6)
        ld (xix+16),wa
        ld wa,(xiz+8)
        and wa,(xix+32)
        or wa,(xiz+10)
        ld (xix+32),wa
        ld wa,(xiz+12)
        and wa,(xix+48)
        or wa,(xiz+14)
        ld (xix+48),wa
        ld wa,(xiz+16)
        and wa,(xix+64)
        or wa,(xiz+18)
        ld (xix+64),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_5
        inc 2,xix
        jr background_next_5
background_band_5:
        lda xix,xix+306
background_next_5:
        dec 1,hl
        cp hl,0
        jp nz,background_fast_5
        jp background_fast_done
background_fast_6:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        ld wa,(xiz+4)
        and wa,(xix+16)
        or wa,(xiz+6)
        ld (xix+16),wa
        ld wa,(xiz+8)
        and wa,(xix+32)
        or wa,(xiz+10)
        ld (xix+32),wa
        ld wa,(xiz+12)
        and wa,(xix+48)
        or wa,(xiz+14)
        ld (xix+48),wa
        ld wa,(xiz+16)
        and wa,(xix+64)
        or wa,(xiz+18)
        ld (xix+64),wa
        ld wa,(xiz+20)
        and wa,(xix+80)
        or wa,(xiz+22)
        ld (xix+80),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_6
        inc 2,xix
        jr background_next_6
background_band_6:
        lda xix,xix+306
background_next_6:
        dec 1,hl
        cp hl,0
        jp nz,background_fast_6
        jp background_fast_done
background_fast_7:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        ld wa,(xiz+4)
        and wa,(xix+16)
        or wa,(xiz+6)
        ld (xix+16),wa
        ld wa,(xiz+8)
        and wa,(xix+32)
        or wa,(xiz+10)
        ld (xix+32),wa
        ld wa,(xiz+12)
        and wa,(xix+48)
        or wa,(xiz+14)
        ld (xix+48),wa
        ld wa,(xiz+16)
        and wa,(xix+64)
        or wa,(xiz+18)
        ld (xix+64),wa
        ld wa,(xiz+20)
        and wa,(xix+80)
        or wa,(xiz+22)
        ld (xix+80),wa
        ld wa,(xiz+24)
        and wa,(xix+96)
        or wa,(xiz+26)
        ld (xix+96),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_7
        inc 2,xix
        jr background_next_7
background_band_7:
        lda xix,xix+306
background_next_7:
        dec 1,hl
        cp hl,0
        jp nz,background_fast_7
        jp background_fast_done
background_fast_8:
        ld wa,(xiz)
        and wa,(xix)
        or wa,(xiz+2)
        ld (xix),wa
        ld wa,(xiz+4)
        and wa,(xix+16)
        or wa,(xiz+6)
        ld (xix+16),wa
        ld wa,(xiz+8)
        and wa,(xix+32)
        or wa,(xiz+10)
        ld (xix+32),wa
        ld wa,(xiz+12)
        and wa,(xix+48)
        or wa,(xiz+14)
        ld (xix+48),wa
        ld wa,(xiz+16)
        and wa,(xix+64)
        or wa,(xiz+18)
        ld (xix+64),wa
        ld wa,(xiz+20)
        and wa,(xix+80)
        or wa,(xiz+22)
        ld (xix+80),wa
        ld wa,(xiz+24)
        and wa,(xix+96)
        or wa,(xiz+26)
        ld (xix+96),wa
        ld wa,(xiz+28)
        and wa,(xix+112)
        or wa,(xiz+30)
        ld (xix+112),wa
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_band_8
        inc 2,xix
        jr background_next_8
background_band_8:
        lda xix,xix+306
background_next_8:
        dec 1,hl
        cp hl,0
        jp nz,background_fast_8
        jp background_fast_done
background_fast_done:
        pop xiz
        pop xiy
        pop xix
        ret
background_general:
        push xix
        push xiy
        push xiz
        ld xix,(xsp+16)
        ld xiz,(xsp+20)
        ld hl,(xsp+24)
        cp hl,0
        jr z,background_rows_done
        ld xwa,(xsp+28)
        ld c,a
        srl 8,xwa
        srl 8,xwa
        ld xiy,xwa
        ld b,(xsp+32)
        push bc
background_row:
        ld xde,xix
        ld c,(xsp)
background_word:
        ld wa,(xiz)
        and wa,(xde)
        or wa,(xiz+2)
        ld (xde),wa
        inc 4,xiz
        lda xde,xde+16
        djnz c,background_word
        add xiz,xiy
        inc 1,b
        and b,7
        jr z,background_new_band
        inc 2,xix
        jr background_next_row
background_new_band:
        lda xix,xix+306
background_next_row:
        djnz hl,background_row
        pop bc
background_rows_done:
        pop xiz
        pop xiy
        pop xix
        ret
        end
