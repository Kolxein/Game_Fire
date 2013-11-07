#include "size.h"

Size::Size(int w, int h)
	: width(w)
	, height(h)
{
}

bool Size::operator==(const Size& rhs)const
{
	return (width == rhs.width && height == rhs.height);
}
