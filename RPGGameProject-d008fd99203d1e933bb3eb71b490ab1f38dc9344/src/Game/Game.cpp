#include "Game.hpp"
#include "Combat.hpp"
#include "../Utils/UI.hpp"
#include "../Utils/Utils.hpp"

Game::Game() {
    running = false;
}

Game::Game(Player player) : player(player) {
    running = false;
}

Game::~Game() {
    running = false;
}

void Game::start() {
    initializePlayer();  // Initialize the player when starting the game
    running = true;
    gameLoop();  // Start the main game loop
}


void Game::gameLoop() {
    bool inGame = true;
    int choice;

    // Let's assume you want the enemy level to be 1 for now
    int enemyLevel = 1;  // Set this dynamically based on the player's progression if needed

    while (inGame) {
        UI::printGameMenu();  // Prints the menu (Combat, Inventory, etc.)
        Utils::validateInput(choice, "Choisissez une option :");

        switch (choice) {
            case 1: {  // Combat
                Enemy zombie = Enemy::generateEnemy(enemyLevel);  // Pass the level to generate the enemy
                Combat combat(player, zombie);  // Initialize the combat with the player and the enemy
                combat.insideCombat();  // Start the combat loop

                if (combat.isEnemyDefeated()) {  // Check if the enemy was defeated
                    enemyLevel++;  // Increase the enemy level for next encounter
                    rewardPlayer();  // Reward the player
                    std::cout << "Niveau suivant! Le prochain ennemi sera plus fort.\n";
                }
                break;
            }
            case 2: {  // View Inventory
                player.getInventory().showInventory();  // Display the inventory contents
                int subChoice;
                std::cout << "1. Use an item\n2. Back to menu\n";
                Utils::validateInput(subChoice, "Choose an option:");

                if (subChoice == 1) {
                    std::string itemName;
                    std::cout << "Enter the name of the item to use: ";
                    std::cin.ignore(); // Clear the buffer
                    std::getline(std::cin, itemName);

                    Item* item = player.getInventory().getItem(itemName);
                    if (item) {
                        if (item->getType() == "Potion") {
                            player.setHP(player.getHP() + item->getEffect());
                            std::cout << "You used " << item->getName() << " and restored " << item->getEffect() << " HP.\n";
                            player.getInventory().removeItem(itemName);  // Remove used item
                        } else {
                            std::cout << "This item can't be used here.\n";
                        }
                    } else {
                        std::cout << "Item not found in inventory.\n";
                    }
                }
                break;
            }

            case 3: {  // Use an item
                if (!player.getInventory().isEmpty()) {
                    player.getInventory().showInventory();  // Show items
                    std::string itemName;
                    std::cout << "Enter the name of the item to use: ";
                    std::cin.ignore();
                    std::getline(std::cin, itemName);

                    Item* item = player.getInventory().getItem(itemName);
                    if (item) {
                        if (item->getType() == "Potion") {
                            player.setHP(player.getHP() + item->getEffect());
                            std::cout << "You used " << item->getName() << " and restored " << item->getEffect() << " HP.\n";
                            player.getInventory().removeItem(itemName);  // Remove the used item
                        } else {
                            std::cout << "This item cannot be used during combat.\n";
                        }
                    } else {
                        std::cout << "Item not found.\n";
                    }
                } else {
                    std::cout << "Your inventory is empty.\n";
                }
                break;
            }

            case 4: {  // Quit
                std::cout << "Quitter le jeu...\n";
                inGame = false;  // Exit the game loop
                break;
            }
            default: {  // Invalid option
                std::cout << "Option invalide. Essayez encore.\n";
                break;
            }
        }
    }
}
void Game::rewardPlayer() {
    int rewardType = Utils::getRandomNumber(1, 3);  // Randomly select a reward
    if (rewardType == 1) {
        player.getInventory().addItem(Item("Health Potion", "Potion", 50));
        std::cout << "You found a Health Potion!\n";
    } else if (rewardType == 2) {
        player.getInventory().addItem(Item("Iron Sword", "Weapon", 15));
        std::cout << "You found an Iron Sword!\n";
    } else {
        player.getInventory().addItem(Item("Gold Coin", "Misc", 100));
        std::cout << "You found 100 gold coins!\n";
    }
}


void Game::initializePlayer() {
    int choice;

    // Show character selection menu only once at the start
    UI::printSelectClass();  // Display class selection menu
    Utils::validateInput(choice, "Choisissez une option :");

    switch (choice) {
        case 1: {
            Warrior warriorRole;
            player = Player(warriorRole);  // Initialize Player with Warrior role
            player.getInventory().addItem(Item("Sword", "Weapon", 25));  // Add Warrior-specific weapon
            player.getInventory().addItem(Item("Health Potion", "Potion", 50));  // Add health potion
            std::cout << "You chose Warrior! You now have a Sword and a Health Potion.\n";
            break;
        }
        case 2: {
            Mage mageRole;
            player = Player(mageRole);  // Initialize Player with Mage role
            player.getInventory().addItem(Item("Staff", "Weapon", 20));  // Add Mage-specific weapon
            player.getInventory().addItem(Item("Health Potion", "Potion", 50));  // Add health potion
            std::cout << "You chose Mage! You now have a Staff and a Health Potion.\n";
            break;
        }
        case 3: {
            Archer archerRole;
            player = Player(archerRole);  // Initialize Player with Archer role
            player.getInventory().addItem(Item("Bow", "Weapon", 15));  // Add Archer-specific weapon
            player.getInventory().addItem(Item("Health Potion", "Potion", 50));  // Add health potion
            std::cout << "You chose Archer! You now have a Bow and a Health Potion.\n";
            break;
        }
        default: {
            // Default to Warrior if input is invalid
            Warrior defaultWarrior;
            player = Player(defaultWarrior);
            player.getInventory().addItem(Item("Sword", "Weapon", 25));
            player.getInventory().addItem(Item("Health Potion", "Potion", 50));
            std::cout << "Invalid choice. Defaulting to Warrior.\n";
            break;
        }
    }
    std::cout << "DEBUG: Player inventory size after initialization: "
              << player.getInventory().isEmpty() << "\n";
}
