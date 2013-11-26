
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

int collizia(Board& board, Man& mens[], int number_of_elements)
{
	if (mens[1].GetPosition().x == 4 && board.GetPosition().x != 0
		|| mens[1].GetPosition().x == 12 && board.GetPosition().x != BOARD_WIDTH 
		|| mens[1].GetPosition().x == 18 && board.GetPosition().x != BOARD_WIDTH * 2)
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

void button(Board& board, Man& mens[], int number_of_elements)
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
			collizia(board, mens[], 3);
			break;
		default:
			s = "Eror";
			break;
		}
		
		draw(board, mens[], 3, kill, ekspa);
		print(s);
	}
}

int main()
{
	Board board(0);
	Man mens[3];// {(Point(0,0), Size(1,1)), (Point(1,1), Size(1,1)), (Point(2,2), Size(1,1))};
	mens[1].SetPosition(0, 0);
	mens[2].SetPosition(1, 1);
	mens[3].SetPosition(2, 2);
	draw(board, mens[], 3, kill, ekspa);
	button(board, mens[], 3);
	return 0;
}
