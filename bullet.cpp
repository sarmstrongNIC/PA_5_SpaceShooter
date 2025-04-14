#include <iostream>
#include "bullet.h"

Bullet::Bullet(sf::Vector2f position)
{
    mBulletShape.setSize(sf::Vector2f(5.f,10.f));
    mBulletShape.setFillColor(sf::Color::Red);
    mBulletShape.setPosition(position);
}

void Bullet::updateBulletPosition()
{
    mBulletShape.move(0.f,-5.f);
}

void Bullet::drawBullet(sf::RenderWindow &window)
{
    window.draw(mBulletShape);
}

void Bullet::getPosition()
{

}
