//
// Created by alexi on 12/11/2024.
//

#ifndef ROLE_HPP
#define ROLE_HPP
#include <string>


class Role {

protected:
    std::string roleName;
    int vitality;
    int strength;
    int intel;
    int dexterity;

public:
    Role(std::string roleName, int vitality, int strength, int intel, int dextirity);

    std::string getRoleName();
    int getVitality();
    int getStrength();
    int getIntel();
    int getDexterity();

};

class Warrior : public Role {

public:
    Warrior() : Role("Warrior", 25, 40, 10, 25) {};
};

class Archer : public Role {
public:
    Archer() : Role("Archer", 20, 10, 30, 40) {};
};

class Mage : public Role {
public:
    Mage() : Role("Mage", 15, 15, 40, 30) {};
};

#endif //ROLE_HPP
