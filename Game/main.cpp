#include "Area.h"
#include "Room.h"
#include "Item.h"
#include "Player.h"
#include "Character.h"
#include "GameSaverLoader.h"
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

int main()

{
    // Create Rooms
    Room startRoom("Start Room");
    Room hallway("You are in a long hallway.");
    Room kitchen("You are in kitchen room");

    // Define exits between rooms
    startRoom.AddExit("north", &hallway);
    hallway.AddExit("south", &startRoom);
    hallway.AddExit("north", &kitchen);
    kitchen.AddExit("south", &hallway);


    // Create Items
    Item key("Key", "A shiny key that looks important.");
    Item sword("Sword", "A sharp sword with a golden hilt."); // to be added to the treasure room
    Item lantern("Lantern", "An old but still bright lantern.");



    // Add items to rooms
    startRoom.AddItem(key);
    kitchen.AddItem(sword);
    hallway.AddItem(lantern);



    Area gameWorld;
    gameWorld.AddRoom("startRoom", &startRoom);
    gameWorld.AddRoom("hallway", &hallway);
    gameWorld.AddRoom("kitchen", &kitchen);
    //gameWorld.ConnectRooms("startRoom", "hallway", "north");
    //gameWorld.ConnectRooms("startRoom", "kitchen", "South");

    // Create a Player
    Player player("Alice", 100);
    //player.SetLocation(&startRoom);

    // Set the player's starting room (you can modify this room name)
    Room* currentRoom = gameWorld.GetRoom("startRoom");
    player.SetLocation(currentRoom);

    // Game loop
    bool gameRunning = true;
    while (gameRunning) {
        std::cout << "\nCurrent Location: " << player.GetLocation()->GetDescription() << std::endl;
        std::cout << "Items in the room:" << std::endl;
        if (player.GetLocation()->GetItems().empty()) {
            std::cout << "  None" << std::endl;
        } else {
            for (const Item& item : player.GetLocation()->GetItems()) {
                std::cout << "  - " << item.GetName() << ": " << item.GetDescription() << std::endl;
            }
        }

        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Look around" << std::endl;
        std::cout << "2. Move to another room" << std::endl;
        std::cout << "3. Interact with an item" << std::endl;
        std::cout << "4. Pick Up Item" << std::endl;
        std::cout << "5. Drop Item" << std::endl;
        std::cout << "6. View Inventory" << std::endl;
        std::cout << "7. Save Player Status" << std::endl;
        std::cout << "8. Load Player Status" << std::endl;
        std::cout << "9. Quit" << std::endl;

        std::cout << "\nEnter your choice: ";
        int choice;
        if (!(std::cin >> choice)) {
            std::cin.clear(); // Clears the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the input buffer
            std::cout << "Invalid input. Please enter a number from the options." << std::endl;
            continue;
        }

        switch (choice) {
            case 1: // Look around
                std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
                std::cout << "Items in the room:" << std::endl;
                for (const Item &item: player.GetLocation()->GetItems()) {
                    std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
                }
                break;
            case 2: { // Move to another room
                std::cout << "Enter the direction (e.g., north, south): ";
                std::string direction;
                std::cin >> direction;
                Room *nextRoom = player.GetLocation()->GetExit(direction);
                if (nextRoom != nullptr) {
                    player.SetLocation(nextRoom);
                    std::cout << "You move to the next room." << std::endl;
                } else {
                    std::cout << "You can't go that way." << std::endl;
                }
                break;
            }
            case 3: { // Interact with an item
                std::cout << "Enter the name of the item you want to interact with: ";
                std::string itemName;
                std::cin >> itemName;
                bool found = false;
                for (const Item &item: player.GetLocation()->GetItems()) {
                    if (item.GetName() == itemName) {
                        item.Interact();
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    std::cout << "Item not found." << std::endl;
                }
                break;
            }
            case 4: { // Pick Up Item
                std::cout << "Enter the name of the item you want to pick up: ";
                std::string itemName;
                std::cin >> itemName;

                if (player.GetLocation()->RemoveItem(itemName)) {
                    Item pickedUpItem(itemName, "No description available");
                    player.PickUpItem(pickedUpItem);
                    std::cout << itemName << " picked up." << std::endl;
                } else {
                    std::cout << "Item not found." << std::endl;
                }
                break;
            }
            case 5: { // Drop Item
                player.ShowInventory();
                std::cout << "Enter the name of the item you want to drop: ";
                std::string itemName;
                std::cin.ignore();
                std::getline(std::cin, itemName);

                if (player.DropItem(itemName)) {
                    std::cout << itemName << " dropped." << std::endl;
                    player.GetLocation()->AddItem(Item(itemName, "Description here"));
                } else {
                    std::cout << "Item not found in inventory." << std::endl;
                }
                break;
            }
            case 6: // View Inventory
                player.ShowInventory();
                break;
            case 7: // Save game
                GameSaverLoader gsl;
                gsl.savePlayerStatus("savefile.dat", player);
                std::cout << "Game saved successfully." << std::endl;
                break;
            case 8: { // Load game
                GameSaverLoader gsl;
                gsl.loadPlayerStatus("savefile.dat", player, gameWorld.GetRooms());

                std::cout << "Game loaded successfully." << std::endl;

                std::cout << "Current Inventory:" << std::endl;
                player.ShowInventory();
                break;
            }
            case 9: // Quit
                gameRunning = false;
                std::cout << "\nGoodbye!\n";
                break;
            default:
                std::cout << "Option not recognized. Please try again.\n";
                break;
        }
    }

    return 0;
}



















