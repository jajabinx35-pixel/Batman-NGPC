"""Convert actual gameplay screenshots into static NGPC ending tiles.
No runtime conversion; opaque black plus three inks per 8x8 tile, 16 palettes.
"""
from pathlib import Path
from collections import Counter
import argparse,json,hashlib
from PIL import Image
import numpy as np
P=Path(__file__).resolve().parents[1];ap=argparse.ArgumentParser();ap.add_argument('--input',type=Path,required=True);a=ap.parse_args();out=P.parent/'EVIDENCE/ENDING_ASSETS';out.mkdir(parents=True,exist_ok=True)
chunks=['#include "ending_shots.h"\n#pragma section const ending_assets\n'];metadata=[];report=[]
def arr(name,values):
 chunks.append('const u16 '+name+'['+str(len(values))+']={\n'+''.join(','.join(str(v)for v in values[i:i+20])+',\n'for i in range(0,len(values),20))+'};\n')
for n in range(1,6):
 src=a.input/f'level{n}.png';im=Image.open(src).convert('RGB');assert im.size==(160,152)
 box=(0,48,160,136)if n==5 else(0,24,160,144);im=im.crop(box);rows=im.height//8;tiles=[];palettes=[];freq=Counter()
 rgb=np.asarray(im,dtype=np.int32);rgb=np.minimum(15,(rgb+8)//17);packed=rgb[:,:,0]+rgb[:,:,1]*16+rgb[:,:,2]*256
 for y in range(rows):
  for x in range(20):
   tile=packed[y*8:y*8+8,x*8:x*8+8];hist=Counter(int(v)for v in tile.flat);col=[v for v,_ in hist.most_common()if v][:3];pal=(0,)+tuple(sorted(col))+tuple([0]*(3-len(col)));freq[pal]+=1;tiles.append(tile);palettes.append(pal)
 candidates=list(freq);palrgb=np.array([[[v&15,(v>>4)&15,(v>>8)&15]for v in pal]for pal in candidates]);errors=[]
 for tile in tiles:
  colors,counts=np.unique(tile,return_counts=True);color=np.array([[v&15,(v>>4)&15,(v>>8)&15]for v in colors]);dist=((color[:,None,None,:]-palrgb[None,:,:,:])**2).sum(axis=3).min(axis=2);errors.append((dist*counts[:,None]).sum(axis=0))
 errors=np.asarray(errors);current=np.full(len(tiles),999999999);chosen=[]
 for _ in range(min(16,len(candidates))):
  improvement=(current[:,None]-np.minimum(current[:,None],errors)).sum(axis=0);improvement[chosen]=-1;j=int(improvement.argmax());chosen.append(j);current=np.minimum(current,errors[:,j])
 pals=[candidates[j]for j in chosen];pals += [(0,0,0,0)]*(16-len(pals));pattern_words=[];pattern_index={};map_words=[];preview=Image.new('RGB',im.size)
 for at,tile in enumerate(tiles):
  j=int(errors[at,chosen].argmin());pal=pals[j];pr=np.array([[v&15,(v>>4)&15,(v>>8)&15]for v in pal]);tr=np.array([[[v&15,(v>>4)&15,(v>>8)&15]for v in row]for row in tile]);inks=((tr[:,:,None,:]-pr[None,None,:,:])**2).sum(axis=3).argmin(axis=2);words=tuple(sum(int(inks[y,x])<<(14-x*2)for x in range(8))for y in range(8))
  if words not in pattern_index:pattern_index[words]=len(pattern_words)//8+1;pattern_words.extend(words)
  map_words.append(pattern_index[words]|(j<<9));x=(at%20)*8;y=(at//20)*8
  for yy in range(8):
   for xx in range(8):preview.putpixel((x+xx,y+yy),tuple(int(c)*17 for c in pr[int(inks[yy,xx])]))
 assert len(pattern_words)//8<400
 arr(f'ending_pixels_{n}',pattern_words);arr(f'ending_map_{n}',map_words);arr(f'ending_palettes_{n}',[v for pal in pals for v in pal]);metadata.append((n,len(pattern_words),rows));preview.save(out/f'level{n}_native_preview.png')
 report.append({'level':n,'source_sha256':hashlib.sha256(src.read_bytes()).hexdigest(),'crop':box,'tile_patterns':len(pattern_words)//8,'rows':rows,'native_bytes':2*(len(pattern_words)+len(map_words)+64),'mean_squared_RGB4_error':float(current.sum()/(im.width*im.height*3))})
chunks.append('#pragma section const f_const\nconst EndingShot ending_shots[5]={\n'+''.join('{ending_pixels_%d,ending_map_%d,ending_palettes_%d,%d,%d},\n'%(n,n,n,w,r)for n,w,r in metadata)+'};\n');(P/'game/src/ending_shots.c').write_text(''.join(chunks));(out/'RESULT.json').write_text(json.dumps({'shots':report,'static_ROM_bytes':sum(r['native_bytes']for r in report),'gameplay_cost':0},indent=2)+'\n');print('Generated ending screenshots',sum(r['native_bytes']for r in report),'bytes')
