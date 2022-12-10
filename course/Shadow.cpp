#include "Shadow.h"

Shadow::Shadow() : A(), B(), C(), D() {}

Shadow::Shadow(Point A, Point B, Point C, Point D) : A(A), B(B), C(C), D(D) {}

void Shadow::castShadow(Pyramid Pyramid, Point Light, Point Centre)
{
	A.z = (((Centre.y - Light.y) * (Pyramid.A.z - Light.z)) / (Pyramid.A.y - Light.y)) + Light.z;
	A.x = (((Centre.y - Light.y) * (Pyramid.A.x - Light.x)) / (Pyramid.A.y - Light.y)) + Light.x;
	A.y = Centre.y;

	B.z = (((Centre.y - Light.y) * (Pyramid.B.z - Light.z)) / (Pyramid.B.y - Light.y)) + Light.z;
	B.x = (((Centre.y - Light.y) * (Pyramid.B.x - Light.x)) / (Pyramid.B.y - Light.y)) + Light.x;
	B.y = Centre.y;

	C.z = (((Centre.y - Light.y) * (Pyramid.C.z - Light.z)) / (Pyramid.C.y - Light.y)) + Light.z;
	C.x = (((Centre.y - Light.y) * (Pyramid.C.x - Light.x)) / (Pyramid.C.y - Light.y)) + Light.x;
	C.y = Centre.y;

	D.z = (((Centre.y - Light.y) * (Pyramid.O.z - Light.z)) / (Pyramid.O.y - Light.y)) + Light.z;
	D.x = (((Centre.y - Light.y) * (Pyramid.O.x - Light.x)) / (Pyramid.O.y - Light.y)) + Light.x;
	D.y = Centre.y;
}

void Shadow::moveToCentre(Point centrePoint)
{
	A - centrePoint;
	B - centrePoint;
	C - centrePoint;
	D - centrePoint;
}

void Shadow::moveFromCentre(Point centrePoint)
{
	A + centrePoint;
	B + centrePoint;
	C + centrePoint;
	D + centrePoint;
}

void Shadow::iso(Point Centre)
{
	Shadow tmp(*this);
	tmp.moveToCentre(Centre);
	tmp.A.iso();
	tmp.B.iso();
	tmp.C.iso();
	tmp.D.iso();
	tmp.moveFromCentre(Centre);
	*this = tmp;
}

void Shadow::fillShadow(Pyramid Pyramid, Point Light, Point Centre)
{
	castShadow(Pyramid, Light, Centre);
	iso(Centre);
	Triangle ABC(A, B, C, 0);
	Triangle ADC(A, D, C, 0);
	Triangle DBC(D, B, C, 0);
	ABC.fill();
	ADC.fill();
	DBC.fill();
}