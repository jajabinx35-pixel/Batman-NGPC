# Building Batman NGPC from source

This repository includes the source and Windows build scripts but **does not distribute** the Toshiba TLCS-900 compiler. The original private development archive included a Toshiba package with a separate licence. You must supply your own lawfully obtained toolchain before rebuilding.

## Windows 10 / 11

1. Download / clone this repository.
2. Put your Toshiba TLCS-900 toolchain directory at `SOURCE\T900\` so that `SOURCE\T900\BIN\cc900.exe`, `asm900.exe`, `tulink.exe`, and `tuconv.exe` exist. Preserve its `LIB`/`INCLUDE` contents.
3. Double-click `BUILD_MY_ROM.bat` in the root (or run it from a Windows terminal).
4. Read `WINDOWS_BUILD_LOG.txt` for success/failure. The normal and diagnostic ROMs are intended to be written under `OUTPUT/`.

This re-packaged GitHub source without Toshiba binaries has not been freshly compiled on Windows. The included ROM binaries in the separate release package were taken unchanged from the validated supplied M66 archive; SHA-256 identities are in `DOCUMENTATION/FINAL_ROM_IDENTITIES.json`.

## Linux / WSL

The project's historical Linux Python scripts also expect external `linux_runner` and a suitable `wibo-compat` Windows-executable runner, which are not included. Do not assume that `python3 SOURCE/tools/build_final.py` runs on a fresh checkout without those requirements.

## ROM identity

The game and diagnostic ROM must each be **4,194,304 bytes**. The SHA-256 checksums in `DOCUMENTATION/FINAL_ROM_IDENTITIES.json` are the authoritative identities for this exact M66 source package. If you rebuild with a different toolchain, the hashes can differ.
