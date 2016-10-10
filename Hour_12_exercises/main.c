#include <stdio.h>
#include <stdlib.h>

/*
Given this character array:
char array_ch[5] = {‘A’, ‘B’, ‘C’, ‘D’, ‘E’};
write a program to display each element of the array on the screen.
*/
void exercise1()
{
    int i;
    char array_ch[5] = {'A', 'B', 'C', 'D', 'E'};
    for (i = 0; i < 5; i++)
    {
        putchar(array_ch[i]);
    }
    putchar('\n');
}

/*
Rewrite the program in Exercise 1, but this time use a for loop to initialize the character array with ‘a’, ‘b’, ‘c’, ‘d’, and ‘e’, and then print out the value of each element in the array.
*/
void exercise2()
{
    int i;
    char array_ch[5];
    for (i = 0; i < 5; i++)
    {
        array_ch[i] = 'a' + i;
    }
    for (i = 0; i < 5; i++)
    {
        putchar(array_ch[i]);
    }
    putchar('\n');
}

/*
Given this two-dimensional unsized array:
char list_ch[][2] = {
                        ‘1’, ‘a’,
                        ‘2’, ‘b’,
                        ‘3’, ‘c’,
                        ‘4’, ‘d’,
                        ‘5’, ‘e’,
                        ‘6’, ‘f’};
write a program to measure the total bytes taken by the array, and then print out all elements of the array.
*/
void exercise3()
{
    char list_ch[][2] = {	{'1', 'a'},
                            {'2', 'b'},
                            {'3', 'c'},
                            {'4', 'd'},
                            {'5', 'e'},
                            {'6', 'f'}};
    printf("%d\n", sizeof(list_ch));
}

/*
Rewrite the program in Listing 12.5. This time put a string of characters, I like C!, on the screen.
*/
void exercise4()
{
    char array_ch[15] = {   'I', ' ',
                            'l', 'i', 'k', 'e', ' ',
                            'C', '!', '\0'};
    int i;
    /* array_ch[i] in logical test */
    for (i = 0; array_ch[i]; i++)
        printf("%c", array_ch[i]);

    printf("\n");
}
/*
Given the following array:
double list_data[6] = { 1.12345,
                        2.12345,
                        3.12345,
                        4.12345,
                        5.12345};
use the two equivalent ways taught in this lesson to measure the total memory space taken by the array, and then display the results on the screen.
*/
void exercise5()
{
    double list_data[6] = { 1.12345,
                            2.12345,
                            3.12345,
                            4.12345,
                            5.12345};
    printf("Using sizeof(double) * 6 = %d\n", sizeof(double) * 6);
    printf("Using sizeof(list_data) =  %d\n", sizeof(list_data));
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
