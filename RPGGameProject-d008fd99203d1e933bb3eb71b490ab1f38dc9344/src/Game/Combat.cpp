#include "Combat.hpp"
#include "../Utils/StringUtils.hpp" // Ajustez en fonction de votre structure de répertoires

#include <iostream>
#include "../Utils/Utils.hpp"
#include <algorithm>
#include <cctype>

// Constructeur par défaut
Combat::Combat() : player(*(new Player())), enemy(Enemy()) {
    this->inCombat = false; // Le combat n'est pas en cours par défaut
}

// Constructeur avec paramètres
Combat::Combat(Player &player, Enemy enemy) : player(player), enemy(enemy) {
    this->inCombat = enemy.getHP() > 0; // Vérifie si l'ennemi a des points de vie pour commencer le combat

    // Ajoute des objets à l'inventaire du joueur si non déjà présents
    if (!player.getInventory().getItem("Épée en fer")) {
        player.getInventory().addItem(Item("Épée en fer", "Weapon", 50)); // Arme de base
    }
    if (!player.getInventory().getItem("Potion de vie")) {
        player.getInventory().addItem(Item("Potion de vie", "Potion", 100)); // Potion de soin
    }
}

// Destructeur
Combat::~Combat() {}

// Boucle principale du combat
void Combat::insideCombat() {
    // Tant que ni le joueur ni l'ennemi ne sont morts
    while (!player.isDead() && !enemy.isDead()) {
        int choice;
        std::cout << "Tour de " << player.getName() << "\n";
        std::cout << "HP du " << enemy.getName() << " : " << enemy.getHP() << "\n";

        // Menu d'options pour le joueur
        std::cout << "1. Attaquer\n";
        std::cout << "2. Fuir\n";
        std::cout << "3. Utiliser un objet\n";
        Utils::validateInput(choice, "Que voulez-vous faire ? :");

        switch (choice) {
            case 1: { // Logique pour attaquer
                int damage = player.getAttack(); // Obtenir les dégâts du joueur
                enemy.setHP(enemy.getHP() - damage); // Réduire les HP de l'ennemi
                std::cout << "Vous attaquez et infligez " << damage << " points de dégâts !" << std::endl;
                std::cout << "Le " << enemy.getName() << " a maintenant " << enemy.getHP() << " HP." << std::endl;
                break;
            }
            case 2: { // Logique pour fuir le combat
                std::cout << "Vous fuyez le combat !" << std::endl;
                return; // Sortir du combat
            }
            case 3: { // Utiliser un objet
                if (!player.getInventory().isEmpty()) { // Vérifie si l'inventaire n'est pas vide
                    player.getInventory().showInventory(); // Affiche l'inventaire
                    std::cout << "Entrez le numéro de l'objet à utiliser : ";

                    int itemIndex;
                    Utils::validateInput(itemIndex, "Choisissez un numéro :"); // Valide l'entrée de l'utilisateur

                    // Vérifie si l'index est valide
                    const auto& inventoryItems = player.getInventory().getItems();
                    if (itemIndex > 0 && itemIndex <= static_cast<int>(inventoryItems.size())) {
                        const Item& item = inventoryItems[itemIndex - 1]; // Accède à l'objet via l'index
                        if (item.getType() == "Potion") { // Si c'est une potion
                            player.setHP(player.getHP() + item.getEffect()); // Restaure les HP du joueur
                            std::cout << "Vous utilisez " << item.getName() << " et récupérez " << item.getEffect() << " HP.\n";
                            player.getInventory().removeItem(item.getName()); // Supprime l'objet utilisé
                        } else if (item.getType() == "Weapon") { // Si c'est une arme
                            int damage = item.getEffect();
                            enemy.setHP(enemy.getHP() - damage); // Inflige des dégâts à l'ennemi
                            std::cout << "Vous utilisez " << item.getName() << " et infligez " << damage << " points de dégâts !\n";
                            std::cout << "Le " << enemy.getName() << " a maintenant " << enemy.getHP() << " HP.\n";
                            player.getInventory().removeItem(item.getName()); // Supprime l'objet utilisé
                        } else {
                            std::cout << "Cet objet n'est pas utilisable.\n";
                        }
                    } else {
                        std::cout << "Numéro invalide. Veuillez réessayer.\n";
                    }
                } else {
                    std::cout << "Votre inventaire est vide.\n";
                }
                break;
            }

            default: { // Si l'utilisateur entre une option invalide
                std::cout << "Choix invalide.\n";
                break;
            }
        }

        // Logique pour l'attaque de l'ennemi
        if (!enemy.isDead()) {
            int damage = enemy.getAttack(); // Obtenir les dégâts de l'ennemi
            player.setHP(player.getHP() - damage); // Réduire les HP du joueur
            std::cout << "Le " << enemy.getName() << " vous attaque et inflige " << damage << " points de dégâts !" << std::endl;
            std::cout << "Il vous reste " << player.getHP() << " HP." << std::endl;
        }
    }
}

// Vérifie si l'ennemi est vaincu
bool Combat::isEnemyDefeated() const {
    return enemy.getHP() <= 0; // Renvoie vrai si les HP de l'ennemi sont <= 0
}
