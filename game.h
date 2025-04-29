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
    void spawnFighter(int count, sf::Vector2f(), std::vector<Fighter> *&f);

private:
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    Enemy mEnemy;
    bool mIsDone;
    int mScore;
};

#endif