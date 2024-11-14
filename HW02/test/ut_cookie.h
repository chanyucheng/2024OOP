#include <bits/stdc++.h>
#include "../src/cookie.h"

/* The function help you to create the empty grid. */
/* You can use this function or create by yourself. */
bool** create_grid(){
    bool** array = new bool*[10];//array裡面裝了10個指標
    for(int i = 0; i < 10; i++){
        array[i] = new bool[10];//每個指標裡面裝10個玩素
        for(int j = 0; j < 10; j++){
            array[i][j] = false;
        }
    }
    array[9][0] = true;
    return array;
}

/* The function help you to delete the grid. */
/* You should implement this by yourself. */
void delete_grid(bool** array){
    for (int i=0; i < 10; i++)
        delete [] array[i]; //把每個指標裡面的十個元素free掉
    delete [] array; //把裝了10個指標的array free掉
}

/* Add some test in here. */

TEST(COOKIE, regularSituation1){
    bool** grid = create_grid();
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);
    placeRight(grid);
    placeTop(grid);

    ASSERT_EQ(calcRow(grid,8),2);
    ASSERT_EQ(calcColumn(grid,2),2);
    delete_grid(grid);
}
TEST(COOKIE, regularSituation2){
    bool** grid = create_grid();
    placeTop(grid);
    placeTop(grid);
    placeRight(grid);
    placeRight(grid);
    placeRight(grid);
    placeTop(grid);

    ASSERT_EQ(calcRow(grid,7),4);
    ASSERT_EQ(calcColumn(grid,2),1);
    delete_grid(grid);
}

TEST(COOKIE, placeOutOfRange_row){
    bool** grid = create_grid();
    for (int i = 0; i < 9; i++)
    {
        placeTop(grid);
    }
    ASSERT_THROW(placeTop(grid), std::string);
    delete_grid(grid);
}

TEST(COOKIE, placeOutOfRange_col){
    bool** grid = create_grid();
    for (int i = 0; i < 9; i++)
    {
        placeRight(grid);
    }
    ASSERT_THROW(placeRight(grid), std::string);
    delete_grid(grid);
}

TEST(COOKIE, rowOutOfRange){
    bool** grid = create_grid();
    ASSERT_EQ(calcRow(grid, 17), -1);
    delete_grid(grid);
}

TEST(COOKIE, colOutOfRange){
    bool** grid = create_grid();
    ASSERT_EQ(calcColumn(grid, 13), -1);
    delete_grid(grid);
}

TEST(COOKIE, placeTenTimesThenCount){
    bool** grid = create_grid();
    for (int i = 0; i < 5; i++)
    {
        placeTop(grid);
        placeRight(grid);
    }
    ASSERT_EQ(calcRow(grid, 6), 2);
    ASSERT_EQ(calcColumn(grid, 5), 1);
    delete_grid(grid);
}
