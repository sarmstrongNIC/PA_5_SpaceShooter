#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "bullet.h"

class Ship
{
public:
    Ship();
    Ship(const sf::Vector2u &windowsize);
    ~Ship(){};
    
    //sf::Vector2u getWindowSize(Game g){return g.mWinSizeVect;}
    void draw(sf::RenderWindow& window);
    void moveShip();
    void handleInput();
    void drawBullet(sf::RenderWindow &window);
    void updateBullets();

private:

    sf::Texture mShipTextureTile;
    sf::Sprite mShipSprite;
    float mIncrement;
    sf::Vector2u mWindowSize;
    sf::Clock mShotClock;
    sf::Time mShotCooldown = sf::seconds(0.25f);

    void fireBullet();
    
    std::vector<Bullet> mBullets;
};

#endif