#include "man.h"

using namespace std;
#include <iostream>

#include <math.h>
#include "config.h"

Man::Man(const Point& rhs1, const Size& rhs2)
	:GameObject(rhs1, rhs2)
{
}

Man::Man()
	:GameObject(Point(0, 0),Size(1, 1))
{
}

void Man::move()
{
	if (position_.x == 0)
	{
		position_.x++;
		return;
	}
	
	if (0 * SIZE_SCALE < position_.x && position_.x <= 4 * SIZE_SCALE)
	{
		position_.y++;
		position_.x++;
		return;
	}

	if (4 * SIZE_SCALE < position_.x && position_.x < 9 * SIZE_SCALE)
	{
		position_.y--;
		position_.x++;
		return;
	}
	if (9 * SIZE_SCALE <= position_.x && position_.x <= 12 * SIZE_SCALE)
	{
		position_.y++;
		position_.x++;
		return;
	}

	if (12 * SIZE_SCALE < position_.x && position_.x < 16 * SIZE_SCALE)
	{
		position_.y--;
		position_.x++;
		return;
	}
	if (16 * SIZE_SCALE <= position_.x && position_.x <= 18 * SIZE_SCALE)
	{
		position_.y++;
		position_.x++;
		return;
	}

	if (18 * SIZE_SCALE < position_.x && position_.x < 21 * SIZE_SCALE)
	{
		position_.y--;
		position_.x++;
		return;
	}
	if (21 * SIZE_SCALE <= position_.x && position_.x < 23 * SIZE_SCALE)
	{
		position_.y++;
		position_.x++;
		return;
	}
}

void Man::moveDed()
{
	position_.y = position_.y + 2;
}

