#include <iostream>
#include "circle.h"

using namespace std;

int main()
{
    // 1.155
    // 0.577
    Circle c(0.577, 20, 20);
    Circle c2(1.155, 20, 20); 
    cout << c.triangle_around(2,2,2) << '\n';
    cout << c.triangle_in(2,2,2) << '\n';
    cout << c2.triangle_around(2,2,2) << '\n';
    cout << c2.triangle_in(2,2,2) << '\n';
}