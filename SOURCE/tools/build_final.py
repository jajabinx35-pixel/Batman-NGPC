"""Build M66 normal and diagnostic ROMs with automatic Toshiba preparation."""
from pathlib import Path
import argparse,subprocess,sys,hashlib,json
P=Path(__file__).resolve().parents[1]
a=argparse.ArgumentParser();a.add_argument('--clean',action='store_true');a.add_argument('--kind',choices=['both','normal','diagnostic'],default='both');a.add_argument('--verify-release',action='store_true');args=a.parse_args()
expected_file=P.parent/'DOCUMENTATION/FINAL_ROM_IDENTITIES.json';expected=json.loads(expected_file.read_text())if expected_file.exists()else{}
results=[]
for label,diag,name in [('normal',False,'Batman_M66_Anti_Farming_Normal_4MB.ngc'),('diagnostic',True,'Batman_M66_Anti_Farming_Diagnostic_4MB.ngc')]:
 if args.kind!='both'and args.kind!=label:continue
 evidence=P.parent/'EVIDENCE'/('M66_'+label.upper()+'_BUILD')
 cmd=[sys.executable,str(P/'tools/build_m12.py'),'--version','66','--build-dir',str(P/'BUILD'/label),'--output-name',name,'--evidence-dir',str(evidence)]
 if diag:cmd.append('--diagnostic')
 if args.clean:cmd.append('--clean')
 subprocess.run(cmd,cwd=P,check=True)
 data=(P/'OUTPUT'/name).read_bytes();digest=hashlib.sha256(data).hexdigest()
 if args.verify_release and expected.get(label,{}).get('sha256')!=digest:raise SystemExit('Accepted release hash mismatch: '+name)
 results.append({'kind':label,'file':name,'bytes':len(data),'sha256':digest})
(P.parent/'EVIDENCE/M66_BUILD_RESULTS.json').write_text(json.dumps({'passed':True,'clean':args.clean,'results':results},indent=2)+'\n')
print('BOTH ROMS READY'if args.kind=='both'else 'ROM READY',flush=True)
