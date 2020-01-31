#include "MazeGen.h"

MazeGen::MazeGen()
{
	lineRen = new Renderer;
	lineRen->initline();
	squareRen = new Renderer;
	squareRen->initSquare();
}

MazeGen::~MazeGen()
{
	delete lineRen;
	delete squareRen;
}

void MazeGen::setupMaze()
{
	int cols = WIDTH / cellWidth;
	int rows = HEIGHT / cellWidth;

	for(int j = 0; j < cols; j++) {

		for(int i = 0; i < rows; i++) {
			Cell cell(i, j, i + j);
			grid.push_back(cell);
		}

	}
	grid[0].visted = true;
	currentIndex = 0;
	current = grid[0];
	//             top	right	bottom	left
	/*grid[0].setWalls(true, true, false, true);
	grid[5].setWalls(false, false, false, true);
	grid[6].setWalls(true, true, false, false);*/
}

void MazeGen::drawMaze()
{

	// draws the grid and the sqaures indicating the gen bot ting
	for(int i = 0; i < grid.size(); i++) {
		grid.at(i).drawCell(lineRen, 1.0f);
	}

	//current.drawCellT(lineRen, 0.0f);
	current.highlight(squareRen);

	int nextIndex = current.checkNeighbours(grid);
	if(nextIndex != -1) {
		grid[nextIndex].visted = true;

		current.removeWalls(grid[nextIndex]);
		grid[currentIndex] = current;
		currentIndex = nextIndex;
		current = grid[nextIndex];
	}
}

