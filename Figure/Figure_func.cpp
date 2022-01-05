#include"Figure.h"

void Figure:: show(){}
void Figure:: hide(){}
void Figure:: moveto(int new_x, int new_y) {
	hide();
	x = new_x;
	y = new_y;
	show();
}

Triangle::Triangle(int new_x, int new_y, int new_a) {//����������� � �����������
	x = new_x;// ���������� ��������� ���������
	y = new_y;
	a = new_a;
	ax = x - a / 2;	//������ ��������� ��� ����������    //���������� ������� ������ ���� 
	ay = y + ((1.73 * a) / 2);							//
	bx = x + a / 2;
	by = y + ((1.73 * a) / 2);
}
void Triangle::show() {
	HWND hwnd = GetConsoleWindow();//�������� ������������� ����
	HDC hdc = GetDC(hwnd);//�������� �������� �����������
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));//������� ����
	HBRUSH brush = CreateSolidBrush(RGB(0, 255, 255));//������� �����
	GetClientRect(hwnd, &rt);//�������� ������ ����
	SelectObject(hdc, pen);//��������� ���� ��� ���������
	SelectObject(hdc, brush);//��������� ����� ��� ���������
	//��������� ���������� ��� ����������
	ax = x - a / 2;
	ay = y + ((1.73 * a) / 2);							
	bx = x + a / 2;
	by = y + ((1.73 * a) / 2);
	if ((ax <= rt.left) ||
		(y <= rt.top) || (bx >= rt.right)
		|| (by >= rt.bottom))throw Border();//������������ ������ �� ������� ����
	POINT points[] = { {bx, by}, {x, y}, {ax, ay} };
	Polygon(hdc, points, 3);// ������ �����������
	//����������� �������
	DeleteObject(pen);
	DeleteObject(brush);
	DeletePen(pen);//�������� ����
	DeleteBrush(brush);//�������� �����
	ReleaseDC(hwnd, hdc);//������������ ��������� �����������
	//cout << "A: " << ax << ',' << ay << endl;
	//cout << "B: " << bx << ',' << by << endl;
}

void Triangle::hide() {
	HWND hwnd = GetConsoleWindow();//�������� ������������� ����
	HDC hdc = GetDC(hwnd);//�������� �������� �����������
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));//������� ����
	HBRUSH brush = CreateSolidBrush(RGB(242, 242, 242));//������� �����
	GetClientRect(hwnd, &rt);//�������� ������ ����
	SelectObject(hdc, pen);//��������� ���� ��� ���������
	SelectObject(hdc, brush);//��������� ����� ��� ���������
	POINT points[] = { {bx, by}, {x, y}, {ax, ay} };
	Polygon(hdc, points, 3);// ������ �����������
	//����������� �������
	DeleteObject(pen);
	DeleteObject(brush);
	DeletePen(pen);//�������� ����
	DeleteBrush(brush);//�������� �����
	ReleaseDC(hwnd, hdc);//������������ ��������� �����������
}
Rectangl::Rectangl(int new_x, int new_y, int new_a) {
	x = new_x;
	y = new_y;										
	a = new_a;
	rx = x + a / 4;//������ ������� ����
	ry = y + ((1.73 * a) / 4);//-
	lx = x - a / 4;//����� ������ ����
	ly = y + ((1.73 * a) / 2);//-

}
void Rectangl::show() {
	HWND hwnd = GetConsoleWindow();//�������� ������������� ����
	HDC hdc = GetDC(hwnd);//�������� �������� �����������
	HPEN Bpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));//������� ����
	HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 255));//������� �����
	GetClientRect(hwnd, &rt);//�������� ������ ����
	SelectObject(hdc, Bpen);//��������� ���� ��� ���������
	SelectObject(hdc, hbrush);//��������� ����� ��� ���������
	//��������� ���������� ��� ����������
	rx = x + a / 4;
	ry = y + ((1.73 * a) / 4);
	lx = x - a / 4;
	ly = y + ((1.73 * a) / 2);
	if ((lx <= rt.left) ||
		(ry <= rt.top) || (rx >= rt.right)
		|| (ly >= rt.bottom))throw Border();//������������ ������ �� ������� ����
	Rectangle(hdc, lx, ly, rx, ry);// ������ ������������
	//����������� �������
	DeleteObject(Bpen);
	DeleteObject(hbrush);
	DeletePen(Bpen);//�������� ����
	DeleteBrush(hbrush);//�������� �����
	ReleaseDC(hwnd, hdc);//������������ ��������� �����������
	//cout << "L: " << lx << ',' << ly << endl;
	//cout << "R: " << rx << ',' << ry << endl;
}
void Rectangl::hide() {
	HWND hwnd = GetConsoleWindow();//�������� ������������� ����
	HDC hdc = GetDC(hwnd);//�������� �������� �����������
	HPEN Bpen = CreatePen(PS_SOLID, 2, RGB(242, 242, 242));//������� ����
	HBRUSH hbrush = CreateSolidBrush(RGB(242, 242, 242));//������� �����
	GetClientRect(hwnd, &rt);//�������� ������ ����
	SelectObject(hdc, Bpen);//��������� ���� ��� ���������
	SelectObject(hdc, hbrush);//��������� ����� ��� ���������
	Rectangle(hdc, lx, ly, rx, ry);// ������ ������������
	//����������� �������
	DeleteObject(Bpen);
	DeleteObject(hbrush);
	DeletePen(Bpen);//�������� ����
	DeleteBrush(hbrush);//�������� �����
	ReleaseDC(hwnd, hdc);//������������ ��������� �����������
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
