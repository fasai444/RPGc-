#ifndef GAME_HPP
#define GAME_HPP

#include "../Entities/Player.hpp"

class Game {
private:
    bool running;
    Player player; // Ensure this is properly declared
    void initializePlayer(); // Declare initializePlayer

public:
    Game();
    Game(Player player);
    ~Game();

    void start();
    void run();
};

#endif // GAME_HPP
