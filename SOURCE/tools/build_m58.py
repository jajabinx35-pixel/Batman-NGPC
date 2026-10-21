#!/usr/bin/env python3
"""Build M58 normal and hardware diagnostic ROMs, then verify known SHA-256."""
from pathlib import Path
import subprocess,sys,argparse,hashlib
p=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--clean',action='store_true');opt=a.parse_args()
for file,diagnostic,expected in [
 ('Batman_The_Movie_M58_Cinematic_Intro_4MB.ngc',False,'fae2dccfb4db537125edc2e41164e830b8131ec914df65fa31bb9d9b3c3b752c'),
 ('Batman_M58_Cinematic_Intro_HARDWARE_DIAG_4MB.ngc',True,'260e8a4bc7ae8f9af8ec1b88340d6232160f093eba17877a54a2cc4071ef3003')]:
 cmd=[sys.executable,str(p/'tools/build_m12.py'),'--version','58','--output-name',file,'--build-dir',str(p/'BUILD'/('diag' if diagnostic else 'normal')),'--evidence-dir',str(p/'BUILD_EVIDENCE'/('diag' if diagnostic else 'normal'))]
 if diagnostic:cmd.append('--diagnostic')
 if opt.clean:cmd.append('--clean')
 subprocess.run(cmd,cwd=p,check=True)
 data=(p/'OUTPUT'/file).read_bytes();digest=hashlib.sha256(data).hexdigest()
 if len(data)!=4194304 or digest!=expected:raise SystemExit('REBUILD MISMATCH '+file+' '+digest)
 print('VERIFIED',file,digest)
