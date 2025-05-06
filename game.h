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
    void spawnFighters(int count, sf::Vector2u position);
    void handleInput(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    bool isDone(sf::RenderWindow &window);
    int displayMainMenu(sf::RenderWindow &window);
    bool displayInstructions(sf::RenderWindow &window);
    int getSelectedMenuItem();
    void setGameDone();
    bool returnMainMenu = false;
    sf::Font mFont;
    sf::Text mLivesText;
    sf::Text mGameOverText;
    sf::Text mScoreText;
    MainMenu mMenu;

private:
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    Enemy mEnemy;
    std::vector<Enemy> mFighters;
    sf::Clock mShipHit;
    sf::Time mShipHitCooldown = sf::seconds(1.0f);
    sf::Clock mGameOverTimer;
    sf::Time mGameOverDelay = sf::seconds(4.0f);
    bool mIsDone;
    int mScore;
    int mHighScore;
    bool mGameOver;
    bool mRespawning;
    sf::Text mPlayAgainText;
    sf::Text mDeclineText;
    bool mPlayAgain;
    
    int selectedMenuItem = 0;
};

#endif