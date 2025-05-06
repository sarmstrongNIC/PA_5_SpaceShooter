#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.h"

class Enemy
{
    public:
    Enemy(const sf::Vector2u &windowsize);
    void fireBullet();
    void draw(sf::RenderWindow& window);
    void drawBullet(sf::RenderWindow &window);
    void handleInput();
    std::vector<Bullet> enemyBullets;
    bool checkCollision(Bullet& bullet);
    sf::RectangleShape mEnemySprite;//TODO, create proper sprite
    void setPosition(sf::Vector2f position);

    private:
    sf::FloatRect mEnemyBoundingBox;
    sf::Vector2u mWindowSize;


};



#endif