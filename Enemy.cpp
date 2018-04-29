#include "Enemy.hpp"

#include <cstdlib>



Enemy::Enemy() {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(250, 250);
    rect.setFillColor(sf::Color::Yellow);
    sprite.setPosition(rect.getPosition());
    setRandomDirection();
    moves = (int)(rand() % 300 + 200);
}

Enemy::~Enemy() { }

void Enemy::loadTexture(sf::Texture &tex) {
    sprite.setTexture(tex);
    sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
}

void Enemy::updateMovement() {
    if (moves == 0) {
        moves = (int)(rand() % 300 + 200);
        setRandomDirection();
    }

    if (direction == "up") {
        rect.move(0, -movementSpeed);
    } else if (direction == "right") {
        rect.move(movementSpeed, 0);
    } else if (direction == "down") {
        rect.move(0, movementSpeed);
    } else if (direction == "left") {
        rect.move(-movementSpeed, 0);
    }

    moves--;
}

void Enemy::update() {
    updateMovement();
    sprite.setPosition(rect.getPosition());
}

void Enemy::hit(float attack) {
    life -= attack;
}

float Enemy::getLife() {
    return life;
}

void Enemy::setRandomDirection() {
    int dir = rand() % 4;
    if (dir == 0) direction = "up";
    else if (dir == 1) direction = "right";
    else if (dir == 2) direction = "down";
    else if (dir == 3) direction = "left";
}
