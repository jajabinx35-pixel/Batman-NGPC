"""Build a 4 MiB cartridge with automatic legacy Toshiba runtime setup."""
from pathlib import Path
import os,sys,json,subprocess,shutil,hashlib,re,argparse
from linux_runner.prepare_runner import prepare_toolchain,workspace
p=Path(__file__).resolve().parents[1];ap=argparse.ArgumentParser();ap.add_argument('--clean',action='store_true');ap.add_argument('--runner',default=str(p/'tools/wibo-compat'));ap.add_argument('--t900',default=str(p/'T900'));ap.add_argument('--build-dir',default=str(workspace()/'generic/game'));ap.add_argument('--source-game',type=Path,default=p/'game');ap.add_argument('--diagnostic',action='store_true');ap.add_argument('--version',type=int,default=18);ap.add_argument('--output-name');ap.add_argument('--evidence-dir',type=Path,default=p/'EVIDENCE');a=ap.parse_args();runner=Path(a.runner).resolve();t900=Path(a.t900).resolve();g=Path(a.build_dir).resolve();src_game=a.source_game.resolve();evidence=a.evidence_dir.resolve();evidence.mkdir(parents=True,exist_ok=True)
# The Windows toolchain uses shared temporary names; serialize SDK builds.
if os.name=='posix':
 import fcntl
 build_lock=open('/tmp/batman_toshiba_build.lock','a')
 fcntl.flock(build_lock.fileno(),fcntl.LOCK_EX)
t900=prepare_toolchain(t900,runner)
shutil.copy2(t900.parent/'PREPARED.json',evidence/'TOOLCHAIN_PREPARED.json')
if a.clean and g.exists():shutil.rmtree(g)
(g/'build').mkdir(parents=True,exist_ok=True)
for n in ['src','vendor']:
 for item in (src_game/n).rglob('*'):
  if item.is_file():
   dst=g/n/item.relative_to(src_game/n);dst.parent.mkdir(parents=True,exist_ok=True)
   if not dst.exists()or dst.read_bytes()!=item.read_bytes():shutil.copy2(item,dst);dst.touch()
shutil.copy(src_game/'ngpc.lcf',g/'ngpc.lcf');win=lambda x:'Z:'+str(Path(x).resolve()).replace('/','\\');env=os.environ.copy();env['THOME']=win(t900);manifest=json.loads((p/'tools/build_sources.json').read_text());objects=[];(evidence/'TOSHIBA_BUILD_LOG.txt').write_text('')
object_stems=[Path(x).stem.lower()for x in manifest['c']+manifest['asm']+manifest['library_asm']]
assert len(object_stems)==len(set(object_stems)),'C/ASM inputs must have unique object basenames'
config=json.dumps({'diagnostic':a.diagnostic,'version':a.version,'source':str(src_game),'manifest_sha256':hashlib.sha256((p/'tools/build_sources.json').read_bytes()).hexdigest()})
if (g/'build/config.json').exists() and (g/'build/config.json').read_text()!=config:
 for stale in (g/'build').glob('*.rel'):stale.unlink()
(g/'build/config.json').write_text(config)
if a.diagnostic:
 f=g/'src/graphics_diff.asm';s=f.read_text()
 s=s.replace('        push bc\n','        push xiz\n        ld iz,0\n        push bc\n',1)
 s=re.sub(r'(        ld \(xde(?:\+\d+)?\),xwa)',r'\1\n        inc 4,iz',s)
 s=s.replace('        ld (xde),wa','        ld (xde),wa\n        inc 2,iz')
 s=s.replace('        ret z','        jp z,diag_diff_return').replace('        ret\n','        jp diag_diff_return\n')
 s=s.replace('        end','diag_diff_return:\n        ld hl,iz\n        pop xiz\n        ret\n        end')
 f.write_bytes(s.replace('\n','\r\n').encode())
def run(exe,args,expected=None):
 print('RUN',exe, next((x for x in args if x.lower().endswith(('.c','.asm'))),args[0]if args else''),flush=True)
 if expected:expected.unlink(missing_ok=True)
 r=subprocess.run([str(runner),'-C',str(g),str(t900/'BIN'/exe)]+args,env=env,stdout=subprocess.PIPE,stderr=subprocess.STDOUT);s=r.stdout.decode('latin1')
 with (evidence/'TOSHIBA_BUILD_LOG.txt').open('a')as log:
  log.write('\nRUN '+exe+' '+repr(args)+'\n'+s+'\nEXIT '+str(r.returncode)+'\n')
 if r.returncode or re.search(r'(?:Error|Fatal)\s*[-:]|runtime error|\bR6\d{3}\b',s,re.I)or(expected and(not expected.is_file()or expected.stat().st_size==0)):
  print(s,file=sys.stderr,flush=True)
  raise RuntimeError('Toshiba tool failure: '+exe+' (exit '+str(r.returncode)+'). See '+str(evidence/'TOSHIBA_BUILD_LOG.txt'))
def latest(f,seen=None):
 seen=set()if seen is None else seen
 if f in seen:return 0
 seen.add(f);v=f.stat().st_mtime
 if f.suffix.lower()in ['.c','.h','.inc']:
  for name in re.findall(r'^\s*#include\s+"([^"]+)"',f.read_text(),re.M):
   target=next((q for q in [f.parent/name]+[g/n/name for n in ['src','vendor/ngpc/core','vendor/ngpc/gfx']]if q.is_file()),None)
   if target:v=max(v,latest(target,seen))
 return v
flags=['-A','-c','-O3','-Nb2']+['-I'+win(g/x)for x in ['src','vendor/ngpc/core','vendor/ngpc/gfx']]+['-DNGP_ENABLE_DEBUG=0','-DNGP_PROFILE_RELEASE=1','-DNGP_ENABLE_SOUND=0','-DNGP_ENABLE_FLASH_SAVE=0','-DNGP_NEAR=__near']
if a.diagnostic:flags+=['-DHW_PERF=1','-DHW_PERF_VERSION='+str(a.version)]
for src in manifest['c']:
 source=g/src;obj=g/'build'/(source.stem+'.rel')
 if not obj.exists()or obj.stat().st_mtime<latest(source):run('cc900.exe',flags+[win(source),'-o',win(obj)],obj)
 objects.append(obj)
for src in manifest['asm']+manifest['library_asm']:
 source=g/src if src in manifest['asm']else t900/'LIB/SRC'/src;obj=g/'build'/(source.stem+'.rel')
 if not obj.exists()or obj.stat().st_mtime<latest(source):run('asm900.exe',[win(source),'-o',win(obj)],obj)
 objects.append(obj)
for f in ['batman.abs','batman.s24','batman.map']:(g/f).unlink(missing_ok=True)
for stale in g.glob('batman.o[0-9a-f][0-9a-f]'):stale.unlink()
run('tulink.exe',['-la','-o',win(g/'batman.abs'),win(g/'ngpc.lcf')]+[win(f)for f in objects]);run('tuconv.exe',['-Fs24',win(g/'batman.abs')]);rom=bytearray(b'\xff'*4194304);seen=bytearray(4194304)
assert not list(g.glob('batman.o[0-9a-f][0-9a-f]')),'Converter emitted split overlays: overlapping load images are not a valid cartridge'
for line in (g/'batman.s24').read_text().splitlines():
 if not line.startswith(('S1','S2','S3')):continue
 n={'1':2,'2':3,'3':4}[line[1]];raw=bytes.fromhex(line[2:]);assert len(raw)==raw[0]+1 and sum(raw)&255==255;at=int.from_bytes(raw[1:n+1],'big');data=raw[n+1:-1]
 if not data:continue
 if 0x200000<=at and at+len(data)<=0x400000:off=at-0x200000
 elif 0x800000<=at and at+len(data)<=0xa00000:off=0x200000+at-0x800000
 else:raise ValueError('S-record outside cartridge windows: '+hex(at))
 assert not any(seen[off:off+len(data)]),'Overlapping cartridge load images at '+hex(at)
 seen[off:off+len(data)]=b'\1'*len(data);rom[off:off+len(data)]=data
assert len(rom)==4194304 and rom[36:48]==b'BATMAN MOVIE'
assert not any(seen[0x1f0000:0x200000]),'Cartridge image overlaps save/BIOS flash sectors'
assert rom[0x1f0000:0x200000]==b'\xff'*65536,'Save and BIOS flash sectors must ship erased'
mp=(g/'batman.map').read_text()
if (src_game/'src/vehicle_edge_pixels_all.asm').is_file() and 'chg 0,l' in (src_game/'src/vehicle_edge_pixels_all.asm').read_text():
 stage_at=re.search(r'_stage_work\s+([0-9A-F]{4,6})\s+f_area',mp)
 assert stage_at and int(stage_at[1],16)%2==0,'Word-swapped edge addressing requires aligned stage_work'

link_values={n:int(v,16) for n,v in re.findall(r'(__[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})',mp)}
ram_end=link_values['__DataRAM_START']+link_values['__DataROM_END']-link_values['__DataROM_START']
ram_limit=0x6b60 if '__GraphicsROM_START' in link_values else 0x6c00
assert link_values['__Bss_END']<=ram_limit and ram_end<=ram_limit,'Game RAM overlaps runtime code or BIOS workspace'
for stem,limit in [('Pcm',496),('Graphics',160),('Clear',64),('FastAxis',448),('FastCat',448),('FastVeh',448)]:
 if '__'+stem+'ROM_START' in link_values:assert 0<link_values['__'+stem+'ROM_END']-link_values['__'+stem+'ROM_START']<=limit,stem+' load image exceeds its RAM window'
for section,limit in [('PCM_NATIVE',0x1f0),('FAST_AXIS',448),('FAST_CAT',448),('FAST_VEH',448),('GRAPHICS_DIFF',160),('RAM_CLEAR',64)]:
 sizes=re.findall(r'\b'+section+r'\s+CODE\s+[0-9A-F]+\s+([0-9A-F]+)\s+'+section+r'\(',mp)
 if sizes:assert len(sizes)==1 and int(sizes[0],16)<=limit,section+' exceeds reserved RAM'
scan_size=link_values['__PlatformScanROM_END']-link_values['__PlatformScanROM_START']
assert 0<scan_size<=6568-2560,'Platform scan kernel exceeds unused platform render tail'
native_size=link_values['__NativeKernelROM_END']-link_values['__NativeKernelROM_START']
assert 0<native_size<=400,'Native edge kernels exceed the unused vehicle map window'
road_size=link_values['__NativeRoadROM_END']-link_values['__NativeRoadROM_START']
assert 0<road_size<=676,'Native road kernel exceeds compact-cache tail'
out=p/'OUTPUT'/(a.output_name or (('Batman_M%d_HARDWARE_DIAG_4MB.ngc' if a.diagnostic else 'Batman_The_Movie_NGPC_M%d_4MB.ngc') % a.version));out.parent.mkdir(parents=True,exist_ok=True);out.write_bytes(rom)
for n in ['batman.abs','batman.s24','batman.map']:shutil.copy(g/n,evidence/n)
print('BUILT',out,'SHA256',hashlib.sha256(rom).hexdigest(),flush=True)
