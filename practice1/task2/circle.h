
class Circle
{
private:
    float radius;
    float x_center;
    float y_center;
public:
    Circle() = default;

    Circle(float, float, float);

    void set_circle(float, float, float);

    float square();

    bool triangle_around(float, float, float);

    bool triangle_in(float, float, float);

    bool check_circle(float, float, float);
};
