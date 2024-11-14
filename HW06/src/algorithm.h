// 放algorithm的一些function
#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "alcohol.h"
#include <algorithm>
#include <vector>

void sort_alcohol_by_name(vector<Alcohol*> &alcohol)
{
    std::sort(alcohol.begin(), alcohol.end(),
            [](Alcohol* a, Alcohol* b){
                return a->get_name() < b->get_name();
            });
}
void sort_alcohol_by_content(vector<Alcohol*> &alcohol)
{
    sort_alcohol_by_name(alcohol);
    std::sort(alcohol.begin(), alcohol.end(),
            [](Alcohol* a, Alcohol* b){
                if (a->get_alcohol_content() == b->get_alcohol_content())
                    return a->get_name() < b->get_name();
                else
                    return a->get_alcohol_content() < b->get_alcohol_content();
            });
}
Alcohol* get_greatest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    sort_alcohol_by_content(alcohol);
    if(alcohol.size() != 0)
        return alcohol.back();//回傳最後一個元素
    else
        throw std::invalid_argument("vector is empty!");
}
Alcohol* get_smallest_content_of_alcohol(vector<Alcohol*> alcohol)
{
    sort_alcohol_by_content(alcohol);
    if(alcohol.size() != 0)
        return alcohol.front();//回傳第一個元素
    else
        throw std::invalid_argument("vector is empty!");
}

#endif