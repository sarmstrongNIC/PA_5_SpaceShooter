#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
public:
    Bullet(sf::Vector2f position);
    ~Bullet(){};
    void bulletMotion();
    bool updateBulletPosition(sf::Vector2u &mWindowSize);
    void drawBullet(sf::RenderWindow &window);
    sf::Vector2f getPosition();


private:
//mPosition
//mSize
sf::RectangleShape mBulletShape;
float mSpeed;
bool mBulletActive; //active until hit or off screen


   
};

#endif