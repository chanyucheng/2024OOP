#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include "../src/drink.h"

/* Place some test here */
TEST(DRINK, constructorTest){
    ASSERT_THROW(Drink d("Tea", 0.5, 40), std::string);
    ASSERT_THROW(Drink d("Black Tea", 1.1, 40), std::string);
    ASSERT_THROW(Drink d("Black Tea", 0.6, -10), std::string);
}
TEST(DRINK, gettter){
    Drink d;
    ASSERT_THROW(d.getName(), std::string);
    ASSERT_THROW(d.getSweetnessLevel(), std::string);
    ASSERT_THROW(d.getPrice(), std::string);
}
TEST(DRINK, CreateDrink){
    Drink d("Signature Black Tea with Milk", 0.3, 45);
    ASSERT_EQ(d.getName(), "Signature Black Tea with Milk");
    ASSERT_EQ(d.getSweetnessLevel(), 0.3);
    ASSERT_EQ(d.getPrice(), 45); 
}
TEST(DRINK, AddTopping){
    Drink drink("Signature Black Tea with Milk", 0.3, 45);
    drink.addTopping(Topping("Bubble", 0.15, 5));
    ASSERT_EQ(drink.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.45, 0.01);
    ASSERT_EQ(drink.getPrice(), 50);
}
TEST(DRINK, DrinkCopy){
    Drink some_drink("Black Tea", 0.2, 15);
    Drink drink;
    drink = some_drink;

    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.2, 0.01);
    ASSERT_EQ(drink.getPrice(), 15);
}
TEST(DRINK, GetTopping){
    Drink drink("Signature Black Tea with Milk", 0.3, 45);
    drink.addTopping(Topping("Bubble", 0.15, 5));
    Topping topping = drink.getToppingByIndex(0);

    ASSERT_THROW(drink.getToppingByIndex(1), std::string);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_NEAR(topping.getSweetnessLevel(), 0.15, 0.01);
    ASSERT_EQ(topping.getPrice(), 5);
}
TEST(DRINK, ToppingCount){
    Drink some_drink("Black Tea", 0.2, 15);
    Drink drink;
    drink = some_drink;
    drink.addTopping(Topping("Bubble", 0.15, 5));
    drink.addTopping(Topping("Aloe", 0.2, 10));

    ASSERT_EQ(some_drink.getToppingCount(), 0);
    ASSERT_EQ(drink.getToppingCount(), 2);
}