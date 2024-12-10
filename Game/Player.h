//
// Created by zain_ on 06/02/2024.
//

#ifndef LAB4_PLAYER_H
#define LAB4_PLAYER_H

#include "Character.h"
#include "Room.h" // Include Room definition
#include "Item.h" // Ensure you include the definition of Item
#include <vector> // Include the vector library

class Player : public Character {
private:
    Room* location;
    std::vector<Item> inventory; // This is for storing the items

public:
    Player(const std::string& name, int health);
    void SetLocation(Room* room);
    Room* GetLocation() const;

    void SetName(std::string& name);
    std::string GetName() const;

    void SetHealth(int health);
    int GetHealth() const;

    // Updated methods for inventory management
    void PickUpItem(const Item& item); // Add an item to the inventory
    bool DropItem(const std::string& itemName); // Remove an item from the inventory by name
    void ShowInventory() const; // Show the items in the inventory
    void ClearInventory(); // Add this method to clear the inventory.


    // If you decide to keep these, you might need to adjust their implementation
    void SetInventory(std::vector<Item> inventory);
    std::vector<Item> GetInventory() const;
};

#endif //LAB4_PLAYER_H
