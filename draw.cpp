#include <iostream>
#include <stdlib.h>
#include "point.h"
#include "draw.h"
#include "objects.h"

using namespace std;


int calc_chars(int j);
void draw_boarder();
void draw_fence(const int& FIELD_WIDTH);
int draw_body(const Objects& Board, const Objects& Man,const Point& drawPoint);

void draw(const Objects& Board, const Objects& Man, const int& FIELD_HEIGHT, const int& FIELD_WIDTH)
{
	system("cls");					//clining window
	draw_fence(FIELD_WIDTH);
	cout << "\n";
	Point drawPoint(0,0);
	for (drawPoint.y = 0; drawPoint.y < FIELD_HEIGHT ;++drawPoint.y)
	{
		draw_boarder();
		for (drawPoint.x = 0; drawPoint.x < FIELD_WIDTH; )
		{
			drawPoint.x += draw_body(Board, Man, drawPoint);
		}
		draw_boarder();
		cout << "\n";
	}
	draw_fence(FIELD_WIDTH);
	cout << "\n";
}

void draw_boarder()
{
	cout << "#";
}

void draw_fence(const int& FIELD_WIDTH)
{
	for (int j = 0; j < FIELD_WIDTH + 2; ++j)
	{
		draw_boarder();
	}
}

int draw_body(const Objects& Board, const Objects& Man,const Point& drawPoint)
{
	if (Man.GetPosition() == drawPoint)
	{
		for (int n = 0; n < Man.GetSize().x; n++)
		{
			cout << Man.simbl;
		}
		cout << "(" << drawPoint.x << ":" << drawPoint.y << ")";
		return 3 + Man.GetSize().x + calc_chars(drawPoint.y) + calc_chars(drawPoint.x);
	}
	
	if (Man.GetPosition().x == drawPoint.x 
		&& drawPoint.y > Man.GetPosition().y 
		&& (Man.GetSize().y + Man.GetPosition().y) > drawPoint.y)
	{
		for (int n = 0; n < Man.GetSize().x; n++)
		{
			cout << Man.simbl;
		}
		return  Man.GetSize().x;
	}
	
	if (drawPoint.x == Board.GetPosition().x && drawPoint.y == Board.GetPosition().y - 2)
	{
		int i = 0;
		for (i; i < Board.GetSize().x; i++)
		{
			cout << Board.simbl;
		}
		return i;
	}
	
	if (drawPoint.x == Board.GetPosition().x && drawPoint.y == Board.GetPosition().y - 1)
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
