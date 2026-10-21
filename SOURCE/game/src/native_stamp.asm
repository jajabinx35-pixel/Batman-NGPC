$MAXIMUM
        module native_stamp
        public _native_stamp_rows
STAMP section code large
;Five32-bit args. Mask/colour variants already match native tile placement.
_native_stamp_rows:
        push xix
        ld xde,(xsp+8)
        ld xhl,(xsp+12)
        ld c,(xsp+16)
        ld b,(xsp+20)
        ld ix,(xsp+24)
        cp c,0
        jr z,stamp_done
stamp_loop:
        bit 0,ix
        jr z,stamp_right
        ld wa,(xhl)
        and wa,(xde)
        or wa,(xhl+2)
        ld (xde),wa
stamp_right:
        bit 1,ix
        jr z,stamp_next
        ld wa,(xhl+4)
        and wa,(xde+16)
        or wa,(xhl+6)
        ld (xde+16),wa
stamp_next:
        inc 8,xhl
        inc 2,xde
        inc 1,b
        and b,7
        jr nz,stamp_same_band
        lda xde,xde+304
stamp_same_band:
        djnz c,stamp_loop
stamp_done:
        pop xix
        ret
        end
