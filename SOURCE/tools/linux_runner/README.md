# Legacy Linux/WSL toolchain runner

The historical development build used Wibo 1.2.0 with a project-specific Windows-path shim, plus a separately licensed Toshiba TLCS-900 toolchain. Those compiled executables and the Toshiba SDK are **not included** in this public GitHub package.

The source/scripts are retained for reference; do not expect `tools/build_final.py` or `prepare_runner.py` to succeed on a fresh checkout without providing compatible lawful dependencies.

Wibo upstream: https://github.com/decompals/wibo/releases/tag/1.2.0

For native Windows builds with a lawfully obtained Toshiba toolchain see the repository's `BUILDING.md`.
