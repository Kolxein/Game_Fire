#include "board.h"


#include "config.h"


Board::Board(int rhs)
	:GameObject(Point(rhs,BOARD_POSITION_Y), Size(BOARD_WIDTH,1))
{
};

