/**
 * @file spaceShip.cpp
 * @author Sam Armstrong, Nick Bailey
 * @brief 
 * @version 0.1
 * @date 2025-05-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "spaceShip.h"

// Ship::Ship()
// {
//     mShipTextureTile.loadFromFile("galagaShip_crop.png");
//     mShipSprite.setTexture(mShipTextureTile);
//     mShipSprite.setOrigin(209.f / 2.f, 241.f / 2.f);
//     mShipSprite.setPosition(320.f, 40.f);
//     mIncrement = 5.0;
//     mLives = 3;
//     mShipBoundingBox = mShipSprite.getGlobalBounds();
//     std::cout << "default constructor called" << std::endl;
// }
/**
 * @brief Construct a new Ship:: Ship object
 * 
 * @param windowsize game window size
 */
Ship::Ship(const sf::Vector2u &windowsize)
{
    mShipTextureTile.loadFromFile("galagaShip_crop.png");
    mShipSprite.setTexture(mShipTextureTile);
    mWindowSize = windowsize;
    mShipSprite.setOrigin(209.f/2.f, 241.f/2.f);
    mShipSprite.setPosition(320.f, 600.f);
    mIncrement = 5.0;
    mLives = 3;
    mShipBoundingBox = mShipSprite.getGlobalBounds();
}

/**
 * @brief Move ship left/right within screen bounds
 * 
 */
void Ship::moveShip()
{
    if(mLives > 0)
    {
        float speed = 40.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (mShipSprite.getPosition().x - (209.0/2)> 0)
                mShipSprite.move((mIncrement*-1), 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (mShipSprite.getPosition().x + (209.0/2) < mWindowSize.x)
                mShipSprite.move(mIncrement, 0.f);
        }
        mShipBoundingBox = mShipSprite.getGlobalBounds();
    }
}

/**
 * @brief draw the ship sprite
 * 
 * @param window 
 */
void Ship::draw(sf::RenderWindow& window)
{
    window.draw(mShipSprite);
}

/**
 * @brief User fire bullet, creates new bullet object
 * 
 */
void Ship::fireBullet()
{
    Bullet newBullet(mShipSprite.getPosition(), false);
    mBullets.push_back(newBullet);
}

/**
 * @brief handleInput loop for Spaceship, spacebar to shoot a bullet. 'A' key for debugging bullets
 * 
 */
void Ship::handleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && mLives > 0)
    {
        if (mShotClock.getElapsedTime() > mShotCooldown)
        {
            fireBullet();
            mShotClock.restart();
        }
    }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    //     std::cout << "Bullets in air: " << mBullets.size() << "\n";
    //     for (std::size_t i = 0; i < mBullets.size(); ++i) {
    //         std::cout << "Bullet " << i << ": x = " 
    //                   << mBullets[i].getPosition().x << ", y = "
    //                   << mBullets[i].getPosition().y << "\n";
    //     }
    // }
    
}
/**
 * @brief drawbullet if it exists on the screen
 * 
 * @param window 
 */
void Ship::drawBullet(sf::RenderWindow &window)
{
    for (std::size_t i = 0; i < mBullets.size();)
    {
        mBullets[i].drawBullet(window);
        if(!mBullets[i].updateBulletPosition(mWindowSize))
        {
            std::swap(mBullets[i], mBullets.back());
            mBullets.pop_back();
        }
        else
        {
            i++;
        }
    }
}

/**
 * @brief checks for colission between a bullet object and the ship's bounding box
 * 
 * @param bullet bullet shot from enemy
 * @return true bullet has hit spaceship
 * @return false no collision 
 */
bool Ship::checkCollision(Bullet& bullet)
{
    return mShipBoundingBox.intersects(bullet.getBoundingBox());
}