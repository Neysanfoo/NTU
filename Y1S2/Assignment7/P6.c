#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

// Fibonacci using tabulation
long long fibTabulation(int n)
{
    long long fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    return fib[n];
}

int main(void)
{
    printf("%lld\n", fibTabulation(50));
}