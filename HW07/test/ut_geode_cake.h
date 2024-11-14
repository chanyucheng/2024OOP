#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/geode_cake.h"
#include <iostream>

TEST(GEODE_CAKE, GeodeCake_Constructor)
{
    GeodeCake GCake1(55, 40);
    GeodeCake GCake2();
}
TEST(GEODE_CAKE, GeodeCake_getPrice_and_getSweet)
{
    GeodeCake gCake1(55, 40);
    ASSERT_EQ(55, gCake1.get_price());
    ASSERT_EQ(40, gCake1.get_sweet());
}
TEST(GEODE_CAKE, GetGeodeCakeCount)
{
    GeodeCake gCake1(55, 40);
    GeodeCake cCake2(55, 40);
    ASSERT_EQ(2, gCake1.get_total());
    ASSERT_EQ(2, gCake1.get_count());
    ASSERT_EQ(2, cCake2.get_count());

}
TEST(GEODE_CAKE, GeodeCake_To_string)
{
    GeodeCake gCake1(55, 40);
    std::string s = gCake1.to_string();
    std::cout << s << std::endl;
}
