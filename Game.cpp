#include "Game.hpp"

Game::Game() {
    WIDTH = 800;
    HEIGHT = 600;
    window.create(sf::VideoMode(WIDTH, HEIGHT), "Platformer"); 
}

Game::~Game() {

}

int Game::play() {
    // Load Textures

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("Resources/playerSheet.png")) {
        return EXIT_FAILURE;
    }
    player.loadTexture(playerTexture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            Projectile proj;
            proj.setPosition(player.getRectPosition());
            proj.setDirection(player.getDirection());
            projectiles.push_back(proj);
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
            }
            projectiles[i].update();
            projectiles[i].drawRect(window);
        }

        // Draws
        player.draw(window);
        // player.drawRect(window);

        window.display();
    }

    return 0;
}
