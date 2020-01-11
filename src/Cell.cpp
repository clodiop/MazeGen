#include "Cell.h"

Cell::Cell()
{
}

Cell::Cell(float i, float j) : x(i), y(j), visted(false)
{
}

void Cell::drawCell(Renderer* line, Renderer* sqaure)
{
	int x = this->x * cellWidth;
	int y = this->y * cellWidth;

	if(this->visted == true) {
		sqaure->drawSquare(glm::vec2(x, y), glm::vec2(cellWidth, cellWidth), glm::vec3(0.0f, 1.0f, 0.f));
	}

	if(walls[0]) {
		line->drawLine(glm::vec2(x, y), glm::vec2(cellWidth / 2, 0), glm::vec3(1.0f, 0.0f, 0.0f)); // top
		//^^^^^^^ i did `cellWidth / 2` because the line x vertex data is -1 to 1 so its a length of 2 so if you didnt divide it then it will 20(default cellwidth) will end up scalled to 40. 20*2=40
	}
	if(walls[1]) {
		line->drawLine(glm::vec2(x, y), glm::vec2(cellWidth / 2, 0), glm::vec3(1.0f, 0.0f, 0.0f), 90.0f);//left side
	}
	if(walls[2]) {
		line->drawLine(glm::vec2(x + cellWidth, y), glm::vec2(cellWidth / 2, 0), glm::vec3(1.0f, 0.0f, 0.0f), 90.0f);// right siede
	}
	if(walls[3]) {
		line->drawLine(glm::vec2(x, y + cellWidth), glm::vec2(cellWidth / 2, 0), glm::vec3(1.0f, 0.0f, 0.0f)); // bottom
		//std::cout << walls[0] << "  " << walls[1] << "  " << walls[2] << "  " << walls[3];
	}
}

int Cell::index(int i, int j)
{
	return 0;
}

void Cell::checkNeighbours()
{


}

void Cell::setWalls(bool wall1, bool wall2, bool wall3, bool wall4)
{
	walls[0] = wall1;
	walls[1] = wall2;
	walls[2] = wall3;
	walls[3] = wall4;
}
