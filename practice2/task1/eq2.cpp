#include <iostream>
#include <cmath>
#include "eq2.h"


eq2::eq2(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    D = b * b - 4 * a * c;
}

void eq2::set(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    D = b * b - 4 * a * c;
}

double eq2::find_X()
{
    if (D < 0) return NAN;
    double x1 = (-b + sqrt(D)) / (2 * a);
    double x2 = (-b - sqrt(D)) / (2 * a);
    if (x2 > x1) return x2;
    return x1;
}

double eq2::find_Y(double x)
{
    return a * x * x + b * x + c;
}

eq2 eq2::operator+(const eq2 second)
{
    eq2 copy{*this};
    double a = copy.a + second.a;
    double b = copy.b + second.b;
    double c = copy.c + second.c;
    copy.set(a,b,c);
    return copy;
}

void eq2::show()
{
    std::cout << "a - (" << a << ") " << "b - (" << b << ") " << "c - (" << c << ")\n"; 
}
