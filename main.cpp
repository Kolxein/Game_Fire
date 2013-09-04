#include <iostream>
#include <stdlib.h>
#include "point.h"
#include "draw.h"
#include "user_input.h"

using namespace std;


void button(const int board, const Point& obgect)
{
	bool exit = true;
	while(exit)
	{
		switch (wait_for_input())
		{
		case KEY_OTHER:					//all key
			system("cls");
			draw(board, obgect);
			cout << "all key\n";
			break;
		case KEY_RIGHT:					//right
			system("cls");
			draw(board, obgect);
			cout << "right\n";
			break;
		case KEY_LEFT:					//left
			system("cls");
			draw(board, obgect);
			cout << "left\n";
			break;
		case KEY_ENTER:
			cout << "Entr\n";
			exit = false;
			break;
		default:cout << "Eror\n";
		}
	;}
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
//void button(const int& board, const Point& obgect)

