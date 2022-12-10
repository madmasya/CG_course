#pragma once
#include "Point.h"

class Triangle
{
public:
	Point A, B, C;
	int color;
	Triangle();
	Triangle(Point A, Point B, Point C, int color);
	Triangle(const Triangle& refTriangle);
	double findZCentral();
	Point** makeArrOfPoints();
	void sortPointsX();
	void fill();
};