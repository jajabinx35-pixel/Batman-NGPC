# Batman: The Movie — NGPC v1.0.0 (M66)

First public release candidate for the complete five-stage Neo Geo Pocket Color fan port.

### Includes

- All five stages: Axis Chemicals, Batmobile, Batcave, Batwing and Gotham Cathedral.
- Cinematic introduction, music, sound effects, controls and pause/options screens.
- Save/continue, stage high scores, overall records and QR-code score display.
- Checkpoint anti-score-farming fix: replaying an already-credited checkpoint section after death cannot generate the same points again; only new progress adds points.
- A normal 4 MiB game cartridge image and separate 4 MiB diagnostic image.
- Printable manual and case insert and a trailer in the release ZIP.

### Important notes

- For ranked M66 scoring, start a new game after updating from an older save. Old records remain, so reset previously farmed records if you want a clean leaderboard.
- Runs using unlocked cheats or an ineligible initial lives setting cannot qualify for ranked score upload.
- The QR format needs support from the receiving leaderboard website; online acceptance of per-stage uploads is not confirmed.
- The normal ROM is for playing; the diagnostic ROM is for performance analysis.
- This is an unofficial, non-commercial fan port, not endorsed by the original rights holders.
- **Credit:** [MarkyTurtle's Amiga disassembly](https://github.com/MarkyTurtle/Batman---Amiga) was the foundation/reference for this AI-assisted NGPC port, and Mark is credited in the game.

### SHA-256

```text
f3068e05f59ca1c538e471d3679b12ca901936ddb1f9ccad56f5b12a94552858  Batman_M66_Anti_Farming_Normal_4MB.ngc
18ac92304507cea431f5e6f8c2e9c3a1f912fa7e18980a64ca8dc22b2c45e695  Batman_M66_Anti_Farming_Diagnostic_4MB.ngc
```

The existing normal/diagnostic ROMs are preserved unchanged from the supplied M66 ZIP; these checksums were verified when this package was prepared. The GitHub toolchain-excluded source has not been independently rebuilt from scratch.
