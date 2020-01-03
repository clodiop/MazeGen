#include "Cell.h"

Cell::Cell(int i, int j)
{
	this->i = i;
	this->j = j;
}

void Cell::drawCell(Renderer ren)
{
	int x = this->i * cellWidth;
	int y = this->j * cellWidth;

	ren.initSquare();
	ren.drawSquare(glm::vec2(x, y), glm::vec2(cellWidth, cellWidth), glm::vec3(0.0f, 1.0f, 0.0f));
}
