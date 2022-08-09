/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int countOddDigits1(int num);
void countOddDigits2(int num, int *result);
int main()
{
    int number, result;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("countOddDigits1(): %d\n", countOddDigits1(number));
    countOddDigits2(number, &result);
    printf("countOddDigits2(): %d\n", result);
    return 0;
}
int countOddDigits1(int number)
{
    /*edit*/
    /* Write your code here */
    int odd_count = 0;
    while (number > 0)
    {
        int last_digit = number % 10;
        if (last_digit % 2 == 1)
        {
            odd_count++;
        }
        number = number / 10;
    }
    return odd_count;
    /*end_edit*/
}
void countOddDigits2(int number, int *count)
{
    /*edit*/
    /* Write your code here */
    int odd_count = 0;
    while (number > 0)
    {
        int last_digit = number % 10;
        if (last_digit % 2 == 1)
        {
            odd_count++;
        }
        number = number / 10;
    }
    *count = odd_count;
    /*end_edit*/
}