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
    void hit(float attack);
    float getLife();
private:
    float movementSpeed = 0.1;
    float attackDamage = 15;
    float life = 50;
};
