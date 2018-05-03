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
#include "Coin.hpp"

class Game {
public:
    Game();
    ~Game();
    void play();
private:
    sf::Clock clockProjectile;
    sf::Clock clockHit;

    sf::Time elapsedShot;
    sf::Time elapsedPlayerDamage;

    sf::Font font;

    int WIDTH, HEIGHT;
    sf::RenderWindow window;

    int playerScore = 0;

    void loadMap(std::string mapLevel, sf::Texture &tex);
    void updateProjectiles();
    void updateEnemies();
    void playerCollidesWall();
    void projectilesHits();
    void playerHitsEnemy();
    void enemiesCollideWall();
    void updateCoins();
    void checkCoinsCollected();

    sf::Texture playerTexture;
    sf::Texture enemyTexture;
    sf::Texture fireballTexture;
    sf::Texture wallTexture;
    sf::Texture coinTexture;
    void loadTextures();

    Player player;
    std::vector<Projectile> projectiles;
    std::vector<Enemy> enemies;
    std::vector<Wall> walls;
    std::vector<TextDisplay> texts;
    std::vector<Coin> coins;
};
