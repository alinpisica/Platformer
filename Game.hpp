#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"
#include "Wall.hpp"
#include "TextDisplay.hpp"

class Game {
public:
    Game();
    ~Game();
    int play();
private:
    sf::Clock clockProjectile;
    sf::Clock clockHit;

    int WIDTH, HEIGHT;
    sf::RenderWindow window;

    void loadMap(std::string mapLevel, sf::Texture &tex);
    void updateProjectiles();

    Player player;
    std::vector<Projectile> projectiles;
    std::vector<Enemy> enemies;
    std::vector<Wall> walls;
    std::vector<TextDisplay> texts;
};
