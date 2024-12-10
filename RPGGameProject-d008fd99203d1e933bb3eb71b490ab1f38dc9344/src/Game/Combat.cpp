//
// Created by alexi on 19/11/2024.
//

#include "Combat.hpp"

#include <iostream>

#include "../Utils/Utils.hpp"

Combat::Combat() {
    this->inCombat = false;
}

Combat::Combat(Player player, Enemy enemy) {
    this->player = player;
    this->enemy = enemy;
    this->inCombat = enemy.getHP() > 0 || enemy.getHP() > 0;
}

Combat::~Combat() {

}

void Combat::insideCombat() {
    while (inCombat) {
        int choice;
        std::cout << "Tour de " << player.getName() << "\n";

        std::cout << "HP du " << enemy.getName() << " : " << enemy.getHP() << "\n";

        std::cout << "1. Attaquer\n";
        std::cout << "2. Fuir\n";

        Utils::validateInput(choice, "Que voulez-vous faire ? :");

        switch (choice) {
            case 1:
                enemy.setHP(enemy.getHP() - player.getAttack());
                break;
            case 2:
                inCombat = false;
            break;
            default:
                break;

        }

        std::cout << inCombat << "\n";

        this->inCombat = enemy.getHP() > 0 && player.getHP() > 0;
    }
}


