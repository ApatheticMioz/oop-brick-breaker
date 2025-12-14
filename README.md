# OOP Brick Breaker

A classic brick-breaker game built with C++ and OpenGL/GLUT, featuring object-oriented design principles including inheritance, polymorphism, and encapsulation. Originally developed as an OOP course assignment.

> **Status:** Archived / Refactored

## Description

This is a fully functional brick-breaker (Breakout-style) game that demonstrates core OOP concepts through gameplay entities like balls, bricks, paddles, and power-ups. The game features randomized brick patterns, angle-based ball physics, multiple power-up types, and multi-ball gameplay.

## Features

- **Two Level Layouts:** Dense grid and patterned spread with randomized brick colors
- **Physics System:** Paddle deflection adjusts ball trajectory using angle-based calculations
- **Five Power-Up Types:**
  - 🟢 Widen paddle
  - 🟣 Shrink paddle
  - 🔵 Slow balls
  - 🔴 Speed up balls
  - 🟡 Spawn extra balls
- **Multi-Ball Gameplay:** Extra balls expire after a few seconds
- **Life System:** Track lives with game reset on ball loss

## Project Structure

```
.
├── game.cpp      # Entry point, GLUT setup, render/update loop, input handlers
├── game.h        # Game class: state management, collision, power-ups, levels
├── ball.h        # Ball class: movement, rendering, static ball count
├── brick.h       # Brick class: health, color, static brick count
├── food.h        # Food (power-up) class: drop and collision logic
├── paddle.h      # Paddle class: position, size, rendering
├── abstract.h    # Base classes: Object and movingObject
└── util.h        # (Required) Course-provided OpenGL/GLUT utilities
```

## Installation

### Prerequisites

- C++ compiler (g++, clang++, or MSVC)
- OpenGL development libraries
- GLUT/freeglut development libraries
- Course-provided `util.h` and `util.cpp` (not included)

### Build

**Linux (with freeglut-dev):**

```bash
g++ game.cpp -o breakout -lglut -lGL -lGLU -lm
./breakout
```

**Windows (MinGW + freeglut):**

```bash
g++ game.cpp -o breakout -lfreeglut -lopengl32 -lglu32
./breakout
```

> **Note:** Adjust library flags/paths as needed for your toolchain. If `util.cpp` is supplied separately, include it in the compilation.

## Usage

### Controls

| Key | Action |
|-----|--------|
| `1` | Start Level 1 |
| `2` | Start Level 2 |
| `3` | Start Level 3 (placeholder) |
| Mouse | Move paddle horizontally |
| `Esc` | Quit game |

### Gameplay

1. Press `1` or `2` to start a level
2. Move your mouse to control the paddle
3. Deflect the ball to break bricks
4. Catch falling power-ups to gain advantages
5. Don't let the ball fall below the paddle!

## Technical Details

- **Language:** C++
- **Graphics:** OpenGL/GLUT
- **Architecture:** Object-oriented with inheritance hierarchy
  - `Object` → Base class for positioned entities
  - `movingObject` → Extends Object with velocity
  - Game entities inherit from appropriate base classes

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.
