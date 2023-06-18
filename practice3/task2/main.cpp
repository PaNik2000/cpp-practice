#include <iostream>
#include "cone.h"

int main()
{
    frustum c1(0, 0, 0, 20, 5, 10);
    frustum c2(0, 0, 0, 20, 5, 10);
    frustum c3(0, 0, 0, 10, 2, 10);
    std::cout << c1 << c2;
    std::cout << (c1 > c2) << " " << (c1 < c2) << " "  << (c1 == c2) << "\n";
    std::cout << (c1 > c3) << " " << (c1 < c3) << " "  << (c1 == c3) << "\n";
    std::cout << (c3 > c2) << " " << (c3 < c2) << " "  << (c3 == c2) << "\n";
}