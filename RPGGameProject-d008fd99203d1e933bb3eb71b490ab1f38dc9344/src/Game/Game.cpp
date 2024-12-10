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
    run();  // Start the main game loop
}

void Game::run() {
    // The character selection menu shouldn't be displayed again after initialization.
    while (running) {
        int choice;
        UI::printGameMenu(); // Prints the menu (Combat, Inventory, etc.)
        Utils::validateInput(choice, "Choisissez une option :");

        switch (choice) {
            case 1: // Combat
                Combat(player, Enemy::generateEnemy()).insideCombat();
                break;
            case 2: // View Inventory
                player.getInventory().showInventory();
                break;
            case 3: // W.I.P Options
                std::cout << "Option under construction.\n";
                break;
            case 4: // Quit
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
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
}
