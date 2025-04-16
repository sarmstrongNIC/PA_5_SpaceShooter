#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
    public:
    Enemy(){spacing = 0;}
    Enemy(int sp){spacing = sp;};
    //use spacing and count to spawn ships in a row vector is origin point for row;
    void spawn(int count, sf::Vector2f());

    private:
    int spacing;

};

class Fighter:public Enemy
{
    public:
    Fighter():Enemy(4){health = 1;}
    void fire();
    private:
    int health;
};





#endif