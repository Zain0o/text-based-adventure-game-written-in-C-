//
// Created by zain_ on 06/02/2024.
//

#include "Player.h"
#include <iostream> // For std::cout in ShowInventory

Player::Player(const std::string& name, int health) : Character(name, health), location(nullptr) {}

void Player::ClearInventory() {
    inventory.clear();
}

void Player::SetLocation(Room* room) {
    this->location = room; // Use this-> to clarify scope
}

Room* Player::GetLocation() const {
    return this->location;
}

void Player::SetName(std::string& newName) {
    this->name = newName; // Corrected to avoid shadowing and use this->
}

std::string Player::GetName() const {
    return this->name;
}

void Player::SetHealth(int newHealth) {
    this->health = newHealth; // Corrected to avoid shadowing and use this->
}

int Player::GetHealth() const {
    return this->health;
}

void Player::SetInventory(std::vector<Item> newInventory) {
    this->inventory = newInventory; // Corrected to avoid shadowing and use this->
}

std::vector<Item> Player::GetInventory() const {
    return this->inventory;
}

// Implementing new inventory management methods
void Player::PickUpItem(const Item& item) {
    this->inventory.push_back(item);
}

bool Player::DropItem(const std::string& itemName) {
    auto it = inventory.begin();
    while (it != inventory.end()) {
        if (it->GetName() == itemName) {
            it = inventory.erase(it); // Correctly erase and advance the iterator
            return true;
        } else {
            ++it;
        }
    }
    return false; // Item not found
}

void Player::ShowInventory() const {
    std::cout << "Inventory:" << std::endl;
    if (this->inventory.empty()) {
        std::cout << "Empty." << std::endl;
    } else {
        for (const auto& item : this->inventory) {
            std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
        }
    }
}
