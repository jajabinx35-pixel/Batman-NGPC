# Legacy Toshiba PE preparation

The included `../wibo-compat` is the same pinned runner used for the accepted
M61 baseline. It already contains the previously documented Windows-path shim
(`path_compat.s`). Its SHA-256 is checked before every build. Upstream is Wibo
1.2.0: https://github.com/decompals/wibo/releases/tag/1.2.0.

`prepare_runner.py` restores the original full-package SDK preparation. It
copies `T900/` to a project-specific temporary directory and maps each PE file's
headers with a read-only `.hdr` section. The original tools are untouched.
The transformation matches the earlier preparation script exactly.

Run `python3 tools/build_final.py --clean --verify-release` from the project root.
Both normal and diagnostic builds prepare the SDK automatically. The standalone
preparer is optional and uses the same compiler lock:

```sh
python3 tools/linux_runner/prepare_runner.py
```
