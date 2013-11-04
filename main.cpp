#include <iostream>
#include <string>
#include "point.h"
#include "objects.h"
#include "draw.h"
#include "user_input.h"

using namespace std;



void button(const Objects& board, const Objects& Man)
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
		
		draw(board, Man);
		print(s);
	}
}

int main()
{
	Objects board(3,11,1,4);
	Objects Man(3,4,1,1);
	//int board = 2;
	Point oboard(board.GetX(), board.GetY());
	//Point positionMan(Man.GetX(), Man.GetY());
	//Point sizeMan(Man.GetWidth(), Man.GetHeight());
	
	draw(board, Man);
	button(board, Man);
	
	return 0;
}
