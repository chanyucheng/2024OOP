#ifndef SANDWICH_H
#define SANDWICH_H

#include <iostream>
#include <set>

class Sandwich
{
private:
    int _price = -1;
    int _id = -1;
    static std::set<int> _container;
public:
    Sandwich() = delete;
    Sandwich(int price, int id)
    {
        if(price < 0) throw std::invalid_argument("price can not be negative!!");
        _price = price;
        _id = id;
        _container.insert(id);
    }
    int get_price() const
    {
        return _price;
    }
    int get_id() const
    {
        return _id;
    }
    static bool record_has_specific_id(int id)
    {
        return _container.find(id) != _container.end();
    }
    static int get_size_of_record_container()
    {
        return _container.size();
    }
    virtual ~Sandwich()
    {
        _container.erase(this->_id);
    }
};

std::set<int> Sandwich::_container;

#endif