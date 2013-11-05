#ifndef DRAW_H
#define DRAW_H
#include <string>
#include "draw.h"
#include "objects.h"
#include "point.h"

class Point;

void draw(const Objects& Board, const Objects& Man);
void print(const std::string& msg);

#endif
