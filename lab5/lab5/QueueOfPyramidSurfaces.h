#pragma once

#include "PyramidSurface.h"
#include "Pyramid.h"

class QueueOfPyramidSurfaces {
public:
	QueueOfPyramidSurfaces(Pyramid& par);
	~QueueOfPyramidSurfaces();
	void sortSurfacesByZcoord();
	friend class Pyramid;
private:
	PyramidSurface** arr;
};