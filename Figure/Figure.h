#pragma once
#include <iostream>
#include <windows.h>
#include<windowsx.h>
#include<stack>
using namespace std;

const int NotUsed = system("color F0");// ���� ���� ����

class Figure {// ������� �����
protected:
	int x;//�������� ������� ������������
	int y;//�������� ������� ������������
	int a;// ������� ��������������� ������������
	RECT rt;// �������������
public:
	virtual void show();//��������
	virtual void hide();//������
	void moveto(int, int);// ����������� ������

	class Border {};//��� ��������� ����������
};
class Rectangl :public Figure {//�������������
private:
	int lx, ly, rx, ry;//l - ����� ������ ����, r - ������ ������� ����
public:
	Rectangl() {
		x = 0;
		y = 0;
		a = 0;
	}
	Rectangl(int new_x, int new_y, int new_a);//����������� � �����������, ��������� �������������
	void show() override;//override - ��� ��������������� ����������� ������� �������� ������
	void hide() override;
};

class Triangle:public Figure {//�����������
private:
	int ax, ay, bx, by;//a - ������ ����� ���� ����������, b - ������ ������ ���� ������������ 
public:
	Triangle() {
		x = 0;
		y = 0;
		a = 0;
	}
	Triangle(int new_x, int new_y, int new_a);//����������� � �����������, ��������� �����������
	void show()override;
	void hide()override;
};
class Complex_F :public Figure
{
private:
	Rectangl rectangl;
	Triangle triangle;
public:
	Complex_F(int new_x, int new_y, int new_a);//����������� � �����������, ��������� ������� ������
	void show()override;
	void hide()override;
};