//
// Created by alexi on 19/11/2024.
//

#ifndef COMBAT_HPP
#define COMBAT_HPP
#include "../Entities/Player.hpp"
#include "../Entities/Enemy.hpp"


class Combat {
private:
    Player player;
    Enemy enemy;
    bool inCombat;

public:
    Combat();
    Combat(Player player, Enemy enemy);
    ~Combat();

    void insideCombat();

};



#endif //COMBAT_HPP
