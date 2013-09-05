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
		return Key::LEFT;
	if (key == 77) //reagth
		return Key::RIGHT;
	if (key == 13) //Enter
		return Key::EXIT;
	
	return Key::OTHER;
}
