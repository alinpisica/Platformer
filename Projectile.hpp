#pragma once

#include "Entity.hpp"
#include <string>

class Projectile : public Entity {
public:
    Projectile();
    ~Projectile();
    void update();
    void updateMovement();
    void setPosition(sf::Vector2f pos);
    float getAttackDamage();
    void loadTexture(sf::Texture &tex);
private:
    float movementSpeed = 1;
    float attackDamage = 10;
};
