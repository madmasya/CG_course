#include "QueueOfPyramidSurfaces.h"

QueueOfPyramidSurfaces::QueueOfPyramidSurfaces(Pyramid& par) {

	arr = new PyramidSurface * [5];

	arr[0] = new PyramidSurface(par.point2, par.point3, par.point4, par.point5);
	arr[1] = new PyramidSurface(par.point2, par.point3, par.point1, par.point1);
	arr[2] = new PyramidSurface(par.point3, par.point4, par.point1, par.point1);
	arr[3] = new PyramidSurface(par.point4, par.point5, par.point1, par.point1);
	arr[4] = new PyramidSurface(par.point5, par.point2, par.point1, par.point1);

	sortSurfacesByZcoord();
}

QueueOfPyramidSurfaces::~QueueOfPyramidSurfaces() {

	for (int i = 0; i < 5; i++)
		delete arr[i];

	delete arr;
}

void QueueOfPyramidSurfaces::sortSurfacesByZcoord() {

	PyramidSurface* ptrSurface;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (arr[j]->centerZvalue < arr[j + 1]->centerZvalue) {
				ptrSurface = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = ptrSurface;
			}
}