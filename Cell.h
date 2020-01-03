#pragma once
#include "constants.h"
#include "Renderer.h"

class Cell
{
public:

	Cell(int i, int j);

	void drawCell(Renderer ren);

private:
	int i;
	int j;


};

