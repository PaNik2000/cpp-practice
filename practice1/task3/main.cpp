#include <iostream>
#include "figure.h"

using namespace std;

int main()
{
    // параллелограмм
    Figure f1(-2,1,0,-3, 0,0,-2,-2);
    // прямоугольник
    Figure f2(2,-1,1,4, -2,1,3,0);
    // ромб
    Figure f3(-3,-4,-3, -2,-2,0,2,0);
    // квадрат
    Figure f4(1,2,1,0, 3,2,1,2);
    
    f1.show();
    f2.show();
    f3.show();
    f4.show();
}