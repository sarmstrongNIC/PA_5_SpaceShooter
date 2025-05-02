#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "spaceShip.h"
#include "enemy.h"
#include "bullet.h"
#include "mainMenu.h"

class Game
{
public:
    Game(sf::RenderWindow &window);
    ~Game(){};

    void handleInput(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    bool isDone(sf::RenderWindow &window);
    int displayMainMenu(sf::RenderWindow &window);
    int getSelectedMenuItem();
    void setGameDone();
    sf::Font mFont;
    sf::Text mLivesText;
    sf::Text mGameOverText;
    MainMenu mMenu;

private:
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    Enemy mEnemy;
    bool mIsDone;
    int mScore;
    bool mGameOver;
    
    int selectedMenuItem = 0;
};

#endif