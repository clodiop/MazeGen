#include "MazeGen.h"

void MazeGen::setupMaze()
{
	cols = WIDTH / cellWidth;
	rows = HEIGHT / cellWidth;

	for(int j = 0; j < rows; j++) {

		for(int i = 0; i < cols; i++) {
			Cell cell(i, j);
			grid.push_back(cell);
		}

	}

}

void MazeGen::drawMaze()
{

	for(int i = 0; i < grid.size(); i++) {

		grid[i].drawCell(ren);

	}


}
