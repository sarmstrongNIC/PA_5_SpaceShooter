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
    void spawnFighters(sf::RenderWindow &window);
    void handleInput(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    bool isDone(sf::RenderWindow &window);
    int displayMainMenu(sf::RenderWindow &window);
    bool displayInstructions(sf::RenderWindow &window);
    int getSelectedMenuItem();
    void setGameDone();
    void checkCollision(std::vector<Enemy*> &FighterRow);
    void randomEnemyShoot();
    void drawEnemyShots(std::vector<Enemy*> &FighterRow, sf::RenderWindow &window);
    bool returnMainMenu = false;
    sf::Font mFont;
    sf::Text mLivesText;
    sf::Text mGameOverText;
    sf::Text mScoreText;
    sf::Clock mEnemyFireClock;
    MainMenu mMenu;

private:
    void drawFighters(sf::RenderWindow &window);
    void spawnFighterRow(int count, sf::Vector2f position, std::vector<Enemy*> &FighterRow, sf::RenderWindow &window);
    sf::Texture mHomeTextureTile;
    sf::RenderWindow mWindow;
    Ship mPlayerSpaceShip;
    Enemy mEnemy;
    std::vector<Enemy*> mFightersRow1;
    std::vector<Enemy*> mFightersRow2;
    std::vector<Enemy*> mFightersRow3;
    sf::Clock mShipHit;
    sf::Time mShipHitCooldown = sf::seconds(1.0f);
    sf::Clock mGameOverTimer;
    sf::Time mGameOverDelay = sf::seconds(4.0f);
    bool mIsDone;
    int mScore;
    int mHighScore;
    int mWave; //display?
    bool mGameOver;
    bool mRespawning;
    sf::Text mPlayAgainText;
    sf::Text mDeclineText;
    bool mPlayAgain;
    
    int selectedMenuItem = 0;
};

#endif