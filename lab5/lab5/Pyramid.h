#pragma once

#include "Definitions.h"
#include "Point.h"
#include "Matrix.h"
#include "BresenhamAndFillingFunctions.h"

class Pyramid {
public:
	Pyramid();
	Pyramid(const Pyramid& par);
	~Pyramid();
	void rerenderPyramid();
	void moveAlongAxis(char axis);
	void moveReverseAxis(char axis);
	void rotateClockwise(char axis);
	void rotateCounterclockwise(char axis);
	void increaseScale();
	void decreaseScale();
	void printCenterCoordZ();
	Pyramid* createPyramidWithIsometricalProjection();
	friend class QueueOfPyramidSurfaces;
private:
	Point point1, point2, point3, point4, point5;
	Point centerPoint;
	Matrix* matrixOfPoints = nullptr;
	void findCenter();
	void moveToCenterCoords();
	void moveFromCenterCoords();
	Matrix* createMatrixOfPoints();
	void fillPointsWithMatrix(Matrix* matrix);

};