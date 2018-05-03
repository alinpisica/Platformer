#pragma once

#include "Entity.hpp"


class TextDisplay : public Entity {
public:
    TextDisplay();
    ~TextDisplay();
    void setText(std::string txt);
    void loadFont(sf::Font &fnt);
    void setColor(sf::Color cl);
    bool shouldDestroy();
    void setPosition(sf::Vector2f pos);
    void update();
    void draw(sf::RenderWindow &window);
private:
    int lifeTime = 30;
    float movementSpeed = 1;
};
