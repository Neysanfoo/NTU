#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

/*
Knapsack Problem
*/

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsackTabular(int n, int m, int *weights, int *values)
{
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m)
    int table[n+1][m+1];
    for (int i = 0; i<=n; i++)
    {
        for (int j = 0; j<=m; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (weights[i-1] <= j)
                table[i][j] = max(values[i-1] + table[i-1][j-weights[i-1]], table[i-1][j]);
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[n][m];
}


int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));
    
    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);
        
    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);
    printf("%d\n", knapsackTabular(2, 6, (int[]){3,3}, (int[]){12,10}));
    s = s+1;
    v = v+1;

    
    printf("The maximum value is: %d \n", knapsackTabular(n,C,s,v));
        
}