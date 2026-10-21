# M64 Windows build launcher restoration

Extract the entire archive before building. Double-click **BUILD_MY_ROM.bat**
beside README_M64.md. Keep SOURCE, OUTPUT and DOCUMENTATION beside it.

The launcher builds the ordinary game **and** the hardware diagnostic image.
It uses Windows PowerShell 5.1, .NET and the Toshiba SDK already included in
SOURCE/T900. Windows 10/11 supplies the first two. No Python, WSL, Wibo,
compiler installation, network download or administrator rights is required
by the Windows build script. Build in a writable folder.

After a successful build:

- OUTPUT/Batman_M64_Final_4MB.ngc is the normal game.
- OUTPUT/Batman_M64_Final_HARDWARE_DIAG_4MB.ngc is the diagnostic game.
- SOURCE/OUTPUT contains the same newly compiled images.
- WINDOWS_BUILD_LOG.txt contains all compiler/linker/converter output.
- EVIDENCE/WINDOWS_BUILD/RESULT.json records both SHA256 hashes.
- EVIDENCE/WINDOWS_BUILD/normal and diagnostic hold the new link maps,
  S-records and absolute images.

Both ROMs are exactly 4,194,304 bytes. A build failure does not publish an
unfinished image or label the already-supplied release ROMs as newly built.
The console stays open so the error can be read. `--no-pause` suppresses
only the final keypress for automation.

## What was restored and corrected

M12R2 included BUILD_MY_ROM.bat; the M64 archive omitted it. This restores that
entry point and its native Toshiba/PowerShell workflow, updated to the complete
M64 source manifest. Copying the old BAT unchanged would omit newer source
files and diagnostic instrumentation.

The new builder uses the same C optimisation flags, object ordering, assembly
sources, hardware diagnostic modifications and cartridge layout as the
existing Linux builder. It builds in a fresh temporary workspace, uses
relative compiler paths to avoid legacy path parsing problems, checks tool
exit statuses, detects R6002 and other runtime failures, and requires fresh
nonempty outputs. All requested images must compile and pass validation
before the release OUTPUT files are replaced.

The converter checks S-record lengths/checksums, overlapping load images,
both NGPC ROM address windows, the Batman header, erased save/BIOS sectors,
RAM boundaries, alignment and the reserved native-code windows. It refuses
split overlay load images. Windows uses the original native Toshiba PE tools;
the Linux-specific header mapping is applied only by the existing Linux
compatibility route. SOURCE/T900 is not patched by this Windows builder.

PowerShell telemetry and update checks are disabled in the launcher's process
environment. The build script contains no network operations.

This change does not alter any game C/assembly source, assets, gameplay,
performance settings, save format or the supplied M64 ROM bytes.

## Validation scope

See EVIDENCE/WINDOWS_BUILD_RESTORATION for the clean-build log, measured hashes
and failure-test results. The full PowerShell build is exercised from a fresh
extraction in a directory containing spaces, with prebuilt ROMs removed.
Both clean builds reproduced the existing M64 release hashes exactly. The
checks also confirmed publication of the fresh images in both OUTPUT folders.

These automated checks run on Linux x86-64 with PowerShell 7.4.6 and the
already supplied, prepared Toshiba compatibility runner. They exercise the
PowerShell build orchestration, diagnostic patching, compiler arguments,
linking, new .NET converter, output publication and failure paths. They do
**not** constitute an execution test of cmd.exe, Windows PowerShell 5.1 or
the native Windows PE loader. No Windows desktop is available in this
environment. The script uses PowerShell 5.1/.NET Framework-compatible syntax
and APIs, but the Windows-native branch still needs confirmation on Windows.

Automatic approval review interrupted an initial test because the downloaded
PowerShell test runtime attempted Microsoft telemetry. The repeated tests set
Microsoft's documented POWERSHELL_TELEMETRY_OPTOUT=1 before launching it.
Neither that test runtime nor its download is required or included for Windows.

## Optional Windows verification and single-image builds

From the extracted top directory in Command Prompt, verify an **unchanged**
source tree against the published release hashes:

```bat
set POWERSHELL_TELEMETRY_OPTOUT=1
powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File SOURCE\tools\windows\build_windows.ps1 -VerifyRelease
```

After editing source, use BUILD_MY_ROM.bat normally; edited ROMs are allowed
to have new hashes. The optional `-VerifyRelease` flag deliberately rejects
different ROMs.

To rebuild one image only:

```bat
powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File SOURCE\tools\windows\build_windows.ps1 -Kind normal
powershell.exe -NoLogo -NoProfile -ExecutionPolicy Bypass -File SOURCE\tools\windows\build_windows.ps1 -Kind diagnostic
```

The original Linux/WSL2 command is unchanged:

```sh
cd SOURCE
python3 tools/build_final.py --clean --verify-release
```

It writes to SOURCE/OUTPUT. A modified source tree will naturally fail the
package's static SHA256SUMS verification; that integrity check is for the
unmodified download, not a restriction on editing the project.
