#pragma once
#include <vector>

#include "constants.h"
#include "Renderer.h"
#include "Cell.h"

class MazeGen
{
public:
	void setupMaze();
	void drawMaze();

private:
	int cols;
	int rows;

	std::vector<Cell> grid;
	Renderer ren;
};

