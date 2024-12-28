#include "Inventory.hpp"
#include "../Utils/StringUtils.hpp" // Adjust based on your directory structure

#include <algorithm> // For std::remove_if
#include <vector>    // For std::vector
#include <string>    // For std::string
#include <algorithm>
#include <cctype>




void Inventory::addItem(const Item& item) {
    items.push_back(item);
    std::cout << "DEBUG: Added item " << item.getName() << "\n";
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

    std::cout << "DEBUG: Inventory contains " << items.size() << " items:\n";
    for (const auto& item : items) {
        std::cout << " - " << item.getName()
                  << " (Type: " << item.getType()
                  << ", Effect: " << item.getEffect() << ")\n";
    }
}


Item* Inventory::getItem(const std::string& itemName) {
    std::string normalizedInput = normalizeString(itemName);  // Normalize input
    for (auto& item : items) {
        if (normalizeString(item.getName()) == normalizedInput) {  // Compare normalized names
            return &item;
        }
    }
    return nullptr;  // Return nullptr if item is not found
}
const std::vector<Item>& Inventory::getItems() const {
    return items;  // Return the internal list of items
}

bool Inventory::isEmpty() const {
    return items.empty();
}

