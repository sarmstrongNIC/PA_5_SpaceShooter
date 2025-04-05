#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "spaceShip.h"

class Game
{
public:
    Game();
    ~Game(){};

    void handleInput();
    void update();
    void render();
    bool isDone() const;

private:
    friend class Enemy;
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    bool mIsDone;
   
};

#endif