#include "Point.h"
#define ROTATE_VALUE double(45) / 180 * M_PI

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}
Point::Point() : x(NULL), y(NULL), z(NULL) {}

void Point::iso()
{
	double arr[4] = { x, y, z , 1 };
	double theta = (double)45 / 180 * M_PI;
	double fi = (double)45 / 180 * M_PI;
	double isoArr[16] = { cos(theta),  sin(theta) * sin(fi), -sin(theta) * cos(fi), 0,
								0,	             cos(fi),		        sin(fi), 0,
					   sin(theta), -cos(theta) * sin(fi),  cos(theta) * cos(fi), 0,
								0,					   0,					  0, 1 };
	double newPoints[4] = { arr[0] * isoArr[0] + arr[1] * isoArr[4] + arr[2] * isoArr[8] + arr[3] * isoArr[12],
						arr[0] * isoArr[1] + arr[1] * isoArr[5] + arr[2] * isoArr[9] + arr[3] * isoArr[13],
						arr[0] * isoArr[2] + arr[1] * isoArr[6] + arr[2] * isoArr[10] + arr[3] * isoArr[14],
						arr[0] * isoArr[3] + arr[1] * isoArr[7] + arr[2] * isoArr[11] + arr[3] * isoArr[15] };
	x = newPoints[0];
	y = newPoints[1];
	z = newPoints[2];
}

void Point::operator+ (Point& p2) {
	this->x += p2.x;
	this->y += p2.y;
	this->z += p2.z;
}

void Point::operator- (Point& p2) {
	this->x -= p2.x;
	this->y -= p2.y;
	this->z -= p2.z;
}

void Point::move(char axis, bool direction)
{
	switch (axis)
	{
	case 'x':
	{
		if (direction)
			this->x += 10;
		else this->x -= 10;
		break;
	}
	case 'y':
	{
		if (direction)
			this->y += 10;
		else this->y -= 10;
		break;
	}
	case 'z':
	{
		if (direction)
			this->z += 10;
		else this->z -= 10;
		break;
	}
	}
}

void Point::scale(bool direction)
{
	if (direction)
	{
		this->x *= 1.1;
		this->y *= 1.1;
		this->z *= 1.1;
	}
	else
	{
		this->x *= 0.9;
		this->y *= 0.9;
		this->z *= 0.9;
	}
}

void Point::rotate(char axis, bool direction)
{
	double arr[4] = { x, y, z , 1 };
	switch (axis)
	{
	case 'x':
	{
		if (direction)
		{
			double rotateArr[16] = { 1,				     0,                 0, 0,
									 0,  cos(ROTATE_VALUE), sin(ROTATE_VALUE), 0,
									 0, -sin(ROTATE_VALUE), cos(ROTATE_VALUE), 0,
									 0,				     0,                 0, 1 };
			double newPoints[4] = { arr[0] * rotateArr[0] + arr[1] * rotateArr[4] + arr[2] * rotateArr[8] + arr[3] * rotateArr[12],
						arr[0] * rotateArr[1] + arr[1] * rotateArr[5] + arr[2] * rotateArr[9] + arr[3] * rotateArr[13],
						arr[0] * rotateArr[2] + arr[1] * rotateArr[6] + arr[2] * rotateArr[10] + arr[3] * rotateArr[14],
						arr[0] * rotateArr[3] + arr[1] * rotateArr[7] + arr[2] * rotateArr[11] + arr[3] * rotateArr[15] };
			x = newPoints[0];
			y = newPoints[1];
			z = newPoints[2];
		}
		else
		{
			double rotateArr[16] = { 1,   0,                 0,                0,
								   0, cos(ROTATE_VALUE), -sin(ROTATE_VALUE), 0,
								   0, sin(ROTATE_VALUE),  cos(ROTATE_VALUE), 0,
								   0,   0,                 0,                1 };
			double newPoints[4] = { arr[0] * rotateArr[0] + arr[1] * rotateArr[4] + arr[2] * rotateArr[8] + arr[3] * rotateArr[12],
						arr[0] * rotateArr[1] + arr[1] * rotateArr[5] + arr[2] * rotateArr[9] + arr[3] * rotateArr[13],
						arr[0] * rotateArr[2] + arr[1] * rotateArr[6] + arr[2] * rotateArr[10] + arr[3] * rotateArr[14],
						arr[0] * rotateArr[3] + arr[1] * rotateArr[7] + arr[2] * rotateArr[11] + arr[3] * rotateArr[15] };
			x = newPoints[0];
			y = newPoints[1];
			z = newPoints[2];
		}
		break;
	}
	case 'y':
	{
		if (direction)
		{
			double rotateArr[16] = { cos(ROTATE_VALUE), 0, sin(ROTATE_VALUE), 0,
						0,				  1,  0,				0,
					  -sin(ROTATE_VALUE), 0, cos(ROTATE_VALUE), 0,
						0,				  0,  0,                1 };
			double newPoints[4] = { arr[0] * rotateArr[0] + arr[1] * rotateArr[4] + arr[2] * rotateArr[8] + arr[3] * rotateArr[12],
						arr[0] * rotateArr[1] + arr[1] * rotateArr[5] + arr[2] * rotateArr[9] + arr[3] * rotateArr[13],
						arr[0] * rotateArr[2] + arr[1] * rotateArr[6] + arr[2] * rotateArr[10] + arr[3] * rotateArr[14],
						arr[0] * rotateArr[3] + arr[1] * rotateArr[7] + arr[2] * rotateArr[11] + arr[3] * rotateArr[15] };
			x = newPoints[0];
			y = newPoints[1];
			z = newPoints[2];
		}
		else
		{
			double rotateArr[16] = { cos(ROTATE_VALUE), 0, -sin(ROTATE_VALUE), 0,
									0,				  1,  0,				 0,
								   sin(ROTATE_VALUE), 0,  cos(ROTATE_VALUE), 0,
									0,				  0,  0,                 1 };
			double newPoints[4] = { arr[0] * rotateArr[0] + arr[1] * rotateArr[4] + arr[2] * rotateArr[8] + arr[3] * rotateArr[12],
						arr[0] * rotateArr[1] + arr[1] * rotateArr[5] + arr[2] * rotateArr[9] + arr[3] * rotateArr[13],
						arr[0] * rotateArr[2] + arr[1] * rotateArr[6] + arr[2] * rotateArr[10] + arr[3] * rotateArr[14],
						arr[0] * rotateArr[3] + arr[1] * rotateArr[7] + arr[2] * rotateArr[11] + arr[3] * rotateArr[15] };
			x = newPoints[0];
			y = newPoints[1];
			z = newPoints[2];
		}
		break;
	}
	case 'z':
	{
		if (direction)
		{
			double rotateArr[16] = { cos(ROTATE_VALUE), sin(ROTATE_VALUE), 0, 0,
								  -sin(ROTATE_VALUE), cos(ROTATE_VALUE), 0,	0,
									0,				   0,				 1, 0,
									0,				   0,				 0, 1 };
			double newPoints[4] = { arr[0] * rotateArr[0] + arr[1] * rotateArr[4] + arr[2] * rotateArr[8] + arr[3] * rotateArr[12],
						arr[0] * rotateArr[1] + arr[1] * rotateArr[5] + arr[2] * rotateArr[9] + arr[3] * rotateArr[13],
						arr[0] * rotateArr[2] + arr[1] * rotateArr[6] + arr[2] * rotateArr[10] + arr[3] * rotateArr[14],
						arr[0] * rotateArr[3] + arr[1] * rotateArr[7] + arr[2] * rotateArr[11] + arr[3] * rotateArr[15] };
			x = newPoints[0];
			y = newPoints[1];
			z = newPoints[2];
		}
		else
		{
			double rotateArr[16] = { cos(ROTATE_VALUE), -sin(ROTATE_VALUE), 0, 0,
								   sin(ROTATE_VALUE),  cos(ROTATE_VALUE), 0, 0,
									0,				   0,				  1, 0,
									0,				   0,				  0, 1 };
			double newPoints[4] = { arr[0] * rotateArr[0] + arr[1] * rotateArr[4] + arr[2] * rotateArr[8] + arr[3] * rotateArr[12],
						arr[0] * rotateArr[1] + arr[1] * rotateArr[5] + arr[2] * rotateArr[9] + arr[3] * rotateArr[13],
						arr[0] * rotateArr[2] + arr[1] * rotateArr[6] + arr[2] * rotateArr[10] + arr[3] * rotateArr[14],
						arr[0] * rotateArr[3] + arr[1] * rotateArr[7] + arr[2] * rotateArr[11] + arr[3] * rotateArr[15] };
			x = newPoints[0];
			y = newPoints[1];
			z = newPoints[2];
		}
		break;
	}
	}

}