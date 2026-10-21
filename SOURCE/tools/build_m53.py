#!/usr/bin/env python3
"""Build exact M53 normal+diagnostic ROMs using repaired Toshiba tools."""
from pathlib import Path
import subprocess,sys,hashlib,shutil,argparse
p=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--clean',action='store_true');args=a.parse_args()
cmd=[sys.executable,str(p/'tools/build_m30r2.py'),'--kind','both']
if args.clean:cmd.append('--clean')
subprocess.run(cmd,cwd=p,check=True)
for source,dst,expected in [
('Batman_M30R2_Rear_Skyline_4MB.ngc','Batman_M53_DirectRoad_Normal_4MB.ngc','0493b001795003130b4add223c06016959bbb15fc869f49e66196cc508dcb678'),
('Batman_M30R2_Rear_Skyline_HARDWARE_DIAG_4MB.ngc','Batman_M53_DirectRoad_HARDWARE_DIAG_4MB.ngc','f3fed9704b7a18bc8d0251bcfaf1164be6d172c985d2510bd3d0f77eec162204')]:
 b=(p/'OUTPUT'/source).read_bytes();actual=hashlib.sha256(b).hexdigest()
 if len(b)!=4194304 or actual!=expected:raise SystemExit('Rebuild mismatch: '+source+' '+actual)
 (p/'OUTPUT'/dst).write_bytes(b);print('VERIFIED',dst,actual)
