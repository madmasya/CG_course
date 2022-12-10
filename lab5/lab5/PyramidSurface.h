#pragma once

#include "Definitions.h"
#include "Point.h"
#include "ArrrayOfPoints.h"

struct PyramidSurface {
	PyramidSurface(Point& p1, Point& p2, Point& p3, Point& p4);
	~PyramidSurface();
	void drawSurface(ArrayOfPoints* arrOfPoints);
	void findCenterZvalue();
	Point* point1, * point2, * point3, * point4;
	double centerZvalue;
};