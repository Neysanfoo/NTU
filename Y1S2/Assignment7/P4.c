#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include <stdbool.h>

/*
Write a function canSum(targetSum, numbers) that takes
in a targetSum and an array of numbers as arguments.
The function should return a boolean indication whether or not
it is possible to generate the targetSum using numbers from the array.

You may use an element of the array as many times as needed.

You may assume that all input numbers are nonnegative.

canSum(7,[5,3,4]) -> true

canSum(7,[2,4]) -> false

Time Complexity of canSum: O(n^m) where n is the length of the array and m is the targetSum
Space Complexity of canSum: O(m)

Time Complexity of canSumMemo: O(m*n)
Space Complexity of canSumMemo: O(m)

*/

int memo[1000];


bool canSum(int targetSum, int numbers[], int arrSize)
{
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;
    for (int i = 0; i<arrSize; i++)
    {
        int remainder = targetSum - numbers[i];
        if (canSum(remainder, numbers, arrSize))
        {
            return true;
        }
    }
    return false;

}


bool canSumMemo(int targetSum, int numbers[], int arrSize)
{
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;
    if (memo[targetSum] != -1) return memo[targetSum];
    

    for (int i = 0; i<arrSize; i++)
    {
        int remainder = targetSum - numbers[i];
        if (canSumMemo(remainder, numbers, arrSize))
        {
            memo[targetSum] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}


int main(void)
{
    double time_spent;
    clock_t begin;
    clock_t end;
    for (int i = 0; i<1000; i++)
    {
        memo[i] = -1;
    }
    
    int targetSum;
    int arrSize;
    printf("Enter TargetSum: ");
    scanf("%d", &targetSum);
    printf("Enter Size of Array: ");
    scanf("%d", &arrSize);
    int arr[arrSize];
    printf("Enter Array (Seperated by space): ");
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    time_spent = 0.0;
    begin = clock();
    printf(canSum(targetSum, arr, arrSize) ? "true\n" : "false\n");
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Normal Time: %f \n", time_spent);

    time_spent = 0.0;
    begin = clock();
    printf(canSumMemo(targetSum, arr, arrSize) ? "true\n" : "false\n");
    end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Memo Time: %f \n", time_spent);
    
    

}

