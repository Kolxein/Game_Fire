#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

class Point
{
public:
	Point(int a, int b);
	int x;
	int y;
private:
};

Point::Point(int a, int b)
	: x(a)
	, y(b)
{
}
 
const int FIELD_HEIGHT = 7;
const int FIELD_WIDTH = 20;

void draw(const int board, const Point& obgect);

int main()
{
	int board = 0;
	Point obgect(1,1);
	draw(board, obgect);
	cout<< board << "\n";
	cout<< obgect.x << "\n";
	cout<< obgect.y << "\n";
	cout<< "GAME OVER!!!!\n\n";
	cout<< "Press ENTER to continue...";
	//cin.get();
	getch();
	return 0;
}
void draw(const int board, const Point& obgect)
{
	for (int counterH = 0; counterH < FIELD_HEIGHT; counterH++) 
	{
		for (int counterW = 0; counterW < FIELD_WIDTH; counterW++)
		{
			if (counterW == obgect.x && counterH == obgect.y)
			{
				cout << "*";
				continue;
			}
			if (counterW == board && counterH == FIELD_HEIGHT - 2)
			{
				cout << "_";
				continue;
			}
			cout << "-" ;
		}
		cout << "\n";
	}
}

