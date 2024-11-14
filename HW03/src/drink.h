#include <string>
#include <algorithm>
using namespace std;

class Drink{
public:
    Drink(){//constructor

    }
    /* The constructor of the Drink. */
    Drink(string name, double sweetness_level){
        if ((sweetness_level > 1) || (sweetness_level < 0)){
            throw string("sweetnessLevel out of range");
        }else{
            _sweetness_level = sweetness_level;
        }
        if (name.size() <= 4){
            throw string("name length out of range");
        }else{
            _name = name;
        }
    }
    /* The destructor of the Drink. */
    ~Drink(){
        delete[] _topping;
    }
    /* Return the name of drink. */
    string getName(){
        if (_name == "")
            throw string("Name Empty");
        return _name;
    }
    /* Return the level of sweetness. */
    double getSweetnessLevel(){
        if ((_sweetness_level > 1) || (_sweetness_level < 0))
            throw string("sweetnessLevel isn't set");
        return _sweetness_level;
    }
    /* Add a topping to the drink. */
    void addTopping(string topping){
        if (_toppingCount == 0){
            _topping = new string[_capacity];
            _topping[_toppingCount] = topping;
            _toppingCount++;
        }else if (_capacity > _toppingCount)
        {
            _topping[_toppingCount] = topping;
            _toppingCount++;
        }else
        {
            _capacity *= 2;
            string* newTopping = new string[_capacity];
            copy(_topping, _topping + _toppingCount, newTopping);
            newTopping[_toppingCount] = topping;
            delete[] _topping;
            _topping = newTopping;
            _toppingCount++;
        }
    }
    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    string getToppingByIndex(int index){
        if (index < 0 || index > (_toppingCount-1))
            throw string("Wrong Index");
        else
            return _topping[index];
    }
    /* Get the count of topping in drink. */
    int getToppingCount(){
        return _toppingCount;
    }
private:
    /* Put some attribute on here if necessary. */
    string _name = "";
    string* _topping = nullptr;
    int _toppingCount = 0;
    double _sweetness_level = -1;
    int _capacity = 4;
};
