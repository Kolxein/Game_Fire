#ifndef BOARD_H
#define BOARD_H

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
