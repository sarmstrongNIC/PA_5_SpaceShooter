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
        bool userHit = mPlayerSpaceShip.checkCollision(mEnemy.enemyBullets[i]);
        if(userHit)
        {
            std::swap(mEnemy.enemyBullets[i], mEnemy.enemyBullets.back());
            mEnemy.enemyBullets.pop_back();
            std::cout << "SPACESHIP HIT" << std::endl;
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


void Game::spawnFighters(int count, sf::Vector2u position)
{
    //fighters spawn left to right
    for(int i = 0; i < count; i++)
    {
    //check if spacing will go outside of window
        if(position.x > mWindow.getSize().x)
        {
            break;
        }
    //create new objects using count to loop
        else
        {
            Enemy *temp = new Enemy(position);
            mFighters.push_back(temp);
            position.x +=40;
        }
    }
}