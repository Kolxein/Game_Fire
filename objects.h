#ifndef OBJECTS_H
#define OBJECTS_H
#include "point.h"

class Objects
{
public:
	char simbl = '*';
	Objects(const Point&, const Point&);
	Point GetPosition() const {return position_;}
protected:
	Point position_;
	Point size_;

};

#endif
