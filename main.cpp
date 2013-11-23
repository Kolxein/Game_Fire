
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

int kill = 0;
int ekspa = 0;


using namespace std;

int collizia(Board& board, Man& man)
{
	if (man.GetPosition().x == 4 && board.GetPosition().x != 0 
		|| man.GetPosition().x == 12 && board.GetPosition().x != BOARD_WIDTH 
		|| man.GetPosition().x == 18 && board.GetPosition().x != BOARD_WIDTH * 2)
	{
		man.moveDed();
		kill++;
		draw(board, man, kill, ekspa);
		man.SetPosition(0,0);
	}
	else 
	{
		man.move();
		if (man.GetPosition().x == FIELD_WIDTH - 1)
		{
			ekspa++;
			man.SetPosition(0,0);
		}
	}
}

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
			collizia(board,man);
			break;
		default:
			s = "Eror";
			break;
		}
		
		draw(board, man, kill, ekspa);
		print(s);
	}
}

int main()
{
	Board board(0);
	Man man(Point(0,0), Size(1,1));
	
	draw(board, man, kill, ekspa);
	button(board, man);
	return 0;
}
