
class rational
{
private:
    int integer_part;
    int a, b;

    static int euclid(int, int);

public:

    rational() = default;

    rational(int, int);

    void set(int, int);

    void show();

    void show_int();

    rational operator +(const rational&);

    friend rational operator -(const rational&, const rational&);

    rational& operator ++();

    bool operator ==(const rational&);

    bool operator >(const rational&);

    rational& operator =(const rational&);
};