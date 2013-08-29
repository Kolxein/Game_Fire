//#include <iostream>
#include "point.h"

using namespace std;
/*
void draw(const int board, const Point& obgect)
{
 	draw_fence();
	cout << "\n";
	for (int i = 0; i < FIELD_HEIGHT ; ++i) 
	{
		draw_boarder();
		for (int j = 0; j < FIELD_WIDTH ;)
		{
			j = j + draw_body(board,obgect,i,j);
		}
		draw_boarder();
		cout << "\n";
	}
	draw_fence();
}

void draw_boarder()
{
	cout << "#";
}

void draw_fence()
{
	for (int j = 0; j < FIELD_WIDTH + 2; ++j)
	{
		draw_boarder();
	}
}

int draw_body(const int board, const Point& obgect, int i, int j)
{
	if (j == obgect.x && i == obgect.y)
	{
		cout << "*";
		cout << "(" << i << ":" << j << ")";
		return 4 + calc_chars(i) + calc_chars(j);
	}
	if (j == board && i == FIELD_HEIGHT - 2)
	{
		cout << "====";
		return 4;
	}
	if (j == board && i == FIELD_HEIGHT - 1)
	{
		cout << "(" << j << ")";
		return 2 + calc_chars(j);
	}
	cout << " " ;
	return 1;
}

int calc_chars(int j)
{
	int n = 1;
	while (j > 9)
	{
		j = j / 10;
		++n;
	}
	return n;
}
*/
