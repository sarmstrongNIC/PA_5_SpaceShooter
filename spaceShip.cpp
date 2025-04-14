#include "spaceShip.h"
#include "game.h"
#include <iostream>
//TODO: improve default constructor, investigate whether it is possible to remove
Ship::Ship()
{
    mShipTextureTile.loadFromFile("galagaShip.jpg");
    mShipSprite.setTexture(mShipTextureTile);
    mShipSprite.setOrigin(62.f / 2.f, 62.f / 2.f);
    mShipSprite.setPosition(320.f, 400.f);
    mIncrement = 5.0;
    std::cout << "default constructor called" << std::endl;
}

Ship::Ship(const sf::Vector2u &windowsize)
{
    mShipTextureTile.loadFromFile("galagaShip.jpg");
    mShipSprite.setTexture(mShipTextureTile);
    mWindowSize = windowsize;
    //TODO set rect around sprite
    //mHomeSprite.setTextureRect(sf::IntRect(64, 32, 62, 62));
    mShipSprite.setOrigin(62.f / 2.f, 62.f / 2.f);
    mShipSprite.setPosition(320.f, 400.f);
    mIncrement = 5.0;
}


void Ship::moveShip()
{
    float speed = 5.f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (mShipSprite.getPosition().x > 0)
            mShipSprite.move((mIncrement*-1), 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (mShipSprite.getPosition().x < mWindowSize.x)
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
    //mBullets.push_back(newBullet);
}