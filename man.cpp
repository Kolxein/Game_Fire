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
	if (position_.x <= 3 * SIZE_SCALE)
	{
		position_.y++;
		position_.x++;
		return;
	}

	if (3 * SIZE_SCALE < position_.x && position_.x < 8 * SIZE_SCALE)
	{
		position_.y--;
		position_.x++;
		return;
	}
	if (8 * SIZE_SCALE <= position_.x && position_.x <= 11 * SIZE_SCALE)
	{
		position_.y++;
		position_.x++;
		return;
	}

	if (11 * SIZE_SCALE < position_.x && position_.x < 15 * SIZE_SCALE)
	{
		position_.y--;
		position_.x++;
		return;
	}
	if (15 * SIZE_SCALE <= position_.x && position_.x <= 17 * SIZE_SCALE)
	{
		position_.y++;
		position_.x++;
		return;
	}

	if (17 * SIZE_SCALE < position_.x && position_.x < 20 * SIZE_SCALE)
	{
		position_.y--;
		position_.x++;
		return;
	}
	if (20 * SIZE_SCALE <= position_.x && position_.x < 21 * SIZE_SCALE)
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

