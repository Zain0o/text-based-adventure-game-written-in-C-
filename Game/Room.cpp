//
// Created by zain_ on 06/02/2024.
//
#include "Room.h"
#include <algorithm>

Room::Room(const std::string& desc) : description(desc) {}

void Room::AddItem(const Item& item) {
    items.push_back(item);
}

void Room::RemoveItem(const Item& item) {
    // Implementation depends on how you identify items (e.g., by name)
}

void Room::AddExit(const std::string& direction, Room* room) {
    exits[direction] = room;
}

std::string Room::GetDescription() const {
    return description;
}

const std::vector<Item>& Room::GetItems() const {
    return items;
}


Room* Room::GetExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    }
    return nullptr;
}
bool Room::RemoveItem(const std::string& itemName) {
    auto it = std::find_if(items.begin(), items.end(), [&](const Item& item) {
        return item.GetName() == itemName;
    });

    if (it != items.end()) {
        items.erase(it);
        return true;
    }

    return false;
}