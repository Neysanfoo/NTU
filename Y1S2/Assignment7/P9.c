#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
Rod cutting problem:
Return maximum value of a rod of length n
*/

int max(int a, int b)
{
    return a > b ? a : b;
}

int rod_cutting1(int *prices,int n)
{
    if (n == 0)
        return 0;
    int max_value = 0;
    for (int i = 1; i <= n; i++)
    {
        max_value = max(max_value, prices[i] + rod_cutting1(prices, n - i));
    }
    return max_value;
}
    
int M[1000];

int rod_cutting2(int *prices, int n)
{
    if (n == 0)
        return 0;
    if (M[n] > 0)
        return M[n];
    else
    {
        int max_value = 0;
        for (int i = 1; i <= n; i++)
        {
            max_value = max(max_value, prices[i] + rod_cutting2(prices, n - i));
        }
        M[n] = max_value;
    }
    return M[n];
}

int rod_cutting3(int *prices, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            M[i] = max(M[i], prices[j] + M[i - j]);
        }
    }
    return M[n];
}

int main(void)
{
    double time_spent;
    clock_t begin;
    clock_t end;
    
    int prices[10] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24};
    
    int n;
    printf("Enter the length of the rod: ");
    scanf("%d", &n);


    time_spent = 0.0;
    begin = clock();
    printf("Rod Cutting Normal: %d\n", rod_cutting1(prices,n));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Normal Time: %f \n", time_spent);

    time_spent = 0.0;
    begin = clock();
    printf("Rod Cutting Memo: %d\n", rod_cutting2(prices,n));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Memo Time: %f \n", time_spent);
    
    time_spent = 0.0;
    begin = clock();
    printf("Rod Cutting Tabulation: %d\n", rod_cutting3(prices,n));
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tabulation Time: %f \n", time_spent);

}