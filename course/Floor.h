#pragma once
#include "Definitions.h"
#include "Triangle.h"

class Floor
{
public:
	Point A, B, C, D;
	Floor(Point A, Point B, Point C, Point D);
	Point findCentre();
	void moveToCentre(Point centrePoint);
	void moveFromCentre(Point centrePoint);
	void iso();
	void printAndFill();
};