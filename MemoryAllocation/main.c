#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pointer, i, j;

    printf("Enter how many bytes you want to store\n");
    scanf("%d", &i);

    // allocate as many bytes as the user specified
    pointer = malloc(i);

    // For as many characters as there are room for in the allocated memory
    // store an integer (4 bytes each) starting a the first memory slot onwards
    for(j = 0; j < i/sizeof(pointer); j++)
    {
        *(pointer+j) = j+1;
    }

    // print all stored numbers and their memory locations
    for(j = 0; j < i/sizeof(pointer); j++)
    {
        printf("%d at %p\n", *(pointer+j), pointer+j);
    }

    free(pointer);

    return 0;
}
