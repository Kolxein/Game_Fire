#include <iostream>
#include <string>
#include "point.h"
#include "gameObject.h"
#include "draw.h"
#include "user_input.h"
#include "config.h"

using namespace std;


void button(const GameObject& board, const GameObject& man)
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

	
	//GameObject board(Point(3,BOARD_POSITION_Y), Point(BOARD_WIDTH,1));
	//Board board(Point(3,BOARD_POSITION_Y), Point(BOARD_WIDTH,1));
	Board board(3);
	//board.simbl = '=';
	//GameObject man(Point(3,1), Point(2,2));
	Man man(Point(3,1), Point(2,1));
	
	draw(board, man);
	button(board, man);
	return 0;
}
