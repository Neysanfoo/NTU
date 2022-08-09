/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
/*edit*/
 /* Write your code here */
 int height;
 printf("Enter the height: \n");
 scanf("%d", &height);
 printf("Pattern:\n");
 for (int i = 0; i<height; i++)
 {
   for (int j = 0; j<i+1; j++)
   {
     int n = i % 3+1;
     printf("%d",n);
   }
   printf("\n");
 }
/*end_edit*/

 return 0;
}
