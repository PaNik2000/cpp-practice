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
    int flag = 1;
    if (a < 0)
    {
        a = a * -1;
        flag = -1;
    }
    if (b == 0) b = 1;
    integer_part = a / b;
    a = a - (integer_part * b);
    int nod = euclid(a, b);
    a = a / nod;
    b = b / nod;
    this->a = a * flag;
    this->b = b;
}

void rational::show()
{
    if (integer_part != 0)
    std::cout /*<< integer_part << " " */<< a << "/" << b << "\n";
    else 
    std::cout << a << "/" << b << "\n";
}

void rational::show_int()
{
    std::cout << integer_part << "\n";
}


rational rational::operator +(const rational& second)
{
    rational tmp;
    int nok = (this->b * second.b) / euclid(this->b, second.b);
    tmp.set((this->a * (nok / this->b) + second.a * (nok / second.b)), nok);
    tmp.integer_part += this->integer_part + second.integer_part;
    return tmp;
}

rational operator -(const rational& first, const rational& second)
{
    rational tmp;
    int nok = (first.b * second.b) / rational::euclid(first.b, second.b);
    tmp.set((first.a * (nok / first.b) - second.a * (nok / second.b)), nok);
    return tmp;
}

rational& rational::operator++()
{
    this->set(this->a+1, this->b);
    return *this;
}

bool rational::operator ==(const rational& second)
{
    return this->a == second.a && this->b == second.b;
}

bool rational::operator >(const rational& second)
{
    int nok = (this->b * second.b) / euclid(this->b, second.b);
    return this->a * (nok / this->b) > second.a *(nok / second.b);
}

rational& rational::operator =(const rational& second)
{
    integer_part = second.integer_part;
    a = second.a;
    b = second.b;
    return *this;
}