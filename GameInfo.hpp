#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class GameInfo {
public:
    GameInfo();
    ~GameInfo();
    void draw(sf::RenderWindow &window);
    void loadFont(sf::Font &fnt);
    void setHp(int hp);
    void setScore(int score);
    void setAttack(std::string s);
private:
    sf::Text playerHp;
    sf::Text playerScore;
    sf::Text playerAttack;
};
