#include <iostream>
#include <string>
#include "point.h"
#include "draw.h"
#include "user_input.h"

using namespace std;

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
		case Key::LEFT:					//left
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
