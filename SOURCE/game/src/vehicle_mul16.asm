$MAXIMUM
        module vehicle_mul16
        public _vehicle_div16_packed
        public _vehicle_mulu16
        public _vehicle_mul16
MUL16 section code large
;32-bit arguments, signed low16-bit product returned in XHL (Toshiba ABI).
_vehicle_div16_packed:
        ld xhl,(xsp+4)
        ld bc,(xsp+8)
        div xhl,bc
        ret
_vehicle_mulu16:
        ld wa,(xsp+4)
        ld bc,(xsp+8)
        mul xwa,bc
        ld xhl,xwa
        ret
_vehicle_mul16:
        ld wa,(xsp+4)
        ld bc,(xsp+8)
        muls xwa,bc
        ld xhl,xwa
        ret
        end
