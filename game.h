#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "spaceShip.h"
#include "enemy.h"
#include "bullet.h"
#include "fighter.h"

class Game
{
public:
    Game();
    ~Game(){};

    void handleInput();
    void update();
    void render();
    bool isDone() const;
    void spawnFighters(int count, sf::Vector2u position);

private:
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    Enemy mEnemy;
    std::vector<Enemy*> mFighters;
    bool mIsDone;
    int mScore;
};

#endif