#ifndef MY_BIKE_H
#define MY_BIKE_H

#include "bike.h"

class MyBike : public Bike
{
private:

public:
    MyBike() = delete;
    MyBike(int ID, int rent_price, double power = 0) : Bike(ID, rent_price){};

    std::string to_string() override
    {
        char _str[50];
        sprintf(_str, "%d-MyBike price=%d",this->get_id(),this->get_rental_price());
        return _str;
    }
    ~MyBike() override = default;
};



#endif

