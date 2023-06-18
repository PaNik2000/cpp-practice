

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

class frustum: public cone
{
public:
    double radius_h;

    frustum();
    
    frustum(double, double, double);

    frustum(double, double, double, double, double, double);

    void set(double, double, double, double, double, double);

    double square();

    double volume();    

    bool operator >(frustum&);

    bool operator <(frustum&);
    
    bool operator ==(frustum&);
};

std::ostream& operator <<(std::ostream&, frustum&);

std::istream& operator >>(std::istream&, frustum&);
