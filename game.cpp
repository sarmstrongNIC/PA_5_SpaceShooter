#include "game.h"
#include <iostream>

Game::Game(sf::RenderWindow &window) : mPlayerSpaceShip(window.getSize()), mEnemy(window.getSize()), mMenu(window)
{

    if (!mFont.loadFromFile("game_over.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }
    mLivesText.setFont(mFont);
    mLivesText.setCharacterSize(50);
    mLivesText.setFillColor(sf::Color::White);
    mLivesText.setPosition(10.f, window.getSize().y - 90.f);
    //Enemy mEnemyInitial
    mScore = 0;
    mIsDone = false;
    mGameOver = false;
}

void Game::handleInput(sf::RenderWindow &window)
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            // Close window button clicked.
            window.close();
        }
    }
    mPlayerSpaceShip.moveShip();
    mPlayerSpaceShip.handleInput();
    mEnemy.handleInput();
}

void Game::update(sf::RenderWindow &window)
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
        mGameOverText.setPosition(window.getSize().x/2 - 275, window.getSize().y/2 - 250);
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
void Game::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    mEnemy.draw(window);
    mEnemy.drawBullet(window);
    mPlayerSpaceShip.draw(window);
    mPlayerSpaceShip.drawBullet(window);
    window.draw(mLivesText);
    if(mGameOver)
    {
        window.draw(mGameOverText);
    }
    window.display();
}

bool Game::isDone(sf::RenderWindow &window) 
{
    return (!window.isOpen() || mIsDone);
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
int Game::displayMainMenu(sf::RenderWindow &window)
{
    
    mMenu.display(window);
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
            

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                std::cout << "Up key pressed" << std::endl;
                if(selectedMenuItem == 0)
                {
                    
                    selectedMenuItem = 3;
                }
                else
                {
                    selectedMenuItem--;
                }
                std::cout << "selectedMenuItem = " << selectedMenuItem << std::endl;

            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                std::cout << "Down key pressed" << std::endl;
                if(selectedMenuItem == 3)
                {
                    selectedMenuItem = 0;
                }
                else
                {
                    selectedMenuItem++;
                }
                std::cout << "selectedMenuItem = " << selectedMenuItem << std::endl;
            }
                
            else if (event.key.code == sf::Keyboard::A)
            {
                std::cout << "Enter key pressed" << std::endl;
                if(selectedMenuItem == 0)
                {
                    return 0;
                    //play game
                }
                else if(selectedMenuItem == 1)
                {
                    return 1;
                    //display instructions
                }
                else if(selectedMenuItem == 2)
                {
                    return 2;
                    //display high score
                }
                else if(selectedMenuItem == 3)
                {
                    return 3;
                    //exit
                }
            }

        }
    }
    return -1;
}

void Game::setGameDone()
{
    mIsDone = true;
}

int Game::getSelectedMenuItem()
{
    return selectedMenuItem;
}