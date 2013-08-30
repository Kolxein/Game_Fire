#include <iostream>
#include "point.h"
#include "draw.h"


using namespace std;


int main()
{
	int board = 5;
	Point obgect(4,6);
	draw(board, obgect);
	cout << "\n\n\n";
	cout << "Press ENTER to continue...";
	cin.get();
	return 0;
}
