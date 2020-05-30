#pragma once
#include "SFML/Graphics.hpp"
class Text
{
private:
	sf::Text text;
protected:
	sf::Font font;
public:
	Text();
	Text(int fontCharSize, sf::Vector2f textPosition, std::string text);
	~Text();

	void draw(sf::RenderWindow& window);
	void setColor();
	void setText(std::string str);
};

