#define _USE_MATH_DEFINES
#include <D:\Downloads\дз\актуальное\компьютерная графика\labs\libwinbgi\src\graphics.h>
#include <iostream>
#include <cmath>
#include <process.h>

class point
{
public:
	double x;
	double y;
	double z;
public:
	void sumPoints(point& point)
	{
		x += point.x;
		y += point.y;
		z += point.z;
	}

	void decPoints(point& point)
	{
		x -= point.x;
		y -= point.y;
		z -= point.z;
	}

	void increaseX(double val)
	{
		x += val;
	}

	void increaseY(double val)
	{
		y += val;
	}

	void increaseZ(double val)
	{
		z += val;
	}

	void decreaseX(double val)
	{
		x -= val;
	}

	void decreaseY(double val)
	{
		y -= val;
	}

	void decreaseZ(double val)
	{
		z -= val;
	}
};

class Matrix
{
private:
	double* matrix;
	int sizeRows;
	int sizeColumns;
public:
	Matrix(int sizeRows, int sizeColumns);
	Matrix(int sizeRows, int sizeColumns, double* initialisationMatrix);
	~Matrix();
	void fillMatrix(int sizeRows, int sizeColumns, double* initialisationMatrix);
	Matrix* operator* (Matrix& m2);
	friend class Pyramid;
};

Matrix::Matrix(int sizeRows, int sizeColumns) : sizeRows(sizeRows), sizeColumns(sizeColumns)
{
	matrix = new double[sizeRows * sizeColumns]{};
}

Matrix::Matrix(int sizeRows, int sizeColumns, double* initialisationMatrix) : sizeRows(sizeRows), sizeColumns(sizeColumns)
{
	matrix = new double[sizeRows * sizeColumns];
	for (int i = 0; i < sizeColumns * sizeRows; i++)
		matrix[i] = initialisationMatrix[i];
}

Matrix::~Matrix()
{
	delete[] matrix;
}

Matrix* Matrix::operator* (Matrix& m2)
{
	double* newMatrix = new double[sizeRows * m2.sizeColumns];
	int newMatrixIndex = 0;

	for (int i = 0; i < sizeRows; i++)
	{
		for (int j = 0; j < m2.sizeColumns; j++)
		{
			double result = 0;
			int m = i * sizeColumns;
			int n = j;
			for (int k = 0; k < sizeColumns; k++, m++, n += m2.sizeColumns)
				result += matrix[m] * m2.matrix[n];
			newMatrix[newMatrixIndex++] = result;
		}
	}

	Matrix* M = new Matrix(sizeRows, m2.sizeColumns, newMatrix);

	delete[] newMatrix;

	return M;
}

class Pyramid
{
private:
	// точки
	point point1, point2, point3, point4, point5;
	point centerPoint;
	Matrix* matrixOfPoints;
private:
	// функции над точками
	void findCenter();
	void moveToCenterCoords();
	void moveFromCenterCoords();
	Matrix* createMatrixOfPoints();
	void fillPointsWithMatrix(Matrix* matrix);
public:
	Pyramid();
	Pyramid(const Pyramid& p2);
	~Pyramid();
	void renderPyramid();
	void moveAlongAxis(char axis);
	void moveReverseAxis(char axis);
	void rotateClockwise(char axis);
	void rotateCounterClockwise(char axis);
	void increaseScale();
	void decreaseScale();
	Pyramid* createPyramidWithIsometricalProjection();
};

void Pyramid::rotateCounterClockwise(char axis)
{
	moveToCenterCoords();
	createMatrixOfPoints();

	switch (axis) {
	case 'x':
	{
		double matrixArray[16] = { 1,   0,                 0,                0,
								   0,  cos(double(10)/180*M_PI), sin(double(10)/180*M_PI), 0,
								   0, -sin(double(10)/180*M_PI), cos(double(10)/180*M_PI), 0,
								   0,   0,                 0,                1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'y':
	{
		double matrixArray[16] = { cos(double(10)/180*M_PI), 0, sin(double(10)/180*M_PI), 0,
									0,				  1,  0,				0,
								  -sin(double(10)/180*M_PI), 0, cos(double(10)/180*M_PI), 0,
									0,				  0,  0,                1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'z':
	{
		double matrixArray[16] = { cos(double(10)/180*M_PI), sin(double(10)/180*M_PI), 0, 0,
								  -sin(double(10)/180*M_PI), cos(double(10)/180*M_PI), 0,	0,
									0,				   0,				 1, 0,
									0,				   0,				 0, 1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	default:
		std::cout << "Wrong rotation axis!";
	}

	moveFromCenterCoords();
	createMatrixOfPoints();
	findCenter();
}

void Pyramid::rotateClockwise(char axis)
{
	moveToCenterCoords();
	createMatrixOfPoints();

	switch (axis) {
	case 'x':
	{
		double matrixArray[16] = { 1,   0,                 0,                0,
								   0, cos(double(10)/180*M_PI), -sin(double(10)/180*M_PI), 0,
								   0, sin(double(10)/180*M_PI),  cos(double(10)/180*M_PI), 0,
								   0,   0,                 0,                1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'y':
	{
		double matrixArray[16] = { cos(double(10)/180*M_PI), 0, -sin(double(10)/180*M_PI), 0,
									0,				  1,  0,				 0,
								   sin(double(10)/180*M_PI), 0,  cos(double(10)/180*M_PI), 0,
									0,				  0,  0,                 1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	case 'z':
	{
		double matrixArray[16] = { cos(double(10)/180*M_PI), -sin(double(10)/180*M_PI), 0, 0,
								   sin(double(10)/180*M_PI),  cos(double(10)/180*M_PI), 0, 0,
									0,				   0,				  1, 0,
									0,				   0,				  0, 1 };
		Matrix* M = new Matrix(4, 4, matrixArray);
		Matrix* newMatrix = *matrixOfPoints * *M;
		fillPointsWithMatrix(newMatrix);
		delete M;
		break;
	}
	default:
		std::cout << "Wrong rotation axis!";
	}

	moveFromCenterCoords();
	createMatrixOfPoints();
	findCenter();
}

void Pyramid::increaseScale()
{
	moveToCenterCoords();

	point1.x *= 1.1;
	point1.y *= 1.1;
	point1.z *= 1.1;
			
	point2.x *= 1.1;
	point2.y *= 1.1;
	point2.z *= 1.1;
			
	point3.x *= 1.1;
	point3.y *= 1.1;
	point3.z *= 1.1;
				
	point4.x *= 1.1;
	point4.y *= 1.1;
	point4.z *= 1.1;
				
	point5.x *= 1.1;
	point5.y *= 1.1;
	point5.z *= 1.1;

	moveFromCenterCoords();
	findCenter();
	createMatrixOfPoints();
}

void Pyramid::decreaseScale()
{
	moveToCenterCoords();

	point1.x *= 0.9;
	point1.y *= 0.9;
	point1.z *= 0.9;
			
	point2.x *= 0.9;
	point2.y *= 0.9;
	point2.z *= 0.9;
				
	point3.x *= 0.9;
	point3.y *= 0.9;
	point3.z *= 0.9;
				
	point4.x *= 0.9;
	point4.y *= 0.9;
	point4.z *= 0.9;
				
	point5.x *= 0.9;
	point5.y *= 0.9;
	point5.z *= 0.9;

	moveFromCenterCoords();
	findCenter();
	createMatrixOfPoints();
}

void Pyramid::moveAlongAxis(char axis)
{
	switch (axis) {
	case 'x':
		point1.increaseX(10);
		point2.increaseX(10);
		point3.increaseX(10);
		point4.increaseX(10);
		point5.increaseX(10);
		break;			
	case 'y':			
		point1.increaseY(10);
		point2.increaseY(10);
		point3.increaseY(10);
		point4.increaseY(10);
		point5.increaseY(10);
		break;			
	case 'z':			
		point1.increaseZ(10);
		point2.increaseZ(10);
		point3.increaseZ(10);
		point4.increaseZ(10);
		point5.increaseZ(10);
		break;
	default:
		std::cout << "Wrong axis to move!";
	}

	findCenter();
	createMatrixOfPoints();
}

void Pyramid::moveReverseAxis(char axis)
{
	switch (axis) {
	case 'x':
		point1.decreaseX(10);
		point2.decreaseX(10);
		point3.decreaseX(10);
		point4.decreaseX(10);
		point5.decreaseX(10);
		break;			
	case 'y':			
		point1.decreaseY(10);
		point2.decreaseY(10);
		point3.decreaseY(10);
		point4.decreaseY(10);
		point5.decreaseY(10);
		break;			
	case 'z':			
		point1.decreaseZ(10);
		point2.decreaseZ(10);
		point3.decreaseZ(10);
		point4.decreaseZ(10);
		point5.decreaseZ(10);
		break;
	default:
		std::cout << "Wrong axis to move!";
	}

	findCenter();
	createMatrixOfPoints();
}

void Pyramid::fillPointsWithMatrix(Matrix* matrix)
{
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

Matrix* Pyramid::createMatrixOfPoints()
{
	if (matrixOfPoints != nullptr)
		delete matrixOfPoints;

	double matrixArray[20] = { point1.x, point1.y, point1.z, 1,
							   point2.x, point2.y, point2.z, 1,
							   point3.x, point3.y, point3.z, 1,
							   point4.x, point4.y, point4.z, 1,
							   point5.x, point5.y, point5.z, 1, };

	matrixOfPoints = new Matrix(5, 4, matrixArray);

	return matrixOfPoints;
}

Pyramid* Pyramid::createPyramidWithIsometricalProjection()
{
	Pyramid* newPyramid = new Pyramid(*this);

	newPyramid->findCenter();

	newPyramid->moveToCenterCoords();
	newPyramid->createMatrixOfPoints();

	double theta = (double)45 / 180 * M_PI;
	double fi = (double)45 / 180 * M_PI;

	double matrixArray[16] = { cos(theta),  sin(theta) * sin(fi), -sin(theta) * cos(fi), 0,
										0,	 	  		 cos(fi),		        sin(fi), 0,
							   sin(theta), -cos(theta) * sin(fi),  cos(theta) * cos(fi), 0,
										0,					   0,					  0, 1 };

	Matrix* M = new Matrix(4, 4, matrixArray);
	Matrix* newMatrix = *matrixOfPoints * *M;
	newPyramid->fillPointsWithMatrix(newMatrix);
	delete M;

	newPyramid->moveFromCenterCoords();
	newPyramid->createMatrixOfPoints();
	newPyramid->findCenter();

	return newPyramid;
}

void Pyramid::renderPyramid()
{
	clearviewport();

	setcolor(15);

	outtextxy(point1.x+10, point1.y-10, const_cast<char*>("A"));
	outtextxy(point2.x-10, point2.y-10, const_cast<char*>("B"));
	outtextxy(point3.x, point3.y, const_cast<char*>("C"));
	outtextxy(point4.x, point4.y, const_cast<char*>("D"));
	outtextxy(point5.x+10, point5.y-10, const_cast<char*>("E"));

	setcolor(10);
	setlinestyle(0,0, 3);
	line(point1.x, point1.y, point2.x, point2.y);
	line(point1.x, point1.y, point3.x, point3.y);
	line(point1.x, point1.y, point4.x, point4.y);
	line(point1.x, point1.y, point5.x, point5.y);
	line(point2.x, point2.y, point3.x, point3.y);
	line(point3.x, point3.y, point4.x, point4.y);
	line(point4.x, point4.y, point5.x, point5.y);
	line(point5.x, point5.y, point2.x, point2.y);
}

Pyramid::Pyramid() : matrixOfPoints(nullptr), centerPoint{ 0, 0, 0 }
{
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

Pyramid::Pyramid(const Pyramid& p2)
{
	point1 = p2.point1;
	point2 = p2.point2;
	point3 = p2.point3;
	point4 = p2.point4;
	point5 = p2.point5;

	centerPoint = p2.centerPoint;

	matrixOfPoints = new Matrix(p2.matrixOfPoints->sizeRows, p2.matrixOfPoints->sizeColumns, p2.matrixOfPoints->matrix);
}

Pyramid::~Pyramid()
{
	delete(matrixOfPoints);
}

void Pyramid::findCenter()
{
	centerPoint.x = (point1.x + point2.x + point3.x + point4.x + point5.x) / 5;
	centerPoint.y = (point1.y + point2.y + point3.y + point4.y + point5.y) / 5;
	centerPoint.z = (point1.z + point2.z + point3.z + point4.z + point5.z) / 5;
}

void Pyramid::moveToCenterCoords()
{
	point1.decPoints(centerPoint);
	point2.decPoints(centerPoint);
	point3.decPoints(centerPoint);
	point4.decPoints(centerPoint);
	point5.decPoints(centerPoint);
}

void Pyramid::moveFromCenterCoords()
{
	point1.sumPoints(centerPoint);
	point2.sumPoints(centerPoint);
	point3.sumPoints(centerPoint);
	point4.sumPoints(centerPoint);
	point5.sumPoints(centerPoint);
}

int main()
{
	using std::cout;
	using std::endl;

	setlocale(LC_ALL, "RUS");
	initwindow(1000, 500, "Square", 1921 - 999, 0);

	Pyramid pyr;
	Pyramid* isPyr;

	while (1)
	{
		isPyr = pyr.createPyramidWithIsometricalProjection();
		isPyr->renderPyramid();
		delete(isPyr);

		system("cls");
		cout << "\tУправление:" << endl << "a - переместить пирамиду против оси X на 10 единиц" << endl << "d - переместить пирамиду по оси X на 10 единиц" << endl
			<< "w - переместить пирамиду против оси Y на 10 единиц" << endl << "s - переместить пирамиду по оси Y на 10 единиц" << endl
			<< "q - переместить пирамиду по оси Z на 10 единиц" << endl << "e - переместить пирамиду против оси Z на 10 единиц" << endl
			<< "z - уменьшить пирамиду на 10%" << endl << "x - увеличить пирамиду на 10%" << endl
			<< "r - повернуть пирамиду по часовой стрелке вдоль оси X" << endl << "t - повернуть пирамиду против часовой стрелки вдоль оси X" << endl
			<< "f - повернуть пирамиду по часовой стрелке вдоль оси Y" << endl << "g - повернуть пирамиду против часовой стрелки вдоль оси Y" << endl
			<< "v - повернуть пирамиду по часовой стрелке вдоль оси Z" << endl << "b - повернуть пирамиду против часовой стрелки вдоль оси Z";
		cout << endl << "0 - выйти\n\n";

		char c = getch();

		switch (c)
		{
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
			break;
		case 'q':
			pyr.moveAlongAxis('z');
			break;
		case 'x':
			pyr.increaseScale();
			break;
		case 'z':
			pyr.decreaseScale();
			break;
		case 't':
			pyr.rotateCounterClockwise('x');
			break;
		case 'r':
			pyr.rotateClockwise('x');
			break;
		case 'g':
			pyr.rotateCounterClockwise('y');
			break;
		case 'f':
			pyr.rotateClockwise('y');
			break;
		case 'v':
			pyr.rotateClockwise('z');
			break;
		case 'b':
			pyr.rotateCounterClockwise('z');
			break;
		case '0':
			return 0;
		default:
			system("cls");
			cout << endl << "Неверный ввод!" << endl;
			system("pause");
		}

	}

	return 0;

}