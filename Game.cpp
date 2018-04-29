#include "Game.hpp"

Game::Game() {
    WIDTH = 800;
    HEIGHT = 600;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Platformer"); 
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
            if (projectiles[i].getRectPosition().x < 0 ||
                    projectiles[i].getRectPosition().x > WIDTH ||
                    projectiles[i].getRectPosition().y < 0 ||
                    projectiles[i].getRectPosition().y > HEIGHT) {
                projectiles.erase(projectiles.begin() + i);
            } else {
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
           

        window.display();
    }

    return 0;
}
