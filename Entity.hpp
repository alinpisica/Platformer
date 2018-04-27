#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Entity {
public:
    Entity() {};
    Entity(sf::Texture tex, sf::Vector2f pos);
    ~Entity();
    void draw(sf::RenderWindow &window);
    void drawRect(sf::RenderWindow &window);
    void setDirection(std::string s);
    std::string getDirection();
    sf::Vector2f getRectPosition();
    sf::RectangleShape getRect();
    bool collides(sf::RectangleShape rectToCollide);
protected:
    std::string direction;
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
};
