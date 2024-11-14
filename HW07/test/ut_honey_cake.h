#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/honey_cake.h"
#include "../src/geode_cake.h"
#include "../src/chocolate_cake.h"
#include <iostream>

TEST(HONEY_CAKE, HoneyCake_Constructor)
{
    HoneyCake HCake1(55, 40);
    HoneyCake HCake2();
}
TEST(HONEY_CAKE, HoneyCake_getPrice_and_getSweet)
{
    HoneyCake HCake1(55, 40);
    ASSERT_EQ(55, HCake1.get_price());
    ASSERT_EQ(40, HCake1.get_sweet());
}
TEST(HONEY_CAKE, GetHoneyCakeCount)
{
    HoneyCake HCake1(55, 40);
    HoneyCake HCake2(55, 40);
    ASSERT_EQ(2, HCake1.get_total());
    ASSERT_EQ(2, HCake1.get_count());
    ASSERT_EQ(2, HCake2.get_count());

}
TEST(HONEY_CAKE, HoneyCake_To_string)
{
    HoneyCake HCake1(55, 40);
    std::string s = HCake1.to_string();
    std::cout << s << std::endl;
}
