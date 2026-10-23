# Batman: The Movie — NGPC v1.0.2

**Updated Neo Geo Pocket Color fan port (unofficial, non-commercial).** All five stages remain present, including the M66 scoring/anti-farming work and v1.0.1 improvements.

## What's changed since v1.0.1

- Faster **enemy/actor processing in platform stages 1 and 5**, particularly crowded scenes. The same enemy AI, hit detection, placement, graphics, scrolling and sound timing are retained.
- Optimised actor preflight, projectile-to-actor scans, drawing boundary and immutable animation-table word reads.
- On the project's pinned NGPCraft emulator, matched 300-update diagnostic replays with sound ON completed with **12.21% more update throughput in stage 1** and **12.63% more in stage 5** vs v1.0.1. Other three stages' measured cadence was unchanged. These measurements do **not** establish the same gain on physical hardware, or a constant 60 FPS.
- Gameplay and rendered state in the sampled 300-update test routes matched v1.0.1; this is not a claim that every possible game state or full campaign was tested.
- Save format, scoring/QR payload format, music and artwork remain unchanged from v1.0.1.

## Download choices

- **`Batman_v1.0.2.ngc`** — normal playable 4 MiB ROM; recommended one-click download.
- **`Batman_NGPC_v1.0.2_Release.zip`** — game ROM, separate developer diagnostic ROM, printable manual/case designs, and cinematic trailer.
- **`Source code (zip)`** — GitHub-generated source archive for this tagged commit; contains source but **not** the separately licensed Toshiba TLCS-900 compiler.

## Before you play

- The normal ROM is for play. The diagnostic ROM is for fixed performance replays and analysis.
- Existing saves are intended to remain compatible, but make a backup before changing ROMs or flash cartridges.
- Per-stage QR leaderboard submission requires support from the recipient website; online acceptance has not been independently confirmed.
- Hardware performance can vary. No new physical-console benchmark for v1.0.2 is claimed.

## Credits and rights

Port and testing: **jajabinx35-pixel**, with extensive AI programming assistance. The Amiga disassembly by **[MarkyTurtle](https://github.com/MarkyTurtle/Batman---Amiga)** provided a foundational reference. Mark has welcomed reuse of his own published work and is credited in-game.

Batman and original game rights belong to their respective owners; this fan project is not endorsed by them, and permission from the disassembly author does not independently grant rights to the original assets.

## Integrity (SHA-256)

```text
eff0a8225fe7e3c2cd820896956dc28981b3e4f2da409ddee3eeea852222cdc6  Batman_v1.0.2.ngc
4bb00a169a8e976cc9ab660e1d80624b5b94b590c9d2f68043484a0b20f75756  Batman_v1.0.2_Diagnostic.ngc
```

These ROM hashes match the uploaded v1.0.2 release manifest. They have not been rebuilt independently from the toolchain-excluded public repository package.
