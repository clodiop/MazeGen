#pragma once
#include <vector>

#include "constants.h"
#include "Renderer.h"
#include "Cell.h"

class MazeGen
{
public:
	MazeGen(); // used to init the vertex data for either the square or lines
	~MazeGen();

	void setupMaze();
	void drawMaze();

	//void drawBorder();

private:
	std::vector<Cell> grid;
	Renderer* line;
	Renderer* square;

};

