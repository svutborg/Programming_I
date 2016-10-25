#include <stdio.h>
#include <stdlib.h>

/*
Write a program to ask the user to enter the total number of bytes he or she wants to allocate. Then, initialize the allocated memory with consecutive integers, starting from 1.
Add all the integers contained by the memory block and print out the final result on the screen.
*/
void exercise1()
{
    int n_bytes = 0, i;
    int *num_ptr;
    unsigned long sum = 0;

    // get user to enter number
    printf("Please enter a total number of memory segments you want to allocate:\n");
    scanf("%d", &n_bytes);

    // allocate the number of memory segments
    printf("Allocation a total of %d memory segments\n", n_bytes);
    num_ptr = malloc(n_bytes*sizeof(unsigned int));

    // store numbers 1 to n and print the memory location
    for(i = 0; i < n_bytes; i++)
    {
        *(num_ptr + i) = i + 1;
        printf("Storing %d in %p\n", i + 1, (num_ptr + i));
    }

    // sum and print all stored numbers
    for(i = 0; i < n_bytes; i++)
    {
        sum += *(num_ptr + i);
    }
    printf("The sum of these numbers are: %lu\n", sum);

    // freeing up allocated memory
    free(num_ptr);
}

/*
Write a program that allocates a block of memory space to hold 100 items of the float data type by calling the calloc() function.
Then, reallocate the block of memory in order to hold 50 more items of the float data type.
*/
void exercise2()
{
    float *f_ptr;

    // allocating 100 elements of the size of a float
    f_ptr = calloc(100, sizeof(float));
    // reallocating 150 elements of the size of a float
    f_ptr = realloc(f_ptr, 150*sizeof(float));

    // freeing up allocated memory
    free(f_ptr);
}

/*
Write a program to ask the user to enter the total number of float data.
Then use the calloc() and malloc() functions to allocate two memory blocks with the same size specified by the number, and print out the initial values of the two memory blocks.
*/
void exercise3()
{
    int num = 0, i;
    float *flt_ptr1, *flt_ptr2;

    // get number from user
    printf("Enter a number of float data elements you want to allocate memory for:\n");
    scanf("%d", &num);

    // allocate memory
    flt_ptr1 = malloc(num * sizeof(float));
    flt_ptr2 = calloc(num, sizeof(float));

    // print contents in allocated memory, side by side
    for(i = 0; i < num; i++)
    {
        printf("malloc: %5f calloc: %5f\n", flt_ptr1[i], flt_ptr2[i]);
    }

    // freeing up allocated memory
    free(flt_ptr1);
    free(flt_ptr2);
}

/*
Rewrite the program in Listing 17.4.
This time, use the two special cases of the realloc() function to replace the malloc() and free() functions.
*/
int exercise4()
{
    /* 17L04.c: Using the realloc() function */
    // #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    /* function declaration */
    auto void StrCopy(char *str1, char *str2);
    /* local main() function */
    //main()
    {
        char *str[4] = {    "There's music in the sighing of a reed;",
                            "There's music in the gushing of a rill;",
                            "There's music in all things if men had ears;",
                            "There earth is but an echo of the spheres.\n"};
        char *ptr;
        int i;

        int termination = 0;

        ptr = realloc(NULL, (strlen(str[0]) + 1) * sizeof(char));
        if (ptr == NULL)
        {
            printf("malloc() failed.\n");
            termination = 1;
        }
        else
        {
            StrCopy(str[0], ptr);
            printf("%s\n", ptr);
            for (i=1; i<4; i++){
                ptr = realloc(ptr, (strlen(str[i]) + 1) * sizeof(char));
                if (ptr == NULL)
                {
                    printf("realloc() failed.\n");
                    termination = 1;
                    i = 4; /* break the fro loop */
                }
                else
                {
                    StrCopy(str[i], ptr);
                    printf("%s\n", ptr);
                }
            }
        }
        realloc(ptr, 0);
        return termination;
    }
    /* funciton definition */
    void StrCopy(char *str1, char *str2)
    {
        int i;

        for (i=0; str1[i]; i++)
            str2[i] = str1[i];
        str2[i] = '\0';
    }
}

/*

*/
void exercise5()
{

}

int main()
{
    char selection[20];
    while(1)
    {
        printf("Choose exercise\n");
        printf("Enter number, press q to quit\n");
        scanf("%s", selection );
        if(selection[0] == 'q')
        {
            break;
        }
        switch(selection[0])
        {
            case '1':
                exercise1();
                break;
            case '2':
                exercise2();
                break;
            case '3':
                exercise3();
                break;
            case '4':
                exercise4();
                break;
            case '5':
                exercise5();
                break;
            default:
                printf("Non-valid selection, press another number...\n");
                break;
        }
    }
    printf("Quitting, Goodbye!");
    return 0;
}
