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
        std::random_device rd; //Génère un seed aléatoire
        std::mt19937 gen(rd()); //Utilisation du générateur MersenTwister
        std::uniform_int_distribution<> dis(min, max); // plage [min, max] d'entier
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
};



#endif //UTILS_HPP
