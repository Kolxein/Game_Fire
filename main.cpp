#include <iostream>
#include "point.h"
#include "draw.h"


using namespace std;


int main()
{
	int board = 2;
	Point obgect(5,2);
	draw(board, obgect);
	cout << "\n\n\n";
	cout << "Press ENTER to continue...";
	cin.get();
	return 0;
}
