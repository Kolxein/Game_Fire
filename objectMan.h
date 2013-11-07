#ifndef OBJECT_MAN_H
#define OBJECT_MAN_H

#include "gameObject.h"
#include "point.h"
#include "size.h"


class Man : public GameObject
{
	public:
		Man(const Point&, const Size&);
		char simbl = '*';
};

#endif
