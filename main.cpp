
#include <iostream>
#include <string>
#include <vector>

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

int collizia(Board& board, std::vector<Man>& vMen)
{
	for (int i = 0; i < vMen.size() ; i++)
	{
			
		if (vMen.at(i).GetPosition().x == 23 * SIZE_SCALE )
		{
			ekspa++;
			vMen.at(i).SetPosition(0,0);
		}
		if (vMen.at(i).GetPosition().x == 5 * SIZE_SCALE && board.GetPosition().x != 4 * SIZE_SCALE
			|| vMen.at(i).GetPosition().x == 13 * SIZE_SCALE && board.GetPosition().x != 12 * SIZE_SCALE
			|| vMen.at(i).GetPosition().x == 19 * SIZE_SCALE && board.GetPosition().x != 18 * SIZE_SCALE)
		{
			vMen.at(i).moveDed();
			kill++;
			draw(board, vMen, kill, ekspa);
			vMen.at(i).SetPosition(0,0);
		}
		if (drawShek == 1)
		{
			vMen.at(i).moveStep1();
		}
		if (drawShek == 2)
		{
			vMen.at(i).moveStep2();
		}
		if (drawShek == 3)
		{
			vMen.at(i).moveStep3();
		}
	}
	drawShek < 3 ? drawShek++ : drawShek = 1;
}
void button(Board& board, std::vector<Man>& vMen)
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
			collizia(board, vMen);
			break;
		default:
			s = "Eror";
			break;
		}
		
		draw(board, vMen, kill, ekspa);
		print(s);
	}
}

int main()
{
	Board board(4);
	std::vector<Man> vMen;
	vMen.push_back(Man());
	vMen.push_back(Man());
	vMen.push_back(Man());
	cout << vMen.size() << "\n";
	//Man mens[2];// {(Point(0,0), Size(1,1)), (Point(1,1), Size(1,1)), (Point(2,2), Size(1,1))};
	//mens[0].SetPosition(1, 1);
	//mens[1].SetPosition(3, 2);
	//mens[2].SetPosition(8, 3);
	//cout << mens[1].GetPosition().x << "\n";
	//cout << mens[1].GetPosition().y << "\n";
	draw(board, vMen, kill, ekspa);
	button(board, vMen);
	return 0;
}
