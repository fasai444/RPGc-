#include <iostream>

#include "Entities/Player.hpp"
#include "Utils/Utils.hpp"
#include "Utils/UI.hpp"
#include "Game/Game.hpp"

Player selectClass();

int main() {
    Player player = selectClass();

    player.getInventory().addItem(Item("Health Potion", "Potion", 50));
    player.getInventory().addItem(Item("Sword", "Weapon", 10));

    Game game(player);
    game.start();

    return 0;
}

Player selectClass() {
    int choice;
    Warrior warrior{};
    Archer archer{};
    Mage mage{};

    UI::printSelectClass();

    Utils::validateInput(choice, "Choisissez une option :");

    switch (choice) {
        case 1:
            return Player(warrior);
        case 2:
            return Player(mage);
        case 3:
            return Player(archer);
        default:
            return Player();
    }
}