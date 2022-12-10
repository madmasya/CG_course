#pragma once

#include "Point.h"
#include "Pyramid.h"
#include "Floor.h"
#include "Triangle.h"

class Shadow
{
public:
	Point A, B, C, D;
	Shadow();
	Shadow(Point A, Point B, Point C, Point D);
	void castShadow(Pyramid Pyramid, Point Light, Point Centre);
	void moveToCentre(Point centrePoint);
	void moveFromCentre(Point centrePoint);
	void iso(Point Centre);
	void fillShadow(Pyramid Pyramid, Point Light, Point Centre);
};