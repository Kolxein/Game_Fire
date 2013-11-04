#ifndef OBJECTS_H
#define OBJECTS_H
#include "point.h"

class Objects
{
public:
	char simbl = '*';
	Objects(int a, int b, int c, int d);
	int GetX() const {return itsX;};
	int GetY() const {return itsY;};
	int GetHeight() const {return itsHeight;};
	int GetWidth() const {return itsWidth;};
	void SetX(int x) {itsX = x;};
	void SetY(int y) {itsY = y;};
	void SetHeight(int height) {itsHeight = height;};
	void SetWidth(int width) {itsWidth = width;};
	
protected:
	int itsX;
	int itsY;
	int itsHeight;
	int itsWidth;
	Point position();
};

#endif
