#define _USE_MATH_DEFINES
#include <D:\Downloads\дз\актуальное\компьютерна€ графика\labs\libwinbgi\src\graphics.h>
#include <iostream>
#include <cmath>
#include <process.h>
void Rect(int& xa, int& ya, int& xb, int& yb, int& xc, int& yc, int& xd, int& yd)
{
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(xa, ya, xb, yb);
	line(xb, yb, xc, yc);
	line(xc, yc, xd, yd);
	line(xd, yd, xa, ya);
}
void moveX(int& xa, int& xb, int& xc, int& xd, char flag)
{
	clearviewport();
	if (flag == 'r')
	{
		xa += 10;
		xb += 10;
		xc += 10;
		xd += 10;
	}
	else
	{
		xa -= 10;
		xb -= 10;
		xc -= 10;
		xd -= 10;
	}
}
void moveY(int& ya, int& yb, int& yc, int& yd, char flag)
{
	clearviewport();
	if (flag == 'u')
	{
		ya -= 10;
		yb -= 10;
		yc -= 10;
		yd -= 10;
	}
	else
	{
		ya += 10;
		yb += 10;
		yc += 10;
		yd += 10;
	}
}
void scaleLine(int& x1, int& y1, int& x2, int& y2, char flag)
{
	if (flag == 'u')
	{
		int lengthX = x2 - x1;
		int lengthY = y2 - y1;
		x2 = x1 + lengthX * 1.1;
		y2 = y1 + lengthY * 1.1;
	}
	else
	{
		int lengthX = x2 - x1;
		int lengthY = y2 - y1;
		x2 = x1 + lengthX * 0.9;
		y2 = y1 + lengthY * 0.9;
	}
}
void scale(int& xa, int& ya, int& xb, int& yb, int& xc, int& yc, int& xd, int& yd, char flag)
{
	clearviewport();
	scaleLine(xa, ya, xb, yb, flag);
	scaleLine(xa, ya, xd, yd, flag);
	scaleLine(xa, ya, xc, yc, flag);
}
void rotateLine(int& x1, int& y1, int& x2, int& y2, char flag)
{
	if (flag == 'e')
	{
		int newX = x2 - x1;
		int newY = y2 - y1;
		x2 = x1 + (newX * cos(10 * M_PI / 180) - newY * sin(10 * M_PI / 180));
		y2 = y1 + (newX * sin(10 * M_PI / 180) + newY * cos(10 * M_PI / 180));
	}
	else
	{
		int newX = x2 - x1;
		int newY = y2 - y1;
		x2 = x1 + (newX * cos(-10 * M_PI / 180) - newY * sin(-10 * M_PI / 180));
		y2 = y1 + (newX * sin(-10 * M_PI / 180) + newY * cos(-10 * M_PI / 180));
	}
}
void rotate(int& xa, int& ya, int& xb, int& yb, int& xc, int& yc, int& xd, int& yd, char flag)
{
	clearviewport();
	rotateLine(xa, ya, xb, yb, flag);
	rotateLine(xa, ya, xd, yd, flag);
	rotateLine(xa, ya, xc, yc, flag);
}
void colourizeTRIANGLE(int& xa, int& ya, int& xb, int& yb, int& xc, int& yc)
{
	int xleft = xa, xright = xa, yleft = ya, yright = ya, ytop = ya, ymid = ya, ybot = ya, xtop = xa, xmid = xa, xbot = xa;
	
	// find the top point of ABC
	if (ytop > yc)
	{
		ytop = yc;
		xtop = xc;
	}
	if (ytop > yb)
	{
		ytop = yb;
		xtop = xb;
	}

	// find the bottom point of ABC
	if (ybot < yc)
	{
		ybot = yc;
		xbot = xc;
	}
	if (ybot < yb)
	{
		ybot = yb;
		xbot = xb;
	}

	// find the middle-height point of ABC
	if (ytop == ya && ybot == yc)
	{
		ymid = yb;
		xmid = xb;
	}
	if (ytop == ya && ybot == yb)
	{
		ymid = yc;
		xmid = xc;
	}
	if (ytop == yb && ybot == ya)
	{
		ymid = yc;
		xmid = xc;
	}
	if (ytop == yb && ybot == yc)
	{
		ymid = ya;
		xmid = xa;
	}
	if (ytop == yc && ybot == ya)
	{
		ymid = yb;
		xmid = xb;
	}
	if (ytop == yc && ybot == yb)
	{
		ymid = ya;
		xmid = xa;
	}

	// find the left point of ABC
	if (xleft > xc)
	{
		xleft = xc;
		yleft = yc;
	}
	if (xleft > xb)
	{
		xleft = xb;
		yleft = yb;
	}

	// find the right point of ABC
	if (xright < xc)
	{
		xright = xc;
		yright = yc;
	}
	if (xright < xb)
	{
		xright = xb;
		yright = yb;
	}
	if (ytop == ymid)
	{
		xright = xb;
		yright = yb;
		xmid = xb;
		ymid = yb;
	}
	if (ybot == ymid)
	{
		xleft = xb;
		yleft = yb;
		xmid = xb;
		ymid = yb;
	}

	// build the horizontal line from middle point and colourize ABC
	float k;
	int xcross, xleft1, xright1;
	if (xtop == xbot || xmid == xtop)
		xcross = xleft;
	else
	{
		k = ((float)ytop - (float)ybot) / ((float)xtop - xbot);
		xcross = (ymid - ytop + k * xtop) / k;
	}

	if (xcross < xright && xcross > xmid) 
	{ 
		xleft1 = xleft; 
		xright1 = xcross; 
	}
	else 
		if (xcross > xleft && xcross < xmid)
		{
			xleft1 = xcross;
			xright1 = xmid;
		}
		else
		{
			xleft1 = xleft;
			xright1 = xright;
		}
	int i = 1;
	int j = 0;
	while (xleft1 < xright1)
	{
		setcolor(i);
		if (i < 15)
		{
			if (j < 10) j++;
			else { i++; j = 0; }
		}
		else i = 1;
		line(xtop, ytop, xleft1, ymid);
		line(xbot, ybot, xleft1, ymid);
		xleft1++;
	}
}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	setlocale(LC_ALL, "RUS");
	initwindow(1000, 500, "Square", 1921 - 999, 0);
	int xa = 100, ya = 100, xb = 400, yb = 100, xc = 400, yc = 400, xd = 100, yd = 400;
	while (1)
	{
		system("cls");
		setcolor(15);
		settextstyle(10, 0, 1);
		outtextxy(xa - 20, ya + 10, (char*)"A");
		outtextxy(xb + 10, yb + 10, (char*)"B");
		outtextxy(xc + 10, yc - 20, (char*)"C");
		outtextxy(xd - 20, yd - 20, (char*)"D");
		Rect(xa, ya, xb, yb, xc, yc, xd, yd);
		colourizeTRIANGLE(xa, ya, xb, yb, xc, yc);
		colourizeTRIANGLE(xa, ya, xd, yd, xc, yc);
		cout << "\t”правление:" << endl << "a - переместить квадрат влево на 10 единиц" << endl << "d - переместить квадрат вправо на 10 единиц" << endl << "w - переместить квадрат вверх на 10 единиц" << endl << "s - переместить квадрат вниз на 10 единиц" << endl;
		cout << "q - поворот квадрата против часовой стрелки на 10 градусов" << endl << "e - поворот квадрата по часовой стрелке на 10 градусов" << endl << "z - уменьшить квадрат на 10 % " << endl << "x - увеличить квадрат на 10%" << endl;
		cout << endl << "0 - выйти\n\n";
		char symb = '1';
		symb = getch();
		switch (symb)
		{
		case 'a': {
			moveX(xa, xb, xc, xd, 'l');
			Rect(xa, ya, xb, yb, xc, yc, xd, yd);
			break;
		}
		case 'd': {
			moveX(xa, xb, xc, xd, 'r');
			Rect(xa, ya, xb, yb, xc, yc, xd, yd);
			break;
		}
		case 'w': {
			moveY(ya, yb, yc, yd, 'u');
			Rect(xa, ya, xb, yb, xc, yc, xd, yd);
			break;
		}
		case 's': {
			moveY(ya, yb, yc, yd, 'd');
			Rect(xa, ya, xb, yb, xc, yc, xd, yd);
			break;
		}
		case 'x': {
			scale(xa, ya, xb, yb, xc, yc, xd, yd, 'u');
			Rect(xa, ya, xb, yb, xc, yc, xd, yd);
			break;
		}
		case 'z': {
			scale(xa, ya, xb, yb, xc, yc, xd, yd, 'd');
			Rect(xa, ya, xb, yb, xc, yc, xd, yd);
			break;
		}
		case 'e': {
			rotate(xa, ya, xb, yb, xc, yc, xd, yd, 'e');
			break;
		}
		case 'q': {
			rotate(xa, ya, xb, yb, xc, yc, xd, yd, 'q');
			break;
		}
		case '0': {
			exit(1);
		}
		default: {
			cout << "¬ведена неверна€ команда.\n\n";
			system("pause");
			break;
		}
		}
	}
	closegraph();
	return 0;
}