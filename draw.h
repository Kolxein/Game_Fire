#include <iostream>
#ifndef DRAW_H
#define DRAW_H

using namespace std;

void draw(const int board, const Point& obgect);
int calc_chars(int j);
void draw_boarder();
void draw_fence();
int draw_body(const int board, const Point& obgect, int i, int j);

#endif
