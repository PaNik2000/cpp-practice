#include <iostream>
#include <set>

int main()
{
    std::set<int> num;
    try
    {
        if (num.empty()) throw std::string("Пустое множество");
        std::cout << num.count(10) << "\n";
    }
    catch (std::string err)
    {
        std::cout << err << "\n";
        num.insert(10);
        std::cout << num.count(10) << "\n";
    }
}