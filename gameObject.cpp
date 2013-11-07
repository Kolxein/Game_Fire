#include "gameObject.h"
#include "point.h"
#include "draw.h"


GameObject::GameObject(const Point& position, const Point& size)
		: position_(position)
		, size_(size)
{
};
