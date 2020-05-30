#include "Text.h"

Text::Text(){}
Text::~Text(){}

Text::Text(int fontCharSize, sf::Vector2f textPosition, std::string sText)
{
	font.loadFromFile("resources/fonts/Roboto-Medium.ttf");
	text.setFont(font);
	text.setPosition(textPosition);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(fontCharSize);
	text.setString(sText);
}

void Text::setColor() {
	text.setFillColor(sf::Color::White);
}
void Text::draw(sf::RenderWindow& window) {
	window.draw(text);
}
void Text::setText(std::string str) {
	text.setString(str);
}