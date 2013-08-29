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
int calc_chars (int j);
void draw_boarder ();
void draw_fence ();
void draw_body (const int board, const Point& obgect, int i, int& j);

int main()
{
	int board = 12;
	Point obgect(15,8);
	draw(board, obgect);
	cout<< "\n\n\n";
	cout<< "Press ENTER to continue...";
	cin.get();
	return 0;
}
void draw(const int board, const Point& obgect)
{
	for (int i = 0; i <= FIELD_HEIGHT + 1; ++i) 
	{
		if (i == 0)
		{
			draw_fence ();
			cout << "\n";
		}
		else if (i == FIELD_HEIGHT + 1)
		{
			draw_fence ();
			break;
		}
		draw_boarder ();
		for (int j = 0; j < FIELD_WIDTH ; ++j)
		{
			draw_body (board,obgect,i,j);
		}
		draw_boarder ();
		cout << "\n";
	}
}

void draw_boarder ()
{
	cout << "#";
}

void draw_fence ()
{
	for (int j = 0; j < FIELD_WIDTH + 2; ++j)
	{
		draw_boarder ();
	}
}

void draw_body (const int board, const Point& obgect, int i, int& j)
{
	if (j == obgect.x && i == obgect.y)
	{
		cout << "*";
		cout << "(" << i << ":" << j << ")";
		int n = calc_chars (i);
		int m = calc_chars (j);
		j = j + (4 + n + m);
	}
	if (j == board && i == FIELD_HEIGHT - 1 * SIZE_SCALE)
	{
		cout << "====";
		j = j + 4;
	}
	if (j == board && i == FIELD_HEIGHT + 1 - 1 * SIZE_SCALE)
	{
		int n = calc_chars (j);
		cout << "(" << j + 2 << ")";
		j = j + (2 + n);
	}
	cout << " " ;
}


int calc_chars (int j)
{
	int n = 1;
	while (j > 9)
	{
		j = j / 10;
		++n;
	}
	return n;
}
