/**
 * @file enemy.cpp
 * @author Sam Armstrong, Nick Bailey
 * @brief 
 * @version 0.1
 * @date 2025-05-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "enemy.h"

/**
 * @brief Construct a new Enemy:: Enemy object
 * 
 * @param windowSize 
 */
Enemy::Enemy(const sf::Vector2u &windowSize)
{
    mEnemyTextureTile.loadFromFile("Enemy Ship.png");
    mEnemyShip.setTexture(mEnemyTextureTile);
    mEnemyShip.scale(3.5,3.5);
    mEnemySprite.setSize(sf::Vector2f(60.f, 40.f));
    mEnemySprite.setFillColor(sf::Color::Black);
    mEnemySprite.setPosition(windowSize.x / 2.f, 100.f);
    mEnemyShip.setPosition(windowSize.x / 2.f, 100.f);
    mWindowSize = windowSize;
    mSwitch = 0;
}

/**
 * @brief sets position and new starting position
 * 
 * @param Vector2f position - new position for object
 */
void Enemy::setPosition(sf::Vector2f position)
{
    mEnemySprite.setPosition(position);
    mEnemyShip.setPosition(position);
    mEnemyBoundingBox = mEnemySprite.getGlobalBounds();
    mStartPosition = position;
}

void Enemy::movementSwitch()
{
    if(mMovement.getElapsedTime() > mMovementSwitch)
    {
        mSwitch += 1;
        mMovement.restart();
    }
}

void Enemy::moveEnemy()
{
    movementSwitch();
    if(mEnemySprite.getPosition().y < mStartPosition.y + 300)
    {
        mEnemySprite.move(0,1);
        mEnemyShip.move(0,1);
        mEnemyBoundingBox = mEnemySprite.getGlobalBounds();
    }
    else if(mSwitch%2 == 0)
    {
        mEnemySprite.move(0.5,0);
        mEnemyShip.move(0.5,0);
        mEnemyBoundingBox = mEnemySprite.getGlobalBounds();
    }
    else if(mSwitch%2 == 1)
    {
        mEnemySprite.move(-0.5,0);
        mEnemyShip.move(-0.5,0); 
        mEnemyBoundingBox = mEnemySprite.getGlobalBounds();
    }
}

/**
 * @brief fires enemy bullet
 * 
 */
void Enemy::fireBullet()
{
    std::cout << "fireBullet called " << std::endl;
    Bullet newBullet(mEnemySprite.getPosition(),true);
    enemyBullets.push_back(newBullet);
}

/**
 * @brief input loop for manually shooting enemy bullets in development.
 * 
 */
void Enemy::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        fireBullet();
        // std::cout << "Enemy bullets in air: " << enemyBullets.size() << "\n";
        
        // for (std::size_t i = 0; i < enemyBullets.size(); ++i) {
        //     sf::FloatRect bounds = enemyBullets[i].getBoundingBox();
        //     std::cout << "Bullet " << i << ": x = " 
        //               << enemyBullets[i].getPosition().x << ", y = "
        //               << enemyBullets[i].getPosition().y << " | Bounds: left = " << bounds.left 
        //               << ", top = " << bounds.top 
        //               << ", width = " << bounds.width 
        //               << ", height = " << bounds.height << "\n";
            
        //}
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
    {
        //fireBullet();
        std::cout << "Enemy bullets in air: " << enemyBullets.size() << "\n";
        
        for (std::size_t i = 0; i < enemyBullets.size(); ++i) {
            sf::FloatRect bounds = enemyBullets[i].getBoundingBox();
            std::cout << "Bullet " << i << ": x = " 
                      << enemyBullets[i].getPosition().x << ", y = "
                      << enemyBullets[i].getPosition().y << " | Bounds: left = " << bounds.left 
                      << ", top = " << bounds.top 
                      << ", width = " << bounds.width 
                      << ", height = " << bounds.height << "\n";
            
        }
    }
}

/**
 * @brief draw enemy sprite
 * 
 * @param window 
 */
void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(mEnemySprite);
    window.draw(mEnemyShip);
}

/**
 * @brief draw enemy bullet as long as it is on the screen
 * 
 * @param window 
 */
void Enemy::drawBullet(sf::RenderWindow &window)
{
    for (std::size_t i = 0; i < enemyBullets.size();)
    {
        enemyBullets[i].drawBullet(window);
        if(!enemyBullets[i].updateBulletPosition(mWindowSize))
        {
            std::swap(enemyBullets[i], enemyBullets.back());
            enemyBullets.pop_back();
        }
        else
        {
            i++;
        }
    }
}

/**
 * @brief check for collision between enemy and bullet
 * 
 * @param bullet bullet shot by user spaceship
 * @return true collision detected 
 * @return false no collision
 */
bool Enemy::checkCollision(Bullet& bullet)
{
    return mEnemyBoundingBox.intersects(bullet.getBoundingBox());
}





