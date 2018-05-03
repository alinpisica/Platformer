#include "Coin.hpp"

Coin::Coin() {
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(rand() % (960 - 36), rand() % (640 - 36));
    rect.setFillColor(sf::Color::Green);
    sprite.setPosition(rect.getPosition());
}

Coin::~Coin() { }

void Coin::loadTexture(sf::Texture &tx) {
    sprite.setTexture(tx);
    sprite.setTextureRect(sf::IntRect(32 * rotator, 0, 32, 32));
}

void Coin::update() {
    rotator++;
    sprite.setTextureRect(sf::IntRect(32 * rotator, 0, 32, 32));
    if (rotator == 10) {
        rotator = 0;
    }
}

int Coin::getScore() {
    return score;
}
