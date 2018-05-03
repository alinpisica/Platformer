#pragma once

#include "Entity.hpp"

class Coin : public Entity {
public:
    Coin();
    ~Coin();
    int getScore();
    void update();
    void loadTexture(sf::Texture &tx);

private:
    int rotator = 0;
    int score = 10;
};

