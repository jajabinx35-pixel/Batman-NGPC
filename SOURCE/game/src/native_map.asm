$MAXIMUM
        module native_map
        public _native_map_upload
        public _native_map_upload_fast
NATIVE_MAP section code large
_native_map_upload:
        push xix
        ld xhl,(xsp+8)
        ld xde,(xsp+12)
        ld ix,10
map_row:
        ld bc,10
map_pair:
        ld xwa,(xhl)
        cp xwa,(xde)
        jr z,map_equal
        ld (xde),xwa
map_equal:
        inc 4,xhl
        inc 4,xde
        djnz bc,map_pair
        lda xde,xde+24
        djnz ix,map_row
        pop xix
        ret
; Pure full map commit: faster than scanning VRAM when palette flags move.
_native_map_upload_fast:
        push xix
        ld xhl,(xsp+8)
        ld xde,(xsp+12)
        ld ix,10
fast_map_row:
        ld bc,10
fast_map_pair:
        ld xwa,(xhl)
        ld (xde),xwa
        inc 4,xhl
        inc 4,xde
        djnz bc,fast_map_pair
        lda xde,xde+24
        djnz ix,fast_map_row
        pop xix
        ret
        end
