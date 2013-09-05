#include "user_input.h"
#include <ncurses.h>

///
Key wait_for_input()
{
	switch (getch())
	{
	case 'q':
		return Key::EXIT;
	case KEY_LEFT:
		return Key::LEFT;
	case KEY_RIGHT:
		return Key::RIGHT;
	default:
		break;
	}

	return Key::OTHER;
}
