// Corrected File: GameSaverLoader.h
#ifndef GAMESAVERLOADER_H
#define GAMESAVERLOADER_H

#include <string>
#include "Player.h" // Include the Player definition
#include "Room.h" // This might be necessary if Room class is referenced
#include <map> // Include for std::map

class GameSaverLoader {
public:
    void savePlayerStatus(const std::string& filename, const Player& player);
    void loadPlayerStatus(const std::string& filename, Player& player, const std::map<std::string, Room*>& roomMap);
};

#endif // GAMESAVERLOADER_H
