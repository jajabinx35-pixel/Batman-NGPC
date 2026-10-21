$MAXIMUM
        module ngpc_flash_asm
                public _session_flash_erase
        public _session_flash_page
FLASH section code large
; Standard SWI 1 interface: BIOS and HLE emulators both register persistent writes.
; Only blocks 32/33 (8 KiB each) hold saves. BIOS block 34 is never used.
_session_flash_erase:
        ld a,(xsp+4)
        ld rb3,a
        push xix
        push xiy
        push xiz
        push sr
        di
        ld (0x6F),0x4E
        ld a,(0x6E)
        push wa
        ld (0x6E),0x14
        ld (0x6F),0xB1
        ld (0x6F),0x4E
        ld ra3,0
        ld rw3,8
        swi 1
        ld (0x6F),0x4E
        pop wa
        ld (0x6E),a
        ld (0x6F),0x4E
        pop sr
        pop xiz
        pop xiy
        pop xix
        ret
; cc900 pushes each argument into a four-byte stack slot.
_session_flash_page:
        ld xhl,(xsp+4)
        ld xhl3,xhl
        ld xde,(xsp+8)
        ld xde3,xde
        push xix
        push xiy
        push xiz
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
        pop xiz
        pop xiy
        pop xix
        ret
        end
