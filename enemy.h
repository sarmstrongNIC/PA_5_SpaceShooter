#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Enemy
{
    public:
    Enemy(){spacing = 0;}
    Enemy(int sp){spacing = sp;};
    //use spacing and count to spawn ships in a row vector is origin point for row;
    private:
    int spacing;

};



#endif