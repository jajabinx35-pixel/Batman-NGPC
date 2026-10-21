"""Check packaged M64 captures against M63, at matching original update indices.
Only the eight deliberately black outside-window palette words are excluded.
There are no HUD, scene, sprite or gameplay exclusions.
"""
from pathlib import Path
import argparse, csv, json, statistics, zlib
p=argparse.ArgumentParser()
p.add_argument('--baseline',type=Path,required=True,help='Directory with LEVEL1..5')
p.add_argument('--candidate',type=Path,required=True,help='Directory with LEVEL1..5')
p.add_argument('--output',type=Path,required=True)
a=p.parse_args();results=[]
for n in range(1,6):
    b=a.baseline/f'LEVEL{n}';c=a.candidate/f'LEVEL{n}'
    br=json.loads((b/'RESULT.json').read_text());cr=json.loads((c/'RESULT.json').read_text())
    assert br['passed']and cr['passed']and br['updates']==200 and cr['updates']>=200
    assert json.loads((b/'state_bytes.sha256.json').read_text())==json.loads((c/'state_bytes.sha256.json').read_text())[:200],f'Level {n} gameplay changed'
    size=br['surface_size'];assert cr['surface_size']==size
    bb=zlib.decompress((b/'surface_bytes.zlib').read_bytes());cc=zlib.decompress((c/'surface_bytes.zlib').read_bytes())
    for i in range(len(bb)//size):
        x=bb[i*size:(i+1)*size];y=cc[i*size:(i+1)*size]
        assert x[:4592]==y[:4592]and x[4608:]==y[4608:],f'Level {n} scene changed at presentation {i+1}'
    def mean(d):
        rows=list(csv.DictReader((d/'cpu_times.csv').open()))[:200]
        assert len(rows)==200
        return statistics.mean(float(r['gameplay_elapsed_ms'])+float(r['prepare_elapsed_ms'])for r in rows)
    results.append({'stage':n,'updates':200,'all_gameplay_states_equal':True,
                    'all_non_window_palette_surfaces_equal':True,
                    'excluded_surface_bytes':[4592,4608],
                    'M63_mean_gameplay_plus_prepare_ms':mean(b),
                    'M64_mean_gameplay_plus_prepare_ms':mean(c),
                    'baseline_rom_sha256':br['rom_sha256'],'rom_sha256':cr['rom_sha256']})
a.output.write_text(json.dumps({'passed':True,'hardware_verified':False,
 'comparison':'1000 unchanged original gameplay states; sound ON, stock emulated clock, identical update-indexed inputs. M64 is UI polish, not a gameplay speed claim.',
 'results':results},indent=2)+'\n')
print('PASS: 1000 gameplay states and all committed non-window-palette surfaces')
