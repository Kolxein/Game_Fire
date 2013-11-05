#include <iostream>
#include <string>
#include "point.h"
#include "objects.h"
#include "draw.h"
#include "user_input.h"

using namespace std;


void button(const Objects& Board, const Objects& Man)
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
		
		draw(Board, Man);
		print(s);
	}
}

int main()
{
	Objects Board(Point(3,11), Point(1,4));
	Objects Man(Point(3,1), Point(1,1));
	
	draw(Board, Man);
	button(Board, Man);
	
	return 0;
}
