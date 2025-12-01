# **so_long – 2D Game Project (42 School)**

A small 2D top-down game built using **MiniLibX**, where the player must collect all collectibles and reach the exit while navigating a map.
This project focuses on event handling, memory management, file parsing, and rendering graphics using a basic graphics library.

---

## 📌 **Table of Contents**

1. [Introduction](#introduction)
2. [Mandatory](#mandatory)
3. [Features](#features)
4. [Project Structure](#project-structure)
5. [Gameplay](#gameplay)
6. [Map Rules](#map-rules)
7. [Compilation & Usage](#compilation--usage)
8. [Controls](#controls)
9. [Error Handling](#error-handling)

---

## 🧩 **Introduction**

**so_long** is a simple 2D adventure game. Using the MiniLibX (MLX) library, you will open a window that displays a map loaded from a `.ber` file.
Your goal is to **collect all items** on the map and **reach the exit** without breaking wall collisions or map rules.

The project teaches:

* Basic game loop logic
* Window creation and pixel rendering
* Event hooks (keyboard input, window close, etc.)
* Proper memory management
* File parsing and validation

---

## ⭐ **Mandatory**

### **Mandatory**

* Basic rendering
* Proper map parsing
* Player movement
* Movement counter
* Exit only after collecting all `C`

## 🎮 **Features**

✔️ Load and validate map files (`.ber`)
✔️ Render textures (player, wall, floor, collectible, exit)
✔️ Count and display player's movements
✔️ Collect items
✔️ Reach exit only after collecting everything
✔️ Keyboard-based movement
✔️ Flood fill map validation (path check)
✔️ Graceful error messages

---

## 📁 **Project Structure**

Example structure (yours may vary):

```
so_long/
│
├── src/
│   ├── main.c
│   ├── init_game.c
│   ├── read_map.c
│   ├── check_map.c
│   ├── flood_fill.c
│   ├── render.c
│   ├── events.c
│   └── utils.c
│
├── includes/
│   └── so_long.h
│
├── assets/
│   ├── player.xpm
│   ├── wall.xpm
│   ├── floor.xpm
│   ├── coin.xpm
│   └── exit.xpm
│
├── maps/
│   └── example.ber
│
├── Makefile
└── README.md
```

---

## 🕹️ **Gameplay**

The player navigates a small map:

* **Walls** block movement
* **Collectibles** must all be gathered
* The **exit** opens only when all collectibles are taken
* Moving increases the move counter printed to the terminal

---

## 🗺️ **Map Rules**

Maps must follow strict rules:

### **1. Rectangle**

All rows must have the same width.

### **2. Surrounded by walls**

First and last row: all `1`
First and last character of each row: `1`

### **3. Valid characters**

```
0 → Floor  
1 → Wall  
P → Player (only 1 allowed)  
E → Exit (only 1 allowed)  
C → Collectible (at least 1 required)
```

### **4. Path Validation**

A valid path must exist:

* From player → all collectibles
* From player → exit after collecting

Flood fill is used to verify this.

---

## 🛠️ **Compilation & Usage**

### **Compile**

```bash
make
```

### **Run**

```
./so_long maps/example.ber
```

### **Clean**

```bash
make clean
make fclean
```

---

## ⌨️ **Controls**

| Key     | Action        |
| ------- | ------------- |
| **W**   | Move up       |
| **A**   | Move left     |
| **S**   | Move down     |
| **D**   | Move right    |
| **ESC** | Exit the game |

---

## 🚨 **Error Handling**

The program displays clear messages for errors such as:

* Invalid file extension
* Map not rectangular
* Map not surrounded by walls
* Missing or multiple `P` or `E`
* No collectibles
* Invalid characters
* No valid path
* MLX failure or allocation error

All errors print:

```
Error
<description>
```
