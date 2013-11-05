#ifndef OBJECTS_H
#define OBJECTS_H
#include "point.h"

class Objects
{
public:
	char simbl = '*';
	Objects(const Point&, const Point&);
	Point position_;
	Point size_;
protected:


};

#endif
