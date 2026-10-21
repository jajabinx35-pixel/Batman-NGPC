"""Build the exact Rear Skyline normal and diagnostic ROMs, serially."""
from pathlib import Path
import argparse
import hashlib
import json
import subprocess
import sys
from linux_runner.prepare_runner import workspace

P = Path(__file__).resolve().parents[1]
ap = argparse.ArgumentParser(description=__doc__)
ap.add_argument('--kind', choices=['both','normal','diagnostic'], default='both')
ap.add_argument('--clean', action='store_true')
ap.add_argument('--t900', type=Path, default=P/'T900', help='Original SDK; prepared automatically')
ap.add_argument('--runner', type=Path, default=P/'tools/wibo-compat')
ap.add_argument('--work-dir', type=Path, default=workspace()/'build')
ap.add_argument('--verify-release', action='store_true', help='Require accepted ROM hashes; omit after editing game sources')
a = ap.parse_args()
accepted = json.loads((P/'Batman_M30R2_Rear_Skyline_Manifest.json').read_text())
results = []
evidence = P/'EVIDENCE/COMPILER_FIX'
evidence.mkdir(parents=True, exist_ok=True)
for diagnostic in (False,True):
    if a.kind != 'both' and diagnostic != (a.kind == 'diagnostic'):
        continue
    label = 'diagnostic' if diagnostic else 'normal'
    info = accepted[label]
    cmd = [sys.executable, str(P/'tools/build_m12.py'),
           '--version', '31' if diagnostic else '30',
           '--runner', str(a.runner.resolve()), '--t900', str(a.t900.resolve()),
           '--build-dir', str(a.work_dir.resolve()/label/'game'),
           '--evidence-dir', str(evidence/('BUILD_'+label.upper())),
           '--output-name', info['file']]
    if a.clean:
        cmd.append('--clean')
    if diagnostic:
        cmd.append('--diagnostic')
    with (evidence/(label+'_build.log')).open('w') as log:
        process = subprocess.Popen(cmd, cwd=P, stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                                   text=True, bufsize=1)
        for line in process.stdout:
            print(line, end='', flush=True)
            log.write(line)
            log.flush()
        code = process.wait()
    if code:
        raise SystemExit('Build failed; see '+str(evidence/(label+'_build.log')))
    output = P/'OUTPUT'/info['file']
    data = output.read_bytes()
    digest = hashlib.sha256(data).hexdigest()
    matches = len(data) == info['bytes'] and digest == info['sha256']
    results.append({'kind':label, 'file':info['file'], 'bytes':len(data),
                    'sha256':digest, 'matches_accepted_release':matches})
    if a.verify_release and not matches:
        raise SystemExit('ROM differs from accepted release: '+str(output))
(evidence/'CLEAN_BUILD_RESULTS.json').write_text(json.dumps({
    'passed':True, 'clean':a.clean, 'verified_release':a.verify_release,
    'results':results}, indent=2)+'\n')
print('BUILD COMPLETE: cartridges are in OUTPUT/')
