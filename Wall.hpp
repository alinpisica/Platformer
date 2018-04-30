#pragma once

#include "Entity.hpp"

class Wall : public Entity {
public:
    Wall();
    ~Wall();
    void loadTexture(sf::Texture &tex);
    void setPosition(sf::Vector2f pos);
private:

};
