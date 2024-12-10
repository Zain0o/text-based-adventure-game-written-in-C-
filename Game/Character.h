//
// Created by zain_ on 06/02/2024.
//

#ifndef LAB4_CHARACTER_H
#define LAB4_CHARACTER_H

#include <string>
#include <vector>
#include "Item.h" // Assume Item class is defined in Item.h

class Character {
protected:
    std::string name;
    int health;
    std::vector<Item> inventory;

public:
    Character(const std::string& name, int health);
    virtual void TakeDamage(int damage);
    // Add methods for inventory management
};
#endif //LAB4_CHARACTER_H
