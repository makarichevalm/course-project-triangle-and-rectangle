#include"Figure.h"

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
	cout << "triangle: " << points[0].x;
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