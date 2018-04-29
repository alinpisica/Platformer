#include "Projectile.hpp"

Projectile::Projectile() {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setFillColor(sf::Color::Red);
}

Projectile::~Projectile() {
}

void Projectile::loadTexture(sf::Texture &tex) {
    sprite.setTexture(tex);
    sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void Projectile::updateMovement() {
    if (direction == "down") {
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(0, 32 * 6, 32, 32));
    }
    if (direction == "up") {
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(0, 32 * 2, 32, 32));
    }
    if (direction == "left") {
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(0, 32 * 0, 32, 32));
    }
    if (direction == "right") {
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(0, 32 * 4, 32, 32));
    }
}

void Projectile::update() {
    sprite.setPosition(rect.getPosition());
    updateMovement();
}

void Projectile::setPosition(sf::Vector2f pos) {
    rect.setPosition(pos);
}

float Projectile::getAttackDamage() {
    return attackDamage;
}
