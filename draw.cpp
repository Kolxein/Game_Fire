#include "draw.h"

#include <iostream>
#include <stdlib.h>

#include "config.h"
#include "point.h"
#include "size.h"
#include "gameObject.h"



using namespace std;


int calc_chars(int j);
void draw_boarder();
void draw_fence();
int draw_body(const GameObject& board, const GameObject& man,const Point& drawPoint);

void draw(const GameObject& board, const GameObject& man)
{
	system("cls");					//clining window
	draw_fence();
	cout << "\n";
	Point drawPoint(0,0);
	for (drawPoint.y = 0; drawPoint.y < FIELD_HEIGHT ;++drawPoint.y)
	{
		draw_boarder();
		for (drawPoint.x = 0; drawPoint.x < FIELD_WIDTH; )
		{
			drawPoint.x += draw_body(board, man, drawPoint);
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

int draw_body(const GameObject& board, const GameObject& man,const Point& drawPoint)
{
	if (man.GetPosition() == drawPoint)
	{
		for (int n = 0; n < man.GetSize().width ; n++)
		{
			cout << man.simbl;
		}
		cout << "(" << drawPoint.x << ":" << drawPoint.y << ")";
		return 3 + man.GetSize().width + calc_chars(drawPoint.y) + calc_chars(drawPoint.x);
	}
	
	if (man.GetPosition().x == drawPoint.x 
		&& drawPoint.y > man.GetPosition().y 
		&& (man.GetSize().height + man.GetPosition().y) > drawPoint.y)
	{
		for (int n = 0; n < man.GetSize().width; n++)
		{
			cout << man.simbl;
		}
		return man.GetSize().width;
	}
	
	if (drawPoint.x == board.GetPosition().x && drawPoint.y == board.GetPosition().y - 2)
	{
		int i = 0;
		for (i; i < board.GetSize().width; i++)
		{
			cout << board.simbl;
		}
		return i;
	}
	
	if (drawPoint.x == board.GetPosition().x && drawPoint.y == board.GetPosition().y - 1)
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
