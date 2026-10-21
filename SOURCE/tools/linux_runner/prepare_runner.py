"""Prepare original Toshiba PE files for the pinned Linux Wibo runner.

Only a temporary SDK copy is changed. The read-only .hdr section maps the
PE headers at RVA 0. No compiler code is patched.
"""
from pathlib import Path
import argparse
import hashlib
import json
import platform
import shutil
import struct
import tempfile

PROJECT = Path(__file__).resolve().parents[2]
RUNNER_SHA256 = '37028b143ad43e22f1b43eaac7fcf3452357f09ed80ee0acb5168e7bca3298a1'


def workspace():
    identity = hashlib.sha256(str(PROJECT).encode()).hexdigest()[:16]
    return Path(tempfile.gettempdir()) / ('batman_m30r2_' + identity)


def map_headers(data):
    """Map headers explicitly for legacy Wibo 1.2.0."""
    b = bytearray(data)
    if b[:2] != b'MZ':
        raise RuntimeError('Expected a Toshiba Windows PE executable')
    pe = struct.unpack_from('<I', b, 0x3c)[0]
    if b[pe:pe+4] != b'PE\0\0':
        raise RuntimeError('Invalid Toshiba PE signature')
    count = struct.unpack_from('<H', b, pe+6)[0]
    optlen = struct.unpack_from('<H', b, pe+20)[0]
    table = pe+24+optlen
    names = [bytes(b[table+i*40:table+i*40+8]).rstrip(b'\0') for i in range(count)]
    if b'.hdr' in names:
        return bytes(b)
    first = min(struct.unpack_from('<I', b, table+i*40+20)[0] for i in range(count))
    new = table+count*40
    if new+40 > first or len(b) < 4096:
        raise RuntimeError('No room for the documented PE header mapping')
    raw = (len(b)+0x1ff) & ~0x1ff
    struct.pack_into('<H', b, pe+6, count+1)
    struct.pack_into('<8sIIIIIIHHI', b, new, b'.hdr\0\0\0\0',
                     4096, 0, 4096, raw, 0, 0, 0, 0, 0x40000040)
    header = bytes(b[:4096])
    b.extend(b'\0'*(raw-len(b)))
    b.extend(header)
    return bytes(b)


def prepare_toolchain(source=None, runner=None):
    """Caller holds /tmp/batman_toshiba_build.lock until tools finish."""
    if platform.system() != 'Linux' or platform.machine().lower() not in ('x86_64','amd64'):
        raise RuntimeError('This entry point requires Linux x86-64 (including WSL2 x86-64).')
    source = Path(source or PROJECT/'T900').resolve()
    runner = Path(runner or PROJECT/'tools/wibo-compat').resolve()
    if not runner.is_file() or hashlib.sha256(runner.read_bytes()).hexdigest() != RUNNER_SHA256:
        raise RuntimeError('Missing or altered tools/wibo-compat. Extract the complete corrected ZIP.')
    runner.chmod(runner.stat().st_mode | 0o111)
    for name in ('cc900.exe','asm900.exe','tulink.exe','tuconv.exe'):
        if not (source/'BIN'/name).is_file():
            raise RuntimeError('Missing Toshiba tool: '+str(source/'BIN'/name)+'. Extract T900 from the ZIP.')
    signature = hashlib.sha256()
    for f in sorted(source.rglob('*')):
        if f.is_file():
            signature.update(f.relative_to(source).as_posix().encode()+b'\0')
            signature.update(hashlib.sha256(f.read_bytes()).digest())
    fingerprint = signature.hexdigest()
    target = workspace()/'sdk'/fingerprint[:16]/'T900'
    if source == target or source in target.parents:
        raise RuntimeError('SDK source must not contain its temporary destination')
    shutil.copytree(source, target, dirs_exist_ok=True)
    rows = []
    for f in sorted((target/'BIN').iterdir()):
        if f.suffix.lower() not in ('.exe','.dll'):
            continue
        original = f.read_bytes()
        prepared = map_headers(original)
        f.write_bytes(prepared)
        rows.append({'file':f.name, 'source_sha256':hashlib.sha256(original).hexdigest(),
                     'prepared_sha256':hashlib.sha256(prepared).hexdigest()})
    (target.parent/'PREPARED.json').write_text(json.dumps({
        'source':str(source), 'source_fingerprint':fingerprint,
        'runner_sha256':RUNNER_SHA256, 'header_mapping':'read-only RVA 0, 4096 bytes',
        'files':rows}, indent=2)+'\n')
    print('Prepared Toshiba SDK copy:', target, flush=True)
    return target


if __name__ == '__main__':
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--t900', type=Path, default=PROJECT/'T900')
    ap.add_argument('--runner', type=Path, default=PROJECT/'tools/wibo-compat')
    args = ap.parse_args()
    import fcntl
    with open('/tmp/batman_toshiba_build.lock','a') as lock:
        fcntl.flock(lock.fileno(), fcntl.LOCK_EX)
        prepare_toolchain(args.t900, args.runner)
