#ifndef FIGHTER_H
#define FIGHTER_H

#include "enemy.h"

class Fighter:public Enemy
{
    public:
    Fighter(sf::Vector2f position);
    void fire();
    private:
    int health;
    sf::CircleShape mFighter;
};


#endif