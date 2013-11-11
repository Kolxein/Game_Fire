
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

void mooveReat(GameObject& rhs)
{
	cout << rhs.GetPosition().x << "\n";
	if (rhs.GetPosition().x + rhs.GetSize().width >= FIELD_WIDTH)
	{
		rhs.SetPosition(FIELD_WIDTH - rhs.GetSize().width);
	}
	else if ((rhs.GetPosition().x + rhs.GetSize().width) < FIELD_WIDTH)
	{
		rhs.SetPosition(rhs.GetPosition().x + rhs.GetSize().width);
	}

};

void mooveLeft(GameObject& rhs)
{
	cout << rhs.GetPosition().x << "\n";
	if (rhs.GetPosition().x <= 0)
	{
		rhs.SetPosition(0);
	}
	else if (rhs.GetPosition().x > 0)
	{
		rhs.SetPosition(rhs.GetPosition().x - rhs.GetSize().width);
	}
};

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
			mooveReat(board);
			s = "right";
			break;
		case Key::LEFT:						//left
			s = "left";
			mooveLeft(board);
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

	
	//GameObject board(Point(3,BOARD_POSITION_Y), Size(BOARD_WIDTH,1));
	//Board board(Point(3,BOARD_POSITION_Y), Size(BOARD_WIDTH,1));
	Board board(3);
	//board.simbl = '=';
	//GameObject man(Point(3,1), Size(2,2));
	Man man(Point(3,1), Size(2,2));
	
	draw(board, man);
	button(board, man);
	return 0;
}
