#include "Projectile.hpp"

Projectile::Projectile() {
    rect.setSize(sf::Vector2f(24, 32));
    rect.setFillColor(sf::Color::Red);
}

Projectile::~Projectile() {
}

void Projectile::updateMovement() {
    if (direction == "down") {
        rect.move(0, movementSpeed);
    }
    if (direction == "up") {
        rect.move(0, -movementSpeed);
    }
    if (direction == "left") {
        rect.move(-movementSpeed, 0);
    }
    if (direction == "right") {
        rect.move(movementSpeed, 0);
    }
}

void Projectile::update() {
    sprite.setPosition(rect.getPosition());
    updateMovement();
}

void Projectile::setPosition(sf::Vector2f pos) {
    rect.setPosition(pos);
}

