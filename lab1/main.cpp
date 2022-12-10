#define _USE_MATH_DEFINES
#include <D:\Downloads\дз\актуальное\компьютерна€ графика\labs\libwinbgi\src\graphics.h>
#include <iostream>
#include <cmath>
#include "defaultlines.h"
#include "brezenham.h"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "RUS");
	initwindow(1000, 500, "Line", 1921 - 999, 0);
	int x1 = 50, y1 = 50, x2 = 100, y2 = 100;
	int x11 = 100, y11 = 50, x21 = 150, y21 = 100;
Menu:
	setcolor(15);
	settextstyle(10, 0, 1);
	outtextxy(x1 - 20, y1 - 20, (char*)"A");
	outtextxy(x2 + 5, y2 + 5, (char*)"B");
	outtextxy(x11 - 20, y11 - 20, (char*)"A1");
	outtextxy(x21 + 5, y21 + 5, (char*)"B1");
	setcolor(13);
	setlinestyle(0, 0, 3);
	line(x1, y1, x2, y2);
	BrezenhamLine(x11, y11, x21, y21);
	cout << "\t”правление:" << endl << "a (num4) - переместить линию влево на 10 единиц" << endl << "d (num6) - переместить линию вправо на 10 единиц" << endl << "w (num8) - переместить линию вверх на 10 единиц" << endl << "s (num5) - переместить линию вниз на 10 единиц" << endl;
	cout << "q (num7) - поворот линии против часовой стрелки на 10 градусов" << endl << "e (num9) - поворот линии по часовой стрелке на 10 градусов" << endl << "z (num-) - уменьшить линию на 10%" << endl << "x (num+) - увеличить линию на 10%" << endl;
	cout << endl << "0 - выйти\n\n";
	char symb = '1';
	while (symb != '0')
	{
		symb = cin.get();
		switch (symb)
		{
		case 'a': {
			moveLeft(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case 'd': {
			moveRight(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case 'w': {
			moveUp(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case 's': {
			moveDown(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case 'x': {
			scaleUp(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case 'z': {
			scaleDown(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case 'e': {
			rotateClockwise(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case 'q': {
			rotateCounterClockwise(x1, y1, x2, y2);
			system("cls");
			goto Menu;
		}
		case '4': {
			BrezenhamMoveLeft(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		case '6': {
			BrezenhamMoveRight(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		case '8': {
			BrezenhamMoveUp(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		case '5': {
			BrezenhamMoveDown(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		case '7': {
			BrezenhamRotateCounterClockwise(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		case '9': {
			BrezenhamRotateClockwise(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		case '+': {
			BrezenhamScaleUp(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		case '-': {
			BrezenhamScaleDown(x11, y11, x21, y21);
			system("cls");
			goto Menu;
		}
		}

	}
	closegraph();

	return 0;
}