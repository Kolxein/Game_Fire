#include "user_input.h"
#include "./window.h"

///
Key wait_for_input()
{
	return Window::Instance()->WaitForInput();
}
