#include "NovaPickup.hpp"

NovaPickup::NovaPickup() {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(350, 350);
    sprite.setPosition(rect.getPosition());
    rect.setFillColor(sf::Color::Magenta);
}

NovaPickup::~NovaPickup() { }

void NovaPickup::loadTexture(sf::Texture &tx) {
    sprite.setTexture(tx);
    sprite.setTextureRect(sf::IntRect(32 * 5, 32 * 7, 32, 32));
}
