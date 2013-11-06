#ifndef DRAW_H
#define DRAW_H
#include <string>
#include "draw.h"
#include "objects.h"
#include "point.h"

void draw(const Objects& Board, const Objects& Man, const int& FIELD_HEIGHT, const int& FIELD_WIDTH);
void print(const std::string& msg);

#endif
