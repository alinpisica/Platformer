#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"

class Game {
public:
    Game();
    ~Game();
    int play();
private:
    int WIDTH, HEIGHT;
    sf::RenderWindow window;

    Player player;
    std::vector<Projectile> projectiles;
    std::vector<Enemy> enemies;
};
