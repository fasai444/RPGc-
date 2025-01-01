//
// Created by alexi on 12/11/2024.
//

#include "Player.hpp"
// Constructeur par défaut
// Initialise un joueur (Player) avec le nom  et un rôle
Player::Player() : Entity("Player"), m_role("", 0, 0, 0, 0) {
}

// Constructeur avec un rôle
// Permet de créer un joueur avec un rôle spécifique
Player::Player(Role &role) : Entity("Player"), m_role(role) {
    setName(getName() + " " + role.getRoleName());
    Player::setStats();
}
// Initialisation des statistiques
//Calcule les points de vie (HP), l'attaque, et la défense du joueur en fonction des caractéristiques du rôle.
void Player::setStats() {
    this->HP = 20 * m_role.getVitality() + 10 * m_role.getStrength();
    this->attack = 5 * m_role.getStrength() + 2 * m_role.getIntel();
    this->defense = 5 * m_role.getStrength() + 2 * m_role.getDexterity();
}
Inventory& Player::getInventory() {
    return inventory;
}
void Player::setAttack(int newAttack) {  // Setter implementation
    this->attack = newAttack;
}

int Player::getAttack() const {  // Getter implementation
    return this->attack;
}
