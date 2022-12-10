#include "Triangle.h"

Triangle::Triangle() : A(0, 0, 0), B(0, 0, 0), C(0, 0, 0), color(0) {}

Triangle::Triangle(Point A, Point B, Point C, int color) : A(A), B(B), C(C), color(color) {}

Triangle::Triangle(const Triangle& refTriangle) : A(refTriangle.A), B(refTriangle.B), C(refTriangle.C), color(refTriangle.color) {}

double Triangle::findZCentral()
{
	double zCentral = (A.z + B.z + C.z) / 3;
	return zCentral;
}

Point** Triangle::makeArrOfPoints()
{
	Point** Points = new Point * [3];
	Points[0] = new Point(A);
	Points[1] = new Point(B);
	Points[2] = new Point(C);
	return Points;
}

void Triangle::sortPointsX()
{
	Point** Points = makeArrOfPoints();
	for (int i = 0; i < 3; i++) {
		bool flag = true;
		for (int j = 0; j < 3 - (i + 1); j++) {
			if (Points[j]->x < Points[j + 1]->x) {
				flag = false;
				std::swap(Points[j], Points[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	A = *Points[0];
	B = *Points[1];
	C = *Points[2];
}

void Triangle::fill()
{
	sortPointsX();
	float difX = A.x - C.x;
	float step = 0;

	float k = (A.y - C.y) / (A.x - C.x);
	float b = A.y - k * A.x;

	float x = A.x;
	float y;

	if (difX > 0)
	{
		step = -0.1;
		for (x = A.x; x > C.x;)
		{
			x += step;
			y = k * x + b;
			setcolor(color);
			line(B.x, B.y, x, y);
		}
	}
	if (difX < 0)
	{
		step = 0.1;
		for (x = A.x; x < C.x;)
		{
			x += step;
			y = k * x + b;
			setcolor(color);
			line(B.x, B.y, x, y);
		}
	}
}