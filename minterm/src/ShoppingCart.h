#include "Product.h"
#include <vector>

class ShoppingCart{
public:
    void init(int item_list_size, Product* item_list){
        for(int i = 0; i < item_list_size-1; i++){
            for(int j = i+1; j < item_list_size; j++){
                if (item_list[i] == item_list[j]){
                    throw string("the item list contains repeat item");
                }
            }
        }
        for (int q = 0; q < item_list_size; q++)
        {
            _totalCost += item_list[q].getPrice();
        }
        
        this->_item_list_size = item_list_size;
        for (int i = 0; i < item_list_size; i++)
        {
            _item_list.push_back(item_list[i]);
        }
    }
    ShoppingCart() = default;
    ShoppingCart(int item_list_size, Product* item_list)
    {
        init(item_list_size, item_list);
    }

    ShoppingCart& operator=(const ShoppingCart& other){
        if (this != &other){
            this->_item_list = other._item_list;
            this->_item_list_size = other._item_list_size;
            this->_totalCost = other._totalCost;
        }
        return *this;
    }
    ShoppingCart& operator+(const ShoppingCart& other){
        for (int i = 0; i < other._item_list_size; i++)
        {
            bool flag = false;
            for (int j = 0; j < this->_item_list_size; j++)
            {
                if (other.getItemByIndex(i) == this->getItemByIndex(j))
                    flag = true;
            }
            if(flag == false){
                this->appendItem(other._item_list[i]);
            }
        }
        return *this;
    }
    ShoppingCart& operator-(const ShoppingCart& other){
        for (int i = 0; i < other.getItemCount(); i++){
            for (int j = 0; j < this->_item_list_size; j++)
            {
                if (other.getItemByIndex(i) == this->_item_list[j]){
                    this->_totalCost -= this->_item_list[j].getPrice();
                    this->_item_list.erase(_item_list.begin()+j);
                    this->_item_list_size = _item_list.size();
                }
            }
        }
        return *this;
    }

    int getItemCount() const{
        return _item_list_size;
    }
    Product getItemByIndex(int index) const{
        if (!(0 <= index && index < _item_list_size)){
            throw string("index is out of range.");
        }
        return _item_list[index];
    }
    void setItemByIndex(int index, Product product){
        if (!(0 <= index && index < _item_list_size)){
            throw string("index is out of range.");
        }
        for(int i = 0; i < _item_list_size; i++){
            if (product == _item_list[i] && index != i){
                throw string("the item list contains repeat item");
            }
        }
        _totalCost -= _item_list[index].getPrice();
        _totalCost += product.getPrice();
        _item_list[index] = product;
    }
    void appendItem(Product product){
        for(int i = 0; i < _item_list_size; i++){
            if (product.getName() == _item_list[i].getName()){
                throw string("this itme is already exist.");
            }
        }
        _item_list.push_back(product);
        _totalCost += product.getPrice();
        _item_list_size += 1;
    }
    int getTotalCost() const{
        return _totalCost;
    }
private:
    int _item_list_size = 0;
    vector<Product> _item_list;
    int _totalCost = 0;
};