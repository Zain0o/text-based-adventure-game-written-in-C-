//
// Created by zain_ on 06/02/2024.
//

#include "Area.h"
Area::~Area() {
    for (auto& pair : rooms) {
        delete pair.second;
    }
}

void Area::AddRoom(const std::string& name, Room* room) {
    rooms[name] = room;
}

Room* Area::GetRoom(const std::string& name) {
    if (rooms.find(name) != rooms.end()) {
        return rooms[name];
    }
    return nullptr;
}

void Area::ConnectRooms(const std::string& room1Name, const std::string& room2Name, const std::string& direction) {
    Room* room1 = GetRoom(room1Name);
    Room* room2 = GetRoom(room2Name);
    if (room1 && room2) {
        room1->AddExit(direction, room2);
    }
}

void Area::LoadMapFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string room1, room2, direction;
        std::getline(iss, room1, '|');
        std::getline(iss, room2, '|');
        std::getline(iss, direction);
        if (!GetRoom(room1)) {
            AddRoom(room1, new Room(room1));
        }
        if (!GetRoom(room2)) {
            AddRoom(room2, new Room(room2));
        }
        ConnectRooms(room1, room2, direction);
    }
}
std::map<std::string, Room*> Area::GetRooms() const {
    return rooms;
}

