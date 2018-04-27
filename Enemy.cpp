#include "Enemy.hpp"

Enemy::Enemy() {
    rect.setSize(sf::Vector2f(69, 69));
    rect.setPosition(250, 250);
    rect.setFillColor(sf::Color::Yellow);
    sprite.setPosition(rect.getPosition());
    direction = "left";
}

Enemy::~Enemy() { }

void Enemy::loadTexture(sf::Texture &tex) {
    sprite.setTexture(tex);
    sprite.setTextureRect(sf::IntRect(0, 0, 69, 69));
}

void Enemy::updateMovement() {
}

void Enemy::update() {
    updateMovement();
    sprite.setPosition(rect.getPosition());
}

