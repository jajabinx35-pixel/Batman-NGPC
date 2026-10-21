$MAXIMUM
        module bitmap_rows
        public _bitmap_fill_bytes
        public _bitmap_clear_words
        public _stack_guard_init
        public _bitmap_copy_bytes
        public _bitmap_mask_bytes
ROWS section code large
_bitmap_fill_bytes:
        ld xhl,(xsp+4)
        ld a,(xsp+8)
        ld bc,(xsp+12)
        cp bc,0
        jr z,fill_done
        ld (xhl),a
        dec 1,bc
        jr z,fill_done
        ld xde,xhl
        inc 1,xde
        ldir
fill_done:
        ret
RAM_CLEAR section code large
_bitmap_clear_words:
        ld xhl,(xsp+4)
        ld bc,(xsp+8)
        push bc
        ld xwa,0
        srl 4,bc
        cp bc,0
        jr z,clear_tail
clear_tiles:
        ld (xhl),xwa
        ld (xhl+4),xwa
        ld (xhl+8),xwa
        ld (xhl+12),xwa
        ld (xhl+16),xwa
        ld (xhl+20),xwa
        ld (xhl+24),xwa
        ld (xhl+28),xwa
        lda xhl,xhl+32
        djnz bc,clear_tiles
clear_tail:
        pop bc
        and bc,15
        cp bc,0
        ret z
clear_words:
        ld (xhl),wa
        inc 2,xhl
        djnz bc,clear_words
        ret
ROWS section code large
_stack_guard_init:
        ld xde,0x7800
        ld bc,0x780
        ld a,0xa5
stack_guard_loop:
        ld (xde),a
        inc 1,xde
        djnz bc,stack_guard_loop
        ret
_bitmap_copy_bytes:
        ld xde,(xsp+4)
        ld xhl,(xsp+8)
        ld bc,(xsp+12)
        cp bc,0
        jr z,copy_done
        ldir
copy_done:
        ret
_bitmap_mask_bytes:
        ld xde,(xsp+4)
        ld xhl,(xsp+8)
        ld bc,(xsp+12)
        cp bc,0
        jr z,mask_done
mask_row_loop:
        ld wa,(xhl)
        cp wa,0x00ff
        jr z,mask_next
        and a,(xde)
        or a,w
        ld (xde),a
mask_next:
        inc 1,xde
        inc 2,xhl
        djnz bc,mask_row_loop
mask_done:
        ret
        end
