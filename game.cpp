#include "game.h"
#include <iostream>

Game::Game() : mWindow(sf::VideoMode(1000, 800), "SpaceShooters"), mPlayerSpaceShip(mWindow.getSize())
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


void Game::spawnFighter(int count, sf::Vector2f(), std::vector<Fighter> *&f)
{
    //fighters spawn left to right
    //check if spacing will go outside of window
    //create new objects using count to loop
}