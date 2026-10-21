# Reusable NGPC port optimization handover and ChatGPT template

This guide describes techniques **present in the supplied Batman M61 baseline**, the independent M62 investigation and a repeatable workflow for future ports. It does not invent per-technique speedups or imply that every optimization below was newly written in M62. Historical version numbers are not reliable performance evidence unless their exact ROMs, sources and tests are available.

## 1. Start with a reproducible accepted baseline

Keep the accepted source archive, its SHA-256, normal ROM, diagnostic ROM and matching linker maps together. Compile from clean source before editing. Require byte-identical output where the toolchain is deterministic. Preserve the original toolchain and fix its runtime setup in a temporary copy; do not silently replace compiler binaries or switch ABI.

For this Batman handover, M61 normal/diagnostic rebuilt byte-identically. Toshiba cc900 runs through a pinned Wibo-compatible runner after the documented PE header mapping. The builder rejects compiler errors even when a legacy tool exits zero, overlapping S-records, unexpected split overlays, out-of-window output and collisions with cartridge save/BIOS sectors.

Never optimize an obsolete fork when a later accepted build already contains caching, native kernels, audio or save fixes. Record exactly which files change. The final source manifest should make unrelated engine/artwork edits visible.

## 2. Separate four different rates

- Display refreshes are the physical/emulated LCD clock.
- Simulation updates are actual executions of game logic; original translated routines may also return while waiting for a continuation.
- Source-complete gameplay steps are useful if a VM can yield mid-frame.
- Presents are completed graphics frames committed to display memory.

Count all of them. Report rates over the same measurement interval and expose maximum gaps and a histogram. A game which does more presentation without doing its original collision/enemy work is not equivalent. A diagnostic called `300 steps` specifies the fixed work count, not an overclock option.

Clock measurements from VBlank/RTC or emulated machine time, not host wall-clock throughput. `-nothrottle` can accelerate execution of the regression harness on the host while preserving emulated clock ratios; it must not change CPU clock settings. Do not convert a MAME processing interval into physical NGPC FPS. This project's old hardware photos remain historical observations and cannot establish the performance of the new build.

## 3. Profile the translated gameplay before rewriting it

Translated Amiga code can spend time in address mapping, virtual register access, condition flags, memory endian conversion, call dispatch, table scans and callback boundaries. The biggest-looking C function is not automatically the most expensive target. Place low-overhead phase tags around complete root operations and time those tags independently with emulator bus taps. Make instrumentation an isolated, non-shipping build.

Batman vehicle updates have 13 ordered roots. The M62 investigation found scene preparation, road work and native edge work dominant. The phase-instrumented build matched every one of 200 captured gameplay states and committed surfaces in both vehicle stages. The tag overhead means these are bottleneck estimates, not exact uninstrumented cycle allocations.

Preserve root order, emulated register results, flags, memory writes, timer behaviour and audio service points. Before replacing a loop, specify its input range, accepted/rejected cases and exact continuation state. Keep fallback handling for unusual pointers or stack frames.

## 4. Exact native batching, not omitted work

Batman already includes native replacements for several expensive translated boundaries:

- `platform_scan.c` batches rejected spawn/hazard entries and empty projectile slots while retaining the same accepted-entry path and published registers/flags.
- `platform_stack.asm` handles known source draw-stack frames with the required word order/sign extension; unusual cases retain ordinary mapping.
- `vehicle_road_native.asm`, `vehicle_rows_all.asm`, `vehicle_edges_native.asm` and associated kernels reduce repeated virtual callbacks by processing identical samples in a batch.
- `fast_memory.asm` and the fast-axis/cathedral/vehicle overlays avoid repeated generic mapping in hot paths.

For another game, choose a measured, semantically closed operation. Compare all output registers, source flags, RAM bytes and continuation addresses against the original on normal and boundary inputs. Reading every empty entry more cheaply is safe; inspecting only some entries every other update changes behaviour. Avoid moving audio service points far enough apart to cause underruns.

A word access is not always faster. In this final pass, native-word plus byte-swap replacements produced about 1.64% and 1.95% gains in platform-stage processing intervals and zero in vehicles. They were rejected because the requested gain was substantial. The accepted memory-access header was restored. Always compare compiler output and target measurements; do not select a trick merely because it sounds lower-level.

## 5. Prepare graphics offline in the target format

NGPC is a tile/sprite machine; copying an Amiga framebuffer representation into runtime conversions wastes work. Batman's native renderer uses prepared 2bpp tiles, palettes, frame metadata, pre-shifted rows, masks, scene recipes and residency information. Platform and vehicle assets have different pipelines; forcing one generic renderer on all stages can lose performance.

Move deterministic work out of gameplay: planar unpacking, resampling, color selection, transparency masks, tile extraction/deduplication and position-independent row variants. Preserve original artwork and animation identities. Include a generator or enough source data to regenerate the tables. Measure ROM growth against the real cartridge windows and flash reserves, not just the rounded output file size.

Use pre-shifted data only where ROM savings/time tradeoffs are measured. Handle every sub-tile alignment, negative clipping coordinate, flip, palette change and boundary row. A lookup table can be slower if it increases far-pointer arithmetic or cartridge reads enough to outweigh saved arithmetic.

## 6. Reuse work at three separate layers

1. **Prepared image reuse:** reuse native pattern/mask data instead of re-decoding a repeated source frame.
2. **Residency reuse:** retain known tile contents in pattern memory and update tile-map/sprite references.
3. **Transfer reuse:** compare completed data and write only changed VRAM words/regions.

They are not interchangeable. A high tile-cache hit rate can coexist with slow scene preparation. A diff uploader can reduce writes while still reading/scanning the whole surface expensively. Track pattern reads, pattern writes, descriptor bytes, conversions avoided and elapsed processing time independently.

Batman examples include `platform_residency.inc`, `native_residency.inc`, `native_frame_stamp.asm`, `native_stamp_rows`, the background atlas/scene recipe tables and `graphics_diff.asm`. Cache keys must include all data which affects output: source frame, animation state, palette/ink interpretation, scale, flips, alignment and clipped coverage where relevant. Never use a weak hash without validating collisions or a generation marker. Reset caches on stage entry, save restore, palette mode change and scratch-buffer reuse. A QR/menu may reuse a renderer buffer only while the renderer is idle and must restore the next mode's graphics state.

## 7. Let hardware layers do stable compositing

A static or slowly moving skyline can be installed once in a background plane and scrolled by registers. It does not need to be re-stamped into the road buffer every update. Batman's vehicle background uses a hardware map and palettes behind the road plane; transparency ink and plane priority determine the final scene. These choices preserve original sky/city artwork while reducing software compositing.

For another port, prove the required layer order at overlaps, occlusion edges and camera transitions. A black opaque pixel and transparent pixel are different even if a screenshot against black looks the same. Pause/menu transparency and QR plane cleanup are part of this contract. Sparse stars/projectiles can use existing prepared patterns or palette edits if allocation and scanline limits permit; do not add a per-pixel software background animation for a decorative effect.

## 8. Commit complete graphics frames

Prepare the next frame in the existing staging workspace. Publish a ready flag only when tile data, maps and sprite descriptors agree. Commit at the intended VBlank boundary and release the buffer only after display ownership ends. Never overwrite a buffer still being presented. Track missing frames, sprite overflows and maximum present gaps.

VRAM transfer reduction must account for correct invalidation. If a sprite count falls, clear old descriptors. If tile residency is reset, invalidate cached references. If a menu borrows pattern memory, reinstall gameplay fonts/palettes/maps on return. A faster partial frame with stale tiles is a regression even when average FPS improves.

## 9. Treat RAM as a set of owned windows

Write a memory map before adding caches. In this Batman build the ordinary game allocation must end before 0x6B60; graphics code and BIOS workspace occupy the following regions. PCM decoder/lookup occupy 0x7000–0x71FF; double audio buffers use 0x7200–0x75FF. Fast gameplay overlays use 0x7600–0x77BF, a clear kernel 0x77C0–0x77FF, and the native stack starts at 0x7800 with initial SP 0x8000. Rendering overlays share specific inactive portions of render workspace. These are project-specific ownership assignments, not free general-purpose NGPC RAM.

The builder checks linker-end symbols and individual overlay sizes. Fill the stack guard and measure its lowest overwritten address in busy gameplay, saving, menus and QR generation. Account for nested interrupt stack usage, compiler spills and local arrays. Never assume the linker alone proves stack safety. Preserve the documented interrupt priority when re-enabling interrupts inside an ISR.

## 10. Sampled audio: correct hardware first, then cost

This baseline feeds both DAC channels through Timer1→DMA0 using two 256-sample buffers. A completed DMA half requests one refill; playback switching belongs to the completion IRQ. Main-context service and the VBlank fallback use guarded ownership so they cannot decode the same half concurrently. A fast native decoder expands the palette/nibble block representation, mixes effects into the pending half and avoids an extra decoded-effect scratch pass. Z80 ownership is explicit in this implementation.

For another game, verify the actual DAC destination/channel, timer mode, transfer width/count, interrupt vector/priority and buffer alignment from target documentation before tuning a decoder. Check DAC sample range and expected sample cadence, not only that the emulator emits sound. Count underruns, refills per completion, decoder maximum duration and sound-OFF work. Matched sound ON/OFF replays can isolate overhead; different free-play sequences cannot.

Preserve sample rate and trigger order. Doubling playback frequency changes pitch and does not optimize the game. Increasing gain requires signed/unsigned centering and clipping checks. Keep audio clock independent of simulation throughput. M61's intro follows **actually played DMA blocks**, excluding the two prefilled halves; the visual clock therefore follows audible progress rather than assuming all hardware presents every frame.

## 11. Regression evidence which answers the question

For every proposed optimization:

- Freeze the control build and input stream. Select stages through actual UI or explicitly label a fixture.
- Compare complete gameplay-state bytes at the same update indices, including private state where needed.
- Compare resolved committed graphics, not only pattern indices that may change under a residency cache. Account only for documented intended differences such as a new score HUD. Do not mask an entire screen to hide regressions.
- Keep raw processing intervals, presents, VRAM bus counters and exact ROM/map hashes.
- Test sound ON/OFF, stage changes, save restore, unusual clipping/scroll boundaries and full stress scenes.
- Record whether a completion was naturally played or forced by a test fixture. A forced boss-complete event tests the autosave/records handler, not game solvability.
- Independently validate diagnostics against bus taps and an independent clock. Independent QR decoding should inspect the actual generated LCD image, not only a host-side library.

LCD screenshots can differ due to temporal phase/presentation timing even when committed graphics surfaces match. Investigate the difference; do not claim pixel equality without checking it. Likewise identical screenshots do not prove equivalent AI/collision.

Use the actual physical console as the deciding performance test. Quote uncertainty and retain a regression path. Reject a change which breaks a feature, shifts game timing, compromises audio or fails the user's practical gain threshold.

## 12. Knowing when to stop

A profiler does not prove a global mathematical maximum. A defensible stopping point is: the remaining expensive phases are identified; plausible equivalence-preserving changes were measured; meaningful candidates failed or regressed; the accepted engine's behaviour remains intact; and the owner is satisfied with physical-console play. State which experiments were tried and which expensive regions remain. Do not call a 1% gain a breakthrough or claim a missing-art speed experiment as a valid port.

The M62 decision was to retain M61's engine and reject the small memory-access gain. Native scene preparation and road/edge processing remain candidates for deeper future redesign. Such work needs new correctness proofs and physical measurements, not a promise of a particular percentage.

## Copy/paste task template for a future port

```text
You are continuing an NGPC port. Use ONLY the accepted source ZIP and ROM hashes
listed below as the baseline. Preserve all existing graphics reuse, native kernels,
audio fixes, original game behaviour and saved-state compatibility where feasible.

Game and original reference: [name / source reference]
Accepted source ZIP and SHA-256: [path / hash]
Normal ROM SHA-256: [hash]
Diagnostic ROM SHA-256 and matching map: [hash / path]
Build command/toolchain: [command / compiler / runner versions]
Physical hardware/cart: [model / flash cartridge / stock-clock confirmation]
Known issues and intended art/UI changes: [list]
Required minimum practical improvement: [criterion]
Attached hardware measurements: [exact version, level, sound, route, refreshes,
real updates, presents, gaps, sprites, read/write bytes, underruns, repetitions]

First reproduce both accepted builds. Establish matched baseline input replays.
Inspect the complete linker map, ROM windows, flash reserves, overlay lifetimes,
interrupt ownership and native stack limits. Never guess free RAM.

Profile game logic/translated dispatch, address mapping, scene preparation,
road/edge work, conversion/cache lookup, VRAM reads/writes and audio separately.
Instrument an isolated profiling build and prove its gameplay/graphics match.
Select the largest measured bottleneck, then make one bounded equivalent change.
Prefer offline native assets, exact native batching, complete cache keys, tile
residency, hardware planes/scrolling and changed-only transfers where measured.
Keep every original update, physics rule, timer rate, enemy, collision, animation,
art asset, music cue, sampled effect and cutscene. No CPU overclock, speed-mode
multipliers or discarded gameplay to inflate results.

For each candidate, compare the unchanged baseline with the same stock-emulated
clock and inputs. Capture state at matched updates and resolved committed art.
Measure processing intervals, actual source-complete steps, presents, frame gaps,
VRAM activity, sprites, stack headroom and audio underruns. Test sound ON/OFF.
Reject regressions and changes below the agreed useful threshold. Distinguish
fixture-driven completions from naturally played clears. Do not certify physical
hardware using MAME results; supply a controlled console measurement checklist.

Deliver normal and diagnostic ROMs, full source, reproducible build entry point,
CRC-tested ZIP, SHA-256 manifest, raw compact evidence, accepted/rejected experiment
notes and clear remaining limitations. Preserve the accepted rollback. If no
substantial safe gain is verified, say so instead of inventing a maximum or gain.
If adding saves/records/QR, keep menu work outside gameplay; use idle scratch only
with explicit ownership, test cold boot and score eligibility, independently decode
an actual target-rendered QR and document any site-owner configuration still needed.
```


## M64 menu and QR presentation lesson

Keep full page construction on entry. A selector move or one-letter edit should update only its owned tile-map cells. Avoid reloading font patterns, clearing the entire map, hiding the viewport or rebuilding sprite state on each key. Configure the NGPC outside-window palette explicitly: a black backdrop alone does not guarantee a hidden viewport is black. Pad replacement text so short values erase old characters. Make the active editable field unmistakable with both a palette highlight and a position label.

Instrument the actual bus during stable edit periods. M64 tested 84 alphabet steps across three initial positions and counted zero viewport writes and zero pattern uploads over 1,940 checked refreshes. Exclude page entry/exit work explicitly. This is a UI-workload and blanking fix, not evidence of faster gameplay. It required no new static RAM; the diagnostic still had only nine bytes before its next overlay. Confirm persistence by a separate cold boot of CPU-written save sectors, and test both menu availability and actual rejection of invalid zero-score uploads.
