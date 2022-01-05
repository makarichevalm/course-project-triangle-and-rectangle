#include"Figure.h"

void Figure:: show(){}
void Figure:: hide(){}
void Figure:: moveto(int new_x, int new_y) {
	hide();
	x = new_x;
	y = new_y;
	show();
}

Triangle::Triangle(int new_x, int new_y, int new_a) {//конструктор с параметрами
	x = new_x;// объявление начальных координат
	y = new_y;
	a = new_a;
	ax = x - a / 2;	//расчет координат для построения    //координаты нижнего левого угла 
	ay = y + ((1.73 * a) / 2);							//
	bx = x + a / 2;
	by = y + ((1.73 * a) / 2);
}
void Triangle::show() {
	HWND hwnd = GetConsoleWindow();//Получаем идентификатор окна
	HDC hdc = GetDC(hwnd);//получаем контекст изображения
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));//создаем перо
	HBRUSH brush = CreateSolidBrush(RGB(0, 255, 255));//создаем кисть
	GetClientRect(hwnd, &rt);//получаем размер окна
	SelectObject(hdc, pen);//назначаем перо для рисования
	SelectObject(hdc, brush);//назначаем кисть для рисования
	//объявляем координаты для построения
	ax = x - a / 2;
	ay = y + ((1.73 * a) / 2);							
	bx = x + a / 2;
	by = y + ((1.73 * a) / 2);
	if ((ax <= rt.left) ||
		(y <= rt.top) || (bx >= rt.right)
		|| (by >= rt.bottom))throw Border();//отлавливание выхода за границы окна
	POINT points[] = { {bx, by}, {x, y}, {ax, ay} };
	Polygon(hdc, points, 3);// рисуем треугольник
	//освобождаем ресурсы
	DeleteObject(pen);
	DeleteObject(brush);
	DeletePen(pen);//удаление пера
	DeleteBrush(brush);//удаление кисти
	ReleaseDC(hwnd, hdc);//освобождение контекста изображения
	//cout << "A: " << ax << ',' << ay << endl;
	//cout << "B: " << bx << ',' << by << endl;
}

void Triangle::hide() {
	HWND hwnd = GetConsoleWindow();//Получаем идентификатор окна
	HDC hdc = GetDC(hwnd);//получаем контекст изображения
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));//создаем перо
	HBRUSH brush = CreateSolidBrush(RGB(242, 242, 242));//создаем кисть
	GetClientRect(hwnd, &rt);//получаем размер окна
	SelectObject(hdc, pen);//назначаем перо для рисования
	SelectObject(hdc, brush);//назначаем кисть для рисования
	POINT points[] = { {bx, by}, {x, y}, {ax, ay} };
	Polygon(hdc, points, 3);// рисуем треугольник
	//освобождаем ресурсы
	DeleteObject(pen);
	DeleteObject(brush);
	DeletePen(pen);//удаление пера
	DeleteBrush(brush);//удаление кисти
	ReleaseDC(hwnd, hdc);//освобождение контекста изображения
}
Rectangl::Rectangl(int new_x, int new_y, int new_a) {
	x = new_x;
	y = new_y;										
	a = new_a;
	rx = x + a / 4;//правый верхний угол
	ry = y + ((1.73 * a) / 4);//-
	lx = x - a / 4;//левый нижний угол
	ly = y + ((1.73 * a) / 2);//-

}
void Rectangl::show() {
	HWND hwnd = GetConsoleWindow();//Получаем идентификатор окна
	HDC hdc = GetDC(hwnd);//получаем контекст изображения
	HPEN Bpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));//создаем перо
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 255));//создаем кисть
	GetClientRect(hwnd, &rt);//получаем размер окна
	SelectObject(hdc, Bpen);//назначаем перо для рисования
	SelectObject(hdc, hbrush);//назначаем кисть для рисования
	//объявляем координаты для построения
	rx = x + a / 4;
	ry = y + ((1.73 * a) / 4);
	lx = x - a / 4;
	ly = y + ((1.73 * a) / 2);
	if ((lx <= rt.left) ||
		(ry <= rt.top) || (rx >= rt.right)
		|| (ly >= rt.bottom))throw Border();//отлавливание выхода за границы окна
	Rectangle(hdc, lx, ly, rx, ry);// рисуем прямугольник
	//освобождаем ресурсы
	DeleteObject(Bpen);
	DeleteObject(hbrush);
	DeletePen(Bpen);//удаление пера
	DeleteBrush(hbrush);//удаление кисти
	ReleaseDC(hwnd, hdc);//освобождение контекста изображения
	//cout << "L: " << lx << ',' << ly << endl;
	//cout << "R: " << rx << ',' << ry << endl;
}
void Rectangl::hide() {
	HWND hwnd = GetConsoleWindow();//Получаем идентификатор окна
	HDC hdc = GetDC(hwnd);//получаем контекст изображения
	HPEN Bpen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));//создаем перо
	HBRUSH hbrush = CreateSolidBrush(RGB(242, 242, 242));//создаем кисть
	GetClientRect(hwnd, &rt);//получаем размер окна
	SelectObject(hdc, Bpen);//назначаем перо для рисования
	SelectObject(hdc, hbrush);//назначаем кисть для рисования
	Rectangle(hdc, lx, ly, rx, ry);// рисуем прямугольник
	//освобождаем ресурсы
	DeleteObject(Bpen);
	DeleteObject(hbrush);
	DeletePen(Bpen);//удаление пера
	DeleteBrush(hbrush);//удаление кисти
	ReleaseDC(hwnd, hdc);//освобождение контекста изображения
}
Complex_F::Complex_F(int new_x, int new_y, int new_a){
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
