#ifndef DRAW_H
#define DRAW_H

#include <string>

#include "gameObject.h"
#include "board.h"
#include "man.h"


void draw(const Board& board, const Man& mens[], int number_of_elements, int, int);
void print(const std::string& msg);

#endif
