#pragma once
#include <iostream>
#include <windows.h>
#include<windowsx.h>
#include<stack>
using namespace std;

const int NotUsed = system("color F0");// цвет фона окна

class Figure {// базовый класс
protected:
	int x;//абсцисса вершины треугольника
	int y;//ордината вершины треугольника
	int a;// сторона равностороннего треугольника
	RECT rt;// прямоугольник
public:
	virtual void show();//показать
	virtual void hide();//скрыть
	void moveto(int, int);// переместить фигуру

	class Border {};//для обработки исключений
};
class Rectangl :public Figure {//прямоугольник
private:
	int lx, ly, rx, ry;//l - левый нижний угол, r - правый верхний угол
public:
	Rectangl() {
		x = 0;
		y = 0;
		a = 0;
	}
	Rectangl(int new_x, int new_y, int new_a);//конструктор с параметрами, задающими прямоугольник
	void show() override;//override - для переопределения виртуальной функции базового класса
	void hide() override;
};

class Triangle:public Figure {//треугольник
private:
	int ax, ay, bx, by;//a - нижний левый угол треульника, b - нижний правый угол треугольника 
public:
	Triangle() {
		x = 0;
		y = 0;
		a = 0;
	}
	Triangle(int new_x, int new_y, int new_a);//конструктор с параметрами, задающими треугольник
	void show()override;
	void hide()override;
};
class Complex_F :public Figure
{
private:
	Rectangl rectangl;
	Triangle triangle;
public:
	Complex_F(int new_x, int new_y, int new_a);//конструктор с параметрами, задающими сложную фигуру
	void show()override;
	void hide()override;
};