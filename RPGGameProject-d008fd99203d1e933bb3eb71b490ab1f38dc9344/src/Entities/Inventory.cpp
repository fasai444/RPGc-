#include "Inventory.hpp"
#include <algorithm> // For std::remove_if
#include <vector>    // For std::vector
#include <string>    // For std::string

void Inventory::addItem(const Item& item) {
    items.push_back(item);
    std::cout << "Added item: " << item.getName() << "\n";
}

void Inventory::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
                               [&](const Item& item) { return item.getName() == itemName; }), items.end());
}

void Inventory::showInventory() const {
    if (items.empty()) {
        std::cout << "Your inventory is empty.\n";
        return;
    }

    std::cout << "Your inventory contains:\n";
    for (const auto& item : items) {
        std::cout << " - " << item.getName()
                  << " (Type: " << item.getType()
                  << ", Effect: " << item.getEffect() << ")\n";
    }
}

bool Inventory::isEmpty() const {
    return items.empty();
}
