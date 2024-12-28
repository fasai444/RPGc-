#include <iostream>
#include "Entities/Player.hpp"
#include "Entities/Enemy.hpp"
#include "Utils/Utils.hpp"
#include "Utils/UI.hpp"
#include "Game/Game.hpp"
#include "Game/Combat.hpp"

Player selectClass();  // Forward declaration

int main() {
    int enemyLevel = 1;  // Start with level 1 (Zombie)
    bool inGame = true;

    // Select the player class (warrior, mage, or archer)
    Player player = selectClass();  // Make sure player is selected before combat

    while (inGame) {
        std::cout << "\n=============================\n";
        std::cout << "         XARSAROTH\n";
        std::cout << "=============================\n";
        std::cout << "1. Combattre\n";
        std::cout << "2. Consulter l'inventaire\n";
        std::cout << "3. Autres options (W.I.P)\n";
        std::cout << "4. Quitter\n";
        std::cout << "=============================\n";

        int choice;
        Utils::validateInput(choice, "Choisissez une option :");

        switch (choice) {
            case 1: {
                // Create the enemy based on the current level
                Enemy enemy = Enemy::generateEnemy(enemyLevel);  // Generate the current enemy

                // Start combat with the generated enemy
                Combat combat(player, enemy);  // Pass player and enemy into the Combat constructor
                combat.insideCombat();  // Start the combat loop

                if (combat.isEnemyDefeated()) {  // Check if the enemy is defeated
                    enemyLevel++;  // Increase the level for the next enemy
                    std::cout << "Niveau suivant! Le prochain ennemi sera plus fort.\n";
                }

                break;
            }
            case 2:
                player.getInventory().showInventory();  // Show inventory
                break;
            case 3:
                std::cout << "Autres options en développement...\n";
                break;
            case 4:
                std::cout << "Quitter le jeu...\n";
                inGame = false;
                break;
            default:
                std::cout << "Option invalide. Essayez encore.\n";
                break;
        }
    }

    return 0;
}

Player selectClass() {
    int choice;
    Warrior warrior{};
    Archer archer{};
    Mage mage{};

    UI::printSelectClass();  // Assuming this function prints the class selection options

    Utils::validateInput(choice, "Choisissez une option :");

    switch (choice) {
        case 1:
            return Player(warrior);  // Return a player with a Warrior class
        case 2:
            return Player(mage);  // Return a player with a Mage class
        case 3:
            return Player(archer);  // Return a player with an Archer class
        default:
            std::cout << "Choix invalide, classe par défaut (Guerrier) choisie.\n";
            return Player(warrior);  // Default to Warrior if invalid input
    }
}
