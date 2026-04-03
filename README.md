*This project has been created as part of the 42 curriculum by bolegari, bnanque.*

# Cub3d
A 42 project: a first‑person raycaster using miniLibX (MLX42), inspired by Wolfenstein 3D. The program reads a `.cub` scene, parses configuration (textures and colors), validates the map, and renders a 3D maze using ray‑casting.

## Description
**Specification goals (cub3d.pdf)**
1. Graphically represent the inside of a maze in first‑person perspective.
2. Display different wall textures depending on wall direction (N, S, E, W).
3. Allow configuration of floor and ceiling colors.
4. Handle movement/rotation input and cleanly exit.

**Libraries and constraints**
1. miniLibX is required (this project uses `MLX42` in `minilibx-linux`).
2. `libft` is allowed.
3. Allowed external functions (summary): `open`, `close`, `read`, `write`,
   `printf`, `malloc`, `free`, `perror`, `strerror`, `exit`, `gettimeofday`,
   math library (`-lm`), and miniLibX functions.
   
## Instructions
**Build**
enter the project folder then
```bash
make
make bonus
```

**Run**
```bash
./cub3d ./maps/example1.cub
./cub3d_bonus ./maps/example1.cub
```

**Controls (per PDF)**
1. `W`, `A`, `S`, `D`: move the player.
2. Left/Right arrows: rotate the camera.
3. `ESC` or window close button: exit cleanly.

## `.cub` File Format
The scene file ends with the map and may list elements in any order (except the
map, which must be last). Different element blocks must be separated by one or
more empty lines.

**Required elements**
1. Textures:
   - `NO ./path_to_north_texture`
   - `SO ./path_to_south_texture`
   - `WE ./path_to_west_texture`
   - `EA ./path_to_east_texture`
2. Colors:
   - `F R,G,B` (floor)
   - `C R,G,B` (ceiling)

**Minimal example**
```text
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

## Map Rules (PDF)
1. The map may only use: `0` (empty), `1` (wall), and `N/S/E/W` (player start).
2. The map must be closed by walls; otherwise the program must error out.
3. Spaces inside the map are valid and must be handled by parsing.
4. The map must be parsed exactly as written in the file.

## Parsing in This Project

High‑level flow:
1. Read the `.cub` file and split config from the map.
2. Validate and store textures (`NO/SO/WE/EA`) and colors (`F/C`).
3. Extract the map grid and validate characters and closure.
4. Ensure exactly one player and initialize position/direction.

If any configuration or validation fails, the program exits and prints
`Error\n` followed by an explicit message.

## Project Structure

Main modules:
1. `src/parser/`: file reading, parsing, and validations.
2. `src/exec/`: ray calculations and wall rendering, key handling and player updates, window init, main loop, shutdown and shading, assets, and helpers.
3. `src/bonus/`: files responsible for the bonuses.

## Bonus
The mandatory part of the project was implemented and just 3 out of 5 bonuses was done: Wall collisions, a minimap system and rotate the point of view with the mouse.

## Resources
**Classic references**
1. miniLibX / MLX42 documentation.
2. Ray‑casting tutorial (e.g., Lode Vandevenne).
3. `.cub` map format and parsing guides.

**AI usage**
1. AI helped review clarity of instructions and requirements.
2. AI was used to understand core 3D graphics concepts (ray‑casting and related).
3. AI assisted in creating and adjusting project maps.
