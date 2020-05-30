#include "Score.h"

Score::Score() {
	std::ifstream input("data/score.txt");
	input >> bestScore;
	input.close();
}

int Score::getBestScore() {
	return bestScore;
}
int Score::calculatePoints() {
	switch (pCount) {
	case 1:
		score += LINE1;
		break;
	case 2:
		score += LINE2;
		break;
	case 3:
		score += LINE3;
		break;
	case 4:
		score += LINE4;
		break;
	}
	return score;
}
void Score::setPCount(short value) {
	this->pCount = value;
}
void Score::setScore(int score) {
	this->score = score;
}

Score::~Score() {
	if (score > bestScore)
	system(("echo " + std::to_string(score) + " > data/score.txt").c_str());
}