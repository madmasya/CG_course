
#include "BresenhamAndFillingFunctions.h"

void drawBresenhamLine(int x1, int y1, int x2, int y2, ArrayOfPoints* arr) {

	int startX, startY, endX, endY;

	/*find start and end point*/
	if (x1 < x2) {
		startX = x1;
		startY = y1;
		endX = x2;
		endY = y2;
	}
	else if (x2 < x1) {
		startX = x2;
		startY = y2;
		endX = x1;
		endY = y1;
	}
	else {
		if (y1 < y2) {
			startX = x1;
			startY = y1;
			endX = x2;
			endY = y2;
		}
		else {
			startX = x2;
			startY = y2;
			endX = x1;
			endY = y1;
		}
	}

	int deltaX = endX - startX;
	int deltaY = endY - startY;

	double tang = 0; // tan of angle
	double mistake = 0;

	putpixel(startX, startY, 10);
	if (arr->amountPoints == arr->sizeArr - 1)
		arr->resizePointArr();


	if (!arr->ifPointInArr(startX, startY)) {
		arr->addPointToArr(startX, startY);
		++arr->amountPoints;
	}

	
	if (abs(deltaY) < abs(deltaX)) {

		tang = (double)deltaY / (double)deltaX;

		for (int x = startX, y = startY; x <= endX; x++) {
			putpixel(x, y, 10);

			if (arr->amountPoints == arr->sizeArr - 1)
				arr->resizePointArr();

			if (!arr->ifPointInArr(x, y)) {
				arr->addPointToArr(x, y);
				++arr->amountPoints;
			}

			mistake += tang;
			if (tang > 0) {
				if (mistake > 0.5) {
					y++;
					mistake -= 1;
				}
			}
			else {
				if (mistake < -0.5) {
					y--;
					mistake += 1;
				}
			}
		}
	}
	else {

		tang = (double)deltaX / (double)deltaY;
		if (startY < endY)
			for (int y = startY, x = startX; y <= endY; y++) {
				putpixel(x, y, 10);

				if (arr->amountPoints == arr->sizeArr - 1)
					arr->resizePointArr();

				if (!arr->ifPointInArr(x, y)) {
					arr->addPointToArr(x, y);
					++arr->amountPoints;
				}

				mistake += tang;
				if (mistake > 0.5) {
					x++;
					mistake -= 1;
				}
			}
		else
			for (int y = startY, x = startX; y >= endY; y--) {
				putpixel(x, y, 10);

				if (arr->amountPoints == arr->sizeArr - 1)
					arr->resizePointArr();

				if (!arr->ifPointInArr(x, y)) {
					arr->addPointToArr(x, y);
					++arr->amountPoints;
				}

				mistake += tang;
				if (mistake < -0.5) {
					x++;
					mistake += 1;
				}
			}
	}

	return;
}

void fillPyramid(PyramidSurface* surface, ArrayOfPoints* arr, int color) {

	double centerX = 0, centerY = 0;

	centerX = (surface->point1->x + surface->point2->x + surface->point3->x + surface->point4->x) / 4;
	centerY = (surface->point1->y + surface->point2->y + surface->point3->y + surface->point4->y) / 4;

	int X = centerX;
	int Y = centerY;

	recursiveFilling(arr, X, Y, color);

	return;
}

void recursiveFilling(ArrayOfPoints* arr, int x, int y, int color) {

	if (arr->ifPointInArr(x, y))
		return;
	else {
		if (arr->amountPoints == arr->sizeArr - 1)
			arr->resizePointArr();

		arr->addPointToArr(x, y);
		++arr->amountPoints;
	}
	putpixel(x, y, color);

	if (!(arr->ifPointInArr(x + 1, y)))
		recursiveFilling(arr, x + 1, y, color);

	if (!(arr->ifPointInArr(x, y + 1)))
		recursiveFilling(arr, x, y + 1, color);

	if (!(arr->ifPointInArr(x, y - 1)))
		recursiveFilling(arr, x, y - 1, color);

	if (!(arr->ifPointInArr(x - 1, y)))
		recursiveFilling(arr, x - 1, y, color);

	return;
}