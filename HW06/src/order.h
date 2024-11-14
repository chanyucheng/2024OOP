#ifndef ORDER_H
#define ORDER_H
#include "alcohol.h"
#include <vector>

class Order
{
public:
    Order() = default;
    ~Order() = default;
        // for (int i = 0; i < _order.size(); i++)
        // {
        //     delete _order[i];
        // }
    void append_alcohol(Alcohol* alcohol)
    {
        _order.push_back(alcohol);
        _totalPrice += alcohol->get_price();
    }
    int get_alcohol_count()
    {
        return _order.size();
    }
    int get_total_price()
    {
        return _totalPrice;
    }
    /*不用在這邊新增algorithm的function去做sort?
    然後寫getter來驗證*/


private:
    vector<Alcohol*> _order;
    int _totalPrice = 0;
};

#endif
