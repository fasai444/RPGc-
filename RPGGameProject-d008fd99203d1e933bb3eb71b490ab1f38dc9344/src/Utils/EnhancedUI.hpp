#ifndef ENHANCED_UI_HPP
#define ENHANCED_UI_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

namespace Color {
    const std::string RESET   = "\033[0m";
    const std::string RED     = "\033[31m";
    const std::string GREEN   = "\033[32m";
    const std::string YELLOW  = "\033[33m";
    const std::string BLUE    = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN    = "\033[36m";
    const std::string BOLD    = "\033[1m";
}

class EnhancedUI {
public:
    static void clearScreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    static void displayTitle() {
        clearScreen();
        std::cout << Color::CYAN << Color::BOLD;
        std::cout << R"(
    __  __                           _   _
    \ \/ /__ _ _ __ ___  __ _ _ __ | |_| |__
     \  // _` | '__/ __|/ _` | '_ \| __| '_ \
     /  \ (_| | |  \__ \ (_| | | | | |_| | | |
    /_/\_\__,_|_|  |___/\__,_|_| |_|\__|_| |_|
    )" << '\n';
        std::cout << Color::RESET << "\n";
    }

    static void displayClassSelection() {
        clearScreen();
        std::cout << Color::CYAN << Color::BOLD;
        std::cout << "======== SELECT CLASS ========\n\n";
        std::cout << "1. Warrior - Strong & Tough\n";
        std::cout << "2. Mage - Powerful Magic\n";
        std::cout << "3. Archer - Swift & Precise\n";
        std::cout << "============================\n" << Color::RESET;
    }

    static void displayMainMenu() {
        displayTitle();
        std::cout << Color::CYAN << Color::BOLD;
        std::cout << "======== MAIN MENU ========\n\n";
        std::cout << "1. Combat\n";
        std::cout << "2. Inventory\n";
        std::cout << "3. Options (W.I.P)\n";
        std::cout << "4. Quit\n";
        std::cout << "=========================\n" << Color::RESET;
    }

    static void displayHealthBar(const std::string& name, int currentHP, int maxHP) {
        float percentage = static_cast<float>(currentHP) / maxHP;
        int barWidth = 20;
        int filledWidth = static_cast<int>(percentage * barWidth);

        std::cout << std::setw(10) << std::left << name << " [";
        for (int i = 0; i < barWidth; i++) {
            if (i < filledWidth) {
                std::cout << Color::GREEN << "*" << Color::RESET;
            } else {
                std::cout << ".";
            }
        }
        std::cout << "] " << currentHP << "/" << maxHP << "\n";
    }

    static void displayCombatScreen(const Player& player, const Enemy& enemy) {
        clearScreen();
        std::cout << Color::YELLOW << Color::BOLD;
        std::cout << "========= COMBAT =========\n\n" << Color::RESET;

        displayHealthBar(player.getName(), player.getHP(), 100);
        displayHealthBar(enemy.getName(), enemy.getHP(), enemy.getHP());

        std::cout << Color::CYAN << "\nActions:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Run\n";
        std::cout << "3. Use Item\n";
        std::cout << "=======================\n" << Color::RESET;
    }

    static void displayInventoryScreen(const Inventory& inventory) {
        clearScreen();
        std::cout << Color::MAGENTA << Color::BOLD;
        std::cout << "======== INVENTORY ========\n\n" << Color::RESET;

        const auto& items = inventory.getItems();
        if (items.empty()) {
            std::cout << Color::YELLOW << "Inventory is empty!\n";
        } else {
            for (size_t i = 0; i < items.size(); ++i) {
                const auto& item = items[i];
                std::cout << Color::CYAN;
                std::cout << i + 1 << ". ";
                std::cout << std::setw(25) << std::left << item.getName()
                          << " (" << item.getType() << ")\n";
            }
        }
        std::cout << Color::MAGENTA;
        std::cout << "========================\n" << Color::RESET;
    }
};

#endif // ENHANCED_UI_HPP