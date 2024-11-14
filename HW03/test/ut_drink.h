#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "../src/drink.h"

/* Place some test here */


TEST(DRINK, CreateDrink1)
{
    Drink drink;
    ASSERT_THROW(drink.getName(), string);
}
TEST(DRINK, CreateDrink2)
{
    Drink drink;
    ASSERT_THROW(drink.getSweetnessLevel(), string);
}
TEST(DRINK, GetName)
{
    Drink drink("Bubble Tea", 0.8);
    ASSERT_EQ(drink.getName(), "Bubble Tea");
}
TEST(DRINK, GetNameThrow)
{
    ASSERT_THROW(Drink drink("", 1), string);
}
TEST(DRINK, GetSweetnessLevel)
{
    Drink drink("coco cola", 0.5);
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.5, 0.01);
}
TEST(DRINK, GetSweetnessLevelThrow)
{
    Drink drink;
    ASSERT_THROW(drink.getSweetnessLevel(), string);
}
TEST(DRINK, AddTopping1)
{
    Drink drink("Green Tea", 0.1);
    drink.addTopping("bubble");
    ASSERT_EQ(drink.getToppingByIndex(0), "bubble");
}
TEST(DRINK, AddTopping2)
{
    Drink drink("Black Tea", 0.1);
    drink.addTopping("bubble");
    drink.addTopping("pudding");
    for (int i = 0; i < 100; i++)
    {
        drink.addTopping("ADD");
    }
    ASSERT_EQ(drink.getToppingByIndex(100), "ADD");
}
TEST(DRINK, GetToppingByIndex)
{
    Drink drink("Black Tea", 0.1);
    drink.addTopping("aloe");
    ASSERT_EQ(drink.getToppingByIndex(0), "aloe");
}
TEST(DRINK, GetToppingByIndexThrow)
{
    Drink drink("Black Tea", 0.1);
    drink.addTopping("aloe");
    ASSERT_THROW(drink.getToppingByIndex(1), string);
}
TEST(DRINK, GetToppingCount1)
{
    Drink drink("Green Tea", 0);
    drink.addTopping("aloe");
    drink.addTopping("pudding");
    ASSERT_EQ(drink.getToppingCount(), 2);
}
TEST(DRINK, GetToppingCount2)
{
    Drink drink("Green Tea", 0);
    ASSERT_EQ(drink.getToppingCount(), 0);
}