#ifndef CAKE_H
#define CAKE_H
#include <iostream>

class Cake
{
private:
    int _price = -1;
    int _sweet = -1;
    
    static int _total_cake_count;
    
public:

    Cake() = delete;
    virtual ~Cake()
    {
        _total_cake_count--;
    }
    Cake(int price, int sweet)
    {
        _price = price;
        _sweet = sweet;
        _total_cake_count++;
    }

    int get_price()
    {
        return _price;
    }
    int get_sweet()
    {
        return _sweet;
    }
    static int get_total()
    {
        return _total_cake_count;
    }
    virtual std::string to_string() = 0;
};


int Cake::_total_cake_count = 0;


#endif