"""Repeat the unchanged-main.c R6002 control and prepared-toolchain test."""
from pathlib import Path
import fcntl
import hashlib
import json
import os
import subprocess
from linux_runner.prepare_runner import PROJECT, prepare_toolchain, workspace

P = PROJECT
evidence = P/'EVIDENCE/COMPILER_FIX'
evidence.mkdir(parents=True, exist_ok=True)
runner = P/'tools/wibo-compat'
source_sdk = P/'T900'
win = lambda path:'Z:'+str(Path(path).resolve()).replace('/','\\')
with open('/tmp/batman_toshiba_build.lock','a') as lock:
    fcntl.flock(lock.fileno(), fcntl.LOCK_EX)
    sdk = prepare_toolchain(source_sdk, runner)
    work = workspace()/'compiler_control'
    work.mkdir(parents=True, exist_ok=True)
    flags = ['-A','-c','-O3','-Nb2']
    flags += ['-I'+win(P/'game'/x) for x in ['src','vendor/ngpc/core','vendor/ngpc/gfx']]
    flags += ['-DNGP_ENABLE_DEBUG=0','-DNGP_PROFILE_RELEASE=1','-DNGP_ENABLE_SOUND=0',
              '-DNGP_ENABLE_FLASH_SAVE=0','-DNGP_NEAR=__near']
    rows = []
    for label, toolchain in [('original_pe',source_sdk), ('prepared_pe',sdk)]:
        obj = work/(label+'_main.rel')
        obj.unlink(missing_ok=True)
        env = os.environ.copy()
        env['THOME'] = win(toolchain)
        result = subprocess.run([str(runner),'-C',str(work),str(toolchain/'BIN/cc900.exe')]
            + flags + [win(P/'game/src/main.c'),'-o',win(obj)], env=env,
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=90)
        output = result.stdout.decode('latin1')
        (evidence/(label+'_main.log')).write_bytes(result.stdout)
        rows.append({'case':label,'returncode':result.returncode,
                     'object_exists':obj.is_file(),'object_bytes':obj.stat().st_size if obj.is_file() else 0,
                     'output':output,
                     'sdk_sha256':hashlib.sha256((toolchain/'BIN/cc900.exe').read_bytes()).hexdigest()})
    original, prepared = rows
    passed = (original['returncode'] != 0 and 'R6002' in original['output']
              and prepared['returncode'] == 0 and prepared['object_bytes'] > 0
              and 'R6002' not in prepared['output'])
    report = {'passed':passed,'source':'game/src/main.c',
              'source_sha256':hashlib.sha256((P/'game/src/main.c').read_bytes()).hexdigest(),
              'same_source_and_flags':True,'results':rows}
    (evidence/'MAIN_CONTROL_RESULTS.json').write_text(json.dumps(report,indent=2)+'\n')
    print(json.dumps(report,indent=2))
    if not passed:
        raise SystemExit('Compiler control did not match the documented Linux x86-64 result; inspect logs.')
