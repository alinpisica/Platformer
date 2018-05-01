#include "Player.hpp"

Player::Player() {
    rect.setSize(sf::Vector2f(24, 32));
    rect.setPosition(100, 100);
    rect.setFillColor(sf::Color::Blue);
    sprite.setPosition(rect.getPosition());
    direction = "down";
}

Player::~Player() {

}

void Player::loadTexture(sf::Texture &tex) {
    sprite.setTexture(tex);
    sprite.setTextureRect(sf::IntRect(0, 0, 24, 32));
}

void Player::updateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (canMoveUp) {
            rect.move(0, -movementSpeed);
            sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 1, 24, 32));
            direction = "up";
            canMoveLeft = true;
            canMoveRight = true;
            canMoveUp = true;
            canMoveDown = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (canMoveDown) {
            rect.move(0, movementSpeed);
            sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 0, 24, 32));
            direction = "down";
            canMoveLeft = true;
            canMoveRight = true;
            canMoveUp = true;
            canMoveDown = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (canMoveLeft) {
            rect.move(-movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 2, 24, 32));
            direction = "left";
            canMoveLeft = true;
            canMoveRight = true;
            canMoveUp = true;
            canMoveDown = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (canMoveRight) {
            rect.move(movementSpeed, 0);
            sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 3, 24, 32));
            direction = "right";
            canMoveLeft = true;
            canMoveRight = true;
            canMoveUp = true;
            canMoveDown = true;
        }
    }
    walkCounter++;
    if (walkCounter == 8) {
        walkCounter = 0;
    }
}

void Player::update() {
    updateMovement();
    sprite.setPosition(rect.getPosition());
}

void Player::hit(float attack) {
    life -= attack;
}

float Player::getLife() {
    return life;
}

void Player::disableMoveUp() { canMoveUp = false; }
void Player::disableMoveDown() { canMoveDown = false; }
void Player::disableMoveLeft() { canMoveLeft = false; }
void Player::disableMoveRight() { canMoveRight = false; }

void Player::movePlayer(sf::Vector2f mv) {
    rect.move(mv);
    sprite.setPosition(rect.getPosition());
}
