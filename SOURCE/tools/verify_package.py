"""Verify all source ZIP payload files immediately after extraction."""
from pathlib import Path
import hashlib
import json

P = Path(__file__).resolve().parents[1]
rows = json.loads((P/'SHA256_MANIFEST.json').read_text())
for row in rows:
    data = (P/row['path']).read_bytes()
    if len(data) != row['bytes'] or hashlib.sha256(data).hexdigest() != row['sha256']:
        raise SystemExit('FAIL '+row['path'])
print('PASS',len(rows),'manifest files, including both ROMs')
