#include "NextTetramino.h"

short figures[7][4] =
{
	{ 1,3,5,7 },	// I
	{ 2,4,5,7 },	// Z
	{ 3,5,4,6 },	// S
	{ 3,5,4,7 },	// T
	{ 2,3,5,7 },	// L
	{ 3,5,7,6 },	// J
	{ 2,3,4,5 }		// O
};

NextTetramino::NextTetramino() {}
NextTetramino::~NextTetramino() {}

void NextTetramino::createTetramino(int n) {
	this->nextId = n;
	for (int i = 0; i < 4; i++) {
		a[i].x = figures[n][i] % 2 + 15;
		a[i].y = figures[n][i] / 2 + 16;
	}
}
int NextTetramino::getNextFigureId() {
	return this->nextId;
}
void NextTetramino::rotateTetramino() {
	NextTetramino::Pos p = this->a[1]; // Figure center
	for (int i = 0; i < 4; i++) {
		short rotX = this->a[i].y - p.y; // y - y0
		short rotY = this->a[i].x - p.x; // x - x0
		a[i].x = p.x - rotX;
		a[i].y = p.y + rotY;
	}
}
short NextTetramino::randomTetramino() {
	srand(time(NULL));
	return rand() % 7;
}