#include "Inventory.hpp"
#include "../Utils/StringUtils.hpp"

#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>



// Cette méthode ajoute un nouvel objet à la liste des items de l'inventaire.
void Inventory::addItem(const Item& item) {
    items.push_back(item);
    //std::cout << "DEBUG: Added item " << item.getName() << "\n";
}

// Cette méthode supprime un objet spécifique de l'inventaire en fonction de son nom.
void Inventory::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
                               [&](const Item& item) { return item.getName() == itemName; }), items.end());
}

// Cette méthode affiche tous les objets de l'inventaire avec leurs types et effets.
void Inventory::showInventory() const {
    if (items.empty()) {
        std::cout << "Your inventory is empty.\n";
        return;
    }

    std::cout << " Inventory contains " << items.size() << " items:\n";
    for (const auto& item : items) {
        std::cout << " - " << item.getName()
                  << " (Type: " << item.getType()
                  << ", Effect: " << item.getEffect() << ")\n";
    }
}

// Recherche d'un objet dans l'inventaire
// Retourne un pointeur vers l'objet correspondant au nom donné
Item* Inventory::getItem(const std::string& itemName) {
    std::string normalizedInput = normalizeString(itemName);  // Normalize input
    for (auto& item : items) {
        if (normalizeString(item.getName()) == normalizedInput) {  // Compare normalized names
            return &item;
        }
    }
    return nullptr;
}
// Retourne tous les objets de l'inventaire

const std::vector<Item>& Inventory::getItems() const {
    return items;  //
}

// Vérifie si l'inventaire est vide
// Retourne true si l'inventaire ne contient aucun objet
bool Inventory::isEmpty() const {
    return items.empty();
}

