#ifndef HONEY_CAKE_H
#define HONEY_CAKE_H
#include "cake.h"
#include <iostream>


class HoneyCake : public Cake
{
public:
    HoneyCake() = delete;
    HoneyCake(int price, int sweet) : Cake(price, sweet)
    {
        _count++;
    }

    ~HoneyCake() override
    {
        _count--;
    }

    std::string to_string() override
    {
        sprintf(_str, "| HoneyCake            |         %d |         %d |",this->get_price(), this->get_sweet());
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

int HoneyCake::_count = 0;

#endif