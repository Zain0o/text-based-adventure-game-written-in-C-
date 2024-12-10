cmake_minimum_required(VERSION 3.27)
project(lab4)

set(CMAKE_CXX_STANDARD 23)

add_executable(lab4 main.cpp
        Room.h
        Room.cpp
        Item.cpp
        Item.h
        Character.cpp
        Character.h
        Player.cpp
        Player.h
        Area.cpp
        Area.h
        GameSaverLoader.h
        GameSaverLoader.cpp)
