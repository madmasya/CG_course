#include "PyramidSurface.h"

PyramidSurface::PyramidSurface(Point& p1, Point& p2, Point& p3, Point& p4) {

	point1 = new Point;
	point2 = new Point;
	point3 = new Point;
	point4 = new Point;

	point1->copyPointValues(p1);
	point2->copyPointValues(p2);
	point3->copyPointValues(p3);
	point4->copyPointValues(p4);

	findCenterZvalue();
}

PyramidSurface::~PyramidSurface() {

	delete point1;
	delete point2;
	delete point3;
	delete point4;
}

void PyramidSurface::drawSurface(ArrayOfPoints* arrOfPoints) {

	drawBresenhamLine(point1->x, point1->y, point2->x, point2->y, arrOfPoints);
	drawBresenhamLine(point2->x, point2->y, point3->x, point3->y, arrOfPoints);
	drawBresenhamLine(point3->x, point3->y, point4->x, point4->y, arrOfPoints);
	drawBresenhamLine(point4->x, point4->y, point1->x, point1->y, arrOfPoints);
}

void PyramidSurface::findCenterZvalue() {
	
	centerZvalue = (point1->z + point2->z + point3->z + point4->z) / 4;
}

