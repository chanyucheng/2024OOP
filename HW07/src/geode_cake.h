#ifndef GEODE_CAKE_H
#define GEODE_CAKE_H
#include "cake.h"
#include <iostream>


class GeodeCake : public Cake
{
public:
    GeodeCake() = delete;
    GeodeCake(int price, int sweet) : Cake(price, sweet)
    {
        _count++;
    }

    ~GeodeCake() override
    {
        _count--;
    }

    std::string to_string() override
    {
        sprintf(_str, "| GeodeCake            |         %d |         %d |",this->get_price(), this->get_sweet());
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

int GeodeCake::_count = 0;

#endif