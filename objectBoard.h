#ifndef OBJECT_BOARD_H
#define OBJECT_BOARD_H

#include "gameObject.h"
#include "point.h"



class Board : public GameObject
{
	public:
		Board(const Point&, const Point&);
		Board(int);
		char simbl = '=';
};

#endif
