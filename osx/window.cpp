#include "./window.h"
#include "point.h"
#include "objects.h"
#include "config.h"
#include <stdlib.h> // for atexit()

const int FIELD_HEIGHT = 7 * SIZE_SCALE;
const int FIELD_WIDTH = 20 * SIZE_SCALE;

///
Window* Window::instance_ = nullptr;

///
Window* Window::Instance()
{
	if (!instance_)
		instance_ = new Window();
	return instance_;
}

///
void Window::RemoveInstance()
{
	delete instance_;
	instance_ = nullptr;
}

///
Window::Window()
	: wnd_(nullptr)
{
	initscr();
	noecho(); // don't print input symbols
	cbreak(); // don't buffer input symbols
	keypad(stdscr, TRUE); // enable special symbols (arrows)
	refresh();

	// Window includes 1-symbol border
	const int winWidth = FIELD_WIDTH + 2;
	const int winHeight = FIELD_HEIGHT + 2;

	int offsetx = (COLS - winWidth)/2;
	int offsety = (LINES - winHeight)/2;

	wnd_ = newwin(winHeight, winWidth, offsety, offsetx);

	atexit(Window::RemoveInstance);
}

///
Window::~Window()
{
	if (wnd_)
		delwin(wnd_);
	endwin();
}

///
void Window::Clear()
{
	clear();
	refresh();
	wclear(wnd_);
}

///
inline void Window::Refresh()
{
	wrefresh(wnd_);
	refresh();
}

///
inline void Window::DrawBorder()
{
	box(wnd_, 0, 0);;
}

///
inline void Window::DrawMan(const Objects& man)
{
	DrawSymbol(man.GetPosition(), man.simbl);
}

///
inline void Window::DrawBoard(const Objects& board)
{
	for (int i = 0; i < board.GetSize().y; ++i) {
		for (int j = 0; j < board.GetSize().x; ++j) {
			const Point p = board.GetPosition();
			DrawSymbol({p.x + j, p.y + i}, board.simbl);
		}
	}
}

/// shift due to border
inline void Window::DrawSymbol(const Point& p, const char ch)
{
	mvwaddch(wnd_, p.y + 1, p.x + 1, ch);
}

///
void Window::Draw(const Objects& board, const Objects& man)
{
	Clear();

	DrawBorder();
	DrawMan(man);
	DrawBoard(board);

	printw("Press q to quit...\n");
	printw("man: (%d, %d)\n", man.GetPosition().x, man.GetPosition().y);
	printw("board position: (%d, %d)\n", board.GetPosition().x, board.GetPosition().y);

	Refresh();
}

///
void Window::Print(const std::string& msg)
{
	printw("%s\n", msg.c_str());
}

///
Key Window::WaitForInput()
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
