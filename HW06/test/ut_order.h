#include <gtest/gtest.h>
#include "../src/order.h"
#include "../src/sour.h"
#include "../src/tequila.h"

TEST(ORDER, Constructor)
{
    Order orders;
    Alcohol* s = new Sour("sourDrink", 100, 0.4);
    Alcohol* t = new Tequila("tequilaDrink", 180, 0.2);

    orders.append_alcohol(s);
    orders.append_alcohol(t);
    // std::cout << ("tequila1" > "sour2") << std::endl;
    // std::cout << ("tequila1" < "sour2") << std::endl;
    
    delete s;
    delete t;
}

TEST(ORDER, Get_alcohol_count)
{
    Order orders;
    Alcohol* s = new Sour("sourDrink", 100, 0.4);
    Alcohol* t = new Tequila("tequilaDrink", 180, 0.2);

    orders.append_alcohol(s);
    orders.append_alcohol(t);
    ASSERT_EQ(2, orders.get_alcohol_count());
    delete s;
    delete t;
}
TEST(ORDER, Get_total_price)
{
    Order orders;
    Alcohol* s = new Sour("sourDrink", 100, 0.4);
    Alcohol* t = new Tequila("tequilaDrink", 180, 0.2);

    orders.append_alcohol(s);
    orders.append_alcohol(t);
    ASSERT_EQ(280, orders.get_total_price());
    delete s;
    delete t;
}