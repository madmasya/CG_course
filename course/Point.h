#pragma once

#include "Definitions.h"

class Point {
public:
	Point();
	Point(double x, double y, double z);
	double x;
	double y;
	double z;
	void iso();
	void operator+ (Point& p2);
	void operator- (Point& p2);
	void move(char axis, bool direction);
	void scale(bool direction);
	void rotate(char axis, bool direction);
};