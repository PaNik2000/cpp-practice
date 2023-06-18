#include <iostream>
#include "water.hpp"

water::water(std::string n, std::string l, double s, double d)
{
    name = n;
    location = l;
    size = s;
    depth = d;
}

ocean::ocean(std::string n, std::string l, double s, double d): water(n, l, s, d)
{
    type = "Океан";
}

void ocean::add_sea(sea *sea_ptr)
{
    if(!head)
    {
        head = new list_sea;
        head->begin = head;
        head->next = nullptr;
        head->sea_o = sea_ptr;
        count_sea++;
    }
    else
    {
        head->next = new list_sea;
        head->next->begin = head->begin;
        head = head->next;
        head->next = nullptr;
        head->sea_o = sea_ptr;
        count_sea++;
    }
}

void ocean::add_sea(sea& sea_o)
{
    add_sea(&sea_o);
}

ocean::~ocean()
{
    if (head)
    {
        head = head->begin;
        list_sea *next_ptr;
        while(head->next)
        {
            next_ptr = head->next;
            delete head;
            head = next_ptr;
        }
        delete head;
    }
}

sea::sea(std::string n, std::string l, double s, double d): water(n, l, s, d)
{
    type = "Море";
}

void sea::add_bay(bay *bay_ptr)
{
    if(!head)
    {
        head = new list_bay;
        head->begin = head;
        head->next = nullptr;
        head->bay_o = bay_ptr;
        count_bay++;
    }
    else
    {
        head->next = new list_bay;
        head->next->begin = head->begin;
        head = head->next;
        head->next = nullptr;
        head->bay_o = bay_ptr;
        count_bay++;
    }
}

void sea::add_bay(bay& bay_o)
{
    add_bay(&bay_o);
}

sea::~sea()
{
    if(head)
    {
        head = head->begin;
        list_bay *next_ptr;
        while(head->next)
        {
            next_ptr = head->next;
            delete head;
            head = next_ptr;
        }
        delete head;
    }
}

bay::bay(std::string n, std::string l, double s, double d): water(n, l, s, d)
{
    type = "Залив";
}

std::ostream& operator <<(std::ostream& stream, ocean& second)
{
    std::cout << "Название: " << second.name << "\n";
    std::cout << "Местоположение: " << second.location << "\n";
    std::cout << "Тип: " << second.type << "\n";
    std::cout << "Глубина: " << second.depth << "\n";
    std::cout << "Размер: " << second.size << "\n";
    std::cout << "Количество морей: " << second.count_sea << "\n";
    std::cout << "Входящие моря: \n";
    if(second.head)
    {
        list_sea *next = second.head->begin;
        int count = 1;
        while(next->next)
        {
            std::cout << count << "." << next->sea_o->name << "\n";
            next = next->next;
            count++;
        }
        std::cout << count << "." << next->sea_o->name << "\n";
    }
    return stream;
}

std::istream& operator >>(std::istream& stream, ocean& second)
{
    std::cout << "Введите данные для океана\n";
    std::string n;
    std::string l;
    double s;
    double d;
    stream >> n >> l >> s >> d;
    second.name = n;
    second.location = l;
    second.size = s;
    second.depth = d;
    second.type = "Океан";
    return stream;
}

std::ostream& operator <<(std::ostream& stream, sea& second)
{
    std::cout << "Название: " << second.name << "\n";
    std::cout << "Местоположение: " << second.location << "\n";
    std::cout << "Тип: " << second.type << "\n";
    std::cout << "Глубина: " << second.depth << "\n";
    std::cout << "Размер: " << second.size << "\n";
    std::cout << "Количество заливов: " << second.count_bay << "\n";
    std::cout << "Входящие заливы: \n";
    if (second.head)
    {
        list_bay *next = second.head->begin;
        int count = 1;
        while(next->next)
        {
            std::cout << count << "." << next->bay_o->name << "\n";
            next = next->next;
            count++;
        }
        std::cout << count << "." << next->bay_o->name << "\n";
    }
    return stream;
}

std::istream& operator >>(std::istream& stream, sea& second)
{
    std::cout << "Введите данные для моря\n";
    std::string n;
    std::string l;
    double s;
    double d;
    stream >> n >> l >> s >> d;
    second.name = n;
    second.location = l;
    second.size = s;
    second.depth = d;
    second.type = "Море";
    return stream;
}

std::ostream& operator <<(std::ostream& stream, bay& second)
{
    std::cout << "Название: " << second.name << "\n";
    std::cout << "Местоположение: " << second.location << "\n";
    std::cout << "Тип: " << second.type << "\n";
    std::cout << "Глубина: " << second.depth << "\n";
    std::cout << "Размер: " << second.size << "\n";
    return stream;
}

std::istream& operator >>(std::istream& stream, bay& second)
{
    std::cout << "Введите данные для залива\n";
    std::string n;
    std::string l;
    double s;
    double d;
    stream >> n >> l >> s >> d;
    second.name = n;
    second.location = l;
    second.size = s;
    second.depth = d;
    second.type = "Залив";
    return stream;
}
