// Enemy.cpp
#include "Enemy.hpp"
#include "../Utils/Utils.hpp"

// Default constructor
Enemy::Enemy() : Entity("", 0, 0, 0) {}

// Parameterized constructor
Enemy::Enemy(std::string name, int HP, int attack, int defense) : Entity(name, HP, attack, defense) {}

// In Enemy.cpp, modify the generateEnemy function:

Enemy Enemy::generateEnemy(int level) {
    int hp = 0, attack = 0, defense = 0;

    switch (level) {
        case 1:  // Zombie
            hp = 300;
            attack = 10;
            defense = 5;
            break;
        case 2:  // Skeleton
            hp = 500;
            attack = 15;
            defense = 10;
            break;
        case 3:  // Giant Spider
            hp = 700;
            attack = 20;
            defense = 15;
            break;
            // Add more enemies as needed
        default:
            hp = 300;
            attack = 10;
            defense = 5;
    }

    return Enemy("Enemy Level " + std::to_string(level), hp, attack, defense);
}

