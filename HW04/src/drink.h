#include <string>
#include <vector>
#include "topping.h"
using namespace std;

class Drink{
public:

	Drink() = default;

	/* The constructor of the Drink. */
	Drink(string name, double sweetness_level, int price){
        if ((sweetness_level > 1) || (sweetness_level < 0)){
            throw string("sweetnessLevel out of range");
        }
        if (name.size() <= 4){
            throw string("name length out of range");
        }
        if (!(price >= 0)){
            throw string("price can't be negative");
        }
        _sweetness_level = sweetness_level;
        _name = name;
        _price = price;
    }

	/* The destructor of the Drink. */
	~Drink(){}

	/* Return the name of drink. */
	string getName() const {
        if (_name == "")
            throw string("Name Empty");
        return _name;
    }

	/* Return the level of sweetness. */
	double getSweetnessLevel() const {
        if ((_sweetness_level > 1) || (_sweetness_level < 0))
            throw string("sweetnessLevel isn't set");
        return _sweetness_level;
    }

	/* Return the price of drink. */
	int getPrice() const {
        if (_price == -1)
            throw string("_price isn't set");
        return _price;
    }

	/* Add a topping to the drink. */
	void addTopping(Topping topping){
        _sweetness_level += topping.getSweetnessLevel();
        _price += topping.getPrice();
        _topping.push_back(topping);
    }

	/* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
	Topping getToppingByIndex(int index) const {
        if (index >= _topping.size() || index < 0){
            throw string("index out of range");
        }
        return _topping[index];
    }

	/* Get the count of topping in drink. */
	int getToppingCount() const{ 
        return _topping.size();
    }

	/* Operator overloading */
	Drink &operator=(const Drink& other){
        if (this != &other){
            this->_name = other._name;
            this->_price = other._price;
            this->_sweetness_level = other._sweetness_level;
            this->_topping = other._topping;
        }
        return *this;
    }

private:
	/* Put some attribute on here if necessary. */
    string _name = "";
    vector<Topping> _topping;
    double _sweetness_level = -1;
    int _price = -1;
};
