/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int numDigits1(int num);
void numDigits2(int num, int *result);
int main()
{
    int number, result = 0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("numDigits1(): %d\n", numDigits1(number));
    numDigits2(number, &result);
    printf("numDigits2(): %d\n", result);
    return 0;
}
int numDigits1(int num)
{
    /*edit*/
    /* Write your code here */
    int nDigits = floor(log10(abs(num))) + 1;
    return nDigits;

    /*end_edit*/
}
void numDigits2(int num, int *result)
{
    /*edit*/
    /* Write your code here */
    *result = numDigits1(num);
    /*end_edit*/
}