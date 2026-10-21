$MAXIMUM
        module fast_memory
        public .vr8
        public .vr16
        public .vr32
        public .vw8
        public .vw16
        public .vw32
        public .cvr8
        public .cvr16
        public .cvr32
        public .cvw8
        public .cvw16
        public .cvw32
        public .ver8
        public .ver16
        public .ver32
        public .vew8
        public .vew16
        public .vew32
        extern _stage_work
        extern _stack
        extern .vr8_slow
        extern .vr16_slow
        extern .vr32_slow
        extern .vw8_slow
        extern .vw16_slow
        extern .vw32_slow
        extern .cvr8_slow
        extern .cvr16_slow
        extern .cvr32_slow
        extern .cvw8_slow
        extern .cvw16_slow
        extern .cvw32_slow
        extern .ver8_slow
        extern .ver16_slow
        extern .ver32_slow
        extern .vew8_slow
        extern .vew16_slow
        extern .vew32_slow
        extern _vehicle_shared
        extern _vehicle_data24
        extern _vehicle_code
        extern _vehicle_stage
; XWA=address, XBC=value; XHL=result (Toshiba __adecl).
FAST_AXIS section code large
.vr8:
        call v_mutable
        jp c,.vr8_slow
        ld l,(xde)
        ret
.vr16:
        call v_mutable
        jp c,.vr16_slow
        ld hl,(xde)
        ex l,h
        ret
.vr32:
        call v_mutable
        jp c,.vr32_slow
        ld xhl,0
        ld hl,(xde)
        ex l,h
        sll 8,xhl
        sll 8,xhl
        ld hl,(xde+2)
        ex l,h
        ret
.vw8:
        call v_mutable
        jp c,.vw8_slow
        ld a,c
        ld (xde),a
        ret
.vw16:
        call v_mutable
        jp c,.vw16_slow
        ld wa,bc
        ex a,w
        ld (xde),wa
        ret
.vw32:
        call v_mutable
        jp c,.vw32_slow
        ld xwa,xbc
        srl 8,xwa
        srl 8,xwa
        ex a,w
        ld (xde),wa
        ld wa,bc
        ex a,w
        ld (xde+2),wa
        ret
v_mutable:
        cp xwa,0x10000
        jp nc,v_stack
        ld hl,wa
        sub hl,0x62de
        cp hl,1260
        jr c,v_region0
        ld hl,wa
        sub hl,0x39c8
        cp hl,220
        jr c,v_region1
        ld hl,wa
        sub hl,0x4894
        cp hl,160
        jr c,v_region2
        ld hl,wa
        sub hl,0x36e0
        cp hl,48
        jr c,v_region3
        scf
        ret
v_region0:
        ld xde,_stage_work+0
        add de,hl
        rcf
        ret
v_region1:
        ld xde,_stage_work+1748
        add de,hl
        rcf
        ret
v_region2:
        ld xde,_stage_work+1968
        add de,hl
        rcf
        ret
v_region3:
        ld xde,_stage_work+2128
        add de,hl
        rcf
        ret
v_stack:
        cp xwa,0x1ffe00
        jr c,v_miss
        cp xwa,0x200000
        jr nc,v_miss
        ld hl,wa
        sub hl,0xfe00
        ld xde,_stack
        add de,hl
        rcf
        ret
v_miss:
        scf
        ret
FAST_CAT section code large
.cvr8:
        call cv_mutable
        jp c,.cvr8_slow
        ld l,(xde)
        ret
.cvr16:
        call cv_mutable
        jp c,.cvr16_slow
        ld hl,(xde)
        ex l,h
        ret
.cvr32:
        call cv_mutable
        jp c,.cvr32_slow
        ld xhl,0
        ld hl,(xde)
        ex l,h
        sll 8,xhl
        sll 8,xhl
        ld hl,(xde+2)
        ex l,h
        ret
.cvw8:
        call cv_mutable
        jp c,.cvw8_slow
        ld a,c
        ld (xde),a
        ret
.cvw16:
        call cv_mutable
        jp c,.cvw16_slow
        ld wa,bc
        ex a,w
        ld (xde),wa
        ret
.cvw32:
        call cv_mutable
        jp c,.cvw32_slow
        ld xwa,xbc
        srl 8,xwa
        srl 8,xwa
        ex a,w
        ld (xde),wa
        ld wa,bc
        ex a,w
        ld (xde+2),wa
        ret
cv_mutable:
        cp xwa,0x10000
        jp nc,cv_stack
        ld hl,wa
        sub hl,0x6326
        cp hl,1748
        jr c,cv_region0
        ld hl,wa
        sub hl,0x39bc
        cp hl,220
        jr c,cv_region1
        ld hl,wa
        sub hl,0x48d2
        cp hl,160
        jr c,cv_region2
        ld hl,wa
        sub hl,0x36e0
        cp hl,48
        jr c,cv_region3
        ld hl,wa
        sub hl,0x5fac
        cp hl,104
        jr c,cv_region4
        scf
        ret
cv_region0:
        ld xde,_stage_work+0
        add de,hl
        rcf
        ret
cv_region1:
        ld xde,_stage_work+1748
        add de,hl
        rcf
        ret
cv_region2:
        ld xde,_stage_work+1968
        add de,hl
        rcf
        ret
cv_region3:
        ld xde,_stage_work+2128
        add de,hl
        rcf
        ret
cv_region4:
        ld xde,_stage_work+2176
        add de,hl
        rcf
        ret
cv_stack:
        cp xwa,0x1ffe00
        jr c,cv_miss
        cp xwa,0x200000
        jr nc,cv_miss
        ld hl,wa
        sub hl,0xfe00
        ld xde,_stack
        add de,hl
        rcf
        ret
cv_miss:
        scf
        ret
FAST_VEH section code large
.ver8:
        call ve_read_rom
        jp c,.ver8_slow
        chg 0,de
        ld l,(xde)
        ret
.ver16:
        bit 0,a
        jp nz,.ver16_slow
        call ve_read_rom
        jp c,.ver16_slow
        ld hl,(xde)
        ret
.ver32:
        call ve_read_rom
        jp c,.ver32_slow
        ld xhl,0
        ld hl,(xde)
        sll 8,xhl
        sll 8,xhl
        ld hl,(xde+2)
        ret
.vew8:
        call ve_mutable
        jp c,.vew8_slow
        chg 0,de
        ld a,c
        ld (xde),a
        ret
.vew16:
        bit 0,a
        jp nz,.vew16_slow
        call ve_mutable
        jp c,.vew16_slow
        ld wa,bc
        ld (xde),wa
        ret
.vew32:
        call ve_mutable
        jp c,.vew32_slow
        ld xwa,xbc
        srl 8,xwa
        srl 8,xwa
        ld (xde),wa
        ld wa,bc
        ld (xde+2),wa
        ret
ve_mutable:
        cp xwa,0x10000
        jp nc,ve_stack
        ld hl,wa
        sub hl,0x8d1e
        cp hl,1008
        jr c,ve_region0
        ld hl,wa
        sub hl,0x7bc8
        cp hl,1424
        jr c,ve_region1
        ld hl,wa
        sub hl,0x3700
        cp hl,200
        jr c,ve_region2
        ld hl,wa
        sub hl,0x4238
        cp hl,6
        jr c,ve_region3
        ld hl,wa
        sub hl,0x4e60
        cp hl,64
        jr c,ve_region4
        ld hl,wa
        sub hl,0x3f3a
        cp hl,54
        jr c,ve_region5
        scf
        ret
ve_region0:
        ld xde,_stage_work+0
        add de,hl
        rcf
        ret
ve_region1:
        ld xde,_stage_work+1008
        add de,hl
        rcf
        ret
ve_region2:
        ld xde,_stage_work+2432
        add de,hl
        rcf
        ret
ve_region3:
        ld xde,_stage_work+2632
        add de,hl
        rcf
        ret
ve_region4:
        ld xde,_stage_work+2638
        add de,hl
        rcf
        ret
ve_region5:
        ld xde,_stage_work+2702
        add de,hl
        rcf
        ret
ve_stack:
        cp xwa,0x1ffe00
        jr c,ve_miss
        cp xwa,0x200000
        jr nc,ve_miss
        ld hl,wa
        sub hl,0xfe00
        ld xde,_stack
        add de,hl
        rcf
        ret
ve_miss:
        scf
        ret
ve_read_rom:
        cp xwa,0x1fffc
        jp nc,ve_read_high
        call ve_mutable
        ret nc
        ; Original ROM has mutable animation counters overlaid in this range.
        cp xwa,0x6688
        jr c,ve_read_code
        cp xwa,0x6768
        jr c,ve_read_miss
ve_read_code:
        cp xwa,0x2ffc
        jr c,ve_read_miss
        cp xwa,0xcdf4
        jr nc,ve_read_miss
        ld xde,(_vehicle_code)
        sub xwa,0x2ffc
        add xde,xwa
        rcf
        ret
ve_read_high:
        cp xwa,0x2a416
        jr nc,ve_read_data24
        ld xde,(_vehicle_shared)
        sub xwa,0x1fffc
        add xde,xwa
        rcf
        ret
ve_read_data24:
        cp xwa,0x5681a
        jp nc,ve_mutable
        ld l,(_vehicle_stage)
        cp l,2
        jr nz,ve_read_data24_ok
        cp xwa,0x50044
        jr nc,ve_read_miss
ve_read_data24_ok:
        ld xde,(_vehicle_data24)
        sub xwa,0x2a416
        add xde,xwa
        rcf
        ret
ve_read_miss:
        scf
        ret
        end
