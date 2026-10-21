$MAXIMUM
        module vehicle_edge_pixels_all
        public _vehicle_edge_pixels_all
        extern _stage_work
        extern _vehicle_edge_pixels_regs
EDGE_ALL section code large
; QWA=w1 QBC=w2 QDE=low word of r4. Their low register halves
; are scratch for the private pixel ABI. A hidden segment leaves w1
; in 0..255; 0xffff therefore exactly denotes the source reset state.
_vehicle_edge_pixels_all:
        push xix
        push xiy
        push xiz
        ld xiz,(xsp+16)
        ld xix,0
        ld ix,(xiz+20)
        ld xiy,_stage_work+896
        ld qwa,0xffff
        ld de,(xiz+12)
        ld qde,de
edge_all_loop:
        bit 15,qwa
        jr z,edge_all_keep_w1
        ld qwa,0
edge_all_keep_w1:
        ld bc,qwa
        sub c,2
        ld xhl,xiy
        chg 0,l
        add c,(xhl)
        lda xhl,xiy+1
        chg 0,l
        sub c,(xhl)
        ld qbc,bc
        bit 7,c
        jp z,edge_all_visible
        lda xhl,xiy+91
        chg 0,l
        ld (xhl),1
        inc 1,c
        jr z,edge_all_hidden_zero
        inc 1,c
edge_all_hidden_zero:
        ld qwa,bc
        lda xhl,xiy+46
        chg 0,l
        ld b,(xhl)
        lda xhl,xhl-22
        ld c,(xhl)
        ld qbc,bc
        ld wa,(xiz+18)
        add wa,bc
        scc c,l
        ld (xiz+22),l
        ld (xiz+18),wa
        ld (xix),wa
        inc 2,xix
        jp edge_all_next
edge_all_visible:
        add c,2
        lda xhl,xiy+91
        chg 0,l
        ld (xhl),c
        sub c,qa
        ld qbc,bc
        ld a,c
        dec 1,a
        ld qa,a
        lda xhl,xiy+46
        chg 0,l
        ld a,(xhl)
        bit 7,a
        jr z,edge_all_positive
        lda xhl,xhl-22
        ld a,(xhl)
        neg a
        ld (xiz+16),a
        cp c,a
        scc c,e
        jr edge_all_kind
edge_all_positive:
        lda xhl,xhl-22
        ld a,(xhl)
        ld (xiz+16),a
        cp c,a
        ld e,2
        adc e,0
edge_all_kind:
        ld b,e
        bit 0,b
        jr z,edge_all_shallow_error
        ld qde,0
        ldw (xiz+14),0
        jr edge_all_args
edge_all_shallow_error:
        ld a,qc
        srl 1,a
        ld qe,a
edge_all_args:
        push xiy
        ld iy,(xiz+18)
        ld hl,qwa
        inc 1,hl
        ld a,qe
        ld w,qc
        ld c,(xiz+16)
        call _vehicle_edge_pixels_regs
        ld (xiz+18),iy
        ld qe,a
        ld (xiz+22),e
        pop xiy
        ld qwa,0xffff
edge_all_next:
        inc 1,xiy
        cp xiy,_stage_work+917
        jp c,edge_all_loop
        ld wa,qwa
        ld (xiz+4),wa
        ld bc,qbc
        ld (xiz+6),bc
        ld de,qde
        ld (xiz+12),de
        ld (xiz+20),ix
        pop xiz
        pop xiy
        pop xix
        ret
        end
