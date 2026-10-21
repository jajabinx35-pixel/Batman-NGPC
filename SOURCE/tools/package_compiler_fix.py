"""Package only after clean ROM reproduction and unchanged-source audits pass."""
from pathlib import Path
import hashlib
import json
import shutil
import zipfile

P = Path(__file__).resolve().parents[1]
E = P/'EVIDENCE/COMPILER_FIX'
D = P/'deliverables'
D.mkdir(exist_ok=True)
build = json.loads((E/'CLEAN_BUILD_RESULTS.json').read_text())
control = json.loads((E/'MAIN_CONTROL_RESULTS.json').read_text())
assert build['passed'] and build['clean'] and build['verified_release']
assert len(build['results']) == 2 and all(r['matches_accepted_release'] for r in build['results'])
assert control['passed'], 'Run check_compiler_runtime.py first'
original = json.loads((E/'ORIGINAL_PACKAGE_FILES.json').read_text())
allowed = {'tools/build_m12.py','tools/build_m30r2.py'}
changed = []
for row in original:
    f = P/row['path']
    if hashlib.sha256(f.read_bytes()).hexdigest() != row['sha256']:
        changed.append(row['path'])
assert set(changed) <= allowed, changed
assert not any(x.startswith('game/') for x in changed)
roms = json.loads((P/'Batman_M30R2_Rear_Skyline_Manifest.json').read_text())
for label in ('normal','diagnostic'):
    info = roms[label]
    data = (P/'OUTPUT'/info['file']).read_bytes()
    assert len(data) == 4194304 == info['bytes']
    assert hashlib.sha256(data).hexdigest() == info['sha256']
    assert data[0x1f0000:0x200000] == b'\xff'*65536
    assert data == (P/info['file']).read_bytes()

files = []
for f in sorted(P.rglob('*')):
    if not f.is_file():
        continue
    rel = f.relative_to(P)
    if rel.parts[0] in ('deliverables','OUTPUT') or '__pycache__' in rel.parts:
        continue
    if rel.as_posix() == 'SHA256_MANIFEST.json':
        continue
    if rel.parts[0] == 'EVIDENCE' and f.suffix.lower() in ('.abs','.s24','.rel','.o'):
        continue
    files.append(f)
rows = [{'path':f.relative_to(P).as_posix(), 'bytes':f.stat().st_size,
         'sha256':hashlib.sha256(f.read_bytes()).hexdigest()} for f in files]
manifest = P/'SHA256_MANIFEST.json'
manifest.write_text(json.dumps(rows,indent=2)+'\n')
files.append(manifest)
archive = D/'Batman_M30R2_Rear_Skyline_Source_ROM_Diagnostic.zip'
root = 'M30R2_HARDWARE_SKYLINE/'
with zipfile.ZipFile(archive,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as z:
    for f in files:
        z.write(f,root+f.relative_to(P).as_posix())
with zipfile.ZipFile(archive) as z:
    assert len(z.namelist()) == len(set(z.namelist())) == len(rows)+1
    for row in rows:
        data = z.read(root+row['path'])  # Reads every member and checks its CRC.
        assert len(data) == row['bytes']
        assert hashlib.sha256(data).hexdigest() == row['sha256'],row['path']
    assert json.loads(z.read(root+'SHA256_MANIFEST.json')) == rows
    for label in ('normal','diagnostic'):
        info = roms[label]
        assert hashlib.sha256(z.read(root+info['file'])).hexdigest() == info['sha256']
report = {'passed':True, 'all_member_crc_and_sha256_verified':True,
          'archive':archive.name,'bytes':archive.stat().st_size,
          'sha256':hashlib.sha256(archive.read_bytes()).hexdigest(),
          'members':len(rows)+1,'normal_and_diagnostic_in_zip':True,
          'unchanged_game_source':True,'changed_original_files':changed,
          'clean_rom_rebuilds':build['results']}
(D/'PACKAGE_VERIFICATION.json').write_text(json.dumps(report,indent=2)+'\n')
print(json.dumps(report,indent=2))
