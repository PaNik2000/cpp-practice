#include <iostream>
#include <cmath>
#include "cone.h"


cone::cone()
{
    x = 0;
    y = 0;
    z = 0;
    radius = 0;
    height = 0;
}

cone::cone(double r, double h)
{
    radius = r;
    height = h;
}

cone::cone(double a, double b, double c, double r, double h)
{
    x = a;
    y = b;
    z = c;
    radius = r;
    height = h;
}

void cone::set(double a, double b, double c, double r, double h)
{
    x = a;
    y = b;
    z = c;
    radius = r;
    height = h;
}

double cone::square()
{
    double l = std::sqrt(std::pow(height, 2) + std::pow(radius, 2));
    double S = M_PI * radius * (l + radius);
    return S;
}

double cone::volume()
{
    return M_PI * radius * radius * height / 3;
}

std::ostream& operator <<(std::ostream& stream, cone& second)
{
    stream << "Конус" << "\n";
    stream << "Координаты центра основания x: " << second.x << " y: " << second.y 
    << " z: " << second.z << "\n"; 
    stream << "Высота: " << second.height << " Радиус: " << second.radius << "\n";
    stream << "Площадь поверхности: " << second.square() << " Объем: " << second.volume() << "\n";
    return stream;
}
