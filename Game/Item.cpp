//
// Created by zain_ on 06/02/2024.
//
#include <string>
#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, const std::string& desc) : name(name), description(desc) {}

void Item::Interact() const {
    std::cout << "Interacting with " << name << ": " << description << std::endl;
}

std::string Item::GetName() const {
    return name;
}

std::string Item::GetDescription() const {return description;}