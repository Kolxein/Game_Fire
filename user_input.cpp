#include <iostream>
#include <conio.h>
#include "user_input.h"

using namespace std;

Key wait_for_input()
{
	int key = getch();
	if (key == 224)				//proverka dla strelok otdelenie 2 simvola
	{
		key = getch();
	}
	if (key == 75) //left
		return KEY_LEFT;
	if (key == 77) //reagth
		return KEY_RIGHT;
	if (key == 13) //Enter
		return KEY_ENTER;
	return KEY_OTHER;
}