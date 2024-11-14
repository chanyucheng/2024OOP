#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"
#include <iostream>

TEST(CAKE, constructor)
{
    Cake *c1 = new ChocolateCake(55, 40);
    delete c1;
}
TEST(CAKE, getPrice)
{
    Cake *c1 = new ChocolateCake(55, 40);
    Cake *c2 = new ChocolateCake(60, 45);
    ASSERT_EQ(55, c1->get_price());
    ASSERT_EQ(60, c2->get_price());
    delete c1;
    delete c2;
}
TEST(CAKE, getSweet)
{
    Cake *c1 = new ChocolateCake(55, 40);
    Cake *c2 = new ChocolateCake(60, 45);
    ASSERT_EQ(40, c1->get_sweet());
    ASSERT_EQ(45, c2->get_sweet());
    delete c1;
    delete c2;
}
TEST(CAKE, getTotalCakeCount)
{
    Cake *c1 = new ChocolateCake(55, 40);
    Cake *c2 = new ChocolateCake(60, 45);
    Cake *g1 = new GeodeCake(50, 40);
    Cake *h1 = new HoneyCake(40, 30);
    ASSERT_EQ(4, c1->get_total());
    delete c1;
    delete c2;
    delete g1;
    delete h1;
}

