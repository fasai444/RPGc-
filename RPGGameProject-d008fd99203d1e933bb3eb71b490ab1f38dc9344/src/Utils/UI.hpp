// UI.hpp - Update your existing UI.hpp with these new functions
#ifndef UI_HPP
#define UI_HPP

#include "EnhancedUI.hpp"

class UI {
public:
    static void printSelectClass() {
        EnhancedUI::clearScreen();
        std::cout << Color::CYAN << Color::BOLD;
        std::cout << "╔═══════════ SELECT CLASS ═══════════╗\n";
        std::cout << "│ 1. ⚔️  Warrior - Strong & Tough    │\n";
        std::cout << "│ 2. 🧙 Mage - Powerful Magic        │\n";
        std::cout << "│ 3. 🏹 Archer - Swift & Precise     │\n";
        std::cout << "╚═══════════════════════════════════╝\n" << Color::RESET;
    }

    static void printGameMenu() {
        EnhancedUI::clearScreen();
        std::cout << Color::CYAN << Color::BOLD;
        std::cout << "╔═══════════ XARSAROTH ═══════════╗\n";
        std::cout << "│ 1. ⚔️  Combat                    │\n";
        std::cout << "│ 2. 🎒 Inventory                  │\n";
        std::cout << "│ 3. ⚙️  Options (W.I.P)           │\n";
        std::cout << "│ 4. 🚪 Exit                       │\n";
        std::cout << "╚═══════════════════════════════════╝\n" << Color::RESET;
    }

    static void printCombatMenu(const Player& player, const Enemy& enemy) {
        EnhancedUI::clearScreen();
        std::cout << Color::YELLOW << Color::BOLD;
        std::cout << "╔════════════════ COMBAT ════════════════╗\n" << Color::RESET;

        // Display health bars
        EnhancedUI::displayHealthBar(player.getName(), player.getHP(), 1000);  // Assuming max HP is 1000
        EnhancedUI::displayHealthBar(enemy.getName(), enemy.getHP(), enemy.getHP());

        std::cout << Color::CYAN << "\nActions:\n";
        std::cout << "│ 1. ⚔️  Attack                          │\n";
        std::cout << "│ 2. 🏃 Run                              │\n";
        std::cout << "│ 3. 🎒 Use Item                         │\n";
        std::cout << Color::YELLOW;
        std::cout << "╚══════════════════════════════════════╝\n" << Color::RESET;
    }
};

#endif