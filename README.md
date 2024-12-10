# Text-Based Adventure Game in C++

## Overview
This is a text-based adventure game implemented in C++. Players can navigate a world of interconnected rooms, interact with items, and manage their inventory. The game allows players to save and load progress, making it an immersive and replayable experience.

---

## Features
- **Room Exploration**: Navigate between rooms connected by various directions.
- **Item Interaction**: Pick up, drop, and interact with items in the game world.
- **Inventory Management**: Maintain and manage a collection of items as you explore.
- **Dynamic Game World**: Rooms and their connections are dynamically loaded from the `game_map.txt` file.
- **Save and Load Functionality**: Save your game progress, including location, health, and inventory, and resume it later.

---

## Project Files
### Source Code
1. **`main.cpp`**: Contains the main game loop and logic for player interaction.
2. **`Area.cpp` / `Area.h`**: Handles the game world structure, including rooms and their connections.
3. **`Room.cpp` / `Room.h`**: Represents individual rooms in the game, including their items and exits.
4. **`Player.cpp` / `Player.h`**: Implements the player character, including inventory and location management.
5. **`Character.cpp` / `Character.h`**: Defines the base class for game characters, including health and basic properties.
6. **`Item.cpp` / `Item.h`**: Represents items in the game, including their properties and interactions.
7. **`GameSaverLoader.cpp` / `GameSaverLoader.h`**: Provides functionality to save and load player progress.

### Data Files
1. **`game_map.txt`**: Specifies the rooms and their connections in the format:
   ```
   room1|room2|direction
   ```
   Example:
   ```
   startRoom|hallway|north
   hallway|kitchen|north
   ```

---

## How to Build and Run
### Prerequisites
- A C++ compiler (e.g., GCC, Clang, or MSVC).
- A terminal or IDE such as CLion or Visual Studio.

### Build Instructions
1. **Compile the Game**:
   ```bash
   g++ main.cpp Area.cpp Room.cpp Player.cpp Character.cpp Item.cpp GameSaverLoader.cpp -o adventure_game
   ```
2. **Ensure Data Files Are Present**:
   - Place `game_map.txt` in the same directory as the executable.

3. **Run the Game**:
   ```bash
   ./adventure_game
   ```

---

## Gameplay Instructions
1. **Start the Game**:
   - The player begins in the starting room with a default health value.

2. **Game Options**:
   - Look around the room.
   - Move to a connected room by specifying a direction (e.g., north, south).
   - Interact with items in the room.
   - Pick up or drop items.
   - View your inventory.
   - Save and load your progress.

3. **Game Map**:
   - The game world is defined in `game_map.txt`. Rooms and their connections are dynamically loaded at runtime.

---

## Example Gameplay
1. Start in the **Start Room** with a shiny key.
2. Move **north** to the **Hallway**.
3. Pick up a lantern in the **Hallway**.
4. Move **north** again to the **Kitchen** and find a sword.
5. Save your progress and quit the game.


