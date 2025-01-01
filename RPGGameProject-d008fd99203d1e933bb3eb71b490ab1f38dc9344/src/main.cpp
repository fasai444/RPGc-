#include <iostream>
#include "Entities/Player.hpp"
#include "Entities/Enemy.hpp"
#include "Utils/Utils.hpp"
#include "Utils/UI.hpp"
#include "Game/Game.hpp"
#include "Game/Combat.hpp"
#include "Utils/EnhancedUI.hpp"
#include <thread>
#include <chrono>
// Sélection de la classe du joueur
Player selectClass() {
    EnhancedUI::displayClassSelection();

    int choice;
    Utils::validateInput(choice, "Choose your class (1-3): ");

    Warrior warrior{};
    Archer archer{};
    Mage mage{};

    switch (choice) {
        case 1:
            return Player(warrior);
        case 2:
            return Player(mage);
        case 3:
            return Player(archer);
        default:
            std::cout << "Invalid choice, defaulting to Warrior.\n";
            return Player(warrior);
    }
}
void animatedLoadingScreen(const std::string& message) {
    EnhancedUI::clearScreen();
      const std::string dots ="...";
     std::cout << Color::CYAN << Color::BOLD << message;
    for (char dot : dots) {
        std::cout << dot<<std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << Color::RESET << std::endl;
}
int main() {
    int enemyLevel = 1;
    bool inGame = true;

    // Affichage de l'écran de chargement
    std::cout << "Loading XARSAROTH...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Selection du classe du joueur
    Player player = selectClass();

    while (inGame) {
        EnhancedUI::displayMainMenu();// Affiche le menu principal

        int choice;
        Utils::validateInput(choice, "Enter your choice (1-4): ");

        switch (choice) {
            case 1: {
                Enemy enemy = Enemy::generateEnemy(enemyLevel);//genere un ennemi
                Combat combat(player, enemy);// initialise le combat
                combat.insideCombat();//demarre la boucle de combat

                if (combat.isEnemyDefeated()) {
                    enemyLevel++;
                    std::cout << Color::GREEN << "Level up! The next enemy will be stronger.\n" << Color::RESET;
                }
                break;
            }
            case 2://affiche l inventaire
                EnhancedUI::displayInventoryScreen(player.getInventory());
                std::cout << "\nPress Enter to continue...";
                std::cin.get();
                break;
            case 3://en cours de dev
                std::cout << Color::YELLOW << "Other options in development...\n" << Color::RESET;
                break;
            case 4://quitte le jeu
                std::cout << Color::RED << "Exiting game...\n" << Color::RESET;
                inGame = false;
                break;
            default:// option invalide
                std::cout << Color::RED << "Invalid option. Try again.\n" << Color::RESET;
                break;
        }
    }

    return 0;
}


