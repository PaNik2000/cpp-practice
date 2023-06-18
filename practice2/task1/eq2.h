

class eq2
{
private:
    double a, b, c;
    double D;

public:

    eq2() = default;

    eq2(double, double, double);

    void set(double, double, double);

    void show();

    double find_X();

    double find_Y(double);

    eq2 operator +(const eq2);
};