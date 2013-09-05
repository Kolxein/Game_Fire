#include "draw.h"
#include "point.h"
#include <stdlib.h> // for atexit()
#include <ncurses.h>

using namespace std;

const int SIZE_SCALE = 2;
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

	const int fieldWidth = FIELD_WIDTH + 2;
	const int fieldHeight = FIELD_HEIGHT + 2;

	int offsetx = (COLS - fieldWidth)/2;
	int offsety = (LINES - FIELD_HEIGHT)/2;

	g_mainWindow = newwin(fieldHeight, fieldWidth, offsety, offsetx);

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

/// shift due to border
void draw_symbol(const Point& p, const char ch)
{
	mvwaddch(g_mainWindow, p.y + 1, p.x + 1, ch);
}

///
void actual_draw(const int board, const Point& object)
{
	clear();
	refresh();
	wclear(g_mainWindow);

	draw_symbol(object, '*');

	const int boardY = FIELD_HEIGHT - 1;
	for (int i = 0; i < 4; ++i)
	{
		draw_symbol({board + i, boardY}, '=');
	}

	box(g_mainWindow, 0, 0);

	wrefresh(g_mainWindow);

	printw("Press ENTER to quit...\n");
	printw("object: (%d, %d)\n", object.x, object.y);
	printw("board: (%d, %d)\n", board, boardY);
	refresh();
}

///
void draw(const int board, const Point& obgect)
{
	g_drawFunction(board, obgect);
}

///
void print(const string& msg)
{
	printw("%s\n", msg.c_str());
}
