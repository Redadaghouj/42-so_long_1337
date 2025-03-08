# so_long - 1337 Project  

[![1337 Badge](https://img.shields.io/badge/1337-Project-blue)](https://www.42network.org/)  

## 📜 Project Overview  

**so_long** is a 2D game project from **1337** (part of the **42 Network**). The objective is to create a simple game where the player collects items and exits the level. The project focuses on window management, event handling, and basic gameplay elements using the **MiniLibX** library.

---

## 🚀 Features  

- **Window Management:** Opens and manages a game window using MiniLibX.
- **Event Handling:** Handles keyboard inputs (arrow keys) for player movement.
- **Collision Detection:** Uses **AABB (Axis-Aligned Bounding Box)** method for collision detection.
- **Map Parsing:** Reads and validates maps from `.ber` files.
- **Bonus Features:** Includes enemy patrols and sprite animations.
- **Graphic Rendering:** Displays textures, sprites, and collectibles.

---

## 📂 Repository Structure  

```plaintext  
📦 so_long
├── 📂 mandatory
│   ├── 📂 gnl
│   │   ├── get_next_line.c
│   │   ├── get_next_line.h
│   │   ├── get_next_line_utils.c
│   ├── 📂 images
│   │   ├── collect.png
│   │   ├── exit.png
│   │   ├── player.png
│   │   ├── wall.png
│   ├── 📂 maps
│   │   ├── 1337_map.ber
│   │   ├── large_map.ber
│   │   ├── map.ber
│   ├── 📂 utils
│   │   ├── error_handlers.c
│   │   ├── ft_putchar.c
│   │   ├── ft_putstr_fd.c
│   │   ├── ft_strcmp.c
│   ├── check_walls.c
│   ├── display_frame_utils.c
│   ├── display_frame.c
│   ├── print_steps.c
│   ├── so_long.c
│   ├── so_long.h
│   ├── validate_map_utils.c
│   ├── validate_map.c
│
├── 📂 bonus
│   ├── 📂 gnl_bonus
│   ├── 📂 image_bonus
│   ├── 📂 maps_bonus
│   ├── 📂 utils_bonus
│   ├── check_walls_bonus.c
│   ├── display_frame_utils_bonus.c
│   ├── display_frame_bonus.c
│   ├── print_steps_bonus.c
│   ├── so_long_bonus.c
│   ├── so_long_utils_bonus.c
│   ├── so_long_bonus.h
│   ├── sprite_animation_bonus.h
│   ├── validate_map_utils_bonus.c
│   ├── validate_map_bonus.c
│
├── 📂 MLX42
├── Makefile
├── README.md
```  

---

## 🛠️ How to Compile  

### Without Bonus  
```bash  
make  
```  
This will generate the `so_long` executable.  

### With Bonus (Enemy Patrol and Animations)  
```bash  
make bonus  
```  
This will generate the `so_long` executable too.  

To clean up object files:  
```bash  
make clean  
```  

To remove both executables and object files:  
```bash  
make fclean  
```  

To recompile everything:  
```bash  
make re  
```  

---

## 🎮 Game Controls  

| Key  | Action |  
|------|--------|  
| **Arrow Keys** | Move the player (Up, Down, Left, Right) |  
| **ESC** | Close the game window and exit the program |  

---

## 🗺️ Map Rules  

- The map must be a `.ber` file.
- The map must contain:
  - **1 Player (P)**
  - **1 Exit (E)**
  - **At least 1 Collectible (C)**
- The map must be surrounded by walls (**1**).
- The map must be rectangular.
- The map must have a valid path for the player to collect all items and reach the exit.

---

## 🛡️ Error Handling  

- **Invalid Maps:** Displays an error message and exits if the map is invalid.
- **Memory Leaks:** Ensures all allocated memory is properly freed.
- **File Errors:** Handles file reading errors gracefully.

---

## 🌟 Achievements  

- Mastered **MiniLibX** for window and graphic management.
- Implemented **AABB collision detection** for smooth gameplay.
- Added **enemy patrols** and **sprite animations** as bonus features.
- Gained experience in **2D game development** and **event handling**.

---

## 🛡️ License  

This project is part of the **1337 curriculum**. It is shared here for educational purposes and should not be used for plagiarism.

---

Feel free to customize this README further to better fit your project's specifics!
