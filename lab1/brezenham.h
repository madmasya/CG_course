#pragma once

void BrezenhamLine(int x1, int y1, int x2, int y2);
void BrezenhamMoveLeft(int& x1, int& y1, int& x2, int& y2);
void BrezenhamMoveRight(int& x1, int& y1, int& x2, int& y2);
void BrezenhamMoveUp(int& x1, int& y1, int& x2, int& y2);
void BrezenhamMoveDown(int& x1, int& y1, int& x2, int& y2);
void BrezenhamScaleUp(int& x1, int& y1, int& x2, int& y2);
void BrezenhamScaleDown(int& x1, int& y1, int& x2, int& y2);
void BrezenhamRotateClockwise(int& x1, int& y1, int& x2, int& y2);
void BrezenhamRotateCounterClockwise(int& x1, int& y1, int& x2, int& y2);