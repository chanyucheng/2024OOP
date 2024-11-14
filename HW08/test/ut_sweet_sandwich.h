#include <gtest/gtest.h>
// #include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"


TEST(SWEETSANDWICH, Constructor)
{
    SweetSandwich s = SweetSandwich(100, 0);
    ASSERT_THROW(SweetSandwich(-1, 0), std::invalid_argument);
}
TEST(SWEETSANDWICH, Getter)
{
    SweetSandwich s = SweetSandwich(100, 0);
    ASSERT_EQ(s.get_id(), 0);
    ASSERT_EQ(s.get_price(), 100);
}
TEST(SWEETSANDWICH, Get_size_of_the_container)
{
    SweetSandwich s1 = SweetSandwich(100, 0);
    SweetSandwich s2 = SweetSandwich(100, 1);
    SweetSandwich s3 = SweetSandwich(100, 2);

    ASSERT_EQ(SweetSandwich::get_size_of_record_container(), 3);
}
TEST(SWEETSANDWICH, Check_specific_element_is_in_the_container_or_not)
{
    SweetSandwich s = SweetSandwich(100, 4);
    ASSERT_EQ(SweetSandwich::record_has_specific_id(4), true); 
    ASSERT_EQ(SweetSandwich::record_has_specific_id(1), false); 
    ASSERT_EQ(SweetSandwich::record_has_specific_id(3), false); 
}
