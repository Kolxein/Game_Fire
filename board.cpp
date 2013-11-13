#include "board.h"

#include "config.h"

Board::Board(int rhs)
	:GameObject(Point(rhs,BOARD_POSITION_Y), Size(BOARD_WIDTH,1))
{
};

void moveRight()
{
	if (position_.x + size_.width * 2 >= FIELD_WIDTH)
	{
		position_.x = FIELD_WIDTH - size_.width;
	}
	else if (position_.x + size_.width * 2 < FIELD_WIDTH)
	{
		position_.x = position_.x + size_.width;
	}

};

void moveLeft()
{
	if (position_.x - size_.width <= 0)
	{
		position_.x = 0;
	}
	else if (position_.x > 0)
	{
		position_.x = position_.x - size_.width;
	}
};
