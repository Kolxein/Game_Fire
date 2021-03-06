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
int draw_body(const Board& board, std::vector<Man>& vMen,const Point& drawPoint);

void draw(const Board& board, std::vector<Man>& vMen, int kill, int ekspa)
{
	system("cls");					//clining window
	cout << "ekspa   " << ekspa << "   kill   " << kill<<"\n";
	draw_fence();
	cout << "\n";
	Point drawPoint(0,0);
	for (drawPoint.y = 0; drawPoint.y < FIELD_HEIGHT ;++drawPoint.y)
	{
		draw_boarder();
		for (drawPoint.x = 0; drawPoint.x < FIELD_WIDTH; )
		{
			drawPoint.x += draw_body(board, vMen, drawPoint);
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

int draw_body(const Board& board, std::vector<Man>& vMen, const Point& drawPoint)
{
	for (int m = 0; m < vMen.size(); m++)
	{
		if (vMen.at(m).GetPosition() == drawPoint)
		{
			for (int n = 0; n < vMen.at(m).GetSize().width ; n++)
			{
				cout << vMen.at(m).simbl;
			}
			//cout << "(" << drawPoint.x << ":" << drawPoint.y << ")";
			return 1; //3 + mens[m].GetSize().width + calc_chars(drawPoint.y) + calc_chars(drawPoint.x);
		}
		
		if (vMen.at(m).GetPosition().x == drawPoint.x 
			&& drawPoint.y > vMen.at(m).GetPosition().y 
			&& (vMen.at(m).GetSize().height + vMen.at(m).GetPosition().y) > drawPoint.y)
		{
			for (int n = 0; n < vMen.at(m).GetSize().width; n++)
			{
				cout << vMen.at(m).simbl;
			}
			return vMen.at(m).GetSize().width;
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
		/*
		if (drawPoint.x == board.GetPosition().x && drawPoint.y == board.GetPosition().y - 1)
		{
			cout << "(" << drawPoint.x << ")";
			return 2 + calc_chars(drawPoint.x);
		}
		*/
		
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

