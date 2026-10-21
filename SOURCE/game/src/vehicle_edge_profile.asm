$MAXIMUM
        module vehicle_edge_profile
        public _vehicle_edge_profile
        extern _vehicle_code
        extern _stage_work
EDGE_PROFILE section code large
; Cached native registers: DE=w1 QBC=v QDE=position. The 22 source
; samples and signed products are unchanged. Publish final context once.
_vehicle_edge_profile:
        push xix
        push xiy
        push xiz
        ld xhl,(xsp+16)
        ld bc,(xhl+2)
        ld qbc,bc
        ld de,(xhl)
        ld qde,de
        ld de,(xhl+4)
        ld xix,(_vehicle_code)
        ld xiz,0
        ld iz,(xsp+20)
        add iz,0x4924
        add xiz,xix
        ld xiy,_stage_work+920
edge_profile_loop:
        ld xhl,0
        ld hl,qde
        add hl,598
        chg 0,l
        add xhl,_stage_work
        ld a,(xhl)
        add a,qc
        ld qc,a
        inc 1,qe
        ld xhl,0
        ld hl,qbc
        add hl,0x4724
        add xhl,xix
        ld wa,(xhl)
        sub wa,de
        add wa,30
        exts xwa
        ld bc,0
        chg 0,iz
        ld c,(xiz)
        chg 0,iz
        inc 1,xiz
        srl 1,c
        muls xwa,bc
        sra 8,xwa
        sra 1,xwa
        chg 0,iy
        ld (xiy),a
        add de,wa
        ld bc,wa
        sra 8,bc
        ld (xiy+22),c
        chg 0,iy
        inc 1,xiy
        cp xiy,_stage_work+942
        jp c,edge_profile_loop
        ld xix,(xsp+16)
        ld (xix+8),xwa
        ld (xix+6),bc
        ld (xix+8),bc
        ld (xix+4),de
        ld bc,qbc
        ld (xix+2),bc
        ld bc,qde
        ld (xix),bc
; Recover the final pre-accumulation w1 from the last product. XHL
; still addresses that sample's immutable curve word.
        ld bc,de
        sub bc,wa
        ld wa,(xhl)
        sub wa,bc
        add wa,30
        exts xwa
        ld (xix+12),xwa
        lda xiz,xiz-1
        chg 0,iz
        ld a,(xiz)
        sll 7,a
        ld (xix+16),a
        pop xiz
        pop xiy
        pop xix
        ret
        end
