#ifndef ELECTRIC_BIKE_H
#define ELECTRIC_BIKE_H

#include "bike.h"

class ElectricBike : public Bike
{
private:
    double _power = -1;
public:
    ElectricBike() = delete;
    ElectricBike(int ID, int rent_price, double power = 0) : Bike(ID, rent_price)
    {
        if(!(0 <= power && power <= 1)) throw  std::invalid_argument("the power should between 0 and 1!");
        _power = power;
    }
    /*i think no need to create same funtion again*/
    // int get_id()
    // {

    // }
    // int get_rental_price()
    // {

    // }
    double get_power()
    {
        return _power;
    }
    void set_power(double power)
    {
        if(!(0 <= power && power <= 1)) throw  std::invalid_argument("the power should between 0 and 1!");
        _power = power;
    }
    std::string to_string() override
    {
        // 15-ElectricBike price=30 power=0.30
        char _str[50];
        sprintf(_str, "%d-ElectricBike price=%d power=%.2f",this->get_id(),this->get_rental_price(),this->get_power());
        return _str;
    }
    ~ElectricBike() override = default;
};



#endif

