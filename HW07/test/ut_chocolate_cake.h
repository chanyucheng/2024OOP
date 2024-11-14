#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"
#include <iostream>

TEST(CHOCOLATE_CAKE, Constructor)
{
    ChocolateCake cCake1(55, 40);
    ChocolateCake cCake2();
}
TEST(CHOCOLATE_CAKE, GetPrice_and_getSweet)
{
    ChocolateCake cCake1(55, 40);
    ChocolateCake cCake2(55, 40);
    ASSERT_EQ(55, cCake1.get_price());
    ASSERT_EQ(40, cCake1.get_sweet());
}
TEST(CHOCOLATE_CAKE, GetChocolateCakeCount)
{
    ChocolateCake cCake1(55, 40);
    ChocolateCake cCake2(55, 40);
    // HoneyCake hCake1(100, 40);
    ASSERT_EQ(2, cCake1.get_total());
    ASSERT_EQ(2, cCake1.get_count());
    ASSERT_EQ(2, cCake2.get_count());
    // ASSERT_EQ(1, hCake1.get_count());

}
TEST(CHOCOLATE_CAKE, ChocolateCake_To_string)
{
    ChocolateCake cCake1(55, 40);
    std::string s = cCake1.to_string();
    std::cout << s << std::endl;
}
