#include "Entity.hpp"

// constrcuteur par defaut
Entity::Entity() {
    this->name = "";
    this->HP = 0;
    this->attack = 0;
    this->defense = 0;
}

// Constructeur avec un parametre
Entity::Entity(std::string name) {
    this->name = name;
    Entity::setStats();// Initialise les statistiques par défaut (HP, attaque, défense).
}

// Constructeur avec tous les paramètres
Entity::Entity(std::string name, int HP, int attack, int defense) {
    this->name = name;
    this->HP = HP;
    this->attack = attack;
    this->defense = defense;
}

// / Définir les statistiques par défaut
void Entity::setStats() {
    this->HP = 0;
    this->attack = 0;
    this->defense = 0;
}

// getter Retourne le nom de l'entité.
std::string Entity::getName() const {
    return name;
}

// setter qui Permet de définir ou de modifier le nom de l'entité.
void Entity::setName(std::string name) {
    this->name = name;
}

// Getter Retourne les points de vie (HP) de l'entité.
int Entity::getHP() const {
    return this->HP;
}

// Setter for HP
void Entity::setHP(int HP) {
    this->HP = HP;
}

// Getter
int Entity::getAttack() const {
    return this->attack;
}

// Getter
int Entity::getDefense() const {
    return this->defense;
}
