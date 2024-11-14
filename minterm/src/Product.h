#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
using namespace std;


class Product{
public:
    void init(string name, int price){
        if (name.size() < 4){
            throw string("The length of name should longer than 4.");
        }
        if (price <= 0){
            throw string(" the price should be a positive number.");
        }
        _name = name;
        _price = price;
    }
    Product() = default;
    Product(string name, int price)
    {
        init(name, price);
    }
    Product& operator=(const Product& other){
        if (this != &other)
        {
            init(other._name, other._price);
        }
        return *this;
    }
    bool operator==(const Product& other){
        return (this->_name == other._name);
    }

    string getName() const{
        return _name;
    }
    int getPrice() const{
        return _price;
    }

private:
    string _name = "";
    int _price = 0;
};

#endif