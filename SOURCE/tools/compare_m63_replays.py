"""Compare ordinary M63 replays with the retained M62 replay evidence.
No target memory writes or forced completion events are used by final_perf.
"""
from pathlib import Path
import argparse,concurrent.futures,subprocess,sys,json,csv,statistics,zlib
P=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser()
for n in ['mame','bios','seed','rom','map','baseline-source']:a.add_argument('--'+n,required=True)
v=a.parse_args();base=Path(v.baseline_source).resolve();common=[]
for n in ['mame','bios','seed','rom','map']:common+=['--'+n,str(Path(getattr(v,n)).resolve())]
def run(stage):
 name=f'FINAL_M63_L{stage}_200';out=P/'EVIDENCE'/name;old=base/'EVIDENCE'/f'FINAL_RELEASE_L{stage}_200'
 with(P.parent/'EVIDENCE'/f'replay_{name}.log').open('w')as h:
  subprocess.run([sys.executable,str(P/'tools/final_perf.py')]+common+['--updates','200','--name',name,'--stage',str(stage)],stdout=h,stderr=subprocess.STDOUT,check=True)
 m=json.loads((out/'RESULT.json').read_text());b=json.loads((old/'RESULT.json').read_text());assert m['passed']and b['passed']and m['updates']==b['updates']==200
 assert json.loads((out/'state_bytes.sha256.json').read_text())==json.loads((old/'state_bytes.sha256.json').read_text()),f'L{stage}: changed gameplay state'
 n=m['surface_size'];assert n==b['surface_size'];ignore=384 if stage==5 else 192
 def surfaces(d):
  raw=zlib.decompress((d/'surface_bytes.zlib').read_bytes());return[raw[i+ignore:i+n]for i in range(0,len(raw),n)]
 assert surfaces(out)==surfaces(old),f'L{stage}: changed non-HUD graphics'
 def means(d):
  rows=list(csv.DictReader((d/'cpu_times.csv').open()));assert len(rows)==200
  return statistics.mean(float(r['gameplay_elapsed_ms'])+float(r['prepare_elapsed_ms'])for r in rows)
 btime=means(old);mtime=means(out)
 r={'stage':stage,'updates':200,'all_gameplay_states_equal':True,'all_non_HUD_committed_surfaces_equal':True,'ignored_SCR1_HUD_map_bytes':ignore,'M62_mean_gameplay_plus_prepare_ms':btime,'M63_mean_gameplay_plus_prepare_ms':mtime,'processing_reduction_percent':(btime-mtime)*100/btime,'baseline_rom_sha256':b['rom_sha256'],'rom_sha256':m['rom_sha256']}
 print('PASS',r,flush=True);return r
with concurrent.futures.ThreadPoolExecutor(max_workers=2)as ex:r=list(ex.map(run,range(1,6)))
(P.parent/'EVIDENCE/FINAL_REPLAY_COMPARISON.json').write_text(json.dumps({'passed':True,'comparison':'M62 versus M63 at stock emulated clock, sound ON, identical update-indexed inputs; 1000 original gameplay updates','hardware_verified':False,'results':r},indent=2)+'\n')
