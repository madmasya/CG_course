#include "Pyramid.h"

Pyramid::Pyramid() : O(), A(), B(), C() {}

Pyramid::Pyramid(Point O, Point A, Point B, Point C) : O(O), A(A), B(B), C(C) {}

Pyramid::Pyramid(const Pyramid& Pyramid) : O(Pyramid.O), A(Pyramid.A), B(Pyramid.B), C(Pyramid.C) {}

Point Pyramid::findCentre()
{
	double centreX = (A.x + B.x + C.x + O.x) / 4;
	double centreY = (A.y + B.y + C.y + O.y) / 4;
	double centreZ = (A.z + B.z + C.z + O.z) / 4;
	Point centre(centreX, centreY, centreZ);
	return centre;
}

void Pyramid::moveToCentre(Point centrePoint)
{
	O - centrePoint;
	A - centrePoint;
	B - centrePoint;
	C - centrePoint;
}

void Pyramid::moveFromCentre(Point centrePoint)
{
	O + centrePoint;
	A + centrePoint;
	B + centrePoint;
	C + centrePoint;
}

void Pyramid::iso(Point Centre)
{
	Pyramid tmp(*this);
	tmp.moveToCentre(Centre);
	tmp.O.iso();
	tmp.A.iso();
	tmp.B.iso();
	tmp.C.iso();
	tmp.moveFromCentre(Centre);
	*this = tmp;
}

Triangle** Pyramid::pyramidToTriangles(int* colours)
{
	Triangle** Triangles = new Triangle * [4];
	Triangles[0] = new Triangle(A, B, C, colours[0]);
	Triangles[1] = new Triangle(O, A, B, colours[1]);
	Triangles[2] = new Triangle(O, A, C, colours[2]);
	Triangles[3] = new Triangle(O, B, C, colours[3]);
	return Triangles;
}

Triangle** Pyramid::sortTriangles(int* colours)
{
	Triangle** Triangles = pyramidToTriangles(colours);
	for (int i = 0; i < 4; i++) {
		bool flag = true;
		for (int j = 0; j < 4 - (i + 1); j++) {
			if (Triangles[j]->findZCentral() < Triangles[j + 1]->findZCentral()) {
				flag = false;
				std::swap(Triangles[j], Triangles[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	return Triangles;
}

void Pyramid::move(char axis, bool direction)
{
	A.move(axis, direction);
	B.move(axis, direction);
	C.move(axis, direction);
	O.move(axis, direction);
}

void Pyramid::scale(bool direction)
{
	Pyramid tmp(*this);
	tmp.moveToCentre(findCentre());
	tmp.O.scale(direction);
	tmp.A.scale(direction);
	tmp.B.scale(direction);
	tmp.C.scale(direction);
	tmp.moveFromCentre(findCentre());
	*this = tmp;
}

void Pyramid::rotate(char axis, bool direction)
{
	Pyramid tmp(*this);
	tmp.moveToCentre(findCentre());
	tmp.O.rotate(axis, direction);
	tmp.A.rotate(axis, direction);
	tmp.B.rotate(axis, direction);
	tmp.C.rotate(axis, direction);
	tmp.moveFromCentre(findCentre());
	*this = tmp;
}

void Pyramid::printAndFill(Point Centre, int* colours)
{
	iso(Centre);
	Triangle** Triangles = sortTriangles(colours);
	setcolor(14);
	for (int i = 0; i < 4; i++)
	{
		Triangles[i]->fill();
		setcolor(15);
		setlinestyle(0, 0, 2);
		line(Triangles[i]->A.x, Triangles[i]->A.y, Triangles[i]->B.x, Triangles[i]->B.y);
		line(Triangles[i]->B.x, Triangles[i]->B.y, Triangles[i]->C.x, Triangles[i]->C.y);
		line(Triangles[i]->C.x, Triangles[i]->C.y, Triangles[i]->A.x, Triangles[i]->A.y);
		setlinestyle(0, 0, 1);
	}
}