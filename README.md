*This project has been created as part of the 42 curriculum by cdahne, fschnorr.*

# cub3D

## Description
`cub3D` is a small 3D-like rendering engine written in C with MiniLibX.

Project goal:
- Learn core graphics and game-loop concepts through a raycasting renderer.
- Parse and validate `.cub` map files.
- Render textured walls and allow real-time player movement in a grid-based world.

In short, the program reads a map description, initializes textures/colors/player state, then renders a first-person view at runtime.

## Features
- Raycasting-based wall rendering.
- Texture loading for `NO`, `SO`, `WE`, `EA` wall directions.
- Floor and ceiling RGB color parsing (`F` and `C`).
- Map validation (required identifiers, one spawn, closed map checks).
- Player movement with collision handling.

## Instructions
### Prerequisites
- Linux (X11 environment).
- `cc`, `make`.
- X11 and MiniLibX dependencies (see setup targets below).

### Build
1. Download minilibx-linux.tgz and extract into `./lib` using `tar -xvf minilibx-linux.tgz`.
2. Compile the project:
```bash
make
```

This produces the executable `./cub3D`.

### Run
```bash
./cub3D assets/maps/basic.cub
```

You can use any valid `.cub` file, for example:
- `assets/maps/example.cub`
- `assets/maps/map.cub`
- `assets/maps/quad.cub`

### Controls
- `W` / `S`: move forward / backward
- `A` / `D`: strafe left / right
- `Left Arrow` / `Right Arrow`: rotate camera
- `ESC` or window close: quit

### Useful targets
- `make debug`: build and open in `gdb`.
- `make valgrind ARG="assets/maps/basic.cub"`: run with leak checks.
- `make re`: full rebuild.

## Map Format (Quick Reference)
A valid `.cub` file must include:
- Texture identifiers: `NO`, `SO`, `WE`, `EA`
- Color identifiers: `F` and `C`
- A map using only valid tiles (`0`, `1`, `N`, `S`, `E`, `W`, and spaces)
- Exactly one player start position
- A map enclosed by walls

## Project Structure
- `src/`: core implementation (init, parsing, validation, player, raycasting, drawing)
- `include/`: headers and project structs
- `assets/`: example maps and textures
- `lib/libft/`: custom C utility library
- `lib/minilibx-linux/`: MiniLibX
- `_docs/en.subject.pdf`: 42 subject document

## Resources
Classic references:
- 42 subject file: `en.subject.pdf`
- MiniLibX reference: https://harm-smits.github.io/42docs/libs/minilibx
- Permadi Ray Casting Tutorial: https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

AI usage disclosure:
- Project development followed the official 42 AI Instructions as provided by the 42 subject file.
- AI was used to draft and structure this `README.md`.
- AI support in this update was limited to documentation tasks (wording, sectioning, and command clarity).
