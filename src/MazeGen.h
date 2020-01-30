#pragma once
#include <vector>
#include "Cell.h"

#include "constants.h"
#include "Renderer.h"


class MazeGen
{
public:
	MazeGen(); // used to init the vertex data for either the square or lines
	~MazeGen();

	void setupMaze();
	void drawMaze();

	//void drawBorder();

private:
	Cell current;
	std::vector<Cell> grid;
	Renderer* lineRen;
	Renderer* squareRen;

};

