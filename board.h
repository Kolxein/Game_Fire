#ifndef BOARD_H
#define BOARD_H

#include "gameObject.h"
#include "point.h"
#include "size.h"


class Board : public GameObject
{
	public:
		Board(int);
		char simbl = '=';
		void moveRight();
		void moveLeft();
};

#endif
