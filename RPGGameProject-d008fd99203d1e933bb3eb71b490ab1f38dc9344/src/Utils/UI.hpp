//
// Created by alexi on 19/11/2024.
//

#ifndef UI_HPP
#define UI_HPP

#include <iostream>

class UI {
public:
    static void printSelectClass() {
        std::cout << "=============================\n";
        std::cout << "    SELECTION DE CLASSE      \n";
        std::cout << "=============================\n";
        std::cout << "1. Guerrier - Combattant de melee robuste avec une grande defense.\n";
        std::cout << "2. Mage - Lanceur de sorts puissant mais fragile en defense.\n";
        std::cout << "3. Archer - Combattant agile specialise dans les attaques a distance.\n";
        std::cout << "=============================\n";
    }

    static void printGameMenu() {
        std::cout << "=============================\n";
        std::cout << "         XARSAROTH           \n";
        std::cout << "=============================\n";
        std::cout << "1. Combattre\n";
        std::cout << "2. Consulter l'inventaire\n";
        std::cout << "3. Autres options (W.I.P)\n";
        std::cout << "4. Quitter\n";
        std::cout << "=============================\n";
    }


    static void printCombatMenu() {
        std::cout << "=============================\n";
        std::cout << "         COMBAT              \n";
        std::cout << "=============================\n";

    }

};



#endif //UI_HPP
