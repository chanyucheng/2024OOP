#ifndef COOKIE_H
#define COOKIE_H

int check_x(bool** grid){
    /* Return the x-coordinate of the lastest of cookie. */ 
    for (int i = 0; i < 10; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (grid[i][j] == true)
            {
                return i;//row
            }
        }
    }
}

int check_y(bool** grid){
    /* Return the y-coordinate of the lastest of cookie. */
    for (int i = 0; i < 10; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (grid[i][j] != false)
            {
                return j;//col
            }
        }
    }
}

void print_grid(bool** grid){
    /* Print the grid you input. */
    /* Implement this function if necessary, it can help you to check your grid is correct or not. */
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(grid[i][j] == true)
            {
                std:: cout << "1 ";
            }else
            {
                std:: cout << "0 ";
            }
            
        }
        std:: cout << std:: endl;
    }
}

void placeTop(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    /* You can implement check_x(), check_y() above to get the x, y of the lastest cookie you place. */
    int x = check_x(grid);
    int y = check_y(grid);
    /* Check when you place cookie, it will out of bound or not. */
    if ((x-1) < 0)
    {
        throw std::string("out of range.");
    }
    

    /* Place cookie from the top of current cookie. */
    grid[x-1][y] = true;
}

void placeRight(bool** grid){
    /* Get the coordinate of the cookie which place lastest from grid. */
    int x = check_x(grid);
    int y = check_y(grid);

    /* Check when you place cookie, it will out of bound or not. */
    if ((y+1) > 9)
    {
        throw std::string("out of range.");
    }
    /* Place cookie from the right of current cookie. */
    grid[x][y+1] = true;
}

int calcRow(bool** grid, int row){
    /* Calculate the count of cookie on the specific row */
    int sum = 0;
    if (row > 9 || row < 0) return -1;
    for (int j = 0; j < 10; j++)
    {
        if(grid[row][j] == true)
        {
            sum += 1;
            if ((j+1) < 10 && grid[row][j+1] != true) break;
        }
    }
    return sum;
    
}

int calcColumn(bool** grid, int column){
    /* Calculate the count of cookie on the specific column */
    int sum = 0;
    if (column > 9 || column < 0) return -1;
    for (int i = 0; i < 10; i++)
    {
        if(grid[i][column] == true)
        {
            sum += 1;
            if ((i+1) < 10 && grid[i+1][column] != true) break;
        }
    }
    return sum;
    
}

#endif
