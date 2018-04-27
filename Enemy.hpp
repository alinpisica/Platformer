#pragma once

#include "Entity.hpp"

class Enemy : public Entity {
public:
    Enemy();
    ~Enemy();
    void update();
    void updateMovement();
    void loadTexture(sf::Texture &tex);
    sf::Vector2f getRectPosition();
private:
    float movementSpeed = 0.1;
    int attackDamage = 15;
    int life = 50;
};
