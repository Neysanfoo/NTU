#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
0/1 Knapsack
*/

int max(int a, int b) 
{
    return a > b ? a : b;
}

int knapsack(int *weights, int *values, int n, int W)
{
    int table[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (weights[i-1] <= j)
                table[i][j] = max(table[i-1][j], values[i-1]+table[i-1][j-weights[i-1]]);
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[n][W];
}

int main(void)
{

    ;
}