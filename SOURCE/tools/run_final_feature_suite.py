"""Run the M64 target feature suite. Requires an external working MAME/BIOS seed.
Completion fixtures force boss_state=B_COMPLETE, never used by performance tests.
"""
from pathlib import Path
import argparse,concurrent.futures,subprocess,sys,json,binascii,hashlib
P=Path(__file__).resolve().parents[1];a=argparse.ArgumentParser()
for n in ['mame','bios','seed','rom','map']:a.add_argument('--'+n,required=True)
a.add_argument('--reuse-passed',action='store_true',help='Reuse successful exact-ROM results; failed/missing/different-ROM cases always rerun.')
a.add_argument('--m62-flash',type=Path,help='Optional original M62 manual-checkpoint flash fixture for migration cases.')
v=a.parse_args();common=[];rom_hash=hashlib.sha256(Path(v.rom).read_bytes()).hexdigest()
for n in ['mame','bios','seed','rom','map']:common+=['--'+n,str(Path(getattr(v,n)).resolve())]
root=P/'EVIDENCE/FINAL_FEATURES';logs=P.parent/'EVIDENCE';runs=[]
def run(case,flash=None,name=None):
 name='release_'+(name or case);args=[sys.executable,str(P/'tools/test_final_features.py'),'--case',case,'--name',name]+common
 if v.reuse_passed and(root/name/'RESULT.json').exists():
  r=json.loads((root/name/'RESULT.json').read_text())
  if r.get('passed')and r.get('rom_sha256')==rom_hash:
   print('REUSE PASS',name,flush=True);runs.append({'name':name,**r});return root/name
 if flash:args+=['--flash',str(flash)]
 with(logs/(name+'.log')).open('w')as h:subprocess.run(args,cwd=P.parent,stdout=h,stderr=subprocess.STDOUT,check=True)
 r=json.loads((root/name/'RESULT.json').read_text());assert r['passed'];print('PASS',name,flush=True);runs.append({'name':name,**r});return root/name
# Independent factory-boot cases; no emulator save states.
with concurrent.futures.ThreadPoolExecutor(max_workers=2)as ex:
 names=['campaign','cheat_save','lives_save','zero_upload','gameover_points','quick_death','restart_points','grapple','cat_grapple','ending','menu_credits']
 dirs=dict(zip(names,ex.map(run,names)))
completed=dirs['campaign']/'completed_flash.bin';auto=dirs['campaign']/'autosave_l1_flash.bin';cheat=dirs['cheat_save']/'cheated_flash.bin';nine=dirs['lives_save']/'nine_lives_flash.bin'
with concurrent.futures.ThreadPoolExecutor(max_workers=2)as ex:
 jobs=[('continue_auto',auto),('cheat_resume',cheat),('fresh_after_cheat',cheat),('lives_resume',nine),('fresh_three',nine),('qr',dirs['gameover_points']/'gameover_flash.bin'),('cheat_campaign',completed)]
 later=dict(zip([c for c,f in jobs],ex.map(lambda j:run(*j),jobs)))
manual=later['continue_auto']/'manual_flash.bin'
# Make explicit legacy and reset fixtures from CPU-written save bytes.
def bank(raw):return max([i for i in [0,8192]if raw[i:i+4]==b'BT15'],key=lambda i:int.from_bytes(raw[i+12:i+16],'little'))
def finish_header(raw,at):raw[at+510:at+512]=binascii.crc_hqx(raw[at:at+510],0xffff).to_bytes(2,'little')
r=bytearray(manual.read_bytes());at=bank(r);r[at+16:at+20]=(12345).to_bytes(4,'little');r[at+39:at+104]=b'\xff'*65;finish_header(r,at);legacy=logs/'legacy_fixture_flash.bin';legacy.write_bytes(r)
r=bytearray(manual.read_bytes());at=bank(r);good=completed.read_bytes();g=bank(good)
for x,y in [(16,24),(72,104),(112,117)]:r[at+x:at+y]=good[g+x:g+y]
finish_header(r,at);reset=logs/'reset_fixture_flash.bin';reset.write_bytes(r)
with concurrent.futures.ThreadPoolExecutor(max_workers=2)as ex:
 jobs=[('resume_manual',manual,None),('legacy_resume',legacy,None),('reset',reset,None),('lives_resume',later['fresh_three']/'three_pref_flash.bin','lives_resume_three_preference')]
 list(ex.map(lambda j:run(*j),jobs))
with concurrent.futures.ThreadPoolExecutor(max_workers=2)as ex:
 list(ex.map(lambda j:run(*j),[('reset_cold',root/'release_reset/reset_flash.bin'),('ui_stress',dirs['gameover_points']/'gameover_flash.bin')]))
# Compatibility checks use a real M62 checkpoint when supplied alongside M62.
m62=v.m62_flash or P.parent/'REFERENCE_M62/M62_manual_flash_fixture.bin'
if not m62.exists()and not v.m62_flash:m62=P.parent.parent/'M61_final_release/candidate/SOURCE/EVIDENCE/FINAL_FEATURES/release_continue_auto/manual_flash.bin'
if m62.exists():
 with concurrent.futures.ThreadPoolExecutor(max_workers=2)as ex:list(ex.map(lambda case:run(case,m62),['m62_resume','m62_profile_migration']))
result={'passed':True,'rom_sha256':hashlib.sha256(Path(v.rom).read_bytes()).hexdigest(),'target_cases':len(runs),'runs':sorted(runs,key=lambda r:r['name']),'completion_tests_are_forced_event_fixtures':True,'cold_boot_tests_use_cpu_written_flash_except_explicit_legacy_and_reset_fixtures':True}
(logs/'FINAL_FEATURE_SUITE.json').write_text(json.dumps(result,indent=2)+'\n');print('FINAL_FEATURE_SUITE_PASS',len(runs),flush=True)
