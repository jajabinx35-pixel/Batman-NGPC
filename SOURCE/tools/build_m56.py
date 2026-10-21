#!/usr/bin/env python3
"""Rebuild M56 normal/diagnostic and require byte-identical expected ROMs.
Linux x86-64 with bundled repaired Toshiba compiler and wibo-compat.
"""
from pathlib import Path
import subprocess,sys,hashlib,argparse
p=Path(__file__).resolve().parents[1]
ap=argparse.ArgumentParser();ap.add_argument('--clean',action='store_true');a=ap.parse_args()
for name,diagnostic,version,expected in [
 ('Batman_M56_RoadPointer_4MB.ngc',False,30,'a1bef10ee49f9b1cc95fa78ae9998d9e06ad32fbab285060c0b59ae1c565545d'),
 ('Batman_M56_RoadPointer_HARDWARE_DIAG_4MB.ngc',True,56,'19fdb0c09c4d318fd7d2afe5af8298cd7a98124c66fe9fae4f6ef9e9c28efb5b')]:
 cmd=[sys.executable,str(p/'tools/build_m12.py'),'--version',str(version),'--output-name',name,
      '--evidence-dir',str(p/'EVIDENCE'/('BUILD_DIAG' if diagnostic else 'BUILD_NORMAL')),
      '--build-dir',str(p/'BUILD'/('diag' if diagnostic else 'normal'))]
 if diagnostic:cmd.append('--diagnostic')
 if a.clean:cmd.append('--clean')
 subprocess.run(cmd,cwd=p,check=True)
 rom=p/'OUTPUT'/name
 digest=hashlib.sha256(rom.read_bytes()).hexdigest()
 if rom.stat().st_size!=4194304 or digest!=expected:raise SystemExit('ROM validation failed: '+name+' '+digest)
 print('VERIFIED',name,digest)
