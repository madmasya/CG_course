#include "Floor.h"

Floor::Floor(Point A, Point B, Point C, Point D) : A(A), B(B), C(C), D(D) {}

Point Floor::findCentre()
{
	double centreX = (A.x + B.x + C.x + D.x) / 4;
	double centreY = (A.y + B.y + C.y + D.y) / 4;
	double centreZ = (A.z + B.z + C.z + D.z) / 4;
	Point centre(centreX, centreY, centreZ);
	return centre;
}
void Floor::moveToCentre(Point centrePoint)
{
	A - centrePoint;
	B - centrePoint;
	C - centrePoint;
	D - centrePoint;
}
void Floor::moveFromCentre(Point centrePoint)
{
	A + centrePoint;
	B + centrePoint;
	C + centrePoint;
	D + centrePoint;
}
void Floor::iso()
{
	Floor tmp(*this);
	tmp.moveToCentre(this->findCentre());
	tmp.A.iso();
	tmp.B.iso();
	tmp.C.iso();
	tmp.D.iso();
	tmp.moveFromCentre(this->findCentre());
	*this = tmp;
}
void Floor::printAndFill()
{
	iso();
	Triangle ABC(A, B, C, 8);
	Triangle ADC(A, D, C, 8);
	ABC.fill();
	ADC.fill();
	outtextxy(A.x, A.y, (char*)"AF");
	outtextxy(B.x, B.y, (char*)"BF");
	outtextxy(C.x, C.y, (char*)"CF");
	outtextxy(D.x, D.y, (char*)"DF");
}