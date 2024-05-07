# FRACT-OL


## Description:

Welcome to Fractol, a basic computer graphics project that explores fractals using the MiniLibX graphical library. This project introduces us to fractals, complex numbers, optimization in computer graphics, and event handling.

## Project Structure

. fractol.c: Main file containing the entry point and logic for rendering fractals.

. ft_atof.c: Custom implementation of atof for converting strings to floats.

. julia.c: Logic for rendering Julia sets.

. mandelbrot.c: Logic for rendering Mandelbrot sets.

. hook_and_zoom.c: Implementation of mouse wheel zoom functionality.

. error.c: Error handling functions.

. utils.c: Utility functions.

. Makefile: Compiles the source files without relinking.

. fractol.h: Header file containing function prototypes and necessary includes.

## Compilation

To compile the project, simply run 'make':

```bash
make
```
## Usage 
. Run the executable fractol with the type of fractal to display and any additional options:

```bash
./fractol [fractal_type] [options]
```
Available fractal types:

j: Julia set

m: Mandelbrot set

## Features
. Fractal Rendering: Offers Julia set and Mandelbrot set rendering.

. Mouse Wheel Zoom: Allows zooming in and out infinitely using the mouse wheel.

. Dynamic Parameters: Can create different Julia sets by passing different parameters to the program.

. Smooth Graphic Management: Ensures smooth window management, including minimizing and switching to other windows.

. User Interaction: Supports closing the window and quitting the program cleanly using ESC key or window's close button.

. Color Depth: Utilizes multiple colors to represent the depth of each fractal, allowing for psychedelic effects.

## Some Fractols

  Mandelbrot:

![Login](https://github.com/adhaka-afk/FRACT-OL/blob/main/Mandelbrot_output.png?raw=true)

  Julia:

![Login](https://github.com/adhaka-afk/FRACT-OL/blob/main/Julia_output.png?raw=true)
## 🚀 Next Project

[push_swap](https://github.com/adhaka-afk/PUSH_SWAP)

## ⏳ Previous Project

[minitalk](https://github.com/adhaka-afk/MINI_TALK)

