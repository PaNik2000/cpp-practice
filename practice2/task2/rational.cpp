#include "rational.h"
#include <iostream>


int rational::euclid(int a, int b)
{
    while (a!=0 && b!=0)
    {
        if (a>b) a = a % b;
        else b = b % a;
    }
    return a + b;
}


rational::rational(int a, int b)
{
    set(a, b);
}

void rational::set(int a, int b)
{
    if (b == 0) b = 1;
    integer_part = a / b;
    a = a - (integer_part * b);
    int nod = euclid(a, b);
    a = a / nod;
    b = b / nod;
    this->a = a;
    this->b = b;
}

void rational::show()
{
    std::cout << a << "/" << b << "\n";
}