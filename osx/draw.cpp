#include "./window.h"

///
void draw(const int board, const Point& object)
{
	Window::Instance()->Draw(board, object);
}

///
void print(const std::string& msg)
{
	Window::Instance()->Print(msg);
}
