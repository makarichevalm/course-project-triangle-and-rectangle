#include"Figure.h"

int main() {
	SetConsoleTitle((LPCWSTR)L"20VP1_18");// заголовок консоли
	setlocale(LC_ALL, "Russian");
	stack<Figure*> st; // создание стека для хранения фигур
	// заполнение стека фигурами
	st.push(reinterpret_cast<Figure*>(new Triangle(200, 200, 100)));
	st.push(reinterpret_cast<Figure*>(new Rectangl(200, 100, 100)));
	st.push(reinterpret_cast<Figure*>(new Complex_F(350, 200, 100)));
	try {
		while (!st.empty()) {
			st.top()->show();
			st.pop();
		}
	}
	catch (Figure::Border) {
		cout << "Выход за границы окна" << endl;
		// обработка исключения выхода за границы окна
	}
	return 0;
}
	//Triangle tr(200, 200, 150);// y должен быть больше а
	//tr.show();
	//tr.moveto(300, 378);
	//tr.hide();
	//Rectangl r(200, 100, 100);
	//r.moveto(300, 350);
	//Complex_F fig(350, 200, 100);
	//fig.moveto(450, 200);
	//fig.hide();
	//fig.moveto(450, 300);
	//system("pause");
	//return 0;
//}