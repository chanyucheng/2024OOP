#include <gtest/gtest.h>
#include "../src/tequila.h"
#include "../src/sour.h"
#include <iostream>

TEST(ALCOHOL, ThrowException)
{
    ASSERT_THROW(Alcohol *a = new Sour("", 100, 0.5), std::invalid_argument);
    ASSERT_THROW(Alcohol *b = new Sour("drink", -1, 0.5), std::invalid_argument);
    ASSERT_THROW(Alcohol *c = new Sour("drink", 100, 1.5), std::invalid_argument);
}
TEST(ALCOHOL, Constructor)
{

    Alcohol *a = new Sour("sourDrink", 100, 0.4);
    ASSERT_EQ(a->get_name(), "sourDrink");
    ASSERT_EQ(a->get_price(), 100);
    ASSERT_EQ(a->get_alcohol_content(), 0.4);
    delete a;
}



