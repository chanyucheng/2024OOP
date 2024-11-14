#include <gtest/gtest.h>
#include "../src/sandwich.h"


TEST(SANDWICH, Constructor)
{
    Sandwich s = Sandwich(100, 0);
    ASSERT_THROW(Sandwich(-1, 0), std::invalid_argument);
}
TEST(SANDWICH, Getter)
{
    Sandwich s = Sandwich(100, 0);
    ASSERT_EQ(s.get_id(), 0);
    ASSERT_EQ(s.get_price(), 100);
}
TEST(SANDWICH, Get_size_of_the_container)
{
    Sandwich s1 = Sandwich(100, 0);
    Sandwich s2 = Sandwich(100, 1);
    Sandwich s3 = Sandwich(100, 2);

    ASSERT_EQ(Sandwich::get_size_of_record_container(), 3);
}
TEST(SANDWICH, Check_specific_element_is_in_the_container_or_not)
{
    Sandwich s = Sandwich(100, 0);
    ASSERT_EQ(Sandwich::record_has_specific_id(0), true); 
    ASSERT_EQ(Sandwich::record_has_specific_id(1), false); 
}
