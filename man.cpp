#include "man.h"

using namespace std;
#include <iostream>

#include <math.h>
#include "config.h"

Man::Man(const Point& rhs1, const Size& rhs2)
	:GameObject(rhs1, rhs2)
{
}

void Man::move()
{
	int step_1 = 4 * SIZE_SCALE; //volni
	int cosYgla_1 = cos(position_.x * 180 / step_1 * (3.14 / 180) + 10) * 3 * SIZE_SCALE + 3 * SIZE_SCALE;
	int cosYgla_2 = cos(position_.x * 180 / step_1 * (3.14 / 180) + 5) * 2 * SIZE_SCALE + 4 * SIZE_SCALE;
	int cosYgla_3 = cos(position_.x * 180 / step_1 * (3.14 / 180) + 5) * 1 * SIZE_SCALE + 5 * SIZE_SCALE;
	
	
	if (position_.x < 6 * SIZE_SCALE)
	{
		position_.y = cosYgla_1;
	}
	if (position_.x < 11 * SIZE_SCALE && position_.x > 6 * SIZE_SCALE)
	{
		position_.y = cosYgla_2;
	}
	if (position_.x < FIELD_WIDTH && position_.x > 11 * SIZE_SCALE)
	{
		position_.y = cosYgla_3;
	}

	position_.x++;

}

void Man::moveRight()
{
	if ( + size_.width * 2 >= FIELD_WIDTH)
	{
		position_.x = FIELD_WIDTH - size_.width;
	}
	else if (position_.x + size_.width * 2 < FIELD_WIDTH)
	{
		position_.x = position_.x + size_.width;
	}
}

void Man::moveLeft()
{
	if (position_.x - size_.width <= 0)
	{
		position_.x = 0;
	}
	else if (position_.x > 0)
	{
		position_.x = position_.x - size_.width;
	}
}
/*
void moveTop(GameObject& rhs)
{
	if (rhs.GetPosition().y - rhs.GetSize().height <= 0)
	{
		rhs.SetPosition(rhs.GetPosition().x, 0);
	}
	else if (rhs.GetPosition().y > 0)
	{
		rhs.SetPosition(rhs.GetPosition().x, rhs.GetPosition().y - rhs.GetSize().height);
	}
};

void moveDown(GameObject& rhs)
{
	if (rhs.GetPosition().y + (rhs.GetSize().height * 2) >= FIELD_HEIGHT)
	{
		rhs.SetPosition(rhs.GetPosition().x, FIELD_HEIGHT - rhs.GetSize().height);
	}
	else if (rhs.GetPosition().y + (rhs.GetSize().height * 2) < FIELD_HEIGHT)
	{
		rhs.SetPosition(rhs.GetPosition().x, rhs.GetPosition().y + rhs.GetSize().height);
	}
};*/
