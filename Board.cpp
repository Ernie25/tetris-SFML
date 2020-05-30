#include "Board.h"


Board::Board() {
	// Colors
	colors.emplace("Cyan", 5);
	colors.emplace("Yellow", 4);
	colors.emplace("Purple", 1);
	colors.emplace("Green", 3);
	colors.emplace("Red", 2);
	colors.emplace("Blue", 0);
	colors.emplace("Orange", 6);

	//Texture init
	texture.loadFromFile("resources/textures/blocks.png");

	// Vertical 
	verticalSeparationLine.setSize(sf::Vector2f(1.f, 19.f * 19.f));
	verticalSeparationLine.setPosition(sf::Vector2f(10.f * 18.f, 0));
	verticalSeparationLine.setFillColor(sf::Color::Red);
	// Horizontal
	horizontalSeparationLine.setSize(sf::Vector2f(19.f * 9.55f, 1.f));
	horizontalSeparationLine.setPosition(sf::Vector2f(0, 20.f * 18.f));
	horizontalSeparationLine.setFillColor(sf::Color::Red);
}

Board::~Board(){}

void Board::SetTexturePath(const char* path) {
	texture.loadFromFile(path);
}

int Board::SetColor(int n) {
	switch (n) {
	case 0:
		it = colors.find("Cyan");
		return it->second;
		break;
	case 2:
		it = colors.find("Red");
		return it->second;
		break;
	case 1:
		it = colors.find("Green");
		return it->second;
		break;
	case 3:
		it = colors.find("Purple");
		return it->second;
		break;
	case 4:
		it = colors.find("Orange");
		return it->second;
		break;
	case 5:
		it = colors.find("Blue");
		return it->second;
		break;
	case 6:
		it = colors.find("Yellow");
		return it->second;
		break;
	}
}

void Board::DrawSeparationLines(sf::RenderWindow& window) {
	window.draw(verticalSeparationLine);
	window.draw(horizontalSeparationLine);
}
