
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

int collizia(Board& board, Man mens[])
{
	for (int i = 0; i < 3; i++)
	{
		if (mens[i].GetPosition().x == 4 && board.GetPosition().x != 0
			|| mens[i].GetPosition().x == 12 && board.GetPosition().x != BOARD_WIDTH 
			|| mens[i].GetPosition().x == 18 && board.GetPosition().x != BOARD_WIDTH * 2)
		{
			mens[i].moveDed();
			kill++;
			draw(board, mens, kill, ekspa);
			mens[i].SetPosition(0,0);
		}
		else
		{
			mens[i].move();
			if (mens[i].GetPosition().x == FIELD_WIDTH - 1)
			{
				ekspa++;
				mens[i].SetPosition(0,0);
			}
		}
	}
}

void button(Board& board, Man mens[3])
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
			collizia(board, mens);
			break;
		default:
			s = "Eror";
			break;
		}
		
		draw(board, mens, kill, ekspa);
		print(s);
	}
}

int main()
{
	Board board(10);
	Man mens[3];// {(Point(0,0), Size(1,1)), (Point(1,1), Size(1,1)), (Point(2,2), Size(1,1))};
	mens[0].SetPosition(1, 1);
	mens[1].SetPosition(3, 2);
	mens[2].SetPosition(8, 3);
	cout << mens[1].GetPosition().x << "\n";
	cout << mens[1].GetPosition().y << "\n";
	draw(board, mens, kill, ekspa);
	button(board, mens);
	return 0;
}
