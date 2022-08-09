/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
/*edit*/
 /* Write your code here */
  const int cap = 40;
  int hours, overtime;
  double Gross, Tax, Net;
  printf("Enter hours of work:\n");
  scanf("%d",&hours);
  if (hours > cap)
  {
      overtime = hours - cap;
      Gross = 40*6.00 + overtime*6.00*1.5;
  }
  else
  {
      Gross = hours*6.00;
  }
  // Tax Brackets : <= 1000, <= 1500, >= 1500
  if (Gross <= 1000)
  {
      Tax = Gross*0.1;
  }
  else if (1000<Gross && Gross<= 1500)
  {
      Tax = 100 + (Gross-1000)*0.2;
  }
  else if (Gross > 1500)
  {
      Tax = 200 + (Gross-1500)*0.3;
  }
  else
  {
      return 0;
  }
  Net = Gross - Tax;
  printf("Gross pay=%.2f\n", Gross);
  printf("Tax=%.2f\n", Tax);
  printf("Net pay=%.2f\n", Net);

/*end_edit*/
 return 0;
}
