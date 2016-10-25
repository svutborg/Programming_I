#include <stdio.h>
#include <stdlib.h>

/*
Given a character string, I like C!, write a program to pass the string to a function that displays the string on the screen.
*/
void exercise1()
{
    // function that accepts a char * type argument, and prints it
    void printString(char *str)
    {
        printf(str);
    }

    // call function
    printString("I like C!");
    putchar('\n');
}

/*
Rewrite the program in exercise 1. This time, change the string of I like C! to I love C! by moving a pointer that is initialized
with the start address of the string and updating the string with new characters.
Then, pass the updated string to the function to display the content of the string on the screen.
*/
void exercise2()
{
    // function that accepts a char * type argument, and prints it
    void printString(char *str)
    {
        printf(str);
    }

    char s[] = "I like C!"; // initialize string

    // change characters i and k to o and v
    *(s + 3) = 'o';
    *(s + 4) = 'v';

    // call function
    printString(s);
    putchar('\n');
}

/*
Given a two-dimensional character array, str, that is initialized as
char str[2][15] = { "You know what,", "C is powerful." };
write a program to pass the start address of str to a function that prints out the content of the character array.
*/
void exercise3()
{
    // This is dangerous and you should not do this
    void printFromAddress(int addr)
    {
        char *string = (char *)addr;

        printf("%s",string);
    }

    char str[2][30] = { "You know what, ", "C is powerful, but unsafe." };

    printFromAddress((int)&(str[0][0]));
    printFromAddress((int)&(str[1][0]));
    putchar('\n');
}

/*
Rewrite the program in Listing 16.7. This time, the array of pointers is initialized with the following strings:
“Monday”, “Tuesday”, “Wednesday”, “Thursday”, “Friday”, “Saturday” and “Sunday”.
*/
void exercise4()
{
    /* 16L07.c: Using an array of pointers */
    //#include <stdio.h>
    /* function declarations */
    auto void StrPrint1(char **str1, int size);
    auto void StrPrint2(char *str2);
    /* local main() function */
    //main()
    {
        char *str[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        int i, size = 7;

        StrPrint1(str, size);
        for (i=0; i<size; i++)
            StrPrint2(str[i]);

        //return 0;
    }
    /* function definition */
    void StrPrint1(char **str1, int size)
    {
        int i;
        /* Print all strings in an array of pointers to strings */
        for (i=0; i<size; i++)
            printf("%s\n", str1[i]);
    }
    /* function definition */
    void StrPrint2(char *str2)
    {
        /* Prints one string at a time */
        printf("%s\n", str2);
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
