$MAXIMUM
        module sampled_pcm
        public _pcm_unpack
        public _pcm_unpack_mix
        public _pcm_unpack_mix_end
        public _pcm_mix
        public _pcm_silence
        public _pcm_dma_arm
PCM_NATIVE section code large
_pcm_unpack:
        push xix
        push xiy
        push xiz
        ld xix,(xsp+16)
        ld xiy,(xsp+20)
        ld xwa,(xiy)
        ld (0x71f0),xwa
        ld xwa,(xiy+4)
        ld (0x71f4),xwa
        ld xwa,(xiy+8)
        ld (0x71f8),xwa
        ld xwa,(xiy+12)
        ld (0x71fc),xwa
        lda xhl,xiy+16
        ld xiy,0x71f0
        ld iz,64
        ld wa,0
pcm_unpack_loop:
        ld c,(xhl+0)
        ld a,c
        and a,15
        ld e,(xiy+wa)
        ld d,e
        ld (xix+0),de
        srl 4,c
        ld a,c
        ld e,(xiy+wa)
        ld d,e
        ld (xix+2),de
        ld c,(xhl+1)
        ld a,c
        and a,15
        ld e,(xiy+wa)
        ld d,e
        ld (xix+4),de
        srl 4,c
        ld a,c
        ld e,(xiy+wa)
        ld d,e
        ld (xix+6),de
        inc 2,xhl
        inc 8,xix
        djnz iz,pcm_unpack_loop
        pop xiz
        pop xiy
        pop xix
        ret
_pcm_mix:
        ld xhl,(xsp+4)
        ld xde,(xsp+8)
        ld bc,256
pcm_mix_loop:
        ld wa,0
        ld a,(xhl)
        ld w,0
        add a,(xde)
        adc w,0
        sub wa,128
        cp wa,0
        jr ge,pcm_mix_nonnegative
        ld wa,0
pcm_mix_nonnegative:
        cp wa,255
        jr le,pcm_mix_inrange
        ld wa,255
pcm_mix_inrange:
        ld w,a
        ld (xhl),wa
        inc 2,xhl
        inc 2,xde
        djnz bc,pcm_mix_loop
        ret
_pcm_silence:
        ld xde,(xsp+4)
        ld bc,256
        ld wa,0x8080
pcm_silent_loop:
        ld (xde),wa
        inc 2,xde
        djnz bc,pcm_silent_loop
        ret
_pcm_dma_arm:
        ld xwa,0xa2
        ldc dmad0,xwa
        ld a,9
        ldc dmam0,a
        ld xwa,(xsp+4)
        ldc dmas0,xwa
        ld wa,256
        ldc dmac0,wa
        ld (0x7c),0x11
        ret

_pcm_unpack_mix:
        push xix
        push xiy
        push xiz
        ld xix,(xsp+16)
        ld xiy,(xsp+20)
        ld xwa,(xiy)
        ld (0x71f0),xwa
        ld xwa,(xiy+4)
        ld (0x71f4),xwa
        ld xwa,(xiy+8)
        ld (0x71f8),xwa
        ld xwa,(xiy+12)
        ld (0x71fc),xwa
        lda xhl,xiy+16
        ld xiy,0x71f0
        ld iz,128
pcm_fused_loop:
        ld c,(xhl)
        inc 1,xhl
        ld wa,0
        ld a,c
        and a,15
        ld e,(xiy+wa)
        ld d,0
        ld a,(xix+0)
        add wa,de
        sub wa,128
        cp wa,255
        jr ule,pcm_fused_ok_0
        bit 7,w
        jr z,pcm_fused_positive_0
        ld wa,0
        jr pcm_fused_ok_0
pcm_fused_positive_0:
        ld wa,255
pcm_fused_ok_0:
        ld w,a
        ld (xix+0),wa
        srl 4,c
        ld wa,0
        ld a,c
        and a,15
        ld e,(xiy+wa)
        ld d,0
        ld a,(xix+2)
        add wa,de
        sub wa,128
        cp wa,255
        jr ule,pcm_fused_ok_1
        bit 7,w
        jr z,pcm_fused_positive_1
        ld wa,0
        jr pcm_fused_ok_1
pcm_fused_positive_1:
        ld wa,255
pcm_fused_ok_1:
        ld w,a
        ld (xix+2),wa
        inc 4,xix
        djnz iz,pcm_fused_loop
        pop xiz
        pop xiy
        pop xix
        ret
_pcm_unpack_mix_end:
        end
