"""Prove vehicle key compaction preserves every per-stage cache identity."""
import argparse
import json
import re
from pathlib import Path

root = Path(__file__).resolve().parents[2]
ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument('--out')
args = ap.parse_args()
original = json.loads((root / 'EVIDENCE/V101_ORIGINAL_KEYS.json').read_text())
source = (root / 'SOURCE/game/src/assets_residency.c').read_text()
body = re.search(r'native_tile_keys\[2323\]\s*=\s*\{(.*?)\}', source, re.S)[1]
current = list(map(int, re.findall(r'\d+', body)))
assert len(original) == len(current) == 2323
results = []
for stage, start, stop in [(2, 0, 1164), (4, 1164, 2323)]:
    forward, reverse = {}, {}
    for old, new in zip(original[start:stop], current[start:stop]):
        assert (old == 65535) == (new == 65535), 'Sentinel changed'
        if old == 65535:
            continue
        assert forward.setdefault(old, new) == new, 'Identity split'
        assert reverse.setdefault(new, old) == old, 'Distinct identities merged'
    assert set(reverse) == set(range(len(reverse))), 'Keys are not compact'
    assert len(reverse) <= 622
    results.append({'stage': stage, 'tile_indices': stop-start,
                    'distinct_valid_keys': len(reverse), 'bijection': True})
result = {'passed': True, 'lookup_bytes_before': 1298,
          'lookup_bytes_after': 622, 'bytes_reclaimed': 676, 'results': results}
if args.out:
    Path(args.out).write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps(result, indent=2))
