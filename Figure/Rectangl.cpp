#include"Figure.h"

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