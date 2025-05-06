#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "bullet.h"

class Enemy
{
    public:
    Enemy(const sf::Vector2u &windowsize);
    //use spacing and count to spawn ships in a row vector is origin point for row;
    void spawn(int count, sf::Vector2f());
    void fireBullet();
    void draw(sf::RenderWindow& window);
    void drawBullet(sf::RenderWindow &window);
    void handleInput();
    std::vector<Bullet> enemyBullets;
    bool checkCollision(Bullet& bullet);
    sf::RectangleShape mEnemySprite;//TODO, create proper sprite


    private:
    sf::FloatRect mEnemyBoundingBox;
    sf::Vector2u mWindowSize;


};



#endif