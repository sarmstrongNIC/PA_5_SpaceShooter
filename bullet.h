#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>
#include "spaceShip.h"

class Bullet
{
public:
    Bullet(sf::Vector2f position);
    ~Bullet(){};
    void bulletMotion();
    void updateBulletPosition();
    void drawBullet(sf::RenderWindow &window);
    void getPosition();


private:
//mPosition
//mSize
sf::RectangleShape mBulletShape;
float mSpeed;
bool mBulletActive; //active until hit or off screen


   
};

#endif