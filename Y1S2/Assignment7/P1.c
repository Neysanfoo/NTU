#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

long long M[1000];

/*
fib
Time Complexity: O(2^n)
Space Complexity: O(n)

fib1
Time Complexity: O(n)
Space Complexity: O(n)
*/



int fib(int n)
{
    if (n <= 2) 
        return 1;
    return fib(n-1) + fib(n-2);
}


//Using memoization
long long fib1(int n)
{
    if (n<=2)
        return 1;
    if (M[n-1] == -1)
        M[n-1] = fib1(n-1);
    if (M[n-2] == -1)
        M[n-2] = fib1(n-2);
    M[n] = M[n-1] + M[n-2];
    return M[n];
}


// Using closed form formula
long long fib2(int n)
{
    return round((1.0/sqrt(5)) * pow(((1+sqrt(5))/2), n) - pow(((1-sqrt(5))/2), n));
}

long long fib3(int n)
{
    M[0] = 0;
    M[1] = 1;
    for (int i = 2; i<=n; i++)
    {
        M[i] = M[i-1] + M[i-2];
    }
    return M[n];
}


int main(void)
{
    double time_spent;
    clock_t begin;
    clock_t end;
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    time_spent = 0.0;
    begin = clock();
    printf("Fib: %d\n",fib(n));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Fib Time: %f \n", time_spent);

    for (int i = 0; i<1000; i++)
    {
        M[i] = -1;
    }
    M[1] = 1;
    M[2] = 1;

    time_spent = 0.0;
    begin = clock();
    printf("Fib1: %lld\n",fib1(n));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Fib1 Time: %f \n", time_spent);

    time_spent = 0.0;
    begin = clock();
    printf("Fib2: %lld\n",fib2(n));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Fib2 Time: %f \n", time_spent);

    time_spent = 0.0;
    begin = clock();
    printf("Fib3: %lld\n",fib3(n));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Fib3 Time: %f \n", time_spent);
}

