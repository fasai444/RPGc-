// Combat.hpp
#ifndef COMBAT_HPP
#define COMBAT_HPP
#include "../Entities/Player.hpp"
#include "../Entities/Enemy.hpp"

class Combat {
public:
    Combat();
    Combat(Player &player, Enemy enemy);  // Pass Player by reference
    ~Combat();

    void insideCombat();
    bool isEnemyDefeated() const;

private:
    Player &player;  // Reference to the Player
    Enemy enemy;
    bool inCombat;
};


#endif // COMBAT_HPP
