#include "gameObject.h"
#include "point.h"
#include "draw.h"


GameObject::GameObject(const Point& position, const Point& size)
		: position_(position)
		, size_(size)
{
};


Man::Man(const Point& rhs1, const Point& rhs2)
	:GameObject(rhs1, rhs2)
{
};


Board::Board(const Point& rhs1, const Point& rhs2)
	:GameObject(rhs1, rhs2)
{
};

Board::Board(int rhs)
	:GameObject(Point(rhs,BOARD_POSITION_Y), Point(BOARD_WIDTH,1))
{
};

