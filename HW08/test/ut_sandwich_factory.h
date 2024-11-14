#include <gtest/gtest.h>
#include "../src/sandwich_factory.h"

TEST(SANDWICHFACTORY, Create_a_sandwich)
{
    BeefSandwich* bs =  SandwichFactory<BeefSandwich>::create_sandwich(55, 12345);
    ASSERT_EQ(bs->get_id(), 12345);
    ASSERT_EQ(bs->get_price(), 55);
    ASSERT_EQ(bs->get_size_of_record_container(), 1);
    ASSERT_EQ(bs->record_has_specific_id(12345), true);
    ASSERT_EQ(bs->record_has_specific_id(123), false);
    delete bs;
}
TEST(SANDWICHFACTORY, Create_a_sandwich_array)
{
    vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, 5, {33, 44, 55, 66, 99});
    ASSERT_EQ(sweet_sandwich_set[0]->get_id(), 33);
    ASSERT_EQ(sweet_sandwich_set[1]->get_id(), 44);
    ASSERT_EQ(sweet_sandwich_set[2]->get_id(), 55);
    ASSERT_EQ(sweet_sandwich_set[3]->get_id(), 66);
    ASSERT_EQ(sweet_sandwich_set[4]->get_id(), 99);
    
    for (int i = 0; i < 5; i++)
    {
        delete sweet_sandwich_set[i];
    }
}
TEST(SANDWICHFACTORY, Create_a_sandwich_array_should_throw_while_negative_count)
{
    ASSERT_THROW(SandwichFactory<SweetSandwich>::create_sandwich_array(15, -5, {33, 44, 55, 66, 99}), invalid_argument);

}
TEST(SANDWICHFACTORY, Create_a_sandwich_array_should_throw_while_negative_price)
{
    ASSERT_THROW(SandwichFactory<SweetSandwich>::create_sandwich_array(-15, 5, {33, 44, 55, 66, 99}), invalid_argument);
}

