#define _USE_MATH_DEFINES
#include <D:\Downloads\дз\актуальное\компьютерная графика\labs\libwinbgi\src\graphics.h>
#include <cmath>

void BrezenhamLine(int x1, int y1, int x2, int y2)
{
	const int deltaX = abs(x2 - x1);
	const int deltaY = abs(y2 - y1);
	const int signX = x1 < x2 ? 1 : -1;
	const int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;
	putpixel(x2, y2, 12);
	while (x1 != x2 || y1 != y2)
	{
		putpixel(x1, y1, 12);
		int error2 = error * 2;
		if (error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if (error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}

}

void BrezenhamMoveLeft(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	x1 -= 10;
	x2 -= 10;
	BrezenhamLine(x1, y1, x2, y2);
}

void BrezenhamMoveRight(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	x1 += 10;
	x2 += 10;
	BrezenhamLine(x1, y1, x2, y2);
}

void BrezenhamMoveUp(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	y1 -= 10;
	y2 -= 10;
	BrezenhamLine(x1, y1, x2, y2);
}

void BrezenhamMoveDown(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	y1 += 10;
	y2 += 10;
	BrezenhamLine(x1, y1, x2, y2);
}

void BrezenhamScaleUp(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int lengthX = x2 - x1;
	int lengthY = y2 - y1;
	x2 = x1 + lengthX * 1.1;
	y2 = y1 + lengthY * 1.1;
	BrezenhamLine(x1, y1, x2, y2);
}

void BrezenhamScaleDown(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int lengthX = x2 - x1;
	int lengthY = y2 - y1;
	x2 = x1 + lengthX * 0.9;
	y2 = y1 + lengthY * 0.9;
	BrezenhamLine(x1, y1, x2, y2);
}

void BrezenhamRotateClockwise(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int newX = x2 - x1;
	int newY = y2 - y1;

	x2 = x1 + (newX * cos(10 * M_PI / 180) - newY * sin(10 * M_PI / 180));
	y2 = y1 + (newX * sin(10 * M_PI / 180) + newY * cos(10 * M_PI / 180));
	BrezenhamLine(x1, y1, x2, y2);
}

void BrezenhamRotateCounterClockwise(int& x1, int& y1, int& x2, int& y2)
{
	clearviewport();
	int newX = x2 - x1;
	int newY = y2 - y1;

	x2 = x1 + (newX * cos(-10 * M_PI / 180) - newY * sin(-10 * M_PI / 180));
	y2 = y1 + (newX * sin(-10 * M_PI / 180) + newY * cos(-10 * M_PI / 180));
	BrezenhamLine(x1, y1, x2, y2);
}