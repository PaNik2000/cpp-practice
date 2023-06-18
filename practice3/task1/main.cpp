#include <cmath>
#include <iostream>
#include "cone.h"


int main()
{
    cone c_center(2,5);
    cone c(1,2,3,4,5);
    std::cout << c_center << c;

    cone * c_din = new cone();
    c_din->set(1,2,3,4,5);
    std::cout << *c_din;
    delete c_din;
    cone arr_c[3]{{5,5,5,4,5}, {5,5,5,4,5}, {5,5,5,4,5}};
    for(int i = 0; i < 3; i++)
    {
        std::cout << arr_c[i];
    }
}
