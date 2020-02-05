#pragma once
#include "constants.h"
#include "Renderer.h"
#include <ctime>

constexpr int COLS = WIDTH / CELL_WIDTH;
constexpr int ROWS = HEIGHT / CELL_WIDTH;

constexpr glm::vec3 LINE_COLOR(1.0f, 1.0f, 0.0f);

class Cell
{
public:
	Cell();
	Cell(float i, float j, std::string id);

	void drawLineCell(Renderer* line);

	inline int index(int x, int y);

	void removeWalls(Cell& nextCell);

	void highlight(Renderer* sqaure, glm::vec3 squareColor, glm::vec2 squareScale);

	int checkNeighbours(std::vector<Cell>& grid);

	inline void setVisted(bool visted)
	{
		this->visted = visted;
	}

	inline void addCellInfo(std::string info)
	{
		this->cellInfo = info;
	}

	inline std::string getCellInfo()
	{
		return this->cellInfo;
	}

private:
	std::string cellInfo; // main purpose is to allow a way to identify the starting and the point :)
	std::string ID;

	bool walls[4];// top	right	bottom	left
	bool visted;
	float x;
	float y;
};
