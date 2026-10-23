# Building Batman NGPC v1.0.2 from source

The source and build scripts are provided, but the separately licensed **Toshiba TLCS-900** toolchain is **not** redistributed in this GitHub package. Historical compiled compatibility executables also are not included. The prebuilt release ROMs are published separately on GitHub Releases.

## Windows 10/11

1. Clone/download and extract this repository.
2. Supply your own lawfully obtained compatible Toshiba compiler under `SOURCE\T900\`, including `BIN\cc900.exe`, `BIN\asm900.exe`, `BIN\tulink.exe`, `BIN\tuconv.exe`, together with its `LIB` and `INCLUDE` directories.
3. Run `BUILD_MY_ROM.bat` from the root; it calls `SOURCE/tools/windows/build_windows.ps1`.
4. Read `WINDOWS_BUILD_LOG.txt`. Successful builds should produce `OUTPUT/Batman_V1.0.2.ngc` and `OUTPUT/Batman_V1.0.2_Diags.ngc`.

A native Windows rebuild **has not been executed** from this repackaged, compiler-excluded source. The provided ROM hashes refer to the original supplied v1.0.2 binary release.

## Linux / WSL2

The historical `SOURCE/tools/build_final.py` builds used a pinned legacy executable runner and the licensed Toshiba toolchain. These are not included; do not expect a fresh checkout to build without adding compatible, lawful versions. `--verify-release` requires a byte-identical toolchain.

## Verify prebuilt release ROMs

Use the checksums in [`DOCUMENTATION/FINAL_ROM_IDENTITIES.json`](DOCUMENTATION/FINAL_ROM_IDENTITIES.json). Each ROM must be 4,194,304 bytes. See [v1.0.2 technical validation](DOCUMENTATION/V1.0.2_BUSY_SCENES_AND_TESTS.md) for the test scope and limitations.
