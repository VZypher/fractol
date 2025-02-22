Fractol Project

## Overview

Fractol is a graphical application that allows users to explore fractal images. It is built using the MiniLibX library, which provides a simple interface for creating windows and handling events in C.

## Features

- Explore different types of fractals, including Julia sets.
- Zoom in and out using mouse scroll.
- Navigate the fractal space using keyboard arrow keys.
- Reset view with the spacebar.
- Exit the application with the `Esc` key.

### Prerequisites

- **Linux**: Ensure you have `gcc`, `make`, `xorg`, `libxext-dev`, and `libbsd-dev` installed.
- **MacOS**: Install [XQuartz](https://www.xquartz.org/).

### Building the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/VZypher/fractol
   cd fractol
   ```

2. Build the project:
   ```bash
   make
   ```

### Controls

- **Arrow Keys/WASD**: Move around the fractal.
- **Mouse Scroll**: Zoom in and out.
- **Spacebar**: Reset the view.
- **Esc**: Exit the application.
- **\***: Increase imaginary values ​​for Julia
- **/**: Decrease imaginary values for Julia 

- **fractol.h**: Header file containing necessary includes and function prototypes.

### Screenshots
![Screenshot from 2025-02-22 04-30-34](https://github.com/user-attachments/assets/a494e491-4c9d-4dd7-a774-d3352c578913)
![Screenshot from 2025-02-22 04-32-24](https://github.com/user-attachments/assets/f870b718-e8bf-45d0-8896-2f103b1a7650)
![Screenshot from 2025-02-22 04-32-45](https://github.com/user-attachments/assets/ec87e3c2-13c4-41ed-94af-0ed6da6b35c1)
