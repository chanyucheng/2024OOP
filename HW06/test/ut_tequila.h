#include <gtest/gtest.h>
#include "../src/tequila.h"

TEST(TEQUILA, Constructor)
{
    Tequila t("tequilaDrink", 100, 0.4);
    ASSERT_EQ(t.get_name(), "tequilaDrink");
    ASSERT_EQ(t.get_price(), 100);
    ASSERT_EQ(t.get_alcohol_content(), 0.4);
}
TEST(TEQUILA, TequilaDilute)
{
    Tequila t("tequilaDrink", 100, 0.5);
    t.dilute();
    ASSERT_EQ(0.45, t.get_alcohol_content());
}
TEST(TEQUILA, Add)
{
    Tequila t1("Tequilala1", 180, 0.2);
    Tequila t2("Tequilala2", 280, 0.3);
    Tequila t3;
    t3 = t1 + t2;
    ASSERT_EQ("Tequilala1", t3.get_name());
    ASSERT_EQ(460, t3.get_price());
    ASSERT_EQ(0.25, t3.get_alcohol_content());
}
TEST(TEQUILA, Boolean)
{
    Tequila t1("TequilaDrink1", 100, 0.3);
    Tequila t2("TequilaDrink1", 100, 0.3);
    Tequila t3("TequilaDrink3", 120, 0.4);
    ASSERT_EQ(true, t1 == t2);
    ASSERT_EQ(false, t1 == t3);
}
TEST(TEQUILA, Assignment)
{
    Tequila s1("TequilaDrink1", 100, 0.3);
    Tequila s2 = s1;
    ASSERT_EQ("TequilaDrink1", s2.get_name());
    ASSERT_EQ(100, s2.get_price());
    ASSERT_EQ(0.3, s2.get_alcohol_content());
}