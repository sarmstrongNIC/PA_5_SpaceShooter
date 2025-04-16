#include "spaceShip.h"

//TODO: improve default constructor, investigate whether it is possible to remove
Ship::Ship()
{
    mShipTextureTile.loadFromFile("galagaShip_crop.png");
    mShipSprite.setTexture(mShipTextureTile);
    mShipSprite.setOrigin(209.f / 2.f, 241.f / 2.f);
    mShipSprite.setPosition(320.f, 40.f);
    mIncrement = 5.0;
    std::cout << "default constructor called" << std::endl;
}

Ship::Ship(const sf::Vector2u &windowsize)
{
    mShipTextureTile.loadFromFile("galagaShip_crop.png");
    mShipSprite.setTexture(mShipTextureTile);
    mWindowSize = windowsize;
    //TODO set rect around sprite
    //mHomeSprite.setTextureRect(sf::IntRect(64, 32, 62, 62));
    mShipSprite.setOrigin(209.f/2.f, 241.f/2.f);
    mShipSprite.setPosition(320.f, 600.f);
    mIncrement = 5.0;
}


void Ship::moveShip()
{
    //TODO remove magic #s for screen edge detection
    float speed = 40.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (mShipSprite.getPosition().x - (209.0/2)> 0)
            mShipSprite.move((mIncrement*-1), 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (mShipSprite.getPosition().x + (209.0/2) < mWindowSize.x)
            mShipSprite.move(mIncrement, 0.f);
    }
}

void Ship::draw(sf::RenderWindow& window)
{
    window.draw(mShipSprite);
}

void Ship::fireBullet()
{
    Bullet newBullet(mShipSprite.getPosition());
    mBullets.push_back(newBullet);
}

void Ship::handleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (mShotClock.getElapsedTime() > mShotCooldown)
        {
            fireBullet();
            mShotClock.restart();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cout << "Bullets in air: " << mBullets.size() << "\n";
        for (std::size_t i = 0; i < mBullets.size(); ++i) {
            std::cout << "Bullet " << i << ": x = " 
                      << mBullets[i].getPosition().x << ", y = "
                      << mBullets[i].getPosition().y << "\n";
        }
    }
    
}

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
            ++i;
        }
    }
}