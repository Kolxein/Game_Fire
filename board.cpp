#include "board.h"

#include "config.h"

Board::Board(int rhs)
	:GameObject(Point(rhs,BOARD_POSITION_Y), Size(BOARD_WIDTH,1))
{
}

void Board::moveRight()
{
	if (position_.x * 2 > 23 * SIZE_SCALE)
	{
		position_.x = 18 * SIZE_SCALE;
	}
	else position_.x = 12 * SIZE_SCALE;
}

void Board::moveLeft()
{
	if (position_.x / 2 < 7 * SIZE_SCALE)
	{
		position_.x = 4 * SIZE_SCALE;
	}
	else position_.x = 12 * SIZE_SCALE;
}
