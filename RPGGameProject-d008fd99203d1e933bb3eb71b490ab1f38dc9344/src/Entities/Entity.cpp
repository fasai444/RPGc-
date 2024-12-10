//
// Created by alexi on 12/11/2024.
//

#include "Entity.hpp"

Entity::Entity() {
    this->name = "";
    this->HP = 0;
    this->attack = 0;
    this->defense = 0;
}

Entity::Entity(std::string name) {
    this->name = name;
    Entity::setStats();
}

Entity::Entity(std::string name, int HP, int attack, int defense) {
    this->name = name;
    this->HP = HP;
    this->attack = attack;
    this->defense = defense;
}

void Entity::setStats() {
    this->HP = 0;
    this->attack = 0;
    this->defense = 0;
}

std::string Entity::getName() {
    return name;
}

void Entity::setName(std::string name) {
    this->name = name;
}

int Entity::getHP() {
    return this->HP;
}

void Entity::setHP(int HP) {
    this->HP = HP;
}

int Entity::getAttack() {
    return this->attack;
}

int Entity::getDefense() {
    return this->defense;
}

