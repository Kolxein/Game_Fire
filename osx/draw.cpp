#include "./window.h"

///
void draw(const int board, const Point& man)
{
	Window::Instance()->Draw(board, man);
}

///
void print(const std::string& msg)
{
	Window::Instance()->Print(msg);
}
