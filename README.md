# cub3D

> A 3D raycasting engine written in C, inspired by Wolfenstein 3D.

## About

cub3D is a graphics project developed as part of the 42 curriculum.
It renders a first-person view of a maze from a 2D map using raycasting.

The project focuses on real-time rendering, mathematical projections, map parsing, input handling and memory management.

## Features

- Raycasting-based 3D rendering
- Textured walls with directional textures
- Configurable floor and ceiling colors
- `.cub` map parsing and validation
- Player movement with collision detection
- Camera rotation
- Error handling and resource cleanup
- Bonus: minimap and mouse rotation

## Technologies

- **Language:** C
- **Graphics:** MLX42
- **Libraries:** Libft, GLFW, OpenGL
- **Build:** Make, CMake

## Installation

### Requirements

- GCC or Clang
- Make
- CMake
- GLFW and required OpenGL dependencies

On Ubuntu / Debian:

```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libx11-dev libxext-dev libbsd-dev
```

### Build

```bash
make
```

For the bonus version:

```bash
make bonus
```

## Usage

Run the program with a `.cub` map:

```bash
./cub3D maps/example.cub
```

### Controls

| Key | Action |
| --- | --- |
| `W` | Move forward |
| `S` | Move backward |
| `A` | Move left |
| `D` | Move right |
| `←` / `→` | Rotate camera |
| `ESC` | Exit |

## Architecture

```text
.cub map
   │
   ▼
Parsing & Validation
   │
   ▼
Game Initialization
   │
   ▼
Input Handling
   │
   ▼
Render Loop
   │
   ▼
Raycasting (DDA)
   │
   ▼
Wall Projection & Textures
```

The code is organized into modules for parsing, initialization, rendering, input handling and utilities.

## Authors

**Luis Peralta** · [GitHub](https://github.com/lperalta14) · [LinkedIn](https://www.linkedin.com/in/lperaltamu%C3%B1oz/)

**Ana Zaragoza** · 42 Málaga
