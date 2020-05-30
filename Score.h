#pragma once
#include <fstream>
#include <string>
#include <sstream>

// Points
#define LINE1								100
#define LINE2								300
#define LINE3								700
#define LINE4								1500

class Score
{
private:
	short pCount;
	int score = 0;
	int bestScore = 0;

public:
	Score();
	~Score();
	
	int getBestScore();
	int calculatePoints();
	
	void setScore(int score);
	void setPCount(short value);
};

