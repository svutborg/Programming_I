#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

/*
Rewrite the program in Listing 15.2. This time use the format specifier %c, instead of %s, to print out the character string of the local time on your computer.
*/
void exercise1()
{
/* 15L02.c: Functions with no arguments */
//#include <stdio.h>
//#include <time.h> - was added to the top of the file

    auto void GetDateTime(void); // Added auto keyword, otherwise the prototype had to be placed in global scope.

    int local_main()
    {
        printf("Before the GetDateTime() function is called.\n");
        GetDateTime();
        printf("After the GetDateTime() function is called.\n");
        return 0;
    }
    local_main();
    /* GetDateTime() definition */
    void GetDateTime(void)
    {
        time_t now;

        printf("Within GetDateTime().\n");
        time(&now);
        printf("Current date and time is: %s\n",
        asctime(localtime(&now)));
    }
}

/*
Declare and define a function, called MultiTwo(), that can perform multiplication on two integer variables.
Call the MultiTwo() function from the main() function and pass two integers to MultiTwo().
Then print out the result returned by the MultiTwo() function on the screen.
*/
void exercise2()
{
    auto int MultiTwo(int a, int b);

    int local_main()
    {
        int x = 4, y = -8;
        printf("The result from multiplying %d and %d is %d\n", x, y, MultiTwo(x, y));
        return 0;
    }
    // run local_main
    local_main();

    int MultiTwo(int a, int b)
    {
        return a * b;
    }
}

/*
Rewrite the program in Listing 15.3.
This time, make a function that takes a variable number of int arguments and performs the operation of multiplication on these arguments.
*/
void exercise3()
{
    /* 15L03.c: Processing variable arguments */
    //#include <stdio.h>
    //#include <stdarg.h> - was added to the top of the file

    auto double MultDouble(int x, ...);

    // local_main()
    {
        double d1 = 1.5;
        double d2 = 2.5;
        double d3 = 3.5;
        double d4 = 4.5;

        printf("Given an argument: %2.1f\n", d1);
        printf("The result returned by MultDouble() is: %2.1f\n\n", MultDouble(1, d1));
        printf("Given arguments: %2.1f and %2.1f\n", d1, d2);
        printf("The result returned by MultDouble() is: %2.1f\n\n", MultDouble(2, d1, d2));
        printf("Given arguments: %2.1f, %2.1f and %2.1f\n", d1, d2, d3);
        printf("The result returned by MultDouble() is: %2.1f\n\n", MultDouble(3, d1, d2, d3));
        printf("Given arguments: %2.1f, %2.1f, %2.1f, and %2.1f\n", d1, d2, d3, d4);
        printf("The result returned by MultDouble() is: %2.1f\n", MultDouble(4, d1, d2, d3, d4));
        //return 0;
    }

    /* definition of MultDouble() */
    double MultDouble(int x, ...)
    {
        va_list arglist;
        int i;
        double result = 1.0;

        printf("The number of arguments is: %d\n", x);
        va_start (arglist, x);
        for (i=0; i<x; i++)
            result *= va_arg(arglist, double);
        va_end (arglist);
        return result;
    }
}

/*
Rewrite the program in Listing 15.3 again. This time, print out all arguments passed to the AddDouble() function.
Does va_arg() fetch each argument in the same order (that is, from left to right) of the argument list passed to AddDouble()?
*/
void exercise4()
{
    /* 15L03.c: Processing variable arguments */
    //#include <stdio.h>
    //#include <stdarg.h> - was added to the top of the file

    auto double AddDouble(int x, ...);

    // local_main()
    {
        double d1 = 1.5;
        double d2 = 2.5;
        double d3 = 3.5;
        double d4 = 4.5;

        printf("Given an argument: %2.1f\n", d1);
        printf("The result returned by AddDouble() is: %2.1f\n\n", AddDouble(1, d1));
        printf("Given arguments: %2.1f and %2.1f\n", d1, d2);
        printf("The result returned by AddDouble() is: %2.1f\n\n", AddDouble(2, d1, d2));
        printf("Given arguments: %2.1f, %2.1f and %2.1f\n", d1, d2, d3);
        printf("The result returned by AddDouble() is: %2.1f\n\n", AddDouble(3, d1, d2, d3));
        printf("Given arguments: %2.1f, %2.1f, %2.1f, and %2.1f\n", d1, d2, d3, d4);
        printf("The result returned by AddDouble() is: %2.1f\n", AddDouble(4, d1, d2, d3, d4));
        //return 0;
    }

    /* definition of AddDouble() */
    double AddDouble(int x, ...)
    {
        va_list arglist;
        int i;
        double result = 0.0;
        double temp_arg = 0.0;

        printf("The number of arguments is: %d\n", x);
        va_start (arglist, x);
        printf("Argument list:");
        for (i=0; i<x; i++)
        {
            temp_arg = va_arg(arglist, double);
            printf(" %.1f", temp_arg);
            result += temp_arg;
        }
        putchar('\n');
        va_end (arglist);
        return result;
    }
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
            default:
                printf("Non-valid selection, press another number...\n");
                break;
        }
    }
    printf("Quitting, Goodbye!");
    return 0;
}
