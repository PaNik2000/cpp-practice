#include <iostream>
#include <cmath>

using namespace std;

class Triangle
{
public:
    double a, b, c;

    Triangle() = default;
    
    Triangle(double a, double b, double c);

    bool exst_tr();

    void set(double a, double b, double c);

    void show();

    double perimeter();

    double square();
};
