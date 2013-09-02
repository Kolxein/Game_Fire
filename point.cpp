#include "point.h"


Point::Point(int a, int b)
	: x(a)
	, y(b)
{
}

bool Point::operator==(const Point& rhs)
{
	return x == rhs.x && y == rhs.y;
}
