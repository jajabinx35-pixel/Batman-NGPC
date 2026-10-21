#!/usr/bin/env python3
"""Rebuild the matched M57 normal and diagnostic ROMs from this source.
Legacy Toshiba TLCS-900 compiler requires Linux x86-64 and bundled wibo-compat.
"""
from pathlib import Path
import subprocess,sys,hashlib,argparse
p=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser();parser.add_argument('--clean',action='store_true');args=parser.parse_args()
releases=[
 ('M57_PLATFORM_NORMAL_4MB.ngc',False,30,'ae4b8457f240b6e9e37cdd212c44c978d7e22239d5b6bfa630ec190800a6e3a1'),
 ('M57_PLATFORM_DIAG_4MB.ngc',True,57,'bfbcd7c545bc6cccb6a21612223de57c1c4079f4e43983e6ae719d28d1347838')]
for name,diag,ver,expected in releases:
 cmd=[sys.executable,str(p/'tools/build_m12.py'),'--version',str(ver),'--output-name',name,
      '--build-dir',str(p/'BUILD'/('diag' if diag else 'normal')),
      '--evidence-dir',str(p/'BUILD_EVIDENCE'/('diag' if diag else 'normal'))]
 if diag:cmd.append('--diagnostic')
 if args.clean:cmd.append('--clean')
 subprocess.run(cmd,cwd=p,check=True)
 rom=p/'OUTPUT'/name
 digest=hashlib.sha256(rom.read_bytes()).hexdigest()
 if rom.stat().st_size!=4194304 or digest!=expected:
  raise SystemExit('NOT REPRODUCIBLE: '+name+' '+digest)
 print('VERIFIED',name,digest)
