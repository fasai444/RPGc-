#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "Item.hpp"
#include <vector>
#include <iostream>

class Inventory {
private:
    std::vector<Item> items;

public:
    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    void showInventory() const;
    bool isEmpty() const;
};

#endif // INVENTORY_HPP
