$MAXIMUM
        module graphics_diff
        public _graphics_diff_words
GRAPHICS_DIFF section code large
_graphics_diff_words:
        ld xde,(xsp+4)
        ld xhl,(xsp+8)
        ld bc,(xsp+12)
        push bc
        srl 3,bc
        cp bc,0
        jp z,diff_tail
diff_tile:
        ld xwa,(xhl)
        cp xwa,(xde)
        jr z,diff_equal_0
        ld (xde),xwa
diff_equal_0:
        ld xwa,(xhl+4)
        cp xwa,(xde+4)
        jr z,diff_equal_4
        ld (xde+4),xwa
diff_equal_4:
        ld xwa,(xhl+8)
        cp xwa,(xde+8)
        jr z,diff_equal_8
        ld (xde+8),xwa
diff_equal_8:
        ld xwa,(xhl+12)
        cp xwa,(xde+12)
        jr z,diff_equal_12
        ld (xde+12),xwa
diff_equal_12:
        lda xhl,xhl+16
        lda xde,xde+16
        djnz bc,diff_tile
diff_tail:
        pop bc
        and bc,7
        ld a,c
        and a,1
        push wa
        srl 1,bc
        cp bc,0
        jr z,diff_odd
diff_pair:
        ld xwa,(xhl)
        cp xwa,(xde)
        jr z,diff_equal
        ld (xde),xwa
diff_equal:
        inc 4,xhl
        inc 4,xde
        djnz bc,diff_pair
diff_odd:
        pop wa
        and a,1
        ret z
        ld wa,(xhl)
        cp wa,(xde)
        ret z
        ld (xde),wa
        ret
        end
