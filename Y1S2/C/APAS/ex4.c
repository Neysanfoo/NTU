/*edit*/

/*custom header*/
#include <math.h>
double exp(double x);
int factorial(int n);
/*end_edit*/
#include <stdio.h>
int main()
{
/*edit*/
 /* Write your code here */
  double x;
  printf("Enter x:\n");
  scanf("%lf",&x);
  double result = exp(x);
  printf("Result = %.2f\n", result);

/*end_edit*/

 return 0;
}

double exp(double x)
{
double sum = 0;
for (int i = 0; i<11; i++)
{
    double term = pow(x,i) / factorial(i);
    sum += term;
}
return sum;
}

int factorial(int n)
{
  if (n == 0)
  {
      return 1;
  }
  else
  {
      return n * factorial(n-1);
  }
}
