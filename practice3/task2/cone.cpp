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

frustum::frustum(): cone()
{
    radius_h = 0;
}

frustum::frustum(double r, double h, double r2): cone(r, h)
{
    radius_h = r2;
}

frustum::frustum(double a, double b, double c, double r, double h, double r2): cone(a, b, c, r, h)
{
    radius_h = r2;
}

void frustum::set(double a, double b, double c, double r, double h, double r2)
{
    cone::set(a, b, c, r, h);
    radius_h = r2;
}

double frustum::square()
{
    // double Sbok = cone::square() - (M_PI * radius * radius);
    // Sbok = Sbok + Sbok * radius_h / radius;
    // double S = Sbok + M_PI * radius * radius + M_PI * radius_h * radius_h;
    // return S;
    double L = std::sqrt(height * height + std::pow(radius - radius_h, 2));
    double Sbok = M_PI * L * (radius + radius_h);
    double S = Sbok + M_PI * (radius * radius + radius_h * radius_h);
    return S;
}

double frustum::volume()
{
    double V = cone::volume();
    V += (radius * radius_h + radius_h * radius_h) * M_PI * height / 3;
    return V;
}

std::ostream& operator <<(std::ostream& stream, frustum& second)
{
    stream << "Конус" << "\n";
    stream << "Координаты центра основания x: " << second.x << " y: " << second.y 
    << " z: " << second.z << "\n"; 
    stream << "Высота: " << second.height << " Радиус: " << second.radius
    << " Второй радиус: " << second.radius_h << "\n";
    stream << "Площадь поверхности: " << second.square() << " Объем: " << second.volume() << "\n";
    return stream;
}

std::istream& operator >>(std::istream& stream, frustum& second)
{
    std::cout << "Введите параметры усеченного конуса:\n";
    double a, b, c, r, h, r2;
    stream >> a >> b >> c >> r >> h >> r2;
    second.set(a, b, c, r, h, r2);
    return stream;
}

bool frustum::operator >(frustum& second)
{
    return (square() > second.square()) && (volume() > second.volume());
}

bool frustum::operator <(frustum& second)
{
    return (square() < second.square()) && (volume() < second.volume());
}

bool frustum::operator ==(frustum& second)
{
    bool a = (square() >= second.square()) && (volume() <= second.volume());
    bool b = (square() <= second.square()) && (volume() >= second.volume());
    return a || b;
}

