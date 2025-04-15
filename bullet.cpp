#include <iostream>
#include "bullet.h"
//TODO
//Shoot bullet from middle of ship rather than edge
//Handle duplicate shots


Bullet::Bullet(sf::Vector2f position)
{
    mBulletShape.setSize(sf::Vector2f(15.f,30.f));
    mBulletShape.setFillColor(sf::Color::Red);
    mBulletShape.setPosition(position.x + 162.f, position.y);
    std::cout << "bullet fired" << std::endl;
    mBulletActive = true;
}

bool Bullet::updateBulletPosition(sf::Vector2u &mWindowSize)
{
    mBulletShape.move(0.f,-50.f);//consider making this speed a CONST
    if(getPosition().y < 0.f)
    {
        mBulletActive = false;
    }
    return mBulletActive;
}

void Bullet::drawBullet(sf::RenderWindow &window)
{
    window.draw(mBulletShape);
}

sf::Vector2f Bullet::getPosition()
{
    return mBulletShape.getPosition();
}