/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <math.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}
int extEvenDigits1(int num)
{
    /*edit*/
    /* Write your code here */
    int even_digits[20];
    int last_digit;
    int even_pos = 0;
    int digit_count = 0;

    while (num > 0)
    {
        last_digit = num % 10;
        digit_count++;
        if (last_digit % 2 == 0)
        {
            even_digits[even_pos] = last_digit;
            even_pos++;
        }
        num = num / 10;
    }
    int sum = 0;
    for (int i = 0; i < even_pos; i++)
    {
        sum += even_digits[i] * pow(10, i);
    }
    if (sum == 0)
    {
        return -1;
    }
    return sum;
    /*end_edit*/
}
void extEvenDigits2(int num, int *result)
{
    /*edit*/
    /* Write your code here */
    int even_digits[20];
    int last_digit;
    int even_pos = 0;
    int digit_count = 0;

    while (num > 0)
    {
        last_digit = num % 10;
        digit_count++;
        if (last_digit % 2 == 0)
        {
            even_digits[even_pos] = last_digit;
            even_pos++;
        }
        num = num / 10;
    }
    int sum = 0;
    for (int i = 0; i < even_pos; i++)
    {
        sum += even_digits[i] * pow(10, i);
    }
    if (sum == 0)
    {
        sum = -1;
        *result = sum;
    }
    *result = sum;
    /*end_edit*/
}