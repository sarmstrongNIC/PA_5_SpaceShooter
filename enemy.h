#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy
{
    public:
    Enemy(){spacing = 0;}
    Enemy(int sp){spacing = sp;};
    void spawn(int count, sf::Vector2f()); //use spacing and argument to spawn ships in a row;


    private:
    int spacing;

};

class fighter:public Enemy
{
    public:
    fighter(){health = 1;}
    private:
    int health;
    int count;
};





#endif