#!/usr/bin/env python3
"""Rebuild the corrected M58R1 normal + diagnostic NGPC cartridges."""
from pathlib import Path
import argparse,subprocess,sys,hashlib
root=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--clean',action='store_true');arg=a.parse_args()
items=[
 ('Batman_The_Movie_M58R1_Cinematic_AudioFixed_4MB.ngc',False,'553f78cbf5bad6242d9391e7f0053072e63b7598efb32661e6f4d8fe1b2a4df0'),
 ('Batman_M58R1_AudioFixed_HARDWARE_DIAG_4MB.ngc',True,'05f3b955afd820f06f4a51b4288b493f27fb8c9b1243fd1452f19b02b0c0b0ec')]
for name,diag,expected in items:
 cmd=[sys.executable,str(root/'tools/build_m12.py'),'--version','58','--output-name',name,'--build-dir',str(root/'BUILD'/('diag' if diag else 'normal')),'--evidence-dir',str(root/'BUILD_EVIDENCE'/('M58R1_diag' if diag else 'M58R1_normal'))]
 if diag:cmd.append('--diagnostic')
 if arg.clean:cmd.append('--clean')
 subprocess.run(cmd,cwd=root,check=True)
 data=(root/'OUTPUT'/name).read_bytes();digest=hashlib.sha256(data).hexdigest()
 if len(data)!=4194304 or digest!=expected:raise SystemExit('M58R1 failed reproducibility check: '+name+' '+digest)
 print('M58R1 VERIFIED',name,digest,flush=True)
