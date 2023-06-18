
class rational
{
private:
    int integer_part;
    int a, b;

    int euclid(int, int);

public:

    rational() = default;

    rational(int, int);

    void set(int, int);

    void show();

};