from pathlib import Path
import re
from PIL import Image
p=Path('/mnt/data/batman_skyline_backlayer/game/src')
s=(p/'assets_native_sky.c').read_text()
def vals(name):
 m=re.search(r'\b'+name+r'\[\d+\]\s*=\s*\{(.*?)\};',s,re.S); assert m, name
 return [int(x,0) for x in re.findall(r'\b(?:0x[0-9a-fA-F]+|\d+)\b',m.group(1))]
pixels=vals('native_sky_pixels'); tilepal=vals('native_sky_pal'); pals=vals('native_sky_palettes')
assert (len(pixels),len(tilepal),len(pals))==(960,120,64)
roadcols=[(0,0,0),(15,10,2),(5,7,9),(13,14,15)]
def col(v):return v&15,(v>>4)&15,(v>>8)&15
original=Image.new('P',(320,24));original.putpalette(sum(([r*17,g*17,b*17]for r,g,b in roadcols),[])+[0]*(768-12))
for y in range(24):
 for x in range(320):
  tile=y//8*40+x//8; ink=(pixels[tile*8+y%8]>>((7-x%8)*2))&3
  rgb=col(pals[tilepal[tile]*4+ink])
  # Map native ink0 to transparent; preserve closest valid building palette
  idx=0 if ink==0 else min(range(1,4),key=lambda i:sum((rgb[k]-roadcols[i][k])**2 for k in range(3)))
  original.putpixel((x,y),idx)
# Preserve full original panorama scaled to screen-width; double its vertical reach.
city=original.resize((160,48),Image.Resampling.NEAREST)
city.resize((640,192),Image.Resampling.NEAREST).convert('RGB').save('/mnt/data/batman_skyline_backlayer/hardware_skyline_preview.png')
pattern=[]
for by in range(6):
 for bx in range(20):
  for ry in range(8):
   w=0
   for rx in range(8):w=(w<<2)|city.getpixel((bx*8+rx,by*8+ry))
   pattern.append(w)
assert len(pattern)==960
incl='/* Pre-stretched 160x48 Gotham skyline for K2GE rear scroll plane.\n'
incl+='   120 native patterns 201..320; no new RAM or frame-time raster work. */\n'
incl+='static const u16 skyline_hw_patterns[960]={\n'
for i in range(0,len(pattern),16):incl+=' '+','.join(str(v) for v in pattern[i:i+16])+',\n'
incl+='};\n'
(p/'skyline_hw.inc').write_text(incl)
n=p/'native_video.c';src=n.read_text()
start=src.index('#include "skyline_stretched.inc"');end=src.index('\n#include "vehicle_complete_frames.inc"',start)
src=src[:start]+'#include "skyline_hw.inc"\n'+src[end:]
start=src.index('  /* Far skyline belongs');end=src.index('\n }\n}',start)
src=src[:start]+'''  /* Hardware compositing: SCR2 behind SCR1, transparent ink 0.  No
     framebuffer prefills, no moving skyline over the Batmobile or Batwing. */
  HW_SCR_PRIO &= (u8)~0x80u;
  ngpc_gfx_scroll(1,0u,0u);
  ngpc_gfx_load_tiles_at(skyline_hw_patterns,960u,201u);
  ngpc_gfx_set_palette(1,0,RGB(0,0,0),RGB(15,10,2),RGB(5,7,9),RGB(13,14,15));
  palette(2,native_vehicle_palettes,16);
  ngpc_gfx_set_palette(0,0,RGB(0,0,0),RGB(15,10,2),RGB(5,7,9),RGB(13,14,15));
  /* 32-map-column repetition covers the visible 20 columns; the city is
     installed only once per stage.  At pixel level the road plane wins. */
  for(i=0;i<32u*19u;i++)HW_SCR2_MAP[i]=0;
  for(i=0;i<6u*32u;i++)HW_SCR2_MAP[6u*32u+i]=(u16)(201u+(i/32u)*20u+(i%32u)%20u);''' +src[end:]
start=src.index(' if(active_stage!=3){\n  background_dirty=1;bitmap_clear_words(');end=src.index(' }\n vehicle_profile[14]',start)
src=src[:start]+''' if(active_stage!=3){background_dirty=1;bitmap_clear_words((u32)R.road,1600ul);'''+src[end:]
start=src.index(' if(active_stage!=3){\n  scroll=skyline_frame_scroll>>3;');end=src.index('\n}',start)
src=src[:start]+src[end:]
# Clean up now-unused native_commit globals for build warnings only.
n.write_text(src)
print('compiled source size',len(src),'pattern bytes',len(pattern)*2)
