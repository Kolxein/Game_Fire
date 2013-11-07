#ifndef OBJECT_MAN_H
#define OBJECT_MAN_H

#include "gameObject.h"
#include "point.h"


class Man : public GameObject
{
	public:
		Man(const Point&, const Point&);
		char simbl = '*';
};

#endif
