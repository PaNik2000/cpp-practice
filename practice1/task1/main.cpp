#include <iostream>
#include <cmath>
#include "triangle.h"

using namespace std;

int main()
{
	Triangle arr[3];
	double abc[3];
	for (int i = 0; i<3; i++)
	{
		cout << "Введите стороны " << i+1 << " треугольника:";
		cin >> abc[0] >> abc[1] >> abc[2];
		arr[i].set(abc[0], abc[1], abc[2]);
		if (!arr[i].exst_tr())
		{
			cout << "Треугольник с данными сторонами не существует\n";
			i--;
		}
	}
	for (int i = 0; i<3; i++)
	{
		arr[i].show();
		cout << "Периметр:" << arr[i].perimeter() <<'\n' << "Площадь:" << arr[i].square() << '\n';
	}
}
