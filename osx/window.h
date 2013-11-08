#include "user_input.h"
#include <ncurses.h>
#include <string>

class Point;
class GameObject;

/// Window singleton
class Window
{
public:
	static Window* Instance();
	static void RemoveInstance();

	void Draw(const GameObject& board, const GameObject& man);
	void Print(const std::string& msg);
	Key WaitForInput();

private:
	Window();
	~Window();
	void Clear();
	void Refresh();
	void DrawBorder();
	void DrawMan(const GameObject& man);
	void DrawBoard(const GameObject& board);
	void DrawSymbol(const Point& p, const char ch);

	static Window* instance_;
	WINDOW* wnd_;
};
