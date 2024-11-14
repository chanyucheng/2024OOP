#ifndef ALCOHOL_H
#define ALCOHOL_H
#include <iostream>
// #include <stdexcept>

using namespace std;

class Alcohol
{
public:
    Alcohol() = default;
    virtual ~Alcohol(){};
    Alcohol(std::string name, int price, double content)
    {
        if(name.size() == 0) throw std::invalid_argument("Alcohol name can't be empty!");
        if(price < 0) throw std::invalid_argument("Alcohol price can't be negative!");
        if(content > 1.0 || content < 0.0) throw std::invalid_argument("Alcohol content should be [0,1]");

        _name = name;
        _price = price;
        _content = content;
    }
    double get_alcohol_content()
    {
        return _content;
    }
    int get_price()
    {
        return _price;
    }
    std::string get_name()
    {
        return _name;
    }
    virtual void dilute() = 0;
protected:
    std::string _name = "";
    int _price = -1;
    double _content = -1;
};
#endif