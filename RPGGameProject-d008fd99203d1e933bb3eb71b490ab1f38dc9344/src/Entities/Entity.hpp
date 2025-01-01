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

    std::string getName() const;
    void setName(std::string name);

    virtual void setStats();
    int getHP() const;
    void setHP(int HP);

    int getAttack() const;
    int getDefense() const;

    bool isDead() const { return HP <= 0; }
};

#endif //ENTITY_HPP
