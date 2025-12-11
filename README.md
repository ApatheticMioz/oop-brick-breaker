# OOP Breakout (OpenGL/GLUT)

Single-file GLUT/OpenGL brick-breaker built for an OOP course assignment. The game spawns randomized brick patterns, power-up drops, multi-ball play, and paddle-angle deflection for richer ball physics.

## Features
- Two starter layouts (dense grid and patterned spread) with randomized brick colors/power-ups per round.
- Paddle deflection adjusts ball vector using an angle map; walls and ceiling add bounce constraints.
- Five power-up types: widen paddle, shrink paddle, slow balls, speed up balls, and spawn two extra balls.
- Multi-ball lifecycle: balls expire after a few seconds while creation time is tracked to auto-prune.
- Life tracking and game reset on ball loss; exits when lives reach zero.
- Rendering helpers for circles, rectangles, and triangles via course-supplied `util.h`/GLUT.

## Controls
- `1`, `2`, `3`: start level 1, 2, or (placeholder) 3.
- Mouse move: slide paddle horizontally.
- `Esc`: quit.

## Tech Stack
- C++ with basic OOP classes (`Ball`, `Brick`, `Food`, `Paddle`, `Game`).
- OpenGL/GLUT via the provided `util.h` helper.
- Standard library math utilities for collision/angle calculations.

## Project Layout
- [game.cpp](game.cpp): GLUT entry point, render/update loop, input hooks.
- [game.h](game.h): core game state, collision handling, power-ups, level setup.
- [ball.h](ball.h), [brick.h](brick.h), [food.h](food.h), [paddle.h](paddle.h), [abstract.h](abstract.h): gameplay entities and shared base classes.

## Build and Run
Dependencies: a C++ compiler, GLUT/OpenGL development libraries, and the course-provided `util.h` (and its implementation). On Windows with MinGW + freeglut installed:

```bash
# from the project root
 g++ game.cpp -o breakout -lfreeglut -lopengl32 -lglu32
 ./breakout
```

On Linux with freeglut-dev installed:

```bash
 g++ game.cpp -o breakout -lglut -lGL -lGLU -lm
 ./breakout
```

Adjust library flags/paths as needed for your toolchain or if `util.cpp` is supplied separately by your course kit.

## Gameplay Notes
- Paddle deflection uses a variable angle map to control rebound direction; speed is normalized to a set magnitude.
- Power-ups are time-bound: speed boosts/nerfs revert after a short duration.
- Bricks drop matching-color food tokens; catching them applies the associated effect.
