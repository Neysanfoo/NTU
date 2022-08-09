/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
/*edit*/
 /* Write your code here */
 int lines;
 printf("Enter number of lines: \n");
 scanf("%d", &lines);
 for (int i = 0; i<lines; i++)
 {
     int input;
     int total = 0;
     int n = 0;
     printf("Enter line %d (end with -1):\n", i+1);
     while (1)
     {
       scanf("%d",&input);
       if (input == -1)
       {
         break;
       }
       total += input;
       n ++;
     }
     double avg = (double) total / n;
     printf("Average = %.2f\n", avg );
 }

/*end_edit*/

 return 0;
}
