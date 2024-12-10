//
// Created by alexi on 19/11/2024.
//

#include "Enemy.hpp"

#include "../Utils/Utils.hpp"

Enemy::Enemy() {

}

Enemy::Enemy(std::string name, int HP, int attack, int defense) : Entity(name, HP, attack, defense){

}

Enemy Enemy::generateEnemy() {
    switch (Utils::generateRandomInt(1, 2)) {
        case 1:
            return Skeleton{};
        case 2:
            return Zombie{};
        default:
            return Enemy{};
    }
}


