#include <stdio.h>
int square1(int num);
void square2(int num, int *result);
int main()
{
    int number, result = 0;
    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("square1(): %d\n", square1(number));
    square2(number, &result);
    printf("square2(): %d\n", result);
    return 0;
}
int square1(int num)
{
    /* Write your code here */
    int sum = 0;
    int odd = 1;
    for (int i = 0; i < num; i++)
    {
        sum = sum + odd;
        odd += 2;
    }
    return sum;
}
void square2(int num, int *result)
{
    /* Write your code here */
    int sum = 0;
    int odd = 1;
    for (int i = 0; i < num; i++)
    {
        sum = sum + odd;
        odd += 2;
    }
    *result = sum;
}