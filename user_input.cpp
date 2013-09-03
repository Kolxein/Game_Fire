#include <iostream>
#include <conio.h>
#include "user_input.h"

int wait_for_input(enum Key)
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
