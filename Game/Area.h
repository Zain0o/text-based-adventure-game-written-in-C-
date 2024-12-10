//
// Created by zain_ on 06/02/2024.
//

#ifndef LAB4_AREA_H
#define LAB4_AREA_H

#include "Room.h"
#include <string>
#include <map>
#include <fstream>
#include <sstream>

class Area {
private:
    std::map<std::string, Room*> rooms;

public:
    Area() = default;
    ~Area();
    void AddRoom(const std::string& name, Room* room);
    Room* GetRoom(const std::string& name);
    void ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction);
    void LoadMapFromFile(const std::string& filename);
    std::map<std::string, Room*> GetRooms() const;

};

#endif //LAB4_AREA_H
