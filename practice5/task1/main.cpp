#include <iostream>

int main()
{
    int a = 100;
    int b = 0;
    try
    {
        if (b==0) throw std::string("Деление на ноль");
    }
    catch (std::string err)
    {
        std::cout << "Ошибка - " << err << "\n";
        std::cout << "Деление на ноль, b заменено на 1\n";
        b = 1;
    }
    std::cout << a/b << "\n";
}