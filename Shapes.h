#pragma once
class Shapes
{
public:
	virtual void createTetramino(int n) = 0;
	virtual void rotateTetramino() = 0;
protected:
	virtual short randomTetramino() = 0;
};

