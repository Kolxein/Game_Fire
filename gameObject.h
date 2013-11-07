#ifndef OBJECTS_H
#define OBJECTS_H

#include "point.h"


class GameObject
{
public:
	char simbl = '*';
	GameObject(const Point&, const Point&);
	Point GetPosition() const {return position_;}
	Point GetSize() const {return size_;}
protected:
	Point position_;
	Point size_;

};

#endif
