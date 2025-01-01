#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include <string>

class Enemy : public Entity {
private:
    std::string ability;

public:
    Enemy();
    Enemy(std::string name, int HP, int attack, int defense, std::string ability);  // Constructor with ability

    static Enemy generateEnemy(int level);

    std::string getAbility() const;
};

#endif
