cmake_minimum_required(VERSION 3.27)
project(RPGGameProject)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/src/Utils)

add_executable(RPGGameProject src/main.cpp
        src/Entities/Role.cpp
        src/Entities/Role.hpp
        src/Entities/Entity.cpp
        src/Entities/Entity.hpp
        src/Entities/Player.cpp
        src/Entities/Player.hpp
        src/Utils/Utils.hpp
        src/Utils/UI.hpp
        src/Game/Game.cpp
        src/Game/Game.hpp
        src/Game/Combat.cpp
        src/Game/Combat.hpp
        src/Entities/Enemy.cpp
        src/Entities/Enemy.hpp
        src/Entities/Inventory.cpp
        src/Entities/Inventory.hpp
        src/Entities/Item.cpp
        src/Entities/Item.hpp
        src/Utils/StringUtils.hpp


)
