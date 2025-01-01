//
// Created by alexi on 12/11/2024.
//

#include "Role.hpp"
// Constructeur avec paramètres
// Initialise un rôle avec un nom et des caractéristiques spécifiques
Role::Role(std::string roleName, int vitality, int strength, int intel, int dexterity) {
    this->roleName = roleName;
    this->vitality = vitality;
    this->strength = strength;
    this->intel = intel;
    this->dexterity = dexterity;
}

std::string Role::getRoleName() {
    return this->roleName;
}

int Role::getVitality() {
    return this->vitality;
}

int Role::getStrength() {
    return this->strength;
}

int Role::getIntel() {
    return this->intel;
}

int Role::getDexterity() {
    return this->dexterity;
}