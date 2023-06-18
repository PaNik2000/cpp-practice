

class cone
{
public:
    double x, y, z;
    double radius;
    double height;

    cone();

    cone(double, double);

    cone(double, double, double, double, double);

    void set(double, double, double, double, double);

    // void show();

    double square();

    double volume();

};

std::ostream& operator <<(std::ostream&, cone&);
