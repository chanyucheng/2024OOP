#include <gtest/gtest.h>
#include "../src/sour.h"

TEST(SOUR, Constructor)
{
    Sour s("sourDrink", 100, 0.4);
    ASSERT_EQ(s.get_name(), "sourDrink");
    ASSERT_EQ(s.get_price(), 100);
    ASSERT_EQ(s.get_alcohol_content(), 0.4);
}
TEST(SOUR, SourDilute)
{
    Sour s("sourDrink", 100, 0.5);
    s.dilute();
    ASSERT_EQ(0.2, s.get_alcohol_content());
}
TEST(SOUR, SourDilute2)
{
    Sour s("sourDrink", 100, 0.5);
    s.dilute();
    ASSERT_EQ(0.2, s.get_alcohol_content());
}
TEST(SOUR, Add)
{
    Sour s1("sourDrink1", 100, 0.3);
    Sour s2("sourDrink2", 80, 0.2);
    Sour s3;
    // Sour s3("abc", 10, 0.2);
    s3 = s1 + s2;
    ASSERT_EQ("sourDrink1", s3.get_name());
    ASSERT_EQ(180, s3.get_price());
    ASSERT_EQ(0.25, s3.get_alcohol_content());
}
TEST(SOUR, Boolean)
{
    Sour s1("sourDrink1", 100, 0.3);
    Sour s2("sourDrink1", 100, 0.3);
    Sour s3("sourDrink1", 120, 0.4);
    ASSERT_EQ(true, s1 == s2);
    ASSERT_EQ(false, s1 == s3);
}
TEST(SOUR, Assignment)
{
    Sour s1("sourDrink1", 100, 0.3);
    Sour s2 = s1;
    ASSERT_EQ("sourDrink1", s2.get_name());
    ASSERT_EQ(100, s2.get_price());
    ASSERT_EQ(0.3, s2.get_alcohol_content());
}