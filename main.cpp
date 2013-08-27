#include <iostream>

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
const int SIZE_SCALE = 3; 
const int FIELD_HEIGHT = 7 * SIZE_SCALE;
const int FIELD_WIDTH = 20 * SIZE_SCALE;


void draw(const int board, const Point& obgect);

int main()
{
	int board = 1;
	Point obgect(1,1);
	draw(board, obgect);
	cout<< board << "\n";
	cout<< obgect.x << "\n";
	cout<< obgect.y << "\n";
	cout<< "GAME OVER!!!!\n\n";
	cout<< "Press ENTER to continue...";
	cin.get();
	return 0;
}
void draw(const int board, const Point& obgect)
{
	for (int i = 0; i < FIELD_HEIGHT + 2; i++) 
	{
		for (int j = 0; j < FIELD_WIDTH + 2; j++)
		{
			if (i == 0 || i == FIELD_HEIGHT + 1)
			{
				cout << "#";
				continue;
			}
			if (j == 0 || j == FIELD_WIDTH + 1)
			{
				cout << "#";
				continue;
			}
			if (j == obgect.x && i == obgect.y)
			{
				cout << "*";
				cout << "(" << i << ":" << j << ")";
				j = j + 5;				// korrekt dlin strok
				continue;
			}
			if (j == board && i == FIELD_HEIGHT - 1 * SIZE_SCALE)
			{
				cout << "====";
				j = j + 3;				// korrekt dlin strok
				continue;
			}
			if (j == board && i == FIELD_HEIGHT + 1 - 1 * SIZE_SCALE)
			{
				cout << "(" << j << ")";
				j = j + 2;				// korrekt dlin strok
				continue;
			}
			cout << " " ;
		}
		cout << "\n";
	}
}

