#ifndef OBJECTS_H
#define OBJECTS_H

#include "point.h"
#include "size.h"



class GameObject
{
public:
	GameObject(const Point&, const Size&);
	Point GetPosition() const {return position_;}
	Size GetSize() const {return size_;}
	void SetPosition(int x) {position_.x = x;}
protected:
	Point position_;
	Size size_;

};

#endif
