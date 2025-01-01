//
//
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Entity.hpp"
#include "Role.hpp"
#include "Inventory.hpp"

class Player : public Entity {

protected:
    Role m_role;
private:

    Inventory inventory;

public:
    Player();
    Player(Role &role);

    void setStats();
    Inventory& getInventory(); // Getter inventory

    void setAttack(int newAttack);  // Add setter
    int getAttack() const;
};



#endif //PLAYER_HPP
