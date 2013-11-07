#include "user_input.h"
#include <ncurses.h>
#include <string>

class Point;
class Objects;

/// Window singleton
class Window
{
public:
	static Window* Instance();
	static void RemoveInstance();

	void Draw(const Objects& board, const Objects& man);
	void Print(const std::string& msg);
	Key WaitForInput();

private:
	Window();
	~Window();
	void Clear();
	void Refresh();
	void DrawBorder();
	void DrawMan(const Objects& man);
	void DrawBoard(const Objects& board);
	void DrawSymbol(const Point& p, const char ch);

	static Window* instance_;
	WINDOW* wnd_;
};
