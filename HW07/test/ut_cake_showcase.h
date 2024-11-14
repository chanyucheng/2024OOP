#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"
#include "../src/cake_showcase.h"
#include <iostream>
#include <vector>

//As long as using new, you should delete it.
//If you new type[], then you have to delete by using []. Otherwise, no need to []
TEST(CAKE_SHOWCASE, Constructor)
{
    Cake** array = new Cake*[3];
    array[0] = new ChocolateCake(55, 40);
    array[1] = new HoneyCake(55, 40);
    array[2] = new GeodeCake(55, 40);

    CakeShowcase<Cake> showcase1(3, array);
    std::string s = showcase1.to_string();
    // std::cout << s;

    ASSERT_EQ(s, 
    "| CakeName             | Price      | Sweet      |\n"
    "| ChocolateCake        |         55 |         40 |\n"
    "| HoneyCake            |         55 |         40 |\n"
    "| GeodeCake            |         55 |         40 |\n"
    "| -------------------- | ---------- | ---------- |"
    );

    for (int i=0; i < 3; i++)
        delete array[i]; //把每個指標裡面的三個元素free掉
    delete[] array; //把裝了3個指標的array free掉
}
TEST(CAKE_SHOWCASE, Calc_total_price)
{
    Cake** array = new Cake*[3];
    array[0] = new ChocolateCake(55, 40);
    array[1] = new HoneyCake(55, 40);
    array[2] = new GeodeCake(55, 40);

    CakeShowcase<Cake> showcase1(3, array);
    ASSERT_EQ(165, showcase1.calc_total_price());
    for (int i=0; i < 3; i++)
        delete array[i]; //把每個指標裡面的三個元素free掉
    delete[] array; //把裝了3個指標的array free掉
}
TEST(CAKE_SHOWCASE, Calc_total_sweet)
{
    Cake** array = new Cake*[3];
    array[0] = new ChocolateCake(55, 40);
    array[1] = new HoneyCake(55, 40);
    array[2] = new GeodeCake(55, 40);

    CakeShowcase<Cake> showcase1(3, array);
    ASSERT_EQ(120, showcase1.calc_total_sweet());
    for (int i=0; i < 3; i++)
        delete array[i]; //把每個指標裡面的三個元素free掉
    delete[] array; //把裝了3個指標的array free掉
}
TEST(CAKE_SHOWCASE, operatorBracketOverloading)
{
    Cake** array = new Cake*[3];
    array[0] = new ChocolateCake(55, 40);
    array[1] = new HoneyCake(55, 40);
    array[2] = new GeodeCake(55, 40);

    CakeShowcase<Cake> showcase1(3, array);


    ASSERT_EQ(array[0], showcase1[0]);
    ASSERT_EQ(showcase1[0]->get_price(), 55);
    ASSERT_EQ(showcase1[0]->get_sweet(), 40);
    ASSERT_THROW(showcase1[3], std::out_of_range);
    ASSERT_THROW(showcase1[-1], std::out_of_range);


    for (int i=0; i < 3; i++)
        delete array[i]; //把每個指標裡面的三個元素free掉
    delete[] array; //把裝了3個指標的array free掉
}
