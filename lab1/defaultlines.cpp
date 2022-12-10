#define _USE_MATH_DEFINES
#include <D:\Downloads\дз\актуальное\компьютерная графика\labs\libwinbgi\src\graphics.h>
#include <cmath>



void moveLeft(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	x1 -= 10;
	x2 -= 10;
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}

void moveRight(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	x1 += 10;
	x2 += 10;
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}

void moveUp(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	y1 -= 10;
	y2 -= 10;
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}

void moveDown(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	y1 += 10;
	y2 += 10;
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}

void scaleUp(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int lengthX = x2 - x1;
	int lengthY = y2 - y1;
	x2 = x1 + lengthX * 1.5;
	y2 = y1 + lengthY * 1.5;
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}

void scaleDown(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int lengthX = x2 - x1;
	int lengthY = y2 - y1;
	x2 = x1 + lengthX * 0.5;
	y2 = y1 + lengthY * 0.5;
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}

void rotateClockwise(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int newX = x2 - x1;
	int newY = y2 - y1;

	x2 = x1 + (newX * cos(10 * M_PI / 180) - newY * sin(10 * M_PI / 180));
	y2 = y1 + (newX * sin(10 * M_PI / 180) + newY * cos(10 * M_PI / 180));
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}

void rotateCounterClockwise(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int newX = x2 - x1;
	int newY = y2 - y1;

	x2 = x1 + (newX * cos(-10 * M_PI / 180) - newY * sin(-10 * M_PI / 180));
	y2 = y1 + (newX * sin(-10 * M_PI / 180) + newY * cos(-10 * M_PI / 180));
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
}