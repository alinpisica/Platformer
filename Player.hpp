#pragma once

#include "Entity.hpp"
#include <string>

class Player : public Entity {
public:
  Player();
  ~Player();
  void update();
  void updateMovement();
  void loadTexture(sf::Texture &tex);
  sf::Vector2f getRectPosition();
private:
  float movementSpeed = 0.2;
  int attackDamage = 5;
  int life = 100;
  int walkCounter = 0;
};
