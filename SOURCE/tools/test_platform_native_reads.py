"""Compare actual Toshiba word-accessor code against V1.0.1 on boundary/range inputs."""
import argparse,hashlib,json,random,re,struct,sys
from pathlib import Path
ap=argparse.ArgumentParser();ap.add_argument('--emulator',required=True);ap.add_argument('--baseline-rom',required=True);ap.add_argument('--baseline-map',required=True);ap.add_argument('--rom',required=True);ap.add_argument('--map',required=True);ap.add_argument('--out',required=True);args=ap.parse_args()
sys.path.insert(0,str(Path(args.emulator).resolve()))
from core.native import NativeMachine
machines=[]
for rom,mp in [(args.baseline_rom,args.baseline_map),(args.rom,args.map)]:
 text=Path(mp).read_text();symbols={n:int(v,16)for n,v in re.findall(r'([_.A-Za-z][A-Za-z0-9_.$]*)\s+([0-9A-F]{4,6})\s+(?:f_[a-z]+|[A-Z_]+|platform_scan)',text)};links={n:int(v,16)for n,v in re.findall(r'(__[A-Za-z0-9_]+)\s+([0-9A-F]{4,6})',text)}
 m=NativeMachine(Path(rom).read_bytes());m.set_timing_silicon();m.reset();machines.append((m,symbols,links))
addresses=list(range(0x3a98,0x7001))+list(range(0x10000,0x1098a))+[0x22,0x23,0x7c874,0x7c875,0x1ffe00,0x1ffffc,0x1ffffe]
addresses+=list(range(0x3c70,0x3ca0))+list(range(0x48d0,0x4980))+list(range(0x5fa8,0x6018))
addresses+=list(range(0x7ffc,0x8080));addresses=sorted(set(addresses));addresses+=[p|0x1000000 for p in addresses[::59]]
rng=random.Random(0x102b);workspace=rng.randbytes(2776);stack=rng.randbytes(512);total=0
for stage in [1,5]:
 for m,s,l in machines:
  name='FastAxis'if stage==1 else'FastCat';at=l['__'+name+'ROM_START'];m.write(0x7600,m.read(at,l['__'+name+'ROM_END']-at))
  at=l['__PlatformScanROM_START'];m.write(s['_render_work']+2560,m.read(at,l['__PlatformScanROM_END']-at))
  m.write(s['_stage_work'],workspace);m.write(s['_stack'],stack);m.write(s['_vm_player_state'],b'\x23\x8f');m.write(s['_vm_platform_opcode'],b'\xdc\xfe')
  if stage==5:m.write(s['_stage_work']+2280,b'\xff'*256)
  m.set_breakpoints([0x200000])
 for address in addresses:
  outputs=[]
  for m,s,l in machines:
   m.bus_write(0x6f,0x4e);cpu=m.cpu();cpu.pc=s['.vr16'if stage==1 else'.cvr16'];cpu.regs[0]=address;cpu.regs[7]=0x7ffc;cpu.iff_level=7;cpu.sr_raw=(cpu.sr_raw&~0x7000)|0x7000;m.write(0x7ffc,struct.pack('<I',0x200000));m.set_cpu(cpu);r,_=m.run(100000,record=False)
   assert r.stop_status==40,(stage,hex(address),r.stop_status,hex(r.stop_pc));outputs.append(m.cpu().regs[3]&65535)
  assert outputs[0]==outputs[1],(stage,hex(address),outputs)
  if address==0x22:assert outputs==[0xa55a,0xa55a],outputs
  total+=1
 print('PASS native accessor stage',stage,'cases',len(addresses),flush=True)
for m,s,l in machines:m.close()
Path(args.out).write_text(json.dumps({'passed':True,'native_Toshiba_code':True,'baseline_sha256':hashlib.sha256(Path(args.baseline_rom).read_bytes()).hexdigest(),'candidate_sha256':hashlib.sha256(Path(args.rom).read_bytes()).hexdigest(),'cases':total,'coverage':'every source-table/header byte position, odd addresses, mutable holes, sparse-history boundary, special words, stack and 24-bit aliases'},indent=2)+'\n')
