#include"Figure.h"

Complex_F::Complex_F(int new_x, int new_y, int new_a) {
	x = new_x;
	y = new_y;
	a = new_a;
	rectangl = Rectangl(x, y, a);
	triangle = Triangle(x, y, a);
}
void Complex_F::show() {
	rectangl = Rectangl(x, y, a);
	triangle = Triangle(x, y, a);
	triangle.show();
	rectangl.show();
}
void Complex_F::hide() {
	triangle.hide();
	rectangl.hide();
}
