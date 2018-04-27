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
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 1, 24, 32));
        direction = "up";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 0, 24, 32));
        direction = "down";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 2, 24, 32));
        direction = "left";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(walkCounter * 24, 32 * 3, 24, 32));
        direction = "right";
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

