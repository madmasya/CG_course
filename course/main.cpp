#include "Pyramid.h"
#include "Floor.h"
#include "Shadow.h"
#include "Axis.h"
#include <iostream>

void makeSomeManipulations(char symb, Pyramid &PyramidToManipulate);

int main()
{
	initwindow(WWIDTH, WHEIGHT, "Course", 0, 0);

	// Main Pyramid
	Point A1(0 + WWIDTH / 2, 0 + WHEIGHT / 2, -20);
	Point B1(60 + WWIDTH / 2, 0 + WHEIGHT / 2, 0);
	Point C1(50 + WWIDTH / 2, 0 + WHEIGHT / 2, -50);
	Point O1(20 + WWIDTH / 2, -80 + WHEIGHT / 2, -20);
	
	// Second Pyramid
	Point A2(-50 + WWIDTH / 2, 0 + WHEIGHT / 2, 80);
	Point B2(10 + WWIDTH / 2, 0 + WHEIGHT / 2, 100);
	Point C2(0 + WWIDTH / 2, 0 + WHEIGHT / 2, 50);
	Point O2(-30 + WWIDTH / 2, -80 + WHEIGHT / 2, 80);
	
	Pyramid O1A1B1C1(O1, A1, B1, C1);
	Pyramid O2A2B2C2(O2, A2, B2, C2);
	
	while (1)
	{

		char Pyr = '9';
		Pyr = getch();
		while (1)
		{
			// LightCaster
			Point Light(0 + WWIDTH / 2, -250 + WHEIGHT / 2, -100);

			// Floor
			Point AF(-185 + WWIDTH / 2, 0 + WHEIGHT / 2, 200);
			Point BF(215 + WWIDTH / 2, 0 + WHEIGHT / 2, 200);
			Point CF(215 + WWIDTH / 2, 0 + WHEIGHT / 2, -200);
			Point DF(-185 + WWIDTH / 2, 0 + WHEIGHT / 2, -200);

			// Isometrical pyramids
			Pyramid O1A1B1C1ISO(O1A1B1C1);
			Pyramid O2A2B2C2ISO(O2A2B2C2);


			Floor floor(AF, BF, CF, DF);
			Axis axis;
			Shadow shadow;
			Point Centre = floor.findCentre();

			clearviewport();
			floor.printAndFill();

			shadow.fillShadow(O1A1B1C1, Light, Centre);
			shadow.fillShadow(O2A2B2C2, Light, Centre);

			Light - Centre;
			Light.iso();
			Light + Centre;

			int colours1[4] = { 1, 2, 3, 4 };
			O1A1B1C1ISO.printAndFill(Centre, colours1);

			int colours2[4] = { 4, 3, 2, 1 };
			O2A2B2C2ISO.printAndFill(Centre, colours2);

			setcolor(15);
			fillellipse(Light.x, Light.y, 5, 5);
			axis.print();

			if (Pyr == '1')
			{
				char symb;
				symb = getch();
				if (symb == '3') 
				{ 
					std::cout << "Return to Pyramid choice!" << std::endl;
					break; 
				}
				makeSomeManipulations(symb, O1A1B1C1);
			}
			else if (Pyr == '2')
			{
				char symb;
				symb = getch();
				if (symb == '3')
				{
					std::cout << "Return to Pyramid choice!" << std::endl;
					break;
				}
				makeSomeManipulations(symb, O2A2B2C2);
			}
			else if (Pyr == '0')
			{
				exit(1);
				break;
			}
			else
			{ 
				std::cout << "Wrong key!" << std::endl;
				break;
			}
		}
	}
	return 0;
}

void makeSomeManipulations(char symb, Pyramid &PyramidToManipulate)
{
	switch (symb)
	{
	case 'a':
	{
		PyramidToManipulate.move('x', false);
		break;
	}
	case 'w':
	{
		PyramidToManipulate.move('z', true);
		break;
	}
	case 's':
	{
		PyramidToManipulate.move('z', false);
		break;
	}
	case 'd':
	{
		PyramidToManipulate.move('x', true);
		break;
	}
	case 'q':
	{
		PyramidToManipulate.move('y', true);
		break;
	}
	case 'e':
	{
		PyramidToManipulate.move('y', false);
		break;
	}
	case 'x':
	{
		PyramidToManipulate.scale(true);
		break;
	}
	case 'z':
	{
		PyramidToManipulate.scale(false);
		break;
	}
	case '[':
	{
		PyramidToManipulate.rotate('x', false);
		break;
	}
	case ']':
	{
		PyramidToManipulate.rotate('x', true);
		break;
	}
	case ';':
	{
		PyramidToManipulate.rotate('y', false);
		break;
	}
	case '\'':
	{
		PyramidToManipulate.rotate('y', true);
		break;
	}
	case ',':
	{
		PyramidToManipulate.rotate('z', false);
		break;
	}
	case '.':
	{
		PyramidToManipulate.rotate('z', true);
		break;
	}
	case '0':
	{
		exit(1);
		break;
	}
	default:
	{
		std::cout << "Wrong key!" << std::endl;
		break;
	}
	}
}