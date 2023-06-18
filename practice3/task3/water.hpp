class water;
class sea;
class bay;

struct list_sea
{
    sea *sea_o = nullptr;
    list_sea *begin = nullptr;
    list_sea *next = nullptr;
};

struct list_bay
{
    bay *bay_o = nullptr;
    list_bay *begin = nullptr;
    list_bay *next = nullptr;
};


class water
{
public:
    std::string name;
    std::string location;
    double size;
    double depth;
    std::string type;

    water() = default;

    water(std::string, std::string, double, double);
};

class ocean: public water
{
public:
    int count_sea = 0;

    list_sea *head = nullptr;

    ocean() = default;

    ocean(std::string, std::string, double, double);

    void add_sea(sea *);

    void add_sea(sea&);

    ~ocean();
};

class sea: public water
{
public:
    int count_bay = 0;

    list_bay *head = nullptr;

    sea() = default;

    sea(std::string, std::string, double, double);

    void add_bay(bay *);

    void add_bay(bay&);

    ~sea();
};

class bay: public water
{
public:
    bay() = default;    

    bay(std::string, std::string, double, double);
};

std::ostream& operator <<(std::ostream&, ocean&);

std::istream& operator >>(std::istream&, ocean&);

std::ostream& operator <<(std::ostream&, sea&);

std::istream& operator >>(std::istream&, sea&);

std::ostream& operator <<(std::ostream&, bay&);

std::istream& operator >>(std::istream&, bay&);

