#include "TextDisplay.hpp"

TextDisplay::TextDisplay() { 
    text.setFillColor(sf::Color::Red);
}

TextDisplay::~TextDisplay() { }

bool TextDisplay::shouldDestroy() {
    return lifeTime <= 0;
}

void TextDisplay::loadFont(sf::Font &fnt) {
    text.setFont(fnt);
}

void TextDisplay::setText(std::string s) {
    text.setString(s);
}

void TextDisplay::setPosition(sf::Vector2f pos) {
    text.setPosition(pos);
}

void TextDisplay::update() {
    lifeTime--;
    text.move(0, -movementSpeed);
}

void TextDisplay::setColor(sf::Color cl) {
    text.setFillColor(cl);
}

void TextDisplay::draw(sf::RenderWindow &window) {
    window.draw(text);
}
