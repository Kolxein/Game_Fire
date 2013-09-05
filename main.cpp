#include <iostream>
#include <string>
#include "point.h"
#include "draw.h"
#include "user_input.h"

using namespace std;

void button(const int board, const Point& obgect)
{
	for (;;)
	{
		string s = "ok";
		switch (wait_for_input())
		{
		case Key::EXIT:
			s = "Exit\n";
			return;
		case Key::RIGHT:					//right
			s = "right\n";
			break;
		case Key::LEFT:					//left
			s = "left\n";
			break;
		case Key::OTHER:					//all key
			s = "all key\n";
			break;
		default:
			s = "Eror\n";
			break;
		}
		
		draw(board, obgect);
		cout << s << "\n";
	}
}

int main()
{
	int board = 2;
	Point obgect(3,8);
	
	draw(board, obgect);
	button(board, obgect);
	
	cout << "Press ENTER to Exit";
	cin.get();
	return 0;
}
