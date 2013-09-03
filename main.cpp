#include <iostream>
//#include <conio.h>
#include <stdlib.h>
#include "point.h"
#include "draw.h"

using namespace std;
void button(const int& board, const Point& obgect)
{
	bool exit = true;
	while(exit)
	{
		int key = cin.get();
		cout << key << endl;
		//int key = 0;
		key = cin.get();
		switch (key)
		{
		case 39:					//right
			system("cls");
			draw(board, obgect);
			cout << "right\n";
			break;
		case 37:					//left
			system("cls");
			draw(board, obgect);
			cout << "left\n";
			break;
		case 10:
			cout << "Entr\n";
			exit = false;
			break;
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

