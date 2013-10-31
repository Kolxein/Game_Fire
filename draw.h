#ifndef DRAW_H
#define DRAW_H

#include <string>
#include "objects.h"

class Point;

void draw(const Objects& board, const Point& oman);
void print(const std::string& msg);

#endif
