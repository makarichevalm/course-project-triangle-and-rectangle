#include"Figure.h"

void Figure::show() {}
void Figure::hide() {}
void Figure::moveto(int new_x, int new_y) {
	hide();
	x = new_x;
	y = new_y;
	show();
}