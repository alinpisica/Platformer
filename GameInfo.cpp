#include "GameInfo.hpp"

GameInfo::GameInfo() {

    playerAttack.setFillColor(sf::Color::White);
    playerHp.setFillColor(sf::Color::White);
    playerScore.setFillColor(sf::Color::White);

    playerAttack.setCharacterSize(30);
    playerScore.setCharacterSize(30);
    playerHp.setCharacterSize(30);

    playerHp.setString("HP 100");
    playerScore.setString("Score 0");
    playerAttack.setString("Attack  Normal");
    playerScore.setPosition(sf::Vector2f(50, 690));
    playerAttack.setPosition(sf::Vector2f(400, 690));
    playerHp.setPosition(sf::Vector2f(800, 690));

}

GameInfo::~GameInfo() { }

void GameInfo::loadFont(sf::Font &fnt) {
    playerHp.setFont(fnt);
    playerScore.setFont(fnt);
    playerAttack.setFont(fnt);
}

void GameInfo::setHp(int hp) {
    std::string h = std::to_string(hp);
    playerHp.setString("HP  " + h);
}

void GameInfo::setScore(int score) {
    playerScore.setString("Score  " + std::to_string(score));
}

void GameInfo::setAttack(std::string attack) {
    playerAttack.setString("Attack  " + attack);
}

void GameInfo::draw(sf::RenderWindow &window) {
    window.draw(playerHp);
    window.draw(playerAttack);
    window.draw(playerScore);
}
