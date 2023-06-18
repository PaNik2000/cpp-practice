#include "rational.h"
#include <iostream>

int main()
{
    rational r1(100,3);
    r1.show();

    int n;
    std::cout << "Введите число элементов" << "\n";
    std::cin >> n;

    rational *array_r = new rational[n];

    for (int i = 0; i < n; i++)
    {
        array_r[i].set(i, i*i + i);
        array_r[i].show();
    }

    delete[] array_r;
}