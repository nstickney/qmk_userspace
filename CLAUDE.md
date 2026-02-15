# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

QMK userspace repository for `nstickney`, containing custom keymaps for two split keyboards:
- **Hidtech Bastyl** (Dactyl-style, primary)
- **Keebio Iris rev2** (may be outdated)

Shared user code lives in `users/nstickney/` and is used by both keymaps.

## Build Commands

This repo is an overlay on `qmk/qmk_firmware`. The QMK firmware checkout location is determined by `qmk config user.qmk_home`.

```bash
# Build and flash Bastyl firmware
qmk flash -kb hidtech/bastyl -km nstickney

# Build via make (delegates to QMK firmware Makefile with this repo as overlay)
make hidtech/bastyl:nstickney
```

The devcontainer (`.devcontainer/setup.sh`) clones QMK firmware to `/workspaces/qmk_firmware` and configures overlay_dir automatically.

## Architecture

### Layers (shared across both keyboards)

| Layer | Index | Purpose |
|-------|-------|---------|
| `BASE` | 0 | QWERTY with mod-tap keys |
| `SYMB` | 1 | Unicode symbols (US-International style) |
| `NUMP` | 2 | Numpad on both hands |
| `FCTN` | 3 | Function keys, arrows, media, RGB |

### Key files

- `users/nstickney/nstickney.h` — Keycode aliases (mod-tap, layer-tap), layer/tap-dance enums, unicode_names enum
- `users/nstickney/nstickney.c` — Tap dance logic, RGB per-layer colors, unicode map (~60 entries)
- `users/nstickney/rules.mk` — Enabled features: KEY_LOCK, RGBLIGHT, TAP_DANCE, UNICODEMAP, LTO. Has `INTROSPECTION_KEYMAP_C = nstickney.c` workaround for QMK issue #24530
- `users/nstickney/config.h` — Unicode mode (Linux/IBus), RGB sleep, disables unused features to reduce binary size
- `keyboards/hidtech/bastyl/keymaps/nstickney/keymap.c` — Bastyl keymap (4 layers)
- `keyboards/keebio/iris/keymaps/nstickney/keymap.c` — Iris keymap (4 layers, uses older RGB API)

### Mod-tap conventions

Custom aliases defined in `nstickney.h`:
- `CC_ESC` / `CC_QUOT` — Ctrl on hold, Esc/' on tap
- `AC_SLSH` / `AC_EQL` — Alt on hold, /​/= on tap
- `FC_BSLS` / `FC_MINS` — FCTN layer on hold, \​/- on tap
- `SC_LSPO` / `SC_RSPC` — Space Cadet Shift (tap sends parentheses)

### Tap dances

- `LOCKS` — 1 tap: GUI, 2: NumLock, 3: CapsLock, 4: ScrollLock
- `LAYERS` — 1 tap: Menu/App, 2: toggle NUMP, 3: toggle SYMB

## Code Style

- `.clang-format`: Google style, 4-space indent
- `.editorconfig`: UTF-8, 4-space indent (tabs for Makefiles)
- `.clangd`: Suppresses AVR/QMK-specific warnings for LSP

## CI

GitHub Actions (`.github/workflows/build_binaries.yaml`) delegates to shared QMK org workflows for building and publishing firmware on every push. Note: `qmk.json` has empty `build_targets`, so manual target specification is needed.
