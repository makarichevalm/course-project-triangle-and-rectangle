#include"Figure.h"

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