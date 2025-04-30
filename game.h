#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "spaceShip.h"
#include "enemy.h"
#include "bullet.h"
#include "mainMenu.h"

class Game
{
public:
    Game(sf::RenderWindow &window);
    ~Game(){};

    void handleInput();
    void update();
    void render();
    bool isDone() const;
    void spawnFighters(int count, sf::Vector2u position);
    void handleInput(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    bool isDone(sf::RenderWindow &window) const;
    int displayMainMenu(sf::RenderWindow &window);
    sf::Font mFont;
    sf::Text mLivesText;
    sf::Text mGameOverText;


private:
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    Enemy mEnemy;
    std::vector<Enemy*> mFighters;
    bool mIsDone;
    int mScore;
    bool mGameOver;
    MainMenu mMenu;
    int selectedMenuItem = 0;
};

#endif