#include <gtest/gtest.h>
#include "../src/algorithm.h"
#include "../src/sour.h"
#include "../src/tequila.h"

TEST(ALGORITHM, SortByNameOnly)
{
    Alcohol* t1 = new Tequila("tequila1",100, 0.1);
    Alcohol* s1 = new Sour("sour1",80, 0.1);
    Alcohol* t2 = new Tequila("tequila2",100, 0.2);
    Alcohol* s2 = new Sour("sour2",80, 0.2);
    
    vector <Alcohol*> _order;
    _order.push_back(t2);
    _order.push_back(s1);
    _order.push_back(t1);
    _order.push_back(s2);

    sort_alcohol_by_name(_order);
    ASSERT_EQ("sour1", _order[0]->get_name());
    ASSERT_EQ("sour2", _order[1]->get_name());
    ASSERT_EQ("tequila1", _order[2]->get_name());
    ASSERT_EQ("tequila2", _order[3]->get_name());

    delete t1;
    delete t2;
    delete s1;
    delete s2;
}
TEST(ALGORITHM, SortWithoutSameContent)
{
    Alcohol* t1 = new Tequila("Tequila1",100, 0.1);
    Alcohol* s1 = new Sour("sour1",80, 0.2);
    Alcohol* t2 = new Tequila("Tequila2",100, 0.3);
    Alcohol* s2 = new Sour("sour2",80, 0.4);
    vector <Alcohol*> _order;
    _order.push_back(t2);
    _order.push_back(s1);
    _order.push_back(t1);
    _order.push_back(s2);
    // sort_alcohol_by_content(_order);
    ASSERT_EQ("sour2", get_greatest_content_of_alcohol(_order)->get_name());
    ASSERT_EQ("Tequila1", get_smallest_content_of_alcohol(_order)->get_name());

    delete t1;
    delete t2;
    delete s1;
    delete s2;
}

TEST(ALGORITHM, SortWithSameContent_should_campare_names)
{
    Alcohol* t1 = new Tequila("tequila1",100, 0.3);
    Alcohol* s1 = new Sour("sour1",80, 0.1);
    // Alcohol* t2 = new Tequila("tequila2",100, 0.1);
    Alcohol* s2 = new Sour("sour2",80, 0.1);
    vector <Alcohol*> _order;
    // _order.push_back(t2);
    _order.push_back(s2);
    _order.push_back(s1);
    _order.push_back(t1);
    // sort_alcohol_by_content(_order);
    // ASSERT_EQ("tequila1", get_greatest_content_of_alcohol(_order)->get_name());
    ASSERT_EQ("sour1", get_smallest_content_of_alcohol(_order)->get_name());

    delete t1;
    // delete t2;s
    delete s1;
    delete s2;
}


TEST(ALGORITHM, VectorIsEmpty)
{
    vector <Alcohol*> order;
    ASSERT_THROW(get_greatest_content_of_alcohol(order), std::invalid_argument);
    ASSERT_THROW(get_smallest_content_of_alcohol(order), std::invalid_argument);
}
/*
TEST(ALGORITHM, TrysomeTAsTest)
{
    vector<Alcohol*> order;
    Alcohol* t1 = new Tequila("tequila1",100, 0.1);
    Alcohol* s1 = new Sour("sour2",80, 0.1);
    order.push_back(t1);
    order.push_back(s1);
    sort_alcohol_by_content(order);

    // std::cout << order[0]->get_name() << std::endl;
    // std::cout << order[1]->get_name() << std::endl;

    delete t1;
    delete s1;

}*/