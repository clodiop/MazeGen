#pragma once
#include <vector>
#include "Cell.h"
#include <string> 
#include <queue>
#include "constants.h"
#include "Renderer.h"
#include <utility>

class MazeGen
{
public:
	MazeGen(); // used to init the vertex data for either the square or lines
	~MazeGen();

	void setupMaze();
	void drawMaze();

private:
	Cell current;
	int currentIndex;
	std::vector<Cell> grid;
	Renderer* lineRen;
	Renderer* squareRen;

	// for backtracking
	std::queue<std::pair<Cell, int>> queue;
};
