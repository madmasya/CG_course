#include <iostream>
#include "QueueOfPyramidSurfaces.h"
#include "Pyramid.h"

using std::invalid_argument;
using std::cout;
using std::endl;

Pyramid::Pyramid() {

	point1.x = 200;
	point1.y = 0;
	point1.z = 0;

	point2.x = 200;
	point2.y = 100;
	point2.z = -100;

	point3.x = 300;
	point3.y = 100;
	point3.z = -100;

	point4.x = 300;
	point4.y = 100;
	point4.z = 0;

	point5.x = 200;
	point5.y = 100;
	point5.z = 0;

	findCenter();
	createMatrixOfPoints();
}

/*copy costructor*/
Pyramid::Pyramid(const Pyramid& par) {

	point1 = par.point1;
	point2 = par.point2;
	point3 = par.point3;
	point4 = par.point4;
	point5 = par.point5;


	centerPoint = par.centerPoint;

	matrixOfPoints = new Matrix(par.matrixOfPoints->sizeRows, par.matrixOfPoints->sizeColumns, par.matrixOfPoints->matrix);

}

Pyramid::~Pyramid() {

	delete(matrixOfPoints);
}

void Pyramid::rerenderPyramid() {

	clearviewport();

	QueueOfPyramidSurfaces queue(*this);
	ArrayOfPoints* arrOfPoints;
	arrOfPoints = new ArrayOfPoints;

	queue.arr[0]->drawSurface(arrOfPoints);
	fillPyramid(queue.arr[0], arrOfPoints, 2);

	delete arrOfPoints;

	arrOfPoints = new ArrayOfPoints;
	queue.arr[1]->drawSurface(arrOfPoints);
	fillPyramid(queue.arr[1], arrOfPoints, 3);

	delete arrOfPoints;

	arrOfPoints = new ArrayOfPoints;
	queue.arr[2]->drawSurface(arrOfPoints);
	fillPyramid(queue.arr[2], arrOfPoints, 4);

	delete arrOfPoints;

	arrOfPoints = new ArrayOfPoints;
	queue.arr[3]->drawSurface(arrOfPoints);
	fillPyramid(queue.arr[3], arrOfPoints, 5);

	delete arrOfPoints;

	arrOfPoints = new ArrayOfPoints;
	queue.arr[4]->drawSurface(arrOfPoints);
	fillPyramid(queue.arr[4], arrOfPoints, 6);

	delete arrOfPoints;

	setcolor(10);

	return;
}

void Pyramid::findCenter() {

	centerPoint.x = (point1.x + point2.x + point3.x + point4.x + point5.x) / 5;
	centerPoint.y = (point1.y + point2.y + point3.y + point4.y + point5.y) / 5;
	centerPoint.z = (point1.z + point2.z + point3.z + point4.z + point5.z) / 5;
}

void Pyramid::moveToCenterCoords() {

	point1.decPoints(centerPoint);
	point2.decPoints(centerPoint);
	point3.decPoints(centerPoint);
	point4.decPoints(centerPoint);
	point5.decPoints(centerPoint);

}

void Pyramid::moveFromCenterCoords() {


	point1.sumPoints(centerPoint);
	point2.sumPoints(centerPoint);
	point3.sumPoints(centerPoint);
	point4.sumPoints(centerPoint);
	point5.sumPoints(centerPoint);
}

/*also returns pointer to this matrix*/
Matrix* Pyramid::createMatrixOfPoints() {

	if (matrixOfPoints != nullptr)
		delete matrixOfPoints;

	double matrixArray[32] = { point1.x, point1.y, point1.z, 1,
							   point2.x, point2.y, point2.z, 1,
							   point3.x, point3.y, point3.z, 1,
							   point4.x, point4.y, point4.z, 1,
							   point5.x, point5.y, point5.z, 1,
																};
	matrixOfPoints = new Matrix(5, 4, matrixArray);

	return matrixOfPoints;
}

/*matrix 5x4 with x, y, z, 1 columns*/
void Pyramid::fillPointsWithMatrix(Matrix* matrix) {

	point1.x = matrix->matrix[0];
	point1.y = matrix->matrix[1];
	point1.z = matrix->matrix[2];

	point2.x = matrix->matrix[4];
	point2.y = matrix->matrix[5];
	point2.z = matrix->matrix[6];

	point3.x = matrix->matrix[8];
	point3.y = matrix->matrix[9];
	point3.z = matrix->matrix[10];

	point4.x = matrix->matrix[12];
	point4.y = matrix->matrix[13];
	point4.z = matrix->matrix[14];

	point5.x = matrix->matrix[16];
	point5.y = matrix->matrix[17];
	point5.z = matrix->matrix[18];
}

/*axis - x, y or z*/
void Pyramid::moveAlongAxis(char axis) {

	switch (axis) {
	case 'x':
		point1.increaseX(SHIFT_VALUE);
		point2.increaseX(SHIFT_VALUE);
		point3.increaseX(SHIFT_VALUE);
		point4.increaseX(SHIFT_VALUE);
		point5.increaseX(SHIFT_VALUE);
		break;
	case 'y':
		point1.increaseY(SHIFT_VALUE);
		point2.increaseY(SHIFT_VALUE);
		point3.increaseY(SHIFT_VALUE);
		point4.increaseY(SHIFT_VALUE);
		point5.increaseY(SHIFT_VALUE);
		break;
	case 'z':
		point1.increaseZ(SHIFT_VALUE);
		point2.increaseZ(SHIFT_VALUE);
		point3.increaseZ(SHIFT_VALUE);
		point4.increaseZ(SHIFT_VALUE);
		point5.increaseZ(SHIFT_VALUE);
		break;
	default:
		throw invalid_argument("Wrong axis to move!");
	}

	findCenter();
	createMatrixOfPoints();
}

void Pyramid::moveReverseAxis(char axis) {

	switch (axis) {
	case 'x':
		point1.decreaseX(SHIFT_VALUE);
		point2.decreaseX(SHIFT_VALUE);
		point3.decreaseX(SHIFT_VALUE);
		point4.decreaseX(SHIFT_VALUE);
		point5.decreaseX(SHIFT_VALUE);
		break;
	case 'y':
		point1.decreaseY(SHIFT_VALUE);
		point2.decreaseY(SHIFT_VALUE);
		point3.decreaseY(SHIFT_VALUE);
		point4.decreaseY(SHIFT_VALUE);
		point5.decreaseY(SHIFT_VALUE);
		break;
	case 'z':
		point1.decreaseZ(SHIFT_VALUE);
		point2.decreaseZ(SHIFT_VALUE);
		point3.decreaseZ(SHIFT_VALUE);
		point4.decreaseZ(SHIFT_VALUE);
		point5.decreaseZ(SHIFT_VALUE);
		break;
	default:
		throw invalid_argument("Wrong axis to move!");
	}

	findCenter();
	createMatrixOfPoints();
}

void Pyramid::rotateClockwise(char axis) {

	moveToCenterCoords();
	createMatrixOfPoints();

	switch (axis) {
	case 'x':
	{
		double matrixArray[16] = { 1,   0,                 0,                0,
								   0,  cos(ROTATE_VALUE), sin(ROTATE_VALUE), 0,
								   0, -sin(ROTATE_VALUE), cos(ROTATE_VALUE), 0,
								   0,   0,                 0,                1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'y':
	{
		double matrixArray[16] = { cos(ROTATE_VALUE), 0, sin(ROTATE_VALUE), 0,
									0,				  1,  0,				0,
								  -sin(ROTATE_VALUE), 0, cos(ROTATE_VALUE), 0,
									0,				  0,  0,                1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'z':
	{
		double matrixArray[16] = { cos(ROTATE_VALUE), sin(ROTATE_VALUE), 0, 0,
								  -sin(ROTATE_VALUE), cos(ROTATE_VALUE), 0,	0,
									0,				   0,				 1, 0,
									0,				   0,				 0, 1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	default:
		throw invalid_argument("Wrong rotation axis!");
	}

	moveFromCenterCoords();
	createMatrixOfPoints();
	findCenter();
}

void Pyramid::rotateCounterclockwise(char axis) {

	moveToCenterCoords();
	createMatrixOfPoints();

	switch (axis) {
	case 'x':
	{
		double matrixArray[16] = { 1,   0,                 0,                0,
								   0, cos(ROTATE_VALUE), -sin(ROTATE_VALUE), 0,
								   0, sin(ROTATE_VALUE),  cos(ROTATE_VALUE), 0,
								   0,   0,                 0,                1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'y':
	{
		double matrixArray[16] = { cos(ROTATE_VALUE), 0, -sin(ROTATE_VALUE), 0,
									0,				  1,  0,				 0,
								   sin(ROTATE_VALUE), 0,  cos(ROTATE_VALUE), 0,
									0,				  0,  0,                 1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'z':
	{
		double matrixArray[16] = { cos(ROTATE_VALUE), -sin(ROTATE_VALUE), 0, 0,
								   sin(ROTATE_VALUE),  cos(ROTATE_VALUE), 0, 0,
									0,				   0,				  1, 0,
									0,				   0,				  0, 1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	default:
		throw invalid_argument("Wrong rotation axis!");
	}

	moveFromCenterCoords();
	createMatrixOfPoints();
	findCenter();
}

void Pyramid::increaseScale() {

	moveToCenterCoords();

	point1.x *= 1 + ADD_SCALE;
	point1.y *= 1 + ADD_SCALE;
	point1.z *= 1 + ADD_SCALE;

	point2.x *= 1 + ADD_SCALE;
	point2.y *= 1 + ADD_SCALE;
	point2.z *= 1 + ADD_SCALE;

	point3.x *= 1 + ADD_SCALE;
	point3.y *= 1 + ADD_SCALE;
	point3.z *= 1 + ADD_SCALE;

	point4.x *= 1 + ADD_SCALE;
	point4.y *= 1 + ADD_SCALE;
	point4.z *= 1 + ADD_SCALE;

	point5.x *= 1 + ADD_SCALE;
	point5.y *= 1 + ADD_SCALE;
	point5.z *= 1 + ADD_SCALE;

	moveFromCenterCoords();
	findCenter();
	createMatrixOfPoints();
}

void Pyramid::decreaseScale() {

	moveToCenterCoords();

	point1.x *= 1 - ADD_SCALE;
	point1.y *= 1 - ADD_SCALE;
	point1.z *= 1 - ADD_SCALE;

	point2.x *= 1 - ADD_SCALE;
	point2.y *= 1 - ADD_SCALE;
	point2.z *= 1 - ADD_SCALE;

	point3.x *= 1 - ADD_SCALE;
	point3.y *= 1 - ADD_SCALE;
	point3.z *= 1 - ADD_SCALE;

	point4.x *= 1 - ADD_SCALE;
	point4.y *= 1 - ADD_SCALE;
	point4.z *= 1 - ADD_SCALE;

	point5.x *= 1 - ADD_SCALE;
	point5.y *= 1 - ADD_SCALE;
	point5.z *= 1 - ADD_SCALE;
	moveFromCenterCoords();
	findCenter();
	createMatrixOfPoints();
}

void Pyramid::printCenterCoordZ() {

	cout << "Current z coordinate of center: " << centerPoint.z << endl;
	return;
}

Pyramid* Pyramid::createPyramidWithIsometricalProjection() {

	Pyramid* newPyramid = new Pyramid(*this);

	newPyramid->findCenter();

	newPyramid->moveToCenterCoords();
	newPyramid->createMatrixOfPoints();

	double theta = (double)45 / 180 * M_PI;
	double fi = (double)45 / 180 * M_PI;

	double matrixArray[16] = { cos(theta), sin(theta) * sin(fi), -sin(theta) * cos(fi), 0,
								  0,	           cos(fi),		          sin(fi),      0,
							  sin(theta),  -cos(theta) * sin(fi), cos(theta) * cos(fi), 0,
								  0,				 0,						 0,			1 };

	Matrix* M = new Matrix(4, 4, matrixArray);
	Matrix* newMatrix = *matrixOfPoints * *M;
	newPyramid->fillPointsWithMatrix(newMatrix);
	delete M;

	newPyramid->moveFromCenterCoords();
	newPyramid->createMatrixOfPoints();
	newPyramid->findCenter();

	return newPyramid;
}