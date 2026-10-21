$MAXIMUM
        module ngpc_flash_asm
        public _ngpc_full_speed
        public _ngpc_flash_erase_asm
        public _ngpc_flash_write_asm
FLASH section code large
; Standard SWI 1 interface: BIOS and HLE emulators both register persistent writes.
; Block 31 is the reserved 32 KiB region at cartridge offset 0x1F0000.
_ngpc_flash_erase_asm:
        push sr
        di
        ld (0x6F),0x4E
        ld a,(0x6E)
        push wa
        ld (0x6E),0x14
        ld (0x6F),0xB1
        ld (0x6F),0x4E
        ld ra3,0
        ld rb3,31
        ld rw3,8
        swi 1
        ld (0x6F),0x4E
        pop wa
        ld (0x6E),a
        ld (0x6F),0x4E
        pop sr
        ret
; cc900 pushes each argument into a four-byte stack slot.
_ngpc_flash_write_asm:
        ld xhl,(xsp+4)
        ld xhl3,xhl
        ld xde,(xsp+8)
        ld xde3,xde
        push sr
        di
        ld (0x6F),0x4E
        ld a,(0x6E)
        push wa
        ld (0x6E),0x14
        ld (0x6F),0xB1
        ld ra3,0
        ld rbc3,2
        ld rw3,6
        ld (0x6F),0x4E
        swi 1
        ld (0x6F),0x4E
        pop wa
        ld (0x6E),a
        ld (0x6F),0x4E
        pop sr
        ret
; Constant BIOS argument avoids compiler stack/prologue ambiguity.
_ngpc_full_speed:
        ld rb3,0
        ld rw3,1
        swi 1
        ret
        end
