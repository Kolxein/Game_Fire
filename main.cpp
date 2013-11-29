
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
int drawShek = 1;

using namespace std;

int collizia(Board& board, Man mens[])
{
	for (int i = 0; i < 3; i++)
	{
			
		if (mens[i].GetPosition().x == 23 * SIZE_SCALE )
		{
			ekspa++;
			mens[i].SetPosition(0,0);
		}
		if (mens[i].GetPosition().x == 5 * SIZE_SCALE && board.GetPosition().x != 4 * SIZE_SCALE
			|| mens[i].GetPosition().x == 13 * SIZE_SCALE && board.GetPosition().x != 12 * SIZE_SCALE
			|| mens[i].GetPosition().x == 19 * SIZE_SCALE && board.GetPosition().x != 18 * SIZE_SCALE)
		{
			mens[i].moveDed();
			kill++;
			draw(board, mens, kill, ekspa);
			mens[i].SetPosition(0,0);
		}
		if (drawShek == 1)
		{
			mens[i].moveStep1();
		}
		if (drawShek == 2)
		{
			mens[i].moveStep2();
		}
		if (drawShek == 3)
		{
			mens[i].moveStep3();
		}
	}
	drawShek < 3 ? drawShek++ : drawShek = 1;
}
void button(Board& board, Man mens[])
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
