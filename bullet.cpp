/**
 * @file bullet.cpp
 * @author Sam Armstrong, Nick Bailey
 * @brief 
 * @version 0.1
 * @date 2025-05-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>
#include "bullet.h"

/**
 * @brief Construct a new Bullet:: Bullet object
 * 
 * @param position position of object shooting bullet
 * @param enemy bool for enemy/user shot. Dictates direction of bullet and collision handling
 */
Bullet::Bullet(sf::Vector2f position, bool enemy)
{
    mBulletShape.setSize(sf::Vector2f(15.f,30.f));
    mBulletShape.setFillColor(sf::Color::Red);
    mEnemyBullet = enemy;
    if(mEnemyBullet)
    {
        std::cout <<"Enemy ";
        mBulletShape.setPosition(position.x, position.y+50);
    }
    else
    {
        std::cout <<"User ";
        mBulletShape.setPosition(position.x-7, position.y-150);
    }
    std::cout << "bullet fired" << std::endl;
    
    mBulletActive = true;
}

/**
 * @brief updates bullet position in the window
 * 
 * @param mWindowSize size of the window
 * @return true bullet is still in the screen
 * @return false bullet has left the screen
 */
bool Bullet::updateBulletPosition(sf::Vector2u &mWindowSize)
{
    if(!mEnemyBullet)
    {
        mBulletShape.move(0.f,-10.f);
        if(getPosition().y < 0.f)
        {
            mBulletActive = false;
        }
        return mBulletActive;
    }
    else
    {
        mBulletShape.move(0.f,10.f);
        if(getPosition().y > mWindowSize.y)
        {
            mBulletActive = false;
        }
        return mBulletActive;
    }
}

/**
 * @brief draws bullet in the window
 * 
 * @param window 
 */
void Bullet::drawBullet(sf::RenderWindow &window)
{
    window.draw(mBulletShape);
}

/**
 * @brief get bullet's position
 * 
 * @return sf::Vector2f 
 */
sf::Vector2f Bullet::getPosition()
{
    return mBulletShape.getPosition();
}

/**
 * @brief get bullet's bounding box for collision detection
 * 
 * @return sf::FloatRect 
 */
sf::FloatRect Bullet::getBoundingBox()
{
    return mBulletShape.getGlobalBounds();
}