	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#define SIZE 5
void findMinMax2D(int ar[SIZE][SIZE], int *min, int *max);
int main()
{
   int A[5][5];
   int i,j,min,max;  
   
   printf("Enter the matrix data (%dx%d): \n", SIZE, SIZE);
   for (i=0; i<5; i++)
      for (j=0; j<5; j++)
         scanf("%d", &A[i][j]);
   findMinMax2D(A, &min, &max);
   printf("min = %d\nmax = %d", min, max);   
   return 0;          
}
void findMinMax2D(int ar[SIZE][SIZE], int *min, int *max)
{
	/*edit*/
   /* Write your code here */   
    int min_num = ar[0][0];
    int max_num = ar[0][0];
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col<SIZE; col++)
        {
            if (ar[row][col] < min_num)
            {
                min_num = ar[row][col];
            }
            if (ar[row][col] > max_num)
            {
                max_num = ar[row][col];
            }
        }
    }
    *min = min_num;
    *max = max_num;
	/*end_edit*/
}
