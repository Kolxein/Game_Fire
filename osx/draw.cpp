#include "draw.h"
#include "./window.h"

///
void draw(const Objects& board, const Objects& man, const int&, const int&)
{
	Window::Instance()->Draw(board, man);
}

///
void print(const std::string& msg)
{
	Window::Instance()->Print(msg);
}
