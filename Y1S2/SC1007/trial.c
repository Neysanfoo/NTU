#include <stdio.h>
#include <stdlib.h>

struct Student{
    int age;
    float height;
} typedef Student;

int main(void)
{
    Student neysan;
    neysan.age = 21;
    neysan.height = 182.4;
    printf("%d\n",neysan.age);
}