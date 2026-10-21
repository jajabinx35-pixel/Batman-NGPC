$MAXIMUM
        module vehicle_edges_native
        public _vehicle_edge_pixels_regs
EDGE_PIXELS section code large
; Private assembly register ABI, called only by edge_pixels_all.
; A=error W=dy C=dx B=kind HL=count+1 IY=x IX=destination.
; Returns A=error E=source-X IY=x IX=advanced destination.
_vehicle_edge_pixels_regs:
        bit 0,b
        jr nz,edge_steep
edge_shallow:
        add a,c
        scc c,e
        cp a,w
        jr c,edge_shallow_store
        sub a,w
        bit 1,b
        jr z,edge_shallow_left
        inc 1,iy
        cp iy,0
        scc z,e
        jr edge_shallow_store
edge_shallow_left:
        dec 1,iy
        cp iy,0xffff
        scc z,e
edge_shallow_store:
        ld (xix),iy
        inc 2,xix
        djnz hl,edge_shallow
        jr edge_result
edge_steep:
        bit 1,b
        jr z,edge_steep_left
        inc 1,iy
        jr edge_steep_add
edge_steep_left:
        dec 1,iy
edge_steep_add:
        add a,w
        jr c,edge_steep_sub
        cp a,c
        jr c,edge_steep
edge_steep_sub:
        cp a,c
        scc c,e
        sub a,c
        ld (xix),iy
        inc 2,xix
        djnz hl,edge_steep
edge_result:
        ret
        end
