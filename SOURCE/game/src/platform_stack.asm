$MAXIMUM
        module platform_stack
        public _platform_draw_push
        public _platform_draw_pop
        extern _stack
        extern _d
        extern _a
platform_scan section code large
; Original MOVEM.W frame, same big-endian stack and signed restores.
; Only caller-saved TLCS registers are used; emulated flags are untouched.
_platform_draw_push:
        ld xwa,(_a+28)
        cp xwa,0x1ffe08
        jp c,draw_stack_failure
        cp xwa,0x200001
        jp nc,draw_stack_failure
        sub xwa,8
        ld (_a+28),xwa
        ld xhl,xwa
        sub xhl,0x1ffe00
        ld xde,_stack
        add xde,xhl
        ld wa,(_d)
        ex a,w
        ld (xde),wa
        ld wa,(_d+4)
        ex a,w
        ld (xde+2),wa
        ld wa,(_a+20)
        ex a,w
        ld (xde+4),wa
        ld wa,(_a+24)
        ex a,w
        ld (xde+6),wa
        ld l,1
        ret
_platform_draw_pop:
        ld xwa,(_a+28)
        cp xwa,0x1ffe00
        jp c,draw_stack_failure
        cp xwa,0x1ffff9
        jp nc,draw_stack_failure
        ld xhl,xwa
        sub xhl,0x1ffe00
        ld xde,_stack
        add xde,xhl
        add xwa,8
        ld (_a+28),xwa
        ld wa,(xde)
        ex a,w
        exts xwa
        ld (_d),xwa
        ld wa,(xde+2)
        ex a,w
        exts xwa
        ld (_d+4),xwa
        ld wa,(xde+4)
        ex a,w
        exts xwa
        ld (_a+20),xwa
        ld wa,(xde+6)
        ex a,w
        exts xwa
        ld (_a+24),xwa
        ld l,1
        ret
draw_stack_failure:
        ld l,0
        ret
        end
