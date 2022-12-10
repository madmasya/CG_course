#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <conio.h>

#include "Definitions.h"
#include "Pyramid.h"

using namespace std;


int main(int argc, char* argv[])
{

	initwindow(1000, 500, "Pyramid", 1921 - 999, 0);

	Pyramid pyr;
	Pyramid* isPyr;

	while (1) {

		isPyr = pyr.createPyramidWithIsometricalProjection();
		isPyr->rerenderPyramid();
		delete(isPyr);

		char c = _getch();
		std::cout << c;

		switch (c) {
		case 'w':
			pyr.moveReverseAxis('y');
			break;
		case 's':
			pyr.moveAlongAxis('y');
			break;
		case 'd':
			pyr.moveAlongAxis('x');
			break;
		case 'a':
			pyr.moveReverseAxis('x');
			break;
		case 'e':
			pyr.moveReverseAxis('z');
			pyr.printCenterCoordZ();
			break;
		case 'q':
			pyr.moveAlongAxis('z');
			pyr.printCenterCoordZ();
			break;
		case 'x':
			pyr.increaseScale();
			break;
		case 'z':
			pyr.decreaseScale();
			break;
		case 'i':
			pyr.rotateCounterclockwise('x');
			break;
		case 'o':
			pyr.rotateClockwise('x');
			break;
		case 'k':
			pyr.rotateCounterclockwise('y');
			break;
		case 'l':
			pyr.rotateClockwise('y');
			break;
		case 'n':
			pyr.rotateClockwise('z');
			break;
		case 'm':
			pyr.rotateCounterclockwise('z');
			break;
		case '0':
			return 0;
		default:
			std::cout << std::endl << "Wrong key!" << std::endl;
		}
	}

	return 0;
}

