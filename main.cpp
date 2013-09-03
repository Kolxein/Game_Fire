#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "point.h"
#include "draw.h"
#include "user_input.h"

using namespace std;

enum Key
	{
	    KEY_OTHER = 1,
	    KEY_LEFT,
	    KEY_RIGHT,
	    KEY_ENTER
	};
void button(const int& board, const Point& obgect, int wait_for_input(enum Key))
{
	bool exit = true;
	while(exit)
	{
		switch (wait_for_input(Key))
		{
		case 1:					//all key
			cout << "all key\n";
			break;
		case 2:					//right
			system("cls");
			draw(board, obgect);
			cout << "right\n";
			break;
		case 3:					//left
			system("cls");
			draw(board, obgect);
			cout << "left\n";
			break;
		case 4:
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
	button(board, obgect, wait_for_input(Key));
	cout << "Press ENTER to Exit";
	cin.get();
	return 0;
}
//void button(const int& board, const Point& obgect)

