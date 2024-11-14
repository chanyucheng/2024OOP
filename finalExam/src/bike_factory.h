#ifndef BIKE_FACTORY_H
#define BIKE_FACTORY_H

#include "electric_bike.h"
#include "mybike.h"

#include <vector>
using namespace std;

template <typename T>
class BikeFactory
{
private:
    /* data */
public:
    static T* create_bike(int ID, int rent_price)
    {
        return (new T(ID, rent_price));
    }
    static vector<T*> create_bike_array(vector<int> IDs, vector<int> rent_prices)
    {
        vector<T*> arr;
        for (int i = 0; i < IDs.size(); i++)
        {
            T* temp = new T(IDs[i], rent_prices[i]);
            arr.push_back(temp);
        }
        return arr;
    }
    BikeFactory() = delete;
    ~BikeFactory() = delete;
};

#endif 