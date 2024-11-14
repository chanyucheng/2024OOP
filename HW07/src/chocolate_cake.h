#ifndef CHOCOLATE_CAKE_H
#define CHOCOLATE_CAKE_H
#include "cake.h"
#include <iostream>


class ChocolateCake : public Cake
{
public:

    ChocolateCake() = delete;
    ChocolateCake(int price, int sweet) : Cake(price, sweet)
    {
        _count++;
    }

    ~ChocolateCake() override
    {
        _count--;
    }

    std::string to_string() override
    {
        sprintf(_str, "| ChocolateCake        |         %d |         %d |",this->get_price(), this->get_sweet());
        return _str;         
    }
    static int get_count()
    {
        return _count;
    }
    

private:
    char _str[50];
    static int _count;
};

int ChocolateCake::_count = 0;

#endif