#pragma once
#include "constants.h"
#include "Renderer.h"


class Cell
{
public:
	Cell();
	Cell(float i, float j, int id);

	void drawCell(Renderer* line, float i);

	inline int index(int i, int j);

	void removeWalls(Cell& nextCell);

	void highlight(Renderer* sqaure);

	int checkNeighbours(std::vector<Cell>& grid);
	bool visted;
	bool valid = true;
private:
	float x;
	float y;
	// top	right	bottom	left
	bool walls[4];
	int ID;
	int cols;
	int rows;
};

