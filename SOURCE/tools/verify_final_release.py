"""Verify an extracted M64 package, including both playable ROMs and source."""
from pathlib import Path
import hashlib,json
P=Path(__file__).resolve().parents[2];manifest=P/'SHA256SUMS.txt';count=0
for line in manifest.read_text().splitlines():
 if not line:continue
 expected,name=line.split('  ',1);p=P/name
 assert p.is_file(),'Missing '+name
 assert hashlib.sha256(p.read_bytes()).hexdigest()==expected,'Modified/corrupt '+name;count+=1
ids=json.loads((P/'DOCUMENTATION/FINAL_ROM_IDENTITIES.json').read_text())
for kind in ['normal','diagnostic']:
 r=ids[kind];p=P/'OUTPUT'/r['file'];b=p.read_bytes();assert len(b)==4194304 and hashlib.sha256(b).hexdigest()==r['sha256'];assert b[0x1f0000:0x200000]==b'\xff'*65536
print('PASS',count,'files; normal and diagnostic ROM sizes/hashes; erased save/BIOS area')
