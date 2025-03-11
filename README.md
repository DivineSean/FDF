# FDF (Fil de Fer)

## Overview
FDF (Fil de Fer) is a 3D wireframe renderer project from the 42 programming curriculum. This program takes a map file as input and renders it as a 3D wireframe using the school's graphics library, MiniLibX.

## Features
- Reads and parses map files with elevation data
- Renders 3D wireframe models with proper perspective
- Supports rotation, scaling, and translation transformations
- Color gradient visualization based on elevation
- Smooth window management

## Installation

### Prerequisites
- MiniLibX library
- C compiler (gcc/clang)
- Make

### Building the program
Clone the repository and compile:
```bash
git clone https://github.com/DivineSean/FDF.git
cd FDF
make
```

## Usage
```bash
./fdf [map_file]
```

### Example
```bash
./fdf maps/42.fdf
```

### Controls
- **Arrow keys**: Move the model
- **+/-**: Zoom in/out
- **A/D**: Increase/decrease arround Y axis
- **W/S**: Increase/decrease arround X axis
- **4/6**: Rotate around Y axis
- **8/2**: Rotate around X axis
- **ESC**: Close the program

## Map Format
The map file should contain integers representing the height of each point:
```
0  0  0  0  0
0  0  0  0  0
0  0 10 10  0
0  0 10 10  0
0  0  0  0  0
```

## Conclusion
This FDF project demonstrates fundamental computer graphics concepts including 3D visualization, wireframe rendering, and transformation matrices. Through this project, I've gained valuable experience in handling graphical programming, mathematical calculations for 3D projection, and efficient memory management. The implementation showcases my ability to create a functional interactive 3D visualization tool from scratch using C programming and the MiniLibX library.
