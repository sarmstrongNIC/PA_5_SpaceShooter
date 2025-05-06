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

    mScoreText.setFont(mFont);
    mScoreText.setCharacterSize(80);
    mScoreText.setFillColor(sf::Color::White);
    mScoreText.setPosition(10.f, 0.f);

    //Enemy mEnemyInitial

    mWave = 1;
    mScore = 0;
    mHighScore = 0;
    mIsDone = false;
    mGameOver = false;
    mRespawning = false;
    mPlayAgain = true;
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
    if(!mGameOver)
    {
        spawnFighters(window);
    }
    if(mPlayerSpaceShip.mLives == 0 && mGameOver == false)
    {
        std::cout << "GAME OVER" << std::endl;
        mGameOver = true;
        mGameOverTimer.restart();
        if(mScore > mHighScore)
        {
            mHighScore = mScore;
        }
        //display game over screen
        //pop up displaying score and asking to play again
        if(mGameOver && (mGameOverTimer.getElapsedTime() < mGameOverDelay))
        {
            mGameOverText.setFont(mFont);
            mGameOverText.setCharacterSize(250);
            mGameOverText.setFillColor(sf::Color::White);
            mGameOverText.setPosition(window.getSize().x/2 - 275, window.getSize().y/2 - 250);
            mGameOverText.setString("GAME OVER");
        }
    }
    for(std::size_t i = 0; i < mEnemy.enemyBullets.size(); i++)
    {            
        //ship not affected by bullets for cooldown period after hit
        if (mShipHit.getElapsedTime() > mShipHitCooldown)
        {
            mRespawning = false;
        }
        if(!mRespawning)
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
                mRespawning = true;
                mShipHit.restart();
            }   
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
            mScore+=100;
            std::cout << "Score: " << mScore << std::endl;
        }
    }
    mScoreText.setString("Score: " + std::to_string(mScore));
    mLivesText.setString("Lives Remaining: " + std::to_string(mPlayerSpaceShip.mLives));
    //Play again prompt
    if(mGameOver && (mGameOverTimer.getElapsedTime() > mGameOverDelay))
    {
        mGameOverText.setFont(mFont);
        mGameOverText.setCharacterSize(250);
        mGameOverText.setFillColor(sf::Color::White);
        mGameOverText.setPosition(window.getSize().x/2 - 275, window.getSize().y/2 - 400);
        mGameOverText.setString("Play Again?");

        mPlayAgainText.setFont(mFont);
        mPlayAgainText.setCharacterSize(150);
        mPlayAgainText.setFillColor(sf::Color::White);
        mPlayAgainText.setPosition(window.getSize().x/2 - 150, window.getSize().y/2-200);
        mPlayAgainText.setString("Yes");

        mDeclineText.setFont(mFont);
        mDeclineText.setCharacterSize(150);
        mDeclineText.setFillColor(sf::Color::White);
        mDeclineText.setPosition(window.getSize().x/2 + 50, window.getSize().y/2-200);
        mDeclineText.setString("No");

        if(mPlayAgain == true)
        {
            mPlayAgainText.setFillColor(sf::Color::Red);
        }
        else
        {
            mDeclineText.setFillColor(sf::Color::Red);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            mPlayAgain = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            mPlayAgain = false;
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && mPlayAgain == true)
        {
            std::cout << "Play again selected" << std::endl;
            mGameOver = false;
            mPlayerSpaceShip.mLives = 3;
            mScore = 0;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && mPlayAgain == false)
        {
            std::cout << "Decline play again" << std::endl;
            returnMainMenu = true;
            mGameOver = false;
            mPlayerSpaceShip.mLives = 3;
            mScore = 0;
        }
    }
}

//friend for spaceship and enemy draw?
void Game::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    // for(int i = 0; i < 1; i++)
    // {
    //     mFightersRow1[i]->draw(window);
    //     mFightersRow1[i]->drawBullet(window);
    // }
    // mEnemy.draw(window);
    // mEnemy.drawBullet(window);
    mPlayerSpaceShip.draw(window);
    mPlayerSpaceShip.drawBullet(window);
    window.draw(mLivesText);
    window.draw(mScoreText);
    if(mGameOver)
    {
        window.draw(mGameOverText);
        if((mGameOverTimer.getElapsedTime() > mGameOverDelay))
        {
            window.draw(mPlayAgainText);
            window.draw(mDeclineText);
        }
    }
    window.display();
}

bool Game::isDone(sf::RenderWindow &window) 
{
    return (!window.isOpen() || mIsDone);
}

void Game::spawnFighters(sf::RenderWindow &window) //function to check if all fighters are destroyed and spawn new ones
{
    int destroyed = 0;
    //check if all fighter vectors are null/destroyed
    for(int i = 0; i < mFightersRow1.size(); i++)
    {
        if(mFightersRow1[i] == nullptr)
        {
            destroyed +=1;
        }
        if(mFightersRow2[i] == nullptr)
        {
            destroyed +=1;
        }
        if(mFightersRow3[i] == nullptr)
        {
            destroyed +=1;
        }
    }
    if (destroyed == mFightersRow1.size()*3 || mFightersRow1.size() == 0)
    {
        for(int i = 0; i < mFightersRow1.size(); i++)//clear vectors
        {
            mFightersRow1.pop_back();
            mFightersRow2.pop_back();
            mFightersRow3.pop_back();
        }
        //spawn new enemy fighters
        spawnFighterRow(5,sf::Vector2f{80,40},mFightersRow1, window);
        spawnFighterRow(5,sf::Vector2f{80,120},mFightersRow2, window);
        spawnFighterRow(5,sf::Vector2f{80,200},mFightersRow3, window);
        mWave =+ 1; //wave increment
    }
}
//spawns fighters in a row
void Game::spawnFighterRow(int count, sf::Vector2f position, std::vector<Enemy*> &FighterRow, sf::RenderWindow &window)
{
    //fighters spawn left to right
    for(int i = 0; i < count; i++)
    {
    //check if spacing will go outside of window
    //spacing value may need adjustment
        if(position.x > window.getSize().x || position.x < 0)
        {
            break;
        }
    //create new object
        else
        {
            Enemy *temp = new Enemy(mWindow.getSize());
            temp->setPosition(position);
            FighterRow.push_back(temp);
            position.x +=180;
        }
    }
}
void Game::drawFighters(sf::RenderWindow &window)
{
    for (int i = 0; i < mFightersRow1.size(); i++)
    {
        if(mFightersRow1[i] != nullptr)
        {
            mFightersRow1[i]->draw(window);
        }
        if(mFightersRow2[i] != nullptr)
        {
            mFightersRow2[i]->draw(window);
        }
        if(mFightersRow3[i] != nullptr)
        {
            mFightersRow3[i]->draw(window);
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
        {
            window.close();
        }
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
};


bool Game::displayInstructions(sf::RenderWindow &window)
{
    mMenu.displayInstructions(window);
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
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