#include "objectBoard.h"


#include "config.h"

Board::Board(const Point& rhs1, const Point& rhs2)
	:GameObject(rhs1, rhs2)
{
};

Board::Board(int rhs)
	:GameObject(Point(rhs,BOARD_POSITION_Y), Point(BOARD_WIDTH,1))
{
};

