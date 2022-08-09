#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int memo[1000];

int topDown(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return topDown(n-1) + 2*topDown(n-2) - 3*topDown(n-3);
}

int topDownMemo(int n)
{
    if (memo[n] != -1) return memo[n];
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    memo[n] = topDownMemo(n-1) + 2*topDownMemo(n-2) - 3*topDownMemo(n-3);
    return memo[n];
}


 
int main ()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    for (int i = 0; i<=n; i++)
    {
        memo[i] = -1;
    }
    
    printf("The value of F(%d) is: %d \n", n, topDown(n));
    printf("The value of F(%d) is: %d \n", n, topDownMemo(n));
    
        
}