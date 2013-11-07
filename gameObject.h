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

Man::Man(const Point& rhs1, const Point& rhs2)
	:GameObject(rhs1, rhs2)
{
};

class Board : public GameObject
{
	public:
		Board(const Point&, const Point&);
		Board(int);
		char simbl = '=';
};

Board::Board(const Point& rhs1, const Point& rhs2)
	:GameObject(rhs1, rhs2)
{
};

/*Board::Board(int rhs)
	:GameObject(Point(rhs,BOARD_POSITION_Y), Point(BOARD_WIDTH,1))
{
};
*/
#endif
