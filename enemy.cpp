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
    mEnemySprite.setSize(sf::Vector2f(60.f, 40.f));
    mEnemySprite.setFillColor(sf::Color::Red);
    mEnemySprite.setPosition(windowSize.x / 2.f, 100.f);
    mWindowSize = windowSize;
    mEnemyBoundingBox = mEnemySprite.getGlobalBounds();
}

void Enemy::setPosition(sf::Vector2f position)
{
    mEnemySprite.setPosition(position);
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



