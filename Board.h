#pragma once
#include <SFML/Graphics.hpp>
#include <map>
class Board
{
private:
	sf::RectangleShape	verticalSeparationLine;
	sf::RectangleShape	horizontalSeparationLine;
	std::map<std::string, short>colors;
	std::map<std::string, short> ::iterator it;
public:
	sf::Texture texture;

	Board();
	~Board();
	void SetTexturePath(const char* path);
	int SetColor(int n);
	void DrawSeparationLines(sf::RenderWindow& window);
};

