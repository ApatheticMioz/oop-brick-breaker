# Contributing to OOP Brick Breaker

Thank you for your interest in contributing to this project! This document provides guidelines for contributing.

## How to Contribute

### Reporting Issues

1. Check if the issue has already been reported
2. Open a new issue with a clear title and description
3. Include steps to reproduce the problem
4. Include your environment details (OS, compiler version, OpenGL/GLUT version)

### Submitting Pull Requests

1. Fork the repository
2. Create a new branch for your feature or bug fix
3. Make your changes following the coding style below
4. Test your changes to ensure they compile and run correctly
5. Submit a pull request with a clear description of your changes

### Coding Style

- Use tabs for indentation (consistent with existing code)
- Follow the existing naming conventions:
  - Classes: PascalCase (e.g., `Ball`, `Brick`, `Paddle`)
  - Methods: camelCase (e.g., `getXPos`, `setColor`)
  - Variables: snake_case for private members (e.g., `x_pos`, `y_speed`)
- Include header guards in all `.h` files
- Keep lines under 120 characters when practical

### Build Requirements

- C++ compiler with C++11 support or later
- OpenGL development libraries
- GLUT/freeglut development libraries
- Course-provided `util.h` header

### Testing Your Changes

Before submitting a pull request, ensure:

1. The code compiles without warnings
2. The game runs and functions correctly
3. No existing functionality is broken

## Code of Conduct

Please be respectful and constructive in all interactions. We welcome contributors of all experience levels.

## Questions?

If you have questions about contributing, feel free to open an issue for discussion.
