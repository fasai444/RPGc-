//
// Created by alexi on 12/11/2024.
//

#include "Player.hpp"

Player::Player() : Entity("Player"), m_role("", 0, 0, 0, 0) {
}

Player::Player(Role &role) : Entity("Player"), m_role(role) {
    setName(getName() + " " + role.getRoleName());
    Player::setStats();
}

void Player::setStats() {
    this->HP = 20 * m_role.getVitality() + 10 * m_role.getStrength();
    this->attack = 5 * m_role.getStrength() + 2 * m_role.getIntel();
    this->defense = 5 * m_role.getStrength() + 2 * m_role.getDexterity();
}
Inventory& Player::getInventory() {
    return inventory;
}
