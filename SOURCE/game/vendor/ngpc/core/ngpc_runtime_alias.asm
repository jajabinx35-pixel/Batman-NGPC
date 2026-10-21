; Bridge compiler helper register arguments (XWA, XBC) to C stack arguments.
; Result remains in XHL.
$MAXIMUM

        module  ngpc_runtime_alias

        public  C9H_mullu, C9H_divlu, C9H_remlu
        extern  large _C9H_mullu, _C9H_divlu, _C9H_remlu

ALIAS   section code large

C9H_mullu:
        push    xbc
        push    xwa
        call    _C9H_mullu
        inc     8, xsp
        ret

C9H_divlu:
        push    xbc
        push    xwa
        call    _C9H_divlu
        inc     8, xsp
        ret

C9H_remlu:
        push    xbc
        push    xwa
        call    _C9H_remlu
        inc     8, xsp
        ret

        end
