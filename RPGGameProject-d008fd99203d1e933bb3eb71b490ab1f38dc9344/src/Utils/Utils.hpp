//
// Created by alexi on 13/11/2024.
//

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <limits>
#include <random>

class Utils {

public:

    static void clearInput() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    static int generateRandomInt(int min, int max) {
        std::random_device rd; //
        std::mt19937 gen(rd()); // générateur MersenTwister
        std::uniform_int_distribution<> dis(min, max); // plage  d'entier
        return dis(gen);
    }

    static int getRandomNumber(int min, int max) {  // Correct definition
        return rand() % (max - min + 1) + min;
    }

    template<typename T>
    static T validateInput(T& val, std::string message) {

        while (true) {
            std::cout << message;
            if (std::cin >> val) {
                break;
            } else {
                std::cout << "Veuillez entrer une option valide !" << std::endl;
                clearInput();
            }
        }
        clearInput(); // Nettoie les caractères restants après validation
        return val;
    }

    //  renderLifeBar
    static void renderLifeBar(const std::string& name, int currentHP, int maxHP) {
        float hpPercentage = static_cast<float>(currentHP) / maxHP;
        int barWidth = 20; // Width of the life bar
        int filledWidth = static_cast<int>(hpPercentage * barWidth);

        std::cout << name << " HP: [";
        for (int i = 0; i < barWidth; ++i) {
            if (i < filledWidth) {
                std::cout << "#"; // Filled portion
            } else {
                std::cout << " "; // Empty portion
            }
        }
        std::cout << "] " << currentHP << "/" << maxHP << "\n";
    }
};

#endif //UTILS_HPP
