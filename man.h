#ifndef MAN_H
#define MAN_H

#include "gameObject.h"
#include "point.h"
#include "size.h"


class Man : public GameObject
{
	public:
		Man(const Point&, const Size&);
		char simbl = '*';
		void moveRight();
		void moveLeft();
		
};

#endif
