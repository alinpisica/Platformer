#include "Game.hpp"
#include <ctime>
Game::Game() {
    WIDTH = 960;
    HEIGHT = 640;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Platformer");
    srand(time(NULL));
    window.setFramerateLimit(60);
}

Game::~Game() {

}

void Game::updateProjectiles() {
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
            }
        }
        if (deleted == false) {
            projectiles[i].update();
        }
    }
}

void Game::pickupNovas() {
    for (size_t i = 0; i < novas.size(); i++) {
        if (player.collides(novas[i].getRect())) {
            player.enableNovaAttack();
            novas.erase(novas.begin() + i);
        }
    }
}

void Game::updateEnemies() {
    for (size_t i = 0; i < enemies.size(); i++) {
        bool deleted = false;
        if (enemies[i].getLife() <= 0) {
            enemies.erase(enemies.begin() + i);
            deleted = true;
            std::cout << "Enemy died.\n";
        }
        
        if (!deleted) {
            enemies[i].update();
        }
    }
}

void Game::playerCollidesWall() {
    for (size_t i = 0; i < walls.size(); i++) {
        if (player.collides(walls[i].getRect())) {
            if (player.getDirection() == "up") {
                player.disableMoveUp();
                player.movePlayer(sf::Vector2f(0, 2));
            } else if (player.getDirection() == "down") {
                player.disableMoveDown();
                player.movePlayer(sf::Vector2f(0, -2));
            } else if (player.getDirection() == "left") {
                player.disableMoveLeft();
                player.movePlayer(sf::Vector2f(2, 0));
            } else if (player.getDirection() == "right") {
                player.disableMoveRight();
                player.movePlayer(sf::Vector2f(-2, 0));
            }
        }
    }
}

void Game::enemiesCollideWall() {
    for (size_t i = 0; i < enemies.size(); i++) {
        for (size_t j = 0; j < walls.size(); j++) {
            if (enemies[i].collides(walls[j].getRect())) {
                std::string dr = enemies[i].getDirection();
                float mspeed = enemies[i].getMovementSpeed();
                if (dr == "up") {
                    enemies[i].disableMoveUp();
                    enemies[i].moveEnemy(sf::Vector2f(0, mspeed * 2));
                } 
                if (dr == "down") {
                    enemies[i].disableMoveDown();
                    enemies[i].moveEnemy(sf::Vector2f(0, -mspeed * 2));
                }
                if (dr == "left") {
                    enemies[i].disableMoveLeft();
                    enemies[i].moveEnemy(sf::Vector2f(mspeed, 0 * 2));
                } 
                if (dr == "right") {
                    enemies[i].disableMoveRight();
                    enemies[i].moveEnemy(sf::Vector2f(-mspeed, 0 * 2));
                }
            }
        }
    }
}

void Game::loadTextures() {
    if (!font.loadFromFile("Resources/arcadeclassic.ttf")) {
        std::cout << "Error loading font.\n";
    }

    if (!playerTexture.loadFromFile("Resources/playerSheet.png")) {
        std::cout << "Error loading player texture.\n";
    }
    player.loadTexture(playerTexture);

    if (!enemyTexture.loadFromFile("Resources/monsters.png")) {
        std::cout << "Error loading enemy texture.\n";
    }

    if (!fireballTexture.loadFromFile("Resources/fireball.png")) {
        std::cout << "Error loading fireball texture.\n";
    }

    if (!wallTexture.loadFromFile("Resources/wall.png")) {
        std::cout << "Error loading wall texture.\n";
    }

    if (!coinTexture.loadFromFile("Resources/coin.png")) {
        std::cout << "Error loading coin texture.\n";
    }

    if (!pickupTexture.loadFromFile("Resources/pickup.png")) {
        std::cout << "Error loading pickup texture.\n";
    }
}

void Game::projectilesHits() {
    for (size_t i = 0; i < enemies.size(); i++) { 
        for (size_t j = 0; j < projectiles.size(); j++) {
            if (enemies[i].collides(projectiles[j].getRect())) {
                enemies[i].hit(projectiles[j].getAttackDamage());
                projectiles.erase(projectiles.begin() + j);
                TextDisplay txt;
                std::string s = std::to_string((int)projectiles[j].getAttackDamage());
                txt.setText(s);
                txt.setPosition(sf::Vector2f(enemies[i].getRectPosition().x, enemies[i].getRectPosition().y - 20));
                txt.loadFont(font);
                txt.setColor(sf::Color::Red);
                texts.push_back(txt);
            }
        }
    }
}

void Game::playerHitsEnemy() {
    float lifeDamage = 0;
    for (size_t i = 0; i < enemies.size(); i++) {
        if (enemies[i].collides(player.getRect())) {
            lifeDamage += enemies[i].getAttackDamage();
        }
    }
    if (lifeDamage > 0 && elapsedPlayerDamage.asSeconds() >= 1) {
        TextDisplay txt;
        std::string s = std::to_string((int)lifeDamage);
        txt.setText(s);
        txt.setPosition(sf::Vector2f(player.getRectPosition().x, player.getRectPosition().y - 20));
        txt.loadFont(font);
        txt.setColor(sf::Color::Green);
        texts.push_back(txt);
        clockHit.restart();
        player.hit(lifeDamage);
        player.disableNovaAttack();
    }
}

void Game::updateCoins() {
    for (size_t i = 0; i < coins.size(); i++) {
        coins[i].update();
    }
}

void Game::checkCoinsCollected() {
    for (size_t i = 0; i < coins.size(); i++) {
        if (player.collides(coins[i].getRect())) {
            playerScore += coins[i].getScore();
            coins.erase(coins.begin() + i);
        }
    }
}

void Game::play() {
    loadTextures(); 
    
    Enemy enemy1;
    enemy1.loadTexture(enemyTexture);
    enemies.push_back(enemy1);

    Coin coin1;
    coin1.loadTexture(coinTexture);
    coins.push_back(coin1);

    NovaPickup nova;
    nova.loadTexture(pickupTexture);
    novas.push_back(nova);

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
            if (elapsedShot.asSeconds() >= 0.2) {
                clockProjectile.restart();
                Projectile proj;
                proj.loadTexture(fireballTexture);
                proj.setPosition(player.getRectPosition());
                if (player.hasNovaAttack()) {
                    proj.setDirection("up");
                    projectiles.push_back(proj);
                    proj.setDirection("down");
                    projectiles.push_back(proj);
                    proj.setDirection("left");
                    projectiles.push_back(proj);
                    proj.setDirection("right");
                    projectiles.push_back(proj);
                } else {
                    proj.setDirection(player.getDirection());
                    projectiles.push_back(proj); 
                }
            }
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            Enemy en;
            en.loadTexture(enemyTexture);
            enemies.push_back(en);
        }

        window.clear(sf::Color(102, 102, 102));

        // Updates
        updateProjectiles();
        playerCollidesWall();
        player.update();
        projectilesHits();
        playerHitsEnemy();
        enemiesCollideWall();
        updateEnemies();
        updateCoins();
        checkCoinsCollected();
        pickupNovas();

        for (size_t i = 0; i < texts.size(); i++) {
            if (texts[i].shouldDestroy()) {
                texts.erase(texts.begin() + i);
            } else {
                texts[i].update();
            }
        }

        player.draw(window);
        for (size_t i = 0; i < walls.size(); i++) {
            walls[i].draw(window);
        }
        for (size_t i = 0; i < enemies.size(); i++) {
            enemies[i].draw(window);
        }
        for (size_t i = 0; i < projectiles.size(); i++) {
            projectiles[i].draw(window);
        } 
        for (size_t i = 0; i < texts.size(); i++) {
            texts[i].draw(window);
        }
        for (size_t i = 0; i < coins.size(); i++) {
            coins[i].draw(window);
        }
        for (size_t i = 0; i < novas.size(); i++) {
            novas[i].draw(window);
        }

        window.display();
    }
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
