import sys,re,json,random,struct,hashlib,argparse
from pathlib import Path
P=Path(__file__).resolve().parent;
ap=argparse.ArgumentParser();ap.add_argument('--baseline-rom',required=True);ap.add_argument('--baseline-map',required=True);ap.add_argument('--rom',required=True);ap.add_argument('--map',required=True);ap.add_argument('--out',required=True);ap.add_argument('--emulator',required=True,help='Path to pinned Ngpcraft_emulator checkout');o=ap.parse_args()
EMU=Path(o.emulator).resolve();sys.path.insert(0,str(EMU))
from core.native import NativeMachine
def machine(rom,mp):
 text=Path(mp).read_text();s={n:int(v,16)for n,v in re.findall(r'([_.A-Za-z][A-Za-z0-9_.$]*)\s+([0-9A-F]{4,6})\s+(?:f_[a-z]+|[A-Z_]+|platform_scan)',text)}
 link={n:int(v,16)for n,v in re.findall(r'(__[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})',text)}
 m=NativeMachine(Path(rom).read_bytes());m.set_timing_silicon();m.reset()
 if '__NativeRoadROM_START'in link:
  at=link['__NativeRoadROM_START'];size=link['__NativeRoadROM_END']-at;m.write(s['_render_work']+5892,m.read(at,size))
 return m,s
bs=[machine(o.baseline_rom,o.baseline_map),machine(o.rom,o.map)];rng=random.Random(0x1011989);counts={'road':0,'midpoints':0};times=[0,0]
def call(m,s,name,count=0):
 m.bus_write(0x6f,0x4e);st=m.cpu();st.pc=s[name];st.regs[0]=count;st.regs[7]=0x7ffc;st.iff_level=7;st.sr_raw=(st.sr_raw&~0x7000)|0x7000;m.write(0x7ffc,struct.pack('<I',0x200000));m.set_cpu(st);m.set_breakpoints([0x200000]);r,recs=m.run(100000,record=False);
 if r.stop_status!=40:
  at=next((i for i,t in enumerate(recs)if t.pc<0x5700),0);print('FIRST',[(hex(t.pc),bytes(t.raw[:t.raw_len]).hex(),[(hex(w.address),bytes(w.data[:w.size]).hex())for w in t.writes[:t.n_writes]])for t in recs[max(0,at-10):at+3]],flush=True)
  print('DEBUG',hex(s[name]),'count',count,'SP',hex(m.cpu().regs[7]),'tail',[(hex(t.pc),bytes(t.raw[:t.raw_len]).hex())for t in recs[-12:]],flush=True)
 assert r.stop_status==40,(name,r.stop_status,hex(r.stop_pc));return r.total_cycles
for j in range(400):
 projection=struct.pack('<712H',*(rng.choice([rng.randrange(65536),rng.randrange(0,400),rng.randrange(65400,65536)])for _ in range(712)));road=rng.randbytes(3200);count=rng.randrange(152);y=rng.randrange(-8,192);mask=rng.randrange(4)<<16;suppress=rng.randrange(4)==0;outs=[]
 for i,(m,s)in enumerate(bs):
  m.write(s['_stage_work']+1008,projection);m.write(s['_stage_work']+586,struct.pack('<HH',int(suppress),0));m.write(s['_d']+20,struct.pack('<I',mask));m.write(s['_a']+20,struct.pack('<I',0x7bc8));m.write(s['_vehicle_road_y'],struct.pack('<h',y));m.write(s['_render_work'],road);times[i]+=call(m,s,'.vehicle_road_rows_fast',count);outs.append(m.read(s['_render_work'],3200))
 assert outs[0]==outs[1],('road',j,count,y,mask);counts['road']+=1
for j in range(200):
 projection=rng.randbytes(1424);outs=[]
 for m,s in bs:
  m.write(s['_stage_work']+1008,projection);call(m,s,'_vehicle_midpoint_rows');outs.append(m.read(s['_stage_work']+1008,1424))
 assert outs[0]==outs[1],('midpoints',j);counts['midpoints']+=1
for m,s in bs:m.close()
Path(o.out).write_text(json.dumps({'passed':True,'controlled_fixture':True,'seed':'0x1011989','cases':counts,'road_cases_cover':'signed 16-bit projected edges, off-screen and partially visible rows, all 4 outer-marker masks and inner-marker suppression','road_fixture_cycles':{'baseline':times[0],'candidate':times[1]},'baseline_sha256':hashlib.sha256(Path(o.baseline_rom).read_bytes()).hexdigest(),'candidate_sha256':hashlib.sha256(Path(o.rom).read_bytes()).hexdigest()},indent=2)+'\n');print('PASS',counts)
