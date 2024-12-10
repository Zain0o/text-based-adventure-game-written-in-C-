#include <limits>
#include "GameSaverLoader.h"
#include <fstream>
#include <iostream>
#include <map>

void GameSaverLoader::savePlayerStatus(const std::string& filename, const Player& player)
{
    std::ofstream outFile(filename);
    if (!outFile)
    {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    outFile << player.GetName() << "\n" << player.GetHealth() << "\n" << player.GetLocation()->GetDescription() << std::endl;
    // Save inventory
    for (const auto& item : player.GetInventory())
    {
        outFile << item.GetName() << "\n";
    }

    outFile.close();
}

void GameSaverLoader::loadPlayerStatus(const std::string& filename, Player& player, const std::map<std::string, Room*>& roomMap) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
        return;
    }

    std::string name, roomName, itemName; // Declare itemName here
    int health;

    std::getline(inFile, name);
    inFile >> health;
    inFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(inFile, roomName);

    player.SetName(name);
    player.SetHealth(health);

    // Assuming you've correctly set the player's location based on roomName...
    if (roomMap.find(roomName) != roomMap.end()) {
        player.SetLocation(roomMap.at(roomName));
    }

    player.ClearInventory();

    // Use the already declared itemName variable to read each item name within the while loop
    while (std::getline(inFile, itemName)) {
        if (!itemName.empty()) {
            Item item(itemName, "Restored item description"); // Adjust according to your design
            player.PickUpItem(item);
        }
    }

    inFile.close();
}
