#include "Enemy.hpp"
#include "../Utils/Utils.hpp"

// Constructeur par défaut
// Initialise un ennemi avec des valeurs par défaut
Enemy::Enemy() : Entity("", 0, 0, 0), ability("") {}

//Constructeur avec paramètres
// Permet de créer un ennemi
Enemy::Enemy(std::string name, int HP, int attack, int defense, std::string ability)
        : Entity(std::move(name), HP, attack, defense), ability(std::move(ability)) {}

// Getter pour ability
// Retourne la capacité spéciale de l'ennemi
std::string Enemy::getAbility() const {
    return ability;
}

// Cette fonction crée un ennemi avec des caractéristiques spécifiques
Enemy Enemy::generateEnemy(int level) {
    int hp = 0, attack = 0, defense = 0;
    std::string ability;

    switch (level) {
        case 1:  //niv 1
            hp = 300;
            attack = 10;
            defense = 5;
            ability = "Poison";
            break;
        case 2:  //niv 2
            hp = 500;
            attack = 15;
            defense = 10;
            ability = "Stun";
            break;
        case 3:  //niv 3
            hp = 700;
            attack = 20;
            defense = 15;
            ability = "Web Trap";
            break;
        default:
            hp = 300;
            attack = 10;
            defense = 5;
            ability = "None";
    }
    // Retourne un objet Enemy avec les caractéristiques générées
    return Enemy("Enemy Level " + std::to_string(level), hp, attack, defense, ability);
}
