#!/usr/bin/env python3
"""Build M51R1 through the preserved, repaired M30R2 Toshiba pipeline."""
from pathlib import Path
import argparse,hashlib,json,subprocess,sys,shutil
root=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--clean',action='store_true');args=a.parse_args()
cmd=[sys.executable,str(root/'tools/build_m30r2.py')]
if args.clean:cmd.append('--clean')
subprocess.run(cmd,cwd=root,check=True)
manifest=json.loads((root/'M51R1_MANIFEST.json').read_text())['roms']
for kind,old in [('normal','Batman_M30R2_Rear_Skyline_4MB.ngc'),('diagnostic','Batman_M30R2_Rear_Skyline_HARDWARE_DIAG_4MB.ngc')]:
 entry=manifest[kind];src=root/'OUTPUT'/old;dst=root/'OUTPUT'/entry['file'];data=src.read_bytes()
 actual=hashlib.sha256(data).hexdigest()
 if actual!=entry['sha256'] or len(data)!=entry['bytes']:raise SystemExit(f'{kind} ROM differs from verified M51R1: {actual}')
 shutil.copyfile(src,dst)
 print('VERIFIED',kind,actual,dst)
