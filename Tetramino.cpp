#include "Tetramino.h"

short figure[7][4] =
{
	{ 1,3,5,7},		// I
	{ 2,4,5,7},		// Z
	{ 3,5,4,6},		// S
	{ 3,5,4,7 },	// T
	{ 2,3,5,7 },	// L
	{ 3,5,7,6 },	// J
	{ 2,3,4,5 }		// O
};

Tetramino::Tetramino() {
	field[BOARD_HEIGHT][BOARD_WIDTH] = { 0 };
}

Tetramino::~Tetramino() {
}
void Tetramino::createTetramino(int n) {
	this->figureID = n;
	for (int i = 0; i < 4; i++) {
		this->coord[i].x = figure[n][i] % 2 + (BOARD_WIDTH / 2.5);
		this->coord[i].y = figure[n][i] / 2;
	}
}
short Tetramino::getFigureId() {
	return this->figureID;
}
void Tetramino::rotateTetramino() {
	Tetramino::Position p = this->coord[1]; // Figure center
	for (int i = 0; i < 4; i++) {
		short rotX = this->coord[i].y - p.y; // y - y0
		short rotY = this->coord[i].x - p.x; // x - x0
		coord[i].x = p.x - rotX;
		coord[i].y = p.y + rotY;
	}
}
bool Tetramino::isAbroad() {
	for (int i = 0; i < 4; i++) {
		if (coord[i].x < 0 || coord[i].x >= BOARD_WIDTH || coord[i].y >= BOARD_HEIGHT)
			return 0;
		else if (field[coord[i].y][coord[i].x]) 
			return 0;
	}
	return 1;
}
short Tetramino::randomTetramino(){
	srand(time(NULL));
	return rand() % 7;
}

