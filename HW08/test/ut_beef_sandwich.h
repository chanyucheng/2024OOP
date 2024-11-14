#include <gtest/gtest.h>
// #include "../src/sandwich.h"
#include "../src/beef_sandwich.h"


TEST(BEEFSANDWICH, Constructor)
{
    BeefSandwich s = BeefSandwich(100, 0);
    ASSERT_THROW(BeefSandwich(-1, 0), std::invalid_argument);
}
TEST(BEEFSANDWICH, Getter)
{
    BeefSandwich s = BeefSandwich(100, 0);
    ASSERT_EQ(s.get_id(), 0);
    ASSERT_EQ(s.get_price(), 100);
}
TEST(BEEFSANDWICH, Get_size_of_the_container)
{
    BeefSandwich s1 = BeefSandwich(100, 0);
    BeefSandwich s2 = BeefSandwich(100, 1);
    BeefSandwich s3 = BeefSandwich(100, 2);

    ASSERT_EQ(BeefSandwich::get_size_of_record_container(), 3);
}
TEST(BEEFSANDWICH, Check_specific_element_is_in_the_container_or_not)
{
    BeefSandwich s = BeefSandwich(100, 4);
    ASSERT_EQ(BeefSandwich::record_has_specific_id(4), true); 
    ASSERT_EQ(BeefSandwich::record_has_specific_id(1), false); 
    ASSERT_EQ(BeefSandwich::record_has_specific_id(3), false); 
}
