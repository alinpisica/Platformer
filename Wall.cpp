#include "Wall.hpp"

Wall::Wall() {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::White);
    sprite.setPosition(rect.getPosition());
    direction = "up";
}

Wall::~Wall() { }

void Wall::loadTexture(sf::Texture &tex) {
    sprite.setTexture(tex);
}

void Wall::setPosition(sf::Vector2f pos) {
    rect.setPosition(pos);
    sprite.setPosition(rect.getPosition());
}
