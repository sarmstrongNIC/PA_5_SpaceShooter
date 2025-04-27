#include "game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(1000, 800), "SpaceShooters"), mPlayerSpaceShip(mWindow.getSize()), mEnemy(mWindow.getSize())
{
    Ship mPlayerSpaceShip(mWindow.getSize());
    
    //Enemy mEnemyInitial
    mScore = 0;
    mIsDone = false;
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
    for(std::size_t i = 0; i < mEnemy.enemyBullets.size(); i++)
    {
        bool colission = mPlayerSpaceShip.checkCollision(mEnemy.enemyBullets[i]);
        if(colission)
        {
            std::cout << "SPACESHIP HIT" << std::endl;
        }
    }
}


//friend for spaceship and enemy draw?
void Game::render()
{
    mWindow.clear(sf::Color::Black);
    mEnemy.draw(mWindow);
    mEnemy.drawBullet(mWindow);
    mPlayerSpaceShip.draw(mWindow);
    mPlayerSpaceShip.drawBullet(mWindow);
    
    mWindow.display();
}

bool Game::isDone() const
{
    return (!mWindow.isOpen() || mIsDone);
}
