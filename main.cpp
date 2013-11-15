
#include <iostream>
#include <string>

#include "config.h"
#include "point.h"
#include "size.h"
#include "gameObject.h"
#include "board.h"
#include "man.h"
#include "draw.h"
#include "user_input.h"



using namespace std;



void button(Board& board, Man& man)
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
			board.moveRight();
			s = "right";
			break;
		case Key::LEFT:						//left
			s = "left";
			board.moveLeft();
			break;
		case Key::OTHER:					//all key
			s = "other key";
			man.move();
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

	
	Board board(0);
	Man man(Point(0,0), Size(1,1));
	
	draw(board, man);
	button(board, man);
	return 0;
}
