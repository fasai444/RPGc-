#include "Combat.hpp"
#include "../Utils/StringUtils.hpp"
#include "../Utils/Utils.hpp"
#include "../Utils/EnhancedUI.hpp"  // Adjust the path based on your directory structure
#include "UI.hpp"
#include <chrono>
#include <thread>
#include <iostream>
#include <algorithm>
#include <cctype>

// Constructeur par défaut
Combat::Combat() : player(*(new Player())), enemy(Enemy()) {
    this->inCombat = false; // Le combat n'est pas en cours par défaut
}

// Constructeur avec paramètres
// Permet de démarrer un combat entre un joueur donné et un ennemi.
// Si l'ennemi a des points de vie (> 0), le combat commence.
Combat::Combat(Player &player, Enemy enemy) : player(player), enemy(enemy) {
    this->inCombat = enemy.getHP() > 0; // Vérifie si l'ennemi a des points de vie pour commencer le combat

    // Ajoute des objets à l'inventaire du joueur si non déjà présents
    if (!player.getInventory().getItem("sword")) {
        player.getInventory().addItem(Item("sword", "Weapon", 50)); // Arme de base
    }
    if (!player.getInventory().getItem("Potion")) {
        player.getInventory().addItem(Item("Potion", "Potion", 100)); // Potion de soin
    }
}

// Destructeur
Combat::~Combat() {}

// Affiche l'interface de combat
void displayCombatUI(const Player& player, const Enemy& enemy) {
    UI::printCombatMenu(player, enemy);
}

// Boucle principale du combat
// Gère les actions du joueur et de l'ennemi jusqu'à ce que l'un d'eux soit vaincu.
void Combat::insideCombat() {
    while (!player.isDead() && !enemy.isDead()) {
        EnhancedUI::displayCombatScreen(player, enemy); // Affiche l'état actuel du combat

        int choice;
        Utils::validateInput(choice, "Choose your action: ");

        switch (choice) {
            case 1: {  // pour que le joueur attaque
                int damage = player.getAttack();
                enemy.setHP(enemy.getHP() - damage);
                std::cout << Color::GREEN << "You attack and deal " << damage << " damage\n" << Color::RESET;
                break;
            }
            case 2: {  // fuir
                std::cout << Color::YELLOW << "You flee from combat\n" << Color::RESET;
                return;
            }
            case 3: {  // Utiliser un objet
                if (!player.getInventory().isEmpty()) {
                    // afficher inventory
                    EnhancedUI::displayInventoryScreen(player.getInventory());

                    int itemIndex;
                    Utils::validateInput(itemIndex, "Enter the number of the item to use: ");

                    // objet selectionner
                    const auto& inventoryItems = player.getInventory().getItems();
                    if (itemIndex > 0 && itemIndex <= static_cast<int>(inventoryItems.size())) {
                        const Item& item = inventoryItems[itemIndex - 1];

                        // Check the item type
                        if (item.getType() == "Potion") {//utilisation d un objet
                            player.setHP(player.getHP() + item.getEffect());
                            std::cout << Color::GREEN << "You use " << item.getName() << " and recover "
                                      << item.getEffect() << " HP.\n" << Color::RESET;
                            player.getInventory().removeItem(item.getName());
                        } else if (item.getType() == "Weapon") {//utiliser sword
                            int damage = item.getEffect();
                            enemy.setHP(enemy.getHP() - damage);
                            std::cout << Color::GREEN << "You use " << item.getName() << " and deal "
                                      << damage << " damage to " << enemy.getName() << ".\n" << Color::RESET;
                            player.getInventory().removeItem(item.getName());
                        } else {
                            std::cout << Color::YELLOW << "This item cannot be used in combat.\n" << Color::RESET;
                        }
                    } else {
                        std::cout << Color::RED << "Invalid item selection.\n" << Color::RESET;
                    }
                } else {
                    std::cout << Color::RED << "Your inventory is empty.\n" << Color::RESET;
                }
                break;
            }

            default:
                std::cout << Color::RED << "Invalid choice.\n" << Color::RESET;
                continue;
        }

        // Enemy
        if (!enemy.isDead()) {
            if (enemy.getAbility() == "Poison") {
                int poisonDamage = 5;
                player.setHP(player.getHP() - poisonDamage);
                std::cout << Color::RED << enemy.getName() << " uses Poison! You take "<< poisonDamage << " damage over time.\n" << Color::RESET;
            } else if (enemy.getAbility() == "Stun") {
                bool isStunned = Utils::getRandomNumber(0, 1);  // 50 chance
                if (isStunned) {
                    std::cout << Color::RED << enemy.getName() << " uses Stun! You are stunned and lose your next turn.\n" << Color::RESET;
                    // Pause de 2 secondes
                    std::this_thread::sleep_for(std::chrono::seconds(2));  // Pause for 2 seconds
                    continue;
                }
            } else if (enemy.getAbility() == "Web Trap") {
                int attackReduction = 3;
                player.setAttack(player.getAttack() - attackReduction);
                std::cout << Color::RED << enemy.getName() << " uses Web Trap! Your attack is reduced by "
                          << attackReduction << " for the next 2 turns.\n" << Color::RESET;
                std::this_thread::sleep_for(std::chrono::seconds(2));  // Pause for 2 seconds
            }

            //   Attaque basique de l'ennemi
            int damage = enemy.getAttack();
            player.setHP(player.getHP() - damage);
            std::cout << Color::RED << enemy.getName() << " attacks and deals "
                      << damage << " damage!\n" << Color::RESET;
        }
    }
    // Vérifie si le joueur ou l'ennemi a gagné
    if (player.getHP() > 0) {
        std::cout << Color::GREEN << "You defeated the enemy!\n" << Color::RESET;
    } else {
        std::cout << Color::RED << "You were defeated...\n" << Color::RESET;
    }
}


// Vérifie si l'ennemi est vaincu
bool Combat::isEnemyDefeated() const {
    return enemy.getHP() <= 0;
}
