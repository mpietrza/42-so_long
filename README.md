# 42 so_long 🎮

> Summary: Implementation of the 42 `so_long` project in C using MiniLibX on Linux. The program loads a `.ber` map, validates it, opens a small 2D window, and lets the player collect every collectible before reaching the exit. The implementation focuses on map correctness, path validation, clean resource management, and simple tile-based gameplay.

---

## 📁 Repository layout (root)
- Makefile
- image.png
- include/ (public headers)
- libft/ (local libft dependency, `ft_printf`, `get_next_line`)
- maps/ (valid and invalid test maps)
- mlx/ (bundled MiniLibX for Linux)
- srcs/ (source files)
- textures/ (game assets)

---

## 📂 srcs/ (actual files)
The game logic, parsing, rendering, and cleanup are implemented in `srcs/`:

- cleanup.c
- exit.c
- flood_fill.c
- init_map.c
- initialize.c
- map_check_path.c
- map_check_scan.c
- map_find_start_pos.c
- map_parse.c
- move.c
- put_textures.c
- so_long.c
- utils.c

Key entrypoint: `srcs/so_long.c`

---

## ✅ Features
- 2D tile-based game built in C
- Uses MiniLibX with X11 on Linux
- Loads textures for:
  - player facing up
  - player facing left
  - player facing down
  - player facing right
  - background
  - wall
  - collectible
  - exit
- Robust map validation:
  - accepts only `.ber` files
  - checks rectangular shape
  - checks the map is closed by walls
  - checks allowed symbols only: `0`, `1`, `C`, `E`, `P`
  - requires exactly 1 player
  - requires exactly 1 exit
  - requires at least 1 collectible
  - verifies reachability with flood fill
- Movement handling with keyboard input
- Prevents entering the exit before collecting all collectibles
- Prints the movement counter to stdout
- Cleanup for allocated memory, images, window, and display resources
- Includes both valid and invalid sample maps for testing

---

## 🎮 Controls
- `W` / `↑` — move up
- `A` / `←` — move left
- `S` / `↓` — move down
- `D` / `→` — move right
- `Esc` — quit the game

---

## 🗺️ Map format
Each map must use the `.ber` extension and may contain only:

- `1` — wall
- `0` — empty floor
- `C` — collectible
- `E` — exit
- `P` — player start

### Required rules
- The map must be rectangular.
- The map border must be entirely walls.
- There must be exactly one `P`.
- There must be exactly one `E`.
- There must be at least one `C`.
- All collectibles must be reachable from the player start.
- The exit is only useful once all collectibles are gathered.

---

## 🔧 Build
From repository root:
```bash
make         # build so_long and its local dependencies
make clean   # remove object files
make fclean  # remove object files and executable
make re      # rebuild everything
```

The root `Makefile` also builds:
- `libft/`
- bundled MiniLibX from `mlx/`

---

## 🚀 Usage
Basic usage:
```bash
./so_long maps/map1.ber
```

Other sample playable maps are available in `maps/`, for example:
```bash
./so_long maps/map2.ber
./so_long maps/map3.ber
./so_long maps/map4.ber
```

The repository also includes intentionally invalid maps that are useful for validation testing.

---

## 🧪 Testing & Debugging Tips
- Start by running a known valid map such as `maps/map1.ber`.
- Test invalid maps from `maps/` to confirm parsing and error handling.
- Verify edge cases:
  - wrong file extension
  - non-rectangular maps
  - missing player / exit / collectibles
  - multiple players or exits
  - unreachable collectibles
- Use sanitizers or `valgrind` while developing to check for leaks.
- If MiniLibX fails to open a window, verify your X11 environment and libraries.

---

## 📌 Error handling rules
The program exits with an error when:
- the argument count is wrong
- the file cannot be opened
- the file extension is not `.ber`
- the map contains invalid symbols
- the map is not rectangular
- the map is not closed by walls
- there is not exactly one player
- there is not exactly one exit
- there are no collectibles
- there is no valid path through the map
- initialization of MLX, textures, window, or memory allocation fails

---

## 🧠 Implementation notes
- `so_long.c` contains the main flow, event hooks, and startup logic.
- `map_parse.c` reads the map and performs rectangular checks.
- `map_find_start_pos.c`, `map_check_scan.c`, and `map_check_path.c` validate map content and reachability.
- `flood_fill.c` performs path validation.
- `initialize.c` loads textures and initializes the main game state.
- `put_textures.c` renders the background, objects, and player.
- `move.c` handles movement, collectible pickup, and movement counting.
- `cleanup.c` and `exit.c` handle shutdown and error exits.
- Utility code relies on the local `libft/` implementation.

---

## 🖼️ Assets
Textures are stored in `textures/` as both `.xpm` and `.png` files. The game loads the `.xpm` versions through MiniLibX.

---

## 🎯 Learning outcomes
- Event-driven programming in C
- Basic 2D rendering with MiniLibX
- File parsing and strict validation
- Flood fill/pathfinding for gameplay constraints
- Resource cleanup and defensive memory handling
- Building small graphical projects on Linux with X11
