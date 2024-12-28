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
    Item* getItem(const std::string& itemName);
    const std::vector<Item>& getItems() const; // Add this declaration

};

#endif // INVENTORY_HPP
