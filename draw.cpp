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
	for (drawPoint.y = 0; drawPoint.y < FIELD_HEIGHT ;)
	{
		draw_boarder();
		for (drawPoint.x = 0; drawPoint.x < FIELD_WIDTH ;)
		{
			drawPoint.x = drawPoint.x + draw_body(board,obgect,drawPoint);
		}
		draw_boarder();
		cout << "\n";
		++drawPoint.y;
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
	//drawPoint(drawPoint.x,drawPoint.y);
	//if (object == drawPoint)
	if (drawPoint.x == obgect.x && drawPoint.y == obgect.y)
	{
		cout << "*";
		cout << "(" << drawPoint.x << ":" << drawPoint.y << ")";
		return 4 + calc_chars(drawPoint.y) + calc_chars(drawPoint.x);
	}
	if (drawPoint.x == board && drawPoint.y == FIELD_HEIGHT - 2)
	{
		cout << "====";
		return 4;
	}
	if (drawPoint.x == board && drawPoint.y == FIELD_HEIGHT - 1)
	{
		cout << "(" << drawPoint.x << ")";
		return 2 + calc_chars(drawPoint.x);
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
