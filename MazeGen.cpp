#include "MazeGen.h"

MazeGen::MazeGen()
{
	line = new Renderer;
	line->initline();
	square = new Renderer;
	square->initSquare();
}

MazeGen::~MazeGen()
{
	delete line;
}

void MazeGen::setupMaze()
{
	int cols = WIDTH / cellWidth;
	int rows = HEIGHT / cellWidth;

	for(int j = 0; j < cols; j++) {

		for(int i = 0; i < rows; i++) {
			Cell cell(i, j);
			grid.push_back(cell);
		}

	}
}

void MazeGen::drawMaze()
{

	grid[0].visted = true;
	grid[0].setWalls(true, true, true, false);
	for(int i = 0; i < grid.size(); i++) {
		grid[i].drawCellLine(line, square);
	}


}

/**
void MazeGen::drawBorder()
{
	ren.drawLine(glm::vec2(20, 20), glm::vec2(380, 0), glm::vec3(1.0f, 1.0f, 1.0f)); // TOP line
	ren.drawLine(glm::vec2(20, 780), glm::vec2(380, 0), glm::vec3(1.0f, 1.0f, 1.0f)); // Bottom line
	ren.drawLine(glm::vec2(20, 20), glm::vec2(380, 0), glm::vec3(1.0f, 1.0f, 1.0f), 90.0f);  // left line
	ren.drawLine(glm::vec2(780, 20), glm::vec2(380, 0), glm::vec3(1.0f, 1.0f, 1.0f), 90.0f); // right Line
}*/
