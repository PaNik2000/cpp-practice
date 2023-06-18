#include "figure.h"
#include <cmath>
#include <iostream>

// точки вводятся последовательно по часовой стрелке
Figure::Figure(float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4)
{
    this->x1 = x1;
    this->x2 = x2;
    this->x3 = x3;
    this->x4 = x4;
    this->y1 = y1;
    this->y2 = y2;
    this->y3 = y3;
    this->y4 = y4;

    double ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    double cd = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
    double da = sqrt(pow((x1 - x4), 2) + pow((y1 - y4), 2));
    
    P = ab + bc + cd + da;

    if (is_rectangle())
    {
        S = ab * bc;
    }
    else if (is_rhombus())
    {
        double ac = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
        double bd = sqrt(pow((x4 - x2), 2) + pow((y4 - y2), 2));
        S = ac * bd / 2;
    }
    else S=0;
}

void Figure::show()
{
    if (is_square())
    {
        std::cout << "Это квадрат" << "\n";
    }
    else if (is_rhombus())
    {
        std::cout << "Это ромб" << "\n";
    }
    else if (is_rectangle())
    {
        std::cout << "Это прямоугольник" << "\n";
    }
    else
    {
        std::cout << "Это ни квадрат, ни ромб и не прямоугольник" << "\n";
    }

    std::cout << "x: " << x1 << ", " << x2 << ", " << x3 << ", " << x4 << "\n";
    std::cout << "y: " << y1 << ", " << y2 << ", " << y3 << ", " << y4 << "\n";
    std::cout << "Периметр: " << P << "\n";
    std::cout << "Площадь: " << S << "\n";
    
    if (is_in_circle())
    {
        std::cout << "Окружность может быть описана около фигуры" << "\n";
    }
    if (is_out_circle())
    {
        std::cout << "Окружность можно вписать в фигуру" << "\n";
    }
    

}

bool Figure::is_paral()
{
    double ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    double cd = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
    double da = sqrt(pow((x1 - x4), 2) + pow((y1 - y4), 2));

    // std::cout << ab << " " << bc << " " << cd << " " << da << "\n";

    // std::cout << ab + bc + cd + da << "\n";

    double kx1 = (x2 - x1);
    double ky1 = (y2 - y1);
    double kx2 = (x3 - x2);
    double ky2 = (y3 - y2);
    double kx3 = (x3 - x4);
    double ky3 = (y3 - y4);
    double kx4 = (x4 - x1);
    double ky4 = (y4 - y1);
    
    
    // double k2 = (y3 - y2)/(x3 - x2);
    // double k3 = (y4 - y3)/(x4 - x3);
    // double k4 = (y1 - y4)/(x1 - x4);

    // std::cout << kx1 << " " << ky1 << " " << kx3 << " " << ky3 << "\n";
    // std::cout << kx2 << " " << ky2 << " " << kx4 << " " << ky4 << "\n";
    
    if (ab == cd && bc == da)
    {
        if (kx1 == kx3 && ky1 == ky3 && kx2 == kx4 && ky2 == ky4) return 1;
    }
    return 0;
}

bool Figure::is_rhombus()
{
    if (!is_paral()) return 0;
    double ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    double bc = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    double cd = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
    double da = sqrt(pow((x1 - x4), 2) + pow((y1 - y4), 2));
    if (ab == bc && bc == cd && cd && da) return 1;
    return 0;
}

bool Figure::is_rectangle()
{
    if (!is_paral()) return 0;
    double ac = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
    double bd = sqrt(pow((x4 - x2), 2) + pow((y4 - y2), 2));
    // std::cout << ac << " " << bd << "\n";
    if (ac == bd) return 1;
    return 0;
}


bool Figure::is_square()
{
    if (is_rhombus() && is_rectangle()) return 1;
    return 0;
}

bool Figure::is_in_circle()
{
    if (is_rectangle()) return 1;
    return 0;
}

bool Figure::is_out_circle()
{
    if (is_rhombus()) return 1;
    return 0;
}
