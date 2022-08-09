#include <stdio.h>
#include <stdlib.h>

struct person{
  char firstName[15];
  char lastName[15];
  struct {
    int age;
    float height;
    float weight;
    char firstName[15];
    } Info, *InfoPtr;
} student1;
struct person personP;
typedef struct person person_t;


int main(void)
{
  person_t *studentPtr = &student1;
  person_t **studentPtrPtr = &studentPtr;
  studentPtr->Info.age = 8;
  (*studentPtrPtr)->Info.age = 16;
  printf("%d\n", studentPtr->Info.age);
}