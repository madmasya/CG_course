#pragma once

#include "Triangle.h"

class Pyramid {
public:
	Pyramid();
	Pyramid(Point O, Point A, Point B, Point C);
	Pyramid(const Pyramid& Pyramid);
	Point O;
	Point A;
	Point B;
	Point C;
	Point findCentre();
	void moveToCentre(Point centrePoint);
	void moveFromCentre(Point centrePoint);
	void iso(Point Centre);
	Triangle** pyramidToTriangles(int* colours);
	Triangle** sortTriangles(int* colours);
	void move(char axis, bool direction);
	void scale(bool direction);
	void rotate(char axis, bool direction);
	void printAndFill(Point Centre, int* colours);
};