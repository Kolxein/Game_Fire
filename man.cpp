#include "man.h"

#include "config.h"

Man::Man(const Point& rhs1, const Size& rhs2)
	:GameObject(rhs1, rhs2)
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
/*
void moveLeft(GameObject& rhs)
{
	if (rhs.GetPosition().x - rhs.GetSize().width <= 0)
	{
		rhs.SetPosition(0, rhs.GetPosition().y);
	}
	else if (rhs.GetPosition().x > 0)
	{
		rhs.SetPosition(rhs.GetPosition().x - rhs.GetSize().width, rhs.GetPosition().y);
	}
};

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
