#ifndef CAKE_SHOWCASE_H
#define CAKE_SHOWCASE_H
#include "cake.h"
#include "chocolate_cake.h"
#include "geode_cake.h"
#include "honey_cake.h"
#include <vector>
#include <iostream>
#include <string>

template <typename T>
class CakeShowcase
{
public:
    CakeShowcase() = delete;
    CakeShowcase(int length, T** array)
    {
        _length = length;
        for (int i = 0; i < length; i++)
        {
            T_array.push_back(array[i]);
        }
    }
    ~CakeShowcase() = default;
    int calc_total_price()
    {
        int total_price = 0;
        for (int i = 0; i < T_array.size(); i++)
        {
            total_price += T_array[i]->get_price();
        }
        return total_price;
    }
    int calc_total_sweet()
    {
        int total_sweet = 0;
        for (int i = 0; i < T_array.size(); i++)
        {
            total_sweet += T_array[i]->get_sweet();
        }
        return total_sweet;
    }
    std::string to_string()
    {
        // char _str[1000];
        // sprintf(_str, "| CakeName             | Price      | Sweet      |\n");
        // sprintf(_str + strlen(_str), "| -------------------- | ---------- | ---------- |\n");
        // for (int i = 0; i < T_array.size(); i++)
        // {
        //     sprintf(_str + strlen(_str), "%s",T_array[i]->to_string().c_str());
        //     sprintf(_str + strlen(_str), "\n");
        // }
        // sprintf(_str + strlen(_str), "| -------------------- | ---------- | ---------- |");
        // return _str;
        std::string s;
        s += "| CakeName             | Price      | Sweet      |\n";
        for (int i = 0; i < T_array.size(); i++)
        {
            s += T_array[i]->to_string();
            s += "\n";
        }
        s += "| -------------------- | ---------- | ---------- |";
        return s;
    }
    T* operator[](int index)
    {
        if(index >= _length || index < 0)
        {
            throw std::out_of_range("index out of range");
        }
        return T_array[index];
    }
    

private:
    int _length = 0;
    std::vector<T*> T_array;
};

// template class CakeShowcase<Cake>; 因為我有都寫在一起所以沒差??

#endif