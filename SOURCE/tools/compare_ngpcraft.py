"""Compare complete per-update state and committed surfaces from two captures."""
import argparse
import json
import zlib
from pathlib import Path

ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument('--baseline', type=Path, required=True)
ap.add_argument('--candidate', type=Path, required=True)
ap.add_argument('--out', type=Path, required=True)
args = ap.parse_args()
results = []
for stage in range(1, 6):
    name = f'LEVEL{stage}.json.zlib'
    a = json.loads(zlib.decompress((args.baseline/name).read_bytes()))
    b = json.loads(zlib.decompress((args.candidate/name).read_bytes()))
    assert a['states'] == b['states'], ('State differs', stage)
    assert a['surfaces'] == b['surfaces'], ('Surface differs', stage)
    assert len(a['states']) == len(a['surfaces']) == 300
    results.append({'stage': stage, 'identical_states': 300,
                    'identical_surfaces': 300})
result = {'passed': True, 'results': results}
args.out.write_text(json.dumps(result, indent=2) + '\n')
print('PASS: 1500 identical states and 1500 identical committed surfaces')
