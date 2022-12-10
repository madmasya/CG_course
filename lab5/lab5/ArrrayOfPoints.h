#pragma once

#include "Definitions.h"
#include "Point.h"

class ArrayOfPoints {
public:
	ArrayOfPoints();
	~ArrayOfPoints();
	void addPointToArr(int x, int y);
	bool ifPointInArr(int x, int y);
	friend void drawBresenhamLine(int x1, int y1, int x2, int y2, ArrayOfPoints* arr);
	friend void recursiveFilling(ArrayOfPoints* arr, int x, int y, int color);
private:
	Point** pointArr = new Point * [REALLOC_VAL];
	int sizeArr = REALLOC_VAL;
	int amountPoints = 0;

	void resizePointArr();
};