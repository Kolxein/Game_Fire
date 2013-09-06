#include "user_input.h"
#include <ncurses.h>
#include <string>

class Point;

/// Window singleton
class Window
{
public:
	static Window* Instance();
	static void RemoveInstance();

	void Draw(const int board, const Point& man);
	void Print(const std::string& msg);
	Key WaitForInput();

private:
	Window();
	~Window();
	void Clear();
	void Refresh();
	void DrawBorder();
	void DrawObject(const Point& p);
	void DrawBoard(const Point& l);
	void DrawSymbol(const Point& p, const char ch);

	static Window* instance_;
	WINDOW* wnd_;
};
