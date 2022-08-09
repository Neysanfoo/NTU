#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

/*
Say you are a traveler on a 2D grid. 
You begin in the top-left corner and your goal
is to reach the bottom-right corner. You many only
move down or right.

In how many ways can you travel to the goal on a grid
with dimensions m * n?
*/

/*
Brute force solution
Time complexity: O(2^(n+m))
Space complexity: O(n+m)

Memoization
Time complexity: O(n*m)
Space complexity: O(n+m)
*/

long long M[100][100];


int gridTraveler(int m, int n) {
    if (m == 1 && n == 1) {
        return 1;
    }
    if (m == 0 || n == 0)
    {
        return 0;
    }
    return gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
}


// Using memoization

long long gridTravelerMemo(int m, int n) {
    if (m == 1 && n == 1) {
        return 1;
    }
    if (m == 0 || n == 0)
    {
        return 0;
    }
    if (M[m][n] != -1) {
        return M[m][n];
    }
    // if (M[n][m] != -1) {
    //     return M[n][m]; // Slightly faster
    // }
    M[m][n] = gridTravelerMemo(m - 1, n) + gridTravelerMemo(m, n - 1);
    return M[m][n];
}



int main (void)
{
    double time_spent;
    clock_t begin;
    clock_t end;

    for (int i = 0; i<100;i++)
    {
        for (int j = 0; j<100;j++)
        {
            M[i][j] = -1;
        }
    }

    time_spent = 0.0;
    begin = clock();
    printf("Grid Travel: %d\n",gridTraveler(10, 18));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Normal Time: %f \n", time_spent);

    time_spent = 0.0;
    begin = clock();
    printf("Grid Travel (Memo): %lld\n", gridTravelerMemo(30, 30));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Memo Time: %f \n", time_spent);

}