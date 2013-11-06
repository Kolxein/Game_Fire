#ifndef OBJECTS_H
#define OBJECTS_H
#include "point.h"

class Objects
{
public:
	char simbl = '*';
	Objects(const Point&, const Point&);
	Point GetPosition() const {return position_;}
	Point GetSize() const {return size_;}
	void SetPosition(int x, int y) {position_.x = x, position_.y = y;}
	void SetSize(int x, int y) {size_.x = x, size_.y = y;}
private:
	Point position_;
	Point size_;

};

#endif
