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
	int step = 10;  //volni
	int cosYgla = cos(position_.x * 180 / step * (3.14 / 180) - 160) * 3 * SIZE_SCALE + 3 * SIZE_SCALE;
	position_.y = cosYgla;
	position_.x++;
/*	if (cosYgla < FIELD_HEIGHT / 2)
	{
		if (position_.y != cosYgla)
		{
			position_.y++;
		}
		else 
		{
			position_.y++;
			position_.x++;
		}
	}
	if (cosYgla > FIELD_HEIGHT / 2)
	{
		if (position_.y != cosYgla)
		{
			position_.y--;
		}
		else 
		{
			position_.y--;
			position_.x++;
		}
	}
*/


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
