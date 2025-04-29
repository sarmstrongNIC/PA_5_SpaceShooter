#include "fighter.h"



Fighter::Fighter(sf::Vector2f position):Enemy(40)
{
    mEnemy.setRadius(50.f);
    mEnemy.setFillColor(sf::Color::Red);
    mEnemy.setOrigin(sf::Vector2f(25.f,25.f));
    mEnemy.setPosition(position);
}


void Fighter::fire()
{
    //set random point when enemy fighter fires a bullet object
    // (second bullet class?)
}