#include"Figure.h"

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
	cout << "triangle: " << points[0].x;
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