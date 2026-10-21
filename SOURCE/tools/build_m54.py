#!/usr/bin/env python3
"""Build and verify M54 normal/diagnostic using the supplied corrected Toshiba SDK."""
from pathlib import Path
import subprocess,hashlib,sys
P=Path(__file__).resolve().parents[1]
subprocess.run([sys.executable,str(P/'tools/build_m30r2.py'),'--kind','both']+sys.argv[1:],cwd=P,check=True)
for src,dst,sha in [
 ('Batman_M30R2_Rear_Skyline_4MB.ngc','Batman_M54_Clear16_Normal_4MB.ngc','2efd9b2491bcaf9990a68dd8756fb67645e379a52fa13804493d5b3a58f49aaf'),
 ('Batman_M30R2_Rear_Skyline_HARDWARE_DIAG_4MB.ngc','Batman_M54_Clear16_HARDWARE_DIAG_4MB.ngc','a6e522c20f3651432b03c40e6cc28a1331c21683025a9c6c7735c3d2c27889ab')]:
 data=(P/'OUTPUT'/src).read_bytes();actual=hashlib.sha256(data).hexdigest()
 if len(data)!=4194304 or actual!=sha:raise SystemExit('M54 build mismatch: '+dst+' '+actual)
 (P/'OUTPUT'/dst).write_bytes(data);print('VERIFIED',dst,actual)
