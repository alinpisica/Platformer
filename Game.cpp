#include "Game.hpp"
#include <ctime>
Game::Game() {
    WIDTH = 960;
    HEIGHT = 640;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Platformer");
    srand(time(NULL));
}

Game::~Game() {

}

int Game::play() {
    sf::Time elapsedShot;
    sf::Time elapsedPlayerDamage;

    // Load Textures
    sf::Texture playerTexture;
    sf::Texture enemyTexture;
    sf::Texture fireballTexture;
    sf::Texture wallTexture;

    if (!playerTexture.loadFromFile("Resources/playerSheet.png")) {
        return EXIT_FAILURE;
    }
    player.loadTexture(playerTexture);

    if (!enemyTexture.loadFromFile("Resources/monsters.png")) {
        return EXIT_FAILURE;
    }
    Enemy enemy1;
    enemy1.loadTexture(enemyTexture);
    enemies.push_back(enemy1);

    if (!fireballTexture.loadFromFile("Resources/fireball.png")) {
        return EXIT_FAILURE;
    }

    if (!wallTexture.loadFromFile("Resources/wall.png")) {
        return EXIT_FAILURE;
    }

    loadMap("Level1.txt", wallTexture);

    while (window.isOpen()) {
        elapsedShot = clockProjectile.getElapsedTime();
        elapsedPlayerDamage = clockHit.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (elapsedShot.asSeconds() >= 0.3) {
                clockProjectile.restart();
                Projectile proj;
                proj.loadTexture(fireballTexture);
                proj.setPosition(player.getRectPosition());
                proj.setDirection(player.getDirection());
                projectiles.push_back(proj);
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            Enemy en;
            en.loadTexture(enemyTexture);
            enemies.push_back(en);
        }

        window.clear(sf::Color::Black);

        // Updates
        player.update();

        for (size_t i = 0; i < projectiles.size(); i++) {
            bool deleted = false;
            if (projectiles[i].getRectPosition().x < 0 ||
                    projectiles[i].getRectPosition().x > WIDTH ||
                    projectiles[i].getRectPosition().y < 0 ||
                    projectiles[i].getRectPosition().y > HEIGHT) {
                projectiles.erase(projectiles.begin() + i);
                deleted = true;
            } 
            for (size_t j = 0; j < walls.size() && deleted == false; j++) {
                if (projectiles[i].collides(walls[j].getRect())) {
                    projectiles.erase(projectiles.begin() + i);
                    deleted = true;
                    std::cout << "Deleted\n";
                }
            }
            if (deleted == false) {
                projectiles[i].update();
            }            
        }
        for (size_t i = 0; i < enemies.size(); i++) {
            if (enemies[i].getLife() <= 0) {
                enemies.erase(enemies.begin() + i);
            } else {
                enemies[i].update();
            }
        }

        for (size_t i = 0; i < enemies.size(); i++) { 
            for (size_t j = 0; j < projectiles.size(); j++) {
                if (enemies[i].collides(projectiles[j].getRect())) {
                    enemies[i].hit(projectiles[j].getAttackDamage());
                    projectiles.erase(projectiles.begin() + j);
                    std::cout << "DA\n";
                }
            }
        }

        float lifeDamage = 0;
        for (size_t i = 0; i < enemies.size(); i++) {
            if (enemies[i].collides(player.getRect())) {
                lifeDamage += enemies[i].getAttackDamage();
            }
        }
        if (lifeDamage > 0 && elapsedPlayerDamage.asSeconds() >= 1) {
            clockHit.restart();
            player.hit(lifeDamage);
            std::cout << player.getLife() << "\n";
        }

        // Draw rects

        // for (size_t i = 0; i < enemies.size(); i++) {
        //     enemies[i].drawRect(window);
        // }
        //for (size_t i = 0; i < projectiles.size(); i++) {
        //    projectiles[i].drawRect(window);
        //}
        // player.drawRect(window);

        // Draws
        player.draw(window);
        for (size_t i = 0; i < enemies.size(); i++) {
            enemies[i].draw(window);
        }
        for (size_t i = 0; i < projectiles.size(); i++) {
            projectiles[i].draw(window);
        } 
        for (size_t i = 0; i < walls.size(); i++) {
            walls[i].draw(window);
        }

        window.display();
    }

    return 0;
}

void Game::loadMap(std::string mapLevel, sf::Texture &texWall) {
    int wall;
    std::ifstream fin("Resources/Maps/" + mapLevel);
    for (size_t i = 0; i < 20; i++) {
        for (size_t j = 0; j < 30; j++) {
            fin >> wall;
            if (wall) {
                Wall w;
                w.loadTexture(texWall);
                w.setPosition(sf::Vector2f(32 * j, 32 * i));
                walls.push_back(w);
            }
        }
    }

    fin.close();
}
