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
	int cols = WIDTH / CELL_WIDTH;
	int rows = HEIGHT / CELL_WIDTH;

	for(int j = 0; j < cols; j++) {

		for(int i = 0; i < rows; i++) {
			Cell cell(i, j, std::to_string(i) + "," + std::to_string(j));
			grid.push_back(cell);
		}

	}
	grid[0].addCellInfo("Starting point");
	grid[0].setVisted(true);
	currentIndex = 0;
	current = grid[0];
}

void MazeGen::drawMaze()
{
	// draws the grid and the sqaures indicating the gen bot ting
	for(int i = 0; i < grid.size(); i++) {
		grid.at(i).drawLineCell(lineRen);

		if(grid.at(i).getCellInfo() == "Starting point") {
			grid.at(i).highlight(squareRen, glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(10, 10));
		}
	}

	current.highlight(squareRen, glm::vec3(1.0f, 1.0f, 0.0f), glm::vec2(10, 10));

	int nextIndex = current.checkNeighbours(grid);
	if(nextIndex != -1) {
		grid[nextIndex].setVisted(true);

		current.removeWalls(grid[nextIndex]);

		queue.push(std::make_pair(current, currentIndex));

		grid[currentIndex] = current;
		currentIndex = nextIndex;
		current = grid[nextIndex];
	}
	else if(!queue.empty()) { // checks if the stack is not empty
		std::pair<Cell, int> queueItems = queue.front();
		queue.pop();

		current = queueItems.first; // gets the Cell
		currentIndex = queueItems.second; // gets the index value
	}
}
// top	right	bottom	left
