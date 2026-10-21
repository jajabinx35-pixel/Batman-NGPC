"""Independently decode the actual M64 LCD screenshot at native and 4x size."""
from pathlib import Path
import argparse,json,hashlib
from PIL import Image
import zxingcpp
from batman_score_payload import decode
p=argparse.ArgumentParser()
for n in ['image','payload','rom','output']:p.add_argument('--'+n,required=True)
a=p.parse_args();im=Image.open(a.image).convert('RGB');expected=Path(a.payload).read_text().strip();sizes=[]
for scale in [1,4]:
 v=im if scale==1 else im.resize((im.width*scale,im.height*scale),Image.Resampling.NEAREST)
 results=zxingcpp.read_barcodes(v);assert len(results)==1 and results[0].text==expected,'target QR decode mismatch';sizes.append([v.width,v.height])
r={'passed':True,'independent_decoder':'ZXing-C++','decoded_image_sizes':sizes,'text':expected,'text_length':len(expected),'payload_length':len(expected)-20,'decoded':decode(expected),'rom_sha256':hashlib.sha256(Path(a.rom).read_bytes()).hexdigest()}
Path(a.output).write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
