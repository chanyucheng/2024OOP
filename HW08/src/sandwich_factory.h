#ifndef SANDWICH_FACTORY_H
#define SANDWICH_FACTORY_H

#include "sandwich.h"
#include "sweet_sandwich.h"
#include "beef_sandwich.h"

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class SandwichFactory
{
private:
    /* data */
public:
    static T* create_sandwich(int price, int id)
    {
        T* t = new T(price, id);
        return t;
    }
    static vector<T*> create_sandwich_array(int price, int count, std::vector<int> id_list)
    {
        if(count != id_list.size()) throw invalid_argument("count does not match the id_list");
        //should check price is correct or not here, because if we find out late, the for loop has already create some pointer, which might lead to memory leak
        if(price < 0) throw invalid_argument("price can not be negative!!");
        vector<T*> arr;
        for (int i = 0; i < count; i++)
        {
            T* temp = new T(price, id_list[i]);
            arr.push_back(temp);
        }
        return arr;
    }
    SandwichFactory() = delete;
    ~SandwichFactory() = delete;
};




#endif