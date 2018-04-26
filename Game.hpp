#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.hpp"
#include "Projectile.hpp"

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
};
