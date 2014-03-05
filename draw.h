#ifndef DRAW_H
#define DRAW_H

#include <string>
#include <vector>

#include "gameObject.h"
#include "board.h"
#include "man.h"


void draw(const Board& board, std::vector<Man>& vMen, int, int);
void print(const std::string& msg);

#endif
