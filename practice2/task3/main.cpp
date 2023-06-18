#include <iostream>
#include "rational.h"

int main()
{
    int n;
    std::cout << "Введите число элементов" << "\n";
    std::cin >> n;
    rational * array_r = new rational[n];
    // проверка +
    std::cout << "Проверка +" << "\n";
    for(int i = 0; i < n; i++)
    {
        array_r[i].set(i, i*i + i);
        array_r[i].show();
        array_r[0] = array_r[0] + array_r[i];
    }

    std::cout << "Сумма:" << "\n";
    array_r[0].show();
    // проверка -
    std::cout << "Проверка -" << "\n";
    for(int i = 0; i < n; i++)
    {
        array_r[i].set(i, i*i + i);
        array_r[i].show();
        array_r[0] = array_r[0] - array_r[i];
    }

    std::cout << "Вычитание:" << "\n";
    array_r[0].show();
    // проверка ++
    std::cout << "Проверка ++" << "\n";
    for(int i = 2; i < n; i++)
    {
        array_r[i].set(i, i*i + i);
        array_r[i].show();
        ++array_r[i];
        array_r[i].show();
    }

    // проверка ==
    std::cout << "Проверка ==" << "\n";
    std::cout << (array_r[3] == array_r[3]) << "\n";
    std::cout << (array_r[3] == array_r[4]) << "\n";
    

    // проверка >
    std::cout << "Проверка >" << "\n";
    std::cout << (array_r[3] > array_r[3]) << "\n";
    std::cout << (array_r[3] > array_r[4]) << "\n";
    std::cout << (array_r[4] > array_r[3]) << "\n";


    // проверка =
    std::cout << "Проверка =" << "\n";
    array_r[0].show();
    array_r[3].show();
    array_r[0] = array_r[3];
    array_r[0].show();
    
    delete[] array_r;
    
}