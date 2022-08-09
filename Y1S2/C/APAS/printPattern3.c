/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
/*edit*/
 /* Write your code here */
 int height;
 printf("Enter the height:\n");
 scanf("%d",&height);
 printf("The pattern is:\n");
 for (int i = 1; i < height+1; i++)
 {
     for (int j=0; j<i ; j++)
     {
         printf("%d",(i+j)%10);
     }
     printf("\n");
 }

/*end_edit*/
 return 0;
}
