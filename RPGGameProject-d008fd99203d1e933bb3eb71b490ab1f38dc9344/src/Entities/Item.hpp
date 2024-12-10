#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>

class Item {
private:
    std::string name;
    std::string type; // e.g., "Potion", "Weapon", "Armor"
    int effect;       // e.g., HP restoration or attack boost

public:
    Item(const std::string& name, const std::string& type, int effect);
    std::string getName() const;
    std::string getType() const;
    int getEffect() const;
};

#endif
