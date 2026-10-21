from pathlib import Path
import subprocess,ctypes,random,string,json,sys
import zxingcpp
from PIL import Image
P=Path(__file__).resolve().parents[2];out=P/'EVIDENCE/QR_ENCODER';out.mkdir(parents=True,exist_ok=True)
inc=out/'include';inc.mkdir(exist_ok=True);(inc/'ngpc_types.h').write_text('#include <stdint.h>\ntypedef uint8_t u8;typedef uint16_t u16;typedef int16_t s16;typedef uint32_t u32;\n')
libs=[]
for label,root in [('upstream',P/'REFERENCE_QR_SDK/src'),('adapted',P/'SOURCE/game/src')]:
 lib=out/(label+'.so');subprocess.run(['cc','-shared','-fPIC','-O2','-I'+str(inc),'-I'+str(root),str(root/'ngpc_qr.c'),'-o',str(lib)],check=True)
 c=ctypes.CDLL(str(lib));libs.append(c)
class Q(ctypes.Structure):_fields_=[('matrix',ctypes.c_uint8*172),('words',ctypes.c_uint8*134),('count',ctypes.c_uint16),('valid',ctypes.c_uint8)]
for c in libs:c.ngpc_qr_encode.argtypes=[ctypes.POINTER(Q),ctypes.c_char_p];c.ngpc_qr_encode.restype=ctypes.c_uint8
rng=random.Random(62);samples=['NGPC-DEV.COM/BATMAN/BATMAN1AAA000042500001000000075000008000000900000080FFFF','A','A'*154]
samples += [''.join(rng.choice(string.ascii_uppercase+string.digits+'-.:/')for _ in range(n)) for n in [2,7,19,40,76,100,153,154]*3]
for index,text in enumerate(samples):
 a,b=Q(),Q();assert libs[0].ngpc_qr_encode(ctypes.byref(a),text.encode())==1;assert libs[1].ngpc_qr_encode(ctypes.byref(b),text.encode())==1
 assert bytes(a)==bytes(b),'scratch overlay changed matrix/ECC'
 im=Image.new('L',(45,45),255)
 for y in range(37):
  for x in range(37):
   n=y*37+x
   if (a.matrix[n>>3]>>(n&7))&1:im.putpixel((x+4,y+4),0)
 decoded=zxingcpp.read_barcodes(im.resize((360,360),Image.Resampling.NEAREST));assert len(decoded)==1 and decoded[0].text==text,(index,text,[d.text for d in decoded])
 if index in [0,2]:im.resize((360,360),Image.Resampling.NEAREST).save(out/('sample_'+str(index)+'.png'))
for text in ['', 'lowercase','A'*155]:
 a=Q();assert libs[1].ngpc_qr_encode(ctypes.byref(a),text.encode())==0 and a.valid==0
result={'passed':True,'messages':len(samples),'matrix_and_codewords_match_upstream':True,'independent_decoder':'ZXing-C++','invalid_messages_rejected':3}
(out/'RESULT.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result,indent=2))
