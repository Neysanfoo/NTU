#include <stdio.h>
#include <stdlib.h>

int A5Q(int X, int N)
{
    int Half;

    if (N == 1) return X;
    else
    {
        Half = N/2;
        if (2 * Half == N)
        {
            return A5Q(X, Half) * A5Q(X, Half);
        }
        else
        {
            return A5Q(X, Half) *A5Q(X, Half ) * X;
        }
    }
}

int main(void)
{
    printf("%d\n", A5Q(2,3));
}

