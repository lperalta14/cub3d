*This project has been created as part of the 42 curriculum by anzarago, lperalta*

# cub3D

## Description

cub3D is a 42 graphics project inspired by the famous game Wolfenstein 3D. The goal of the project is to create a dynamic first-person view inside a maze using the raycasting technique.

The project focuses on:

- Real-time rendering
- Raycasting mathematics
- Event handling
- Parsing and validation
- Memory management
- Graphics programming with MiniLibX / MLX42

The player can move through a 2D map rendered as a pseudo-3D environment with textured walls, floor and ceiling colors, and smooth camera movement.

## Features

### Mandatory Part

- Raycasting engine
- Directional wall textures (North, South, East, West)
- Floor and ceiling colors
- Keyboard movement with `W`, `A`, `S`, `D`
- Camera rotation with arrow keys
- `.cub` map parsing
- Map validation
- Error handling
- Proper memory management
- Clean window closing

### Bonus Part

- Minimap
- Mouse rotation
- Wall collision improvements

## Instructions

### Requirements

Before compiling the project, install:

- CC or Clang
- Make
- CMake
- GLFW
- OpenGL dependencies

### Linux Dependencies

Ubuntu / Debian:

```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libx11-dev libxext-dev libbsd-dev
```

### Compilation

Compile mandatory part:

```bash
make
```

Compile bonus part:

```bash
make bonus
```

Clean object files:

```bash
make clean
```

Remove all generated files:

```bash
make fclean
```

Recompile project:

```bash
make re
```

## Execution

Run the program with a valid `.cub` map:

```bash
./cub3D maps/example.cub
```

Example:

```bash
./cub3D maps/bunker.cub
```

## Controls

| Key | Action |
|------|--------|
| W | Move forward |
| S | Move backward |
| A | Move left |
| D | Move right |
| ← / → | Rotate camera |
| ESC | Exit program |

## Map Format

Example of a valid `.cub` file:

```txt
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png

F 220,100,0
C 225,30,0

111111111
100000001
101101001
1000N0001
111111111
```

### Valid Map Characters

| Character | Meaning |
|-----------|---------|
| 1 | Wall |
| 0 | Empty space |
| N/S/E/W | Player spawn |
| Space | Void area |

## Error Handling

The parser validates:

- Invalid map characters
- Invalid RGB values
- Missing textures
- Multiple player positions
- Open maps
- Invalid `.cub` files
- Incorrect map configuration

All errors return:

```bash
Error
<description>
```

## Technical Overview

The rendering engine uses the raycasting technique:

1. Rays are cast from the player position.
2. Wall intersections are calculated.
3. Distances determine projected wall height.
4. Texture slices are rendered vertically.

This creates a pseudo-3D environment from a 2D map.

## Resources

### Raycasting

- https://lodev.org/cgtutor/raycasting.html
- https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/

### MiniLibX / MLX42

- https://github.com/codam-coding-college/MLX42
- https://harm-smits.github.io/42docs/libs/minilibx

### Mathematics

- https://www.khanacademy.org/math/trigonometry

## AI Usage

AI tools were used as support during development for:

- Understanding raycasting concepts
- Reviewing parsing strategies
- Debugging specific issues
- Improving documentation
- Clarifying mathematical calculations

All generated content was reviewed, tested, and adapted manually before integration.

## Learning Outcomes

This project helped develop knowledge in:

- Graphics programming
- Real-time rendering
- Parsing and validation
- Memory management
- Mathematical projections
- Event-driven programming
- Structured C development
