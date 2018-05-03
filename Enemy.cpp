#include "Enemy.hpp"

#include <cstdlib>

Enemy::Enemy() {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(rand() % (960 - 34), rand() % (640 - 34));
    rect.setFillColor(sf::Color::Yellow);
    sprite.setPosition(rect.getPosition());
    canMoveLeft = true;
    canMoveRight = true;
    canMoveDown = true;
    canMoveUp = true;
    direction = "up";
 //   moves = (int)(rand() % 800 + 200);
    newDirection();
}

Enemy::~Enemy() { }

void Enemy::loadTexture(sf::Texture &tex) {
    sprite.setTexture(tex);
    sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
}

void Enemy::newDirection() {
    moves = (int)(rand() % 50 + 10);
    setRandomDirection();
}

void Enemy::updateMovement() {
    if (direction == "up" && canMoveUp) {
        rect.move(0, -movementSpeed);
        //canMoveUp = true;
        canMoveDown = true;
        //canMoveLeft = true;
        //canMoveRight = true;
    } else if (direction == "down" && canMoveDown) {
        rect.move(0, movementSpeed);
        canMoveUp = true;
        //canMoveDown = true;
        //canMoveLeft = true;
        //canMoveRight = true;
    } else if (direction == "left" && canMoveLeft) {
        rect.move(-movementSpeed, 0);
        //canMoveUp = true;
        //canMoveLeft = true;
        //canMoveDown = true;
        canMoveRight = true;
    } else if (direction == "right" && canMoveRight) {
        rect.move(movementSpeed, 0);
        //canMoveUp = true;
        canMoveLeft = true;
        //canMoveDown = true;
        //canMoveRight = true;
    }
    
    moves--;
    if (moves <= 1) {
        newDirection();
    }

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

float Enemy::getAttackDamage() {
    return attackDamage;
}

void Enemy::setRandomDirection() {
    int dir = rand() % 4;
    if (dir == 0) direction = "up";
    else if (dir == 1) direction = "right";
    else if (dir == 2) direction = "down";
    else if (dir == 3) direction = "left";
}

void Enemy::disableMoveUp() { canMoveUp = false; }
void Enemy::disableMoveDown() { canMoveDown = false; }
void Enemy::disableMoveLeft() { canMoveLeft = false; }
void Enemy::disableMoveRight() { canMoveRight = false; }

void Enemy::moveEnemy(sf::Vector2f mv) {
    rect.move(mv);
    sprite.setPosition(rect.getPosition());
}

float Enemy::getMovementSpeed() {
    return movementSpeed;
}
