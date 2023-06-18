#include <iostream>
#include "water.hpp"

int main()
{
    // ocean tixo("tixii", "posredi", 20, 300);
    ocean tixo;
    std::cin >> tixo;
    // sea s1("cher", "ra", 30, 20);
    sea s1;
    std::cin >> s1;
    sea s2("more2", "daleko", 90, 40);
    tixo.add_sea(s1);
    tixo.add_sea(s2);
    std::cout << "-------------------\n";
    std::cout << tixo;
    bay b1("bay1", "nedaleko", 20, 40);
    s1.add_bay(b1);
    s1.add_bay(b1);
    std::cout << "-------------------\n";
    std::cout << s1;
    std::cout << "-------------------\n";
    std::cout << s2;
    std::cout << "-------------------\n";
    std::cout << b1;
    bay b2;
    std::cin >> b2;
    s1.add_bay(b2);
    std::cout << "-------------------\n";
    std::cout << b2;
    std::cout << "-------------------\n";
    std::cout << s1;
}