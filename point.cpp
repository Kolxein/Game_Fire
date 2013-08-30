#include "point.h"


Point::Point(int a, int b)
	: x(a)
	, y(b)
{
}
bool Point::Point( const Point &rhs ) const
{
 	if (x == rhs.x && y == rhs.y)
	{
	   	 return (true);
	}
	return ( false );
}


/*class Point
{
 public:
    bool f( const Point & ) const;
 //........
 //.........
 private:
    int x[200], y[200], z;
};

bool Point::f( const Point &rhs ) const
{
   if ( x[0] == rhs.y[0] ) return ( true );
   if ( x[199] = rhs.y[199] ) return ( flase );
   if ( x[0] + rhs.x[100] ) > 0 ) return ( true );
   return ( false );
}
*/
