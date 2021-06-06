# CPPND: Capstone Hello World Repo

This the implementation for the capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213).

This project is an implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) providing several abstract classes to be able to extend the functionality easily. 

Structure (respectively most important classes of the project):
- `Grid2D` provides a generic two-dimensional grid, which is able to represent f.e. a grid of `Cells`
- `Grid2DRenderer` is an abstract class providing a single render method to be able to add custom renderers to the project (f.e. by using opencv)
- `Cell` is a representation of a biological cell (can be alive or dead)
- `GameOfLife` implements the cellular automaton by providing parameters (with convenient defaults) for customizing the simulation:
  - Hooks:
    - Start hook at the beginning
    - Loop hook for every generation
    - End Hook at the end
  - Initial state supplier
  - Renderer
  - Time between the generations
  
The `main` file contains several examples of customized simulations.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./GameOfLife`.

## Rubric points
- [x] README
- [x] Control structures
- [x] Uses Object Oriented Programming techniques
- [x] Usage of access specifiers
- [x] Member initialization lists
- [x] Inheritance
- [x] Derived functions override virtual base class functions
- [x] Templates generalizing functions in the project
- [x] Usage of references
- [x] Usage of smart pointers (f.e. in the tests)
