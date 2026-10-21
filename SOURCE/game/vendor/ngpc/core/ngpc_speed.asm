$MAXIMUM
        module ngpc_speed
        public _ngpc_full_speed
SPEED section code large
; Same constant-argument BIOS routine used by the supplied Pocket Sprint build.
; Separated from ngpc_flash_asm because this game does not use flash saves.
_ngpc_full_speed:
        ld rb3,0
        ld rc3,0
        ld rw3,1
        swi 1
        ret
        end
