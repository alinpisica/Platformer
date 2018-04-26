#include "Entity.hpp"

Entity::~Entity() {

}

void Entity::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Entity::drawRect(sf::RenderWindow &window) {
    window.draw(rect);
}

void Entity::setDirection(std::string s) {
    direction = s;
}

std::string Entity::getDirection() {
    return direction;
}

sf::Vector2f Entity::getRectPosition() {
    return rect.getPosition();
}
