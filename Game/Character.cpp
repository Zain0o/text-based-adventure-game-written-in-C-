//
// Created by zain_ on 06/02/2024.
//

#include "Character.h"
#include <iostream>

Character::Character(const std::string& name, int health) : name(name), health(health) {}

void Character::TakeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << name << " is defeated." << std::endl;
    }
}