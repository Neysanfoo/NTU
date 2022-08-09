#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	// allocate 7 bytes on the heap to hold 7 chars "Neysan\0"
	char *name = malloc(7 * sizeof(char));
	strcpy(name, "Neysan");
	printf("%s\n",name);

	// allocate 4 or 8 bytes on the heap to hold 2 ints, initialized to 0
	int *numbers = calloc(2, sizeof(int));
	numbers[0] = 1;
	numbers[1] = 2;

	printf("%d %d\n",numbers[0],numbers[1] );

	// reallocate name to 25 bytes
	name = realloc(name, 11*sizeof(char));
	strcat(name, " Foo");
	printf("%s\n",name);

	// release memory back to the operating system
	free(name);
	free(numbers);
}
