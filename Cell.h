#pragma once
#include "constants.h"
#include "Renderer.h"

class Cell
{
public:
	Cell();
	Cell(float i, float j);

	void setWalls(bool wall1, bool wall2, bool wall3, bool wall4);

	void drawCellLine(Renderer* line, Renderer* sqaure);

	void drawCellSquare(Renderer* ren);

	int index(int i, int j);

	void checkNeighbours();

	bool visted;
private:
	//			     top    left  right  bottom
	bool walls[4] = { true, true, true, true };
	float x;
	float y;
};

