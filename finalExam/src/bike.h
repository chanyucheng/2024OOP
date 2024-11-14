#ifndef BIKE_H
#define BIKE_H

#include <iostream>
#include <string>

class Bike
{
private:
    int _id = -1;
    int _rent_price = -1;
public:
    Bike() = delete;
    virtual ~Bike() = default;
    Bike(int ID, int rent_price)
    {
        if(rent_price < 0) throw  std::invalid_argument("rent_price should be positive!");
        _id = ID;
        _rent_price = rent_price;
    }
    int get_id()
    {
        return _id;
    }
    int get_rental_price()
    {
        return _rent_price;
    }
    virtual std::string to_string() = 0;
    
};



#endif