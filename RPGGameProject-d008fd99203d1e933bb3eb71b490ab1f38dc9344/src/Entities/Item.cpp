#include "Item.hpp"
//constructeur avec parametres
Item::Item(const std::string& name, const std::string& type, int effect)
        : name(name), type(type), effect(effect) {}

std::string Item::getName() const { return name; }
std::string Item::getType() const { return type; }
int Item::getEffect() const { return effect; }

