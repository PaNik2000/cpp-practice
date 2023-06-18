#include <iostream>
#include <cmath>
#include "triangle.h"

using namespace std;

Triangle::Triangle(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

bool Triangle::exst_tr()
{
    if (a + b > c)
    {
        if (a + c > b)
        {
            if (b + c > a) return true;
        }
    }
    return false;
}

void Triangle::set(double a, double b, double c)
{
    this->a = a;
    this->b = b;
    this->c = c;
}

void Triangle::show()
{
    cout << "a side is " << a << '\n';
    cout << "b side is " << b << '\n';
    cout << "c side is " << c << '\n';
}

double Triangle::perimeter() {return a+b+c;}

double Triangle::square()
{
    double p = perimeter() / 2;
    double square = p * (p-a) * (p-b) * (p-c);
    square = sqrt(square);
    return square;
}
