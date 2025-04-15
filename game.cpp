#include "game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(1640, 1480), "SpaceShooters"), mPlayerSpaceShip(mWindow.getSize())
{
    Ship mPlayerSpaceShip(mWindow.getSize());
    //Enemy mEnemyInitial
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
}

void Game::update()
{

}


//friend for spaceship and enemy draw?
void Game::render()
{
    mWindow.clear(sf::Color::Black);
    mPlayerSpaceShip.draw(mWindow);
    mPlayerSpaceShip.drawBullet(mWindow);
    mWindow.display();
}

bool Game::isDone() const
{
    return (!mWindow.isOpen() || mIsDone);
}
