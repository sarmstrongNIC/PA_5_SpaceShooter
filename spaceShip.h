#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <SFML/Graphics.hpp>

class Ship
{
public:
    Ship();
    Ship(const sf::Vector2u &windowsize);
    ~Ship(){};
    
    //sf::Vector2u getWindowSize(Game g){return g.mWinSizeVect;}
    void draw(sf::RenderWindow& window);
    void moveShip();

private:

    sf::Texture mShipTextureTile;
    sf::Sprite mShipSprite;
    float mIncrement;
    sf::Vector2u mWindowSize;

    void shootShip();
   
};

#endif