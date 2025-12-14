# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## [1.0.0] - Initial Archival Release

### Added
- Complete brick-breaker game implementation with OOP design
- Multiple gameplay entities: Ball, Brick, Food (power-ups), Paddle
- Two starter level layouts with randomized brick patterns
- Five power-up types:
  - Widen paddle
  - Shrink paddle
  - Slow balls
  - Speed up balls
  - Spawn extra balls
- Paddle deflection physics with angle-based ball trajectory
- Multi-ball gameplay with lifecycle management
- Life tracking and game reset mechanics
- OpenGL/GLUT rendering using course-provided utilities

### Technical
- Object-oriented C++ implementation with inheritance hierarchy
- Abstract base classes for game objects
- Static member management for ball/brick counts
- Time-based power-up duration system
