#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

long long gridTravelerTabulation(int n, int m)
{
    // Implement gridTraveler using tabulation
    
    long long grid[n+1][m+1];
    for (int i = 0; i<=n; i++)
    {
        for (int j = 0; j<=m; j++)
        {
            if (i == 0 || j == 0)
                grid[i][j] = 0;
            else if (i == 1 && j == 1)
                grid[i][j] = 1;
            else
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }
    return grid[n][m];
}

int main(void)
{
    printf("%lld\n", gridTravelerTabulation(2, 4));
}