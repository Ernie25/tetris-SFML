#pragma once
#include "Shapes.h"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>

#define BOARD_HEIGHT	20
#define BOARD_WIDTH		10

class NextTetramino : public Shapes
{
public:
	NextTetramino();
	~NextTetramino();
	void createTetramino(int n) override;
	struct Pos {
		short x = 0,
			y = 0,
			p = 0; // Is used like a center position
	}a[4];
	int getNextFigureId();


private:
	short colorNum = 0;
	short nextId = 0;
	short randomTetramino() override;
	void rotateTetramino() override;


};

