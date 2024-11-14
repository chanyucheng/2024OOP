#ifndef BIKE_RMS_H
#define BIKE_RMS_H

#include "electric_bike.h"
#include "mybike.h"

#include <vector>

class BikeRMS
{
private:
    std::vector<Bike*> _avaliableBikes;
    std::vector<Bike*> _rentedBikes;
    static int _total_return_income;
public:
    BikeRMS() = delete;
    BikeRMS(std::vector<Bike*> bikes)
    {
        _avaliableBikes = bikes; // use reference or not???
    }
    int get_count_of_available_bike()
    {
        return _avaliableBikes.size();
    }
    Bike* rent_bike(int ID)
    {
        for (int i = 0; i < _avaliableBikes.size(); i++)
        {
            if(_avaliableBikes[i]->get_id() == ID){
                Bike* temp = _avaliableBikes[i];
                _avaliableBikes.erase(_avaliableBikes.begin()+i);
                _rentedBikes.push_back(temp);
                _total_return_income += temp->get_rental_price();
                return temp;
            }
        }
        throw std::invalid_argument("the bike can't be rent!!");
    }
    void return_bike(Bike* bike)
    {
        bool flag = false;
        for (int i = 0; i < _rentedBikes.size(); i++)
        {
            if(_rentedBikes[i]->get_id() == bike->get_id()){
                flag = true;
                _avaliableBikes.push_back(bike);
                _rentedBikes.erase(_rentedBikes.begin()+i);
            }
        }
        if(flag == false)
            throw std::invalid_argument("Can't be return!!");
    }
    void append_bike(Bike* bike)
    {
        for (int i = 0; i < _avaliableBikes.size() ; i++)
        {
            if(bike->get_id() == _avaliableBikes[i]->get_id())
                throw std::invalid_argument("the bike already exist, can't append");
        }
        for (int i = 0; i < _rentedBikes.size() ; i++)
        {
            if(bike->get_id() == _rentedBikes[i]->get_id())
                throw std::invalid_argument("the bike already exist, can't append");
        }
        _avaliableBikes.push_back(bike);
    }
    static int get_total_rental_income()
    {
        return _total_return_income;
    }
    static void reset_total_rental_income()
    {
        _total_return_income = 0;
    }

    ~BikeRMS() = default;
};

int BikeRMS::_total_return_income = 0;


#endif