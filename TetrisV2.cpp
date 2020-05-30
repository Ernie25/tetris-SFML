#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <time.h>

#include "Board.h"
#include "Tetramino.h"
#include "Text.h"
#include "Score.h"
#include "NextTetramino.h"

#define BOARD_HEIGHT			20
#define BOARD_WIDTH				10
#define ONE_CUBE_PIXELS			18

// CYAN		| 
// YELLOW	O 
// PURPLE	T 
// GREEN	S 
// RED		Z 
// ORANGE	L 
// BLUE		J 

//Global Objects
Tetramino tetr;
int main(){
	sf::RenderWindow window(sf::VideoMode(400, 480), "Tetris");
	sf::Clock clock;

	//Objects
	Score scoreObj;
	NextTetramino nextTetr;
	Board board;
	//Texts
	Text endGameScore(18, sf::Vector2f(165.0f,240.0f), "Your Score:");
	Text endGame(24, sf::Vector2f(141.5f, 210.0f), "Game Over");
	Text bestScoreTxt(16, sf::Vector2f(240.0f, 180.0f), "Best Score:");
	Text gameScoreTxt(16, sf::Vector2f(240.0f, 150.0f), "Score:");
	// Sprites
	sf::Sprite nextTetramino(board.texture);
	sf::Sprite sprite(board.texture);
	// Separate block. (one block's size is 18x18)
	sprite.setTextureRect(sf::IntRect(0, 0, ONE_CUBE_PIXELS, ONE_CUBE_PIXELS));
	nextTetramino.setTextureRect(sf::IntRect(0, 0, ONE_CUBE_PIXELS, ONE_CUBE_PIXELS));
	// Variables
	short tetraminoPosX = 0;
	bool rotateTetramino = 0;
	bool isLost = false;
	int colorNum = 3;
	bool beginGame = true;
	int n = rand() % 7;
	float timer = 0, delay = 0.2;
	int bestScore = scoreObj.getBestScore();
	int score = 0;


	// The game
	while (window.isOpen()) {
	if (!isLost) {
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		sf::Event evnt;
				while (window.pollEvent(evnt)) {
					if (evnt.type == sf::Event::Closed) {
						window.close();
					}
					if (evnt.type == sf::Event::KeyPressed) {
							// Rotate figure
						if (evnt.key.code == sf::Keyboard::Up && tetr.getFigureId() != 6) {rotateTetramino = true;}
							// Slide left
						if (evnt.key.code == sf::Keyboard::Left) tetraminoPosX = -1;
							// Slide right
						if (evnt.key.code == sf::Keyboard::Right) tetraminoPosX = 1;
							// Down faster
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) delay = 0.01;
					}
				}
				// Horizontal movement
				for (int i = 0; i < 4; i++) {
					tetr.coord2[i] = tetr.coord[i];
					tetr.coord[i].x += tetraminoPosX;
				}
				// Check if tetramino is not out of board
				if (!tetr.isAbroad()) {
					for (int i = 0; i < 4; i++) {
						tetr.coord[i] = tetr.coord2[i];
					}
				}
				// Tetramino rotation
				if (rotateTetramino) {
					tetr.rotateTetramino();

					if (!tetr.isAbroad()) {
						for (int i = 0; i < 4; i++) {
							tetr.coord[i] = tetr.coord2[i];
						}
					}
				}
				// Vertical movement
				if (timer > delay) {
					for (int i = 0; i < 4; i++) {
							tetr.coord2[i] = tetr.coord[i];
							tetr.coord[i].y += 1;
					}

					// Checks is tetramino is on board
					if (!tetr.isAbroad()) {
						for (int i = 0; i < 4; i++) {
							// Check if lose
							if (tetr.coord[i].y <= 1 || tetr.field[tetr.coord2[i].y][tetr.coord2[i].x] == 1) {
								isLost = true;
							}
							tetr.field[tetr.coord2[i].y][tetr.coord2[i].x] = 1;
						}
						// Choose next tetramino color
						if (!isLost) {
							n = nextTetr.getNextFigureId();
							colorNum = board.SetColor(n);
							tetr.createTetramino(n);
						}
					}
					timer = 0;
				}
				// Checks is line full
				int row = BOARD_HEIGHT - 1;
				int temp = 0;
				for (int i = BOARD_HEIGHT - 1; i > 0; i--) {
					int count = 0;
					for (int j = 0; j < BOARD_WIDTH; j++) {
						count += (tetr.field[i][j] ? 1 : 0);
						tetr.field[row][j] = tetr.field[i][j];
					}
					if (count < BOARD_WIDTH) {
						row--;
					}
					else {
						temp++;
					}
				}
				scoreObj.setPCount(temp);
				// Score calculation
				score = scoreObj.calculatePoints();
				// Draw first tetramino
				if (beginGame) {
					beginGame = false;
					n = rand() % 7;
					for (int i = 0; i < 4; i++) {
						if(!isLost)
						tetr.createTetramino(n);
					}
				}
				// Refresh variables
				tetraminoPosX = 0;
				rotateTetramino = 0;
				delay = 0.3;

				// Score Text
				std::ostringstream currentScoreStr,bestScoreStr;
				currentScoreStr << "Score:" << score;
				if (score > bestScore) 
					bestScoreStr << "Best Score:" << score;
				else
					bestScoreStr << "Best Score:" << bestScore;

				gameScoreTxt.setText(currentScoreStr.str());
				bestScoreTxt.setText(bestScoreStr.str());
				endGameScore.setText(currentScoreStr.str());

				window.clear(sf::Color::White);

				board.DrawSeparationLines(window);
				bestScoreTxt.draw(window);
				gameScoreTxt.draw(window);

				// Save tetramino position when its down
				for (int i = 0; i < BOARD_HEIGHT; i++) {
					for (int j = 0; j < BOARD_WIDTH; j++) {
						if (tetr.field[i][j] == 0)
							continue;
						else {
							sprite.setTextureRect(sf::IntRect(tetr.field[i][j] * ONE_CUBE_PIXELS, 0, ONE_CUBE_PIXELS, ONE_CUBE_PIXELS));
							sprite.setPosition(j * 18, i * 18);
							window.draw(sprite);
						}
					}
				}

				for (int i = 0; i < 4; i++) {
					sprite.setTextureRect(sf::IntRect(colorNum * ONE_CUBE_PIXELS, 0, ONE_CUBE_PIXELS, ONE_CUBE_PIXELS));
					sprite.setPosition(tetr.coord[i].x * ONE_CUBE_PIXELS, tetr.coord[i].y * ONE_CUBE_PIXELS);
					window.draw(sprite);
				}
				// Next Tetramino
				if (n != -1) {
					n = rand() % 7;
					nextTetr.createTetramino(n);
					n = -1;
				}

				for (int i = 0; i < 4; i++) {
					nextTetramino.setTextureRect(sf::IntRect(1 * ONE_CUBE_PIXELS, 0, ONE_CUBE_PIXELS, ONE_CUBE_PIXELS));
					nextTetramino.setPosition(nextTetr.a[i].x * ONE_CUBE_PIXELS,nextTetr.a[i].y  * ONE_CUBE_PIXELS);
					window.draw(nextTetramino);
				}
		} else {
		// Lose case
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if (evnt.type == sf::Event::Closed) {
				window.close();
			}
		}
		scoreObj.setScore(score);
		window.clear(sf::Color::Black);
		endGame.setColor();
		endGameScore.setColor();
		endGame.draw(window);
		endGameScore.draw(window);
		}
		window.display();
	}
}