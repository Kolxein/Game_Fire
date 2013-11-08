#include "draw.h"
#include "./window.h"

///
void draw(const GameObject& board, const GameObject& man)
{
	Window::Instance()->Draw(board, man);
}

///
void print(const std::string& msg)
{
	Window::Instance()->Print(msg);
}
