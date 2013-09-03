#include <iostream>
#include <conio.h>
#include "user_input.h"

Key wait_for_input()
{
	int key = getch();
	cout << key << endl;
	if (key == 75) //left
		return KEY_LEFT;
	if (key == 77) //reagth
		return KEY_RIGHT;
	if (key == 13) //Enter
		return KEY_ENTER;
}
