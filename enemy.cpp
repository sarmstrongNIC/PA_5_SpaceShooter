#include "enemy.h"

Enemy::Enemy(const sf::Vector2u &windowSize)
{
    mEnemySprite.setSize(sf::Vector2f(60.f, 40.f));
    mEnemySprite.setFillColor(sf::Color::Red);
    mEnemySprite.setPosition(windowSize.x / 2.f, 100.f);
    mWindowSize = windowSize;
    std::cout << "Enemy constructor called" << std::endl;
    mEnemyBoundingBox = mEnemySprite.getGlobalBounds();
}


void Enemy::fireBullet()
{
    Bullet newBullet(mEnemySprite.getPosition(),true);
    enemyBullets.push_back(newBullet);
}

void Enemy::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
    {
        fireBullet();
        std::cout << "Enemy bullets in air: " << enemyBullets.size() << "\n";
        for (std::size_t i = 0; i < enemyBullets.size(); ++i) {
            std::cout << "Bullet " << i << ": x = " 
                      << enemyBullets[i].getPosition().x << ", y = "
                      << enemyBullets[i].getPosition().y << "\n";
        }
    }
}

void Enemy::draw(sf::RenderWindow& window)
{
    window.draw(mEnemySprite);
}

void Enemy::drawBullet(sf::RenderWindow &window)
{
    for (std::size_t i = 0; i < enemyBullets.size();)
    {
        enemyBullets[i].drawBullet(window);
        if(!enemyBullets[i].updateBulletPosition(mWindowSize))
        {
            std::swap(enemyBullets[i], enemyBullets.back());
            enemyBullets.pop_back();
        }
        else
        {
            ++i;
        }
    }
}

bool Enemy::checkCollision(Bullet& bullet)
{
    return mEnemyBoundingBox.intersects(bullet.getBoundingBox());
}

void Fighter::fire()
{
    
}