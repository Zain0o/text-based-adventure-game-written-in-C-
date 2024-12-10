//
// Created by zain_ on 06/02/2024.
//

#ifndef LAB4_ITEM_H
#define LAB4_ITEM_H
#include "Item.h"
class Item {
private:
    std::string name;
    std::string description;

public:
    Item(const std::string& name, const std::string& desc);
    void Interact() const;
    std::string GetName() const;
    std::string GetDescription() const;
};

#endif //LAB4_ITEM_H
