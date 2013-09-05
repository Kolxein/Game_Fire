#ifndef USER_INPUT_H
#define USER_INPUT_H

enum class Key
{
	OTHER = 0,
	LEFT,
	RIGHT,
	EXIT
};

Key wait_for_input();

#endif
