#ifndef BEEF_SANDWICH_H
#define BEEF_SANDWICH_H

#include <iostream>
#include <set>
#include "sandwich.h"

class BeefSandwich : public Sandwich
{
private:
    static std::set<int> _container;
public:
    BeefSandwich() = delete;
    BeefSandwich(int price, int id) : Sandwich(price, id)
    {
        this->_container.insert(id);
    }
    static bool record_has_specific_id(int id)
    {
        return _container.find(id) != _container.end();
    }
    static int get_size_of_record_container()
    {
        return _container.size();
    }
    ~BeefSandwich() override
    {
        _container.erase(this->get_id());
    }
};

std::set<int> BeefSandwich::_container;

#endif