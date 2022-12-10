#pragma once
#include "Point.h"

class Axis {
public:
	Axis();
	Point O;
	Point A;
	Point B;
	Point C;
	void iso();
	void print();
};