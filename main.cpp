#include <iostream>
#include <string>
#include "point.h"
#include "objects.h"
#include "draw.h"
#include "user_input.h"

using namespace std;


void button(const Objects& Board, const Objects& Man, const int& FIELD_HEIGHT, const int& FIELD_WIDTH)
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
		
		draw(Board, Man, FIELD_HEIGHT, FIELD_WIDTH);
		print(s);
	}
}

int main()
{
	const int SIZE_SCALE = 2;
	const int BOARD_WIDTH = 8;
	const int FIELD_HEIGHT = 7 * SIZE_SCALE;
	const int FIELD_WIDTH = 2 * BOARD_WIDTH * SIZE_SCALE;
	const int BOARD_POSITION_Y = FIELD_HEIGHT;
	
	Objects Board(Point(3,BOARD_POSITION_Y), Point(BOARD_WIDTH,1));
	Board.simbl = '=';
	Objects Man(Point(3,1), Point(2,2));
	//Man.simbl = '*';
	
	draw(Board, Man, FIELD_HEIGHT, FIELD_WIDTH);
	button(Board, Man, FIELD_HEIGHT, FIELD_WIDTH);
	return 0;
}
