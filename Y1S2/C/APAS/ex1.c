/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int main()
{
/*edit*/
 /* Write your code here */
  while (1)
    {
    int ID;
    int Mark;
    char Grade;

    printf("Enter Student ID:\n");
    scanf("%d",&ID);
    if (ID == -1)
    {
      return 0;
    }

    printf("Enter Mark:\n");

    scanf("%d",&Mark);

    switch (Mark) {
      case 1 ... 44:
        Grade = 'F';
        break;
      case 45 ... 54:
        Grade = 'D';
        break;
      case 55 ... 64:
        Grade = 'C';
        break;
      case 65 ... 74:
        Grade = 'B';
        break;
      case 75 ... 100:
        Grade = 'A';
        break;
    }

    printf("Grade = %c\n",Grade);
  }
/*end_edit*/

 return 0;
}
