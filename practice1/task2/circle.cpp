#include "circle.h"
#include <cmath>

Circle::Circle(float r, float x, float y)
{
    radius = r;
    x_center = x;
    y_center = y;
}

void Circle::set_circle(float r, float x, float y)
{
    radius = r;
    x_center = x;
    y_center = y;
}

float Circle::square()
{
    return M_PI * radius * radius;
}

bool Circle::triangle_around(float a, float b, float c)
{
    double p = (a + b + c) / 2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    double r = (a * b * c)/(4 * s);
    double eps = 0.01;
    // std::cout << r << " " << radius << "\n" << std::abs(r - radius) << "\n";
    if (std::abs(r - radius) <= eps) return true;
    return false;
}

bool Circle::triangle_in(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    float s = sqrt(p*(p-a)*(p-b)*(p-c));
    float r = s/p;
    double eps = 0.01;
    // std::cout << r << " " << radius << "\n" << std::abs(r - radius) << "\n";
    if (std::abs(r - radius) <= eps) return true;
    return false;
}

bool Circle::check_circle(float r, float x_cntr, float y_cntr)
{
    float dis = pow(x_center - x_cntr, 2) + pow(y_center - y_cntr, 2);
    dis = sqrt(dis);
    if (dis > (radius+r)) return false;
    return true;
}

// протестировать
