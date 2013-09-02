#include <iostream>
#include <conio.h>
#include "point.h"
#include "draw.h"

using namespace std;
void button(const int& board, const Point& obgect);

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
void button(const int& board, const Point& obgect)
{
	bool exit = true;
	while(exit)
	{
		int key = 0;
		key = getch();
		switch (key)
		{
		case 77:					//right
			draw(board, obgect);
			cout << "right\n";
			break;
		case 75:					//left
			draw(board, obgect);
			cout << "left\n";
			break;
		case 13:
			cout << "Entr\n";
			exit = false;
			break;
		}
	;}
}
