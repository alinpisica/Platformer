#pragma once

#include "Entity.hpp"

class Enemy : public Entity {
public:
    Enemy();
    ~Enemy();
    void update();
    void updateMovement();
    void loadTexture(sf::Texture &tex);
    void hit(float attack);
    float getLife();
    float getAttackDamage();
    void disableMoveUp();
    void disableMoveDown();
    void disableMoveLeft();
    void disableMoveRight();
    void moveEnemy(sf::Vector2f mv);
    void newDirection();
    float getMovementSpeed();


private:
    int walkCounter = 0;
    int moves;
    float movementSpeed = 3;
    float attackDamage = 15;
    float life = 50;
    bool canMoveLeft;
    bool canMoveRight;
    bool canMoveUp;
    bool canMoveDown;

    void setRandomDirection();
};
