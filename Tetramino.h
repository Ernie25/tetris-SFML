#pragma once
#include <SFML/Graphics.hpp>
#include "Shapes.h"
#include <time.h>
#include <stdlib.h>

#define BOARD_HEIGHT	20
#define BOARD_WIDTH		10

class Tetramino : public Shapes
{
public:
	Tetramino();
	~Tetramino();


	void createTetramino(int n) override;
	void rotateTetramino() override;

	short getFigureId();

	bool isAbroad();

	short field[BOARD_HEIGHT][BOARD_WIDTH];

	struct Position {
		short x = 0,  
			  y = 0, 
			  p = 0; // Is used like a center position
	}coord[4],coord2[4];

private:
	short figureID;
	short randomTetramino() override;

};

