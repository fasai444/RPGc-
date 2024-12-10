//
// Created by alexi on 12/11/2024.
//

#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <string>


class Entity {

protected:
    std::string name;
    int HP;
    int attack;
    int defense;


public:
    Entity();
    Entity(std::string name);
    Entity(std::string name, int HP, int attack, int defense);
    virtual ~Entity() = default;

    std::string getName();
    void setName(std::string name);

    virtual void setStats();
    int getHP();
    void setHP(int HP);
    int getAttack();
    int getDefense();

};



#endif //ENTITY_HPP
