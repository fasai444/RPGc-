#ifndef GAME_HPP
#define GAME_HPP

#include "../Entities/Player.hpp"
#include "Combat.hpp"  // Include Combat to use it

class Game {
private:
    bool running;
    Player player; // The player object
    void initializePlayer(); // Declare initializePlayer

public:
    Game();
    Game(Player player); // Constructor that accepts a Player object
    ~Game();

    void start();
    void run();
    void gameLoop(); // Declare gameLoop
    void rewardPlayer();
};

#endif // GAME_HPP
