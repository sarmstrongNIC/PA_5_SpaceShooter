#include "game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(1000, 800), "SpaceShooters"), mPlayerSpaceShip(mWindow.getSize()), mEnemy(mWindow.getSize())
{

    if (!mFont.loadFromFile("game_over.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    mLivesText.setFont(mFont);
    mLivesText.setCharacterSize(50);
    mLivesText.setFillColor(sf::Color::White);
    mLivesText.setPosition(10.f, mWindow.getSize().y - 90.f);
    //Enemy mEnemyInitial
    mScore = 0;
    mIsDone = false;
    mGameOver = false;
}

void Game::handleInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            // Close window button clicked.
            mWindow.close();
        }
    }
    mPlayerSpaceShip.moveShip();
    mPlayerSpaceShip.handleInput();
    mEnemy.handleInput();
}

void Game::update()
{
    if(mPlayerSpaceShip.mLives == 0 && mGameOver == false)
    {
        std::cout << "GAME OVER" << std::endl;
        mGameOver = true;
        //display game over screen
        //pop up displaying score and asking to play again
        mGameOverText.setFont(mFont);
        mGameOverText.setCharacterSize(250);
        mGameOverText.setFillColor(sf::Color::White);
        mGameOverText.setPosition(mWindow.getSize().x/2 - 275, mWindow.getSize().y/2 - 250);
        mGameOverText.setString("GAME OVER");
        
    }
    for(std::size_t i = 0; i < mEnemy.enemyBullets.size(); i++)
    {
        bool userHit = mPlayerSpaceShip.checkCollision(mEnemy.enemyBullets[i]);
        if(userHit)
        {
            std::swap(mEnemy.enemyBullets[i], mEnemy.enemyBullets.back());
            mEnemy.enemyBullets.pop_back();
            if(mPlayerSpaceShip.mLives > 0)
            {
                mPlayerSpaceShip.mLives--;
            }
            std::cout << "SPACESHIP HIT" << std::endl;
            std::cout << mPlayerSpaceShip.mLives << " Lives Remaining" << std::endl;
        }
    }
    for(std::size_t i = 0; i < mPlayerSpaceShip.mBullets.size(); i++)
    {
        bool enemyHit = mEnemy.checkCollision(mPlayerSpaceShip.mBullets[i]);
        if(enemyHit)
        {
            std::swap(mPlayerSpaceShip.mBullets[i], mPlayerSpaceShip.mBullets.back());
            mPlayerSpaceShip.mBullets.pop_back();
            std::cout << "ENEMY HIT" << std::endl;
        }
    }
    mLivesText.setString("Lives Remaining: " + std::to_string(mPlayerSpaceShip.mLives));
}


//friend for spaceship and enemy draw?
void Game::render()
{
    mWindow.clear(sf::Color::Black);
    mEnemy.draw(mWindow);
    mEnemy.drawBullet(mWindow);
    mPlayerSpaceShip.draw(mWindow);
    mPlayerSpaceShip.drawBullet(mWindow);
    mWindow.draw(mLivesText);
    if(mGameOver)
    {
        mWindow.draw(mGameOverText);
    }
    mWindow.display();
}

bool Game::isDone() const
{
    return (!mWindow.isOpen() || mIsDone);
}
