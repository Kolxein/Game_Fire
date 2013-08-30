#include <iostream>
#include "point.h"
#include "draw.h"

using namespace std;

const int SIZE_SCALE = 3;
const int FIELD_HEIGHT = 7 * SIZE_SCALE;
const int FIELD_WIDTH = 20 * SIZE_SCALE;

int calc_chars(int j);
void draw_boarder();
void draw_fence();
int draw_body(const int board, const Point& obgect, const Point drawPoint);

void draw(const int board, const Point& obgect)
{
	draw_fence();
	cout << "\n";
	Point drawPoint(0,0);
	for (int i = 0; i < FIELD_HEIGHT ;)
	{
		draw_boarder();
		for (int j = 0; j < FIELD_WIDTH ;)
		{
			j = j + draw_body(board,obgect,drawPoint);
			drawPoint.y = j;
		}
		draw_boarder();
		cout << "\n";
		drawPoint.x = ++i;
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

int draw_body(const int board, const Point& obgect,const Point drawPoint)
{
	if (drawPoint.y == obgect.x && drawPoint.x == obgect.y)
	{
		cout << "*";
		cout << "(" << drawPoint.y << ":" << drawPoint.x << ")";
		return 4 + calc_chars(drawPoint.x) + calc_chars(drawPoint.y);
	}
	if (drawPoint.y == board && drawPoint.x == FIELD_HEIGHT - 2)
	{
		cout << "====";
		return 4;
	}
	if (drawPoint.y == board && drawPoint.x == FIELD_HEIGHT - 1)
	{
		cout << "(" << drawPoint.y << ")";
		return 2 + calc_chars(drawPoint.y);
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
