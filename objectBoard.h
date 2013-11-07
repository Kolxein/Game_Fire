#ifndef OBJECT_BOARD_H
#define OBJECT_BOARD_H

#include "gameObject.h"
#include "point.h"
#include "size.h"



class Board : public GameObject
{
	public:
		Board(const Point&, const Size&);
		Board(int);
		char simbl = '=';
};

#endif
