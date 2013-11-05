#include <iostream>
#include <stdlib.h>
#include "point.h"
#include "draw.h"
#include "objects.h"

using namespace std;

const int SIZE_SCALE = 2;
const int FIELD_HEIGHT = 7 * SIZE_SCALE;
const int FIELD_WIDTH = 20 * SIZE_SCALE;

int calc_chars(int j);
void draw_boarder();
void draw_fence();
int draw_body(const Objects& Board, const Objects& Man,const Point& drawPoint);

void draw(const Objects& Board, const Objects& Man)
{
	system("cls");					//clining window
	draw_fence();
	cout << "\n";
	Point drawPoint(0,0);
	for (drawPoint.y = 0; drawPoint.y < FIELD_HEIGHT ;++drawPoint.y)
	{
		draw_boarder();
		for (drawPoint.x = 0; drawPoint.x < FIELD_WIDTH ;)
		{
			drawPoint.x += draw_body(Board, Man, drawPoint);
		}
		draw_boarder();
		cout << "\n";
	}
	draw_fence();
	cout << "\n";
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

int draw_body(const Objects& Board, const Objects& Man,const Point& drawPoint)
{
	if (Man.position_ == drawPoint)
	{
		cout << "*";
		cout << "(" << drawPoint.x << ":" << drawPoint.y << ")";
		return 4 + calc_chars(drawPoint.y) + calc_chars(drawPoint.x);
	}
	if (drawPoint.x == Board.position_.x && drawPoint.y == Board.position_.y - 2)
	{
		cout << "====";
		return 4;
	}
	if (drawPoint.x == Board.position_.x && drawPoint.y == Board.position_.y - 1)
	{
		cout << "(" << drawPoint.x << ")";
		return 2 + calc_chars(drawPoint.x);
	}
	cout << " ";
	return 1;
}

int calc_chars(int j)
{
	//if (j > 9)
	//return 1+ calc_chars(j/10);
	//else return 1;
	return j > 9 ? 1 + calc_chars(j/10) : 1;
}

void print(const string& msg)
{
	cout << msg << endl;
}
