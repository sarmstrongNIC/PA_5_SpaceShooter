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
    void moveEnemy();
    std::vector<Bullet> enemyBullets;
    bool checkCollision(Bullet& bullet);
    void setPosition(sf::Vector2f position);

    private:
    void movementSwitch();
    sf::Texture mEnemyTextureTile;
    sf::Clock mMovement;
    sf::Time mMovementSwitch = sf::seconds(2);
    int mSwitch;
    sf::Sprite mEnemyShip;
    sf::Vector2f mStartPosition;
    sf::RectangleShape mEnemySprite;//TODO, create proper sprite
    sf::FloatRect mEnemyBoundingBox;
    sf::Vector2u mWindowSize;


};



#endif