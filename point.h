#ifndef POINT_H
#define POINT_H
#include "objects.h"


class Point
{
public:
	Point(int a, int b);
	bool operator==(const Point& rhs)const;
	int x;
	int y;
};

#endif
