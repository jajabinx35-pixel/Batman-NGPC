"""Choose the public startup screen using controller buttons, never RAM writes."""
def runtime_choice(lua, symbols, runtime='emulation'):
    if '_hardware_mode' not in symbols:
        return lua
    target = 0 if runtime == 'hardware' else 1
    return lua + '''
local runtime_mem=manager.machine.devices[':maincpu'].spaces.program
local runtime_keys=manager.machine.ioport.ports[':Controls'].fields
local runtime_age=0
emu.register_frame_done(function()
 if runtime_mem:read_u8(MODE)==17 and runtime_mem:read_u16(DISPLAY)>0 then
  runtime_age=runtime_age+1
  runtime_keys['Button A']:set_value(0);runtime_keys['Down']:set_value(0)
  if runtime_age==4 then manager.machine.screens[':screen']:snapshot(os.getenv('BATMAN_OUT')..'/startup_mode.png')end
  if runtime_age>=32 and (runtime_age%16)<4 then
   if runtime_mem:read_u8(CHOICE)~=TARGET then runtime_keys['Down']:set_value(1)
   else runtime_keys['Button A']:set_value(1)end
  end
 end
end)
'''.replace('MODE',str(symbols['_screen_mode'])).replace('DISPLAY',str(symbols['_display_frames'])).replace('CHOICE',str(symbols['_ui_choice'])).replace('TARGET',str(target))
