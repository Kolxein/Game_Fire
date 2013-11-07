#ifndef OBJECTS_H
#define OBJECTS_H
#include "point.h"
#include "config.h"

class GameObject
{
public:
	char simbl = '*';
	GameObject(const Point&, const Point&);
	Point GetPosition() const {return position_;}
	Point GetSize() const {return size_;}
protected:
	Point position_;
	Point size_;

};

class Man : public GameObject
{
	public:
		Man(const Point&, const Point&);
		char simbl = '*';
};

class Board : public GameObject
{
	public:
		Board(const Point&, const Point&);
		Board(int);
		char simbl = '=';
};

#endif
