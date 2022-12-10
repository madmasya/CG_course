#include "Axis.h"

Axis::Axis() : O(10, 50 + WHEIGHT, 0), A(110, 50 + WHEIGHT, 0), B(10, 150 + WHEIGHT, 0), C(10, 50 + WHEIGHT, 100) {}

void Axis::iso()
{
	Axis tmp(*this);
	tmp.O.iso();
	tmp.A.iso();
	tmp.B.iso();
	tmp.C.iso();
	*this = tmp;
}

void Axis::print()
{
	iso();
	setlinestyle(0, 0, 3);
	settextstyle(1, 0, 2);
	setcolor(4);
	line(O.x, O.y, A.x, A.y);
	outtextxy(A.x, A.y, (char*)"X");
	setcolor(2);
	line(O.x, O.y, B.x, B.y);
	outtextxy(B.x, B.y, (char*)"Y");
	setcolor(3);
	line(O.x, O.y, C.x, C.y);
	outtextxy(C.x, C.y, (char*)"Z");
	setlinestyle(0, 0, 1);
	settextstyle(0, 0, 1);
}