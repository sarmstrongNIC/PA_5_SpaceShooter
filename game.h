#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "enemy.h"
#include "bullet.h"




class Game
{
public:
    Game();
    ~Game(){};

    void handleInput();
    void update();
    void render();
    bool isDone() const;
    sf::Font mFont;
    sf::Text mLivesText;
    sf::Text mGameOverText;


private:
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    Enemy mEnemy;
    bool mIsDone;
    int mScore;
    bool mGameOver;
};

#endif