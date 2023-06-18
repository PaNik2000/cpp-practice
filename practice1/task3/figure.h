

// класс фигуры для прямоугольника, квадрата и ромба
class Figure
{
private:
    float x1, x2, x3, x4;
    float y1, y2, y3, y4;
    float S;
    float P;

    bool is_paral();

public:
    Figure() = default;

    Figure(float, float, float, float, float, float, float, float);

    void show();

    bool is_rectangle();

    bool is_square();

    bool is_rhombus();

    bool is_in_circle();

    bool is_out_circle();

};