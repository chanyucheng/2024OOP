#ifndef SOUR_H
#define SOUR_H
#include "alcohol.h"

class Sour : public Alcohol
{
public:
    Sour() : Alcohol(){};
    virtual ~Sour(){};
    Sour(std::string name, int price, double content) : Alcohol(name, price, content){};
    void dilute()
    {
        _content -= 0.3;
    }
    Sour operator+(const Sour&other)
    {
        Sour s = Sour(_name, _price + other._price, (_content + other._content)/2);
        return s;
    }
    bool operator==(const Sour &other)
    {
        if(_name == other._name && _price == other._price && _content == other._content)
        {
            return true;
        }
        return false;
    }
    Sour &operator=(const Sour &other)
    {
        _name = other._name;
        _price = other._price;
        _content = other._content;
        return *this;
    }
private:

};

#endif