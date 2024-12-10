//
// Created by zain_ on 06/02/2024.
//

#ifndef LAB4_ROOM_H
#define LAB4_ROOM_H


#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Item.h" // Assume Item class is defined in Item.h

class Room {
private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;

public:
    Room(const std::string& desc);
    void AddItem(const Item& item);
    void RemoveItem(const Item& item);
    void AddExit(const std::string& direction, Room* room);
    std::string GetDescription() const;
    const std::vector<Item>& GetItems() const;
    Room* GetExit(const std::string& direction) const;
    bool RemoveItem(const std::string& itemName);
    std::map<std::string, Room*> GetExits() const {
        return exits;
    }


};

#endif //LAB4_ROOM_H
