# FdF project for 42Madrid

This is the first graphical project at 42, focused on representing a landscape as a 3D object.  
All surfaces are drawn using lines in a **wireframe model**, with the help of the 42 school's graphical library: **MiniLibX**.  
This internal library provides the basic tools to open a window, create images, and handle keyboard/mouse events.

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Makefile](https://img.shields.io/badge/Makefile-000000.svg?style=for-the-badge)

📄 [Click here to see the official subject PDF](https://github.com/agn3shayd3n/fdf42/blob/main/es.subject.pdf)

---

# 🌍 MY PROJECT

I created my own custom map for the project, called **`my_map.fdf`**, based on an imaginary topographic landscape generated with the help of AI.

I also implemented the bonus part of the project, which includes a **control panel** displayed in the top-left corner of the screen.  
The controls were programmed using **key hooks** and include:

- Zoom In / Zoom Out  
- Move the map  
- Rotate on the X, Y, and Z axes  
- Switch between bird's eye view and isometric view  
- Reset the view  
- Hide the control panel  

### 🖼️ Screenshots

![Screenshot 2](https://github.com/agn3shayd3n/fdf42/blob/main/img/fdf02.png)  
![Screenshot 3](https://github.com/agn3shayd3n/fdf42/blob/main/img/fdf03.png)  
![Screenshot 1](https://github.com/agn3shayd3n/fdf42/blob/main/img/fdf01.png)
![Screenshot 4](https://github.com/agn3shayd3n/fdf42/blob/main/img/fdf04.png)  

---

# 🧩 PROJECT STEPS

## V.1 Rendering

Your program must represent the model using isometric projection.  
The coordinates of the landscape are stored in a `.fdf` file passed as an argument.

**Example**:

``` bash
$> cat 42.fdf
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
```

Each number represents a point in 3D space:
- The horizontal position corresponds to its **X** axis
- The vertical position corresponds to its **Y** axis
- The value corresponds to its **altitude (Z axis)**

---

## V.2 Graphic Management

- Your program must display the image in a window.  
- Switching between windows or minimizing must not crash the program.  
- Pressing **ESC** should close the window and exit cleanly.  
- Clicking the close button (❌) should also exit cleanly.  
- Use of **MiniLibX image functions** is mandatory.

---

## V.3 Bonus Features

Extra points are awarded for implementing:
- An extra projection (e.g., parallel or conic)  
- Zoom functionality  
- Translation (map movement)  
- Rotation  
- Any additional feature of your choice

---

# ⚙️ HOW TO USE

1. Clone this repository:

```bash
git clone https://github.com/agn3shayd3n/fdf42.git
```
Navigate to the MiniLibX directory and compile:

```bash
cd minilibx_macos
make
```
Return to the main directory and compile the project:

```bash
cd ..
make
```
Run the program using a sample map from the maps folder:

```bash
./fdf maps/t1.fdf
```
Or use the custom map I created:
```bash
./fdf my_map.fdf
```
Use the following controls to interact with the map:
```
--- CONTROLS ---
Z / X       → Zoom in / out
Arrows      → Move map
Q / E       → Rotate X axis
W / S       → Rotate Y axis
R / L       → Rotate Z axis
B           → Switch view
Backspace   → Reset view
H           → Toggle control panel
```
