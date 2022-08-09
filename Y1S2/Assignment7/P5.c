#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>

/*
Write a function howSum(targetSum, numbers) that takes in
a targetSum and an array of numbers as arguments.

The function should return an array containing any combination of 
elements that add up to exactly the targetSum. If there is no
combination that adds up to the target sum, then return NULL.

If there are multiple combinations available, you may return any one.

howSum(7, [5,3,4,7]) -> [7] or howSum(7, [5,3,4,7]) -> [3,4]

howSum(7, [2,4]) -> NULL

howSum(0, [1,2,3]) -> []
*/

int *howSum(int targetSum, int numbers[],int arrSize)
{
    // return a int array containing any combination of elements that add up to exactly the targetSum 
    // if there is no combination that adds up to the target sum, then return NULL
    // if there are multiple combinations available, you may return any one

    // Time Complexity of howSum: O(n^2) where n is the length of the array
    // Space Complexity of howSum: O(n)

   
}


int main()
{
    int targetSum = 7;
    int numbers[] = {5,3,4,7};
    int arrSize = sizeof(numbers)/sizeof(numbers[0]);
    int *result = howSum(targetSum, numbers, arrSize);
    printf("%d\n", result[0]);
    return 0;
}
