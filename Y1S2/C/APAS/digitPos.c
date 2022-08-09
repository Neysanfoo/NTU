/*edit*/

/*custom header*/
#include <string.h>
/*end_edit*/
#include <stdio.h>
int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);
int main()
{
    int number, digit, result = 0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("Enter the digit: \n");
    scanf("%d", &digit);
    printf("digitPos1(): %d\n", digitPos1(number, digit));
    digitPos2(number, digit, &result);
    printf("digitPos2(): %d\n", result);
    return 0;
}
int digitPos1(int num, int digit)
{
    /*edit*/
    /* Write your code here */
    int count = 0;
    while (num / 10 != 0)
    {
        int last_digit = num % 10;
        if (last_digit == digit)
        {
            count += 1;
            return count;
        }
        count += 1;
        num = num / 10;
    }
    return 0;

    /*end_edit*/
}
void digitPos2(int num, int digit, int *result)
{
    /*edit*/
    /* Write your code here */
    int count = 0;
    while (num / 10 != 0)
    {
        int last_digit = num % 10;
        if (last_digit == digit)
        {
            count += 1;
            *result = count;
            break;
        }
        count += 1;
        num = num / 10;
    }
    /*end_edit*/
}