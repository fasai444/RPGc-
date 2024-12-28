#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity {
public:
    Enemy();  // Default constructor
    Enemy(std::string name, int HP, int attack, int defense);  // Parameterized constructor

    static Enemy generateEnemy(int level);  // Static function to generate random enemies

    bool isDead() const { return getHP() <= 0; }  // Check if the enemy is dead
};

class Zombie : public Enemy {
public:
    Zombie() : Enemy("Zombie", 300, 10, 15) {}
};

class Skeleton : public Enemy {
public:
    Skeleton() : Enemy("Squelette", 200, 20, 5) {}
};

#endif // ENEMY_HPP
