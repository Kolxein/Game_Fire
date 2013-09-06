#include <iostream>
#include <string>
#include "point.h"
#include "draw.h"
#include "user_input.h"

using namespace std;

class Man
{
public:
	char simbl = '*';
	Man(int a, int b, int c, int d);
	int SetCoord();
	int SetSize();
private:
	int x;
	int y;
	int height;
	int width;
	
};
Man::Man(int a, int b, int c, int d)
	: x(a)
	, y(b)
	, height(c)
	, width(d)
{
}
int Man::SetCoord()
{
	return Man(const int& x,const int& y);
}
int Man::SetSize()
{
	return Man(const int& height,const int& width);
}



void button(const int board, const Point& man)
{
	for (;;)
	{
		string s = "ok";
		switch (wait_for_input())
		{
		case Key::EXIT:
			s = "Exit";
			return;
		case Key::RIGHT:					//right
			s = "right";
			break;
		case Key::LEFT:						//left
			s = "left";
			break;
		case Key::OTHER:					//all key
			s = "other key";
			break;
		default:
			s = "Eror";
			break;
		}
		
		draw(board, man);
		print(s);
	}
}

int main()
{
	int board = 2;
	Point man(3,8);
	
	draw(board, man);
	button(board, man);
	
	return 0;
}
