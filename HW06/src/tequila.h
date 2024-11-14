#ifndef TEQUILA_H
#define TEQUILA_H
#include "alcohol.h"

class Tequila : public Alcohol
{
private:
    /* data */
public:
    Tequila() : Alcohol(){};
    ~Tequila() override{};
    Tequila(std::string name, int price, double content) : Alcohol(name, price, content){};
    void dilute()
    {
        _content -= 0.05;
    }
    Tequila operator+(const Tequila&other)
    {
        return Tequila(_name, _price + other._price, (_content + other._content)/2);
    }
    bool operator==(const Tequila &other)
    {
        if(_name == other._name && _price == other._price && _content == other._content)
        {
            return true;
        }
        return false;
    }
    Tequila &operator=(const Tequila &other)
    {
        _name = other._name;
        _price = other._price;
        _content = other._content;
        return *this;
    }
};

#endif