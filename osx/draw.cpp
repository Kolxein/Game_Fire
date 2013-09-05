#include "draw.h"
#include "point.h"
#include <stdlib.h> // for atexit()
#include <ncurses.h>

const int SIZE_SCALE = 5;
const int FIELD_HEIGHT = 7 * SIZE_SCALE;
const int FIELD_WIDTH = 20 * SIZE_SCALE;

void draw_init(const int, const Point&);
void draw_finalize();
void actual_draw(const int, const Point&);

using DrawFunction = void(*)(const int, const Point&);

DrawFunction g_drawFunction = draw_init;
WINDOW* g_mainWindow = nullptr;

///
void draw_init(const int board, const Point& object)
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();

	int offsetx = (COLS - FIELD_WIDTH)/2;
	int offsety = (LINES - FIELD_HEIGHT)/2;

	g_mainWindow = newwin(FIELD_HEIGHT, FIELD_WIDTH, offsety, offsetx);

	atexit(draw_finalize);
	g_drawFunction = actual_draw;
	g_drawFunction(board, object);
}

///
void draw_finalize()
{
	if (g_mainWindow)
		delwin(g_mainWindow);
	endwin();
}

///
void actual_draw(const int board, const Point& object)
{
	clear();
	refresh();
	wclear(g_mainWindow);

	mvwaddch(g_mainWindow, object.y, object.x, '*');

	const int boardY = FIELD_HEIGHT - 2;
	for (int i = 0; i < 4; ++i)
	{
		mvwaddch(g_mainWindow, boardY, board + i, '=');
	}

	box(g_mainWindow, 0, 0);

	wrefresh(g_mainWindow);

	printw("Press ENTER to quit...\n");
	refresh();
}

///
void draw(const int board, const Point& obgect)
{
	g_drawFunction(board, obgect);
}

///
void print(const std::string& msg)
{
	printw("%s\n", msg.c_str());
}
