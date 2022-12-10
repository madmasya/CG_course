
#include "Definitions.h"
#include "ArrrayOfPoints.h"
#include "PyramidSurface.h"

void drawBresenhamLine(int x1, int y1, int x2, int y2, ArrayOfPoints* arr);
void fillPyramid(PyramidSurface* surface, ArrayOfPoints* arr, int color);
void recursiveFilling(ArrayOfPoints* arr, int x, int y, int color);